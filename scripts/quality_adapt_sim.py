#!/usr/bin/env python3
"""
Replay the quality adaptation rule against logged drives before trusting it on
the car.

The rule itself (src/adaptation/quality_adapt.cpp) is a pure function of the
shift's quality vector, its context and the ADP settings. This script compiles
that exact file for the host, scores every logged shift with
scripts/shift_quality.py, feeds the shifts through the rule in drive order while
tracking the per-cell offsets, and prints:

  * how many shifts passed the gates and why the rest were skipped
  * the trajectory of every SPC and prefill cell across the drive(s)
  * whether any cell hit its clamp, and how fast

It answers "does this converge or oscillate, and how many shifts does it take"
without a road test. It cannot answer whether the car feels better: the logged
shifts do not react to the offsets, so the trajectory is the open-loop response
to the calibration as it was driven.

Caveats that matter for reading the output:
  * Logs before firmware 679fed1 carry no on-TCU quality vector, so quality is
    scored offline from the 19 Hz cycle records plus the 50 Hz trace jerk. The
    firmware's own vector will differ in detail (response is judged on a 20 ms
    grid there). Use it for shape, not for the exact count.
  * Logs before cab9e58 carry no agility score. Pedal percent at the shift is
    used as a stand-in, which is the score's position term and so under-reads
    stabs. Pass --agility-from pedal|zero|log to choose.
  * Flare is not in the log. It is inferred from the turbine overshooting the
    pre-shift speed by --flare-rpm during an upshift.

Usage:
  scripts/quality_adapt_sim.py logger/logs/<log>.jsonl [more logs...]
      [--set quality_jerk_target_mms3=20000 ...] [--agility-from pedal]
"""
from __future__ import annotations

import argparse
import collections
import os
import subprocess
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
sys.path.insert(0, os.path.join(ROOT, "logger"))
sys.path.insert(0, HERE)
from nag52logger.reader import LogFile  # noqa: E402
import shift_quality as sq  # noqa: E402

CHANGE = {(1, 2): 1, (2, 3): 2, (3, 4): 3, (4, 5): 4, (2, 1): 5, (3, 2): 6, (4, 3): 7, (5, 4): 8}
SPC_CELL = {1: 0, 5: 0, 2: 1, 6: 1, 3: 2, 4: 3, 8: 3, 7: 6}
CHANGE_NAME = {v: "%d-%d" % k for k, v in CHANGE.items()}
STUBS = os.path.join(ROOT, "tmp", "shift_replay", "stubs")


def build_host(out: str) -> str:
    """Compile the firmware's decision function plus the driver for this host."""
    src = [os.path.join(HERE, "quality_adapt_host.cpp"),
           os.path.join(ROOT, "src", "adaptation", "quality_adapt.cpp")]
    if os.path.exists(out) and all(os.path.getmtime(out) > os.path.getmtime(f) for f in src +
                                   [os.path.join(ROOT, "src", "nvs", "module_settings.h"),
                                    os.path.join(ROOT, "src", "shift_trace.h")]):
        return out
    cmd = ["g++", "-std=gnu++17", "-O1", "-w", "-include", os.path.join(STUBS, "preinclude.h"),
           "-I" + STUBS, "-I" + os.path.join(ROOT, "src"), "-I" + ROOT,
           "-I" + os.path.join(ROOT, "lib", "core"),
           "-I" + os.path.join(ROOT, "tmp", "shift_replay")] + src + ["-o", out]
    subprocess.run(cmd, check=True)
    return out


def flare_in(log: LogFile, t0: float, t1: float, up: bool, rpm: int) -> bool:
    """Turbine ran above where it started during an upshift: the releasing
    clutch let go before the applying one carried."""
    if not up:
        return False
    pre = [c["sensors"]["input_rpm"] for c in log.cycles
           if t0 - 0.3 <= c["t"] < t0 and isinstance(c.get("sensors", {}).get("input_rpm"), int)]
    if not pre:
        return False
    base = max(pre)
    during = [c["sensors"]["input_rpm"] for c in log.cycles
              if t0 <= c["t"] <= t1 and isinstance(c.get("sensors", {}).get("input_rpm"), int)]
    return bool(during) and max(during) > base + rpm


def agility_for(log: LogFile, t0: float, pedal: int, mode: str) -> int:
    if mode == "zero":
        return 0
    if mode == "log":
        best = None
        for c in log.cycles:
            d = c.get("driving_dynamics")
            if isinstance(d, dict) and "agility_score" in d and c["t"] <= t0:
                best = d["agility_score"]
        return int(best or 0)
    return int(pedal)  # pedal proxy: the score's position term


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("logs", nargs="+")
    ap.add_argument("--set", action="append", default=[], help="ADP override, name=value")
    ap.add_argument("--agility-from", choices=["pedal", "zero", "log"], default="pedal")
    ap.add_argument("--flare-rpm", type=int, default=100)
    ap.add_argument("--atf", type=int, default=80, help="ATF to assume when the log has none")
    ap.add_argument("--verbose", action="store_true")
    a = ap.parse_args()

    exe = build_host(os.path.join(ROOT, ".pio", "quality_adapt_host") if os.path.isdir(os.path.join(ROOT, ".pio"))
                     else os.path.join(HERE, ".quality_adapt_host"))
    proc = subprocess.Popen([exe] + a.set, stdin=subprocess.PIPE, stdout=subprocess.PIPE, text=True, bufsize=1)

    spc = collections.defaultdict(int)
    pre = collections.defaultdict(int)
    reasons = collections.Counter()
    traj = collections.defaultdict(list)   # cell -> [(shift index, value)]
    n = 0
    learned = 0
    clamp_hits = collections.Counter()
    for path in a.logs:
        log = LogFile.load(path)
        tj = sq.trace_jerk(log)
        tcu_off = 0.0
        for c in log.cycles:
            if isinstance(c.get("tcu_ms"), int):
                tcu_off = c["tcu_ms"] / 1000.0 - c["t"]
                break
        shifts = sq.shifts_from(log)
        print("%s: %d forward shifts" % (os.path.basename(path), len(shifts)))
        for (t0, t1, g0, g1) in shifts:
            q = sq.score(log, t0, t1, g0, g1, tj, tcu_off)
            change = CHANGE.get((g0, g1), 0)
            if q is None or change == 0:
                reasons["unscorable"] += 1
                continue
            n += 1
            cell = SPC_CELL[change]
            pcell = change - 1
            atf = a.atf
            for c in log.cycles:
                v = c.get("sensors", {}).get("atf_temp")
                if abs(c["t"] - t0) < 0.2 and isinstance(v, int) and v > 0:
                    atf = v
                    break
            out_rpm = 0
            for c in log.cycles:
                v = c.get("sensors", {}).get("output_rpm")
                if abs(c["t"] - t0) < 0.2 and isinstance(v, int):
                    out_rpm = v
                    break
            flared = flare_in(log, t0, t1, g1 > g0, a.flare_rpm)
            agility = agility_for(log, t0, q["pedal"], a.agility_from)
            resp = q["response_ms"] if q["response_ms"] and q["response_ms"] > 0 else 0
            line = "%d %d 0 0 %d %d %d 0 0 %d %d %d %d %d %d %d 1\n" % (
                change, agility, 1 if flared else 0, atf, out_rpm, spc[cell], pre[pcell],
                resp, q["duration_ms"], int(q["peak_jerk"] * 1000), q["torque_hole"], q["slip_energy_J"])
            proc.stdin.write(line)
            res = proc.stdout.readline().split(None, 4)
            dspc, dpre, reason, lrn, text = int(res[0]), int(res[1]), int(res[2]), int(res[3]), res[4].strip()
            reasons[text] += 1
            learned += lrn
            if text == "at clamp":
                clamp_hits[CHANGE_NAME[change]] += 1
            spc[cell] += dspc
            pre[pcell] += dpre
            traj["spc %s" % CHANGE_NAME[change]].append((n, spc[cell]))
            traj["pre %s" % CHANGE_NAME[change]].append((n, pre[pcell]))
            if a.verbose:
                print("  #%3d %s pedal %3d%% resp %4d dur %4d jerk %5.1f hole %4d slip %6d %s-> %-14s spc %+d pre %+d"
                      % (n, CHANGE_NAME[change], q["pedal"], resp, q["duration_ms"], q["peak_jerk"],
                         q["torque_hole"], q["slip_energy_J"], "FLARE " if flared else "", text, dspc, dpre))
    proc.stdin.close()

    print("\n%d shifts scored, %d passed the gates" % (n, learned))
    print("reasons:")
    for k, v in reasons.most_common():
        print("  %-24s %d" % (k, v))
    print("\nfinal offsets (mBar / cycles):")
    for change in sorted(CHANGE_NAME):
        nm = CHANGE_NAME[change]
        if ("spc %s" % nm) in traj:
            shared = "" if change in (1, 2, 3, 4, 7) else "  (spc cell shared with the upshift, fill time only)"
            print("  %-4s spc %+5d  prefill %+3d  (%d shifts)%s" % (nm, spc[SPC_CELL[change]], pre[change - 1], len(traj["spc %s" % nm]), shared))
    if clamp_hits:
        print("\nclamp reached on: " + ", ".join("%s x%d" % kv for kv in clamp_hits.items()))
    print("\ntrajectories (value after each shift of that type):")
    for k in sorted(traj):
        vals = [v for _, v in traj[k]]
        if any(vals):
            print("  %-10s " % k + " ".join("%+d" % v for v in vals))
    return 0


if __name__ == "__main__":
    sys.exit(main())
