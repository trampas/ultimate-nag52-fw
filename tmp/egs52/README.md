# EGS52 A0325452132 reconstruction

Start with [reconstructed/README.md](reconstructed/README.md) and its coverage
report. The original `A0325452132.FLS` is the immutable input; it is **not in
CPU byte order**. Disassembling it directly produces false functions.

Each little-endian 16-bit word has the following data-bit permutation. For raw
bit numbers 0 through 15, the corresponding CPU bit numbers are:

```
15 13 11 9 7 5 3 1 14 12 10 8 6 4 2 0
```

Byte addresses do not move. CPU flash address is file offset plus `0x080000`.
The decoded image's SHA-256 is
`bace445d34ce1cff2971eb4f4fe4998b266998e2096c2f9e89dcc41a3d96bf83`.

This mapping was recovered by matching the bit signatures of the part-number
string, constraining the vector opcodes/pointers, and checking startup code.
Independent consistency checks include two occurrences of `A0325452132`,
readable calibration identifiers, both vector tables, and valid code at their
handler targets. The transform round-trips every input byte exactly. It is a
format conversion, not an instruction patch or firmware modification.

## Reproduce

```sh
python3 tmp/egs52/tools/decode_flash.py
python3 tmp/egs52/tests/verify_math.py
python3 tmp/egs52/tools/rebuild.py
```

The first two commands use Python 3 and a host C compiler; neither needs Ghidra.
The third uses Ghidra 12.1.2 and the installed C166 module. Use `--ghidra PATH`
and `--extension PATH` to select other installation locations. The former
`ghidra_import.sh` now invokes this checked pipeline; it no longer tries
unrelated processors against scrambled input.

`tools/symbols.csv` is the editable source of function names and evidence.
`tools/patch_c166_module.py` reapplies the local processor corrections from an
upstream baseline. `tools/CheckEgs52Processor.java` executes p-code regression
tests before the export. See [tools/PROCESSOR_FIXES.md](tools/PROCESSOR_FIXES.md).

Rebuilds use a fresh disposable project. Passing results replace generated
artifacts in `reconstructed/` and the project in `analysis/ghidra_project/`.
Failures leave the last published result intact and record the error in
`logs/`. Known-invalid decompiler bodies are omitted; only their addresses and
failure classifications appear in `reconstructed/unresolved.csv`.

All previous scrambled-image C, stubs, indexes, and recovery scripts were
removed. The contaminated `/tmp/ghidra_egs52_root` project was also removed.
Do not use old conversational claims about its functions as evidence.
