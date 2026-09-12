#!/usr/bin/env python3
"""Rebuild EGS52 analysis in a disposable project and publish checked artifacts.

Usage: python3 tmp/egs52/tools/rebuild.py
No Ghidra project or prior exports are reused. Failed runs do not publish C.
"""
import argparse
import csv
import fcntl
import hashlib
import json
import re
import shutil
import subprocess
import sys
import tempfile
from pathlib import Path
from decode_flash import ROOT, transform, verify
from c_listing_checks import known_arities, call_abi_errors


def digest(path):return hashlib.sha256(path.read_bytes()).hexdigest()


def run(command, log):
    result=subprocess.run([str(x) for x in command],stdout=subprocess.PIPE,stderr=subprocess.STDOUT,text=True)
    log.write_text(result.stdout)
    if result.returncode or 'ERROR REPORT SCRIPT ERROR' in result.stdout or 'ERROR REPORT: Error' in result.stdout:
        raise RuntimeError(f'Command failed; see {log}\n'+result.stdout[-4000:])
    return result.stdout


def publish(export, report, verification, processor_log, analysis_log):
    target=ROOT/'reconstructed'
    arities=known_arities(ROOT/'tools')
    symbols={r['address']:r for r in csv.DictReader((ROOT/'tools/symbols.csv').open())}
    structural={r['address']:r for r in csv.DictReader((export/'structural_names.csv').open())}
    rows=list(csv.DictReader((export/'functions_index.csv').open()))
    # Native equivalents replace the decompiler versions rather than retaining
    # known ABI mistakes under a second name.
    native={r['address']:r['name'] for r in symbols.values() if r['confidence']=='verified'}
    native['092118']='egs52_near_to_physical'
    # These register-ABI routines have accurate call-site p-code fixups, but
    # Ghidra cannot describe their multiple live register outputs as ordinary C.
    register_abi={'083132','083138','09212e','09214e','0921b4','0921ce','092226','09222c','09226c','09227c'}
    invalid_patterns={
        'decompilation_failed':r'DECOMPILATION FAILED',
        'invalid_type':r'\bBADTYPE\b',
        'invalid_instruction':r'Bad instruction|halt_baddata|bad instruction data',
        'overlapping_instructions':r'overlaps instruction',
        'unresolved_jump_table':r'Could not recover jumptable|Could not recover jump table',
        'unknown_register_abi':r'\b(?:unaff_|extraout_|in_)[A-Za-z0-9_]+',
        'truncated_control_flow':r'Truncating control flow',
    }
    with tempfile.TemporaryDirectory(prefix='egs52_publish_',dir=ROOT) as temp:
        stage=Path(temp);(stage/'functions').mkdir()
        index=[];unresolved=[];source_count=0
        # Preserve byte-for-byte evidence alongside the C. Interpretation is
        # explicitly labelled in the index, not implied by filename alone.
        for filename in ('firmware.asm','calls.csv','recovered_jumps.csv','structural_names.csv'):
            shutil.copy2(export/filename,stage/filename)
        for row in rows:
            a=row['address'];name=row['name'];entry=int(a,16)
            f=export/'functions'/f'{a}_{name}.c'
            text=f.read_text();reasons=[k for k,v in invalid_patterns.items() if re.search(v,text)]
            if call_abi_errors(text,arities):reasons.append('known_call_abi_mismatch')
            status='decompiled_unverified';source=f'functions/{f.name}'
            if a in native:
                status='verified_native';source='egs52_reconstructed_clean.c';reasons=[]
            elif a in register_abi:
                status='register_abi_in_fixups';source='';reasons=['multiple_register_outputs_or_indirect_transfer']
            elif entry<0x80200 or 0x93b00<=entry<0x93d00:
                status='vector_data';source='egs52_vectors.c';reasons=[]
            elif reasons:
                status='withheld';source=''
            else:
                # A single-register return and a constant-return leaf can be
                # named mechanically without assigning a speculative ECU role.
                body=text[text.find('\n\n'):]
                if name.startswith('egs52_sub_'):
                    match=re.search(r'\breturn (?:Ram|uRam|sRam|bRam|cRam)([0-9a-f]{6});',body)
                    literal=re.search(r'\{\s*return (0x[0-9a-f]+|[0-9]+);\s*\}',body)
                    if match:name=f'egs52_read_{match[1]}_{a}'
                    elif literal:name=f'egs52_return_{literal[1]}_{a}'
                text=text.replace(row['name'],name)
                text='/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware\n * effects require review. Native verified equivalents are indexed separately.\n * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.\n */\n'+text
                source=f'functions/{a}_{name}.c'
                (stage/source).write_text(text);source_count+=1
            meta=symbols.get(a,structural.get(a,{}))
            if status=='vector_data' and not meta:
                meta={'confidence':'observed','evidence':'Exact JMPS vector slot and destination in decoded image'}
            if not meta and name!=row['name']:
                meta={'confidence':'mechanical','evidence':'Literal register read or constant return in decompiled leaf'}
            index.append({**row,'name':name,'status':status,'source':source,
                          'native_symbol':native.get(a,''),'name_confidence':meta.get('confidence','address_only'),
                          'name_evidence':meta.get('evidence','Unresolved role; address retained')})
            if reasons:unresolved.append({'address':a,'name':name,'reason':';'.join(reasons)})
        with (stage/'functions_index.csv').open('w') as f:
            w=csv.DictWriter(f,fieldnames=list(index[0]));w.writeheader();w.writerows(index)
        with (stage/'unresolved.csv').open('w') as f:
            w=csv.DictWriter(f,fieldnames=['address','name','reason']);w.writeheader();w.writerows(unresolved)
        renames={old['name']:new['name'] for old,new in zip(rows,index) if old['name']!=new['name']}
        if renames:
            pattern=re.compile(r'\b(?:'+'|'.join(map(re.escape,renames))+r')\b')
            for source_path in (stage/'functions').glob('*.c'):
                source_path.write_text(pattern.sub(lambda m:renames[m.group()],source_path.read_text()))
            calls=stage/'calls.csv';calls.write_text(pattern.sub(lambda m:renames[m.group()],calls.read_text()))
        # Generate vector constants directly from decoded bytes, not decompiled
        # wrappers that can accidentally inline or truncate whole handlers.
        rom=(ROOT/'decoded/A0325452132.bin').read_bytes()
        vectors=['/* Exact vector destinations from decoded flash. */','#include <stdint.h>',
                 'typedef struct { uint32_t slot; uint32_t target; } Egs52Vector;',
                 'const Egs52Vector egs52_vectors[256] = {']
        for base in (0,0x13b00):
            for off in range(base,base+0x200,4):
                assert rom[off]==0xfa
                addr=rom[off+1]<<16|int.from_bytes(rom[off+2:off+4],'little')
                vectors.append(f'    {{0x{off+0x80000:06x}u, 0x{addr:06x}u}},')
        vectors+=['};',''];(stage/'egs52_vectors.c').write_text('\n'.join(vectors))
        dispatch=['/* Boot records: callback address followed by packed service metadata. */',
                  '#include <stdint.h>',
                  'typedef struct { uint32_t slot, callback, metadata; } Egs52BootDispatch;',
                  'const Egs52BootDispatch egs52_boot_dispatch[35] = {']
        for base,count in ((0x28c,18),(0x31c,17)):
            for slot in range(base,base+8*count,8):
                callback=int.from_bytes(rom[slot:slot+4],'little')
                metadata=int.from_bytes(rom[slot+4:slot+8],'little')
                dispatch.append(f'    {{0x{slot+0x80000:06x}u, 0x{callback:06x}u, 0x{metadata:08x}u}},')
        dispatch+=['};',''];(stage/'egs52_boot_dispatch.c').write_text('\n'.join(dispatch))
        callbacks=['/* Exact audited callback records. Metadata is zero for four-byte pointer cells. */',
                   '#include <stdint.h>',
                   'typedef struct { uint32_t slot, callback, metadata; uint8_t record_size; } Egs52CallbackRecord;',
                   'const Egs52CallbackRecord egs52_callback_records[] = {']
        for spec in csv.DictReader((ROOT/'tools/callback_tables.csv').open()):
            base=int(spec['base'],16);stride=int(spec['stride'])
            for slot in range(base,base+int(spec['count'])*stride,stride):
                off=slot-0x80000;callback=int.from_bytes(rom[off:off+4],'little')
                metadata=int.from_bytes(rom[off+4:off+8],'little') if stride==8 else 0
                callbacks.append(f'    {{0x{slot:06x}u, 0x{callback:06x}u, 0x{metadata:08x}u, {stride}u}},')
        callbacks+=['};',''];(stage/'egs52_callback_tables.c').write_text('\n'.join(callbacks))
        shutil.copy2(ROOT/'tools/callback_tables.csv',stage/'callback_tables.csv')
        summary={'raw_sha256':report['raw_sha256'],'decoded_sha256':report['decoded_sha256'],
                 'functions_discovered':len(rows),'decompiler_c_files':source_count,
                 'native_functions':sum(r['status']=='verified_native' for r in index),
                 'withheld_or_register_abi':len(unresolved),
                 'curated_names':sum(r['address'] in symbols for r in index),
                 'named_with_evidence':sum(r['name_confidence']!='address_only' for r in index),
                 'instruction_addresses':sum(1 for _ in (stage/'firmware.asm').open()),
                 'whole_firmware_semantically_verified':False}
        (stage/'coverage.json').write_text(json.dumps(summary,indent=2)+'\n')
        (stage/'verification.txt').write_text(verification)
        (stage/'processor_verification.txt').write_text(processor_log)
        (stage/'analysis.log').write_text(analysis_log)
        (stage/'decode_manifest.json').write_text(json.dumps(report,indent=2)+'\n')
        evidence_files = [target/'egs52_reconstructed_clean.c', target/'egs52_math.h',
                          *sorted((ROOT/'tests').glob('*.py'))]
        (stage/'verification_manifest.json').write_text(json.dumps(
            {str(p.relative_to(ROOT)):digest(p) for p in evidence_files},indent=2)+'\n')
        (stage/'tool_manifest.json').write_text(json.dumps({p.name:digest(p) for p in sorted((ROOT/'tools').iterdir()) if p.is_file()},indent=2)+'\n')
        # Validate the staged inventory before any publication. Provide the
        # native sources read-only for cross-reference checks, then remove the
        # temporary copies; the real native files are maintained by hand.
        for filename in ('egs52_reconstructed_clean.c','egs52_math.h'):
            shutil.copy2(target/filename,stage/filename)
        check=subprocess.run([sys.executable,str(ROOT/'tests/verify_artifacts.py'),
                              '--artifact-root',str(stage)],capture_output=True,text=True)
        if check.returncode:
            raise RuntimeError('Staged artifacts rejected; nothing published.\n'+check.stdout+check.stderr)
        (stage/'artifact_verification.txt').write_text(check.stdout)
        for filename in ('egs52_reconstructed_clean.c','egs52_math.h'):
            (stage/filename).unlink()
        # Replace only generated artifacts. Handwritten native C/header/README
        # are outside this publication set. No old generated functions survive.
        for p in stage.iterdir():
            dest=target/p.name
            if dest.is_dir():shutil.rmtree(dest)
            elif dest.exists():dest.unlink()
            shutil.move(str(p),str(dest))
    print(json.dumps(summary,indent=2))


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--ghidra',type=Path,default=Path('/snap/ghidra/47/ghidra'))
    parser.add_argument('--extension',type=Path,default=Path.home()/'.config/ghidra/ghidra_12.1.2_PUBLIC/Extensions/c166-ghidra-module')
    args=parser.parse_args()
    known_arities(ROOT/'tools') # fail fast on incomplete signature metadata
    logs=ROOT/'logs';logs.mkdir(exist_ok=True)
    raw=(ROOT/'A0325452132.FLS').read_bytes();decoded=transform(raw);report=verify(raw,decoded)
    (ROOT/'decoded').mkdir(exist_ok=True);image=ROOT/'decoded/A0325452132.bin';image.write_bytes(decoded)
    run([sys.executable,ROOT/'tools/patch_c166_module.py',args.extension],logs/'module_patch.log')
    evidence_paths=[*(ROOT/'tools').glob('*'),*(ROOT/'tests').glob('*.py'),
                    ROOT/'reconstructed/egs52_reconstructed_clean.c',ROOT/'reconstructed/egs52_math.h']
    input_hashes={p:digest(p) for p in evidence_paths if p.is_file()}
    run([sys.executable,ROOT/'tests/verify_listing_checks.py'],logs/'listing_checks.log')
    verification=run([sys.executable,ROOT/'tests/verify_math.py'],logs/'native_verification.log')
    print(verification.splitlines()[-1],flush=True)
    with tempfile.TemporaryDirectory(prefix='egs52_rebuild_') as temp:
        work=Path(temp);project=work/'project';project.mkdir();export=work/'export'
        cmd=[args.ghidra/'support/analyzeHeadless',project,'egs52',
             '-import',image,'-loader','BinaryLoader','-loader-baseAddr','0x80000',
             '-processor','C166:CS:LE:16:default','-cspec','tasking','-noanalysis',
             '-scriptPath',ROOT/'tools','-postScript','CheckEgs52Processor.java',
             '-postScript','RecoverDecodedEgs52.java',export,ROOT/'tools/symbols.csv']
        output=run(cmd,logs/'rebuild.log')
        processor_checks=int(re.search(r'EXPECTED_CHECKS=(\d+)',(ROOT/'tools/CheckEgs52Processor.java').read_text())[1])
        table_count=len(list(csv.DictReader((ROOT/'tools/jump_tables.csv').open())))
        if f'INDIRECT_TABLES_RECOVERED={table_count}' not in output:
            raise RuntimeError('Indirect-flow recovery marker missing; generated C was not published')
        callback_count=sum(int(r['count']) for r in csv.DictReader((ROOT/'tools/callback_tables.csv').open()))
        if f'AUDITED_CALLBACK_CELLS={callback_count}' not in output:raise RuntimeError('Audited callback marker missing')
        abi_count=len(list(csv.DictReader((ROOT/'tools/native_abi.csv').open())))
        if f'PROCESSOR_REGRESSIONS_PASSED={processor_checks}' not in output or 'EXPORTED=' not in output or f'NATIVE_ABI_APPLIED={abi_count}' not in output:
            raise RuntimeError('Required success markers missing; generated C was not published')
        processor='\n'.join(l for l in output.splitlines() if 'PROCESSOR_REGRESSIONS_' in l)+'\n'
        changed=[str(p) for p,sha in input_hashes.items() if not p.is_file() or digest(p)!=sha]
        if changed:raise RuntimeError('Inputs changed during rebuild; nothing published: '+', '.join(changed))
        publish(export,report,verification,processor,output)
        destination=ROOT/'analysis/ghidra_project'
        if destination.exists():shutil.rmtree(destination)
        destination.parent.mkdir(exist_ok=True);shutil.copytree(project,destination)
    print('Published checked analysis to '+str(ROOT/'reconstructed'))


if __name__=='__main__':
    # Serialize rebuilds which share the installed processor module and output.
    with (ROOT/'.rebuild.lock').open('w') as lock:
        try:fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
        except BlockingIOError:raise SystemExit('An EGS52 rebuild is already running')
        main()
