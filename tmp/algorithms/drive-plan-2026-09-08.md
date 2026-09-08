# Drive plan, 2026-09-08

Goal: drive with the agility blend and the quality adaptation live, come back
with data that says whether each works, and adjust settings rather than code.

Everything below is a setting. All of it defaults to yesterday's behaviour, so
the flash itself changes nothing until a setting is turned on over KWP from the
config app (SBS = shift basic, ADP = adaptation). Settings written over KWP
take effect at once and persist.

## Before leaving

1. Flash (`.venv/bin/pio run -e unified -t upload`), then a boot check:
   `logger/nag52log.py --reset -o logger/logs/boot.jsonl -q`, grep for
   `Guru`/`panic`. The logger must report the trace as ready, with version 2;
   a version mismatch means the logger and firmware are out of step.
2. Read SBS and ADP back from the config app and confirm the new fields are
   present: SBS is 16 bytes / 15 params, ADP 51 bytes / 35 params.
3. Run the logger for the whole drive. The live dashboard now shows per shift:
   arm, blend %, target time and what the adaptation did.

## What to enable, and in what order

The stamp lets these run together. Each is judged on a different signal, and
each can be turned off again at the roadside without a reflash.

### Leg 1: baseline, 10 minutes

Nothing enabled. Warm the ATF above 60 C (the adaptation gate). This gives a
same-day, same-road baseline for the quality vectors, on the calibration the
car has now.

### Leg 2: blend, interleaved

Set `SBS agility_blend = 1` and `SBS ab_interleave = true`. Drive normally
with Comfort selected, including some deliberate part-throttle stabs (score 30
to 70). Every other shift now runs with the blended target time; the trace
stamps each with arm A or B and the blend weight.

What answers it: per shift type, compare median `response_ms`, `duration_ms`
and `peak_jerk` between arms A and B at similar blend weights. Expect arm A
to shorten duration at mid scores and feel more consistent between a gentle
and a firm stab. If arm A is worse on jerk without being faster, raise
`agility_blend_lo` (start the blend later) rather than turning it off.

Optional, if leg 2 feels right: set `agility_blend = 2` for the rest of the
drive, no interleave (schedule changes cannot be interleaved). Judged on
landing rpm and hunting count, not on the quality vector.

### Leg 3: quality adaptation, 15 minutes or more

Set `SBS ab_interleave = false` (the learner must not see alternating shifts)
and `ADP quality_adapt = true`. Before that, set
`ADP quality_jerk_target_mms3 = 25000`. The published 12 m/s^3 comfort target
is far below anything this calibration produces (median 39 on the 12:20
drive), and with it the rule would cut every owning cell by 10 mBar a shift
until the 200 mBar clamp. At 25 it only trims the harsher half.

What to watch on the dashboard, per shift: the reason column. Expected on
this car, from the replay of the 12:20 drive:

| what | expect | if not |
|---|---|---|
| 1-2 | `flare`, +40 mBar and +2 prefill cycles each, for the first few, then stops flaring | if it never stops, the flare detector or the cell is not reaching the clutch; stop and read the log |
| 4-5, 4-3 | `harsh`, -10 mBar a shift, slowly | if a cell walks to -200 in one leg, raise the jerk target |
| coast 3-2, 5-4, 2-1 | fill time only (shared SPC cell), `slow response` +1 cycle | |
| stabs | `agility score too high`, no change | that is the gate working |
| 3-4 at 50 %+ pedal | `slip energy over budget`, +40 mBar | if it fires on gentle 3-4s, raise `quality_slip_budget_j` |

Stop condition: any shift that flares *after* its cell has been raised twice,
or a cell reaching its clamp. Neither is dangerous (the clamp is 200 mBar,
the prefill clamp 10 cycles), but it means a step or a target is wrong and
more driving will not fix it.

### Leg 4: downshift anti-clunk guard

`SBS downshift_min_end_rpm = 0`. This is the fix for the coast-down clunk you
felt on the 07:01 drive. It projects the output speed to the end of a downshift
and holds the shift if the car will have stopped by then, so the last rung of
the ladder happens at a true standstill instead of landing on the stop.

Replayed over that drive with `scripts/downshift_ladder.py` it holds the one
clunking 2-1 (jerk 50.9 m/s^3, projected end -48 rpm) and holds nothing else:
the five clean 2-1s project to +53 rpm or above.

What answers it: come to a stop several times, gently and hard. The clunk should
be gone, and the log should show 2-1 shifts starting at output speed zero with a
jerk near zero, which is what the standstill shift measures. The TCU logs a line
whenever it holds one. If a clunk survives, raise the floor to 50 and re-run the
script on the new log to see whether that case was predictable.

Expected side effect: the car will more often be in 2nd when it stops, and take
1st at a standstill. If a launch ever feels like it starts in the wrong gear,
that is this, and the floor is the knob.

### Leg 5: next-gear veto (optional, if there is time)

`SBS next_gear_min_accel_mms2 = 214`. Measured but never driven. Judged on
whether the 3-4 and 4-5 bog cases disappear and no upshift is lost on the
flat. The stamp records `next_gear` enabled; the veto itself logs a line.

## After the drive

```
scripts/shift_quality.py logger/logs/<log>.jsonl        # per-shift vectors, both sources
scripts/quality_adapt_sim.py logger/logs/<log>.jsonl --agility-from log
                                                        # replay the rule on what was driven
```

The second command reproduces the adaptation decisions from the log, so a
different step or target can be tried on the same drive before the next one.
Compare arms with a few lines of Python on `LogFile.shift_traces`, splitting
on `stamp["arm"]` (see logger/README.md).

Then read the adaptation maps back from the config app: they are what the
learner actually left in NVS, and the trace stamps say how they got there.

## Settings reference for the day

| setting | default | leg |
|---|---|---|
| SBS agility_blend | 0 | 2: 1, later 2 |
| SBS agility_blend_lo / hi | 20 / 80 | leave |
| SBS ab_interleave | false | 2: true, then false |
| ADP quality_adapt | false | 3: true |
| ADP quality_jerk_target_mms3 | 12000 | 3: 25000 |
| ADP quality_max_agility | 40 | leave; lower to 25 if stabs are still learned |
| ADP quality_slip_budget_j | 12000 | raise if gentle shifts breach it |
| ADP quality_spc_step_mbar / flare step | 10 / 40 | leave |
| ADP quality_prefill_step / flare step / max | 1 / 2 / 10 cycles | leave |
| ADP prefill_max_pressure_delta (SPC clamp) | 200 | leave |
| SBS downshift_min_end_rpm | off | 4: 0 |
| SBS next_gear_min_accel_mms2 | off | 5: 214 |

## Findings from the 2026-09-08 drives, and what changed after them

* **The jerk metric was measuring its own quantisation.** Differentiating an
  integer output speed twice over one 20 ms step has a floor of 29.7 m/s^3 on
  this car, and the 04:59 drive measured a median of 30.5 against it. Both
  derivatives now span 57 ms; the 07:01 drive measures a median of 9.3, which
  discriminates. Every jerk number from before that fix, including the 39 m/s^3
  in the notes, is a floor and not a measurement.
* **The agility score never decayed.** 4 points per second evaluated every
  100 ms truncated to zero, so it pegged at 100 after the first stab. Fixed.
* **The coast-down clunk is the ladder finishing after the car stops.** Leg 4.
* **The launch upshift is harsh for a different reason** and is still open: the
  1-2 is asked to take 541 ms and takes 1250 ms, the ratio does not move for the
  first 517 ms while the engine winds up 280 rpm, and the sync then pulls 900 rpm
  out of the input shaft in 425 ms for 25 kJ. The engine torque request arrives
  at the start of that sync rather than before it. Median 1-2 jerk is 13.3 m/s^3
  against 6.6 to 10.1 for every other upshift. The fix is torque reduction shaped
  into the inertia phase, plus prefill trimmed from the measured response.
* **Chained downshifts under power are a third, separate fault**, seen at 169 s
  and 178 s on the 04:59 drive: 5-4 then 4-3 at 2000 rpm output with the car
  accelerating, followed by an immediate upshift. The anti-clunk guard does not
  address that and should not - the car is not stopping. That is the next-gear
  veto and the pedal stabilisation, legs 5 and beyond.

## Flash state

The downshift guard is built and validated offline but NOT flashed: the TCU was
unplugged after the 07:01 drive. Plug it in and run

```sh
.venv/bin/pio run -e unified -t upload
logger/nag52log.py --reset -o logger/logs/boot.jsonl -q
```

then set `SBS downshift_min_end_rpm = 0` before leg 4.
