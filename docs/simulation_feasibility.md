# Transmission and vehicle simulation assessment — 2026-09-10

An initial [closed-loop shift simulator](../sim/README.md) now implements the
first-order physical response described below. It runs the shift executor at
20 ms with a faster physical integration step; the full controller runner and
drive-based parameter fitting remain follow-up work.

We have enough recordings and existing code to build a useful simulator for finding
NAG52 software bugs. We do not yet have enough independent measurements to treat
its pressure, shift-shock or wear predictions as validated vehicle behavior.

The useful first deliverable is a deterministic host runner containing the real
controller and a small physical model, with uncertain parameters varied across
scenarios. It should reproduce known failures and expose new ones before a road
test. A simulator whose inputs remain fixed to an old drive cannot evaluate how
changed control outputs alter that drive.

## Evidence in the current logs

I inventoried all 43 `logger/logs/*.jsonl` files, including boot sessions. The
[inventory script](../tmp/simulation_assessment_20260910/inventory.py) and
[per-file results](../tmp/simulation_assessment_20260910/inventory.json) are saved
with this assessment. Run the script from the repository root to regenerate it.

| Observation | Implication |
|---|---|
| 147,742 polling cycles and 523 captured shift events | Enough historical examples to seed regression scenarios. These are captured events, not a count of every physical shift. |
| 488 forward events: 49 × 1→2, 63 × 2→3, 78 × 3→4, 54 × 4→5, 58 × 2→1, 62 × 3→2, 76 × 4→3, 54 × 5→4 | All adjacent forward changes are represented. Counts alone do not establish coverage of load, temperature or tip-in conditions. |
| 505 events have every sequence number between their reported start and end | Sequence completeness is only an initial screen. Some older windows contain timestamp discontinuities; legacy merged events also need to be split or excluded. |
| Today's `045439` and `073946` drives contain 98 version-4 events, 94 forward, with complete sequence windows | Best initial calibration/validation candidates: same firmware hash, valid calibration CRCs, explicit shift IDs, annotations and torque-boundary fields. |
| Today's drives total about 23.2 minutes; polling median is 52 ms, shift samples median 19 ms | Use actual TCU timestamps. Polled records are sequential reads, not a simultaneous physical snapshot; interpolation to 20 ms creates no new information. |
| 425 older events omit explicit trace version; no version-5 events are present | Recover schema/firmware provenance before pooling. The new time-adaptation behavior has no captured v5 road validation yet. |
| Main drives contain reported moving ATF temperatures from 28–83 °C | There is some warm-up coverage, but it is not a balanced shift-type × load × temperature experiment. |
| Only 24 forward events start above 175/250 pedal; three are from today | Heavy-load extrapolation is weak. These bins use the first in-window pedal sample, not peak pedal or proof of steady power. |
| Today's 6,109 in-window trace samples contain no active raw kickdown or kickdown demand | Today's recordings cannot validate the held-kickdown changes experimentally. |
| Accelerometer interval is about 0.300 s; today's end records explicitly report 3.33 Hz and `usable_for_shift_shock: false` | Useful for slow trends at best, after mounting/orientation checks. Insufficient to fit short driveline shocks or validate peak jerk. |
| No polled `driving_dynamics` or `downshift_observer` records in these files | Brake state, the full agility/road-load context, and the new decision-history observer are missing from the dataset despite being available in current code. |

The pressure names are particularly easy to misinterpret. In
[`get_pressure_data`](../src/diag/diag_data.cpp), line/inlet pressure comes from
calculations, and clutch pressure comes from the pressure manager's commanded
shift state. These are not pressure-transducer readings. SPC/MPC electrical
currents are measured, but matching commanded pressure does not validate the
hydraulic plant. CAN engine torque and calculated turbine torque also are not
independent shaft-torque measurements.

The `dropped_by_tcu` end counter is not a count of unread physical shifts: the
recorder increments it as old event-header slots rotate, without knowing what the
host already read. Establish capture loss from request/event/sample continuity.

## What can be modeled now

| Model component | Starting point and confidence |
|---|---|
| Geartrain kinematics and clutch topology | Strong starting point from mechanical calibration, ratios, N2/N3 and `models/clutch_speed.cpp`. Dynamic torque balance and freewheel behavior still need implementation. |
| Longitudinal vehicle motion | A simple mass, road resistance, grade and wheel-radius model can support acceleration, hills, payload and stop/start scenarios. Fit effective parameters in steady-gear segments; sweep mass and grade when they are unmeasured. |
| Engine and ECU response | Pedal/RPM/torque data can seed a torque surface, lag and request-response model within observed conditions. Torque scaling, boost/transient response and gross/net request interpretation remain uncertain. |
| Torque converter and TCC | Logged engine/turbine speeds plus converter calibration support a first approximation with open/slipping/locked states. Validate response separately in each state. |
| Hydraulic actuation and clutch filling | Model command/current lag, fill delay, pressure rise/fall, leakage and clutch torque capacity. Fit combined response to speed trajectories; current logs cannot uniquely identify each physical parameter. |
| Driveline compliance and shift feel | A spring/damper extension can test sensitivity, but its resonance and damping are weakly constrained by the present accelerometer data. |
| Faults and controller sequencing | High immediate value: deterministic CAN expiry, invalid sensors, selector changes, timers, kickdown, repeated shifts and adaptation saturation do not require an exact hydraulic model. |

Use physical equations with a small number of fitted parameters. Start with
engine/turbine/output rotational states, clutch fill/pressure states and vehicle
speed. Brake effort and road grade are scenario inputs. Gear/circuit state must
determine clutch torque paths, including transitions and freewheels, rather than
instantaneously assigning a new gear ratio. A failed engagement must remain
physically possible; setting the simulated gear to the requested gear would hide
the very timeout and ratio-verification bugs we want to find.

Separating hydraulic delay and clutch engagement is consistent with published
transmission modeling work, which includes solenoid, pressure-regulator,
clutch and accumulator dynamics. The cited work does not supply this car's
parameters. [Watechagit and Srinivasan, SAE 2003-01-0314](https://saemobilus.sae.org/papers/modeling-simulation-a-shift-hydraulic-system-a-stepped-automatic-transmission-2003-01-0314).

Avoid fitting every unknown simultaneously. Engine torque scale and vehicle mass
can compensate for one another; so can clutch friction, pressure gain and fill
delay over limited observations. The existing [`road_load.h`](../src/road_load.h)
already documents the mass/torque-scale ambiguity. Fix known quantities, estimate
combined parameters where necessary, and retain parameter ranges where the data
cannot distinguish alternatives.

## Reuse the existing work

[`tmp/shift_replay`](../tmp/shift_replay/README.md) already compiles the real shift
algorithms and pressure manager for the host. Its inputs are recorded RPMs and
torques, so it can compare commands but cannot predict a different shift outcome.
Its profile/TCC/hardware stubs and copied executor logic also mean it is not a
complete controller simulation. Full settings and NVS state are not restored
from the recordings. In particular, the executor currently does not reproduce
the new adaptive target-time adjustment.

I repaired its missing shift-time NVS-key stub during this assessment so it can
build against the current firmware. This is maintenance of the replay harness,
not creation or validation of a physical simulator.

The [EGS51 executable reconstruction](../tmp/egs51/reconstructed/README.md) is
useful as an independent reference for recovered controller routines and constants.
Its ROM-comparison tests validate software semantics; they do not turn it into a
model of hydraulic hardware. Use its recovered behavior as another comparison,
not as the physical response generated by the simulator.

## Recommended implementation order

1. **Make deterministic controller replay reliable.** Factor a controller tick
   and shift-executor tick out of their task loops, retaining the production
   decision code. Inject time, CAN/sensor reads, storage and actuator writes.
   Preserve delivery order, signal expiry, task scheduling and startup state.
   Use real profiles and adaptation code. Add known-bug fixtures, including the
   low-speed kickdown, garage cancellation, RPM-loss, timeout verification and
   saturation cases. This stage can pay off before plant fitting.
2. **Close the loop with a simple physical model.** Controller outputs change
   engine torque, clutch pressures/torques and shaft speeds; modeled sensors feed
   the next tick. Include current/pressure limits, delay and fill dynamics.
   Run fixed seeds faster than real time, with configurable grade, payload,
   temperature, throttle/brake/selector schedules and sensor faults.
3. **Fit and validate against separate drives.** Begin with today's two drives,
   reserving one whole drive for validation. Screen clock gaps, missing data,
   merged shifts and initialization intervals. Fit steady-gear behavior before
   converter and shift transients. Hold out complete maneuvers, not alternating
   samples from the same shift. Report shaft-speed errors, slip onset, sync time,
   total duration and actual failure/recovery outcomes by shift and load. Do not
   use the controller's calculated pressure or slip-energy estimate as independent
   proof that the model is physically correct.
4. **Use scenario sweeps as a regression gate.** Sweep uncertain hydraulic gain,
   fill delay, engine response and road load. Test tip-in during a coast downshift,
   held/released kickdown, fast lift, adjacent ladders, uphill acceleration,
   downhill braking, engine-RPM expiry mid-shift, gear disagreement, launch and
   adaptation over repeated drives. Assert no overrev request, bounded commands,
   appropriate fault inhibition, no learning from rejected observations and
   correct recovery. Keep any discovered failure as a small repeatable scenario.

A change that improves one fitted trajectory but fails nearby plausible parameter
sets should not be called an improvement. After a new drive, compare its outcome
to the simulator's prediction and revise the model's validated operating range.

## Measurements with the largest payoff

First improve recording without changing hardware:

- Archive the exact source/build alongside the firmware hash, the complete module
  settings, all active maps, adaptation cells and profile selection. Today's
  `65c991f-dirty` string and hash identify an image but do not reconstruct its
  source changes or NVS state. Capture settings changes during the recording too.
- Include brake state, raw and validated kickdown, sensor validity/age, failure and
  timeout reasons, trace IDs, selected shift characteristics and controller
  commands on a common TCU timebase. Ensure steady driving and garage engagements
  have usable coverage, not only completed forward shifts. Enable the observer
  and driving-dynamics records, with measured polling overhead.
- Capture driver/indicated torque, request mode/bounds/wire torque, measured and
  target currents, RPMs and ATF alongside the shift state at controller cadence.
  Prefer a buffered binary recorder if adding fields would overload diagnostic
  polling. Preserve raw observations as well as filtered values.
- Record vehicle mass/load, tire configuration and route/grade context. Collect
  repeated comparable maneuvers across temperature and pedal conditions, including
  kickdown and coast-to-power transitions, so parameters can be checked out of
  sample.

For credible shift-feel validation, obtain a rigidly mounted, timestamped IMU with
verified actual bandwidth/rate, preferably 100–200 Hz for an initial measurement
target, and known axis orientation. For confident hydraulic identification, obtain
synchronized physical line/apply-pressure measurements on a suitable instrumented
setup. These are follow-up measurements, not prerequisites for starting the
software regression simulator.

The distinction matters: published clutch-control studies validate their physical
models against bench measurements, and in-vehicle work reports temperature-dependent
nonlinear engagement behavior. Existing maps alone cannot establish that behavior
for this transmission. [Mishra et al., SAE 2019-01-1129](https://saemobilus.sae.org/papers/modeling-control-adaptation-shift-quality-control-automatic-transmissions-2019-01-1129),
[Haria et al., SAE 2018-01-0395](https://saemobilus.sae.org/articles/vehicle-characterization-wet-clutch-engagement-behaviors-automatic-transmission-systems-2018-01-0395).

The recommended next project is the deterministic controller runner plus a simple
closed-loop plant and a set of known-failure scenarios. Its first acceptance test
should be that it exposes an old bug and passes its fix under a range of plausible
vehicle parameters. Absolute comfort or durability prediction should remain a
separate, measurement-dependent objective.

### EGS51 closed-loop pressure schedule

The [EGS51 host adapter](../sim/EGS51.md) now runs reconstructed C release
pressure phases for a forced 4→3 shift against the same physical plant. Optional
raw-ROM execution checks independent persistent C state after each call. This
adds a way to exercise the reconstruction with physics-generated feedback;
it does not replace drive-log validation of the plant or reconstruct the entire
ECU scheduler. Timing, sensor mappings and missing feedback producers are
explicit assumptions in its generated report.
