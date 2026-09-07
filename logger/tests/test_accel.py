"""
Accelerometer capture tests.

The IIO sysfs layout is reproduced in a temp directory so the sampling,
scaling and discovery logic is exercised without real hardware (and so the
tests do not depend on whatever sensor the host happens to have).
"""
import io
import os
import sys
import tempfile
import time
import unittest
from unittest import mock

sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))
from nag52logger.accel import (AccelDevice, AccelSource, USEFUL_HZ,  # noqa: E402
                               find_accelerometers, select)
from nag52logger.logger import Nag52Logger  # noqa: E402
from nag52logger.reader import LogFile  # noqa: E402
from fake_tcu import FakeTcu  # noqa: E402


def make_iio_tree(root, node="iio:device0", name="accel_3d", scale="0.000009806",
                  freq="100.000000", raw=(1000, 2000, 3000), offset=None,
                  scan_elements=False):
    """Build a minimal IIO sysfs tree; returns the device directory."""
    path = os.path.join(root, node)
    os.makedirs(path, exist_ok=True)

    def w(rel, val):
        with open(os.path.join(path, rel), "w") as fh:
            fh.write(str(val) + "\n")

    w("name", name)
    w("in_accel_scale", scale)
    if offset is not None:
        w("in_accel_offset", offset)
    if freq is not None:
        w("in_accel_sampling_frequency", freq)
    for axis, v in zip("xyz", raw):
        w("in_accel_%s_raw" % axis, v)
    if scan_elements:
        se = os.path.join(path, "scan_elements")
        os.makedirs(se, exist_ok=True)
        for i, ch in enumerate(["in_accel_x", "in_accel_y", "in_accel_z"]):
            with open(os.path.join(se, ch + "_en"), "w") as fh:
                fh.write("0\n")
            with open(os.path.join(se, ch + "_index"), "w") as fh:
                fh.write("%d\n" % i)
            with open(os.path.join(se, ch + "_type"), "w") as fh:
                fh.write("le:s16/32>>0\n")
    return path


class DiscoveryTests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.root = self.tmp.name

    def tearDown(self):
        self.tmp.cleanup()

    def test_finds_only_accelerometers(self):
        make_iio_tree(self.root, "iio:device0", name="accel_3d")
        # A non-accelerometer IIO device (ambient light) must be ignored.
        als = os.path.join(self.root, "iio:device1")
        os.makedirs(als)
        with open(os.path.join(als, "name"), "w") as fh:
            fh.write("als\n")
        found = find_accelerometers(self.root)
        self.assertEqual([d.node for d in found], ["iio:device0"])
        self.assertEqual(found[0].name, "accel_3d")

    def test_empty_tree(self):
        self.assertEqual(find_accelerometers(self.root), [])
        self.assertIsNone(select("auto", self.root))

    def test_select_by_spec(self):
        make_iio_tree(self.root, "iio:device0", name="accel_3d")
        make_iio_tree(self.root, "iio:device1", name="bmc150")
        self.assertEqual(select("auto", self.root).node, "iio:device0")
        self.assertEqual(select("bmc150", self.root).name, "bmc150")
        self.assertEqual(select("iio:device1", self.root).node, "iio:device1")
        self.assertIsNone(select("nope", self.root))
        # Explicitly disabled
        for off in (None, "", "off", "none"):
            self.assertIsNone(select(off, self.root))

    def test_describe_reports_capability(self):
        p = make_iio_tree(self.root, scan_elements=True)
        d = AccelDevice(p).describe()
        self.assertEqual(d["name"], "accel_3d")
        self.assertAlmostEqual(d["scale"], 9.806e-06)
        self.assertEqual(d["sampling_frequency"], 100.0)
        # No /dev node exists for the fake tree, so the buffer is unusable.
        self.assertFalse(d["buffer"])
        self.assertFalse(d["buffer_readable"])


class SysfsSamplingTests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.root = self.tmp.name

    def tearDown(self):
        self.tmp.cleanup()

    def _sample(self, **kw):
        p = make_iio_tree(self.root, **kw)
        src = AccelSource(AccelDevice(p), time.monotonic(), rate_hz=0)
        src.start()
        time.sleep(0.3)
        src.stop()
        return src

    def test_scale_and_offset_applied(self):
        src = self._sample(scale="0.01", raw=(100, 200, 300), offset="5", freq="200")
        self.assertEqual(src.backend, "sysfs")
        samples = src.drain()
        self.assertTrue(samples)
        _, x, y, z = samples[0]
        self.assertAlmostEqual(x, (100 + 5) * 0.01)
        self.assertAlmostEqual(y, (200 + 5) * 0.01)
        self.assertAlmostEqual(z, (300 + 5) * 0.01)

    def test_timestamps_are_on_the_log_clock(self):
        src = self._sample(freq="100")
        samples = src.drain()
        self.assertTrue(samples)
        # t is seconds since t_zero, so a 0.3 s run must stay well inside 0..1
        self.assertTrue(all(0.0 <= s[0] < 1.0 for s in samples))
        self.assertEqual(sorted(s[0] for s in samples), [s[0] for s in samples])

    def test_measured_rate_and_verdict(self):
        src = self._sample(freq="100")
        self.assertIsNotNone(src.measured_rate)
        summary = src.summary()
        self.assertEqual(summary["backend"], "sysfs")
        self.assertGreater(summary["samples"], 1)
        self.assertEqual(summary["usable_for_shift_shock"],
                         summary["measured_rate_hz"] >= USEFUL_HZ)

    def test_slow_sensor_is_reported_unusable(self):
        src = self._sample(freq="5")
        self.assertLess(src.measured_rate, USEFUL_HZ)
        self.assertFalse(src.usable)
        self.assertFalse(src.summary()["usable_for_shift_shock"])

    def test_drain_is_not_destructive_to_later_samples(self):
        p = make_iio_tree(self.root, freq="200")
        src = AccelSource(AccelDevice(p), time.monotonic())
        src.start()
        time.sleep(0.15)
        first = src.drain()
        time.sleep(0.15)
        second = src.drain()
        src.stop()
        self.assertTrue(first)
        self.assertTrue(second)
        self.assertGreater(second[0][0], first[-1][0])

    def test_vanishing_sensor_does_not_raise(self):
        p = make_iio_tree(self.root, freq="200")
        src = AccelSource(AccelDevice(p), time.monotonic())
        src.start()
        time.sleep(0.05)
        for axis in "xyz":
            os.remove(os.path.join(p, "in_accel_%s_raw" % axis))
        time.sleep(0.1)
        src.stop()
        self.assertIsNotNone(src.error)  # recorded, not raised


class ScanTypeTests(unittest.TestCase):
    def test_parses_iio_type_strings(self):
        tmp = tempfile.TemporaryDirectory()
        se = os.path.join(tmp.name, "scan_elements")
        os.makedirs(se)
        cases = {
            "le:s16/32>>0": {"signed": True, "bits": 16, "bytes": 4, "shift": 0},
            "be:u12/16>>4": {"signed": False, "bits": 12, "bytes": 2, "shift": 4},
            "le:s64/64>>0": {"signed": True, "bits": 64, "bytes": 8, "shift": 0},
        }
        for raw, want in cases.items():
            with open(os.path.join(se, "ch_type"), "w") as fh:
                fh.write(raw + "\n")
            got = AccelSource._scan_type(se, "ch")
            for k, v in want.items():
                self.assertEqual(got[k], v, "%s -> %s" % (raw, k))
        with open(os.path.join(se, "bad_type"), "w") as fh:
            fh.write("garbage\n")
        self.assertIsNone(AccelSource._scan_type(se, "bad"))
        self.assertIsNone(AccelSource._scan_type(se, "missing"))
        tmp.cleanup()


class RecordingIntegrationTests(unittest.TestCase):
    """The recorder must interleave accel samples with cycles in one file."""

    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.path = os.path.join(self.tmp.name, "log.jsonl")
        self.root = os.path.join(self.tmp.name, "iio")
        os.makedirs(self.root)

    def tearDown(self):
        self.tmp.cleanup()

    def _run(self, accel_spec):
        lg = Nag52Logger(FakeTcu(), self.path, status=False, echo_log=False,
                         request_timeout=0.3, echo_stream=io.StringIO(),
                         status_stream=io.StringIO(), max_cycles=8, slow_interval=0.0,
                         accel=accel_spec)
        return lg.run()

    def test_samples_land_in_the_log(self):
        p = make_iio_tree(self.root, scale="0.001", raw=(1, 2, 3), freq="200")
        stats = self._run(p)
        self.assertGreater(stats["accel_samples"], 0)

        lf = LogFile.load(self.path)
        self.assertEqual(lf.header["accel"], p)
        self.assertTrue(lf.accel)
        self.assertEqual(len(lf.accel), stats["accel_samples"])
        first = lf.accel[0]
        self.assertAlmostEqual(first["x"], 0.001)
        self.assertAlmostEqual(first["z"], 0.003)
        # Same clock as the polling cycles, so the two can be correlated.
        self.assertTrue(lf.cycles)
        self.assertLessEqual(lf.accel[0]["t"], lf.cycles[-1]["t"] + 1.0)
        # The end record carries the verdict.
        self.assertIn("accel", lf.end)
        self.assertEqual(lf.end["accel"]["backend"], "sysfs")
        self.assertEqual(lf.end["stats"]["accel_samples"], stats["accel_samples"])

    def test_reader_helpers(self):
        make_iio_tree(self.root, scale="1", raw=(3, 4, 0), freq="200")
        self._run(os.path.join(self.root, "iio:device0"))
        lf = LogFile.load(self.path)
        ts, mag = lf.accel_series()
        self.assertEqual(len(ts), len(lf.accel))
        self.assertAlmostEqual(mag[0], 5.0)  # 3-4-5
        _, xs = lf.accel_series("x")
        self.assertAlmostEqual(xs[0], 3.0)
        self.assertIsNotNone(lf.accel_rate())

    def test_disabled_by_no_accel(self):
        stats = self._run(None)
        self.assertEqual(stats["accel_samples"], 0)
        lf = LogFile.load(self.path)
        self.assertEqual(lf.accel, [])
        self.assertIsNone(lf.header["accel"])
        self.assertIsNone(lf.accel_rate())
        self.assertNotIn("accel", lf.end)

    def test_auto_with_no_sensor_is_silent(self):
        """Capture is on by default, so a host without a sensor must not look broken."""
        # Patched, otherwise "auto" finds whatever the machine running the tests has.
        with mock.patch("nag52logger.logger.select_accel", return_value=None):
            stats = self._run("auto")
        self.assertEqual(stats["cycles"], 8)
        lf = LogFile.load(self.path)
        self.assertFalse([e for e in lf.events if e["event"] == "accel_not_found"])
        self.assertEqual(LogFile.load(self.path).accel, [])

    def test_named_but_missing_device_still_warns(self):
        with mock.patch("nag52logger.logger.select_accel", return_value=None):
            self._run("iio:device99")
        lf = LogFile.load(self.path)
        self.assertTrue([e for e in lf.events if e["event"] == "accel_not_found"])

    def test_missing_device_is_reported_not_fatal(self):
        stats = self._run("no-such-sensor")  # not a node, name or path -> select() returns None
        self.assertEqual(stats["cycles"], 8)  # recording continued regardless
        lf = LogFile.load(self.path)
        self.assertTrue(any(e["event"] == "accel_not_found" for e in lf.events))

    def test_start_event_describes_the_device(self):
        make_iio_tree(self.root, freq="200")
        self._run(os.path.join(self.root, "iio:device0"))
        lf = LogFile.load(self.path)
        start = [e for e in lf.events if e["event"] == "accel_start"]
        self.assertEqual(len(start), 1)
        self.assertEqual(start[0]["device"]["name"], "accel_3d")
        self.assertEqual(start[0]["device"]["backend"], "sysfs")


if __name__ == "__main__":
    unittest.main()
