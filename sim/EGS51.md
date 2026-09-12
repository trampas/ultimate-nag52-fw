# EGS51 C driving the physical plant

The recovered EGS51 C now drives the **same `plant.h` model** used by the native
NAG52 runner. The initial supported case is a forced 4→3 release shift (OEM mode
3), from entry through release, transfer, pressure matching and circuit release.
The plant feeds evolving shaft speeds back into C every host control tick;
pressure commands change clutch capacity, shaft speeds, acceleration and jerk.
There is no prerecorded speed trajectory or forced ratio synchronization.

```sh
python3 sim/egs51.py --scenario sim/scenarios/egs51_release_43.json --compare-rom --convergence
python3 sim/egs51.py --set mass_kg=2300 --set grade_percent=5 --output sim/results/egs51_loaded
```

Open `sim/results/egs51_43/comparison.html`. Full-rate CSVs include pressures,
capacities, slips, acceleration, raw and 20 ms jerk, phase/substates, circuit bits
and the emergency timer. `summary.json` records resolved inputs, calibration,
source/binary/ROM hashes, visited phases and differential call counts. The local
uncommitted `tmp/egs51/EGS51_A0215451432.bin` is required; it is not redistributed.
A C compiler, C++ compiler and Python standard library are sufficient.

`--compare-rom` executes each recovered routine in the 8051 emulator as well as
native C. Both receive the same physical inputs and retain **independent state**
across ticks. After every call it compares all 1,024 XRAM bytes and the persistent
IRAM pressure, phase, timer and flag fields. Compiler scratch registers are
excluded. ROM outputs are never copied into native state. Arithmetic and map
callees execute ROM bytes; the existing emulator models the arithmetic
peripheral. A mismatch stops the run. Without this option only native C runs,
which is appropriate for faster parameter exploration.

## What this validates

* Differential agreement tests the C reconstruction against the original ROM on
  physically generated trajectories, including transitions between routines.
* Plant unit tests check mechanical properties, and timestep sweeps expose
  numerical sensitivity. Changing clutch capacity must alter both physical
  behavior and subsequent controller commands; a regression test checks this.
* Drive logs remain the independent evidence for whether the simulated car is
  accurate. Agreement between two controllers sharing a plant is insufficient.

## Explicit limits of this first adapter

This is a **host pressure schedule**, not the complete EGS51 ECU scheduler.
It calls setup, the phase's recovered pressure routines, and one timer service
per host tick. Phase 1 calls applying control followed by modulating control.
The shift is forced; gear selection, skip handoff, torque-request production,
CAN transport, TCC scheduling, adaptation learning and the complete task
scheduler are outside this runner. Completion is reported as
`pressure_schedule_completed`; `controller_completed` deliberately stays false.
Synchronization and emergency timeout are reported separately from completion.

The following are scenario assumptions, not recovered physical interfaces:

| Interface | Current mapping |
| --- | --- |
| Host/timer period | `tick_ms`, default 20 ms; OEM physical timer period remains unverified |
| Speed units | `speed_raw_per_rpm`, default 1 |
| Torque units | `torque_raw_per_nm`, default 1; positive constant commanded torque, without intervention |
| Pressure units | `mbar_per_pressure_raw`, default 1 |
| Temperature / demand qualification | Explicit raw bytes, default 60 / 10; not a Celsius conversion |
| X22F | Modeled turbine speed |
| X1FD / IAD | Signed torque / magnitude from the recovered CF5B producer; the fixture sets X397 to 100 (unity scaling) |
| X2AC | Modeled output speed |
| X2EF | Wheel-derived context; left at fixture default, not populated with engine speed |
| X1EA / X357 / X2BB | B2 rear-sun/applying speed and K3 releasing speed, using NAG52 4→3 kinematics |
| Other unavailable producer inputs | Zero initialization, including extra torque/inertia feedback terms |

ROM calibration selection uses coding bytes `0x20/0x22`. Gear ratios come from
that ROM's gear table, and spring/friction coefficients come from its selected
mechanical calibration. Those ratios/calibrations can differ from the NAG52
harness. Controller-derived clutch capacities are **seeds**, not independent
measurements. Do not interpret differences between default EGS51 and NAG52 runs
as a controller ranking until their vehicle, calibration and operating conditions
have been aligned.

The shared plant takes applying clutch pressure I46, not SPC solenoid pressure
I48; the latter is retained in the CSV. Releasing pressure is inferred by
inverting the recovered overlap mixer using I44. This omits hydraulic routing
transients and centrifugal capacity effects. During circuit closure the host
uses a steady clutch holding boundary condition. There is one second of old-gear
warmup before the recorded shift to avoid counting startup acceleration as shift
jerk. The simulation stops when the recovered pressure schedule finishes; it does
not invent a post-shift controller or snap shaft speeds into agreement.

Next priorities are recovering the actual scheduler cadence and sensor producers,
adding the engine torque-request/response loop, and fitting the shared plant
against held-out drive events. Those improvements can be checked separately:
ROM agreement for C, and prediction error against real traces for physics.

## Failure interpretation and initial-state checks

The summary now records old-ratio slip and engine RPM after warmup, before the
shift request. `warmup_old_gear_synchronized=false` means the test is already
slipping in the old gear; it is not a healthy-gear shift test.
`final_sync_held_100ms` checks the final 100 ms separately from the older final
sample flag. Completion, synchronization and domain exits remain separate.

The holding boundary has nominal capacity 1.8 times prescribed torque, then
`capacity_scale` reduces actual capacity. At scale 0.1, the 120 Nm base case
has only 21.6 Nm of old-clutch capacity during warmup. This is intentional
severe hardware-loss input, but cannot validate normal shift quality. See
[the failure audit](../docs/simulation_failure_review_20260911.md) for controlled
probes and raw-ROM checks.

A separate [persistent drive-cycle runner](DRIVE_CYCLE.md) now connects the
complete normal scheduler and startup to the plant. The scope limits above
continue to describe this older forced 4→3 pressure-sequence runner.
