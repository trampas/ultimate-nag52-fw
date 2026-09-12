#!/usr/bin/env python3
"""Reconstruct shifts from sample gear identities, not potentially merged event headers.
Usage: python3 analyze.py LOG [LOG ...] --out DIRECTORY
No missing measurements are replaced with zero. No jerk/energy claims are made.
"""
import argparse, collections, csv, hashlib, json, pathlib, statistics, sys
ROOT = pathlib.Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'logger'))
from nag52logger.reader import LogFile


def analyze(path, out):
    log = LogFile.load(str(path))
    samples = {}
    memberships = collections.defaultdict(set)
    for n, tr in enumerate(log.shift_traces, 1):
        for s in tr['samples']:
            if s['seq'] in samples and samples[s['seq']] != s:
                raise ValueError(f'Conflicting sample {s["seq"]}')
            samples[s['seq']] = s
            if tr['seq_start'] <= s['seq'] < tr['seq_end']:
                memberships[s['seq']].add(n)
    ss = sorted(samples.values(), key=lambda s: s['seq'])
    segments, cur = [], []
    for s in ss:
        active = s['shifting'] and s['gear_actual'] != s['gear_target']
        if cur and (not active or s['seq'] != cur[-1]['seq']+1 or
                    (s['gear_actual'], s['gear_target']) != (cur[-1]['gear_actual'], cur[-1]['gear_target'])):
            segments.append(cur); cur = []
        if active: cur.append(s)
    if cur: segments.append(cur)
    cal = log.snapshot['calibration']['mech_cal']['ratio_table']
    ratios = {str(i):cal[i]/1000 for i in range(1,6)}
    rows = []
    for i, group in enumerate(segments, 1):
        a,b = group[0],group[-1]
        nxt = samples.get(b['seq']+1)
        end = nxt['t_ms'] if nxt else None
        gf,gt = a['gear_actual'],a['gear_target']
        forward = gf in ratios and gt in ratios
        times = collections.Counter()
        substates = collections.Counter()
        for s in group:
            ns = samples.get(s['seq']+1)
            if ns:
                dt=ns['t_ms']-s['t_ms']
                times[s['phase']] += dt
                substates[f"{s['phase']}.{s['subphase_shift']}.{s['subphase_mod']}"] += dt
        def cross(level):
            if not forward or a['output_rpm']<=150: return None
            for j in range(len(group)-2):
                chunk=group[j:j+3]
                if all(s['output_rpm']>150 and
                       (s['input_rpm']/s['output_rpm']-ratios[gf])/(ratios[gt]-ratios[gf])>=level for s in chunk):
                    return chunk[0]['t_ms']-a['t_ms']
            return None
        r10,r90=cross(.1),cross(.9)
        ids=sorted(set().union(*(memberships[s['seq']] for s in group)))
        req=[s['trq_req_amount'] for s in group if s['trq_req_amount'] is not None]
        errors=[s['input_rpm']-s['output_rpm']*ratios[gt] for s in group if forward and s['output_rpm']>150]
        row=dict(id=i, start_s=a['t_ms']/1000, end_s=end/1000 if end else None,
                 shift=f'{gf}->{gt}',duration_ms=end-a['t_ms'] if end else None,
                 response10_ms=r10,ratio90_ms=r90,
                 pedal_start_pct=a['pedal']/2.5,pedal_end_pct=b['pedal']/2.5,
                 input_start=a['input_rpm'],input_end=b['input_rpm'],
                 output_start=a['output_rpm'],output_end=b['output_rpm'],
                 engine_peak=max(s['engine_rpm'] for s in group),
                 request_min=min(req) if req else None,request_max=max(req) if req else None,
                 net_torque_min=min(s['engine_torque'] for s in group),
                 target_overshoot_rpm=round(max(0,max(errors))) if errors and int(gt)<int(gf) else None,
                 phases_ms=json.dumps(dict(sorted(times.items()))),
                 longest_substate=max(substates,key=substates.get),longest_substate_ms=max(substates.values()),
                 trace_events=','.join(map(str,ids)),
                 forward=forward)
        notes=[]
        if not forward:
            nearby=[c for c in log.cycles if a['t_ms']-100<=c['tcu_ms']<end+1000]
            pos=list(dict.fromkeys(c['can'].get('shifter_position') for c in nearby))
            notes.append('Selector '+ '/'.join(str(p) for p in pos))
            notes.append('Cancel on selector transit; record cancellation reason' if gt=='R1' else 'Completed; retain sequence pending separate OEM garage comparison')
        else:
            if row['duration_ms']>2500:notes.append('Long shift: correct '+('release control' if int(gt)<int(gf) else 'sync pressure recovery'))
            if row['longest_substate']=='3.2.0' and row['longest_substate_ms']>1000:notes.append('Long wait for sync; inspect pressure floor, PID and torque restoration')
            if int(gt)<int(gf) and times[1]>1500:notes.append('Fill/release dominates; coordinate MPC release and SPC rise as pedal increases')
            if r10 is None:notes.append('Low-speed ratio response unavailable; use output/clutch signals')
            elif r10>700:notes.append('Slow initial response; improve fill/release onset')
            if gf=='3' and gt=='4' and a['pedal']>0:notes.append('Review fill/overlap delay; do not tune from existing slip-energy estimate')
            if row['net_torque_min']<=0 and req and min(s['pedal'] for s in group)>10:notes.append('Torque undershoot with demand: check CAN torque units and engine lag')
            if int(gt)<int(gf) and row['target_overshoot_rpm'] is not None and row['target_overshoot_rpm']>150:notes.append('Turbine overshoot; taper release/sync torque with latency compensation')
            if int(gt)>int(gf) and b['pedal']>=175 and b['input_rpm']<2400:notes.append('Loaded landing below boost; coordinate up/down schedule and hysteresis')
            if not notes:notes.append('No specific control failure established; retain as comparison shift')
        row['review']='; '.join(notes)
        rows.append(row)
    for r, following in zip(rows, rows[1:]):
        if not r['forward'] or not following['forward']:
            continue
        gf, gt = r['shift'].split('->')
        nf, nt = following['shift'].split('->')
        gap = round((following['start_s']-r['end_s'])*1000)
        if 0 <= gap < 1000 and nf == gt:
            if nt == gf:
                r['review'] += f'; Reverses to {gf} after {gap} ms: check useful gear residence and changing demand'
            elif int(gt)<int(gf) and int(nt)<int(nf):
                r['review'] += f'; Next downshift follows after {gap} ms: judge total ladder response'
    forward=[r for r in rows if r['forward']]
    summary=log.summary()
    summary.update(sha256=hashlib.sha256(path.read_bytes()).hexdigest(), reconstructed_forward=len(forward),
                   reconstructed_garage=len(rows)-len(forward),trace_events=len(log.shift_traces),
                   accel_hz=log.accel_rate(),
                   trace_median_dt_ms=statistics.median(b['t_ms']-a['t_ms'] for a,b in zip(ss,ss[1:]) if b['seq']==a['seq']+1),
                   groups={})
    for shift in sorted(set(r['shift'] for r in forward)):
        rr=[r for r in forward if r['shift']==shift]
        responses=[r['response10_ms'] for r in rr if r['response10_ms'] is not None]
        summary['groups'][shift]=dict(n=len(rr),median_duration_ms=statistics.median(r['duration_ms'] for r in rr),
                                     max_duration_ms=max(r['duration_ms'] for r in rr),
                                     median_response_ms=statistics.median(responses) if responses else None)
    out.mkdir(parents=True,exist_ok=True)
    stem=path.stem
    with (out/(stem+'.csv')).open('w') as f:
        w=csv.DictWriter(f,fieldnames=rows[0]);w.writeheader();w.writerows(rows)
    (out/(stem+'.summary.json')).write_text(json.dumps(summary,indent=2)+'\n')
    with (out/(stem+'.ledger.md')).open('w') as f:
        f.write(f'# Shift ledger: {stem}\n\nSample timestamps are TCU seconds since boot. Response is first of three consecutive samples beyond 10% ratio progress, unavailable below 150 output rpm at start. Durations include bleed and handover. Phase numbers differ by algorithm; see report. Each row has its own sample gear identity; merged trace stamps are not attributed to the individual shifts. These are review observations, not validated tuning changes.\n\n')
        f.write('| # | Start s | Shift | Duration ms | Response ms | Pedal % start→end | Turbine rpm start→end | Review |\n|---|---:|---|---:|---:|---|---|---|\n')
        for r in rows:
            response='—' if r['response10_ms'] is None else str(r['response10_ms'])
            f.write(f"| {r['id']} | {r['start_s']:.3f} | {r['shift']} | {r['duration_ms']} | {response} | {r['pedal_start_pct']:g}→{r['pedal_end_pct']:g} | {r['input_start']}→{r['input_end']} | {r['review']} |\n")
    print(stem, 'forward',len(forward),'garage',len(rows)-len(forward),json.dumps(summary['groups']))

if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('logs',nargs='+',type=pathlib.Path);p.add_argument('--out',required=True,type=pathlib.Path)
    a=p.parse_args()
    for path in a.logs:analyze(path,a.out)
