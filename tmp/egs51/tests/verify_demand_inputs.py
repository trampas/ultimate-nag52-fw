#!/usr/bin/env python3
"""Complete bank0 upstream input/target stages against unhooked ROM execution."""
import ctypes as c
import os
from pathlib import Path
import random
import subprocess
import tempfile
from verify_model import ROOT, State, base, state, word, check_memory, ROM

ROUTINES=[('vehicle_flags',0xba18),('pedal_inputs',0xbc4a),('target_step',0xbd50),
          ('aux_qualification',0xbe8e),('engine_inputs',0xbec3),('wheel_inputs',0xbfd5),('gear_qualification',0x920f),('shaft_inputs',0xc496)]
def main():
    rng=random.Random(0xbd50);visited=set()
    with tempfile.TemporaryDirectory(prefix='egs51-demand-inputs-') as td:
        so=Path(td)/'model.so'
        subprocess.run(['cc','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-shared','-fPIC',
                        *map(str,sorted((ROOT/'reconstructed').glob('egs51_*.c'))),'-o',str(so)],check=True)
        lib=c.CDLL(str(so))
        for name,entry in ROUTINES:
            if os.environ.get('EGS51_ROUTINES') and name not in os.environ['EGS51_ROUTINES'].split(','):continue
            fn=getattr(lib,'egs51_'+name);fn.argtypes=[c.POINTER(State)];fn.restype=None
            for j in range(12000):
                cpu=base(0);cpu.x[:]=rng.randbytes(1024)
                for a in (0x20,0x23,0x81,0x82,0x83,0x84,0x86,0x87,0x88,0xb6):cpu.im[a]=rng.randrange(256)
                cpu.x[0x183]=rng.randrange(4);cpu.x[0x184]=rng.choice([2,3])
                cpu.x[0x71]&=rng.choice([0,255]);cpu.x[0x70]&=rng.choice([0,255])
                cpu.x[0x334]=rng.randrange(9) if j%2 else rng.randrange(256)
                cpu.x[0x75]=rng.randrange(9) if j%2 else rng.randrange(256)
                cpu.x[0x216]=rng.choice([0,1,20,255]);cpu.im[0xb6]=rng.randrange(8)
                word(cpu.x,0x181,rng.randrange(1,65536))
                if name=='shaft_inputs' and j%2:
                    cpu.x[0x6e]=rng.choice([0,0,2,4,8,16]);cpu.x[0x1ca]=0;cpu.x[0x1cb]=0
                    cpu.x[0x1c6]=8;cpu.x[0x78]=0;cpu.x[0x1c7]=0
                    for a in (0x87,0x89,0x323,0x314):word(cpu.x,a,1000)
                    word(cpu.im,0x81,rng.choice([0,1000,8000]));word(cpu.im,0x83,rng.choice([0,1000,8000]))
                    cpu.x[0x34c]=3;cpu.im[0xb9]=3;cpu.im[0xb6]=rng.choice([0,1])
                if name=='gear_qualification':
                    cpu.x[0x227]=rng.randrange(1,6);cpu.im[0xaa]=rng.randrange(8)
                    for a in (0xab,0xb9):cpu.im[a]=rng.randrange(1,6)
                    cpu.im[0x95]=rng.randrange(256);cpu.im[0x9a]=rng.randrange(256)
                    cpu.x[0x2eb]=rng.randrange(6)
                    for cell,table in ((0x3a8,0xed70),(0x3aa,0xed90)):
                        word(cpu.x,cell,int.from_bytes(ROM[table:table+2],'big'))
                native=state(cpu);cpu.run(entry);fn(c.byref(native));visited.update(cpu.visited)
                try:check_memory(cpu,native,[0x20,0x23,*range(0x80,0xc0)],range(1024))
                except AssertionError as e:raise AssertionError((name,j,str(e))) from e
            if name=='shaft_inputs':
                assert {0xc5b9,0xc621,0xc6a6}<=visited,('shaft diagnostic paths missing',visited)
            print(f'PASS: 12000 complete {name} calls',flush=True)
        if os.environ.get('EGS51_ROUTINES'):return
        cpu=base(0);cpu.x[0x183]=1;cpu.x[0x184]=3;cpu.x[0x75]=5;cpu.x[0x334]=5
        word(cpu.x,0x181,1000);word(cpu.x,0x203,3000)
        cpu.x[0x227]=3;cpu.im[0xab]=3;cpu.im[0xb9]=3
        for cell,table in ((0x3a8,0xed70),(0x3aa,0xed90)):
            word(cpu.x,cell,int.from_bytes(ROM[table:table+2],'big'))
        native=state(cpu);timer=lib.egs51_timers_tick;timer.argtypes=[c.POINTER(State)];timer.restype=None
        checks=0;targets=set()
        for tick in range(2400):
            for a,v in ((0x75,[5,2,4,1,7,6,8][(tick//100)%7]),
                        (0x71,8 if tick%173<5 else 0),(0x70,1 if tick%199<3 else 0)):
                cpu.x[a]=v;native.x[a]=v
            for a,v in ((0x20,5 if tick%500<250 else 0),(0x86,tick%256)):
                cpu.im[a]=v;native.im[a]=v
            for st in (cpu,native):word(st.im,0x87,0 if tick%211<20 else 1000+tick%2000)
            for name,entry in ROUTINES+[('timers_tick',0xe48d)]:
                cpu.run(entry);getattr(lib,'egs51_'+name)(c.byref(native));checks+=1
                check_memory(cpu,native,[0x20,0x23,*range(0x80,0xc0)],range(1024));visited.update(cpu.visited)
            targets.add(native.x[0x334])
        assert set(range(1,9))<=targets,targets
        required={0xba32,0xba50,0xbc08,0xbc17,0xbc42,0xbc87,0xbd46,0xbe0a,0xbe1a,0xbe41,0xbe86,0xbeea,0xbf6d,0xbf97}
        assert required<=visited,('uncovered qualification/latch branches',sorted(required-visited))
        print(f'PASS: {checks} persistent upstream/timer calls, all target gears and selected fallback/latch paths',flush=True)
if __name__=='__main__':main()
