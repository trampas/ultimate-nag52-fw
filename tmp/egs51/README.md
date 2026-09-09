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
