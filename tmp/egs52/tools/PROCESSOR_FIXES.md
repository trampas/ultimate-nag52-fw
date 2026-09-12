# Reproducible C166 analysis corrections

Upstream module: [keyhana/c166-ghidra-module](https://github.com/keyhana/c166-ghidra-module),
local source checkout commit `6a579b9a6f594fb53250e5e43a9af6b27ebf216c`.
The installed baseline had additional local changes; its `c166.sinc` SHA-256 is
`fe4cc16e49509ec9cbdbc904372731648818bda78011eaa25e024baa1d88c6f0`.
The MIT license is included in `LICENSE.C166_MODULE`.

`patch_c166_module.py` preserves that baseline as `c166.sinc.upstream` and
`c166.cspec.upstream`, then deterministically reapplies the corrections.
`patch_c166_module.patch` records the SLEIGH changes. The baseline is tooling
input, not a valid reconstruction of the ECU. Generated manifests fingerprint
all scripts used by the rebuild.

Instruction reference: *Infineon C166 Family Instruction Set Manual*, V2.0,
2001-03, supplied in the module's `data/manuals/` directory. In particular,
BFLDH and BFLDL have different physical operand byte orders (pages 52–53).

## Corrected behavior

- **BFLDL mask/data byte order.** `0A 89 FF 84` writes SYSCON's low byte to
  `84`; it does not force it to `FF`.
- **Prefix lifetime.** EXTR/EXTP/EXTS effects begin at the next instruction,
  apply for the encoded count, and expire afterward. Clearing prefix state
  while decoding the last covered instruction had selected the wrong SFR.
- **Dynamic address translation.** Register-based EXTP/EXTS values are retained
  as runtime registers. Near addressing selects the DPP from the wrapped sum
  of register and displacement. No unknown page is silently replaced by zero.
- **Same-register indirect MOV.** `MOV Rn,[Rn]` uses the normal memory operation;
  an upstream switch-table heuristic had bypassed prefix and flag semantics.
- **DPP/PSW aliases.** Direct SFR reads/writes reference the same registers used
  in address translation and flags, rather than separate RAM variables.
- **PSW destination rules.** BMOV/BMOVN destination encodings now alias PSW,
  just like their source encoding. Explicit PSW bit/field writes preserve all
  other bits; word writes do not receive an additional flag update (manual
  page 35). `c166_psw.sinc` supplies the specialized constructors used here.
  `__write_psw_bits(mask, value)` preserves explicit control effects in the C
  output. Its emulator callback only acknowledges an already-executed write.
- **Shift/rotate counts and flags.** Counts use their low four bits. Right
  shifts put the last bit shifted out into C, including bit zero; V records
  earlier discarded bits. ROR clears V. Zero-count shifts clear C and V.
- **Hardware stack.** PUSH/POP and SCXT use SP. R0 remains the compiler's user
  stack. Compiler call/return analysis remains a semantic decompiler model,
  not a cycle-accurate hardware call-stack emulator.
- **C data model.** Near pointers and `int` are 16 bits; `long` is 32 bits.
- **Compiler helper ABIs.** Call-site fixups describe the register effects of
  near-to-far conversion, 32-bit multiply/divide, far word-pair loading, and
  the PUSH-R5/PUSH-R4/RETS indirect-call trampoline. The trampoline must never
  be exported as an empty function.

`c166_addressing.sinc` and `c166_runtime_fixups.xml` are checked-in inputs to the
patch. R0 stack simplification assumes the normal compiler ABI: internal RAM
and DPP3=3 outside an explicit memory prefix. Startup's arbitrary register/RAM
self-tests are not covered by this ABI assumption.

## Regression gates

`CheckEgs52Processor.java` executes short synthetic instruction sequences using
Ghidra's p-code emulator. It checks both bit-field orders; one- and two-instruction
EXTR expiration; dynamic EXTS and EXTP; same-register MOV under EXTS; DPP
selection after indexed-address carry; direct DPP writes; and hardware SP/R0
separation; masked shift/rotate counts and rounding/carry flags; PSW source
and destination aliases; preservation of non-destination PSW bits; and explicit
PSW write visibility. A clean rebuild requires all 49 assertions to pass.

The independent Python oracle runs original decoded firmware instructions for
the native C tests. It implements only the tested opcode subset and fails on
unsupported opcodes, divide errors and runaway execution. It is not a hardware
emulator, and passing these tests does not certify all instruction semantics
in the third-party processor module.

## Remaining analysis limits

The decompiler can still infer the wrong register/stack ABI, alias memory
incorrectly, or fail to resolve an indirect jump. These are tracked as
unresolved work. The publication step rejects recognizable failures and
labels every surviving automatic body **unverified**. It does not claim that
lack of a warning establishes correctness. The only verified native functions
are those identified in the reconstruction index and differential test report.

## Established function signatures

`native_abi.csv` records instruction-tested register and R0 stack locations.
`RecoverDecodedEgs52.java` applies them as custom storage before decompilation.
This prevents the decompiler from erasing a live argument when compiler helper
p-code or inferred prototypes leave gaps (observed at the weighted filter call
in `0x0e0036`). ROM far addresses, split words, and implicit RAM side effects
are deliberately distinct from host-native API parameters. Listing publication
rejects calls with the wrong count for one of these established signatures.
