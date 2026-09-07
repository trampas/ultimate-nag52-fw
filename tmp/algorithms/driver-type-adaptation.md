# Driver type recognition and adaptive shift strategy

Implemented as `agility_score` in `src/gearbox.cpp`, exposed on RLI 0x32 and
stamped on every shift in the trace event.

---

## What production systems do

**Mercedes EGS** (the controller originally in this car) records driving style
over roughly **the last 40 shift points** and shifts earlier or later to match.
Drive it hard and it holds gears; drive gently and it shifts early. Worth knowing
because it sets the behaviour the driver already expects.

**ZF 8HP** uses fuzzy "driver type assessment" with an inertia sensor (G-sensor)
as the central input, evaluating engine torque demand and acceleration and
deceleration rates.

The line worth remembering, from the ZF material: during emergency management
program selection, driver type assessment data is **ignored**.

That is the gating principle, and it generalises: **suspend adaptation whenever
the objective changes.** Do not learn a comfort calibration from a shift the
driver explicitly asked to be sporty.

---

## Why a score and not a flag

Driver intent is not binary, and anything learning from a shift has to know how
hard the driver was pushing when it happened — otherwise it adapts the comfort
calibration towards an objective the driver wanted for ten seconds.

Measured over five drives with our score implementation, the distribution is
**not** bimodal:

```
  0-  9   35.7%
 10- 19    8.0%
 20- 29    7.1%
 ...
 90- 99    7.8%
```

**41.8 % of driving sits in the middle of the range (20–79)** — where an
interpolated shift map would give something neither endpoint does. A binary
switch snaps all of that to one map or the other, and on our maps that is a
discontinuity of up to **491 rpm** on the 1→2 at 10 % pedal.

---

## The score

0–100, **rising immediately and decaying over ~25 s**. Asymmetric on purpose: a
driver who asks for performance should get it on the same pedal application, and
should not lose it because they lifted for a moment mid-overtake.

Instantaneous demand, strongest input first:

| input | rationale |
|---|---|
| **pedal rate** — a quarter of travel inside 500 ms | the strongest single indicator; a deliberate request even if the pedal never approaches the floor |
| pedal position | sustained demand |
| kickdown | goes straight to 100 |
| hard braking | someone braking hard for a corner usually wants the gear on the way out |

```
demand = max(rate_term, position_term, brake_term)      # kickdown → 100
score  = demand                    if demand > score    # rise at once
       = score − decay_rate·dt     otherwise            # fall slowly
```

**A pre-existing slow filter is not a substitute.** Our `pedal_delta` tracker is
a first-order filter over 25 samples at 100 ms — a 2.5 s time constant, which
smooths a stab away entirely. A short rolling *minimum* of pedal position over
500 ms detects the same event immediately.

Consume with **hysteresis** (engage 60, release 25) so a score hovering at the
threshold cannot chatter the profile back and forth.

---

## Where the learning signal comes from

Two candidates, and the obvious one is the weaker.

**Explicit hunting** — upshift, driver adds throttle, downshift back within a few
seconds. Self-labelling, needs no driver input, and intuitively the right signal.
Measured across five drives: **6 events in 105 upshifts** (4–12 % per drive,
median 4.2 s to the corrective downshift, all 4→5 and 3→4). Real, but at ~1 event
per drive against 44 map cells a learner keyed on it alone would take months.

**Landing rpm** — where the engine ends up after every upshift, against a target
band. Dense: 105 labelled events instead of 6. Ours showed 17 % landing below
1200 rpm.

So use landing error as the primary signal and treat hunting as a strong
occasional confirmation, not the other way round.

**And do not learn what you can calculate.** The defaults were wrong; one edit
fixed what learning would have taken weeks to crawl towards. Adaptation is for
per-driver drift and for what cannot be computed, not for escaping a bad starting
point.

---

## Suggested layering

1. **Fix the defaults by calculation** against a known envelope (boost threshold,
   economy rpm, redline, ratios). Cheapest and largest effect.
2. **Driver type as a continuous score**, gating everything below.
3. **Running resistance / grade estimation** — the documented anti-hunt input,
   and dense. See [road-load-estimation.md](road-load-estimation.md).
4. **Per-cell adaptation** from landing-rpm error, gated on low driver-type
   score, no significant grade, and ATF warm.

The pieces for 1–3 exist. Step 4 needs a validated shift-quality reward signal
first, otherwise it optimises against something it cannot measure.

---

## On driver-feedback buttons

A "that shift was bad" switch is tempting and the prior art does not use one.
The reason is **attribution**: by the time the button is pressed, which shift is
being rated, and the label arrives seconds late. The inferred signals give
thousands of labels a drive against a handful of presses.

Where a physical switch does earn its place is coarser: pinning the driver type,
forcing learning on or off, or marking "start a fresh adaptation" after a change.
Those avoid the attribution problem entirely.
