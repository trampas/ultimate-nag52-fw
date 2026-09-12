#!/usr/bin/env python3
"""Mode6 engagement routines against unhooked bank1 instructions."""
import ctypes as c
from pathlib import Path
import random, subprocess, tempfile, os
from verify_model import ROOT, State, U8, U16, state, word, check_memory
from verify_handoff import configured
from verify_shift_pressure import IMS

def main():
    rng=random.Random(0x37cc)
    with tempfile.TemporaryDirectory(prefix='egs51-engage-') as td:
        so=Path(td)/'model.so'
        subprocess.run(['cc','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-shared','-fPIC',*map(str,sorted((ROOT/'reconstructed').glob('egs51_*.c'))),'-o',str(so)],check=True)
        lib=c.CDLL(str(so));ptr=c.POINTER(State)
        routines=[('engage_timeout',0x31ae,[],U16),('engage_torque_pressure',0x31ee,[U16],U16),
                  ('engage_momentum',0x323d,[],None),('engage_match',0x33d6,[U8]*4,U8),
                  ('engage_recover',0x3545,[],None),('engage_prepare',0x3646,[],None),
                  ('engage_finish',0x423b,[],None),('engage_abort',0x42be,[],None),('engage_resolve',0x4311,[],None),('engage_control',0x37cc,[],None)]
        selection=os.environ.get('EGS51_ROUTINES','').split(',')
        for name,entry,types,ret in routines:
            if selection!=[''] and name not in selection:continue
            fn=getattr(lib,'egs51_'+name);fn.argtypes=[ptr]+types;fn.restype=ret
            for j in range(6000):
                cpu=configured()
                # Mode6's 37CC uses descriptor+2F as a divisor. The alternate
                # coding branch has zero here; its MDU-zero behavior is unknown.
                if name=='engage_control':
                    cpu.x[0x17b]&=0xfe;cpu.run(0x20bc)
                cpu.im[0xb6]=6;cpu.im[0xb9]=rng.randrange(1,8);cpu.im[0xac]=rng.choice([1,3])
                cpu.x[0x32e]=rng.randrange(31);word(cpu.x,0x329,9000);cpu.run(0x2bb2)
                for a in (0x94,0x97,0x9a):cpu.im[a]=rng.randrange(256)
                cpu.im[0xb4]=rng.randrange(11);cpu.im[0xb0]=rng.choice([0,1,255]);cpu.im[0xb1]=rng.choice([0,1,255]);word(cpu.im,0xb7,rng.choice([0,1,120]))
                cpu.x[0x334]=rng.randrange(9);cpu.x[0x2ec]=rng.choice([0,0x58,255,rng.randrange(9)])
                args=[rng.randrange(65536) if t==U16 else rng.choice([0,1,255,rng.randrange(256)]) for t in types]
                for n,v in enumerate(args):
                    if n==3:cpu.im[0x6c]=v
                    elif types[n]==U16:cpu.wr(6-2*n,v>>8);cpu.wr(7-2*n,v)
                    else:cpu.wr(7-2*n,v)
                s=state(cpu)
                try:
                    cpu.run(entry);got=fn(c.byref(s),*args)
                    if ret:assert got==(cpu.r(7) if ret==U8 else cpu.r(6)*256+cpu.r(7))
                    check_memory(cpu,s,IMS+[0x94,0x97,0x9a,0xa9],range(1024))
                except Exception as e:raise AssertionError((name,j,args,str(e))) from e
            print(f'PASS: 6000 complete {name} calls',flush=True)
if __name__=='__main__':main()
