#!/usr/bin/env python3
"""
Can the TCU predict, before it upshifts, how the car will pull in the next gear?

This is the measurement behind the anti-hunt check in tmp/algorithms/recommendation.md.
The published method (GM US 6098004, Ford US 5669850) refuses an upshift when the
acceleration available in the next gear is below a required minimum, instead of
shifting on a speed threshold and discovering the answer afterwards. It only works
if the prediction is any good, so that is what this script measures: predict from
the state just before each upshift, then compare against what the car actually did
once the shift finished.

Nothing here runs on the TCU. It answers "is the mechanism real?" - the number that
CLAUDE.md says to produce before flashing, not after.

Method
------
Just before each upshift, take the road-load estimator's own state - effective mass
(mass conflated with the ECM torque scale, which is exactly the combination the
prediction needs) and grade - and predict:

    a_next = ( T_turbine_next / r_g_next  -  F_aero ) / M_eff  -  g * sin(grade)

with the torque in the next gear scaled from the torque now by a relative curve:

    T_turbine_next = T_now * curve(rpm_next) / curve(rpm_now)

A ratio, so the ECM's absolute torque error cancels - the same reason the estimator
survives a worn engine at all. Two candidate curves are compared, because neither is
obviously right:

  ecm       the ECM's own broadcast max_torque, binned by engine rpm. Free and
            self-updating, but its shape does not look like this engine (it rises
            to 3500 rpm, where an OM606 makes peak torque nearer 2000) and
            MAX_TRQ_FACTOR is known to be unapplied - see commit a49ab90.
  measured  from the drives' own acceleration at >75 % pedal, via the power curve
            in tmp/algorithms/findings-from-our-data.md. Torque = power / rpm.
  flat      control: assume torque does not change with rpm. If this scores as well
            as the others, the curve is not carrying any information and the check
            should not pretend to use one.

Actual acceleration is measured after the shift completes plus a settling delay,
over a window where the pedal is steady and no new shift starts.

Usage:
    scripts/next_gear.py logger/logs/<drive>.jsonl [more logs...]
    scripts/next_gear.py --verbose <log>        # per-shift table
"""
from __future__ import annotations

import argparse
import math
import os
import statistics
import sys

sys.path.insert(0, os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "logger"))
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

from nag52logger.reader import LogFile  # noqa: E402
import road_load as rl  # noqa: E402

G = 9.81
RHO = 1.2
CDA = 0.62

# Settling and measurement windows, seconds. The inertia phase is 100-200 ms and the
# driveline rings for a few hundred more, so measuring immediately after the shift
# ends measures the ring, not the pull.
SETTLE_S = 0.4
WINDOW_S = 0.8
# The pedal has to stay put across the window or we are measuring the driver.
# Raw pedal units, which are 0-250 on this bus, not a percentage.
PEDAL_TOL = 20.0
PEDAL_FULL = 250.0

# Relative torque curves, keyed by turbine/engine rpm. Values are arbitrary units -
# only ratios between two rpm are ever used.
#
# From tmp/algorithms/findings-from-our-data.md, which gives % of PEAK POWER at
# >75 % pedal. Torque = power / rpm, so divide before comparing.
_POWER_PCT = [(2125, 0.65), (2375, 0.76), (2750, 0.81), (3125, 0.85),
              (3500, 1.00), (4000, 0.915)]
CURVE_MEASURED = [(rpm, pct / rpm) for rpm, pct in _POWER_PCT]


def curve_lookup(curve, rpm):
    """Linear interpolation, held flat outside the measured range.

    Held flat rather than extrapolated on purpose: below 2000 rpm this car has no
    measurement at all (the power curve was fitted at >75 % pedal, which never
    happens down there), and a linear extrapolation of a turbo diesel through its
    boost threshold would invent a number rather than admit to not having one.
    """
    if not curve:
        return 1.0
    if rpm <= curve[0][0]:
        return curve[0][1]
    if rpm >= curve[-1][0]:
        return curve[-1][1]
    for (r0, v0), (r1, v1) in zip(curve, curve[1:]):
        if r0 <= rpm <= r1:
            return v0 + (v1 - v0) * (rpm - r0) / (r1 - r0)
    return curve[-1][1]


def ecm_curve(logs):
    """The ECM's broadcast full-load torque, binned by engine rpm, median per bin.

    Built from every log given, because a single drive does not cover the range.
    """
    bins = {}
    for log in logs:
        for c in log.cycles:
            can = c.get("can") or {}
            rpm, mx = can.get("engine_rpm"), can.get("max_torque")
            if rpm is None or mx is None or rpm < 600:
                continue
            bins.setdefault(int(rpm // 250) * 250 + 125, []).append(mx)
    return [(k, statistics.median(v)) for k, v in sorted(bins.items()) if len(v) > 5]


def rls_track(log, diff, circ):
    """Run the road-load estimator and keep its state against time.

    The same code path as scripts/road_load.py, but recording (t, M_eff, sin_grade)
    so a prediction can use the estimate as it stood at that moment rather than the
    converged end-of-drive value - which is what the TCU would have.
    """
    r_wheel = circ / (2.0 * math.pi)
    theta = [1.0 / 1700.0, 0.013]
    P = [[1e-8, 0.0], [0.0, 1e-3]]
    prev = None
    track = []
    for c in log.cycles:
        s = c.get("sensors") or {}
        can = c.get("can") or {}
        live = c.get("shift_live") or {}
        o, i = s.get("output_rpm"), s.get("input_rpm")
        trq, g, ped = live.get("input_torque"), str(live.get("actual_gear")), can.get("pedal_pos")
        if None in (o, i, trq, ped) or g not in rl.GEAR_IDX:
            prev = None
            continue
        v = o / 60.0 / diff * circ
        w = i * 2.0 * math.pi / 60.0
        if prev is None:
            prev = (c["t"], v, w, g)
            continue
        dt = c["t"] - prev[0]
        if not (0.03 < dt < 0.15) or g != prev[3]:
            prev = (c["t"], v, w, g)
            continue
        dyn = c.get("driving_dynamics") or {}
        braking = bool(dyn.get("brake_pressed")) if "brake_pressed" in dyn else (ped == 0)
        skip = (c.get("shift_algo") or {}).get("active") or braking or trq <= 0 or v < 4.0
        dv, dw = (v - prev[1]) / dt, (w - prev[2]) / dt
        prev = (c["t"], v, w, g)
        if skip:
            track.append((c["t"], 1.0 / theta[0], theta[1]))
            continue
        r_g = r_wheel / (rl.RATIOS[rl.GEAR_IDX[g]] * diff)
        phi1 = (trq - rl.J_TURBINE * dw) / r_g - 0.5 * RHO * CDA * v * v
        phi2 = -G
        Pphi = [P[0][0] * phi1 + P[0][1] * phi2, P[1][0] * phi1 + P[1][1] * phi2]
        den = 1.0 + phi1 * Pphi[0] + phi2 * Pphi[1]
        K = [Pphi[0] / den, Pphi[1] / den]
        err = dv - (phi1 * theta[0] + phi2 * theta[1])
        theta = [theta[0] + K[0] * err, theta[1] + K[1] * err]
        P = [[P[0][0] - K[0] * Pphi[0], P[0][1] - K[0] * Pphi[1]],
             [P[1][0] - K[1] * Pphi[0], P[1][1] - K[1] * Pphi[1]]]
        P[0][0] /= rl.LAMBDA_MASS
        P[1][1] /= rl.LAMBDA_GRADE
        theta[0] = min(max(theta[0], 1.0 / 4000.0), 1.0 / 700.0)
        track.append((c["t"], 1.0 / theta[0], theta[1]))
    return track


def state_at(track, t):
    """Estimator state as it stood at time t - never a later one."""
    best = None
    for row in track:
        if row[0] <= t:
            best = row
        else:
            break
    return best


def cycle_at(log, t):
    best = None
    for c in log.cycles:
        if c["t"] <= t:
            best = c
        else:
            break
    return best


def measure_actual(log, t_from, t_to, gear):
    """Mean acceleration over a window, or None if the window is not clean.

    Returns None rather than a number whenever the driver moved the pedal, another
    shift started, or a reading dropped out. A missing field decodes as None and
    must never become 0 - that is the trap that has already produced wrong answers
    in this repo (CLAUDE.md).
    """
    pts = []
    peds = []
    for c in log.cycles:
        if c["t"] < t_from:
            continue
        if c["t"] > t_to:
            break
        s = c.get("sensors") or {}
        can = c.get("can") or {}
        live = c.get("shift_live") or {}
        o, ped = s.get("output_rpm"), can.get("pedal_pos")
        if o is None or ped is None:
            return None
        if (c.get("shift_algo") or {}).get("active"):
            return None
        if str(live.get("actual_gear")) != gear:
            return None
        pts.append((c["t"], o))
        peds.append(ped)
    if len(pts) < 6 or not peds:
        return None
    if max(peds) - min(peds) > PEDAL_TOL:
        return None
    # Least squares slope of output rpm against time, so one noisy sample at an
    # endpoint cannot set the answer the way a first-to-last difference would.
    n = len(pts)
    mt = sum(p[0] for p in pts) / n
    mo = sum(p[1] for p in pts) / n
    num = sum((p[0] - mt) * (p[1] - mo) for p in pts)
    den = sum((p[0] - mt) ** 2 for p in pts)
    if den <= 0:
        return None
    return num / den  # rpm/s of output shaft


def analyse(logs, paths, verbose=False):
    log0 = logs[0]
    cfg = (log0.snapshot.get("records") or {}).get("tcm_config") or {}
    diff = cfg.get("diff_ratio", 3070) / 1000.0
    circ = cfg.get("wheel_circumference", 1975) / 1000.0
    r_wheel = circ / (2.0 * math.pi)
    print("final drive %.3f, wheel circumference %.3f m" % (diff, circ))

    curves = {
        "flat": [],
        "measured": CURVE_MEASURED,
        "ecm": ecm_curve(logs),
    }
    print("ECM broadcast torque curve, %d rpm bins: %s" % (
        len(curves["ecm"]),
        " ".join("%d:%.0f" % (r, v) for r, v in curves["ecm"][:8]) + (" ..." if len(curves["ecm"]) > 8 else "")))

    rows = []
    for log, path in zip(logs, paths):
        track = rls_track(log, diff, circ)
        if not track:
            print("%s: estimator never converged, skipped" % os.path.basename(path))
            continue
        for sh in log.shifts():
            g_from, g_to = str(sh["from"]), str(sh["to"])
            if g_from not in rl.GEAR_IDX or g_to not in rl.GEAR_IDX:
                continue
            if rl.GEAR_IDX[g_to] <= rl.GEAR_IDX[g_from]:
                continue  # upshifts only
            pre = cycle_at(log, sh["t_start"] - 0.1)
            st = state_at(track, sh["t_start"])
            if pre is None or st is None:
                continue
            s = pre.get("sensors") or {}
            can = pre.get("can") or {}
            live = pre.get("shift_live") or {}
            o, i = s.get("output_rpm"), s.get("input_rpm")
            trq, ped = live.get("input_torque"), can.get("pedal_pos")
            erpm = can.get("engine_rpm")
            if None in (o, i, trq, ped, erpm) or o <= 0 or trq <= 0:
                continue
            _, m_eff, sin_grade = st
            v = o / 60.0 / diff * circ
            if v < 4.0:
                continue
            ratio_to = rl.RATIOS[rl.GEAR_IDX[g_to]]
            rpm_next = i * ratio_to / rl.RATIOS[rl.GEAR_IDX[g_from]]
            r_g_next = r_wheel / (ratio_to * diff)
            f_aero = 0.5 * RHO * CDA * v * v

            preds = {}
            for name, curve in curves.items():
                if curve:
                    scale = curve_lookup(curve, rpm_next) / max(1e-9, curve_lookup(curve, i))
                else:
                    scale = 1.0
                t_next = trq * scale
                # m/s^2, then to output shaft rpm/s so it can be compared with a
                # measurement the TCU can actually make.
                a = (t_next / r_g_next - f_aero) / m_eff - G * sin_grade
                preds[name] = a * 60.0 * diff / circ

            t0 = sh["t_end"] + SETTLE_S
            act = measure_actual(log, t0, t0 + WINDOW_S, g_to)
            if act is None:
                continue
            rows.append({
                "log": os.path.basename(path), "t": sh["t_start"], "from": g_from, "to": g_to,
                "pedal": ped, "rpm": i, "rpm_next": rpm_next, "trq": trq,
                "m_eff": m_eff, "grade_deg": math.degrees(math.asin(max(-0.3, min(0.3, sin_grade)))),
                "actual": act, **{"pred_" + k: v for k, v in preds.items()},
            })

    if not rows:
        print("\nno upshift produced a clean measurement window - nothing to say")
        return 1

    print("\n%d upshifts with a clean window after the shift, from %d drives\n" % (len(rows), len(logs)))
    if verbose:
        print("%-8s %6s %4s %5s %5s %6s | %7s %7s %7s %7s" % (
            "shift", "t", "ped%", "rpm", "next", "grade", "actual", "flat", "measur", "ecm"))
        for r in rows:
            print("%-8s %6.0f %4.0f %5.0f %5.0f %+6.1f | %7.0f %7.0f %7.0f %7.0f" % (
                r["from"] + "-" + r["to"], r["t"], 100 * r["pedal"] / PEDAL_FULL,
                r["rpm"], r["rpm_next"], r["grade_deg"],
                r["actual"], r["pred_flat"], r["pred_measured"], r["pred_ecm"]))
        print()

    ac_all = sorted(r["actual"] for r in rows)
    print("Measured post-shift acceleration, output rpm/s: median %.0f, "
          "10th %.0f, 90th %.0f\n" % (
              statistics.median(ac_all), ac_all[len(ac_all) // 10], ac_all[-1 - len(ac_all) // 10]))

    print("Prediction of post-shift output acceleration, rpm/s:\n")
    print("%-9s %8s %8s %8s %8s   %s" % ("curve", "bias", "mae", "median", "sign ok", "correlation"))
    for name in ("flat", "measured", "ecm"):
        errs = [r["pred_" + name] - r["actual"] for r in rows]
        pr = [r["pred_" + name] for r in rows]
        ac = [r["actual"] for r in rows]
        n = len(rows)
        mp, ma = sum(pr) / n, sum(ac) / n
        num = sum((p - mp) * (a - ma) for p, a in zip(pr, ac))
        den = math.sqrt(sum((p - mp) ** 2 for p in pr) * sum((a - ma) ** 2 for a in ac))
        corr = num / den if den > 0 else float("nan")
        sign = sum(1 for p, a in zip(pr, ac) if (p >= 0) == (a >= 0)) / n
        print("%-9s %8.1f %8.1f %8.1f %7.0f%% %11.2f" % (
            name, statistics.mean(errs), statistics.mean(abs(e) for e in errs),
            statistics.median(errs), 100 * sign, corr))

    print("\nWhat the car actually did after upshifting:")
    neg = [r for r in rows if r["actual"] < 0]
    print("  %d of %d upshifts (%.0f %%) were followed by DECELERATION in the new gear"
          % (len(neg), len(rows), 100.0 * len(neg) / len(rows)))
    if neg:
        print("  by shift: %s" % ", ".join(
            "%s x%d" % (k, sum(1 for r in neg if r["from"] + "-" + r["to"] == k))
            for k in sorted(set(r["from"] + "-" + r["to"] for r in neg))))
        print("  pedal there: median %.0f %%, range %.0f-%.0f %%" % (
            100 * statistics.median([r["pedal"] for r in neg]) / PEDAL_FULL,
            100 * min(r["pedal"] for r in neg) / PEDAL_FULL,
            100 * max(r["pedal"] for r in neg) / PEDAL_FULL))
        print("  grade there: median %+.1f deg vs %+.1f deg on the rest" % (
            statistics.median([r["grade_deg"] for r in neg]),
            statistics.median([r["grade_deg"] for r in rows if r["actual"] >= 0])))
        uphill = sum(1 for r in neg if r["grade_deg"] > 2.0)
        print("  %d of the %d were on a grade above 2 deg - a tall gear on a hill is the"
              % (uphill, len(neg)))
        print("  textbook case the check exists for, not a false alarm")

    # ---------------------------------------------------------------------
    # The decision. Absolute prediction accuracy is not what matters: the check
    # only has to SEPARATE the upshifts that pulled from the ones that did not.
    # Sweep the threshold and report the trade, so the choice is made on the
    # numbers rather than on the correlation looking respectable.
    # ---------------------------------------------------------------------
    print("\nWould the check have caught them? Refuse the upshift when the predicted")
    print("acceleration is below a threshold. Caught = a decelerating upshift blocked;")
    print("cost = an upshift that pulled fine, blocked anyway.\n")
    # Landing rpm as a rival discriminator. It needs no estimator, no torque and no
    # mass - it is just rpm * ratio_next / ratio_now, known exactly before the shift.
    # If it separates as well as the model, the model is not earning its complexity.
    print("  landing rpm (refuse the upshift if the new gear lands below this):")
    print("    %10s %10s %10s %10s" % ("threshold", "caught", "cost", "precision"))
    for th in (1000, 1200, 1400, 1600, 1800, 2000, 2200, 2400):
        caught = sum(1 for r in neg if r["rpm_next"] < th)
        cost = sum(1 for r in rows if r["actual"] >= 0 and r["rpm_next"] < th)
        prec = caught / (caught + cost) if (caught + cost) else 0.0
        print("    %10d %6d/%-3d %10d %9.0f%%" % (th, caught, len(neg), cost, 100 * prec))
    print()

    best = None
    for name in ("flat", "measured", "ecm"):
        print("  %s:" % name)
        print("    %10s %10s %10s %10s" % ("threshold", "caught", "cost", "precision"))
        for th in (-40, -20, 0, 20, 40, 60, 80):
            caught = sum(1 for r in neg if r["pred_" + name] < th)
            cost = sum(1 for r in rows if r["actual"] >= 0 and r["pred_" + name] < th)
            prec = caught / (caught + cost) if (caught + cost) else 0.0
            print("    %10d %6d/%-3d %10d %9.0f%%" % (
                th, caught, len(neg), cost, 100 * prec))
            score = caught - 2 * cost   # blocking a good upshift is worse than missing a bad one
            if best is None or score > best[0]:
                best = (score, name, th, caught, cost)
        print()
    if best:
        _, name, th, caught, cost = best
        print("  Best trade (counting a wrongly blocked upshift as twice the cost of a")
        print("  missed one): %s curve, threshold %d rpm/s - catches %d of %d, costs %d." % (
            name, th, caught, len(neg), cost))
    return 0


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("logs", nargs="+", help="drive logs (jsonl)")
    ap.add_argument("--verbose", action="store_true", help="per-shift table")
    args = ap.parse_args()
    logs = [LogFile.load(p) for p in args.logs]
    return analyse(logs, args.logs, args.verbose)


if __name__ == "__main__":
    sys.exit(main())
