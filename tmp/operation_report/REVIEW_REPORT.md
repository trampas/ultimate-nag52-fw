# ultimate-nag52-fw: TCU math and algorithm review

Date: 2026-09-06
Base commit: 1b96089 (main)
Scope: shift algorithms, pressure/solenoid pipeline, torque and TCC models, adaptation, sensors, gear detection, shift-point selection, ESP32 ADC usage (ESP-IDF 5.3.0 via platform espressif32@6.8.1).

Confidence legend: **confirmed** = code demonstrably does this; **likely** = wrong under realistic conditions but depends on calibration data not in the repo; **design** = works as coded but physically or control-theoretically questionable.

## 1. Summary

The core physics is sound: clutch application table, shift-circuit to clutch mapping, per-shift clutch slip kinematics, turbine speed reconstruction from N2/N3, torque to pressure conversions and their inverses, map interpolation, and PID sign conventions all check out. The defects are around the edges: unit and variable slips in adaptation, dead or overwritten logic, memory-safety issues, missing hysteresis, and missing validity handling on sensor and CAN inputs.

## 2. Confirmed bugs

| # | Location | Issue | Fix status |
|---|---|---|---|
| C1 | `src/solenoids/pwm_solenoid.cpp:131-134` | `adc_cali_raw_to_voltage` writes an `int` (4 bytes) through a `uint16_t*` (2 bytes). Stack corruption in the solenoid current feedback path. Verified against IDF 5.3.0 signature `esp_err_t adc_cali_raw_to_voltage(handle, int raw, int *voltage)`. | fixed |
| C2 | `src/shifting_algo/shift_release.cpp:130-150` | Emergency torque limit computed then unconditionally overwritten by the ramp value on line 150. Off-clutch overload protection never reaches CAN. | fixed |
| C3 | `src/shifting_algo/s_algo.cpp:614-615` | Torque adaptation divides instantaneous torque by sample count; `abs_sum` accumulated on line 395 never read. Learning scalar pinned at 0.10. Both divisions integer. | fixed |
| C4 | `src/shifting_algo/s_algo.cpp:540-545` | SPC offset clamp compares against `pressure_multi_spc_int` but assigns `2*` that value; offsets between the two jump up. `prefill_max_pressure_delta` setting never referenced. | fixed (now clamps to `prefill_max_pressure_delta`) |
| C5 | `src/shifting_algo/shift_release.cpp:496` | `torque_adder` member never written; sync phase ignores freeing-torque adaptation (`trq_adder`). | fixed |
| C6 | `src/shifting_algo/shifting_algo_helpers.cpp:27` | `SHIFT_FLAG_COAST_32_21` set for `_1_2` instead of `_2_1`. Coasting 1-2 release upshift gets 25 rpm sync thresholds. | fixed |
| C7 | `src/shifting_algo/shift_crossover.cpp:659` | Fill-time adaptation cycle count passed as `int8_t`; values over 127 wrap negative and adapt the wrong direction. Same wrap in `shift_adaptation.cpp:135` (`int8_t` return of a cell clamped to +/-200). | fixed |
| C8 | `src/torque_converter.cpp:196-208` | `else if` on engine TCC request does not test for `Open`; a `Slipping` request while already slipping fully opens the converter. | fixed |
| C9 | `src/torque_converter.cpp:331-344` | Cold-ATF multiplier scales `tcc_commanded_pressure` in place; model converges to scaled value while state promotion compares the unscaled value. State machine never settles below 60 C. | fixed |
| C10 | `src/gearbox.cpp:819` vs `:949-957` | Boot-in-D sets `gear_disagree_count=20` to force ratio verification, but the main loop zeroes it whenever stationary or slow. TCU then believes 5th and issues downshift toggles against unknown valve states. | fixed |
| C11 | `src/gearbox.cpp:492` and `:1381` | Shift thread and main loop both call `update_pressures` with different change states; commanded current flip-flops during shifts. Same call re-applies stale MPC/TCC after the engine-off shutdown (`:1197-1204`). | fixed |
| C12 | `src/canbus/can_egs52.cpp:182-187` | 13-bit torque fields compared against `UINT16_MAX`; SNV (0x1FFF) decodes as about +1547 Nm. | fixed |
| C13 | `src/sensors.cpp:56-67` | Dead speed sensor reads 0 rpm; sentinel overwritten. In 5th a dead N2 yields turbine 0 and triggers a real 5-4. | fixed (plausibility check added in `process_speed_sensors`) |
| C14 | `src/gearbox.cpp:994-997` | Engine RPM never expires on CAN loss. | fixed (expires after 10 cycles) |
| C15 | `src/solenoids/inrush_solenoid.cpp:145` | `total - hold_time` while `total < hold_time`; unsigned underflow, hold phase overruns by up to a PWM slice. | fixed |
| C16 | `pressure_manager.cpp`, `torque_converter.cpp`, `profiles.cpp` | `delete[]` on `new` objects on map-load failure; pointers left dangling so null guards are ineffective. | fixed |
| C17 | `src/shifting_algo/s_algo.cpp:106` | Bleed-phase torque floor uses `/100` (3 Nm) instead of `/10` (30 Nm). | fixed |
| C18 | `src/shifting_algo/s_algo.cpp:56` | Pump-torque filter seeded at 10x scale. | fixed |
| C19 | `src/gearbox.cpp:978` | Delta trackers compare against the current iteration start; never update. | fixed |
| C20 | `src/gearbox.cpp:1207-1231` | Solenoid resistance temperature calibration and "hold ATF during shift" logic sit in an unreachable branch. | fixed (restructured) |
| C21 | `src/gearbox.cpp:112-121`, `:1430-1436` | Reverse ratio bands have min/max swapped because the ratio is negative; reverse detection can never match. | fixed |
| C22 | `src/profiles.cpp:377` | Standard downshift null-checks the upshift table. | fixed |
| C23 | `src/shifting_algo/shift_release.cpp:375-378` | Torque-request down-ramp timer re-armed every cycle; ramp becomes geometric and stalls. | fixed |
| C24 | `src/egs_calibration/calibration.cpp` | Reload validates the live block instead of the temp block. No validation of hydraulic divisors. | fixed |
| C25 | `src/models/input_torque.cpp:20`, `gearbox.cpp:1315` | `input/engine` with engine 0 gives NaN multiplier sent on CAN. | fixed |
| C26 | `src/gearbox.cpp:907-911` | `gear_ratio` = inf when output is 0 and turbine >= 100 (N/P with engine running). | fixed |
| C27 | `src/tcu_io/tcu_io.cpp:345` | ATF substitute uses coolant value without validity check; defaults to 0 C. | fixed |
| C28 | `src/solenoids/solenoids.cpp:40` | `CHANNEL_ID_MAP` has 9 entries but is indexed by a 4-bit channel field (0-15). | fixed |
| C29 | `src/shifting_algo/s_algo.cpp:456-460` | Fill-pressure adaptation analysis runs on partial data after early cancellation. | fixed |
| C30 | `src/shifting_algo/s_algo.cpp:145` | Bleed phase adds the release spring twice into the MPC minimum. | fixed |

## 3. Design concerns

| # | Location | Issue | Action |
|---|---|---|---|
| D1 | `src/maps.cpp`, `src/profiles.cpp` | Up/down shift maps lack hysteresis for several cells: post-upshift rpm lands below the downshift line (Comfort diesel 2-3 at 30-50% pedal: -63 to -148 rpm; Standard diesel 2-3 at 40-80%: -7 to -92; all petrol 2-3 at 40%: -25). Comfort/Agility hunt at steady pedal. | Post-upshift downshift inhibit added in `Gearbox` (2 s, released by kickdown, brake, or pedal increase). Maps still need retuning. |
| D2 | `src/torque_converter.cpp:152-161` | TCC Open/Slip/Closed decision is a pure threshold on an interpolated map value; jitter toggles commanded pressure. | Hysteresis band added around the state transitions. |
| D3 | `src/torque_converter.cpp:305-323` | Closed-state adaptation bleeds lock pressure until slip appears; N2/N3 resolution is about 25 rpm per 20 ms window so the 5-20 rpm band is at the noise floor. | Left as is (OEM-derived). Recommend a dead-band tied to sensor resolution. |
| D4 | `src/gearbox.cpp:598`, `:637` | Garage shift: first SPC request divides by the SPC gain (clutch to solenoid conversion), the loop value does not. Hard-coded 1.993. | Hard-coded gain replaced with calibration value. Magnitude left unchanged pending intent. |
| D5 | `src/shifting_algo/shift_crossover.cpp:410-414` | Crossover downshift overlap2 subphase 1 exits on the same condition that ended overlap; sync ramp skipped. | Condition removed; needs road validation. |
| D6 | `src/shifting_algo/s_algo.cpp:77-83`, `gearbox.cpp:501-528` | Timeout-forced shift reports success with no ratio check. | Warning logged and the shift is not reported as clean; ratio detection recovers. |
| D7 | `src/adaptation/shift_adaptation.cpp:183-205` | SPC and torque offsets accumulate unbounded; PID has no anti-windup. | Clamps added: SPC +/-`prefill_max_pressure_delta`, torque +/-50 Nm. |
| D8 | `src/shifting_algo/s_algo.cpp:133` | Bleed ramp starts from constant SPC_MAX each cycle, giving a hyperbolic drop. | Ramp now starts from the previous value. |
| D9 | `src/gearbox.cpp:1185-1189` | One invalid speed cycle dumps TCC pressure. | Hold for up to 5 invalid cycles before opening. |
| D10 | `src/nvs/module_settings.h` | PID sign conventions rely on negative default gains for downshift and release-upshift. | Documented; no code change. |
| D11 | `src/gearbox.cpp:87-111` | +/-10% ratio bands overlap between 4th and 5th; first-hit scan picks 4th. | Bands capped at the geometric midpoint to the neighbour gear. |
| D12 | `src/solenoids/cc_solenoid.cpp:44` | Constant-current feed-forward assumes 12 V; PID absorbs battery and coil-temperature variation. | Feed-forward now uses measured battery voltage. |
| D13 | `src/solenoids/solenoids.cpp:141` | Temperature compensation formula wrong (2.16 instead of 1.216 at 80 C) and unused. | Formula corrected; still unused by design. |
| D14 | `src/pressure_manager.cpp:513-536` | MPC flush logic can never engage because the entry condition tests the already-clamped target. | Uses the pre-clamp output from the previous call. |
| D15 | `src/profiles.cpp:351-353`, `:278-280` | Standard never upshifts at pedal 0; Winter never auto-upshifts. | Left as is; intent unclear. |
| D16 | `src/shifting_algo/shift_release.cpp:107-111` | `max_torque_on/off_clutch` indexed per circuit; on/off may be swapped for downshifts depending on calibration semantics. | Left as is; needs calibration knowledge. |
| D17 | `src/gearbox.cpp:461` | Flare detection cannot see 1-2/4-5 flares (both terms non-negative on that circuit). Display only. | Left as is. |

## 4. ESP32 ADC usage (checked against ESP-IDF 5.3.0)

- `adc_cali_raw_to_voltage(handle, int raw, int *voltage)`: `pwm_solenoid.cpp` passed a `uint16_t` through `int*` (C1). Fixed with an `int` local.
- Continuous mode (`solenoids.cpp`): `ADC_DIGI_OUTPUT_FORMAT_TYPE1`, `SOC_ADC_DIGI_RESULT_BYTES = 2`, 12-bit data + 4-bit channel per sample. Parsing is correct for ESP32. `CHANNEL_ID_MAP` sized 9 but indexed by a 4-bit field (C28), fixed to 16 entries.
- Requested `sample_freq_hz = 1,464,000` is within the ESP32 limit (2 MHz). In IDF 5.3.0 the I2S path derives `bclk = 2 * fs`, so the realised rate should match the request; the "real freq is 600 kHz (IDF 5.1 bug)" comment is likely stale. This only affects frame timing (about 1.6 ms per 2400-sample frame instead of 4 ms), not the averaged values. Verify the frame period with a scope or timestamp if the PID cadence matters.
- Line-fitting calibration: `CONFIG_ADC_CALI_EFUSE_TP_ENABLE` and `VREF_ENABLE` are set, default-Vref boards are rejected at init. Correct.
- ADC2 oneshot for battery and ATF: no WiFi or BT in this firmware, so the ESP32 ADC2/WiFi conflict does not apply.
- 12 dB attenuation: the ESP32 line-fitting range is roughly 150 to 2450 mV. Battery at 14.4 V reads 2.6 V through the 5.54:1 divider (slightly nonlinear); above about 17 V it saturates. ATF divider math `Rs = V*R2/(3300-V)` and the parking-lock threshold (raw > 3000) are consistent.

## 5. Verified correct

- Clutch pairs per shift, holding clutches, and shift-circuit solenoid mapping match the 722.6 chart (1: B1 B2 K3; 2: K1 B2 K3; 3: K1 K2 B2; 4: K1 K2 K3; 5: B1 K2 K3).
- Clutch slip formulas reach zero at the correct sync ratios; two independent derivations of the 3rd-gear K3 speed agree.
- Turbine speed `n2*R + n3*(1-R)` with `R = r1/r2` is the front planetary Willis relation and holds in every gear.
- Torque to pressure and pressure to current conversions are exact inverses; clamps applied on the right side of each conversion.
- Map search and bilinear interpolation handle boundaries; `interpolate_float` swaps inverted axes correctly.
- Timer decrement and ramp semantics are consistent; every shift phase has a bounded exit.
- PID sign conventions (crossover on-clutch, release off-clutch, gains signed per direction) are consistent.
- The drag-torque x10 storage convention is applied consistently at every site except C17.

## 6. Fix log

All fixes were applied to the working tree on `main` (not committed). The `unified` environment builds cleanly with PlatformIO (espressif32@6.8.1, ESP-IDF 5.3.0); the only remaining warnings are pre-existing (unused variables, packed-member addresses, missing field initialisers).

### Files changed

| File | Changes |
|---|---|
| `src/shifting_algo/s_algo.cpp` | C3 (abs_sum, float division), C4 (clamp uses `prefill_max_pressure_delta`), C17 (`/10.0`), C18 (filter seed 1x, invalid pump torque skipped), C29 (cancelled adaptation skips analysis, min 3 cycles), C30 (raw fill pressure into `calc_mod_min_abs_trq`), D6 (timeout flag + warning), D8 (bleed ramp from previous value), analysis stage ends at MAX_PRESSURE (`>= 4`). |
| `src/shifting_algo/s_algo.h` | `shift_timed_out` flag and `did_time_out()`. |
| `src/shifting_algo/shift_release.cpp/.h` | C2 (emergency torque request no longer overwritten), C5 (`trq_adder`, dead member removed), C23 (down-ramp armed once), prefill offset as `int16_t`, `spc_ramp_speed` and M/R multipliers from settings now used. |
| `src/shifting_algo/shift_crossover.cpp/.h` | C7 (`int` cycle count), D5 (downshift no longer exits overlap2 sub-phase 1 immediately), prefill offset as `int16_t`, shadowed base members removed. |
| `src/shifting_algo/shifting_algo_helpers.cpp` | C6 (`_2_1`). |
| `src/adaptation/shift_adaptation.cpp/.h` | C7 (`int16_t` return), D7 (SPC offset clamped to +/-`prefill_max_pressure_delta`, torque offsets to +/-50 Nm), log text. |
| `src/gearbox.cpp/.h` | C10 (disagree counter no longer cleared when slow/stationary), C11 (main-loop `update_pressures` skipped while shifting or engine stopped; TCC target zeroed on engine stop), C13 (N2 = 0 while moving forward is a fault), C14 (engine rpm expires after 10 missing cycles), C19 (delta timer), C20 (ATF branch restructured, calibration now runs), C21 (reverse bands), C26 (`output_rpm > 0` guard), D1 (2 s post-upshift downshift inhibit), D4 (gain from calibration), D6 (timeout warning), D9 (TCC held for up to 5 invalid speed cycles, `tcc->reset()` on real bypass), D11 (band midpoint caps). |
| `src/torque_converter.cpp/.h` | C8 (Open request check), C9 (cold multiplier applied to output only), C16 (delete + nullptr), D2 (10 rpm hysteresis), `reset()`. |
| `src/models/input_torque.cpp` | C25 (engine 0 returns factor 1.0). |
| `src/models/clutch_speed.cpp` | `get_speed_long_eq` aligned with the inline B2 formula (debug output only). |
| `src/profiles.cpp` | C16 (delete + nullptr), C22 (downshift null check). |
| `src/pressure_manager.cpp/.h` | C16, coefficient/friction/p_multi divide-by-zero guards, float-to-int range clamps, D14 (flush logic uses the un-clamped previous output). |
| `src/egs_calibration/calibration.cpp` | C24 (validates the new block on reload; rejects zero `p_multi`/`shift_spc_gain`, warns on zero inertia/drag/TCC multiplier). |
| `src/sensors.cpp` | `t == 0` guard, ATF resistance plausibility bound (the smoothed sensor then holds its last value instead of reporting 175 C). |
| `src/tcu_io/tcu_io.cpp` | C27 (coolant substitute validated; invalid until first frame). |
| `src/solenoids/pwm_solenoid.cpp` | C1 (`int` local for `adc_cali_raw_to_voltage`). |
| `src/solenoids/inrush_solenoid.cpp` | C15 (`hold_time - total`, guarded). |
| `src/solenoids/cc_solenoid.cpp` | D12 (feed-forward from measured battery voltage; resistance guard). |
| `src/solenoids/solenoids.cpp` | C28 (`CHANNEL_ID_MAP[16]`, masked index), D13 (temperature factor formula). |
| `src/canbus/can_egs52.cpp`, `can_egs53.cpp` | C12 (13-bit SNV marker `0x1FFF`). |
| `lib/core/lookupmap.h`, `lookuptable.h`, `lookupheader.h`, `src/stored_data.h` | Virtual destructors so maps/tables/headers can be deleted through base pointers (the original `delete[]` masked this). |

### Behaviour changes that need road validation

- D1: automatic downshifts are inhibited for 2 s after an automatic upshift unless kickdown, brake, a pedal increase of more than 10%, or a range restriction applies.
- D2: TCC state changes now need the slip target to cross the threshold by 10 rpm.
- D5: crossover (coast) downshifts now run the overlap2 sync ramp instead of stepping straight to target pressure.
- D9: a speed-sensor dropout shorter than 5 cycles no longer opens the converter.
- D12: constant-current solenoid feed-forward scales with battery voltage, so the PID trim settles at a different value than before.
- C4/D7: the SPC adaptation offset is now bounded by `prefill_max_pressure_delta` (default 200 mBar) instead of roughly 2 bar; existing adapted values above that are clamped on the next adaptation write.
- C13: with a dead N2 sensor the speeds are flagged invalid rather than reading 0; in 5th this means no automatic 5-4 and, after 5 cycles, an open converter.

### Left unchanged (needs the author's intent or calibration knowledge)

- D3 TCC micro-slip adaptation dead-band.
- D4 garage-shift fill magnitude (only the hard-coded gain was replaced); `s_algo.cpp` 2-3 release factor 1.993 also left as is.
- D15 Standard/Winter upshift rules.
- D16 `max_torque_on/off_clutch` circuit indexing.
- D17 flare detection on the 1-2/4-5 circuit.
- Shift map retuning for the negative-hysteresis cells in section 3 (the code inhibit only masks the symptom).
- PID anti-windup in `calc_correction_trq`.

## 7. Second-pass review (2026-09-07)

A second independent pass was run after the fixes: one reviewer adversarially checked every hunk of the diff for regressions, another re-read the patched code looking for issues the first pass missed. The `unified` build passes after the resulting changes.

### 7.1 Regressions found in the first-pass fixes (all fixed)

| # | Issue | Fix |
|---|---|---|
| R1 | `TorqueConverter::reset()` cleared `is_shifting`, so a speed-sensor dropout mid-shift could let the converter re-apply while the shift algorithm was still in overlap. | `reset()` no longer touches `is_shifting`; the gearbox does not call it while `shifting`. |
| R2 | `gear_disagree_count` (no longer cleared when slow) could carry a stale 1..49 through a stop and delay the first shift after pull-away. | Counter is zeroed when a shift completes successfully and after a garage shift. |
| R3 | Release-shift emergency torque limit dropped to zero the cycle it de-asserted and could chatter. | The ramp value is kept in sync while the emergency is active. |
| R4 | Post-upshift downshift inhibit was armed by failed and by paddle upshifts. | Armed only by a completed automatic upshift. |
| R5 | `TorqueConverter::is_shifting` stuck true when a shift ended abnormally (emergency timer, selector moved), leaving TCC control and adaptation in shift mode until the next clean shift. | `shift_end()` is always called at the end of `elapse_shift`. |

Behaviour changes from the first pass that the reviewer flagged as needing road validation, in addition to the section 6 list: engine-RPM CAN loss now enters solenoid-off limp mode after about 1.2 s instead of holding the last RPM forever; the release-shift SPC ramp is 12 and 16 mBar per cycle in Manual and Race (settings that were previously ignored); calibration blocks with a zero `p_multi` or `shift_spc_gain` entry are now rejected at boot, which should be checked against real EGS52/53 calibration dumps.

### 7.2 New findings (second pass)

| # | Location | Issue | Confidence | Status |
|---|---|---|---|---|
| N1 | `src/inputcomponents/kickdownswitch.cpp:10` | Kickdown "newly pressed" fired on release as well as press; lifting off after a kickdown requested another downshift. | confirmed | fixed (rising edge only) |
| N2 | `src/canbus/can_egs53.cpp` (14 sites) | Signal expiry multiplied by 1000 (one by 10000); EGS52 and the generated getters use ms. Engine RPM, pedal, wheel speeds and shifter position stayed valid for about 1000 s after CAN loss, defeating C14. | confirmed | fixed |
| N3 | `src/canbus/can_hfm.cpp:181` | HFM pedal scaled 0-100 while every consumer expects 0-250; full throttle read as 40%. | confirmed | fixed |
| N4 | `src/canbus/can_custom.cpp:103` | Coolant temperature decoded from the pedal byte. | confirmed | fixed |
| N5 | `src/canbus/can_egs51.cpp:121-127` | Torque freeze result overwritten unconditionally (same pattern as C2). | confirmed | fixed |
| N6 | `src/canbus/can_egs53.cpp:141,175` | Pedal timeout returned 0 instead of the SNV marker; torque clamp compared `int16_t` against `INT_MAX` and had no minimum floor. Gearbox pedal fallback applied to the smoothed value only. | confirmed | fixed (SNV marker, `INT16_MAX`, min floor, substitute applied to both values) |
| N7 | `src/shifting_algo/shift_release.cpp:130-170` | Coast release upshift: negative indicated torque made the torque-reduction request negative, which wrapped through `uint16_t` and was sent on CAN as a huge value. | likely | fixed (clamped to >= 0 at source and output) |
| N8 | `src/shifting_algo/s_algo.cpp:354`, `shifting_algo_helpers.cpp` | Integer divide by shift inertia could be zero on a bad calibration; `short` intermediates in the pressure helpers. | questionable | fixed (guards, `int`) |
| N9 | `src/gearbox.cpp:20-44` | `calc_input_rpm_from_req_gear` ignored reverse ratios, so the reverse garage-shift completion test used output rpm unscaled. | questionable | fixed (reverse ratios added) |
| N10 | `src/gearbox.cpp:1182` | Paddle upshift ignored the TRRS range restriction, causing an upshift immediately followed by a forced downshift. | confirmed | fixed |
| N11 | `src/driver_dynamics/dynamics.cpp` | `DeltaTracker` never stored the previous sample, so it filtered the value rather than its rate; `samples` ignored. | confirmed | fixed |
| N12 | `lib/core/lookupmap.cpp`, `pressure_manager.cpp:28-66` | `LookupByteMap` wrote through unchecked allocations and never set `z_size`; byte-map pointers not nulled after delete. | confirmed (allocation failure only) | fixed |
| N13 | `src/canbus/can_egs52.cpp:800` | Wheel-torque factor encoded as `ratio * 0.05`, which is always 0 for the 11-bit field. The correct scale is not documented in the DBC header. | likely | not changed; needs the FMRAD scale from MB documentation |
| N14 | `src/nvs/module_settings.h` | Several documented shift settings are never read (`adder_spc_*`, `sync_trq_adder_speed`, `overlap_multi_shift_speed`, `trq_req_multi_*`, `adder_trq_multi_*`, `ADP.min_input_rpm`); `spc_p_offset` is never written. | confirmed | not changed; semantics unknown |
| N15 | `src/gearbox.cpp` garage shift | Completion test is direction-blind (a rolling N->D passes as soon as the turbine is below the target) and the fill ramp is unbounded across the timeout; aborts re-spawn immediately. | design | not changed |
| N16 | `src/gearbox.cpp:1041` | Gear selection is gated on the ATF/parking-lock ADC read succeeding; a persistent ADC2 failure freezes shifter handling. | design | not changed |
| N17 | `src/tcu_io/tcu_io.cpp:285` | ATF and battery getters never return their SNV markers, so the callers' validity checks are dead and an invalid ATF sensor reports the held value. | design | not changed; substitution appears intentional |
| N18 | `src/gearbox.cpp:1262` | Solenoid resistance temperature calibration is computed but never consumed, and runs on the first loop iteration before the ATF filter has settled. | confirmed | not changed; result unused |
| N19 | `src/main.cpp:317,322`, `solenoids.cpp:249` | Small task stacks (1024 and 2048 bytes) for tasks calling driver code and float math; paddle input polled at priority 1. | questionable | not changed; recommend a stack high-water check |
| N20 | `src/gearbox.cpp:512,537` | Shift timing is cycle-based; an overrun of the 20 ms budget stretches all shift timers. | design | not changed |

### 7.3 Confirmed correct by the second pass

Reverse bands, band midpoint caps, output-rpm guard, delta timer, ATF restructure, the `update_pressures` gating (every shift-thread path drives the solenoids each cycle), the N2 plausibility check in every forward gear, the bleed ramp (SPC_MAX to target in equal steps, same first-cycle value as before), the adaptation stage machine (stage 5 terminal), the overlap2 downshift exit, the TCC hysteresis transitions (none sticky or unreachable), the battery-scaled current feed-forward, the MPC flush cycle (starts and stops), the calibration reload free path, the tcu_io template ordering, the virtual destructors (all objects heap-allocated and held by pointer), and the 13-bit CAN sentinels.
