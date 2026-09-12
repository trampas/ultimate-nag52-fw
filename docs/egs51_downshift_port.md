# EGS51 baseline port: implementation status

2026-09-10. The target is a faithful EGS51 operating baseline in NAG52 before
adding dynamic agility or additional adaptation. This supersedes the proposed
skip-shift optimization. **The full live NAG52 replacement is not finished or
enabled.** The native reference covers the complete pressure dispatcher, all
eight pressure modes and both forward interruption families. The complete normal scheduler, automatic gear demand and controller startup
are now translated. Physical input/timebase integration, adaptation persistence
and the live executor remain incomplete.
The core now lives under `src/egs51` and compiles in the NAG52 firmware build.
Torque-request production and clutch-speed calculations have also been ported.
Compilation alone does not connect those routines to the vehicle executor.

## Native controller implemented

All functions below execute native C. The original ROM supplies calibration
**data** to the host tests, not instructions or substitute firmware callbacks.
The separate instruction emulator remains the comparison oracle.

| Source | Complete covered behavior |
|---|---|
| `src/shifting_algo/egs51_handoff_math.h` | OEM root approximation and fill-credit transfer; shared portable C/C++ arithmetic |
| `src/egs51/egs51_handoff.c` | High/low fill pressure, spring/centrifugal correction, feedback reset, clutch-context refresh, full 9ACE gear advance |
| `src/egs51/egs51_shift_pressure.c` | Signed arithmetic, overlap/MPC pressure calculations, fill-torque map, OEM adaptation-cell compensation, full 9BF9 handoff, all seven 4BC9 applying-clutch substates |
| `src/egs51/egs51_release.c` | OEM PID and momentum feedback, hold/ramp schedules, release-pressure helpers, all seven 4FC0 modulating-pressure substates and exit gates |
| `src/egs51/egs51_release_phases.c` | Normal mode 2/3 entry 97EC, transfer 96BB, pressure matching 9A6B and completion 9934, including pressure callees |
| `src/egs51/egs51_inputs.c` | Bank0 C449 turbine calculation and complete C6C6 clutch-speed producer, including modes 0–6 and all eight forward shift indices |
| `src/egs51/egs51_torque_gates.c` | All five C9D1..CE9E torque-intervention entry/exit gates and the 6568 upshift threshold helper |
| `src/egs51/egs51_torque_control.c` | Complete CE9F..D76D torque-demand controller: upshift and downshift states, recovery ramps, other-mode fallback and acknowledgement bookkeeping |

The normal release-family phases are used by mode 3 loaded downshifts and mode 2
coasting upshifts. Mode 4 coasting downshifts use the separately translated
crossover pressure family. Entry97EC has an explicit
mode 2/3 and valid-substate contract; the ROM otherwise consumes stale compiler
scratch in some non-entry states. Momentum control supports its defined modes
1,2,3,4,6. These contracts are host reference preconditions, not live fault handling.

## Behaviors preserved

- The handoff owns both command bits, then releases the old circuit when its
  speed/timer gate permits: Y3 → Y3+Y4 → Y4 for the 5→4→3 fixture.
- Advancing the execution gear refreshes applying/releasing clutch coefficients,
  spring pressures, centrifugal terms, strongest-clutch context and feedback.
- Fill progress is converted for the new pressure, then ordinary phase 1 consumes
  that credit. It neither blindly copies the old timer nor restarts filling.
- Signed pressure/torque calculations preserve word truncation, byte wrap and
  the ROM's clamp order. PID integration saturates; derivative subtraction
  wraps to a word before signed scaling. These are not float approximations.
- OEM adaptation-cell compensation remains part of pressure demand. This is
  distinct from the newer NAG52 quality-based learner.
- Final SPC rises to the available pressure and matches before the circuit turns
  off. The fixed synthetic line demand 9000 produces 8999 or 9000 after the selected
  calibration's integer gain conversions; that quantization is preserved.

The approximate root matches all 65,536 input words. In simplified notation,
without showing every intermediate truncation, the credit conversion is:

```
net = max(0, previous_pressure + next_centrifugal - next_spring)
factor = OEM_root(10000 * net / next_fill_pressure)
credit = min(255, (base_timer * (factor + 100) / 2 + factor * elapsed) / 100)
```

Zero next-fill pressure explicitly produces credit 255 in the ROM.

## Verification and its limits

`verify_handoff.py` covers 92,536 original-ROM comparisons. The additional suites
cover signed math and pressure helpers, full handoff calls, all normal applying
and modulating substates, momentum/PID behavior, and entry/completion routines.
The three new suites pass 124,000 snapshot comparisons. They compare persistent
pressure/state outputs and all 1024 XRAM bytes; compiler
scratch is excluded by the semantic API. Calibration selections use the local
A0215451432 image. Randomized fixtures include integer-boundary combinations that
are not claimed to be physically reachable. Inertia-related fixtures maintain a
positive divisor; no result is invented for OEM hardware division by zero.

`tools/replay_downshift_handoff.py --compare-native` runs **independent persistent
native state** alongside the instruction emulator. Oracle outputs are never
copied back into native state. Comparison happens after each supervisor, setup,
pressure, output-transfer and timer call.101 synthetic speed-rise trajectories
exercise 1,543 complete handoff calls through return to phase 1.

`--through-finish` extends the pressure schedule through ordinary phases 1–4 and
circuit release. `--ordinary-gear 1..4` starts a normal loaded downshift into the
specified gear. The host regression checks 15 complete schedules: three synthetic
speed traces for the handoff and each of four ordinary downshifts. It verifies
that pressure matches before the circuit drops. Undefined-behavior sanitization
is enabled for this native trajectory regression.

These are **pressure-schedule comparisons**, not a whole-ECU replay or vehicle
simulation. They omit the complete dispatcher's torque/adaptation side calls,
upstream signal production and physical transmission dynamics. Timer units remain
OEM timer-service calls; no millisecond conversion is asserted. Old drive logs
cannot validate a controller that was not running when they were recorded.


`verify_inputs.py` adds 24,000 raw-ROM comparisons. It verifies staged arithmetic,
word wrap, turbine inhibit, forward shift indices and non-shifting/garage modes.
The resulting XRAM values are still in OEM units; the test establishes arithmetic
parity, not the sensor timebase or a live NAG52 encoding.

`verify_torque_gates.py` adds 60,000 comparisons, with observed latch changes in
each routine. `verify_torque_control.py` adds 20,000 complete CE9F comparisons.
Six independent persistent schedules cover every torque-controller state across
three calibration variants, checking 480 controller/timer pairs through recovery.
Its upshift fixtures use valid upshift map indices; invalid map descriptors are
outside the semantic API. The torque controller swaps the shared pressure
workspace with its own XRAM state exactly as the ROM does. A live scheduler must
preserve that workspace ownership when calling pressure and torque routines.

### Scheduler evidence still requiring a physical timebase

Bank0 `6AE8` samples the `FB:FA` counter at loop entry. Its tail `6CD2..6CF4`
waits until the unsigned counter difference reaches the word at bank0 `0B3D`,
which is **10,000 counter ticks** in this image. The normal loop calls `6E6A`
once at `6BC9`; `6E6A` calls the E48D timer service. This establishes the counter
period and timer-service placement, not microseconds per counter tick. The
owner reports a **4 MHz processor crystal** on the PCB (2026-09-10). The
SIC810 counter clock divider remains unresolved. With no clock multiplication,
a divide-by-4 counter would give a 10 ms main loop and 1.25 ms current loop;
divide-by-8 would give 20 ms and 2.5 ms. These are conditional calculations,
not established timer settings. Initialization at 6711 writes SFR DC=0x48 and
DB=0x0F; a verified SIC810 register definition or bench measurement is still
needed to turn those settings into a physical period.

## Remaining work before live baseline replacement

| Area | Required implementation/evidence |
|---|---|
| Physical inputs | Connect CAN routing, selector acquisition and calibrated sensor acquisition. Bank0 7331 automatic demand and bank0 1DD0 selector decoding are translated: X75 is physical selector/range, while IRAM AB is automatic gear demand |
| Input/calibration adapter | Establish OEM timer timebase, sensor/temperature encoding, torque scaling and selected calibration; translate live NAG52 inputs into the verified controller's units |
| Platform lifecycle and torque/TCC coordination | The complete 29-stage normal scheduler and controller startup are translated. Connect outer-loop fault services, hardware timing, startup/recovery lifecycle and a single live torque/TCC owner |
| Circuit/context ownership | Replace the fixed gear-pair assumptions in `Gearbox::elapse_shift`, own both circuits during transfer, and implement pressure-preserving exits for actual faults |
| Adaptation/persistence | AF12 qualification and RAM cell updates are translated; D9C8/B708 and their interpolation/cell-update helpers are also translated; connect persistence/dirty handling and provide an explicit baseline policy for existing agility and quality-learning settings/cells |
| Trace and hardware validation | Attribute mixed-clutch progress correctly, then verify scheduler timing, current outputs and behavior on the transmission |

The canonical controller is now `src/egs51/`. The old C/header paths under
`tmp/egs51/reconstructed/` forward to that source, so existing ROM tests and
simulation compile the same implementation as firmware. The simulation digest
includes the canonical files. The public C header supports C++ callers.
No firmware setting claims to enable an EGS51 executor that is not integrated.
No calibration or persisted adaptation reset was performed in this pass.

## Validation after moving the core and adding inputs/torque

- All fifteen ROM comparison suites, targeted downshift checks and 32 calibration
  fields passed (`tmp/egs51/tests/run_all.py`).
- The new input and torque routines add 104,000 snapshot comparisons, plus six
  persistent torque schedules covering 480 controller/timer pairs.
- All 132 logger tests passed.
- The unified firmware build passed; a separate C++ caller linked and exercised
  the canonical C input API successfully.
- No firmware was flashed. These results establish native routine parity and
  build compatibility, not completion of the remaining live integration.

## Forward pressure dispatch and adaptation extension

The normal mode1/4 pressure family is now translated, including fill, transfer,
inertia, matching and shared completion. The crossover suites verify 126,000
calls against unhooked ROM instructions. Interrupted crossover A558, context
8520, pressure helpers 8DD5/8E8D and recovery A855/A8C0 add 36,000 comparisons. The release interruption handlers 9F91/A3A5 and their
875D..8DD4 pressure dependencies add another 48,000 comparisons.

The adaptation implementation now includes A97E excursion tracking, A9F2 timing
error, AA98/AC65/ADF6 observation, AF12 qualification/RAM cell updates and 6AA3
demand-factor latching. Its seven routines have 42,000 snapshot cases. Persistent
cell-update tests cover 1,920 calls, including 960 dirty writes, 480 inhibited
writes and 480 zero-error observations. These validate RAM behavior, not NVS
persistence or learning performance on the car.

`egs51_pressure_tick` translates the complete 2C4F dispatcher with its actual
call order, X361..374 pressure workspace swap, intervention gates, observation
calls and D76E regulator-demand conversion. It includes modes0–7, all forward
phases and both interruption families. The compatibility
`egs51_forward_pressure_tick` wrapper retains its original checked contract:
with pressure enabled, modes5 and above return zero without mutation. A rejection
provides no valid new actuator command. Neither API is connected to the current
NAG52 vehicle executor.

Bank0 stubs 0BA8, 0BAD and 0BB2 establish the scheduler order: pressure 2C4F,
torque CE9F, adaptation AF12. The pressure snapshot in X361..374 must survive
CE9F's separate workspace swap; live internal I44/I48 after torque processing
are not pressure commands. Dispatcher tests also exercise this ordering with
independently retained native and ROM state.

### Corrected torque input evidence

Bank0 CF5B..CFB0 copies X2C5 to X2B9, computes signed
`X1FB = X397 * X395 / 100` and `X1FD = X397 * X2B9 / 100`, then stores the
word magnitude of X1FD in IAD. Its native producer passes 12,000 comparisons.
**X1FD is signed torque, not turbine speed.** This establishes staged arithmetic;
it does not establish Nm per raw torque unit.

The simulation previously supplied turbine speed to X1FD. It now calls the
verified producer, with explicitly assumed unity scaling X397=100. The synthetic
handoff fixture likewise uses coherent torque/magnitude values. Old simulation
artifacts with the incorrect mapping must not be treated as current validation.
The corrected default plant run checks 415 native/ROM calls and finishes its
pressure schedule; physical units, timer period and plant behavior remain
assumptions. It does not demonstrate a full controller or vehicle improvement.

## Validation of the forward dispatcher extension

- All 21 ROM comparison suites passed: the full 19-suite regression run plus
  `verify_interrupt_release.py` and the final `verify_dispatch.py`. The aggregate
  runner now includes both additional suites for subsequent runs.
- Whole dispatcher coverage includes 11,000 calls across steady mode0 and forward
  modes1–4, rejection without mutation for unported enabled modes, and 1,920
  persistent pressure/torque/adaptation/timer calls with workspace checks.
- Targeted downshift checks and all 32 calibration fields passed.
- All 132 logger tests passed, and the final unified firmware build succeeded.
- Today's two full drive logs still produce six historical preflight errors:
  one long 3→2, three slip-energy violations and two metric-agreement failures.
  This native-core work does not change or resolve those recorded vehicle results.
- No firmware was flashed, no persisted settings were reset, and the current
  NAG52 vehicle executor was not replaced by this extension.

## Garage, engagement and full pressure dispatcher extension

`egs51_garage.c` adds mode5 selection, release, prefill and inhibit (575D..5BB5)
and mode7 fault pressure (A930..A97D). Mode5's final engagement branch uses the
previously translated 5BB6 controller. `egs51_engage_control.c` adds the complete
mode6 family (31AE..43C4), including all ten engagement-control substates,
momentum feedback, pressure matching, recovery, completion and abort handling.
The native pressure dispatcher now covers all of 2C4F..31AD.

Validation for this extension:

- Five garage/fault routines: 30,000 ROM comparisons.
- Ten engagement routines: 60,000 ROM comparisons.
- Complete pressure dispatcher: 17,600 comparisons across modes0–7, plus the
  compatibility wrapper's rejection-without-mutation checks.
- Ten persistent synthetic engagements into gears1,2,3,6,7 at two raw temperature
  values complete through circuit release and return to mode0. Across these,
  4,380 pressure/torque/adaptation/timer calls retain native and oracle state
  independently. The earlier 1,920 persistent workspace-ordering calls also pass.
- The unified firmware build passes. The aggregate runner includes the two new
  routine suites (23 total); this extension ran the new suites and updated
  dispatcher comparisons separately, not a fresh aggregate run of all23.
- The two drive-log preflights retain their six historical errors. No vehicle
  executor was switched, no persisted settings reset, and no firmware flashed.

The original mode6 controller encounters an MDU zero divisor for a fixture with
X17B bit0 set, selecting table F1DA. The car's coding X17B=0x20, X17C=0x22 selects
F87D with nonzero divisor25. Full mode6 tests constrain this coding bit to the
well-defined domain; they do not establish support for every coding combination
or invent division-by-zero hardware behavior. The persistent trajectories use
synthetic speed inputs and raw timer calls, not established milliseconds.

## Upstream torque qualification extension

Bank0 CA22..CA64 turbine filtering and the complete CA65..CFB0 torque-input
controller are translated in `egs51_inputs.c`. This adds engine-interface
qualification/fallbacks, bounded torque requests, timer-controlled torque
correction, converter speed-ratio curves, engagement converter torque and the
signed context consumed by pressure control. CA22 preserves unsigned filtering
and word truncation before scaling. CA65 preserves its different CF5B/CF6A exits:
only the engagement branch copies converter torque X2C5 into qualified X2B9;
normal operation retains the qualified engine torque.

All five input routines pass 60,000 original-ROM comparisons (24,000 for the two
new routines). Another 5,400 persistent filter/torque/timer calls cover transitions
between normal operation, fallback and engagement. Explicit branch-coverage
assertions include both converter-coefficient outcomes and the CF5B/CF6A exits.
The unified firmware build passes after this addition.

This removes the need to assume unity X397 inside a future complete input
pipeline. The existing pressure-only simulation still explicitly makes that
assumption; it has not been switched to a complete signal pipeline. Live sensor
units, physical timer duration and the remaining upstream scheduler stages are
still required before connecting the controller to NAG52 actuators.

## Complete post-pressure adaptation stages

Bank1 D9C8..E16C is translated in `egs51_adapt_pressure.c`. It owns its eight-byte
X266..26D workspace, qualifies the observation, accumulates pressure error,
subtracts/adds momentum according to direction, clamps the resulting correction
and updates X167/X168/X174. The dirty flag is set on return to steady mode while
the accepted-observation latch remains set.

Bank1 B708..C0D2 is translated in `egs51_adapt_shift.c`. It qualifies a shift while
active and consumes its completed observations in steady mode. The correction
includes accumulated error, momentum and integrator terms. It distributes the
correction across the original cells for all four forward shift families.
`egs51_adapt_cells.c` preserves B2C8 interpolation weights, B3B1 signed byte limits
and B415 neighboring-cell updates, including staged word truncation. B708 itself
does not set the nonvolatile dirty flag; persistence must follow the remaining
OEM lifecycle rather than inventing a write on each helper call.

`egs51_shift_control_tick` now executes the exact five-stage sequence at bank0
6E94..6EA2: pressure2C4F, torqueCE9F, fill adaptationAF12, pressure adaptationD9C8,
then shift-cell adaptationB708. It is a connected native sequence, not the full
6E6A loop. Upstream inputs, demand/supervisor tasks, timers, subsequent TCC/output
tasks, startup and hardware integration remain separate. Pressure commands remain
in I35/I37 and saved X361..374; live I44..4B contains adaptation state afterward.

Validation:

- D9C8: 16,000 ROM comparisons, including 528 changing-cell snapshots; three
  persistent observation/update/dirty lifecycles (186 adaptation/timer calls).
- B2C8/B3B1/B415: 24,000 ROM comparisons covering weighting, signed limits and
  neighboring-cell updates.
- B708: 20,000 ROM comparisons, including 4,255 changing-cell snapshots and all
  four completed-shift families. Another 1,024 persistent qualification/completion
  calls exercise eight signed trajectories through the OEM cell clamps.
- The full five-stage order passes 2,880 persistent stage/timer comparisons in
  the forward fixtures, with the saved pressure workspace retained. The combined
  API also matches 480 complete five-stage ROM sequences.
- Ten synthetic mode6 engagements still complete through circuit release with
  all three adaptation stages running (6,570 persistent stage/timer comparisons).
- The unified firmware build passes. The aggregate runner includes the three new
  suites (26 total); the added suites and updated integration tests were run
  separately, not a fresh full aggregate run. No firmware was flashed.

Earlier investigation notes classified bank1 B9F3/BB02 as shift-point selection.
The complete B708 port establishes that they belong to completed-shift adaptation;
they are not the missing upstream gear-demand selector. Bank1 1DD0 is a signed
torque qualification helper, not a producer of X75. Those earlier interpretations
must not guide the remaining demand port.

## Upstream qualification and connected scheduler prefix

`egs51_demand_inputs.c` translates eight complete bank0 stages:

| ROM entry | Native behavior |
|---|---|
| BA18 | Vehicle-signal qualification, flag composition and interface-specific fallback/scaling |
| BC4A | Pedal qualification, filtered pedal change, demand scaling and fallback |
| BD50 | Move X334 one step toward X75 on each invocation; preserve enable/interlock latches and special range handling |
| BE8E | Auxiliary signal qualification and fallback |
| BEC3 | Engine input, filtering, pressure-enable timer gates and engine threshold flag |
| BFD5 | Four wheel inputs, clamp/substitution rules, filtered/output-speed calculations and low-speed hysteresis |
| 920F | A9 gear qualification, predicted-speed gates, inhibit latches and special-range overrides |
| C496 | Internal shaft inputs, diagnostic qualification, retained-value cases and turbine fallback |

`egs51_scheduler_prefix_tick` executes the actual 19-call prefix at bank0
6E6A..6EA2: timers, those eight input/qualification stages in OEM order, clutch
speeds, the shift supervisor, clutch speeds again, turbine filtering, torque
inputs, pressure/torque and all three adaptation stages. **It advances OEM timers
once per call.** Callers must not add a second timer tick. The five-stage
`egs51_shift_control_tick` API continues to leave timers to its caller.

This prefix consumes already-decoded input values and upstream X75 demand. It
omits acquisition/startup and the remainder beginning at D456, including later
TCC/output tasks and the upstream shift-point selector. The host test supplies
scripted gear demand; it does not demonstrate automatic OEM gear selection,
physical transmission dynamics or established timer duration. No live NAG52
executor switch is enabled by these APIs.

Validation:

- Eight routines: 96,000 unhooked original-ROM comparisons, with raw boundary and
  fallback inputs; 21,600 persistent upstream/timer comparisons.
- 1,800 persistent executions of the real bank-switching scheduler from6E6A to
  bank0 6EA3 match the native prefix, covering 34,200 ordered stage calls and
  observed modes0,1,3. Native and oracle states are retained independently.
- The instruction oracle now supports a bank-qualified stop address. The prefix
  fixture reaches bank1 6EA3 inside a pressure helper; a bare address stop ended
  the comparison prematurely. The final test requires bank0 and a balanced stack.
- The unified firmware build passes. The aggregate runner now includes 28 suites;
  this extension ran its new suites rather than repeating the full aggregate.
- No firmware was flashed. Physical input encoding/timing, the remaining tasks,
  persistence and the NAG52 executor adapter remain necessary.

## Diagnostic and status scheduler tail

`src/egs51/egs51_diagnostic_tasks.c` now translates six complete bank0 tasks:

| Entry | Behavior |
|---|---|
| E01E | Qualified diagnostic latch set/reset, retaining OEM enable masks |
| E0CB | Engine-running qualification and rotating 16-slot fault report |
| E214 | Input-fault summary bit |
| 913D | Range/speed hysteresis and interlock latches |
| E260 | Weighted usage counter, saturation, overflow, inhibited writes and event capture through E48C |
| D259 | Logical status-byte composition, preserving unrelated bits |

Validation adds 72,000 comparisons against unhooked ROM execution and 9,600
persistent calls with independently retained native/oracle states. Fixtures
exercise threshold equality, report-index wrap, 32-bit overflow, 24-bit
saturation, event capture and write inhibition. This ROM's fault table contains
no descriptors 128..135, so that descriptor branch is translated but not covered
by original-table execution. No calibration bytes are altered in the tests.
The aggregate runner includes this as its 29th suite; this extension ran the new
suite, not the full aggregate. The unified firmware build passes (23.541 seconds).
Both September 10 drive-log preflights are byte-for-byte unchanged from the
before-run: four existing errors for 045439 and two for 073946 remain.

These functions are compiled in firmware but are not yet wired into a full-loop
API. D456 includes a substantial ratio observer and fault-recovery state machine;
7331 supplies gear-demand selection. Both remain unported, as do startup,
persistence and the physical NAG52 adapter. The prefix API continues to stop
before D456 and consumes externally supplied X75 demand. No live replacement
or firmware flash is implied by these task-level comparisons.

## Commands

```sh
python3 tmp/egs51/tests/run_all.py
python3 tmp/egs51/tests/verify_dispatch.py
python3 tmp/egs51/tests/verify_garage.py
python3 tmp/egs51/tests/verify_engage.py
python3 tmp/egs51/tests/verify_shift_adapt.py
python3 tmp/egs51/tests/verify_pressure_adapt.py
python3 tmp/egs51/tests/verify_adapt_cells.py
python3 tmp/egs51/tests/verify_shift_cell_adapt.py
python3 tmp/egs51/tests/verify_interrupt_release.py
python3 tmp/egs51/tests/verify_inputs.py
python3 tmp/egs51/tests/verify_demand_inputs.py
python3 tmp/egs51/tests/verify_scheduler_prefix.py
python3 tmp/egs51/tests/verify_diagnostic_tasks.py
python3 tmp/egs51/tests/verify_torque_gates.py
python3 tmp/egs51/tests/verify_torque_control.py
python3 tmp/egs51/tests/verify_handoff.py
python3 tmp/egs51/tests/verify_shift_pressure.py
python3 tmp/egs51/tests/verify_release.py
python3 tmp/egs51/tests/verify_release_phases.py
python3 tmp/egs51/tools/replay_downshift_handoff.py --compare-native --through-finish
python3 tmp/egs51/tools/replay_downshift_handoff.py --compare-native --through-finish --ordinary-gear 1
.venv/bin/python -m unittest discover -s logger/tests
.venv/bin/pio run -e unified
```

See [the ROM review](egs51_downshift_review.md) for the handoff entry evidence and
[the drive-log review](skip_downshift_review.md) for the measured double downshifts.

## Complete normal scheduler and input decoding (2026-09-10)

`egs51_scheduler_tick` now covers all 29 stages of bank0 6E6A..6EC1,
including D456 ratio observation/recovery, TCC supervision, diagnostics, full
7331 automatic gear demand, usage counters and both status composers.
`egs51_controller_init` and `egs51_pressure_init` translate normal controller
startup. Platform timers and physical selector decoding are also translated.
Earlier references above to X75 as automatic gear demand are superseded:
**X75 is decoded physical selector/range; 7331 writes automatic demand to
IRAM AB.**

The demand port includes acceleration, road load, load scaling/corrections,
activity history, load bias/feedback and coast hold. Standalone tests compare
12,000 complete 7331 calls; helper tests include persistent histories. Ratio
checks cover all recovery states and gear recognition. Two full-scheduler
fixtures each compare 3,200 persistent loops against the original bank-switching
ROM: the seeded active fixture observes pressure modes 0/1/3; the startup
fixture currently observes mode 5 only. These are synthetic input tests, not
proof of a complete healthy vehicle drive cycle.

`egs51_can_receive` translates 47A0..4CDB, preserving invalid-value retention,
missing-message flags, variant-specific wheel scaling and pending-bit
acknowledgements. Its 20,000 ROM comparisons use an inferred descending CAN
object-window model; bus identifier routing and hardware window timing remain
adapter responsibilities. No live CAN receive owner is replaced by this API.

The original ROM contains a zero divisor at FC8E in one load-scaling path
(asserted X1C5 bit6 with nonzero X1F3). Tests do not invent an MDU result for
that path, just as they do not for the previously documented mode6 coding
case. Resolving those conditions and selecting verified EEPROM calibration
remain prerequisites for live operation.

The outer platform fault manager (bank0 4D40..5079, including its helpers) is
now translated separately from the normal scheduler. It preserves descriptor
based qualification, latched and pending fault bits, event capture, RAM fault
archives, stop qualification, fallback enable state and counters. Validation
compares 16,000 independent calls and 2,400 persistent timer/fault-manager pairs.
The four starter/voltage/analog qualification routines add 64,000 comparisons.
These APIs do not perform EEPROM writes or replace live hardware fault handling.

Current-feedback initialization evidence: bank0 681C and 6882 explicitly set
X188/X189 to 0x34 and X18A..18D to zero, with AA55 at X18E..18F. These are OEM
initialization/fallback values, not measurements of the original unit's stored
trims or a calibration for NAG52 current-sensing hardware.

Shaft capture processing (547F/5635) preserves the OEM 500,000 / 2,000,000 /
4,000,000 reciprocal numerators, range changes, stale-input handling and speed
acceptance. It passed 32,000 comparisons and 4,800 persistent calls. These raw
conversions do not independently establish the main-loop counter divider.
Output-enable/starter monitors and supply/temperature band selection passed
48,000 comparisons. Solenoid fault monitoring (1EA1) passed 16,000 comparisons,
including its terminal halt: the native API returns zero at the ROM's 1FB2
halt, retaining X3FE=C3 and the unreleased virtual output gate. The adapter
must treat this as a terminal outcome; it is not a normal scheduler return.

Final regression evidence for this pass: the original aggregate run passed
35 ROM suites plus targeted downshift checks and all 32 calibration fields.
The separately added boot scheduler, CAN, platform qualification, platform
diagnostics, shaft capture, output monitor and solenoid monitor suites also
passed. The aggregate runner now includes all 42 suites for subsequent runs.
Both drive-log preflight outputs remain byte-identical to the recorded
pre-change results (four existing errors in 045439, two in 073946).

### Persistent host drive cycle (2026-09-11)

The complete normal scheduler now also runs against a persistent experimental
engine/transmission/vehicle plant in `sim/drive_cycle.py`. The 60-second scenario
starts in Park with empty modeled gear paths, engages Drive, creeps, shifts
automatically through fourth, cruises, coasts, brakes and returns to Park.
Controller and plant state are retained throughout. One initialization pair
and 3,000 timer/scheduler pairs passed 6,002 ROM entry comparisons. All 15 host
simulator tests passed. See [scope and results](../sim/DRIVE_CYCLE.md).

This is host integration, not connection to the live NAG52 Gearbox executor.
Equivalent gear paths, synthetic sensor signals, fixed ATF temperature and
omitted physical TCC/current regulation limit the interpretation. In particular,
the final 2-to-1 pressure sequence lasts 10.36 seconds at the assumed 20 ms tick;
this remains an unresolved model/input/control finding, not a healthy-shift
validation. The processor crystal does not yet resolve the timer divider.
