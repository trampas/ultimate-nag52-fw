#!/usr/bin/env python3
"""Crossover execution against unhooked ROM; no substitute pressure callees."""
import ctypes as c
from pathlib import Path
import random
import subprocess
import tempfile
from verify_model import ROOT, State, U8, U16, state, word, check_memory
from verify_handoff import configured
from verify_shift_pressure import IMS

def main():
    rng=random.Random(0x4667)
    with tempfile.TemporaryDirectory(prefix='egs51-crossover-') as td:
        so=Path(td)/'model.so'
        subprocess.run(['cc','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-shared','-fPIC',
                        *map(str,sorted((ROOT/'reconstructed').glob('egs51_*.c'))),'-o',str(so)],check=True)
        lib=c.CDLL(str(so));ptr=c.POINTER(State)
        routines=[('crossover_inertia_time',0x6784,[]),('crossover_torque_map',0x6c32,[]),
                  ('crossover_torque_margin',0x6e99,[]),('crossover_momentum',0x8f1f,[]),
                  ('crossover_inertia_apply',0x7f0e,[]),('crossover_settle_apply',0x7feb,[]),
                  ('crossover_inertia',0x8fee,[])]
        import os
        selection=os.environ.get('EGS51_ROUTINES','').split(',')
        for name,entry,types in routines:
            if selection!=[''] and name not in selection:continue
            fn=getattr(lib,'egs51_'+name);fn.argtypes=[ptr]+types;fn.restype=U8 if name=='crossover_inertia_time' else U16 if name in ('crossover_momentum','crossover_inertia_apply','crossover_settle_apply') else None
            for j in range(6000):
                cpu=configured();cpu.x[0x32e]=rng.randrange(31);word(cpu.x,0x181,rng.randrange(1,65536))
                cpu.im[0xb6]=rng.choice([1,4]);cpu.im[0xac]=rng.randrange(1,5) if cpu.im[0xb6]==1 else rng.randrange(5,9)
                cpu.run(0x61cf);cpu.run(0x2bb2)
                cpu.im[0xb4]=rng.randrange(2 if name=='release_entry' else 9)
                cpu.im[0xb0]=rng.choice([0,1,255]);cpu.im[0xb2]=rng.choice([0,0,1]);word(cpu.im,0xb7,rng.choice([0,1,120]))
                args=[]
                if types:
                    args=[rng.randrange(65536) if types[0]==U16 else rng.randrange(8)]
                    cpu.wr(6,args[0]>>8);cpu.wr(7,args[0])
                if len(types)>1:
                    args.append(rng.randrange(65536));cpu.wr(4,args[1]>>8);cpu.wr(5,args[1])
                s=state(cpu);cpu.run(entry);got=fn(c.byref(s),*args)
                if fn.restype:assert got==(cpu.r(7) if fn.restype==U8 else cpu.r(6)*256+cpu.r(7)),(name,j,args,got,cpu.r(6)*256+cpu.r(7))
                try:check_memory(cpu,s,IMS,range(1024))
                except AssertionError as e:raise AssertionError((name,j,str(e))) from e
            print(f'PASS: 6000 complete {name} calls',flush=True)
if __name__=='__main__':main()
