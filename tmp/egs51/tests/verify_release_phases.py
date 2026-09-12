#!/usr/bin/env python3
"""Entry/transfer/pressure matching/completion, no hooked firmware callees."""
import ctypes as c
from pathlib import Path
import random
import subprocess
import tempfile
from verify_model import ROOT, State, U8, U16, state, word, check_memory
from verify_handoff import configured
from verify_shift_pressure import IMS
rng=random.Random(0x97ec)
def main():
    with tempfile.TemporaryDirectory(prefix='egs51-phases-') as td:
        so=Path(td)/'model.so'
        subprocess.run(['cc','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-shared','-fPIC',
                        *map(str,sorted((ROOT/'reconstructed').glob('egs51_*.c'))),'-o',str(so)],check=True)
        lib=c.CDLL(str(so));ptr=c.POINTER(State)
        cases=[('release_bleed_pressure',0x72aa,[ptr,U8,U16],U16),
               ('release_transfer_apply',0x7cee,[ptr],U16),
               ('release_transfer_mod',0x79bd,[ptr,U8],U16),
               ('release_match_pressure',0x8200,[ptr,U8],U16),
               ('release_entry',0x97ec,[ptr],None),
               ('release_transfer',0x96bb,[ptr],None),
               ('release_match',0x9a6b,[ptr],None),
               ('shift_finish',0x9934,[ptr],None)]
        for name,entry,types,ret in cases:
            fn=getattr(lib,'egs51_'+name);fn.argtypes=types;fn.restype=ret
            for j in range(4000):
                cpu=configured();cpu.x[0x32e]=rng.randrange(31)
                cpu.im[0xb6]=rng.choice([2,3]);cpu.im[0xac]=cpu.im[0xb9]+4 if cpu.im[0xb6]==3 else cpu.im[0xb9]-1
                cpu.run(0x61cf);cpu.run(0x2bb2)
                cpu.im[0xb4]=rng.randrange(2 if name=='release_entry' else 4)
                cpu.im[0xb0]=rng.choice([0,1,255]);cpu.im[0xb1]=rng.choice([0,1,255]);cpu.im[0xb2]=rng.choice([0,0,0,1])
                word(cpu.im,0xb7,rng.choice([0,1,120]))
                args=[]
                if len(types)>1:
                    args=[rng.randrange(1,9) if name=='release_transfer_mod' else rng.randrange(8)];cpu.wr(7,args[0])
                if len(types)>2:
                    args.append(rng.randrange(65536));cpu.wr(4,args[1]>>8);cpu.wr(5,args[1])
                s=state(cpu);cpu.run(entry);got=fn(c.byref(s),*args)
                if ret:assert got==cpu.r(6)*256+cpu.r(7),(name,j,args,got,cpu.r(6)*256+cpu.r(7))
                try:check_memory(cpu,s,IMS,range(1024))
                except AssertionError as e:raise AssertionError((name,j,args,str(e))) from e
            print(f'PASS: 4000 complete {name} calls',flush=True)
        import sys
        sys.path.insert(0,str(ROOT/'tools'))
        from replay_downshift_handoff import trajectory
        calls=0
        for rise in (0,30,100):
            rows=trajectory(rise,lib,True);calls+=len(rows)
            for gear in range(1,5):calls+=len(trajectory(rise,lib,True,gear))
        print(f'PASS: 15 persistent pressure schedules through completion, {calls} ticks',flush=True)
if __name__=='__main__':main()
