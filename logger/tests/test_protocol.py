import os
import sys
import time
import unittest

sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))
from nag52logger.protocol import (KwpClient, KwpNegativeResponse, KwpTimeout, LineDemux,  # noqa: E402
                                  LogLine, SerialReader, decode_frame_line, encode_request)
from fake_tcu import FakeTcu, frame_line  # noqa: E402


class DemuxTests(unittest.TestCase):
    def test_encode_request_matches_firmware_framing(self):
        # Firmware: read_size == read_pos - 2, id = bytes 2..3, data = bytes 4..
        self.assertEqual(encode_request(bytes([0x21, 0x20])), bytes([0x00, 0x04, 0x07, 0xE1, 0x21, 0x20]))

    def test_decode_frame(self):
        f = decode_frame_line(b"#07E9611234")
        self.assertEqual(f.id, 0x07E9)
        self.assertEqual(f.data, bytes([0x61, 0x12, 0x34]))
        self.assertIsNone(decode_frame_line(b"#07E961ZZ"))
        self.assertIsNone(decode_frame_line(b"#07E9611"))  # odd length

    def test_split_stream(self):
        d = LineDemux()
        out = []
        out += list(d.feed(b"I (12) TAG: hello\r\n#07E96"))
        out += list(d.feed(b"1AA\nW (13) X: partial"))
        out += list(d.feed(b" line\n#07E9ZZ\n"))
        kinds = [k for k, _ in out]
        self.assertEqual(kinds, ["log", "frame", "log", "bad_frame"])
        self.assertEqual(out[0][1], "I (12) TAG: hello")
        self.assertEqual(out[1][1].data, bytes([0x61, 0xAA]))
        self.assertEqual(out[2][1], "W (13) X: partial line")

    def test_logline_parse(self):
        l = LogLine.parse("\x1b[0;32mI (1234) GEARBOX: Shift done\x1b[0m")
        self.assertEqual((l.level, l.tcu_ms, l.tag, l.msg), ("I", 1234, "GEARBOX", "Shift done"))
        self.assertIsNone(LogLine.parse("ets Jun  8 2016 00:22:57").level)


class ClientTests(unittest.TestCase):
    def setUp(self):
        self.tcu = FakeTcu()
        self.logs = []
        self.reader = SerialReader(self.tcu, self.logs.append)
        self.reader.start()
        self.client = KwpClient(self.tcu, self.reader, timeout=0.3, retries=2)

    def tearDown(self):
        self.reader.stop()
        self.reader.join(1)

    def test_session_and_read(self):
        self.client.start_session(0x92)
        self.assertEqual(self.tcu.session, 0x92)
        self.tcu.values["clutch_speeds"] = {"k1": -5, "b2": 300}
        data = self.client.read_local_ident(0x30)
        self.assertEqual(len(data), 12)
        self.assertEqual(self.client.read_ecu_serial(), "AABBCCDDEEFF")

    def test_negative_response(self):
        with self.assertRaises(KwpNegativeResponse) as cm:
            self.client.read_local_ident(0x7A)
        self.assertEqual(cm.exception.nrc, 0x31)

    def test_logs_interleaved_and_corrupt_frames_are_survived(self):
        self.tcu.pending_logs = ["I (100) TCC: lockup", "E (101) SOL: overcurrent"]
        self.tcu.corrupt_next = 2
        data = self.client.read_local_ident(0x30)
        self.assertEqual(len(data), 12)
        time.sleep(0.05)
        self.assertEqual(self.logs, ["I (100) TCC: lockup", "E (101) SOL: overcurrent"])
        self.assertEqual(self.reader.bad_frames, 2)

    def test_response_pending_is_waited_for(self):
        self.tcu.response_pending_first = True
        self.assertEqual(len(self.client.read_local_ident(0x30)), 12)
        self.assertEqual(self.client.stats["retries"], 0)

    def test_dropped_request_is_retried_then_times_out(self):
        self.tcu.drop_next = 1
        self.assertEqual(len(self.client.read_local_ident(0x30)), 12)
        self.assertEqual(self.client.stats["retries"], 1)
        self.tcu.drop_next = 5
        with self.assertRaises(KwpTimeout):
            self.client.read_local_ident(0x30)

    def test_stale_frames_are_discarded(self):
        self.tcu.emit_raw(frame_line(bytes([0x61, 0x25]) + b"\x00" * 23))  # unrelated stale reply
        time.sleep(0.05)
        data = self.client.read_local_ident(0x30)
        self.assertEqual(len(data), 12)


if __name__ == "__main__":
    unittest.main()
