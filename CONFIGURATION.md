# What this TCU is configured by

A map of every calibration surface in the firmware, and - the part that is not
obvious from reading it - **who is supposed to supply each one**. Written
2026-09 after a run of work in which three separate "essential" per-car
constants turned out, on measurement, to cancel at the point of use.

The headline: the surface looks enormous (56 NVS keys, 123 tunable settings, 44
maps) and the genuinely per-car set is about six numbers.

---

## The five layers

| layer | where it lives | who supplies it |
|---|---|---|
| 1. Board identity | eFuse, burnt at manufacture | the board |
| 2. Vehicle configuration | NVS `CORE_SCN` (19 fields) | installer, mostly identity |
| 3. Gearbox calibration | TCU flash, 4 named blocks | the gearbox part number |
| 4. Module settings | NVS, 9 blocks / 123 params | tuner |
| 5. Maps | NVS, 44 keys | tuner, and adaptation |

Plus one that is **not on the TCU at all**: the vehicle envelope in
`scripts/shift_envelope.py`, which exists only to judge maps offline.

---

## 1. Board identity - `TCM_EFUSE_CONFIG`

Board revision and manufacture date, burnt into eFuse. Read-only, not
configuration in any useful sense, but it selects solenoid current handling so
it is worth knowing it exists.

## 2. Vehicle configuration - `TCM_CORE_CONFIG`, NVS key `CORE_SCN`

Nineteen fields, and they are not the same kind of thing as each other:

**Identity - looked up, never tuned.** `engine_type`, `egs_can_type`,
`shifter_style`, `is_four_matic`, `transfer_case_high_ratio` /
`transfer_case_low_ratio`, `jeep_chrysler`, `deprecated_is_large_nag`.

**Board wiring.** `io_0_usage`, `input_sensor_pulses_per_rev`,
`output_pulse_width_per_kmh`, `gen_mosfet_purpose`.

**HFM petrol variant only.** `throttlevalve_maxopeningangle`, `c_eng`.

**Preference.** `default_profile`.

**Actually physical, and the interesting ones:**

| field | status |
|---|---|
| `red_line_rpm_diesel` / `_petrol` | **must be told.** A limit, not a measurement - the experiment that finds it destroys the engine. |
| `wheel_circumference` | **must be told, but need not be accurate.** See below. |
| `diff_ratio` | **could be learned.** `output_rpm / mean(rear wheel rpm)` recovered 3.068-3.069 against a configured 3.070 over three drives. Independent of tyre size, because the ABS reports rotation. Worth learning to *catch a wrong entry*, not to save typing. |
| `engine_drag_torque` | **redundant on EGS51**, where MS_310 carries `DRG_TORQUE` live and `can_egs51.cpp` already uses it. The static copy still sets the adaptation torque limits, so the two can disagree. |

### Why wheel circumference barely matters

It reaches two live consumers on EGS51: the road load estimator, and (until
recently) the jerk metric. The shifter's speed calculation is fed from front
wheels EGS51 does not provide, so it sits at zero.

**In the estimator it cancels**, because the fit and the prediction share it -
the torque term goes as `1/circ` through `r_g` and `circ²` through `theta1`,
and converting back to output rpm/s divides by `circ` again. Deliberately
getting it wrong over 91 upshifts:

| circumference | prediction bias | mean abs error | correlation |
|---|---|---|---|
| 1.975 m (correct) | 7.5 | 50.7 | 0.62 |
| +5 % | 7.9 | 50.8 | 0.62 |
| −5 % | 6.8 | 50.2 | 0.63 |

**The jerk metric does use it**, and should: entering a circumference is not a
burden, and reporting m/s³ keeps the number comparable with the published
thresholds (comfortable under ~10, objectionable over ~20-30) and with whatever
target a user sets. A wrong tyre entry costs about 1 % for a properly
plus-sized wheel and 8 % for a 20 inch wheel nobody would fit, against a metric
that already reads twice different between 19 Hz and 50 Hz sampling. The
conversion lives in one place, `mps_per_output_rpm()` in
`src/models/vehicle_geometry.h`, which falls back to an ordinary saloon rather
than returning zero - an unconfigured TCU reporting a jerk of 0 would look like
a perfect shift.

Also wants it roughly right: the 4 m/s gate on the estimator, the 700-4000 kg
clamps, and anything a human reads.

## 3. Gearbox calibration - `CalibrationInfo`, TCU flash

Four named blocks, matched to the EGS part number out of the config app's
`egs_db.bin`. *(This car: hydraulic STDP, mechanical 51, converter 71, shift
maps SM00, from PN 0205459132.)*

| block | holds |
|---|---|
| `mech_cal` | gear ratios, friction map, release spring pressures, strongest-loaded clutch per gear |
| `hydr_cal` | per-circuit SPC gains, working pressure multipliers, regulator spring, max pressure |
| `tcc_cal` | converter characteristics |
| `shift_algo_cal` | torque adder maps per shift |

Not tuned per car. Read it back from a log rather than hardcoding it - doing so
corrected two ratios this repo had been carrying from memory.

## 4. Module settings - 9 blocks, 123 parameters

| block | params | what it covers |
|---|---|---|
| TCC | 16 | lock-up per gear, adaptation, prefill, unlock-on-shift rules |
| SOL | 10 | solenoid current PID, per-board current offset, boot voltage |
| SBS | 11 | shift program basics, per-shift torque request enables, the next-gear check |
| PRM | 4 | pressure manager friction coefficients |
| ADP | 20 | adaptation windows: ATF temp, RPM, per-clutch and per-shift enables |
| ETS | 15 | shifter configuration and profile selection |
| REL | 14 | releasing-shift torque requests and SPC offsets |
| GAR | 5 | garage shift ramps by ATF temperature |
| CRS | 28 | crossover shift clutch inertia PID |

The schema is generated from `module_settings.h` at build time into
`MODULE_SETTINGS.yml`, zipped into `EMBED.ZIP`, embedded in the firmware image,
and **downloaded by the config app off the running TCU**. So the app never holds
a layout of its own and cannot be out of step - there is no version to match.

Settings may only ever be **appended**. `read_subsystem_settings` loads the
defaults and lets the stored blob overwrite what it reaches, so an older block
keeps its values and new fields take their defaults; reordering or removing a
field silently changes the meaning of bytes already in flash and nothing can
detect it. Proved by `tmp/settings_migration_check/check.sh`.

## 5. Maps - 44 NVS keys

- **Shift point maps** - up/down x {Standard, Comfort, Agility, Manual} x
  {diesel, petrol}. X = pedal, Y = gear, value = input shaft RPM.
- **Shift time maps** - up/down x 6 profiles. X = pedal, Y = % of redline.
- **Fill** - fill time, fill pressure, low fill pressure.
- **TCC** - PWM, slip target, and the adapted slip/lock maps.
- **Adaptation** - prefill time, SPC offset, applying and freeing torque offsets.

Maps are NVS-backed: editing a default in `maps.cpp` does nothing to a TCU that
has already booted, and the key name must be bumped (see TRANSMISSION_NOTES §5).
That is a *different* mechanism from the settings migration above, and the key
bump is still correct there.

## Not on the TCU: the vehicle envelope

`scripts/shift_envelope.py` carries boost threshold, economy RPM, redline and
the measured power band *(this car: 2400 / 2000 / 4500)*. It never reaches the
firmware; it exists so a calibration can be judged against what the engine can
do rather than against the last complaint. Ask the owner for these before
tuning anything.

---

## So what is actually per-car?

Strip out identity, board wiring, preference and anything measurable, and the
list a new installation genuinely needs a human for is:

1. **Wheel circumference** - roughly. Nothing can learn it; little depends on it.
2. **Redline** - exactly. A safety limit.
3. **Gearbox part number** - which selects layer 3 wholesale.
4. **Engine type, CAN type, shifter style** - identity.
5. **Board wiring** - what is connected to the general purpose IO.
6. **Either vehicle mass or the engine torque scale** - and only if something
   needs the split; the estimator identifies the *ratio* and most consumers want
   only that.

Everything else is either derivable, learnable, or a preference.

## The principles worth keeping

**1. Let the software work it out, and default to something that gets the car
home.** A parameter the firmware can measure should be measured - the final
drive ratio is recoverable from the ABS wheels to 0.1 %, and checking it catches
a wrong entry that would otherwise poison every speed silently. Where it cannot
be measured, the default should be a plausible car rather than a placeholder,
so an unconfigured TCU drives home badly instead of not at all, and so a derived
metric never comes out as a suspiciously perfect zero.

That is not yet true of everything. `diff_ratio` defaults to 1.000 and
`wheel_circumference` to 2850 mm, which are placeholders, not a car. The
argument for leaving them obviously wrong is that it forces the installer to
set them; the argument against is that nothing checks, so a wrong entry survives
just as silently. Worth deciding deliberately rather than by inheritance.

**2. State parameters in SI where it is reasonable.** A number a human sets or
reads should mean something outside this codebase: m/s³ can be checked against
published shift-quality work, mm/s² against intuition about how a car pulls.
Native units are the exception, taken only where the conversion would need a
constant nobody can supply - not where the constant is merely approximate.
Pressures stay in mBar because that is the language of the hydraulics.

**3. Do not invent a setting where there is no decision to make.** A parameter
is for a preference or a car-specific fact, not for an implementation constant
someone might get wrong. The anti-bog check shipped with three settings and
needs one: the enable was redundant with the threshold (a floor low enough never
fires, so `INT16_MIN` is the off switch), and the estimator-confidence gate has
one right answer and no preference to express, so it is a constant.

**4. Do not invent a setting for a quantity that cancels.** This TCU is largely
a ratio machine: speeds against speeds, torques against torques from the same
source, pressures from constants fitted against those same torques. The engine
torque scale was added and removed in a day because it was exactly degenerate
with the friction coefficients it sat beside. Before adding a physical constant,
check whether anything downstream can actually tell the difference. Wheel
circumference survives that test - not because it is precise, but because it is
cheap, available, and buys interpretability.
