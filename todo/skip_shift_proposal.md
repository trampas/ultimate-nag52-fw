# Proposal: skip shift ("multi-gear downshift") in NAG52

Status: **Stage 0 implemented on 2026-09-10; Stages 1–3 remain proposals.**
See [review and implementation](../docs/skip_downshift_review.md) for corrections,
reproduced measurements, diagnostic protocol and validation. The original proposal
below is retained as the design history; its causal/savings claims are not established.
**EGS51 follow-up correction (2026-09-10):** The now-verified supervisor has an
early mode3/phase6 continuation, and its pressure-handler listing includes an
ordered Y3→Y3+Y4→Y4 command handoff. The blanket hydraulic-impossibility and
no-overlapping-command claims below are superseded by the
[EGS51 downshift review](../docs/egs51_downshift_review.md). Full pressure-path
validation is still needed before implementing that sequence in NAG52.

Date: 2026-09-09. Author: analysis pass over EGS51 ROM + two 2026-09-09 drive logs.

---

## 1. Recommendation up front

**A true skip shift — 5->2 as one hydraulic event — is not possible on the 722.6, and this
proposal does not attempt it.** The valve body has no skip path, and there is only one SPC
regulator to modulate with. See section 2; that finding is the reason the rest of this
document looks the way it does.

What *is* achievable, and what EGS51 itself does, is a **committed ladder**: decide the whole
multi-gear downshift once, then execute the adjacent rungs back-to-back as one driver-visible
event, with one continuous torque request.

The measured prize is **0.63 s median per rung boundary** (section 4). On a 5->1 ladder that
is roughly 1.9 s of dead time removed from a ~7.5 s event. The work is mostly in the
**decision layer, not the hydraulics** — which is the main reason this is worth doing and
also why it is lower-risk than it first sounds.

Suggested order: **Stage 0 (measure) -> Stage 1 (commit the ladder) -> Stage 2 (continuous
torque request)**. Stage 3 is listed for completeness and I recommend *not* doing it.

---

## 2. What "skip shift" can and cannot mean here

### 2.1 The valve body has no skip path

Every gear change on this transmission is defined by which *adjacent* shift-valve circuit
strokes:

| solenoid | circuit |
|---|---|
| Y3 | 1-2 **and** 4-5 |
| Y5 | 2-3 |
| Y4 | 3-4 |

There is no "4-2" or "5-3" valve. To reach 2nd from 4th the 3-4 circuit must stroke and then
the 2-3 circuit must stroke. This is not a firmware limitation that can be coded around.

It also shows up in both ECUs' data structures, independently: EGS51's shift index `AC` and
NAG52's `GearChange` enumerate exactly the same eight adjacent changes, and every per-shift
calibration array (`shift_spc_gain[8]`, `overlap_circuit_factor_spc[8]`,
`overlap_circuit_spring_pressure[8]`, the trq_adder/momentum map sets) is indexed by that
same 8-entry adjacent space. **A skip shift has no calibration to run on.**

### 2.2 One SPC regulator makes simultaneous circuits uncontrollable

From `TRANSMISSION_NOTES.md` section 2, the rule that matters:

> Solenoid ON -> clutch is fed from **SPC**. This is the *only* window in which the algorithm
> can modulate that clutch. Solenoid OFF -> clutch is fed from working pressure.

If two shift valves are opened at once, SPC feeds **both circuits at the same pressure**.
There is no second regulator, so the two transitions cannot be filled, overlapped or handed
over independently. Worse, `shift_spc_gain` differs per circuit (1-2 is x1.993, the others
x1.0), so one SPC value produces *different* clutch pressures in the two open circuits with
no way to trim either.

Opening both is therefore not "an aggressive skip shift", it is an uncontrolled one. **Do not
implement it.** This is the single most important line in this document.

### 2.3 So "skip shift" here means a committed, pipelined ladder

Sequenced adjacent shifts, with the inter-rung decision latency removed and the driver-facing
behaviour (torque request, gear display, trace event) treated as one event.

---

## 3. What EGS51 does (the reference implementation)

From the reconstructed shift supervisor, `tmp/egs51/reconstructed/egs51_shift.c`:

- It also steps **one gear at a time**: `--B9; AC = B9+4`, then re-enters the decision.
- **Pipelining:** when a downshift is already running, a further downshift request can start
  the next rung once the current one reaches **phase 3 or 4** — it does not wait for
  completion.
- **Change of mind:** a downshift request arriving during an upshift (and vice versa) can
  abandon and redirect the running shift, remapping the phase rather than restarting.

So even the OEM does not skip; it *pipelines*. That is a useful sanity check on the ambition
level of this proposal.

> **Confidence caveat.** `egs51_shift.c` is transcribed from the instruction listing but is
> **not** in the oracle-verified set (see `tmp/egs51/reconstructed/README.md`). Treat EGS51
> pipelining as a strong reading, not a verified result. It is offered here as precedent,
> not as a specification to copy.

---

## 4. What NAG52 does now — measured, not assumed

Two 2026-09-09 drives (`nag52_20260909_065118.jsonl`, `nag52_20260909_175106.jsonl`):

- **20 downshift ladders, 53 rungs, 33 rung boundaries.**
- Of the 33 boundaries, **30 are pipeline dead time** (< 3 s) and 3 are genuinely later
  decisions (8.5 s, 9.7 s, 22.6 s) that should not be counted.
- Dead-time boundaries: **min 0.05 s, median 0.63 s, mean 0.78 s, p90 1.67 s, max 2.15 s.**
- Removing every dead-time gap would recover **23.3 s across the two drives**.

### The finding that shapes the design

The log samples at ~52 ms, and **only 3 of 30 boundaries were at that floor.** If the delay
were task teardown/respawn overhead, every boundary would sit near the floor. It does not.

**The gap is decision latency, not task overhead.** After each rung the code must return to
`!shifting && actual_gear == target_gear`, re-run the profile's downshift map, and re-clear
`inhibit`, `downshift_can_finish()` and `downshift_has_reserve()` before the next rung is
allowed. Each of those can defer the next rung by many controller cycles.

Consequence: **an implementation that only removes task overhead would save ~50 ms per rung
and would not be worth the risk.** The win is in committing to the ladder up front.

Supporting detail in the current code:

- `Gearbox::kickdown_target()` (`src/gearbox.cpp:806`) *already computes* a multi-gear target
  — the gear nearest 75 % of redline — but its own comment says "Execute adjacent shifts",
  and the result is only used as a boolean (`ask_downshift = kd_target < actual_gear`).
  **The intent already exists; only the execution is one rung at a time.**
- The decision block is gated at `if (!shifting && this->actual_gear == this->target_gear &&
  gear_disagree_count == 0)`.
- `this->target_gear = prev;` (`src/gearbox.cpp:2112`) is always exactly one gear.
- Each shift runs in its own FreeRTOS task that ends in `vTaskDelete(nullptr)`, and `cleanup:`
  **releases the torque request** before the next rung is even considered.

---

## 5. Proposed design

### Stage 0 — measure and instrument first (do this before writing control code)

This project's process rules require the mechanism as a number before flashing, and
instrumentation designed from the question. Neither exists yet for ladders.

1. Add a ladder view to the analysis tooling (host-side only, no firmware change): for each
   drive, emit ladders with per-rung durations, gap durations, and the reason the next rung
   was deferred.
2. To get "the reason", add a cheap **deferral-cause counter** in the decision block: when
   `ask_downshift` is true but the rung is not taken, record which test blocked it
   (`inhibit`, `downshift_can_finish`, `downshift_has_reserve`, the RPM veto, or
   `shifting`). Expose it over KWP, not only in a log line.
3. **Exit criterion:** we can state, from a drive, what fraction of the 0.63 s median gap is
   each cause. If it turns out the gap is dominated by a cause a committed ladder would not
   remove, **stop here** — the rest of this proposal does not pay for itself.

This stage is genuinely useful even if Stages 1-2 are never built.

### Stage 1 — commit the ladder (the main change)

**Idea:** decide the *final* gear once, then walk to it without re-consulting the shift map at
each rung.

Concretely:

- Add `GearboxGear ladder_target` (0 = inactive) to `Gearbox`.
- When a downshift is requested and the profile/kickdown logic yields a target more than one
  gear below `actual_gear`, set `ladder_target` to that gear.
  - For kickdown, `kickdown_target()` already returns it.
  - For map-driven downshifts, extend the existing per-gear evaluation to walk downward while
    `downshift_has_reserve()` holds — the same loop `kickdown_target()` already uses. Reuse it
    rather than writing a second one.
- While `ladder_target` is set and `actual_gear > ladder_target`, the decision block sets
  `target_gear = prev_gear(actual_gear)` **without** re-running the profile map or the
  hunting-inhibit test, so the next rung starts as soon as the previous completes.
- Clear `ladder_target` when it is reached, when the driver's input changes materially (pedal
  release, brake, lever/paddle, kickdown release), or on any abort/gear-disagree path.

**Safety tests that must still run on every rung** (these are not hunting suppression, they
are physical protection, and each already exists):

| Test | Why it must stay |
|---|---|
| `downshift_can_finish()` | The standstill-clunk guard. It cost a road test to find. |
| `downshift_has_reserve()` | Stops entering a gear that immediately demands an upshift. |
| RPM veto (`calc_input_rpm_from_req_gear(...) < redline - 500`) | Overspeed protection. |

**The one genuinely new safety requirement.** `downshift_can_finish()` today asks "can *this*
rung finish before the car stops?". A committed ladder must ask it of the **whole remaining
ladder**, or it re-introduces exactly the standstill clunk that guard was added for. From the
measured data a 5->1 ladder is ~7.5 s of wall time; that is easily longer than a stop. So:

> Evaluate `downshift_can_finish()` against the **sum of the remaining rungs**, and if the
> full ladder cannot finish, **shorten the ladder target** rather than abandoning it.

This is the highest-risk detail in the proposal and should be the first thing reviewed.

### Stage 2 — one continuous torque request across the ladder

Today `cleanup:` calls `set_torque_request(None, ...)` at the end of every rung, so engine
torque is released and re-pulled between rungs. That is a large part of what makes a ladder
*feel* like several separate shifts.

Proposal: while `ladder_target` is active and the next rung will start immediately, **hold the
request across the boundary** instead of releasing it.

**This is the part of the proposal with real history attached.** A torque request that
ratcheted into a fuel cut is a bug this project has already shipped once, and
`scripts/preflight.py` fails a run on exactly that signature. Therefore:

- The request must be **recomputed per rung**, never accumulated.
- It must be **bounded by the same limits a single shift uses** — a ladder must not be able
  to request more reduction than its largest single rung would.
- There must be a **hard timeout**: if the ladder does not progress within a bounded time,
  release the request unconditionally.
- `preflight.py` must be run on every ladder drive, and it must be shown to still *fail* on a
  seeded ratchet (prove the check can fail — this project has shipped a check that passed
  everything, once).

If Stage 1 lands and the ladder still feels like separate shifts, this is the reason. If
Stage 1 lands and it already feels like one event, **do not do Stage 2** — it is the riskiest
part for the smallest incremental gain.

### Stage 3 — phase-level pipelining (recommended: do not do this)

EGS51 starts the next rung at phase 3/4 of the current one. The nag52 equivalent would be
starting rung N+1's `PHASE_BLEED` before rung N's `PHASE_END_CONTROL` completes.

Why I recommend against it:

- **It cannot overlap the parts that matter.** Rung N's `PHASE_MAX_PRESSURE` is walking SPC up
  to match line pressure before its valve drops; rung N+1's `PHASE_FILL` needs SPC *down* at
  fill pressure for a different circuit. One SPC regulator, opposite demands. The only
  genuinely overlappable work is MPC pre-positioning and arithmetic.
- It requires the shift thread to run two algorithm instances with interleaved state, which
  is a large change to the most safety-critical code path in the project.
- Expected gain over Stage 1 is small — Stage 1 already removes the measured 0.63 s.

Revisit only if Stage 0 data shows the residual gap after Stage 1 is still large *and*
attributable to end-of-shift phases.

---

## 6. What NOT to do

- **Do not open two shift circuits simultaneously.** Section 2.2.
- **Do not invent a `GearChange::_4_2`-style enum entry.** There is no calibration behind it;
  every per-shift array is 8 entries of adjacent changes, and `fwd_gearchange_egs_map_lookup_idx`
  would have nothing to return.
- **Do not soften the end-of-shift SPC ramp** to make rungs blend. That ramp is pressure
  matching before handover; softening it turns a stepless handover into a step up.
- **Do not bypass `downshift_can_finish()`** to make ladders faster.
- **Do not ship Stage 1 and Stage 2 on the same drive.** One variable per drive unless every
  shift is stamped; and see section 9.

---

## 7. Risks

| Risk | Severity | Mitigation |
|---|---|---|
| Ladder outlives the stop -> standstill clunk | High | Whole-ladder `downshift_can_finish()`; shorten target instead of abandoning (Stage 1) |
| Torque request ratchets across rungs | High | Recompute per rung, bound to single-shift limits, hard timeout, `preflight.py` gate (Stage 2) |
| Adaptation attribution corrupted | Medium | Ladder rungs are still individual shifts with their own trace events; add a ladder id + rung index to `ShiftStamp` so a learner can exclude or weight them. Learners carry state and cannot be interleaved. |
| Committed ladder ignores a changed driver intent | Medium | Explicit clear conditions on pedal/brake/lever/kickdown change |
| Hunting returns because map re-evaluation is skipped | Medium | Only the *hunting-inhibit* test is skipped mid-ladder; the physical vetoes still run every rung. Ladder target is bounded by `downshift_has_reserve()` at selection time |
| More clutch energy per unit time in a fast ladder | Medium | Compare `slip_energy` per rung before/after; the 3-4 investigation already has tooling for this |

---

## 8. Settings and keys

Add one boolean plus one bound, behind a **new** key (do not overload `hold_3_4_in_pn` or
any existing key):

- `SBS.ladder_commit` (bool, default **false**) — Stage 1 on/off.
- `SBS.ladder_max_rungs` (uint8, default 2) — cap the committed ladder length while
  confidence is low; 0 = unlimited.
- `SBS.ladder_torque_hold` (bool, default **false**) — Stage 2 on/off, separate from Stage 1.

Defaults false means an unchanged car until it is deliberately switched on over KWP, which is
also what makes A/B possible without reflashing.

**NVS caution:** these are settings, not maps, so the map key-bump rule does not apply — but
verify the values by reading them back over KWP, not from a boot log line.

---

## 9. Instrumentation (designed from the question)

The question is "did committing the ladder make the multi-gear downshift better?", so the
trace must be able to answer it per ladder, not per shift:

- Identify each rung with a `ladder_id` (0 = not part of a ladder) and a `rung_idx`.

  **This is not a free change.** `ShiftStamp` is exactly full at 16 bytes (6 single bytes +
  five 16-bit fields) and is guarded by
  `static_assert(sizeof(ShiftStamp) == 16, ...)` in `src/shift_trace.h:178`. Adding two bytes
  breaks that assert. Two options, in preference order:

  1. **Steal bits from existing fields.** `arm` is 0/1 and `algorithm` is 0-2, so both have
     spare high bits. Packing `rung_idx` (needs 3 bits, max 4 rungs observed) and a small
     `ladder_id` into them keeps the struct at 16 bytes and avoids a version bump entirely.
     Prefer this while the feature is experimental.
  2. **Grow the struct to 18 bytes** and bump `SHIFT_TRACE_VERSION` (currently 4) to 5. This
     also requires updating `logger/nag52logger/shift_trace.py` (which mirrors the 16-byte
     layout), `logger/tests/fake_tcu.py` and `logger/tests/test_shift_trace.py`
     (`EVENT_SIZE` assertion). Do this only once the field set is settled.

- Mark the rung as part of a ladder. **The `features` byte is full** — `SHIFT_FEAT_*` uses
  all eight bits 0x01-0x80 (`src/shift_trace.h:116-124`). The `flags` byte is not:
  `SHIFT_STAMP_*` uses 0x01, 0x02, 0x04, 0x08 and 0x80, leaving **0x10, 0x20 and 0x40 free**.
  Use one of those for `SHIFT_STAMP_LADDER` rather than extending `features`.
- Record the **deferral cause** from Stage 0 alongside, so a ladder that did not commit can
  be told apart from one that was never requested.

With that, "one variable per drive" is satisfiable: `ladder_commit` can be toggled over KWP
and each ladder judged on its own stamp.

**A/B note:** `SBS ab_interleave` alternates a feature shift-by-shift. A ladder spans several
shifts, so interleaving would split ladders across arms and make them uninterpretable.
**Ladders must be A/B'd per drive or per ladder, not per shift.**

---

## 10. Validation plan

1. `scripts/shift_envelope.py` before and after — a committed ladder must not change shift
   points, so any diff here is a bug.
2. `scripts/preflight.py` on every ladder drive; must pass, and must be shown to still fail on
   a seeded torque ratchet.
3. Ladder report from Stage 0: rung durations, gap durations, deferral causes, before/after.
4. `slip_energy` per rung before/after, to confirm a faster ladder is not quietly dumping more
   energy into the clutches.
5. Cold and warm ATF, and at least one ladder that ends at a standstill (the clunk case).
6. `quality_adapt_sim.py` replay to confirm the adaptation cells do not diverge on
   ladder-heavy logs.

---

## 11. Open questions for the owner

1. **Is this a real complaint?** No log in the two 2026-09-09 drives shows a *failed* or
   *harsh* ladder — only slow ones. If multi-gear downshifts are not something you notice as
   poor, Stage 0 is still worth having but Stages 1-2 may not be worth the risk budget.
2. **Which case matters — kickdown or coast-down?** The measured ladders are mostly
   deceleration ladders (5->4->3->2 while slowing). Kickdown ladders are rarer in this data.
   These want different tuning, and the answer changes what Stage 1 should prioritise.
3. **How much of the 0.63 s is acceptable?** A ladder that steps instantly may feel worse
   (busy/jerky) than one with a small deliberate pause. There may be an optimum gap that is
   not zero, in which case the setting should be a *target gap*, not a boolean.

---

## 12. Scope estimate

| Stage | Firmware | Host tooling | Risk |
|---|---|---|---|
| 0 — measure | small (deferral counters + KWP field) | moderate (ladder report) | low |
| 1 — commit ladder | moderate (`gearbox.cpp` decision block, whole-ladder finish check) | small | medium |
| 2 — torque hold | small but delicate (`cleanup:` path) | none | **high** |
| 3 — phase pipelining | large (shift thread, two algo instances) | none | high, low reward |

**Recommended commitment now: Stage 0 only**, then re-read this document with its output in
hand.

---

## 13. Evidence

- Hydraulics and the shift-valve rule: `TRANSMISSION_NOTES.md` sections 1-2.
- Circuit mapping and `set_shift_circuit`: `src/pressure_manager.cpp:701`.
- Adjacent-only shift space: `src/common_structs.h:129` (`GearChange`).
- Current decision block and one-gear step: `src/gearbox.cpp:2005-2115`.
- Existing multi-gear target computation: `src/gearbox.cpp:806` (`kickdown_target`).
- Per-rung safety checks: `src/gearbox.cpp:748` (`downshift_can_finish`), `:782`
  (`downshift_has_reserve`).
- Torque request release per rung: `src/gearbox.cpp` `cleanup:` label.
- EGS51 supervisor (pipelining, change of mind): `tmp/egs51/reconstructed/egs51_shift.c`;
  coverage/confidence in `tmp/egs51/reconstructed/README.md`.
- Ladder measurements: `logger/logs/nag52_20260909_065118.jsonl`,
  `logger/logs/nag52_20260909_175106.jsonl`, via `logger/nag52logger/reader.py`.
