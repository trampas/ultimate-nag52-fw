#!/usr/bin/env python3
"""Full native pressure calls versus original instructions; no hooked callees."""
import ctypes as c
from pathlib import Path
import random
import subprocess
import tempfile
from verify_model import ROOT, State, U8, U16, base, state, word, check_memory
from verify_handoff import configured

rng=random.Random(0xc144)
IMS=list(range(0x44,0x58))+list(range(0xaa,0xba))+[0x95,0x96,0x98,0x99]

def main():
    with tempfile.TemporaryDirectory(prefix='egs51-pressure-') as td:
        so=Path(td)/'model.so'
        subprocess.run(['cc','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-shared','-fPIC',
                        *map(str,sorted((ROOT/'reconstructed').glob('egs51_*.c'))),'-o',str(so)],check=True)
        lib=c.CDLL(str(so));ptr=c.POINTER(State)
        def bind(name,args,ret):
            fn=getattr(lib,'egs51_'+name);fn.argtypes=args;fn.restype=ret;return fn
        for name,entry,nargs in [('signed_md',0xc20,3),('signed_lerp',0xc0d3,5)]:
            fn=bind(name,[U16]*nargs,U16)
            for j in range(6000):
                cpu=base(); args=[rng.randrange(65536) for _ in range(nargs)]
                if nargs==3 and args[2]==0:args[2]=1
                for reg,v in zip([6,4,2],args):cpu.wr(reg,v>>8);cpu.wr(reg+1,v)
                if nargs==5:word(cpu.im,0x72,args[3]);word(cpu.im,0x74,args[4])
                cpu.run(entry);got=fn(*args);expected=cpu.r(6)*256+cpu.r(7)
                assert got==expected,(name,j,args,got,expected)
            print(f'PASS: 6000 {name}',flush=True)
        routines=[('overlap_pressure',0x6fee,3),('shift_mod_pressure',0x74c8,1),
                  ('shift_signed_mod_pressure',0x7561,1),('shift_net_torque',0x75fd,0),
                  ('handoff_mod_pressure',0x762f,1),('gear_sync_speed',0xd9a0,1),
                  ('shift_fill_torque',0x6b7a,-1),('shift_pressure_compensation',0xc144,-1),
                  ('downshift_handoff',0x9bf9,-1),('release_apply',0x4bc9,-1)]
        for name,entry,nargs in routines:
            fn=bind(name,[ptr]+([U8]+[U16]*(nargs-1) if nargs>0 else []),None if nargs<0 else U16)
            for j in range(4000):
                cpu=configured();cpu.x[0x2ab]=rng.randrange(1,256)
                # Keep adaptation/map indices within actual forward shift cells.
                if cpu.im[0xb6]<=2:cpu.im[0xac]=rng.randrange(1,5)
                else:cpu.im[0xac]=rng.randrange(5,9)
                if name=='downshift_handoff':
                    cpu.im[0xb6]=3;cpu.im[0xac]=cpu.im[0xb9]+4
                    cpu.im[0xb4]=rng.randrange(5)
                    cpu.im[0xb0]=rng.choice([0,1,2,255]);cpu.im[0xb1]=rng.choice([0,1,255])
                    cpu.im[0xaf]=rng.randrange(256);word(cpu.im,0xb7,rng.choice([0,1,120]))
                    # Correct applying clutch selector, coefficient pointers and gain.
                    cpu.run(0x61cf);cpu.run(0x2bb2)
                if name=='release_apply':
                    cpu.x[0x32e]=rng.randrange(31)
                    cpu.im[0xb6]=rng.choice([2,3]);cpu.im[0xb4]=rng.randrange(9)
                    cpu.im[0xb0]=rng.choice([0,1,255])
                    cpu.run(0x61cf);cpu.run(0x2bb2)
                args=[]
                if nargs>0:
                    args=[rng.randrange(1,6) if name=='gear_sync_speed' else rng.randrange(8)]
                    cpu.wr(7,args[0])
                if nargs==3:
                    args += [rng.randrange(65536),rng.randrange(65536)]
                    for reg,v in zip([4,2],args[1:]):cpu.wr(reg,v>>8);cpu.wr(reg+1,v)
                s=state(cpu);cpu.run(entry);got=fn(c.byref(s),*args)
                if nargs>=0:
                    expected=cpu.r(6)*256+cpu.r(7)
                    assert got==expected,(name,j,args,got,expected)
                try:check_memory(cpu,s,IMS,range(1024))
                except AssertionError as e:raise AssertionError((name,j,str(e))) from e
            print(f'PASS: 4000 complete {name} calls',flush=True)
        import sys
        sys.path.insert(0,str(ROOT/'tools'))
        from replay_downshift_handoff import trajectory
        total=0
        for speed_step in range(101):total+=len(trajectory(speed_step,lib))
        print(f'PASS: 101 independent persistent trajectories, {total} complete handler invocations',flush=True)
        print('PASS: 52000 raw-ROM snapshots plus persistent trajectories including every handoff callee')
if __name__=='__main__':main()
