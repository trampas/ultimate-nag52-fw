#!/usr/bin/env python3
"""Complete D9C8 pressure-error adaptation against unhooked ROM execution."""
import ctypes as c
from pathlib import Path
import random
import subprocess
import tempfile
from verify_model import ROOT, State, state, word, check_memory, base
from verify_handoff import configured

def main():
    rng=random.Random(0xd9c8); visited=set(); writes=0
    ims=list(range(0x44,0x4c))+list(range(0x95,0xc0))
    with tempfile.TemporaryDirectory(prefix='egs51-pressure-adapt-') as td:
        so=Path(td)/'model.so'
        subprocess.run(['cc','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-shared','-fPIC',
                        *map(str,sorted((ROOT/'reconstructed').glob('egs51_*.c'))),'-o',str(so)],check=True)
        lib=c.CDLL(str(so));fn=lib.egs51_pressure_adaptation
        fn.argtypes=[c.POINTER(State)];fn.restype=None
        for j in range(16000):
            cpu=configured();cpu.x[0x266]=j%6;cpu.x[0x267]=rng.choice([0,1,2,200,254,255])
            cpu.x[0x2ab]=rng.randrange(1,256);word(cpu.x,0x36f,rng.randrange(1,65536))
            cpu.im[0xaa]=rng.randrange(6);cpu.im[0xb6]=rng.randrange(8)
            if (j//6)%2:
                cpu.im[0xb6]=rng.choice([1,4]);cpu.im[0xac]=rng.choice([1,2]) if cpu.im[0xb6]==1 else 7
                cpu.im[0x99]=1;cpu.im[0x96]&=~4;cpu.im[0x98]=0;cpu.im[0xb4]=0
                cpu.im[0xaa]=rng.choice([1,2,3,4]);word(cpu.im,0xad,0)
                cpu.x[0x1ca]=0;cpu.x[0x1cb]=0;cpu.x[0x1bb]=0;cpu.x[0x1bc]=0;cpu.x[0x264]=0
                cpu.x[0x79]=rng.choice([0,0,16]);cpu.x[0x76]=rng.choice([40,60,80,90])
                cpu.im[0x95]=rng.choice([8,16]);word(cpu.x,0x275,1000)
                word(cpu.x,0x22f,700 if cpu.im[0x95]==8 else 1300)
                word(cpu.x,0x2bb,rng.choice([0,10,200,1000,65535]))
                word(cpu.x,0x357,rng.choice([0,10,200,1000,65535]))
            before=bytes(cpu.x[0x167:0x175]);s=state(cpu)
            cpu.run(0xd9c8);fn(c.byref(s));visited.update(cpu.visited)
            try:check_memory(cpu,s,ims,range(1024))
            except AssertionError as e:raise AssertionError((j,str(e))) from e
            writes+=bytes(cpu.x[0x167:0x175])!=before
        required={0xdaad,0xdc80,0xdd04,0xddb5,0xde01,0xe0ed,0xde72,0xdfab,0xdfb4,0xe0e8}
        assert required<=visited,('uncovered branches',sorted(required-visited))
        assert writes>0
        print(f'PASS: 16000 complete pressure-adaptation calls; {writes} cell changes; all selected state/write branches',flush=True)
        timer=lib.egs51_timers_tick;timer.argtypes=[c.POINTER(State)];timer.restype=None
        completed=0;checks=0
        for mode,shift,direction in ((1,1,8),(1,2,8),(4,7,16)):
            cpu=base();cpu.x[0x17b]=0x20;cpu.x[0x17c]=0x22;cpu.run(0x20bc)
            cpu.im[0xb6]=mode;cpu.im[0xac]=shift;cpu.im[0xaa]=2;cpu.im[0x95]=direction
            cpu.x[0x76]=120;cpu.x[0x2ab]=50
            for a,v in ((0x275,1000),(0x22f,700 if direction==8 else 1300),
                        (0x2bb,0),(0x357,1000),(0x363,5000),(0x36f,1000)):
                word(cpu.x,a,v)
            native=state(cpu);stages=set();finished=False
            for tick in range(100):
                # Allow the native state machine and OEM timer to advance;
                # only the synthetic speed observation changes at tick30.
                if tick==2:
                    word(cpu.x,0x2bb,1000);word(native.x,0x2bb,1000)
                if tick==30:
                    word(cpu.x,0x357,0);word(native.x,0x357,0)
                cpu.run(0xd9c8);fn(c.byref(native));checks+=1
                check_memory(cpu,native,ims,range(1024));stages.add(native.x[0x266])
                if native.x[0x266]==4 and native.im[0x99]&1:
                    assert any(native.x[a] for a in (0x167,0x168,0x174))
                    cpu.im[0xb6]=native.im[0xb6]=0
                    cpu.run(0xd9c8);fn(c.byref(native));checks+=1
                    check_memory(cpu,native,ims,range(1024))
                    assert native.x[0x266]==0 and native.x[0x1bf]&1 and not native.im[0x99]&1
                    finished=True;completed+=1;break
                cpu.put(0x88,cpu.direct(0x88)&~16);cpu.run(0xe48d);timer(c.byref(native));checks+=1
                check_memory(cpu,native,ims,range(1024));cpu.put(0x88,cpu.direct(0x88)|16)
            assert finished and {1,2,3,4}<=stages,(mode,shift,stages,native.im[0x99],native.x[0x266])
        print(f'PASS: {completed} full observation/update/dirty lifecycles, {checks} persistent adaptation/timer calls',flush=True)
if __name__=='__main__':main()
