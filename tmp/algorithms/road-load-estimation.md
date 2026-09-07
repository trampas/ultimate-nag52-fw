# Road load: online mass and grade estimation

Source: Vahidi, Stefanopoulou & Peng, *Recursive Least Squares with Forgetting
for Online Estimation of Vehicle Mass and Road Grade: Theory and Experiments*,
Vehicle System Dynamics 43:1.
PDF: <https://websites.umich.edu/~annastef/papers_Long_ctrl/JournalPaperMassGrade_Final.pdf>

Implemented in `src/road_load.cpp` (firmware) and `scripts/road_load.py`
(offline, and the reference the firmware was ported from).

---

## Why a transmission controller wants this

- **Anti-hunting.** SAE 930674 makes running-resistance estimation the standard
  input for stopping a shift schedule hunting.
- **Climb performance.** A TCU without it shifts too often and runs out of pull
  on a grade or under load.
- **Third map axis.** Miao/Liu/Zhu's three-parameter schedule adds a terrain
  coefficient to pedal and speed, turning a 2D table into a 3D surface.

---

## The model

Longitudinal dynamics, assuming no wheel slip and the driveline engaged:

```
M·v̇ = (T_e − J_e·ω̇)/r_g  −  F_fb  −  F_aero  −  F_grade
```

| term | |
|---|---|
| `M` | total vehicle mass |
| `v` | forward speed |
| `T_e` | engine torque at the flywheel (negative under compression braking) |
| `ω` | engine rotational speed; `J_e·ω̇` is torque spent accelerating the powertrain |
| `r_g = r_w / (g_d·g_f)` | wheel radius ÷ (gear ratio × final drive) |
| `F_fb` | friction (service) brake force at the wheels |
| `F_aero = ½·C_d·ρ·A·v²` | |
| `F_grade = M·g·(μ·cos β + sin β)` | combined grade (β) and rolling resistance (μ) |

Rearranged so mass and grade separate:

```
v̇ = ( (T_e − J_e·ω̇)/r_g − F_fb − F_aero )·(1/M)  −  (g / cos β_μ)·sin(β + β_μ)
```

where `tan(β_μ) = μ`. In linear parametric form:

```
y = φᵀθ

θ = [ θ₁ , θ₂ ]ᵀ = [ 1/M , sin(β + β_μ) ]ᵀ        ← the unknowns
y  = v̇
φ₁ = (T_e − J_e·ω̇)/r_g − F_fb − F_aero
φ₂ = − g / cos(β_μ)                               ≈ −g for small μ
```

**θ₁ depends only on mass and is constant. θ₂ is time-varying.** That difference
is the entire reason the paper exists — a single forgetting factor cannot track
two parameters that change at different rates.

---

## The estimator

Recursive least squares with **one forgetting factor per parameter**:

```
Pφ    = P·φ
K     = Pφ / (1 + φᵀ·Pφ)
err   = y − φᵀ·θ
θ    += K·err
P    -= K·(Pφ)ᵀ
P₀₀  /= λ_mass          # ≈ 1.00  — mass does not change; never forget it
P₁₁  /= λ_grade         # ≈ 0.98  — grade changes with the road
```

Seed with a plausible car on a flat road (`θ = [1/1700, 0.013]`), `P` diagonal
with a small entry for mass and a larger one for grade, reflecting which you
expect to move.

Clamp `θ` to physical ranges each step and reset on a non-finite state — an RLS
that diverges will otherwise feed nonsense to whatever consumes it.

**Accuracy achieved in the paper:** mass within 5 %, grade tracked well,
*provided inputs are persistently exciting*.

---

## Adaptations for this car

| paper | here | why |
|---|---|---|
| flywheel torque, converter assumed locked | **turbine torque**, gear ratio excludes final drive | the TCU already models turbine torque, so no lockup assumption is needed |
| brake force modelled out of the data | brake samples **excluded** | `brake_pressed` is a boolean; there is no force model, exactly as the paper found |
| gear shifts flagged as a tracking difficulty | shifts **excluded** | same |
| — | excluded below ~4 m/s and under overrun | the model means little there |

Update rate 10 Hz. RLS does not need the control loop rate and it keeps the cost
negligible.

---

## What is trustworthy, and what is not

**This is the most important section.** The ECM reports torque from factory maps,
not what a worn engine actually delivers. On our 470k mile car that bias is
large, and it lands directly in `φ₁`.

Measured by scaling the torque input on one drive log:

| torque × | mass estimate | grade median | grade range |
|---|---|---|---|
| 0.70 | 1808 kg | +1.02° | −1.44…+3.19 |
| 0.80 | 2051 kg | +1.11° | −1.37…+3.21 |
| 1.00 | 2551 kg | +1.21° | −1.27…+3.24 |
| 1.10 | 2805 kg | +1.25° | −1.25…+3.25 |

- **Mass scales almost exactly with the torque error — it *is* the torque error.**
  Reported `mass_kg` is really a combined mass-and-torque-scale figure.
- **Grade barely moves.** It is identified from how the *same* torque produces
  different acceleration on different slopes, so the absolute value cancels.

So `terrain_coeff` is usable and `mass_kg` is not, unless you have ground truth.
The same asymmetry is why the published methods survive worn engines and worn
clutches at all: the quantities that matter are relative.

**Inverting it is useful.** Fix the mass at a known value and solve for the
torque scale instead: `scripts/road_load.py --mass 1800` gave 70 % of mapped
torque (78 % against an effective 1980 kg including rotating inertia). Driveline
losses account for maybe 10–15 % of that; the rest is wear and model error.

A persistent non-zero grade at rest on the flat is rolling resistance, not a
hill: `θ₂ = sin(β + β_μ)`, and μ = 0.021 fully explains a +1.2° reading.

---

## Checking the output is signal and not noise

Autocorrelation of the grade estimate over one drive:

```
lag  1 s : +0.98    persistent
lag  5 s : +0.61    persistent
lag 15 s : −0.05    decorrelated
lag 30 s : −0.08    decorrelated
```

White noise decorrelates immediately. A signal still correlated at several
seconds and gone by fifteen is varying on a road-feature timescale, which is what
grade should look like. Worth repeating this check after any change.

---

## Convergence and confidence

The estimate is only meaningful under **persistent excitation** — steady cruise
identifies nothing. Report a confidence based on how many usable samples have
been seen, so a consumer can tell a converged estimate from a seed value.

A batch least-squares fit over full-throttle-in-one-gear data will **not** work:
`a` and `v` are collinear there, the problem is unidentifiable, and it returns
nonsense (we got 202 kg). That failure is what sent us to the literature.
