# September 9 drive review: kickdown, shift execution, and EGS51 comparison

The latest drive has three distinct problems: kickdown demand is not reliably preserved by the scheduler; several low-speed 3→2 shifts release too slowly under changing pedal; and two 2→3 upshifts show a large negative PID correction, falling applying pressure, and renewed slip. A further torque-unit/engine-response problem is strongly suggested by a 2→1 torque undershoot. Changing the shift maps alone will not fix these execution faults.

This is a review and implementation recommendation, not a firmware/calibration change. Existing staged and unstaged work was left intact. No flash, map write, or live vehicle connection was performed.

## Data and reconstruction

- Latest: `logger/logs/nag52_20260909_175106.jsonl`, 964 seconds, firmware `8152244-dirty`, compiled September 9 at 17:49:37. SHA-256 is recorded in the accompanying summary JSON.
- Comparisons: September 9 at 06:51 (`d488336-dirty`, 910 seconds) and 05:10 (same firmware identifier, 706 seconds). Different drives and temperatures: these are descriptive comparisons, not controlled A/B experiments. A dirty build identifier does not uniquely specify its sources.
- All three calibration snapshots are identical, with valid CRCs. The latest snapshot has ratios 3.932/2.408/1.486/1.000/0.830, 4500 rpm diesel redline, 3.070 final drive, 1975 mm wheel circumference, and configured engine drag 54 Nm. Configured drag is not a substitute for the live CAN drag value.
- Pressure fields are calculated/commanded pressures, not hydraulic transducer measurements. Engine torque is the CAN-reported estimate; it is not a shaft torque measurement.
- Latest polling is 18.5 Hz; trace median interval is **19 ms**, approximately 52.6 Hz. The accelerometer is only **3.33 Hz**, unsuitable for evaluating shift shock. Individual diagnostic fields within a polling cycle are not simultaneous.
- There are **82 forward shifts and six garage engagement attempts** in the recorded sample windows. Four garage engagements complete; two reverse attempts cancel during selector transit toward Park. The trace contains 86 event headers because two headers each combine two shifts. The text log has 81 forward request lines: the 3→2 at 159.338 s is present in the trace but its request line is missing. Polled gear transitions alone report 78 shifts.
- Reconstruction deduplicates samples by sequence number and splits active shifts when their sample-level actual/target gear identities change. It excludes the pre/post context from shift duration. This recovers 5→4 plus 4→3 at 282.968/284.090 s and 3→2 plus 2→1 at 835.918/837.421 s.
- Times below are **TCU sample seconds since boot**, not trace download time. Request/completion log clocks and sampling boundaries differ by several tens of milliseconds. The ledger's response is the first of three successive samples exceeding 10% of nominal ratio travel; it is unavailable when output speed is too low. It is not interchangeable with the firmware's single-crossing response metric.

Every shift has a row, measurements, and a review recommendation in the [latest-drive ledger](nag52_20260909_175106.ledger.md). Its [CSV](nag52_20260909_175106.csv) also records phase durations, longest substate, request range, engine speed, and source trace-event IDs. Equivalent ledgers and CSVs accompany both earlier drives.

## Shift-family results

Durations include bleed, filling, synchronization, and handover. They must not be compared directly with the stamped target overlap time.

| Shift | Latest count | Median duration ms | Maximum ms | Median response ms | 06:51 median duration ms | Interpretation / improvement |
|---|---:|---:|---:|---:|---:|---|
| 1→2 | 8 | 1188 | 1659 | 409 | 1161 | Usually consistent. The immediate reversal after the 162.916 s 2→1 deserves scheduler/circuit-turnaround attention. |
| 2→3 | 10 | 1264 | 2840 | 542 | 1277 | Two clear synchronization-control failures; repair PID/pressure recovery before reducing target time. |
| 3→4 | 12 | 1466 | 1653 | 741 | 1436 | Consistent late response. Review fill and initial overlap, plus loaded landing rpm; existing energy numbers cannot justify adding pressure. |
| 4→5 | 10 | 1093 | 1178 | 428 | 1045 | Relatively consistent. Review premature upshift after short lifts as a scheduling issue. |
| 5→4 | 10 | 971 | 1197 | 373 | 937 | Individual shifts are reasonably consistent; the complete 5→3 ladder still takes about 2.4 seconds. |
| 4→3 | 12 | 1008 | 1256 | 457 | 990 | Loaded shifts take roughly 1.2 seconds; evaluate them as part of the demanded ladder. |
| 3→2 | 10 | 1685 | 2727 | 657 | 1544 | Main low-speed downshift weakness; three exceed 2.5 seconds. Changing torque during fill/release is the critical case. |
| 2→1 | 10 | 1189 | 1542 | 361 | 1106 | Review net-torque undershoot and useful gear residence; avoid selecting first only to leave it immediately. |

The 05:10 drive already has a 2573 ms 3→2; the 06:51 drive has a 2800 ms 3→2. The problem predates the latest drive. Neither earlier drive has a 2→3 longer than 1.5 seconds in the reconstructed samples, whereas the latest has two around 2.8 seconds. This is an observed difference, not proof that the latest build caused it.

## Detailed findings and proposed changes

### 1. Preserve kickdown demand and fix decision priority

**Confirmed source defect; individual lost switch presses cannot be counted from these logs.**

[`kickdownswitch.cpp`](../../src/inputcomponents/kickdownswitch.cpp:7) returns only `current_state && !last_state`. [`gearbox.cpp`](../../src/gearbox.cpp:1758) consumes that edge every controller iteration. Gear decisions are behind `!shifting && actual_gear == target_gear && gear_disagree_count == 0` around line 1935. There is no pending kickdown request. A press during a shift or ratio disagreement disappears before that gate reopens. Holding the switch does not keep `kickdown_pressed` true.

The upshift branch also precedes the kickdown/downshift branch ([line 1990](../../src/gearbox.cpp:1990)). An ordinary map upshift can win during the only cycle carrying the kickdown edge. The safety/redline upshift and an ordinary economy upshift should have distinct priority.

The latest trace stamps contain **no kickdown flags**. That does not prove the physical switch was never pressed: the stamp is taken later, and the signal is already edge-only. The CAN polling record does not contain raw kickdown state. EGS51 reads KD only from EWM_230 ([can_egs51.cpp:88](../../src/canbus/can_egs51.cpp:88)); some board variants have the physical input configured `PCA_NUM_NC`. Verify the actual input path as well as fixing scheduling.

Proposed behavior:

1. Keep separate raw/valid held state, press edge, and pending demand. Specify expiry/cancellation for stale CAN, pedal release, selector change, and completion.
2. Compute a useful final target under kickdown using predicted lower-gear turbine speed, engine-speed margin, power band and hysteresis. Execute adjacent shifts serially; a held switch alone must not cause repeated downshifts to first.
3. Give valid kickdown precedence over ordinary schedule upshifts, while preserving overspeed protection.
4. Carry demand through an in-flight shift and stamp raw KD, pending demand, chosen final gear, selection reason, and any veto.
5. Test a press during fill, overlap, ratio disagreement and an ordinary upshift decision; test a held request through a ladder and a release/stale input that cancels it.

### 2. Improve the entire downshift ladder, including the return upshift

Three loaded 5→3 sequences are visible:

| Start | Individual shifts | Total to third | Useful observation |
|---|---|---:|---|
| 118.653 s | 5→4 1122 ms; 4→3 1237 ms | 2511 ms including the gap | Fourth finishes around 1951 turbine rpm; third around 2952. |
| 282.968 s | 5→4 1122 ms; 4→3 1256 ms | 2378 ms | One trace header wrongly labels the whole ladder 5→4. Third finishes around 3358 rpm. |
| 300.386 s | 5→4 1179 ms; 4→3 1218 ms | 2416 ms including the gap | Third finishes around 3322 rpm; an upshift starts only about 0.40 s later. |

The map eventually requests another downshift because pedal/rpm justify it; that is not evidence that kickdown demand is retained. At 303.201 s pedal falls from 78.4% to 5.6% during the ensuing 3→4, followed almost immediately by 4→5. A short-lift hold could preserve the overtaking gear; distinguish a brief release from sustained coast, with a bounded exit policy.

At 162.916 s, 2→1 takes 1425 ms, ending at 4093 turbine rpm. The next 1→2 starts at 164.360 s—only **19 ms** after completion—and spends about 608 ms in its phase-0 trace window. This is an unproductive reversal: the car pays for another full shift with essentially no residence in first. Reevaluate the target using expected speed at completion, acceleration, and the lower gear's imminent upshift threshold. The current downshift guard checks only instantaneous `output_rpm × lower_ratio < redline − 500` ([gearbox.cpp:2023](../../src/gearbox.cpp:2023)).

At 95.401 s, 3→4 ends at only 2153 turbine rpm while pedal remains 74%. At 167.292 s, 2→3 ends around 1983 rpm while pedal has risen to 79.6%. These are concrete below-boost landings. Coordinate upshift and downshift thresholds and account for demand changing during a shift. The target band is the owner's documented 2400 rpm boost / 2000 economy / 4500 redline; do not blindly raise every part-throttle shift point.

The logger snapshot lacks live shift-point maps and complete module settings. Boot messages say NVS maps were loaded; they do not prove the cell values. `shift_envelope.py` checks source defaults, not those maps. Download RAM/NVS maps and settings, evaluate the actual schedule, then version changed NVS keys or explicitly write the reviewed maps. Do not claim a default-map edit reaches the car.

### 3. Repair slow 3→2 release control under tip-in

Rows 22, 58 and 82 of the latest ledger:

| Start | Duration | Pedal start→end | Phase 1 residence | Mechanism visible in data |
|---|---:|---:|---:|---|
| 159.338 s | 2666 ms | 24.4→76.4% | about 1.92 s | Releasing MPC substate 3 persists while input torque rises; then substate 4 takes time to accelerate turbine. |
| 536.025 s | 2663 ms | 0→27.2% | about 1.92 s | Coast-to-power transition while the release sequence is already running. |
| 921.018 s | 2727 ms | 24→40% | about 1.96 s | Similar delayed release; response to stable 10% ratio movement is 1202 ms. |

At 159.338 s, turbine speed is 923 rpm. Around 160.29 s it is still only 997 rpm despite substantially increased pedal. Applying pressure rises slowly from roughly 1205 to 1789 mbar during the wait; MPC grows with increased input torque before release progresses. At 921 s the same pattern repeats.

[`phase_fill_release_mpc`](../../src/shifting_algo/shift_release.cpp:281) uses `abs_input_trq − freeing_trq − loss_torque` to size releasing-clutch pressure. In substate 3, `loss_torque` grows slowly while live input torque can grow much faster. SPC substate 5 adds a fixed amount per control step ([line 249](../../src/shifting_algo/shift_release.cpp:249)). These can leave the old clutch carrying increased torque while the new circuit is barely ramping. This is a release/torque-coordination problem, not simply a long fill-time map.

Proposed change: use bounded release feedback tied to actual off-clutch departure and target turbine acceleration; make the coast→power transition explicit and update the release trajectory without restarting hydraulic fill. Coordinate MPC reduction, SPC rise and available engine torque. Express rates using measured elapsed time. Log release torque, loss torque, clutch capacity, flags and target-speed error. Establish a phase-progress fault distinct from total duration. Do not merely shorten a timeout or force pressure handover while unsynchronized.

There is already turbine PID feedback; the needed work is to correct its trajectory, limits and transitions, not to add a second generic PID. The current emergency timer can force the next phase ([s_algo.cpp:129](../../src/shifting_algo/s_algo.cpp:129)); there is no emergency-timer message in this drive, so these long shifts were not observed timeout-forced completions.

### 4. Repair 2→3 PID pressure collapse and renewed slip

**Strongest directly observed execution defect.** Rows 11 and 35 last 2840/2825 ms. Crossover phase 3, substate 2 (“waiting for sync”), accounts for about 1.73/1.69 seconds.

First event:

- Around 84.33 s: turbine 2514 rpm, target 3021 rpm, PID correction −124 Nm, applying pressure 2587 mbar.
- Around 84.55 s: turbine 2244, target 2898, PID −251 Nm, pressure 1536 mbar, applying slip about 153 rpm.
- Around 84.77 s: PID −304 Nm, pressure 1535 mbar; engine torque has recovered to 270 Nm.
- Turbine speed then climbs again, and applying slip increases to about 574 rpm around 85.41 s before pressure recovers.

Second event reproduces this: near 262.58 s the PID is −328 Nm with pressure 1536 mbar; the clutch approaches sync and then loses progress as engine torque returns. It is not flagged as flare by the stamp, showing that the current flare flag misses this kind of loss of synchronization.

[`calc_correction_trq`](../../src/shifting_algo/s_algo.cpp:397) integrates speed error regardless of actuator saturation, with only a numerical integer clamp. The reference trajectory continues independently of actual clutch synchronization. [`phase_overlap2`](../../src/shifting_algo/shift_crossover.cpp:409) adds this correction to input torque, clips at zero, and only floors pressure at overlap-begin pressure. That floor can be close to fill pressure and cannot guarantee holding restored engine torque. The logged signs and pressure response match this mechanism.

Proposed change: implement actuator-aware anti-windup, bound the speed reference against the moving synchronous-speed target, handle a turbine trajectory that runs ahead of the reference, and make torque restoration conditional on adequate clutch capacity/synchronization. Limit pressure removal after meaningful synchronization progress while still allowing necessary modulation. Exercise these exact two events with host replay and synthetic closed-loop cases. A replay that changes commands under fixed logged RPM cannot prove the physical shift will improve.

Do not reduce the final SPC_MAX handover ramp. The failure happens before that ramp, while the applying circuit is still controllable.

### 5. Audit EGS51 request torque units and low-speed intervention

At 538.707 s the 2→1 request remains finite: it does not reproduce the older 284→2 Nm runaway. Near 539.45 s, a roughly 72 Nm request accompanies measured net engine torque around 24 Nm. The request ends, but net torque reaches **−18 Nm** around 539.65 s while pedal remains near 28%; engine rpm falls from about 1466 to 1215 before recovering.

This confirms a net-torque undershoot during a demanded shift. It does **not** directly prove zero fuel injection; the preflight wording “fuel cut” is stronger than the available signal.

Receive handling subtracts live drag from gross indicated/min/max torques ([can_egs51.cpp:140](../../src/canbus/can_egs51.cpp:140)). Transmit writes `TORQUE_REQ = amount_nm / 3` without an explicit inverse conversion ([line 431](../../src/canbus/can_egs51.cpp:431)). If GS218's request is gross torque, the engine receives a limit lower than intended by approximately its drag torque. The observed request/response gap makes this a high-priority hypothesis. The configured constant 54 Nm must not be silently substituted for the live signal.

The local ROM confirms that bank0 `0xD215..0xD238` writes `0xFE` when inactive and divides the internal word at XRAM `0x2F7:0x2F8` by three when enabled. That verifies wire scale and sentinel, **not the internal word's gross/net convention**. Its upstream producer still needs tracing; no OEM torque-strategy parity is claimed.

Proposed change after verification: explicitly name net/gross quantities at the CAN boundary, convert exactly once, clamp valid wire values away from reserved codes, and handle missing/stale drag. Trace the ROM word producer or capture raw MS310/GS218 and compare commanded gross torque to net+drag. Also account for the controller's previous-step request send ([gearbox.cpp:948](../../src/gearbox.cpp:948)) and engine response lag when timing low-speed reduction/recovery. Keep the existing non-collapsing reference protection.

## EGS51 parity: verified matches, actual gaps, and stale documentation

I read `CLAUDE.md`, the GitHub diagram instructions, the physical transmission notes, the docs primer/parity guide, algorithm research notes, the EGS51 README including its superseding corrections, reconstructed pressure/engagement C, and the relevant NAG52 paths. No new Ghidra import was needed.

`python3 tmp/egs51/tools/egs51tool.py verify` reports **25 fields checked, zero mismatches** against the saved host calibration header. The three drives' own calibration snapshots are identical. The OEM comparison is therefore useful, but matching mechanical/hydraulic values does not prove matching shift control.

| Area | Evidence / current NAG52 behavior | Recommended action |
|---|---|---|
| Circuit assignment and overlap pressure structure | Matches the reconstructed OEM arrangement. NAG52 already has bleed/fill, pressure matching, current regulation and turbine feedback. | Keep this structure; fix the identified control transitions. |
| OEM calibration coding | Mech/hydr matches are established. Shift-algorithm/TCC values differ; remaining coding nibbles and map meanings are not all known. | Identify selected variant, axes, units and call sites before transferring maps. Geometry or a similar part-name string is insufficient. |
| P/N neutral pair | Corrected OEM reconstruction holds Y5+Y4 at low pressure, releases both before engagement. NAG52's optional Y4-only hold differs. | A separate parity experiment may be useful; it does not explain the in-motion kickdown failures. Implement the entire low-pressure exit sequence, not just two solenoid booleans. |
| Garage fill timing | OEM reconstruction contains a temperature-dependent time schedule, despite the older CLAUDE/README claim that none was found. OEM task period is still unknown. | Correct the stale documentation; do not equate OEM scheduler cycles with NAG52's 20 ms nominal cycle. |
| Temperature encoding | EGS51 notes suggest °C+50. **The active NAG52 MPC/SPC current path already uses `atf_temp + 50`** (pressure_manager.cpp:246/252), and the flush gate does too (line 558). | The README's claim that live PCS lookup lacks +50 is stale. Do not add it again or rebase axes and retain the addition. The unused `get_p_solenoid_current` helper at line 673 lacks +50; unify/remove it to avoid future inconsistency. |
| Current regulator | OEM reconstruction shows measured-current PI with saturation. Its gains are in different hardware/time units. | Compare dimensionally; do not copy raw OEM PI gains to ESP32. |
| Shift execution and adaptation parity | Full OEM shift phase machine and torque-request producer remain undecoded in the local notes. | Remove unsupported claims such as “EGS has no anti-windup” from reasoning unless tied to decoded code. Decode bounded functions when needed; label hypotheses explicitly. |

The existing newer working-copy edits to `shift_trace.cpp/.h` partly address the slip-energy model. Their presence was preserved; the dirty firmware identifier cannot establish exactly which edits were in the driven binary.

## Repair the checks before using them to accept a calibration

The unmodified preflight was run on all three drives and exits 1 on each. Outputs are saved alongside this report. For the latest it reports 20 errors; these are **not 20 confirmed control defects**:

- Two `garage_sync` errors are false positives: the checker assumes the historical 20 rpm completion gate. The current code uses the same 90/350 threshold for completion; the log says these engagements completed OK.
- Two garage aborts are selector cancellations, with no retry suffix or subsequent repeated engagement. One occurs after 143 ms, the other 357 ms, while moving toward Park. Distinguish cancellation, retry, hydraulic timeout and synchronization failure. An abort alone cannot establish a slam.
- The 2554 ms “3→2” at trace download time 839.1 s is a merged 1503 ms 3→2 plus 1051 ms 2→1. It is not a single overlong shift. The actual over-2500 ms forward shifts are the two 2→3 and three 3→2 identified above.
- The high 3→4 slip-energy values are model estimates. Full input torque times clutch free speed during low-fill/partial capacity inflates them. The current worktree's capacity-capped model is a partial correction; first verify mechanical torque units and map scaling and ensure offline/firmware use identical definitions. Do not use the old 40–75 kJ figures as measured heat.
- Offline jerk uses a one-sample second derivative and quantization dominates. Firmware uses a wider baseline; that deliberate difference causes much of the reported drift. Neither the 3.33 Hz accelerometer nor these mismatched metrics establishes cabin shock amplitude.
- Both algorithms use different phase numbers: crossover 0/1/2/3/4/5 = bleed/fill/overlap/overlap2/max/end; releasing 0/1/2/3/4 = bleed/fill-release/overlap/max/end. Garage `phase` is its substage. Record algorithm and garage stage explicitly.
- `ShiftTrace::sample` opens/closes events only on a sampled `shifting` edge. The 1–3 ms gaps between consecutive shifts can be missed by a 19 ms sampler. Add an explicit monotonically increasing shift ID and lifecycle boundaries from the shift executor; associate stamp, completion and adaptation by that ID. Merely relabeling a combined event leaves quality and learner attribution wrong.

## Recommended implementation order and acceptance evidence

1. **Make event identity, KD state, algorithm selection, torque units, active map/settings snapshot and cancellation reasons observable.** Replay this log: recover 82 forward shifts; the two merged pairs must remain four separate events. Both successful garages must pass the gate; selector cancellations must not be called retries.
2. **Fix KD demand persistence and decision priority.** Test held/edge/stale input, a press during a shift, ordinary-upshift conflict, overspeed veto, and cancellation. Validate a demanded 5→3 ladder without forcing a direct unsupported clutch skip.
3. **Verify/correct the EGS51 torque boundary and intervention timing.** Unit-test scale/sentinel/saturation and net↔gross handling using confirmed semantics. Reproduce the 539 s undershoot; demonstrate the revised request has the intended net meaning without merely disabling protection.
4. **Repair 2→3 PID recovery and 3→2 coast-to-power release.** Host replay checks commanded pressure/torque and state progression. Add meaningful synthetic dynamics tests for saturation and changing input torque, then one attributable road-test change at a time. Provisional desk gates: no renewed slip after near-sync, no demand-associated net-torque collapse, no single shift exceeding 2500 ms, and no unexplained phase stall.
5. **Tune the loaded schedule and short-lift behavior against downloaded maps.** Evaluate time in useful gear and expected landing rpm across the whole ladder, not only individual shifts. Run envelope checks before/after defaults and verify the actual NVS/RAM result.
6. **Treat OEM P/N parity and fill-map replacement as separate experiments.** Do not mix them into the first kickdown test. Keep adaptation attribution explicit; the newer quality learner is disabled in these stamps, while the original algorithm adaptation is enabled.

The ledger deliberately retains consistent shifts as comparisons instead of assigning every shift an invented pressure change. The most useful next change is a measured control correction with a clear mechanism, not a wholesale OEM-map transplant.

## Reproduction

```sh
python3 tmp/drive_review_20260909/analyze.py \
  logger/logs/nag52_20260909_175106.jsonl \
  logger/logs/nag52_20260909_065118.jsonl \
  logger/logs/nag52_20260909_051027.jsonl \
  --out tmp/drive_review_20260909
python3 scripts/preflight.py logger/logs/nag52_20260909_175106.jsonl
python3 tmp/egs51/tools/egs51tool.py verify
```

Preflight is expected to fail on this historical log; its output needs the distinctions above. No firmware was changed, so a firmware build or claimed post-fix road validation would not establish anything about these recommendations.
