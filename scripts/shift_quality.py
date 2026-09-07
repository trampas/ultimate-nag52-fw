#!/usr/bin/env python3
"""
Score shift quality from a drive log, using the metrics the industry uses.

  jerk        Rate of change of fore-aft acceleration. SAE 650465 (the GMR
              Jerkmeter) established that this is what correlates with subjective
              shift feel, and it is still the primary measure. Computed from
              output shaft speed.
  duration    A shift can be made arbitrarily smooth by making it long, so jerk
              alone is not a score - a good shift is low jerk AND spontaneous.
              Reported alongside so the trade is visible.
  slip_energy Integral of clutch torque x slip speed over the shift, in joules.
              This is the wear and thermal load metric: it is the energy the
              friction material has to absorb and the oil has to carry away.
  lockup_rate How fast the applying clutch slip collapses at engagement. A large
              rate at lock-up excites the driveline afterwards and is felt as a
              thump even when the shift was otherwise smooth.

Clutch torque is not logged, so it is estimated from the input shaft dynamics:
T_clutch = I * dw/dt + T_input, with I = 0.16 kg m^2 fitted from 302 inertia
phase samples across four drives (R^2 0.84-0.96 per shift type on upshifts).
That makes slip_energy a good relative measure and a rough absolute one.

Usage:  scripts/shift_quality.py logger/logs/<log>.jsonl [--csv out.csv]
"""
from __future__ import annotations

import argparse
import bisect
import math
import os
import statistics
import sys

sys.path.insert(0, os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "logger"))
from nag52logger.reader import LogFile  # noqa: E402

RATIOS = {1: 3.932, 2: 2.408, 3: 1.486, 4: 1.000, 5: 0.830}
INPUT_INERTIA = 0.16          # kg m^2, fitted from logged inertia phases
RPM2RAD = 2 * math.pi / 60.0
DIFF, CIRC = 3.070, 1.975     # from the TCU config record


def shifts_from(log):
    out = []
    comp = [l["t"] for l in log.logs
            if l.get("tag") == "SHIFTER" and (l.get("msg") or "").startswith("Shift complete")]
    for l in log.logs:
        m = l.get("msg") or ""
        if l.get("tag") == "SHIFTER" and "request to change between" in m:
            p = m.split()
            a, b = p[-3], p[-1].rstrip("!")
            if a[0] == "D" and b[0] == "D":
                t1 = min([t for t in comp if t > l["t"]] or [l["t"] + 2.0])
                out.append((l["t"], t1, int(a[1]), int(b[1])))
    return out


def trace_jerk(log):
    """
    Peak jerk per shift from the TCU's own 50 Hz shift trace, keyed by TCU clock.

    Jerk is a second derivative, and a shift's inertia phase is 100-200 ms. At the
    ~19 Hz the polled records manage, that is not a measurement - it is aliasing.
    Compared over 51 shifts on one drive the polled figure is HALF the real one
    (median 19.8 against 39.3 m/s^3), so any jerk number taken from cycle records
    understates how harsh the shift actually was.
    """
    out = {}
    for tr in getattr(log, "shift_traces", []):
        ss = [x for x in tr["samples"] if x["output_rpm"] > 150]
        if len(ss) < 10:
            continue
        acc = []
        for a, b in zip(ss, ss[1:]):
            dt = (b["t_ms"] - a["t_ms"]) / 1000.0
            if not (0.015 < dt < 0.05):
                continue
            va = a["output_rpm"] / 60.0 / DIFF * CIRC
            vb = b["output_rpm"] / 60.0 / DIFF * CIRC
            acc.append(((a["t_ms"] + b["t_ms"]) / 2000.0, (vb - va) / dt))
        j = [abs(b[1] - a[1]) / (b[0] - a[0]) for a, b in zip(acc, acc[1:]) if b[0] > a[0]]
        if j:
            out[ss[0]["t_ms"] / 1000.0] = (ss[-1]["t_ms"] / 1000.0, max(j))
    return out


def score(log, t0, t1, g0, g1, tjerk=None, tcu_off=0.0):
    cyc = [c for c in log.cycles
           if t0 - 0.3 <= c["t"] <= t1 + 0.5
           and isinstance(c.get("sensors", {}).get("output_rpm"), int)]
    if len(cyc) < 6:
        return None
    out_rpm = [c["sensors"]["output_rpm"] for c in cyc]
    if max(out_rpm) < 200:
        return None                      # too slow for the ratio maths to mean anything

    # jerk from output shaft speed -> vehicle acceleration -> its derivative
    def v(o):
        return o / 60.0 / DIFF * CIRC
    acc = []
    for a, b in zip(cyc, cyc[1:]):
        dt = b["t"] - a["t"]
        if 0.02 < dt < 0.2:
            acc.append(((a["t"] + b["t"]) / 2, (v(b["sensors"]["output_rpm"]) - v(a["sensors"]["output_rpm"])) / dt))
    jerk = []
    for a, b in zip(acc, acc[1:]):
        dt = b[0] - a[0]
        if dt > 0:
            jerk.append(abs(b[1] - a[1]) / dt)
    peak_jerk = max(jerk) if jerk else 0.0
    # Prefer the 50 Hz trace where the drive has one.
    jerk_src = "19Hz"
    if tjerk:
        tcu_t = t0 + tcu_off
        for a, (b, jv) in tjerk.items():
            if a - 1.0 <= tcu_t <= b + 1.0:
                peak_jerk, jerk_src = jv, "50Hz"
                break

    # Slip energy on the applying clutch, and the lock-up rate.
    #
    # Only integrate while the clutch is actually transmitting. During bleed and
    # fill the slip speed is at its largest but the plates are not yet in contact,
    # so counting that phase inflates the energy several fold - it made a gentle
    # 3->4 read 30 kJ. The clutch starts to take up once its pressure exceeds the
    # return spring, which the calibration puts at 1139-1289 mBar for this box.
    SPRING_MBAR = 1300
    energy, prev = 0.0, None
    lock_rate = 0.0
    for c in cyc:
        a = c.get("shift_algo") or {}
        if not a.get("active"):
            continue
        if (c.get("pressures", {}).get("on_clutch_pressure") or 0) <= SPRING_MBAR:
            prev = None                  # not transmitting yet
            continue
        slip = abs(a.get("s_on") or 0)
        trq = abs(c.get("shift_live", {}).get("input_torque") or 0)
        if prev is not None:
            dt = c["t"] - prev[0]
            if 0.02 < dt < 0.2:
                dw = (c["sensors"]["input_rpm"] - prev[1]) * RPM2RAD / dt
                t_clutch = abs(INPUT_INERTIA * dw) + trq
                energy += t_clutch * slip * RPM2RAD * dt
                if prev[2] > 0 and slip < prev[2]:
                    lock_rate = max(lock_rate, (prev[2] - slip) / dt)
        prev = (c["t"], c["sensors"]["input_rpm"], slip)

    c0 = min(cyc, key=lambda c: abs(c["t"] - t0))
    return {
        "t": t0, "shift": "%d->%d" % (g0, g1), "up": g1 > g0,
        "pedal": round((c0["can"].get("pedal_pos") or 0) / 2.5),
        "torque": c0.get("shift_live", {}).get("input_torque") or 0,
        "kmh": round(c0["sensors"]["output_rpm"] / 60.0 / DIFF * CIRC * 3.6),
        "duration_ms": round((t1 - t0) * 1000),
        "peak_jerk": round(peak_jerk, 1),
        "slip_energy_J": round(energy),
        "lockup_rpm_s": round(lock_rate),
        "jerk_src": jerk_src,
    }


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("log")
    ap.add_argument("--csv")
    ap.add_argument("--sort", default="peak_jerk")
    args = ap.parse_args()

    log = LogFile.load(args.log)
    tj = trace_jerk(log)
    # trace timestamps are the TCU clock, cycle timestamps are the host clock
    off = 0.0
    if log.cycles and "tcu_ms" in log.cycles[0]:
        off = log.cycles[0]["tcu_ms"] / 1000.0 - log.cycles[0]["t"]
    rows = [r for r in (score(log, *s, tjerk=tj, tcu_off=off) for s in shifts_from(log)) if r]
    if not rows:
        print("no scoreable shifts")
        return 1
    rows.sort(key=lambda r: -r[args.sort])
    print("%7s %-5s %4s %5s %5s | %7s %8s %9s %10s" % (
        "t", "shift", "ped", "trq", "km/h", "dur_ms", "jerk", "slip_J", "lockup/s"))
    for r in rows:
        print("%7.1f %-5s %4d %5d %5d | %7d %8.1f %9d %10d" % (
            r["t"], r["shift"], r["pedal"], r["torque"], r["kmh"],
            r["duration_ms"], r["peak_jerk"], r["slip_energy_J"], r["lockup_rpm_s"]))

    def med(k, sel=None):
        v = [r[k] for r in rows if sel is None or sel(r)]
        return statistics.median(v) if v else 0
    print("\n%-22s %8s %9s %9s %10s" % ("", "dur_ms", "jerk", "slip_J", "lockup/s"))
    for lbl, sel in (("all", None), ("upshifts", lambda r: r["up"]),
                     ("downshifts", lambda r: not r["up"]),
                     ("light pedal <40%", lambda r: r["pedal"] < 40),
                     ("heavy pedal >70%", lambda r: r["pedal"] > 70)):
        n = len([r for r in rows if sel is None or sel(r)])
        if n:
            print("%-22s %8.0f %9.1f %9.0f %10.0f   (n=%d)" % (
                lbl, med("duration_ms", sel), med("peak_jerk", sel),
                med("slip_energy_J", sel), med("lockup_rpm_s", sel), n))
    n50 = len([r for r in rows if r["jerk_src"] == "50Hz"])
    print("\ntotal clutch slip energy this drive: %.1f kJ over %d shifts" % (
        sum(r["slip_energy_J"] for r in rows) / 1000.0, len(rows)))
    print("jerk from the 50 Hz trace for %d of %d shifts%s" % (
        n50, len(rows), "" if n50 == len(rows) else
        " - the rest are 19 Hz polled, which understates jerk about twofold"))
    if args.csv:
        import csv
        with open(args.csv, "w", newline="") as fh:
            w = csv.DictWriter(fh, fieldnames=list(rows[0].keys()))
            w.writeheader()
            w.writerows(rows)
        print("wrote %s" % args.csv)
    return 0


if __name__ == "__main__":
    sys.exit(main())
