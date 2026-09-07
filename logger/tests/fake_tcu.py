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


from nag52logger import calibration as C  # noqa: E402

C_DEFAULT_CAL = {
    "tcc_cal_name": "71", "mech_cal_name": "51", "hydr_cal_name": "STDP", "shift_algo_pack_name": "SM00",
    "tcc_cal": {"multiplier_map_x": [0, 850], "multiplier_map_z": [250, 100],
                "pump_map_x": list(range(0, 1100, 100)), "pump_map_z": [50] * 11},
    "mech_cal": {"gb_ty": 1, "ratio_table": [0, 3932, 2408, 1486, 1000, 830, 3100, 1899],
                 "intertia_factor": [1000] * 8, "friction_map": [1500] * 48,
                 "max_torque_on_clutch": [400] * 4, "max_torque_off_clutch": [400] * 4,
                 "release_spring_pressure": [700, 750, 800, 650, 600, 900], "intertia_torque": [120] * 8,
                 "strongest_loaded_clutch_idx": [6, 3, 0, 0, 0, 3, 5, 5], "turbine_drag": [40] * 8,
                 "atf_density_minus_50c": 900, "atf_density_drop_per_c": 70,
                 "atf_density_centrifugal_force_factor": [0, 1200, 1300]},
    "hydr_cal": {"p_multi_1": 1500, "p_multi_other": 1000, "lp_reg_spring_pressure": 1000,
                 "overlap_circuit_factor_spc": [1000] * 8, "overlap_circuit_factor_mpc": [1000] * 8,
                 "overlap_circuit_spring_pressure": [-100] * 8, "shift_reg_spring_pressure": 601,
                 "shift_spc_gain": [1993] * 8, "min_mpc_pressure": 500, "filter_factor": 4,
                 "mpc_flush_temp_threshold": 90, "mpc_no_flush_time": 0, "mpc_flush_time": 0,
                 "extra_p_not_shifting": 0, "shift_pressure_addr_percent": 0, "inlet_pressure_offset": 0,
                 "inlet_pressure_input_min": 0, "inlet_pressure_input_max": 10000,
                 "inlet_pressure_output_min": 0, "inlet_pressure_output_max": 7700,
                 "extra_pressure_pump_speed_min": 0, "extra_pressure_pump_speed_max": 6000,
                 "extra_pressure_adder_r1_1": 0, "extra_pressure_adder_other_gears": 0,
                 "shift_pressure_factor_percent": 100,
                 "pcs_map_x": [0, 1000, 2000, 3000, 4000, 6000, 7700], "pcs_map_y": [0, 40, 80, 120],
                 "pcs_map_z": [1200 - i * 30 for i in range(28)]},
    "shift_algo_cal": {},
}


class FakeTcu:
    def __init__(self) -> None:
        self._rx = bytearray()          # bytes waiting for the PC to read
        self._lock = threading.Lock()
        self.timeout = 0.05
        self.is_open = True
        self.session = 0x81
        self.tcu_ms = 100_000
        self.calibration = C.encode_calibration(C_DEFAULT_CAL)
        self.requests: List[bytes] = []
        self.pending_logs: List[str] = []   # injected before the next response
        self.corrupt_next = 0               # emit N corrupt frames before answering
        self.drop_next = 0                  # swallow N requests (no answer)
        self.response_pending_first = False  # send 0x78 then the answer
        self.values: Dict[str, Dict[str, int]] = {}
        # Shift trace: None = firmware without the recorder. set_trace() builds one.
        self.TRACE_ADDR = 0x3F800100
        self.trace: bytes = None            # packed ShiftTraceHeader
        self.trace_ring: bytes = b""        # packed ShiftTraceSample[]

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
        elif sid == 0x23:
            self._read_memory(req)
        elif sid == 0x24:
            self._read_memory_ext(req)
        else:
            self._neg(sid, 0x11)

    def _read_memory(self, req: bytes) -> None:
        if len(req) != 5:
            self._neg(0x23, 0x12)
            return
        addr = (req[1] << 16) | (req[2] << 8) | req[3]
        n = req[4]
        if 0x800000 <= addr and addr + n <= 0x87D000:
            off = addr - 0x800000
            blob = self.calibration
            chunk = blob[off:off + n]
            chunk = chunk + b"\xff" * (n - len(chunk))   # erased flash beyond the block
            self._respond(bytes([0x63]) + chunk)
        else:
            self._neg(0x23, 0x12)

    def _read_memory_ext(self, req: bytes) -> None:
        """ReadMemoryByAddressExt - used to pull shift trace samples."""
        if len(req) != 6 or self.trace is None:
            self._neg(0x24, 0x12)
            return
        addr = (req[1] << 24) | (req[2] << 16) | (req[3] << 8) | req[4]
        n = req[5]
        off = addr - self.TRACE_ADDR
        if off < 0 or off + n > len(self.trace_ring):
            self._neg(0x24, 0x12)
            return
        self._respond(bytes([0x64]) + self.trace_ring[off:off + n])

    def _rli(self, rli: int) -> None:
        if rli == 0x33:
            if self.trace is None:
                self._neg(0x21, 0x31)
            else:
                self._respond(bytes([0x61, 0x33]) + self.trace)
            return
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


def build_trace(n_samples: int = 60, capacity: int = 512, seq: int = 0,
                events=((10, 40, 2, 3, 1),), addr: int = 0x3F800100):
    """
    Build a (header, ring) pair matching src/shift_trace.h, for tests.

    `events` entries are (seq_start, seq_end, gear_from, gear_to, done).
    """
    import struct as _s
    SAMPLE = "<IHHHhHHHHBBBBBBhh"
    ring = b""
    for i in range(capacity):
        shifting = any(a <= i <= b for a, b, _, _, _ in events)
        ring += _s.pack(SAMPLE, 1000 + i * 20, 2000 - i, 900, 2100, 150,
                        3000 + i, 4000 - i, 5000, 6000, 2, 1, 0,
                        (1 if shifting else 0), 100, 0x23, 120, 200)
    hdr = _s.pack("<IBBHIIIB3x", 0x43415254, 1, _s.calcsize(SAMPLE), capacity,
                  addr, seq or n_samples, 0, len(events))
    for a, b, gf, gt, done in events:
        # event + ShiftQuality (response, duration, jerk mm/s^3, hole, energy,
        # lockup, osc, valid)
        hdr += _s.pack("<IIBBBB" + "HHHHIHBB", a, b, gf, gt, done, 72,
                       420, 1100, 38500, 66, 8100, 9400, 1, 1 if done else 0)
    hdr += b"\x00" * (28 * (4 - len(events)))
    return hdr, ring
