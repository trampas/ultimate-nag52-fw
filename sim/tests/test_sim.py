"""Physics checks and closed-loop firmware regressions; no road-data dependency."""
import csv
import importlib.util
from pathlib import Path
import subprocess
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[2]
spec = importlib.util.spec_from_file_location("sim_runner", ROOT / "sim/run.py")
runner = importlib.util.module_from_spec(spec)
spec.loader.exec_module(runner)


class SimulationTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        runner.build()

    def simulate(self, **parameters):
        with tempfile.TemporaryDirectory() as d:
            path = Path(d) / "trace.csv"
            result = runner.run({"seconds": 5, **parameters}, path)
            text = path.read_text()
            rows = list(csv.DictReader(text.splitlines()))
            return result["result"], rows, text

    def test_physics(self):
        with tempfile.TemporaryDirectory() as d:
            exe = Path(d) / "physics"
            subprocess.run(["g++", "-std=c++17", "-Wall", "-Wextra", "-Werror",
                            str(ROOT / "sim/tests/plant_test.cpp"), "-o", str(exe)], check=True)
            subprocess.run([str(exe)], check=True)

    def test_closed_loop_is_deterministic_and_synchronizes(self):
        a, rows, text = self.simulate()
        b, _, repeated = self.simulate()
        self.assertEqual(text, repeated)
        self.assertEqual(a["samples"], 5000)
        self.assertTrue(a["controller_completed"] and a["final_sync"])
        self.assertFalse(a["controller_timed_out"] or a["domain_exit"])
        self.assertGreater(float(rows[-1]["speed_m_s"]), float(rows[0]["speed_m_s"]))
        self.assertEqual(a["controller_end_s"], b["controller_end_s"])

    def test_mass_changes_motion_and_shift_feedback(self):
        light, a, _ = self.simulate(mass_kg=1500)
        heavy, b, _ = self.simulate(mass_kg=2300)
        self.assertGreater(float(a[899]["accel_m_s2"]), float(b[899]["accel_m_s2"]))
        self.assertNotEqual(a[1800]["input_rpm"], b[1800]["input_rpm"])
        self.assertNotEqual(light["first_sync_s"], heavy["first_sync_s"])

    def test_fixed_window_jerk_and_motion_converge(self):
        a, ar, _ = self.simulate(dt_ms=1)
        b, br, _ = self.simulate(dt_ms=.5)
        self.assertLess(abs(a["peak_abs_jerk_20ms_m_s3"] / b["peak_abs_jerk_20ms_m_s3"] - 1), .05)
        self.assertLess(abs(a["first_sync_s"] - b["first_sync_s"]), .03)
        self.assertLess(abs(float(ar[-1]["speed_m_s"]) - float(br[-1]["speed_m_s"])), .02)

    def test_controller_change_alters_plant_trajectory(self):
        _, a, _ = self.simulate(time_ms=200)
        _, b, _ = self.simulate(time_ms=1000)
        # It is not enough for commands to differ: the model's speeds must react.
        self.assertNotEqual([r["on_pressure_mbar"] for r in a], [r["on_pressure_mbar"] for r in b])
        self.assertNotEqual([r["input_rpm"] for r in a], [r["input_rpm"] for r in b])

    def test_rejects_unknown_or_invalid_scenario_values(self):
        for parameters in ({"mass_kg": 0}, {"dt_ms": 3}, {"change": 2.5}, {"typo": 1}, {"pedal": 251}):
            with self.assertRaises(RuntimeError):
                self.simulate(**parameters)


if __name__ == "__main__":
    unittest.main()
