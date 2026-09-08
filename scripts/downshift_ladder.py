#!/usr/bin/env python3
"""
Check the anti-clunk downshift guard against a logged drive.

A coast-down ladder is serialised - 4-3, 3-2 and 2-1 are each decided only once
the previous one has finished - and each rung takes about a second. The last one
can therefore still be running when the car reaches a standstill, and its closing
ramp to SPC_MAX applies the gear against a stopped output shaft. That is the
coast-down clunk.

`SBS downshift_min_end_rpm` holds a downshift whose projected output speed at the
end of the shift falls below it. This script replays that projection over a log
and reports which shifts it would have held, against what the shift actually
measured, so the threshold is chosen from data rather than guessed.

Read the two columns that matter:

  HELD + high jerk   a clunk the guard would have prevented (what it is for)
  HELD + low jerk    a clean shift held to a standstill instead. Not harmful -
                     the standstill shift is the smoothest one in the log - but
                     it means launching from the higher gear more often.
  RUN + high jerk    a clunk the guard misses. Raise the threshold.

Timing note: the `t` on a shift_trace line is when the LOGGER read it, not when
the shift happened. Shift order and gaps must come from the sample timestamps,
which are the TCU's own clock, and the samples belonging to the shift are the
ones inside seq_start..seq_end - the surrounding context can carry `shifting`
samples from the neighbouring shift.

Usage: scripts/downshift_ladder.py logger/logs/<log>.jsonl [--floor 0] [--margin 1.20]
"""
from __future__ import annotations

import argparse
import json
import os
import statistics
import sys

DOWNSHIFTS = {("2", "1"), ("3", "2"), ("4", "3"), ("5", "4")}


def load(path):
    out = []
    for line in open(path):
        if '"shift_trace"' not in line:
            continue
        r = json.loads(line)
        if r.get("type") != "shift_trace":
            continue
        own = [s for s in r["samples"] if r["seq_start"] <= s["seq"] <= r["seq_end"]]
        pre = [s for s in r["samples"] if s["seq"] < r["seq_start"]]
        if not own or "quality" not in r:
            continue
        r["own"], r["pre"] = own, pre
        r["t0"] = own[0]["t_ms"] / 1000.0
        r["t1"] = own[-1]["t_ms"] / 1000.0
        r["out0"] = own[0]["output_rpm"]
        r["outN"] = own[-1]["output_rpm"]
        # Deceleration as the TCU sees it: output shaft rpm/s over the 0.5 s
        # before the shift. Gearbox::decel_rpm_s is the same quantity at 10 Hz.
        r["decel"] = None
        if len(pre) >= 6:
            dt = (pre[-1]["t_ms"] - pre[0]["t_ms"]) / 1000.0
            if dt > 0:
                r["decel"] = (pre[-1]["output_rpm"] - pre[0]["output_rpm"]) / dt
        out.append(r)
    out.sort(key=lambda r: r["t0"])
    return out


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("logs", nargs="+")
    ap.add_argument("--floor", type=int, default=0, help="SBS downshift_min_end_rpm, output shaft rpm")
    ap.add_argument("--margin", type=float, default=1.20,
                    help="actual shift duration / mapped target; measured 1.20 median on downshifts")
    ap.add_argument("--harsh", type=float, default=25.0, help="peak jerk counted as a clunk, m/s^3")
    a = ap.parse_args()

    held_harsh = held_clean = run_harsh = run_clean = 0
    ratios = []
    for path in a.logs:
        tr = load(path)
        print("%s: %d shifts with quality" % (os.path.basename(path), len(tr)))
        print("  %8s %-6s %6s %6s %7s %6s %7s %6s %6s  %s" %
              ("tcu_t", "shift", "target", "actual", "decel", "out0", "proj", "jerk", "hole", "guard"))
        for r in tr:
            key = (str(r["gear_from"]), str(r["gear_to"]))
            if key not in DOWNSHIFTS:
                continue
            q = r["quality"]
            tt = (r.get("stamp") or {}).get("target_time_ms") or 0
            dur = (r["t1"] - r["t0"]) * 1000
            if tt:
                ratios.append(dur / tt)
            d = r["decel"]
            proj, guard = None, "no data"
            if tt and d is not None:
                if r["out0"] <= a.floor:
                    guard = "RUN (standstill)"
                elif d >= 0:
                    guard = "RUN (not slowing)"
                else:
                    proj = r["out0"] + d * (tt * a.margin / 1000.0)
                    guard = "HELD" if proj < a.floor else "RUN"
            harsh = q["peak_jerk"] >= a.harsh
            if guard == "HELD":
                held_harsh += harsh
                held_clean += not harsh
            else:
                run_harsh += harsh
                run_clean += not harsh
            print("  %8.2f %-6s %6d %6.0f %7s %6d %7s %6.1f %6d  %s%s" %
                  (r["t0"], "%s>%s" % key, tt, dur, ("%.0f" % d) if d is not None else "-",
                   r["out0"], ("%.0f" % proj) if proj is not None else "-",
                   q["peak_jerk"], q["torque_hole"], guard,
                   "   <== CLUNK" if harsh else ""))
        print()

    print("floor %d rpm, margin %.2f, clunk above %.0f m/s^3" % (a.floor, a.margin, a.harsh))
    print("  clunks held (the point)          %d" % held_harsh)
    print("  clunks still run (missed)        %d" % run_harsh)
    print("  clean shifts held (cost)         %d" % held_clean)
    print("  clean shifts run (untouched)     %d" % run_clean)
    if ratios:
        print("  actual/target on downshifts: median %.2f  p90 %.2f  max %.2f"
              % (statistics.median(ratios), sorted(ratios)[int(0.9 * len(ratios))], max(ratios)))
    if run_harsh:
        print("  -> a clunk is still getting through; raise --floor")
    return 0


if __name__ == "__main__":
    sys.exit(main())
