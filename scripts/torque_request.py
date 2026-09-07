#!/usr/bin/env python3
"""
Does asking the engine for less torque during a shift actually do anything?

Reducing engine torque through the shift is the way to soften it without giving
up any clutch clamp - the clutch keeps its full safety margin and simply has
less to hold (US 7762925, US 8032288). It is also the ONLY lever left on the
2-3, 3-4 and 4-5 circuits, where the applying clutch cannot be fed above about
7100 mBar while the new gear wants far more (TRANSMISSION_NOTES section 2).

All of which assumes the lever works. This measures it from drive logs:

  authority   how deep a cut is actually asked for, and how much of it the
              engine delivers. A lever the ECM ignores is not a lever.
  lag         how long between asking and the torque moving. This decides
              whether the reduction can be aimed at a 100-200 ms inertia phase
              or only smeared across the whole shift.
  coverage    which shifts get a request at all.

Sampling: the polled log is ~19 Hz (52.5 ms). That is enough for depth and
coverage, marginal for lag, and NOT enough to place the reduction inside the
inertia phase - for that, capture the 50 Hz shift trace, which carries
trq_req_amount and engine_torque per sample. This script says so rather than
pretending otherwise.

EGS51 note: the bus carries only a magnitude. Control type and bounds are
dropped (can_egs51.cpp), so any shaping has to be produced by the TCU ramping
the number it sends.

Usage:
    scripts/torque_request.py logger/logs/<drive>.jsonl [more logs...]
"""
from __future__ import annotations

import argparse
import os
import statistics
import sys

sys.path.insert(0, os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "logger"))
from nag52logger.reader import LogFile  # noqa: E402

# A request is "present" when the TCU is asking for a specific torque. The CAN
# field reads INT16_MAX / 0x7FFF when there is nothing being asked for; a dropped
# read decodes as None and must not be confused with either.
NO_REQUEST = (None, 32767, 0x7FFF)


def window(log, t0, t1):
    return [c for c in log.cycles if t0 <= c["t"] <= t1]


def analyse(logs, paths):
    rows = []
    for log, path in zip(logs, paths):
        for sh in log.shifts():
            t0, t1 = sh["t_start"], sh.get("t_end")
            if t1 is None:
                continue
            during = window(log, t0, t1)
            before = window(log, t0 - 0.5, t0)
            after = window(log, t1, t1 + 0.5)
            if len(during) < 4 or len(before) < 3:
                continue

            def trq(c):
                return (c.get("can") or {}).get("static_torque")

            def req(c):
                v = (c.get("can") or {}).get("torque_req_amount")
                return None if v in NO_REQUEST else v

            base = [trq(c) for c in before if trq(c) is not None]
            if not base:
                continue
            base_trq = statistics.median(base)
            reqs = [(c["t"], req(c)) for c in during if req(c) is not None]
            trqs = [(c["t"], trq(c)) for c in during if trq(c) is not None]
            if not trqs:
                continue

            rec = {
                "log": os.path.basename(path), "t": t0,
                "shift": "%s-%s" % (sh["from"], sh["to"]),
                "dur_ms": (t1 - t0) * 1000.0,
                "base_trq": base_trq,
                "min_trq": min(v for _, v in trqs),
                "requested": bool(reqs),
            }
            if reqs:
                rec["req_min"] = min(v for _, v in reqs)
                rec["req_t0"] = reqs[0][0] - t0
                rec["req_span_ms"] = (reqs[-1][0] - reqs[0][0]) * 1000.0
                # Lag: from the first request sample to the first sample where the
                # engine has given up a meaningful part of it.
                target_drop = max(10.0, 0.3 * (base_trq - rec["req_min"]))
                lag = None
                for t, v in trqs:
                    if t >= reqs[0][0] and (base_trq - v) >= target_drop:
                        lag = (t - reqs[0][0]) * 1000.0
                        break
                rec["lag_ms"] = lag
                rec["asked_nm"] = base_trq - rec["req_min"]
                rec["got_nm"] = base_trq - rec["min_trq"]
            aft = [trq(c) for c in after if trq(c) is not None]
            rec["after_trq"] = statistics.median(aft) if aft else None
            rows.append(rec)

    if not rows:
        print("no shifts with usable torque data")
        return 1

    withreq = [r for r in rows if r["requested"]]
    print("%d shifts, %d with a torque request (%.0f %%)\n" % (
        len(rows), len(withreq), 100.0 * len(withreq) / len(rows)))

    by = {}
    for r in rows:
        by.setdefault(r["shift"], []).append(r)
    print("coverage by shift:")
    print("  %-8s %6s %8s %10s" % ("shift", "n", "with req", "median ask"))
    for k in sorted(by):
        v = by[k]
        w = [r for r in v if r["requested"]]
        ask = "%.0f Nm" % statistics.median([r["asked_nm"] for r in w]) if w else "-"
        print("  %-8s %6d %7d%% %10s" % (k, len(v), round(100 * len(w) / len(v)), ask))

    if not withreq:
        print("\nNo torque requests at all. Either they are disabled (SBS en_trq_req_*),")
        print("or the conditions to raise one never occurred.")
        return 0

    asked = [r["asked_nm"] for r in withreq]
    got = [r["got_nm"] for r in withreq]
    ratio = [g / a for a, g in zip(asked, got) if a > 5]
    lags = [r["lag_ms"] for r in withreq if r.get("lag_ms") is not None]

    print("\nauthority - does the engine do what it is told?")
    print("  asked for   median %5.0f Nm   (range %.0f to %.0f)" % (
        statistics.median(asked), min(asked), max(asked)))
    print("  gave up     median %5.0f Nm   (range %.0f to %.0f)" % (
        statistics.median(got), min(got), max(got)))
    if ratio:
        print("  delivered   median %5.0f %% of the reduction asked for" % (100 * statistics.median(ratio)))
    print("  deepest cut reached %.0f Nm from a base of %.0f" % (
        max(got), withreq[got.index(max(got))]["base_trq"]))

    floor = [r for r in withreq if r["min_trq"] <= 0]
    print("  %d of %d requests drove reported torque to zero or below" % (len(floor), len(withreq)))
    if floor:
        print("    (a reduction becoming a cut - the failure d4bb5fd fixed; if these are")
        print("     from a build after that fix, it is back)")

    print("\nlag - can it be aimed at the inertia phase?")
    if lags:
        print("  request to torque moving: median %.0f ms, range %.0f to %.0f (n=%d)" % (
            statistics.median(lags), min(lags), max(lags), len(lags)))
        print("  measured at ~52 ms sampling, so treat as 'about one to two samples'")
        print("  and confirm on the 50 Hz shift trace before designing a ramp to it")
    else:
        print("  no sample showed a clear torque response - either the engine ignored")
        print("  the request or the drop was too small to separate from noise")

    print("\ntiming within the shift, as far as 19 Hz can say:")
    print("  request starts   median %+.0f ms after the shift began" % (
        1000 * statistics.median([r["req_t0"] for r in withreq])))
    print("  request lasts    median %.0f ms of a %.0f ms shift" % (
        statistics.median([r["req_span_ms"] for r in withreq]),
        statistics.median([r["dur_ms"] for r in withreq])))
    return 0


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("logs", nargs="+")
    args = ap.parse_args()
    return analyse([LogFile.load(p) for p in args.logs], args.logs)


if __name__ == "__main__":
    sys.exit(main())
