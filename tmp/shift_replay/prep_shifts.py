#!/usr/bin/env python3
"""
Turn the nag52log .jsonl into per-shift replay inputs on a 20 ms grid.

For every forward gear change found in the ESP log lines ("Upshift/Downshift request ...")
we emit one text file:
    line 1: header  "change up from to t0_ms n_rows"
    lines: t_ms n2 n3 turbine_raw output_raw input_rpm engine_rpm output_rpm pedal pedal_smoothed atf
           input_trq conv_trq drv_trq min_trq max_trq
           | logged: active p_on p_off spc_req mpc_req corr_spc corr_mpc sub_shift sub_mod sync_rpm pid adder s_on s_off req_trq circuits
Inputs are linearly interpolated between the ~53 ms log samples (hold for integers/enums).
"""
import sys, os, json, bisect

sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..', '..', '..', '..', '..', 'home', 'tstern', 'projects', 'ultimate-nag52-fw', 'logger'))
sys.path.insert(0, '/home/tstern/projects/ultimate-nag52-fw/logger')
from nag52logger.reader import LogFile

CHANGE_IDX = {('D1', 'D2'): 1, ('D2', 'D3'): 2, ('D3', 'D4'): 3, ('D4', 'D5'): 4,
              ('D2', 'D1'): 5, ('D3', 'D2'): 6, ('D4', 'D3'): 7, ('D5', 'D4'): 8}
GEAR_NUM = {'D1': 1, 'D2': 2, 'D3': 3, 'D4': 4, 'D5': 5}
CIRC_BITS = {'1-2': 1, '2-3': 2, '3-4': 4, '4-5': 8}


def main(path, outdir, pre_ms=200, post_ms=3000):
    log = LogFile.load(path)
    os.makedirs(outdir, exist_ok=True)
    cyc = [c for c in log.cycles if all(k in c for k in ('sensors', 'can', 'pressures', 'shift_live', 'shift_algo', 'solenoids'))
           and c['sensors'].get('_raw') is None]
    # sample time for the cycle = tcu_ms at start + half the cycle duration (records are polled sequentially)
    ts = [c['tcu_ms'] + (c.get('dt', 0) * 1000.0) / 2.0 for c in cyc]

    # pedal_pos_smoothed as the firmware computes it (80 % of new value each 20 ms cycle) - run on the
    # log's own cadence, which is close enough for a signal that only feeds the release-shift multiplier
    smoothed = []
    s = 0
    for c in cyc:
        p = c['can']['pedal_pos']
        if p is None:
            p = 250 // 4
        s = (80 * p) // 100 + (20 * s) // 100
        smoothed.append(s)

    def field(i, rec, key, default=0):
        v = cyc[i][rec].get(key)
        return default if v is None else v

    def interp(t, rec, key, integer=True, default=0):
        j = bisect.bisect_right(ts, t)
        if j <= 0:
            return field(0, rec, key, default)
        if j >= len(ts):
            return field(len(ts) - 1, rec, key, default)
        t0, t1 = ts[j - 1], ts[j]
        v0, v1 = field(j - 1, rec, key, default), field(j, rec, key, default)
        if t1 == t0:
            return v0
        v = v0 + (v1 - v0) * (t - t0) / (t1 - t0)
        return int(round(v)) if integer else v

    def hold(t, rec, key, default=0):
        j = bisect.bisect_right(ts, t) - 1
        j = max(0, min(j, len(ts) - 1))
        return field(j, rec, key, default)

    def hold_idx(t):
        j = bisect.bisect_right(ts, t) - 1
        return max(0, min(j, len(ts) - 1))

    shifts = []
    for l in log.logs:
        m = l.get('msg') or ''
        if l.get('tag') == 'SHIFTER' and 'request to change between' in m:
            parts = m.split()
            frm, to = parts[-3], parts[-1].rstrip('!')
            if (frm, to) in CHANGE_IDX:
                shifts.append({'t0': l['tcu_ms'], 'from': frm, 'to': to, 'change': CHANGE_IDX[(frm, to)], 'up': GEAR_NUM[to] > GEAR_NUM[frm]})
    # shift end = "Shift complete" following the request
    completes = [l['tcu_ms'] for l in log.logs if l.get('tag') == 'SHIFTER' and (l.get('msg') or '').startswith('Shift complete')]
    fails = [l['tcu_ms'] for l in log.logs if l.get('tag') == 'SHIFT' and 'Shift failed' in (l.get('msg') or '')]
    index = []
    for n, sh in enumerate(shifts):
        t0 = sh['t0']
        t_end = min([t for t in completes if t > t0] or [t0 + 3000])
        failed = any(t0 < t < t_end for t in fails)
        sh['t_end'] = t_end
        sh['failed'] = failed
        rows = []
        t = t0 - pre_ms
        while t <= t_end + post_ms:
            i = hold_idx(t)
            circ = cyc[i]['pressures'].get('shift_circuits') or []
            cb = sum(CIRC_BITS[x] for x in circ)
            a = cyc[i]['shift_algo']
            p = cyc[i]['pressures']
            sl = cyc[i]['shift_live']
            row = [int(t - t0),
                   interp(t, 'sensors', 'n2_rpm'), interp(t, 'sensors', 'n3_rpm'), interp(t, 'sensors', 'input_rpm'), interp(t, 'sensors', 'output_rpm'),
                   interp(t, 'shift_live', 'input_rpm'), interp(t, 'shift_live', 'engine_rpm'), interp(t, 'shift_live', 'output_rpm'),
                   hold(t, 'can', 'pedal_pos', 62), smoothed[i], hold(t, 'sensors', 'atf_temp', 0),
                   interp(t, 'shift_live', 'input_torque'), interp(t, 'can', 'static_torque'), interp(t, 'shift_live', 'engine_torque'),
                   interp(t, 'can', 'min_torque'), interp(t, 'can', 'max_torque'),
                   # logged outputs (held)
                   a.get('active', 0), a.get('p_on', 0), a.get('p_off', 0), p.get('shift_req_pressure') or 0, p.get('modulating_req_pressure') or 0,
                   p.get('corrected_spc_pressure') or 0, p.get('corrected_mpc_pressure') or 0,
                   a.get('subphase_shift', 0), a.get('subphase_mod', 0), a.get('sync_rpm', 0), a.get('pid_torque', 0), a.get('adder_torque', 0),
                   a.get('s_on', 0), a.get('s_off', 0), sl.get('req_engine_torque') if sl.get('req_engine_torque') is not None else 32767, cb,
                   1 if (sl.get('actual_gear') != sl.get('target_gear')) else 0]
            rows.append(row)
            t += 20
        fn = os.path.join(outdir, 'shift_%02d_%s_%s.txt' % (n, sh['from'], sh['to']))
        with open(fn, 'w') as fh:
            fh.write('%d %d %d %d %d %d %d\n' % (sh['change'], 1 if sh['up'] else 0, GEAR_NUM[sh['from']], GEAR_NUM[sh['to']], t0, len(rows), pre_ms))
            for r in rows:
                fh.write(' '.join(str(int(x)) for x in r) + '\n')
        index.append({'n': n, 'file': fn, **sh})
    json.dump(index, open(os.path.join(outdir, 'index.json'), 'w'), indent=1)
    print('wrote', len(index), 'shifts to', outdir)


if __name__ == '__main__':
    main(sys.argv[1], sys.argv[2])
