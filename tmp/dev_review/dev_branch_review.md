# Upstream `dev` vs local `log-map-source` — comparison and code review

Date: 2026-09-07
Upstream: https://github.com/rnd-ash/ultimate-nag52-fw branch `dev` at `8289b64` (fetched as remote `upstream`)
Local: branch `log-map-source` at `ce6a2d2`
Merge base: `1b96089` (2026-06-08)

| | commits since merge base | src files touched |
|---|---|---|
| local | 8 (one squashed "Update TCU shift logic and logger tooling" commit carries most fixes) | 38 |
| upstream dev | 75 | 49 |

Line numbers below are for the **upstream `dev`** tree unless marked `(local)`.
Read a dev file with `git show upstream/dev:src/...`.

---

## Part 1 — Bugs fixed locally that are still present in `dev`

Every entry was checked by grep against the dev tree today. "Same fix in dev" entries are listed
separately in Part 2 so this list is only what dev still lacks.

### 1.1 Wrong behaviour in the driving logic

| # | dev location | Bug still in dev | Local fix |
|---|---|---|---|
| 1 | `src/gearbox.cpp:1483-1495` | ATF-temperature block is inverted: the solenoid-resistance calibration runs only when the sensor read is **invalid** and uses `INT16_MAX` as the temperature, so `resistance_spc/mpc` are corrected by (25 − 32767) × 0.393 %. On a valid read, `atf_temp` is also updated while shifting (comment says it must not be). | Calibrate on the first **valid** read, only update `atf_temp` when not shifting. |
| 2 | `src/gearbox.cpp:1046,1178-1189` | `gear_disagree_count` is set to 20 at boot so the gear must be verified by ratio before shifting, then unconditionally cleared to 0 whenever the car is slow, stationary or speeds are invalid. At a standstill the guard is gone before the car moves. | Only clear on a confirmed ratio match, a completed shift, or a garage shift. |
| 3 | `src/gearbox.cpp:1210` | `if (GET_CLOCK_TIME() - start > 100)` is always false (`start` is the current cycle's start, the loop runs at 20 ms), so `pedal_delta`/`input_rpm_delta` trackers never update. Dev's new redline predictor does not use them, but `DeltaTracker` is dead. | Compare against `last_delta_time`. |
| 4 | `src/driver_dynamics/dynamics.cpp:16` | `DeltaTracker::update` never stores `last_value`, so every delta is measured against the first sample; also the `samples` constructor argument is ignored (hard-coded 25). | Store `last_value`, use `this->samples`. |
| 5 | `src/gearbox.cpp:1206` | Pedal SNV fallback (25 %) is only applied to the smoothed value; `pedal_pos` keeps the stale raw value so the two disagree. | Apply fallback to both. |
| 6 | `src/gearbox.cpp:124-133` | Reverse ratio drift bands are inverted: reverse ratios are negative, so `rr × 1.1` is the *minimum*, not the maximum. `calcGearFromRatio` for reverse can never match. `calc_input_rpm_from_req_gear` also has no Reverse case (returns raw output rpm), which the new garage shift uses for `rpm_delta` into R. | Swap the bounds, add Reverse cases with `abs()`. |
| 7 | `src/gearbox.cpp` (ratio bounds) | With ±10 % bands, 4th (0.90–1.10) and 5th (0.75–0.91) overlap and the first-hit scan picks 4th. | Cap neighbouring bands at the geometric midpoint. |
| 8 | `src/gearbox.cpp` (`elapse_shift` cleanup) | `tcc->shift_end()` is only called from inside the crossover algorithm. Release shifts, aborted shifts and emergency-timer exits leave the TCC in "shifting" state. | Always call `tcc->shift_end()` in the shift cleanup. |
| 9 | `src/gearbox.cpp` (`process_speed_sensors`) | A dead N2 sensor reads 0 pulses; in 5th that gives turbine = 0 and triggers a 5-4. | Treat N2 < 50 while output > 250 in a forward gear as a sensor fault. |
| 10 | `src/gearbox.cpp` (engine rpm SNV) | Engine rpm SNV substitutes the last value forever. Dev added an "engine off" branch but only when `input_rpm == 0`, which never happens in gear (converter drag). | Substitute for 10 cycles, then treat as stopped. |
| 11 | `src/profiles.cpp:145,212,342,384` | `should_downshift` null-checks `upshift_table` but dereferences `downshift_table` (all four profiles). | Check `downshift_table`. |
| 12 | `src/profiles.cpp:350,355` | `StandardProfile::should_upshift` stacks +1000 rpm (5 s post-shift) and +1000 rpm (load 0.2–0.8) on a map already indexed on pedal. On a diesel `converted_driver_torque/max_torque ≈ 0.6` at a third pedal, so part-throttle upshifts run 700–1300 rpm above the map (measured 3334 vs map 2064 at 33 % pedal). The adders can also push the threshold past the redline; dev's predictor only intervenes at pedal > 20 %. | Rescale to +300 rpm / 2 s and +400 rpm over load 0.5–1.0, clamp at redline − 250, add the redline force-upshift in `controller_loop`, add a 2 s post-upshift downshift inhibit (anti-hunt). |
| 13 | `src/maps.cpp` (downshift maps) | Coast columns of the Standard/Comfort/Agility downshift maps are 100/150 rpm (2-1, 3-2), Comfort's whole 2-1 low half is literally 0. Indexed on input-shaft rpm, these mean "never", so the box holds 3rd to a standstill then fires 3-2 and 2-1 under power on pull-away. | Descending road-speed ladder (600/650/700/900). Keys bumped to `*_DN_1` so the NVS copy is replaced. |
| 14 | `src/maps.cpp` (downshift time maps) | 2000 ms overlap at 0 % pedal below 1000 rpm; shifts are serialised so a 4-3-2-1 coast ladder takes longer than the car takes to stop and the 2-1 completes at standstill (clunk on brake release, measured). | Coast cells 800 ms (950 for C/W). Keys bumped to `*_DNSHIFT_T1`. |
| 15 | `src/inputcomponents/kickdownswitch.cpp:10` | `is_kickdown_newly_pressed` fires on **both** edges, so releasing kickdown asks for another downshift. | Rising edge only. |
| 16 | `src/torque_converter.cpp:210` | `else if (react_on_engine_open_request)` opens the TCC whenever the setting is on, regardless of what the engine actually requests. | Also require `engine_req_state == Open`. |
| 17 | `src/torque_converter.cpp:349` | The <60 °C temperature multiplier overwrites `tcc_commanded_pressure`, so the internal pressure model and state promotion see the scaled value and the pressure ratchets down every cycle. | Scale only the value sent to the pressure manager. |
| 18 | `src/torque_converter.cpp` (state decision) | No hysteresis between Open/Slip/Closed targets; rpm/pedal jitter at a map boundary toggles the commanded pressure. | ±10 rpm hysteresis on the target state. |
| 19 | `src/gearbox.cpp` (TCC off path) | When speeds go invalid or the box leaves a forward gear, TCC pressure is forced to 0 but the `TorqueConverter` model still believes it is locked; on re-entry it resumes at lock pressure. Also a single-cycle sensor dropout dumps a locked TCC (thump). | `TorqueConverter::reset()` and hold pressure for < 5 invalid cycles. |
| 20 | `src/tcu_io/tcu_io.cpp:150` | ATF-from-engine-temperature mode reads `onepoll_motor_temperature.current_value` without validity check; before the first CAN frame it filters towards 0 °C. | Use `get_onepoll_sensor_val`, start CAN onepolls with `e_counter = 254`. |
| 21 | `src/sensors.cpp` (ATF resistance) | A resistance far beyond the KTY83 table (open connector) is reported as max temperature instead of invalid. | > 1.2 × last table entry → `INT_MAX`. |
| 22 | `src/sensors.cpp:57` | `calc_rpm`: `t` can be 0 → divide by zero. | Guard. |
| 23 | `src/gearbox.cpp` (engine stopped) | With the engine stopped, `update_pressures` was still called every cycle from the bottom of the loop (dev fixed the "while shifting" half of this, not the engine-off half) and TCC target pressure was not zeroed. | Skip when engine rpm ≤ 100, zero TCC target. |
| 24 | `src/gearbox.cpp` (`shift_thread` N→D) | Garage-shift SPC target hard-codes `/ 1.993` ("TODO spc multi"). Dev rewrote the garage shift and this line is gone, but the rewrite still does not use `shift_spc_gain` for the initial target (it goes through `ShiftHelpers::correct_shift_shift_pressure`, which does — OK). | Use `HYDR_PTR->shift_spc_gain[0]`. Not applicable after dev's rewrite. |

### 1.2 Shift algorithm arithmetic

| # | dev location | Bug still in dev | Local fix |
|---|---|---|---|
| 25 | `src/shifting_algo/s_algo.cpp:157` | `phase_bleed` passes the SPC target (already including release spring) into `calc_mod_min_abs_trq`, which adds the release spring again. | Pass the raw filling pressure. |
| 26 | `src/shifting_algo/s_algo.cpp:204,357`, `set_p_apply_clutch_with_spring` | `short` intermediates: `pressure + centrifugal − spring` and `momentum*20/inertia` overflow at high pressures/torques (silent wrap). `correct_shift_shift_pressure(int16_t)` same. | `int`. |
| 27 | `src/shifting_algo/s_algo.cpp:631` | Torque-adaptation analysis divides the **current** `abs_input_trq` by `pid_count` instead of `abs_sum`, so `avg_abs_torque` is ~1/N of reality and the scalar is always the low-torque one. | Use `abs_sum`. |
| 28 | `src/shifting_algo/s_algo.cpp` (fill-pressure adapt) | Cancelled adaptation jumps to stage 4 and still analyses the partial data; `phase_id > 4` misses the max-pressure phase; `time` can be 1 or 2 cycles; the correction limit is `2000 × spc_multi/1000` instead of the settings value. | Stage 5 on cancel, `>= 4`, `time >= 3`, `prefill_max_pressure_delta`. |
| 29 | `src/shifting_algo/s_algo.cpp:58` | `first_order_pump_trq_filter` seeded from `pump_torque` without checking for `INT16_MAX` (engine 0). Dev now seeds at 100× so the overflow is 100× worse. | Skip when `INT16_MAX`. |
| 30 | `src/shifting_algo/shifting_algo_helpers.cpp` | `get_shift_intertia` can return 0 (zeroed cal + drag 0) and is used as a divisor. | `MAX(1.0F, r)`. |
| 31 | `src/shifting_algo/shift_crossover.cpp:146`, `shift_release.cpp`, `shift_adaptation.h` | Prefill-cycle adaptation offset is stored `int16_t` but read into `int8_t` (truncation at ±128 cycles); `calc_t_adapt_offset_adv(int8_t)`. | `int16_t` / `int`. |
| 32 | `src/adaptation/shift_adaptation.cpp` (`offset_*`) | SPC, freeing-torque and applying-torque adaptation offsets accumulate without bound (`ptr[idx] += offset`, four places). | Clamp to `prefill_max_pressure_delta` / ±50 Nm. |
| 33 | `src/adaptation/shift_adaptation.cpp:77` | Log says "min limit" for the max limit. | Cosmetic. |
| 34 | `src/shifting_algo/shift_release.cpp:77` | `spc_ramp_val` hard-coded 8; the `REL_CURRENT_SETTINGS.spc_ramp_speed` / `spc_ramp_multi_m/r` settings are ignored. | Use the settings. |
| 35 | `src/shifting_algo/shift_release.cpp:162` | `torque_req_out` can exceed indicated torque when coasting (negative indicated), and `amount` goes negative into an unsigned field. Emergency-limit path sets `torque_req_out` but not `torque_req_val`, so the request drops to 0 the cycle the emergency clears. | Clamp ≥ 0 both sides, keep `torque_req_val` in sync. |
| 36 | `src/shifting_algo/shift_release.cpp:500`, `shift_release.h` | `calc_sync_mod_pressure` uses `this->torque_adder`, a separate member that is never written (always 0), instead of `trq_adder`. | Use `trq_adder`, delete the dead member. |
| 37 | `src/models/clutch_speed.cpp:12,14` | `get_speed_long_eq` multiplies by `r_high` in the numerator, inconsistent with the inline B2 speed calculation it is meant to mirror. | Remove the factor. |

### 1.3 CAN layers

| # | dev location | Bug still in dev | Local fix |
|---|---|---|---|
| 38 | `src/canbus/can_custom.cpp:103` | Coolant temperature returns `PEDAL − 40`. | `T_COOLANT − 40`. |
| 39 | `src/canbus/can_egs52.cpp` (`get_torque_data`) | 13-bit torque fields compared against `UINT16_MAX`, so the "signal not available" marker `0x1FFF` is decoded as 1523 Nm. | Compare with `0x1FFF`. |
| 40 | `src/canbus/can_egs53.cpp` (14 places) | `expire_time_ms*1000` / `*10000` passed as an ms expiry → stale frames accepted for 1000 s; `EngTrq* != INT16_MAX` on 13-bit fields (should be `0x1FFF`); `INT_MAX != ret.m_max` on an `int16_t` (always true); `get_pedal_value` returns 0 on SNV instead of `0xFF`. | All fixed. |
| 41 | `src/canbus/can_hfm.cpp:181` | Pedal scaled to 0–100 but `pedal_pos` is 0–250 elsewhere, so HFM cars run at ≤ 40 % of the real pedal. | Scale to 250. |

### 1.4 Solenoids / hardware

| # | dev location | Bug still in dev | Local fix |
|---|---|---|---|
| 42 | `src/solenoids/pwm_solenoid.cpp:56` | `adc_cali_raw_to_voltage` writes a 4-byte `int` through `reinterpret_cast<int*>(&ret)` where `ret` is a `uint16_t` — stack corruption on the two adjacent bytes; return value ignored. | Proper `int` local, check the result. |
| 43 | `src/solenoids/solenoids.cpp:41` | `CHANNEL_ID_MAP[ADC_CHANNEL_9]` (9 entries) is indexed by the 4-bit channel field (0–15) of the DMA result → out-of-bounds read on unexpected channels. | 16 entries, mask with `& 0xF`. |
| 44 | `src/solenoids/solenoids.cpp:140` | Temperature compensation computes `ΔT × coef / 10` and uses it as a multiplier (≈ 0.0x instead of 1.0x). | `1 + ΔT × coef / 100`. |
| 45 | `src/solenoids/cc_solenoid.cpp:44` | Constant-current feed-forward assumes a fixed `cc_vref_solenoid`; the PID then has to absorb the whole battery-voltage error. Divide by zero on a zeroed `cc_reference_resistance`. | Feed-forward from measured battery mV, guard the divisor. |
| 46 | `src/solenoids/inrush_solenoid.cpp:162` | `total - this->hold_time` underflows (unsigned) when `total > hold_time`. | Guarded remaining-time. |
| 47 | `src/pressure_manager.cpp:75-124`, `profiles.cpp`, `torque_converter.cpp` | `delete[]` on single `new StoredMap` objects (11 places); pointer left dangling after delete; `StoredData` has no virtual destructor. | `delete`, null the pointer, virtual dtor. |
| 48 | `src/pressure_manager.cpp:523` | MPC flush logic compares `target_modulating_pressure`, which is always clamped ≥ `min_mpc_pressure`, so the "was below min" condition never holds and the flush never runs. | Track the un-clamped output. |
| 49 | `src/pressure_manager.cpp` | No guards for zeroed `p_multi` (`calc_current_linear_sol`), zeroed coefficient settings, or a zero friction value used as divisor in `calc_max_torque_for_clutch`. | Guards; `p_clutch_with_coef` results clamped to the return type. |
| 50 | `src/egs_calibration/calibration.cpp:36-49` | `reload_egs_calibration` leaks the temp buffer on every early `goto exit`, and the "zeroed ratio table" check inspects the block already in use rather than the new one. Only the ratio table is checked (not `p_multi`, `shift_spc_gain`, which are divisors). | Structured checks on the new block, always free, `check_calibration_plausible()`. |
| 51 | `src/nvs/eeprom_config.cpp` | A map seeded from the prog-flash default is logged as "loaded OK from NVS", so the boot log cannot tell a user edit from the built-in map. | Distinct log lines. |

---

## Part 2 — Fixes both branches made (same conclusion, sometimes different code)

These do not need porting but will produce merge conflicts:

- `is_stationary()` judged on the output shaft only (dev: `output_rpm < 10`; local: `output_rpm < 60 && input_rpm < 1000` with the input bound as a dead-output-sensor guard).
- `update_pressures()` no longer called from `controller_loop` while shifting.
- `get_input_torque_factor` guards `engine == 0`.
- `SHIFT_FLAG_COAST_32_21` checks `_2_1` instead of `_1_2`.
- `phase_bleed` seeds `p_apply_clutch = SPC_MAX` and ramps from the stored value.
- `phase_overlap2` no longer ends on the off-clutch slipping (that ended the previous phase).
- `phase_fill_release_mpc` arms `trq_req_down_ramp` once.
- `trq_at_release_clutch` floor: local corrected the `/100.0` typo to `/10.0` (drag torque is Nm × 10); dev removed the line and introduced `filling_torque = MAX(abs, drag/10)`.
- EGS51 `m_converted_driver` only overwritten when not frozen.
- Prefill "max limit" log text (dev did not fix, see #33).

---

## Part 3 — Things `dev` has that local lacks (consider porting)

Genuine fixes and features in dev since the merge base:

1. **TCC ISR vs flash writes** (`inrush_solenoid.cpp`, `map_editor.cpp`, `flasher.cpp`, `eeprom_impl.h`, `eeprom_config.cpp`, `gearbox.cpp` save-in-P): the gptimer ISR is stopped around every NVS/flash write and the TCC solenoid is driven to 0 while stopped. Fixes the "crash when flashing/saving maps in P" reports. Local memory notes a boot loop from core-dump-to-flash on IDF 5.3; dev moved to `espressif32@6.12.0` (IDF 5.5) and keeps `COREDUMP_ENABLE_TO_FLASH` + `CHECK_BOOT` on. Worth re-testing on 5.5 rather than carrying the UART workaround.
2. **GPIO expander initialised after flash reads** (`main.cpp`, `board_config.*`): avoids an I2C init race at boot.
3. **CAN rx filter** (`can_hal.cpp:140`): `rx.rtr == 0` instead of `rx.flags == 0`, needed on IDF 5.5 where `flags` carries extra bits.
4. **`first_order_filter`** (`lib/core/tcu_maths.cpp`): explicit `int32_t` cast on the divisor.
5. **Coefficient default** (`pressure_manager.cpp`): `default: coef = 100.F` — the coefficients are stored ×100 (120/185/140), so the old `1.F` fallback was 100× off. Local still has `1.F`.
6. **Reverse_Second / B3 friction correction** in `p_clutch_with_coef` and `calc_max_torque_for_clutch`.
7. **EGS51**: brake signal from `BS_200`, drag torque (`DRG_TORQUE`) folded into min/max/ind, `MAX_TRQ_FACTOR` applied, `GS_418` transmitted (profile/gear display on the cluster). See review item R7 on the drag-torque validity requirement.
8. **EGS53** diag variant code `0x0253` (was `0x0353`).
9. **Garage shift rewrite** (`gearbox.cpp:597-830`): staged B2/B3/K2 fill with sync detection and a retry path; N→D at speed selects the clutch for the gear the car is actually in (`last_motion_gear`) instead of always 2nd. Large change, unreviewed on this car.
10. **Acceleration tracking** (`process_acceleration`, `SensorData.acceleration_ms2`) and crossover `torque_accel_corr` / `calculate_dynamic_inertia` filtering. See R3 — as written the correction cannot be positive.
11. **Redline prediction** (`gearbox.cpp:1397-1425`): forces an upshift in auto profiles when the filtered engine-rpm slope predicts hitting `redline − redline_offset_auto_upshift` within the shift's fill+overlap time. Local's version is simpler (input-rpm rate × 0.5 s, any pedal) and also clamps the profile adders. Dev's only acts above 20 % pedal, so the adder overrun at part throttle (#12) is not covered.
12. **TCC**: coast slip table when input torque ≤ 0, prefill cycles no longer ×3, adaptation rows kept monotonic (`tcc_adaptation.h`) with a Unity test (`test/test_tcc_adaptation`).
13. **Crossover**: overlap/overlap2 cycle calculations moved into `ShiftHelpers`, profile-dependent torque-adder multipliers, adaptation adder applied inside overlap2 per sub-phase, `get_and_set_adapt_rpm_off_clutch` returns signed, low-fill relaxation for all coasting upshifts.
14. **Torque request activation** for crossover upshifts lowered to ½ drag torque (was 2×).
15. **Downshift algorithm choice** (`gearbox.cpp:440-452`): now release-shift for load downshifts and coasting 3-2/2-1, crossover for 5-4/4-3 coasting and forced shifts (previous logic was inverted).
16. `auto_show_gears_always` setting (show D vs gear number in auto profiles), `redline_offset_auto_upshift` setting.
17. `shift_thread` cleanup clears `algo_feedback`.
18. Speed/engine rpm no longer low-pass filtered (`a75c11a`), `calc_rpm` zeroes readings under 60 rpm.

---

## Part 4 — Code review of `dev` (changes since the merge base)

Severity: **High** = wrong control output or crash; **Medium** = wrong adaptation/diagnostics or latent; **Low** = cleanup.

### R1 — High — Fill-pressure adaptation downshift RPM check is a tautology
`src/shifting_algo/s_algo.cpp:464`
```c
bool rpm_in_range = (sd->engine_rpm - 5 <= sd->input_rpm && upshifting) ||
                    (sd->input_rpm - 5 <= sd->input_rpm && !upshifting);
```
The downshift half compares `input_rpm` with itself, so it is always true and the
"engine/input RPM delta too high" cancel never fires on downshifts. Pressure adaptation then
learns from shifts where the converter was slipping. Intended: `sd->input_rpm - 5 <= sd->engine_rpm`.
(The merge-base version had `±100` tolerances in the right direction.)

### R2 — High — ATF temperature / solenoid calibration inverted
`src/gearbox.cpp:1483-1495` — pre-existing, still in dev. Detailed as #1 above. On a TCU whose
ATF sensor drops out even once, `resistance_spc/mpc` become large negatives and the
constant-current solenoid model is wrong until reboot.

### R3 — High — Acceleration torque correction can never be positive
`src/shifting_algo/shift_crossover.cpp:376`
```c
this->torque_accel_corr = MIN(accel_corr_trq, this->torque_accel_corr);   // member initialised to 0
```
`MIN(x, 0)` is ≤ 0 for all x, so the correction that is supposed to compensate for the vehicle
accelerating during the shift only ever applies while *decelerating*. `get_trq_adder_map_val`
then subtracts it for upshifts (adding torque) and adds it for downshifts. Either the intent was
`MAX`, or the member should be reset per shift and set, not min-ed. Also the units: see R8.

### R4 — High — Map reset leaves the TCC solenoid permanently disabled
`src/diag/map_editor.cpp:198-204`
```c
sol_tcc->isr_disable();
vTaskDelay(5);
if (ESP_OK != ptr->reset_from_flash()) {
    return NRC_GENERAL_REJECT;      // isr_enable() never reached
}
sol_tcc->isr_enable();
```
A failed reset from the config app leaves `is_disabled()` true, and `TorqueConverter::update`
commands 0 TCC pressure until reboot. `burn_to_eeprom` in the same file does it correctly.
`Flasher::on_request_download` (`flasher.cpp:71`) has the same shape: every error return after
`isr_disable()` (erase failure, size rejection) leaves the TCC off, and there is no re-enable on
success either (acceptable only if a reboot always follows).

### R5 — Medium — Boot-in-gear ratio guard is cleared while stationary
`src/gearbox.cpp:1046` sets `gear_disagree_count = 20` so a TCU that boots in D must confirm the
gear by ratio before the profile may shift; `1178-1189` reset it to 0 whenever `output_rpm ≤ 100`,
stationary or speeds invalid, i.e. immediately at the standstill the car booted in.

### R6 — Medium — EGS51 driver torque floored at zero
`src/canbus/can_egs51.cpp:144` `m_esp = MAX(0, MIN(m_esp - m_drg, m_max))`. `converted_driver_torque`
can no longer be negative on EGS51, so `elapse_shift`'s coasting-upshift path
(`converted_driver_torque <= -threshold/2` → `ReleasingShift`) is unreachable and every closed-throttle
upshift runs the crossover algorithm. Downshift algorithm selection (`gearbox.cpp:446`) uses the same
signal.

### R7 — Medium — EGS51 torque data now requires `DRG_TORQUE`
`src/canbus/can_egs51.cpp:137`: all torque fields stay `INT16_MAX` (NDEF) unless `MS_310.DRG_TORQUE`
is valid. On an engine ECU that sends `0xFF` there, the TCU has no torque at all. Consider defaulting
`m_drg` to 0 when SNV rather than invalidating the whole set.

### R8 — Medium — `process_acceleration` units do not reduce to the documented scale
`src/gearbox.cpp:1738-1760`, `gearbox.h`. `wheel_spd` is commented "10x value" but stores
`output_rpm × 100 / diff`. `wheel_accel_m = Δ(wheel rpm×100 per 20 ms) × circumference_mm / 300`:
the conversion from per-cycle rpm×100 to rev/s² is `/120`, not `/300`, and the result is then
`×100` into `acceleration_ms2` ("100× real value") and `/10` into `SensorData.acceleration_ms2`.
Whatever the intended unit, it is consumed by `calculate_accel_trq_corr` through a further chain of
magic divisors (`/1000`, `×6.0`, `/10.0`, `/wheel_circumference`, `/10`). This needs a worked
example in a comment or a unit test; as it stands nobody can check it.

### R9 — Medium — Garage-shift pedal adder saturates at 1 % pedal
`src/gearbox.cpp:631` `int p_1 = MIN(25, (1100 * sensor_data.pedal_pos) / 25);` — for any
`pedal_pos ≥ 1` the inner term is ≥ 44 and `p_1` is 25. Probably meant `MIN(1100, pedal*25)` or
similar. Effect is only 25 mbar so it is a calibration nit, but it is not doing what it says.

### R10 — Medium — `first_order_pump_trq_filter` seeded from an invalid pump torque
`src/shifting_algo/s_algo.cpp:58` seeds `tcc_trq_multiplier × 100 × pump_torque` on the first
step without checking `pump_torque != INT16_MAX` (engine rpm 0 gives `INT16_MAX`). The 100× scale
makes the overflow far worse than before. Same class of bug as local #29.

### R11 — Medium — Downshift redline check moved from −500 to −100
`src/gearbox.cpp:1440`: a requested downshift is now allowed if the predicted input rpm in the lower
gear is ≤ `redline − 100`. Combined with dev's removal of input-rpm filtering and the serialised
shift chain, a kickdown at the top of a gear will land within 100 rpm of the limiter before the
fill phase even starts. Consider whether this was meant to interact with the new predictor.

### R12 — Low — Bit test written as equality
`src/gearbox.cpp:446` `(sid.shift_flags & SHIFT_FLAG_COAST) == 1` works only because
`SHIFT_FLAG_COAST` is `BIT(0)`. Use `!= 0`.

### R13 — Low — Member shadowing in `CrossoverShift`
`src/shifting_algo/shift_crossover.h:44-47` redeclares `trq_req_timer`, `trq_req_up_ramp` and
`torque_req_val`, all of which also exist in `ShiftingAlgorithm` (`s_algo.h:145-156`). Nothing in
the base class currently reads them, so it is harmless today, but `ReleasingShift` uses the base
copies and any future base-class logic will silently see zeros for crossover shifts. Local deleted the
duplicates.

### R14 — Low — Timer ISR callbacks no longer `IRAM_ATTR`
`src/solenoids/inrush_solenoid.cpp:141,191`. The crash fix stops the timer around the flash writes
the firmware itself performs, but an ISR running from flash will still fault during any other
cache-disabled window (OTA, NVS wear-levelling, core dump). If `CONFIG_GPTIMER_ISR_IRAM_SAFE` is not
set, keep the callbacks in IRAM as well.

### R15 — Low — Dead and leftover code
- `can_egs51.cpp:20` `gs418.FMRAD = 1.0;` assigns a float to an 11-bit field, immediately overwritten with `0x7FF`.
- `torque_converter.cpp` `calc_pid_score()` is an empty stub with a public declaration.
- `flasher.cpp` has commented-out `printf("CheckN")` debug lines.
- `s_algo.cpp` `calc_low_filling_p` has a commented-out race-mode adder block instead of a removal.
- `gearbox.cpp` garage shift has a ~15-line commented-out alternative completion path.

### R16 — Low — Engine-off detection depends on `input_rpm == 0`
`src/gearbox.cpp:1229`. In gear at idle the converter keeps the turbine at 100–300 rpm, so the
"engine off, USB powered" branch cannot trigger in D/R; on the bench in P it can. If it does trigger
because of a CAN dropout while the car is rolling in N, `actual_gear` is forced to Neutral.

---

## Part 5 — Merge notes

- `src/gearbox.cpp` (542 lines changed upstream vs 143 locally), `s_algo.cpp`, `shift_crossover.cpp`
  and `shift_release.cpp` will conflict heavily. The garage-shift rewrite and the unfiltered speed
  path are the big structural differences.
- Local map-key bumps (`*_DN_1`, `*_DNSHIFT_T1`) must survive the merge or the corrected downshift
  maps will not take on TCUs that have already booted dev.
- Workflows: dev added `pip install intelHex` to both workflows; local has
  not touched them.
- `sdkconfig.unified`: dev is regenerated for IDF 5.5 (450 lines). Local's core-dump-to-UART change
  should be re-evaluated on 5.5 rather than carried across blindly.
- `tmp/shift_replay/` (local) compiles the shift algorithms for the host; after merging, the stubs
  need `SensorData.acceleration_ms2`, `wheel_speed_mps`, `ShiftInterfaceData.diff_ratio`, and the
  new `ShiftHelpers` functions.

---

## Part 6 — What was ported from `dev` (2026-09-07, commits d22ecea..7a309ef)

Each item is its own commit on `log-map-source` so it can be reverted alone. Firmware builds
clean, the host replay harness (`tmp/shift_replay`) still compiles, and the TCC adaptation cases
pass on the host.

| commit | upstream | what | review notes |
|---|---|---|---|
| d22ecea | — | `first_order_filter` divisor cast to `int32_t` | No behaviour change. |
| 3db7243 | 5d8f5f6 | CAN rx keeps every frame except RTR | `flags == 0` also dropped 29-bit IDs. Field exists on IDF 5.3. |
| b434684 | d74bb57 | EGS53 diag variant code `0x0253` | Matches the `0x0251/0x0252` pattern. Not testable here. |
| 83751de | 4b388a2 | Coefficient fallback `100.F` | PRM coefficients are x100 (120/185/140); our zero-guard was also on the wrong scale. Only reachable through the `default:` case or a zeroed setting. |
| 1efb9ba | 5260067 | IO expander created after NVS/cal reads | Verified nothing touches `ioexpander` before the shifter is created. |
| 092617e | 4ccdf3d | EGS51 brake from `BS_200`; TRRS lock sense inverted | Brake was hard-coded `false` on EGS51, so our brake-dependent upshift hold and downshift-inhibit bypass never fired on this car. TRRS change matches shift-lock semantics but is untested here (this car may not use TRRS). |
| a49ab90 | bc2931c, 5a04818, 0fe765f | EGS51 gross → net torque via `DRG_TORQUE` | Log `nag52_20260907_104051` shows `min_torque` always 0 and static 0 while coasting, i.e. gross values with a 0 floor, while EGS52/53 give net. **Deviation:** `DRG_TORQUE` SNV falls back to 0 instead of invalidating all torques (dev R7). `MAX_TRQ_FACTOR` deliberately not applied (see below). **Drive-test needed:** on-load torque drops by the drag torque, so clutch pressures during shifts will be a little lower. |
| d375cfc | f7f2356, c8596b4 | TCC adaptation rows kept monotonic + Unity test | Ran the seven upstream cases plus a lowest-cell-decrease case on the host: all pass. |
| 7e89b93 | 2836e10 | Cancel fill adaptation on an input-torque step | Adaptation part only; the crossover fill-exit block on `torque_jumped` was not taken (it would hold the off clutch slipping longer). |
| 7a309ef | c936d0e | TCC shift handling starts at fill when adapting | Only has an effect when the TCC unlock settings would unlock anyway; moves that unlock ~one fill time earlier on adaptive shifts. |

### Reviewed and not ported

- **TCC ISR stop around flash writes** (2409592, 687dfbc, a3a0171): not needed here. Our
  `sdkconfig.unified` leaves `CONFIG_GPTIMER_ISR_IRAM_SAFE` unset, so IDF masks that interrupt
  during flash writes. Dev enabled it on IDF 5.5, which is what made their ISR run during writes
  and crash, and they then worked around it by stopping the timer. Porting it would also import R4.
- **`MAX_TRQ_FACTOR`**: applied unconditionally upstream with scale 0.0078 (128 = 1.0). An ECU
  sending `0xFF` would double `m_max`, `0x00` would zero it. Needs a raw `MS_310` capture from this car
  first.
- **GS_418 transmission on EGS51** (586cc5f, 6f2ab88, 010059c): upstream's own `can_data.txt` marks the
  signals "TODO check"; adds a new 20 ms frame to the bus with `FMRAD` (wheel-torque factor) at SNV.
  Only worth taking once the cluster display is wanted and the frame is confirmed harmless.
- **Reverse_Second B3 friction correction** (fdcf448): scales the R2 B3 friction by
  `B2(2nd)/B2(1st)`. Cannot be checked without the EGS disassembly, and `start_second` makes R2 the
  normal reverse on this car, so a wrong multiplier would change every reverse engagement.
- **Downshift algorithm selection** (0859e93, dee90cf): coasting 3-2/2-1 become release shifts and
  mid-torque downshifts become crossover. Our coast-down fixes were tuned and replayed with the
  current selection; changing it invalidates that work without a new drive log.
- **Garage shift rewrite** (071c116, fdcf448), **acceleration tracking / crossover compensation**
  (0a30126, 8756616, R3/R8), **redline predictor** (89273b7, ca28ef3; ours already covers it), **unfiltered
  speed/engine RPM** (a75c11a), **bleed timer 3→5 cycles** (43c53c0), **release-shift loss-torque
  retune** (300876d), **torque-request activation at ½ drag torque** (cd5f1b0, e1466f1), **TCC coast slip
  table and prefill ×3 removal**, **downshift redline margin 500→100** (b7908d7, R11), and the rest
  of the crossover rework: all behaviour changes without data from this car. Candidates for a
  replay-harness A/B, not a blind port.
- **New settings fields** (`redline_offset_auto_upshift`, `auto_show_gears_always`): need the config
  app's YAML to follow; skipped.
- **IDF 5.5 / `espressif32@6.12.0` and the regenerated `sdkconfig`**: separate migration.
- **N/P observed ratio = 0** (1d7f036) and **N3 < 60 rpm → 0** (f5e6a52): our standstill handling
  already judges on the output shaft; no change needed.
