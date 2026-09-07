"""
Host accelerometer capture, recorded alongside the TCU data.

Shift shock is a 5-20 Hz driveline event. The TCU's own polling loop runs at
roughly 20 Hz, which is too slow to resolve it - differentiating the logged
output shaft speed only shows the average torque step, not the jerk. An
accelerometer strapped down in the car measures it directly, so this module
lets ``nag52log record`` capture one into the same file on the same clock.

Sources are Linux IIO devices (``/sys/bus/iio/devices/iio:deviceN`` with an
``in_accel_*`` channel), which covers laptop lid sensors, USB IMUs exposed
through the kernel, and anything else with an IIO driver. Two backends:

* ``buffer`` - enable the device's own trigger and read hardware-timestamped
  samples from ``/dev/iio:deviceN``. Needs write access to the sysfs
  attributes and read access to the character device.
* ``sysfs``  - poll ``in_accel_{x,y,z}_raw``. Always available, but on HID
  sensor-hub devices each read costs a synchronous USB/ISH round trip, so the
  achievable rate can be a few Hz.

**Check the measured rate before trusting the data.** ``nag52log accel`` reports
it, and a recording whose rate came out under ``USEFUL_HZ`` is flagged in the
log header and on the console: below roughly 50 Hz an accelerometer cannot
resolve shift shock, and many laptop lid sensors are firmware-locked to 10 Hz.

Samples are appended to an internal deque by the sampling thread and drained by
the recording loop, so all file writes stay on one thread.
"""
from __future__ import annotations

import glob
import os
import struct
import threading
import time
from collections import deque
from typing import Any, Deque, Dict, List, Optional, Tuple

IIO_ROOT = "/sys/bus/iio/devices"

#: Below this measured rate the capture cannot resolve shift shock (5-20 Hz).
USEFUL_HZ = 50.0

#: (t, x, y, z) - seconds on the logger's clock, acceleration in m/s^2.
Sample = Tuple[float, float, float, float]


def _read(path: str) -> Optional[str]:
    try:
        with open(path, "r") as fh:
            return fh.read().strip()
    except OSError:
        return None


def _read_float(path: str) -> Optional[float]:
    raw = _read(path)
    if raw is None:
        return None
    try:
        return float(raw)
    except ValueError:
        return None


def _write(path: str, value: Any) -> bool:
    try:
        with open(path, "w") as fh:
            fh.write(str(value))
        return True
    except OSError:
        return False


class AccelDevice:
    """One IIO accelerometer, described well enough to choose between them."""

    def __init__(self, path: str) -> None:
        self.path = path
        self.node = os.path.basename(path)
        self.name = _read(os.path.join(path, "name")) or self.node
        self.dev_node = "/dev/" + self.node
        self.scale = _read_float(os.path.join(path, "in_accel_scale")) or 1.0
        self.offset = _read_float(os.path.join(path, "in_accel_offset")) or 0.0
        self.freq_attr = self._find_freq_attr()
        self.sampling_frequency = _read_float(self.freq_attr) if self.freq_attr else None
        avail = _read(os.path.join(path, "in_accel_sampling_frequency_available")) or \
            _read(os.path.join(path, "sampling_frequency_available"))
        self.available_frequencies = avail

    def _find_freq_attr(self) -> Optional[str]:
        for name in ("in_accel_sampling_frequency", "sampling_frequency"):
            p = os.path.join(self.path, name)
            if os.path.exists(p):
                return p
        return None

    @property
    def has_buffer(self) -> bool:
        return os.path.isdir(os.path.join(self.path, "scan_elements")) and \
            os.path.isdir(os.path.join(self.path, "buffer")) and \
            os.path.exists(self.dev_node)

    @property
    def buffer_readable(self) -> bool:
        return self.has_buffer and os.access(self.dev_node, os.R_OK) and \
            os.access(os.path.join(self.path, "scan_elements"), os.W_OK)

    def set_rate(self, hz: float) -> Optional[float]:
        """Request a sampling rate. Returns the rate the driver actually took."""
        if self.freq_attr and hz > 0:
            _write(self.freq_attr, "%g" % hz)
        return _read_float(self.freq_attr) if self.freq_attr else None

    def describe(self) -> Dict[str, Any]:
        return {
            "node": self.node, "name": self.name, "path": self.path,
            "scale": self.scale, "sampling_frequency": self.sampling_frequency,
            "available_frequencies": self.available_frequencies,
            "buffer": self.has_buffer, "buffer_readable": self.buffer_readable,
        }


def find_accelerometers(root: str = IIO_ROOT) -> List[AccelDevice]:
    """Every IIO device that exposes an ``in_accel_x_raw`` channel."""
    found = []
    for path in sorted(glob.glob(os.path.join(root, "iio:device*"))):
        if os.path.exists(os.path.join(path, "in_accel_x_raw")) or \
                os.path.exists(os.path.join(path, "scan_elements", "in_accel_x_en")):
            found.append(AccelDevice(path))
    return found


def select(spec: Optional[str], root: str = IIO_ROOT) -> Optional[AccelDevice]:
    """Resolve ``--accel`` to a device: ``auto``/``None`` picks the first found."""
    if spec in (None, "", "off", "none"):
        return None
    devices = find_accelerometers(root)
    if spec in ("auto", "on", "yes"):
        return devices[0] if devices else None
    for d in devices:
        if spec in (d.node, d.name, d.path):
            return d
    if os.path.isdir(spec):
        return AccelDevice(spec)
    return None


class AccelSource:
    """
    Background sampler. ``start()``, then ``drain()`` from the recording loop.

    ``t_zero`` is the ``time.monotonic()`` origin of the log, so drained sample
    timestamps line up directly with the ``t`` field of every other record.
    """

    def __init__(self, device: AccelDevice, t_zero: float, rate_hz: float = 0.0,
                 max_queue: int = 200000) -> None:
        self.device = device
        self.t_zero = t_zero
        self.requested_rate = rate_hz
        self.actual_rate: Optional[float] = None
        self.backend = "none"
        self.error: Optional[str] = None
        self.count = 0
        self._q: Deque[Sample] = deque(maxlen=max_queue)
        self._thread: Optional[threading.Thread] = None
        self._stop = threading.Event()
        self._fh = None
        self._chans: List[Dict[str, Any]] = []
        self._record_size = 0
        self._clock_skew = 0.0
        self._first_t: Optional[float] = None
        self._last_t: Optional[float] = None
        self._dropped = 0

    # -- lifecycle -----------------------------------------------------------
    def start(self) -> None:
        if self.requested_rate:
            self.actual_rate = self.device.set_rate(self.requested_rate)
        else:
            self.actual_rate = self.device.sampling_frequency
        if self.device.buffer_readable and self._setup_buffer():
            self.backend = "buffer"
        else:
            self.backend = "sysfs"
        self._thread = threading.Thread(target=self._run, name="accel", daemon=True)
        self._thread.start()

    def stop(self) -> None:
        self._stop.set()
        if self._thread is not None:
            self._thread.join(timeout=2.0)
        self._teardown_buffer()

    def drain(self) -> List[Sample]:
        """Take every sample captured since the last call."""
        out = []
        q = self._q
        while True:
            try:
                out.append(q.popleft())
            except IndexError:
                break
        return out

    # -- reporting -----------------------------------------------------------
    @property
    def measured_rate(self) -> Optional[float]:
        if self._first_t is None or self._last_t is None or self.count < 2:
            return None
        span = self._last_t - self._first_t
        return (self.count - 1) / span if span > 0 else None

    @property
    def usable(self) -> bool:
        r = self.measured_rate
        return r is not None and r >= USEFUL_HZ

    def describe(self) -> Dict[str, Any]:
        d = self.device.describe()
        d.update({"backend": self.backend, "requested_rate_hz": self.requested_rate or None,
                  "configured_rate_hz": self.actual_rate})
        if self.error:
            d["error"] = self.error
        return d

    def summary(self) -> Dict[str, Any]:
        return {"samples": self.count, "measured_rate_hz": round(self.measured_rate, 2)
                if self.measured_rate else None, "backend": self.backend,
                "dropped": self._dropped, "usable_for_shift_shock": self.usable}

    # -- buffered backend ----------------------------------------------------
    def _setup_buffer(self) -> bool:
        """Enable x/y/z (+ timestamp) scan elements and open the char device."""
        p = self.device.path
        se = os.path.join(p, "scan_elements")
        # A buffer that is already running cannot be reconfigured.
        _write(os.path.join(p, "buffer", "enable"), 0)
        wanted = ["in_accel_x", "in_accel_y", "in_accel_z", "in_timestamp"]
        chans = []
        for ch in wanted:
            en = os.path.join(se, ch + "_en")
            if not os.path.exists(en):
                if ch == "in_timestamp":
                    continue
                return False
            if not _write(en, 1):
                return False
            info = self._scan_type(se, ch)
            if info is None:
                return False
            info["name"] = ch
            info["index"] = int(_read(os.path.join(se, ch + "_index")) or 0)
            chans.append(info)
        chans.sort(key=lambda c: c["index"])
        # Offsets follow each channel's natural alignment, as the IIO ABI requires.
        offset = 0
        for c in chans:
            size = c["bytes"]
            offset += (-offset) % size
            c["offset"] = offset
            offset += size
        self._chans = chans
        self._record_size = offset + ((-offset) % max(c["bytes"] for c in chans))
        _write(os.path.join(p, "buffer", "length"), 512)
        if not _write(os.path.join(p, "buffer", "enable"), 1):
            return False
        try:
            self._fh = open(self.device.dev_node, "rb", buffering=0)
        except OSError as exc:
            self.error = "open %s: %s" % (self.device.dev_node, exc)
            _write(os.path.join(p, "buffer", "enable"), 0)
            return False
        return True

    @staticmethod
    def _scan_type(se: str, ch: str) -> Optional[Dict[str, Any]]:
        """Parse an IIO ``*_type`` string such as ``le:s16/32>>0``."""
        raw = _read(os.path.join(se, ch + "_type"))
        if not raw:
            return None
        try:
            endian, rest = raw.split(":", 1)
            sign = rest[0]
            bits, rest2 = rest[1:].split("/", 1)
            storage, shift = rest2.split(">>", 1)
            return {"endian": endian, "signed": sign == "s", "bits": int(bits),
                    "bytes": int(storage) // 8, "shift": int(shift)}
        except (ValueError, IndexError):
            return None

    def _teardown_buffer(self) -> None:
        if self._fh is not None:
            try:
                self._fh.close()
            except OSError:
                pass
            self._fh = None
            _write(os.path.join(self.device.path, "buffer", "enable"), 0)

    def _decode(self, buf: bytes) -> Optional[Sample]:
        vals: Dict[str, int] = {}
        for c in self._chans:
            chunk = buf[c["offset"]:c["offset"] + c["bytes"]]
            if len(chunk) != c["bytes"]:
                return None
            order = "little" if c["endian"].startswith("le") else "big"
            v = int.from_bytes(chunk, order, signed=False) >> c["shift"]
            if c["signed"]:
                sign_bit = 1 << (c["bits"] - 1)
                v = (v & (sign_bit - 1)) - (v & sign_bit)
            vals[c["name"]] = v
        s, o = self.device.scale, self.device.offset
        if "in_timestamp" in vals:
            # IIO timestamps are ns on the clock named by current_timestamp_clock,
            # which defaults to CLOCK_REALTIME; convert onto the log's monotonic base.
            t = vals["in_timestamp"] / 1e9 - self._clock_skew
        else:
            t = time.monotonic() - self.t_zero
        return (round(t, 5),
                (vals["in_accel_x"] + o) * s,
                (vals["in_accel_y"] + o) * s,
                (vals["in_accel_z"] + o) * s)

    # -- sampling thread -----------------------------------------------------
    def _run(self) -> None:
        try:
            if self.backend == "buffer":
                self._run_buffer()
            else:
                self._run_sysfs()
        except Exception as exc:  # noqa: BLE001 - a dead sensor must not kill the log
            self.error = "%s: %s" % (type(exc).__name__, exc)

    def _push(self, sample: Sample) -> None:
        if len(self._q) == self._q.maxlen:
            self._dropped += 1
        self._q.append(sample)
        self.count += 1
        if self._first_t is None:
            self._first_t = sample[0]
        self._last_t = sample[0]

    def _run_buffer(self) -> None:
        clock = _read(os.path.join(self.device.path, "current_timestamp_clock")) or "realtime"
        if clock == "monotonic":
            self._clock_skew = self.t_zero
        else:
            self._clock_skew = time.time() - (time.monotonic() - self.t_zero)
        size = self._record_size
        buf = b""
        while not self._stop.is_set():
            try:
                chunk = self._fh.read(size * 64)
            except OSError as exc:
                self.error = "read: %s" % exc
                return
            if not chunk:
                time.sleep(0.002)
                continue
            buf += chunk
            while len(buf) >= size:
                s = self._decode(buf[:size])
                buf = buf[size:]
                if s is not None:
                    self._push(s)

    def _run_sysfs(self) -> None:
        p = self.device.path
        paths = [os.path.join(p, "in_accel_%s_raw" % a) for a in "xyz"]
        period = 1.0 / self.actual_rate if self.actual_rate else 0.0
        s, o = self.device.scale, self.device.offset
        while not self._stop.is_set():
            t0 = time.monotonic()
            try:
                vals = []
                for path in paths:
                    with open(path, "r") as fh:
                        vals.append(int(fh.read()))
            except (OSError, ValueError) as exc:
                self.error = "sysfs read: %s" % exc
                return
            self._push((round(t0 - self.t_zero, 5),
                        (vals[0] + o) * s, (vals[1] + o) * s, (vals[2] + o) * s))
            if period:
                wait = period - (time.monotonic() - t0)
                if wait > 0:
                    self._stop.wait(wait)
