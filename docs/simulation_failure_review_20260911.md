# Simulation failure audit — 2026-09-11

The investigated failures do **not establish a mistranslation of the EGS51 pressure code**. They expose an infeasible initial condition, insufficient modeled clutch capacity, and a host schedule that omits the OEM ratio/fault controller. One stale speed assignment in that host adapter was incorrect and is now removed. Its removal does not change either tested trajectory.

This conclusion is limited to the examined routines and fixtures. Matching individual ROM calls does not validate the complete ECU schedule, physical units, calibration or transmission model.

## Capacity and initial state explain the severe EGS51 run

The plant's old-gear holding pressure provides `1.8 × engine torque × capacity_scale` nominal torque capacity. With 120 Nm and scale 0.1, this is **21.6 Nm**. The model cannot hold the initial gear. Capacity loss applies during the unreported one-second warmup as well as during the shift.

The first recorded sample already has turbine speed **3,633 RPM** against old-gear output speed **1,292 RPM**: roughly **2,342 RPM of old-gear slip**. Engine speed is already **3,705 RPM**. For comparison, the normal run starts at approximately 1,339 RPM turbine/output and 1,481 RPM engine.

At maximum applying pressure the weakened clutch has only about **64.2 Nm** capacity, while the prescribed engine input remains 120 Nm. The engine is not given an OEM torque-reduction request by this pressure-only adapter. Continued acceleration of the slipping engine/turbine is physically consistent with that model.

A controlled probe keeps capacity normal through warmup, then applies the same 90% loss at the shift request. This starts near the normal speeds and removes the early 6,000 RPM domain exit. However, the pressure sequence finishes at **2.02 s with approximately 2,618 RPM target-ratio slip**. The underlying inability to transmit torque is still present; this probe is not a successful shift or a proposed repair.

## EGS51 instruction audit

The pressure-stage behavior under these abnormal inputs matches the original instructions:

- Bank1 **53E2..547F**: the phase-exit test is a **signed, one-sided comparison** of X357 against the selected threshold. With this coding the threshold is 100. Direct raw-ROM fragment tests exit for −3,000 and 0, and remain for +10,000, with a live emergency timer and B5=2. The translated predicate preserves this behavior. A negative applying speed caused by overshooting the target can therefore satisfy this gate; it is not an absolute slip-magnitude test.
- Bank1 **9A6B..9ACD**: pressure matching advances when B1 expires. The `9AC2..9ACC` instructions confirm the timer-based exit.
- Bank1 **9934..99C6**: circuit release/end control clears the mode after its timer. It is not a separate proof of physical gear-ratio synchronization.

All native calls in the six controlled trajectory probes were compared with raw ROM execution using independent persistent state. No mismatch occurred. No native pressure, timer, matching or circuit-release routine was changed for this audit.

The host schedule does **not** run bank0 D456 ratio observation, D8D2 recovery, the full supervisor, or the engine torque-request loop. A separate targeted recovery probe supplies invalid recognized gear `FF`, wheel-motion state 2, completed pressure mode, actual gear 3 and excessive slip qualifiers. Both original ROM and native D8D2 recovery follow **4→1** and assert **IRAM28 bit0 / X1C2 bit1** after the debounce timer expires. This proves the omitted code has a fault response under those supplied qualifiers. It does not prove that a fully integrated observer would produce those qualifiers from these plant signals, nor establish a recovery time in milliseconds.

## Stale host-adapter mapping found and corrected

`sim/egs51.py` wrote engine RPM into X2EF. Recovered bank0 BFD5 instead derives X2EF from filtered wheel inputs; it then computes X2AC as `X2EF × X203 / 2500`. Therefore the engine-speed label and assignment were wrong.

Controlled normal and severe-capacity runs with X2EF left at zero produce **byte-identical CSV trajectories** to the original adapter, including pressures and phases. This assignment was not the cause of these failures on the exercised paths. It has been removed, and the documentation now identifies X2EF as unprovided wheel context. Supplying it properly belongs to the full input adapter; zero is not a general-purpose substitute for a wheel-speed producer.

Other interface assumptions remain: the runner directly supplies approximate clutch kinematics and raw speed/torque values. It does not yet use all recovered producers or establish their complete physical calibration.

## NAG52 failure has the same capacity problem plus a completion boundary

For the 140 Nm tip-in case at capacity scale 0.35, the harness's post-shift holding rule provides **140 × 1.8 × 0.35 = 88.2 Nm** capacity. This cannot maintain lock against the sustained input in this model. Around executor completion, target slip is already approximately **743 RPM**; it grows to approximately 3,398 RPM at domain exit.

The current NAG52 `phase_maxp` and `phase_end_ctrl` also advance on timers after pressure matching. The plant harness then substitutes its assumed holding pressure and clears the engine torque request. The complete Gearbox ratio/fault response is outside this test. The observed executor-completion/physical-slip discrepancy remains a useful regression case, but it cannot be attributed to the new EGS51 translation: this run executes the existing NAG52 C++ algorithms.

## Changes and validation

- Removed the incorrect engine-RPM-to-X2EF assignment and corrected its documentation.
- Added warmup old-ratio slip, warmup engine RPM, and an explicit old-gear synchronization flag to EGS51 results.
- Added a final 100 ms synchronization result. The older final-sample flag remains separate.
- Outcome text now exposes preexisting slip and physical-domain exits, including when a pressure sequence finishes.
- Added a regression test proving the severe case is identified as already slipping before the shift.

All **12 simulator tests pass**. The severe case remains a failure; pressure logic and model capacity were not altered to make it pass. Normal/severe trajectories are unchanged by removing the stale input assignment.

[Controlled probe script](../tmp/simulation_failure_review_20260911/investigate.py) · [Retained original adapter](../tmp/simulation_failure_review_20260911/original_egs51.py.txt) · [Trajectory probes](../sim/results/failure_review_20260911/probes.json) · [Recovery probe](../sim/results/failure_review_20260911/omitted_recovery_probe.json) · [Signed exit probe](../sim/results/failure_review_20260911/rom_exit_gate.json) · [Corrected severe-case reporting/plots](../sim/results/failure_review_20260911/corrected_reporting/comparison.html)

Reproduce with `python3 tmp/simulation_failure_review_20260911/investigate.py` and `python3 -m unittest discover -s sim/tests`. The probe script retains the original adapter as an explicit baseline; its fault-at-shift variant is an isolated experiment, not production controller code.

The next validity step is a plant adapter for the complete OEM observer/supervisor/torque loop, with verified speed and timer units. Changing a correct OEM phase gate to mask a fault-injection failure would undermine the requested baseline.
