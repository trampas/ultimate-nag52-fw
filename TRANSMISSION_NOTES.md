# 722.6 operation and physics — working notes

Background needed to reason about the shift code that is **not** derivable from reading it.
Written after a run of log-driven debugging where several wrong conclusions came from not
knowing the hydraulics. If you are about to change a shift algorithm, a pressure
calculation or a shift map, read this first.

Numbers below marked *(this car)* come from the EGS calibration block read out of the TCU
and stored in every log — do not hardcode them, read them back (see
[Reading the calibration](#reading-the-calibration)).

---

## 1. Mechanical layout

Six clutches — `K1 K2 K3 B1 B2 B3` (that index order is used throughout the calibration:
`release_spring_pressure[]`, `strongest_loaded_clutch_idx[]`, …).

Ratios *(this car, `mech_cal.ratio_table`, ×1000)*:

| gear | P/N | 1 | 2 | 3 | 4 | 5 | R1 | R2 |
|---|---|---|---|---|---|---|---|---|
| ratio | – | 3.932 | 2.408 | 1.486 | 1.000 | 0.830 | 3.100 | 1.899 |

`strongest_loaded_clutch_idx` *(this car)* = `[-, B2, K1, K2, K2, K2, B3, B3]` — i.e. the
clutch that sizes the line pressure requirement in each gear.
A shift is one clutch applying and one releasing; the algorithm calls them the **on clutch**
and the **off clutch** (`p_on` / `p_off` in the logs).

---

## 2. Hydraulics — the part that is easy to get wrong

**This is the single most important section.** Getting it wrong produced a confidently wrong
analysis once already.

Three **on/off shift solenoids** drive shift valves, and two **pressure regulators** set
pressures ([`set_shift_circuit`](src/pressure_manager.cpp)):

| solenoid | circuit |
|---|---|
| Y3 | 1-2 **and** 4-5 |
| Y5 | 2-3 |
| Y4 | 3-4 |

| regulator | role |
|---|---|
| **MPC** | modulating → **working / line pressure**, holds every clutch that is not being shifted |
| **SPC** | shift pressure, feeds the clutch being shifted — *only while its shift valve is actuated* |
| TCC | lock-up clutch |

### The rule

> **The shift valve decides what feeds the clutch.**
> **Solenoid ON** → clutch is fed from **SPC**. This is the *only* window in which the
> algorithm can modulate that clutch.
> **Solenoid OFF** → clutch is fed from **working pressure**. SPC does not reach it at all.

Consequences that are not obvious from the code:

* **The ramp to `SPC_MAX` at the end of every shift is not "clamping the clutch" — it is
  pressure matching before the handover.** `phase_maxp` walks SPC up so that clutch pressure
  already equals the line pressure it is about to be handed to, *then* drops the valve
  (`set_shift_circuit(..., false)`). **Do not "soften" that ramp**: a slower or lower ramp
  leaves SPC below line pressure when the valve opens and turns a stepless handover into a
  step *up*. If a gentler engagement is ever wanted, the lever is **working pressure (MPC)
  at that moment**, not the SPC ramp.
* **Entering a shift is the mirror image.** MPC is raised and SPC dropped to fill pressure
  *one cycle before* the valve opens, so the holding clutches stay clamped when the shift
  circuit starts drawing flow.
* **When not shifting, SPC sits parked at its maximum** (~7700 mBar observed). That is not a
  bug — with every shift valve off, SPC is dead-ended and feeds nothing.

### Per-circuit gain

Clutch pressure is not SPC pressure. `hydr_cal.shift_spc_gain[]` is indexed by shift
(`1-2, 2-3, 3-4, 4-5, 2-1, 3-2, 4-3, 5-4`) and *(this car)* is
`[1993, 1000, 1000, 1000, 1993, 1000, 1000, 1000]` (×1000). So:

* 1-2 / 2-1 circuit: SPC 7099 → **p_on 14148** (×1.993)
* every other circuit: SPC 7099 → **p_on 7099** (×1.0)

`find_working_mpc_pressure` separately applies `p_multi_1` vs `p_multi_other`
*(this car: 431 / 592, ÷1000)* because 1st and R1 use a different valve area.

### The SPC ceiling — a real hardware constraint

On the 2-3 / 3-4 / 4-5 circuits the applying clutch can only reach ~7100 mBar while
SPC-fed, but the line pressure the box commands for the new gear at ~370 Nm is ~12600 mBar.
**During the overlap of a high-torque shift you cannot clamp the applying clutch as hard as
it will be clamped a moment later, and you cannot buy your way out with pressure.** Engine
torque reduction is the only remaining lever on those shifts.

Measured over 49 handovers in one drive: clutch pressure jumps +36…+77 % at the valve
handover on high-torque shifts and drops −26…−39 % on low-torque ones. **Both are benign** —
mean residual slip at handover is 0.47 % for the jumping cases vs 0.60 % for the rest, i.e.
the clutch is always synced first, so the step is a clamp-margin change on a locked clutch,
not a torque event. If you ever measure slip that *correlates* with the step, that is a real
defect; the absence of correlation is what says the design is sound.

---

## 3. Torque converter and speed sensors

`input_rpm` is the **turbine** speed, derived from the N2/N3 sensors. It is *not* engine speed
and it is *not* output × ratio when the converter is slipping.

**At a standstill in gear the turbine is dragged to 100–300 rpm with the engine at idle — it
never reaches zero.** This broke `Gearbox::is_stationary()`, which used to require
`input_rpm < 100 && output_rpm < 100` and therefore never once returned true across a whole
logged stop with `output_rpm` at exactly 0. Standstill must be judged on the **output shaft**.

`gear_ratio = input_rpm / output_rpm` is meaningless near standstill — logs show 0.00, 29.75
and 101.00 as the output shaft passes through zero. Guard any ratio logic with an output
speed threshold.

---

## 4. Shift algorithm structure

Two algorithms, `CrossoverShift` and `ReleasingShift`, over shared phases
([`shift_crossover.cpp`](src/shifting_algo/shift_crossover.cpp)):

```
BLEED → FILL → OVERLAP → OVERLAP2 → MAX_PRESSURE → END_CONTROL
```

`MAX_PRESSURE` is the pressure-matching phase from §2; `END_CONTROL` holds `SPC_MAX` while the
valve is already off.

**Shifts are serialised.** `Gearbox::controller_loop` only asks the profile for a shift when
`!shifting && actual_gear == target_gear && gear_disagree_count == 0`. A downshift ladder
therefore *chains*, each shift blocking the next. This matters more than it looks:

> A coast-down 4→3→2→1 at 2000 ms per shift takes ~4.4 s, but the car stops in ~4.1 s, so the
> final 2→1 completes **at standstill** and engages 1st with a clunk on brake release. The
> 2→1 fired at 279 rpm input against a 600 rpm map threshold, purely because it could not be
> requested until the 3→2 finished.

When calibrating downshift *thresholds*, always check them against the downshift *time* map
and the deceleration rate: a threshold that cannot be reached in time is not the threshold
you calibrated.

---

## 5. Maps

Two families, both per-profile (Standard / Comfort / Agility / Manual / Winter / Race):

* **Shift point maps** — X = pedal %, Y = gear. Values are **input shaft RPM**.
  Because they are indexed on input RPM, the 0–20 % pedal cells decide which gear the box
  coasts down to; they must form a descending *road speed* ladder (rpm ÷ gear ratio), or the
  box holds a high gear to a standstill and then does two power-on downshifts on tip-in.
* **Shift time maps** — X = pedal %, Y = **% of redline** (`1000, +step, …, redline`, so a
  shift at 87 % redline gets the aggressive corner and one at 50 % gets a gentle one).
  Value = target overlap duration in ms.

The two interact: anything that changes *where* a shift happens also changes *how fast* it is
told to be. Raising a shift point by 1300 rpm both increases the speed drop across the shift
and selects a shorter target time — the severity terms multiply.

### ⚠ Maps are NVS-backed — editing the default is not enough

`StoredMap` loads from NVS and only falls back to the `maps.cpp` default **when the key is
absent** ([`read_nvs_map_data`](src/nvs/eeprom_config.cpp)). A TCU that has already booted
once has the old default stored, so **changing `maps.cpp` alone has no effect on the car.**

The established fix is to **bump the NVS key name** in [`all_keys.h`](src/nvs/all_keys.h) —
the key is not found, the new default is written, and the config app is unaffected because it
addresses maps by numeric ID (`map_editor.h`), not by key. Existing precedent:
`FILL_PRESS_3`, `FILL_LPRESS_4`, `TCC_S_ADAPT_3`, `ADP_PT_A2`, `S_DIESEL_DN_1`,
`S_DNSHIFT_T1`. NVS key names are limited to **15 characters**.

This also discards any user edits to that map, which is the intent when fixing a broken
default — say so when you do it.

---

### Known open tension in the shift maps

`scripts/shift_envelope.py` reports findings that cannot be fixed in the
downshift map alone. To keep full load on boost, a downshift must land at or
above 2400 rpm; to avoid hunting, it must land *below* the lower gear's upshift
point. On this calibration those are incompatible except at 100 % pedal:

| pedal | 3->2 must land under | to reach boost it needs |
|---|---|---|
| 80 % | 1790 rpm (2->3 upshifts at 2900) | 2400 |
| 90 % | 2191 rpm (2->3 upshifts at 3550) | 2400 |
| 100 % | 2776 rpm (2->3 upshifts at 4500) | 2400 ✓ |

So the 60-90 % upshift cells are the blocker: they upshift early enough that the
next gear starts below the boost point, and no downshift threshold can rescue
that without hunting. Fixing it means raising the upshift map's mid-to-high pedal
columns, which is a deliberate calibration pass to do with the owner and one
drive per change - not a reactive edit.

## 6. Adaptation

Pressure adaptation is gated to low torque:
`adapting_trq_limit = (engine_drag_torque / 10) * ADAPT_LIMITS[shift_idx]`
([`shift_crossover.cpp`](src/shifting_algo/shift_crossover.cpp)). *(This car: drag torque
53.5 Nm → limits of 40 / 54 / 67 / 94 / 147 Nm depending on the shift.)*

In one 5-minute drive **37 of 39 shifts logged `Pressure adapt cancelled (Engine torque too
high)`** — normal driving is 130–390 Nm. That is the intended EGS design (it adapts under
defined light-load conditions only), *not* a bug — but it means shift pressures effectively
never self-correct in normal use, so base calibration is what you get. Do not "fix" this
without a reason.

---

## 7. Measuring shift quality

**The TCU log cannot measure shift shock.** Driveline shock is a 5–20 Hz event; the polling
loop manages ~19 Hz with the default record set. Differentiating logged output shaft speed
gives the average torque step, not the jerk. An accelerometer needs ≥50 Hz — the logger
records one (`nag52log record`, on by default) and flags `usable_for_shift_shock` in the log,
but a laptop lid sensor is typically firmware-locked to 10 Hz and useless; use a phone IMU.

Useful proxies that the log *can* support:

* **Inertia-phase severity** = input speed drop ÷ target overlap time. Speed drop across an
  upshift is `rpm × (1 − r_new / r_old)`. Inertia torque through the clutch goes as
  `I · dω/dt`, so this is the quantity that actually sets how hard a shift feels.
* **Ratio overshoot past sync** — flare on upshifts, overshoot on downshifts.
* **Output-shaft acceleration step across the handover** — noisy at 19 Hz, use for ranking
  only, never for absolute claims.

---

## 8. Tools

* **`tmp/shift_replay/`** — compiles the real `ShiftingAlgorithm` / `PressureManager` for the
  host and replays logged shifts through them. Open loop: logged RPMs do not react to changed
  pressures, so it answers "what would the algorithm command?" but never "would the car feel
  better?". Excellent for checking whether a change is an isolated knob.
* **`logger/`** — see [logger/README.md](logger/README.md).

### Reading the calibration

Every log stores the EGS calibration block in its `snapshot`:

```python
LogFile.load(path).snapshot["calibration"]["mech_cal"]["ratio_table"]
```

### Reading a live map back over KWP

Do not trust a boot log line to tell you which map is active — read it:

```
SID 0x21, RLI 0x19, <map_id>, <cmd>, 0x00, 0x00
cmd 0x01 = live (RAM)   0x02 = built-in default (flash)   0x08 = stored (NVS)
```

`map_id`s are in [`src/diag/map_editor.h`](src/diag/map_editor.h) (`S_DOWNSHIFT_MAP_ID` =
0x06). Response payload is `int16` values after a 2-byte header.

---

## 9. Pitfalls that have already cost time

* Assuming the end-of-shift SPC ramp is a harshness source. It is pressure matching (§2).
* Editing a map default and expecting the car to use it (§5).
* Judging standstill from `input_rpm` (§3).
* Calibrating a downshift threshold without checking the ladder can reach it in time (§4).
* Treating a missing record field as `0` in analysis scripts — a dropped read decodes as
  `None`, and `None → 0` turns a dropped `output_rpm` into a fake standstill.
* Hardcoding a log path in an analysis script and then trusting a trace from the wrong drive.
* Believing an `EEPROM` boot line that says "custom NVS map": that message was wrong until
  2026-09-07 and reported freshly-seeded defaults as custom.
