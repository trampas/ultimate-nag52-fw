#!/usr/bin/env python3
"""Report adjacent downshift ladders and observed gap causes (Stage 0).

Uses TCU sample timestamps, never trace delivery time. A short gap identifies
only a candidate ladder, not a commitment or proof of avoidable latency.
Older logs still yield timing; unobserved time is explicitly unknown.
"""
from __future__ import annotations

import argparse
from collections import defaultdict
import json
from pathlib import Path
import statistics
import sys

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "logger"))
from nag52logger.reader import iter_entries


def read_drive(path):
    shifts, observations = [], defaultdict(dict)
    epoch = 0
    previous_clock = None
    seen_shifts = set()
    for entry in iter_entries(str(path)):
        if entry.get("type") == "cycle":
            clock = entry.get("tcu_ms")
            # Split reboots and uint32 clock wraps. Never connect across either.
            if clock is not None:
                if previous_clock is not None and clock < previous_clock:
                    epoch += 1
                previous_clock = clock
            d = entry.get("downshift_observer", {})
            if "transitions" not in d or "_error" in d:
                continue
            transitions = d["transitions"]
            for i, event in enumerate(transitions):
                end = transitions[i + 1]["t_ms"] if i + 1 < len(transitions) else d["t_ms"]
                if end < event["t_ms"]:
                    continue
                key = event["seq"]
                old = observations[epoch].get(key)
                # Repeated polls extend the last known state, without bridging a
                # missing transition after ring overwrite.
                observations[epoch][key] = {
                    **event, "end_ms": max(end, old["end_ms"] if old else end)}
        elif entry.get("type") == "shift_trace":
            own = sorted((s for s in entry.get("samples", [])
                          if entry["seq_start"] <= s["seq"] <= entry["seq_end"]),
                         key=lambda s: s["seq"])
            if not own or own[-1]["t_ms"] < own[0]["t_ms"]:
                continue
            key = (epoch, entry.get("shift_id"), entry["seq_start"], entry["seq_end"])
            if key in seen_shifts:
                continue
            seen_shifts.add(key)
            shifts.append({"epoch": epoch, "from": str(entry["gear_from"]),
                           "to": str(entry["gear_to"]), "start_ms": own[0]["t_ms"],
                           "end_ms": own[-1]["t_ms"], "shift_id": entry.get("shift_id"),
                           "duration_ms": own[-1]["t_ms"] - own[0]["t_ms"],
                           "complete": (own[0]["seq"] == entry["seq_start"] and
                                        own[-1]["seq"] == entry["seq_end"] and
                                        len(own) == entry["seq_end"] - entry["seq_start"] + 1),
                           "slip_energy_j": entry.get("quality", {}).get("slip_energy_j"),
                           "kickdown": "kickdown" in entry.get("stamp", {}).get("flags", [])})
    return sorted(shifts, key=lambda s: (s["epoch"], s["start_ms"])), observations


def gap_causes(start, end, observations):
    """Intersect known state intervals with the gap; never extrapolate history."""
    totals = defaultdict(int)
    cursor = start
    for event in sorted(observations.values(), key=lambda e: e["t_ms"]):
        lo, hi = max(cursor, event["t_ms"]), min(end, event["end_ms"])
        if hi <= lo:
            continue
        if lo > cursor:
            totals["unknown"] += lo - cursor
        totals[event["state"]] += hi - lo
        cursor = hi
    if cursor < end:
        totals["unknown"] += end - cursor
    return dict(totals)


def make_report(path, max_gap_ms=3000):
    shifts, observations = read_drive(path)
    ladders, current = [], []

    def finish():
        if len(current) < 2:
            return
        gaps = []
        for left, right in zip(current, current[1:]):
            gaps.append({"duration_ms": right["start_ms"] - left["end_ms"],
                         "causes_ms": gap_causes(left["end_ms"], right["start_ms"],
                                                 observations[left["epoch"]])})
        ladders.append({"epoch": current[0]["epoch"], "rungs": list(current), "gaps": gaps})

    for shift in shifts:
        down = shift["complete"] and (shift["from"], shift["to"]) in {("5", "4"), ("4", "3"), ("3", "2"), ("2", "1")}
        connected = (current and down and current[-1]["epoch"] == shift["epoch"] and
                     current[-1]["to"] == shift["from"] and
                     0 <= shift["start_ms"] - current[-1]["end_ms"] < max_gap_ms)
        if not connected:
            finish()
            current = []
        if down:
            current.append(shift)
    finish()
    gaps = [g for ladder in ladders for g in ladder["gaps"]]
    totals = defaultdict(int)
    for gap in gaps:
        for cause, ms in gap["causes_ms"].items():
            totals[cause] += ms
    return {"path": str(path), "max_gap_ms": max_gap_ms, "ladders": ladders,
            "boundary_count": len(gaps),
            "median_gap_ms": statistics.median(g["duration_ms"] for g in gaps) if gaps else None,
            "total_gap_ms": sum(g["duration_ms"] for g in gaps), "causes_ms": dict(totals)}


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("logs", nargs="+")
    ap.add_argument("--max-gap", type=float, default=3.0, help="candidate boundary limit in seconds")
    ap.add_argument("--json", action="store_true")
    args = ap.parse_args()
    if args.max_gap <= 0:
        ap.error("--max-gap must be positive")
    reports = [make_report(path, args.max_gap * 1000) for path in args.logs]
    if args.json:
        print(json.dumps(reports, indent=2))
        return
    for report in reports:
        print(f"{report['path']}: {len(report['ladders'])} candidate ladders, "
              f"{report['boundary_count']} boundaries, median gap {report['median_gap_ms']} ms")
        for ladder in report["ladders"]:
            gears = [ladder["rungs"][0]["from"]] + [r["to"] for r in ladder["rungs"]]
            print(f"  boot {ladder['epoch']} at {ladder['rungs'][0]['start_ms']/1000:.2f}s: " + ">".join(gears))
            for i, rung in enumerate(ladder["rungs"]):
                print(f"    {rung['from']}>{rung['to']}: {rung['duration_ms']} ms, "
                      f"slip energy {rung['slip_energy_j']} J")
                if i < len(ladder["gaps"]):
                    gap = ladder["gaps"][i]
                    print(f"      gap {gap['duration_ms']} ms: {gap['causes_ms']}")
        total = report["total_gap_ms"]
        print(f"  Total gap: {total} ms; observed attribution (first reached blocker):")
        for cause, ms in sorted(report["causes_ms"].items()):
            print(f"    {cause}: {ms} ms ({100 * ms / total if total else 0:.1f}%)")
        print("  Short gaps alone do not establish removable delay. Timing is sampled at controller cadence.")


if __name__ == "__main__":
    main()
