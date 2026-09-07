# What our own logs measured

Numbers from five drives (~28 minutes, 162 shift events) on the W210 diesel,
September 2026. Kept because they are expensive to re-derive and several of them
contradict the obvious assumption.

Reproduce with `scripts/shift_quality.py`, `scripts/road_load.py`,
`scripts/shift_envelope.py`.

---

## Engine

Power curve derived from acceleration, speed and gear at >75 % pedal across four
drives with a **nominal** mass — relative power, since only the shape matters for
choosing shift points:

| turbine rpm | % of peak |
|---|---|
| 2000–2250 | 65 % |
| 2250–2500 | 76 % |
| 2500–3000 | 80–82 % |
| 3000–3250 | 85 % |
| **3250–3750** | **100 %** |
| 3750–4250 | 87–96 % |

Confirms the owner's stated ~2400 rpm boost threshold from the car's own data,
and puts peak power at 3250–3750. About 140 hp at nominal mass, consistent with
an E300 TD after converter and driveline losses.

**Assuming a nominal mass is the trick.** A batch fit trying to solve for mass
*and* road load from full-throttle-in-gear data is unidentifiable — `a` and `v`
are collinear — and returns nonsense (we got 202 kg). See
[road-load-estimation.md](road-load-estimation.md).

## Driveline

| | |
|---|---|
| ratios (from the TCU's calibration block) | 1st 3.932 · 2nd 2.408 · 3rd 1.486 · 4th 1.000 · 5th 0.830 |
| final drive / wheel circumference | 3.070 / 1.975 m |
| redline (diesel) | 4500 |
| engine drag torque | 53.5 Nm |
| input shaft inertia (fitted) | ~0.16 kg·m² |
| ECM torque actually delivered | **~70–78 %** of mapped |

Read the ratios from the log's calibration block, never hardcode — doing so
corrected two ratios this repo had been carrying from memory.

## Shift quality (12:20 drive, 52 shifts)

| | median |
|---|---|
| response | 500 ms (540 on upshifts) |
| duration | 1041 ms |
| peak jerk | **39.3 m/s³** (comfortable is usually <10) |
| torque hole | 66 rpm/s |
| settle oscillations | 0 |
| slip energy | 5.8 kJ (8.1 upshifts, 0.2 downshifts) |
| total clutch energy | 480 kJ over 52 shifts |

## Timing

| | |
|---|---|
| `controller_loop` / shift algorithm step | **20 ms** (50 Hz) |
| polled logging, 9 records | **52.5 ms** (19.0 Hz), identical in all logs |
| cost per polled record | 5.83 ms — 2.0 ms diag loop, 0.57 ms wire, 3.26 ms USB/host |
| control loop measured from its own clock | 18–21 ms, no overrun |
| inertia phase of a shift | 100–200 ms |

**Polling at 19 Hz against a 20 ms source captured 1 update in 2.6 — 62 % never
left the TCU**, and which ones survived drifted arbitrarily against the shift.
That is aliasing, not coarseness, and it is why a fitted plant model failed
held-out at 161 rpm RMSE with durations wrong by 3–10×.

Only 10 % of a polling cycle is data transfer; the rest is per-request latency.
So batching records into one request, not trimming the record set, is the
structural fix for polled rate.

---

## Traps that cost real time

**Jerk from polled data is half the truth.** 19.8 m/s³ against 39.3 from a 50 Hz
trace over the same 51 shifts.

**Slip energy must be gated on clutch engagement.** Integrating through bleed and
fill — where slip is largest and the plates are not touching — inflated a gentle
3→4 to 30 kJ.

**Mass estimates are torque estimates.** Scaling the torque input 0.7→1.1 moved
mass 1808→2805 kg while grade moved only +1.02→+1.25°.

**Shifts are serialised.** The profile is only consulted when not already
shifting, so a downshift ladder chains and a threshold that cannot be reached in
time is not the threshold you calibrated. A 4→3→2→1 at 2000 ms each takes longer
than the car takes to stop, so the 2→1 completes at standstill.

**Maps live in NVS.** Editing a `maps.cpp` default does nothing on a TCU that has
booted; the key name has to be bumped. Verify by reading the map back over KWP,
not from a boot log line.

**`input_rpm` is turbine speed** and never reaches zero at a standstill in gear —
the converter drags it to 100–300 rpm.

**Analysis-script bugs that produced wrong answers:** treating a missing field as
`0` (a dropped read decodes as `None`, and `None → 0` fakes a standstill);
hardcoding a log path so a "new" trace silently showed an old drive; a map-parser
regex that matched nothing and therefore passed every calibration, including ones
known to be broken.

---

## Learning signals, measured

| signal | density |
|---|---|
| explicit hunting (upshift → throttle → downshift) | **6 in 105 upshifts** |
| landing rpm outside the target band | **17 % lug, 20 % high, of 105** |
| agility score in the mid range (20–79) | **41.8 % of driving** |

The obvious signal is the sparse one. See
[driver-type-adaptation.md](driver-type-adaptation.md).

---

## Open items

- Shift quality is measured on the TCU but nothing consumes it.
- Road load is estimated but not fed to the shift schedule; needs checking
  against a known hill.
- The ECM torque scale (~70–78 %) is unpinned without ground truth, and
  `PressureManager` sizes clutch pressure from that torque — so the box may be
  systematically over-pressurising every shift. The adaptation meant to correct
  it is gated to low torque and ran on 2 shifts out of 39.
- Comfort and Standard shift maps still carry warnings that cannot be fixed in
  the maps alone: at 80–90 % pedal, reaching the boost point and avoiding hunting
  are mathematically incompatible with these ratios.
