# EGS52 reconstructed C

This reconstruction uses the **decoded** `A0325452132.FLS` image, mapped at
CPU addresses `0x080000..0x0fffff`. The previous C was derived from scrambled
bytes and has been deleted. Function addresses here are CPU addresses;
subtract `0x080000` to locate the same bytes in the FLS or decoded file.

## What to read

- `egs52_reconstructed_clean.c` and `egs52_math.h`: readable, compilable native
  C for 55 arithmetic, lookup, control, status, memory, and compiler-runtime helpers. These are checked against execution of
  the original decoded instructions. This is the file to use for the verified
  ramp, weighted filters, percent blends, interpolation, curves, root estimate,
  absolute value, pointer conversion, PID, all three map types, signed curves,
  32-bit root/vector estimates, CRC, and forward byte-copy behavior.
- `functions/`: broader automatic C reconstruction. Every file is explicitly
  marked **unverified decompiler C**. Names backed by evidence come from
  `../tools/symbols.csv`; unresolved roles retain their addresses.
- `functions_index.csv`: every discovered function's source location, byte
  count, instruction count, publication status and naming evidence. Do not
  infer validation from a descriptive name.
- `egs52_vectors.c`: exact primary and secondary vector destinations as C data.
- `firmware.asm`: decoded bytes and instructions for address-level review.
- `calls.csv`: recovered direct call edges. Computed targets are not exhaustive.
- `unresolved.csv`: entries with known decompiler failures or special register
  ABIs. Their misleading C bodies are not retained and no empty stubs replace
  them. Register-ABI call sites use the checked-in processor fixups.
- `coverage.json`, `verification.txt`, `processor_verification.txt`, and the
  manifests: reproducible coverage, checks and provenance.
- `../tools/native_abi.csv`: instruction-backed register and user-stack
  signatures applied before decompilation. These describe the ROM interface;
  the native host API separately exposes memory/state where needed.

**This is not a fully verified whole-firmware C implementation.** The automatic
files are analysis listings, not independently buildable host modules or a
bootable ECU image. They retain Ghidra's type names, segmented-pointer notation,
and inferred declarations. In that C166 data model, `int`/`uint` are 16 bits,
`long`/`ulong` are 32, and ordinary near pointers are 16. Compiling these listings
as ordinary host C would not establish equivalence.

Function discovery follows vectors, direct calls and the explicitly audited
callback layouts in `callback_tables.csv`. Calibration data is not blindly swept as
instructions. Data-driven roots and individual function boundaries remain
provisional. Function counts include vector entries and are not a measure of
how much transmission-control behavior has been verified.

## Build and verify native C

```sh
python3 tmp/egs52/tests/verify_math.py
```

The runner compiles with C11, warnings as errors and undefined-behavior
sanitization. It then executes the original firmware bytes with a separate
Python instruction oracle and compares return values and, for PID, persistent
state and the integral-term RAM write. CRC tests check far-address reads across
segment/24-bit boundaries, and copy tests compare RAM including overlapping
ranges. Random cases have a fixed seed.

The API documents valid curve axes and division domains. PID's individual
products divided by 1000 must fit a signed word, matching the original DIVL
instruction's valid range. The model does not invent division-overflow results.
For the percentage blends, two divisions truncate **separately**. The root
helper performs exactly three Newton steps and returns zero for inputs 1–7;
it is not replaced by a mathematical integer square root.

## Rebuild the broader analysis

```sh
python3 tmp/egs52/tools/rebuild.py
```

This runs the decoder checks, native tests and 49 processor regression
assertions, creates a fresh Ghidra project, applies `../tools/symbols.csv`, then
publishes filtered source and inventories. It never expands an old analysis
database. Failed runs do not publish C. Generated files are replaced so stale
function names and removed bodies cannot survive a rerun. Native C/header and
this README are maintained by hand. `verification_manifest.json` binds the
report to the native C/header and every test script; changed evidence requires
a new passing rebuild.

See [processor corrections](../tools/PROCESSOR_FIXES.md) for the exact fixes and
remaining limitations. No production NAG52 firmware or calibration is modified.

## Lookup details recovered from instructions

- Word maps at `0x0df506` and `0x0df72e` interpolate the two X spans,
  truncate each quotient, then interpolate those intermediate values along Y.
  Values are row-major (`cells[y * nx + x]`). Inputs clamp to the axes, but
  even at the endpoints the map evaluates its divisions.
- The unsigned word map interprets each wrapped cell difference as signed,
  then uses unsigned multiplication/division of its magnitude. A cell change
  from 0 to 65535 therefore acts like a change of -1. Replacing this with a
  generic unsigned bilinear interpolation changes firmware behavior.
- The byte map at `0x0df980` wraps its computed cell indices modulo 256.
  This is preserved, including when dimensions imply more than 256 cells.
- The signed curve and map preserve 16-bit subtraction before signed multiply
  and division. The header states their valid division domain.
- The 32-bit root estimate has an additional threshold at 100000 and returns
  the low word after three Newton steps. The vector helper sums unsigned
  squares modulo 2^32 before calling it; this is not an exact hypotenuse.

The instruction oracle covers the tested arithmetic/RAM subset. Its EXTS
support is deliberately restricted to a single following indirect load; it
rejects unsupported uses. Near-memory helper tests assume ordinary RAM and
exclude active register/peripheral/stack storage.

The rebuild applies explicit argument storage for the native arithmetic and
memory helpers before decompiling callers. This repairs lost register inputs
such as the middle weighted-average argument in the shared tail at
`0x0e0036`. Published listings are checked against the known ROM argument
counts; a missing argument causes the listing to be withheld. This check does
not establish the semantics or unknown signatures of other calls.

## Control and status RAM helpers

Eight additional native routines preserve observed RAM operations rather than
assigning unproven physical meanings to the variables. Their host APIs take a
64-KiB near-RAM image; the ROM signatures in `native_abi.csv` retain the actual
register inputs, with the shared filter tail kept inside its actual caller.

- `egs52_update_scaled_difference_d712` reconstructs the entire scaled
  difference / previous-value update / threshold / weighted-filter sequence at
  `0x0e0000`, including its shared tail at `0x0e0036`.
- Clamp, byte-delta, percentage-term, and signed-classification helpers retain
  wrapping operations in their original order. In particular the initial sum
  wraps before the offset/clamp routine applies its lower and upper limits.
- `egs52_initialize_fault_status` fills exactly 128 status bytes with `0x28`,
  writes the enable word at `0xf84c`, and returns zero.

Tests compare the modeled RAM regions, including untouched neighboring bytes,
against original instructions. Pointer-dependent routines assume ordinary
near RAM; they do not emulate peripheral accesses or arbitrary DPP mappings.
The signed scaled product and unsigned scale quotients must fit the DIVL/DIVLU
word result, as documented in the header.

The five native fault queries at `0x09f7d8..0x09f856` read status bits 4, 3,
2, and 7 or the separate word bitmap. Tests cover every byte-sized index with
random nonzero upper register bytes, checking that the upper byte is ignored.
The queries do not check the 128-entry initialization bound: indices 128..255
read the following RAM, including the adjacent bitmap. The native C retains
that behavior instead of silently adding a bounds check.

## Boot dispatch data and false function roots

`egs52_boot_dispatch.c` contains the exact 35 records from two boot dispatch
arrays, starting at `0x08028c` and `0x08031c`. Each record consists of a far
callback followed by packed metadata whose low byte selects the service.
Callbacks have observed `egs52_boot_service_*` names where no prior evidence
name existed; these names describe their table association.

The previous generic pointer-pair scan incorrectly treated metadata values
`0x000e0034` and `0x000e0036` as function addresses and could miss real callbacks
next to non-address metadata. The typed scan now seeds only callback fields
and excludes nearby memory descriptors from generic pointer discovery. Both
false entries are rejected by the artifact check. Code at `0x0e0036` remains
a verified shared tail within `egs52_update_scaled_difference_d712`, represented
by a static C helper; it is no longer advertised as an independent ROM function.

The table layout is confirmed by the dispatcher instructions: `0x082a2a`
loads offset `0x028c` with page `0x20`; `0x082a36` compares record byte +4
with `0xf582`; `0x082a82..0x082a86` loads the first two words as an indirect
callback. The loop advances eight bytes and compares against 18 records at
`0x082a94`. The alternate path at `0x082a9c` uses offset `0x031c` and a
17-record limit at `0x082b02`. Bytes +5..+7 contribute permission nibbles,
not addresses. These instructions support the typed table discovery above.

## Recovered control flow and names

All 33 identified switch-table sites have explicit, byte-checked destinations,
including nested tables inside the large state machines. The two startup RAM
self-test continuations use their observed R4 return destinations. These are
not modeled as ordinary calls. `recovered_jumps.csv` records each table, bank,
count, owner and target list; `../tools/jump_tables.csv` records its evidence.

`structural_names.csv` names remaining routines from observed near-memory
reads, writes or call targets. Such names describe instruction structure;
they do not assert a transmission-control role. Curated names and their
confidence remain separate in `functions_index.csv`.

## Compiler-runtime interfaces

The native source also models full 32-bit multiplication/division, far
word-pair loading, register-state byte/word copies, and both boot/application
far-call trampolines. The C header states their register and pointer contracts.
Zero-count register copies still perform one transfer, matching the ROM.
Far loaders advance the pointer by two bytes, despite reading two words.

Trampoline tests execute the original PUSH/PUSH/RETS sequence into actual
firmware targets. The independent oracle uses separate hardware SP and user
R0 stacks, including nested CALLS and far returns. Callback interfaces expose
far memory and far execution without inventing hardware implementations.

Some automatic listings contain `__write_psw_bits(mask, value)`. This is an
architectural operation: update exactly the selected PSW bits, preserving the
others. It represents an explicit instruction write, including interrupt
control, and prevents the decompiler from deleting the effect. It is not a
ROM function or an ordinary host library call. Implicit arithmetic flags
remain in the processor model. Bodies with unresolved entry-register values
continue to be withheld.

The three native PSW helpers additionally compare all 65,536 possible initial
PSW words with a separate instruction oracle. They preserve the actual final
condition flags; save/disable takes the preserved caller R6 value because its
restoring MOV supplies those flags. These are sequential instruction models,
not interrupt-delivery or cycle-timing simulators.

Concurrent rebuilds are rejected. A rebuild also rejects publication if any
source, test or tool input changes during its run, so the recorded evidence
cannot silently describe a different revision from the analyzed instructions.

The signed register/stack interpolation helper at `0x0d30f2` shares the
verified signed-axis arithmetic while retaining its distinct ROM ABI. The
indexed record-word helper at `0x0a626c` is tested for every byte index and
limit pair, including the switch between the EF00 and EE00 record arrays.

## Audited callback roots

`egs52_callback_tables.c` preserves the exact pointer cells and diagnostic
records used to discover table-only functions. Null-separated scheduler lists
and records with intervening metadata must not be reduced to adjacent pointer
pairs: that misses real callbacks. Their layouts are checked in
`../tools/callback_tables.csv` and all nonzero entries must resolve to functions.

The unrestricted pointer-pair scan has been removed. Calibration words at
`0x0b0534`, `0x0c1f4c` and `0x0c2258` had incorrectly created function entries
at `0x0d2f00`, `0x0a000a` and `0x0a01f4`. These are interior instructions in
real callers, not independent functions. The rebuild rejects those false roots
and checks that their owning functions retain their recovered bodies.

The FD02 bit test also models its PSW bit-6 write and final flags. Request
staging at `0x09eee4` is checked for all 256 status bytes, with randomized
four-word payloads and comparison of surrounding RAM. Its fourth ROM argument
is on the R0 stack; treating R15 as that argument loses the actual request data.

Three boot interrupt routes (`0x0835f4`, `0x083600`, `0x08360c`) now have
native C with explicit word-I/O and control-event callbacks. Tests compare
every read/write, PSW/DPP3/MDH at callback boundaries, and the forwarding target
or watchdog/reset sequence. The shared reset tail is a static helper. Models
stop at the external transfer/reset boundary and do not simulate asynchronous
interrupt arrival, watchdog timing, or hardware operation after reset.
