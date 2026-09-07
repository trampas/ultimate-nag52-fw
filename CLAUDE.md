# Notes for AI sessions

## Read this first

**[TRANSMISSION_NOTES.md](TRANSMISSION_NOTES.md)** — how the 722.6 actually works: hydraulics,
torque converter, shift algorithm structure, maps, and the physics needed to judge shift
quality. Written because several confidently wrong conclusions came from not knowing it.
Read it before touching anything under `src/shifting_algo/`, `src/pressure_manager.cpp`,
`src/profiles.cpp` or `src/maps.cpp`.

The four things most likely to waste your time:

1. **A shift solenoid that is OFF means its clutch is fed line pressure, not SPC.** The ramp
   to `SPC_MAX` at the end of every shift is pressure matching before the valve drops out —
   it is not a "slam" and must not be softened.
2. **Maps live in NVS.** Editing a default in `maps.cpp` does nothing on a TCU that has
   already booted; you must bump the key name in `src/nvs/all_keys.h` (max 15 chars).
   Verify by reading the map back over KWP, not from a boot log line.
3. **`input_rpm` is turbine speed and never reaches zero at a standstill in gear** (the
   converter drags it to 100–300 rpm). Judge standstill on `output_rpm`.
4. **Shifts are serialised** — the profile is only consulted when not already shifting, so
   downshift ladders chain and a threshold that cannot be reached in time is not the
   threshold you calibrated.

## Build, flash, log

```sh
.venv/bin/pio run -e unified            # build
.venv/bin/pio run -e unified -t upload  # flash (CP2102N on /dev/ttyUSB0, 921600)
logger/nag52log.py --reset -o logger/logs/boot.jsonl -q   # boot check; grep for Guru/panic
```

Check `fuser /dev/ttyUSB0` first — the logger holds the port while recording.
Do not re-enable core dump to flash or `CONFIG_ESP_COREDUMP_CHECK_BOOT` on IDF 5.3 without
re-testing the boot; it boot-loops (see `sdkconfig.unified`).

## Analysing drive logs

`logger/` records to JSONL; `logger/README.md` covers the format and the reader API.
`tmp/shift_replay/` replays logged shifts through the real algorithms compiled for the host.

When writing analysis scripts, two mistakes have already produced wrong answers: treating a
missing field as `0` (a dropped read decodes as `None`, and `None → 0` fakes a standstill),
and hardcoding a log path so a "new" trace silently shows an old drive. Take the log path as
an argument.
