"""
EGS calibration block download and decode.

The TCU keeps a copy of the EGS52/53 calibration (``CalibrationInfo`` in
``src/egs_calibration/calibration_structs.h``) in the ``tcm_shift_store``
flash partition at 0x349000.  It is readable over KWP2000
ReadMemoryByAddress (SID 0x23) using the virtual address range 0x800000..
(the firmware maps 0x800000 to the start of the partition).

This module reads the block, validates the magic/length, and decodes it
into engineering values so a log file records exactly which calibration the
shift algorithms were running with.  Layouts must be kept in sync with
``calibration_structs.h``; ``CAL_STRUCT_SIZE`` is checked against the
``len`` field the firmware wrote, so a layout mismatch is reported rather
than silently mis-decoded.
"""
from __future__ import annotations

import struct
from typing import Any, Dict, List, Optional, Sequence, Tuple

CAL_VIRTUAL_BASE = 0x800000
CAL_MAGIC = 0xDEADBEEF
SHIFT_ARRAY_LEN = 8
SHIFT_NAMES = ["1-2", "2-3", "3-4", "4-5", "2-1", "3-2", "4-3", "5-4"]
CLUTCH_NAMES = ["K1", "K2", "K3", "B1", "B2", "B3"]
GEAR_NAMES = ["P/N", "1", "2", "3", "4", "5", "R1", "R2"]

# (field name, struct format, count)  - count 1 => scalar, >1 => list
TCC_CAL: List[Tuple[str, str, int]] = [
    ("multiplier_map_x", "H", 2), ("multiplier_map_z", "H", 2),
    ("pump_map_x", "H", 11), ("pump_map_z", "H", 11),
]
MECH_CAL: List[Tuple[str, str, int]] = [
    ("gb_ty", "B", 1), ("ratio_table", "H", 8), ("intertia_factor", "H", 8),
    ("friction_map", "H", 48), ("max_torque_on_clutch", "H", 4),
    ("max_torque_off_clutch", "H", 4), ("release_spring_pressure", "H", 6),
    ("intertia_torque", "H", 8), ("strongest_loaded_clutch_idx", "B", 8),
    ("turbine_drag", "H", 8), ("atf_density_minus_50c", "H", 1),
    ("atf_density_drop_per_c", "H", 1), ("atf_density_centrifugal_force_factor", "H", 3),
]
HYDR_CAL: List[Tuple[str, str, int]] = [
    ("p_multi_1", "H", 1), ("p_multi_other", "H", 1), ("lp_reg_spring_pressure", "H", 1),
    ("overlap_circuit_factor_spc", "H", 8), ("overlap_circuit_factor_mpc", "H", 8),
    ("overlap_circuit_spring_pressure", "h", 8), ("shift_reg_spring_pressure", "H", 1),
    ("shift_spc_gain", "H", 8), ("min_mpc_pressure", "H", 1), ("filter_factor", "B", 1),
    ("mpc_flush_temp_threshold", "B", 1), ("mpc_no_flush_time", "H", 1), ("mpc_flush_time", "H", 1),
    ("extra_p_not_shifting", "H", 1), ("shift_pressure_addr_percent", "H", 1),
    ("inlet_pressure_offset", "H", 1), ("inlet_pressure_input_min", "H", 1),
    ("inlet_pressure_input_max", "H", 1), ("inlet_pressure_output_min", "H", 1),
    ("inlet_pressure_output_max", "H", 1), ("extra_pressure_pump_speed_min", "H", 1),
    ("extra_pressure_pump_speed_max", "H", 1), ("extra_pressure_adder_r1_1", "H", 1),
    ("extra_pressure_adder_other_gears", "H", 1), ("shift_pressure_factor_percent", "H", 1),
    ("pcs_map_x", "H", 7), ("pcs_map_y", "H", 4), ("pcs_map_z", "H", 28),
]
SHIFT_ALGO_CAL: List[Tuple[str, str, int]] = (
    [("momentum_%s_x" % s, "B", 3) for s in ("1_2", "2_3", "3_4", "4_5")]
    + [("momentum_%s_y" % s, "B", 2) for s in ("1_2", "2_3", "3_4", "4_5")]
    + [("momentum_%s_z" % s, "B", 6) for s in ("1_2", "2_3", "3_4", "4_5")]
    + [("momentum_%s_x" % s, "B", 6) for s in ("2_1", "3_2", "4_3", "5_4")]
    + [("momentum_%s_y" % s, "B", 10) for s in ("2_1", "3_2", "4_3", "5_4")]
    + [("momentum_%s_z" % s, "B", 60) for s in ("2_1", "3_2", "4_3", "5_4")]
    + [("trq_adder_%s_x" % s, "B", 6) for s in ("1_2", "2_3", "3_4", "4_5")]
    + [("trq_adder_%s_y" % s, "B", 8) for s in ("1_2", "2_3", "3_4", "4_5")]
    + [("trq_adder_%s_z" % s, "B", 48) for s in ("1_2", "2_3", "3_4", "4_5")]
    + [("trq_adder_%s_x" % s, "B", 3) for s in ("2_1", "3_2", "4_3", "5_4")]
    + [("trq_adder_%s_y" % s, "B", 4) for s in ("2_1", "3_2", "4_3", "5_4")]
    + [("trq_adder_%s_z" % s, "B", 12) for s in ("2_1", "3_2", "4_3", "5_4")]
)

# CalibrationInfo: magic u32, len u16, crc u16, then name[16] + block for each section
SECTIONS: List[Tuple[str, str, List[Tuple[str, str, int]]]] = [
    ("tcc_cal_name", "tcc_cal", TCC_CAL),
    ("mech_cal_name", "mech_cal", MECH_CAL),
    ("hydr_cal_name", "hydr_cal", HYDR_CAL),
    ("shift_algo_pack_name", "shift_algo_cal", SHIFT_ALGO_CAL),
]
HEADER_FMT = "<IHH"
NAME_LEN = 16


def _section_fmt(fields: Sequence[Tuple[str, str, int]]) -> str:
    return "<" + "".join("%d%s" % (n, f) for _, f, n in fields)


def _section_size(fields: Sequence[Tuple[str, str, int]]) -> int:
    return struct.calcsize(_section_fmt(fields))


CAL_STRUCT_SIZE = struct.calcsize(HEADER_FMT) + sum(NAME_LEN + _section_size(f) for _, _, f in SECTIONS)


def _decode_section(fields: Sequence[Tuple[str, str, int]], data: bytes) -> Dict[str, Any]:
    vals = struct.unpack(_section_fmt(fields), data)
    out: Dict[str, Any] = {}
    i = 0
    for name, _fmt, n in fields:
        if n == 1:
            out[name] = vals[i]
        else:
            out[name] = list(vals[i:i + n])
        i += n
    return out


def _encode_section(fields: Sequence[Tuple[str, str, int]], values: Dict[str, Any]) -> bytes:
    flat: List[int] = []
    for name, _fmt, n in fields:
        v = values.get(name, 0 if n == 1 else [0] * n)
        if n == 1:
            flat.append(int(v))
        else:
            v = list(v) + [0] * (n - len(v))
            flat.extend(int(x) for x in v[:n])
    return struct.pack(_section_fmt(fields), *flat)


def _cstr(b: bytes) -> str:
    return b.split(b"\0", 1)[0].decode("ascii", errors="replace")


def crc16_sum(payload: bytes) -> int:
    """The firmware's checksum: sum of (index + byte) over the block after the 8 byte header."""
    res = 0
    for i, b in enumerate(payload):
        res = (res + i + b) & 0xFFFF
    return res


def decode_calibration(raw: bytes) -> Dict[str, Any]:
    """
    Decode a raw CalibrationInfo block.  Always returns a dict; problems are
    reported in ``_error`` / ``_warnings`` rather than raised, so a log file
    still records what was read.
    """
    out: Dict[str, Any] = {"_raw": raw.hex(), "_size": len(raw), "_expected_size": CAL_STRUCT_SIZE,
                           "_warnings": []}
    if len(raw) < struct.calcsize(HEADER_FMT):
        out["_error"] = "block too short"
        return out
    magic, length, crc = struct.unpack_from(HEADER_FMT, raw, 0)
    out.update({"magic": "0x%08X" % magic, "len": length, "crc": crc})
    if magic != CAL_MAGIC:
        out["_error"] = "bad magic 0x%08X (calibration not programmed?)" % magic
        return out
    if length != CAL_STRUCT_SIZE:
        out["_warnings"].append("firmware len %d != decoder layout %d (calibration_structs.h changed?)"
                                % (length, CAL_STRUCT_SIZE))
    if len(raw) >= length:
        calc = crc16_sum(raw[8:length])
        out["crc_ok"] = (calc == crc)
        if calc != crc:
            out["_warnings"].append("crc mismatch: stored 0x%04X, calculated 0x%04X" % (crc, calc))
    pos = struct.calcsize(HEADER_FMT)
    for name_key, sec_key, fields in SECTIONS:
        size = _section_size(fields)
        if pos + NAME_LEN + size > len(raw):
            out["_warnings"].append("truncated before %s" % sec_key)
            break
        out[name_key] = _cstr(raw[pos:pos + NAME_LEN])
        pos += NAME_LEN
        out[sec_key] = _decode_section(fields, raw[pos:pos + size])
        pos += size
    _add_derived(out)
    return out


def encode_calibration(cal: Dict[str, Any]) -> bytes:
    """Inverse of decode_calibration (used by tests and the fake TCU)."""
    body = b""
    for name_key, sec_key, fields in SECTIONS:
        body += cal.get(name_key, "").encode("ascii")[:NAME_LEN].ljust(NAME_LEN, b"\0")
        body += _encode_section(fields, cal.get(sec_key, {}))
    length = struct.calcsize(HEADER_FMT) + len(body)
    return struct.pack(HEADER_FMT, CAL_MAGIC, length, crc16_sum(body)) + body


def _add_derived(cal: Dict[str, Any]) -> None:
    """Human-readable views of the values the shift algorithms depend on most."""
    mech = cal.get("mech_cal")
    hydr = cal.get("hydr_cal")
    d: Dict[str, Any] = {}
    if isinstance(mech, dict):
        rt = mech.get("ratio_table") or []
        d["ratios"] = {GEAR_NAMES[i]: round(r / 1000.0, 3) for i, r in enumerate(rt) if i < len(GEAR_NAMES)}
        d["gearbox_type"] = {0: "large (W5A580)", 1: "small (W5A330)"}.get(mech.get("gb_ty"), mech.get("gb_ty"))
        fm = mech.get("friction_map") or []
        if len(fm) == 48:
            d["friction_by_gear"] = {GEAR_NAMES[g]: {CLUTCH_NAMES[c]: fm[g * 6 + c] for c in range(6)} for g in range(8)}
        d["release_spring_pressure"] = {CLUTCH_NAMES[i]: v for i, v in enumerate(mech.get("release_spring_pressure") or [])}
        d["strongest_loaded_clutch"] = {GEAR_NAMES[i]: (CLUTCH_NAMES[v] if v < 6 else v)
                                        for i, v in enumerate(mech.get("strongest_loaded_clutch_idx") or [])}
        for key in ("intertia_factor", "intertia_torque", "turbine_drag"):
            d[key] = {SHIFT_NAMES[i]: v for i, v in enumerate(mech.get(key) or [])}
    if isinstance(hydr, dict):
        for key in ("shift_spc_gain", "overlap_circuit_factor_spc", "overlap_circuit_factor_mpc",
                    "overlap_circuit_spring_pressure"):
            d[key] = {SHIFT_NAMES[i]: v for i, v in enumerate(hydr.get(key) or [])}
        d["max_solenoid_pressure_mbar"] = (hydr.get("pcs_map_x") or [None] * 7)[6]
        zeros = [k for k in ("p_multi_1", "p_multi_other") if hydr.get(k) == 0]
        zeros += ["shift_spc_gain[%s]" % SHIFT_NAMES[i] for i, v in enumerate(hydr.get("shift_spc_gain") or []) if v == 0]
        if zeros:
            cal["_warnings"].append("zero divisors in hydraulic calibration: %s" % ", ".join(zeros))
    cal["derived"] = d


def read_calibration(client, chunk: int = 128, length: Optional[int] = None) -> Dict[str, Any]:
    """
    Download the calibration block through a ``KwpClient``.  Reads the 8 byte
    header first to learn the real block length, then the rest in ``chunk``
    sized ReadMemoryByAddress requests.
    """
    head = client.read_memory(CAL_VIRTUAL_BASE, 8)
    magic, blen, _crc = struct.unpack(HEADER_FMT, head)
    if magic != CAL_MAGIC:
        return decode_calibration(head)
    total = length if length is not None else blen
    total = max(8, min(total, 64 * 1024))
    data = bytearray(head)
    while len(data) < total:
        n = min(chunk, total - len(data))
        data += client.read_memory(CAL_VIRTUAL_BASE + len(data), n)
    return decode_calibration(bytes(data))


def summarize(cal: Dict[str, Any]) -> Dict[str, Any]:
    """Compact view for ``info`` output."""
    if not isinstance(cal, dict):
        return {"_error": "no calibration"}
    if cal.get("_error"):
        return {"_error": cal["_error"]}
    d = cal.get("derived", {})
    return {
        "names": {k: cal.get(k) for k in ("tcc_cal_name", "mech_cal_name", "hydr_cal_name", "shift_algo_pack_name")},
        "crc_ok": cal.get("crc_ok"),
        "gearbox_type": d.get("gearbox_type"),
        "ratios": d.get("ratios"),
        "shift_spc_gain": d.get("shift_spc_gain"),
        "p_multi_1": (cal.get("hydr_cal") or {}).get("p_multi_1"),
        "p_multi_other": (cal.get("hydr_cal") or {}).get("p_multi_other"),
        "max_solenoid_pressure_mbar": d.get("max_solenoid_pressure_mbar"),
        "warnings": cal.get("_warnings"),
    }
