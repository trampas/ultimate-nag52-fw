import io
import json
import os
import sys
import tempfile
import unittest

sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))
from nag52logger.logger import Nag52Logger  # noqa: E402
from nag52logger.reader import LogFile, iter_entries  # noqa: E402
from nag52logger.cli import main  # noqa: E402
from fake_tcu import FakeTcu  # noqa: E402


class EndToEndTests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.path = os.path.join(self.tmp.name, "log.jsonl")

    def tearDown(self):
        self.tmp.cleanup()

    def _run(self, tcu, **kw):
        lg = Nag52Logger(tcu, self.path, status=False, echo_log=False, request_timeout=0.3,
                         echo_stream=io.StringIO(), status_stream=io.StringIO(), **kw)
        return lg.run()

    def test_record_and_read_back(self):
        tcu = FakeTcu()
        tcu.values["shift_live"] = {"input_rpm": 1500, "engine_rpm": 1600, "targ_act_gear": 0x22,
                                    "atf_temp": 40 + 70, "profile": 0}
        tcu.values["fw_header"] = {"version": "9.9.9", "project_name": "test"}
        tcu.pending_logs = ["I (5) INIT: hello"]
        stats = self._run(tcu, max_cycles=5, slow_interval=0.0)
        self.assertEqual(stats["cycles"], 5)

        lf = LogFile.load(self.path)
        self.assertEqual(lf.header["type"], "header")
        self.assertIn("sensors", lf.header["records"])
        self.assertEqual(lf.snapshot["records"]["fw_header"]["version"], "9.9.9")
        self.assertEqual(lf.snapshot["ecu_serial"], "AABBCCDDEEFF")
        self.assertEqual(len(lf.cycles), 5)
        c = lf.cycles[0]
        self.assertIn("tcu_ms", c)
        self.assertEqual(c["shift_live"]["actual_gear"], "D2")
        self.assertEqual(c["shift_live"]["atf_temp"], 70)
        self.assertIn("sys_usage", c)                 # slow group, interval 0 -> every cycle
        self.assertEqual(lf.logs[0]["tag"], "INIT")
        self.assertEqual(lf.logs[0]["tcu_ms"], 5)
        self.assertEqual(lf.end["stats"]["cycles"], 5)
        self.assertEqual([e["event"] for e in lf.events][:2], ["port_open", "connected"])
        # every line is valid JSON with a type
        for e in iter_entries(self.path):
            self.assertIn("type", e)

    def test_reboot_detection(self):
        tcu = FakeTcu()
        lg = Nag52Logger(tcu, self.path, status=False, echo_log=False, max_cycles=4,
                         echo_stream=io.StringIO(), status_stream=io.StringIO())
        orig = lg._cycle

        def cyc():
            if lg.stats["cycles"] == 2:
                tcu.tcu_ms = 10  # TCU rebooted
            orig()
        lg._cycle = cyc
        stats = lg.run()
        self.assertEqual(stats["tcu_reboots"], 1)
        self.assertTrue(any(e["event"] == "tcu_reboot" for e in LogFile.load(self.path).events))

    def test_export_csv_and_info(self):
        tcu = FakeTcu()
        tcu.values["pressures"] = {"ss_flag": 3, "working_pressure": 4321}
        self._run(tcu, max_cycles=3, fast=["sensors", "pressures"])
        lf = LogFile.load(self.path)
        self.assertIn("pressures.shift_circuits", lf.columns())
        csv_path = os.path.join(self.tmp.name, "out.csv")
        n = lf.write_csv(csv_path)
        self.assertEqual(n, 3)
        with open(csv_path) as fh:
            header = fh.readline().strip().split(",")
            row = fh.readline().strip().split(",")
        self.assertEqual(row[header.index("pressures.working_pressure")], "4321")
        self.assertEqual(row[header.index("pressures.shift_circuits")], "1-2|2-3")
        # CLI paths
        self.assertEqual(main(["export", self.path, "-o", csv_path]), 0)
        self.assertEqual(main(["info", self.path]), 0)
        self.assertEqual(main(["records"]), 0)

    def test_shift_detection(self):
        tcu = FakeTcu()
        seq = [0x11, 0x21, 0x21, 0x22, 0x22]
        lg = Nag52Logger(tcu, self.path, status=False, echo_log=False, max_cycles=len(seq),
                         fast=["shift_live"], echo_stream=io.StringIO(), status_stream=io.StringIO())
        orig = lg._cycle

        def cyc():
            tcu.values["shift_live"] = {"targ_act_gear": seq[lg.stats["cycles"]]}
            orig()
        lg._cycle = cyc
        lg.run()
        shifts = LogFile.load(self.path).shifts()
        self.assertEqual(len(shifts), 1)
        self.assertEqual((shifts[0]["from"], shifts[0]["to"]), ("D1", "D2"))

    def test_log_only_mode_writes_logs(self):
        tcu = FakeTcu()
        tcu.emit_log("I (1) BOOT: up")
        lg = Nag52Logger(tcu, self.path, poll=False, status=False, echo_log=False,
                         echo_stream=io.StringIO(), status_stream=io.StringIO())
        import threading
        threading.Timer(0.3, lg.stop).start()
        lg.run()
        self.assertEqual(tcu.requests, [])
        lf = LogFile.load(self.path)
        self.assertEqual(lf.logs[0]["msg"], "up")


if __name__ == "__main__":
    unittest.main()
