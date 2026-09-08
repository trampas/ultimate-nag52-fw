// Here we go, gearbox controller code! Lets go!

#ifndef GEARBOX_H
#define GEARBOX_H

#include <stdint.h>
#include "canbus/can_hal.h"
#include "solenoids/solenoids.h"
#include "sensors.h"
#include "profiles.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "common_structs.h"
#include "torque_converter.h"
#include "pressure_manager.h"
#include "models/input_torque.hpp"
#include "adaptation/shift_adaptation.h"
#include "adaptation/quality_adapt.h"
#include "shift_trace.h"
#include "models/clutch_speed.hpp"
#include "shifter/shifter.h"
#include "inputcomponents/brakepedal.hpp"
#include "inputcomponents/kickdownswitch.hpp"
#include "driver_dynamics/dynamics.h"
//#include "runtime_sensors/runtime_sensors.h"

struct PostShiftTorqueRamp {
    bool enabled;
    uint16_t start_nm;
    uint16_t time_to_exit;
};

class Gearbox {
public:
    explicit Gearbox(Shifter* shifter);
    // Diag test
    ClutchSpeeds diag_get_clutch_speeds();
    void set_profile(AbstractProfile* prof);
    esp_err_t start_controller(void);
    void inc_gear_request(void);
    void dec_gear_request(void);
    void diag_inhibit_control(void) { this->diag_stop_control = true; }
    void diag_regain_control(void) { this->diag_stop_control = false; }
    SensorData sensor_data;
    OutputData output_data;
    uint16_t get_gear_ratio(void) {
        return this->sensor_data.gear_ratio * 100.0F;
    }
    uint16_t get_targ_gear_ratio(void) {
        return this->sensor_data.targ_gear_ratio * 100.0F;
    }
    uint16_t redline_rpm;
    bool shifting = false;
    PressureManager* pressure_mgr = nullptr;

    bool isShifting(void) { return this->shifting; }
    uint8_t get_targ_curr_gear(void) { return (((uint8_t)this->target_gear) & 0x0F) << 4 | ((uint8_t)this->actual_gear & 0x0F); }
    /// Driver agility demand and the inputs behind it, for RLI_DRIVING_DYNAMIC.
    DATA_DRIVING_DYNAMICS get_driving_dynamics(void);
    uint8_t get_profile_id(void) {
        if (this->current_profile) {
            return this->current_profile->get_profile_id();
        } else {
            return 0xFF;
        }
    }
    TorqueConverter* tcc = nullptr;
    ShiftAlgoFeedback algo_feedback = {0,0,0,0,0,0,0,0,0,0,0,0,0};
    ShiftAdaptationSystem* shift_adapter = nullptr;
    SpeedSensors speed_sensors;
private:
    bool is_stationary();
    ShiftReportSegment collect_report_segment(uint64_t start_time);
    void set_torque_request(TorqueRequestControlType ctrl_type, TorqueRequestBounds bounds, float amount);
    bool elapse_shift(GearChange req_lookup, AbstractProfile* profile, bool manually_requested);
    bool calcGearFromRatio(bool is_reverse);

    AbstractProfile* current_profile = nullptr;   // profile the shift logic is using
    AbstractProfile* selected_profile = nullptr;  // profile the driver asked for
    portMUX_TYPE profile_mutex;
    /**
     * @brief Adaptive profile: give Agility on demand while Comfort is selected.
     *
     * Only active when the driver has selected Comfort, so every other profile
     * behaves exactly as before and this cannot surprise anyone who did not opt in.
     * Comfort keeps shifts soft and the converter locked for economy; a deliberate
     * throttle demand switches to Agility at once and holds it, so the box does not
     * fall back to a tall gear halfway through an overtake.
     */
    /**
     * @brief How much agility the driver is asking for, 0-100.
     *
     * A continuous score rather than a flag, because driver intent is not binary
     * and because anything that learns from a shift needs to know how hard the
     * driver was pushing when it happened - otherwise it adapts Comfort towards
     * an objective the driver only wanted for ten seconds. Production systems do
     * the same thing (ZF calls it driver type assessment, and ignores it during
     * special programs, which is the same gating idea).
     *
     * Rises almost immediately and decays over roughly 30 s of gentle driving.
     * The profile switch takes it with hysteresis so it cannot chatter at the
     * boundary.
     */
    uint8_t agility_score = 0;
    uint8_t pedal_history[5] = {0};     // 100 ms apart -> a 500 ms window
    uint8_t pedal_history_idx = 0;
    uint32_t last_score_ms = 0;
    uint16_t last_out_rpm = 0;
    int16_t decel_rpm_s = 0;            // output shaft, for the braking term
    uint8_t agility_demand(void);
    void update_agility_score(void);
    // Anti-bog gate on automatic upshifts; see the definition in gearbox.cpp
    bool next_gear_can_pull(GearboxGear next);
    void update_adaptive_profile(void);

    /**
     * @brief Continuous Comfort/Agility blend and per-shift A/B arms.
     *
     * SBS agility_blend interpolates the target shift time (and, at 2, the shift
     * points) between the Comfort and Agility maps on the agility score, instead
     * of the profile swap's all-or-nothing choice. SBS ab_interleave alternates
     * the blend on and off shift by shift so both populations come from one
     * drive; the arm is stamped on every shift in the trace.
     */
    bool blend_active(void);            // Comfort selected and agility_blend != 0
    bool current_arm_is_a(void);        // false only on even shifts while interleaving
    float agility_blend_weight(void);   // 0 (Comfort) .. 1 (Agility)
    bool profile_should_upshift(AbstractProfile* p, GearboxGear g, SensorData* sd);
    bool profile_should_downshift(AbstractProfile* p, GearboxGear g, SensorData* sd);
    uint32_t fwd_shift_count = 0;       // completed forward shifts since boot

    /**
     * @brief Context of the shift in progress / just finished, for the quality
     * adaptation, which runs in the controller loop after the trace closes the
     * shift's quality vector. See adaptation/quality_adapt.h.
     */
    struct {
        GearChange change;
        bool manual;
        bool kickdown;
        bool flared;
        uint16_t output_rpm;
    } shift_ctx = { GearChange::_IDLE, false, false, false, 0 };
    void quality_adaptation_step(void);
    GearboxGear target_gear = GearboxGear::Park;
    GearboxGear actual_gear = GearboxGear::Park;
    GearboxGear last_fwd_gear = GearboxGear::Second;
    bool process_speed_sensors();
    [[noreturn]]
    void controller_loop(void);

    void shift_thread(void);
    bool start_second = true; // By default
    static void start_shift_thread(void *_this) {
        static_cast<Gearbox*>(_this)->shift_thread();
    }

    [[noreturn]]
    static void start_controller_internal(void *_this) {
        static_cast<Gearbox*>(_this)->controller_loop();
    }
    uint16_t temp_raw = 0;
    uint8_t pedal_last = 0;
    uint16_t input_last = 0;
    TaskHandle_t shift_task = nullptr;
    bool ask_upshift = false;
    bool ask_downshift = false;
    bool manual_shift = false;
    bool shift_req_was_manual = false;
    bool is_upshift = false;
    bool fwd_gear_shift = false;
    float tcc_percent = 0.F;
    uint8_t est_gear_idx = 0;
    uint16_t curr_hold_pressure = 0;
    bool show_upshift = false;
    bool show_downshift = false;
    bool flaring = false;
    int gear_disagree_count = 0;
    unsigned long last_tcc_adjust_time = 0;
    int mpc_working = 0;
    bool diag_stop_control = false;
    Shifter* shifter = nullptr;
    ShifterPosition shifter_pos = ShifterPosition::SignalNotAvailable;
    GearboxConfiguration gearboxConfig;
    ShiftCircuit last_shift_circuit = ShiftCircuit::None;
    float diff_ratio_f =  1.0;
    GearChange shift_idx = GearChange::_IDLE;
    bool abort_shift = false;
    bool aborting = false;
    GearboxGear restrict_target = GearboxGear::Fifth;
    GearboxGear last_motion_gear = GearboxGear::Second;
    
    float pedal_average_ff = 0;
    
    DeltaTracker* input_rpm_delta = nullptr;
    DeltaTracker* pedal_delta = nullptr;
    uint32_t last_delta_time = 0;

    int req_static_torque_delta = 0;
    bool freeze_torque = false;

    KickdownSwitch kickdown;
    BrakePedal brake_pedal;

    int32_t cached_input_rpm = 0;
    int32_t cached_engine_rpm = 0;
    int32_t cached_output_rpm = 0;
    uint8_t engine_rpm_missing_cycles = 0;
    uint8_t speeds_invalid_cycles = 0;
    bool last_shift_was_upshift = false;
    uint8_t pedal_at_last_shift = 0;
};

extern Gearbox* gearbox;

#endif