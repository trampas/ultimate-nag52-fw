# EGS51 ROM reverse engineering (A0215451432)

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
| U x2 | two separate Siemens 7-lead power packages (top-left of photo 1), each printed `RX 930620T QCZ923` / `RY 930620T QCZ923` - `RX`/`RY` is part of the device marking, not a pin name, and these are not L9341 pins | unidentified, marking too blurred to read reliably | two identical parts -> the two current-regulated channels (MPC/SPC) |
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
  the RX service (`0xFF` = no data), `FUN_CODE_4CDC` the error/re-init path.
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
of the two 7-lead `RX`/`RY`-marked packages) back to the MCU pins or to whatever sits in between.

---

## 11. The L9341 frame, and how the ROM drives Y4 (2026-09-09)

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
