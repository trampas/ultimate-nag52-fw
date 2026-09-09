# NAG52 Behavior and EGS51 Parity Guide

## Scope

This document describes NAG52 behavior relative to EGS51 findings from this repository.
It is intended to be updated as parity work progresses.

Companion physical/OEM primer:

- [722.6 + EGS51 primer](7226_egs51_primer.md)

## 1. Quick parity matrix

| Topic | EGS51 (ROM-derived) | NAG52 current | Parity status | Evidence |
|---|---|---|---|---|
| Shift-circuit assignment | Y3=1-2/4-5, Y5=2-3, Y4=3-4 | Same assignment in pressure manager | Match | [R1][R3] |
| Solenoid role | On/off shift valves select SPC vs line feed path | Same model in set_shift_circuit usage/comments | Match | [R1][R4] |
| P/N idle pair | Y5 + Y4 held together in N/P idle state | No persistent Y5+Y4 idle hold state | Diverged | [R2][R3][R5] |
| P/N exit behavior | Release Y5 + Y4 first, then engagement sequence | Y4 behavior depends on hold_3_4_in_pn; no equivalent Y5 idle pair release logic | Partial / diverged | [R2][R3][R5] |
| D engagement valve path | D path uses 1-2 / 2-3 logic with Y4 generally off | Garage-shift and custom logic can route via 3-4 path depending on state/path | Diverged (intentional/legacy) | [R2][R5][R6] |
| R engagement valve path | Y4 used for reverse branch | Y4 used in reverse-relevant branches | Broad match | [R2][R6] |
| Inrush semantics | Peak/hold behavior in output stage | OnOffSolenoid on-edge inrush behavior is modeled and used operationally | Conceptual match | [R2][R6] |

## 2. P/N behavior deep dive

### 2.1 EGS51

Corrected EGS51 state-machine notes indicate:

- N/P idle state holds Y5 and Y4 together.
- Leaving N/P clears both before starting engagement from state 0.

This is recorded both in narrative and reconstructed state code. [R2][R3]

### 2.2 NAG52

Current NAG52 runtime branch around parking lock:

- hold_3_4_in_pn = true: pre-position Y4 in P/N and park SPC low in that branch.
- hold_3_4_in_pn = false (default): explicitly release Y4 when not shifting in P/N.
- no persistent "hold Y5 + Y4 in P/N idle" branch is currently implemented.

Rationale comments in module settings already document known tradeoffs and measured outcomes for the current branch behavior. [R5][R6]

## 3. Pressure and sequencing notes relevant to parity

The largest risk when changing parity behavior is not boolean solenoid states alone, but state transitions under pressure conditions:

- valve-edge timing and pressure level at stroke time,
- whether inrush occurs at engagement or earlier during low pressure,
- and whether SPC path is being used for a clutch that OEM routes differently.

Use the hydraulic rule from transmission notes and confirm with trace data before changing P/N or garage-shift logic. [R1][R5]

## 4. Suggested implementation roadmap for closer OEM parity

1) Add an explicit optional mode:

- hold Y5 + Y4 during N/P idle,
- release both immediately on N/P exit,
- then follow existing engagement machine.

2) Keep this behind a separate setting key from hold_3_4_in_pn.

3) Stamp traces with mode and per-shift branch decisions to compare engagement reliability and timing.

4) Validate against failure metrics already used in project tools:

- engagement success rate,
- time-to-completion,
- retries and abort cause,
- output-speed and turbine-speed consistency.

## 5. Test and validation checklist

- Confirm map persistence path and key versioning before evaluating behavior changes. [R1]
- Run preflight and shift envelope tooling on before/after logs. [R1]
- Verify no regression in N/P-to-D and N/P-to-R engagements under cold and warm ATF.
- Record branch mode in log metadata for A/B comparability.

## References

- [R1] Transmission/hydraulic model notes: [TRANSMISSION_NOTES.md](../TRANSMISSION_NOTES.md)
- [R2] EGS51 reverse-engineering notes: [tmp/egs51/README.md](../tmp/egs51/README.md)
- [R3] EGS51 reconstructed engagement code: [tmp/egs51/reconstructed/egs51_pressure.c](../tmp/egs51/reconstructed/egs51_pressure.c)
- [R4] NAG52 shift circuit mapping: [src/pressure_manager.cpp](../src/pressure_manager.cpp)
- [R5] NAG52 setting rationale and defaults: [src/nvs/module_settings.h](../src/nvs/module_settings.h)
- [R6] NAG52 runtime P/N and engagement branch logic: [src/gearbox.cpp](../src/gearbox.cpp)
