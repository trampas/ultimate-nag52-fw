# Transmission control algorithms — research notes

Collected while debugging shift quality on a 1999 W210 diesel running
Ultimate-NAG52 firmware (722.6 / 5G-Tronic, EGS51), September 2026.

The point of these notes: almost everything we needed had already been solved and
published. Several days went into re-deriving things that exist in SAE papers from
the 1990s. Read the references before inventing.

| file | contents |
|---|---|
| [references.md](references.md) | annotated bibliography, what each source actually gives you |
| [road-load-estimation.md](road-load-estimation.md) | RLS mass + road grade estimation, full maths |
| [shift-quality-metrics.md](shift-quality-metrics.md) | how the industry measures a shift |
| [driver-type-adaptation.md](driver-type-adaptation.md) | driving style recognition and adaptive shift strategy |
| [findings-from-our-data.md](findings-from-our-data.md) | what our own logs measured, and the traps |

## The four ideas worth knowing

1. **Road grade / running resistance estimation is the standard anti-hunt input**
   to a shift schedule (SAE 930674). A TCU without it shifts too often and runs
   out of pull on a climb. It also becomes the third axis of a shift map, turning
   a 2D (pedal, speed) table into a 3D (pedal, speed, terrain) one.

2. **Jerk is the shift quality metric** that correlates with subjective feel
   (SAE 650465), but it is not a score on its own — a shift can always be made
   smooth by making it long, so spontaneity has to be reported with it
   (SAE 911938). And quality is not mode-independent: Comfort and Agility trade
   jerk against response time in opposite directions.

3. **Driver type assessment gates adaptation.** ZF ignores driver-type data
   during special programs; the same logic says do not learn a comfort
   calibration from a shift the driver asked to be sporty. Mercedes EGS adapts
   over roughly the last 40 shift points.

4. **Most of the constants come out relative, not absolute.** Engine torque from
   the ECM is a factory map, not what a worn engine delivers; clutch friction
   drifts with wear. The published methods survive this because the quantities
   that matter — terrain coefficient, driver type, relative shift quality — are
   identified from *ratios and changes*, not from absolute SI values. Do not
   spend effort chasing absolute accuracy you do not need.

## Status in the firmware

Implemented and exposed, not yet consumed by any control decision:

- road load / grade estimator (`src/road_load.cpp`)
- shift quality vector per shift (`src/shift_trace.h`, `ShiftQuality`)
- driver agility score (`src/gearbox.cpp`, `agility_score`)
- 50 Hz shift recorder that everything above is measured from

Offline equivalents live in the repo's `scripts/` so the two can be
cross-checked: `road_load.py`, `shift_quality.py`, `shift_envelope.py`.

These notes cover the general algorithms and the literature. The
vehicle-specific facts about this gearbox — hydraulics, ratios, the NVS gotcha —
are in `TRANSMISSION_NOTES.md` at the repo root, and the process lessons are in
`CLAUDE.md`.
