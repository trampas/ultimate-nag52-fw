# Executable reconstruction — compatibility directory

The canonical implementation now lives in [`src/egs51`](../../../src/egs51/).
C and header files here forward to that source for existing ROM tools. Firmware,
ROM verification and simulation therefore compile the same code. See
[the current port status](../../../docs/egs51_downshift_port.md) for coverage and
remaining integration work. The historical pass-6 inventory below is not the
current public API count.

## Review pass 6

The C files compile as a host-side semantic model with 49 public functions. The earlier files were
incomplete pseudocode, and several of their formulas and branches were wrong.
This pass checks the new implementations against **execution of the raw ROM
instructions**, not Ghidra's generated C. The original notes in the parent README
are historical; this document supersedes their statements on the routines below.

## Build and reproduce

```sh
python3 tmp/egs51/tests/run_all.py
python3 tmp/egs51/tools/egs51tool.py export > tmp/egs51/logs/calibration_pass6.json
```

The first command builds all C files with C11, `-Wall -Wextra -Werror -pedantic`
in a temporary directory and compares their results to the ROM instruction oracle.
It needs Python 3, `cc`, and the existing uncommitted 128 KiB image. No Ghidra or
third-party Python package is required. The optional existing assembly listing
is used only to report coverage. The runner also verifies 32 calibration
fields against `cal_data.h`. The export emits bank/address/width/sign metadata,
known calibration values, and all 16 entries of each of the 25 coding-pointer tables.
It also extracts 37 TCC parameter fields for each of the three populated bank0
variants, with signedness and original addresses (111 decoded values).
It labels variant nibble 2 as the reference variant, without assuming that all
other coding nibbles have been recovered. It retains raw temperature/timer units.

`Egs51` contains separate internal RAM, XRAM, SFR and ROM storage. Upper indirect
RAM is **not** an SFR alias; words are read explicitly as big endian. The caller
provides a complete ROM and valid runtime calibration pointers. These routines
model semantic state and return values, not register/scratch-RAM clobbers,
concurrent interrupts, hardware latency or a bootable ECU. ADC bytes and SPI replies
are external inputs; the TCC ISR exposes its SPI and compare-write event sequence
through `Egs51Io`. Current feedback has its own `page1/page3` input arguments;
the analog scan takes eight ordered bytes through `Egs51AnalogInputs`.
MDU division by zero
is deliberately outside the model's valid input domain, since its hardware
result has not been established. PCS interpolation is validated on this ROM's
PCS table; arbitrary malformed descriptors are outside the API contract.

## Coverage

| C function | ROM location | Implemented scope |
|---|---|---|
| `egs51_lag` | common `1061–10A7` | unsigned-magnitude ramp, including divisor zero |
| `egs51_lerp` | common `1412–14F2` | clamped word interpolation, integer truncation |
| `egs51_map16` | common `14F3–1837` | PCS word axes/z; x first, then y |
| `egs51_spc` | bank1 `7093–7199` | complete clutch-pressure conversion |
| `egs51_pressure_demand` | bank1 `D76E–D99F` | complete line model, shift corrections, inlet correction, PCS lookup, demand scaling |
| `egs51_fill_time`, `egs51_hold_time` | bank1 `56A6–575C` | complete helper return values |
| `egs51_engagement` | bank1 `5BB6–6191` | complete prologue and states 0–8, pressure/pattern/timer/flag effects |
| `egs51_current_control` | bank0 `3EEC–3F5B`, helper `3F5C` | both PI loops and duty conversion; ISR must supply feedback and reset integrators |
| `egs51_frame_compose` | bank0 `0711–07F7` | shift-channel peak/hold frame, request/previous bits, counters, strobe and watchdog stamp |
| `egs51_output_pattern` | bank0 `6BCC–6BE0` | pattern transfer with output-inhibit guard; caller runs scheduler |
| `egs51_shift_solenoid_select` | bank1 `23EE–2437` | selection fragment; caller must satisfy preceding `R1 != 7` guard |
| `egs51_gear_map` | bank1 `2B86–2BB1` | mapping and Park's XRAM223 write; preceding calls excluded |
| `egs51_cal_select` | bank1 `20BC–2343` | all 16 pointers and missing-variant fault |
| `egs51_cal_select_bank0` | bank0 `7138–7330` | all nine pointers, nibble-F fallback and coding validation |
| `egs51_timers_tick` | bank0 `E48D–E603` | full timer service, including conditional word counters |
| `egs51_gs218_compose` | bank0 `CFB1–D258` | complete RAM field composition, request latch and overrides; CAN transmission excluded |
| `egs51_feedback_scale` | bank0 `5ACA–5B4F` | signed-magnitude trim, saturation and asymmetric rounding |
| `egs51_current_interrupt` | common `01FD–02AB` | complete semantic ISR, ADC scaling, fault/reset, PI and compare update |
| `egs51_spi_exchange` | common `068E–0710` | both exchange modes and response storage, including zero-length behavior |
| `egs51_tcc_interrupt` | common `02AC–0520` | all three timing states, demand clamps, SPI and compare-write events |
| `egs51_shift_supervisor` | bank1 `236A–2BB1` | complete supervisor and callees, including interrupted shifts; pressure phase execution separate |
| `egs51_gear_reset` | bank1 `2B80–2BB1` | complete reset, including preceding helper calls |
| `egs51_mode_transition` | bank1 `1E36–1EEA` | both guarded mode/phase transition helpers |
| `egs51_shift_direction` | bank1 `1EEB–1FE1` | complete direction latches and B7:B8 update |
| `egs51_shift_factor` | bank1 `642B–6567` | complete factor calculation |
| `egs51_shift_threshold` | bank1 `6633–6783` | complete threshold, bypass and signed clamp |
| `egs51_curve8`, `egs51_curve16` | `1838–1903`, `12BE–1411` | complete byte/word curves for valid ROM descriptors |
| `egs51_map8` | `1904–1AD2` | byte axes/z, low input bytes, sequential interpolation |
| `egs51_fill_term` | bank1 `6856–68BA` | complete map and correction, including shift-index-8 exception |
| `egs51_tcc_demand` | bank0 `B77B–B837` | complete curve, signed temperature/adaptive corrections and clamp |
| `egs51_tcc_override` | bank0 `9F23–A04A` | complete neutral/diagnostic overrides and timers |
| `egs51_analog_scan` | bank0 `206E–2498` | all ADC reads, startup/steady filters, faults, substitution and debounce |
| `egs51_tcc_target` | bank0 `A7E6–A88A` | complete slip target map and sequential scaling |
| `egs51_tcc_feedforward` | bank0 `AD0B–AE32` | both feedforward branches and adaptive factors |
| `egs51_tcc_direction` | bank0 `A472–A631` | signed direction thresholds and hysteresis |
| `egs51_tcc_slip_pi` | bank0 `AB5B–AD0A` | complete slip PI with signed acceleration corrections |
| `egs51_tcc_regulate` | bank0 `AE33–AFE0` | complete regulator and callees, release ramp and output/integrator clamps |
| `egs51_tcc_entry` | bank0 `A04B–A471` | all five entry phases and fill-time adaptation |
| `egs51_tcc_excess_slip` | bank0 `A632–A7E5` | complete accumulator, per-gear factor update and release |
| `egs51_tcc_supervisor` | bank0 `A88B–AB5A` | complete operating-state supervisor, entry sequence and excess-slip adaptation |
| `egs51_tcc_adapt` | bank0 `AFE1–B77A` | all three factor-learning regions, low-demand bias learning, inhibits and resets |
| `egs51_tcc_scheduler` | bank0 `B838–BA17` | complete context load/store, filters, supervisor, regulation, adaptation, demand and overrides; all firmware callees implemented |
| `egs51_mpc_line` | bank1 `5480–56A5` | complete line target, minimum, flush states/timers and pressure-decrease filter |
| `egs51_speed_pressure` | bank1 `43C5–447F` | both squared-speed terms, temperature coefficient and staged truncation |
| `egs51_shift_gain` | bank1 `6A50–6AA2` | complete temperature-dependent gain selection |
| `egs51_shift_setup` | bank1 `2BB2–2C4E` | complete setup and callees, including available SPC pressure |

The test oracle in `tests/mcs51.py` executes the original bytes with 8051 carry,
bit addressing, register-bank semantics, RAM call stack and TCON code banking.
MDU timing pads perform the inferred multiply/divide operations; ADC/SPI
peripherals receive the same external test inputs as the C. The
routines and their arithmetic/map callees are not substituted with C or Python
implementations. Unsupported opcodes, unknown MDU write orders, zero divisors
and runaway execution fail the test. This provides independence from the C
translation, but is not validation of undocumented physical hardware behavior.

The original `verify_model.py` tests cover 2,000 ramps, 2,000 scalar interpolations, 2,000 PCS lookups, 3,000
SPC conversions, 2,000 complete demand calculations, 1,000 pairs of timing helpers,
12,001 engagement snapshots, 3,000 dual current-loop updates, 2,000 frame
compositions, 256 gear inputs, 1,024 shift-selection and 256 pattern-transfer
fragments. Random tests use a fixed seed; engagement inputs include equality
boundaries, timer zero/255, mixed flag bits and all nine states plus the invalid
state guard. These are state snapshots, not proof that every input combination
is reachable from ECU boot.

The deterministic differential suites now include passes 5 and 6. The combined run
contains **262,953 comparison cases**, with paired helpers and persistent timer cycles
performing additional calls within a case. The saved local run is
`logs/verification_pass6.txt` (ignored, reproducible using the command above).

| Suite | Cases | Principal coverage |
|---|---:|---|
| `verify_model.py` | 31,537 | pressure, engagement, current PI and output fragments |
| `verify_extended.py` | 17,536 | both selectors, timers, GS218, feedback, ISRs and SPI |
| `verify_shift.py` | 32,856 | supervisor, mode/direction/reset and threshold helpers |
| `verify_maps_tcc.py` | 19,000 | maps, fill term, final TCC demand and overrides |
| `verify_analog.py` | 13,000 | 10,000 snapshots plus 3,000 persistent filter/timer cycles |
| `verify_tcc_control.py` | 31,000 | byte curves, target, feedforward, direction, PI and full regulator |
| `verify_tcc_states.py` | 93,000 | entry, excess slip, supervisor, adaptation, full scheduler, 3,000 persistent scheduler/timer cycles |
| `verify_line.py` | 25,024 | MPC line/flush scheduling, squared-speed terms, gain and full shift setup |

The shift supervisor exercises 1,210 instruction PCs inside its address range.
The analog scan exercises 610; the full TCC regulator and its callees exercise
2,176. The complete TCC scheduler and callees exercise 4,875. These are observed
instruction addresses, not a whole-ROM coverage claim. The persistent TCC test
also asserts that all entry phases 0–4 and operating modes 0–3 were observed,
including release and restart when the inhibit changes. That trajectory uses
variant0; variant1 has zero entry timers and can skip observable phases between
calls. The snapshot tests independently cover all three populated variants.

Engagement tests execute 877 of the listing's 893 instruction addresses. The
remaining 16 are `5CA7` (hold time greater than the 45 minimum, impossible here
after the prologue clears the special-time flag) and `615D–6172` (the alternate
forward-range speed test, precluded by the prologue setting 94 bit7 for forward
targets). Those branches are nevertheless transcribed. This reasoning assumes
inputs remain stable during an invocation, as the semantic API requires.

## Corrected findings and additional information

### The pressure gains were inverted

At bank1 `717E`, `R4:R5=1000` and `R2:R3=shift_spc_gain[idx]` before `0BCC`:

```
SPC = shift_reg_spring + min(positive_signed16(clutch + 20*term), SPC_MAX)
                              * 1000 / shift_spc_gain[idx]
```

The signed sum wraps to 16 bits before the positive clamp. The selected term is
from XRAM174 when internal B6 is 6 or index is 6; otherwise XRAM167 for indices
0/4, and XRAM168 for the rest. B6 is distinct from shift phase AA.

For gain 1993, spring 601, clutch 4000, zero additive term and a nonbinding clamp,
the correct result is **2608**, versus **8573** in the previous reconstruction.

Likewise `D86F–D891` computes `1000*(spring + P_MPC)/p_multi`, not
`p_multi*(spring + P_MPC)/1000`. During shifts it adds a timing-dependent lerp
from zero to ROM16[FFE7] (indices 1/5) or ROM16[FFE9] (others), with axis
ROM16[FFE3/FFE5] and input XRAM275. Index 1 also subtracts
`P_CLUTCH*ROM16[FFEB]/100`, floored at zero. Earlier references to XRAM65 were
wrong: internal 65:66 is a scratch word, initially zero.

The inlet map output remains a pressure. `D920` computes a separate correction
factor; the comparison at `D923` uses the original inlet pressure. Below inlet:

```
k = ROM8[FFD3] * (ROM16[FFDC] - inlet) / 1000
adjusted = pressure + k * positive_signed16(pressure + ROM16[FFD4]) / 1000
```

At or above inlet, adjusted pressure comes from XRAM329. The PCS result is
multiplied by 10/45. `D76E` returns a word; its callers store the low byte.

### Current output is sixteen times the previously described scale

The PI helper returns a saturated 16-bit value `I-32768+Kp*error`, after updating
and saturating I. `3F0D–3F25` uses `XCHD`/`SWAP` with register bank 3 to form
`min(255, value >> 4)`, not `value >> 8`. **MPC D9 is 255-u; SPC DA is u**
(`3F59`). The earlier claim that both duty registers are inverted was wrong.
The semantic current-control entry does not reset the integrators at zero
demand; that reset belongs to the surrounding ISR.

### Engagement control-flow changes

| Evidence | Correct behavior |
|---|---|
| `5BB6–5BBF` | clear internal 9A bits 3 and 5 on every invocation |
| `5BC0–5C54` | prologue uses internal 94 bit **7**, internal 96 bit 2, XRAM1C2 bit **1**; state 8's timer is not reloaded while already in state 8 |
| `5CB4–5CB7` | state 0 falls through into state 1 immediately, so pressure targets can change in the same invocation |
| `5D4F–5DA9` | Y3 gate uses XRAM1BD bit **1**. Gears AB=1/5/6 require speed1F6 **>111**; other gears require speed1F6 **<=111 AND speed22F >111** |
| `5DBE–5DEF` | either 9A bit 4 or bit 2 **set** selects the Y3/restart branch; previous pseudocode inverted this |
| `5DFB–5E2E` | state 6 when `(1BD.bit1 && target!=7) || (1BD.bit0 && target==7)`; the bits are different |
| `5E3C–5EDF` | several tests use **Y5**, not Y3; B3 **<=2**, not <2; B3=3 only returns early when its valve test succeeds |
| `5FDE–5FF8` | Y5 clears when B0 expires, before waiting for B2; restart sets B0=20 and B1=10, not both 20 |
| `6036–6045` | state 6 waits on XRAM1BD bit **1**, not bit0 |
| `60BF–6120` | idle gate uses 1C2 bit1; fast exit requires 94 bit7 **set**, 1CA bit1 **clear**, and speed **<=1005** |
| `6140–6172` | alternate exit requires 94 bit7 **clear**, and uses strict speed <1000 in its forward-range subbranch |

N/P state 8 still requests Y5+Y4, pressures 0/200/800, and exit clears both
valves. However the old blanket conclusion that Y4 is never used in Drive
engagement is unsupported: the full machine also sets Y4 in states 1, 2, 4 and
5 under their respective conditions. Full-system reachability needs the caller
and producers of B3/AB/flags to be reconstructed before assigning these paths
to a particular real-world engagement.

Timer arithmetic wraps to eight bits. For example, two cold fill times of 150
sum to **44**, not 300. This is actual `ADD A,R7` behavior, preserved by the C.
The elapsed duration of a timer tick remains unestablished.

### Temperature claims need qualification

The model keeps temperatures in raw ROM units. The preceding notes' assertion
that raw 130 means 30 degrees under a +50 encoding is arithmetically wrong:
**130-50=80**. The CAN object's exact identity remains unconfirmed, so the +50
hypothesis should not by itself drive changes to the live firmware calibration.
Page9/XRAM21 remains distinct from ATF/XRAM76 in frame composition.

Standalone `56DE` can return its special 80 value at engine-speed word **zero**
when the other conditions hold; bank1 FC3E=0 does not make that path impossible.
Within `5BB6`, however, the prologue clears 9A bit3 before calling it, so this
particular caller cannot take the special branch under a stable state snapshot.

### Additional pass-5 findings

- **Calibration banks have different selectors.** Bank0 `7138` uses coding
  `177–17A` and nine pointer tables; bank1 `20BC` uses `17B/17C` and 16 tables.
  Bank0 coding `179` low nibble selects TCC parameters at `3B8` and curves/maps
  at `3B0`; nibble F maps to variant zero in this selector (startup separately
  disables TCC for F). Both selectors still write FFFF pointers and report a
  fault for unpopulated variants. Bank1 `3C2` comes from **E9E2**, not E8E2.
- **Shift modes, phases and substates are separate.** The supervisor treats
  internal B6, AA and B4/B5 separately, including interrupted-shift modes 6–8.
  It is now a complete function; the pressure phase dispatcher remains separate.
- **Fill term input was misidentified.** `6856` reads internal `56`, not entry
  R7. Shift index 8 selects correction XRAM173; others use `16D+internal56`.
  The sum wraps to a byte before the signed-positive clamp into XRAM339.
- **Analog function starts at 206E, not 2132.** Address 2132 is the operand of
  `MOV 66,A`. The function consumes two successive page-F bytes as
  `2*first + (second>>1)`. Fault bounds are `<51` and `>307`; valid samples are
  clamped to 76–238. Startup averaging accumulates the previous saved sample.
  Conversion is `high8(wrap16(2*wrap16(177*low8(mean)+0xCC0B)))`, which differs
  from the previous formula's rounding. Physical Celsius encoding is unresolved.
- **The TCC slip regulator is separate from demand conversion.** The complete
  `AE33` routine calls signed direction hysteresis, feedforward and the PI
  calculation. Its integral increment is two separately truncated signed
  multiply/divides (`Ki*error/100`, then `*20/100`); its output adds the signed
  integral divided by ten to `Kp*error/1000`. Word wrap and clamp order matter.
  `B77B` subsequently converts the resulting word into PWM demand. Its temperature
  correction reads FE63 (word), FE65 (byte) and FE66 (cap), correcting earlier
  FE62/FE64 labels. The enclosing scheduler starts at B838, not B8FF.
- **TCC interrupt timing is reconstructed in counter units.** The period is
  5000, with an initial 750 interval and the remaining duty-dependent intervals.
  Demand below 14 is off; above 238 becomes FF. The C reproduces frame and
  compare-write events; it does not assign microseconds or simulate peripheral
  response latency. The periodic compare is EE/EF; F3/F4 schedule later events.
- **MDU operation follows register write order.** `1D42` performs a 16/16
  divide using the shorter 1DCA wait pad. Classifying 1DCA calls as multiply
  would silently break feedback, filtering and TCC calculations.

### Additional pass-6 findings

The complete TCC control chain is now reconstructed, from scheduler `B838`
through operating-state selection, all adaptation, regulation, demand conversion
and the final override. The model includes actual RAM effects of every firmware
callee; boot initialization, EEPROM persistence and physical MCU behavior remain
outside this scheduler's scope.

- **TCC state persists in a 20-byte context at XRAM252–265.** The scheduler
  copies this to internal RAM44–57 and back. XRAM264 is therefore the saved TCC
  mode, not the selector position previously implied in the GS218 composer.
  Mode0 is off, mode 1 runs entry, mode 2 ramps down, and mode 3 regulates slip.
  XRAM30D is a separate five-phase entry sequence; mode57 qualifies direction.
- **Entry phase0 falls into phase 1 immediately.** Later phases advance only on
  subsequent calls. The first timer adds signed adaptive byte X11D to the base
  timer with byte wrapping. A separate qualification path can increment or
  decrement X11D; its timer sum wraps before an arithmetic byte shift. Both the
  inhibit flag at bit5F and X79.bit1 suppress adaptive writes.
- **Adaptation has distinct regions and storage.** Positive input regions
  update X121+X39E or X121+X1E9. A signed negative-input region updates X11F.
  Those regions use a signed 32-bit accumulated PI output at X309–30C; changing
  region resets an in-progress average. At low demand, a separate signed word
  average updates signed-byte X11E. X1DC delays adaptation without clearing
  existing sums; failed operating conditions clear them. `A632` separately
  accumulates an excess-slip metric and can adjust a factor and request release.
- **Input filtering and feedforward continuity are explicit.** The scheduler's
  `0FD2` helper computes the signed weighted average `(old*n+next)/(n+1)`.
  On transition timer expiry it subtracts ten times the change in feedforward
  from the integral. This differs from the unsigned ramp at `1061`.
- **MPC pressure falls through a filtered path but rises immediately.** The
  line scheduler scales a pressure term, subtracts the line spring with a zero
  floor, caps at X329, and normally enforces minimum MPC pressure. Only a
  decrease from internal44 is filtered. Both inputs wrap to 16 bits after
  multiplication by eight before the weighted average; the result shifts right
  by three. Flush mode permits zero target when qualified and alternates the
  hydraulic block's flush/non-flush timers. This image uses counts 50 and 30000;
  their elapsed durations are not established.
- **SPC setup preserves unsigned subtraction.** `2BB2` computes the available
  pressure from `wrap16(X329-shift_reg_spring)*selected_gain/1000`. It also sets
  X233 to the maximum of internalAD and cal3C6+2, and computes both squared-speed
  pressure terms with truncation between arithmetic stages. The setup does not
  itself execute the later shift pressure phases.

### Remaining whole-ROM work

The covered functions are compilable and tested, with no placeholder firmware
callbacks inside the functions marked complete. **This is still not a completed
whole-ROM reconstruction.** Specifically:

| Remaining area | Evidence / next boundary |
|---|---|
| Shift pressure phase execution | bank1 `2C4F` dispatcher and phase callees, including `33D6`, `37CC`, `7DDF`, `80BC`, `8200`, `8836`; line scheduling `5480` and setup `2BB2` are now complete |
| Shift-point selection and torque-request production | upstream map selection, thresholds and request-word producers; GS218 packaging alone does not establish their behavior |
| Boot, persistence and diagnostics | remaining startup, EEPROM read/write, adaptation persistence and KWP service state machines |
| Physical validation | timer clock, sensor/CAN temperature encoding, actual peripheral latency, concurrency and closed-loop behavior on hardware |

Symbol names inherited from prior passes outside the coverage table have not
all been revalidated. Ghidra listing slices can start inside instructions, and
its automatically inferred function boundaries are not authoritative.

No production NAG52 control code or calibration was changed in this pass.


## Downshift handoff additions (2026-09-10)

`egs51_handoff.c` adds complete functions without placeholder callees:

| Function | Bank1 range |
|---|---|
| `egs51_handoff_high_pressure` | `4480–4534` |
| `egs51_handoff_low_pressure` | `4535–4666` |
| `egs51_handoff_clutch_pressure` | `719A–71EC` |
| `egs51_shift_feedback_reset` | `6192–61CE` |
| `egs51_shift_clutch_context` | `61CF–6397` |
| `egs51_downshift_handoff_advance` | `9ACE–9BF8`, including all callees |

The `0CE8–0D78` root calculation and `9B38–9BF8` fill-credit arithmetic share
`src/shifting_algo/egs51_handoff_math.h` with the NAG52 source tree. The root
helper's C test wrapper is also exposed. `verify_handoff.py` adds **92,536**
raw-ROM comparisons; all pass. `run_all.py` now includes this suite and the
previous targeted downshift-path tests.

`tools/replay_downshift_handoff.py` separately executes full **original ROM**
9BF9 invocations with pressure helpers, supervisor, setup and timer service. Two
synthetic trajectories reach ordinary phase 1 through speed and timeout gates.
At the time of that addition it did not provide native 9BF9 coverage. The next
section supersedes that coverage limitation; physical timing remains unestablished.

See [NAG52 port status](../../../docs/egs51_downshift_port.md) for the remaining
native pressure-controller and live integration work. No live executor was enabled.


## Native release-pressure executor additions (2026-09-10)

`egs51_shift_pressure.c`, `egs51_release.c` and `egs51_release_phases.c` now
implement complete native 9BF9 and the normal mode 2/3 pressure phases 0–4, including
all pressure callees. Covered boundaries include signed arithmetic 0C20/C0D3,
PID 0DD6, compensation C144, momentum C611 (defined modes 1,2,3,4,6), applying 4BC9,
modulating 4FC0, entry 97EC (mode 2/3, valid entry substates), transfer 96BB,
matching 9A6B and finish 9934. APIs document valid indices/calibration requirements.
No firmware callee is replaced by a placeholder inside those covered functions.

New differential suites are `verify_shift_pressure.py`, `verify_release.py` and
`verify_release_phases.py`; all are included in `run_all.py`. The trajectory tool
accepts `--compare-native`, `--through-finish` and `--ordinary-gear 1..4`.
Native and ROM states persist independently and are compared after each complete
call. 15 complete synthetic pressure schedules cover all four normal loaded
downshifts plus the handoff. They check pressure matching before circuit release.

This is not the full shift dispatcher: mode 1/4 execution, interruption phases,
upstream demand and torque producers, remaining OEM adaptation and the live
NAG52 adapter remain unported. No timer-to-millisecond mapping or vehicle parity
is claimed. The [port status](../../../docs/egs51_downshift_port.md) is the current
scope and remaining-work record.
