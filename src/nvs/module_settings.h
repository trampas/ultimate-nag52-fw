#ifndef __MODULE_SETTINGS_H
#define __MODULE_SETTINGS_H

#include <stdint.h>
#include <limits.h>
#include <tcu_maths.h>
#include <esp_err.h>

// Torque converter setting
typedef struct {
    // Enable adaptation for all gears
    bool adapt_enable;
    // Enable torque converter in D1
    bool enable_d1;
    // Enable torque converter in D2
    bool enable_d2;
    // Enable torque converter in D3
    bool enable_d3;
    // Enable torque converter in D4
    bool enable_d4;
    // Enable torque converter in D5
    bool enable_d5;
    // Open the converter to slipping (If locked) if the engine requests it
    // This is used on the M113K platform when the supercharger clutch
    // is about to engage, so that the shock of the supercharger coming on does
    // not cause too much discomfort
    bool react_on_engine_slip_request;
    // Open the converter fully, if the engine requests it.
    // This is usually used under very heavy load under low RPM
    bool react_on_engine_open_request;
    // Scaling for TCC output pressure based on temperature. 
    //
    // When cold, the ATF is thicker, thus a higher pressure can be commanded
    // with the same TCC solenoid PWM. This scaling is meant to mitigate this
    // effect.
    //
    // Adaptation can only work when ATF is hotter than the `raw_max` value
    //
    // To disable this scaling, set output_min and output_max to 1.0
    LinearInterpSetting tcc_temp_multiplier;
    // Prefill pressure for the torque converter. When going from Open->Slipping, 
    // a burst of pressure is first sent in order to fill the converter faster
    // UNIT: mBar
    uint16_t prefill_pressure;
    // Number of 20ms cycles to hold the converter at prefill_pressure for when
    // prefilling
    uint8_t prefill_cycles;
    // DEBUG: Override the automatic calculation of max torque used for TCC adaptations.
    //        Set to 0 to disable the override (Use automatic calculation), Set to any
    //        other number to override max rated torque of the converter. IMPORTANT: If
    //        modified, it is recommended to reset the TCC adaptation maps.
    //
    // UNIT: Nm
    uint16_t tcc_max_trq_override;
    // Forces the TCC to unlock on upshifts under load
    bool unlock_load_upshifts;
    // Forces the TCC to unlock on downshifts under load
    bool unlock_load_downshifts;
    // Forces the TCC to unlock on upshifts when coasting
    bool unlock_coasting_upshifts;
    // Forces the TCC to unlock on downshifts when coasting
    bool unlock_coasting_downshifts;
} __attribute__ ((packed)) TCC_MODULE_SETTINGS;

const TCC_MODULE_SETTINGS TCC_DEFAULT_SETTINGS = {
    .adapt_enable = true,
    .enable_d1 = true,
    .enable_d2 = true,
    .enable_d3 = true,
    .enable_d4 = true,
    .enable_d5 = true,
    .react_on_engine_slip_request = true,
    .react_on_engine_open_request = true,
    .tcc_temp_multiplier = LinearInterpSetting {
        .new_min = 0.5,
        .new_max = 1.0,
        .raw_min = -10,
        .raw_max = 60
    },
    .prefill_pressure = 10000,
    .prefill_cycles = 10,
    .tcc_max_trq_override = 0,
    .unlock_load_upshifts = true,
    .unlock_load_downshifts = true,
    .unlock_coasting_upshifts = false,
    .unlock_coasting_downshifts = false
};

// Solenoid subsystem settings
typedef struct {
    // Minimum battery voltage before performing 
    // the solenoid boot up test on TCU start
    //
    // UNIT: mV
    uint16_t min_batt_power_on_test;
    // If a solenoid is reading more than this current during the
    // boot test, then it is assumed faulty
    //
    // UNIT: mA
    uint16_t current_threshold_error;
    // Solenoid reference voltage. DO NOT TOUCH THIS. It is intended 
    // for debugging ONLY!
    //
    // UNIT: mV
    uint16_t cc_vref_solenoid;
    // The temperature coefficient of the solenoid wiring and coils.
    // DO NOT TOUCH THIS. It is intended for debugging ONLY!
    // UNIT: Ohm/deg C
    float cc_temp_coefficient_wires;
    // MPC and SPC solenoids reference resistance at cc_reference_temp
    // UNIT: Ohm
    float cc_reference_resistance;
    // MPC and SPC solenoids resistance reference temperature
    // UNIT: C
    float cc_reference_temp;
    // MPC and SPC current control PID settings - P component
    int16_t cc_pid_p;
    // MPC and SPC current control PID settings - I component
    int16_t cc_pid_i;
    // MPC and SPC current control PID settings - D component
    int16_t cc_pid_d;
    // MPC and SPC solenoid current offset to correct for ADC/Board characteristics
    //
    // 1.3 boards - (Up to -100mA is recommended)
    // UNIT: mA
    int16_t cc_offset_ma;
    
} __attribute__ ((packed)) SOL_MODULE_SETTINGS;

const SOL_MODULE_SETTINGS SOL_DEFAULT_SETTINGS = {
    .min_batt_power_on_test = 11000,
    .current_threshold_error = 500,
    .cc_vref_solenoid = 12000,
    .cc_temp_coefficient_wires = 0.393,
    .cc_reference_resistance = 5.3,
    .cc_reference_temp = 25,
    .cc_pid_p = 800,
    .cc_pid_i = 500,
    .cc_pid_d = 0,
    .cc_offset_ma = 0,
};

// Shift program basic settings
typedef struct {
    // DEBUG - Show an 'F' marker in the gear display when the TCU
    // detects a flare condition
    bool f_shown_if_flare;
    // DEBUG - Show '^' or 'v' in the gear display when the shift
    // thread is active
    bool debug_show_up_down_arrows_in_r;
    // Enable torque requests for 1-2
    bool en_trq_req_1_2;
    // Enable torque requests for 2-3
    bool en_trq_req_2_3;
    // Enable torque requests for 3-4
    bool en_trq_req_3_4;
    // Enable torque requests for 4-5
    bool en_trq_req_4_5;
    // Enable torque requests for 2-1
    bool en_trq_req_2_1;
    // Enable torque requests for 3-2
    bool en_trq_req_3_2;
    // Enable torque requests for 4-3
    bool en_trq_req_4_3;
    // Enable torque requests for 5-4
    bool en_trq_req_5_4;
    // Refuse an automatic upshift when the next gear cannot pull.
    //
    // Rather than shifting on an RPM threshold and finding out afterwards, the
    // acceleration the next gear would give is predicted from the road load
    // estimator's fitted mass and grade, and the gear is held if it comes out
    // below this (GM US 6098004, Ford US 5669850). In mm/s^2.
    //
    // INT16_MIN disables it, and is the default: this has never been driven, and
    // adding a setting must not change how anyone's car behaves. 214 is the
    // measured starting point - over 91 upshifts on the 2026-09-07 drives, 33 %
    // were followed by the car DECELERATING in the new gear and 214 catches half
    // of those while wrongly holding 7 of the 61 good ones. 0 is the timid
    // setting: block only upshifts predicted to actually slow the car down.
    // Higher holds gears longer and shifts less often.
    //
    // Re-measure on another car with scripts/next_gear.py rather than guessing.
    int16_t next_gear_min_accel_mms2;
    // Blend Comfort and Agility continuously on the driver agility score instead
    // of swapping whole profiles at a threshold.
    //
    // 0: off. Comfort swaps to Agility at score 60 and back at 25, as before.
    // 1: shift TIME only. The target shift time is interpolated between the
    //    Comfort and Agility time maps by the score, so a half-hearted stab gets
    //    a half-way shift instead of a full Comfort one. Shift POINTS still come
    //    from whichever profile the swap chose.
    // 2: shift time AND shift points are both interpolated.
    //
    // Only acts while the driver has Comfort selected; every other profile is
    // untouched. Measured over five drives, 42 % of driving sits between score 20
    // and 79, where a swap gives one endpoint or the other and a blend gives
    // what was asked for. The swap is a 491 rpm step on the 1-2 at 10 % pedal.
    uint8_t agility_blend;
    // Score at or below which the blend is pure Comfort (weight 0).
    uint8_t agility_blend_lo;
    // Score at or above which the blend is pure Agility (weight 1).
    uint8_t agility_blend_hi;
    // A/B test the blend inside one drive: odd-numbered shifts get the blend
    // (arm A) and even-numbered ones the unblended behaviour (arm B). Every shift
    // in the trace is stamped with its arm, so the two populations come from the
    // same road, load and mood and can be compared directly. Turn off once the
    // decision is made.
    bool ab_interleave;
    // Refuse an automatic downshift that cannot finish before the car stops.
    //
    // A coast-down ladder is serialised: 4-3, 3-2 and 2-1 are decided one at a
    // time and each takes about a second, so the last one can still be running
    // when the car reaches a standstill. Its closing pressure ramp - which is
    // pressure matching before the shift valve drops out, and is correct - then
    // applies the gear with the output shaft stopped and the turbine still
    // turning. That is the coast-down clunk.
    //
    // Before requesting the shift the projected output speed at the end of it is
    // computed from the current deceleration and the shift time map, and the
    // shift is held if that projection falls below this value in output shaft
    // rpm. Holding is safe: the car then stops in the higher gear, and the shift
    // happens at a true standstill, where the algorithm takes its stationary
    // path. On the 2026-09-08 07:01 drive the one clunking 2-1 (jerk 50.9 m/s^3,
    // torque hole 239 rpm/s) projects to -47 rpm, while the five clean ones
    // project to +21 rpm or above, so 0 separates them.
    //
    // INT16_MIN disables it, and is the default: this has never been driven, and
    // adding a setting must not change how anyone's car behaves. 0 is the
    // measured starting point. Higher holds more downshifts to a standstill.
    //
    // Manual, kickdown and lever-restricted downshifts are never held.
    int16_t downshift_min_end_rpm;
    // When in an automatic profile, this limit determines the offset from
    // Redline RPM before an upshift is forced, in order to stop the engine
    // actually hitting redline. If your engine stays at the limiter and after
    // a while the car finally upshifts, increase this threshold
    uint16_t redline_offset_auto_upshift;
    // Hold the 3-4 shift circuit (Y4) energised while in P/N.
    //
    // true is what 47c7633 (upstream fdcf448) does, taken from EGS52 behaviour:
    // Y4 is switched on as soon as the engine turns and held at hold current
    // for as long as the parking lock is engaged, with SPC parked at 500 mBar
    // behind it. Because OnOffSolenoid::on() only inrushes from the off state,
    // the garage shift's own set_shift_circuit(sc_3_4, true) is then a no-op:
    // the valve is never stroked by the engagement, only by whatever happened
    // when Y4 first came on. On 2026-09-09 that was during cranking, at no line
    // pressure, on both drives where the car would not go into gear (0 of 6);
    // every engagement with Y4 first stroked at full pressure worked.
    //
    // false is what the owner's EGS51 ROM (A0215451432) does: Y4 is off in N,
    // P, R, 1st and 2nd, and off during the N/P -> D engagement. It is the
    // ROM's only PWM-modulated shift solenoid, driven in gears 3-5 during a
    // shift; the N/P pulse the code contains is calibrated to zero ticks on
    // this part. See tmp/egs51/README.md section 11. false also restores the
    // pre-merge property that engagement starts from Y4 off and gets a fresh
    // inrush stroke under line pressure - 14 of 14 engagements in 1068-1162 ms.
    //
    // Live-editable over KWP so the two can be A/B'd without a reflash.
    bool hold_3_4_in_pn;
} __attribute__ ((packed)) SBS_MODULE_SETTINGS;

const SBS_MODULE_SETTINGS SBS_DEFAULT_SETTINGS = {
    .f_shown_if_flare = false,
    .debug_show_up_down_arrows_in_r = false,
    .en_trq_req_1_2 = true,
    .en_trq_req_2_3 = true,
    .en_trq_req_3_4 = true,
    .en_trq_req_4_5 = true,

    .en_trq_req_2_1 = true,
    .en_trq_req_3_2 = true,
    .en_trq_req_4_3 = true,
    .en_trq_req_5_4 = true,

    .next_gear_min_accel_mms2 = INT16_MIN,   // disabled; 214 is the measured value
    .agility_blend = 0,                      // off: the profile swap, as before
    .agility_blend_lo = 20,
    .agility_blend_hi = 80,
    .ab_interleave = false,
    .downshift_min_end_rpm = INT16_MIN,      // disabled; 0 is the measured value
    .redline_offset_auto_upshift = 100,
    .hold_3_4_in_pn = false,                 // EGS51 behaviour; true = the 47c7633 hold
};

// Pressure manager settings
typedef struct {
    // DEBUG: Friction coefficient when stationary (In gear)
    uint8_t stationary_coefficient;
    // DEBUG: Friction coefficient when releasing a clutch
    uint8_t releasing_coefficient;
    // DEBUG: Friction coefficient when applying a clutch (Cold)
    uint8_t applying_coefficient_cold;
    // DEBUG: Friction coefficient when applying a clutch (Hot)
    uint8_t applying_coefficient_hot;
} __attribute__ ((packed)) PRM_MODULE_SETTINGS;



const PRM_MODULE_SETTINGS PRM_DEFAULT_SETTINGS = {
    .stationary_coefficient = 100,
    .releasing_coefficient = 120,
    .applying_coefficient_cold = 185,
    .applying_coefficient_hot = 140
};

// Adaptation settings
typedef struct {
    // Minimum transmission oil temperature for adaptation
    //
    // UNIT: degrees C
    int16_t min_atf_temp;
    // Maximum transmission oil temperature for adaptation
    //
    // UNIT: degrees C
    int16_t max_atf_temp;
    // Minimum input speed for adaptation
    //
    // UNIT: RPM
    uint16_t min_input_rpm;
    // Maximum input speed for adaptation
    //
    // UNIT: RPM
    uint16_t max_input_rpm;
    // Prefill time/pressure adapt allowed for the K1 clutch
    bool prefill_adapt_k1;
    // Prefill time/pressure adapt allowed for the K2 clutch
    bool prefill_adapt_k2;
    // Prefill time/pressure adapt allowed for the K3 clutch
    bool prefill_adapt_k3;
    // Prefill time/pressure adapt allowed for the B1 brake
    bool prefill_adapt_b1;
    // Prefill time/pressure adapt allowed for the B2 brake
    bool prefill_adapt_b2;
    // The max pressure delta (+/-) allowed for prefill adaptation
    //
    // UNIT: mBar
    uint16_t prefill_max_pressure_delta;
    // The max time delta (+/-) allowed for prefill adaptation
    //
    // UNIT: milliseconds
    uint16_t prefill_max_time_delta;
    // Torque adaptation allowed for 1-2
    bool adapt_trq_1_2;
    // Torque adaptation allowed for 2-3
    bool adapt_trq_2_3;
    // Torque adaptation allowed for 3-4
    bool adapt_trq_3_4;
    // Torque adaptation allowed for 4-5
    bool adapt_trq_4_5;
    // Torque adaptation allowed for 2-1
    bool adapt_trq_2_1;
    // Torque adaptation allowed for 3-2
    bool adapt_trq_3_2;
    // Torque adaptation allowed for 4-3
    bool adapt_trq_4_3;
    // Torque adaptation allowed for 5-4
    bool adapt_trq_5_4;
    // Enable adaptation when manual shifting.
    // It is disabled by default as this can
    // cause shift latency
    bool adaptation_when_manual_shifting;
    // Trim shift pressure and fill time from the measured shift quality.
    //
    // Every completed forward shift is judged from the TCU's own quality vector
    // (ShiftQuality in the shift trace) and nudges the same adaptation cells the
    // built-in fill time / fill pressure adaptation writes:
    //   flare (turbine ran away)          -> prefill + flare step AND SPC + flare step, at once
    //   slip energy over budget           -> SPC + flare step (protect the plates)
    //   slow response                     -> prefill + step
    //   fast response with a torque hole  -> prefill - step (the clutch bit early)
    //   harsh (jerk over target)          -> SPC - step, small
    //   soft AND long                     -> SPC + step, small
    // Asymmetric on purpose: a clutch that slips under load is destroyed while one
    // that is over-clamped is merely harsh, so raises are large and immediate and
    // cuts are small. The SPC offset is clamped by prefill_max_pressure_delta and
    // the prefill offset by quality_prefill_max_cycles.
    //
    // The built-in fill time / fill pressure adaptation is suspended while this is
    // on, so two learners cannot fight over one cell. Pressure is only learned for
    // shifts that own a cell (1-2, 2-3, 3-4, 4-5, 4-3); 2-1, 3-2 and 5-4 share an
    // upshift's cell and only learn fill time.
    bool quality_adapt;
    // Skip learning from shifts that started above this agility score. A shift the
    // driver asked to be sporty must not teach the Comfort calibration.
    uint8_t quality_max_agility;
    // Jerk above this is harsh. Vehicle jerk in mm/s^3: 12000 is the published
    // comfort limit (12 m/s^3); objectionable is usually quoted over 20-30 m/s^3.
    // The 2026-09-07 drive measured a median of 39 m/s^3.
    uint16_t quality_jerk_target_mms3;
    // Response (request until the ratio moves) above this is slow. ms
    uint16_t quality_response_hi_ms;
    // Response below this, together with a torque hole, means the applying clutch
    // bit before the releasing one let go. ms
    uint16_t quality_response_lo_ms;
    // Torque hole confirming an early bite: output shaft rpm/s lost mid-shift.
    uint16_t quality_hole_target;
    // Slip energy budget per shift. Over it, pressure goes up regardless of feel. J
    uint16_t quality_slip_budget_j;
    // A shift under half the jerk target that also lasts longer than this is soft
    // and long, and gets a little more pressure. ms
    uint16_t quality_duration_hi_ms;
    // SPC step for a harsh, or a soft-and-long, shift. mBar
    int16_t quality_spc_step_mbar;
    // SPC step on a flare or a slip budget breach. mBar
    int16_t quality_flare_spc_step_mbar;
    // Prefill step for a slow or an early response. 20 ms cycles
    int8_t quality_prefill_step_cycles;
    // Prefill step on a flare. 20 ms cycles
    int8_t quality_flare_prefill_step_cycles;
    // Clamp on the prefill offset this learner may reach, either way. cycles
    uint8_t quality_prefill_max_cycles;
    // Skip shifts below this output shaft speed (garage and creep shifts). rpm
    uint16_t quality_min_output_rpm;
    // Skip shifts on a grade steeper than this once the road load estimator is
    // confident. sin(grade) x 10000; 500 is about 3 degrees.
    uint16_t quality_max_terrain;
} __attribute__ ((packed)) ADP_MODULE_SETTINGS;

const ADP_MODULE_SETTINGS ADP_DEFAULT_SETTINGS = {
    .min_atf_temp = 60,
    .max_atf_temp = 110,
    .min_input_rpm = 1000,
    .max_input_rpm = 3000,
    .prefill_adapt_k1 = true,
    .prefill_adapt_k2 = true,
    .prefill_adapt_k3 = true,
    .prefill_adapt_b1 = true,
    .prefill_adapt_b2 = true,
    .prefill_max_pressure_delta = 200,
    .prefill_max_time_delta = 200,
    .adapt_trq_1_2 = false,
    .adapt_trq_2_3 = false,
    .adapt_trq_3_4 = false,
    .adapt_trq_4_5 = false,
    .adapt_trq_2_1 = false,
    .adapt_trq_3_2 = false,
    .adapt_trq_4_3 = false,
    .adapt_trq_5_4 = false,
    .adaptation_when_manual_shifting = false,
    .quality_adapt = false,                  // never driven: off until enabled for a drive
    .quality_max_agility = 40,
    .quality_jerk_target_mms3 = 12000,
    .quality_response_hi_ms = 500,
    .quality_response_lo_ms = 150,
    .quality_hole_target = 60,
    .quality_slip_budget_j = 12000,
    .quality_duration_hi_ms = 1400,
    .quality_spc_step_mbar = 10,
    .quality_flare_spc_step_mbar = 40,
    .quality_prefill_step_cycles = 1,
    .quality_flare_prefill_step_cycles = 2,
    .quality_prefill_max_cycles = 10,
    .quality_min_output_rpm = 300,
    .quality_max_terrain = 500,
};

enum EwmSelectorType: uint8_t {
    None = 0,
    Button = 1,
    Switch = 2
};

enum SelectableGearboxProfile : uint8_t {
    // Standard mode
    Standard = 0,
    // Comfort mode
    Comfort = 1,
    // Agility mode
    Agility = 2,
    /// Manual mode - REQUIRES TIPTRONIC OR PADDLES TO FUNCTION
    Manual = 3,
    /// Manual mode - REQUIRES TIPTRONIC OR PADDLES TO FUNCTION
    Race = 4
};

// Shifter settings
typedef struct {
    // TRRS shifter (Wired to the TCU) has a profile selector?
    bool trrs_has_profile_selector;
    // The type of profile selection available on the CAN EWM
    // shifter
    EwmSelectorType ewm_selector_type;
    // When using a switch profile selector. This is the profile
    // to use when in the top position
    SelectableGearboxProfile switch_profile_idx_top;
    // When using a switch profile selector. This is the profile
    // to use when in the bottom position
    SelectableGearboxProfile switch_profile_idx_bottom;
    // When using the SLR profile selector, this is the profile
    // when the profile selector is in the left position
    SelectableGearboxProfile slr_profile_idx_left;
    // When using the SLR profile selector, this is the profile
    // when the profile selector is in the center position
    SelectableGearboxProfile slr_profile_idx_center;
    // When using the SLR profile selector, this is the profile
    // when the profile selector is in the right position
    SelectableGearboxProfile slr_profile_idx_right;
    // CAN Shifter button profile selector - Enable Comfort mode
    bool ewm_enable_c;
    // CAN Shifter button profile selector - Enable Winter (Manual 2nd gear start) mode
    bool ewm_enable_w;
    // CAN Shifter button profile selector - Enable Agility mode
    bool ewm_enable_a;
    // CAN Shifter button profile selector - Enable Manual mode
    bool ewm_enable_m;
    // CAN Shifter button profile selector - Enable Race (Super fast manual) mode
    bool ewm_enable_r;
    // CAN Shifter button profile selector - Save profile for 
    // next start - Only applys for auto profiles (This overrides startup profile in basic options)
    bool ewm_save_profile;
    // CAN Shifter button profile selector - Save profile for 
    // next start (Including manual profile options)
    bool ewm_save_profile_manual;
    // Check the WIKI. This option allows you to wire up a push button to the TCU Pin 3 (PRG) if you
    // are running the EWM shifter without a profile button (W163/Sprinter vehicles). The button
    // should be wired between VBatt and Pin 3 of the TCU, and should conduct when pressed.
    bool ewm_custom_profile_btn;
    // When in automatic profiles (C/S/A), always show the gear number (5/4/3/2/1) on the cluster,
    // rather than showing just 'D'
    bool auto_show_gears_always;
} __attribute__ ((packed)) ETS_MODULE_SETTINGS;

const ETS_MODULE_SETTINGS ETS_DEFAULT_SETTINGS = {
    .trrs_has_profile_selector = true,
    .ewm_selector_type = EwmSelectorType::Button,
    .switch_profile_idx_top = SelectableGearboxProfile::Comfort,
    .switch_profile_idx_bottom = SelectableGearboxProfile::Standard,
    .slr_profile_idx_left = SelectableGearboxProfile::Comfort,
    .slr_profile_idx_center = SelectableGearboxProfile::Standard,
    .slr_profile_idx_right = SelectableGearboxProfile::Manual,
    .ewm_enable_c = false,
    .ewm_enable_w = false,
    .ewm_enable_a = false,
    .ewm_enable_m = true,
    .ewm_enable_r = false,
    .ewm_save_profile = true,
    .ewm_save_profile_manual = false,
    .ewm_custom_profile_btn = false,
    .auto_show_gears_always = false,
};

// Release shift settings
typedef struct {
    // Past this output shaft RPM, torque requests
    // will not be activated when upshifting
    uint16_t output_rpm_disable_trq_req;
    // Below this RPM, a clutch will be considered 'stationary'
    // which triggers the clutch syncronization phases
    // UNIT: RPM
    uint16_t clutch_stationary_rpm;
    // Clutch inertia control PID algorithm 'P' value (upshifts)
    int16_t pid_p_val_upshift;
    // Clutch inertia control PID algorithm 'I' value (downshifts)
    int16_t pid_i_val_upshift;
    // Clutch inertia control PID algorithm 'P' value (upshifts)
    int16_t pid_p_val_downshift;
    // Clutch inertia control PID algorithm 'I' value (downshifts)
    int16_t pid_i_val_downshift;
    // Mapping of pedal position to off clutch torque ramp release speed
    //
    // 'raw' values are pedal position (0-250 = 0-100%), 'new' values
    // are the output, in Nm/20ms reduction
    LinearInterpSetting torque_loss_speed_pedal_pos;
    // SPC ramp speed
    // UNIT: mBar/20ms
    uint8_t spc_ramp_speed;
    // SPC ramp multiplier in 'Manual' mode
    float spc_ramp_multi_m;
    // SPC ramp multiplier in 'Race' mode
    float spc_ramp_multi_r;
    // SPC offset based on input RPM. If your shifts are sliggish at higher
    // RPMs, then you can increase the output pressure here
    LinearInterpSetting adder_spc_rpm;
    // SPC offset based on pedal position for Race mode. Pedal is from 0-250
    LinearInterpSetting adder_spc_pedal_r;
    // SPC offset based on pedal position for Manual mode. Pedal is from 0-250
    LinearInterpSetting adder_spc_pedal_m;
    // SPC offset based on pedal position for all other modes. Pedal is from 0-250
    LinearInterpSetting adder_spc_pedal;
} __attribute__ ((packed)) REL_MODULE_SETTINGS;

const REL_MODULE_SETTINGS REL_DEFAULT_SETTINGS = {
    .output_rpm_disable_trq_req = 1500,
    .clutch_stationary_rpm = 130,
    .pid_p_val_upshift = -150,
    .pid_i_val_upshift = -5,
    .pid_p_val_downshift = 200,
    .pid_i_val_downshift = 5,
    .torque_loss_speed_pedal_pos = {
        .new_min = 0.1,
        .new_max = 0.5,
        .raw_min = 10,
        .raw_max = 250,
    },
    .spc_ramp_speed = 8,
    .spc_ramp_multi_m = 1.5,
    .spc_ramp_multi_r = 2.0,
    .adder_spc_rpm = {
        .new_min = 0,
        .new_max = 100,
        .raw_min = 2500,
        .raw_max = 5000,
    },
    .adder_spc_pedal_r = {
        .new_min = 0,
        .new_max = 500,
        .raw_min = 10,
        .raw_max = 250,
    },
    .adder_spc_pedal_m = {
        .new_min = 0,
        .new_max = 250,
        .raw_min = 10,
        .raw_max = 250,
    },
    .adder_spc_pedal = {
        .new_min = 0,
        .new_max = 100,
        .raw_min = 10,
        .raw_max = 250,
    }
};

// Garage shift settings
typedef struct {
    // Number of 20ms cycles before garage shift times out
    // and the TCU tries again
    // UNIT: cycles
    uint16_t timeout_cycles;
    // Prefilling time for B2 clutch (For N to D shift)
    // 'raw' values are the ATF Temperature (In Celcius), 'new' values
    // are the number of 20ms cycles for prefilling (so 20 would be 400ms)
    LinearInterpSetting prefill_time_b2;
    // Prefilling time for B3 clutch (For N to R shift)
    // 'raw' values are the ATF Temperature (In Celcius), 'new' values
    // are the number of 20ms cycles for prefilling (so 20 would be 400ms)
    LinearInterpSetting prefill_time_b3;

    // Apply ramp for B2 clutch
    // 'raw' values are the ATF Temperature (In Celcius), 'new' values
    // are the pressure added to B2 every 20ms until it engages
    LinearInterpSetting p_ramp_b2;
    // Apply ramp for B3 clutch
    // 'raw' values are the ATF Temperature (In Celcius), 'new' values
    // are the pressure added to B2 every 20ms until it engages
    LinearInterpSetting p_ramp_b3;
} __attribute__ ((packed)) GAR_MODULE_SETTINGS;

const GAR_MODULE_SETTINGS GAR_DEFAULT_SETTINGS = {
    .timeout_cycles = 250,
    .prefill_time_b2 = {
        .new_min = 15,
        .new_max = 4,
        .raw_min = -10,
        .raw_max = 80,
    },
    .prefill_time_b3 = {
        .new_min = 15,
        .new_max = 4,
        .raw_min = -10,
        .raw_max = 80,
    },
    .p_ramp_b2 = {
        .new_min = 20,
        .new_max = 7,
        .raw_min = -10,
        .raw_max = 80,
    },
    .p_ramp_b3 = {
        .new_min = 20,
        .new_max = 7,
        .raw_min = -10,
        .raw_max = 80,
    },
};

// Crossover shift settings
typedef struct {
    // Below this RPM, a clutch will be considered 'stationary'
    // which triggers the clutch syncronization phases
    // UNIT: RPM
    uint16_t clutch_stationary_rpm;
    // Number of 20ms cycles for the overlap phase when at low torque (<= 2x Drag torque)
    // UNIT: cycles
    uint8_t overlap_cycles_low_trq;
    // Number of 20ms cycles for the overlap phase when at high torque (>= 10x Drag torque)
    // UNIT: cycles
    uint8_t overlap_cycles_high_trq;
    // Adder to overlap_cycles_low_trq for 1-2 at low torque
    // UNIT: cycles
    uint8_t overlap_cycles_low_trq_adder_1_2;
    // Adder to overlap_cycles_high_trq for 1-2 at low torque
    // UNIT: cycles
    uint8_t overlap_cycles_high_trq_adder_1_2;
    // Adder to overlap_cycles based on RPM. Increasing the output minimum can help
    // with harsh shifting at lower RPMs
    LinearInterpSetting overlap_cycles_adder_rpm;
    // Multiplier for the overlap cycles based on target shift speed
    LinearInterpSetting overlap_multi_shift_speed;
    // Torque adder factor for upshifting in normal profiles
    float adder_trq_multi_normal_up;
    // Torque adder factor for upshifting in manual profile
    float adder_trq_multi_manual_up;
    // Torque adder factor for upshifting in race profile
    float adder_trq_multi_race_up;
    // Torque adder factor for downshifting in normal profiles
    float adder_trq_multi_normal_dn;
    // Torque adder factor for downshifting in manual profile
    float adder_trq_multi_manual_dn;
    // Torque adder factor for downshifting in race profile
    float adder_trq_multi_race_dn;
    // Number of 20ms cycles for the torque sync phase when at low torque (<= 2x Drag torque)
    // UNIT: cycles
    uint8_t sync_cycles_low_trq;
    // Number of 20ms cycles for the torque sync phase when at high torque (>= 10x Drag torque)
    // UNIT: cycles
    uint8_t sync_cycles_high_trq;
    // Adder to sync_cycles_low_trq for 1-2 at low torque
    // UNIT: cycles
    uint8_t sync_cycles_low_trq_adder_1_2;
    // Adder to sync_cycles_high_trq for 1-2 at low torque
    // UNIT: cycles
    uint8_t sync_cycles_high_trq_adder_1_2;
    // Adder to sync_cycles based on RPM. Increasing the output minimum can help
    // with harsh shifting at lower RPMs
    LinearInterpSetting sync_cycles_adder_rpm;
    // Multiplier for the output sync cycles based on target shift speed
    LinearInterpSetting sync_multi_shift_speed;
    // Torque sync torque adder ramp value based on shift speed (Output is in Nm/20ms)
    LinearInterpSetting sync_trq_adder_speed;

    // Torque request multiplier based on pedal position (100% = 250)
    LinearInterpSetting trq_req_multi_pedal_pos;
    // Torque request multiplier based on input RPM
    LinearInterpSetting trq_req_multi_input_rpm;
    // Clutch inertia control PID algorithm 'P' value (upshifts)
    int16_t pid_p_val_upshift;
    // Clutch inertia control PID algorithm 'I' value (downshifts)
    int16_t pid_i_val_upshift;
    // Clutch inertia control PID algorithm 'D' value (downshifts)
    int16_t pid_d_val_upshift;
    // Clutch inertia control PID algorithm 'P' value (upshifts)
    int16_t pid_p_val_downshift;
    // Clutch inertia control PID algorithm 'I' value (downshifts)
    int16_t pid_i_val_downshift;
    // Clutch inertia control PID algorithm 'D' value (downshifts)
    int16_t pid_d_val_downshift;
} __attribute__ ((packed)) CRS_MODULE_SETTINGS;

const CRS_MODULE_SETTINGS CRS_DEFAULT_SETTINGS = {
    .clutch_stationary_rpm = 130,
    .overlap_cycles_low_trq = 10,
    .overlap_cycles_high_trq = 6,
    .overlap_cycles_low_trq_adder_1_2 = 3,
    .overlap_cycles_high_trq_adder_1_2 = 2,
    .overlap_cycles_adder_rpm = LinearInterpSetting {
        .new_min = 3,
        .new_max = 1,
        .raw_min = 1000,
        .raw_max = 4000
    },
    .overlap_multi_shift_speed = LinearInterpSetting {
        .new_min = 0.5,
        .new_max = 1.0,
        .raw_min = 100,
        .raw_max = 750
    },

    .adder_trq_multi_normal_up = 1.0,
    .adder_trq_multi_manual_up = 1.5,
    .adder_trq_multi_race_up = 2.0,
    .adder_trq_multi_normal_dn = 1.0,
    .adder_trq_multi_manual_dn = 1.5,
    .adder_trq_multi_race_dn = 2.0,

    .sync_cycles_low_trq = 10,
    .sync_cycles_high_trq = 7,
    .sync_cycles_low_trq_adder_1_2 = 2,
    .sync_cycles_high_trq_adder_1_2 = 1,
    .sync_cycles_adder_rpm = LinearInterpSetting {
        .new_min = 0,
        .new_max = 2,
        .raw_min = 1000,
        .raw_max = 4000
    },
    .sync_multi_shift_speed = LinearInterpSetting {
        .new_min = 0.5,
        .new_max = 1.0,
        .raw_min = 100,
        .raw_max = 750
    },
    .sync_trq_adder_speed = LinearInterpSetting {
        .new_min = 0.25,
        .new_max = 1.0,
        .raw_min = 1000,
        .raw_max = 100
    },

    .trq_req_multi_pedal_pos = LinearInterpSetting {
        .new_min = 0,
        .new_max = 0.5,
        .raw_min = 25,
        .raw_max = 250
    },
    .trq_req_multi_input_rpm = LinearInterpSetting {
        .new_min = 1.0,
        .new_max = 1.5,
        .raw_min = 1500,
        .raw_max = 6000
    },
    .pid_p_val_upshift = 150,
    .pid_i_val_upshift = 15,
    .pid_d_val_upshift = 30,
    .pid_p_val_downshift = -150,
    .pid_i_val_downshift = -5,
    .pid_d_val_downshift = -15
};

// module settings
extern TCC_MODULE_SETTINGS TCC_CURRENT_SETTINGS;
extern SOL_MODULE_SETTINGS SOL_CURRENT_SETTINGS;
extern SBS_MODULE_SETTINGS SBS_CURRENT_SETTINGS;
extern PRM_MODULE_SETTINGS PRM_CURRENT_SETTINGS;
extern ADP_MODULE_SETTINGS ADP_CURRENT_SETTINGS;
extern ETS_MODULE_SETTINGS ETS_CURRENT_SETTINGS;
extern REL_MODULE_SETTINGS REL_CURRENT_SETTINGS;
extern GAR_MODULE_SETTINGS GAR_CURRENT_SETTINGS;
extern CRS_MODULE_SETTINGS CRS_CURRENT_SETTINGS;

// Setting IDx
#define TCC_MODULE_SETTINGS_SCN_ID 0x01
#define SOL_MODULE_SETTINGS_SCN_ID 0x02
#define SBS_MODULE_SETTINGS_SCN_ID 0x03
#define PRM_MODULE_SETTINGS_SCN_ID 0x05
#define ADP_MODULE_SETTINGS_SCN_ID 0x06
#define ETS_MODULE_SETTINGS_SCN_ID 0x07
#define REL_MODULE_SETTINGS_SCN_ID 0x08
#define GAR_MODULE_SETTINGS_SCN_ID 0x09
#define CRS_MODULE_SETTINGS_SCN_ID 0x0A

namespace ModuleConfiguration {
    esp_err_t load_all_settings();
    esp_err_t reset_settings(uint8_t idx);
    esp_err_t write_settings(uint8_t module_id, uint16_t buffer_len, uint8_t* buffer);
    esp_err_t read_settings(uint8_t module_id, uint16_t* buffer_len, uint8_t** buffer);
}

#endif