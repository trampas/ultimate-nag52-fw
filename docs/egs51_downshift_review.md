# EGS51 downshift code review

Reviewed 2026-09-10 against A0215451432 ROM, MD5
`46be22165b2489d311a28bb489885825`, the pass-6 executable reconstruction,
and the original bank1 instruction listing. This is a host-side investigation;
no production control, calibration or flashing changes were made.

**Port work has started:** the fill-credit arithmetic and complete 9ACE/context
helpers are now native and ROM-verified; complete synthetic ROM trajectories also
exercise 9BF9. See [implementation status](egs51_downshift_port.md). The live NAG52
executor replacement and native full 9BF9 pressure controller are still pending.

## Main finding

**EGS51 has dedicated handling for a further downshift during a running downshift,
including an early special pressure-control sequence.** It does more than decide
adjacent shifts after completion. The previous proposal's blanket rejection of
phase-level coordination and simultaneous shift-circuit commands was too strong.

There are still adjacent gear/shift indices. That does not mean every intermediate
gear must undergo a complete, isolated shift cycle before the next one starts.
The useful implementation model is a calibrated, state-dependent handoff, not two
independent pressure controllers sharing SPC without coordination.

## Evidence and confidence

- `tmp/egs51/reconstructed/egs51_shift.c` implements the complete supervisor and
  helpers. Its 32,856-case differential suite passes against raw ROM execution.
  This supersedes the original skip proposal's claim that the supervisor was not
  in the verified set.
- Dispatcher and phase-handler findings below were checked in the instruction
  listing and selected fragments executed with the existing raw-ROM oracle.
  **The complete pressure handler and its closed-loop trajectory are not yet
  independently validated.** Fragment entry states are deliberately supplied;
  this is not a simulation of the car or proof of reachability from ECU boot.
- Raw variables retain address names when their producers/physical units are not
  established. In particular, do not convert a raw temperature threshold of 70
  into Celsius, or timer counts into milliseconds.

## 1. Separate requested gear, execution gear and shift index

Bank1 `236A–2BB1` compares internal A9 against B9. A request below the execution
gear enters downshift selection. In the ordinary idle path, `new_down` decrements
B9 once, copies it to B3, and sets AC = B9 + 4. Thus 5→4 has AC8 and 4→3 AC7.

B9 is therefore an execution/target state, not proof of the physically established
gear at every instant. Historical symbol names calling it simply CURRENT_GEAR
obscure this distinction. XRAM334 is a separate range/selection-related input;
its meaning should not be collapsed into A9 or B9.

## 2. Two downshift modes, with different further-downshift paths

The supervisor chooses modes 3 or 4 with signed XRAM2B9 thresholds and internal
96 bits 5/6 (`1DF3` helper). The entry comparison selects different thresholds
according to B9 versus XRAM334. Later mode changes use a second threshold pair
(cal3CA offsets 2F/3C versus entry offsets 2D/3A), giving state-dependent switching.

Pressure dispatcher `2C4F` groups modes 1/4 together and modes 2/3 together.
That supports different pressure strategies rather than one universal downshift
algorithm. Mapping every mode to a driver-facing load/coast name still requires
verification of the signed signal's producers.

### Mode 4: late continuation

Bank1 `297A–2A10`, reconstructed `case 4`:

- Another lower request must still exist and the newly selected mode must be 4.
- Requires a direction/range gate, or B9=4 with XRAM285 below cal3CA+31.
- Raw temperature XRAM76 must be at least cal3C4+0F.
- Allowed at **AA=3 with B4=4**, or **AA=4**; not every phase-3 state qualifies.
- Clears the three circuit-command bits in I95, decrements B9, updates B3/AC,
  loads B2 from a gear-indexed byte, and resets AA/B4/B5.

This is real early continuation relative to the supervisor's idle state, but it
has explicit qualification and a timer. It does not establish an arbitrary
zero-delay coast ladder or justify bypassing NAG52's standstill protection.

### Mode 3: early special continuation

Bank1 `282D–2979`, reconstructed `case 3`:

- Another lower request exists; selection must remain mode 3.
- I96 bit6 must be clear.
- XRAM76 >= cal3C4+0F; XRAM202 > cal3C4+20.
- B9=3 has an additional gate involving XRAM1C5 bit7 and XRAM29A.
- Sets I96 bit1 as part of qualification.
- Requires **AA=1** and **B5>2 or B4>1**.
- Signed XRAM2BB must reach cal3C4+16; signed XRAM357 must be below the result
  of the verified `6633` threshold calculation. Its parameter is gear-dependent.
- On acceptance, sets I96 bit0, keeps B9 unchanged, sets AC=B9+4, resets the
  phase substates, and enters **AA=6**.

For the deterministic 5→4→3 fixture, A9=3, B9=4, AC8 remains AC8 at this point.
The second gear-state decrement belongs to the special pressure handler, not
this supervisor branch. That distinction is absent from the original proposal.

## 3. The special handler performs an ordered circuit handoff

The mode3 dispatcher table routes phase6 to `3007`, which calls **9BF9**. Its
substate logic contains these operations:

| Bank1 address | Operation | 5→4→3 interpretation |
|---|---|---|
| `9CF3–9CFE` | OR ROM8[E67E+B9] into I95 | B9=4 adds bit2 (Y4) while an existing Y3 command can remain |
| `9DF6–9E20` | speed-derived comparison, B1 and B7:B8 timeout checks | qualification before clearing the old circuit |
| `9E21–9E2C` | clear ROM8[E67B+AC] from I95 | AC8 clears bit0 (Y3), leaving Y4 |
| `9E30–9EA3` | gear-specific dwell and timeout branches | handoff is timed, not just simultaneous opening |
| `9ACE–9AD4` | decrement B9, copy to B3 | advance execution gear 4→3 |
| `9EA4–9F90` | fill/pressure helpers, ramps, timer checks, then AA=1/B5=3 | resume a prepared shift state rather than ordinary phase0 |

The exact ROM bytes give E67E+4 = 4 and E67B+8 = 1. With I95 initially 1, the
isolated command fragments execute **1→5→4**, i.e. **Y3→Y3+Y4→Y4**. Output mapping
of I95 bits0/1/2 to Y3/Y5/Y4 is covered by the existing reconstruction.

This proves the code includes overlapping command states. It does **not** by
itself prove how long both valves are physically open, that both clutches need
independent SPC control during that interval, or that an arbitrary dual-solenoid
command is safe. Complete phase execution, scheduler/output timing and hydraulic
interpretation are needed for those claims.

The helper `9ACE` also uses current pressure-related values and elapsed counter
AF in arithmetic that changes the carried state. Replacing this sequence with a
fresh ordinary shift would discard information the OEM path explicitly uses.
Its detailed formulas remain outside the validated semantic model.

## 4. Direction changes also have explicit transitions

In the supervisor, another direction can interrupt selected early modes when
feature bits in cal3C6+1 permit it. It resets selected timers/substates and enters
special phases 6, 7 or 8, rather than universally returning to phase0. The allowed
phase windows differ between modes. Same-direction load-mode changes can also
preserve or remap phase/substate progress through helpers `1E36` and `1E9D`.

That is evidence for a coordinated executor with change-of-mind behavior. It is
not permission to copy the numeric phase IDs into NAG52; the state machines differ.

## 5. What this means for today's 5→4→3 complaint

The logged double shifts take 2.247/2.416 seconds with only 19/229 ms between them.
A supervisor-only committed target cannot remove the two full executor sequences.
EGS51's mode3 phase6 path is a more relevant lead because it handles a further
request during phase1 and resumes with prepared substates after a circuit handoff.
Whether today's events would qualify under OEM selection still needs the signal
and calibration mapping; the logs cannot directly supply all EGS51 state inputs.

Recommended next reconstruction boundary:

1. Implement and differentially validate full `9BF9`, `9ACE` and their callees,
   including initial pressure setup, speed gate, gear-dependent dwell and carried
   fill state. Include the dispatcher and ordinary phase1 routines `4BC9/4FC0`.
2. Exercise persistent trajectories with timer service and output-pattern transfer.
   Record requested/execution gear, mode/phase/substates, I95, SPC/MPC values and
   actual handoff conditions. Test request withdrawal and direction changes.
3. Resolve signal units, variant selection and timebase before selecting any
   NAG52 constants. Map operations and hydraulic states, not numeric phase IDs.
4. Evaluate a coordinated loaded-downshift implementation against today's traces,
   preserving pressure matching, torque limits, overspeed and abort behavior.

Continuous engine-torque request is **not established** by this review. GS218
packaging is reconstructed, but the upstream torque-request producers remain
incomplete. No claim that OEM holds one uninterrupted request is justified yet.

## Reproduction

```sh
python3 tmp/egs51/tests/verify_shift.py
python3 tmp/egs51/tests/verify_downshift_paths.py
```

Both pass. The new targeted test executes full supervisor fixtures, seven
independent veto cases, a raw-temperature equality boundary, four late-phase
boundaries, dispatcher instruction checks, and explicitly isolated circuit-command
and gear-decrement fragments. It requires the local uncommitted ROM and makes no
changes to it. It is a standalone evidence test, not a new whole-ROM coverage claim.
