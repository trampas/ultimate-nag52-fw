"""
Live-data record definitions for the Ultimate-NAG52 TCU.

Each ``Record`` mirrors one KWP2000 ReadDataByLocalIdentifier (SID 0x21)
record served by the firmware.  Layouts come from ``src/diag/diag_data.h``,
``src/common_structs.h`` (ShiftAlgoFeedback), ``src/models/clutch_speed.hpp``
(ClutchSpeeds) and ``src/nvs/eeprom_config.h`` (TCM_CORE_CONFIG).  All structs
are packed, little endian.

Values are decoded into engineering units (mBar, RPM, Nm, degC, ...) and enum
fields are stored as their names.  If the firmware ever changes a struct and
the received length no longer matches, the record is stored as ``{"_raw":
"<hex>"}`` instead of being dropped, so old loggers keep producing usable
files with new firmware.
"""
from __future__ import annotations

import struct
from dataclasses import dataclass, field
from typing import Any, Callable, Dict, List, Optional

# --- RLI numbers (src/diag/diag_data.h) --------------------------------------
RLI_GEARBOX_SENSORS = 0x20
RLI_SOLENOID_STATUS = 0x21
RLI_CAN_DATA_DUMP = 0x22
RLI_SYS_USAGE = 0x23
RLI_TCC_PROGRAM = 0x24
RLI_PRESSURES = 0x25
RLI_TCU_TIME = 0x26
RLI_SHIFT_LIVE = 0x27
RLI_FW_HEADER = 0x28
RLI_CLUTCH_SPEEDS = 0x30
RLI_SHIFTING_ALGO = 0x31
RLI_EFUSE_CONFIG = 0xFD
RLI_TCM_CONFIG = 0xFE

# --- Enums ------------------------------------------------------------------
SHIFTER_POSITION = {0: "P", 1: "P_R", 2: "R", 3: "R_N", 4: "N", 5: "N_D", 6: "D",
                    7: "PLUS", 8: "MINUS", 9: "FOUR", 10: "THREE", 11: "TWO",
                    12: "ONE", 255: "SNV"}
PADDLE_POSITION = {0: "None", 1: "Plus", 2: "Minus", 3: "PlusAndMinus", 255: "SNV"}
TORQUE_REQ_CTRL = {0: "None", 1: "NormalSpeed", 2: "FastAsPossible", 3: "BackToDemandTorque"}
TORQUE_REQ_BOUNDS = {0: "LessThan", 1: "MoreThan", 2: "Exact"}
PROFILE_INPUT = {0: "None", 1: "SwitchTop", 2: "SwitchBottom", 3: "ButtonPressed",
                 4: "ButtonReleased", 5: "SLRLeft", 6: "SLRMiddle", 7: "SLRRight", 255: "SNV"}
GEARBOX_PROFILE = {0: "S", 1: "C", 2: "W", 3: "A", 4: "M", 5: "R", 6: "I", 7: "_", 8: "F", 255: "SNV"}
GEARBOX_GEAR = {1: "D1", 2: "D2", 3: "D3", 4: "D4", 5: "D5", 8: "P", 9: "N",
                10: "R1", 11: "R2", 15: "SNV"}
TCC_STATE = {0: "Open", 1: "Slipping", 2: "Closed"}
SHIFT_CIRCUIT_BITS = {1: "1-2", 2: "2-3", 4: "3-4", 8: "4-5"}

ENUMS = {
    "ShifterPosition": SHIFTER_POSITION,
    "PaddlePosition": PADDLE_POSITION,
    "TorqueRequestControlType": TORQUE_REQ_CTRL,
    "TorqueRequestBounds": TORQUE_REQ_BOUNDS,
    "DiagProfileInputState": PROFILE_INPUT,
    "GearboxProfile": GEARBOX_PROFILE,
    "GearboxGear": GEARBOX_GEAR,
    "TccState": TCC_STATE,
}

U16_NA = 0xFFFF
I16_NA = 0x7FFF
U8_NA = 0xFF


def _torque_x4(v: int) -> Optional[float]:
    """CAN torques are sent as (Nm + 500) * 4."""
    return None if v == U16_NA else v / 4.0 - 500.0


def _shift_circuits(v: int) -> List[str]:
    return [name for bit, name in SHIFT_CIRCUIT_BITS.items() if v & bit]


@dataclass
class Field:
    name: str
    fmt: str                       # struct format character(s)
    unit: str = ""
    scale: Optional[float] = None  # value * scale
    offset: float = 0.0            # (value * scale) + offset
    na: Optional[int] = None       # raw value meaning "not available" -> None
    enum: Optional[str] = None     # key in ENUMS
    convert: Optional[Callable[[int], Any]] = None
    desc: str = ""

    def decode(self, raw: Any) -> Any:
        if self.na is not None and raw == self.na:
            return None
        if self.convert is not None:
            return self.convert(raw)
        if self.enum is not None:
            return ENUMS[self.enum].get(raw, raw)
        if self.scale is not None or self.offset:
            v = raw * (self.scale if self.scale is not None else 1)
            v += self.offset
            return round(v, 4) if isinstance(v, float) else v
        return raw

    def describe(self) -> Dict[str, Any]:
        d: Dict[str, Any] = {"fmt": self.fmt}
        if self.unit:
            d["unit"] = self.unit
        if self.scale is not None:
            d["scale"] = self.scale
        if self.offset:
            d["offset"] = self.offset
        if self.na is not None:
            d["na"] = self.na
        if self.enum:
            d["enum"] = self.enum
        if self.desc:
            d["desc"] = self.desc
        return d


@dataclass
class Record:
    name: str
    rli: int
    desc: str
    fields: List[Field]
    group: str = "fast"      # "fast" = every cycle, "slow" = periodic, "once" = snapshot
    post: Optional[Callable[[Dict[str, Any]], None]] = None
    _struct: struct.Struct = field(init=False, repr=False)

    def __post_init__(self) -> None:
        self._struct = struct.Struct("<" + "".join(f.fmt for f in self.fields))

    @property
    def size(self) -> int:
        return self._struct.size

    def decode(self, payload: bytes) -> Dict[str, Any]:
        if len(payload) != self.size:
            return {"_raw": payload.hex(), "_len": len(payload), "_expected": self.size}
        values = self._struct.unpack(payload)
        out: Dict[str, Any] = {}
        for f, raw in zip(self.fields, values):
            out[f.name] = f.decode(raw)
        if self.post:
            self.post(out)
        return out

    def describe(self) -> Dict[str, Any]:
        return {"rli": self.rli, "size": self.size, "group": self.group,
                "desc": self.desc,
                "fields": {f.name: f.describe() for f in self.fields}}


# --- Post processors ---------------------------------------------------------
def _post_shift_live(d: Dict[str, Any]) -> None:
    v = d.pop("targ_act_gear")
    d["target_gear"] = GEARBOX_GEAR.get(v >> 4, v >> 4)
    d["actual_gear"] = GEARBOX_GEAR.get(v & 0x0F, v & 0x0F)


def _post_pressures(d: Dict[str, Any]) -> None:
    v = d["ss_flag"]
    d["shift_circuits"] = None if v == U8_NA else _shift_circuits(v)


def _post_fw_header(d: Dict[str, Any]) -> None:
    for k in ("version", "project_name", "time", "date", "idf_ver"):
        d[k] = d[k].split(b"\0", 1)[0].decode("utf-8", errors="replace")
    d["app_elf_sha256"] = d["app_elf_sha256"].hex()
    d.pop("reserv1", None)
    d.pop("reserv2", None)


# --- Record table ------------------------------------------------------------
RECORDS: Dict[str, Record] = {}


def _add(rec: Record) -> Record:
    RECORDS[rec.name] = rec
    return rec


_add(Record("tcu_time", RLI_TCU_TIME, "TCU millisecond clock (esp_timer based, ms since boot)", [
    Field("tcu_ms", "I", "ms"),
]))

_add(Record("sensors", RLI_GEARBOX_SENSORS, "Gearbox sensor inputs (DATA_GEARBOX_SENSORS)", [
    Field("n2_rpm", "H", "rpm", desc="Raw N2 speed sensor"),
    Field("n3_rpm", "H", "rpm", desc="Raw N3 speed sensor"),
    Field("input_rpm", "H", "rpm", desc="Turbine / input shaft RPM calculated from N2+N3"),
    Field("gear_ratio", "H", "", scale=0.01, na=U16_NA, desc="Measured ratio"),
    Field("target_ratio", "H", "", scale=0.01, na=U16_NA, desc="Ratio of target gear"),
    Field("v_batt", "H", "mV", desc="Solenoid supply / battery voltage"),
    Field("atf_temp", "i", "degC", na=0xFFFF, desc="ATF temperature (invalid while parking lock engaged)"),
    Field("parking_lock", "B", "", na=U8_NA, desc="1 = engaged"),
    Field("output_rpm", "H", "rpm", desc="Output shaft RPM"),
]))

_add(Record("solenoids", RLI_SOLENOID_STATUS, "Solenoid commands and measured currents (DATA_SOLENOIDS)", [
    Field("spc_pwm", "H", "/4096"), Field("mpc_pwm", "H", "/4096"), Field("tcc_pwm", "H", "/4096"),
    Field("y3_pwm", "H", "/4096"), Field("y4_pwm", "H", "/4096"), Field("y5_pwm", "H", "/4096"),
    Field("spc_current", "H", "mA"), Field("mpc_current", "H", "mA"), Field("tcc_current", "H", "mA"),
    Field("targ_spc_current", "H", "mA"), Field("targ_mpc_current", "H", "mA"),
    Field("adjustment_spc", "H", "", scale=0.001, desc="Current-loop trim factor"),
    Field("adjustment_mpc", "H", "", scale=0.001, desc="Current-loop trim factor"),
    Field("y3_current", "H", "mA"), Field("y4_current", "H", "mA"), Field("y5_current", "H", "mA"),
]))

_add(Record("can", RLI_CAN_DATA_DUMP, "Engine / vehicle inputs from CAN and TCU torque requests (DATA_CANBUS_RX)", [
    Field("pedal_pos", "B", "/250", na=U8_NA),
    Field("min_torque", "H", "Nm", convert=_torque_x4),
    Field("max_torque", "H", "Nm", convert=_torque_x4),
    Field("static_torque", "H", "Nm", convert=_torque_x4, desc="Engine torque (converted)"),
    Field("driver_torque", "H", "Nm", convert=_torque_x4, desc="Driver demanded torque (converted)"),
    Field("left_rear_rpm", "H", "rpm", na=U16_NA),
    Field("right_rear_rpm", "H", "rpm", na=U16_NA),
    Field("profile_input", "B", "", enum="DiagProfileInputState"),
    Field("shifter_position", "B", "", enum="ShifterPosition"),
    Field("paddle_position", "B", "", enum="PaddlePosition"),
    Field("engine_rpm", "H", "rpm", na=U16_NA),
    Field("fuel_rate", "H", "", na=U16_NA),
    Field("torque_req_amount", "H", "Nm", convert=_torque_x4, desc="TCU torque request (None when no request)"),
    Field("torque_req_ctrl_type", "B", "", enum="TorqueRequestControlType"),
    Field("torque_req_bounds", "B", "", enum="TorqueRequestBounds"),
    Field("e_iat_temp", "h", "degC", na=I16_NA),
    Field("e_oil_temp", "h", "degC", na=I16_NA),
    Field("e_coolant_temp", "h", "degC", na=I16_NA),
]))

_add(Record("sys_usage", RLI_SYS_USAGE, "TCU CPU / memory usage (DATA_SYS_USAGE)", [
    Field("core1_load", "H", "%", scale=0.1), Field("core2_load", "H", "%", scale=0.1),
    Field("free_ram", "I", "B"), Field("total_ram", "I", "B"),
    Field("free_psram", "I", "B"), Field("total_psram", "I", "B"),
    Field("num_tasks", "I", ""),
], group="slow"))

_add(Record("tcc", RLI_TCC_PROGRAM, "Torque converter lockup program (DATA_TCC_PROGRAM)", [
    Field("current_pressure", "H", "mBar"), Field("target_pressure", "H", "mBar"),
    Field("slip_now", "h", "rpm"), Field("slip_filtered", "h", "rpm"), Field("slip_target", "H", "rpm"),
    Field("pedal_now", "H", "/250"), Field("pedal_filtered", "H", "/250"),
    Field("target_state", "B", "", enum="TccState"), Field("current_state", "B", "", enum="TccState"),
    Field("can_request_bits", "B", ""),
    Field("engine_output_joule", "I", "J"), Field("tcc_absorbed_joule", "I", "J"),
    Field("load_percent", "h", "%"),
]))

_add(Record("pressures", RLI_PRESSURES, "Pressure manager outputs (DATA_PRESSURES)", [
    Field("ss_flag", "B", "", desc="Active shift-circuit bitmask"),
    Field("shift_req_pressure", "H", "mBar", na=U16_NA, desc="Requested SPC (shift) pressure"),
    Field("modulating_req_pressure", "H", "mBar", na=U16_NA, desc="Requested MPC (modulating) pressure"),
    Field("working_pressure", "H", "mBar", na=U16_NA, desc="Calculated line pressure"),
    Field("inlet_pressure", "H", "mBar", na=U16_NA),
    Field("corrected_spc_pressure", "H", "mBar", na=U16_NA),
    Field("corrected_mpc_pressure", "H", "mBar", na=U16_NA),
    Field("tcc_pressure", "H", "mBar", na=U16_NA),
    Field("on_clutch_pressure", "H", "mBar", na=U16_NA),
    Field("off_clutch_pressure", "H", "mBar", na=U16_NA),
    Field("overlap_mod", "H", "mBar", na=U16_NA),
    Field("overlap_shift", "H", "mBar", na=U16_NA),
], post=_post_pressures))

_add(Record("shift_live", RLI_SHIFT_LIVE, "Compact shift overview (SHIFT_LIVE_INFO)", [
    Field("spc_pressure", "H", "mBar"), Field("mpc_pressure", "H", "mBar"), Field("tcc_pressure", "H", "mBar"),
    Field("ss_pos", "B", "", desc="Shift solenoid state (PWM>>8 of Y3|Y4|Y5)"),
    Field("input_rpm", "H", "rpm"), Field("engine_rpm", "H", "rpm"), Field("output_rpm", "H", "rpm"),
    Field("engine_torque", "h", "Nm", desc="Converted driver torque"),
    Field("input_torque", "h", "Nm"),
    Field("req_engine_torque", "h", "Nm", na=I16_NA),
    Field("atf_temp", "B", "degC", offset=-40),
    Field("targ_act_gear", "B", ""),
    Field("profile", "B", "", enum="GearboxProfile"),
], post=_post_shift_live))

_add(Record("clutch_speeds", RLI_CLUTCH_SPEEDS, "Modelled clutch slip speeds (ClutchSpeeds)", [
    Field("k1", "h", "rpm"), Field("k2", "h", "rpm"), Field("k3", "h", "rpm"),
    Field("b1", "h", "rpm"), Field("b2", "h", "rpm"), Field("b3", "h", "rpm"),
]))

_add(Record("driving_dynamics", 0x32, "Driver agility demand (DATA_DRIVING_DYNAMICS)", [
    Field("agility_score", "B", "", desc="0-100, rises at once and decays over ~25 s"),
    Field("agility_demand", "B", "", desc="instantaneous value the score is tracking"),
    Field("pedal_pos", "B", "/250"),
    Field("pedal_rise", "B", "/250", desc="pedal travel added within the last 500 ms"),
    Field("decel_rpm_s", "h", "rpm/s", desc="output shaft, negative when braking"),
    Field("profile_id", "B", "", desc="profile actually in force"),
    Field("selected_id", "B", "", desc="profile the driver asked for"),
    Field("brake_pressed", "B", "", desc="1 while the brake pedal is down"),
    Field("kickdown_pressed", "B", "", desc="1 on a kickdown switch press"),
]))

_add(Record("shift_algo", RLI_SHIFTING_ALGO, "Shifting algorithm feedback (ShiftAlgoFeedback)", [
    Field("active", "B", "", desc="1 while a shift algorithm is running"),
    Field("shift_phase", "B", ""), Field("subphase_shift", "B", ""), Field("subphase_mod", "B", ""),
    Field("sync_rpm", "H", "rpm"),
    Field("pid_torque", "h", "Nm"), Field("adder_torque", "h", "Nm"),
    Field("p_on", "H", "mBar"), Field("p_off", "H", "mBar"),
    Field("s_off", "h", "rpm"), Field("s_on", "h", "rpm"),
    Field("s_turbine", "h", "rpm"), Field("s_targ", "h", "rpm"),
]))

_add(Record("fw_header", RLI_FW_HEADER, "Firmware image header (esp_app_desc_t)", [
    Field("magic_word", "I", ""), Field("secure_version", "I", ""), Field("reserv1", "8s", ""),
    Field("version", "32s", ""), Field("project_name", "32s", ""), Field("time", "16s", ""),
    Field("date", "16s", ""), Field("idf_ver", "32s", ""), Field("app_elf_sha256", "32s", ""),
    Field("reserv2", "80s", ""),
], group="once", post=_post_fw_header))

_add(Record("tcm_config", RLI_TCM_CONFIG, "Vehicle / TCU configuration (TCM_CORE_CONFIG)", [
    Field("deprecated_is_large_nag", "B", ""),
    Field("diff_ratio", "H", "x1000"), Field("wheel_circumference", "H", "mm"),
    Field("is_four_matic", "B", ""),
    Field("transfer_case_high_ratio", "H", "x1000"), Field("transfer_case_low_ratio", "H", "x1000"),
    Field("default_profile", "B", "", enum="GearboxProfile"),
    Field("red_line_rpm_diesel", "H", "rpm"), Field("red_line_rpm_petrol", "H", "rpm"),
    Field("engine_type", "B", "", desc="0 diesel, 1 petrol"),
    Field("egs_can_type", "B", "", desc="1 EGS51, 2 EGS52, 3 EGS53"),
    Field("shifter_style", "B", "", desc="0 EWM, 1 TRRS, 2 SLR"),
    Field("io_0_usage", "B", ""), Field("input_sensor_pulses_per_rev", "B", ""),
    Field("output_pulse_width_per_kmh", "B", ""), Field("gen_mosfet_purpose", "B", ""),
    Field("throttlevalve_maxopeningangle", "B", "deg"),
    Field("c_eng", "H", ""), Field("engine_drag_torque", "H", "Nm/10"),
    Field("jeep_chrysler", "?", ""),
], group="once"))

# Default polling sets
DEFAULT_FAST = ["tcu_time", "sensors", "can", "pressures", "solenoids",
                "shift_live", "shift_algo", "clutch_speeds", "tcc"]
DEFAULT_SLOW = ["sys_usage"]
DEFAULT_ONCE = ["fw_header", "tcm_config"]


def describe_all() -> Dict[str, Any]:
    return {name: rec.describe() for name, rec in RECORDS.items()}


def resolve(names: List[str]) -> List[Record]:
    out = []
    for n in names:
        n = n.strip()
        if not n:
            continue
        if n not in RECORDS:
            raise KeyError("unknown record %r (known: %s)" % (n, ", ".join(RECORDS)))
        out.append(RECORDS[n])
    return out
