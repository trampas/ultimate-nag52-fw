# 722.6 / EGS51 / NAG52 Documentation Index

The previous combined guide has been split into two documents:

- Physical transmission and OEM behavior primer:
  - [docs/7226_egs51_primer.md](7226_egs51_primer.md)
- NAG52 implementation behavior and EGS51 parity:
  - [docs/nag52_behavior_and_parity.md](nag52_behavior_and_parity.md)

Reference artifacts and downloaded sources are in:

- [docs/references/README.md](references/README.md)

Key extracted sensor data file:

- [docs/references/kty81_221_222_table.csv](references/kty81_221_222_table.csv)

## EGS51 reverse-engineering artifacts

The ROM image and its disassembly are proprietary and not committed; everything below is
ours and is in the repository.

| Artifact | What it is |
|---|---|
| [tmp/egs51/README.md](../tmp/egs51/README.md) | Full narrative: image, MCU, import recipe, code structure, calibration blocks, output path, pressure path, traps |
| [tmp/egs51/reconstructed/README.md](../tmp/egs51/reconstructed/README.md) | Executable-model review notes, **coverage table**, and the list of corrections to earlier passes |
| [tmp/egs51/reconstructed/](../tmp/egs51/reconstructed/) | Host-side C model (`egs51_*.c`, `egs51_model.h`) plus `symbols.txt` |
| [tmp/egs51/tests/verify_model.py](../tmp/egs51/tests/verify_model.py) | Compiles the model and checks it against an 8051 interpreter running the original ROM bytes |
| [tmp/egs51/tools/egs51tool.py](../tmp/egs51/tools/egs51tool.py) | Query the ROM without Ghidra: `asm`, `fn`, `xrefs`, `calrefs`, `desc`, `map`, `calsets`, `find`, `mdu`, `vectors`, `verify`, `export` |
| [tmp/egs51/ghidra/](../tmp/egs51/ghidra/) | Headless Ghidra scripts: vector seeding, MDU/SFR annotation, map-descriptor typing, both jump-table forms, symbol import |

Reproduce the checks (requires the uncommitted ROM image):

```sh
python3 tmp/egs51/tests/verify_model.py       # model vs ROM instruction oracle
python3 tmp/egs51/tools/egs51tool.py verify   # 32 calibration fields vs cal_data.h
```

Confidence boundary: the routines in the coverage table are oracle-verified; the shift
supervisor, TCC control, analog scan and calibration-services files compile clean but are
transcribed only. Two conclusions from earlier passes have been **withdrawn** - "EGS51 keeps
Y4 off during Drive engagement" and the "+50" temperature encoding - see the primer sections
4 and 5.4.
