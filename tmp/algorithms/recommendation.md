# Recommended control strategy for the TCU

Written September 2026 after a second pass through the literature, on top of
[references.md](references.md) and the four topic notes. Constraint throughout:
**no new sensors**. Everything below runs on what the board and the EGS51 CAN
bus already give us.

---

## The recommendation in one paragraph

Use a **layered supervisory shift strategy**: a base shift schedule that is
*calculated* from the vehicle envelope and a target power reserve, corrected at
run time by a small set of **driving-situation recognisers** (driver type,
road grade, cornering, fast-off, downhill braking, next-gear acceleration
capability), with **bounded, gated adaptation** on top for what cannot be
calculated. This is the architecture every production controller from the
1990s onward converged on (Bosch/Siemens EGS, ZF, Porsche Tiptronic DSP, the
original 722.6 EGS), and every input it needs is either already on the bus or
already computed in this firmware. Fuzzy schedules, neural nets and
reinforcement learning are **not** recommended on the controller: they solve
the same problem with parameters nobody can inspect, and on one car with no
ground truth they cannot be verified. Dynamic programming has a place, but
offline, in `scripts/`, for generating the base maps.

The user-facing result is that people tune **a dozen physically meaningful
knobs** (power reserve, sportiness, grade sensitivity, comfort/agility
targets, vehicle mass, hold times) instead of 44-cell maps.

---

## What we have to work with

Inputs (EGS51, see the firmware inventory):

| signal | source | used by |
|---|---|---|
| turbine rpm (N2/N3), output rpm | board | everything |
| ATF temperature | board | gating |
| **rear wheel speeds L and R** | BS_208 | cornering detection (front wheels are not on EGS51) |
| pedal 0-250, kickdown, brake switch | MS_210 / EWM_230 / BS_200 | driver type, fast-off, grade braking |
| engine rpm, indicated / min / max torque, drag torque | MS_308 / MS_310 | load, road load, pressure sizing |
| coolant, oil, intake temps, fuel flow | MS_308 / MS_608 | warm-up, telemetry |

Outputs: MPC, SPC, TCC regulators, Y3/Y4/Y5 shift valves, and **one torque
request magnitude** to the ECM (EGS51 ignores control type and bounds).

Already computed on the TCU and not yet consumed by any decision:

- `RoadLoad` RLS estimator: `terrain_coeff` (usable), `mass_kg` (a combined
  mass-and-torque-scale figure, see below), `confidence`.
- `agility_score` 0-100, instant rise, ~25 s decay. Only used to swap Comfort
  for Agility with hysteresis.
- `ShiftQuality` per shift: response, duration, peak jerk, torque hole, lockup
  rate, settle oscillation, slip energy. 50 Hz trace.
- Pressure adaptation maps (prefill time, SPC offset, torque offsets), gated to
  low torque so it ran on 2 of 39 shifts.

What the logs say is wrong today: 500 ms median response before the ratio
moves, 39 m/s³ peak jerk, 17 % of upshifts landing below 1200 rpm, hunting on
6 of 105 upshifts (all 4-5 and 3-4), downshift ladders completing at
standstill, and the ECM torque signal delivering ~70-78 % of mapped so every
clutch pressure is sized ~30 % high.

---

## The layers

### Layer 0 — calculated base schedule (offline, `scripts/`)

Generate the upshift/downshift maps from the envelope instead of editing cells.
Two published formulations fit, and they agree with what `shift_envelope.py`
already checks:

- **Constant / variable power reserve** (Ngo, Hofman, Steinbuch, Serrarens
  2013; the horsepower-reserve formulation of driveability). At each pedal
  position the upshift point is the speed where the *next* gear still leaves
  the required power reserve above the road load. Reserve is the knob:
  small reserve = economy, large reserve = sport. This is the single number
  that reconciles the "boost point vs hunting" tension in the 60-90 % pedal
  columns, because it moves the *upshift* column, which is the blocker.
- **Three-parameter schedule** (Miao, Liu, Zhu 2018): pedal × speed × terrain
  coefficient. Generate the map for three or four terrain values and
  interpolate on `terrain_coeff` at run time.

Dynamic programming (Ngo 2013, the heavy-truck and EV papers) belongs here:
run it once over the logged drives to produce a schedule, then check it with
`shift_envelope.py`. It does **not** belong on the ESP32.

Downshift map: derived from the upshift map minus a hysteresis band in road
speed, then checked against the shift-time map and a deceleration model so the
ladder can finish before the car stops (§4 of TRANSMISSION_NOTES.md).

Inputs the owner must supply, exactly as `CLAUDE.md` says: boost threshold,
economy rpm, redline, and ratios (read from the calibration block). A
**relative torque-vs-rpm curve** is wanted here, for choosing where the power
reserve is available; the drive logs gave its shape (65 % of peak power at
2000-2250 rpm, 100 % at 3250-3750). Note this curve is needed *only* for map
generation — the next-gear check in Layer 1c was measured not to want one.

### Layer 1 — driving-situation recognition (on the TCU, 10-50 Hz)

Each recogniser is a small, inspectable state machine producing one flag or one
scalar. Production controllers run exactly this set.

**a. Driver type → continuous map blend.** Keep `agility_score`, but use it as
an interpolation weight between the economy and sport schedules rather than a
switch. The score distribution is not bimodal (42 % of driving in the 20-79
band), and a switch produces a 491 rpm discontinuity at 10 % pedal. Keep the
60/25 hysteresis only for anything that *must* be discrete (TCC strategy).
Add the Mercedes-style long-term memory: a slow average over the last ~40
shifts that biases the default blend, so a habitually gentle driver gets the
economy end without waiting for the score to decay. Suspend the long-term
update during kickdown, Winter, Manual and any limp state (ZF's gating rule).

**b. Road grade → schedule correction (anti-hunt, climb, descent).** Consume
`terrain_coeff` in three places:
- interpolate the Layer-0 terrain axis (SAE 930674, Miao 2018);
- **downhill hold**: on a negative grade with the pedal released, inhibit
  upshifts so engine braking stays (Porsche DSP "downhill program", and the
  original 722.6 did this);
- **grade braking**: grade below a threshold **and** brake pressed **and** the
  car still accelerating (from output rpm) ⇒ command one downshift, regardless
  of the map; release when the brake has been off ~3 s, deceleration is
  established, or the grade flattens (Ford US 9676388, which uses an
  inclinometer; the RLS estimate substitutes).
Gate all three on `confidence` so a seed value never acts.

**c. Next-gear acceleration capability (the direct anti-hunt check).** Before
any upshift, predict the acceleration the next gear can deliver and refuse the
shift if it is below a required minimum indexed by pedal (GM US 6098004, Ford
US 5669850: "the closer to the scheduled upshift point, the more acceleration
is required"). Two things make this cheap here:
- The RLS state already *is* the model: `a_pred = θ₁·(T_e(n_next)/r_g_next −
  F_aero) − g·θ₂`. And because `θ₁` was fitted against the same ECM torque
  signal, the torque-scale error cancels in the prediction. This is the one
  place the biased `mass_kg` is actually useful.
- `T_e(n_next)` is the **current torque, unscaled**. Scaling it by a relative
  torque curve for the lower rpm was the plan and it turned out to be wrong:
  over 91 upshifts a flat assumption predicts better (correlation 0.62) than
  the measured power curve (0.59) or the ECM's broadcast max torque (0.53).
  So this check needs no curve and no owner-supplied torque numbers.

**Measured before building it** (`scripts/next_gear.py`, and the reason to
re-run it on any other car): 30 of 91 upshifts were followed by the car
decelerating in the new gear, 13 of them past −0.64 m/s². Landing rpm alone is
*not* a cheaper substitute — to catch 14 of the 30 it holds 38 good upshifts,
against 7 for the model. **Built and off by default** as `SBS
en_next_gear_check`; never driven.

**d. Cornering hold from rear wheel speeds.** Rear L/R difference above S1 ⇒
inhibit upshift, below S2 ⇒ release (US 6571162). Thresholds lower in sport,
higher in economy. EGS51 has exactly the two rear wheels this needs. Also
gates adaptation (a shift inside a corner is not a clean sample).

**e. Fast-off hold.** Pedal release rate beyond a threshold that depends on
pedal position and driver type ⇒ hold the gear for a period that depends on
grade, released on clear traction (pedal above a traction/thrust line vs rpm
and grade), on timeout, or below a minimum output speed (Bosch US 6527672).
Fixes the "lifted for an instant mid-overtake and lost the gear" complaint
without extending the agility decay.

**f. Pedal-based shift point stabilisation.** Instead of one 2 s post-upshift
inhibit, make the pedal-rate threshold that arms an inhibit a function of time
since last shift (Ford US 8133154: −86 %/s right after a shift decaying to
−4 %/s at 6 s), and look the schedule up with a stabilised pedal value during
gradual transitions. This kills the small-pedal-wobble shifts in the 20-40 %
band without blocking deliberate requests.

**g. Ladder timing guard.** Already known from the standstill clunk: before
requesting a downshift, check that the ladder can complete before the
projected output speed reaches the next threshold, using the shift-time map and
the current deceleration. If not, skip a gear or skip the shift. This is a
calculation, not a calibration.

### Layer 2 — shift execution

The response and jerk numbers are execution problems, not schedule problems,
and the literature is unanimous on the tool: **turbine speed feedback**
(SAE 911938; GM US 7374513; the clutch-to-clutch inertia-phase papers).

- **Fill/response adaptation from turbine timing on every shift.** Measure the
  delay from valve command to the ratio starting to move (turbine departs the
  attained-gear speed by ~50 rpm), and whether it flared or tied up. Fill
  volume is nearly torque-independent, so this can adapt on *all* shifts, not
  only the low-torque ones. Long delay ⇒ raise prefill; early movement or tie-up
  ⇒ lower it. Counter-based gain that resets to minimum when direction reverses
  (US 6915890 / 7374513). This attacks the 500 ms response directly.
- **Inertia-phase closed loop on slip.** Track the turbine towards the target
  gear speed along a reference trajectory whose slope comes from the shift-time
  map, and correct SPC from the slip error. The `CRS` PID already exists; the
  change is to make the reference explicit and mode-dependent (Comfort: longer,
  S-shaped; Agility: shorter, straighter) and to score it with `ShiftQuality`.
- **Engine torque reduction timed to the inertia phase.** Begin the reduction
  slightly *before* the expected inertia phase and ramp it, rather than a step
  (US 7762925, US 8032288). EGS51 exposes one magnitude only, so the shape has
  to be produced by the TCU. The 2-3/3-4/4-5 SPC ceiling means this is the only
  lever on high-torque upshifts (TRANSMISSION_NOTES §2), and the current 39 m/s³
  jerk is where it shows.
- **Pressure/duration adaptation stays gated to low torque**, as the EGS
  intended, but extend the gate to include *closed-throttle downshifts*, which
  the GM patent uses precisely because they are frequent and clean. That turns
  "2 of 39" into most coast-downs.
- **Pin the torque scale.** Let the user enter vehicle mass; fix `θ₁` and solve
  the RLS for the ECM torque scale instead (`scripts/road_load.py --mass`
  already does it offline). Feed that scale into `PressureManager`. This is a
  single constant that currently makes every clutch pressure ~30 % high, and it
  is the cheapest quality improvement on the list.

### Layer 3 — bounded learning

Only after Layers 0-2, and only for per-driver drift:

- **Per-cell shift-point adaptation from landing rpm** (dense: 105 labels per
  drive against 6 hunting events). Update the cell only when driver type is low,
  grade is near zero, not cornering, ATF warm, and the shift was not forced by a
  recogniser. Clamp each cell to ±N rpm of the calculated default, decay towards
  the default slowly, and expose a reset.
- Hunting events act as a strong occasional confirmation, not the primary
  signal.
- `ShiftQuality` is the reward for execution adaptation, per mode: Comfort
  minimises jerk under a duration cap, Agility minimises response under a jerk
  cap. Never collapse it to one number.

### Layer 4 — torque converter

Keep the current slip/lock state machine, but key it to the same recognisers:
**stay locked** through grade braking and downhill hold - the retarding torque
is the point of both recognisers, and an open converter throws most of it away
as fluid shear (heat into the ATF, on the one occasion a long descent is already
heating it). Unlock there only for the reasons that have nothing to do with
braking: approaching stall as the car comes to rest, or lugging NVH, which a
slip target handles better than a full open. Note that a grade-braking downshift
has the pedal released, so it takes the coasting branch in
`torque_converter.cpp` and `unlock_coasting_downshifts` (default false) would
open the converter on exactly the shift that is meant to slow the car.
Otherwise: lock earlier under a gentle long-term driver type, and never adapt
the TCC maps inside a corner or during fast-off.

---

## User-facing parameters

The goal is that a user describes *their driving*, not a map.

| knob | what it does | default source |
|---|---|---|
| boost threshold, economy rpm, redline | envelope for Layer 0 | owner (2400 / 2000 / 4500 on this car) |
| relative torque curve (5-7 points) | Layer 0 and the next-gear check | drive logs |
| vehicle mass | pins the ECM torque scale | owner |
| power reserve, economy and sport values | schedule aggressiveness at each end of the blend | generated |
| sportiness bias and decay time | driver-type blend, long-term memory rate | 25 s decay today |
| grade sensitivity | how far terrain moves the schedule; downhill hold strength | medium |
| grade braking on/off and threshold | one downshift when braking on a descent | on, 4 % |
| corner hold on/off and thresholds | rear wheel differential S1/S2 | on |
| fast-off hold time | how long a lifted gear is kept | 2-4 s |
| comfort and agility targets | jerk / response / duration caps for Layer 2 | `TARGETS` in `scripts/shift_quality.py` |
| adaptation: enable, rate, clamp, reset | Layer 3 bounds | on, ±150 rpm |
| TCC aggressiveness | lock earlier or later | current maps |

Everything else (maps, offsets) stays editable for people who want it, but is
generated from the knobs and re-generated when a knob changes.

---

## What must be told to the TCU, and what it can work out

The useful split is not "easy vs hard", it is **identifiability**: a quantity can
be learned if the car's ordinary motion excites it *and* it is not degenerate
with something else the TCU also does not know. Everything below is judged on
that, and measured where a measurement was available.

### Must be told - no signal can reveal it

| parameter | why not learnable |
|---|---|
| **wheel circumference** | nothing can learn it - it is the only absolute length in the system and the ABS sends wheel *rotation*, not road speed. But see below: it needs to be supplied, not to be accurate. |
| **redline** | a limit, not a measurement. The experiment that identifies it destroys the engine. |
| **vehicle mass _or_ engine torque scale - pick one** | the central result of [road-load-estimation.md](road-load-estimation.md). The estimator identifies `1/M` against the ECM's reported torque, so it can only ever know the *ratio*. Supplying either one pins the other. Supplying neither leaves both floating together, which is exactly what "mass estimates are torque estimates" means. |
| **gearbox / EGS variant** | identity. The calibration blocks follow from the part number. |
| **safety limits** (ATF temp, max pressure) | consequences are one-sided; a limit must not be discovered. |
| **preference** (comfort vs sport, how firm) | not a fact about the car. |

That is a five-line setup, and everything below follows from it.

### Supplied but barely used: wheel circumference

Worth separating from the rest of that table, because "cannot be learned" is not
the same as "matters". On EGS51 it reaches only two live consumers - the road
load estimator and the jerk figure in the shift trace. (The shifter's speed
calculation is fed from the front wheels, which EGS51 does not provide, so it
sits at zero; the HFM path belongs to another CAN variant.)

**In the estimator it cancels.** Both terms scale with it in the fit and unscale
in the prediction: the torque term goes as `1/circ` through `r_g` and `circ²`
through `theta1`, the grade term as `circ` through `theta2`, and the conversion
back to output rpm/s divides by `circ` again. Measured by deliberately getting
it wrong over 91 upshifts:

| circumference | prediction bias | mean abs error | correlation |
|---|---|---|---|
| 1.975 m (correct) | 7.5 | 50.7 | 0.62 |
| 2.074 m (+5 %) | 7.9 | 50.8 | 0.62 |
| 1.876 m (−5 %) | 6.8 | 50.2 | 0.63 |

A 5 % tyre error moves the answer by 0.5 rpm/s against a 20 rpm/s threshold and
51 rpm/s of scatter. It does not matter.

**What does not cancel** is anything expressed in SI against an outside number:
the 4 m/s gate deciding when the estimator runs, the 700–4000 kg clamps, the
jerk targets of 12 and 30 m/s³ taken from the literature, and any figure a human
reads. Those are the only reasons to get it roughly right.

### The pattern behind all of this

**This TCU is a ratio machine.** Speeds are compared with speeds, torques with
torques from the same source, pressures come from constants fitted against those
same torques. Every absolute physical quantity reached for so far - the engine
torque scale, the vehicle mass, the wheel circumference - has turned out to
cancel at the point of use, and the two that were built as settings were removed
or demoted once measured.

The design rule that follows is worth applying deliberately: **state thresholds
in the units the TCU natively measures** - rpm, rpm/s, mBar - and no calibration
constant is required at all. The next-gear check has its floor in output rpm/s,
which is exactly why a 5 % tyre error cannot touch it. The jerk metric is stated
in m/s³ against published targets, which is exactly why it is the one place
circumference bites. Reach for SI only where something outside the TCU has to
understand the number.

### Learnable now, with evidence

| parameter | how | measured |
|---|---|---|
| **final drive ratio** | `output_rpm / mean(rear wheel rpm)`; the ABS already sends both rear wheels on EGS51 | **3.068 / 3.069 / 3.069 against a configured 3.070 - 0.1 %**, over three drives, ~10 k samples each. Independent of tyre size, because the ABS reports rotation. Worth learning not to save typing but to *catch a wrong entry*. |
| **gear ratios** | `input_rpm / output_rpm` per gear with the converter locked | already computed every cycle; the TCU only uses it to detect mismatch |
| **road grade** | RLS, already running | robust because it is identified from how the *same* torque gives different acceleration, so the torque error cancels |
| **rolling resistance** | the persistent offset in the grade estimate over a closed loop - real grade averages to zero over a round trip, rolling resistance does not | mu = 0.021 already explains the standing +1.2 deg on the flat |
| **effective mass / torque scale** (as one number) | RLS, already running | the combination is identified; the split is not |
| **clutch fill time and volume** | turbine departure timing per shift | the existing adaptation does a gated version; US 6915890 / 7374513 do it properly |
| **driver type** | `agility_score`, already running | distribution measured over five drives |
| **cornering thresholds** | left/right rear wheel difference | straight-line median **0.17-0.33 %**, p95 **3.1 %** - S1/S2 fall straight out of that spread |
| **relative torque curve** | acceleration vs rpm at high pedal | derived in [findings-from-our-data.md](findings-from-our-data.md); note the next-gear check measured that it does *not* need one |

### Learnable in principle, but should not be

- **Friction coefficients.** Degenerate with the engine torque scale - clutch
  pressure is `torque x scale x friction / coefficient`, so only the product is
  identifiable. Learn one, set the other, never tune both against one symptom.
- **CdA.** Would need clean neutral coastdowns, which do not occur in normal
  driving, and it is degenerate with mass in the estimator anyway. Sensitivity
  is low - set it and move on.
- **Shift points.** Learnable from landing-rpm error, but "do not learn what you
  can calculate": the defaults were wrong once and one edit fixed what learning
  would have crawled towards over weeks. Adaptation is for per-driver drift.
- **Boost threshold.** Inferrable as the knee in the learned torque curve, but
  the owner knows it, and it gates calibration decisions that want a stable
  number rather than one that moves as the engine ages.

## Order of work, one variable per drive

1. ~~**Pin the torque scale** from vehicle mass and feed it to
   `PressureManager`.~~ **Tried and removed - it was the wrong shape of answer.**
   Clutch pressure is deliberately generous, because a clutch that slips under
   load is destroyed while one that is over-clamped is merely harsh, and the
   margin is already explicit in the calibration (`release_spring_pressure` +
   `extra_p_not_shifting`). An open-loop scale factor eats a margin somebody
   chose, using a number that is measured at the road and so includes gearbox
   and final-drive losses *downstream of the clutch*, anchored on a mass that
   changes every time somebody gets in the car.
   **Replace it with a closed loop** (below), which is what the margin is
   waiting for.

1b. **Trim shift pressure against measured slip and shift quality.**
   **Built 2026-09-07 as `ADP quality_adapt`, off by default, not yet driven.**
   Replayed against the 12:20 drive with `scripts/quality_adapt_sim.py`: 34 of
   52 shifts pass the gates with the pedal as the agility stand-in; every 1-2
   reads as a flare and walks its cell up 40 mBar a shift; 4-5 and 4-3 walk
   down 10 mBar a shift because nothing on that drive is under the 12 m/s^3
   comfort target, so with that target the loop's equilibrium is the clamp.
   Set the jerk target near the drive's better shifts first (about 25 m/s^3)
   so it discriminates, then lower it as the calibration improves.
   The signals were already there and unused: `ShiftQuality.peak_jerk` and
   `slip_energy_j` per shift, plus the existing flare flag, plus ratio deviation
   which measures slip directly. Adapt the SPC offset per shift index in the
   maps `ShiftAdaptationSystem` already carries.
   - **Asymmetric, in the safe direction**: lower a little when a shift is
     clean and harsh, raise a lot and at once on any flare or excess slip.
   - **Bound it with the slip energy budget** rather than a pressure limit -
     that is the quantity that actually wears the plates (measured: 5.8 kJ
     median per shift, 480 kJ over 52).
   - **It has to run at real torque.** Adaptation is gated so tightly today
     that 37 of 39 shifts cancelled, which is why base calibration is what the
     car gets. Widening that gate is the change, and it is the one that needs a
     drive to trust.
   - Note the ceiling from TRANSMISSION_NOTES section 2: on 2-3, 3-4 and 4-5
     the applying clutch cannot be fed above ~7100 mBar, so "raise on slip" runs
     out on high-torque shifts and torque reduction is the only lever left.
2. **Fill adaptation from turbine timing on all shifts.** Partly covered by
   1b: `quality_adapt` moves the prefill cell one cycle a shift on measured
   `response_ms`, on all shifts that pass the gates, and stands the built-in
   fill adaptation down while it is on. Verify: median `response_ms` falls
   from 500 towards the Agility target.
3. **Layer 0 map generation** with a power-reserve knob, checked by
   `shift_envelope.py`, flashed with an NVS key bump. Verify: landing-rpm
   distribution, hunting count.
4. ~~**Next-gear acceleration check** consuming the RLS state.~~ **Built, off
   by default, not driven.** Enable `SBS en_next_gear_check` for one drive.
   Verify: the 4-5 and 3-4 bogging cases disappear; no lost upshifts on the
   flat; check the veto log lines against where it actually felt wrong.
5. **Grade consumption**: terrain interpolation, downhill hold, grade braking.
   Verify against a known hill (still open in findings-from-our-data.md).
6. **Cornering hold, fast-off, pedal stabilisation**, one at a time.
7. **Continuous driver-type blend** replacing the profile swap. **Built
   2026-09-07 as `SBS agility_blend` (1 = shift time, 2 = time and points),
   off by default, not yet driven.** `SBS ab_interleave` alternates it shift
   by shift so the comparison comes from one drive.
8. **Torque-reduction shaping** in the inertia phase.
9. **Bounded landing-rpm adaptation**, last.

Each step has a measurement in the existing trace, and each is a knob a user
can turn off. Nothing above needs hardware.

---

## What was considered and rejected

- **Fuzzy shift schedule (SAE 930674 style).** The value in that paper is the
  running-resistance input, not the fuzzy inference. A calculated schedule plus
  the terrain axis captures it with parameters that mean something.
- **Neural / reinforcement-learning schedule on the TCU** (Peng 2022; the
  2022-2025 DRL gearshift papers). Trained in simulation with a plant model we
  do not have; unverifiable on one worn car; no safe bound on what it learns.
  Use DP offline for map generation if anything.
- **A driver "bad shift" button.** Attribution problem; see
  driver-type-adaptation.md. A coarse mode/reset switch is fine.
- **Batch least-squares from full-throttle data** for anything. Unidentifiable.

---

## Sources added in this pass

Patents (USPTO full text via Google Patents):
- US 6098004 — preventing gear hunting via required upshift acceleration (GM)
- US 5669850 — shift hunting prevention from next-gear torque capability (Ford)
- US 6571162 — cornering detection from left/right wheel speed difference, upshift inhibit with S1/S2 thresholds per shift map
- US 6527672 — FastOff detection from pedal gradient, grade-dependent hold, traction-line release (Bosch)
- US 8133154 — accelerator-pedal-based shift point stabilisation, pedal-rate thresholds vs time since last shift (Ford)
- US 9676388 — grade logic braking: downgrade + brake + accelerating ⇒ downshift, 3 s release
- US 7374513 — adaptive control of closed-throttle downshifts from turbine timing (GM)
- US 6915890 — learning oncoming clutch fill level and volume, counter-gated gains
- US 7762925 / US 8032288 — engine torque reduction begun before and ramped into the inertia phase
- US 7505842 — Porsche method for configuring transmission control (DSP programs: fast-off, uphill, downhill)

Papers:
- Ngo, Hofman, Steinbuch, Serrarens, *Optimal gear shift strategies for fuel economy and driveability*, IMechE Part D 2013 — constant / variable power reserve; DP for schedule generation
- *The Horsepower Reserve Formulation of Driveability* (CVT, but the reserve definition is what is used)
- Miao, Liu, Zhu 2018 — three-parameter schedule with terrain coefficient
- *Inertia Phase Control of the Clutch-to-Clutch Shift Process* (Springer) and *Robust control and estimation of clutch-to-clutch shifts* (Control Eng. Practice 2018) — slip-trajectory tracking
- Adaptive control of the shifting process in automatic transmissions, IJAT 2017 — torque-phase slip band, inertia-phase duration band
- DRL for gearshift controllers (Array 2022) and the 2024-25 tractor/heavy-truck RL papers — surveyed, not adopted

Trade press: Gears Magazine (ZF 8HP driver-type gating), Transmission Digest
(722.6 strategy: continual adaptation on speed, throttle and throttle rate;
curve recognition from wheel speeds that "lives for the moment").
