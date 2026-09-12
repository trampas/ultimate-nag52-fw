#!/usr/bin/env python3
"""Compare physical signal calculations with unhooked bank0 ROM instructions."""
import ctypes as c
import os
from pathlib import Path
import random
import subprocess
import tempfile
from verify_model import ROOT, State, base, state, word, check_memory, ROM

def main():
    rng=random.Random(0xc6c6)
    with tempfile.TemporaryDirectory(prefix='egs51-inputs-') as td:
        so=Path(td)/'model.so'
        subprocess.run(['cc','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-shared','-fPIC',
                        *map(str,sorted((ROOT/'reconstructed').glob('egs51_*.c'))),'-o',str(so)],check=True)
        lib=c.CDLL(str(so))
        visited=set()
        for name,entry in [('turbine_speed',0xc449),('clutch_speeds',0xc6c6),('torque_context',0xcf5b),('turbine_filter',0xca22),('torque_inputs',0xca65)]:
            if os.environ.get('EGS51_ROUTINES') and name not in os.environ['EGS51_ROUTINES'].split(','):continue
            fn=getattr(lib,'egs51_'+name); fn.argtypes=[c.POINTER(State)]; fn.restype=None
            for j in range(12000):
                cpu=base(0)
                for a in range(1024):cpu.x[a]=rng.randrange(256)
                for a in (0xb6,0xac,0xb3,0xb9):cpu.im[a]=rng.randrange(12) if j%2 else rng.randrange(256)
                for a in (0x1f0,0x1f6,0x375,0x22f):
                    word(cpu.x,a,rng.choice([0,1,32767,32768,65535]) if j%3==0 else rng.randrange(65536))
                if name=='torque_inputs':
                    # Valid bank0 converter descriptors across supported coding entries.
                    code=rng.choice([n for n in range(16) if int.from_bytes(ROM[0xecf0+2*n:0xecf2+2*n],'big')!=65535])
                    word(cpu.x,0x3ac,int.from_bytes(ROM[0xecf0+2*code:0xecf2+2*code],'big'))
                    cpu.im[0xb6]=j%8;cpu.im[0xb9]=1+j%7
                    if j%3==0:word(cpu.x,0x275,rng.choice([0,1,32767,32768,65535]))
                    cpu.x[0x184]=rng.choice([2,3])
                    # Include healthy and each fallback path, not only random faults.
                    cpu.x[0x71]&=rng.choice([0,8,16,32,255])
                    cpu.x[0x70]&=rng.choice([0,8,16,32,255])
                    cpu.x[0x1ca]&=rng.choice([0,255]);cpu.x[0x1cb]&=rng.choice([0,255])
                    for a in (0x284,0x2bd):cpu.x[a]=rng.choice([0,1,255])
                s=state(cpu);cpu.run(entry);fn(c.byref(s))
                if name=='torque_inputs':visited.update(cpu.visited)
                try:check_memory(cpu,s,range(0xa9,0xc0),range(1024))
                except AssertionError as e:raise AssertionError((name,j,str(e))) from e
            print(f'PASS: 12000 complete {name} calls',flush=True)
        if not os.environ.get('EGS51_ROUTINES') or 'torque_inputs' in os.environ['EGS51_ROUTINES'].split(','):
            cpu=base(0);word(cpu.x,0x3ac,int.from_bytes(ROM[0xecf0:0xecf2],'big'))
            cpu.x[0x9b]=90;cpu.x[0x9d]=60;cpu.x[0x9e]=80;cpu.x[0x9f]=100
            cpu.x[0x8b]=100;cpu.x[0x86]=30
            native=state(cpu)
            stages=[('turbine_filter',0xca22),('torque_inputs',0xca65),('timers_tick',0xe48d)]
            for name,_ in stages:
                fn=getattr(lib,'egs51_'+name);fn.argtypes=[c.POINTER(State)];fn.restype=None
            for tick in range(1800):
                for a,v in ((0x275,0 if tick%100==0 else 1000+tick%1500),(0x22f,tick%2400),(0x2ac,tick%800)):
                    word(cpu.x,a,v);word(native.x,a,v)
                for a,v in ((0x184,2+(tick//75)%2),(0x71,8 if tick%173<4 else 0),
                            (0x70,32 if tick%227<3 else 0),(0x1ca,8 if tick%307<5 else 0),
                            (0x1c8,8 if tick%160<80 else 0)):
                    cpu.x[a]=v;native.x[a]=v
                for a,v in ((0xb6,(tick//100)%8),(0xb9,1+(tick//150)%7)):
                    cpu.im[a]=v;native.im[a]=v
                for name,entry in stages:
                    cpu.run(entry);getattr(lib,'egs51_'+name)(c.byref(native))
                    check_memory(cpu,native,range(0xa9,0xc0),range(1024))
                    visited.update(cpu.visited)
            required={0xca7f,0xcacc,0xcaed,0xcb22,0xcc6c,0xcc97,0xcd17,0xcd43,
                      0xcdb8,0xcdc1,0xceac,0xcf42,0xcf4c,0xcf5b,0xcf6a}
            assert required<=visited,('unexercised qualification paths',sorted(required-visited))
            print('PASS: 5400 persistent filter/torque/timer calls; all selected qualification and converter branches',flush=True)
if __name__=='__main__':main()
