# What of rnd-ash `dev` needs merging into our `main`

Date: 2026-09-08. Updates [dev_branch_review.md](dev_branch_review.md), which was written
against dev at `8289b64`. Dev is now `d4ecee6`; our `main` is `6d74b19` (the former
`shift-strategy`, fast-forwarded).

| | commits since merge base `1b96089` (2026-06-08) | newest |
|---|---|---|
| our `main` | 58 | 2026-09-08 |
| `upstream/dev` | 81 | 2026-09-08 |

Both branches are current. Six of dev's 81 commits are credited to us. **rnd-ash's `main`
is the merge base itself and has not moved since June**, which is probably where the
impression that upstream is stale comes from - it is `dev` that is live.

A straight `git merge upstream/dev` produces **24 conflict hunks over 299 lines** in
`gearbox.cpp`, the shift algorithms, `pressure_manager.cpp` and `torque_converter.cpp`.
That is not a merge to do in one sitting, and most of it should not be taken blind.

---

## What changed in dev since the last review

Six commits. Four are our own findings, which Ashcon reimplemented from the review's
Part 1 - we already have all four, in different code, so they will **conflict and should
resolve to ours**:

| dev | our equivalent |
|---|---|
| `c285f91` Fix ATF setter logic | identical, already in `main` |
| `a8a0004` Fix pedal position SNV substitution | `gearbox.cpp` applies the fallback to both raw and smoothed |
| `acf9f8a` TCC - Ensure on_shift_end is always called | `gearbox.cpp:1016`, in the shift cleanup so aborts are covered too |
| `7c491f2` StandardProfile - Fix upshift table check on should_downshift | `profiles.cpp:401` |

Two are genuinely new to us:

| dev | what | verdict |
|---|---|---|
| `d4ecee6` Sensors - guard against 0 pulses/rev | 4 lines. `sensors.cpp:61` divides by `pulses_rev`; a zeroed config divides by zero. Ours by authorship, but never backported. | **take now** |
| `58383db` Start new TCC adaptation logic | Ashcon's new work: `calculate_slip_target`, `calculate_min_pressure`, `calculate_torque_correction`, plus an NVS key change. 114 insertions. | tier 2 |

---

## Tier 1 - take now, no drive needed

Only one item qualifies on its own merits.

- **`d4ecee6` sensors 0-pulse guard.** Applies cleanly, four lines, removes a
  divide-by-zero on a misconfigured TCU. No behaviour change on a configured car.

Everything else in dev either changes shift behaviour or is structural.

---

## Tier 2 - changes shift behaviour, needs data before taking

These are the reason a blind merge is a bad idea. Each is a real fix upstream, and each
lands on code this car's calibration was tuned against.

**Directly relevant to the harshness we are chasing.** All absent from `main`, all
conflict:

| dev | what it does |
|---|---|
| `8289b64` Shift bleed - fix hyperbolic drop of SPC pressure | 2 lines in `s_algo.cpp`. Ours by authorship, upstream only. Bleed shapes the delay before the ratio moves, which is the 500 ms `response_ms` measured on the 07:01 drive. |
| `43c53c0` Increase shift bleed time | same area, opposite direction |
| `c72e621` Fix harsh release shifts when downshifting | the release path, i.e. coast downshifts |
| `4782e91` Potential fixes for 4-3 shifting harshness | 4-3 specifically |
| `3265462` Crossover - fix wrong downshift torque calc | torque sizing on downshifts |
| `b13c81b` Shift release - start torque request earlier | 3 lines. Arms the torque request ramp before the sync instead of on reaching the threshold. This is the same defect I measured on the 1-2 today, in the release path rather than the crossover one. |
| `300876d` Shift release - slightly faster clutch release | release timing |
| `e1466f1` Relax release upshift low filling pressure | applies cleanly |

**The tension worth stating plainly.** Our coast-down work - the anti-clunk downshift
guard and the downshift map and time-map corrections - was measured and replayed against
the *current* shift algorithm and the *current* downshift algorithm selection. Dev changes
both. Taking dev's downshift changes invalidates that tuning and the drive logs behind it;
not taking them means re-solving problems upstream may already have fixed. The way out is
the replay harness, not a coin toss: `tmp/shift_replay/` builds two variants of the real
algorithms and runs the logged shifts through both.

**Larger dev features, still absent, still deferred for the same reasons as last time:**

- Garage shift rewrite (staged fill with sync detection; N->D at speed picks the clutch
  for the gear the car is in). Large, unreviewed on this car.
- Acceleration tracking (`acceleration_ms2`) and the crossover inertia/torque correction
  that consumes it. Review item R3 says the correction as written cannot go positive.
- New TCC adaptation (`58383db`) and the TCC coast slip table.
- Downshift algorithm selection: coasting 3-2 and 2-1 become release shifts, mid-torque
  downshifts become crossover.
- Unfiltered speed and engine rpm.
- `MAX_TRQ_FACTOR` on EGS51 - still wants a raw `MS_310` capture from this car first,
  since an ECU sending `0xFF` would double `m_max` and `0x00` would zero it.
- New settings (`redline_offset_auto_upshift`, `auto_show_gears_always`) - need the config
  app YAML to follow.
- `GS_418` on EGS51 and the Reverse_Second B3 friction correction - unchanged reasoning.

**Explicitly still not wanted:** the TCC ISR stop around flash writes. Our
`sdkconfig.unified` leaves `CONFIG_GPTIMER_ISR_IRAM_SAFE` unset, so IDF already masks that
interrupt during flash writes. Dev enabled it on IDF 5.5, which is what made their ISR run
during writes, and the timer-stop is their workaround for that. Porting it would import
review item R4 for no benefit here.

---

## Tier 3 - the structural migration, on its own

| | main | dev |
|---|---|---|
| platform | `espressif32@6.8.1` (IDF 5.3) | `espressif32@6.12.0` (IDF 5.5) |
| `sdkconfig.unified` | 1994 lines | 2202 lines |

Dev keeps `COREDUMP_ENABLE_TO_FLASH` and `CHECK_BOOT` on. On IDF 5.3 that boot-loops this
board, which is why ours is on core-dump-to-UART. That has to be **re-tested on 5.5**, not
carried across and not dropped blind. Dev also adds `pip install intelHex` to both CI
workflows, which is the same missing dependency that broke the bootloader build here today.

This is its own task with its own boot check. Do not fold it into a behaviour merge.

---

## Recommended order

1. **Take `d4ecee6` now.** One commit, four lines, no drive.
2. **Finish the current experiment first.** The anti-clunk guard is committed, validated
   offline and never flashed. Get a drive on it while the algorithm underneath is the one
   it was tuned against. Changing the shift code first throws away that comparison.
3. **Then A/B the harshness fixes in the replay harness**, as one group:
   `8289b64`, `43c53c0`, `b13c81b`, `c72e621`, `300876d`, `3265462`, `e1466f1`. Build old
   and new variants, run the logged shifts from the 07:01 drive through both, and compare
   `response_ms` and `peak_jerk` per shift type. That answers whether dev's fixes address
   what we measured, before touching the car.
4. **Then the IDF 5.5 migration** as a separate flash-and-boot-check task.
5. **Then reconsider the big features** - garage shift, acceleration tracking, downshift
   algorithm selection, new TCC adaptation - each with a replay A/B, in the order they
   affect what we are actually complaining about.

Merging all of dev in one go is possible but would mean resolving 24 hunks in the shift
algorithms and then having no idea which change caused which regression - the exact failure
the one-variable rule in `CLAUDE.md` exists to prevent. The per-shift stamp now makes more
than one variable per drive attributable, but only for changes that are behind settings.
Dev's are not.
