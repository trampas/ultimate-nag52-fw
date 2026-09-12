# Persistent Park-to-Park drive cycle

`drive_cycle.py` connects the complete native EGS51 normal scheduler to a persistent engine/transmission/vehicle plant. It initializes controller RAM once in Park, starts with empty modeled drive-path clutches, then retains controller and plant state through the whole cycle. Automatic demand, qualifications, pressure execution, torque requests, adaptation, TCC scheduling and ratio recovery run in their original normal-loop order. Gear changes are not forced by the driver script.

```sh
python3 sim/drive_cycle.py --compare-rom --output sim/results/park_to_park_20260911_final
python3 sim/drive_cycle.py --dt-ms 0.5 --output sim/results/park_to_park_dt05
python3 sim/drive_cycle.py --tick-ms 10 --output sim/results/park_to_park_tick10
python3 -m unittest discover -s sim/tests
```

The local EGS51 ROM and C/C++ compilers are required. Each run produces `drive.csv`, `summary.json` and standalone interactive `comparison.html`. CSV samples are recorded at controller ticks; the plant integrates at the finer selected step. JSON includes resolved driver stages, calibration/input assumptions, automatic shifts, long pressure sequences, coverage and source/binary/ROM hashes. Output directories are Git-ignored artifacts.

## Driver sequence

The editable [scenario](scenarios/park_to_park.json) requests:

| Time | Driver action |
|---|---|
| 0–3 s | Park, idle engine, brake held |
| 3–7 s | Select Drive, continue holding brake |
| 7–10 s | Release brake and creep |
| 10–27 s | Apply accelerator |
| 27–35 s | Follow a 50 km/h cruise target using pedal feedback |
| 35–39 s | Lift accelerator and coast |
| 39–52 s | Brake to a stop |
| 52–56 s | Remain in Drive with brake held |
| 56–60 s | Return to Park after vehicle speed is below 0.05 m/s |

Park selection waits for a physical stop. It does not set the vehicle speed to zero. The braking model applies a bounded friction impulse; the Park constraint only locks the output after selection. A simple idle governor and a speed-dependent converter coupling permit idle in Park and against the brake in Drive. The converter coefficient is a plant assumption, not an OEM calibration fit.

Both initialization routines execute once. The normal scheduler runs once per assumed 10 or 20 ms tick, preceded by the separate platform timer service. Neither controller state nor shaft velocities are reset when the scenario changes stage or when a pressure sequence ends. Equivalent path fill and pressure states persist across gear use and decay under a zero pressure command when inactive. The path routing transfers state without snapping shafts to a gear ratio.

## Pressure and input boundaries

The adapter reads **saved pressure workspace X361..X374**, not the live overlaid IRAM workspace after the torque and adaptation tasks have run. Steady-gear clutch supply uses the ROM hydraulic line relation, `line = 1000 × (MPC + regulator spring) / line factor`. Treating MPC alone as clutch pressure substantially understates capacity. While a shift circuit is active, the adapter inverts the OEM overlap mixer for the releasing path. Once the shift valve is closed, the applying path receives line pressure. Dynamic line corrections and detailed hydraulic routing remain approximations.

Inputs are decoded signal values, supplied through the normal producer interfaces: synthetic N2/N3 words, equal wheel-speed words, engine RPM and torque bytes. The default fixture uses X17F=3070, X181=1975, engine coding 1/3 and mechanical/hydraulic coding 0x20/0x22. The normal wheel and torque producers perform their original integer arithmetic. The physical meaning of all those raw encodings is not yet independently calibrated.

Engine torque requests use the OEM GS218 enable/limit fields and are applied through engine torque lag; negative active limits remain distinct from an inactive request. The engine's pedal torque curve, idle governor and 4,500 RPM governor are host assumptions. No independent learned cells or fake healthy-ratio flags are injected to obtain shifts.

## What “primed” means here

`primed_at_acceleration` requires the controller to be in steady forward mode and an active modeled path to have filled before the acceleration segment. The test also checks initial empty paths in Park, garage engagement, forward gear progression, a final physical stop and one initialization. Timers, filters, RAM adaptation cells and TCC controller state continue evolving rather than being recreated for each maneuver.

This is **not all of the physical ECU/transmission**. It starts with the engine already idling, not a simulated crank/key-on sequence. ATF is fixed at raw 110 rather than thermally warmed. Physical TCC torque capacity, electrical current regulation, EEPROM persistence, full outer-loop hardware diagnostics, planetary/freewheel mechanics and detailed hydraulic priming are absent. The plant retains equivalent **gear-path** clutches, not independently reconstructed 722.6 physical clutch circuits. No claim is made that every adaptation cell or every clutch was exercised. The observed cycle uses first through fourth gear; it does not exercise fifth or Reverse.

`--compare-rom` compares each complete normal scheduler and platform-timer invocation, plus startup, against unhooked ROM execution with independent controller RAM. Both receive the same plant inputs. This verifies the C task chain on the generated trajectory; it does not validate the physical model or the outer-ECU lifecycle.

## Findings from the first cycle

The [saved September 11 run](results/park_to_park_20260911_final/comparison.html) completed 3,000 normal scheduler ticks with one controller initialization and one pressure initialization. All 6,002 ROM entry comparisons passed: two startup calls, 3,000 platform timer calls and 3,000 complete normal scheduler calls. The simulator test suite passed all 15 tests, including persistent engagement/braking and integration-step convergence. After adding initialization-count metadata, the three drive-cycle tests were rerun and passed. This validation applies to the host simulator; it does not establish live NAG52 integration.

The 20 ms fixture reaches roughly 56 km/h and automatically shifts 1→2→3→4, then 4→3→2→1 before stopping and returning to Park. Engine speed remains around 3,000 RPM or below. Park holding, Drive engagement, creep and the brake-held return to standstill are now exercised with continuous state.

There is a **long final 2→1 pressure sequence**, approximately 10.36 seconds at the assumed 20 ms tick (5.18 seconds at 10 ms in the corresponding probe). The report explicitly lists sequences longer than five seconds for investigation. It is not marked as good shift quality merely because the overall drive finishes. Standstill kinematics, pressure/control inputs and the omitted freewheel topology need further validation before interpreting this duration as a prediction for the car.

The 4 MHz processor crystal still does not establish the SIC810 counter divider. Running at both assumed periods exposes that uncertainty; it does not select the correct period.
