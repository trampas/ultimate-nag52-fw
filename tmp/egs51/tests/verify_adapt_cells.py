#!/usr/bin/env python3
"""Original-ROM parity for B2C8, B3B1 and B415 adaptation cell helpers."""
import ctypes as c
from pathlib import Path
import random
import subprocess
import tempfile
from verify_model import ROOT, State, U8, U16, state, word, check_memory
from verify_handoff import configured

def main():
    rng=random.Random(0xb415)
    with tempfile.TemporaryDirectory(prefix='egs51-adapt-cells-') as td:
        so=Path(td)/'model.so'
        subprocess.run(['cc','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-shared','-fPIC',
                        *map(str,sorted((ROOT/'reconstructed').glob('egs51_*.c'))),'-o',str(so)],check=True)
        lib=c.CDLL(str(so));ptr=c.POINTER(State)
        for name,entry,types in [('adapt_weights',0xb2c8,[U16]*4),('adapt_limit',0xb3b1,[U16]),('adapt_cells',0xb415,[U16,U8])]:
            fn=getattr(lib,'egs51_'+name);fn.argtypes=[ptr]+types;fn.restype=U8 if name=='adapt_limit' else None
            for j in range(8000):
                cpu=configured();word(cpu.x,0x305,0x127+rng.randrange(50))
                args=[rng.randrange(65536)]
                cpu.wr(6,args[0]>>8);cpu.wr(7,args[0])
                if name=='adapt_weights':
                    args.extend(rng.randrange(65536) for _ in range(3))
                    # Equal limits with midpoint overflow can hit OEM zero-divisor;
                    # cover equal limits without overflow as well as arbitrary unequal limits.
                    if j%8==0:args[2]=args[3]=rng.randrange(16000)
                    elif args[2]==args[3]:args[3]^=1
                    cpu.wr(4,args[1]>>8);cpu.wr(5,args[1]);cpu.wr(2,args[2]>>8);cpu.wr(3,args[2]);word(cpu.im,0x68,args[3])
                elif name=='adapt_cells':args.append(rng.randrange(4));cpu.wr(5,args[1])
                s=state(cpu);cpu.run(entry);value=fn(c.byref(s),*args)
                if fn.restype:assert value==cpu.r(7),(name,j,args,value,cpu.r(7))
                try:check_memory(cpu,s,range(0x95,0xc0),range(1024))
                except AssertionError as e:raise AssertionError((name,j,args,str(e))) from e
            print(f'PASS: 8000 complete {name} calls',flush=True)
if __name__=='__main__':main()
