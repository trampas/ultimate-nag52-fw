# Kickdown and shift-control changes, 2026-09-09

These changes address the drive in `logger/logs/nag52_20260909_175106.jsonl`.
The shift-by-shift evidence and EGS51 comparison are in
[the drive review](../tmp/drive_review_20260909/REVIEW.md).
They are implemented and host-tested; improved road behavior is not yet verified.

## Changes

| Observed issue | Implemented response |
|---|---|
| Kickdown arriving during a shift could lose its edge; ordinary upshift could win over it | Read held demand every controller cycle. Cancel on release, expired pedal data, or leaving drive. Re-evaluate useful lower gears between adjacent shifts. Give kickdown priority over normal upshift requests while preserving automatic overspeed protection, including when RPM is no longer rising. |
| 2→1 at 162.916 s landed near 4093 RPM and immediately reversed | Predict landing using positive output acceleration, a conservative shift horizon, converter slip, and the lower gear's actual upshift threshold (including active agility blending). Keep 500 RPM engine reserve and 150 RPM map reserve. Apply this to automatic power downshifts; explicit manual/selector requests retain their existing gates. |
| Brief accelerator lift returned the box to a higher gear too soon | Hold ordinary automatic upshifts for up to one second after a fast pedal drop across a 250 ms window. Cancel on renewed pedal demand, stale data, or leaving drive. Protective upshifts bypass this hold. |
| Long 2→3 shifts at 83.457 and 261.157 s lost applying pressure near synchronization | Bound the turbine trajectory at the target ratio. Use elapsed-time PID and conditional integration against torque bounds. For powered crossover upshifts, derive bounds from clutch capacity and the existing overlap pressure floor; after 80% ratio progress, retain capacity for current input torque. |
| Long 3→2 shifts at 159.338, 536.025, and 921.018 s stayed in release/fill during tip-in | Once powered release has begun, do not raise the old clutch's torque target with rising pedal. Progress its release with elapsed time and preserve command continuity into feedback. Clear stale coast flags during powered 3→2/2→1 transitions. |
| Engine request lagged algorithm output | Publish the newly calculated torque request immediately after the algorithm step instead of sending the preceding step's request. |
| Separate shifts merged into one trace and could inherit the wrong adaptation context | Assign an executor shift ID. Close/open events on ID changes even without an idle sample. Match stamps and flare marks by ID. Use event-start temperature/output and event manual/kickdown/flare flags for quality adaptation; reject unmatched context. |
| Selector transits appeared as failed garage engagements | Log selector cancellation explicitly, with the existing pressure/speed diagnostics. Preflight does not flag explicit cancellation as an engagement failure. Phase 8 alone is now a warning, not proof of rejection. |

The new pressure behavior is a bounded control proposal based on the logged failure
and the existing clutch model. The 80% ratio threshold, release rate, landing
horizon, and lift hold require vehicle validation; they are not claimed to be
recovered OEM calibration. Final SPC_MAX handover and circuit turnaround remain
as implemented previously. Shift maps, hydraulic calibration and adaptation rules
were not retuned in this change.

## EGS51 torque convention

The ROM's GS218 transmit path divides its input word by three and sends `0xFE`
when inactive. That establishes scaling, not whether the upstream request word is
gross or net torque. The engine receive path subtracts drag torque, but this does
not independently prove the convention expected by the engine's request input.

`SBS.egs51_request_gross` therefore defaults to **false**, retaining legacy request
conversion. When explicitly enabled, encoding adds fresh CAN drag before division
by three; missing/expired drag disables that request. Encoding clamps finite values
to 0…253 counts and rejects non-finite values, preventing byte wraparound. The
negative reported engine torque in the drive remains an unresolved undershoot,
not proof of fuel cut or proof that gross conversion should be enabled.

Trace version 4 records raw kickdown, validated demand, selected gross mode,
requested wire torque (3 Nm quantization), and fresh drag torque. The wire value
is the outgoing CAN frame field, not an engine acknowledgement. Other CAN variants
report unavailable for the EGS51-specific diagnostic fields.

## Settings and logger compatibility

- `SBS.feedback_guard = true` enables bounded trajectory/PID, powered release
  progression, and coast-flag correction. Turning it off permits a stamped
  comparison of those control changes only; it does not undo the demand or logger
  changes.
- `SBS.egs51_request_gross = false` keeps the unconfirmed conversion disabled.
- Both fields are appended to SBS settings. Existing settings are retained by
  the subsystem loader; appended fields take defaults. The build regenerates
  `EMBED.ZIP` for configuration tools. Read live settings back before comparison.
- Trace samples grow from 30 to 38 bytes; events from 44 to 52 bytes. The new
  logger reads versions 3 and 4. Use it with this firmware; the old logger rejects
  version 4. Missing version-3 metadata is omitted, never fabricated as zero.
- Event algorithm values: 0 garage/unset, 1 crossover, 2 releasing. Feature bit
  0x80 records feedback-guard enablement. Consecutive events have distinct IDs;
  surrounding context samples may belong to neighboring events, so analyses must
  filter by ID or event sequence bounds.

## Validation

Commands run:

```sh
python3 -m unittest discover -s logger/tests
.venv/bin/pio run -e unified
python3 scripts/preflight.py logger/logs/nag52_20260909_175106.jsonl
python3 scripts/quality_adapt_sim.py logger/logs/nag52_20260909_175106.jsonl
```

All 120 tests pass and the unified firmware build succeeds. New host cases compile
actual C++ control primitives and the trace recorder. They cover saturation recovery,
elapsed-time integration, target limits, increasing-demand release, RPM reserve,
held/cancelled kickdown, gradual fast lifts, torque encoding boundaries, consecutive
shift IDs, annotation ordering, and event-ring rotation. Logger tests cover both
wire versions and new metadata.

The historical-log preflight remains red: it contains actual long shifts and torque
undershoot, plus known legacy interpretation problems (merged ladders, ambiguous
old garage-abort messages, old slip-energy estimates, and the offline one-sample
jerk calculation). Changing firmware cannot change that drive. Outputs are saved
under `tmp/drive_review_20260909/*_after.txt`. The quality-adaptation replay scores
78 textual-request shifts and accepts 22; it is an open-loop desk check, not a
closed-loop demonstration of better shifts, and it misses the request absent from
the log and cannot repair merged trace quality vectors.

Next vehicle validation should measure the same 2→3 and 3→2 cases with trace v4,
checking release onset, minimum near-sync pressure, total ladder duration, immediate
reversals, and requested versus reported engine torque. No firmware was flashed as
part of this implementation.
