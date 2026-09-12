"""
Read the TCU's high rate shift recorder.

The diagnostic link is request/response, so polling costs one round trip per
record (~6.5 ms) and a full record set only reaches ~17 Hz - about two samples
across a shift's 100-200 ms inertia phase.  The firmware therefore records the
shift itself into a PSRAM ring at the 20 ms period its control loop already
runs at, and this module pulls the window around each completed shift out
afterwards, in the gap between shifts.

Transfer is deliberately host paced: every chunk is a separate request for at
most 255 bytes, so the USB serial bridge's FIFO is never burst through.

Layout must track ``src/shift_trace.h``; ``SAMPLE_FMT``/``HEADER_FMT`` sizes are
checked against the sizes the firmware reports, so a mismatch is reported rather
than silently mis-decoded.
"""
from __future__ import annotations

import struct
from typing import Any, Dict, List, Optional

from .protocol import KwpError, KwpNegativeResponse

RLI_SHIFT_TRACE = 0x33
TRACE_MAGIC = 0x43415254  # 'TRAC'

# ReadMemoryByAddress allows 255 bytes, but the wire format is ASCII hex
# ("#%04X" + payload.hex() + "\n"), so an N byte payload is 2N+6 bytes on the
# UART.  A full 255 byte read is a 518 byte frame, which is 90 % of the CP2102N's
# 576 byte UART receive buffer - too close to rely on the USB host draining in
# time. Version 4 fits three 38-byte samples per request (234 UART bytes).
# Keep requests paced; consecutive ladder shifts can have no idle sample.
MAX_CHUNK = 120

# struct ShiftTraceSample - version 3: 30 bytes, version 4: 38 bytes
LEGACY_SAMPLE_FMT = "<IHHHhHHHHBBBBBBhh"
SAMPLE_FMT = "<IIHHHhHHHHBBBBBBhhhh"
SAMPLE_SIZE = struct.calcsize(SAMPLE_FMT)
SAMPLE_FIELDS = ["t_ms", "shift_id", "input_rpm", "output_rpm", "engine_rpm", "input_torque",
                 "p_on", "p_off", "spc", "mpc", "phase", "subphase_shift",
                 "subphase_mod", "flags", "pedal", "gear", "trq_req_amount",
                 "engine_torque", "request_wire_nm", "engine_drag_nm"]
LEGACY_SAMPLE_FIELDS = [k for k in SAMPLE_FIELDS if k not in
                        ("shift_id", "request_wire_nm", "engine_drag_nm")]

# struct ShiftQuality - 16 bytes, computed on the TCU as the shift happens.
# There is no single quality number and no mode-independent one, so this is a
# vector; scripts/shift_quality.py judges it against per-mode targets.
QUALITY_FMT = "<HHHHIHBB"
QUALITY_FIELDS = ["response_ms", "duration_ms", "peak_jerk_mms3", "torque_hole",
                  "slip_energy_j", "lockup_rate", "settle_osc", "valid"]
# struct ShiftStamp - version 4: 16 bytes, version 5: 20 bytes.
# What was in force when the shift ran and what the
# quality adaptation did afterwards. This is what lets a single drive carry
# several experiments: every shift is labelled with its feature set and A/B arm.
STAMP_FMT_V4 = "<BBBBBBHhhhh"
STAMP_FIELDS_V4 = ["features", "arm", "blend_pct", "flags", "adapt_reason", "algorithm",
                   "target_time_ms", "spc_offset", "prefill_offset", "spc_delta", "prefill_delta"]
STAMP_FMT_V5 = "<BBBBBBHhhhhhh"
STAMP_FIELDS_V5 = ["features", "arm", "blend_pct", "flags", "adapt_reason", "algorithm",
                   "target_time_ms", "spc_offset", "prefill_offset", "shift_time_offset",
                   "spc_delta", "prefill_delta", "shift_time_delta"]
FEATURE_BITS = {0x01: "blend_time", 0x02: "blend_points", 0x04: "quality_adapt",
                0x08: "next_gear", 0x10: "interleave", 0x20: "algo_adapt",
                0x40: "profile_agility", 0x80: "feedback_guard"}
STAMP_FLAG_BITS = {0x01: "flare", 0x02: "adapted", 0x04: "manual", 0x08: "kickdown",
                   0x80: "annotated"}
# QualityReason in src/adaptation/quality_adapt.h
ADAPT_REASONS = {0: "not evaluated", 1: "disabled", 2: "no quality", 3: "not forward",
                 4: "manual", 5: "kickdown", 6: "agility", 7: "atf", 8: "too slow",
                 9: "grade", 10: "flare", 11: "slip budget", 12: "slow response",
                 13: "early bite", 14: "harsh", 15: "soft long", 16: "in target",
                 17: "clamped"}
# struct ShiftTraceEvent - version 3: 44 bytes, version 4: 52 bytes, version 5: 56 bytes
LEGACY_EVENT_FMT = "<IIBBBB" + QUALITY_FMT[1:] + STAMP_FMT_V4[1:]
EVENT_FMT_V4 = "<IHh" + LEGACY_EVENT_FMT[1:]
EVENT_FMT_V5 = "<IHh" + "<IIBBBB"[1:] + QUALITY_FMT[1:] + STAMP_FMT_V5[1:]
EVENT_SIZE = struct.calcsize(EVENT_FMT_V5)
# struct ShiftTraceHeader - fixed part, then 4 events
HEADER_FMT = "<IBBHIIIB3x"
HEADER_SIZE = struct.calcsize(HEADER_FMT)
N_EVENTS = 4

GEAR_NAMES = {0: "N/P", 1: "1", 2: "2", 3: "3", 4: "4", 5: "5", 6: "R1", 7: "R2"}


class TraceUnavailable(Exception):
    """The firmware has no trace buffer (older build, or allocation failed)."""


# Must track SHIFT_TRACE_VERSION in src/shift_trace.h. Bumped whenever a field's
# meaning changes, even if the layout does not - a size check cannot catch that.
TRACE_VERSION = 5


def read_header(client) -> Dict[str, Any]:
    try:
        raw = client.read_local_ident(RLI_SHIFT_TRACE)
    except KwpNegativeResponse as exc:
        raise TraceUnavailable(str(exc))
    if len(raw) < HEADER_SIZE:
        raise TraceUnavailable("header too short (%d bytes)" % len(raw))
    magic, ver, ssize, cap, addr, seq, dropped, n_ev = struct.unpack_from(HEADER_FMT, raw, 0)
    if magic != TRACE_MAGIC:
        raise TraceUnavailable("bad magic 0x%08X" % magic)
    if ver not in (3, 4, TRACE_VERSION):
        raise TraceUnavailable(
            "trace version mismatch: firmware %d, decoder %d. Field meanings have "
            "changed between these, so decoding would silently misreport rather "
            "than fail - a size check cannot catch a field that kept its width."
            % (ver, TRACE_VERSION))
    if ver >= 5:
        event_fmt = EVENT_FMT_V5
        stamp_fields = STAMP_FIELDS_V5
    elif ver >= 4:
        event_fmt = EVENT_FMT_V4
        stamp_fields = STAMP_FIELDS_V4
    else:
        event_fmt = LEGACY_EVENT_FMT
        stamp_fields = STAMP_FIELDS_V4
    event_size = struct.calcsize(event_fmt)
    expected_sample = SAMPLE_SIZE if ver >= 4 else struct.calcsize(LEGACY_SAMPLE_FMT)
    if len(raw) < HEADER_SIZE + N_EVENTS * event_size:
        raise TraceUnavailable("header events truncated")
    if ssize != expected_sample:
        raise TraceUnavailable("sample size mismatch: firmware %d, decoder %d - "
                               "shift_trace.py is out of sync with shift_trace.h"
                               % (ssize, expected_sample))
    events = []
    off = HEADER_SIZE
    for i in range(min(n_ev, N_EVENTS)):
        v = struct.unpack_from(event_fmt, raw, off + i * event_size)
        identity = {}
        if ver >= 4:
            identity = dict(shift_id=v[0], output_rpm_start=v[1], atf_temp_start=v[2])
            v = v[3:]
        s0, s1, gf, gt, done, agility = v[0], v[1], v[2], v[3], v[4], v[5]
        nq = len(QUALITY_FIELDS)
        q = dict(zip(QUALITY_FIELDS, v[6:6 + nq]))
        st = dict(zip(stamp_fields, v[6 + nq:]))
        if ver < 4:
            del st["algorithm"]
        st["features"] = [n for b, n in FEATURE_BITS.items() if st["features"] & b]
        st["flags"] = [n for b, n in STAMP_FLAG_BITS.items() if st["flags"] & b]
        st["adapt_reason"] = ADAPT_REASONS.get(st["adapt_reason"], st["adapt_reason"])
        ev = {"seq_start": s0, "seq_end": s1, "gear_from": GEAR_NAMES.get(gf, gf),
              "gear_to": GEAR_NAMES.get(gt, gt), "done": bool(done),
              # how hard the driver was pushing when this shift started - the gate
              # any future adaptation needs so it does not learn Comfort from an
              # Agility shift
              "agility_score": agility}
        if q.pop("valid", 0):
            # SI, scaled x1000 on the wire to stay an integer.
            q["peak_jerk"] = q.pop("peak_jerk_mms3") / 1000.0
            ev["quality"] = q
        ev.update(identity)
        ev["stamp"] = st
        events.append(ev)
    return {"version": ver, "sample_size": ssize, "capacity": cap, "buffer_addr": addr,
            "seq": seq, "dropped": dropped, "events": events}


def read_samples(client, header: Dict[str, Any], first: int, count: int) -> List[Dict[str, Any]]:
    """
    Pull ``count`` samples starting at absolute sequence number ``first``.

    Samples still in the ring satisfy ``header['seq'] - n < capacity``; anything
    older has been overwritten and is skipped rather than returned as garbage.
    """
    sample_fmt = SAMPLE_FMT if header["version"] >= 4 else LEGACY_SAMPLE_FMT
    sample_fields = SAMPLE_FIELDS if header["version"] >= 4 else LEGACY_SAMPLE_FIELDS
    sample_size = header["sample_size"]
    cap = header["capacity"]
    base = header["buffer_addr"]
    newest = header["seq"]
    out: List[Dict[str, Any]] = []
    n = first
    while n < first + count and n < newest:
        if newest - n >= cap:       # overwritten while we were reading
            n += 1
            continue
        slot = n % cap
        # Read as many whole samples as fit in one response, without wrapping
        # past the end of the ring.
        run = min((first + count) - n, newest - n, cap - slot, MAX_CHUNK // sample_size)
        data = client.read_memory_raw(base + slot * sample_size, run * sample_size)
        for i in range(run):
            v = struct.unpack_from(sample_fmt, data, i * sample_size)
            rec = dict(zip(sample_fields, v))
            rec["seq"] = n + i
            rec["shifting"] = bool(rec["flags"] & 0x01)
            rec["circuits"] = (rec["flags"] >> 1) & 0x0F
            rec["gear_actual"] = GEAR_NAMES.get(rec["gear"] >> 4, rec["gear"] >> 4)
            rec["gear_target"] = GEAR_NAMES.get(rec["gear"] & 0x0F, rec["gear"] & 0x0F)
            if rec["trq_req_amount"] == 32767:
                rec["trq_req_amount"] = None       # no request active
            if header["version"] >= 4:
                rec["raw_kickdown"] = bool(rec["flags"] & 0x20)
                rec["kickdown_demand"] = bool(rec["flags"] & 0x40)
                rec["request_gross"] = bool(rec["flags"] & 0x80)
                for key in ("request_wire_nm", "engine_drag_nm"):
                    if rec[key] == 32767:
                        rec[key] = None
            del rec["flags"], rec["gear"]
            out.append(rec)
        n += run

    # The ring keeps filling while we read (7-8 new samples per chunk), so a slot
    # can be overwritten between the header read and the read of that slot. Drop
    # anything whose timestamp is not consistent with its neighbours - without this
    # a drive produced duplicate samples and jumps of several hundred seconds.
    clean = []
    for r in out:
        if clean:
            dt = r["t_ms"] - clean[-1]["t_ms"]
            if dt <= 0 or dt > 200:
                break                              # stale from an older wrap
        clean.append(r)
    return clean


def read_shift(client, header: Dict[str, Any], event: Dict[str, Any],
               pre: int = 25, post: int = 15) -> Optional[Dict[str, Any]]:
    """One completed shift plus context either side (25 samples = 0.5 s)."""
    if not event["done"]:
        return None
    first = max(0, event["seq_start"] - pre)
    count = (event["seq_end"] - first) + post
    samples = read_samples(client, header, first, count)
    if not samples:
        return None
    # Confirm the whole window was still in the ring when we finished reading it.
    try:
        after = read_header(client)
        if after["seq"] - first >= after["capacity"]:
            return None                            # overwritten mid-read, discard
    except (TraceUnavailable, KwpError):
        pass
    out = {"trace_version": header["version"], "gear_from": event["gear_from"], "gear_to": event["gear_to"],
           "seq_start": event["seq_start"], "seq_end": event["seq_end"],
           "samples": samples}
    for key in ("shift_id", "output_rpm_start", "atf_temp_start"):
        if key in event:
            out[key] = event[key]
    if "quality" in event:
        out["quality"] = event["quality"]
    out["agility_score"] = event.get("agility_score", 0)
    if "stamp" in event:
        out["stamp"] = event["stamp"]
    return out
