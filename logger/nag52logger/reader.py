"""
Read ``.jsonl`` files produced by the logger back into Python.

Typical use in a simulation / analysis script::

    from nag52logger.reader import LogFile

    log = LogFile.load("logs/nag52_20260906_150000.jsonl")
    for cyc in log.cycles:                 # one dict per polling cycle
        rpm = cyc["sensors"]["input_rpm"]
        spc = cyc["pressures"]["corrected_spc_pressure"]
        ...
    t, in_rpm = log.series("sensors", "input_rpm")     # aligned lists
    log.write_csv("out.csv")                            # flat table

``iter_entries`` streams a file without loading it fully.
"""
from __future__ import annotations

import csv
import gzip
import json
from typing import Any, Dict, Iterable, Iterator, List, Optional, Sequence, TextIO, Tuple


def _open_text(path: str) -> TextIO:
    if path.endswith(".gz"):
        return gzip.open(path, "rt", encoding="utf-8")
    return open(path, "r", encoding="utf-8")


def iter_entries(path: str) -> Iterator[Dict[str, Any]]:
    """Yield every JSON object in the file, skipping a truncated last line."""
    with _open_text(path) as fh:
        for line in fh:
            line = line.strip()
            if not line:
                continue
            try:
                yield json.loads(line)
            except json.JSONDecodeError:
                # A crash mid-write can leave a partial final line; ignore it.
                continue


def flatten_cycle(cycle: Dict[str, Any], sep: str = ".") -> Dict[str, Any]:
    """``{"t":1, "sensors": {"n2_rpm": 5}}`` -> ``{"t":1, "sensors.n2_rpm": 5}``."""
    out: Dict[str, Any] = {}
    for k, v in cycle.items():
        if k == "type":
            continue
        if isinstance(v, dict):
            for fk, fv in v.items():
                if isinstance(fv, list):
                    fv = "|".join(str(x) for x in fv)
                out[k + sep + fk] = fv
        else:
            out[k] = v
    return out


class LogFile:
    def __init__(self) -> None:
        self.path: Optional[str] = None
        self.header: Dict[str, Any] = {}
        self.snapshot: Dict[str, Any] = {}
        self.cycles: List[Dict[str, Any]] = []
        self.logs: List[Dict[str, Any]] = []
        self.events: List[Dict[str, Any]] = []
        self.accel: List[Dict[str, Any]] = []
        self.end: Dict[str, Any] = {}

    @classmethod
    def load(cls, path: str) -> "LogFile":
        lf = cls()
        lf.path = path
        for e in iter_entries(path):
            t = e.get("type")
            if t == "cycle":
                lf.cycles.append(e)
            elif t == "log":
                lf.logs.append(e)
            elif t == "header":
                lf.header = e
            elif t == "snapshot":
                lf.snapshot = e
            elif t == "accel":
                lf.accel.append(e)
            elif t == "event":
                lf.events.append(e)
            elif t == "end":
                lf.end = e
        return lf

    # -- convenience accessors ------------------------------------------------
    @property
    def duration(self) -> float:
        if self.cycles:
            return float(self.cycles[-1]["t"]) - float(self.cycles[0]["t"])
        if self.logs:
            return float(self.logs[-1]["t"]) - float(self.logs[0]["t"])
        return 0.0

    @property
    def record_names(self) -> List[str]:
        names: List[str] = []
        for c in self.cycles:
            for k, v in c.items():
                if isinstance(v, dict) and k not in names:
                    names.append(k)
        return names

    def accel_series(self, axis: Optional[str] = None) -> Tuple[List[float], List[Any]]:
        """
        Host accelerometer samples as aligned lists on the same ``t`` clock as
        ``cycles``. ``axis`` picks one of ``x``/``y``/``z``; the default returns
        the magnitude, which needs no knowledge of how the sensor was oriented.
        """
        ts: List[float] = []
        vs: List[Any] = []
        for a in self.accel:
            ts.append(a["t"])
            if axis is None:
                vs.append((a["x"] ** 2 + a["y"] ** 2 + a["z"] ** 2) ** 0.5)
            else:
                vs.append(a[axis])
        return ts, vs

    def accel_rate(self) -> Optional[float]:
        """Measured sample rate of the accelerometer capture, or None."""
        if len(self.accel) < 2:
            return None
        span = self.accel[-1]["t"] - self.accel[0]["t"]
        return (len(self.accel) - 1) / span if span > 0 else None

    def series(self, record: str, field: str, time_key: str = "t") -> Tuple[List[float], List[Any]]:
        """Aligned (time, value) lists for one field; cycles lacking it are skipped."""
        ts: List[float] = []
        vs: List[Any] = []
        for c in self.cycles:
            r = c.get(record)
            if isinstance(r, dict) and field in r:
                ts.append(c[time_key])
                vs.append(r[field])
        return ts, vs

    def columns(self) -> List[str]:
        cols: List[str] = []
        for c in self.cycles:
            for k in flatten_cycle(c):
                if k not in cols:
                    cols.append(k)
        return cols

    def rows(self, columns: Optional[Sequence[str]] = None) -> Iterable[Dict[str, Any]]:
        cols = list(columns) if columns else self.columns()
        for c in self.cycles:
            flat = flatten_cycle(c)
            yield {k: flat.get(k) for k in cols}

    def write_csv(self, path: str, columns: Optional[Sequence[str]] = None) -> int:
        cols = list(columns) if columns else self.columns()
        n = 0
        with open(path, "w", newline="", encoding="utf-8") as fh:
            w = csv.DictWriter(fh, fieldnames=cols)
            w.writeheader()
            for row in self.rows(cols):
                w.writerow(row)
                n += 1
        return n

    def write_log_text(self, path: str) -> int:
        """Dump the captured ESP_LOG lines as plain text (like a serial monitor)."""
        n = 0
        with open(path, "w", encoding="utf-8") as fh:
            for l in self.logs:
                if "raw" in l:
                    fh.write("%s\n" % l["raw"])
                else:
                    fh.write("%s (%s) %s: %s\n" % (l.get("level"), l.get("tcu_ms"), l.get("tag"), l.get("msg")))
                n += 1
        return n

    def shifts(self) -> List[Dict[str, Any]]:
        """
        Rough list of gear changes seen in ``shift_live`` (target != actual
        transitions).  Handy for jumping to interesting parts of a log.
        """
        out: List[Dict[str, Any]] = []
        active: Optional[Dict[str, Any]] = None
        for c in self.cycles:
            sl = c.get("shift_live")
            if not isinstance(sl, dict) or "actual_gear" not in sl:
                continue
            shifting = sl["actual_gear"] != sl["target_gear"]
            if shifting and active is None:
                active = {"t_start": c["t"], "seq_start": c["seq"], "from": sl["actual_gear"],
                          "to": sl["target_gear"], "profile": sl.get("profile")}
            elif not shifting and active is not None:
                active.update({"t_end": c["t"], "seq_end": c["seq"], "duration": round(c["t"] - active["t_start"], 3)})
                out.append(active)
                active = None
        return out

    def summary(self) -> Dict[str, Any]:
        s: Dict[str, Any] = {
            "path": self.path, "started": self.header.get("started"),
            "duration_s": round(self.duration, 1), "cycles": len(self.cycles),
            "log_lines": len(self.logs), "events": len(self.events), "records": self.record_names,
        }
        if self.cycles:
            s["cycle_rate_hz"] = round(len(self.cycles) / self.duration, 1) if self.duration else None
        fw = self.snapshot.get("records", {}).get("fw_header") if self.snapshot else None
        if isinstance(fw, dict):
            s["firmware"] = {k: fw.get(k) for k in ("version", "project_name", "date", "time", "idf_ver")}
        if self.snapshot.get("ecu_serial"):
            s["ecu_serial"] = self.snapshot["ecu_serial"]
        if self.snapshot.get("calibration") is not None:
            from .calibration import summarize
            s["calibration"] = summarize(self.snapshot["calibration"])
        s["shifts"] = len(self.shifts())
        if self.end:
            s["stats"] = self.end.get("stats")
        return s
