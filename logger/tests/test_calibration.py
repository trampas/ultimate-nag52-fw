import io
import os
import sys
import tempfile
import unittest

sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))
from nag52logger import calibration as C  # noqa: E402
from nag52logger.logger import Nag52Logger  # noqa: E402
from nag52logger.reader import LogFile  # noqa: E402
from fake_tcu import FakeTcu, C_DEFAULT_CAL  # noqa: E402


class CalibrationTests(unittest.TestCase):
    def test_layout_size_matches_firmware_struct(self):
        # sizeof(CalibrationInfo) in calibration_structs.h (packed)
        self.assertEqual(C.CAL_STRUCT_SIZE, 1185)

    def test_roundtrip(self):
        blob = C.encode_calibration(C_DEFAULT_CAL)
        self.assertEqual(len(blob), C.CAL_STRUCT_SIZE)
        cal = C.decode_calibration(blob)
        self.assertNotIn("_error", cal)
        self.assertTrue(cal["crc_ok"])
        self.assertEqual(cal["len"], C.CAL_STRUCT_SIZE)
        self.assertEqual(cal["hydr_cal_name"], "STDP")
        self.assertEqual(cal["mech_cal"]["ratio_table"], C_DEFAULT_CAL["mech_cal"]["ratio_table"])
        self.assertEqual(cal["hydr_cal"]["shift_spc_gain"], [1993] * 8)
        self.assertEqual(cal["derived"]["ratios"]["1"], 3.932)
        self.assertEqual(cal["derived"]["max_solenoid_pressure_mbar"], 7700)
        self.assertEqual(cal["_warnings"], [])

    def test_bad_magic_reported(self):
        cal = C.decode_calibration(b"\xff" * 64)
        self.assertIn("_error", cal)

    def test_zero_divisor_warning(self):
        d = dict(C_DEFAULT_CAL)
        d["hydr_cal"] = dict(C_DEFAULT_CAL["hydr_cal"], p_multi_1=0)
        cal = C.decode_calibration(C.encode_calibration(d))
        self.assertTrue(any("zero divisors" in w for w in cal["_warnings"]))

    def test_logger_records_calibration_in_snapshot(self):
        tmp = tempfile.TemporaryDirectory()
        try:
            path = os.path.join(tmp.name, "log.jsonl")
            tcu = FakeTcu()
            lg = Nag52Logger(tcu, path, status=False, echo_log=False, request_timeout=0.3,
                             echo_stream=io.StringIO(), status_stream=io.StringIO(),
                             max_cycles=2, slow_interval=0.0)
            lg.run()
            lf = LogFile.load(path)
            cal = lf.snapshot["calibration"]
            self.assertEqual(cal["mech_cal_name"], "51")
            self.assertEqual(cal["derived"]["ratios"]["2"], 2.408)
            self.assertEqual(lf.summary()["calibration"]["names"]["hydr_cal_name"], "STDP")
        finally:
            tmp.cleanup()


if __name__ == "__main__":
    unittest.main()
