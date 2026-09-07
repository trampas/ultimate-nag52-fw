"""
Live dashboard tests.

It runs in a car during a recording session, so the things that matter are that
it never raises on missing or odd data and never blocks the polling loop.
"""
import io
import os
import sys
import unittest

sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))
from nag52logger.dashboard import Dashboard  # noqa: E402


def cycle(t, **kw):
    return {
        "t": t,
        "sensors": {"input_rpm": kw.get("in_rpm", 1800), "output_rpm": kw.get("out_rpm", 900),
                    "atf_temp": 78},
        "can": {"pedal_pos": kw.get("pedal", 50)},
        "driving_dynamics": {"agility_score": kw["agility"]} if "agility" in kw else {},
        "shift_live": {"actual_gear": "D3", "target_gear": "D3", "profile": "C"},
    }


class WindowTests(unittest.TestCase):
    def test_old_samples_leave_the_window(self):
        d = Dashboard(window_s=10.0, stream=io.StringIO())
        for i in range(400):
            d.add_cycle(cycle(i * 0.05, agility=i % 100))
        span = d.samples[-1]["t"] - d.samples[0]["t"]
        self.assertLessEqual(span, 10.0)
        self.assertGreater(len(d.samples), 10)

    def test_cycle_without_a_timestamp_is_ignored(self):
        d = Dashboard(stream=io.StringIO())
        d.add_cycle({"sensors": {}})
        self.assertEqual(len(d.samples), 0)


class RenderTests(unittest.TestCase):
    def _render(self, **kw):
        buf = io.StringIO()
        d = Dashboard(stream=buf, **kw)
        return d, buf

    def test_renders_with_no_data_at_all(self):
        d, buf = self._render()
        d.render(force=True)
        self.assertIn("nag52 live", buf.getvalue())

    def test_reports_when_the_agility_record_is_absent(self):
        """Old firmware, or driving_dynamics simply not polled."""
        d, buf = self._render()
        for i in range(20):
            d.add_cycle(cycle(i * 0.05))          # no driving_dynamics
        d.render(force=True)
        self.assertIn("no driving_dynamics", buf.getvalue())

    def test_shows_the_score_and_shift_quality(self):
        d, buf = self._render()
        for i in range(60):
            d.add_cycle(cycle(i * 0.05, agility=70))
        d.add_shift({"gear_from": "2", "gear_to": "3", "agility_score": 18,
                     "quality": {"response_ms": 480, "duration_ms": 1120, "peak_jerk": 38.4,
                                 "torque_hole": 66, "slip_energy_j": 8100}})
        d.render(force=True)
        out = buf.getvalue()
        self.assertIn("agility  70", out)
        self.assertIn("2>3", out)
        self.assertIn("480", out)
        self.assertIn("8100", out)

    def test_shift_without_quality_does_not_raise(self):
        """Firmware that has the trace but not the quality vector."""
        d, buf = self._render()
        d.add_cycle(cycle(0.0, agility=10))
        d.add_shift({"gear_from": "3", "gear_to": "4"})
        d.render(force=True)
        self.assertIn("3>4", buf.getvalue())

    def test_missing_fields_do_not_raise(self):
        d, buf = self._render()
        d.add_cycle({"t": 1.0, "sensors": {}, "can": {}})
        d.render(force=True)
        self.assertIn("nag52 live", buf.getvalue())

    def test_rate_limited(self):
        d, buf = self._render(interval=1000.0)
        d.add_cycle(cycle(0.0, agility=5))
        d.render()
        d.render()
        # the second call inside the interval must not redraw
        self.assertEqual(buf.getvalue().count("nag52 live"), 1)

    def test_constant_signal_does_not_divide_by_zero(self):
        d, buf = self._render()
        for i in range(30):
            d.add_cycle(cycle(i * 0.05, agility=42, in_rpm=2000, pedal=80))
        d.render(force=True)
        self.assertIn("agility  42", buf.getvalue())

    def test_ascii_fallback_when_the_terminal_cannot_do_blocks(self):
        class AsciiBuf(io.StringIO):
            encoding = "ascii"
        d = Dashboard(stream=AsciiBuf())
        self.assertEqual(d.blocks, ".:-=+*#@")

    def test_write_failure_is_swallowed(self):
        """A closed pipe must not take the recording down with it."""
        buf = io.StringIO()
        d = Dashboard(stream=buf)
        d.add_cycle(cycle(0.0, agility=1))
        buf.close()
        d.render(force=True)      # must not raise
        d.finish()


if __name__ == "__main__":
    unittest.main()
