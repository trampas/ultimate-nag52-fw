#!/usr/bin/env python3
"""Complete pressure dispatcher and ordered shift-control stages versus ROM."""
import ctypes as c
from pathlib import Path
import random
import subprocess
import tempfile
from verify_model import ROOT, State, state, word, check_memory
from verify_handoff import configured
from verify_shift_pressure import IMS

def main():
    rng=random.Random(0x2c4f)
    with tempfile.TemporaryDirectory(prefix='egs51-dispatch-') as td:
        so=Path(td)/'model.so'
        subprocess.run(['cc','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-shared','-fPIC',
                        *map(str,sorted((ROOT/'reconstructed').glob('egs51_*.c'))),'-o',str(so)],check=True)
        lib=c.CDLL(str(so));fn=lib.egs51_pressure_tick;fn.argtypes=[c.POINTER(State)];fn.restype=None
        import os
        selection=os.environ.get('EGS51_MODES','').split(',')
        for mode in range(8):
            if selection!=[''] and str(mode) not in selection:continue
            phases=list(range(11)) if mode in (1,4) else list(range(14))
            for j in range(2200):
                cpu=configured()
                if mode==6:
                    cpu.x[0x17b]&=0xfe;cpu.run(0x20bc)
                cpu.im[0xb6]=mode
                if mode in (0,5,6,7):cpu.im[0xb9]=rng.randrange(1,8)
                cpu.x[0x32e]=rng.randrange(31);word(cpu.x,0x181,rng.randrange(1,65536))
                cpu.im[0x96]&=~0x20;word(cpu.x,0x329,9000)
                if mode<=4:cpu.run(0x61cf)
                else:cpu.im[0xac]=rng.choice([1,3]);cpu.im[0x56]=rng.choice([1,4,5])
                cpu.run(0x2bb2)
                cpu.im[0xaa]=phases[j%len(phases)];cpu.im[0xb4]=rng.randrange(2) if cpu.im[0xaa]==0 else rng.randrange(7)
                cpu.im[0xb0]=rng.choice([0,1,255]);cpu.im[0xb1]=rng.choice([0,1,255]);cpu.im[0xb2]=rng.choice([0,1])
                word(cpu.im,0xb7,rng.choice([0,1,120]));cpu.im[0x97]=rng.randrange(256)
                # Valid persisted pressure context, distinct live scratch values.
                cpu.x[0x361:0x375]=cpu.im[0x44:0x58]
                cpu.im[0x44:0x58]=rng.randbytes(20)
                cpu.x[0x1c6]|=16
                if j%19==0:cpu.x[0x1c6]&=~16
                s=state(cpu)
                try:
                    cpu.run(0x2c4f);fn(c.byref(s))
                    check_memory(cpu,s,IMS+[0x35,0x37,0x94,0x97,0x9a,0xa9],range(1024))
                    assert s.sfr[0x18]==cpu.direct(0x98)
                except Exception as e:raise AssertionError((mode,j,phases[j%len(phases)],str(e))) from e
            print(f'PASS: 2200 full pressure dispatcher calls, mode {mode}',flush=True)
        checked=lib.egs51_forward_pressure_tick;checked.argtypes=[c.POINTER(State)];checked.restype=c.c_int
        for mode in range(8):
            for phase in range(14):
                if mode<=4:continue
                cpu=configured()
                if mode==6:
                    cpu.x[0x17b]&=0xfe;cpu.run(0x20bc)
                cpu.im[0xb6]=mode;cpu.im[0xaa]=phase;cpu.x[0x1c6]|=16
                s=state(cpu);before=bytes(s)
                assert checked(c.byref(s))==0 and bytes(s)==before,(mode,phase)
        print('PASS: unsupported dispatcher states rejected without mutation',flush=True)
        from verify_model import base
        for name in ('torque_control','shift_adaptation','pressure_adaptation','shift_cell_adaptation','timers_tick'):
            f=getattr(lib,'egs51_'+name);f.argtypes=[c.POINTER(State)];f.restype=None
        batch=lib.egs51_shift_control_tick;batch.argtypes=[c.POINTER(State)];batch.restype=None
        checks=0
        for mode in (1,2,3,4):
            cpu=base();cpu.x[0x17b]=0x20;cpu.x[0x17c]=0x22;cpu.run(0x20bc)
            cpu.im[0xb6]=mode;cpu.im[0xb9]=3;cpu.im[0xb3]=3;cpu.im[0xa9]=3
            cpu.x[0x76]=60;cpu.x[0x202]=10;cpu.x[0x397]=100;cpu.x[0x32e]=10;cpu.x[0x1c6]=16
            for a,v in ((0x329,9000),(0x22f,1500),(0x1fd,200),(0x2b9,200),(0x2ac,1000),(0x181,1000),(0x347,600)):
                word(cpu.x,a,v)
            word(cpu.im,0xad,200);cpu.run(0x61cf);cpu.run(0x2bb2)
            cpu.x[0x361:0x375]=cpu.im[0x44:0x58];native=state(cpu)
            for tick in range(120):
                # Forced phase schedule tests workspace ownership across successive
                # scheduler calls. It is not a physical shift/gear-selection replay.
                for st in (cpu,native):
                    st.im[0xb6]=mode;st.im[0xaa]=(tick//20)%5;st.im[0xb4]=0 if tick%20==0 else st.im[0xb4]
                    word(st.x,0x22f,1500+tick);word(st.x,0x357,(200-tick*3)&65535)
                batched=State.from_buffer_copy(native)
                cpu.run(0x2c4f);fn(c.byref(native))
                check_memory(cpu,native,IMS+[0x35,0x37,0x94,0x97,0x9a,0xa9],range(1024));checks+=1
                saved=bytes(native.x[0x361:0x375])
                for entry,name in ((0xce9f,'torque_control'),(0xaf12,'shift_adaptation'),(0xd9c8,'pressure_adaptation'),(0xb708,'shift_cell_adaptation')):
                    cpu.run(entry);getattr(lib,'egs51_'+name)(c.byref(native))
                    check_memory(cpu,native,IMS+[0x35,0x37,0x94,0x97,0x9a,0xa9],range(1024));checks+=1
                    assert bytes(native.x[0x361:0x375])==saved
                batch(c.byref(batched))
                check_memory(cpu,batched,IMS+[0x35,0x37,0x94,0x97,0x9a,0xa9],range(1024))
                assert bytes(batched)==bytes(native)
                cpu.put(0x88,cpu.direct(0x88)&~16);cpu.run(0xe48d);lib.egs51_timers_tick(c.byref(native))
                check_memory(cpu,native,IMS+[0x35,0x37,0x94,0x97,0x9a,0xa9],range(1024));checks+=1
                cpu.put(0x88,cpu.direct(0x88)|16)
        print(f'PASS: {checks} persistent pressure/torque/adaptation/timer calls; saved pressure workspace retained',flush=True)
        # Persistent complete mode6 engagements, with synthetic falling turbine
        # speed at zero output speed. Raw ticks are not assigned physical units.
        completed=0;checks=0
        for gear in (1,2,3,6,7):
            for temperature in (40,90):
                cpu=base();cpu.x[0x17b]=0x20;cpu.x[0x17c]=0x22;cpu.run(0x20bc)
                cpu.im[0xb6]=6;cpu.im[0xb9]=cpu.im[0xb3]=gear;cpu.im[0xac]=1
                cpu.im[0x56]=4;cpu.im[0x57]=255;cpu.x[0x334]=7 if gear>=6 else 2
                cpu.x[0x76]=temperature;cpu.x[0x1c6]=16;cpu.x[0x397]=100;cpu.x[0x32e]=10
                for a,v in ((0x329,9000),(0x275,1000),(0x22f,1000),(0x2b9,40),(0x1fd,40)):
                    word(cpu.x,a,v)
                word(cpu.im,0xad,40);cpu.run(0x2bb2);cpu.x[0x361:0x375]=cpu.im[0x44:0x58]
                native=state(cpu)
                for tick in range(600):
                    turbine=max(0,1000-tick*10)
                    for st in (cpu,native):word(st.x,0x22f,turbine)
                    cpu.run(0x2c4f);fn(c.byref(native))
                    check_memory(cpu,native,IMS+[0x35,0x37,0x94,0x97,0x9a,0xa9],range(1024));checks+=1
                    for entry,name in ((0xce9f,'torque_control'),(0xaf12,'shift_adaptation'),(0xd9c8,'pressure_adaptation'),(0xb708,'shift_cell_adaptation')):
                        cpu.run(entry);getattr(lib,'egs51_'+name)(c.byref(native))
                        check_memory(cpu,native,IMS+[0x35,0x37,0x94,0x97,0x9a,0xa9],range(1024));checks+=1
                    cpu.put(0x88,cpu.direct(0x88)&~16);cpu.run(0xe48d);lib.egs51_timers_tick(c.byref(native))
                    check_memory(cpu,native,IMS+[0x35,0x37,0x94,0x97,0x9a,0xa9],range(1024));checks+=1
                    cpu.put(0x88,cpu.direct(0x88)|16)
                    if native.im[0xb6]==0:
                        assert not native.im[0x95]&7;completed+=1;break
                else:raise AssertionError(('engagement did not finish',gear,temperature,native.im[0xaa],native.im[0xb4]))
        assert completed==10
        print(f'PASS: ten synthetic mode6 engagements through completion, {checks} persistent stage/timer calls',flush=True)
if __name__=='__main__':main()
