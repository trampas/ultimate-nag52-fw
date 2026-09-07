import os
import struct
import sys
import unittest

sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))
from nag52logger import records as R  # noqa: E402

# sizeof() of the packed firmware structs (src/diag/diag_data.h etc.)
FIRMWARE_SIZES = {
    "tcu_time": 4, "sensors": 19, "solenoids": 32, "can": 30, "sys_usage": 24,
    "tcc": 27, "pressures": 23, "shift_live": 22, "clutch_speeds": 12,
    "shift_algo": 22, "fw_header": 256, "tcm_config": 28,
}


class RecordLayoutTests(unittest.TestCase):
    def test_struct_sizes_match_firmware(self):
        for name, size in FIRMWARE_SIZES.items():
            self.assertEqual(R.RECORDS[name].size, size, name)
        self.assertEqual(set(FIRMWARE_SIZES), set(R.RECORDS))

    def test_rli_numbers_unique(self):
        rlis = [r.rli for r in R.RECORDS.values()]
        self.assertEqual(len(rlis), len(set(rlis)))

    def test_length_mismatch_keeps_raw(self):
        d = R.RECORDS["sensors"].decode(b"\x01\x02\x03")
        self.assertEqual(d, {"_raw": "010203", "_len": 3, "_expected": 19})


class DecodeTests(unittest.TestCase):
    def test_sensors(self):
        raw = struct.pack("<HHHHHHiBH", 1500, 1400, 1450, 324, 232, 13800, 85, 0, 800)
        d = R.RECORDS["sensors"].decode(raw)
        self.assertEqual(d["input_rpm"], 1450)
        self.assertAlmostEqual(d["gear_ratio"], 3.24)
        self.assertEqual(d["atf_temp"], 85)
        self.assertEqual(d["parking_lock"], 0)
        raw_na = struct.pack("<HHHHHHiBH", 0, 0, 0, 0xFFFF, 0xFFFF, 0, 0xFFFF, 0xFF, 0)
        d = R.RECORDS["sensors"].decode(raw_na)
        self.assertIsNone(d["gear_ratio"])
        self.assertIsNone(d["atf_temp"])
        self.assertIsNone(d["parking_lock"])

    def test_can_torque_and_enums(self):
        vals = [200, (0 + 500) * 4, (300 + 500) * 4, (120 + 500) * 4, (-20 + 500) * 4,
                600, 601, 3, 6, 0, 2500, 0xFFFF, 0xFFFF, 0, 0, 25, 90, 0x7FFF]
        raw = struct.pack("<BHHHHHHBBBHHHBBhhh", *vals)
        d = R.RECORDS["can"].decode(raw)
        self.assertEqual(d["max_torque"], 300.0)
        self.assertEqual(d["driver_torque"], -20.0)
        self.assertIsNone(d["torque_req_amount"])
        self.assertEqual(d["shifter_position"], "D")
        self.assertEqual(d["profile_input"], "ButtonPressed")
        self.assertEqual(d["torque_req_ctrl_type"], "None")
        self.assertEqual(d["e_oil_temp"], 90)
        self.assertIsNone(d["e_coolant_temp"])
        self.assertIsNone(d["fuel_rate"])

    def test_shift_live_gear_split(self):
        raw = struct.pack("<HHHBHHHhhhBBB", 1000, 2000, 0, 0, 1500, 1600, 700, 100, 120, 0x7FFF,
                          40 + 65, (3 << 4) | 2, 1)
        d = R.RECORDS["shift_live"].decode(raw)
        self.assertEqual(d["target_gear"], "D3")
        self.assertEqual(d["actual_gear"], "D2")
        self.assertEqual(d["atf_temp"], 65)
        self.assertIsNone(d["req_engine_torque"])
        self.assertEqual(d["profile"], "C")
        self.assertNotIn("targ_act_gear", d)

    def test_pressures_shift_circuits(self):
        raw = struct.pack("<B11H", 0b0101, *([100] * 11))
        d = R.RECORDS["pressures"].decode(raw)
        self.assertEqual(d["shift_circuits"], ["1-2", "3-4"])

    def test_fw_header_strings(self):
        raw = struct.pack("<II8s32s32s16s16s32s32s80s", 0xABCD5432, 0, b"", b"1.2.3", b"un52",
                          b"12:00:00", b"Sep  6 2026", b"v5.1", b"\x11" * 32, b"")
        d = R.RECORDS["fw_header"].decode(raw)
        self.assertEqual(d["version"], "1.2.3")
        self.assertEqual(d["project_name"], "un52")
        self.assertEqual(d["app_elf_sha256"], "11" * 32)
        self.assertNotIn("reserv1", d)

    def test_solenoid_trim_scale(self):
        raw = struct.pack("<16H", *([0] * 11 + [1023, 987, 0, 0, 0]))
        d = R.RECORDS["solenoids"].decode(raw)
        self.assertAlmostEqual(d["adjustment_spc"], 1.023)
        self.assertAlmostEqual(d["adjustment_mpc"], 0.987)


if __name__ == "__main__":
    unittest.main()
