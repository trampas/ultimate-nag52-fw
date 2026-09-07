"""
A pyserial-lookalike that behaves like the firmware's USB endpoint
(src/diag/endpoints/usb_endpoint.cpp + kwp2000.cpp), for tests.

* Requests are raw ``[len_hi, len_lo, id_hi, id_lo, payload]`` bytes.
* Responses are ``#07E9<hex>\\n`` lines.
* Can interleave ESP_LOG lines and corrupt frames on demand.
"""
from __future__ import annotations

import struct
import threading
from typing import Dict, List, Optional

import sys, os
sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))
from nag52logger import records as R  # noqa: E402

TX_ID = 0x07E9


def frame_line(payload: bytes, fid: int = TX_ID) -> bytes:
    return ("#%04X%s\n" % (fid, payload.hex().upper())).encode("ascii")


class FakeTcu:
    def __init__(self) -> None:
        self._rx = bytearray()          # bytes waiting for the PC to read
        self._lock = threading.Lock()
        self.timeout = 0.05
        self.is_open = True
        self.session = 0x81
        self.tcu_ms = 100_000
        self.requests: List[bytes] = []
        self.pending_logs: List[str] = []   # injected before the next response
        self.corrupt_next = 0               # emit N corrupt frames before answering
        self.drop_next = 0                  # swallow N requests (no answer)
        self.response_pending_first = False  # send 0x78 then the answer
        self.values: Dict[str, Dict[str, int]] = {}

    # -- pyserial-ish API ----------------------------------------------------
    @property
    def in_waiting(self) -> int:
        with self._lock:
            return len(self._rx)

    def read(self, n: int = 1) -> bytes:
        with self._lock:
            out = bytes(self._rx[:n])
            del self._rx[:n]
        return out

    def write(self, data: bytes) -> int:
        self.requests.append(bytes(data))
        length = (data[0] << 8) | data[1]
        assert length == len(data) - 2, "bad length prefix"
        payload = data[4:]
        self._handle(payload)
        return len(data)

    def close(self) -> None:
        self.is_open = False

    def reset_input_buffer(self) -> None:
        with self._lock:
            self._rx.clear()

    # -- helpers for tests ---------------------------------------------------
    def emit_raw(self, data: bytes) -> None:
        with self._lock:
            self._rx += data

    def emit_log(self, text: str) -> None:
        self.emit_raw((text + "\r\n").encode())

    def _respond(self, payload: bytes) -> None:
        for l in self.pending_logs:
            self.emit_log(l)
        self.pending_logs = []
        while self.corrupt_next:
            self.corrupt_next -= 1
            self.emit_raw(b"#07E961ZZ12\n")
        self.emit_raw(frame_line(payload))

    def _neg(self, sid: int, nrc: int) -> None:
        self._respond(bytes([0x7F, sid, nrc]))

    # -- firmware emulation --------------------------------------------------
    def _handle(self, req: bytes) -> None:
        if self.drop_next:
            self.drop_next -= 1
            return
        sid = req[0]
        if self.response_pending_first:
            self.response_pending_first = False
            self.emit_raw(frame_line(bytes([0x7F, sid, 0x78])))
        if sid == 0x10:
            if req[1] in (0x81, 0x92, 0x93):
                self.session = req[1]
                self._respond(bytes([0x50, req[1]]))
            else:
                self._neg(sid, 0x12)
        elif sid == 0x3E:
            self._respond(bytes([0x7E]))
        elif sid == 0x21:
            self._rli(req[1])
        else:
            self._neg(sid, 0x11)

    def _rli(self, rli: int) -> None:
        if rli == 0xE1:
            self._respond(bytes([0x61, 0xE1]) + b"AABBCCDDEEFF")
            return
        rec = next((r for r in R.RECORDS.values() if r.rli == rli), None)
        if rec is None:
            self._neg(0x21, 0x31)
            return
        if rec.name == "tcu_time":
            self.tcu_ms += 37
            body = struct.pack("<I", self.tcu_ms)
        else:
            body = self.encode(rec)
        self._respond(bytes([0x61, rli]) + body)

    def encode(self, rec) -> bytes:
        """Pack a record from self.values[rec.name] (missing fields -> 0 / b'')."""
        vals = self.values.get(rec.name, {})
        packed = []
        for f in rec.fields:
            v = vals.get(f.name)
            if f.fmt.endswith("s"):
                packed.append(v if isinstance(v, bytes) else (v or "").encode())
            elif f.fmt == "?":
                packed.append(bool(v))
            else:
                packed.append(int(v or 0))
        return rec._struct.pack(*packed)
