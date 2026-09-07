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

## 8. What the drive log shows (logger/logs/nag52_20260907_054611.jsonl)

12-minute log from the car (EGS51 CAN layer, profile S), firmware build `2409592` dated 16 Aug 2026 on ESP-IDF 5.5.0. That build predates this repository's HEAD and its commit is not in this repository, so code-to-log correspondence is approximate. None of the fixes in this report were on the car.

| Observation | Evidence | Relevance |
|---|---|---|
| **Two boot panics before a successful boot.** `Guru Meditation Error: Core 0 panic'ed (Cache error). Cache disabled but cached memory region accessed`, PC 0x400e47c8, right after the EEPROM map loads, twice in a row, then a clean third boot. | log lines at t=0.14 s and 0.34 s | New, not in the review. Signature is an IRAM-flagged interrupt handler calling flash-resident code during a flash write. Running ISRs at that moment: the TCC inrush gptimer callback (old path calls `ledc_set_duty`, which is not in IRAM unless `CONFIG_LEDC_CTRL_FUNC_IN_IRAM`), the ADC continuous ISR, and TWAI. Resolve with `xtensa-esp32-elf-addr2line -e <that build's .elf> 0x400e47c5 0x4008909e 0x400855f1`. The repo's sdkconfig leaves `CONFIG_GPTIMER_ISR_IRAM_SAFE` off, which masks the timer ISR during flash writes instead; if the car build had it on, the LEDC call from the ISR is the likely culprit. |
| **Static (converted) engine torque is negative on every cycle and identical to min torque** (-84 to 0 Nm, mean -54). Driver torque is 0 to 225 Nm. | `can.static_torque == can.min_torque` in 13532/13532 cycles | With the current EGS51 decode (uint8 x3) static torque cannot be negative, so the car build decodes MS_310 differently or the field is not what the code assumes. `converted_torque` selects release vs crossover shifting, gates TCC adaptation, and sets TCC load. Re-log with the current build and check MS_310. |
| **Converter never reached its Closed state.** Target was Closed for 2398 cycles, current state stayed Open; slip about 90 rpm at 1990 rpm while "closed"; 33 Closed/Slipping target flips. ATF was below 60 C for the whole drive (20 C rising to 56 C, 84 C only after stopping). | `tcc` record | Confirms C9 in the field: below 60 C the state machine cannot settle, so the ECU is told the clutch is in transition and the lock map never adapts. Also confirms D2 (target toggling) and that the lock map is under-pressured for this box. |
| **Adaptation ran on none of the 38 shifts.** | `Start adaptation flags: 0 0 0` every shift | Expected: `min_atf_temp` is 60 C and the box never got there while driving. Not a bug, but it means none of the adaptation paths has ever run on this car. |
| **ATF reported -40 C for the first 6 s** (parking lock engaged, coolant frame not yet received). | `sensors.atf_temp` t=1.1 to 6.8 s | Consistent with C27 (substitute value before the first coolant frame); the EGS51 coolant decode returns -40 for a zero raw byte, so an SNV check on that byte is also needed. |
| **Battery reads 2.1 to 2.5 V for the first 1.5 s.** | `sensors.v_batt` | Filter start-up from the ADC before the divider settles; the solenoid feed-forward (D12) now uses this value, so the `> 9 V` gate matters and holds. |
| **Garage shifts N to D and P to R completed in 1020 ms each**, turbine pulled from about 620 to 26 rpm, no abort. | log lines at 26 s, 56 s, 647 s | The current garage-shift fill (D4, magnitude unchanged) works on this car. No reason to alter it. |
| **No up/down hunting.** Seven reversals within 8 s, every one explained by a pedal change (lift-off to 0% or a kickdown-style increase). | shift request lines with pedal/rpm context | D1 did not occur on this drive (diesel Standard maps, mostly 30 to 60% pedal). The inhibit stays as a safeguard. |
| No N2/N3 disagreement in gears 2 to 4, no zero-turbine-while-moving cycles, no reboots after boot, CPU load 0.4% / 0.2% at idle, 100 KB internal RAM free. | | Sensor path healthy on this car. |
| Pedal peaked at 124 of 250. | `can.pedal_pos` | Either the driver never exceeded half throttle or MS_210 PW is not 0-250 on this vehicle; worth a full-throttle check in the next log. |

What the log cannot answer: the FMRAD wheel-torque scale (EGS52 only, and the TCU's transmitted frames are not logged), the SPC gain calibration (the on-clutch pressure record is only populated during a shift and the logged build's conversion is unknown), and the on/off torque-limit indexing.

Recommended next log: flash the current build, drive until ATF exceeds 60 C so adaptation and TCC lock run, include one full-throttle pull, and capture the boot with `--reset` to see whether the cache-error panic persists.

## 9. Flashing the TCU (2026-09-07)

The `unified` build (commit 5813b7b plus the sdkconfig change below) was flashed over `/dev/ttyUSB0` with PlatformIO (`pio run -e unified -t upload`) and the boot captured with the logger (`nag52log.py --reset`).

**First attempt: boot loop.** Every boot panicked on core 1 with `Cache disabled but cached memory region accessed` inside ESP-IDF's `do_system_init_fn` (startup.c:123), before `app_main`. Cause: in IDF 5.3.0 the core-0 secondary init stage runs concurrently with core 1's init loop, which executes from flash. The core-dump init on core 0 (`init_coredump`, priority 130) reads flash (the boot-time image check and the lazy partition-table load behind `esp_partition_find_first`). Before the scheduler starts, `spi_flash_disable_interrupts_caches_and_other_cpu` assumes core 1 is parked in IRAM and disables both caches, so core 1 faults. The car's earlier build on IDF 5.5.0 did not show this particular race (its boot panics were a different signature, on core 0).

**Fix (sdkconfig.unified):** `CONFIG_ESP_COREDUMP_CHECK_BOOT` off (removed most panics: 4 before a successful boot) and core dumps redirected from flash to UART (`CONFIG_ESP_COREDUMP_ENABLE_TO_FLASH=n`, `CONFIG_ESP_COREDUMP_ENABLE_TO_UART=y`), which removes the remaining flash access from the race window. Result: two consecutive clean boots, no panics, `GEARBOX START` at 0.25 s (was 0.53 s after the retries), calibration plausibility check passed, no warnings or errors, diagnostics polling at ~18 cycles/s. With the engine off and the selector in P the TCU reports 12.4 V, all solenoid currents zero, coolant 82 C.

Side effect worth knowing: a future panic now prints the core dump as a base64 blob on the serial port instead of storing it in the `coredump` partition; the logger records it as log lines.

Observation from the boot: `Calibrated solenoids at -40 C` on the first control-loop iteration. With the parking lock engaged the ATF substitute comes from the EGS51 coolant frame, which decoded to -40 C at that moment; the resistance figure it produces is unused (N18), but the same -40 C feeds the first garage-shift fill lookups for a few seconds (see section 8). The EGS51 coolant decode needs an SNV check on a zero raw byte.

Not yet done: a drive on this build. The road-validation list in sections 6 and 7.1 applies.

## 10. Second drive on the new build (logger/logs/nag52_20260907_082955.jsonl)

5.7 minute drive, build 5813b7b-dirty, profile S (summer position), ATF 62 to 79 C, 37 shifts, no panics or reboots. Reported: rough first engagement, hard shifts, engine over 5000 rpm.

Important context: the previous firmware on this car (build 2409592) was not built from this repository, and it decoded the EGS51 engine torque differently (static torque was always negative and equal to min torque). On this build static torque is valid (0 to 408 Nm). So the shift algorithms, torque requests and adaptation are all exercising paths on this car for the first time; the comparison with the morning log is "old firmware vs this repository", not "before vs after the review fixes".

### 10.1 Over-rev (5154 rpm engine, 5144 rpm input, 1st gear, 170 to 171 s)

Sequence: at 168.2 s a full-throttle kickdown in 2nd at 1723 rpm requested 2-1 (correct per the S diesel map). In 1st at full throttle the input shaft climbed at about 1100 rpm/s. `StandardProfile::should_upshift` takes the map value (4500 rpm at 100% pedal, which already equals the diesel redline) and adds up to +1000 rpm for "time since last shift" (decaying over 5 s) and up to +1000 rpm for engine load, giving a threshold above 6000 rpm. The upshift was only requested at 171.1 s when the driver lifted. No code path enforced the redline on upshifts; the only redline logic (`restrict_target` seek and the downshift guard) does not apply here. This is pre-existing profile logic, not a review change.

Fix applied (built, not yet flashed):
- `StandardProfile::should_upshift` caps the threshold at redline minus 250 rpm, so the request is made before the redline. The pedal-zero and brake inhibits are bypassed above that point.
- `Gearbox::controller_loop` has a profile-independent backstop: if the input rpm plus half of its rate of change (rpm/s from the now-working delta tracker, 0.5 s look-ahead for bleed and fill) reaches the redline, an upshift is forced and a warning logged.

The maps and adders still deserve tuning: an adder of +1000 rpm within 5 s of any shift is very aggressive on a diesel with a 4500 rpm limit.

### 10.2 Rough first engagement (56.2 to 58.3 s)

N to D garage shift started at 56.4 s (prefill 3390 mBar, fill ramp 2200 to 2700 mBar), the turbine was pulled down by 57.1 s and the shift was declared complete at 57.4 s (the fixed 1020 ms minimum). The driver applied throttle from 56.98 s, i.e. while the engagement was still in progress, reaching 87% by 57.5 s. Because the S position starts in 1st, the TCU then executed the stationary 2-1 (B1 apply, K1 release) as a release shift at 87% pedal. At standstill all clutch slip speeds are near zero, so the release algorithm's slip-based exits fire immediately: fill-and-release lasted one cycle and the overlap ramped B1 to full pressure in 0.6 s while the engine rose from 800 to 1500 rpm and the car launched. That is the jolt.

Contributing factors: (1) throttle applied 0.6 s after selecting D, before the garage sequence finished; (2) the 2-1 after a garage shift is run by the normal shift algorithm, which has no stationary handling (`SHIFT_FLAG_STATIONARY` is computed but unused; the `stationary` argument to `step_internal` is ignored). The morning log had the same 2-1 at 50% pedal and it was tolerable. Not changed yet; the right fix is a dedicated stationary 2-1 (timer-based fill, no slip exits) and ideally performing it before releasing torque. Listed as an open item.

### 10.3 Shift harshness

Power upshifts (pedal above 30%): peak engine deceleration during the inertia phase, median 4466 rpm/s (max 7966) versus 3245 rpm/s (max 4504) on the morning log. Output-shaft jumps are similar (median 8 vs 7 rpm per cycle). What the data shows for a typical 1-2 at 80% pedal (62 s): the inertia phase lasted about 0.35 s, which is close to the S-profile target shift time, but the PID saturated at -192 Nm for six cycles because the turbine fell 1280 rpm below its target, and the apply pressure could not be reduced below the overlap-begin floor. The feed-forward apply pressure (torque adder map plus adaptation) is too high for this car, so the clutch grabs faster than the momentum controller wants.

Differences from the morning log that plausibly contribute: valid static torque enables torque requests (active during 12 shifts, small reductions of 20 to 60 Nm, NormalSpeed) and changes the release/crossover selection; solenoid current tracking is now accurate (MPC error 9.6 mA mean vs 79 mA), so actual pressures now match the commanded values the tuning was done without; fill-time adaptation is now running (offsets moved between -7 and +1 cycles) and one SPC pressure adaptation applied -72 mBar. None of the review fixes changes the overlap or overlap2 feed-forward for power upshifts.

Suggested next step: compare the crossover feed-forward against the car's calibration (section 10.4) and consider a slower S-profile target time or a lower torque adder map until adaptation has settled. Adaptation cancelled on most shifts with "Engine torque too high" (limits 40 to 94 Nm vs 66 to 369 Nm input torque), so fill-pressure adaptation only ran once; the applying-torque adaptation is off by default.

### 10.4 Calibration

The logger did not previously record the calibration block, so which blocks the TCU holds could only be inferred (a parallel session matched the morning log to hydraulic STDP, mechanical 51, converter 71, shift maps SM00 from the config app database). The logger now downloads the block at connect via KWP ReadMemoryByAddress (0x800000 maps to the `tcm_shift_store` partition), validates magic, length and checksum, decodes every field of `CalibrationInfo`, and stores it in the `snapshot` line. `nag52log.py info` prints the block names, ratios, SPC gains and pressure multipliers; `nag52log.py calibration <log>` prints the full decode; `--live` reads it from a connected TCU. Zero divisors are flagged. Tests cover the round trip and the fake TCU serves the block.

Firmware updates via `pio run -t upload` write only the bootloader, partition table, OTA data and app; the NVS settings, maps and the calibration partition are preserved (confirmed by the boot log: all settings and maps loaded from NVS, calibration check passed).

### 10.5 Status

Built and ready to flash: redline cap and predictive backstop. Open: stationary 2-1 handling after garage shifts; feed-forward tuning for power upshifts on this car; verification of the calibration block against the config database once the next log is recorded.
