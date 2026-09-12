# Transmission / vehicle model review — 2026-09-11

**Follow-up:** [Failure audit](simulation_failure_review_20260911.md) identifies preexisting warmup slip, insufficient capacity, omitted OEM fault/torque stages, and a corrected inactive speed assignment. These failures are not evidence by themselves of an EGS51 mistranslation.

The nominal scenarios complete and synchronize, but reduced clutch capacity exposes failures. These results exercise the current NAG52 shift executor and the recovered EGS51 4→3 pressure sequence. The full EGS51 scheduler is **not connected to the physical plant** in this runner.

[Interactive results and all 29 runs](../sim/results/review_20260911/index.html) · [Derived metrics](../sim/results/review_20260911/review_metrics.json) · [Report generator](../tmp/simulation_review_20260911/report.py)

Results directories are local, Git-ignored artifacts. Each contains CSV trajectories, interactive plots and summary.json with resolved assumptions and source/binary/calibration hashes.

| Scenario | Time from shift request | Physical outcome |
|---|---:|---|
| NAG52 2→3, 35 km/h, 120 Nm | 2.08 s | Completes; synchronized |
| NAG52 tip-in 3→2, 30 km/h, −20→140 Nm | 1.30 s | Completes; synchronized |
| EGS51 4→3, 50 km/h, 120 Nm, assumed 20 ms tick | 1.98 s | Pressure sequence completes; synchronized |
| Same EGS51 case, assumed 10 ms tick | 1.08 s | Pressure sequence completes; synchronized |
| EGS51 4→3, 2,300 kg and 5% grade | 1.96 s | Pressure sequence completes; synchronized |
| EGS51 4→3, 300 ms fill and 80 ms pressure lag | 2.08 s | Pressure sequence completes; synchronized |
| EGS51 4→3, 250 Nm | 2.00 s | Pressure sequence completes; synchronized |
| NAG52 tip-in 3→2, 35% clutch capacity | Executor says complete at 1.26 s | Never synchronizes; engine exceeds model's 6,000 RPM limit at 4.969 s scenario time |
| EGS51 4→3, 10% clutch capacity | Unfinished | Unsynchronized; engine exceeds model's 6,000 RPM limit at 1.386 s after request |

Nominal runs and both severe failure cases were checked at 1, 0.5 and 0.25 ms plant integration steps. Completion durations remain unchanged across those steps in the nominal cases. Failure-domain times differ by less than 1 ms. This makes the observed failures unlikely to be artifacts of the chosen integration step; it does not establish physical model accuracy.

The NAG52 capacity failure needs investigation at the adapter/completion boundary. The executor reports success while the plant has never held target-ratio synchronization. Post-shift pressure in this harness is an assumed holding boundary, and the full Gearbox fault/recovery loop is absent. This finding therefore does not by itself prove a live firmware completion defect. The EGS51 runner likewise omits the full supervisor, ratio/fault observer, torque intervention and TCC.

At 1 ms, peak fixed-window jerk is 22.30 m/s³ for NAG52 2→3, 38.67 for NAG52 tip-in 3→2 and 56.52 for the EGS51 base sequence. At 0.25 ms these are 22.59, 40.01 and 57.17. These are different maneuvers and calibration/adapter boundaries, so they must not be used to rank EGS51 against NAG52. Raw instantaneous jerk grows strongly as the integration step shrinks because the rigid clutch model permits abrupt stick/slip transitions. The low jerk in a slipping failure case is not an improvement.

Validation: all 11 simulator tests passed, including physical invariants and changed plant feedback changing controller commands. EGS51 runs additionally checked 5,425 native routine calls against raw ROM execution with independent retained state; no mismatches occurred. The review independently checks target-ratio slip below 40 RPM throughout the final 100 ms, rather than relying only on the EGS51 runner's single final-sample flag.

The model is an uncalibrated two-equivalent-path approximation, with prescribed driver torque, simplified converter/hydraulics and no full driving schedule. NAG52 uses the existing replay calibration seed; EGS51 uses ROM coding 0x20/0x22. The 4 MHz processor crystal does not yet determine the SIC810 counter divider. The large 10/20 ms sensitivity is evidence that this timing must be resolved before treating the EGS51 durations as predictions.

Next useful work is to connect the complete EGS51 scheduler—including fault observation and engine torque response—to the plant, align calibration and physical inputs for paired cases, and fit/validate the plant against separate recorded maneuvers. The current runs cannot establish double-downshift or skip-shift behavior because shifts are forced individually.

Representative reproduction commands:

```sh
python3 -m unittest discover -s sim/tests
python3 sim/egs51.py --compare-rom --convergence --output sim/results/review_20260911/egs51_base
python3 sim/egs51.py --compare-rom --set tick_ms=10 --convergence --output sim/results/review_20260911/egs51_tick10
python3 sim/egs51.py --compare-rom --set capacity_scale=0.1 --convergence --output sim/results/review_20260911/egs51_very_weak_convergence
python3 sim/run.py sim/scenarios/power_23.json --convergence --output sim/results/review_20260911/nag52_power23
python3 sim/run.py sim/scenarios/tipin_32.json --set capacity_scale=0.35 --convergence --output sim/results/review_20260911/nag52_weak_convergence --no-build
python3 tmp/simulation_review_20260911/report.py
```

All other resolved case parameters are retained in each case's summary.json.
