/* A0215451432 bank0 6E6A..6EA2: normal scheduler prefix through adaptation.
 * The prefix is retained for callers that explicitly own the remaining stages.
 * One invocation advances the OEM timers once; no physical tick period assumed. */
#include "egs51_model.h"
void egs51_scheduler_prefix_tick(Egs51 *s) {
    egs51_timers_tick(s);
    egs51_vehicle_flags(s);
    egs51_pedal_inputs(s);
    egs51_target_step(s);
    egs51_aux_qualification(s);
    egs51_engine_inputs(s);
    egs51_wheel_inputs(s);
    egs51_gear_qualification(s);
    egs51_shaft_inputs(s);
    egs51_clutch_speeds(s);
    egs51_shift_supervisor(s);
    egs51_clutch_speeds(s);
    egs51_turbine_filter(s);
    egs51_torque_inputs(s);
    egs51_shift_control_tick(s);
}

/* Complete bank0 normal task chain 6E6A..6EC1. Acquisition, boot services,
 * interrupt/current-control cadence and nonvolatile storage remain external. */
void egs51_scheduler_tick(Egs51 *s) {
    egs51_scheduler_prefix_tick(s);
    egs51_ratio_observer(s);
    egs51_tcc_scheduler(s);
    egs51_diagnostic_latches(s);
    egs51_diagnostic_scan(s);
    egs51_input_fault_summary(s);
    egs51_range_speed_latches(s);
    egs51_gear_demand(s);
    egs51_usage_counters(s);
    egs51_gs218_compose(s);
    egs51_status_compose(s);
}
