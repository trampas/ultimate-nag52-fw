"""
Shift trace readout tests.

The wire layout is duplicated between src/shift_trace.h and
nag52logger/shift_trace.py, so these check the decode against a fake TCU that
packs the C layout, and check the ring/overrun arithmetic that decides which
samples are still readable.
"""
import io
import os
import struct
import sys
import unittest

sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))
from nag52logger import shift_trace as ST  # noqa: E402
from nag52logger.logger import Nag52Logger  # noqa: E402
from nag52logger.reader import LogFile  # noqa: E402
from fake_tcu import FakeTcu, build_trace  # noqa: E402


class LayoutTests(unittest.TestCase):
    def test_struct_sizes_match_the_firmware_header(self):
        # src/shift_trace.h pins these with static_asserts.
        self.assertEqual(ST.SAMPLE_SIZE, 30)
        self.assertEqual(ST.EVENT_SIZE, 28)
        self.assertEqual(ST.HEADER_SIZE, 24)

    def test_chunk_size_leaves_headroom_in_the_bridge_fifo(self):
        # The wire format is ASCII hex, so an N byte payload is 2N+6 UART bytes.
        # That must stay well under the CP2102N's 576 byte receive buffer - a full
        # 255 byte read would be 518 bytes, 90 % of it.
        per_request = ST.MAX_CHUNK // ST.SAMPLE_SIZE
        self.assertEqual(per_request, 4)
        frame = 2 * (1 + per_request * ST.SAMPLE_SIZE) + 6
        self.assertLess(frame, 576 * 0.6, "frame %d bytes is too close to the FIFO" % frame)


class ReadoutTests(unittest.TestCase):
    def _client(self, **kw):
        from nag52logger.protocol import KwpClient, SerialReader
        tcu = FakeTcu()
        hdr, ring = build_trace(**kw)
        tcu.trace, tcu.trace_ring = hdr, ring
        rd = SerialReader(tcu, lambda t: None, lambda t: None)
        rd.start()
        cl = KwpClient(tcu, rd, timeout=0.5)
        cl.start_session(0x92)
        return cl, rd, tcu

    def test_header_decode(self):
        cl, rd, _ = self._client(seq=100, events=((10, 40, 2, 3, 1),))
        try:
            h = ST.read_header(cl)
            self.assertEqual(h["capacity"], 512)
            self.assertEqual(h["sample_size"], 30)
            self.assertEqual(h["seq"], 100)
            self.assertEqual(len(h["events"]), 1)
            ev = h["events"][0]
            self.assertEqual((ev["gear_from"], ev["gear_to"]), ("2", "3"))
            self.assertTrue(ev["done"])
        finally:
            rd.stop()

    def test_samples_decode_and_are_contiguous(self):
        cl, rd, _ = self._client(seq=100)
        try:
            h = ST.read_header(cl)
            s = ST.read_samples(cl, h, 0, 30)
            self.assertEqual(len(s), 30)
            self.assertEqual([x["seq"] for x in s], list(range(30)))
            # values follow build_trace's ramp
            self.assertEqual(s[0]["input_rpm"], 2000)
            self.assertEqual(s[5]["input_rpm"], 1995)
            self.assertEqual(s[5]["p_on"], 3005)
            self.assertEqual(s[0]["gear_actual"], "2")
            self.assertEqual(s[0]["gear_target"], "3")
        finally:
            rd.stop()

    def test_shift_window_includes_context_either_side(self):
        cl, rd, _ = self._client(seq=100, events=((30, 60, 2, 3, 1),))
        try:
            h = ST.read_header(cl)
            sh = ST.read_shift(cl, h, h["events"][0], pre=10, post=5)
            self.assertIsNotNone(sh)
            self.assertEqual(sh["samples"][0]["seq"], 20)      # 30 - 10 pre
            self.assertTrue(any(x["shifting"] for x in sh["samples"]))
            self.assertFalse(sh["samples"][0]["shifting"])     # context is quiet
        finally:
            rd.stop()

    def test_quality_vector_decodes(self):
        """The TCU computes the metrics itself; check they survive the wire."""
        cl, rd, _ = self._client(seq=100, events=((10, 40, 2, 3, 1),))
        try:
            q = ST.read_header(cl)["events"][0]["quality"]
            self.assertEqual(q["response_ms"], 420)
            self.assertEqual(q["duration_ms"], 1100)
            self.assertAlmostEqual(q["peak_jerk"], 38.5)     # sent as mm/s^3
            self.assertEqual(q["slip_energy_j"], 8100)
            self.assertEqual(q["settle_osc"], 1)
        finally:
            rd.stop()

    def test_unfinished_shift_has_no_quality(self):
        cl, rd, _ = self._client(seq=100, events=((30, 60, 2, 3, 0),))
        try:
            self.assertNotIn("quality", ST.read_header(cl)["events"][0])
        finally:
            rd.stop()

    def test_unfinished_shift_is_not_returned(self):
        cl, rd, _ = self._client(seq=100, events=((30, 60, 2, 3, 0),))
        try:
            h = ST.read_header(cl)
            self.assertIsNone(ST.read_shift(cl, h, h["events"][0]))
        finally:
            rd.stop()

    def test_overwritten_samples_are_skipped_not_returned_as_garbage(self):
        # seq far beyond capacity: the oldest samples are gone from the ring.
        cl, rd, _ = self._client(seq=2000, capacity=512)
        try:
            h = ST.read_header(cl)
            s = ST.read_samples(cl, h, 0, 40)   # all long overwritten
            self.assertEqual(s, [])
            s = ST.read_samples(cl, h, 1900, 20)
            self.assertEqual([x["seq"] for x in s], list(range(1900, 1920)))
        finally:
            rd.stop()

    def test_stale_samples_from_a_wrap_are_rejected(self):
        """
        The ring keeps filling while we read, so a slot can be overwritten between
        the header read and the read of that slot. The last drive produced
        duplicate samples and jumps of hundreds of seconds this way.
        """
        import struct as _s
        cl, rd, tcu = self._client(seq=100)
        try:
            h = ST.read_header(cl)
            # Corrupt slot 20 with a sample from a much later wrap.
            ring = bytearray(tcu.trace_ring)
            off = 20 * ST.SAMPLE_SIZE
            old_s = list(_s.unpack_from(ST.SAMPLE_FMT, ring, off))
            old_s[0] = 900_000                      # t_ms far in the future
            _s.pack_into(ST.SAMPLE_FMT, ring, off, *old_s)
            tcu.trace_ring = bytes(ring)
            got = ST.read_samples(cl, h, 10, 30)
            self.assertEqual([x["seq"] for x in got], list(range(10, 20)),
                             "should stop at the stale sample, not return it")
        finally:
            rd.stop()

    def test_torque_request_none_is_decoded(self):
        cl, rd, tcu = self._client(seq=60)
        try:
            import struct as _s
            ring = bytearray(tcu.trace_ring)
            v = list(_s.unpack_from(ST.SAMPLE_FMT, ring, 0))
            v[15] = 32767                            # INT16_MAX = no request
            _s.pack_into(ST.SAMPLE_FMT, ring, 0, *v)
            tcu.trace_ring = bytes(ring)
            s = ST.read_samples(cl, ST.read_header(cl), 0, 2)
            self.assertIsNone(s[0]["trq_req_amount"])
            self.assertEqual(s[1]["trq_req_amount"], 120)
            self.assertEqual(s[0]["engine_torque"], 200)
        finally:
            rd.stop()

    def test_never_reads_past_the_newest_sample(self):
        cl, rd, _ = self._client(seq=50)
        try:
            h = ST.read_header(cl)
            s = ST.read_samples(cl, h, 40, 100)
            self.assertEqual([x["seq"] for x in s], list(range(40, 50)))
        finally:
            rd.stop()

    def test_sample_size_mismatch_is_reported(self):
        cl, rd, tcu = self._client()
        try:
            bad = bytearray(tcu.trace)
            bad[5] = 99                      # sample_size field
            tcu.trace = bytes(bad)
            with self.assertRaises(ST.TraceUnavailable) as cm:
                ST.read_header(cl)
            self.assertIn("out of sync", str(cm.exception))
        finally:
            rd.stop()

    def test_bad_magic_is_reported(self):
        cl, rd, tcu = self._client()
        try:
            tcu.trace = b"\x00\x00\x00\x00" + tcu.trace[4:]
            with self.assertRaises(ST.TraceUnavailable):
                ST.read_header(cl)
        finally:
            rd.stop()


class RecordingTests(unittest.TestCase):
    """The recorder must pull a trace out and put it in the log."""

    def _run(self, tcu, path, **kw):
        lg = Nag52Logger(tcu, path, status=False, echo_log=False, request_timeout=0.3,
                         echo_stream=io.StringIO(), status_stream=io.StringIO(),
                         slow_interval=0.0, accel=None, **kw)
        return lg.run()

    def setUp(self):
        import tempfile
        self.tmp = tempfile.TemporaryDirectory()
        self.path = os.path.join(self.tmp.name, "log.jsonl")

    def tearDown(self):
        self.tmp.cleanup()

    def test_firmware_without_the_recorder_is_reported_once(self):
        tcu = FakeTcu()          # trace is None
        stats = self._run(tcu, self.path, max_cycles=6)
        self.assertEqual(stats["cycles"], 6)
        lf = LogFile.load(self.path)
        ev = [e["event"] for e in lf.events]
        self.assertEqual(ev[:2], ["port_open", "connected"])   # probe must not preempt
        self.assertEqual(ev.count("shift_trace_unavailable"), 1)
        self.assertEqual(lf.shift_traces, [])

    def test_ready_event_when_supported(self):
        tcu = FakeTcu()
        tcu.trace, tcu.trace_ring = build_trace(seq=100)
        self._run(tcu, self.path, max_cycles=4)
        lf = LogFile.load(self.path)
        ready = [e for e in lf.events if e["event"] == "shift_trace_ready"]
        self.assertEqual(len(ready), 1)
        self.assertEqual(ready[0]["capacity"], 512)
        self.assertEqual(ready[0]["seconds"], 10.2)

    def test_disabled_by_flag(self):
        tcu = FakeTcu()
        tcu.trace, tcu.trace_ring = build_trace()
        self._run(tcu, self.path, max_cycles=4, trace=False)
        lf = LogFile.load(self.path)
        self.assertFalse([e for e in lf.events if e["event"].startswith("shift_trace")])
        self.assertIs(lf.header["shift_trace"], False)


if __name__ == "__main__":
    unittest.main()
