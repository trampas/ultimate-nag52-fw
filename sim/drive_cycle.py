#!/usr/bin/env python3
"""Persistent Park-to-Park experiment using the full native EGS51 normal loop.
Physical input encodings, equivalent gear paths and engine model are assumptions.
"""
import argparse,csv,ctypes as c,hashlib,json,math,subprocess,tempfile,time
import html
from pathlib import Path
import egs51
from verify_model import base,state,word,check_memory
ROOT=Path(__file__).resolve().parents[1]

def build(folder):
    native,_=egs51.build(folder)
    subprocess.run(['c++','-std=c++17','-O2','-Wall','-Wextra','-Werror','-shared','-fPIC',str(ROOT/'sim/cycle_plant.cpp'),'-o',str(folder/'cycle.so')],check=True)
    plant=c.CDLL(str(folder/'cycle.so'))
    plant.cycle_create.restype=c.c_void_p
    plant.cycle_destroy.argtypes=[c.c_void_p]
    plant.cycle_read.argtypes=[c.c_void_p,c.POINTER(c.c_double)]
    plant.cycle_command.argtypes=[c.c_void_p,c.c_int,c.c_int,c.POINTER(c.c_double)]
    plant.cycle_step.argtypes=[c.c_void_p,c.c_double,c.c_double,c.c_double]
    return native,plant

def simulate(lib,plant,path,tick_ms=20,dt_ms=1,compare_rom=False,scenario=None):
    scenario=scenario or json.loads((ROOT/'sim/scenarios/park_to_park.json').read_text())
    stages=scenario['stages'];seconds=scenario['seconds']
    if not stages or stages[0]['at_s']!=0 or not 1<=seconds<=600:raise ValueError('cycle needs a stage at zero and duration 1..600 seconds')
    if [x['at_s'] for x in stages]!=sorted(set(x['at_s'] for x in stages)):raise ValueError('stage times must be strictly increasing')
    for x in stages:
        if x['selector'] not in (5,8) or not 0<=x['pedal']<=1 or not 0<=x['brake_n']<=20000 or not 0<=x['at_s']<seconds:raise ValueError('unsupported driver stage')
    if tick_ms not in (10,20) or dt_ms not in (1,.5,.25):raise ValueError('supported ticks 10/20, plant steps 1/.5/.25 ms')
    cpu=base(0);s=state(cpu)
    def put(space,a,v):
        getattr(s,space)[a]=v
        if compare_rom:getattr(cpu,space)[a]=v
    def putw(space,a,v):
        v=max(0,min(65535,round(v)));word(getattr(s,space),a,v)
        if compare_rom:word(getattr(cpu,space),a,v)
    calls=0;call_counts={}
    entries={'controller_init':(0,0x6ec2),'pressure_init':(1,0x10ba),'platform_timers':(0,0x6cf8),'scheduler_tick':(0,0x6e6a)}
    def call(name):
        nonlocal calls
        fn=getattr(lib,'egs51_'+name);fn.argtypes=[c.POINTER(egs51.State)];fn.restype=c.c_uint8 if name.endswith('_init') else None
        result=fn(c.byref(s))
        if compare_rom:
            bank,entry=entries[name];cpu.put(0x88,(cpu.direct(0x88)&~16)|(bank<<4))
            cpu.run(entry,stop=0x6ec1 if name=='scheduler_tick' else None,stop_bank=0)
            check_memory(cpu,s,[*range(0x20,0x30),0x35,0x37,*range(0x44,0x58),*range(0x80,0x9b),*range(0xa9,0xba)],range(1024))
            if name.endswith('_init'):assert result==cpu.r(7)
        if name.endswith('_init') and result:raise ValueError(f'{name}: invalid calibration {result}')
        calls+=1;call_counts[name]=call_counts.get(name,0)+1
    def w(a):return (s.x[a]<<8)|s.x[a+1]
    def rw(a):return int.from_bytes(egs51.ROM[65536+a:65536+a+2],'big')
    for a,v in [(0x175,egs51.ROM[0xfbfb]),(0x176,egs51.ROM[0xfbfc]),(0x183,1),(0x184,3),(0x185,10),(0x17b,32),(0x17c,34),(0x75,8),(0x76,110)]:put('x',a,v)
    putw('x',0x181,1975);putw('x',0x17f,3070);putw('im',0x87,750)
    call('controller_init');call('pressure_init')
    ratios=[1]+[rw(0x1040+2*g)/1000 for g in range(1,6)]
    model=plant.cycle_create();values=(c.c_double*17)();args=(c.c_double*10)()
    plant.cycle_read(model,values)
    rows=[];events=[];last_event=None;active_old=0;active_target=0
    dt=dt_ms/1000;stride=round(tick_ms/dt_ms);limit=1e9;pedal=0;start=time.perf_counter()
    try:
        for step in range(round(seconds/dt)):
            t=step*dt
            stage=next(x for x in reversed(stages) if t>=x['at_s'])
            segment=stage['name'];selector=stage['selector'];brake=stage['brake_n'];pedal=stage['pedal']
            if 'target_speed_kph' in stage:pedal=max(0,min(.4,(stage['target_speed_kph']-values[3]*3.6)*.035+.09))
            # A driver must stop before selecting Park. This does not alter shaft speeds.
            if selector==8 and abs(values[3])>=.05:selector=5
            if step%stride==0:
                engine,turbine,output=values[:3];mode=s.im[0xb6];gear=s.im[0xb9];idx=s.im[0xac]
                put('x',0x75,selector);put('im',0x86,round(pedal*250));put('im',0x80,120)
                put('im',0x20,(s.im[0x20]&~0x10)|(0x10 if brake else 0))
                putw('im',0x87,engine)
                # Synthetic N2/N3 endpoints; interpolation during 1<->2 uses the known ratio relation.
                if mode in (1,2,3,4) and idx in (1,5):
                    n2=output*ratios[2];n3=(output*ratios[1]-turbine)/(ratios[1]/ratios[2]-1)
                elif gear==1 or gear==0:n2=turbine*2408/3932;n3=0
                else:n2=n3=turbine
                putw('im',0x81,n2);putw('im',0x83,n3)
                # BFD5: equal wheel words -> combined=25*word; X375=combined*X203/2500.
                wheel=output*100/3070
                for a in (0x81,0x84,0x87,0x89):putw('x',a,wheel)
                drag=30;gross=max(0,min(250,round(values[6]/3)+drag))
                for a,v in [(0x86,drag),(0x9b,gross),(0x9e,gross),(0x9f,200),(0x8b,200),(0x9d,0),(0x7c,255)]:put('x',a,v)
                call('platform_timers');call('scheduler_tick')
                mode=s.im[0xb6];gear=s.im[0xb9];phase=s.im[0xaa]
                if mode in (1,2,3,4):
                    active_target=gear;active_old=gear-1 if mode in (1,2) else gear+1
                elif mode==6:active_old=0;active_target=gear
                elif mode==0 and 1<=gear<=5:active_old=gear;active_target=0
                else:active_old=active_target=0
                if selector>=6:active_old=active_target=0
                if any(g<0 or g>5 for g in [active_old,active_target]):raise RuntimeError('invalid physical gear routing')
                mpc=w(0x361);on=w(0x363);spring_on=w(0x367);spring_off=w(0x369)
                gain_on=egs51.ROM[65536+0xffd0]/w(0x36f) if w(0x36f) else .08
                gain_off=egs51.ROM[65536+0xffd0]/w(0x371) if w(0x371) else .08
                cmd_off=cmd_on=0
                h=w(0x3ce)
                first=(gear in (1,6)) if not mode else s.im[0xac] in (1,5)
                line_pressure=(mpc+rw(h+5))*1000/rw(h+(1 if first else 3))
                if active_target:
                    cmd_on=on
                    if active_old:
                        h=w(0x3ce);j=s.im[0xac]-1;spring=rw(h+0x27+2*j);spring=spring if spring<32768 else spring-65536
                        offmulti=rw(h+0x17+2*j)
                        cmd_off=max(0,(mpc-spring-on*rw(h+7+2*j)/1000)*1000/offmulti) if offmulti else 0
                    if mode in (1,2,3,4) and not s.im[0x95]&7:
                        cmd_off=0;cmd_on=line_pressure
                elif active_old:
                    spring_off=spring_on;gain_off=gain_on;cmd_off=line_pressure
                args[:]=[ratios[active_old],ratios[active_target],cmd_off,cmd_on,spring_off,gain_off,spring_on,gain_on,brake,selector==8]
                plant.cycle_command(model,active_old,active_target,args)
                limit=3*s.x[0x7e]-3*s.x[0x86] if s.x[0x90]&1 and s.x[0x7e]<254 else 1e9
                event=(segment,mode,phase,gear,s.im[0xab],s.x[0x390])
                if event!=last_event:
                    events.append(dict(t_s=t,segment=segment,mode=mode,phase=phase,gear=gear,demand=s.im[0xab],recovery=s.x[0x390]))
                    last_event=event
            plant.cycle_step(model,dt,pedal,limit);plant.cycle_read(model,values)
            if not all(math.isfinite(v) for v in values) or min(values[:3])<-.1 or max(values[:2])>6000:raise RuntimeError(f'plant domain exit at {t}: {list(values[:3])}')
            if step%stride==0:
                rows.append(dict(t_s=t+dt,segment=segment,selector=selector,gear=gear,mode=mode,phase=phase,demand=s.im[0xab],
                    engine_rpm=values[0],input_rpm=values[1],output_rpm=values[2],speed_kph=values[3]*3.6,accel_m_s2=values[4],
                    engine_torque_nm=values[6],converter_torque_nm=values[7],off_pressure_mbar=values[8],on_pressure_mbar=values[9],
                    off_fill=values[14],on_fill=values[15],mpc_raw=mpc,clutch_raw=on,torque_limit_nm=limit if limit<1e9 else -1,torque_request_active=int(limit<1e9),
                    ratio_recovery=s.x[0x390],fault_flags=s.im[0x28],pedal=pedal,brake_n=brake,
                    on_slip_rpm=values[1]-ratios[active_target or active_old]*values[2],
                    commanded_old_gear=active_old,commanded_new_gear=active_target,
                    tcc_demand_raw=s.im[0x36],pressure_timer=(s.im[0xb7]<<8)|s.im[0xb8]))
    finally:plant.cycle_destroy(model)
    with path.open('w') as f:
        writer=csv.DictWriter(f,fieldnames=rows[0]);writer.writeheader();writer.writerows(rows)
    result=dict(initializations=call_counts['controller_init'],pressure_initializations=call_counts['pressure_init'],scheduler_ticks=call_counts['scheduler_tick'],rom_stage_calls_checked=calls if compare_rom else 0,
        gears=sorted({r['gear'] for r in rows}),modes=sorted({r['mode'] for r in rows}),
        max_speed_kph=max(r['speed_kph'] for r in rows),final_speed_kph=rows[-1]['speed_kph'],final_selector=rows[-1]['selector'],
        final_mode=rows[-1]['mode'],max_engine_rpm=max(r['engine_rpm'] for r in rows),events=events,wall_s=time.perf_counter()-start)
    acceleration=next((r for r in rows if r['segment']=='accelerate'),None)
    result['primed_at_acceleration']=bool(acceleration and acceleration['mode']==0 and acceleration['gear'] in range(1,6) and max(acceleration['off_fill'],acceleration['on_fill'])>.999)
    result['controller_reset_during_cycle']=call_counts['controller_init']!=1 or call_counts['pressure_init']!=1
    result['normal_scheduler_complete']=True
    result['full_oem_ecu']=False
    result['model_calibrated']=False
    result['call_counts']=call_counts
    result['fault_flags_seen']=sorted({r['fault_flags'] for r in rows})
    shifts=[];pending=None
    for e in events:
        if e['mode'] in (1,2,3,4) and pending is None:pending=e
        elif e['mode'] not in (1,2,3,4) and pending is not None:
            shifts.append(dict(start_s=pending['t_s'],target_gear=pending['gear'],mode=pending['mode'],duration_s=e['t_s']-pending['t_s']))
            pending=None
    result['automatic_shifts']=shifts
    result['long_pressure_sequences']=[shift for shift in shifts if shift['duration_s']>5]
    result['scenario']=scenario
    result['assumptions']={'tick_ms':tick_ms,'dt_ms':dt_ms,'atf_raw':110,'coding':[32,34],
        'final_drive_x1000':3070,'wheel_circumference_raw':1975,'controller':'complete normal scheduler; decoded inputs',
        'plant':'equivalent gear paths; no planetary/freewheel reconstruction',
        'omitted':'physical TCC, current regulator, EEPROM persistence, complete outer hardware diagnostics',
        'engine':'idle PI + prescribed pedal torque; quadratic stall coupling; 4500 RPM governor',
        'temperature':'fixed, not a thermal warmup model'}
    return result

def main():
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('--output',default='sim/results/full_drive_cycle');parser.add_argument('--tick-ms',type=int,default=20);parser.add_argument('--dt-ms',type=float,default=1);parser.add_argument('--compare-rom',action='store_true');parser.add_argument('--scenario',default=str(ROOT/'sim/scenarios/park_to_park.json'));a=parser.parse_args()
    out=Path(a.output);out.mkdir(parents=True,exist_ok=True)
    sources=sorted([*(ROOT/'src/egs51').glob('*.[ch]'),ROOT/'sim/plant.h',ROOT/'sim/cycle_plant.cpp',Path(__file__)])
    source_hash=hashlib.sha256(b''.join(p.read_bytes() for p in sources)).hexdigest()
    with tempfile.TemporaryDirectory() as td:
        lib,plant=build(Path(td));r=simulate(lib,plant,out/'drive.csv',a.tick_ms,a.dt_ms,a.compare_rom,json.loads(Path(a.scenario).read_text()))
        r['native_sha256']=hashlib.sha256((Path(td)/'egs51.so').read_bytes()).hexdigest()
        r['plant_sha256']=hashlib.sha256((Path(td)/'cycle.so').read_bytes()).hexdigest()
    r['rom_sha256']=hashlib.sha256(egs51.ROM).hexdigest()
    r['source_sha256']=source_hash
    make_report(out,r)
    (out/'summary.json').write_text(json.dumps(r,indent=2)+'\n');print(json.dumps({k:v for k,v in r.items() if k!='events'},indent=2))

def make_report(out,result):
    data=[{k:(v if k=='segment' else float(v)) for k,v in row.items()} for row in csv.DictReader((out/'drive.csv').read_text().splitlines())]
    title='EGS51 persistent Park-to-Park cycle'
    text=f'''<!doctype html><meta charset="utf-8"><title>{title}</title><style>
body{{font:16px system-ui;max-width:1100px;margin:30px auto;padding:0 20px;color:#172533}}canvas{{width:100%;height:310px;border:1px solid #ccd}}select{{padding:8px;margin:12px 0}}pre{{white-space:pre-wrap}}p{{line-height:1.5}}</style>
<h1>{title}</h1><p>One initialization; {result['scheduler_ticks']} complete normal scheduler ticks. Controller RAM, timers, filters, adaptation and physical path fill persist between stages. Automatic gears observed: {html.escape(str(result['gears']))}. Maximum speed: {result['max_speed_kph']:.1f} km/h. Final speed: {result['final_speed_kph']:.3f} km/h; selector: {result['final_selector']} (8 = Park). Primed at acceleration: {result['primed_at_acceleration']}.</p>
<p><strong>Sequences longer than 5 s (investigate, not a quality pass):</strong> {html.escape(str(result['long_pressure_sequences']))}</p>
<p>This is a development model, not vehicle validation. It starts with an idling engine and fixed ATF temperature. Physical TCC, electrical current regulation, detailed planetary/freewheel hydraulics and EEPROM persistence are omitted. Tick period and physical input encodings remain assumptions.</p>
<p><a href="drive.csv">Controller-tick trace CSV</a> · <a href="summary.json">Scenario, state coverage, events and provenance</a>. Hover over a plot to inspect retained state through the cycle.</p>
<select id="a"></select><canvas id="ca" width="1060" height="310"></canvas><pre id="ta"></pre>
<select id="b"></select><canvas id="cb" width="1060" height="310"></canvas><pre id="tb"></pre>
<script>const data={json.dumps(data)};
const series={{speed_kph:'Vehicle speed (km/h)',engine_rpm:'Engine RPM',input_rpm:'Turbine RPM',gear:'Controller gear',demand:'Automatic gear demand',mode:'Pressure mode',off_fill:'Old path fill (0–1)',on_fill:'New path fill (0–1)',mpc_raw:'MPC command (raw)',clutch_raw:'Applying pressure (raw)',torque_limit_nm:'Engine torque limit (Nm; -1 inactive)',pressure_timer:'Pressure emergency timer (raw ticks)',ratio_recovery:'Ratio recovery state',tcc_demand_raw:'TCC command (raw; physical TCC omitted)'}};
function panel(id,initial){{const sel=document.getElementById(id),can=document.getElementById('c'+id),ctx=can.getContext('2d'),tip=document.getElementById('t'+id);
for(const [k,v] of Object.entries(series)){{const o=document.createElement('option');o.value=k;o.textContent=v;sel.append(o)}}sel.value=initial;
function draw(){{let lo=Math.min(0,...data.map(r=>r[sel.value])),hi=Math.max(1,...data.map(r=>r[sel.value]));ctx.clearRect(0,0,1060,310);ctx.font='13px system-ui';for(let i=0;i<=5;i++){{let y=280-i*50;ctx.strokeStyle='#dde2e8';ctx.beginPath();ctx.moveTo(65,y);ctx.lineTo(1040,y);ctx.stroke();ctx.fillStyle='#354052';ctx.fillText((lo+(hi-lo)*i/5).toFixed(1),3,y);ctx.fillText((data.at(-1).t_s*i/5).toFixed(0)+' s',65+975*i/5,302)}}ctx.strokeStyle='#146bb2';ctx.lineWidth=1.8;ctx.beginPath();data.forEach((r,i)=>{{let x=65+975*r.t_s/data.at(-1).t_s,y=280-250*(r[sel.value]-lo)/(hi-lo);if(i)ctx.lineTo(x,y);else ctx.moveTo(x,y)}});ctx.stroke()}}
sel.onchange=draw;can.onmousemove=e=>{{let x=(e.clientX-can.getBoundingClientRect().left)*1060/can.getBoundingClientRect().width;let i=Math.max(0,Math.min(data.length-1,Math.round((x-65)/975*(data.length-1))));let r=data[i];tip.textContent=`${{r.t_s.toFixed(2)}} s — ${{r.segment}} | ${{series[sel.value]}}: ${{r[sel.value].toFixed(3)}} | gear ${{r.gear}}, mode ${{r.mode}}, phase ${{r.phase}}`;}};draw();}}
panel('a','speed_kph');panel('b','gear');</script>'''
    (out/'comparison.html').write_text(text)

if __name__=='__main__':main()
