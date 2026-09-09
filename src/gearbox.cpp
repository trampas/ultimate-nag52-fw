#include "gearbox.h"
#include "common_structs_ops.h"
#include "nvs/eeprom_config.h"
#include "adv_opts.h"
#include <tcu_maths.h>
#include "speaker.h"
#include "clock.hpp"
#include "shift_trace.h"
#include "road_load.h"
#include "nvs/device_mode.h"
#include "egs_calibration/calibration_structs.h"
#include "shifting_algo/s_algo.h"
#include "shifting_algo/shift_crossover.h"
#include "shifting_algo/shift_release.h"
#include "tcu_io/tcu_io.hpp"
#include <math.h>

#define SBS SBS_CURRENT_SETTINGS

const DRAM_ATTR uint8_t AVG_SAMPLES_500MS = 500 / 20;

// ONLY FOR FORWARD GEARS!
int calc_input_rpm_from_req_gear(const int output_rpm, const GearboxGear req_gear, const GearboxConfiguration* gb_config)
{
    int calculated = output_rpm;
    switch (req_gear)
    {
    case GearboxGear::First:
        calculated *= gb_config->bounds[0].ratio;
        break;
    case GearboxGear::Second:
        calculated *= gb_config->bounds[1].ratio;
        break;
    case GearboxGear::Third:
        calculated *= gb_config->bounds[2].ratio;
        break;
    case GearboxGear::Fourth:
        calculated *= gb_config->bounds[3].ratio;
        break;
    case GearboxGear::Fifth:
        calculated *= gb_config->bounds[4].ratio;
        break;
    case GearboxGear::Reverse_First:
        calculated *= abs(gb_config->bounds[5].ratio);
        break;
    case GearboxGear::Reverse_Second:
        calculated *= abs(gb_config->bounds[6].ratio);
        break;
    default:
        break;
    }
    return calculated;
}

Gearbox::Gearbox(Shifter* shifter) : shifter(shifter), kickdown(), brake_pedal()
{
    this->current_profile = nullptr;
    egs_can_hal->set_drive_profile(GearboxProfile::Underscore); // Uninitialized
    this->profile_mutex = portMUX_INITIALIZER_UNLOCKED;
    this->speed_sensors = SpeedSensors {
        .n2 = 0,
        .n3 = 0,
        .turbine = 0,
        .output = 0,
    };
    this->sensor_data = SensorData{
        .input_rpm = 0,
        .engine_rpm = 0,
        .output_rpm = 0,
        .pedal_pos = 0,
        .pedal_pos_smoothed = 0,
        .atf_temp = 0,
        .input_torque = 0,
        .converted_torque = 0,
        .converted_driver_torque = 0,
        .indicated_torque = 0,
        .max_torque = 0,
        .min_torque = 0,
        .pump_torque = 0,
        .last_shift_time = 0,
        .gear_ratio = 0.0F,
        .targ_gear_ratio = 0.0F,
        .tcc_trq_multiplier = 1.0,
        .kickdown_pressed = false,
        .brake_pressed = false,
        .wheel_speed_mps = 0,
        .acceleration_ms2 = 0
    };
    this->output_data = OutputData{
        .torque_req_amount = 0,
        .ctrl_type = TorqueRequestControlType::None,
        .bounds = TorqueRequestBounds::LessThan,
    };

    float r1 = ((float)(MECH_PTR->ratio_table[1])) / 1000.0;
    float r2 = ((float)(MECH_PTR->ratio_table[2])) / 1000.0;
    float r3 = ((float)(MECH_PTR->ratio_table[3])) / 1000.0;
    float r4 = ((float)(MECH_PTR->ratio_table[4])) / 1000.0;
    float r5 = ((float)(MECH_PTR->ratio_table[5])) / 1000.0;
    float rr1 = ((float)(MECH_PTR->ratio_table[6]) * -1) / 1000.0;
    float rr2 = ((float)(MECH_PTR->ratio_table[7]) * -1) / 1000.0;

    this->gearboxConfig.max_torque = 330;
    if (MECH_PTR->gb_ty == 0) {
        this->gearboxConfig.max_torque = 580;
    }
    this->gearboxConfig.bounds[0] = GearRatioInfo{ // 1st 
        .ratio_max_drift = r1 * (float)1.1,
        .ratio = r1,
        .ratio_min_drift = r1 * (float)0.9,
    };
    this->gearboxConfig.bounds[1] = GearRatioInfo{ // 2nd 
        .ratio_max_drift = r2 * (float)1.1,
        .ratio = r2,
        .ratio_min_drift = r2 * (float)0.9,
    };
    this->gearboxConfig.bounds[2] = GearRatioInfo{ // 3rd 
        .ratio_max_drift = r3 * (float)1.1,
        .ratio = r3,
        .ratio_min_drift = r3 * (float)0.9,
    };
    this->gearboxConfig.bounds[3] = GearRatioInfo{ // 4th 
        .ratio_max_drift = r4 * (float)1.1,
        .ratio = r4,
        .ratio_min_drift = r4 * (float)0.9,
    };
    this->gearboxConfig.bounds[4] = GearRatioInfo{ // 5th 
        .ratio_max_drift = r5 * (float)1.1,
        .ratio = r5,
        .ratio_min_drift = r5 * (float)0.9,
    };
    // Reverse ratios are negative, so the 1.1x value is the (more negative) minimum
    this->gearboxConfig.bounds[5] = GearRatioInfo{ // R1 
        .ratio_max_drift = rr1 * (float)0.9,
        .ratio = rr1,
        .ratio_min_drift = rr1 * (float)1.1,
    };
    this->gearboxConfig.bounds[6] = GearRatioInfo{ // R2 
        .ratio_max_drift = rr2 * (float)0.9,
        .ratio = rr2,
        .ratio_min_drift = rr2 * (float)1.1,
    };
    // Cap neighbouring forward gear bands at the geometric midpoint so they cannot overlap
    // (With +/-10%, 4th (0.90-1.10) and 5th (0.75-0.91) overlap and the first-hit scan picks 4th)
    for (int i = 0; i < 4; i++) {
        float mid = sqrtf(this->gearboxConfig.bounds[i].ratio * this->gearboxConfig.bounds[i+1].ratio);
        if (this->gearboxConfig.bounds[i].ratio_min_drift < mid) {
            this->gearboxConfig.bounds[i].ratio_min_drift = mid;
        }
        if (this->gearboxConfig.bounds[i+1].ratio_max_drift > mid) {
            this->gearboxConfig.bounds[i+1].ratio_max_drift = mid;
        }
    }
    // IMPORTANT - Set the Ratio2/Ratio1 multiplier for the sensor RPM reading algorithm!
    TCUIO::set_2_1_ratio(r1 / r2);

    this->pressure_mgr = new PressureManager(&this->sensor_data, this->gearboxConfig.max_torque);
    this->tcc = new TorqueConverter(this->gearboxConfig.max_torque);
    this->shift_adapter = new ShiftAdaptationSystem();
    pressure_manager = this->pressure_mgr;
    adaptation_manager = this->shift_adapter;
    // Wait for solenoid routine to complete
    if (!Solenoids::init_routine_completed())
    {
        vTaskDelay(1);
    }
    if (VEHICLE_CONFIG.engine_type == 1)
    {
        this->redline_rpm = VEHICLE_CONFIG.red_line_rpm_petrol;
    }
    else
    {
        this->redline_rpm = VEHICLE_CONFIG.red_line_rpm_diesel;
    }
    if (this->redline_rpm < 4000)
    {
        this->redline_rpm = 4000; // just in case
    }
    this->diff_ratio_f = (float)VEHICLE_CONFIG.diff_ratio / 1000.0;
    this->input_rpm_delta = new DeltaTracker(5); // 5 x 100 ms: fast enough to predict the redline
    this->pedal_delta = new DeltaTracker(25);
}

bool Gearbox::is_stationary() const {
    // The output shaft is what says the car has stopped. The old test also demanded
    // input_rpm < 100, but standing in gear the converter drags the turbine to
    // 100-300 rpm at idle, so a genuine standstill never satisfied it: a 2-1 coast
    // downshift that finished at a stop was still handled as a moving shift, with
    // torque requests and flare detection live and a meaningless gear ratio
    // (output 0 gives ratios of 0 or 100+). The input bound is kept only so a dead
    // output speed sensor at road speed cannot fake a standstill.
    return this->sensor_data.output_rpm < 60 && this->sensor_data.input_rpm < 1000;
}

// -- Adaptive profile -------------------------------------------------------
// Thresholds for "the driver wants to go now". Pedal is 0-250.
#define DEMAND_PEDAL_FULL      225u   // 90 % - treat as full throttle
#define DEMAND_PEDAL_RISE       62u   // a quarter of pedal travel ...
                                      // ... within the 500 ms pedal_history window
#define AGILITY_DECAY_PER_S      4    // 100 -> 0 in ~25 s of gentle driving
#define AGILITY_ENGAGE          60u   // score at which Agility takes over ...
#define AGILITY_RELEASE         25u   // ... and the score it has to fall to first
#define AGILITY_DECEL_RPM_S    900    // output shaft decel counted as hard braking

void Gearbox::set_profile(AbstractProfile* prof)
{
    // This is called every main loop iteration with whatever the shifter says, so
    // only react to an actual change. It records what the DRIVER asked for;
    // update_adaptive_profile decides what the shift logic actually runs.
    if (nullptr != prof && prof != this->selected_profile)
    {
        this->selected_profile = prof;
        this->agility_score = 0;      // a deliberate profile change resets the score
        portENTER_CRITICAL(&this->profile_mutex);
        this->current_profile = prof;
        portEXIT_CRITICAL(&this->profile_mutex);
    }
}

/**
 * @brief Has the driver just asked for performance?
 *
 * Any of: kickdown, near-full throttle, or a quick stab - a quarter of pedal
 * travel inside the 500 ms history window. The existing pedal_delta tracker is
 * not usable for this: it is a first order filter over 25 samples at 100 ms, so
 * its time constant is 2.5 s and a stab is smoothed away long before it shows.
 */
/**
 * @brief Instantaneous agility demand, 0-100, from what the driver is doing now.
 *
 * The strongest single indicator is how fast the pedal went down, not where it
 * ended up - a quarter of travel inside 500 ms is a deliberate request even if
 * the pedal never gets near the floor. Absolute position and kickdown are the
 * other two, and hard braking counts because someone braking hard for a corner
 * usually wants the gear when they get back on it.
 *
 * The existing pedal_delta tracker cannot serve here: it is a first order filter
 * over 25 samples at 100 ms, so its time constant is 2.5 s and a stab is smoothed
 * away long before it shows.
 */
uint8_t Gearbox::agility_demand(void)
{
    if (this->sensor_data.kickdown_pressed) {
        return 100u;
    }
    uint16_t demand = 0;
    // absolute pedal: 40 % pedal -> 0, full pedal -> 100
    if (this->sensor_data.pedal_pos > 100u) {
        demand = ((uint16_t)(this->sensor_data.pedal_pos - 100u) * 100u) / 150u;
    }
    // rate of application over the 500 ms window, the dominant term
    uint8_t lowest = UINT8_MAX;
    for (uint8_t i = 0; i < sizeof(this->pedal_history); i++) {
        if (this->pedal_history[i] < lowest) {
            lowest = this->pedal_history[i];
        }
    }
    if (this->sensor_data.pedal_pos > lowest) {
        uint16_t rise = this->sensor_data.pedal_pos - lowest;
        uint16_t by_rate = (rise * 100u) / DEMAND_PEDAL_RISE;   // full marks at a quarter of travel
        if (by_rate > demand) { demand = by_rate; }
    }
    // hard braking - the driver is likely to want the gear on the way out
    if (this->decel_rpm_s < -AGILITY_DECEL_RPM_S) {
        uint16_t by_brake = ((uint16_t)(-this->decel_rpm_s - AGILITY_DECEL_RPM_S) * 100u) / AGILITY_DECEL_RPM_S;
        if (by_brake > demand) { demand = by_brake; }
    }
    return (uint8_t)MIN(100u, demand);
}

/**
 * @brief Track agility demand: rise at once, fall slowly.
 *
 * Asymmetric on purpose. A driver who asks for performance should get it on the
 * same pedal application, but should not lose it because they lifted for a
 * moment mid-overtake, so the score only falls at AGILITY_DECAY_PER_S.
 */
void Gearbox::update_agility_score(void)
{
    uint32_t now = GET_CLOCK_TIME();
    if (0 == this->last_score_ms) {
        this->last_score_ms = now;
        this->last_out_rpm = this->sensor_data.output_rpm;
        return;
    }
    uint32_t dt = now - this->last_score_ms;
    if (dt < 100u) {
        return;                     // evaluate at 10 Hz, the inputs are slower than that
    }
    this->decel_rpm_s = (int16_t)(((int32_t)this->sensor_data.output_rpm -
                                   (int32_t)this->last_out_rpm) * 1000 / (int32_t)dt);
    this->last_out_rpm = this->sensor_data.output_rpm;
    this->last_score_ms = now;

    uint8_t demand = this->agility_demand();
    if (demand > this->agility_score) {
        this->agility_score = demand;                      // rise immediately
        this->agility_decay_ms = 0;
    } else {
        // One point per 1000/AGILITY_DECAY_PER_S ms. Accumulated, because at the
        // 100 ms step this runs at, 4 * 100 / 1000 truncated to zero and the
        // score never came down: on the 2026-09-08 04:59 drive it sat at 100
        // for eight minutes of coasting with the pedal released.
        this->agility_decay_ms += (uint16_t)dt;
        const uint16_t ms_per_point = 1000u / AGILITY_DECAY_PER_S;
        uint16_t decay = this->agility_decay_ms / ms_per_point;
        this->agility_decay_ms -= decay * ms_per_point;
        this->agility_score = (this->agility_score > decay) ?
            (uint8_t)(this->agility_score - decay) : 0u;
    }
}

DATA_DRIVING_DYNAMICS Gearbox::get_driving_dynamics(void)
{
    uint8_t lowest = UINT8_MAX;
    for (uint8_t i = 0; i < sizeof(this->pedal_history); i++) {
        if (this->pedal_history[i] < lowest) { lowest = this->pedal_history[i]; }
    }
    RoadLoad rl = RoadLoadEstimator::get();
    return DATA_DRIVING_DYNAMICS {
        .agility_score = this->agility_score,
        .agility_demand = this->agility_demand(),
        .pedal_pos = (uint8_t)MIN(250, (int)this->sensor_data.pedal_pos),
        .pedal_rise = (uint8_t)((this->sensor_data.pedal_pos > lowest) ?
                                MIN(250, (int)this->sensor_data.pedal_pos - (int)lowest) : 0),
        .decel_rpm_s = this->decel_rpm_s,
        .profile_id = (uint8_t)((nullptr != this->current_profile) ? this->current_profile->get_profile_id() : 0xFF),
        .selected_id = (uint8_t)((nullptr != this->selected_profile) ? this->selected_profile->get_profile_id() : 0xFF),
        .brake_pressed = (uint8_t)(this->sensor_data.brake_pressed ? 1 : 0),
        .kickdown_pressed = (uint8_t)(this->sensor_data.kickdown_pressed ? 1 : 0),
        .terrain_coeff = rl.terrain_coeff,
        .road_mass_kg = rl.mass_kg,
        .road_confidence = rl.confidence,
        .road_updating = rl.updating,
    };
}

void Gearbox::update_adaptive_profile(void)
{
    // Only Comfort opts in. Anything else the driver selected is left alone.
    if (nullptr == this->selected_profile || this->selected_profile != static_cast<AbstractProfile*>(comfort) ||
        nullptr == agility) {
        return;
    }
    // Hysteresis, so a score hovering at the threshold cannot swap profiles back
    // and forth. Once engaged it stays until the driver has genuinely settled.
    bool want_agility = (this->current_profile == static_cast<AbstractProfile*>(agility))
        ? (this->agility_score > AGILITY_RELEASE)
        : (this->agility_score >= AGILITY_ENGAGE);
    AbstractProfile* target = want_agility ? static_cast<AbstractProfile*>(agility) : this->selected_profile;
    // Never swap the maps out from under a shift in progress - the shift thread
    // reads chars/target time from the profile it started with.
    if (!this->shifting && target != this->current_profile) {
        ESP_LOG_LEVEL(ESP_LOG_INFO, "GEARBOX", "Adaptive profile -> %s (agility score %d)",
            want_agility ? "AGILITY" : "COMFORT", this->agility_score);
        portENTER_CRITICAL(&this->profile_mutex);
        this->current_profile = target;
        portEXIT_CRITICAL(&this->profile_mutex);
    }
}

bool Gearbox::blend_active(void) const
{
    return 0 != SBS_CURRENT_SETTINGS.agility_blend &&
           nullptr != this->selected_profile && this->selected_profile == static_cast<AbstractProfile*>(comfort) &&
           nullptr != comfort && nullptr != agility;
}

bool Gearbox::current_arm_is_a(void) const
{
    // Odd shifts get the feature, even shifts the baseline. With interleaving
    // off every shift is arm A, so the stamp reads the same either way.
    return !SBS_CURRENT_SETTINGS.ab_interleave || (0 != (this->fwd_shift_count & 1u));
}

float Gearbox::agility_blend_weight(void)
{
    int lo = SBS_CURRENT_SETTINGS.agility_blend_lo;
    int hi = SBS_CURRENT_SETTINGS.agility_blend_hi;
    if (hi <= lo) { hi = lo + 1; }
    int sc = this->agility_score;
    if (sc <= lo) { return 0.0f; }
    if (sc >= hi) { return 1.0f; }
    return (float)(sc - lo) / (float)(hi - lo);
}

/**
 * @brief Shift point with the Comfort/Agility maps blended on the agility score.
 *
 * Only when SBS agility_blend is 2, Comfort is selected, and this shift falls in
 * arm A; otherwise the profile the swap chose decides, exactly as before. The
 * Comfort rule of no upshift on the brake is kept, since the blend is Comfort
 * with some Agility mixed in rather than a new profile.
 */
bool Gearbox::profile_should_upshift(AbstractProfile* p, GearboxGear g, SensorData* sd)
{
    if (2 == SBS_CURRENT_SETTINGS.agility_blend && this->blend_active() && this->current_arm_is_a() &&
        nullptr != comfort->get_upshift_map() && nullptr != agility->get_upshift_map()) {
        if (g == GearboxGear::Fifth) { return false; }
        float w = this->agility_blend_weight();
        float pedal = sd->pedal_pos / 2.5f;
        float t_c = comfort->get_upshift_map()->get_value(pedal, (float)g);
        float t_a = agility->get_upshift_map()->get_value(pedal, (float)g);
        float threshold = t_c + w * (t_a - t_c);
        bool can_upshift = (float)sd->input_rpm > threshold;
        if (sd->brake_pressed) { can_upshift = false; }
        return can_upshift;
    }
    return p->should_upshift(g, sd);
}

bool Gearbox::profile_should_downshift(AbstractProfile* p, GearboxGear g, SensorData* sd)
{
    if (2 == SBS_CURRENT_SETTINGS.agility_blend && this->blend_active() && this->current_arm_is_a() &&
        nullptr != comfort->get_downshift_map() && nullptr != agility->get_downshift_map()) {
        if (g == GearboxGear::First) { return false; }
        float w = this->agility_blend_weight();
        float pedal = sd->pedal_pos / 2.5f;
        float t_c = comfort->get_downshift_map()->get_value(pedal, (float)g);
        float t_a = agility->get_downshift_map()->get_value(pedal, (float)g);
        float threshold = t_c + w * (t_a - t_c);
        return (float)sd->input_rpm < threshold;
    }
    return p->should_downshift(g, sd);
}

/**
 * @brief Learn from the shift the trace just closed.
 *
 * Runs in the controller loop, after ShiftTrace::sample has finalised a
 * quality vector and while no shift is in progress, so the shift thread is not
 * reading the cells being written. The decision itself is a pure function in
 * adaptation/quality_adapt.cpp; this gathers its inputs and applies the result.
 */
void Gearbox::quality_adaptation_step(void)
{
    ShiftTraceEvent ev;
    if (!ShiftTrace::take_completed(&ev)) {
        return;
    }
    QualityContext ctx = {
        .change = this->shift_ctx.change,
        .agility_score = ev.agility_score,
        .manual = this->shift_ctx.manual,
        .kickdown = this->shift_ctx.kickdown,
        .flared = this->shift_ctx.flared,
        .atf_temp = this->sensor_data.atf_temp,
        .output_rpm = this->shift_ctx.output_rpm,
        .terrain_coeff = 0,
        .road_confidence = 0,
        .spc_offset_now = 0,
        .prefill_offset_now = 0,
    };
    RoadLoad rl = RoadLoadEstimator::get();
    ctx.terrain_coeff = rl.terrain_coeff;
    ctx.road_confidence = rl.confidence;
    // A garage shift, or a shift the sampler saw before elapse_shift stamped it,
    // has no context we can trust - do not learn from it.
    if (0 == (ev.stamp.flags & SHIFT_STAMP_ANNOTATED)) {
        ctx.change = GearChange::_IDLE;
    }
    uint8_t spc_cell = adapt_spc_cell(ctx.change);
    uint8_t pre_cell = adapt_prefill_cell(ctx.change);
    if (nullptr != this->shift_adapter && 0xFF != spc_cell && 0xFF != pre_cell) {
        ctx.spc_offset_now = this->shift_adapter->get_adapt_spc_offset(spc_cell);
        ctx.prefill_offset_now = this->shift_adapter->get_prefill_cycles_offset(pre_cell);
    }
    QualityDecision d = quality_decide(&ev.quality, &ctx, &ADP_CURRENT_SETTINGS);
    if (nullptr != this->shift_adapter && 0xFF != spc_cell && 0xFF != pre_cell) {
        if (0 != d.spc_delta) {
            this->shift_adapter->offset_spc_pressure(spc_cell, d.spc_delta);
        }
        if (0 != d.prefill_delta) {
            this->shift_adapter->offset_prefill_cycles(pre_cell, (int8_t)d.prefill_delta);
        }
    }
    if (QR_DISABLED != d.reason) {
        ESP_LOG_LEVEL(ESP_LOG_INFO, "QADAPT",
            "%d>%d %s: jerk %u response %u hole %u slip %lu -> spc %+d prefill %+d (cells %d/%d now %d/%d)",
            ev.gear_from, ev.gear_to, quality_reason_text(d.reason),
            (unsigned)ev.quality.peak_jerk, (unsigned)ev.quality.response_ms, (unsigned)ev.quality.torque_hole,
            (unsigned long)ev.quality.slip_energy_j, d.spc_delta, d.prefill_delta, spc_cell, pre_cell,
            ctx.spc_offset_now + d.spc_delta, ctx.prefill_offset_now + d.prefill_delta);
    }
    ShiftTrace::record_adaptation(d.reason, d.spc_delta, d.prefill_delta);
}

esp_err_t Gearbox::start_controller()
{
    xTaskCreatePinnedToCore(Gearbox::start_controller_internal, "GEARBOX", 32768, static_cast<void*>(this), 10, nullptr, 1);
    return ESP_OK;
}

GearboxGear gear_from_idx(uint8_t idx)
{
    // Only for drivable gears. P/R/SNV is never used
    GearboxGear ret = GearboxGear::SignalNotAvailable;
    if (likely(idx >= 1 && idx <= 5)) {
        ret = (GearboxGear)(idx); // Direct cast for gears 1-5
    }
    else if (idx == 6) {
        ret = GearboxGear::Reverse_First;
    }
    else if (idx == 7) {
        ret = GearboxGear::Reverse_Second;
    }
    return ret;
}

bool is_controllable_gear(GearboxGear g)
{
    bool controllable = true;
    if (unlikely(g == GearboxGear::Park || g == GearboxGear::Neutral || g == GearboxGear::SignalNotAvailable)) {
        controllable = false;
    }
    return controllable;
}

float ratio_absolute(GearboxGear g, GearboxConfiguration* cfg) {
    switch (g) {
    case GearboxGear::First:
        return cfg->bounds[0].ratio;
    case GearboxGear::Second:
        return cfg->bounds[1].ratio;
    case GearboxGear::Third:
        return cfg->bounds[2].ratio;
    case GearboxGear::Fourth:
        return cfg->bounds[3].ratio;
    case GearboxGear::Fifth:
        return cfg->bounds[4].ratio;
    case GearboxGear::Reverse_First:
        return abs(cfg->bounds[5].ratio);
    case GearboxGear::Reverse_Second:
        return abs(cfg->bounds[6].ratio);
    default:
        return 0;
    }
}

bool is_fwd_gear(GearboxGear g)
{
    bool is_fwd = false;
    if (likely((uint8_t)g >= 1 && (uint8_t)g <= 5)) {
        is_fwd = true;
    }
    return is_fwd;
}

const char* gear_to_text(GearboxGear g)
{
    switch (g)
    {
    case GearboxGear::First:
        return "D1";
    case GearboxGear::Second:
        return "D2";
    case GearboxGear::Third:
        return "D3";
    case GearboxGear::Fourth:
        return "D4";
    case GearboxGear::Fifth:
        return "D5";
    case GearboxGear::Reverse_First:
        return "R1";
    case GearboxGear::Reverse_Second:
        return "R2";
    case GearboxGear::Park:
        return "P";
    case GearboxGear::SignalNotAvailable:
        return "SNA";
    case GearboxGear::Neutral:
        return "N";
    default:
        return "";
    }
}

void Gearbox::inc_gear_request()
{
    this->ask_upshift = true;
    this->ask_downshift = false;
    this->manual_shift = true;
}

void Gearbox::dec_gear_request()
{
    this->ask_upshift = false;
    this->ask_downshift = true;
    this->manual_shift = true;
}

void Gearbox::set_torque_request(TorqueRequestControlType ctrl_type, TorqueRequestBounds bounds, float amount) {
    this->output_data.torque_req_amount = amount;
    this->output_data.ctrl_type = ctrl_type;
    this->output_data.bounds = bounds;
    egs_can_hal->set_torque_request(ctrl_type, bounds, amount);
}

GearboxGear next_gear(GearboxGear g)
{
    GearboxGear next = g;
    uint8_t idx = (uint8_t)g;
    if (idx >= 1 && idx < 5) { // 1-4
        next = (GearboxGear)(idx + 1);
    }
    return next;
}

GearboxGear prev_gear(GearboxGear g)
{
    GearboxGear prev = g;
    uint8_t idx = (uint8_t)g;
    if (idx > 1 && idx <= 5) { // 2-5
        prev = (GearboxGear)(idx - 1);
    }
    return prev;
}

#define SHIFT_DELAY_MS 20     // 20ms steps
#define NUM_SCD_ENTRIES 100 / SHIFT_DELAY_MS // 100ms moving average window

ClutchSpeeds Gearbox::diag_get_clutch_speeds() const
{

    return ClutchSpeedModel::get_clutch_speeds_debug(
        this->speed_sensors,
        this->last_motion_gear,
        this->actual_gear,
        this->target_gear,
        this->gearboxConfig.bounds
    );
}

ShiftReportSegment Gearbox::collect_report_segment(uint64_t start_time) {
    return ShiftReportSegment{
        .static_torque = sensor_data.converted_torque,
        .driver_torque = sensor_data.converted_driver_torque,
        .egs_req_torque = (int16_t)((this->output_data.ctrl_type == TorqueRequestControlType::None) ? INT16_MAX : (int16_t)(this->output_data.torque_req_amount)),
        .engine_rpm = sensor_data.engine_rpm,
        .input_rpm = sensor_data.input_rpm,
        .output_rpm = sensor_data.output_rpm,
        .mpc_pressure = 0, //this->pressure_mgr->get_targ_mpc_clutch_pressure(),
        .spc_pressure = 0, //this->pressure_mgr->get_targ_spc_clutch_pressure(),
        .timestamp = (uint16_t)(GET_CLOCK_TIME() - start_time)
    };
}

/**
 * @brief Used to shift between forward gears
 *
 * @return uint16_t - The actual time taken to shift gears. This is fed back into the adaptation network so it can better meet 'target_shift_duration_ms'
 */

// Road load confidence (0-100) below which the anti-bog check declines to act.
// 50 is roughly 25 s of driving under power at the estimator's 10 Hz.
#define NEXT_GEAR_MIN_CONFIDENCE 50

/**
 * @brief Would the next gear still pull, or would the car bog?
 *
 * A shift map answers "is the RPM high enough to shift?", and how the next gear
 * actually pulls is discovered afterwards. On the 2026-09-07 drives that answer
 * was wrong for 33 % of upshifts, which were followed by the car slowing down in
 * the new gear - 13 of 91 by more than -0.64 m/s^2, the worst a 3-4 at 78 %
 * pedal that lost 1.6 m/s^2. The published fix is to predict first and refuse
 * the shift when the next gear cannot deliver a minimum acceleration
 * (GM US 6098004, Ford US 5669850).
 *
 * The prediction comes from the road load estimator, which has already fitted
 * the mass and grade it needs. Validated offline against the same logs by
 * scripts/next_gear.py - re-run that before changing the floor.
 *
 * Returns true (allow the shift) whenever the check cannot be trusted:
 * disabled, estimator not converged, stationary, or coasting. A check that is
 * unsure must not hold a gear. It never sees a redline protection upshift, a
 * manual shift or a range restriction - those are decided elsewhere.
 */
bool Gearbox::next_gear_can_pull(GearboxGear next) {
    if (INT16_MIN == SBS_CURRENT_SETTINGS.next_gear_min_accel_mms2) {
        return true;    // disabled - no floor can be low enough to mean anything else
    }
    // Coasting or braking: the driver is not asking for pull and input_torque is
    // negative, so a prediction here would refuse every overrun upshift.
    if (this->sensor_data.input_torque <= 0 || this->sensor_data.output_rpm < 100) {
        return true;
    }
    // The estimate means nothing without persistent excitation, so a seed value
    // must never hold a gear. Not a setting: there is no preference to express
    // here, only a right answer, and a user who lowers it gets nonsense.
    RoadLoad rl = RoadLoadEstimator::get();
    if (rl.confidence < NEXT_GEAR_MIN_CONFIDENCE) {
        return true;
    }
    float ratio = ratio_absolute(next, &this->gearboxConfig);
    if (ratio <= 0.0f) {
        return true;
    }
    int16_t predicted = RoadLoadEstimator::predict_accel_mms2(&this->sensor_data, ratio);
    if (predicted >= SBS_CURRENT_SETTINGS.next_gear_min_accel_mms2) {
        return true;
    }
    ESP_LOGI("GEARBOX", "Holding %s: %s predicted at %d mm/s2, floor %d (mass %d kg, terrain %d, conf %d)",
             gear_to_text(this->actual_gear), gear_to_text(next), predicted,
             SBS_CURRENT_SETTINGS.next_gear_min_accel_mms2, rl.mass_kg, rl.terrain_coeff, rl.confidence);
    return false;
}

/**
 * @brief Can this downshift finish before the car stops?
 *
 * Shifts are serialised: the profile is only consulted when one is not already
 * running, so a coast-down ladder is decided one rung at a time and each rung
 * takes about a second. The last one can therefore still be running when the
 * car reaches a standstill, and its closing ramp to SPC_MAX - pressure matching
 * before the shift valve drops out, which is correct and must not be softened -
 * then applies the gear against a stopped output shaft. That is the clunk.
 *
 * So project the output speed to the end of the shift and refuse it if the car
 * will have stopped by then. Refusing is safe and is the point: the car stops in
 * the higher gear and the shift happens at a true standstill instead, where
 * ShiftingAlgorithm takes its stationary path. Measured on the 2026-09-08 07:01
 * drive, the standstill 2-1 scores 0.0 m/s^3 while the one that landed on the
 * stop scored 50.9.
 *
 * The shift time map is the source for how long it will take. Actual duration
 * ran 1.20x the mapped target across 31 downshifts on that drive (p90 1.42), so
 * the projection uses the median - being a little optimistic here costs a clunk
 * only in the cases the p90 would also have caught, while being pessimistic
 * holds shifts that would have been clean.
 */
#define DOWNSHIFT_TIME_MARGIN_X100 120   // measured actual/target on downshifts
#define STANDSTILL_OUTPUT_RPM       60   // as is_stationary(); a stopped output shaft

bool Gearbox::downshift_can_finish(AbstractProfile* p)
{
    if (INT16_MIN == SBS_CURRENT_SETTINGS.downshift_min_end_rpm || nullptr == p) {
        return true;                     // disabled, or nothing to ask
    }
    int floor_rpm = SBS_CURRENT_SETTINGS.downshift_min_end_rpm;
    // A shift that starts at a true standstill is the smooth one - never hold it,
    // or the car would be left in the higher gear. Judge that on the output shaft
    // actually being stopped, the same test is_stationary() uses, and NOT against
    // floor_rpm: comparing to the tunable made raising the floor exempt exactly
    // the shifts the guard exists to hold (one starting at 200 rpm with a floor of
    // 300 is the one that lands on the stop), so the guard got weaker the harder
    // it was tuned and only ever behaved at floor 0.
    if ((int)this->sensor_data.output_rpm < STANDSTILL_OUTPUT_RPM) {
        return true;
    }
    if (this->decel_rpm_s >= 0) {
        return true;                     // not slowing down, so it cannot run out of road
    }
    uint16_t t_ms = p->get_downshift_time(this->sensor_data.input_rpm,
                                          ((float)this->sensor_data.pedal_pos * 100.0f) / 250.0f);
    int32_t t_scaled = ((int32_t)t_ms * DOWNSHIFT_TIME_MARGIN_X100) / 100;
    int32_t projected = (int32_t)this->sensor_data.output_rpm +
                        (((int32_t)this->decel_rpm_s * t_scaled) / 1000);
    if (projected >= floor_rpm) {
        return true;
    }
    ESP_LOG_LEVEL(ESP_LOG_INFO, "GEARBOX",
        "Downshift from %s held: %d rpm at %d rpm/s reaches %d over %d ms, floor %d",
        gear_to_text(this->actual_gear), this->sensor_data.output_rpm, this->decel_rpm_s,
        (int)projected, (int)t_scaled, floor_rpm);
    return false;
}

bool Gearbox::elapse_shift(GearChange req_lookup, AbstractProfile* profile, bool manually_requested)
{
    bool result = false;
    // This is important for all EGS compatibility
    uint8_t egs_map_idx_lookup = fwd_gearchange_egs_map_lookup_idx(req_lookup);

    if (nullptr != profile && req_lookup != GearChange::_IDLE && 0xFF != egs_map_idx_lookup)
    {
        ShiftCharacteristics chars = profile->get_shift_characteristics(req_lookup, &this->sensor_data);
        // Continuous Comfort/Agility blend of the target shift time (SBS agility_blend).
        // The swap's choice of profile is the arm B baseline; arm A interpolates
        // between the two time maps on the score, so a half-hearted stab gets a
        // half-way shift.
        ShiftStamp stamp = {};
        stamp.arm = this->current_arm_is_a() ? 1 : 0;
        if (this->blend_active()) {
            stamp.features |= SHIFT_FEAT_BLEND_TIME;
            if (2 == SBS_CURRENT_SETTINGS.agility_blend) { stamp.features |= SHIFT_FEAT_BLEND_POINTS; }
            if (1 == stamp.arm) {
                float w = this->agility_blend_weight();
                ShiftCharacteristics c_c = comfort->get_shift_characteristics(req_lookup, &this->sensor_data);
                ShiftCharacteristics c_a = agility->get_shift_characteristics(req_lookup, &this->sensor_data);
                chars.target_shift_time = (uint16_t)((float)c_c.target_shift_time +
                    w * ((float)c_a.target_shift_time - (float)c_c.target_shift_time));
                stamp.blend_pct = (uint8_t)(w * 100.0f + 0.5f);
            }
        }
        chars.target_shift_time = MAX(100, chars.target_shift_time);
        if (ADP_CURRENT_SETTINGS.quality_adapt) { stamp.features |= SHIFT_FEAT_QUALITY_ADAPT; }
        else { stamp.features |= SHIFT_FEAT_ALGO_ADAPT; }
        if (INT16_MIN != SBS_CURRENT_SETTINGS.next_gear_min_accel_mms2) { stamp.features |= SHIFT_FEAT_NEXT_GEAR; }
        if (SBS_CURRENT_SETTINGS.ab_interleave) { stamp.features |= SHIFT_FEAT_INTERLEAVE; }
        if (this->current_profile == static_cast<AbstractProfile*>(agility) && this->selected_profile == static_cast<AbstractProfile*>(comfort)) {
            stamp.features |= SHIFT_FEAT_PROFILE_AGILITY;
        }
        if (manually_requested) { stamp.flags |= SHIFT_STAMP_MANUAL; }
        if (this->sensor_data.kickdown_pressed) { stamp.flags |= SHIFT_STAMP_KICKDOWN; }
        stamp.target_time_ms = chars.target_shift_time;
        if (nullptr != this->shift_adapter) {
            uint8_t cell = adapt_spc_cell(req_lookup);
            stamp.spc_offset = (0xFF == cell) ? 0 : this->shift_adapter->get_adapt_spc_offset(cell);
            stamp.prefill_offset = this->shift_adapter->get_prefill_cycles_offset(egs_map_idx_lookup);
        }
        this->shift_ctx.change = req_lookup;
        this->shift_ctx.manual = manually_requested;
        this->shift_ctx.kickdown = this->sensor_data.kickdown_pressed;
        this->shift_ctx.flared = false;
        this->shift_ctx.output_rpm = this->sensor_data.output_rpm;
        ShiftTrace::annotate(&stamp);
        CircuitInfo sd = pressure_mgr->get_basic_shift_data(req_lookup);
        sd.map_idx = egs_map_idx_lookup;
        if (this->last_shift_circuit == sd.shift_circuit) { // Same shift solenoid
            while (GET_CLOCK_TIME() - sensor_data.last_shift_time < 500) {
                vTaskDelay(10);
            }
        }
        this->last_shift_circuit = sd.shift_circuit;
        bool process_shift = true;

        ShiftPressures p_now = {};

        uint32_t total_elapsed = 0;
        uint32_t phase_elapsed = 0;

        pressure_manager->register_shift_pressure_data(&p_now);

        ShiftClutchData now_cs = ClutchSpeedModel::get_shifting_clutch_speeds(this->speed_sensors, req_lookup, this->gearboxConfig.bounds);
        Clutch applying = get_clutch_to_apply(req_lookup);
        Clutch releasing = get_clutch_to_release(req_lookup);
        PrefillData prefill_data = pressure_mgr->make_fill_data(applying);

        int MOD_MAX = this->pressure_mgr->get_max_solenoid_pressure();
        int SPC_MAX = pressure_manager->get_max_shift_pressure(egs_map_idx_lookup);

        TorqueRequstData trd = {
            .ty = TorqueRequestControlType::None,
            .bounds = TorqueRequestBounds::LessThan,
            .amount = 0
        };

        bool en_trq_req = true;
        if (GearChange::_1_2 == req_lookup) {
            en_trq_req = SBS_CURRENT_SETTINGS.en_trq_req_1_2;
        } else if (GearChange::_2_3 == req_lookup) {
            en_trq_req = SBS_CURRENT_SETTINGS.en_trq_req_2_3;
        } else if (GearChange::_3_4 == req_lookup) {
            en_trq_req = SBS_CURRENT_SETTINGS.en_trq_req_3_4;
        } else if (GearChange::_4_5 == req_lookup) {
            en_trq_req = SBS_CURRENT_SETTINGS.en_trq_req_4_5;
        } else if (GearChange::_2_1 == req_lookup) {
            en_trq_req = SBS_CURRENT_SETTINGS.en_trq_req_2_1;
        } else if (GearChange::_3_2 == req_lookup) {
            en_trq_req = SBS_CURRENT_SETTINGS.en_trq_req_3_2;
        } else if (GearChange::_4_3 == req_lookup) {
            en_trq_req = SBS_CURRENT_SETTINGS.en_trq_req_4_3;
        } else if (GearChange::_5_4 == req_lookup) {
            en_trq_req = SBS_CURRENT_SETTINGS.en_trq_req_5_4;
        }

        ShiftInterfaceData sid = {
            .profile = profile,
            .MOD_MAX = MOD_MAX,
            .SPC_MAX = SPC_MAX,
            .shift_flags = 0,
            .change = req_lookup,
            .applying = applying,
            .releasing = releasing,
            .curr_g = this->actual_gear,
            .targ_g = this->target_gear,
            .inf = sd,
            .release_spring_on_clutch = pressure_manager->get_spring_pressure(applying),
            .release_spring_off_clutch = pressure_manager->get_spring_pressure(releasing),
            .prefill_info = prefill_data,
            .chars = chars,
            .ptr_r_clutch_speeds = &now_cs,
            .ptr_w_pressures = &p_now,
            .ptr_w_trq_req = &trd,
            .tcc = this->tcc,
            .adaptation_mgr = this->shift_adapter,
            .manual_shift = manually_requested,
            .trq_req_en = en_trq_req,
            .diff_ratio = this->diff_ratio_f
        };
        // To set the flag values initially
        ShiftHelpers::calc_shift_flags(&sid, &this->sensor_data, true);

        float threshold_torque = VEHICLE_CONFIG.engine_drag_torque/10.0;
        ShiftingAlgorithm* algo;
        if (is_upshift) {
            if (sensor_data.converted_driver_torque <= -threshold_torque/2) {
                algo = new ReleasingShift(&sid);
            }
            else {
                algo = new CrossoverShift(&sid);
            }
        }
        else {
            bool is_release = false;
            if (
                // Load downshift, OR coasting 32/21 (NOT Coasting 54/43)
                (sensor_data.converted_driver_torque > threshold_torque || (sid.shift_flags & SHIFT_FLAG_COAST) == 1) &&
                // (Note - 54/43 is overriden if we did a force-shift)
                ((sid.shift_flags & SHIFT_FLAG_COAST_54_43) == 0 && !manual_shift)
            ) {
                is_release = true;
            }
            if (is_release) {
                algo = new ReleasingShift(&sid);
            } else {
                algo = new CrossoverShift(&sid);
            }
        }

        uint8_t algo_phase_id = 0;
        while (process_shift) {
            uint32_t start_time = GET_CLOCK_TIME();
            bool stationary_shift = this->is_stationary();
            // Shifter moved mid shift!
            if (!is_shifter_in_valid_drive_pos(this->shifter_pos)) {
                process_shift = false;
                result = false;
                break;
            }

            int abs_input_torque = abs(sensor_data.input_torque);
            now_cs = ClutchSpeedModel::get_shifting_clutch_speeds(this->speed_sensors, req_lookup, this->gearboxConfig.bounds);

            // Shift reporting
            if (!stationary_shift) {
                if (now_cs.off_clutch_speed < -50 || now_cs.on_clutch_speed < -50) {
                    flaring = true;
                    if (!this->shift_ctx.flared) {
                        this->shift_ctx.flared = true;
                        ShiftTrace::mark(SHIFT_STAMP_FLARE);
                    }
                }
                else {
                    flaring = false;
                }

                this->set_torque_request(trd.ty, trd.bounds, trd.amount);
            }
            else {
                // If input speed is too low, use the overlap time as a way of measuring shift progress
                this->flaring = false;
                this->set_torque_request(TorqueRequestControlType::None, TorqueRequestBounds::LessThan, 0); // And also torque requests
            }

            // Algorithm has control
            uint8_t step_result = algo->step(
                algo_phase_id,
                abs_input_torque,
                stationary_shift,
                is_upshift,
                phase_elapsed,
                total_elapsed,
                this->pressure_mgr,
                &this->sensor_data
            );
            this->algo_feedback = algo->get_diag_feedback(algo_phase_id);

            // Update pressures
            pressure_mgr->set_target_modulating_pressure(p_now.mod_sol_req);
            pressure_mgr->set_target_shift_pressure(p_now.shift_sol_req);
            pressure_mgr->update_pressures(
                sid.curr_g,
                sid.change
            );

            if (step_result == 0) {
                // Continue
                phase_elapsed += SHIFT_DELAY_MS;
            }
            else if (step_result == STEP_RES_END_SHIFT) {
                // Shift completed OK!
                result = true;
                break;
            }
            else if (step_result == STEP_RES_FAILURE) {
                // Shift failure!
                break;
            }
            else {
                // Phase has completed, update our data
                phase_elapsed = 0;
                if (step_result == STEP_RES_NEXT) {
                    algo_phase_id += 1;
                }
                else {
                    algo_phase_id = step_result;
                }
            }
            uint32_t elapsed = GET_CLOCK_TIME() - start_time;
            if (elapsed < SHIFT_DELAY_MS) {
                vTaskDelay((SHIFT_DELAY_MS - elapsed) / portTICK_PERIOD_MS);
            }
            total_elapsed += SHIFT_DELAY_MS;
        }
        if (result) { // Only set gear on conformation!
            if (algo->did_time_out()) {
                ESP_LOGW("SHIFT", "Shift %d->%d completed via emergency timer, gear will be verified by ratio", sd.curr_g, sd.targ_g);
            }
            this->actual_gear = gear_from_idx(sd.targ_g);
            this->gear_disagree_count = 0; // Gear is now known
            this->last_motion_gear = this->actual_gear;
        }
        else {
            if (!is_shifter_in_valid_drive_pos(this->shifter_pos)) {
                ESP_LOGE("SHIFT", "Shift failed due to selector moving");
                this->target_gear = GearboxGear::Neutral;
                this->actual_gear = GearboxGear::Neutral;
            }
            else {
                ESP_LOGE("SHIFT", "Shift failed! End ratio is %.2f", (float)sensor_data.gear_ratio);
                this->target_gear = this->actual_gear;
            }
        }
        pressure_manager->set_spc_p_max();
        pressure_manager->set_shift_circuit(sd.shift_circuit, false);
        pressure_manager->notify_shift_end();
        this->set_torque_request(TorqueRequestControlType::None, TorqueRequestBounds::LessThan, 0);
        this->abort_shift = false;
        this->sensor_data.last_shift_time = GET_CLOCK_TIME();
        // Arm the post-upshift downshift inhibit only for a completed, automatic upshift
        this->last_shift_was_upshift = is_upshift && result && !manually_requested;
        this->pedal_at_last_shift = this->sensor_data.pedal_pos;
        // The TCC must always be told the shift is over, even if the algorithm exited abnormally
        if (this->tcc != nullptr) {
            this->tcc->shift_end();
        }
        this->flaring = false;
        this->fwd_shift_count += 1;     // advances the A/B arm for the next shift
        memset(&this->algo_feedback, 0x00, sizeof(ShiftAlgoFeedback));
        delete algo;
    }
    else if (GearChange::_IDLE == req_lookup) {
        ESP_LOGE("ELAPSE_SHIFT", "BUG! GearChange is IDLE");
    }
    else if (0xFF == egs_map_idx_lookup) {
        ESP_LOGE("ELAPSE_SHIFT", "BUG! GearChange is INVALID for FwdShift");
    }
    else if (nullptr == profile) {
        ESP_LOGE("ELAPSE_SHIFT", "BUG! Profile is null");
    }
    this->shift_idx = GearChange::_IDLE;
    return result;
}

void Gearbox::shift_thread()
{
    this->shifting = true;
    GearboxGear curr_target = this->target_gear;
    GearboxGear curr_actual = this->actual_gear;
    if (curr_actual == curr_target)
    {
        ESP_LOG_LEVEL(ESP_LOG_WARN, "SHIFTER", "Gears are the same????");
        goto cleanup;
    }
    if (!is_controllable_gear(curr_actual) && !is_controllable_gear(curr_target))
    {
        ESP_LOG_LEVEL(ESP_LOG_INFO, "SHIFTER", "No need to shift");
        this->actual_gear = curr_target;
        goto cleanup;
    }
    else if (is_controllable_gear(curr_actual) != is_controllable_gear(curr_target))
    { // This would be a garage shift, either in or out
        ESP_LOG_LEVEL(ESP_LOG_INFO, "SHIFTER", "Garage shift");
        if (is_controllable_gear(curr_target))
        {
            bool into_reverse = GearboxGear::Reverse_First == curr_target || GearboxGear::Reverse_Second == curr_target;
            Clutch applying = Clutch::B2;
            if (into_reverse) {
                applying = Clutch::B3;
            } else if (GearboxGear::Fourth == curr_target || GearboxGear::Fifth == curr_target) {
                applying = Clutch::K2;
            }
            GearChange circuit = GearChange::_4_5;
            uint16_t centrifugal = 0;
            uint16_t spring_p = pressure_manager->get_spring_pressure(applying);
            uint16_t p_mod = 0;
            uint16_t p_shift = 0;
            uint16_t p_apply_clutch = 0;
            uint16_t p_max_apply_clutch = 0;
            uint8_t stage = 0;
            uint8_t substage = 0;
            uint8_t timer_s = 0;
            uint8_t timer_m = 0;
            // NOTE: timer_3 is set (to 80) at three points below but is never
            // decremented or read, unlike timer_s/timer_m above. It is an
            // unfinished stage timer carried over from the EGS algorithm. Do not
            // delete it (it marks missing logic, and the file tracks upstream) and
            // do not wire it up without a drive to judge the resulting shift feel.
            uint8_t timer_3 = 0;

            bool completed_ok = false;
            bool jump_to_pid = false;
            bool tried_again = false;
            // Why an abort happened is the question this log line has never been
            // able to answer. "Garage shift aborted" on its own cannot separate a
            // clutch that never took up from a sync gate that rejected a good
            // engagement, and the abort is chronic - it appears in 8 of the 13
            // logged drives, on vehicle power and USB power alike. Carry the
            // evidence out with it. The discriminator is the turbine: an
            // engagement that is working drags it to zero, and on both drives
            // where the car never went into gear it did not move at all while
            // shift pressure went to the 7700 mBar ceiling.
            uint16_t in_rpm_start = sensor_data.input_rpm;
            uint16_t in_rpm_min = sensor_data.input_rpm;
            uint16_t p_shift_peak = 0;
            int last_rpm_delta = 0;
            int last_sync_thresh = 0;
            this->algo_feedback.active = true;
            
            while(true) {
                egs_can_hal->set_garage_shift_state(sensor_data.output_rpm < 10, !into_reverse);
                int rpm_delta = abs(sensor_data.input_rpm - calc_input_rpm_from_req_gear(sensor_data.output_rpm, curr_target, &this->gearboxConfig));
                int sync_rpm_threshold = 90;
                if (sensor_data.pedal_pos > 10) {
                    sync_rpm_threshold = 350;
                }
                int p_1 = MIN(25, (1100 * sensor_data.pedal_pos) / 25);
                int rpm_offset = MAX(0, sensor_data.engine_rpm - 800);
                int dyn_adder = ((rpm_offset * 150) / 100) + p_1; 

                // K3 is never used here, so specifying 0 rear sun gear is OK
                centrifugal = pressure_manager->calculate_centrifugal_force_for_clutch(applying, sensor_data.input_rpm, 0);
                if (timer_s > 0) {
                    timer_s -= 1;
                }
                if (timer_m > 0) {
                    timer_m -= 1;
                }
                // Safety, going into reverse, AND car is moving forward! - Enter neutral until stopped
                if (0 == stage) {
                    if ((into_reverse && sensor_data.output_rpm > 50) || sensor_data.output_rpm > 1000) {
                        this->pressure_mgr->set_shift_circuit(ShiftCircuit::sc_3_4, true);
                        this->pressure_mgr->set_shift_circuit(ShiftCircuit::sc_2_3, true);
                        p_mod = 0;
                        p_shift = 0;
                    } else {
                        if (!is_fwd_gear(target_gear) || target_gear == GearboxGear::Second || target_gear == GearboxGear::First) {
                            circuit = GearChange::_1_2;
                        }
                        if (this->tcu_restarted && (sensor_data.output_rpm < 10 && this->shifter_pos == ShifterPosition::N)) {
                            circuit = GearChange::_1_2;
                        }
                        p_max_apply_clutch = pressure_manager->get_max_shift_pressure(((uint8_t)circuit)-1);
                    }
                    stage += 1;
                    substage = 0;
                } else if (stage == 1) {
                    float div = 1.0;
                    if (sensor_data.engine_rpm > 0) {
                        div = (float)sensor_data.input_rpm / (float)sensor_data.engine_rpm;
                        if (div > 1.5) {
                            jump_to_pid = false;
                        } else {
                            jump_to_pid = true;
                        }
                    }

                    if (substage == 0) {
                        if (!is_fwd_gear(target_gear) || target_gear == GearboxGear::Second || target_gear == GearboxGear::First) {
                            this->pressure_mgr->set_shift_circuit(ShiftCircuit::sc_3_4, true);
                            this->pressure_mgr->set_shift_circuit(ShiftCircuit::sc_2_3, false);
                        } else {
                            this->pressure_mgr->set_shift_circuit(ShiftCircuit::sc_3_4, false);
                            this->pressure_mgr->set_shift_circuit(ShiftCircuit::sc_2_3, true);
                        }
                        timer_s = interpolate_float(sensor_data.atf_temp, 25, 11, -5, 20, InterpType::Linear);
                        substage = 1;
                    }
                    if (substage == 1) {
                        p_mod = 3000;
                        int p = 0;
                        if (applying == Clutch::K2) {
                            p = 1200; // K2RAMP
                        } else {
                            p = interpolate_float(sensor_data.atf_temp, 4000, 1200, -35, 25, InterpType::Linear);
                        }
                        p = MAX(0, (int16_t)p + (int16_t)spring_p - (int16_t)centrifugal);
                        p_apply_clutch = p + dyn_adder;
                        p_shift = ShiftHelpers::correct_shift_shift_pressure(pressure_manager, p_apply_clutch, ((uint8_t)circuit)-1); 
                        if (0 == timer_s) {
                            substage = 2;
                            timer_s = interpolate_float(sensor_data.atf_temp, 50, 10, -20, 90, InterpType::Linear);
                        }
                    } else if (substage == 2) {
                        p_mod = 3000;
                        if (0 == timer_s || (div <= 7.5 && sensor_data.atf_temp > -20)) {
                            if (sensor_data.pedal_pos > 10) {
                                timer_s = 11;
                            } else {
                                timer_s = 80;
                            }
                            substage = 3;
                        }
                    } else if (substage == 3) {
                        if (0 == timer_s || jump_to_pid) {
                            if (Clutch::B2 == applying) {
                                timer_s = 25;
                            } else if (Clutch::K2 == applying) {
                                timer_s = 10;
                            } else {
                                timer_s = 25;
                            }
                            substage = 4;
                        } else {
                            p_mod = 3000;
                            int p = 0;
                            if (applying == Clutch::K2) {
                                p = 7500; // K2RAMP2
                            } else {
                                if (applying == Clutch::B2) {
                                    p = 6600;
                                } else {
                                    p = 4500;
                                }
                                p = interpolate_float(sensor_data.atf_temp, 8000, p, -35, 25, InterpType::Linear);
                            }
                            p = MAX(0, (int16_t)p + (int16_t)spring_p - (int16_t)centrifugal);
                            p_apply_clutch = linear_ramp_with_timer(p_apply_clutch, p + dyn_adder, timer_s);
                            p_shift = ShiftHelpers::correct_shift_shift_pressure(pressure_manager, p_apply_clutch, ((uint8_t)circuit)-1); 
                            if (rpm_delta < sync_rpm_threshold) {
                                timer_s = 9;
                                if (sensor_data.output_rpm < 60) {
                                    timer_m = timer_s + interpolate_float(sensor_data.atf_temp, 40, 7, -30, 20, InterpType::Linear);
                                } else {
                                    timer_m = timer_s + 80;
                                }
                                timer_3 = 80;
                                substage = 7;
                            }
                        }
                    } else if (substage == 4) {
                        if (0 == timer_s || jump_to_pid) {
                            timer_s = 80; // TODO
                            timer_m = 0;
                            substage = 5;
                        } else {
                            p_mod = 3000;
                            int p = 0;
                            if (applying == Clutch::K2) {
                                p = 7500; // K2RAMP2
                            } else {
                                if (applying == Clutch::B2) {
                                    p = 6600;
                                } else {
                                    p = 4500;
                                }
                                p = interpolate_float(sensor_data.atf_temp, 8000, p, -35, 25, InterpType::Linear);
                            }
                            p = MAX(0, (int16_t)p + (int16_t)spring_p - (int16_t)centrifugal);
                            p_apply_clutch = p + dyn_adder;
                            p_shift = ShiftHelpers::correct_shift_shift_pressure(pressure_manager, p_apply_clutch, ((uint8_t)circuit)-1); 
                            if (rpm_delta < sync_rpm_threshold) {
                                timer_s = 9;
                                if (sensor_data.output_rpm < 60) {
                                    timer_m = timer_s + interpolate_float(sensor_data.atf_temp, 40, 7, -30, 20, InterpType::Linear);
                                } else {
                                    timer_m = timer_s + 80;
                                }
                                timer_3 = 80;
                                substage = 7;
                            }
                        }
                    } else if (substage == 5) {
                        p_mod = 3000;
                        p_apply_clutch += 10;
                        p_shift = ShiftHelpers::correct_shift_shift_pressure(pressure_manager, p_apply_clutch, ((uint8_t)circuit)-1); 
                        if (0 == timer_s || p_shift > pressure_manager->get_max_solenoid_pressure() - 1500 || rpm_delta < sync_rpm_threshold) {
                            timer_s = 9;
                            if (sensor_data.output_rpm < 60) {
                                timer_m = timer_s + interpolate_float(sensor_data.atf_temp, 40, 7, -30, 20, InterpType::Linear);
                            } else {
                                timer_m = timer_s + 80;
                            }
                            timer_3 = 80;
                            substage = 7;
                        }
                    }  else if (substage == 6 || substage == 7) {
                        bool done = false;
                        if (0 == timer_s) {
                            p_shift = pressure_manager->get_max_solenoid_pressure();
                            p_apply_clutch = p_max_apply_clutch;
                            p_mod = 5000;
                            if (0 == timer_m) {
                                done = true;
                            }
                        } else {
                            p_apply_clutch = linear_ramp_with_timer(p_apply_clutch, p_max_apply_clutch, timer_s);
                            p_shift = ShiftHelpers::correct_shift_shift_pressure(pressure_manager, p_apply_clutch, ((uint8_t)circuit)-1);
                            p_mod = linear_ramp_with_timer(p_mod, 5000, timer_s);
                        }

                        if (done) {
                            substage = 8;
                        }
                    } else if (substage == 8) {
                        // Check for completion.
                        //
                        // Use the same sync threshold that substages 3/4/5 used to
                        // declare sync and hand over to the max-pressure ramp. A fixed
                        // 20 rpm here rejected the very sync that got us to this
                        // substage: with any throttle the converter drags the turbine,
                        // and input_rpm never reaches zero at a standstill in gear
                        // (CLAUDE.md), so the check could not pass. Measured 2026-09-08
                        // on N->D with the driver already on the pedal: rpm_delta was 96
                        // at the first check and 34 at the second, so both engagements
                        // were thrown away, the clutch was slammed to max pressure three
                        // times and the gear only took 3.9 s later once the car rolled.
                        // With zero pedal the turbine does stall to 0, which is why the
                        // same code engages reverse cleanly first time.
                        if (rpm_delta < sync_rpm_threshold) {
                            // Sync is OK!
                            //int rpm_delta_engine = abs(sensor_data.engine_rpm - sensor_data.input_rpm);
                            //if (rpm_delta_engine > 150 || rpm_delta < 10) {
                            substage = 0;
                            stage = 2;
                            //} else {
                            //    if (sensor_data.output_rpm < 300) {
                            //        this->pressure_mgr->set_shift_circuit(ShiftCircuit::sc_3_4, false);
                            //        timer_s = interpolate_float(sensor_data.atf_temp, 40, 7, -30, 20, InterpType::Linear);
                            //        substage += 1; // To stage 9
                            //    } else {
                            //        substage = 0;
                            //        stage = 3; // Did not complete OK
                            //    }
                            //}
                        } else {
                            // Did not complete OK
                            stage = 3;
                        }
                    } else {
                        // Stage 9 - Reset stage 1
                        if (0 == timer_s) {
                            substage = 0;
                        }
                    }
                } else if (stage == 2) {
                    // Exit!
                    p_mod = 5100;
                    p_apply_clutch = p_max_apply_clutch;
                    p_shift =  ShiftHelpers::correct_shift_shift_pressure(pressure_manager, p_apply_clutch, ((uint8_t)circuit)-1);
                    completed_ok = true;
                } else if (stage == 3) {
                    // Failure to shift, try again!
                    if (0 == substage) {
                        // Init
                        this->pressure_mgr->set_shift_circuit(ShiftCircuit::sc_3_4, true);
                        this->pressure_mgr->set_shift_circuit(ShiftCircuit::sc_2_3, true);
                        this->pressure_mgr->set_shift_circuit(ShiftCircuit::sc_1_2, false);
                        timer_s = interpolate_float(sensor_data.atf_temp, 150, 40, -20, 30, InterpType::Linear);
                        substage += 1;

                    } else {
                        p_mod = 0;
                        p_apply_clutch = 0;
                        p_shift = 0;
                        if (0 == timer_s) {
                            if (tried_again) {
                                // We have already retried once and still did not sync.
                                // Without this the loop cycles stage 1 <-> stage 3
                                // indefinitely, because its only other exits are a
                                // successful sync or the driver selecting N/P - so a
                                // shift that can never complete (failed clutch, bad
                                // N2/N3 signal, low line pressure) would hang the
                                // shift thread with the car in gear. Fall through to
                                // the existing abort path instead.
                                completed_ok = false;
                                break;
                            }
                            tried_again = true;
                            this->pressure_mgr->set_shift_circuit(ShiftCircuit::sc_3_4, false);
                            this->pressure_mgr->set_shift_circuit(ShiftCircuit::sc_2_3, false);
                            this->pressure_mgr->set_shift_circuit(ShiftCircuit::sc_1_2, false);
                            stage = 1;
                            substage = 0;

                        }
                    }
                }
                last_rpm_delta = rpm_delta;
                last_sync_thresh = sync_rpm_threshold;
                if (sensor_data.input_rpm < in_rpm_min) { in_rpm_min = sensor_data.input_rpm; }
                if (p_shift > p_shift_peak) { p_shift_peak = p_shift; }
                pressure_mgr->set_target_modulating_pressure(p_mod);
                pressure_mgr->set_target_shift_pressure(p_shift);
                this->pressure_mgr->update_pressures(this->target_gear, circuit);
                this->algo_feedback.p_off = p_mod;
                this->algo_feedback.p_on = p_apply_clutch;
                this->algo_feedback.s_off = 0;
                this->algo_feedback.s_on = rpm_delta;
                this->algo_feedback.shift_phase = substage;
                this->algo_feedback.sync_rpm = sync_rpm_threshold;

                vTaskDelay(20);
                if (completed_ok) {
                    break;
                }
                if (this->shifter_pos == ShifterPosition::N || this->shifter_pos == ShifterPosition::P) {
                    completed_ok = false;
                    break;
                }
            }

            if (!completed_ok) {
                ESP_LOGW("SHIFT",
                    "Garage shift aborted at stage %d.%d: turbine %d->%d rpm (min %d), "
                    "delta %d vs sync %d, peak shift p %d mBar, mpc %d mBar, out %d rpm, ATF %d C%s",
                    (int)stage, (int)substage, (int)in_rpm_start, (int)sensor_data.input_rpm,
                    (int)in_rpm_min, last_rpm_delta, last_sync_thresh, (int)p_shift_peak,
                    (int)p_mod, (int)sensor_data.output_rpm, (int)sensor_data.atf_temp,
                    tried_again ? ", after a retry" : "");
                curr_target = this->shifter_pos == ShifterPosition::P ? GearboxGear::Park : GearboxGear::Neutral;
                curr_actual = this->shifter_pos == ShifterPosition::P ? GearboxGear::Park : GearboxGear::Neutral;
                pressure_mgr->set_target_shift_pressure(4000);
            }
            else {
                ESP_LOGI("SHIFT", "Garage shift completed OK");
            }
            this->tcu_restarted = false;
            pressure_mgr->set_spc_p_max();
            this->pressure_mgr->set_shift_circuit(ShiftCircuit::sc_3_4, false);
            this->pressure_mgr->set_shift_circuit(ShiftCircuit::sc_2_3, false);
            this->pressure_mgr->set_shift_circuit(ShiftCircuit::sc_1_2, false);
            egs_can_hal->set_garage_shift_state(false, !into_reverse);
        }
        else
        {
            // Shift to N/P from an in-gear gear
            if (this->actual_gear < GearboxGear::Third) {
                // So only for D1/D2 to N/P will this shift valve turn on
                this->pressure_mgr->set_shift_circuit(ShiftCircuit::sc_3_4, true);
            }
            this->pressure_mgr->set_shift_circuit(ShiftCircuit::sc_1_2, false);
            this->pressure_mgr->set_shift_circuit(ShiftCircuit::sc_2_3, false);
            pressure_mgr->set_target_modulating_pressure(1500);
            pressure_mgr->set_target_shift_pressure(3000);
            this->pressure_mgr->update_pressures(this->target_gear, GearChange::_IDLE);
        }
        this->gear_disagree_count = 0; // Garage shift establishes a known gear
        this->actual_gear = curr_target;
        
        goto cleanup;
    }
    else
    { // Both gears are controllable
        if (is_fwd_gear(curr_target) != is_fwd_gear(curr_actual))
        {
            // In this case, we set the current gear to neutral, then thread will re-spawn
            ESP_LOG_LEVEL(ESP_LOG_INFO, "SHIFTER", "Shifter got stuck in R-D. Returning and trying again");
            this->actual_gear = GearboxGear::Neutral;
            goto cleanup;
        }
        else if (is_fwd_gear(curr_target) && is_fwd_gear(curr_actual))
        {
            // Forward shift logic
            if (curr_target > curr_actual)
            { // Upshifting
                ESP_LOG_LEVEL(ESP_LOG_INFO, "SHIFTER", "Upshift request to change between %s and %s!", gear_to_text(curr_actual), gear_to_text(curr_target));
                // this->show_upshift = true;
                GearChange pgc;
                if (curr_target == GearboxGear::Second)
                { // 1-2
                    pgc = GearChange::_1_2;
                }
                else if (curr_target == GearboxGear::Third)
                { // 2-3
                    pgc = GearChange::_2_3;
                }
                else if (curr_target == GearboxGear::Fourth)
                { // 3-4
                    pgc = GearChange::_3_4;
                }
                else if (curr_target == GearboxGear::Fifth)
                { // 4-5
                    pgc = GearChange::_4_5;
                }
                else
                { // WTF
                    this->target_gear = this->actual_gear;
                    goto cleanup;
                }
                this->shift_idx = pgc;
                portENTER_CRITICAL(&this->profile_mutex);
                AbstractProfile* prof = this->current_profile;
                portEXIT_CRITICAL(&this->profile_mutex);
                this->is_upshift = true;
                this->fwd_gear_shift = true;
                elapse_shift(pgc, prof, this->shift_req_was_manual);
                this->start_second = true;
                goto cleanup;
            }
            else
            { // Downshifting
                ESP_LOG_LEVEL(ESP_LOG_INFO, "SHIFTER", "Downshift request to change between %s and %s!", gear_to_text(curr_actual), gear_to_text(curr_target));
                // this->show_downshift = true;
                GearChange pgc;
                if (curr_target == GearboxGear::First)
                { // 2-1
                    pgc = GearChange::_2_1;
                    this->start_second = false;
                }
                else if (curr_target == GearboxGear::Second)
                { // 3-2
                    pgc = GearChange::_3_2;
                    this->start_second = true;
                }
                else if (curr_target == GearboxGear::Third)
                { // 4-3
                    pgc = GearChange::_4_3;
                }
                else if (curr_target == GearboxGear::Fourth)
                { // 5-4
                    pgc = GearChange::_5_4;
                }
                else
                { // WTF
                    this->target_gear = this->actual_gear;
                    goto cleanup;
                }
                this->shift_idx = pgc;
                portENTER_CRITICAL(&this->profile_mutex);
                AbstractProfile* prof = this->current_profile;
                portEXIT_CRITICAL(&this->profile_mutex);
                this->is_upshift = false;
                this->fwd_gear_shift = true;
                elapse_shift(pgc, prof, this->shift_req_was_manual);
                goto cleanup;
            }
        }
        else
        {
            ESP_LOG_LEVEL(ESP_LOG_INFO, "SHIFTER", "Ignoring request to change between %s and %s!", gear_to_text(curr_actual), gear_to_text(curr_target));
        }
        goto cleanup;
    }
cleanup:
    ESP_LOG_LEVEL(ESP_LOG_INFO, "SHIFTER", "Shift complete");
    this->set_torque_request(TorqueRequestControlType::None, TorqueRequestBounds::LessThan, 0);
    this->shifting = false;
    this->fwd_gear_shift = false;
    this->is_upshift = false;
    memset(&this->algo_feedback, 0x00, sizeof(ShiftAlgoFeedback));
    vTaskDelete(nullptr);
}

void Gearbox::controller_loop()
{
    ShifterPosition last_position = ShifterPosition::SignalNotAvailable;
    ESP_LOG_LEVEL(ESP_LOG_INFO, "GEARBOX", "GEARBOX START!");
    ShiftTrace::init();
    RoadLoadEstimator::init();
    uint32_t expire_check = GET_CLOCK_TIME() + 100; // 100ms
    egs_can_hal->set_safe_start(true);
    sol_tcc->isr_enable(); // Safe to enable ISR now that all init is done
    while (GET_CLOCK_TIME() < expire_check)
    {
        // Step 1. Aquire ALL Sensors
        TCUIO::update_io_layer();

        this->shifter_pos = egs_can_hal->get_shifter_position(250);
        last_position = this->shifter_pos;
        if (this->shifter_pos == ShifterPosition::P || this->shifter_pos == ShifterPosition::N)
        {
            egs_can_hal->set_safe_start(true);
            break; // Default startup, OK
        }
        else if (this->shifter_pos == ShifterPosition::D)
        { // Car is in motion forwards!
            this->actual_gear = GearboxGear::Fifth;
            this->target_gear = GearboxGear::Fifth;
            this->gear_disagree_count = 20; // Set disagree counter to non 0. This way gearbox must calculate ratio
            egs_can_hal->set_safe_start(false);
            break;
        }
        else if (this->shifter_pos == ShifterPosition::R)
        { // Car is in motion backwards!
            this->actual_gear = GearboxGear::Reverse_Second;
            this->target_gear = GearboxGear::Reverse_Second;
            egs_can_hal->set_safe_start(false);
            break;
        }
        else {
            egs_can_hal->set_safe_start(true); // Unknown position, keep polling until we don't know
        }
        vTaskDelay(5);
    }
    while (1)
    {
        uint32_t start = GET_CLOCK_TIME();
        TCUIO::update_io_layer();
        if (CHECK_MODE_BIT_ENABLED(DEVICE_MODE_SLAVE)) {
            SOLENOID_CONTROL_EGS_SLAVE slave_rq = egs_can_hal->get_tester_req();
            sol_mpc->set_current_target(__builtin_bswap16(slave_rq.MPC_REQ));
            sol_spc->set_current_target(__builtin_bswap16(slave_rq.SPC_REQ));
            sol_tcc->set_duty(slave_rq.TCC_REQ * 16); // x16 to go from 8 bit (0-255) to 12bit (0-4096)
            if (slave_rq.Y3_EN) {
                sol_y3->on();
            }
            else {
                sol_y3->off();
            }
            if (slave_rq.Y4_EN) {
                sol_y4->on();
            }
            else {
                sol_y4->off();
            }
            if (slave_rq.Y5_EN) {
                sol_y5->on();
            }
            else {
                sol_y5->off();
            }
            SENSOR_REPORT_EGS_SLAVE sensor_rpt;

            this->process_speed_sensors();


            uint8_t pll = TCUIO::parking_lock();
            int16_t tft = TCUIO::atf_temperature();
            uint16_t vbatt = TCUIO::battery_mv();

            sensor_rpt.N2_RAW = __builtin_bswap16(this->speed_sensors.n2);
            sensor_rpt.N3_RAW = __builtin_bswap16(this->speed_sensors.n3);
            sensor_rpt.TFT = pll ? 0xFF : tft + 50;
            sensor_rpt.VBATT = (vbatt / 100) & 0xFF;

            SOLENOID_REPORT_EGS_SLAVE sol_rpt;
            sol_rpt.MPC_CURR = __builtin_bswap16(sol_mpc->get_current());
            sol_rpt.SPC_CURR = __builtin_bswap16(sol_spc->get_current());
            sol_rpt.TCC_PWM = (sol_tcc->get_pwm_raw() / 16) & 0xFF;

            UN52_REPORT_EGS_SLAVE un52_rpt;
            un52_rpt.Y3_CURR = __builtin_bswap16(sol_y3->get_current());
            un52_rpt.Y4_CURR = __builtin_bswap16(sol_y4->get_current());
            un52_rpt.Y5_CURR = __builtin_bswap16(sol_y5->get_current());
            un52_rpt.TCC_CURR = __builtin_bswap16(sol_tcc->get_current());

            egs_can_hal->set_slave_mode_reports(sol_rpt, sensor_rpt, un52_rpt);
            vTaskDelay(20);
            continue;
        }
        if (this->diag_stop_control)
        {
            vTaskDelay(50);
            continue;
        }


        bool speeds_valid = this->process_speed_sensors();
        if (speeds_valid)
        {
            this->sensor_data.input_rpm = speed_sensors.turbine;
            this->sensor_data.output_rpm = speed_sensors.output;
            bool stationary = this->is_stationary();
            this->process_acceleration();   
            this->sensor_data.acceleration_ms2 = this->acceleration_ms2/10;
            this->sensor_data.wheel_speed_mps = this->wheel_spd;
            if (!stationary && this->sensor_data.output_rpm > 0)
            {
                // Store our ratio
                if (this->actual_gear == GearboxGear::Neutral || this->actual_gear == GearboxGear::Park || this->actual_gear == GearboxGear::SignalNotAvailable) {
                    this->sensor_data.gear_ratio = 0.0;
                } else {
                    this->sensor_data.gear_ratio = (float)this->sensor_data.input_rpm / (float)this->sensor_data.output_rpm;
                }
                this->sensor_data.targ_gear_ratio = ratio_absolute(this->actual_gear, &this->gearboxConfig);

            }
            else {
                // Stationary so no ratios
                this->sensor_data.gear_ratio = 0.0;
                this->sensor_data.targ_gear_ratio = 0.0;
            }
            if (!shifting && sensor_data.output_rpm > 100)
            {
                if (is_fwd_gear(this->actual_gear))
                {
                    if (calcGearFromRatio(false) && this->est_gear_idx != 0)
                    {
                        // Compare gears
                        GearboxGear estimate = gear_from_idx(this->est_gear_idx);
                        if (estimate != this->actual_gear)
                        {
                            gear_disagree_count++;
                            if (gear_disagree_count >= 50)
                            {
                                this->actual_gear = estimate; // DID NOT SHIFT!
                                this->target_gear = estimate;
                                this->last_fwd_gear = estimate;
                            }
                        }
                        else
                        {
                            gear_disagree_count = 0;
                        }
                    }
                }
                else
                {
                    gear_disagree_count = 0;
                }
            }
            // NOTE: Do not clear gear_disagree_count when slow, stationary or shifting.
            // It is deliberately set non-zero at startup (booted in D) so that the gear
            // must be verified by ratio before the profile is allowed to shift.
        }
        else
        {
            speeds_valid = false;
        }
        if (speeds_valid) {
            this->speeds_invalid_cycles = 0;
        } else if (this->speeds_invalid_cycles < UINT8_MAX) {
            this->speeds_invalid_cycles += 1;
        }
        if (speeds_valid && !this->is_stationary())
        {
            bool rev = !is_fwd_gear(this->target_gear);
            if (!this->calcGearFromRatio(rev))
            {
                // ESP_LOG_LEVEL(ESP_LOG_ERROR, "GEARBOX", "GEAR RATIO IMPLAUSIBLE");
            }
        }
        uint8_t p_tmp = egs_can_hal->get_pedal_value(1000);
        this->pedal_last = this->sensor_data.pedal_pos;
        if (p_tmp == 0xFF) {
            p_tmp = 250 / 4; // 25% as a fallback (Applied to both raw and smoothed so they agree)
        }
        this->sensor_data.pedal_pos = p_tmp;
        this->sensor_data.pedal_pos_smoothed = linear_interp_with_percentage(80, p_tmp, this->sensor_data.pedal_pos_smoothed);

        if (start - this->last_delta_time > 100) {
            // Update every 100ms, not every EGS cycle, values multiplied by 10
            // to get them in terms of 1 second (1s/100ms = 10)
            if (this->pedal_delta) {
                this->pedal_delta->update(this->sensor_data.pedal_pos * 10);
            }
            if (this->input_rpm_delta) {
                this->input_rpm_delta->update(this->sensor_data.input_rpm * 10);
            }
            this->pedal_history[this->pedal_history_idx] = this->sensor_data.pedal_pos;
            this->pedal_history_idx = (this->pedal_history_idx + 1) % sizeof(this->pedal_history);
            this->last_delta_time = start;
        }

        sensor_data.brake_pressed = brake_pedal.is_brake_pedal_pressed(egs_can_hal, 250);
        sensor_data.kickdown_pressed = kickdown.is_kickdown_newly_pressed(egs_can_hal, 250);
        int tmp_rpm = 0;
        tmp_rpm = egs_can_hal->get_engine_rpm(1000);
        if (tmp_rpm == UINT16_MAX)
        {
            // Substitute the last value for a short while, then treat the engine as
            // stopped. Substituting forever hides a dead signal, and the input_rpm == 0
            // test below cannot catch it in gear: the converter drags the turbine to
            // 100-300 rpm at a standstill, so it never reads zero.
            if (this->engine_rpm_missing_cycles < 10) {
                this->engine_rpm_missing_cycles += 1;
                tmp_rpm = this->sensor_data.engine_rpm; // Sub last value!
            } else {
                tmp_rpm = 0;
            }
            if (sensor_data.input_rpm == 0 && this->engine_running) {
                // Engine is off, and USB is powering the TCU
                this->engine_running = false;
                tmp_rpm = 0;
                this->last_motion_gear = GearboxGear::Second; // No pressure default
                this->actual_gear = GearboxGear::Neutral;
                this->target_gear = GearboxGear::Neutral;
            }
        }
        else
        {
            this->engine_rpm_missing_cycles = 0;
        }
        this->sensor_data.engine_rpm = tmp_rpm;
        // Update solenoids, only if engine RPM is OK
        if (tmp_rpm > 400 && tmp_rpm != UINT16_MAX)
        {
            if (!this->engine_running) {
                this->engine_running = true;
            }
        }
        if (this->engine_running && !shifting) {
            this->mpc_working = pressure_mgr->find_working_mpc_pressure(this->actual_gear, true);
            this->pressure_mgr->set_target_modulating_pressure(this->mpc_working);
        }
        this->process_motor_spd_filtered();
        uint8_t pll = TCUIO::parking_lock();
        if (UINT8_MAX != pll)
        {
            bool lock_state = pll != 0;
            if (lock_state) {
                if (engine_running && !shifting) {
                    this->pressure_mgr->set_target_shift_pressure(500);
                    if (this->last_motion_gear < GearboxGear::Third) {
                        this->pressure_mgr->set_shift_circuit(ShiftCircuit::sc_3_4, true);
                    }
                } else if (!engine_running) {
                    this->pressure_mgr->set_shift_circuit(ShiftCircuit::sc_3_4, true);
                }
            }
            egs_can_hal->set_safe_start(lock_state);
            this->shifter_pos = egs_can_hal->get_shifter_position(1000);
            if (
                this->shifter_pos == ShifterPosition::P ||
                this->shifter_pos == ShifterPosition::P_R ||
                this->shifter_pos == ShifterPosition::R ||
                this->shifter_pos == ShifterPosition::R_N ||
                this->shifter_pos == ShifterPosition::N ||
                this->shifter_pos == ShifterPosition::N_D ||
                this->shifter_pos == ShifterPosition::D ||
                this->shifter_pos == ShifterPosition::FOUR ||
                this->shifter_pos == ShifterPosition::THREE ||
                this->shifter_pos == ShifterPosition::TWO ||
                this->shifter_pos == ShifterPosition::ONE)
            {
                if (this->shifter_pos != last_position)
                {
                    if (lock_state)
                    {
                        if (this->shifter_pos == ShifterPosition::P)
                        {
                            this->target_gear = GearboxGear::Park;
                            last_position = this->shifter_pos;
                            sol_tcc->isr_disable();
                            vTaskDelay(5);
                            if (this->shift_adapter != nullptr)
                            {
                                this->shift_adapter->save();
                            }
                            this->tcc->save();
                            sol_tcc->isr_enable();
                            // Save profile
                            if (ShifterStyle::EWM == shifter->get_shifter_type()) {
                                if (ETS_CURRENT_SETTINGS.ewm_save_profile) {
                                    // We know that the profile is valid based on
                                    // use selection (EWM button code) - So we don't need to check this
                                    uint8_t tag = this->current_profile->get_profile_id();
                                    // By default, we can save, but just check if manual profile without
                                    // the user wanting to save manual profiles
                                    bool can_save = true;
                                    if (tag == PROFILE_IDX_M || tag == PROFILE_IDX_R || tag == PROFILE_IDX_W) {
                                        can_save = ETS_CURRENT_SETTINGS.ewm_save_profile_manual;
                                    }
                                    if (can_save) {
                                        esp_err_t res = EEPROM::ewm_btn_save_profile(tag);
                                        if (ESP_OK != res) {
                                            ESP_LOGW("EWM SAVE", "Profile could not be saved to NVS");
                                        }
                                    }
                                }
                            }
                        }
                        else if (this->shifter_pos == ShifterPosition::N)
                        {
                            this->target_gear = GearboxGear::Neutral;
                            last_position = this->shifter_pos;
                        }
                    }
                    else
                    {
                        // Drive or R!
                        if (this->shifter_pos == ShifterPosition::R)
                        {
                            this->target_gear = this->last_motion_gear == GearboxGear::First ? GearboxGear::Reverse_First : GearboxGear::Reverse_Second;
                            last_position = this->shifter_pos;
                        }
                        else if (this->shifter_pos == ShifterPosition::D || this->shifter_pos == ShifterPosition::N_D)
                        {
                            // Some shift levers can be semi broken
                            // and can switch between ND and D randomly whilst in motion
                            // handle that case here by checking current fwd gear first
                            // If current gear is also fwd, ignore!
                            if (!is_fwd_gear(this->actual_gear) && !is_fwd_gear(this->target_gear))
                            {
                                this->target_gear = this->last_motion_gear;
                            }
                            last_position = this->shifter_pos;
                        }
                    }
                }
            }
        }
        if (this->engine_running)
        {
            if (speeds_valid && is_fwd_gear(this->actual_gear))
            {
                // Check our range restict (Only for TRRS)
                switch (egs_can_hal->get_shifter_position(250)) { // Don't use shifter_pos, as that only registers D. Query raw selector pos
                case ShifterPosition::FOUR:
                    this->restrict_target = GearboxGear::Fourth;
                    break;
                case ShifterPosition::THREE:
                    this->restrict_target = GearboxGear::Third;
                    break;
                case ShifterPosition::TWO:
                    this->restrict_target = GearboxGear::Second;
                    break;
                case ShifterPosition::ONE:
                    this->restrict_target = GearboxGear::First;
                    break;
                default:
                    this->restrict_target = GearboxGear::Fifth;
                    break;
                }
                // Seek up the restriction target if the RPM is too high for the current gear!
                // Seek up to Fifth
                while (this->restrict_target != GearboxGear::Fifth && calc_input_rpm_from_req_gear(this->sensor_data.output_rpm, this->restrict_target, &this->gearboxConfig) > this->redline_rpm)
                {
                    this->restrict_target = next_gear(this->restrict_target);
                }

                // In gear, not shifting, and no ratio mismatch
                if (!shifting && this->actual_gear == this->target_gear && gear_disagree_count == 0)
                {
                    // Enter critical ISR section
                    portENTER_CRITICAL(&this->profile_mutex);
                    AbstractProfile* p = this->current_profile;
                    // Exit critical
                    portEXIT_CRITICAL(&this->profile_mutex);
                    // Check if profile is loaded
                    if (p != nullptr)
                    {
                        p->update(&this->sensor_data);
                        // Ask the current drive profile if it thinks, given the current
                        // data, if the car should up/downshift
                        if (this->restrict_target > this->actual_gear && this->profile_should_upshift(p, this->actual_gear, &this->sensor_data))
                        {
                            // The map says shift. Before taking its word for it, ask whether the
                            // next gear can actually pull - see next_gear_can_pull(). If it cannot,
                            // hold this gear: take neither branch, so this does not turn into a
                            // downshift either.
                            if (this->next_gear_can_pull(next_gear(this->actual_gear)))
                            {
                                this->ask_upshift = true; // Upshift takes priority
                                this->manual_shift = false;
                            }
                        }
                        else if (this->restrict_target < this->actual_gear || this->profile_should_downshift(p, this->actual_gear, &this->sensor_data)) {
                            this->ask_downshift = true; // Downshift is secondary
                            this->manual_shift = false;
                        }
                    }
                    if ((standard == this->current_profile ||
                        comfort == this->current_profile ||
                        agility == this->current_profile ||
                        winter == this->current_profile) &&
                        this->actual_gear != GearboxGear::Fifth && // Already checked if in FWD gear
                        !this->ask_upshift &&
                        this->engine_spd_flt > this->engine_spd_flt_prev
                    ) {
                        GearChange change = GearChange::_1_2;
                        if (this->actual_gear == GearboxGear::Second) {
                            change = GearChange::_2_3;
                        } else if (this->actual_gear == GearboxGear::Third) {
                            change = GearChange::_3_4;
                        } else if (this->actual_gear == GearboxGear::Fourth) {
                            change = GearChange::_4_5;
                        }
                        int cycles_to_shift = ShiftHelpers::total_time_crossover_shift(this->pressure_mgr, change, abs(sensor_data.input_torque), sensor_data.input_rpm);
                        int delta_est = this->engine_spd_flt - this->engine_spd_flt_prev; // Per 20ms cycle (10x value)
                        int est_rpm_when_shifting = sensor_data.engine_rpm + (delta_est * cycles_to_shift)/10;
                        if (
                            est_rpm_when_shifting > this->redline_rpm - SBS_CURRENT_SETTINGS.redline_offset_auto_upshift && 
                            sensor_data.pedal_pos > 50
                        ) {
                            this->ask_upshift = true;
                        }
                    }
                    if (this->ask_upshift && this->actual_gear < GearboxGear::Fifth)
                    {
                        // Check RPMs
                        GearboxGear next = next_gear(this->actual_gear);
                        // Second gear shift defaults to OK as we can safely start in second (For C/W mode)
                        if (next == GearboxGear::Second || calc_input_rpm_from_req_gear(this->sensor_data.output_rpm, next, &this->gearboxConfig) > 900)
                        {
                            this->target_gear = next;
                        }
                    }
                    else if ((this->ask_downshift || sensor_data.kickdown_pressed) && this->actual_gear > GearboxGear::First)
                    {
                        // Post-upshift downshift inhibit. Several map cells land the post-upshift
                        // input RPM below the downshift line, which causes up/down hunting at a
                        // steady pedal. Hold the downshift for a short while after an automatic
                        // upshift unless the driver clearly asks for it.
                        bool inhibit = this->last_shift_was_upshift &&
                            !this->manual_shift &&
                            !sensor_data.kickdown_pressed &&
                            !sensor_data.brake_pressed &&
                            this->restrict_target >= this->actual_gear &&
                            (GET_CLOCK_TIME() - sensor_data.last_shift_time) < 2000 &&
                            sensor_data.pedal_pos <= (this->pedal_at_last_shift + 25);
                        // Anti-clunk: hold a downshift that would still be running when the
                        // car stops - see downshift_can_finish(). Only automatic ones; a
                        // driver asking for the gear gets it.
                        if (!inhibit && !this->manual_shift && !sensor_data.kickdown_pressed &&
                            this->restrict_target >= this->actual_gear &&
                            !this->downshift_can_finish(p)) {
                            inhibit = true;
                        }
                        // Check RPMs
                        GearboxGear prev = prev_gear(this->actual_gear);
                        if (!inhibit && calc_input_rpm_from_req_gear(this->sensor_data.output_rpm, prev, &this->gearboxConfig) < this->redline_rpm - 500)
                        {
                            this->target_gear = prev;
                        }
                    }
                }
                // Request processed. Cancel the requests. Put this outside here so that if there is a ratio mismatch, paddles are ignored
                this->ask_downshift = false;
                this->ask_upshift = false;
                this->shift_req_was_manual = this->manual_shift;
                this->manual_shift = false;

                if (is_fwd_gear(this->target_gear))
                {
                    if (this->tcc != nullptr)
                    {
                        this->tcc->update(this->actual_gear, this->target_gear, this->pressure_mgr, this->current_profile, &this->sensor_data);
                        egs_can_hal->set_clutch_status(this->tcc->get_clutch_state());
                    }
                }
            }
            else if (is_fwd_gear(this->actual_gear) && this->speeds_invalid_cycles < 5) {
                // Transient sensor dropout in a forward gear - hold the current TCC pressure
                // rather than dumping it (which causes a thump under lock).
            }
            else { // Cannot read, or not in foward gear!
                this->tcc_percent = 0;
                this->pressure_mgr->set_target_tcc_pressure(0);
                if (this->tcc != nullptr && !this->shifting) {
                    this->tcc->reset();
                }
                egs_can_hal->set_clutch_status(TccClutchStatus::Open);
                // sol_tcc->write_pwm_12_bit(0);
            }
            // Not shifting, but target has changed! Spawn a shift thread!
            if (this->target_gear != this->actual_gear && !this->shifting)
            {
                xTaskCreatePinnedToCore(Gearbox::start_shift_thread, "Shift handler", 8192, this, 10, &this->shift_task, 1);
            }
        }
        else if (!shifting && sensor_data.input_rpm < 10)
        {
            // Engine not running - solenoids off (update_pressures is skipped below in this state)
            this->pressure_mgr->set_target_tcc_pressure(0);
            sol_mpc->set_current_target(0);
            sol_spc->set_current_target(0);
            sol_tcc->set_duty(0);
            this->pressure_mgr->set_shift_circuit(ShiftCircuit::sc_1_2, false);
            this->pressure_mgr->set_shift_circuit(ShiftCircuit::sc_2_3, false);
            this->pressure_mgr->set_shift_circuit(ShiftCircuit::sc_3_4, false);
        }

        int16_t tmp_atf = TCUIO::atf_temperature();
        if (INT16_MAX != tmp_atf)
        {
            if (!temp_cal)
            {
                temp_cal = true;
                temp_at_test = tmp_atf;
                if (temp_at_test != 25)
                {
                    resistance_mpc = resistance_mpc + (resistance_mpc * (((25.0 - (float)temp_at_test) * 0.393) / 100.0));
                    resistance_spc = resistance_spc + (resistance_spc * (((25.0 - (float)temp_at_test) * 0.393) / 100.0));
                }
                ESP_LOGI("GB", "Calibrated solenoids at %d C. Adjusted for 25C: SPC %.2f MPC %.2f", tmp_atf, resistance_spc, resistance_mpc);
            }
            // SPC and MPC can cause voltage swing on the ATF line, so disable
            // monitoring when shifting gears!
            if (!shifting)
            {
                this->sensor_data.atf_temp = tmp_atf;
            }
        }
        egs_can_hal->set_gearbox_temperature(this->sensor_data.atf_temp);
        egs_can_hal->set_shifter_position(this->shifter_pos);
        egs_can_hal->set_input_shaft_speed(this->sensor_data.input_rpm);
        egs_can_hal->set_tcc_trq_multiplier(this->sensor_data.tcc_trq_multiplier);
        if (this->aborting)
        {
            egs_can_hal->set_abort_shift(true);
        }
        else
        {
            egs_can_hal->set_target_gear(this->target_gear);
        }
        egs_can_hal->set_actual_gear(this->actual_gear);
        egs_can_hal->set_wheel_torque(0); // Nm

        CanTorqueData trqs = egs_can_hal->get_torque_data(100);
        // CALC TORQUES
        if (INT16_MAX != trqs.m_min) { sensor_data.min_torque = trqs.m_min; }
        if (INT16_MAX != trqs.m_max) { sensor_data.max_torque = trqs.m_max; }
        if (INT16_MAX != trqs.m_ind) { sensor_data.indicated_torque = trqs.m_ind; }
        if (INT16_MAX != trqs.m_converted_static) { sensor_data.converted_torque = trqs.m_converted_static; }
        if (INT16_MAX != trqs.m_converted_driver) {
            int input_trq = InputTorqueModel::get_input_torque(
                sensor_data.engine_rpm,
                sensor_data.input_rpm,
                trqs.m_converted_driver
            );
            sensor_data.input_torque = input_trq;
            sensor_data.converted_driver_torque = trqs.m_converted_driver;
        }
        sensor_data.pump_torque = InputTorqueModel::get_pump_torque(sensor_data.engine_rpm, sensor_data.input_rpm);

        if (this->shifting && is_controllable_gear(this->target_gear) && !is_controllable_gear(this->actual_gear)) {
            if (INT16_MAX != sensor_data.pump_torque) {
                sensor_data.input_torque = sensor_data.pump_torque * sensor_data.tcc_trq_multiplier;
            }
        }

        // Wheel torque
        /*
        if (this->sensor_data.gear_ratio == 0)
        {
            // Fallback ratio for when gear ratio is actually 0
            float f;
            switch (this->target_gear)
            {
            case GearboxGear::First:
                f = gearboxConfig.ratios[0];
                break;
            case GearboxGear::Second:
                f = gearboxConfig.ratios[1];
                break;
            case GearboxGear::Third:
                f = gearboxConfig.ratios[2];
                break;
            case GearboxGear::Fourth:
                f = gearboxConfig.ratios[3];
                break;
            case GearboxGear::Reverse_First:
                f = gearboxConfig.ratios[4] * -1;
                break;
            case GearboxGear::Reverse_Second:
                f = gearboxConfig.ratios[4] * -1;
                break;
            case GearboxGear::Park:
            case GearboxGear::SignalNotAvailable:
            case GearboxGear::Neutral:
            default:
                f = 0.0;
                break;
            }
            egs_can_hal->set_wheel_torque_multi_factor(f);
        }
        else
        {
            egs_can_hal->set_wheel_torque_multi_factor(this->sensor_data.gear_ratio);
        }
        */

        // ESP_LOG_LEVEL(ESP_LOG_INFO, "GEARBOX", "Torque: MIN: %3d, MAX: %3d, STAT: %3d", min_torque, max_torque, static_torque);
        //  Show debug symbols on IC
        float ratio_from_c_gear = ratio_absolute(this->actual_gear, &this->gearboxConfig);
        float ratio_from_t_gear = ratio_absolute(this->target_gear, &this->gearboxConfig);
        float tcc_multipler = InputTorqueModel::get_input_torque_factor(sensor_data.engine_rpm, sensor_data.input_rpm);
        this->sensor_data.tcc_trq_multiplier = tcc_multipler;
        float torque_ratio = 0; // Implausible
        if (!shifting) {
            pressure_mgr->update_pressures(this->actual_gear, GearChange::_IDLE);
        }
        if (
            ratio_from_c_gear != 0 && // Valid ratio
            sensor_data.engine_rpm != 0 // Engine is turning
            ) {
            torque_ratio = ratio_from_c_gear;
            if (ratio_from_t_gear > ratio_from_c_gear) {
                torque_ratio = ratio_from_t_gear;
            }
            torque_ratio *= tcc_multipler;
            torque_ratio *= diff_ratio_f;
            if (torque_ratio < 1) {
                torque_ratio = 1; // HOW!? (diff ratio is always > 2.0)
            }
        }
        else if (sensor_data.engine_rpm == 0) {
            torque_ratio = -1; // Cannot calculate
        }
        egs_can_hal->set_wheel_torque_multi_factor(torque_ratio);
        if (this->show_upshift && this->show_downshift)
        {
            egs_can_hal->set_display_msg(GearboxMessage::RequestGearAgain);
        }
        else if (this->show_upshift)
        {
            egs_can_hal->set_display_msg(GearboxMessage::Upshift);
        }
        else if (this->show_downshift)
        {
            egs_can_hal->set_display_msg(GearboxMessage::Downshift);
        }
        else
        {
            egs_can_hal->set_display_msg(GearboxMessage::None);
        }

        // Lastly, set display gear
        portENTER_CRITICAL(&this->profile_mutex);
        if (this->current_profile != nullptr)
        {
            egs_can_hal->set_drive_profile(this->current_profile->get_profile());
            if (this->flaring && SBS.f_shown_if_flare)
            {
                // Takes president
                egs_can_hal->set_display_msg(GearboxMessage::None);
                egs_can_hal->set_display_gear(GearboxDisplayGear::Failure, false);
            }
            else
            {
                if (this->current_profile == race && this->fwd_gear_shift && SBS.debug_show_up_down_arrows_in_r) {
                    egs_can_hal->set_display_msg(this->is_upshift ? GearboxMessage::Upshift : GearboxMessage::Downshift);
                }
                else if ((this->current_profile == manual || this->current_profile == race) &&
                    sensor_data.engine_rpm > this->redline_rpm - 1000
                    ) {
                    egs_can_hal->set_display_msg(GearboxMessage::Upshift);
                }
                else {
                    egs_can_hal->set_display_msg(GearboxMessage::None);
                }
                egs_can_hal->set_display_gear(this->current_profile->get_display_gear(this->target_gear, this->actual_gear), this->current_profile == manual);
            }
        }
        portEXIT_CRITICAL(&this->profile_mutex);
        // While shifting, the shift thread owns the solenoid update (with the correct change
        // state). With the engine stopped the solenoids were switched off above.
        if (!this->shifting && this->sensor_data.engine_rpm > 100) {
            pressure_mgr->update_pressures(this->actual_gear, GearChange::_IDLE);
        }
        this->update_agility_score();
        // Road load: how hard the grade and the load are working the car. Not
        // consumed yet - see road_load.h for why it is worth having.
        if (is_fwd_gear(this->actual_gear) && this->actual_gear == this->target_gear) {
            RoadLoadEstimator::update(&this->sensor_data,
                ratio_absolute(this->actual_gear, &this->gearboxConfig),
                this->shifting, this->sensor_data.brake_pressed);
        }
        this->update_adaptive_profile();
        // High rate shift recorder. This loop is the algorithm's own 20 ms period,
        // so the capture is lossless; the sampler is O(1) and allocation free.
        ShiftTrace::sample(&this->sensor_data, &this->algo_feedback, this->shifting,
            (uint8_t)gear_to_idx_lookup(this->actual_gear), (uint8_t)gear_to_idx_lookup(this->target_gear),
            this->pressure_mgr->get_corrected_spc_pressure(),
            this->pressure_mgr->get_corrected_modulating_pressure(),
            this->pressure_mgr->get_active_shift_circuits(),
            (this->output_data.ctrl_type == TorqueRequestControlType::None)
                ? INT16_MAX : (int16_t)this->output_data.torque_req_amount,
            (int16_t)this->sensor_data.converted_torque, this->agility_score);
        // Closed loop on shift quality: runs once per completed shift, between shifts.
        this->quality_adaptation_step();
        uint32_t time = GET_CLOCK_TIME() - start;
        if (time < 20) {
            vTaskDelay((20 - time) / portTICK_PERIOD_MS); // 50 updates/sec!
        }
    }
}

bool Gearbox::process_speed_sensors()
{
    bool ok = true;
    bool conduct_sanity_check = gear_disagree_count == 0 &&
        (this->actual_gear == this->target_gear) && (                                                 // Same gear (Not shifting)
            (this->actual_gear == GearboxGear::Second) || // And in 2..
            (this->actual_gear == GearboxGear::Third) ||  // .. or 3 ..
            (this->actual_gear == GearboxGear::Fourth)    // .. or 4
            );
    uint16_t n2 = TCUIO::n2_rpm();
    uint16_t n3 = TCUIO::n3_rpm();
    uint16_t output = TCUIO::output_rpm();

    if (UINT16_MAX != n2 && UINT16_MAX != n3) {
        uint16_t turbine = TCUIO::calc_turbine_rpm(n2, n3);
        if (conduct_sanity_check) {
            if (abs(n2 - n3) > 100) {
                ok = false;
            }
        }
        // A dead N2 sensor reads 0 (no pulses). N2 can never be 0 whilst moving in a forward gear,
        // so treat that as a sensor fault (Otherwise turbine = 0 in 5th and a 5-4 is triggered).
        if (is_fwd_gear(this->actual_gear) && this->speed_sensors.output > 250 && n2 < 50) {
            ok = false;
        }
        if (ok) {
            this->speed_sensors.turbine = turbine;
        }
        this->speed_sensors.n2 = n2;
        this->speed_sensors.n3 = n3;
    }

    if (UINT16_MAX != output) {
        speed_sensors.output = output;
    }
    else {
        ok = false; // Output RPM failed
    }

    return ok;
}

bool Gearbox::calcGearFromRatio(bool is_reverse)
{
    float ratio = (float)this->sensor_data.input_rpm / (float)this->sensor_data.output_rpm;
    //ESP_LOGI("CGFR", "R %.3f", ratio);
    if (is_reverse)
    {
        ratio *= -1;
        for (uint8_t i = 0; i < 2; i++)
        { // Scan the 2 reverse gears
            GearRatioInfo limits = gearboxConfig.bounds[i + 5];
            if (ratio >= limits.ratio_min_drift && ratio <= limits.ratio_max_drift)
            {
                //ESP_LOGI("CGFR", "G %d", i+1);
                this->est_gear_idx = i + 1;
                return true;
            }
        }
    }
    else
    {
        for (uint8_t i = 0; i < 5; i++)
        { // Scan the 5 forwards gears
            GearRatioInfo limits = gearboxConfig.bounds[i];
            if (ratio >= limits.ratio_min_drift && ratio <= limits.ratio_max_drift)
            {
                this->est_gear_idx = i + 1;
                return true;
            }
        }
    }
    this->est_gear_idx = 0;
    return false;
}

void Gearbox::process_acceleration() {
    if (UINT16_MAX != sensor_data.output_rpm) {
        int wheel_spd_now = (((float)sensor_data.output_rpm*100) / this->diff_ratio_f);
        // Rpm -> Rps = RPM/60
        // Rps -> Rp/cycle = Rps/50
        int wheel_delta = ((int)this->wheel_spd-(int)this->wheel_spd_prev);
        int wheel_accel_m = (wheel_delta * (int)VEHICLE_CONFIG.wheel_circumference)/300; // mm/sec delta
        // Rotate values
        this->wheel_spd_prev = this->wheel_spd;
        this->wheel_spd = wheel_spd_now;
        if (sensor_data.output_rpm < 20) {
            wheel_accel_m = 0;
            acceleration_ms2 = 0;
        } else {
            acceleration_ms2 = first_order_filter(10, wheel_accel_m*100, this->acceleration_ms2);
        }
    } else {
        wheel_spd = 0;
        wheel_spd_prev = 0;
        acceleration_ms2 = 0;
    }
}

void Gearbox::process_motor_spd_filtered() {
    if (UINT16_MAX != sensor_data.engine_rpm) {
        this->engine_spd_flt_prev = this->engine_spd_flt;
        this->engine_spd_flt = first_order_filter(8, sensor_data.engine_rpm*10, engine_spd_flt);
    }
}

Gearbox* gearbox = nullptr;
