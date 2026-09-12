# EGS51 ROM reverse engineering (A0215451432)

> **Current status:** See [the native port status](../../docs/egs51_downshift_port.md)
> and [the executable reconstruction and correction report](reconstructed/README.md).
> The C model now includes the full shift supervisor, current/TCC interrupt routines,
> complete TCC scheduler/control/adaptation, analog scan/filter, calibration selectors,
> timer service, MPC line/flush scheduling and shift setup. The native core also
> covers the full pressure dispatcher, torque control and all three post-pressure
> adaptation stages, with original-ROM differential tests.
> Earlier sections below are a historical investigation log. The correction report
> supersedes its formulas, function boundaries and confidence claims where noted.
> Whole-ROM reconstruction remains incomplete; the report lists the remaining subsystems.

Disassembly and analysis of the original Mercedes EGS51 transmission ECU firmware from the
owner's own car, done 2026-09-08/09. The point of the exercise is interoperability: this repo
reimplements the EGS, and the OEM ROM is the only authoritative source for what the factory
calibration actually contained.

**The ROM image and the disassembly derived from it are not committed** (see `.gitignore`).
They are proprietary Mercedes firmware and derivative work. Everything in this directory that
*is* committed — this document and `ghidra/` — is our own.

---

## 1. Where everything is

**Everything is on this machine, under `tmp/egs51/`.** Nothing is left stranded on the remote
box; it was all copied back on 2026-09-09 and verified (image md5 matches on both).

| path | tracked? | what |
|---|---|---|
| `README.md` | yes | this document |
| `ghidra/*.java` | yes | the four Ghidra scripts that make the import work |
| `ghidra/run_bank0_funcs.sh` | yes | launcher pattern for background headless runs (see §7) |
| `EGS51_A0215451432.bin` | **no** | the ROM image, 128 KB, md5 `46be22165b2489d311a28bb489885825` |
| `disasm/bank0.bin.asm` | **no** | full disassembly, bank 0 (880 KB, ~40k instructions) |
| `disasm/bank1.bin.asm` | **no** | full disassembly, bank 1 (907 KB, ~42k instructions) |
| `disasm/bank0.bin.c` | **no** | **decompiled C, bank 0** (766 KB, 292 functions, 0 failures) |
| `disasm/bank1.bin.c` | **no** | **decompiled C, bank 1** (477 KB, 292 functions, 0 failures) |
| `ghidra_projects/proj0b/EGS51A.{gpr,rep}` | **no** | **Ghidra project, bank 0** — swept, functions created |
| `ghidra_projects/proj1/EGS51B.{gpr,rep}` | **no** | **Ghidra project, bank 1** — swept, functions created |
| `logs/*.log` | **no** | analyzeHeadless run logs |

**Start from the Ghidra projects, not a fresh import.** They carry all the analysis state:

```sh
/snap/ghidra/47/ghidra/ghidraRun     # then File > Open Project > tmp/egs51/ghidra_projects/proj1
```

Ghidra 12 is installed via snap on both this machine and the fast box. For a headless re-run,
`analyzeHeadless` is at `/snap/ghidra/47/ghidra/support/analyzeHeadless`.

Original source of the image: `~/Downloads/1999 E300 A0215451432_EGS1.BIN`.

### Also still on the fast box (192.168.72.64, user `trampas`)

`~/egs51_disasm/` — the same content, plus `in/bank0.bin` / `in/bank1.bin` (the split banks,
regenerable with `dd bs=65536 count=1 [skip=1]`) and a superseded first attempt in `proj/`.
That box has 24 cores and is the one to use for long runs; nothing there is unique any more.

---

## 2. The image

- 128 KB = **two 64 KB banks**, both mapped at `CODE:0000`.
- Common stub `0x0000–0x0BF3` is byte-identical in both banks (vectors + the bank-switch
  trampoline). They diverge from `0x0BF3`; only 13.9 % of the whole 64 KB is identical.
- Valid 8051 vector table: reset `LJMP 0x0039`, INT0 `LJMP 0x0664`, T1 `LJMP 0x0521`.
- `BHW001300392SW001300392` at `0x031FE` — hardware/software part numbers.
- Part number `0215451432` in BCD at `0xFBFE`, matching the calibration the car reports over
  KWP (`0215451432.STDP / .52 / .71 / .SM00`).

## 3. The MCU

**Siemens 80C517A / C509-L family** (8051 core). Identified from the SFR fingerprint against
the Siemens datasheets:

| feature | addresses used | evidence |
|---|---|---|
| multiply/divide unit | `E9–EF` (MD0–MD5, ARCON) | on both 517A and C509-L |
| compare/capture unit | `C1–C7` (CCEN, CCL/CCH1-3) | on both |
| compare regs CMH3–CMH5 | `E3–E7` | **C509-L only** |
| CMEN / CMSEL, P9 | `F6 / F7 / F9` | C509-L |
| ADC | `D8–DD` (ADCON0/1, ADDATH/L, P7, P8) | on both |
| DPSEL / XPAGE | `92 / 91` | on both |
| serial 1 | `9C` (S1BUF), `BA/BB` (S0RELH/S1RELH) | on both |

C509-L is the better fit — it is ROMless with external program memory, which is what a banked
external EPROM implies.

**Unresolved:** `A5 A6 A7 AD AE AF` are the six busiest registers in the ROM and are documented
as *reserved* on both datasheets. See §5 for what they do. This is probably a custom or
undocumented Siemens automotive variant; **the chip marking on the ECU board would settle it**,
and would let the remaining peripherals be named.

Caution: Ghidra's generic 8051 spec labels some of these with names from a *different* 8051
(`TXCON`, `CCAP0H`, `T2MOD`). Those names are wrong here — treat them as raw addresses
`F4`, `FA`, `C9`.

## 4. How to reproduce the import (this is the part that matters)

A raw binary import produces **zero functions** — Ghidra will not disassemble without entry
points, and the decompiler then has nothing. The working recipe, per bank:

```sh
analyzeHeadless <proj> <name> \
  -import in/bank0.bin -processor 8051:BE:16:default \
  -loader BinaryLoader -loader-baseAddr 0x0000 \
  -scriptPath scripts -preScript PrepEntry -postScript SweepDisasm -postScript DumpAll
# then, to turn the swept instructions into functions:
analyzeHeadless <proj> <name> -process bank0.bin -noanalysis \
  -scriptPath scripts -postScript MakeFuncs -postScript DumpAll
```

The four scripts, in `ghidra/`:

- **`PrepEntry.java`** — seeds the 8051 vector table (0x0000, 0x0003, 0x000B, … 0x0063) so the
  analyzer has somewhere to start. Without this: 0 functions.
- **`SweepDisasm.java`** — linear sweep, disassembles every address not already code or data.
  Recovers ~24k instructions per bank that flow-following alone misses (indirect jumps).
- **`MakeFuncs.java`** — creates functions at every call target. This is what takes the result
  from 26 functions to **292** and the decompiled C from 14 KB to 477 KB.
- **`DumpAll.java`** — exports the listing and the decompiled C.

Result per bank: 292 functions, **0 decompile failures**, readable C.

## 5. Code structure

**Compiled C, not hand assembly.** Keil C51 with the BL51 banked linker:

- Thunk table at `0x0B6F–0x0BC9`: `MOV DPTR,#target ; AJMP 0x0B3F`.
- Bank switch at `0x0B3F` / `0x0B57`, helpers at `0x0C00` / `0x0C08`:
  ```
  0x0B3F: A = TCON & 0x10          ; current-bank flag
          if flag==0: JMP @DPTR    ; same bank, direct
          else: push 0x0C08, push DPTR, LJMP 0x0C00
  0x0C00: TCON |= 0x10; TCON &= ~0x10; RET   ; toggle, "RET" into DPTR
  0x0C08: TCON |= 0x10; RET                  ; restore on return
  ```
  **The bank-select flag is `TCON.4`** (Timer 0 run bit) — implying the external bank latch is
  driven from Timer 0 state. Worth confirming against the board.
- ~20 cross-bank entry points (`0x5ACA`, `0x3EEC`, `0x2000`, `0xD9A0`, …) — these are the
  module boundaries.
- Arguments in R4–R7, constants via `MOVC`, standard C51 idiom.

**The six undocumented SFRs look like a hardware math coprocessor.** The most-called routine in
the ROM is `0x0BCC` — **242 call sites**:

```
A5←R7  AE←R5  A6←R6  AF←R4      ; write four operand bytes
LCALL 0x1DCA                     ; = RET          (a timing pad, 4 cycles)
R7←A5  R6←A6  R5←A7  R4←AD      ; read back, including A7/AD which were never written
A5..AF ← R7..R2                  ; write six more
LCALL 0x1DCB                     ; = NOP NOP NOP NOP RET  (8 cycles)
R7←A5  R6←A6 ; RET
```

Both "calls" land on a `RET` in *both* banks — they are latency pads. Write operands, wait a
fixed time, read results from registers never written. That is how firmware drives a hardware
MDU, and it is *separate* from the documented MDU at `E9–EF`.

**Interrupts** — only two are live; everything else is polled from a main loop:

- `0x0521` (T1): computes `{F4:F3} = {FB:FA} − 12`, i.e. loads a 16-bit compare register from a
  16-bit capture register minus twelve ticks. Another undocumented capture/compare pair;
  scheduling solenoid PWM or a speed-sensor edge.
- `0x0664` (INT0): counts pulses into XRAM `0x01AE`, flags at 50.

**Memory:** all state in 1 KB of XRAM (`0x0000–0x03FF`); bank1's modules live mostly in
`0x0300–0x03FF`.

**Largest functions** (the state machines): bank0 `FUN_CODE_7331` ≈ 5.3 KB, bank1
`FUN_CODE_D9A0` ≈ 3.7 KB (also a cross-bank entry point).

**Calibration tables are at `0xF000–0xFFFF` in both banks** (~8 KB total), read through a
two-point linear interpolator at `0x3F5C` (fetch `t[i]`, `t[i+1]`, `MUL` each by an 8-bit
fraction, sum). Table pointers reach it in `DPTR`, so **searching for immediate addresses at
call sites will not find table references** — that mistake is what made the first pass conclude
the calibration was unreferenced.

## 6. Findings about our own calibration

### The mechanical and hydraulic blocks ARE this ROM

Byte-for-byte matches for the blocks nag52 runs on this car (searched from
`tmp/shift_replay/cal_selected.json`), all big-endian, in bank1:

| offset | block |
|---|---|
| `0x1F0DB` | `mech.friction_map` (48 × u16) |
| `0x1F13B` / `0x1F143` | `mech.max_torque_on_clutch` / `off_clutch` |
| `0x1F14B` | `mech.release_spring_pressure` `[1270,846,1205,1139,1289,488]` |
| `0x1F161` | `mech.strongest_loaded_clutch_idx` |
| `0x1F181/91/A1` | `hydr.overlap_circuit_factor_spc` / `_mpc` / `_spring_pressure` |
| `0x1F1B1` | `hydr.shift_reg_spring_pressure` = 601 |
| `0x1F1B3` | `hydr.shift_spc_gain` `[1993,1000,1000,1000,1993,1000,1000,1000]` |
| `0x1FF21/2F/37` | `hydr.pcs_map_x` / `_y` / `_z` |
| `0x1FFD6` | the inlet-pressure map `[3180,8820,2690,8330]` used live by `pressure_manager.cpp:193` |
| `0x1FFF7` | `mech.turbine_drag` |
| bank0 `0x01040` | `mech.ratio_table` |

So every mech/hydr number the car runs is Mercedes' own for this exact part number, and
`tmp/shift_replay/cal_data.h` is genuinely OEM. **The set appears twice** (copy A ~`0x1F0C0`,
copy B ~`0x1F87x`) differing in a few fields — two vehicle variants; know which you are reading.

### The TCC and shift-algo blocks are NOT

- **`SM00` shift-algo pack: 0 of 32 arrays found.** Not OEM data from this ECU.
- **TCC block `71` is not in this ROM.** bank0 holds two different converter characterizations:

  | | multiplier x / z | pump_map_x | pump_map_z |
  |---|---|---|---|
  | egs_db `71` (in the car) | `[0,883]` / `[177,100]` | `[0,104,381,575,674,825,883,1000,1056,1500,2500]` | `[4211,…,2724,0,797,3252,10406]` |
  | ROM **A** @ bank0 `0x0F370` | `[0,917]` / `[179,100]` | `[0,379,500,676,850,891,917,1000,1056,1500,2500]` | `[4333,…,3250,0,1295,5284,17305]` |
  | ROM **B** @ bank0 `0x0F7D4` | `[0,914]` / `[170,100]` | `[0,125,392,573,726,850,914,1000,1056,1500,2500]` | `[4637,…,3712,0,1295,5284,17305]` |

  The coupling point differs (0.883 vs 0.914–0.917) and overrun pump torque is 1.6× higher in
  the ROM. Which of A/B applies is coding-selected and unknown.

  **Tested 2026-09-09** via the replay harness (see `tmp/shift_replay/results_tcc/`): across all
  45 shifts of the 09-08 09:37 log the swap moves input torque ≤ 10 Nm and `p_on`/`spc`
  ≤ 132 mBar (A) / ≤ 102 mBar (B), torque request unchanged. **2–4 % — minor, parked.**
  Not exercised: the TCC lockup controller itself (`torque_converter.cpp` `pump_trq_targ`),
  which is where `pump_map_z` matters most; the harness is open-loop and does not run it.

### What is NOT in this ROM

- **The TFT resistance table.** nag52's `TFT_RESISTANCE_TAB` is the NXP KTY81/110 curve
  (verified against the datasheet: mean −0.5 °C, max 3 °C, exact 1000 Ω at 25 °C). It did not
  come from here.
- **Any temperature schedule for garage fill**, in code or as an obvious table.
- **The EGS52-format `FillingCalibration`.** nag52 decodes this struct but never loads it
  (commented out of `CalibrationInfo`, zero field uses). Sliding its 115-byte layout across the
  whole calibration span in both endiannesses produced only false fits on u8 map data —
  EGS51 does not store fill parameters in that format. Populating nag52's unused fill
  calibration would require tracing the fill routines, not matching a layout.

  One unverified candidate cluster, bank1 `0x1F330`: u16 `[0,500,700,1500,1300,1300,1300,1500,30]`
  then u8 `[25,223,0,1,2,3,4,30,55,75,110,30,81,43,…]`. The `30 55 75 110` run is the first
  thing in the ROM shaped like an ATF temperature axis (and 75 matches
  `hydr.mpc_flush_temp_threshold`). Nothing in bank1 loads a DPTR into `0xF300–0xF370`, so it is
  reached by computed pointer and unconfirmed.

## 7. Traps

- **Odd alignment.** The calibration block starts with a `u8` (`mech.gb_ty`), so the 16-bit
  arrays sit at odd offsets. An early pass read `6600/1400/1200/1200/9000/5700/5600/4500` at an
  odd offset, decided it was a "garage fill block", and was wrong about what it was — it is real
  calibration data immediately after `shift_spc_gain`, but unnamed, because nag52's repacked
  struct diverges from the ROM layout there. **Do not cite a table without a code reference or a
  byte-for-byte match to something known.**
- **`pgrep -f` / `pkill -f` match their own command line.** A `while pgrep -f analyzeHeadless`
  waiter never exits, and a `pkill -f` launched over SSH can kill the launching shell. Use a
  launcher script plus a pidfile (`run_bank0_funcs.sh` / `bank0.pid`, `kill -0 $(cat …)`).
- Long headless runs: launch with `nohup … &` and **poll** briefly; do not block.
- **A Ghidra project carries its creator's username.** These projects were made on the fast
  box as `trampas`; opening them here as `tstern` aborts with
  `NotOwnerException: Project is owned by trampas` and no hint of the fix. The owner is a
  single field in `<proj>/<name>.rep/project.prp` (`STATE NAME="OWNER"`); both projects have
  been rewritten to `tstern` and the originals kept as `project.prp.bak-trampas`.
- **`MOVC` reads the bank that is currently selected**, so a `MOV DPTR,#0xFC3E` in bank1 code
  reads *bank1* `0xFC3E`, not bank0's. The two differ completely: bank0 `0xFC3C/0xFC3E` are
  the engine-speed thresholds 2100/2400 rpm used by `FUN_913D`, while bank1 `0xFC3E` sits
  inside a map's z-data and reads `0x0000`. `FUN_56DE` (bank1) compares engine speed against
  the bank1 value, so its "fast" branch (`INTMEM 0x72 = ROM[0xFF9D] = 80`) cannot be taken on
  this calibration. Always say which bank a `MOVC` constant comes from.
- **Read a byte as u8 or u16 only after seeing which the code does.** Several of the
  engagement constants are u8 (`0xFF78`, `0xFF7B`, `0xFF9F`, `0xFFA1`, `0xFFA2`, `0xFF73`,
  `0xFF9E`) and the neighbouring ones u16 (`0xFF81`, `0xFF87`, `0xFF9B`, `0xFFA7`, `0xFFAD`);
  a first pass of this section published four wrong numbers by guessing.

## 8. Open threads

1. **Read the chip marking off the ECU board.** Unlocks the SFR map for `A5–AF`, `F3/F4/FA/FB`,
   and therefore the peripheral code (ADC, PWM, CAN).
2. **Model the banking in Ghidra** using the `TCON.4` mechanism so cross-bank calls resolve into
   one navigable program instead of two halves.
3. **Locate the analog input path.** The on-chip ADC result registers `D9`/`DA` are *written*
   during init and never read by any real function, and there is no memory-mapped peripheral
   window — every heavily-used external address is plain RAM in `0x0000–0x03FF`. So the TFT and
   other analog inputs arrive by some other route, not yet found. This is the prerequisite for
   any temperature-schedule question.
4. **Decode bank0's `0xFBF7` calibration area** — nine tables (starts `FC00 FC35 FCD4 FD46 FE12
   FE5F FEF3 FF6A FF7E`), including a 7-point rpm axis `[800,1000,1200,1500,2000,2500,4000]` at
   `0xFE55`. These are the OEM shift/torque maps for this exact car; `src/maps.cpp` and the
   `scripts/shift_envelope.py` envelope are hand-derived by comparison.

---

## 9. Output path and solenoid drive (2026-09-09)

Looked for how the ROM drives Y4 (the 3-4 shift solenoid) in P/N and at garage
engagement, to compare with nag52's two behaviours (pre-merge: Y4 off in P/N,
inrush at engagement; post-47c7633: Y4 held on in P/N). **Not resolved** - but the
search mapped the output architecture and ruled a lot out. All addresses bank0
unless stated; only code that decompiles cleanly is cited.

### What the shift solenoids are NOT driven by

- **Not port bits.** Every real-code write to a port is supervisory:
  - `P4.0` (bit `0xE8`, Ghidra mislabels it `HIFLG_0`): cleared wherever the fault
    flag `XRAM[0x78] |= 2` is set (`0x501D/0x504C/0x5061`, `0x6C13`), cleared at
    shutdown (`0x659D`), set once at `0x6DD7` bracketed by `P0.0` pulses - an
    output-enable / external-watchdog line.
  - `P4.4` (`0xEC`): set at init end (`0x6705`), and set/cleared on whether the
    16-bit capture value `{0x81:0x82}` is non-zero (`0x677B/0x69A7/0x69C5/0x6AE3`),
    cleared at shutdown (`0x6593`) - an enable that follows "signal present".
  - `P4.3`, `P4.7`, `P4.5`, all of `P5`: only read.
  - `P2 = 6` at init (`0x66FF`) and `P2.1/P2.2/P2.5` bit toggles near `0x1FC1` /
    `0x2071` - bank/latch housekeeping on the address bus, not outputs.
  - `P1.5/P1.6` and `SFR 0x96` bit 6 are pulsed in loops around writes of
    `0x9C = 0xCF` (`0x6602-0x665F`) - a bit-banged serial link to an external
    part (EEPROM-shaped), not a solenoid.
- **Not an external latch.** Zero `MOVX` writes to any address above XRAM
  (`0x400+`) in either bank.
- **Not a per-gear compare-register write.** A census of every real-code write to
  `0xD2-0xE7`, `0xF3/0xF4/0xF6/0xF7/0xFA-0xFD` finds only: init (`0x6339`,
  `0x6711`), the ADC scan (`0x3ECD`, writes `0xD9/0xDA`), the stub PWM engine
  and T1 ISR (below), and `0x5635` (speed-range word, below).

### What IS there

- **Speed inputs.** ISRs at `0x059C` and `0x05FF` read capture pairs `{E3:E4}` and
  `{E5:E6}`, subtract the previous capture (`{0x3C:0x3D}` / `{0x3E:0x3F}`) and
  store the periods in `{0x8A:0x8B}` / `{0x8C:0x8D}`. So **E3-E6 are capture
  registers for two speed sensors**, which corrects the 'CMH3-CMH5' guess in
  section 3. `0x0664` (INT0) counts a third pulse input into `XRAM[0x1AE]`.
  `FUN_CODE_5635` consumes `{0x8C:0x8D}` and runs a 3-state range selector
  (states 1/3/4, thresholds 625 / 1250 / 3333 with hysteresis, per-state scaling
  via the MDU) and writes the range word to `SFR 0xFD` - input conditioning.
- **One proportional PWM channel, in the shared stub.** Vector `0x0024 -> 0x02AC`
  (ends `RETI` at `0x0520`): a 3-phase scheduler on `XRAM[0x0007]`, period
  `0x1388` = 5000 ticks, demand byte `INTMEM 0x36` (0-238; `0xFF` = off; forced
  to 0 by the `XRAM[0x78]` fault flag), a 16-bit compare-offset table at
  `0x089D` (`0, 4981, 4962, ... ` step -19) indexed by the demand, next compare
  loaded as `{FB:FA} + delta` into `{F4:F3}`, `SFR 0xDD = 0x88 / 0x08` as the
  set/clear control on the match. `XRAM[0x000B]` (0-4, set by `FUN_CODE_1FC6`
  from `XRAM[0x21]` vs `0x7E/0x91` and `XRAM[0x76]` vs `0x46/0xAA` - a
  temperature x load index) selects a nibble from the table at `0x088E`
  (`F0 E0 D0 C0 ...`) OR'd into `XRAM[0x0012]`, a correction to the duty.
  Demand writers: `FUN_CODE_B77B` (MOVC table lookup, clamped against
  `{0x5D:0x5E}`), `FUN_CODE_9F23` (2-byte table via `0x1CA2`), and the special
  codes `0xFE` (`0x6E12`) / `0xED` (`0x6E5D`) in the fault/limp path. This is a
  pressure regulator (MPC or SPC shaped). Which one, unknown.
- **`0x98` pulse sequences.** `MOV 0x98,#0x04 / #0xF7 / #0x10 / #0xDF` at
  `0x6C05-0x6C0E` and `0x6B23-0x6B29` on the fault path - `0x98` is not SCON
  here; it is a keyed write sequence to an undocumented register.

### Where that leaves Y4

The per-gear on/off solenoid drive is not visible as any port, latch or
compare-register write in the real code. Given the `0x98` / `0x96` / `0x9C`
sequences and the A5-AF block, the most likely explanation is a **driver
peripheral behind undocumented SFRs**, which is exactly the section 3 open
thread: the chip marking. Until that is known, the ROM cannot say whether EGS51
holds the 3-4 solenoid in P/N or strokes it at engagement, and nag52's two
readings of that (pre- and post-47c7633) have to be adjudicated by their author,
not by this image.

### Traps hit this time (add to section 7)

- **`FUN_CODE_1CED` is the Keil `switch` dispatcher** (walks 3-byte
  `{addr, case}` entries, `JMP @A+DPTR`). Anything that `LCALL 0x1CED`s is a
  `switch` on A, and the bytes after the call are the case table - which the
  sweep decodes as instructions. That is the "overlapping instruction" at
  `0xD8D2/0xD8D3`. `XRAM[0x390]` is therefore a state byte (0-5, and -1/-2/-3),
  not an output image, and the `MOV P1,@R1` at `0xD92E` sits inside case-table
  bytes: not code.
- **Bank0 `0xE8E0-0xEE85` and bank1 `0xE600-0xEBFF` are data swept as code.**
  Ghidra says "bad instruction data" and the listing has `MOV A,R7` x12 and
  `RETI` mid-stream. Every `SETB P4.2 / P4.6`, `CMEN = R6`, `ORL 0xF4,#0x4C`
  and `MOV 0xF4,@R1` in those ranges is an artefact. Do not cite them.
- **The bank1 `0xEEA0-0xEF90` and `0xFBE0-0xFCB8` byte runs are 2-D maps**
  (header byte, rows of six with three leading zeros, then two axes such as
  `0B 0D 17 2F 30 48` and `02 04 0A 0C 0E 18 2E`), not solenoid pattern tables;
  bank1 `0x5701` references the second of the four at `0xFC3E`.

---

## 10. The chip, the board, and the peripheral map (2026-09-09, from photos)

### Parts read off the ECU (owner's photos)

| ref | marking | what it is | role (inferred) |
|---|---|---|---|
| MCU | **SIEMENS SEC 51C810-N R7.0 C3 GERMANY "SIECO 51"**, date 9919, PLCC | Siemens custom automotive 8051-core ASIC. No public datasheet exists (searched). | everything below |
| U | AMD **AM27C010-90JI** (1997) | 128 KB EPROM = this image | program + calibration, banked |
| U | **74HC573** | octal latch | A0-A7 from the multiplexed bus |
| U | ST **L9341** (1880F9922, Singapore) | quad low-side driver | the on/off solenoids Y3/Y4/Y5 (+TCC?) - **unconfirmed which pin drives it** |
| U x2 | two separate Siemens 7-lead power packages (top-left of photo 1), both printed `RY 930620T QCZ923` (an earlier reading of the first photo as RX/RY was a misread; the owner confirms both are `RY`) - `RY` is part of the device marking, not a pin name, and these are not L9341 pins | unidentified, marking too blurred to read reliably | **MPC and SPC power stages**: owner traced MPC to the 4th and SPC to the 5th MCU pin counting from the top-left corner of the PLCC (2026-09-09) |
| U x2 | Analog Devices **AD22057** | current-sense / sensor-interface amplifier | MPC/SPC current feedback (two channels, two amps) |
| U | Siemens **BTS426L1** (hand-marked "N3") | PROFET smart high-side switch | solenoid supply cut - matches the `P4.0` output-enable line |
| U | `P4383 / H8 MAX`, small power pkg | unidentified | |
| U | `S+M 082790 5513 N` | Siemens+Matsushita part, unidentified | |
| C | `IGB 35V` tantalums | | |

No external SRAM is visible in the two photos. If none exists, every `MOVX`
access in `0x000-0x3FF` is to the ASIC's on-chip XRAM, and that space can
contain hardware registers - see "still open" below. **Please confirm there is
no RAM chip on the other side of the board.**

### SFR attributions established by data flow (bank0 real code unless stated)

- **`0xB8-0xBC` = the CAN module.** `0xBA` = register address (auto-increment),
  `0xB9` = data, `0xB8` bit 7 = update/strobe, `0xBC` = page. `FUN_CODE_46B1`
  is the init: after `0xBA = 0x57` it streams the message-object table, and the
  bytes `42 82 40 C1 62 61 43 41` are exactly nag52's `MS_210 KLA_410 BS_200
  MS_608 MS_310 MS_308 GS_218 BS_208` IDs shifted right by 3 (`lib/egs51_ecus/
  src/GS51.h`). `0x85` = ID `0x428`, which nag52 does not handle. `FUN_CODE_3FC3`
  is the **GS218 transmit**: 6 data bytes from `XRAM 0x7E`, `@R0`, `XRAM 0x93,
  0x92, 0x90, 0x83`, then `0xBA = 8, 0xB9 = 4` (TX request). `FUN_CODE_47A0` is
  the RX (receive) service (`0xFF` = no data), `FUN_CODE_4CDC` the error/re-init path.
- **`0xC1-0xC4` + `P4.3` = the K-line.** `FUN_CODE_2524` is the ISO/KWP
  protocol: `0x55` sync byte, states 0-10 in `XRAM 0x34`, bit timing `0xC2 =
  0x19/0x22`, `0xC4 = 3/0`, `JNB P4.3,$` spins on the K-line input. Its TX
  buffer is `XRAM 0x40-0x53`, filled by the service handlers `37FF 38A7 3964
  3A4B 3AFC`; protocol state in `0x32/0x33/0x3A/0x3C/0x6A`.
- **`0x91` (XPAGE) + `0x92` = the paged analog/input read path** - this closes
  section 8 thread 3. `FUN_CODE_206E`: `XPAGE = 7,5,9,0xB,0x11,0x13,0xF` then
  read `0x92` into `XRAM 0x1D, 0x22, 0x21, @0x80, 0x1E, 0x20, 0x62`. `XRAM
  0x21` is the temperature-shaped variable (compared to `0x69/0x7E/0x91`), so
  **ATF temperature = page 9**. `P2.1` is dropped during the access (chip
  select); `P2` is saved/restored through `INTMEM 0x67`.
- **`0xB3`** = page register for `MOVX @Ri` block copies (Ghidra "IPH1").
- **`0x98`** = a keyed 4-channel refresh register: `FUN_CODE_403A` writes
  `01 FD 04 F7 10 DF 40 7F` (set even bit / clear odd bit, four channels); the
  fault path repeats the middle two pairs.
- **`P2`** is GPIO on this part (`P2 = 6` at init, `P2.1`/`P2.2` toggled). It is
  not the address bus.
- **`P0.6`** <- a status flag (`FUN_CODE_5812`); `P0.7`, `P0.0` strobes.
- **`P5.0 / P5.2 / P5.6`** are three switch inputs polled by `FUN_CODE_5821`
  into bit `0x17` - lever/selector shaped.
- **`0xFD` / `0xFE` SFR** = capture-range words from `FUN_CODE_5635 / 547F`.
- Section 9's "not censused" for `0xB8-0xBC` is superseded by the CAN finding.

### Still open: the on/off solenoid command

Every SFR write in the real code is now attributed. The discrete outputs found
(`P0.6`, `P0.7`, `P0.0`, `P4.0`, `P4.4`), one software PWM channel, CAN and
K-line cannot cover Y3/Y4/Y5 + TCC + two regulators. What remains is
memory-mapped I/O inside the on-chip `0x000-0x3FF` space. The write-mostly
cells there with 3-bit values are **`XRAM 0x0FC-0x0FE`**: written `2/4/5/6` by
the self-test sequencer `FUN_CODE_5E20` (called from 16 places in the
init/test sequence, switching on `XRAM 0x195`) and mirrored every cycle by the
PWM engine (`0x12/0x13 -> 0xFD/0xFE`). Confirming that needs either the SIC810
register map or a board trace from the L9341 input pins back to the MCU - the
latter is a multimeter job the owner can do.

Follow-up on `XRAM 0x0FC-0x0FE`: `FUN_CODE_5635` writes `XRAM 0xF4 = (XRAM 0xF4 & 0xF8) | k`
and then `SFR 0xFD = ` the same byte, i.e. it keeps an XRAM copy of what it puts in the
SFR; `FUN_CODE_5E20`'s timed writes to `0xFC-0xFE` between `0x068E` delays fit the same
pattern. Treat **`XRAM 0xF0-0xFF` as software shadows of the capture/compare SFR block**,
not as hardware. The solenoid latch is not there either. What would settle the output path
now is a continuity trace on the board from the L9341's parallel input pins (and the inputs
of the two 7-lead `RY`-marked packages) back to the MCU pins or to whatever sits in between.

---

## 11. The L9341 frame, and how the ROM drives Y4 (2026-09-09)

> **Superseded in part by section 12.** The frame/SPI model here is right (confirmed by the
> L9341 datasheet, `tmp/datasheet/`), but the channel-to-field map below is wrong by bit
> order, the PWM-engine channel is the **TCC**, not Y4, and the 'Y4 off in N/P' conclusion
> was about the TCC. Section 12 has the corrected map and the real Y4 behaviour.

**Answered, with a board trace to check it.** Reconstructed C and a symbol map
are in [`reconstructed/`](reconstructed/) - our own writing, safe to commit.

### The frame (validated 4/4 against the owner's traces)

`FUN_CODE_068E` is a 16-bit full-duplex SPI exchange with the L9341 through
`SFR 0xC6` (data) / `0xC7` bit 7 (start), chip-select on `P0.7`. The frame is
built in `XRAM 0x12:0x13`, copied to `0xFD:0xFE`, exchanged, and the two status
bytes come back in the same place and are copied to `0x0F:0x10`, where
`FUN_CODE_1EA1` decodes four 2-bit channel states. Four 4-bit fields:

| field | written by | L9341 | solenoid (owner trace) |
|---|---|---|---|
| `0x12` low nibble | bit `0x08`, on/off with inrush 0x0F then hold 4/5/6 by ATF | OUT1 | **Y5** (pin 2) |
| `0x12` high nibble | the PWM engine `FUN_CODE_02AC` (demand `INTMEM 0x36`) | OUT2 | **Y4** (pin 1) |
| `0x13` low nibble | bit `0x09`, same inrush/hold logic | OUT3 | **Y3** (pin 15) |
| `0x13` high nibble | bit `0x0A`, inrush 0x10 then hold C0/B0/A0 | OUT4 | **TCC** or its clamp (pin 14) |

The field-to-channel assignment was derived from the ROM before the traces
were made and matched all four.

### Y4 is not an on/off solenoid in this ROM

Y5 and Y3 are single bits with a 3-cycle inrush code and a temperature-indexed
hold code (`FUN_CODE_0711`, `ROM 0x087F/0x088D`). **Y4 is a PWM channel**: the
stub engine at vector `0x0024 -> 0x02AC` takes demand `INTMEM 0x36` (0-238;
below 14 = off; `0xFF` = idle), converts it through the 16-bit table at
`0x089D` into a compare offset inside a `0x1388`-tick period on `{F4:F3}` vs
the free-running `{FB:FA}` with `0xDD = 0x88/0x08` as set/clear-on-match, and
puts a coarse level (15..11 by the temperature x load index `XRAM 0x0B`) in the
OUT2 nibble. That is the "3-4 is pulsed" behaviour rnd-ash left as a
commented-out line in nag52's P/N branch.

### What Y4 does in N/P and at engagement - on this calibration

- `XRAM 0x334` is the target gear (1-5, 6 = N, 7 = R, 8 = P; the shift decision
  `FUN_CODE_BD50` increments/decrements it). Bank1 `FUN_CODE_2B80` maps it to
  `INTMEM 0xB9` = current gear, **0 for N and P**, 6 for R.
- `FUN_CODE_B8FF` runs the shift-time Y4 modulation (`FUN_CODE_B77B`, 8-point
  curve at `0xFE01` = 0,60,60,98,132,184,242,244, scaled through the MDU with
  constants `0xFE62/64/66`) **only while `2 < gear < 6` and a shift is active**;
  in every other state it writes demand 0. So Y4 is **off in N, P, R, 1st and
  2nd, and off during the N/P -> D engagement**.
- The N/P special case is `FUN_CODE_9F23`: in N/P with `XRAM 0x1C6` bit 3 set
  and `0x1C0` bit 5 clear, Y4 = curve[7] (244, full) for `ROM[0xFE79]` ticks,
  then mark done. **`0xFE79 = 0x00` here** - the pulse is calibrated out on
  part 0215451432. The code is there; this car does not use it.
- Consequence for nag52: neither of nag52's two behaviours is what this ROM
  does. Pre-merge (Y4 off in P/N, inrush at engagement) is closer; the
  post-47C7633 hold of Y4 at full hold current in P/N has no counterpart here.

### Still open

- **Who switches Y5 and Y3 in normal shifts.** In the visible code the only
  writer of bits `0x08/0x09/0x0A` is the workshop actuator test
  (`FUN_CODE_6DE5`, entered when `XRAM 0x1B7 == 2`). Either the L9341's
  switching is by parallel input pins and the frame carries per-channel
  current settings, or there is a writer the sweep cannot see. **Trace the
  L9341 IN pins and its SPI CS/CLK/DI/DO back to the MCU** - that decides it.
- The polarity difference of the OUT4 codes (inrush 0x10, hold C0/B0/A0) vs
  OUT1/OUT3 (inrush 0x0F, hold 4/5/6) is unexplained; the L9341 datasheet's
  frame definition would settle it.

### Also settled this pass

`SFR 0x98` is a **sequence watchdog**: every task function stamps its own byte
of `01 FD 04 F7 10 DF 40 7F` at entry (`0x7331` -> `0xDF`, `0xB838` -> `0x10`,
`0x4D40` -> `0x7F`, `0x5635` -> `0x01`, bank1 `0x236A` -> `0x04`, `0x2C4F` ->
`0xF7`), `FUN_CODE_403A` feeds all eight inside long init loops, and the fault
path feeds the middle four. `FUN_CODE_4020` (`0x9A` = 0x41, 0x20, poll 0x20)
resynchronises it. Bank1 `0xE804 MOV 0x21,A` is data-as-code, not a writer.

### Correction after the MPC/SPC pin trace (2026-09-09, later)

MPC and SPC are driven from MCU pins (4th and 5th from the PLCC's top-left
corner) through the two 7-lead power parts, not through the L9341. The ROM has
two compare-based PWM engines sharing `{F4:F3}` (vector `0x0024 -> 0x02AC`, and
the T1 ISR at `0x0521`), with `0xDD` / `0xFD` / `0xFE` as set/clear controls.
Section 11 attributed the `0x02AC` engine's *hardware* PWM to Y4 because its
demand byte `INTMEM 0x36` also sets Y4's OUT2 nibble; with MPC/SPC on their own
pins, at least one of those engines is a pressure regulator, and **"Y4 is finely
PWM-modulated on a pin" is withdrawn as unconfirmed.** What stands (validated
4/4 by the traces): Y4 = L9341 OUT2, its drive code is the OUT2 nibble, and that
nibble is 0 in N/P/R/1st/2nd and during the N/P -> D engagement on this
calibration. `FUN_CODE_5635` / `547F` (writing `0xFD` / `0xFE` from a period
measured by the capture ISRs) may be the MPC/SPC PWM channel controls rather
than "capture range selectors" - unresolved. To settle: which MCU pins the
L9341's IN2 and SPI lines land on, and whether the two `RY` parts' inputs are the
pins driven by `0xDD`-controlled compare matches.

### L9341 is SPI-only (owner, 2026-09-09): the frame word needs its datasheet definition

The L9341 has no parallel input pins, so every channel is switched through the
SPI word. That makes section 11's open item sharper: in the visible code the
only writer of the OUT1/OUT3/OUT4 fields is the actuator test, and no
computed-address writer of `XRAM 0x12/0x13` exists either (checked both banks).
The word is therefore being read wrongly here. Two clues for whoever has the
datasheet: the T1 ISR (`0x0521`) exchanges `0x0000` **twice** and then tests
bit 1 of the returned byte - a status-read transaction, so zero is probably
read/no-op rather than all-off; and every "on" code the engine puts in the
first byte's high nibble (`F0 E0 D0 C0 B0`) has bit 7 set while idle (`0x10`)
and off (`0x00`) do not - the shape of a write/command flag in bit 15 with the
channel fields below it. Needed: bits per word, which bits are channel on/off
vs current/duty setting vs command flag, and what the device returns.

### Status flag (2026-09-09, late): is the SPI device actually the L9341?

The owner cannot find SPI connections from the MCU to the L9341, and the ROM
never writes the OUT1/OUT3/OUT4 fields outside the actuator test. Two
independent reasons to doubt the section-11 premise that the `0xC6/0xC7`
exchange (CS on `P0.7`) talks to the L9341 directly. Treat "SPI device = L9341"
as **unconfirmed**. Consistent alternatives: (a) a serial-to-parallel latch (a
74HC595-class part, e.g. the unreadable SO-8 next to the AD22057s) on that bus
feeds the L9341's parallel inputs - which would keep the 4/4 field-to-channel
match and explain why no MCU pins reach the L9341; (b) the bus goes to a
different device (the unidentified `P4383 / MAX` or `S+M` parts) and the L9341
inputs come from MCU pins attributed elsewhere. Settle it on the board: follow
the L9341's four logic inputs, and the MCU pin that is `P0.7`'s CS, to whatever
they land on. Until then the reconstructed C's device naming is provisional;
the P/N conclusion about Y4 (field zero in N/P and during engagement) depends
only on the trace Y4 = OUT2 and the ROM's frame-field logic, not on the bus.

---

## 12. Corrected: the solenoid pattern path, and what EGS51 really does with Y4 (2026-09-09, late)

Sources: the ST L9341 datasheet (owner's copy, `tmp/datasheet/L9341_ST_CD00000102.pdf`),
the owner's board traces (Y5 = OUT1 pin 2, Y4 = OUT2 pin 1, Y3 = OUT3 pin 15, TCC = OUT4
pin 14; L9341 SDI <- MCU pin 9 from the top-left corner via 1 kOhm, which is why a
continuity beep never rang; MPC/SPC on MCU pins 4 and 5 via the two `RY` power stages),
and a raw-opcode scan of the image that found the writes the sweep-based regexes missed.
Reconstructed C: [`reconstructed/egs51_outputs.c`](reconstructed/egs51_outputs.c).

### The L9341 word (datasheet Fig. 6, MSB first)

Bits 15-12 = channel 4 duty code, 11-8 = channel 3, 7-4 = channel 2, 3-0 = channel 1.
The ROM sends `XRAM 0x12` first, so:

| ROM field | bits | OUT | solenoid | written by |
|---|---|---|---|---|
| `0x12` high nibble | 15-12 | OUT4 | **TCC** | the demand-0x36 PWM engine (`0x02AC`) |
| `0x12` low nibble | 11-8 | OUT3 | **Y3** | bit `0x08` (RAM 0x21.0) |
| `0x13` high nibble | 7-4 | OUT2 | **Y4** | bit `0x0A` (RAM 0x21.2) |
| `0x13` low nibble | 3-0 | OUT1 | **Y5** | bit `0x09` (RAM 0x21.1) |

Fig. 5: code 0 = output off; for channels 1 and 3 code n = n/16 on; for channels 2 and
4 code n = (16-n)/16 on. That resolves the "inverted polarity" of section 11: Y4's
inrush code 1 is 15/16 and its hold codes 12/11/10 are 4/16-6/16 - identical to Y3/Y5's
inrush 15 and hold 4/5/6. **All three shift solenoids are driven peak-and-hold: 15/16 for
three PWM periods, then 25-38 % by ATF temperature** (`FUN_CODE_0711`, tables `0x087F`,
`0x088D`, `0x088E`, `0x089C`). The TCC's demand byte `INTMEM 0x36` (0-238) is off below 14,
which is why the section-11 "off in N/P/R/1st/2nd, modulated in gears 3-5" statement was
true - of the torque converter lockup. `SFR 0x98` is a sequence watchdog (each task stamps
its byte at entry); `0xC6/0xC7` is the SPI shift register/start bit, CS on `P0.7`, and the
T1 ISR's double `0x0000` exchange is a status read (SDO returns the Fig. 7 diagnostics,
decoded four channels x two bits in `FUN_CODE_1EA1`).

### The pattern path the sweep hid

`MOV bit,C` on `0x08/0x09/0x0A` (opcodes `92 08/09/0A`) at bank0 `0x6BD0/0x6BD7/0x6BE0` -
Ghidra prints the operand as `CY`, which the earlier regexes (`,C$`) missed. That is the
**output stage**, run every cycle by `FUN_CODE_675E` (the main loop, not an init
sequencer) after the scheduler `FUN_CODE_6E6A` has called ~30 task functions: unless
`XRAM 0x1B3` is set, the byte at **internal RAM 0x95** is shifted out, bit 0 -> Y3,
bit 1 -> Y5, bit 2 -> Y4. `INTMEM 0x95` is the solenoid pattern byte; bits 3-6 carry other
flags. Its writers are all in bank1 and reach it through `@R0`, which is why the
`MOV DPTR` censuses saw nothing.

**Shift solenoids during a shift** (`FUN_CODE_2344`, `0x23E9-0x2437`): at shift phase
`INTMEM 0xAA == 0`, the shift index `INTMEM 0xAC` - in nag52's own `GearChange` order,
1 = 1-2, 2 = 2-3, 3 = 3-4, 4 = 4-5, 5 = 2-1, 6 = 3-2, 7 = 4-3, 8 = 5-4 - selects the
solenoid: {1,4,5,8} -> Y3, {2,6} -> Y5, {3,7} -> Y4. That is the 722.6 valve assignment
exactly. At phase 4 (`0x29E3`) all three are cleared: **momentary during shifts, as nag52
does.**

### The engagement state machine (`FUN_CODE_5BB6`, bank1)

Sub-state `INTMEM 0xB4` (0-8) dispatched through the jump table at `0x5C66`; timers
`0xB0-0xB2` from calibration (`ROM 0xFF78` = 10, `0xFF7B` = 26, `0xFF87` table,
`0xFFA1` = 80, `0xFF9F` = 45), target/selector `XRAM 0x334` (1-5 forward, 6 = N, 7 = R,
8 = P), current gear `INTMEM 0xB9` (0 for N/P, 6 for R, from `FUN_CODE_2B80`), and
`XRAM 0x1BD` bit 0 = "{XRAM 0x2EF:0x2F0} above ROM[0xFC3E], cleared below ROM[0xFC3C]"
(`FUN_CODE_913D`; engine-speed-shaped, forced set outside R).

- **State 8 = N/P idle (`0x60A1`): `Y3 off; Y5 ON; Y4 ON`.** EGS51 holds the
  hydraulic-neutral pair in N and P. Entered from N (`0x334 == 6`), from P/R with
  `0x1BD.0`, or on `XRAM 0x1C2` bit 0, with `0xB0 = 80`.
- **Leaving N/P (`0x612E`, `0x6180`): `Y5 off; Y4 off; 0xB4 = 0; 0xAA = 0`** - both
  released first, then the engagement sequence starts from state 0 at shift phase 0.
- State 1 (`0x5CF8`): shift index `0xAC = 1` (1-2), **Y4 off**, timer; an alternate path
  (`0x5D35`) sets Y4 on under a `0xB3 >= 6` condition.
- State 2 (`0x5D44-0x5EDF`): may set **Y3** (1-2 valve) from a `ROM 0xFF81` compare; then
  by `INTMEM 0xB3`: >= 4 -> Y5; == 3 -> Y5 + Y4 (rolling re-engagement into 3rd); < 2 with
  `0xAB >= 3` -> Y5 on, **Y4 off**, `0xAC = 2` (2-3); and **`0x334 == 7` (R) with
  `0x1BD.0` -> Y4 on, state 6** - the only engagement branch that energises Y4.
- States 3-7: timed fill/apply/hold steps (`0x1061` interpolation of the `0xFF87` table,
  `0x7093`), each ending in a pattern update; state 6 waits on `0x1BD` before state 7.

**So for the question this was all for:** EGS51 does not hold Y4 alone in P/N and does
not keep it off either. It holds **Y5 + Y4 together** in N/P, **releases both at the
start of every engagement**, then engages D through the 1-2/2-3 valves (Y3, Y5) with Y4
off and R through the 3-4 valve (Y4). Every engagement therefore strokes its valve from
the off state under line pressure - the property nag52 had before 47c7633 and lost with
the P/N hold. nag52's garage shift routes SPC through the 3-4 valve for D as well as R;
the ROM does not use the 3-4 valve for D at all.

### Files

`tmp/datasheet/` (gitignored): `L9341_ST_CD00000102.pdf` (owner's copy), and the
public `Siemens_1994_8bit_Microcontroller_Handbook.pdf` from bitsavers - the closest
thing to a SIC810 datasheet that exists; none is public for the custom part.

---

## 13. The math block, the calibration pointers, the pressure path and the engagement machine (2026-09-09, pass 3)

Third pass, done entirely on the existing exports with
[`tools/egs51tool.py`](tools/egs51tool.py) (no Ghidra needed; see §14 for the
tooling). Reconstructed C: [`reconstructed/egs51_pressure.c`](reconstructed/egs51_pressure.c);
symbols appended to [`reconstructed/symbols.txt`](reconstructed/symbols.txt). This
section supersedes parts of §2, §3, §5, §6, §8, §10 and §11; each superseded
statement is named below rather than edited in place.

### 13.1 The "reserved" SFRs are the MDU, and the helpers are now readable

`A5 A6 A7 AD AE AF` are `MD0..MD5` of an 80C517-style multiply/divide unit. **The write
order selects the operation, exactly as on the 80C517A datasheet:** `MD0,MD4,MD1,MD5` =
16×16 multiply, `MD0,MD1,MD4,MD5` = 16/16 divide, `MD0..MD5` = 32/16 divide. The
`LCALL 0x1DCA / 0x1DCB` pads are the mandatory wait. That resolves every helper
(common area `0x0C00–0x1CFF`, byte-identical in both banks, so bank1 calls are the same code):

| addr | name | semantics | calls (b0/b1) |
|---|---|---|---|
| `0x0BCC` | `mdu_muldiv_u16` | `(R6:R7 × R4:R5) / R2:R3 → R6:R7`, unsigned; `(x,1000)` pairs are the ubiquitous `/1000` | 96 / 146 |
| `0x0C20` | `mdu_muldiv_s16` | same, signed (abs, count sign flips in R0, negate) | 25 / 40 |
| `0x0C0C` | `mdu_mul16_32` | 32-bit product in `R4:R5:R6:R7` (Ghidra had it misaligned) | 11 / 1 |
| `0x0C7B` | `mdu_div32_ram75` | `R4..R7 / INTMEM{0x75:0x76}`; the divisor is a sensor period | 11 / 1 |
| `0x1061` | `lag_div` | `cur += (target − cur) / R3`; `R3 == 0` returns target | 2 / 69 |
| `0x1412` | `lerp1d_intmem` | clamped two-point lerp on five u16 **values** in INTMEM (`y0,y1,x0,x1,x`) | – / 18 |
| `0x14F3` | `map2d_rom` | bilinear 2-D map from a ROM descriptor (below); `0x1904` = u8-z variant | – / – |
| `0x1CA2` | `dptr_add_a_mul_b` | `DPTR += A×B` (array indexing) | 30 / 58 |

**Ghidra's decompile of anything using the MDU is wrong in the details** (it shows
`FUN_CODE_1dca(x,y)` with made-up arguments and cannot see that `A5..AF` are a unit).
Read the listing for those, or run `MduAnnotate.java` (§14) which comments every call.

The `lag_div` idiom matters: the ramp divisor in `INTMEM 0xB1` is *decremented every
cycle* by `timers_tick` (bank0 `0xE48D`), so `p += (target−p)/n` with `n = 10,9,…,1`
is a **linear ramp that lands exactly on the target** — not an exponential filter.

### 13.2 Corrections to earlier sections

- **§2 / §3 vector table.** The SIC810 has interrupt vectors **three bytes apart** from
  `0x0003`, each a bare `LJMP`, not the 8051's eight-byte table (`egs51tool.py vectors`):
  1→`0664` (INT0 pulse counter), 5→`059B`, 6→`059C`, 7→`05FF` (speed captures),
  8→`006A` (K-line/CAN service), 9→`0521` (SPI status / compare), **11→`01FD` (the
  current-loop ISR, unlisted until now)**, 12→`02AC` (TCC PWM engine), 14→`0662`, 15→`0663`.
  `PrepEntry.java` seeded the wrong slots and got the others only by luck of the sweep;
  use `PrepEntrySIC810.java`.
- **§9 / §11 `0xFD`/`0xFE` are not PWM controls.** `FUN_5635`/`547F` are the
  period→speed conversions for the two speed sensors (`0x0C7B` divides by the captured
  period in `0x75:0x76`; results `{0x83:0x84}` / `{0x81:0x82}`); `0xFD`/`0xFE` hold the
  capture prescaler range (1/3/4). The "MPC/SPC PWM channel controls" reading is withdrawn.
- **§8 thread 3 / §10 `D8–DD` is not an ADC.** `SFR 0xD9` and `0xDA` are the **MPC and
  SPC PWM duty registers**, written only by the PI regulator (`0x3EEC`); the analog inputs
  all come through the paged `0x91/0x92` window. `0xD5` in that code is `PSW.5` (F0), not an SFR.
- **§10 "ATF temperature = page 9" is withdrawn.** ATF is **page `0xF`, 16-bit, averaged
  over 8 samples, linearised in `FUN_2132` to `XRAM 0x17` and published as `XRAM 0x76`**.
  `XRAM 0x21` (page 9, 8-bit) only feeds the on/off-solenoid hold-current index
  (thresholds 126/145) and is most likely the driver/ECU temperature.
- **§5 "calibration tables read through `0x3F5C`"** — `0x3F5C` is the PI step of the
  current regulator (two callers). Calibration is read through the base pointers of
  §13.3, the 1-D lerp `0x1412` and the 2-D map routine `0x14F3`.
- **§6 "SM00 shift-algo pack: 0 of 32 arrays found"** stands for the *values*, but the
  maps exist in the ROM as u8 (§13.4); the earlier search looked for u16.
- **§6 "no temperature schedule for garage fill"** — there is one; it is a *time*
  schedule (§13.6).
- **Bank1 writes no hardware register at all** (SFR census, both banks): bank1 is pure
  control logic, bank0 holds every driver. The `0xDC`/`0xC8` writes reported inside bank1
  `0xEC93..0xFF87` are calibration bytes swept as code.

### 13.3 Calibration: coding-selected pointer sets, and the real block layouts

Bank1 `FUN_20BC` (init) fills **sixteen base pointers `XRAM 0x3B2..0x3D5`** from two
coding bytes, one nibble per pointer, through tables at bank1 `0xE882..0xEA62`
(`egs51tool.py calsets`). `0xFFFF` means "not populated" and sets a fault bit. Every
calibration access in bank1 is `base + offset` (Keil generic pointer with a borrow
fix-up), which is why no `MOV DPTR,#` census ever found the mech/hydr blocks.

| pointer | coding | idx 0 | idx 1 | idx 2 | block |
|---|---|---|---|---|---|
| `0x3D4` | `0x17C` hi | `FE20` | `F77D` | **`F0DA`** | **mech** — `friction_map` at +1, `max_torque_on/off` +0x61/+0x69, `release_spring` +0x71, `strongest_clutch` +0x87; 0xA0 bytes |
| `0x3CE` | `0x17C` hi | `FEC0` | `F81D` | **`F17A`** | **hydr** — layout below; 0x60 bytes |
| `0x3B2` | `0x17B` lo | `F87D` | `F1DA` | – | block after hydr |
| `0x3B4`/`0x3C2` | `0x17B` lo/hi | `EA8C` | `E77E` | – | 4×4 map descriptor (gear × temp) |
| `0x3C8` | `0x17B` hi | `EA96` | `E788` | `E684` | 5×4 map descriptor (gear × ATF) — the fill term |
| `0x3BC` | `0x17B` hi | `F8D6` | `F233` | `EB90` | shift-decision block (`FUN_B9F3/BB02/C144`) |
| `0x3BA`,`0x3C6`,`0x3CA`,`0x3BE`,`0x3C0`,`0x3C4` | `0x17B` hi | … | … | … | shift-timing / SPC / TCC parameter blocks (offsets in `symbols.txt`) |
| `0x3D0`,`0x3D2` | `0x17C` lo | `EAC8`,`EB80` | `E7BA`,`E872` | `E6B6`,`E76E` | lists of four 6×8 descriptors (one per upshift) |
| `0x3CC` | `0x17C` lo | `EB20` | `E812` | `E70E` | list of four 3×2 descriptors |

**This car is coding index 2 for mech/hydr** — `0xF0DA`/`0xF17A` are the blocks that
match the TCU byte-for-byte (§6 called them "copy A"; the third set at `0xFE20/0xFEC0`
was not noticed). The three variants are laid out contiguously (`mech, hydr, post-hydr`
at `F0DA/F17A/F1DA`, `F77D/F81D/F87D`, `FE20/FEC0/–`), so the low-nibble index of `0x17B`
that pairs with hydr index 2 is 1. The other nibbles are unknown; all three variants of
every map are listed by `egs51tool.py desc`.

**Hydr block, ROM layout** (base `0xF17A`, verified against the dump; nag52 names):
`+0 id=3 · +1 p_multi_1=431 · +3 p_multi_other=592 · +5 lp_reg_spring=1828 ·
+7 overlap_circuit_factor_spc[8] · +0x17 …_mpc[8] · +0x27 …_spring_pressure[8] (s16) ·
+0x37 shift_reg_spring=601 · +0x39 shift_spc_gain[8] · +0x49 0,0,0 · +0x4F min_mpc=500 ·
+0x51 filter_factor=15 · +0x52 mpc_flush_temp_threshold=75 · +0x53 0,0,0 ·
+0x56 mpc_no_flush_time=30000 · +0x58 mpc_flush_time=50 · +0x5A 0,0,0`.
nag52's `HydraulicCalibration` holds the same values in the EGS52 order (no gap at
+0x53, `inlet_*`/`pcs_map` inside the struct); in the ROM the inlet map lives at bank1
`0xFFD6` and the pcs map at `0xFF21/2F/37` behind a descriptor. So §7's "unnamed block
after `shift_spc_gain`" is `min_mpc … mpc_flush_time` at odd offsets.

### 13.4 The 2-D map descriptor, and the 65 maps it finds

Keil emitted every 2-D map as a 10-byte descriptor:

```
u8 x_intmem_addr, u8 nx, u8 y_intmem_addr, u8 ny, u16 *x_axis, u16 *y_axis, u16 *z
```

`map2d_rom` (`0x14F3`, `R6:R7` → descriptor) reads the **inputs from internal RAM at the
addresses in the descriptor** — every map in this ROM uses `0xA5:0xA6` (x) and `0xA7:0xA8`
(y), so callers load those first — and does a clamped bilinear lookup. Axes are u8 in
64 of the 65 maps; only the pcs map (`0xEA82` → `0xFF21/0xFF2F/0xFF37`, x = pressure,
y = ATF temperature) has u16 axes. `egs51tool.py desc` lists them all with values,
`map BANK ADDR` prints one as a table; `FindMapDescriptors.java` turns them into typed
data in Ghidra. Geometry per variant: four 6×8 (two families), four 6×10, four 3×4,
four 3×2, one 5×4, one 4×4, plus three 6×6 in bank0 (`0xEB20/0xEC86/0xEF96`, the
converter side). The geometries are nag52's `trq_adder` (6×8 up / 3×4 down) and
`momentum` (6×10 up / 3×2 down) tables; **none of the values match nag52's `SM00`
arrays in any variant**, so the car's shift-algorithm pack is not this ROM's, and this
ROM's own values are now extractable.

### 13.5 The pressure path, end to end

```
bank1 state machines  ──►  P_MPC 0x44:0x45  ──►  pressure_to_demand (D76E)  ──►  i_demand_mpc 0x37 ─┐
                           P_CLUTCH 0x46:0x47 ─► spc_from_clutch (7093) ─► P_SPC_SOL 0x48:0x49 ─► D76E ─► i_demand_spc 0x35 ─┤
                                                                                                                                 ▼
bank0 ISR 0x01FD (vector 11, every 1250 ticks): feedback = page 1 / page 3 (AD22057) scaled by 5ACA  →  PI (3EEC/3F5C)  →  0xD9 / 0xDA = 255−u  →  MCU pins 4 / 5  →  RY stages  →  MPC / SPC
```

- **The three words** are internal RAM, overlaid by each state machine: `0x44:0x45`
  MPC target (mbar), `0x46:0x47` the engaging-circuit target, `0x48:0x49` the SPC
  solenoid pressure from `spc_from_clutch`. The demand stage at bank1 `0x3188–0x3198`
  is unconditional: `0x35 = D76E(0x48:0x49)`, `0x37 = D76E(0x44:0x45)`.
- **`spc_from_clutch` (`0x7093`)**: `shift_reg_spring + clamp(20·τ + p_clutch, P_SPC_MAX) ·
  shift_spc_gain[idx] / 1000`, with `τ` a torque-shaped byte (`XRAM 0x167/0x168/0x174` by
  phase) and `P_SPC_MAX` (`XRAM 0x273:0x274`) set per shift in `shift_setup` (`0x2BB2`).
  This is the OEM form of nag52's clutch→solenoid pressure relation.
- **`pressure_to_demand` (`0xD76E`)**: line model `p_multi_{1|other} × (lp_reg_spring +
  P_MPC) / 1000` (or a per-shift lerp over ROM `0xFFE4..` while shifting), the **inlet
  map** `3180..8820 → 2690..8330` (ROM `0xFFD6`, the map nag52 already uses live), then
  the **pcs map** `(pressure, ATF) → mA`, then `× 10 / 45`: **the demand byte is
  4.5 mA per count (255 = 1147 mA)**.
- **The regulator**: per channel a 16-bit integrator resting at `0x8000`, reset while
  the demand is 0; `I ±= Ki·|e|` saturating, output = high byte of `I − 0x8000 ± Kp·|e|`,
  saturated, inverted into the duty register. **Kp = 4, Ki = 2** (ROM `0x0B38/0x0B39`),
  period = `ROM[0x0B3A:0x0B3B]` = 1250 counter ticks. Feedback scaling constants
  `XRAM 0x188..0x18D` are per channel and not in ROM (EEPROM trims, ?).
- **The overlap computations** (`FUN_8200/80BC/7DDF/6FEE/8836`) use
  `overlap_circuit_factor_spc/mpc[idx]`, `…_spring[idx]` and the `+5+idx` percent table of
  block `0x3BE` with `/1000` and `/100` scalings — the same structure as
  `pressure_manager.cpp`. **`FUN_5480`** is the MPC line/flush logic: `min_mpc_pressure`,
  `filter_factor`, and the flush alternation between `mpc_no_flush_time` and
  `mpc_flush_time` gated on ATF ≥ `mpc_flush_temp_threshold`.

### 13.6 Temperature looks to be stored as °C + 50 — and nag52 reads the same numbers as °C

Evidence, in order of strength:

1. **The substitute value.** When the ATF sensor reads open/short (`XRAM 0x15` bit 7) the ROM
   uses `XRAM 0x97` instead, and the CAN receive service loads it as **`byte + 10`** from an
   engine frame (`FUN_47A0`: read CAN object at register `0xBA = 0xA8`; `< 0xD8` → `+10`,
   else the sentinel `0xE1`). Every MB engine temperature byte on this bus — `T_MOT` and
   `T_OEL` alike, both in `MS_608`, which is the frame nag52 itself decodes as `T_MOT − 40`
   (`can_egs51.cpp:176`) — is in **°C + 40**. A substitute of `+10` on a °C+40 byte is a
   °C+50 value, and this holds whichever of the two bytes it is. (Which frame and byte the
   CAN object at `0xA8` actually is has **not** been pinned — the acceptance table streamed at
   `0xBA = 0x57` gives the IDs but not the object-to-window mapping. That is the one gap in
   this argument, and it does not change the conclusion, only the label.)
2. **The measured range.** The linearisation is a straight line,
   `XRAM 0x17 = ((mean8 × 177) >> 8 − 52) × 2`, over an 8-sample mean of paged input `0xF`.
   Full scale maps to about **−50 °C … +198 °C**: the low end sits exactly at 0 and goes
   negative below it, which is what an offset encoding looks like and not what a plain °C
   reading would do.
3. The boot default `ROM[0xFF01] = 0x82` = 130 → **30 °C** assumed at power-up, a sane
   default; read as plain °C it would be 130 °C.

Consequences, if the encoding is °C + 50:

| ROM number | nag52 reads | ROM means |
|---|---|---|
| `hydr.mpc_flush_temp_threshold` = 75 | 75 °C | **25 °C** |
| `pcs_map_y` = 25 / 70 / 110 / 200 | °C | **−25 / 20 / 60 / 150 °C** |
| engagement-time axis 20 / 70 (`0xFF91/92`) | – | −30 / +20 °C |
| 5×4 fill map axis 30 / 55 / 75 / 110 | – | −20 / 5 / 25 / 60 °C |
| solenoid hold-current thresholds 70 / 170 | – | 20 / 120 °C |

The pcs map is used live by nag52 with the ATF in °C, so at 45 °C it would interpolate
between rows the OEM meant for 20 °C and 60 °C; the flush threshold would be off by 50 °C.
**Nothing in nag52 was changed by this pass** — this is a calibration-*interpretation*
finding, and acting on it means re-basing every temperature axis at once. The decisive test
is cheap and belongs to the owner: park the car at a known ATF temperature and compare the
value the TCU reports with what the OEM tables expect. Note that the sensor is a KTY-class
part (a straight-line fit, no resistance table in the ROM, consistent with §6) and that our
own TFT curve reads 7–10 °C high — so the check needs a real reference, not the TCU's own
number alone.

### 13.7 The engagement machine, with its pressures and times

`FUN_5BB6`, sub-state `INTMEM 0xB4`, fully transcribed in `egs51_pressure.c`. What §12
lacked — the numbers:

- **N/P idle (state 8):** `Y5+Y4` held; `P_MPC = 0` (maximum regulator current, minimum
  line pressure), `P_CLUTCH = 200`, `P_SPC_SOL = 800`; leaves after 80 cycles when a range
  is selected, ATF ≥ 0 °C and the speed word is below `ROM16[0xFFAD]` = 1005 (fast path) or
  the `0x1BD` engine-speed flag allows (normal path): **both valves released, state 0**.
- **States 0–2:** arm (`≥ 45` cycles for 4-3), set `P_MPC = 1500` (`ROM 0xFF87`),
  `P_CLUTCH = 4000`, choose the valve (Y3 above the speed threshold `ROM16 0xFF81` = 111; `Y5`,
  `Y5+Y4`, or `Y4` for R by `INTMEM 0xB3`), load the **fill time** `t_lerp_150_40` =
  150 cycles at ≤ −30 °C → 40 cycles at ≥ +20 °C (ROM `0xFF73`/`0xFF9E`, axis
  `0xFF91` = 20, `0xFF92` = 70) and the ramp divisor `n = ROM[0xFF78] = 10`.
- **States 3/4/7:** `P_MPC` and `P_CLUTCH` ramp linearly to their targets over the 10
  cycles, `P_SPC_SOL` follows through `spc_from_clutch`; at the end of the fill time the
  valves are dropped (3, 7) or Y3→Y4 is swapped and a hold of `t_lerp_40_7 + 26` cycles
  runs (4). **State 5** settles at `P_MPC = 4500` with SPC off, then re-arms.
- The per-gear × temperature **fill term** (`FUN_6856`, 5×4 map at `0x3C8`: 30/81/43/30/41
  at −20 °C down to 8/7/7/9/6 at 60 °C, plus a per-clutch byte from `[0x16D + clutch]`,
  possibly adaptive) is used by the *shift* functions, not by this machine.

The scheduler cycle time is still unmeasured, so all times are in cycles of bank0
`FUN_6E6A` (whose task order is: `E48D` timers, `BA18`, `BC4A`, `BD50` target-gear
stepper, `BE8E`, `BEC3`, `BFD5`, `920F`, `C496`, `C6C6`, bank1 `236A`, `C6C6`, `CA22`,
`CA65`, bank1 `2C4F`/`CE9F`/`AF12`/`D9C8`/`B708`, `D456`, `B838`, `E01E`, `E0CB`, `E214`,
`913D`, `7331`, `E260`, `CFB1` GS218 compose, `D259`).

### 13.9 What was verified, and how the check fails

`tools/egs51tool.py verify` re-derives the two block layouts of §13.3 from the ROM at the
coding-selected bases and compares all 25 fields against the TCU's own calibration
(`tmp/shift_replay/cal_data.h`); it exits 1 on any mismatch and prints `NO DATA` rather than
`ok` when it has nothing to compare. Current result: **25 fields checked, 0 mismatches** —
the hydr block at `0xF17A` and the mech block at `0xF0DA` are byte-for-byte the car's, at
the offsets documented above, which is what licenses reading the surrounding code as the
OEM pressure logic. Proven to fail (§7 rule 7): moving the hydr base one byte to `0xF17B`
gives `25 fields checked, 13 mismatches`, exit 1; a missing `cal_data.h` gives `NO DATA`,
exit 1.

One field does not match and is not a defect: the ROM byte at `mech+0` is **`0x33` = 51**, an
id/version byte, whereas nag52 stores `gb_ty = 0` there. The hydr block's own `+0` is `3`.
Every array after them matches exactly, so the first byte is a block id, not `gb_ty`.

### 13.8 Where this leaves the questions of §8

1. Chip marking: read (§10); the MDU and vector table are now decoded from behaviour.
2. Banking model in Ghidra: still open; the tooling in §14 works around it.
3. Analog input path: closed (paged window; ATF = page 0xF → `XRAM 0x76`).
4. Bank0 `0xFBF7` area: read by `FUN_7331` (24 cells, the big bank0 machine), `889C`,
   `9538`, `9B0A`, `A04B`… as scalar parameters (`egs51tool.py calrefs 0 f000`); the
   earlier identification of bank1 `B9F3/BB02` as shift-point selection was wrong.
   Complete native translation establishes that these are inside the B708
   completed-shift adaptation stage. Bank1 `1DD0` qualifies signed torque and
   returns a mode value; it does not write X75. Bank0 1DD0 produces physical
   selector/range X75. Bank0 7331 automatic demand (IRAM AB) and the complete
   normal scheduler are now translated; see the current port status linked above.

Still not decoded: the shift-execution phase machine (`INTMEM 0xAA`, bank1 `2344`/`D9A0`
and the `0x33D6/0x37CC` family that calls `spc_from_clutch`), the shift-point maps, the
TCC controller, adaptation (whether `[0x16D + clutch]` is learned, and the EEPROM link),
the torque request (`FUN_CFB1` composes GS218). Each is now a bounded job with named
entry points.

## 14. Tooling for the next image (EGS52 or another EGS51)

Everything below is ours and committed.

**[`tools/egs51tool.py`](tools/egs51tool.py)** — works on the `DumpAll.java` exports plus
the image, no Ghidra session needed: `asm` (listing slice), `fn` (enclosing function),
`xrefs`, `calrefs` (which functions read which calibration cells), `desc` / `map` (find
and print every 2-D map, match values against `cal_data.h`), `calsets` (decode the
coding pointer tables), `find` (bytes → function), `mdu` (census of helper calls with
semantics), `vectors`, and `verify` (§13.9: re-derives the block layouts and checks all 25
fields against `cal_data.h`, exit 1 on mismatch, `NO DATA` when it has nothing to compare).
Every question in this pass was answered with it.

**Ghidra scripts (`ghidra/`)**, all headless-runnable; `ghidra/run_annotate.sh 0|1` applies
the whole set to an existing project without re-analysis (bank1: 11 vectors, 419 MDU calls
commented, 66 map descriptors, 9 jump tables, 103 symbols; bank0: 11 / 264 / 3 / 3 switch
tables + 7 jump tables / 131 symbols):

- `PrepEntrySIC810.java` — seeds the 3-byte vector table (use instead of `PrepEntry.java`).
- `MduAnnotate.java` — names the MDU/library helpers, comments every call with its
  semantics, labels the SIC810 SFRs (`MDU_MD0..5`, `XPAGE`, `SPI_*`, `PWM_*_DUTY`, …).
- `FindMapDescriptors.java` — finds the descriptors, converts descriptor, axes and z to
  typed data with labels and references (the sweep had them as instructions).
- `KeilSwitchTables.java` — turns each `switch` case table after an `LCALL ?C?CCASE`
  back into data and adds the jump references (§9's "overlapping instruction").
  3 tables / 34 cases in bank0; bank1 never calls the dispatcher.
- `LjmpTables.java` — the *other* table form: `MOV DPTR,#table … JMP @A+DPTR` over a run of
  `LJMP`s, which Ghidra reports as "Could not recover jumptable" and leaves with no outgoing
  flow. Labels the table, wires a computed-jump reference to each target and creates the case
  functions. 9 tables / 108 targets in bank1 — including the engagement machine at `0x5C66`,
  whose nine states were unreachable code before this.
- `ApplySymbols.java` — applies `reconstructed/symbols.txt` (code, XRAM, INTMEM, SFR).

What a Ghidra *plugin* would add over these scripts is a banked-memory model
(`TCON.4` selecting the bank for cross-bank `LCALL`s) so one program holds both
halves; that is a processor-spec/loader job, not a script, and is the one piece not
done. For an EGS52 image (a different MCU, C167-class) the descriptor/MDU parts do
not transfer, but `egs51tool.py`'s calibration-matching and `calsets`/`desc` logic
and the discipline of §7 do.

### PCB clock observation (2026-09-10)

The owner reports a **4 MHz crystal for the processor**. ROM bank0 0B3D sets
10,000 counter ticks per main loop, and 0B3A sets 1,250 per current interrupt.
The 8:1 cadence is established. The SIC810 counter divider is still required
to derive physical periods; do not equate crystal cycles to counter ticks.
