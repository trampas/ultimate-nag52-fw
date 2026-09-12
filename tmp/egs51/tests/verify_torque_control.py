#!/usr/bin/env python3
"""Complete CE9F torque-demand controller versus unhooked ROM instructions."""
import ctypes as c
from pathlib import Path
import random
import subprocess
import tempfile
from verify_model import ROOT, State, state, word, check_memory
from verify_handoff import configured
from verify_shift_pressure import IMS

def main():
    rng=random.Random(0xcad7)
    with tempfile.TemporaryDirectory(prefix='egs51-torque-') as td:
        so=Path(td)/'model.so'
        subprocess.run(['cc','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-shared','-fPIC',
                        *map(str,sorted((ROOT/'reconstructed').glob('egs51_*.c'))),'-o',str(so)],check=True)
        lib=c.CDLL(str(so))
        for name,entry in [('torque_control',0xce9f)]:
            fn=getattr(lib,'egs51_'+name); fn.argtypes=[c.POINTER(State)]; fn.restype=None
            changes=0
            for j in range(20000):
                cpu=configured();cpu.x[0x32e]=rng.randrange(31);cpu.x[0x2ab]=rng.randrange(1,256)
                cpu.im[0xb6]=rng.choice([0,1,1,1,2,3,3,3,4,5,6,7,255])
                cpu.x[0x2fc]=rng.randrange(8);cpu.x[0x2f4]=rng.choice([0,1,255]);cpu.im[0xb5]=rng.randrange(7)
                cpu.im[0xac]=rng.randrange(1,5) if cpu.im[0xb6]==1 else rng.randrange(5,9)
                cpu.im[0xaa]=rng.randrange(14);cpu.im[0xb4]=rng.randrange(5)
                cpu.im[0x97]=rng.randrange(256);cpu.im[0x96]=rng.choice([0,0,0,rng.randrange(256)])
                word(cpu.im,0xad,rng.choice([0,1,50,100,200,1000,65535]))
                word(cpu.x,0x2b9,rng.choice([0,1,32767,32768,65535]))
                initial=state(cpu);s=state(cpu);before=cpu.im[0x97];cpu.run(entry);fn(c.byref(s));changes+=before!=cpu.im[0x97]
                try:check_memory(cpu,s,IMS+[0x97],range(1024))
                except AssertionError as e:
                    import json
                    Path('/tmp/egs51_torque_failure.json').write_text(json.dumps({'im':list(initial.im),'x':list(initial.x),'sfr':list(initial.sfr)}))
                    raise AssertionError((name,j,str(e))) from e
            assert changes>10,(name,changes)
            print(f'PASS: 20000 complete {name} calls, {changes} latch changes',flush=True)
        # Independent persistent state: compare after every controller/timer call.
        # Only the common external latch events are supplied to both machines.
        from verify_model import base
        for mode in (1,3):
            for coding in (0,16,32):
                cpu=base();cpu.x[0x17b]=coding;cpu.x[0x17c]=0x22;cpu.run(0x20bc)
                cpu.im[0xb6]=mode;cpu.im[0xac]=2 if mode==1 else 7;cpu.im[0xb5]=2
                word(cpu.im,0xad,200);word(cpu.x,0x2b9,200);word(cpu.x,0x347,600)
                word(cpu.x,0x357,65535);word(cpu.x,0x2ac,1000)
                word(cpu.x,0x303,100);word(cpu.x,0x1d6,100)
                cpu.x[0x397]=100;cpu.x[0x32e]=10
                native=state(cpu);seen=set()
                for tick in range(80):
                    if tick in (1,20):
                        cpu.im[0x97]=(cpu.im[0x97]&254)|(tick==1)
                        native.im[0x97]=(native.im[0x97]&254)|(tick==1)
                    seen.add(cpu.x[0x2fc]);cpu.run(0xce9f);lib.egs51_torque_control(c.byref(native))
                    check_memory(cpu,native,IMS+[0x97],range(1024))
                    cpu.put(0x88,cpu.direct(0x88)&~16);cpu.run(0xe48d)
                    lib.egs51_timers_tick(c.byref(native))
                    check_memory(cpu,native,IMS+[0x97],range(1024))
                    cpu.put(0x88,cpu.direct(0x88)|16)
                assert seen==({0,1,2} if mode==1 else {0,1,2,3,4,5}),(mode,coding,seen)
                assert cpu.x[0x2fc]==0 and not(cpu.im[0x97]&1),(mode,coding)
        print('PASS: six persistent torque reduction/recovery schedules, 480 controller/timer pairs',flush=True)
if __name__=='__main__':main()
