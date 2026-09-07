# Notes for AI sessions

## Read this first

**[tmp/algorithms/](tmp/algorithms/)** — the published algorithms behind shift
quality, road load and driver type adaptation, with an annotated bibliography and
what our own logs measured. Almost everything needed here already exists in SAE
papers; read it before inventing.

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

## Working on the calibration

Run **`scripts/shift_envelope.py`** before and after any change to `src/maps.cpp`.
It checks every shift point against the vehicle's measured envelope (boost point,
peak power band, redline, ratios) and catches the classes of defect that have
actually reached the car: coast columns that mean "never downshift", full-load
dead bands below the boost point, downshifts that land above the lower gear's
upshift point and hunt, ladders that cannot finish before the car stops, and
non-monotonic cells. It runs in the test suite too.

The envelope at the top of that script is the spec. **Ask the owner for these
numbers before tuning anything** - boost threshold, economy rpm, redline. Without
them "is this shift point right?" has no answer, and the whole thing degenerates
into reacting to the last complaint. On this car they are 2400 / 2000 / 4500, and
the power band was measured from drive logs (see TRANSMISSION_NOTES.md).

## Process that this project learned the hard way

Each of these cost a road test:

1. **Check the sample rate against the timescale before analysing.** A 160 ms
   inertia phase at 52.5 ms polling is three samples. Conclusions drawn from that
   were wrong, and it took a failed model fit to notice. Use the shift trace.
2. **One variable per drive.** Two change sets went out together and the
   resulting regression could not be attributed to either.
3. **State the mechanism as a number and check it before flashing.** "Three
   1.2 s shifts inside a 4.1 s stop" would have caught the standstill clunk on
   paper; the simulation output even showed downshifts 50 ms apart.
4. **Measure rather than extrapolate** when the measurement is free. A
   per-record cost multiplied out gave 17 Hz; the logs said 19.0 Hz.
5. **Design instrumentation from the question.** The shift trace shipped without
   the torque request field, during a torque investigation.
6. **Verify on the target, not from a log line.** Read maps back over KWP
   (`SID 0x21, RLI 0x19`); the boot message reported seeded defaults as custom.
7. **Prove a check can fail.** The first version of `shift_envelope.py` parsed
   zero maps and passed everything, including calibrations known to be broken.

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
