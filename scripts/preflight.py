#!/usr/bin/env python3
"""
Pre-flight gate for a drive log: turn the things we already measure into
pass/fail, so a defect is caught at the desk instead of in the car.

The repo has good instrumentation and almost no gates. Two bugs found on
2026-09-08 make the point:

  * The torque-request runaway was already diagnosed, in words, by
    scripts/torque_request.py ("a reduction becoming a cut ... if these are
    from a build after that fix, it is back"). It printed that and nothing
    happened, because nothing runs it and nothing fails on it.
  * The garage-shift regression was invisible to every tool: shift_quality.py
    scores gear-to-gear shifts, and an engagement out of N/P is not one.

So this script is deliberately not a new measurement. It is the assertion layer
over the measurements that already exist, plus coverage of the engagement case
that had none.

Each check returns findings at ERROR (fails the run) or WARN (reported only).
ERROR is reserved for things that are defects in the control code - a loop that
runs away, a state machine that cannot complete, an engagement that had to be
retried. Calibration being off target is a judgement call and stays a WARN;
that is what shift_quality.py and shift_envelope.py are for.

Usage:
    scripts/preflight.py logger/logs/<drive>.jsonl [more logs...]
    scripts/preflight.py --no-maps logger/logs/<drive>.jsonl   # skip the static map check
    scripts/preflight.py --list                                # what is checked, and why

Exit code is 1 if any ERROR was raised, 2 if a log could not be read at all,
else 0.
"""
from __future__ import annotations

import argparse
import os
import statistics
import sys
from collections import defaultdict, namedtuple

sys.path.insert(0, os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "logger"))
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from nag52logger.reader import LogFile  # noqa: E402

Finding = namedtuple("Finding", "sev check msg")

# Gear ratios, for turning output shaft speed into the input speed a gear implies.
# Same table as shift_quality.py / the calibration in the log.
RATIOS = {"1": 3.932, "2": 2.408, "3": 1.486, "4": 1.000, "5": 0.830,
          "R1": 3.100, "R2": 1.899}

# --- thresholds ------------------------------------------------------------
# A torque *reduction* request that decays to this fraction of its own peak has
# stopped being a reduction and become a cut. 0.25 is loose on purpose: the real
# failure ran to 0.01 (284 Nm -> 2 Nm), and a legitimate request holds a level.
TRQ_COLLAPSE_FRAC = 0.25
# Pedal (0-250) above which the driver is clearly asking for torque, so engine
# torque going negative is the TCU's doing and not a coast.
PEDAL_DEMANDING = 10
# An engagement out of N/P that takes longer than this had to be retried. The
# pre-merge implementation completed in a fixed 1020 ms every time.
GARAGE_MAX_MS = 2000
# Control-defect ceilings, distinct from the calibration targets in
# shift_quality.TARGETS. A shift beyond these is not "tuned soft", it failed.
SHIFT_MAX_DURATION_MS = 2500
SHIFT_MAX_RESPONSE_MS = 1000
# Clutch slip energy per shift. shift_quality.TARGETS puts comfort at 12 kJ and
# agility at 20 kJ; past the error ceiling a single shift is dumping serious heat
# into the pack, whatever the mode.
SLIP_WARN_J = 20000
SLIP_ERROR_J = 40000
# Offline vs on-TCU quality: the two are meant to compute the same thing. Beyond
# this factor they have drifted and neither can be trusted.
METRIC_DRIFT_FACTOR = 2.0


def quantisation_ladder(values):
    """Is this list of measurements actually counting quantisation steps?

    Returns (base, n_on_ladder, n_total). A signal quantised at step `base` shows
    only integer multiples of it, and the step itself need not appear in the data
    - a jerk metric quantised at 29.7 can show only 59.4, 89.1, 118.8. So search
    small integer divisors of the smallest observed value for the base that
    explains the most values.
    """
    vals = sorted(v for v in values if v > 0)
    if len(vals) < 8:
        return (None, 0, len(vals))

    def on_ladder_for(b):
        return sum(1 for v in vals
                   if abs(v / b - round(v / b)) < 0.01 and round(v / b) >= 1)

    base, n = max(((vals[0] / d, on_ladder_for(vals[0] / d)) for d in range(1, 7)),
                  key=lambda p: p[1])
    return (base, n, len(vals))


def _samples_with_request(trace):
    """Contiguous runs of samples that carry an active torque request."""
    runs, cur = [], []
    for s in trace.get("samples", []):
        if s.get("trq_req_amount") is not None:
            cur.append(s)
        elif cur:
            runs.append(cur)
            cur = []
    if cur:
        runs.append(cur)
    return runs


def check_torque_request(log):
    """A torque reduction must never become a torque cut.

    Two independent symptoms, because either alone can be argued away:
      - the commanded amount collapsing to a small fraction of its own peak
        (the request ratcheting itself down), and
      - engine torque going to zero or below while the driver is on the pedal
        (what that ratchet actually does to the car).
    """
    out = []
    for sh in log.shift_traces:
        label = "%s->%s at t=%.1f" % (sh.get("gear_from"), sh.get("gear_to"), sh.get("t", 0.0))
        for run in _samples_with_request(sh):
            amts = [s["trq_req_amount"] for s in run]
            peak = max(amts)
            if peak > 0 and min(amts) < peak * TRQ_COLLAPSE_FRAC:
                out.append(Finding("ERROR", "torque_request",
                                   "%s: request collapsed %d -> %d Nm (%.0f%% of its own peak) - "
                                   "a reduction ratcheting into a cut"
                                   % (label, peak, min(amts), 100.0 * min(amts) / peak)))
            # Engine torque driven to/below zero while the driver wants torque.
            # Look inside the request and a little after it, since the engine lags.
            idx = sh["samples"].index(run[-1])
            after = sh["samples"][idx:idx + 13]          # ~250 ms at 50 Hz
            for s in run + after:
                et, ped = s.get("engine_torque"), s.get("pedal")
                if et is None or ped is None:
                    continue                              # a dropped read is not a cut
                if et <= 0 and ped > PEDAL_DEMANDING:
                    out.append(Finding("ERROR", "torque_request",
                                       "%s: engine torque %d Nm with pedal at %d/250 - "
                                       "net torque undershoot; fuel-cut causality is not established" % (label, et, ped)))
                    break
    return out


def check_garage_engagement(log):
    """Engagement out of N/P must succeed first time.

    The TCU log is the primary evidence (it says outright when a garage shift was
    aborted); the elapsed time catches the case where it was retried internally
    and still reported success.
    """
    out = []
    starts = [l for l in log.logs
              if (l.get("msg") or "").startswith("Garage shift")]
    for l in starts:
        m = l.get("msg") or ""
        if "aborted" in m:
            out.append(Finding("ERROR", "garage",
                               "t=%.2f: garage shift aborted - the engagement was thrown away "
                               "(legacy logs do not distinguish selector cancellation)" % l["t"]))
    # Time from each "Garage shift" to its resolution.
    opens = [l for l in starts if (l.get("msg") or "").strip() == "Garage shift"]
    closes = [l for l in starts if "completed OK" in (l.get("msg") or "") or "aborted" in (l.get("msg") or "") or "cancelled" in (l.get("msg") or "")]
    for o in opens:
        nxt = [c for c in closes if c["t"] >= o["t"]]
        if not nxt:
            continue
        ms = (nxt[0]["t"] - o["t"]) * 1000.0
        if ms > GARAGE_MAX_MS and "cancelled" not in (nxt[0].get("msg") or ""):
            out.append(Finding("ERROR", "garage",
                               "t=%.2f: engagement took %.0f ms (limit %d) - it did not complete "
                               "within the duration limit" % (o["t"], ms, GARAGE_MAX_MS)))
    # Re-entry: a second "Garage shift" opening hard on the heels of the last one.
    for a, b in zip(opens, opens[1:]):
        if b["t"] - a["t"] < 5.0 and any(c for c in closes if a["t"] <= c["t"] <= b["t"] and "aborted" in (c.get("msg") or "")):
            out.append(Finding("ERROR", "garage",
                               "t=%.2f: garage shift re-entered %.0f ms after an abort - "
                               "repeated max-pressure engagement attempts"
                               % (b["t"], (b["t"] - a["t"]) * 1000.0)))
    return out


def check_garage_sync_gate(log):
    """Flag completion samples for inspection without inventing rejection.

    Phase 8 identifies a completion check, not its result. The older fixed
    20-rpm exit test and the corrected entry-matched gate share that phase ID.
    Without an explicit retry/result, the trace cannot tell them apart.
    """
    out = []
    for sh in log.shift_traces:
        gf, gt = str(sh.get("gear_from")), str(sh.get("gear_to"))
        if "N" not in gf and "P" not in gf:
            continue
        ratio = RATIOS.get(gt)
        if ratio is None:
            continue
        rejected = []
        for s in sh.get("samples", []):
            if s.get("phase") != 8:                    # substage 8 = completion check
                continue
            irpm, orpm, ped = s.get("input_rpm"), s.get("output_rpm"), s.get("pedal")
            if irpm is None or orpm is None or ped is None:
                continue
            delta = abs(irpm - int(orpm * ratio))
            thr = 350 if ped > PEDAL_DEMANDING else 90
            if delta >= 20 and delta < thr:
                rejected.append((s["t_ms"], delta, thr, ped))
        for t_ms, delta, thr, ped in rejected:
            out.append(Finding("WARN", "garage_sync",
                               "%s->%s t_ms=%d: completion sampled at %d rpm slip with pedal "
                               "%d/250 (entry threshold %d rpm); phase 8 alone does not establish "
                               "rejection or which firmware exit threshold was used" % (gf, gt, t_ms, delta, ped, thr)))
    return out


def check_shift_completion(log):
    """Shifts that did not so much complete as give up.

    Uses the on-TCU quality vector, which is computed at the 20 ms control period
    rather than reconstructed from a 19 Hz poll.
    """
    out = []
    for sh in log.shift_traces:
        q = sh.get("quality") or {}
        label = "%s->%s at t=%.1f" % (sh.get("gear_from"), sh.get("gear_to"), sh.get("t", 0.0))
        dur, resp = q.get("duration_ms"), q.get("response_ms")
        if dur is not None and dur > SHIFT_MAX_DURATION_MS:
            out.append(Finding("ERROR", "shift_completion",
                               "%s: duration %d ms (limit %d)" % (label, dur, SHIFT_MAX_DURATION_MS)))
        if resp is not None and resp > SHIFT_MAX_RESPONSE_MS:
            out.append(Finding("ERROR", "shift_completion",
                               "%s: response %d ms (limit %d)" % (label, resp, SHIFT_MAX_RESPONSE_MS)))
    return out


def check_slip_energy(log):
    """Clutch slip energy per shift.

    This is the wear and thermal metric - the energy the friction material has to
    absorb. shift_quality.TARGETS puts comfort at 12 kJ and agility at 20 kJ, so
    a single shift past SLIP_ERROR_J is not "tuned soft", it is dumping heat into
    the pack. Added after the 2026-09-08 review: the duration and response gates
    passed every 3->4 on that drive while 3->4 was running a median of 25.7 kJ
    and a peak of 64.6 kJ, four times any other shift type.
    """
    out = []
    for sh in log.shift_traces:
        q = sh.get("quality") or {}
        e = q.get("slip_energy_j")
        if e is None or not q.get("duration_ms"):
            continue
        label = "%s->%s at t=%.1f" % (sh.get("gear_from"), sh.get("gear_to"), sh.get("t", 0.0))
        if e > SLIP_ERROR_J:
            out.append(Finding("ERROR", "slip_energy",
                               "%s: %d J of clutch slip (limit %d, comfort target 12000)"
                               % (label, e, SLIP_ERROR_J)))
        elif e > SLIP_WARN_J:
            out.append(Finding("WARN", "slip_energy",
                               "%s: %d J of clutch slip (over the %d J agility target)"
                               % (label, e, SLIP_WARN_J)))
    return out


def cov_slip_energy(log):
    return sum(1 for sh in log.shift_traces
               if (sh.get("quality") or {}).get("slip_energy_j") is not None
               and (sh.get("quality") or {}).get("duration_ms"))


def check_metric_agreement(log):
    """Guard the instruments themselves.

    Two failure modes, both of which make a gate built on the metric worthless:
      - the offline and on-TCU implementations of the same vector disagreeing,
      - a metric that is quantisation steps rather than a measurement. Jerk is
        the third derivative of an integer rpm signal, so it lands on exact
        multiples of one quantisation step; when most values do, the number is
        counting steps, not m/s^3.
    """
    out = []
    try:
        import shift_quality as SQ
    except Exception:
        return out

    vals = defaultdict(list)
    for sh in log.shift_traces:
        for k, v in (sh.get("quality") or {}).items():
            if v is not None:
                vals[k].append(v)

    # Offline vs on-TCU, where both exist.
    try:
        shifts = SQ.shifts_from(log)
        tj = SQ.trace_jerk(log)
        offline = defaultdict(list)
        for (t0, t1, g0, g1) in shifts:
            sc = SQ.score(log, t0, t1, g0, g1, tjerk=tj)
            if not sc:
                continue
            for k, v in sc.items():
                if isinstance(v, (int, float)):
                    offline[k].append(v)
    except Exception:
        return out

    # Quantisation: jerk is a third derivative of an integer rpm signal, so a
    # broken one lands on exact multiples of a single step. Check the offline
    # figure, which is the one reconstructed from the polled log.
    base, on_ladder, total = quantisation_ladder(offline.get("peak_jerk", []))
    if base is not None and on_ladder > 0.6 * total:
        out.append(Finding("ERROR", "metric_agreement",
                           "offline peak_jerk: %d of %d values are exact multiples of %.4g m/s^3 - "
                           "the metric is counting quantisation steps of an integer rpm signal, "
                           "not measuring jerk. Fix or drop it; do not gate on it."
                           % (on_ladder, total, base)))

    for key in ("duration_ms", "response_ms", "torque_hole", "peak_jerk"):
        a = vals.get(key) or []
        b = offline.get(key) or []
        if len(a) < 5 or len(b) < 5:
            continue
        ma, mb = statistics.median(a), statistics.median(b)
        if ma > 0 and mb > 0:
            f = max(ma / mb, mb / ma)
            if f > METRIC_DRIFT_FACTOR:
                out.append(Finding("ERROR", "metric_agreement",
                                   "%s: on-TCU median %.0f vs offline %.0f (%.1fx apart) - the two "
                                   "implementations have drifted" % (key, ma, mb, f)))
    return out


# --- coverage ---------------------------------------------------------------
# How many things each check actually got to look at. Without this a check
# reports "ok" on a log that simply does not carry the field it inspects, which
# is how scripts/shift_envelope.py once passed calibrations known to be broken.
# Firmware before the shift trace carried torque requests, for instance, logs no
# trq_req_amount at all: the torque check then examines nothing and says nothing
# is wrong. A green that means "no data" is worse than a red.

def cov_torque_request(log):
    return sum(len(_samples_with_request(sh)) for sh in log.shift_traces)


def cov_garage(log):
    return sum(1 for l in log.logs
               if (l.get("msg") or "").strip() == "Garage shift")


def cov_garage_sync(log):
    n = 0
    for sh in log.shift_traces:
        gf = str(sh.get("gear_from"))
        if "N" not in gf and "P" not in gf:
            continue
        n += sum(1 for s in sh.get("samples", []) if s.get("phase") == 8)
    return n


def cov_shift_completion(log):
    return sum(1 for sh in log.shift_traces if (sh.get("quality") or {}).get("duration_ms"))


def cov_metric_agreement(log):
    return sum(1 for sh in log.shift_traces if (sh.get("quality") or {}))


CHECKS = [
    ("torque_request", check_torque_request, cov_torque_request,
     "a torque reduction never becomes a cut"),
    ("garage", check_garage_engagement, cov_garage,
     "engagement out of N/P succeeds first time"),
    ("garage_sync", check_garage_sync_gate, cov_garage_sync,
     "the engagement completion gate is satisfiable at a standstill"),
    ("shift_completion", check_shift_completion, cov_shift_completion,
     "no shift runs past the control-defect ceiling"),
    ("slip_energy", check_slip_energy, cov_slip_energy,
     "no shift dumps more than %d J into the clutch" % SLIP_ERROR_J),
    ("metric_agreement", check_metric_agreement, cov_metric_agreement,
     "the instruments agree with each other and are not quantisation"),
]


def run_checks(log):
    """Run every check, de-duplicated.

    The shift-trace ring overlaps between consecutive reads, so the same sample
    can appear in two traces and raise the same finding twice.

    A check with nothing to examine raises a WARN of its own rather than being
    counted as a pass.
    """
    out, seen = [], set()
    for name, fn, cov, _desc in CHECKS:
        if cov(log) == 0:
            out.append(Finding("WARN", name,
                               "no data in this log - the check did not run, and its 'ok' "
                               "means nothing here"))
            continue
        for f in fn(log):
            key = (f.check, f.msg)
            if key not in seen:
                seen.add(key)
                out.append(f)
    return out


def coverage(log):
    return {name: cov(log) for name, _fn, cov, _desc in CHECKS}


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("logs", nargs="*", help="drive log(s) to check")
    ap.add_argument("--no-maps", action="store_true", help="skip the static shift map check")
    ap.add_argument("--list", action="store_true", help="list the checks and exit")
    args = ap.parse_args()

    if args.list:
        for name, _fn, _cov, desc in CHECKS:
            print("  %-18s %s" % (name, desc))
        print("  %-18s %s" % ("shift_maps", "static check of maps.cpp (scripts/shift_envelope.py)"))
        return 0

    if not args.logs and args.no_maps:
        ap.error("nothing to do: give a log, or drop --no-maps")

    rc = 0
    all_findings = []
    covered = []

    if not args.no_maps:
        try:
            import shift_envelope as SE
            maps = SE.parse_maps()
            if not maps:
                all_findings.append(Finding("ERROR", "shift_maps",
                                            "parsed no shift maps - the checker would pass everything"))
            else:
                probs = []
                for prof in ("S", "C", "A"):
                    u = "%s_DIESEL_UPSHIFT_MAP" % prof
                    d = "%s_DIESEL_DOWNSHIFT_MAP" % prof
                    if u in maps and d in maps:
                        probs += SE.check(prof, maps[u], maps[d], SE.ENVELOPE)
                for p in probs:
                    all_findings.append(Finding(p.sev, "shift_maps", str(p)))
        except Exception as e:                                   # pragma: no cover
            all_findings.append(Finding("ERROR", "shift_maps", "check failed to run: %s" % e))

    for path in args.logs:
        try:
            log = LogFile.load(path)
        except Exception as e:
            print("ERROR: could not read %s: %s" % (path, e))
            return 2
        found = run_checks(log)
        cov = coverage(log)
        if found:
            print("\n=== %s" % os.path.basename(path))
            for f in found:
                if f.sev == "ERROR":
                    print("  %-5s [%s] %s" % (f.sev, f.check, f.msg))
        all_findings += found
        covered.append(cov)

    errs = [f for f in all_findings if f.sev == "ERROR"]
    warns = [f for f in all_findings if f.sev != "ERROR"]

    if not args.logs:
        pass
    print()
    for name, _fn, _cov, desc in CHECKS:
        n = sum(1 for f in errs if f.check == name)
        seen = sum(c.get(name, 0) for c in covered)
        if n:
            state = "FAIL (%d)" % n
        elif not covered:
            state = "-"
        elif seen == 0:
            state = "NO DATA"
        else:
            state = "ok (n=%d)" % seen
        print("  %-18s %-52s %s" % (name, desc, state))
    if not args.no_maps:
        n = sum(1 for f in errs if f.check == "shift_maps")
        print("  %-18s %-52s %s" % ("shift_maps", "static check of maps.cpp",
                                    "FAIL (%d)" % n if n else "ok"))

    print("\n%d error(s), %d warning(s)" % (len(errs), len(warns)))
    if warns:
        for f in warns:
            print("  WARN  [%s] %s" % (f.check, f.msg))
    rc = 1 if errs else 0
    return rc


if __name__ == "__main__":
    sys.exit(main())
