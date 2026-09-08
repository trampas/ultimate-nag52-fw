"""
Live terminal dashboard for a recording session.

Deliberately terminal only. This gets used on a laptop in a moving car, often
over ssh, so it must not need a display, a window manager or a plotting library -
and it must not fight the recording loop for time. Rendering is a few hundred
bytes of ANSI every 250 ms from the main thread, between polling cycles.

Shows the driver agility score and the key shift quality metrics over a rolling
window, plus the last few shifts with what the TCU scored them.
"""
from __future__ import annotations

import math
import shutil
import sys
import time
from collections import deque
from typing import Any, Deque, Dict, List, Optional, TextIO

# Eighth blocks. Falls back to ASCII if the terminal cannot encode them.
BLOCKS = "▁▂▃▄▅▆▇█"
ASCII_BLOCKS = ".:-=+*#@"
CSI = "\x1b["


def _supports_unicode(stream) -> bool:
    enc = getattr(stream, "encoding", None) or ""
    try:
        BLOCKS.encode(enc or "ascii")
        return True
    except (UnicodeEncodeError, LookupError):
        return False


class Dashboard:
    """
    Feed it every cycle and every shift trace; call ``render`` as often as you
    like - it rate limits itself.
    """

    def __init__(self, window_s: float = 120.0, stream: TextIO = sys.stdout,
                 interval: float = 0.25) -> None:
        self.window_s = window_s
        self.stream = stream
        self.interval = interval
        self.blocks = BLOCKS if _supports_unicode(stream) else ASCII_BLOCKS
        self.samples: Deque[Dict[str, Any]] = deque()
        self.shifts: Deque[Dict[str, Any]] = deque(maxlen=8)
        self._last_render = 0.0
        self._lines = 0
        self.started = time.monotonic()

    # -- ingest --------------------------------------------------------------
    def add_cycle(self, cyc: Dict[str, Any]) -> None:
        t = cyc.get("t")
        if t is None:
            return
        sens = cyc.get("sensors") or {}
        can = cyc.get("can") or {}
        dyn = cyc.get("driving_dynamics") or {}
        live = cyc.get("shift_live") or {}
        self.samples.append({
            "t": t,
            "agility": dyn.get("agility_score"),
            "pedal": can.get("pedal_pos"),
            "input_rpm": sens.get("input_rpm"),
            "output_rpm": sens.get("output_rpm"),
            "gear": live.get("actual_gear"),
            "target": live.get("target_gear"),
            "profile": live.get("profile"),
            "atf": sens.get("atf_temp"),
            "terrain": dyn.get("terrain_coeff"),
            "road_conf": dyn.get("road_confidence"),
            "brake": dyn.get("brake_pressed"),
        })
        while self.samples and t - self.samples[0]["t"] > self.window_s:
            self.samples.popleft()

    def add_shift(self, shift: Dict[str, Any]) -> None:
        self.shifts.append(shift)

    # -- drawing -------------------------------------------------------------
    def _spark(self, key: str, width: int, lo: Optional[float] = None,
               hi: Optional[float] = None) -> str:
        vals = [s[key] for s in self.samples if isinstance(s.get(key), (int, float))]
        if not vals:
            return " " * width
        # bucket the window into `width` columns so the time axis is stable
        out = []
        n = len(vals)
        for i in range(width):
            a, b = i * n // width, max(i * n // width + 1, (i + 1) * n // width)
            chunk = vals[a:b]
            out.append(max(chunk) if chunk else vals[-1])
        vlo = lo if lo is not None else min(out)
        vhi = hi if hi is not None else max(out)
        if vhi <= vlo:
            vhi = vlo + 1
        s = ""
        for v in out:
            f = (v - vlo) / (vhi - vlo)
            idx = int(max(0.0, min(0.999, f)) * len(self.blocks))
            s += self.blocks[idx]
        return s

    def _bar(self, v: Optional[float], lo: float, hi: float, width: int) -> str:
        if v is None:
            return "-" * width
        f = max(0.0, min(1.0, (v - lo) / (hi - lo))) if hi > lo else 0.0
        n = int(round(f * width))
        return ("#" * n) + ("." * (width - n))

    def render(self, force: bool = False) -> None:
        now = time.monotonic()
        if not force and now - self._last_render < self.interval:
            return
        self._last_render = now
        cols = max(60, min(shutil.get_terminal_size((100, 30)).columns, 140))
        w = cols - 22                      # room for the label column
        cur = self.samples[-1] if self.samples else {}
        lines: List[str] = []

        span = (self.samples[-1]["t"] - self.samples[0]["t"]) if len(self.samples) > 1 else 0.0
        lines.append("nag52 live  gear %-5s profile %-3s  in %5s out %5s rpm  pedal %3s  atf %3s C" % (
            "%s>%s" % (cur.get("gear"), cur.get("target")) if cur.get("gear") else "-",
            cur.get("profile") or "-", cur.get("input_rpm") or "-", cur.get("output_rpm") or "-",
            cur.get("pedal") if cur.get("pedal") is not None else "-",
            cur.get("atf") if cur.get("atf") is not None else "-"))
        lines.append("last %.0f s of %.0f" % (span, self.window_s))
        lines.append("")

        ag = cur.get("agility")
        if ag is None:
            lines.append("agility        (no driving_dynamics record - old firmware, or not polled)")
        else:
            lines.append("agility %3d    %s" % (ag, self._spark("agility", w, 0, 100)))
            lines.append("  engage>=60     %s" % self._bar(ag, 0, 100, w - 24))
        lines.append("pedal   %3s    %s" % (
            cur.get("pedal") if cur.get("pedal") is not None else "-",
            self._spark("pedal", w, 0, 250)))
        lines.append("input rpm      %s" % self._spark("input_rpm", w, 0, 4500))
        tc = cur.get("terrain")
        if tc is not None:
            # sin(grade + rolling) x10000 -> degrees
            deg = math.degrees(math.asin(max(-0.3, min(0.3, tc / 10000.0))))
            lines.append("grade %+5.1f    %s conf %s%%" % (
                deg, self._spark("terrain", w - 9, -1500, 3500),
                cur.get("road_conf", "-")))
        lines.append("")

        lines.append("recent shifts  resp_ms  dur_ms    jerk    hole   slip_J  agility arm blend  t_ms  adapt")
        if not self.shifts:
            lines.append("  (none yet - shift quality comes from the TCU trace)")
        for sh in list(self.shifts)[-6:]:
            q = sh.get("quality") or {}
            st = sh.get("stamp") or {}
            adapt = "-"
            if st:
                adapt = st.get("adapt_reason", "-")
                if st.get("spc_delta") or st.get("prefill_delta"):
                    adapt += " spc%+d pre%+d" % (st.get("spc_delta", 0), st.get("prefill_delta", 0))
                if "flare" in (st.get("flags") or []):
                    adapt = "FLARE " + adapt
            lines.append("  %-11s %7s %7s %7s %7s %8s %7s %3s %5s %5s  %s" % (
                "%s>%s" % (sh.get("gear_from"), sh.get("gear_to")),
                q.get("response_ms", "-"), q.get("duration_ms", "-"),
                ("%.0f" % q["peak_jerk"]) if "peak_jerk" in q else "-",
                q.get("torque_hole", "-"), q.get("slip_energy_j", "-"),
                sh.get("agility_score", "-"),
                {1: "A", 0: "B"}.get(st.get("arm"), "-") if st else "-",
                ("%d%%" % st["blend_pct"]) if st and "blend_pct" in st else "-",
                st.get("target_time_ms", "-") if st else "-",
                adapt))

        buf = CSI + "H" + CSI + "2J" if self._lines == 0 else CSI + "%dA" % self._lines
        out = buf + "".join(l[:cols].ljust(cols) + CSI + "K\n" for l in lines)
        self._lines = len(lines)
        try:
            self.stream.write(out)
            self.stream.flush()
        except (OSError, ValueError):
            pass

    def finish(self) -> None:
        try:
            self.stream.write("\n")
            self.stream.flush()
        except (OSError, ValueError):
            pass
