# Run from the repository root: python3 tmp/simulation_assessment_20260910/inventory.py
import json, statistics, collections
from pathlib import Path

def describe(values):
    return {'min':min(values),'median':statistics.median(values),'max':max(values)} if values else None
reports=[]
for path in sorted(Path('logger/logs').glob('*.jsonl')):
    types=collections.Counter(); records=collections.Counter(); versions=collections.Counter(); gears=collections.Counter()
    fields=collections.defaultdict(collections.Counter)
    ranges=collections.defaultdict(list); times=[]; accel=[]; trace_dt=[]; snap=[]; headers=[]; evs=collections.Counter()
    complete=0; seen=set(); epoch=0; prior=None; moving=0; malformed=0; own_count=0; annotated=0; shift_bins=collections.Counter(); fwd_v4=0; errors=0
    for line in path.open():
        try:e=json.loads(line)
        except json.JSONDecodeError:malformed+=1;continue
        typ=e.get('type');types[typ]+=1
        if typ=='header': headers.append({k:e.get(k) for k in ('started','fast','slow','accel')})
        if typ=='snapshot':
            c=e.get('calibration',{}); r=e.get('records',{})
            snap.append({'firmware':r.get('fw_header',{}).get('version'), 'sha256':r.get('fw_header',{}).get('app_elf_sha256'), 'records':list(r),'calibration_crc_ok':c.get('crc_ok'),'calibration_names':[c.get(k) for k in ('tcc_cal_name','mech_cal_name','hydr_cal_name','shift_algo_pack_name')]})
        if typ=='event':evs[e.get('event')]+=1
        if typ=='cycle':
            t=e.get('tcu_ms')
            if t is not None:
                if prior is not None and t<prior:epoch+=1
                if prior is not None and t>prior:times.append(t-prior)
                prior=t
            for k,v in e.items():
                if isinstance(v,dict):
                    records[k]+=1;fields[k].update(v.keys()); errors+=int('_error' in v)
            sensors=e.get('sensors',{}); can=e.get('can',{})
            out=sensors.get('output_rpm')
            if out is not None and 150<out<65535:
                moving+=1
                for k,v in {'atf':sensors.get('atf_temp'),'output_rpm':out,'engine_rpm':can.get('engine_rpm'),'pedal':can.get('pedal_pos'),'torque':can.get('static_torque')}.items():
                    if isinstance(v,(int,float)) and -100<v<65000:ranges[k].append(v)
        if typ=='accel':accel.append(e['t'])
        if typ=='shift_trace':
            key=(epoch,e.get('shift_id'),e['seq_start'],e['seq_end'])
            if key in seen: continue
            seen.add(key)
            ver=e.get('trace_version','legacy/unstated'); versions[str(ver)]+=1
            gf,gt=str(e['gear_from']),str(e['gear_to']); gears[gf+'>'+gt]+=1
            own={s['seq']:s for s in e.get('samples',[]) if e['seq_start']<=s['seq']<=e['seq_end']}
            if len(own)==e['seq_end']-e['seq_start']+1:complete+=1
            own_count+=len(own)
            ordered=sorted(own.values(),key=lambda s:s['seq'])
            trace_dt.extend(b['t_ms']-a['t_ms'] for a,b in zip(ordered,ordered[1:]) if b['t_ms']>a['t_ms'])
            annotated+=int('annotated' in e.get('stamp',{}).get('flags',[]))
            if gf in '12345' and gt in '12345' and gf!=gt:
                fwd_v4+=int(ver in (4,5))
                if ordered:
                    ped=ordered[0].get('pedal',0)
                    shift_bins['coast' if ped<=15 else 'light' if ped<=75 else 'medium' if ped<=175 else 'high']+=1
            for s in ordered:fields['trace_samples'].update(s.keys())
    adt=[b-a for a,b in zip(accel,accel[1:]) if b>a]
    reports.append({'file':path.name,'types':dict(types),'records':dict(records),'fields':{k:list(v) for k,v in fields.items()},'snapshots':snap,'headers':headers,'cycle_dt_ms':describe(times),'moving_cycles_output_gt_150':moving,'moving_ranges':{k:describe(v) for k,v in ranges.items()},'trace_versions':dict(versions),'shifts':dict(gears),'unique_traces':len(seen),'complete_trace_windows':complete,'own_trace_samples':own_count,'annotated_traces':annotated,'forward_traces_v4plus':fwd_v4,'shift_start_pedal_bins':dict(shift_bins),'trace_dt_ms':describe(trace_dt),'accel_dt_s':describe(adt),'accel_span_s':accel[-1]-accel[0] if len(accel)>1 else 0,'events':dict(evs),'record_errors':errors,'malformed_lines':malformed})
Path(__file__).with_name('inventory.json').write_text(json.dumps(reports,indent=2)+'\n')
for r in reports:
 if r['moving_cycles_output_gt_150']>100:
  print(r['file'], 'cycles',r['types'].get('cycle',0),'moving',r['moving_cycles_output_gt_150'],'traces',r['unique_traces'],'complete',r['complete_trace_windows'],'versions',r['trace_versions'],'ATF',r['moving_ranges'].get('atf'),'poll_ms',r['cycle_dt_ms'],'accel_dt',r['accel_dt_s'])
print('TOTAL',len(reports),'files',sum(r['types'].get('cycle',0) for r in reports),'cycles',sum(r['unique_traces'] for r in reports),'traces')
