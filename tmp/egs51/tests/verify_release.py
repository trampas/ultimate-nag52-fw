#!/usr/bin/env python3
"""Release-family pressure control comparisons, complete unhooked ROM calls."""
import ctypes as c
from pathlib import Path
import random
import subprocess
import tempfile
from verify_model import ROOT, State, U8, U16, state, word, check_memory
from verify_handoff import configured
from verify_shift_pressure import IMS
rng=random.Random(0x4fc0)

def main():
    with tempfile.TemporaryDirectory(prefix='egs51-release-') as td:
        so=Path(td)/'model.so'
        subprocess.run(['cc','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-shared','-fPIC',
                        *map(str,sorted((ROOT/'reconstructed').glob('egs51_*.c'))),'-o',str(so)],check=True)
        lib=c.CDLL(str(so));ptr=c.POINTER(State)
        cases=[('shift_pid',0xdd6,[ptr,U16,U16,U16],U16),
               ('percent_filter',0xf97,[U8,U16,U16],U16),
               ('release_hold_time',0x68bb,[ptr,U8],U8),
               ('release_ramp_time',0x69c7,[ptr,U8],U8),
               ('release_initial_pressure',0x7402,[ptr,U8],U16),
               ('release_momentum',0x4ed9,[ptr],U16),
               ('release_final_pressure',0x7711,[ptr,U8],U16),
               ('shift_momentum_control',0xc611,[ptr,U16],None),
               ('release_apply',0x4bc9,[ptr],None),
               ('release_modulate',0x4fc0,[ptr],None)]
        for name,entry,types,ret in cases:
            fn=getattr(lib,'egs51_'+name);fn.argtypes=types;fn.restype=ret
            for j in range(4000):
                cpu=configured()
                # A wrapped zero inertia factor is not a valid control input.
                # Randomize within a positive range; do not invent divide-by-zero semantics.
                cpu.x[0x32e]=rng.randrange(31);word(cpu.x,0x2b1,rng.randrange(1,65536))
                cpu.im[0xb6]=rng.choice([2,3]);cpu.im[0xac]=cpu.im[0xb9]+4 if cpu.im[0xb6]==3 else cpu.im[0xb9]-1
                cpu.im[0xb4]=rng.randrange(9);cpu.im[0xb0]=rng.choice([0,1,255])
                cpu.im[0xb5]=rng.randrange(9);cpu.im[0xb1]=rng.choice([0,1,255])
                word(cpu.im,0xb7,rng.choice([0,1,120]))
                cpu.run(0x61cf);cpu.run(0x2bb2)
                args=[]
                if name=='shift_pid':
                    cal=(cpu.x[0x3ca]*256+cpu.x[0x3cb])+rng.choice([0x12,0x18])
                    args=[0x2d6,cal,rng.randrange(65536)]
                    for reg,v in zip([6,4,2],args):cpu.wr(reg,v>>8);cpu.wr(reg+1,v)
                elif name=='percent_filter':
                    args=[rng.randrange(256),rng.randrange(65536),rng.randrange(65536)]
                    cpu.wr(7,args[0])
                    for reg,v in zip([4,2],args[1:]):cpu.wr(reg,v>>8);cpu.wr(reg+1,v)
                elif name=='shift_momentum_control':
                    cpu.im[0xb6]=rng.choice([1,2,3,4,6])
                    args=[rng.randrange(65536)];cpu.wr(6,args[0]>>8);cpu.wr(7,args[0])
                elif len(types)==2:
                    args=[rng.randrange(1,9) if ret is U8 else rng.randrange(8)];cpu.wr(7,args[0])
                s=state(cpu)
                try:cpu.run(entry)
                except AssertionError as e:raise AssertionError((name,j,args,str(e))) from e
                got=fn(*(([c.byref(s)] if name!='percent_filter' else [])+args))
                if ret:
                    expected=cpu.r(7) if ret is U8 else cpu.r(6)*256+cpu.r(7)
                    assert expected==got,(name,j,args,expected,got)
                try:check_memory(cpu,s,IMS,range(1024))
                except AssertionError as e:raise AssertionError((name,j,args,str(e))) from e
            print(f'PASS: 4000 complete {name} calls',flush=True)
if __name__=='__main__':main()
