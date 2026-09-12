"""Controlled host-adapter probes; native EGS51 routines remain unchanged.

Temporary source variants are retained with the results. The healthy-warmup
probe injects capacity loss at the shift request instead of before warmup.
Neither variant claims to implement a live hardware mapping or repair firmware.
"""
import ctypes as c
import csv
import json
from pathlib import Path
import subprocess
import sys
import types
ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'sim'))
import egs51
OUT=ROOT/'sim/results/failure_review_20260911';OUT.mkdir(parents=True,exist_ok=True)
native,plant=egs51.build(OUT)
bridge=OUT/'probe_bridge.cpp'
bridge.write_text('#include "'+str(ROOT/'sim/plant_bridge.cpp')+'"\nextern "C" void plant_set_capacity(void* p,double value) { static_cast<Nag52Plant::Model*>(p)->p.capacity_scale=value; }\n')
subprocess.run(['c++','-std=c++17','-O2','-shared','-fPIC',str(bridge),'-o',str(OUT/'probe_plant.so')],check=True)
probe=c.CDLL(str(OUT/'probe_plant.so'))
probe.plant_set_capacity.argtypes=[c.c_void_p,c.c_double];probe.plant_set_capacity.restype=None
source=(Path(__file__).with_name('original_egs51.py.txt')).read_text()
variants={'original':source,'zero_wheel_context':source.replace('(0x2ef,engine)','(0x2ef,0)')}
assert variants['zero_wheel_context']!=source
healthy=source.replace("p['mass_kg'],p['grade_percent'],p['capacity_scale'],","p['mass_kg'],p['grade_percent'],1.0,")
healthy=healthy.replace("        for step in range(round(p['seconds']/dt)):","        plant.plant_set_capacity(model,p['capacity_scale'])\n        for step in range(round(p['seconds']/dt)):")
assert healthy!=source
variants['fault_at_shift']=healthy
results=[]
for name,code in variants.items():
    (OUT/(name+'.py.txt')).write_text(code)
    module=types.ModuleType(name);module.__file__=str(ROOT/'sim/egs51.py');exec(compile(code,module.__file__,'exec'),module.__dict__)
    for scale in [1,.1]:
        stem=f'{name}_{scale:g}';path=OUT/(stem+'.csv')
        result=module.simulate({**egs51.DEFAULTS,'capacity_scale':scale},native,probe,path,True)
        rows=list(csv.DictReader(path.open()));transitions=[];last=None
        for r in rows:
            if r['phase']!=last:
                transitions.append({k:r[k] for k in ['t_s','phase','input_rpm','output_rpm','on_slip_rpm','on_capacity_nm','off_capacity_nm','emergency_timer']});last=r['phase']
        result.update(case=stem,first_sample=rows[0],last_sample=rows[-1],phase_transitions=transitions)
        results.append(result)
        print(stem,result['result']['pressure_schedule_completed'],result['result']['domain_exit'],result['result']['simulated_s'],flush=True)
for scale in [1,.1]:
    assert (OUT/f'original_{scale:g}.csv').read_bytes()==(OUT/f'zero_wheel_context_{scale:g}.csv').read_bytes(), 'Wheel context unexpectedly affects tested trajectories'
(OUT/'probes.json').write_text(json.dumps(results,indent=2)+'\n')
print('PASS: X2EF isolation leaves both trajectories byte-identical; all probes compare native calls with ROM')
# Isolate the *omitted* OEM recovery stage with explicit qualified input flags.
# This is not a full scheduler/plant validation: the upstream observer values
# below are deliberately supplied, not derived from the physical CSV.
from verify_model import base,state,word,check_memory
cpu=base(0);cpu.im[0xb6]=0;cpu.im[0xb9]=3;cpu.im[0x9a]=0
cpu.x[0x2ec]=255;cpu.x[0x210]=2;cpu.x[0x390]=0
word(cpu.x,0x2cf,10000);word(cpu.x,0x35c,10000)
s=state(cpu)
fn=native.egs51_ratio_recovery;fn.argtypes=[c.POINTER(egs51.State)]
timer=native.egs51_timers_tick;timer.argtypes=[c.POINTER(egs51.State)]
trace=[]
for tick in range(300):
    cpu.run(0xd8d2);fn(c.byref(s))
    check_memory(cpu,s,list(range(0x20,0x30))+list(range(0x80,0x9b))+list(range(0xa9,0xba)),range(1024))
    row=dict(tick=tick,recovery_state=s.x[0x390],timer=s.x[0x2a4],flags=s.x[0x1c2],fault_flags=s.im[0x28])
    if not trace or any(row[k]!=trace[-1][k] for k in ['recovery_state','flags','fault_flags']):trace.append(row)
    if s.im[0x28]&1:break
    cpu.run(0xe48d);timer(c.byref(s))
assert s.im[0x28]&1,trace
(OUT/'omitted_recovery_probe.json').write_text(json.dumps(trace,indent=2)+'\n')
print('PASS: original and native omitted ratio recovery assert fault:',trace,flush=True)
# Raw signed-comparison fragment, with live phase timer and no exceptional flag.
exit_rows=[]
for slip in [-3000,0,10000]:
    cpu=base(1);cpu.x[0x17b]=32;cpu.x[0x17c]=34;cpu.run(0x20bc)
    cal=int.from_bytes(cpu.x[0x3ca:0x3cc],'big')
    threshold=int.from_bytes(egs51.ROM[65536+cal+0x20:65536+cal+0x22],'big',signed=True)
    cpu.im[0xaa]=1;cpu.im[0xb5]=2;cpu.im[0x96]=0
    word(cpu.im,0xb7,100);word(cpu.x,0x357,slip&65535);cpu.run(0x53e2)
    assert (cpu.im[0xaa]==2)==(slip<threshold)
    exit_rows.append(dict(slip=slip,threshold=threshold,phase_after=cpu.im[0xaa],rom_took_exit=0x546f in cpu.visited))
(OUT/'rom_exit_gate.json').write_text(json.dumps(exit_rows,indent=2)+'\n')
import hashlib
manifest=dict(baseline_adapter_sha256=hashlib.sha256(source.encode()).hexdigest(),
              rom_sha256=hashlib.sha256(egs51.ROM).hexdigest(),
              native_sha256=hashlib.sha256((OUT/'egs51.so').read_bytes()).hexdigest(),
              probe_plant_sha256=hashlib.sha256((OUT/'probe_plant.so').read_bytes()).hexdigest())
(OUT/'manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
