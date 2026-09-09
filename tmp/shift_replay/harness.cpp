// Host replay harness: drives ShiftingAlgorithm (crossover / release) exactly the way
// Gearbox::elapse_shift does, but with sensor inputs read from a logged shift.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>
#include <vector>
#include <string>

#include "esp_log.h"
#include "cal_data.h"
#include "common_structs.h"
#include "common_structs_ops.h"
#include "nvs/eeprom_config.h"
#include "nvs/module_settings.h"
#include "nvs/device_mode.h"
#include "pressure_manager.h"
#include "adaptation/shift_adaptation.h"
#include "models/clutch_speed.hpp"
#include "models/input_torque.hpp"
#include "profiles.h"
#include "torque_converter.h"
#include "shifting_algo/s_algo.h"
#include "shifting_algo/shift_crossover.h"
#include "shifting_algo/shift_release.h"
#include "clock.h"

// ---- globals the firmware expects -------------------------------------------------
TCM_CORE_CONFIG VEHICLE_CONFIG;
uint16_t CURRENT_DEVICE_MODE = DEVICE_MODE_NORMAL;
TCC_MODULE_SETTINGS TCC_CURRENT_SETTINGS = TCC_DEFAULT_SETTINGS;
SOL_MODULE_SETTINGS SOL_CURRENT_SETTINGS = SOL_DEFAULT_SETTINGS;
SBS_MODULE_SETTINGS SBS_CURRENT_SETTINGS = SBS_DEFAULT_SETTINGS;
PRM_MODULE_SETTINGS PRM_CURRENT_SETTINGS = PRM_DEFAULT_SETTINGS;
ADP_MODULE_SETTINGS ADP_CURRENT_SETTINGS = ADP_DEFAULT_SETTINGS;
ETS_MODULE_SETTINGS ETS_CURRENT_SETTINGS = ETS_DEFAULT_SETTINGS;
REL_MODULE_SETTINGS REL_CURRENT_SETTINGS = REL_DEFAULT_SETTINGS;
GAR_MODULE_SETTINGS GAR_CURRENT_SETTINGS = GAR_DEFAULT_SETTINGS;
CRS_MODULE_SETTINGS CRS_CURRENT_SETTINGS = CRS_DEFAULT_SETTINGS;

CalibrationInfo* CAL_RAM_PTR = nullptr;
HydraulicCalibration* HYDR_PTR = &CAL_HYDR;
MechanicalCalibration* MECH_PTR = &CAL_MECH;
TorqueConverterCalibration* TCC_CFG_PTR = &CAL_TCC;
ShiftAlgorithmPack* SHIFT_ALGO_CFG_PTR = &CAL_SHIFT;

static OnOffSolenoid y3, y4, y5;
static ConstantCurrentSolenoid mpc, spc;
static InrushControlSolenoid tcc_sol;
OnOffSolenoid *sol_y3 = &y3, *sol_y4 = &y4, *sol_y5 = &y5;
ConstantCurrentSolenoid *sol_mpc = &mpc, *sol_spc = &spc;
InrushControlSolenoid *sol_tcc = &tcc_sol;
uint16_t Solenoids::get_solenoid_voltage(void) { return 13800; }

AbstractProfile* standard = nullptr;
AbstractProfile* manual = nullptr;
AbstractProfile* race = nullptr;

static uint32_t sim_clock_ms = 0;
uint32_t GET_CLOCK_TIME() { return sim_clock_ms; }

// Defined in the firmware's sensors/adv code; identical to interpolate_float linear
float scale_number(float raw, float new_min, float new_max, float raw_min, float raw_max) {
    return interpolate_float(raw, new_min, new_max, raw_min, raw_max, InterpType::Linear);
}

int SIM_LOG_VERBOSE = 0;
static FILE* log_out = nullptr;
void sim_log(const char* lvl, const char* tag, const char* fmt, ...) {
    if (!SIM_LOG_VERBOSE && !log_out) return;
    char buf[512];
    va_list ap; va_start(ap, fmt); vsnprintf(buf, sizeof(buf), fmt, ap); va_end(ap);
    if (SIM_LOG_VERBOSE) fprintf(stderr, "[%6u] %s %s: %s\n", sim_clock_ms, lvl, tag, buf);
    if (log_out) fprintf(log_out, "LOG %u %s %s: %s\n", sim_clock_ms, lvl, tag, buf);
}

esp_err_t EEPROM::read_nvs_map_data(const char* map_name, int16_t* dest, const int16_t* default_map, size_t n) {
    memcpy(dest, default_map, n * sizeof(int16_t));
    return ESP_OK;
}
esp_err_t EEPROM::write_nvs_map_data(const char*, const int16_t*, size_t) { return ESP_OK; }

// ---- helpers copied from gearbox.cpp ------------------------------------------------
static GearboxGear gear_from_idx(uint8_t idx) {
    if (idx >= 1 && idx <= 5) return (GearboxGear)idx;
    return GearboxGear::SignalNotAvailable;
}

struct Row {
    int t_ms;
    int n2, n3, turbine, output;         // raw speed sensors
    int input_rpm, engine_rpm, output_rpm; // filtered (as in sensor_data)
    int pedal, pedal_smoothed, atf;
    int input_trq, conv_trq, drv_trq, min_trq, max_trq;
    // logged outputs
    int l_active, l_p_on, l_p_off, l_spc_req, l_mpc_req, l_corr_spc, l_corr_mpc, l_sub_shift, l_sub_mod, l_sync, l_pid, l_adder, l_s_on, l_s_off, l_req_trq, l_circ, l_shifting;
};

static void parse_int_list(const char* s, int16_t* dst, int n) {
    for (int i = 0; i < n; i++) dst[i] = 0;
    int i = 0;
    const char* p = s;
    while (*p && i < n) {
        dst[i++] = (int16_t)strtol(p, (char**)&p, 10);
        while (*p == ',' || *p == ' ') p++;
    }
}

int main(int argc, char** argv) {
    if (argc < 3) {
        fprintf(stderr, "usage: %s <shift.txt> <out.txt> [--start-cycle N] [--spc-offsets a,b,..] [--prefill-offsets a,b,..] [--verbose] [--atf N]\n", argv[0]);
        return 1;
    }
    const char* in_path = argv[1];
    const char* out_path = argv[2];
    int start_cycle = 0;   // cycles after t0 at which the algorithm starts
    int16_t spc_offsets[8] = {0}, prefill_offsets[8] = {0}, apply_trq_offsets[8] = {0}, free_trq_offsets[8] = {0};
    int atf_override = INT16_MAX;
    int ind_from_driver = 0;   // what-if: indicated/static torque taken from the (plausible) driver torque
    int recompute_input_trq = 0; // what-if: derive input torque from driver torque through the ACTIVE TCC maps, as gearbox.cpp does
    for (int i = 3; i < argc; i++) {
        if (!strcmp(argv[i], "--start-cycle")) start_cycle = atoi(argv[++i]);
        else if (!strcmp(argv[i], "--recompute-input-trq")) recompute_input_trq = 1;
        else if (!strcmp(argv[i], "--spc-offsets")) parse_int_list(argv[++i], spc_offsets, 8);
        else if (!strcmp(argv[i], "--prefill-offsets")) parse_int_list(argv[++i], prefill_offsets, 8);
        else if (!strcmp(argv[i], "--apply-trq-offsets")) parse_int_list(argv[++i], apply_trq_offsets, 8);
        else if (!strcmp(argv[i], "--free-trq-offsets")) parse_int_list(argv[++i], free_trq_offsets, 8);
        else if (!strcmp(argv[i], "--verbose")) SIM_LOG_VERBOSE = 1;
        else if (!strcmp(argv[i], "--atf")) atf_override = atoi(argv[++i]);
        else if (!strcmp(argv[i], "--ind-from-driver")) ind_from_driver = 1;
    }

    // Vehicle config from the logged TCM_CORE_CONFIG snapshot
    memset(&VEHICLE_CONFIG, 0, sizeof(VEHICLE_CONFIG));
    VEHICLE_CONFIG.diff_ratio = 3070;
    VEHICLE_CONFIG.wheel_circumference = 1975;
    VEHICLE_CONFIG.red_line_rpm_diesel = 4500;
    VEHICLE_CONFIG.engine_type = 0;
    VEHICLE_CONFIG.egs_can_type = 1;
    VEHICLE_CONFIG.shifter_style = 1;
    VEHICLE_CONFIG.engine_drag_torque = 540;

    FILE* f = fopen(in_path, "r");
    if (!f) { perror("open"); return 1; }
    int change_i, up_i, from_g, to_g, t0, nrows, pre_ms;
    if (fscanf(f, "%d %d %d %d %d %d %d", &change_i, &up_i, &from_g, &to_g, &t0, &nrows, &pre_ms) != 7) { fprintf(stderr, "bad header\n"); return 1; }
    std::vector<Row> rows;
    for (int i = 0; i < nrows; i++) {
        Row r;
        int n = fscanf(f, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
            &r.t_ms, &r.n2, &r.n3, &r.turbine, &r.output, &r.input_rpm, &r.engine_rpm, &r.output_rpm, &r.pedal, &r.pedal_smoothed, &r.atf,
            &r.input_trq, &r.conv_trq, &r.drv_trq, &r.min_trq, &r.max_trq,
            &r.l_active, &r.l_p_on, &r.l_p_off, &r.l_spc_req, &r.l_mpc_req, &r.l_corr_spc, &r.l_corr_mpc, &r.l_sub_shift, &r.l_sub_mod, &r.l_sync, &r.l_pid, &r.l_adder, &r.l_s_on, &r.l_s_off, &r.l_req_trq, &r.l_circ, &r.l_shifting);
        if (n != 33) { fprintf(stderr, "bad row %d (%d fields)\n", i, n); return 1; }
        if (atf_override != INT16_MAX) r.atf = atf_override;
        rows.push_back(r);
    }
    fclose(f);

    FILE* out = fopen(out_path, "w");
    if (!out) { perror("out"); return 1; }
    log_out = out;

    // ---- construct the firmware objects ------------------------------------------
    SensorData sd;
    memset(&sd, 0, sizeof(sd));
    standard = new AbstractProfile(0, S_UPSHIFT_TIME_MAP, S_DOWNSHIFT_TIME_MAP);
    manual = new AbstractProfile(4, nullptr, nullptr);
    race = new AbstractProfile(5, nullptr, nullptr);
    PressureManager* pm = new PressureManager(&sd, 330);
    pressure_manager = pm;
    ShiftAdaptationSystem* adapter = new ShiftAdaptationSystem();
    adapter->spc_offset_map->replace_data_content(spc_offsets, 8);
    adapter->prefill_time_map->replace_data_content(prefill_offsets, 8);
    adapter->applying_torque_offset->replace_data_content(apply_trq_offsets, 8);
    adapter->freeing_torque_offset->replace_data_content(free_trq_offsets, 8);
    TorqueConverter* tcc = new TorqueConverter();

    GearboxConfiguration cfg;
    cfg.max_torque = 330;
    for (int i = 0; i < 5; i++) {
        float r = MECH_PTR->ratio_table[i + 1] / 1000.0f;
        cfg.bounds[i] = GearRatioInfo{r * 1.1f, r, r * 0.9f};
    }
    for (int i = 5; i < 7; i++) {
        float r = -(float)MECH_PTR->ratio_table[i + 1] / 1000.0f;
        cfg.bounds[i] = GearRatioInfo{r * 0.9f, r, r * 1.1f};
    }

    GearChange req = (GearChange)change_i;
    bool is_upshift = up_i != 0;
    GearboxGear actual_gear = gear_from_idx(from_g);
    GearboxGear target_gear = gear_from_idx(to_g);

    auto load_sensors = [&](const Row& r) {
        sd.input_rpm = r.input_rpm;
        sd.engine_rpm = r.engine_rpm;
        sd.output_rpm = r.output_rpm;
        sd.pedal_pos = r.pedal;
        sd.pedal_pos_smoothed = r.pedal_smoothed;
        sd.atf_temp = r.atf;
        sd.input_torque = r.input_trq;
        sd.converted_torque = ind_from_driver ? r.drv_trq : r.conv_trq;
        sd.indicated_torque = ind_from_driver ? r.drv_trq : r.conv_trq;   // EGS51: m_ind == static converted
        sd.converted_driver_torque = r.drv_trq;
        sd.min_torque = r.min_trq;
        sd.max_torque = r.max_trq;
        sd.pump_torque = InputTorqueModel::get_pump_torque(sd.engine_rpm, sd.input_rpm);
        sd.tcc_trq_multiplier = InputTorqueModel::get_input_torque_factor(sd.engine_rpm, sd.input_rpm);
        if (recompute_input_trq) sd.input_torque = InputTorqueModel::get_input_torque(sd.engine_rpm, sd.input_rpm, r.drv_trq);
        sd.gear_ratio = r.output_rpm > 0 ? (float)r.input_rpm / (float)r.output_rpm : 0;
        sd.targ_gear_ratio = cfg.bounds[from_g - 1].ratio;
    };

    // Pre-shift cycles: mimic the main loop's MPC working pressure so the pressure manager state is realistic
    int start_row = 0;
    for (size_t i = 0; i < rows.size(); i++) {
        if (rows[i].t_ms >= start_cycle * 20) { start_row = (int)i; break; }
        load_sensors(rows[i]);
        sim_clock_ms = t0 + rows[i].t_ms;
        pm->set_target_modulating_pressure(pm->find_working_mpc_pressure(actual_gear, true));
        pm->update_pressures(actual_gear, GearChange::_IDLE);
    }
    load_sensors(rows[start_row]);
    sim_clock_ms = t0 + rows[start_row].t_ms;

    // ---- elapse_shift ---------------------------------------------------------------
    uint8_t egs_map_idx_lookup = fwd_gearchange_egs_map_lookup_idx(req);
    ShiftCharacteristics chars = standard->get_shift_characteristics(req, &sd);
    chars.target_shift_time = MAX(100, chars.target_shift_time);
    CircuitInfo cinf = pm->get_basic_shift_data(req);
    cinf.map_idx = egs_map_idx_lookup;

    ShiftPressures p_now = {};
    pm->register_shift_pressure_data(&p_now);
    SpeedSensors speeds = {(uint16_t)rows[start_row].n2, (uint16_t)rows[start_row].n3, (uint16_t)rows[start_row].turbine, (uint16_t)rows[start_row].output};
    ShiftClutchData now_cs = ClutchSpeedModel::get_shifting_clutch_speeds(speeds, req, cfg.bounds);
    Clutch applying = get_clutch_to_apply(req);
    Clutch releasing = get_clutch_to_release(req);
    PrefillData prefill_data = pm->make_fill_data(applying);
    int MOD_MAX = pm->get_max_solenoid_pressure();
    int SPC_MAX = pm->get_max_shift_pressure(egs_map_idx_lookup);
    TorqueRequstData trd = { TorqueRequestControlType::None, TorqueRequestBounds::LessThan, 0 };

    ShiftInterfaceData sid = {
        .profile = standard, .MOD_MAX = MOD_MAX, .SPC_MAX = SPC_MAX, .shift_flags = 0, .change = req,
        .applying = applying, .releasing = releasing, .curr_g = actual_gear, .targ_g = target_gear, .inf = cinf,
        .release_spring_on_clutch = pm->get_spring_pressure(applying), .release_spring_off_clutch = pm->get_spring_pressure(releasing),
        .prefill_info = prefill_data, .chars = chars, .ptr_r_clutch_speeds = &now_cs, .ptr_w_pressures = &p_now, .ptr_w_trq_req = &trd,
        .tcc = tcc, .adaptation_mgr = adapter, .manual_shift = false, .trq_req_en = true
    };
    sid.shift_flags = 0;
    ShiftHelpers::calc_shift_flags(&sid, &sd, true);
    float threshold_torque = VEHICLE_CONFIG.engine_drag_torque / 10.0;
    ShiftingAlgorithm* algo;
    const char* algo_name;
    if (is_upshift) {
        if (sd.converted_torque <= -threshold_torque / 2) { algo = new ReleasingShift(&sid); algo_name = "release"; }
        else { algo = new CrossoverShift(&sid); algo_name = "crossover"; }
    } else {
        bool is_release = true;
        if ((sd.converted_torque < threshold_torque && (sid.shift_flags & SHIFT_FLAG_COAST) != 0) || ((sid.shift_flags & SHIFT_FLAG_COAST_54_43) != 0)) is_release = false;
        if (is_release) { algo = new ReleasingShift(&sid); algo_name = "release"; }
        else { algo = new CrossoverShift(&sid); algo_name = "crossover"; }
    }
    fprintf(out, "HEAD algo=%s change=%d up=%d target_shift_time=%d fill_cycles=%d fill_p=%d low_fill_p=%d SPC_MAX=%d MOD_MAX=%d spring_on=%d spring_off=%d flags=%u start_cycle=%d conv_trq0=%d\n",
        algo_name, change_i, up_i, chars.target_shift_time, prefill_data.fill_cycles, prefill_data.fill_pressure_on_clutch, prefill_data.low_fill_pressure_on_clutch,
        SPC_MAX, MOD_MAX, sid.release_spring_on_clutch, sid.release_spring_off_clutch, (unsigned)sid.shift_flags, start_cycle, sd.converted_torque);
    fprintf(out, "COLS t_ms phase sub_shift sub_mod p_on p_off spc_req mpc_req corr_spc corr_mpc sync_rpm pid adder s_on s_off req_ty req_amt circ input_rpm engine_rpm input_trq flaring\n");

    uint8_t algo_phase_id = 0;
    uint32_t phase_elapsed = 0, total_elapsed = 0;
    bool result = false;
    bool process = true;
    int cycles = 0;
    int max_phase = algo->max_shift_stage_id();
    for (size_t i = start_row; i < rows.size() && process; i++) {
        const Row& r = rows[i];
        load_sensors(r);
        sim_clock_ms = t0 + r.t_ms;
        speeds = SpeedSensors{(uint16_t)r.n2, (uint16_t)r.n3, (uint16_t)r.turbine, (uint16_t)r.output};
        bool stationary_shift = sd.input_rpm < 100 && sd.output_rpm < 100;
        int abs_input_torque = abs(sd.input_torque);
        now_cs = ClutchSpeedModel::get_shifting_clutch_speeds(speeds, req, cfg.bounds);
        bool flaring = false;
        if (!stationary_shift) {
            flaring = (now_cs.off_clutch_speed < -50 || now_cs.on_clutch_speed < -50);
        }
        uint8_t step_result = algo->step(algo_phase_id, abs_input_torque, stationary_shift, is_upshift, phase_elapsed, total_elapsed, pm, &sd);
        ShiftAlgoFeedback fb = algo->get_diag_feedback(algo_phase_id);
        pm->set_target_modulating_pressure(p_now.mod_sol_req);
        pm->set_target_shift_pressure(p_now.shift_sol_req);
        pm->update_pressures(target_gear, req);
        cycles++;
        fprintf(out, "ROW %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",
            r.t_ms, algo_phase_id, fb.subphase_shift, fb.subphase_mod, fb.p_on, fb.p_off, (int)p_now.shift_sol_req, (int)p_now.mod_sol_req,
            pm->get_corrected_spc_pressure(), pm->get_corrected_modulating_pressure(), fb.sync_rpm, fb.pid_torque, fb.adder_torque, fb.s_on, fb.s_off,
            (int)(stationary_shift ? TorqueRequestControlType::None : trd.ty), (int)(stationary_shift ? 0 : trd.amount), pm->get_active_shift_circuits(),
            sd.input_rpm, sd.engine_rpm, sd.input_torque, flaring ? 1 : 0);
        if (step_result == 0) {
            phase_elapsed += 20;
        } else if (step_result == STEP_RES_END_SHIFT) {
            result = true; break;
        } else if (step_result == STEP_RES_FAILURE) {
            break;
        } else {
            phase_elapsed = 0;
            if (step_result == STEP_RES_NEXT) algo_phase_id += 1; else algo_phase_id = step_result;
            fprintf(out, "PHASE %d -> %d\n", r.t_ms, algo_phase_id);
        }
        total_elapsed += 20;
    }
    int timed_out = 0;
#ifdef NEW_ALGO
    timed_out = algo->did_time_out() ? 1 : 0;
#endif
    fprintf(out, "END result=%d cycles=%d duration_ms=%d timed_out=%d final_phase=%d max_phase=%d tcc_starts=%d tcc_ends=%d\n",
        result ? 1 : 0, cycles, cycles * 20, timed_out, algo_phase_id, max_phase, tcc->starts, tcc->ends);
    fclose(out);
    return 0;
}
