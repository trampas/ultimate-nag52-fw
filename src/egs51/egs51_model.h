/* Portable A0215451432 controller core; live input/output adapter required.
 * im includes upper INDIRECT RAM, separate from sfr (8051 direct addresses >=80).
 * Words are big endian. ROM must contain both 65536-byte banks. Callers provide
 * valid calibration pointers/indices. Scratch registers, concurrent interrupts,
 * physical timing and helper scratch RAM are outside the semantic API.
 */
#ifndef EGS51_MODEL_H
#define EGS51_MODEL_H
#include <stdint.h>
#include <assert.h>
#ifdef __cplusplus
extern "C" {
#endif
typedef struct {
    uint8_t im[256], x[1024], sfr[128];
    const uint8_t *rom;
} Egs51;
/* Original CAN object register image; registers 4/5 hold pending bits. */
typedef struct { uint8_t registers[256]; } Egs51CanRx;
void egs51_can_receive(Egs51 *s,Egs51CanRx *rx);
static inline uint16_t egs51_word(const uint8_t *p) { return (uint16_t)((p[0]<<8)|p[1]); }
static inline void egs51_put(uint8_t *p, uint16_t v) { p[0]=(uint8_t)(v>>8); p[1]=(uint8_t)v; }
static inline uint8_t egs51_rom8(const Egs51 *s, unsigned bank, uint16_t a) { return s->rom[bank*65536u+a]; }
static inline uint16_t egs51_rom16(const Egs51 *s, unsigned bank, uint16_t a) {
    return (uint16_t)((egs51_rom8(s,bank,a)<<8)|egs51_rom8(s,bank,(uint16_t)(a+1)));
}
uint16_t egs51_lag(uint16_t cur, uint16_t target, uint8_t n);
uint16_t egs51_lerp(uint16_t y0,uint16_t y1,uint16_t x0,uint16_t x1,uint16_t x);
uint16_t egs51_map16(const Egs51 *s,unsigned bank,uint16_t desc,uint16_t x,uint16_t y);
uint16_t egs51_spc(const Egs51 *s,uint8_t idx,uint16_t clutch);
uint16_t egs51_pressure_demand(const Egs51 *s,uint16_t pressure);
uint16_t egs51_pi(uint16_t *integrator,uint8_t demand,uint8_t feedback,uint8_t kp,uint8_t ki);
void egs51_current_control(Egs51 *s); /* bank0 3EEC, assumes ISR already scaled feedback/reset I */
uint8_t egs51_fill_time(const Egs51 *s); /* bank1 56A6 */
uint8_t egs51_hold_time(const Egs51 *s); /* bank1 56DE */
uint16_t egs51_engage_timeout(const Egs51 *s);
uint16_t egs51_engage_torque_pressure(const Egs51 *s,uint16_t torque);
void egs51_engage_momentum(Egs51 *s);
uint8_t egs51_engage_match(Egs51 *s,uint8_t ramp,uint8_t hold,uint8_t inhibit,uint8_t clutch);
void egs51_engage_recover(Egs51 *s);
void egs51_engage_prepare(Egs51 *s);
void egs51_engage_control(Egs51 *s);
void egs51_engage_finish(Egs51 *s);
void egs51_engage_abort(Egs51 *s);
void egs51_engage_resolve(Egs51 *s);
void egs51_garage_select(Egs51 *s);
void egs51_garage_release(Egs51 *s);
void egs51_garage_prefill(Egs51 *s);
void egs51_garage_inhibit(Egs51 *s);
void egs51_fault_pressure(Egs51 *s);
void egs51_engagement(Egs51 *s); /* bank1 5BB6..6191, ALL nine states */
void egs51_frame_compose(Egs51 *s); /* bank0 0711..07F7 */
void egs51_output_pattern(Egs51 *s); /* bank0 6BCC..6BE0 transfer, with 1B3 inhibit; caller runs scheduler */
void egs51_shift_solenoid_select(Egs51 *s); /* bank1 23EE..2437, caller must satisfy R1 != 7 guard */
void egs51_gear_map(Egs51 *s); /* bank1 2B86..2BB1, excludes preceding calls */
uint8_t egs51_cal_select(Egs51 *s);
uint8_t egs51_cal_select_bank0(Egs51 *s);
void egs51_timers_tick(Egs51 *s);
void egs51_gs218_compose(Egs51 *s);
uint8_t egs51_feedback_scale(uint8_t raw,uint8_t trim,uint16_t offset);
void egs51_current_interrupt(Egs51 *s,uint8_t page1,uint8_t page3);
typedef struct {
    uint8_t (*spi_byte)(void *context,uint8_t tx);
    void (*compare)(void *context,uint16_t counter,uint8_t control);
    void *context;
} Egs51Io;
void egs51_spi_exchange(Egs51 *s,uint8_t mode,const Egs51Io *io);
void egs51_tcc_interrupt(Egs51 *s,const Egs51Io *io);
void egs51_gear_reset(Egs51 *s);
uint8_t egs51_shift_factor(Egs51 *s);
uint16_t egs51_shift_threshold(Egs51 *s,uint8_t idx,uint8_t parameter);
void egs51_mode_transition(Egs51 *s,uint8_t mode,uint8_t variant);
void egs51_shift_direction(Egs51 *s);
void egs51_shift_supervisor(Egs51 *s);
uint8_t egs51_map8(const Egs51 *s,unsigned bank,uint16_t desc,uint8_t x,uint8_t y);
uint16_t egs51_curve16(const Egs51 *s,unsigned bank,uint16_t desc,uint16_t x);
uint8_t egs51_fill_term(Egs51 *s);
void egs51_tcc_demand(Egs51 *s);
void egs51_tcc_override(Egs51 *s);
typedef struct {
    uint8_t page7,page5,page9,page_b,page11,page13,page_f_first,page_f_second;
} Egs51AnalogInputs;
void egs51_analog_scan(Egs51 *s,const Egs51AnalogInputs *inputs);
uint8_t egs51_curve8(const Egs51 *s,unsigned bank,uint16_t desc,uint8_t x);
uint8_t egs51_tcc_target(const Egs51 *s);
void egs51_tcc_feedforward(Egs51 *s);
void egs51_tcc_direction(Egs51 *s);
void egs51_tcc_slip_pi(Egs51 *s);
void egs51_tcc_regulate(Egs51 *s);
void egs51_tcc_entry(Egs51 *s);
void egs51_tcc_excess_slip(Egs51 *s);
void egs51_tcc_supervisor(Egs51 *s);
void egs51_tcc_adapt(Egs51 *s);
void egs51_tcc_scheduler(Egs51 *s);
uint16_t egs51_mpc_line(Egs51 *s);
uint16_t egs51_speed_pressure(const Egs51 *s,uint8_t selector);
void egs51_shift_gain(Egs51 *s);
void egs51_shift_setup(Egs51 *s);
uint16_t egs51_handoff_high_pressure(const Egs51 *s,uint8_t mode);
uint16_t egs51_handoff_low_pressure(const Egs51 *s,uint8_t mode);
uint16_t egs51_handoff_clutch_pressure(const Egs51 *s,uint16_t base_pressure);
void egs51_shift_feedback_reset(Egs51 *s);
void egs51_shift_clutch_context(Egs51 *s);
void egs51_downshift_handoff_advance(Egs51 *s);
uint16_t egs51_handoff_root_test(uint16_t value);
uint16_t egs51_signed_md(uint16_t a,uint16_t b,uint16_t d);
uint16_t egs51_signed_lerp(uint16_t y0,uint16_t y1,uint16_t x0,uint16_t x1,uint16_t x);
uint16_t egs51_overlap_pressure(const Egs51 *s,uint8_t idx,uint16_t on,uint16_t off);
uint16_t egs51_shift_mod_pressure(const Egs51 *s,uint8_t idx);
uint16_t egs51_shift_net_torque(const Egs51 *s);
uint16_t egs51_shift_signed_mod_pressure(const Egs51 *s,uint8_t idx);
uint16_t egs51_handoff_mod_pressure(const Egs51 *s,uint8_t idx);
void egs51_shift_fill_torque(Egs51 *s);
void egs51_shift_adapt_address(Egs51 *s,uint8_t stride,uint8_t first,uint16_t base);
void egs51_shift_pressure_compensation(Egs51 *s);
uint16_t egs51_gear_sync_speed(const Egs51 *s,uint8_t gear);
void egs51_downshift_handoff(Egs51 *s);
void egs51_applying_capacity(Egs51 *s,uint16_t pressure,uint8_t gain);
void egs51_release_apply(Egs51 *s);
uint16_t egs51_shift_pid(Egs51 *s,uint16_t memory,uint16_t cal,uint16_t error);
uint16_t egs51_percent_filter(uint8_t weight,uint16_t next,uint16_t old);
uint8_t egs51_release_hold_time(Egs51 *s,uint8_t idx);
uint8_t egs51_release_ramp_time(const Egs51 *s,uint8_t idx);
uint16_t egs51_release_initial_pressure(const Egs51 *s,uint8_t idx);
uint16_t egs51_release_momentum(const Egs51 *s);
uint16_t egs51_release_final_pressure(const Egs51 *s,uint8_t idx);
void egs51_shift_momentum_control(Egs51 *s,uint16_t momentum);
void egs51_release_modulate(Egs51 *s);
uint16_t egs51_release_bleed_pressure(const Egs51 *s,uint8_t idx,uint16_t on);
void egs51_release_entry(Egs51 *s);
uint16_t egs51_release_transfer_apply(const Egs51 *s);
uint16_t egs51_release_transfer_mod(const Egs51 *s,uint8_t idx);
void egs51_release_transfer(Egs51 *s);
uint16_t egs51_release_match_pressure(const Egs51 *s,uint8_t idx);
void egs51_release_match(Egs51 *s);
uint16_t egs51_crossover_clutch_pressure(const Egs51 *s,uint16_t p);
uint16_t egs51_crossover_bleed_pressure(const Egs51 *s,uint8_t idx,uint16_t on);
uint16_t egs51_crossover_fill_pressure(const Egs51 *s,uint8_t idx,uint16_t low);
uint16_t egs51_crossover_free_pressure(const Egs51 *s,uint8_t idx);
void egs51_crossover_fill(Egs51 *s);
void egs51_crossover_momentum_target(Egs51 *s);
uint16_t egs51_crossover_transfer_mod(const Egs51 *s,uint8_t idx);
uint16_t egs51_crossover_transfer_apply(const Egs51 *s);
uint16_t egs51_crossover_spring_mod(const Egs51 *s,uint8_t idx,uint16_t on);
void egs51_crossover_transfer(Egs51 *s);
uint16_t egs51_crossover_match_mod(const Egs51 *s,uint8_t idx);
uint16_t egs51_crossover_match_apply(const Egs51 *s);
void egs51_crossover_match(Egs51 *s);
uint8_t egs51_crossover_inertia_time(const Egs51 *s);
void egs51_crossover_torque_map(Egs51 *s);
void egs51_crossover_torque_margin(Egs51 *s);
uint16_t egs51_crossover_momentum(const Egs51 *s);
uint16_t egs51_crossover_inertia_apply(const Egs51 *s);
uint16_t egs51_crossover_settle_apply(const Egs51 *s);
void egs51_crossover_inertia(Egs51 *s);
uint16_t egs51_adapt_speed_excursion(Egs51 *s);
void egs51_adapt_fill_error(Egs51 *s,uint8_t elapsed);
void egs51_adapt_fill_observe(Egs51 *s);
void egs51_torque_context(Egs51 *s);
void egs51_turbine_filter(Egs51 *s); /* bank0 CA22..CA64 */
void egs51_vehicle_flags(Egs51 *s); /* bank0 BA18..BC49 */
void egs51_pedal_inputs(Egs51 *s); /* bank0 BC4A..BD4F */
void egs51_target_step(Egs51 *s); /* bank0 BD50..BE8D */
void egs51_aux_qualification(Egs51 *s); /* bank0 BE8E..BEC2 */
void egs51_gear_qualification(Egs51 *s); /* bank0 920F..9537 */
void egs51_shaft_inputs(Egs51 *s); /* bank0 C496..C6C5 */
void egs51_wheel_inputs(Egs51 *s); /* bank0 BFD5..C448 */
void egs51_engine_inputs(Egs51 *s); /* bank0 BEC3..BFD4 */
void egs51_torque_inputs(Egs51 *s); /* bank0 CA65..CFB0 */
void egs51_adapt_inertia_observe(Egs51 *s);
void egs51_shift_adaptation(Egs51 *s);
void egs51_adapt_weights(Egs51 *s,uint16_t x,uint16_t correction,uint16_t low,uint16_t high);
uint8_t egs51_adapt_limit(const Egs51 *s,uint16_t value);
void egs51_adapt_cells(Egs51 *s,uint16_t x,uint8_t offset);
void egs51_shift_cell_adaptation(Egs51 *s); /* bank1 B708..C0D2 */
void egs51_pressure_adaptation(Egs51 *s); /* bank1 D9C8..E16C */
void egs51_shift_demand_factor(Egs51 *s);
void egs51_adapt_transfer_observe(Egs51 *s);
void egs51_shift_finish(Egs51 *s);
void egs51_interrupt_fill_capacity(Egs51 *s,uint8_t gain);
uint16_t egs51_interrupt_release_pressure(const Egs51 *s);
uint16_t egs51_interrupt_release_mod_pressure(const Egs51 *s,uint8_t idx,uint16_t pressure);
uint16_t egs51_interrupt_release_settle_pressure(const Egs51 *s,uint8_t idx);
uint16_t egs51_interrupt_transfer_mod_pressure(const Egs51 *s,uint8_t idx);
uint16_t egs51_interrupt_transfer_pressure(const Egs51 *s);
void egs51_interrupt_release(Egs51 *s);
void egs51_interrupt_release_transfer(Egs51 *s);
void egs51_interrupt_context(Egs51 *s);
uint16_t egs51_interrupt_inertia_pressure(const Egs51 *s,uint8_t idx);
uint16_t egs51_interrupt_settle_pressure(const Egs51 *s,uint8_t idx);
void egs51_interrupt_crossover(Egs51 *s);
void egs51_interrupt_match(Egs51 *s);
void egs51_interrupt_finish(Egs51 *s);
/* Handles steady mode0 and forward modes1..4. Returns 0 with no changes
 * for enabled engagement/fault modes5 and above. A 0 result provides NO valid new actuator command. Calibration and
 * sensor domains still follow the core contract; this is not a vehicle API. */
int egs51_forward_pressure_tick(Egs51 *s);
/* Full bank1 2C4F pressure stage; supported calibration domains required. */
void egs51_pressure_tick(Egs51 *s);
/* Pressure, torque and all three adaptation stages; caller supplies other tasks. */
void egs51_shift_control_tick(Egs51 *s);
/* Bank0 6E6A..6EA2, including one timer tick; startup and remaining tasks required. */
void egs51_scheduler_prefix_tick(Egs51 *s);
void egs51_platform_timers(Egs51 *s);
/* Returns 0 at the OEM terminal halt, 1 on normal return. */
uint8_t egs51_solenoid_fault_monitor(Egs51 *s);
void egs51_output_enable_monitor(Egs51 *s);
void egs51_starter_output_monitor(Egs51 *s);
void egs51_supply_temperature_band(Egs51 *s);
void egs51_shaft_capture_n2(Egs51 *s);
void egs51_shaft_capture_n3(Egs51 *s);
void egs51_platform_diagnostics(Egs51 *s);
void egs51_starter_interlock(Egs51 *s);
void egs51_voltage_qualification(Egs51 *s);
void egs51_analog_reference_fault(Egs51 *s);
void egs51_analog_supply_fault(Egs51 *s);
void egs51_selector_inputs(Egs51 *s);
uint8_t egs51_pressure_init(Egs51 *s);
uint8_t egs51_controller_init(Egs51 *s); /* bank0 6EC2..7137 */
void egs51_scheduler_tick(Egs51 *s); /* complete normal bank0 6E6A..6EC1 */
void egs51_gear_demand(Egs51 *s); /* bank0 7331..8813 */
void egs51_coast_hold(Egs51 *s);
void egs51_demand_activity(Egs51 *s);
void egs51_load_bias(Egs51 *s);
void egs51_load_feedback(Egs51 *s);
void egs51_vehicle_acceleration(Egs51 *s);
void egs51_road_load(Egs51 *s);
void egs51_load_scale(Egs51 *s);
void egs51_load_corrections(Egs51 *s);
void egs51_wheel_motion(Egs51 *s);
void egs51_ratio_recovery(Egs51 *s);
void egs51_ratio_observer(Egs51 *s);
void egs51_diagnostic_latches(Egs51 *s); /* bank0 E01E..E0CA */
void egs51_diagnostic_scan(Egs51 *s); /* bank0 E0CB..E213 */
void egs51_input_fault_summary(Egs51 *s); /* bank0 E214..E25F */
void egs51_range_speed_latches(Egs51 *s);
void egs51_status_compose(Egs51 *s);
void egs51_usage_counters(Egs51 *s); /* bank0 E260..E48C */
void egs51_torque_control(Egs51 *s); /* bank1 CE9F..D76D */
uint16_t egs51_up_torque_threshold(Egs51 *s,uint8_t idx,uint8_t parameter); /* bank1 6568 */
void egs51_up_torque_exit(Egs51 *s); /* bank1 CC38 */
void egs51_up_torque_enter(Egs51 *s); /* bank1 C9D1 */
void egs51_down_torque_enter(Egs51 *s); /* bank1 CAD7 */
void egs51_down_torque_exit(Egs51 *s); /* bank1 CC8A */
void egs51_interrupted_torque_exit(Egs51 *s); /* bank1 CD9F */
void egs51_turbine_speed(Egs51 *s); /* bank0 C449 */
void egs51_clutch_speeds(Egs51 *s); /* bank0 C6C6 */
#ifdef __cplusplus
}
#endif
#endif
