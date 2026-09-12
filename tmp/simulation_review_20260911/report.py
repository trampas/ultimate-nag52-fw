"""Rebuild the review index and metrics from simulation CSVs and provenance."""
import csv, html, json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
OUT=ROOT/'sim/results/review_20260911'
rows=[]
for summary in sorted(OUT.glob('*/summary.json')):
    doc=json.loads(summary.read_text())
    for run in doc['runs']:
        p=run['parameters'];r=run['result']
        data=list(csv.DictReader((summary.parent/run['csv']).open()))
        last=float(data[-1]['t_s']);window=[x for x in data if float(x['t_s'])>=last-.1]
        held=last-float(data[0]['t_s'])>=.1 and all(abs(float(x['on_slip_rpm']))<40 for x in window)
        ended=r['controller_end_s']
        duration=ended-p['shift_at_s'] if ended>=0 else None
        result=dict(case=summary.parent.name,run=run['name'],dt_ms=p['dt_ms'],tick_ms=p.get('tick_ms',20),
            scope='EGS51 pressure sequence' if 'pressure_schedule_completed' in r else 'NAG52 shift executor',
            duration_s=duration,sequence_completed=r.get('pressure_schedule_completed',r['controller_completed']),
            sync_last_100ms=held,domain_exit=r['domain_exit'],timeout=r['controller_timed_out'],
            emergency_timer_expired=r.get('emergency_timer_expired',False),
            peak_jerk_20ms_m_s3=r['peak_abs_jerk_20ms_m_s3'],
            final_slip_rpm=float(data[-1]['on_slip_rpm']),max_engine_rpm=max(float(x['engine_rpm']) for x in data),
            rom_calls_checked=r.get('rom_calls_checked',0),source_sha256=doc['source_sha256'],
            chart=str(summary.parent.relative_to(OUT)/'comparison.html'),csv=str(summary.parent.relative_to(OUT)/run['csv']))
        rows.append(result)
(OUT/'review_metrics.json').write_text(json.dumps(rows,indent=2)+'\n')
intro='''<p>29 closed-loop runs plus 11 passing simulator tests. Plant: uncalibrated equivalent two-clutch-path model with engine, turbine and vehicle motion. EGS51 runs exercise the forced 4→3 pressure sequence, not the complete OEM scheduler. NAG52 runs exercise its shift executor, not a whole drive cycle.</p>
<p>Nominal NAG52 2→3 and tip-in 3→2 finish in 2.08 s and 1.30 s respectively. EGS51 4→3 finishes in 1.98 s with an assumed 20 ms tick, or 1.08 s with 10 ms. Both assumptions remain conditional pending the SIC810 counter divider.</p>
<p><strong>Failure cases:</strong> NAG52 at 35% clutch capacity reports executor completion but never synchronizes, then exceeds the model's 6,000 RPM domain. EGS51 at 10% capacity also exits that domain before completion. Both failures persist at 1, 0.5 and 0.25 ms plant steps. Smaller jerk in these cases is not improved shift quality.</p>
<p>EGS51 calibration, scenarios, torque control and completion boundaries differ from NAG52. These results do not rank the two controllers or predict road comfort. EGS51 stops at pressure-sequence completion; NAG52 continues with assumed post-shift holding pressure. Synchronization below is independently checked from the last 100 ms of CSV data (less than 40 RPM target-ratio slip).</p>'''
body=[]
for r in rows:
    bad=r['domain_exit'] or not r['sync_last_100ms'] or not r['sequence_completed']
    duration='unfinished' if r['duration_s'] is None else f"{r['duration_s']:.3f}"
    body.append(f'<tr class="{"bad" if bad else "ok"}"><td><a href="{html.escape(r["chart"])}">{html.escape(r["case"])}</a></td><td>{r["dt_ms"]}</td><td>{duration}</td><td>{r["sequence_completed"]}</td><td>{r["sync_last_100ms"]}</td><td>{r["domain_exit"]}</td><td>{r["peak_jerk_20ms_m_s3"]:.2f}</td><td><a href="{html.escape(r["csv"])}">CSV</a></td></tr>')
page='''<!doctype html><meta charset="utf-8"><title>Transmission simulation review — 2026-09-11</title><style>body{font:16px system-ui;max-width:1200px;margin:32px auto;padding:0 20px;color:#17202a}table{border-collapse:collapse;width:100%}td,th{padding:9px;text-align:left;border-bottom:1px solid #ccd}th{position:sticky;top:0;background:#eef}tr.bad{background:#fff0e8}a{color:#075db5}p{line-height:1.5}</style><h1>Transmission simulation review — 2026-09-11</h1>'''+intro+'''<p><a href="review_metrics.json">Derived metrics and source hashes</a>. Click a case for interactive speed, pressure, acceleration and jerk plots. Each case directory includes the full scenario and binary/calibration provenance in summary.json.</p><table><thead><tr><th>Case / plots</th><th>Plant step (ms)</th><th>Duration from request (s)</th><th>Sequence finished</th><th>Last 100 ms synced</th><th>Domain exit</th><th>Peak 20 ms jerk (m/s³)</th><th>Data</th></tr></thead><tbody>'''+''.join(body)+'</tbody></table>'
(OUT/'index.html').write_text(page)
print(len(rows),'runs;',sum(r['rom_calls_checked'] for r in rows),'ROM calls checked')
