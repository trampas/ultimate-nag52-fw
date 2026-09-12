# Skip-downshift review and Stage 0 implementation

2026-09-10. Reviewed against the working checkout, including its existing kickdown,
reserve, fault-handling and trace changes. **Decision observation is implemented;
committed ladders, torque hold and hydraulic pipelining are not. Nothing was flashed.**

**Subsequent ROM review:** EGS51 contains a gated phase6 path and an ordered
Y3→Y3+Y4→Y4 command handoff. This supersedes this review's earlier blanket
rejection of simultaneous transitions; see the [EGS51 review](egs51_downshift_review.md)
for the exact evidence and remaining pressure-path validation.

## What holds up

- Keep the calibrated adjacent shift executor. There are eight adjacent shift
  calibrations, and the current pressure controller has no independently controlled
  second SPC channel. This is sufficient reason to reject simultaneous transitions
  in this implementation; the absence of a named skip valve alone is not a proof
  that every possible nonadjacent hydraulic strategy is mechanically impossible.
- A bounded final target could make kickdown more consistent. Preserve physical
  vetoes, recheck driver intent, and retain separate torque release per rung first.
- Measure the decision path before bypassing it. Keep completion pressure matching
  and the existing shift/adaptation lifecycle.

## What needs correction before Stage 1

1. **A short gap is not proof of avoidable decision latency.** The downshift map can
   legitimately wait for road speed to fall. `downshift_has_reserve()` is a veto,
   not a demand generator: walking downward solely while reserve exists can select
   gears the driver/profile never requested. Coast-down and kickdown need distinct
   target selection policies.
2. **The quoted timing is not reproduced with native trace timestamps.** Using
   complete `seq_start..seq_end` windows, adjacent gear continuity, no intervening
   shifts, and gaps strictly below three seconds gives the table below. No cause
   can be recovered from these historical logs. The observed total gap is an upper
   bound on possible savings, not a predicted improvement.
3. **Guard applicability differs from the proposal.** The current finish guard
   exempts kickdown, manual and selector-restricted requests. Reserve also exempts
   coast/low-speed cases. A future ladder must explicitly define its safety policy;
   it cannot claim all these guards already run unconditionally on every rung.
4. **Whole-ladder duration needs real estimates.** Sum estimates for each remaining
   gear at projected speed, including fixed executor phases and relevant time-map
   blending. A single current-RPM time multiplied by the rung count is inadequate.
   Revalidate/shorten at each boundary. The existing finish guard is disabled by
   default, which also needs an explicit policy for enabling a committed ladder.
5. **Do not repurpose trace bits without a protocol change.** Older decoders treat
   `arm` and `algorithm` as complete values. Packing IDs into their high bits would
   silently change their meaning even though the structure stayed 16 bytes.
6. **Torque continuity is a separate experiment.** Holding the request requires
   explicit ownership, cancellation and timeout behavior across executor teardown.
   There is no evidence here that its benefit warrants that change yet. The
   reconstructed OEM phase behavior remains unverified precedent.

## Reproduced baseline

Command:

```sh
python3 scripts/skip_downshift_report.py \
  logger/logs/nag52_20260909_065118.jsonl \
  logger/logs/nag52_20260909_175106.jsonl
```

| Drive | Boundaries | Median gap | Total gap |
|---|---:|---:|---:|
| 065118 | 20 | 305 ms | 10,063 ms |
| 175106 | 22 | 408.5 ms | 12,986 ms |
| Combined | 42 | 361 ms | 23,049 ms |

Combined: 23 candidate ladders, 65 rungs. All gap attribution is **unknown** with
these old logs. These figures describe a different, explicitly defined extraction
from the proposal's polling-based count; do not treat them as before/after results.

## Implemented diagnostic contract

`SID 0x21 / RLI 0x34`, 188 bytes, little endian, version 1:

- Four bytes: version, valid transition count, capacity (16), reserved.
- Two uint32s: last controller observation timestamp, total transition sequence.
- Twelve uint32 elapsed-millisecond counters in the state order below.
- Sixteen eight-byte transitions, oldest first: uint32 timestamp, uint8 state,
  uint8 actual gear index, uint8 target gear index, uint8 flags (manual=1,
  kickdown=2). Only `count` entries are valid; their sequence starts at `seq-count`.

States in wire order: unavailable, shifting, target pending, ratio mismatch,
no request, upshift priority, hunting inhibit, cannot finish, no reserve, RPM veto,
accepted, no profile. Gate states do **not** assert a pending downshift demand.
Veto states identify the first blocker reached by the existing short-circuit
logic, not every condition that might also fail. Elapsed counters describe all
controller observations, not just candidate ladders, and wrap modulo 2^32.

The recorder is fixed-size and allocation-free. Controller writes and KWP
snapshots use a short dedicated critical section. It does not reevaluate profiles,
modify demand, change settings or touch torque/pressure control. Timing represents
observations at controller cadence (normally about 20 ms), not exact task edges.
Paused diagnostic/slave control is recorded as unavailable.

The logger polls `downshift_observer` with the default slow group (once per second).
Older firmware produces a normal unsupported-record error; logging continues.
Sixteen retained state transitions capture short gaps without increasing fast
polling. If transitions are overwritten before a poll, the report leaves uncovered
intervals **unknown**. A slow reader cannot recover them from cumulative totals.

`--json` provides machine-readable rung durations, slip energy when available,
individual gaps, attributed milliseconds, and totals. The report uses TCU sample
timestamps, excludes context samples, deduplicates repeated trace readouts, and
breaks candidate ladders at intervening shifts, incomplete sample windows,
observed reboots and clock wrap. A trace not captured at all cannot be reconstructed;
candidate grouping is not proof of a firmware commitment.

## Validation and next measurement

- `.venv/bin/pio run -e unified`: passed (existing compiler warnings remain).
- `.venv/bin/python -m unittest discover -s logger/tests`: 126 tests passed,
  including actual firmware downshift-veto branch execution, recorder clock/ring
  wrap, firmware-to-Python wire decoding, missing-coverage and reboot tests, plus
  existing seeded torque-ratchet/preflight regressions.
- Preflight on both historical logs exits 1: 29 errors across torque request,
  garage engagement, shift completion, slip energy and metric agreement. This is
  not a validation drive for the new code, and those failures were not suppressed.

The next useful input is a drive with RLI 0x34 recorded. Check what share of gap
milliseconds is `no_request`, a physical veto, a closed execution gate or hunting
inhibit. Only then choose a committed-target policy and quantify its potential
benefit. Stage 0's causal exit criterion cannot be met retrospectively from the
available logs, so the proposal's recommended gate before Stage 1 remains unmet.

## Follow-up: today's acceleration double downshifts

The owner's follow-up correctly identifies a real acceleration-response problem.
Reviewed the two populated September 10 logs in `logger/logs/` (the two other
07:39 connection attempts contain no drive samples). Both report firmware
`65c991f-dirty`; that label does not establish identical binaries or settings.

| Drive | TCU event start | Sequence | First shift | Gap | Second shift | Total |
|---|---:|---|---:|---:|---:|---:|
| `nag52_20260910_045439.jsonl` | 380.579 s | 5→4→3 | 1,124 ms | 19 ms | 1,104 ms | 2,247 ms |
| `nag52_20260910_073946.jsonl` | 547.784 s | 5→4→3 | 1,066 ms | 229 ms | 1,121 ms | 2,416 ms |

These timings use each trace's own sample sequence window. They measure from
first shift execution to completion of the second, not from initial pedal motion.

In the early event, pedal rises from 68.4% to 100% during 5→4 and stays at 100%
through 4→3. Turbine speed progresses 1,858→2,273 rpm, then 2,282→3,464 rpm.
The individual TCU response metrics are 420 and 418 ms. The 4→3 trace is marked
as a flare. Its recorded target time is 427 ms against 1,104 ms execution; target
time is not necessarily the full executor wall-time budget, so this ratio alone
must not be interpreted as a controller timeout.

In the later event, pedal rises from 39.2% to 63.2% during 5→4, then is 75.6–79.6%
in 4→3. Turbine speed progresses 1,311→1,607 rpm, then 1,609→2,414 rpm. Individual
response metrics are 382 and 418 ms; 4→3 is again marked as a flare. Continuing
pedal movement means the eventual second target was not necessarily requested
when the first shift began.

Neither event contains a sampled raw kickdown signal, and neither is stamped
kickdown. A commitment feature triggered only by the kickdown switch would miss
these examples. Pedal/profile-driven demand must be part of any useful design.

Even eliminating the entire inter-rung gap would save at most 19 ms (0.85%) and
229 ms (9.48%) respectively. This changes the priority of the proposal: the
measured complaint is primarily two roughly one-second shift executions. A
committed ladder can help consistency but cannot, by itself, make these events
substantially faster. Investigation should focus on the repeated fill/release
response and safe execution of successive loaded downshifts. These logs do not
establish that overlapping hydraulic circuits is safe.

A subsequent 3→4 starts 551 ms after the early double downshift and 1,463 ms after
the later one. Pedal has fallen to 82.4% (then to zero during that upshift) and 60%
respectively. These are short stays in third, but changing pedal demand prevents
calling them steady-demand hunting without further analysis.

Across the entire two drives, the report finds 14 candidate ladders with 26
boundaries (including coast-down ladders). The early drive has 8,555 ms total gaps
and a 484.5 ms median; the later drive has 7,624 ms and a 723.5 ms median. Neither
log records RLI 0x34, so causal attribution remains unknown; that does not negate
the two clearly observed acceleration-response problems above.

Preflight on today's two drives: torque-request checks pass on 46 evaluated
requests; overall exit status is 1, with one long-shift failure, three slip-energy
failures and two metric-agreement failures. In particular, the TCU/offline jerk
metrics disagree, so the flare flag and measured timing are reported here without
using the absolute jerk values as independently validated severity estimates.

Reproduce:

```sh
python3 scripts/skip_downshift_report.py \
  logger/logs/nag52_20260910_045439.jsonl \
  logger/logs/nag52_20260910_073946.jsonl
python3 scripts/preflight.py \
  logger/logs/nag52_20260910_045439.jsonl \
  logger/logs/nag52_20260910_073946.jsonl
```
