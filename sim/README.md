# First-order closed-loop shift simulator

The real NAG52 `ShiftingAlgorithm`, `CrossoverShift`, `ReleasingShift`, pressure
manager and clutch-speed calculations run on the host. A separate physical model
updates engine, turbine and vehicle motion between controller ticks. Recorded
RPMs are not imposed on the simulated shift.

The controller runs every **20 ms of simulated time**. The plant defaults to
**1 ms**, with 0.5 and 0.25 ms available for convergence checks. Nothing sleeps to
keep pace with a car. On the development machine, a five-second scenario took
roughly 0.04 seconds, including full-rate CSV output; compilation is separate.

## Run and inspect

Only Python 3, Bash and a C++17 compiler are needed. From the repository root:

```sh
python3 sim/run.py sim/scenarios/power_23.json \
  --compare time_ms=500,700,1000 --convergence --output sim/results/power_23

python3 sim/run.py sim/scenarios/tipin_32.json \
  --compare feedback_guard=0,1 --output sim/results/tipin_32 --no-build

python3 sim/run.py sim/scenarios/power_23.json \
  --compare mass_kg=1500,1800,2300 --output sim/results/mass --no-build
```

The first command builds the current firmware host harness. `--no-build` refuses
reuse if the binary is older than any of the source inputs. Each output directory
contains:

- `comparison.html`: standalone interactive plots; choose acceleration, raw jerk,
  20 ms jerk, turbine RPM, clutch pressures or target-ratio slip. Toggle runs and
  inspect values by moving over the chart.
- `run_NN.csv`: every physical time step, including torque, pressure, capacities,
  shaft speeds, acceleration, jerk and controller state.
- `summary.json`: resolved scenario/plant parameters, model version, controller
  completion/timeout, physical synchronization, metrics, runtime, source and
  binary hashes, and the calibration-header hash.

Results are ignored by Git. Model code and scenario definitions are source files.

Override a parameter with repeated `--set key=value`. `--compare` sweeps one
parameter. `--convergence` repeats each case at the configured time step and its
half/quarter values. All cases start from the same scenario initial conditions;
physical commands and trajectories can then diverge. The scenario's shift number
is the firmware `GearChange`: 1–4 are 1→2 through 4→5, and 5–8 are 2→1 through 5→4.

The supplied scenarios are synthetic examples, not fitted reproductions of a
particular drive. A scenario specifies initial speed, initial driver torque and
pedal, optional timed torque/pedal change, ATF temperature, requested shift time,
and the driving/model conditions. Driver torque is prescribed over the short
maneuver; it is not yet generated from an identified pedal/RPM/boost map.

## Physical model and assumptions

`plant.h` uses SI units internally. Its states include engine, turbine and output
angular velocity, engine torque lag, and two clutch fill/pressure states. The two
clutches are **equivalent torque paths at the old and new ratios**, not a complete
722.6 planetary/freewheel reconstruction.

With old/new ratios `r_o`, `r_n`, torque paths `T_o`, `T_n`, converter torque `T_c`,
and output-reflected road load `T_load`, the rotational equations are:

```text
J_engine  * dω_engine/dt  = T_engine - T_c
J_turbine * dω_turbine/dt = T_c - T_o - T_n
J_output  * dω_output/dt  = r_o*T_o + r_n*T_n - T_load

J_output = J_output_hardware + mass * (wheel_radius/final_drive)^2
speed = ω_output * wheel_radius/final_drive
acceleration = d(speed)/dt
jerk = d(acceleration)/dt
```

The converter is a dissipative viscous coupling with configurable damping. It
models engine/turbine slip and lag but does not yet model torque multiplication,
stator/freewheel state or TCC control. Engine torque follows driver demand or the
firmware's requested bound through a first-order lag. The firmware receives its
own nominal converter-torque estimate, rather than access to the plant's hidden
actual torque.

Clutch commands pass through a pressure lag and a pressure-dependent fill state.
A clutch develops no torque until filled; capacity then depends on pressure above
the release spring and a calibration-seeded gain. `capacity_scale`, `fill_s` and
`pressure_tau_s` allow the physical response to differ from the controller's
nominal model. Old/new friction torques oppose slip; at synchronization they
transmit only the torque required to remain locked, up to their capacities.
Implicit bounded impulses implement that transition without forcing the requested
gear ratio on algorithm completion.

The adapter uses the firmware's applying-pressure command and inverts its
SPC/MPC overlap mixer for the releasing-pressure command. The `p_off` diagnostic
is MPC, not a measured releasing-clutch pressure. Circuit opening/closing routes
the equivalent paths; post-shift holding pressure has an assumed torque reserve.
Valve flow, detailed centrifugal effects, backlash, compliance and clutch thermal
behavior are not resolved. Gear-endpoint-based synthetic N2/N3 readings provide
feedback to the production clutch-speed calculations.

Vehicle load includes mass, aerodynamic resistance, rolling resistance, road
grade and an optional fixed brake force. Initial conditions start in a forward
gear; garage shifts, a full driving schedule, selector/kickdown decisions,
sensor-fault injection and production TCC are outside this runner. The existing
host profile/TCC/storage stubs remain; adaptation learning is disabled during
paired runs. This is a shift-executor simulator, not a full TCU simulator.

The calibration seed is the existing replay header for EGS PN **0205459132**,
blocks STDP/51/71/SM00. It has not been fitted to the latest car configuration
(STDP/52/119/SM00 in today's snapshots). The hash records exactly which seed was
used. Do not compare its absolute numbers to a drive without matching calibration,
settings and initial state first.

The friction representation follows the standard distinction between bounded
static torque at lock and kinetic torque opposing slip. See the primary
[clutch lock-up modeling example](https://www.mathworks.com/help/simulink/slref/building-a-clutch-lock-up-model.html).
The equivalent-path topology, hydraulic response and parameter defaults here are
our approximations, not calibrated OEM plant equations.

## Acceleration and jerk comparisons

CSV `accel_m_s2` is the step's average acceleration from the solved output motion;
`jerk_m_s3` is its difference from the preceding physical step divided by `dt`.
`jerk_20ms_m_s3` uses the same acceleration difference over **20 ms of physical
time**, independently of the integration step. It is a finite-window derivative,
not an accelerometer recording and not a moving average of acceleration.

Raw jerk at ideal stick/slip transitions does **not** converge in the initial
rigid model: an acceleration discontinuity gives a larger derivative as `dt`
shrinks. Keep raw samples for inspection, but compare the fixed-window derivative
alongside synchronization, torque loss and duration. Adding measured hydraulic
response and driveline compliance is the route to better instantaneous-jerk
predictions; reducing `dt` alone cannot supply those missing dynamics.

Summary peaks/minima cover shift initiation through the scenario's end, excluding
startup warm-up. Keep the same horizon and driver input for paired comparisons.
Controller completion and physical synchronization are reported separately. The
first synchronization timestamp requires 100 ms within 40 RPM of the target ratio;
final synchronization requires the same hold at the end. A controller timeout or
an unfinished shift cannot be interpreted as a comfort improvement. The model
reports a domain exit on backward shaft motion or engine/turbine speed over
6000 RPM; that is a simulation boundary, not simulated overrev protection.

Initial uncalibrated observations:

- The base 2→3 scenario completes at 3.08 s (shift requested at 1.00 s), with
  physical synchronization beginning around 2.73 s.
- Its peak 20 ms jerk is approximately 22.30 m/s³ at 1 ms and 22.59 m/s³ at
  0.5/0.25 ms. The synchronization time also changes by only a few milliseconds.
- Increasing mass reduces acceleration and changes the shaft trajectory fed to
  the firmware. The controller is reacting to the model, not replaying commands.
- Changing target time between 500 and 1000 ms changes the trajectory but does
  not materially change the largest jerk in this case; the largest event comes
  from another portion of the shift. A single peak is not a complete quality score.
- In the synthetic 3→2 tip-in case, `feedback_guard=1` slightly increases peak
  20 ms jerk versus `0` (about 38.67 versus 37.79 m/s³). This model does not yet
  establish whether either is better on the car. It is an example of why the
  simulator must be checked against drive outcomes rather than assumed to favor
  the latest control change.

## Tests and next refinement

```sh
python3 -m unittest discover -s sim/tests
```

The tests check analytic steady-gear acceleration, mass sensitivity, passive
energy dissipation, zero drive transmission with open clutches, fill and torque
limits, synchronization, deterministic output, timestep convergence, and changed
firmware commands producing changed physical trajectories. They compile the real
firmware host harness and do not require a recorded drive.

Refine this iteratively:

1. Match a selected drive's firmware build, calibration, NVS/settings and initial
   state. Use observed pedal/driver demand as external inputs, not observed shaft
   speeds after initialization.
2. Fit engine/converter behavior on steady-gear sections, then effective fill,
   pressure lag and capacity gains against shift speed trajectories. Keep physical
   parameters separate from controller tunings; do not refit the plant separately
   to make each code variant look good.
3. Reserve whole maneuvers/drives for validation. Compare predicted duration,
   slip onset, speed trajectory and acceleration shape to the next drive, then
   revise the model using the discrepancy. Treat the current accelerometer as
   optional; shaft speeds already provide slower motion constraints.
4. Check whether a proposed improvement survives nearby plausible mass, hydraulic
   gain, fill-delay and converter-response values. Preserve observed failures as
   repeatable scenarios and add them to the test suite.
5. Add driveline compliance and more detailed converter/hydraulic behavior when
   their absence explains persistent prediction errors. Extend the host boundary
   to the full controller tick to test driving schedules and fault recovery.

## Recovered EGS51 controller

[EGS51 adapter and validation boundaries](EGS51.md) documents a native C 4→3
release pressure schedule driving the same physical plant, with optional
persistent-state comparison against raw ROM execution:

```sh
python3 sim/egs51.py --compare-rom --convergence
```

## Persistent full driving sequence

[Park-to-Park drive cycle](DRIVE_CYCLE.md) adds a separate runner using the full
native EGS51 normal scheduler, starting stationary in Park and retaining
controller/plant state through Drive engagement, creep, automatic upshifts,
cruise, coast, braking and return to Park:

```sh
python3 sim/drive_cycle.py --compare-rom
```

This extends beyond the isolated pressure-sequence runner above. It still uses
an approximate plant and does not model the complete physical ECU. See the
cycle documentation for priming checks, omissions and the observed long 2→1
sequence at standstill.
