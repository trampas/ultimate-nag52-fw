#!/usr/bin/env python3
"""Differential checks for the complete bank1 shift supervisor and callees."""
import ctypes as c
from pathlib import Path
import random
import subprocess
import tempfile
from verify_model import ROOT, ROM, State, state, base, word, check_memory, U8, U16
rng=random.Random(0x236a)
def configured():
    cpu=base()
    cpu.x[:]=rng.randbytes(1024)
    cpu.x[0x17b]=rng.randrange(3)*16+rng.randrange(2)
    cpu.x[0x17c]=rng.randrange(3)*16+rng.randrange(3)
    cpu.run(0x20bc); assert cpu.r(7)==0
    cpu.im[0xac]=rng.randrange(1,9); cpu.im[0xb6]=rng.randrange(8)
    cpu.x[0x32e]=rng.randrange(10)
    for a in (0x1d6,0x303,0x2c9,0x2b1,0x398): word(cpu.x,a,rng.randrange(100,2000))
    return cpu

def main():
    with tempfile.TemporaryDirectory(prefix='egs51-shift-') as td:
        so=Path(td)/'model.so'
        subprocess.run(['cc','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-shared','-fPIC',
                        *map(str,sorted((ROOT/'reconstructed').glob('egs51_*.c'))),'-o',str(so)],check=True)
        lib=c.CDLL(str(so)); ptr=c.POINTER(State)
        for name,args,ret in [('shift_factor',[ptr],U8),('shift_threshold',[ptr,U8,U8],U16),
                             ('mode_transition',[ptr,U8,U8],None),('shift_direction',[ptr],None),
                             ('shift_supervisor',[ptr],None),('gear_reset',[ptr],None)]:
            fn=getattr(lib,'egs51_'+name); fn.argtypes=args; fn.restype=ret
        for j in range(3000):
            cpu=configured(); s=state(cpu); cpu.run(0x642b)
            assert lib.egs51_shift_factor(c.byref(s))==cpu.r(7)
            check_memory(cpu,s,xs=range(1024))
        print('PASS: 3000 shift factor calculations across all populated variants')
        for j in range(3000):
            cpu=configured(); cpu.im[0x96]=rng.randrange(256)
            idx=rng.randrange(8); param=rng.randrange(256); cpu.wr(7,idx); cpu.wr(5,param)
            s=state(cpu); cpu.run(0x6633)
            expected=cpu.r(6)*256+cpu.r(7); got=lib.egs51_shift_threshold(c.byref(s),idx,param)
            assert expected==got,(j,expected,got)
            check_memory(cpu,s,xs=range(1024))
        print('PASS: 3000 shift threshold calculations, including signed clamp and bypasses')
        for j in range(5000):
            cpu=configured()
            for a in (0x94,0x95,0x96,0xa9,0xb9,0xb7,0xb8): cpu.im[a]=rng.randrange(256)
            cpu.im[0xa9]=rng.randrange(8); cpu.im[0xb9]=rng.randrange(8)
            cpu.x[0x334]=rng.randrange(9); s=state(cpu)
            cpu.run(0x1eeb); lib.egs51_shift_direction(c.byref(s))
            check_memory(cpu,s,range(0x94,0xba),range(1024))
        for variant in range(2):
            for phase in range(10):
                for sub in range(10):
                    for mode in range(8):
                        cpu=base(); cpu.im[0xaa]=phase; cpu.im[0xb4]=sub; cpu.im[0x96]=255
                        cpu.im[0xb0]=10; cpu.im[0xb1]=20; cpu.im[0xb5]=7; cpu.wr(7,mode)
                        s=state(cpu); cpu.run(0x1e36 if variant==0 else 0x1e9d)
                        lib.egs51_mode_transition(c.byref(s),mode,variant)
                        check_memory(cpu,s,range(0x94,0xba),range(1024))
        print('PASS: 5000 direction latches + 1600 mode/phase/substate transitions')
        visited=set()
        for j in range(20000):
            cpu=configured()
            for a in (0x94,0x95,0x96,0x98,0x9a): cpu.im[a]=rng.randrange(256)
            for a in (0xa9,0xb3,0xb9): cpu.im[a]=rng.randrange(8)
            for a in (0xaa,0xb4,0xb5): cpu.im[a]=rng.randrange(9)
            for a in (0xb0,0xb1,0xb2,0xb7,0xb8): cpu.im[a]=rng.randrange(256)
            cpu.im[0xb6]=j%8
            cpu.x[0x334]=rng.randrange(1,9); cpu.x[0x78]=0 if j%5 else 2
            cpu.x[0x1c2]=rng.choice([0,0,0,0,rng.randrange(256)])
            cpu.im[0x96]=rng.choice([0,0,cpu.im[0x96]])
            before=(bytes(cpu.im),bytes(cpu.x)); s=state(cpu); cpu.run(0x236a); visited.update(cpu.visited)
            lib.egs51_shift_supervisor(c.byref(s))
            try: check_memory(cpu,s,range(0x94,0xba),range(1024),[0x98-128])
            except AssertionError as exc:
                raise AssertionError(f'case {j}: {exc}; im94:ba={before[0][0x94:0xba].hex()} flags1c2={before[1][0x1c2]}') from exc
        print(f'PASS: 20000 complete shift supervisor calls; {sum(0x236a<=a<=0x2bb1 for a in visited)} supervisor instruction addresses')
        for j in range(256):
            cpu=configured(); cpu.x[0x334]=j; s=state(cpu); cpu.run(0x2b80)
            lib.egs51_gear_reset(c.byref(s)); check_memory(cpu,s,range(0x94,0xba),range(1024))
        print('PASS: all 256 complete gear-reset inputs')
if __name__=='__main__': main()
