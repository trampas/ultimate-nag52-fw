#!/usr/bin/env python3
"""Bank1 line-pressure scheduler and complete shift setup versus raw ROM."""
import ctypes as c
from pathlib import Path
import random
import subprocess
import tempfile
from verify_model import ROOT, State, state, word, check_memory, U8, U16
from verify_shift import configured
rng=random.Random(0x5480)
def main():
    with tempfile.TemporaryDirectory(prefix='egs51-line-') as td:
        so=Path(td)/'model.so'
        subprocess.run(['cc','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-shared','-fPIC',
                        *map(str,sorted((ROOT/'reconstructed').glob('egs51_*.c'))),'-o',str(so)],check=True)
        lib=c.CDLL(str(so))
        for name,entry,count in [('mpc_line',0x5480,12000),('speed_pressure',0x43c5,6000),('shift_gain',0x6a50,1024),('shift_setup',0x2bb2,6000)]:
            fn=getattr(lib,'egs51_'+name); fn.argtypes=[c.POINTER(State)]+([U8] if name=='speed_pressure' else [])
            fn.restype=U16 if name in ('mpc_line','speed_pressure') else None; visited=set()
            for j in range(count):
                cpu=configured(); cpu.im[0xb9]=j%9
                for a in (0x44,0x4a,0x52,0xad): word(cpu.im,a,rng.randrange(65536))
                for a in (0x22f,0x1ea,0x329): word(cpu.x,a,rng.choice([0,1,32767,32768,32769,65535,rng.randrange(65536)]))
                cpu.im[0x56]=j%4; cpu.im[0x57]=(j//4)%4; cpu.im[0x98]=rng.randrange(256)
                cpu.x[0x76]=j%256; word(cpu.x,0x2df,rng.choice([0,1,50,30000,65535]))
                if name=='mpc_line' and j%3==0:
                    cpu.im[0xb9]=0; word(cpu.im,0x44,rng.choice([0,499,500,501]))
                    cpu.x[0x76]=rng.choice([74,75,76,255])
                if name=='shift_gain': cpu.im[0xb6]=1 if j%2 else 0; cpu.im[0xac]=1 if j%4<2 else 2
                # Concentrate on both arithmetic branches while retaining an
                # exhaustive sweep of ignored selector values at the end.
                selector=j%4 if j<count-256 else j-(count-256)
                cpu.wr(7,selector); s=state(cpu); cpu.run(entry); visited.update(cpu.visited)
                value=fn(c.byref(s),selector) if name=='speed_pressure' else fn(c.byref(s))
                if name in ('mpc_line','speed_pressure'): assert value==cpu.r(6)*256+cpu.r(7),(name,j,value,cpu.r(6)*256+cpu.r(7))
                ims=[0x98] if name=='mpc_line' else range(0x4e,0x52) if name=='shift_setup' else []
                check_memory(cpu,s,ims,range(1024))
            print(f'PASS: {count} complete {name} calls; {len(visited)} instruction PCs including callees')
if __name__=='__main__': main()
