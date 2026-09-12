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
| D engagement valve path | **Unresolved.** Machine sets Y4 in states 1/2/4/5 as well; reachability needs the flag/gear producers | Garage-shift and custom logic can route via 3-4 path depending on state/path | Unknown - previously called "diverged" on a withdrawn premise | [R2][R7] |
| R engagement valve path | Y4 used for reverse branch | Y4 used in reverse-relevant branches | Broad match | [R2][R6] |
| Inrush semantics | Peak/hold behavior in output stage | OnOffSolenoid on-edge inrush behavior is modeled and used operationally | Conceptual match | [R2][R6] |
| Clutch -> SPC solenoid pressure | `spring + p*1000/shift_spc_gain[idx]` (gain is a divisor) | `s_algo.cpp:399` uses the identical expression | Match (exact) | [R3][R7][R8] |
| Line pressure from MPC target | `1000*(lp_reg_spring + P_MPC)/p_multi`, then inlet map | `calc_current_linear_sol` uses the same arrangement | Match (structural) | [R3][R8] |
| Shift pressure adder | lerp 0..`extra_pressure_adder_*` over `extra_pressure_pump_speed_min..max` | `extra_p` interpolated over engine rpm, same constants | Match (structural) | [R3][R8] |
| Regulator duty polarity | MPC duty register = `255-u`; SPC = `u` | Driver-level, not directly comparable | Informational | [R3][R7] |
| Multi-gear downshift | Ladder of adjacent single shifts; shift index is adjacent-only. Next rung may start at phase 3/4 of the previous, and an in-progress shift can be redirected | Ladder of adjacent single shifts; `GearChange` has no skip entries. Next rung only starts after the previous fully completes | Match on laddering; **diverged** on pipelining/interruption | [R9][R7] |
| Temperature axis units | Raw ROM units; the "+50 offset" hypothesis is **not** confirmed | Axes treated as degC | Unknown - do not re-base without measurement | [R2][R7] |

## 2. P/N behavior deep dive

### 2.1 EGS51

The engagement machine is transcribed and checked against an instruction-level oracle
(877 of 893 listing addresses exercised). What is established: [R3][R7]

- N/P idle (state 8) requests Y5 and Y4 together.
- Leaving N/P clears both before starting engagement from state 0.

What was **withdrawn** on instruction review: the claim that Drive engagement keeps Y4 off.
The machine also sets Y4 in states 1, 2, 4 and 5. Whether Drive reaches those states in the
car depends on inputs this routine does not produce (`B3`, `AB`, and the `9A`/`94`/`1BD` flag
words), and those producers are not yet reconstructed. **The OEM Drive-engagement valve path
is therefore currently unknown**, and the roadmap item below is not justified by "OEM does it
this way". [R7]

### 2.2 NAG52

Current NAG52 runtime branch around parking lock:

- hold_3_4_in_pn = true: pre-position Y4 in P/N and park SPC low in that branch.
- hold_3_4_in_pn = false (default): explicitly release Y4 when not shifting in P/N.
- no persistent "hold Y5 + Y4 in P/N idle" branch is currently implemented.

Rationale comments in module settings already document known tradeoffs and measured outcomes for the current branch behavior. [R5][R6]

## 3. Multi-gear downshifts

Neither ECU performs a true skip shift (for example 5->2 as one event). Both walk the gears
one at a time. The shift index is adjacent-only on both sides: EGS51's `AC` and NAG52's
`GearChange` enumerate the same eight adjacent changes, so a skip shift is not representable
in either calibration. [R9]

**EGS51** decrements its gear by one per step (`--B9; AC = B9+4`) and re-enters the decision
next cycle. Its supervisor additionally allows:

- **Pipelining** - when a downshift is already running in one of its modes, a further
  downshift request can start the next rung once the current one reaches phase 3 or 4,
  rather than waiting for completion.
- **Change of mind** - a downshift request arriving during an upshift (and vice versa) can
  abandon and redirect the running shift, with the phase remapped rather than restarted.

**NAG52** sets `target_gear = prev_gear(actual_gear)` - always exactly one gear - and the
whole decision block is gated on `!shifting && actual_gear == target_gear`. So the ladder
chains only after each shift fully completes. Note that `kickdown_target()` deliberately
*chooses* a gear that may be two or more below (nearest 75 percent of redline) but its own
comment records the intent: "Execute adjacent shifts". [R6]

Consequences worth keeping in mind:

- A NAG52 downshift ladder takes at least the sum of the individual shift times, which is
  what makes `downshift_can_finish()` and the standstill-clunk guard necessary.
- Closing this gap means allowing a shift to be superseded mid-flight, which touches the
  serialisation the shift thread currently relies on. It is not a small change, and it is
  not currently justified by a measured complaint.
- The unused EGS52-format `FillingCalibration` contains `extra_p_filling_doubleshift[3]`,
  which suggests the OEM family does treat a chained/double shift as a distinct fill case.
  That struct is commented out of NAG52's `CalibrationInfo` and never loaded. [R10]

**Confidence:** the EGS51 side comes from `egs51_shift.c`, which is transcribed from the
instruction listing but is **not** in the oracle-verified set (section 7). Treat the
pipelining and change-of-mind behavior as a strong reading, not as a verified result. [R7]

## 4. Pressure and sequencing notes relevant to parity

The largest risk when changing parity behavior is not boolean solenoid states alone, but state transitions under pressure conditions:

- valve-edge timing and pressure level at stroke time,
- whether inrush occurs at engagement or earlier during low pressure,
- and whether SPC path is being used for a clutch that OEM routes differently.

Use the hydraulic rule from transmission notes and confirm with trace data before changing P/N or garage-shift logic. [R1][R5]

## 5. Suggested implementation roadmap for closer OEM parity

**Read this first.** The only P/N behavior that is actually established from the ROM is the
N/P idle pair (Y5+Y4 held) and its release on exit. The Drive-side valve path is *not*
established (section 2.1). A parity change should be justified by measured engagement
quality on this car, not by an appeal to OEM behavior that the reconstruction does not yet
support. Item 1 below is worth trying on its own merits; items 2-4 apply regardless.

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

## 6. Test and validation checklist

- Confirm map persistence path and key versioning before evaluating behavior changes. [R1]
- Run preflight and shift envelope tooling on before/after logs. [R1]
- Verify no regression in N/P-to-D and N/P-to-R engagements under cold and warm ATF.
- Record branch mode in log metadata for A/B comparability.

## 7. Confidence and how to re-check

EGS51 claims in this document come from a host-side C reconstruction that is compiled with
`-Wall -Wextra -Werror -pedantic` and compared against an 8051 interpreter executing the
original ROM bytes:

```sh
python3 tmp/egs51/tests/verify_model.py       # model vs ROM instruction oracle
python3 tmp/egs51/tools/egs51tool.py verify   # 32 calibration fields vs cal_data.h
```

Oracle-verified: the arithmetic/map primitives, SPC conversion, pressure demand, timing
helpers, the whole engagement machine, current control, frame composition, gear map and
solenoid select. **Transcribed but not yet oracle-verified:** shift supervisor, TCC control,
analog scan and calibration services. Weight parity arguments accordingly. [R7]

## References

- [R1] Transmission/hydraulic model notes: [TRANSMISSION_NOTES.md](../TRANSMISSION_NOTES.md)
- [R2] EGS51 reverse-engineering notes: [tmp/egs51/README.md](../tmp/egs51/README.md)
- [R3] EGS51 reconstructed engagement code: [tmp/egs51/reconstructed/egs51_pressure.c](../tmp/egs51/reconstructed/egs51_pressure.c)
- [R4] NAG52 shift circuit mapping: [src/pressure_manager.cpp](../src/pressure_manager.cpp)
- [R5] NAG52 setting rationale and defaults: [src/nvs/module_settings.h](../src/nvs/module_settings.h)
- [R6] NAG52 runtime P/N and engagement branch logic: [src/gearbox.cpp](../src/gearbox.cpp)
- [R7] EGS51 executable-model review notes and coverage table: [tmp/egs51/reconstructed/README.md](../tmp/egs51/reconstructed/README.md)
- [R8] NAG52 pressure manager and shift algorithm: [src/pressure_manager.cpp](../src/pressure_manager.cpp), [src/shifting_algo/s_algo.cpp](../src/shifting_algo/s_algo.cpp)
- [R9] EGS51 shift supervisor reconstruction: [tmp/egs51/reconstructed/egs51_shift.c](../tmp/egs51/reconstructed/egs51_shift.c); NAG52 `GearChange`: [src/common_structs.h](../src/common_structs.h)
- [R10] Unused EGS52-format filling calibration: [src/egs_calibration/calibration_structs.h](../src/egs_calibration/calibration_structs.h)
