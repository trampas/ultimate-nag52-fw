"""Compile actual firmware control primitives and trace lifecycle on the host."""
from pathlib import Path
import subprocess
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[2]
STUBS = ROOT / "tmp/shift_replay/stubs"

class FirmwareRegressionTests(unittest.TestCase):
    def test_control_bounds_demand_and_torque_encoding(self):
        with tempfile.TemporaryDirectory() as tmp:
            exe = Path(tmp) / "control"
            subprocess.run(["g++", "-std=c++17", "-Wall", "-Wextra", "-Werror",
                            "-I" + str(ROOT / "src"), str(ROOT / "scripts/shift_control_host.cpp"),
                            "-o", str(exe)], check=True, capture_output=True)
            subprocess.run([str(exe)], check=True, capture_output=True)

    def test_consecutive_trace_events_and_annotation_order(self):
        with tempfile.TemporaryDirectory() as tmp:
            base = Path(tmp)
            (base / "freertos").mkdir()
            (base / "freertos/FreeRTOS.h").write_text(
                "#pragma once\nusing portMUX_TYPE = int;\n"
                "#define portMUX_INITIALIZER_UNLOCKED 0\n"
                "#define portENTER_CRITICAL(x) ((void)(x))\n"
                "#define portEXIT_CRITICAL(x) ((void)(x))\n")
            cmd = ["g++", "-std=gnu++17", "-w", "-include", str(STUBS / "preinclude.h")]
            cmd += ["-I" + str(p) for p in (base, STUBS, ROOT / "src", ROOT, ROOT / "lib/core")]
            cmd += [str(ROOT / "scripts/shift_trace_host.cpp"), "-o", str(base / "trace")]
            result = subprocess.run(cmd, text=True, capture_output=True)
            self.assertEqual(result.returncode, 0, result.stderr)
            subprocess.run([str(base / "trace")], check=True, capture_output=True)
