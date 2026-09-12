# Fault recovery and driver-intent adaptation

The September 9 fault fixes apply to the controller, not the hydraulic calibration.

- An aborted garage engagement clears both the actual and requested gear to N
  (P when the selector is in P). The existing selector edge detector requires a
  new selector request before another engagement. Successful engagements retain
  their normal behavior.
- A forward shift completed through an emergency timer remains unverified.
  The existing ratio estimator can then read N2/N3 without assuming that the
  requested gear engaged. A matching ratio clears the inhibit; a different
  recognized ratio corrects the gear after the existing disagreement threshold.
  Invalid raw readings remain invalid. Such a timed-out shift is excluded from
  the subsequent shift-quality adaptation update.
- Engine-RPM loss retains the existing ten-poll grace period after the CAN HAL's
  1000 ms expiry. After that, the running state clears even if the turbine is
  still turning. Fresh RPM at or below 400 also clears it. New shifts and torque
  requests are inhibited, TCC is released, and MPC/SPC current targets are held.
  An already active shift retains hydraulic control through its normal completion.
  MPC/SPC are switched off only with fresh engine RPM at or below 100 and valid
  stationary shaft readings. Missing engine RPM never establishes Neutral.
  The duplicate pressure update that overwrote the stopped-engine outputs was
  removed; normal pressure updates now have one controller-loop call site.
- Sensor initialization returns its actual failure to the existing startup gate;
  partially initialized hardware cannot be reported as ready.

## Agility metric

The existing score still responds to pedal position, pedal rise, kickdown and
output-shaft deceleration, rises quickly, and decays at four points per second.
The Comfort/Agility blend and shift-time calibration are unchanged. The score is
held while pedal, shaft-speed or engine-RPM inputs are invalid or the engine is
not running. Recovery seeds a new pedal/speed baseline so an outage cannot
manufacture a pedal stab or a braking event. These changes protect the input to
adaptation; they do not establish that the current weights optimally capture a
particular driver's preference.

The local [EGS51 reconstruction](../tmp/egs51/reconstructed/README.md) supplies
engagement and pressure-state reference behavior. Its documented coverage does
not establish a recovered driver-intent classifier, so it is not a source for
new agility weights.

Two primary research abstracts provide useful context:

- [Zhang et al., SAE 2020-01-5004](https://saemobilus.sae.org/papers/gearshift-control-based-fuzzy-logic-a-novel-two-speed-transmission-electric-vehicles-2020-01-5004)
  describes a gearshift schedule reflecting driver intention through fuzzy
  logic. It concerns a two-speed EV transmission and supplies no NAG52 tuning
  constants for this change.
- [Mishra et al., SAE 2019-01-1129](https://saemobilus.sae.org/papers/modeling-control-adaptation-shift-quality-control-automatic-transmissions-2019-01-1129)
  distinguishes feedforward, feedback and learning between shifts, and evaluates
  clutch-fill adaptation using a model validated against bench experiments.
  This supports treating desired shift behavior and hydraulic adaptation as
  separate control concerns. Rejecting invalid-input and timed-out observations
  is our implementation choice, not a claim that the abstract prescribes it.

## Validation

`logger/tests/test_fault_handling_host.py` compiles actual firmware methods and
controller branches with hardware fakes. Cases include D/R engagement failure,
P cancellation, timed-out shifts with and without actual engagement, missing
N2/N3/output readings, engine-RPM expiry and recovery, fresh zero RPM, moving and
stationary output handling, torque-request suppression, and agility recovery.
The sensor-init test injects failures before successful initialization.

These are software regressions. Neither the host tests nor the ESP32 build
validate clutch pressure transients, TCC release behavior or driver preference
on a vehicle.
