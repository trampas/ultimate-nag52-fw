# nag52log – serial data logger for the Ultimate‑NAG52

Records everything the TCU puts on its USB serial port (the CP210x bridge on
UART0, 921600 baud) into one time‑stamped file:

* **ESP_LOG output** (`ESP_LOGI/W/E`, the "LOG()" text you see in a serial
  monitor), parsed into level / TCU timestamp / tag / message.
* **Live data records** polled over the TCU's built‑in KWP2000 diagnostic
  endpoint (the same channel the config app uses): sensor inputs, CAN inputs,
  pressure‑manager and solenoid outputs, shift‑algorithm feedback, clutch
  speeds, TCC program state, CPU load, plus a one‑off snapshot of the firmware
  header and vehicle configuration.

The result is a `.jsonl` file that a simulation can replay cycle by cycle:
every cycle carries the inputs the algorithms saw *and* the outputs they
produced at that instant.

No firmware changes are required; it works with the firmware as‑is.

## Install

```sh
cd logger
pip install -r requirements.txt      # only pyserial
```

Python 3.8+. The reader/export side needs no third‑party packages at all.

## Record

```sh
./nag52log.py                        # /dev/ttyUSB0, writes logs/nag52_<date>_<time>.jsonl
./nag52log.py -p /dev/ttyUSB1 -o drive1.jsonl.gz
./nag52log.py --rate 20              # cap polling at 20 cycles/s (default: as fast as possible)
./nag52log.py --records sensors,pressures,shift_algo   # poll a subset (tcu_time is always added)
./nag52log.py --no-poll              # pure serial monitor to file, sends nothing to the TCU
./nag52log.py --reset                # pulse EN on open so boot logs are captured
./nag52log.py ports                  # find the CP210x
./nag52log.py records                # list every record and field with units
./nag52log.py --no-accel             # skip the accelerometer (on by default, see below)
./nag52log.py --accel iio:device2    # pick a specific accelerometer
./nag52log.py accel                  # list accelerometers and measure their real rate
```

Ctrl‑C stops the recording cleanly. While recording, TCU log lines are echoed
to stdout and a one‑line status (gear, RPMs, pressures, cycle time, error
counters) is printed to stderr once a second (`--no-echo`, `-q` to silence).

Opening the port does **not** reset the TCU: DTR/RTS are held low. If the TCU
is powered off the logger waits and connects when it appears; if it reboots
mid‑session a `tcu_reboot` event is written and polling resumes.

Polling speed: the firmware's diagnostic server loop runs every 2 ms once an
extended session is open (20 ms otherwise, which is why the logger opens one),
and each record costs one request/response, so the default set of nine
records gives roughly 20–30 cycles per second.  Drop records you do not need
to go faster.

### Shift trace

The polled records above manage 19 Hz — a cycle of the default nine records
takes 52.5 ms (measured median over 29944 cycles).  The sensors and the shift
algorithm both update every 20 ms, so polling caught only one update in 2.6 and
a shift's 100-200 ms inertia phase came out as about three aliased samples.

The TCU therefore records shifts itself, into a PSRAM ring filled at the 20 ms
period its control loop already runs at — the same period the sensors and the
shift algorithm update at, so the capture is lossless and there is no point
sampling faster.  The logger reads the window around each
completed shift back afterwards and writes it as a `shift_trace` line holding
~50 Hz samples with 0.5 s of context either side.  This is on by default and
costs nothing until a shift ends; `--no-shift-trace` disables it.  Firmware
without the recorder logs `shift_trace_unavailable` once and carries on.

Transfer is host paced — one request per chunk, never a push.  The wire format
is ASCII hex, so an N byte payload is 2N+6 bytes on the UART; chunks are kept to
5 samples (a 268 byte frame) to stay under half of the CP2102N's 576 byte
receive buffer.  A full 255 byte read would be a 518 byte frame, 90 % of it.

```python
for sh in LogFile.load("logs/drive.jsonl").shift_traces:
    print(sh["gear_from"], "->", sh["gear_to"], len(sh["samples"]), "samples")
    for s in sh["samples"]:
        s["t_ms"], s["input_rpm"], s["p_on"], s["p_off"], s["phase"]
```

Each `shift_trace` line also carries what the TCU measured and decided about
that shift, so a drive can carry more than one experiment and still be
attributable afterwards:

* `quality` — the on-TCU shift quality vector (`response_ms`, `duration_ms`,
  `peak_jerk` in m/s^3, `torque_hole`, `slip_energy_j`, `lockup_rate`,
  `settle_osc`), present from firmware 679fed1.
* `agility_score` — driver agility demand 0-100 when the shift started.
* `stamp` (trace version 2) — what was in force and what was done afterwards:
  `features` (which of `blend_time`, `blend_points`, `quality_adapt`,
  `next_gear`, `interleave`, `algo_adapt`, `profile_agility` were enabled),
  `arm` (1 = feature arm A, 0 = baseline arm B when `ab_interleave` is on),
  `blend_pct` (Comfort/Agility weight applied), `target_time_ms`,
  `spc_offset` / `prefill_offset` (adaptation cells in force), `flags`
  (`flare`, `adapted`, `manual`, `kickdown`, `annotated`), and
  `adapt_reason` / `spc_delta` / `prefill_delta` (what the quality adaptation
  did after the shift, or why it did nothing).

To compare two arms from one drive, split `shift_traces` on
`sh["stamp"]["arm"]` and compare the medians of `quality` per shift type.

### Accelerometer

A host accelerometer is recorded **by default** into the same file, on the same
clock as the polled records, as `accel` lines (`t`, `x`, `y`, `z` in m/s²).  Any
Linux IIO device with an `in_accel_*` channel works; the first one found is used
unless you name a node (`--accel iio:device2`), a driver name, or a sysfs path.
`--no-accel` turns it off, and `--accel-rate` requests a sample rate (the driver
may refuse it).  If the machine has no accelerometer, recording proceeds without
one and nothing is logged about it.

This exists because shift shock is a 5–20 Hz driveline event and the polling
loop only manages ~20 cycles/s, so differentiating the logged output shaft
speed shows the average torque step but not the jerk.

**Measure the rate before relying on it.**  `./nag52log.py accel` reports what a
sensor actually delivers, and a recording is flagged in the log and on the
console if it came out under 50 Hz:

```
iio:device2  accel_3d
    rate        10.0 Hz
    buffer      yes
                not readable as this user - falling back to slow sysfs polling
    MEASURED    2.94 Hz over 3.0 s via sysfs (9 samples)
    VERDICT     too slow for shift shock - needs >= 50 Hz, this is 2.94 Hz
```

Two backends are used automatically: hardware-timestamped samples read from
`/dev/iio:deviceN` when the character device and the sysfs attributes are
writable (a udev rule is usually needed), otherwise polling `in_accel_*_raw`,
which on HID sensor-hub devices costs a synchronous round trip per read and
lands around 3 Hz.  Laptop lid sensors are frequently firmware-locked to 10 Hz
and only report on change, so they are not usable for this; a phone IMU logger
(200–500 Hz) or a dedicated IIO-backed USB IMU is.

Reading it back:

```python
lf = LogFile.load("logs/drive.jsonl")
t, mag = lf.accel_series()        # magnitude, needs no knowledge of orientation
t, x   = lf.accel_series("x")
lf.accel_rate()                   # measured sample rate, or None
```

## Analyse / export

```sh
./nag52log.py info logs/nag52_x.jsonl --shifts      # summary + detected gear changes
./nag52log.py export logs/nag52_x.jsonl              # -> logs/nag52_x.csv, one row per cycle
./nag52log.py export logs/nag52_x.jsonl --columns t,tcu_ms,sensors.input_rpm,pressures.corrected_spc_pressure
./nag52log.py export logs/nag52_x.jsonl --logs tcu.log   # also dump ESP_LOG lines as text
./nag52log.py calibration logs/nag52_x.jsonl              # summary of the calibration the TCU was running
./nag52log.py calibration logs/nag52_x.jsonl --full -o cal.json   # every field, also saved as JSON
./nag52log.py calibration --live                          # read the block from a connected TCU now
```

The calibration block (`src/egs_calibration/calibration_structs.h`) is downloaded at connect and stored in the
`snapshot` line, so a log always carries the ratios, friction map, spring pressures, SPC gains and pressure/current
map the shift algorithms were using. `info` prints a short summary of it; if its length does not match this
logger's layout the raw bytes are kept and a warning is recorded.

From Python (e.g. a simulation harness):

```python
import sys; sys.path.insert(0, "logger")
from nag52logger.reader import LogFile

log = LogFile.load("logs/nag52_x.jsonl")
print(log.summary())
for cyc in log.cycles:
    s, p, a = cyc["sensors"], cyc["pressures"], cyc["shift_algo"]
    # s["input_rpm"], s["output_rpm"], cyc["can"]["pedal_pos"] ... are the inputs
    # p["corrected_spc_pressure"], a["p_on"], ...           are the outputs
t, rpm = log.series("sensors", "input_rpm")
```

## File format

One JSON object per line; the `type` key says what it is.

| type       | content |
|------------|---------|
| `header`   | logger version, start time, port, record/field metadata (units, scaling, enums) – the schema for the rest of the file |
| `snapshot` | ECU serial, firmware header (`fw_header`), vehicle config (`tcm_config`) and the EGS calibration block (`calibration`, decoded from the TCU's flash partition via ReadMemoryByAddress), read once after connecting |
| `cycle`    | `seq`, `t` (host seconds since start), `tcu_ms` (TCU clock at cycle start), `dt` (cycle duration) and one object per record, keyed by record name |
| `log`      | one ESP_LOG line: `t`, `tcu_ms`, `level`, `tag`, `msg` (or `raw` if it was not in ESP‑IDF format, e.g. boot ROM text) |
| `event`    | `port_open`, `waiting_for_tcu`, `connected`, `tcu_lost`, `tcu_reboot`, `kwp_error` |
| `end`      | counters |

Values are already in engineering units (mBar, RPM, Nm, °C, mV); enum fields
hold their names (`"D"`, `"Slipping"`, `"FastAsPossible"`); values the TCU
flags as unavailable are `null`. If the firmware changes a struct so its size
no longer matches, that record is stored as `{"_raw": "<hex>", ...}` rather
than dropped.

Time bases: `t` is the host's monotonic clock. `tcu_ms` inside cycles is the
TCU's `esp_timer` millisecond clock (read from RLI 0x26 each cycle); `tcu_ms`
inside log lines is the ESP log macro's RTOS‑tick clock. Both count from boot
and agree to within a few ms.

## Records

| name            | RLI  | what |
|-----------------|------|------|
| `tcu_time`      | 0x26 | TCU ms clock (always polled first) |
| `sensors`       | 0x20 | N2/N3/input/output RPM, measured and target ratio, battery mV, ATF °C, parking lock |
| `can`           | 0x22 | pedal, engine torques (min/max/static/driver), wheel RPMs, shifter/paddle/profile input, engine RPM, TCU torque request + type/bounds, engine temps |
| `pressures`     | 0x25 | requested SPC/MPC, line & inlet pressure, corrected SPC/MPC, TCC pressure, on/off‑clutch pressures, active shift circuits |
| `solenoids`     | 0x21 | PWM (0–4096) and current (mA) of SPC/MPC/TCC/Y3/Y4/Y5, current targets and trims |
| `shift_live`    | 0x27 | compact overview: pressures, RPMs, torques, ATF, actual/target gear, profile |
| `shift_algo`    | 0x31 | shift algorithm feedback: phase/subphases, sync RPM, PID/adder torque, p_on/p_off, clutch speeds |
| `clutch_speeds` | 0x30 | modelled K1/K2/K3/B1/B2/B3 slip speeds |
| `tcc`           | 0x24 | lockup clutch program: pressures, slip, states, energy, load |
| `sys_usage`     | 0x23 | CPU load per core, heap/PSRAM free (slow group, every `--slow-interval` s) |
| `fw_header`     | 0x28 | firmware version/date/IDF/SHA (once) |
| `tcm_config`    | 0xFE | vehicle configuration struct (once) |

Layouts mirror `src/diag/diag_data.h`, `src/common_structs.h`,
`src/models/clutch_speed.hpp` and `src/nvs/eeprom_config.h`. If you change a
struct in the firmware, update `nag52logger/records.py` and the size table in
`tests/test_records.py`.

## Protocol notes (for maintainers)

See `src/diag/endpoints/usb_endpoint.cpp` and `src/diag/kwp2000.cpp`.

* PC → TCU: raw bytes `[len_hi, len_lo, 0x07, 0xE1, SID, args…]`, `len = 2 + payload`.
  The TCU detects end‑of‑message as "bytes arrived, then a poll with none", so
  each request is written in a single `write()`.
* TCU → PC: `#07E9` + hex payload + `\n`. Anything else on the line is log text.
* Log output and diagnostic frames come from different code paths on the TCU
  and can (rarely) interleave; corrupt frames are counted and the request is
  retried.
* `0x7F <sid> 0x78` (response pending) extends the wait. StartDiagnosticSession
  `0x92` gives the 2 ms server loop; TesterPresent is sent if polling is
  slower than the 4.5 s session timeout.

## Tests

```sh
cd logger && python3 -m unittest discover -s tests
```

The tests run against a fake TCU that emulates the firmware's UART framing,
including interleaved log lines, corrupt frames, dropped requests and
response‑pending, so protocol changes can be checked without hardware.

### Downshift ladder diagnostics

The default slow polling group includes `downshift_observer` (RLI `0x34`). It
captures controller decision counters and the last 16 state transitions, so short
inter-shift gaps can be attributed without faster polling. Older firmware logs an
unsupported-record error and continues. To omit it, use `--slow sys_usage`.

```sh
python3 scripts/skip_downshift_report.py logger/logs/<drive>.jsonl
python3 scripts/skip_downshift_report.py logger/logs/<drive>.jsonl --json
```

Run these from the repository root. Reports include individual rung durations,
slip energy and gap causes. Missing history is `unknown`; `shifting` means the
decision gate was closed, not that another downshift was requested. See the
[review and protocol](../docs/skip_downshift_review.md) for interpretation.
