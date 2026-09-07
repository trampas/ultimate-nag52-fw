#!/usr/bin/env python3
"""
Replay every logged shift through the OLD (HEAD) and NEW (working tree) shift algorithms.

1. For the OLD build, search the algorithm start offset (0..30 cycles after the "shift request" log
   line) that best reproduces the logged on-clutch pressure (p_on) trace. This validates that the
   harness + calibration reproduce what the TCU actually did.
2. Run the NEW build with the same offset and record how the commanded pressures / torque requests /
   phase timing differ.
Outputs: results/<shift>.old.txt, results/<shift>.new.txt, results/summary.json, and a text table.
"""
import json, os, subprocess, sys, math

HERE = os.path.dirname(os.path.abspath(__file__))
SHIFTS = os.path.join(HERE, 'shifts')
RES = os.path.join(HERE, 'results')
os.makedirs(RES, exist_ok=True)

COLS = None


def run(binary, shift_file, out_file, start_cycle, extra=()):
    subprocess.run([binary, shift_file, out_file, '--start-cycle', str(start_cycle), *extra], check=True,
                   stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    return parse(out_file)


def parse(path):
    global COLS
    head = {}
    rows = []
    phases = []
    end = {}
    logs = []
    for line in open(path):
        p = line.split()
        if not p:
            continue
        if p[0] == 'HEAD':
            for kv in p[1:]:
                k, v = kv.split('=', 1)
                head[k] = v
        elif p[0] == 'COLS':
            COLS = p[1:]
        elif p[0] == 'ROW':
            rows.append(dict(zip(COLS, [int(x) for x in p[1:]])))
        elif p[0] == 'PHASE':
            phases.append((int(p[1]), int(p[3])))
        elif p[0] == 'END':
            for kv in p[1:]:
                k, v = kv.split('=', 1)
                end[k] = int(v)
        elif p[0] == 'LOG':
            logs.append(line[4:].rstrip())
    return {'head': head, 'rows': rows, 'phases': phases, 'end': end, 'logs': logs}


def load_shift(shift_file):
    lines = open(shift_file).read().splitlines()
    hdr = [int(x) for x in lines[0].split()]
    names = ['t_ms', 'n2', 'n3', 'turbine', 'output', 'input_rpm', 'engine_rpm', 'output_rpm', 'pedal', 'pedal_smoothed', 'atf',
             'input_trq', 'conv_trq', 'drv_trq', 'min_trq', 'max_trq',
             'l_active', 'l_p_on', 'l_p_off', 'l_spc_req', 'l_mpc_req', 'l_corr_spc', 'l_corr_mpc', 'l_sub_shift', 'l_sub_mod', 'l_sync',
             'l_pid', 'l_adder', 'l_s_on', 'l_s_off', 'l_req_trq', 'l_circ', 'l_shifting']
    rows = [dict(zip(names, [int(x) for x in l.split()])) for l in lines[1:]]
    return {'change': hdr[0], 'up': hdr[1], 'from': hdr[2], 'to': hdr[3], 't0': hdr[4], 'n': hdr[5], 'pre_ms': hdr[6], 'rows': rows}


def logged_active_window(log):
    """(t_start, t_end) in ms of the logged shift: from first cycle with algo active to the last."""
    act = [r['t_ms'] for r in log['rows'] if r['l_active']]
    if not act:
        return None
    return act[0], act[-1]


def fit_error(sim, log):
    """Mean abs error of p_on (and mod pressure) against the logged trace over the logged active window."""
    by_t = {r['t_ms']: r for r in log['rows']}
    win = logged_active_window(log)
    if win is None:
        return 1e9, 0
    t0, t1 = win
    err = 0.0
    n = 0
    sim_by_t = {r['t_ms']: r for r in sim['rows']}
    for t in range(t0, t1 + 1, 20):
        lr = by_t.get(t)
        sr = sim_by_t.get(t)
        if lr is None:
            continue
        if sr is None:
            err += 3000  # sim already finished but log still active
            n += 1
            continue
        err += abs(sr['p_on'] - lr['l_p_on']) + 0.5 * abs(sr['p_off'] - lr['l_p_off'])
        n += 1
    # penalise sim running beyond the logged shift
    extra = sum(1 for r in sim['rows'] if r['t_ms'] > t1)
    err += extra * 1500
    n += extra
    return err / max(1, n), n


def phase_durations(sim):
    """Phase id -> duration in ms."""
    d = {}
    if not sim['rows']:
        return d
    for r in sim['rows']:
        d[r['phase']] = d.get(r['phase'], 0) + 20
    return d


def summarize(sim, log):
    rows = sim['rows']
    win = logged_active_window(log)
    out = {
        'algo': sim['head'].get('algo'),
        'result': sim['end'].get('result'),
        'duration_ms': sim['end'].get('duration_ms'),
        'timed_out': sim['end'].get('timed_out'),
        'phases': phase_durations(sim),
        'phase_times': sim['phases'],
        'max_p_on': max((r['p_on'] for r in rows), default=0),
        'min_p_off': min((r['p_off'] for r in rows), default=0),
        'trq_req_cycles': sum(1 for r in rows if r['req_ty'] != 0),
        'trq_req_min_amt': min((r['req_amt'] for r in rows if r['req_ty'] != 0), default=None),
        'max_abs_pid': max((abs(r['pid']) for r in rows), default=0),
        'flare_cycles': sum(1 for r in rows if r['flaring']),
        'circuit_on_ms': sum(20 for r in rows if r['circ']),
        'logged_window_ms': (win[1] - win[0] + 20) if win else None,
        'log_lines': [l for l in sim['logs'] if 'ADAPT' not in l or 'Start adaptation' in l],
        'target_shift_time': sim['head'].get('target_shift_time'),
        'fill_cycles': sim['head'].get('fill_cycles'),
        'flags': sim['head'].get('flags'),
    }
    return out


def diff_rows(old, new):
    """Per-cycle differences between old and new commanded pressures."""
    o = {r['t_ms']: r for r in old['rows']}
    n = {r['t_ms']: r for r in new['rows']}
    ts = sorted(set(o) | set(n))
    diffs = []
    for t in ts:
        a, b = o.get(t), n.get(t)
        if a and b:
            diffs.append({'t': t, 'd_p_on': b['p_on'] - a['p_on'], 'd_p_off': b['p_off'] - a['p_off'], 'd_spc': b['spc_req'] - a['spc_req'],
                          'd_mpc': b['mpc_req'] - a['mpc_req'], 'd_req': b['req_amt'] - a['req_amt'], 'old_phase': a['phase'], 'new_phase': b['phase'],
                          'old_sub': (a['sub_shift'], a['sub_mod']), 'new_sub': (b['sub_shift'], b['sub_mod'])})
        else:
            diffs.append({'t': t, 'only': 'old' if a else 'new'})
    return diffs


def main():
    index = json.load(open(os.path.join(SHIFTS, 'index.json')))
    sim_old = os.path.join(HERE, 'sim_old')
    sim_new = os.path.join(HERE, 'sim_new')
    extra = sys.argv[1:]
    summary = []
    for sh in index:
        f = sh['file']
        log = load_shift(f)
        base = os.path.splitext(os.path.basename(f))[0]
        # 1. fit the old build's start offset
        best = None
        for sc in range(0, 31):
            outp = os.path.join(RES, base + '.old.tmp')
            sim = run(sim_old, f, outp, sc, extra)
            e, n = fit_error(sim, log)
            if best is None or e < best[0]:
                best = (e, sc, sim)
        e_old, sc, old = best
        old = run(sim_old, f, os.path.join(RES, base + '.old.txt'), sc, extra)
        new = run(sim_new, f, os.path.join(RES, base + '.new.txt'), sc, extra)
        e_new, _ = fit_error(new, log)
        so, sn = summarize(old, log), summarize(new, log)
        d = diff_rows(old, new)
        first_diff = next((x['t'] for x in d if ('only' in x) or abs(x.get('d_p_on', 0)) > 25 or abs(x.get('d_p_off', 0)) > 25 or x.get('d_req', 0) != 0), None)
        rec = {'shift': base, 'n': sh['n'], 'from': sh['from'], 'to': sh['to'], 't0': sh['t0'], 'failed_on_tcu': sh['failed'],
               'logged_duration_ms': int(sh['t_end'] - sh['t0']), 'start_cycle': sc, 'fit_err_old': round(e_old, 1), 'fit_err_new': round(e_new, 1),
               'old': so, 'new': sn, 'first_diff_ms': first_diff,
               'max_d_p_on': max((abs(x.get('d_p_on', 0)) for x in d), default=0),
               'max_d_p_off': max((abs(x.get('d_p_off', 0)) for x in d), default=0)}
        summary.append(rec)
        print('%-22s start=%2d fit_old=%6.1f fit_new=%6.1f | old %-9s %5d ms res=%d | new %-9s %5d ms res=%d to=%d | logged %5d ms | dPon %4d dPoff %4d first_diff=%s' % (
            base, sc, e_old, e_new, so['algo'], so['duration_ms'], so['result'], sn['algo'], sn['duration_ms'], sn['result'], sn['timed_out'],
            rec['logged_duration_ms'], rec['max_d_p_on'], rec['max_d_p_off'], first_diff))
    json.dump(summary, open(os.path.join(RES, 'summary.json'), 'w'), indent=1)


if __name__ == '__main__':
    main()
