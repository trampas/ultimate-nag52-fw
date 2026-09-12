#!/usr/bin/env python3
"""Run the real firmware shift algorithm against the first-order physical plant.

No Python packages are required. Writes full-rate CSVs, JSON provenance and an
interactive HTML comparison. Scenario numbers are assumptions, not fitted values.
"""
from __future__ import annotations
import argparse
import hashlib
import html
import json
import math
from pathlib import Path
import subprocess
import sys
import csv

ROOT = Path(__file__).resolve().parents[1]
BINARY = ROOT / "tmp/shift_replay/sim_new"


def inputs():
    paths = set()
    for folder in ("src", "lib/core", "sim", "tmp/shift_replay"):
        for p in (ROOT / folder).rglob("*"):
            if p.suffix in (".cpp", ".h", ".hpp", ".sh"):
                paths.add(p)
    return sorted(paths)


def parse_assignment(value):
    key, sep, text = value.partition("=")
    if not sep:
        raise ValueError("expected key=value")
    number = float(text)
    if not math.isfinite(number):
        raise ValueError("scenario values must be finite")
    return key, number


def build():
    result = subprocess.run(["bash", str(ROOT / "tmp/shift_replay/build.sh"), "new", str(ROOT)],
                            cwd=ROOT, text=True, capture_output=True)
    if result.returncode:
        raise RuntimeError(result.stdout + result.stderr)


def source_digest(paths):
    digest = hashlib.sha256()
    for p in paths:
        digest.update(str(p.relative_to(ROOT)).encode()+b"\0"+p.read_bytes())
    return digest.hexdigest()


def run(parameters, destination):
    cmd = [str(BINARY), "--plant", str(destination)]
    cmd += [f"{k}={v}" for k, v in sorted(parameters.items())]
    result = subprocess.run(cmd, cwd=ROOT, text=True, capture_output=True, timeout=90)
    if result.returncode:
        raise RuntimeError(result.stderr or result.stdout)
    return json.loads(result.stdout)


def report_html(runs, output, title="NAG52 closed-loop shift comparison", description=None):
    series = []
    keys = ["t_s", "accel_m_s2", "jerk_20ms_m_s3", "jerk_m_s3", "input_rpm",
            "on_pressure_mbar", "off_pressure_mbar", "on_slip_rpm"]
    rows = []
    for item in runs:
        with (output / item["csv"]).open() as f:
            values = [[float(row[k]) for k in keys] for row in csv.DictReader(f)]
        series.append({"name": item["name"], "values": values})
        r = item["result"]
        outcome = "completed + synchronized" if r["controller_completed"] and r["final_sync"] else "incomplete / unsynchronized"
        if "scope_outcome" in r: outcome = html.escape(r["scope_outcome"]) + ("; synchronized" if r["final_sync"] else "; unsynchronized")
        if r["controller_timed_out"]: outcome += "; controller timeout"
        if r["domain_exit"]: outcome += "; model domain exit"
        duration = r["controller_end_s"] - item["parameters"]["shift_at_s"] if r["controller_end_s"] >= 0 else None
        rows.append(f"<tr><td>{html.escape(item['name'])}</td><td>{duration:.3f}</td>" if duration is not None else
                    f"<tr><td>{html.escape(item['name'])}</td><td>—</td>")
        rows[-1] += f"<td>{r['peak_abs_jerk_20ms_m_s3']:.2f}</td><td>{r['peak_abs_jerk_m_s3']:.2f}</td><td>{outcome}</td></tr>"
    payload = json.dumps({"keys": keys, "series": series}, separators=(",", ":")).replace("<", "\\u003c")
    page = '''<!doctype html><meta charset="utf-8"><title>NAG52 physical shift simulation</title>
<style>body{font:16px system-ui;max-width:1100px;margin:32px auto;padding:0 20px;color:#162638;background:#f6f8fa}h1{font-size:26px}canvas{background:white;border:1px solid #ccd5de;width:100%;height:440px}table{border-collapse:collapse;width:100%;font-size:14px}td,th{text-align:left;padding:10px;border-bottom:1px solid #ccd5de}select{font:inherit;padding:6px}#legend{margin:14px 0}#readout{font:14px monospace;white-space:pre-wrap;min-height:65px}p{line-height:1.5}</style>
<h1>NAG52 closed-loop shift comparison</h1>
<p>Firmware tick: 20 ms. The physical model evolves between ticks. These are predictions from an uncalibrated equivalent driveline; compare identical conditions and inspect timestep and parameter sensitivity.</p>
<table><tr><th>Run</th><th>Controller duration (s)</th><th>Peak |jerk| over 20 ms (m/s³)</th><th>Peak raw |jerk| (m/s³)</th><th>Outcome</th></tr>ROWS</table>
<p><label>Plot <select id="metric"></select></label> · Move the pointer over the plot for values. Click a legend entry to toggle a run.</p>
<div id="legend"></div><canvas id="plot" width="1100" height="440"></canvas><div id="readout"></div>
<p>The raw jerk can spike at ideal stick/slip transitions. The 20 ms difference uses the same physical time interval at every integration step. A lower jerk alone is not a pass: inspect synchronization, duration, acceleration loss and timeout outcomes too. Full resolution data and resolved parameters are in the accompanying CSV and summary.json files.</p>
<script>const data=PAYLOAD;
const colors=['#0068b5','#e06b00','#17855d','#9a4cb4','#a13d4b','#657700','#267d91','#333333','#cc51a2'];
const labels=['Time (s)','Acceleration (m/s²)','Jerk over 20 ms (m/s³)','Raw jerk (m/s³)','Turbine speed (rpm)','Applying pressure (mbar)','Releasing pressure (mbar)','Target-ratio slip (rpm)'];
const canvas=document.getElementById('plot'),ctx=canvas.getContext('2d'),metric=document.getElementById('metric');let selected=1,hidden=new Set(),bounds;
for(let i=1;i<labels.length;i++){let o=document.createElement('option');o.value=i;o.textContent=labels[i];metric.append(o)}
data.series.forEach((s,i)=>{let b=document.createElement('button');b.textContent=s.name;b.style='margin:4px;padding:6px;color:'+colors[i%colors.length];b.onclick=()=>{if(hidden.has(i))hidden.delete(i);else hidden.add(i);b.style.opacity=hidden.has(i)?.4:1;draw()};document.getElementById('legend').append(b)});
function draw(cursor){ctx.clearRect(0,0,1100,440);let xmax=0,lo=Infinity,hi=-Infinity;data.series.forEach((s,i)=>{if(hidden.has(i))return;for(const p of s.values){xmax=Math.max(xmax,p[0]);lo=Math.min(lo,p[selected]);hi=Math.max(hi,p[selected])}});if(!Number.isFinite(lo))return;let pad=Math.max(.01,(hi-lo)*.08);lo-=pad;hi+=pad;bounds={xmax,lo,hi};const X=x=>70+x/Math.max(xmax,.001)*1000,Y=y=>390-(y-lo)/(hi-lo)*350;ctx.font='13px system-ui';ctx.strokeStyle='#e2e6eb';ctx.fillStyle='#243b53';for(let i=0;i<=5;i++){let y=lo+(hi-lo)*i/5,x=xmax*i/5;ctx.beginPath();ctx.moveTo(70,Y(y));ctx.lineTo(1070,Y(y));ctx.stroke();ctx.fillText(y.toFixed(2),5,Y(y)+4);ctx.fillText(x.toFixed(2),X(x)-10,417)}ctx.fillText(labels[selected],70,22);ctx.fillText('Time (s)',990,437);data.series.forEach((s,i)=>{if(hidden.has(i))return;ctx.strokeStyle=colors[i%colors.length];ctx.lineWidth=1.4;ctx.beginPath();s.values.forEach((p,j)=>{if(j)ctx.lineTo(X(p[0]),Y(p[selected]));else ctx.moveTo(X(p[0]),Y(p[selected]))});ctx.stroke()});if(cursor!==undefined){ctx.strokeStyle='#8995a2';ctx.beginPath();ctx.moveTo(X(cursor),40);ctx.lineTo(X(cursor),390);ctx.stroke()}}
metric.onchange=()=>{selected=+metric.value;draw()};canvas.onmousemove=e=>{if(!bounds)return;let t=Math.max(0,Math.min(bounds.xmax,((e.clientX-canvas.getBoundingClientRect().left)/canvas.clientWidth*1100-70)/1000*bounds.xmax));draw(t);let lines=['t = '+t.toFixed(3)+' s'];data.series.forEach((s,i)=>{if(hidden.has(i))return;let a=s.values,n=Math.min(a.length-1,Math.max(0,Math.round(t/a[a.length-1][0]*a.length)-1));if(a[n])lines.push(s.name+': '+a[n][selected].toFixed(4))});document.getElementById('readout').textContent=lines.join('\\n')};draw();</script>'''
    (output / "comparison.html").write_text(page.replace("<h1>NAG52 closed-loop shift comparison</h1>", "<h1>"+html.escape(title)+"</h1>").replace("NAG52 physical shift simulation", html.escape(title)).replace("Firmware tick: 20 ms. The physical model evolves between ticks. These are predictions from an uncalibrated equivalent driveline; compare identical conditions and inspect timestep and parameter sensitivity.", html.escape(description) if description else "Firmware tick: 20 ms. The physical model evolves between ticks. These are predictions from an uncalibrated equivalent driveline; compare identical conditions and inspect timestep and parameter sensitivity.").replace("ROWS", "".join(rows)).replace("PAYLOAD", payload))


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("scenario", type=Path)
    parser.add_argument("--set", action="append", default=[], metavar="KEY=VALUE")
    parser.add_argument("--compare", help="one parameter sweep, e.g. time_ms=500,700,1000")
    parser.add_argument("--convergence", action="store_true", help="also run half and quarter plant steps")
    parser.add_argument("--output", type=Path, default=ROOT / "sim/results/latest")
    parser.add_argument("--no-build", action="store_true", help="reuse binary only if newer than all source inputs")
    args = parser.parse_args()
    parameters = json.loads(args.scenario.read_text())
    if not isinstance(parameters, dict) or any(not isinstance(v,(int,float)) or isinstance(v,bool) or not math.isfinite(v) for v in parameters.values()):
        parser.error("scenario must be an object containing finite numeric values")
    parameters.update(dict(parse_assignment(v) for v in args.set))
    variants = [("base", parameters)]
    if args.compare:
        key, sep, values = args.compare.partition("=")
        if not sep: parser.error("--compare expects key=value,value")
        variants = []
        for value in values.split(","):
            _, number = parse_assignment(key+"="+value)
            variants.append((key+"="+value, {**parameters,key:number}))
    if args.convergence:
        variants = [(name+f",dt={p.get('dt_ms',1)/factor:g}ms",{**p,"dt_ms":p.get("dt_ms",1)/factor})
                    for name,p in variants for factor in (1,2,4)]
    sources = inputs()
    source_hash = source_digest(sources)
    if args.no_build:
        if not BINARY.exists() or any(p.stat().st_mtime_ns>BINARY.stat().st_mtime_ns for p in sources):
            parser.error("binary missing or stale; rerun without --no-build")
    else: build()
    if source_digest(inputs()) != source_hash:
        parser.error("source changed during the build; rerun to obtain a consistent comparison")
    output = args.output.resolve(); output.mkdir(parents=True,exist_ok=True)
    runs=[]
    for i,(name,p) in enumerate(variants):
        csv_name=f"run_{i:02d}.csv"
        data=run(p,output/csv_name)
        runs.append({"name":name,"csv":csv_name,**data})
        r=data["result"]
        print(f"{name}: completed={r['controller_completed']} synchronized={r['final_sync']} timeout={r['controller_timed_out']} "
              f"peak jerk(20ms)={r['peak_abs_jerk_20ms_m_s3']:.2f} m/s^3; "
              f"{r['simulated_s']:.2f}s simulated in {r['wall_s']:.3f}s")
    summary={"source_sha256":source_hash,"binary_sha256":hashlib.sha256(BINARY.read_bytes()).hexdigest(),
             "calibration_header_sha256":hashlib.sha256((ROOT/"tmp/shift_replay/cal_data.h").read_bytes()).hexdigest(),
             "controller_period_ms":20,"model_calibrated":False,"runs":runs}
    (output/"summary.json").write_text(json.dumps(summary,indent=2)+"\n")
    report_html(runs,output)
    print(output/"comparison.html")


if __name__ == "__main__":
    try: main()
    except (ValueError,RuntimeError,subprocess.TimeoutExpired) as exc:
        print(str(exc),file=sys.stderr);sys.exit(2)
