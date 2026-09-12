#!/usr/bin/env python3
"""OEM adaptation observations, qualification and cell updates against raw ROM."""
import ctypes as c
from pathlib import Path
import random
import subprocess
import tempfile
from verify_model import ROOT, State, U8, U16, state, word, check_memory
from verify_handoff import configured
from verify_shift_pressure import IMS

def main():
    rng=random.Random(0xaf12)
    with tempfile.TemporaryDirectory(prefix='egs51-shift-adapt-') as td:
        so=Path(td)/'model.so'
        subprocess.run(['cc','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-shared','-fPIC',
                        *map(str,sorted((ROOT/'reconstructed').glob('egs51_*.c'))),'-o',str(so)],check=True)
        lib=c.CDLL(str(so));ptr=c.POINTER(State)
        routines=[('adapt_speed_excursion',0xa97e,[]),('adapt_fill_error',0xa9f2,[U8]),
                  ('adapt_fill_observe',0xaa98,[]),('adapt_transfer_observe',0xac65,[]),('adapt_inertia_observe',0xadf6,[]),('shift_adaptation',0xaf12,[]),('shift_demand_factor',0x6aa3,[])]
        import os
        selection=os.environ.get('EGS51_ROUTINES','').split(',')
        for name,entry,types in routines:
            if selection!=[''] and name not in selection:continue
            fn=getattr(lib,'egs51_'+name);fn.argtypes=[ptr]+types;fn.restype=U16 if name=='adapt_speed_excursion' else None
            for j in range(6000):
                cpu=configured();cpu.x[0x32e]=rng.randrange(31);word(cpu.x,0x181,rng.randrange(1,65536))
                cpu.im[0xb6]=rng.choice([1,4]);cpu.im[0xac]=rng.randrange(1,5) if cpu.im[0xb6]==1 else rng.randrange(5,9)
                cpu.im[0x96]&=~0x20;word(cpu.x,0x329,9000);cpu.run(0x61cf);cpu.run(0x2bb2)
                cpu.im[0xb4]=rng.randrange(2 if name=='release_entry' else 9)
                cpu.im[0xb0]=rng.choice([0,1,255]);cpu.im[0xb2]=rng.choice([0,0,1]);word(cpu.im,0xb7,rng.choice([0,1,120]))
                if name=='shift_adaptation':
                    cpu.im[0xb6]=rng.randrange(8);cpu.im[0xaa]=rng.randrange(13)
                    cpu.x[0x39a]=rng.randrange(4);cpu.x[0x32b]=rng.randrange(1,9)
                args=[]
                if types:
                    args=[rng.randrange(65536) if types[0]==U16 else rng.randrange(256)]
                    cpu.wr(6,args[0]>>8);cpu.wr(7,args[0])
                if len(types)>1:
                    args.append(rng.randrange(65536));cpu.wr(4,args[1]>>8);cpu.wr(5,args[1])
                s=state(cpu);cpu.run(entry);got=fn(c.byref(s),*args)
                if fn.restype:assert got==cpu.r(6)*256+cpu.r(7),(name,j,args,got,cpu.r(6)*256+cpu.r(7))
                try:check_memory(cpu,s,IMS,range(1024))
                except AssertionError as e:raise AssertionError((name,j,str(e))) from e
            print(f'PASS: 6000 complete {name} calls',flush=True)
        if selection!=[''] and 'shift_adaptation' not in selection:return
        fn=lib.egs51_shift_adaptation;fn.argtypes=[ptr];fn.restype=None
        commits=0; inhibited=0; unchanged=0
        for shift in range(1,9):
            for delta in (255,0,1):
                cpu=configured();cpu.im[0xb6]=0;cpu.x[0x32b]=shift
                cpu.x[0x16d:0x174]=bytes(7);cpu.x[0x1bf]=0
                s=state(cpu)
                for tick in range(80):
                    # Synthetic completed observations, retained cells across calls.
                    # Exercise delayed writes, byte clamp saturation and zero error.
                    for st in (cpu,s):
                        st.im[0x99]=12;st.x[0x1e4]=delta
                        st.x[0x79]=16 if tick%4==0 else 0
                        st.x[0x1bf]=0
                    before=bytes(s.x[0x16d:0x174])
                    cpu.run(0xaf12);fn(c.byref(s))
                    check_memory(cpu,s,IMS,range(1024))
                    if tick%4==0:
                        assert bytes(s.x[0x16d:0x174])==before and s.im[0x99]&12==12 and s.x[0x1e4]==delta and not s.x[0x1bf]&1
                        inhibited+=1
                    elif delta:
                        assert s.x[0x1bf]&1 and s.x[0x1e4]==0 and s.im[0x99]&12==0
                        commits+=1
                    else:
                        assert bytes(s.x[0x16d:0x174])==before and not s.x[0x1bf]&1
                        unchanged+=1
        assert (commits,inhibited,unchanged)==(960,480,480)
        print('PASS: 1920 persistent adaptation calls: 960 writes, 480 inhibited, 480 zero-error',flush=True)
if __name__=='__main__':main()
