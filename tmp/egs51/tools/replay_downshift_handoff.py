#!/usr/bin/env python3
"""Execute complete OEM phase6 calls and timer service with synthetic speed input.

With --compare-native, independent persistent native state is checked after
every full call against the raw ROM. This is not a vehicle replay. Tick units
remain unassigned. The trajectory stops on return to ordinary phase1.
"""
import argparse
import ctypes as c
import subprocess
import tempfile
import json
from pathlib import Path
import sys
sys.path.insert(0,str(Path(__file__).resolve().parents[1]/'tests'))
from verify_downshift_paths import fixture
from verify_model import ROOT, State, word, state, check_memory


def trajectory(speed_step=30, native=None, through_finish=False, ordinary_gear=None):
    cpu=fixture()
    for address,value in ((0x329,9000),(0x22f,1858),(0x2ac,2250),(0x1fd,200),(0x2b9,2000)):
        word(cpu.x,address,value)
    cpu.x[0x397]=10  # Synthetic torque scale: 2000 * 10 / 100 = 200.
    word(cpu.im,0xad,200)
    if ordinary_gear is not None:
        assert through_finish and 1<=ordinary_gear<=4
        cpu.im[0xa9]=cpu.im[0xb9]=cpu.im[0xb3]=ordinary_gear
        cpu.im[0xac]=ordinary_gear+4
        for a in (0xaa,0xb4,0xb5,0xb2,0x95):cpu.im[a]=0
    native_state=state(cpu) if native else None
    calls={0x61cf:'shift_clutch_context',0x2bb2:'shift_setup',0x236a:'shift_supervisor',
           0x9bf9:'downshift_handoff',0x6bcc:'output_pattern',0xe48d:'timers_tick',
           0x4bc9:'release_apply',0x4fc0:'release_modulate',0x96bb:'release_transfer',
           0x9a6b:'release_match',0x9934:'shift_finish',0x97ec:'release_entry'}
    def run(entry,stop=None):
        cpu.run(entry,stop=stop)
        if native:
            fn=getattr(native,'egs51_'+calls[entry])
            fn.argtypes=[c.POINTER(State)];fn.restype=None
            fn(c.byref(native_state))
            # Exclude compiler/helper scratch, include all persistent state and
            # pressure outputs. Never copy oracle outputs back into native state.
            check_memory(cpu,native_state,list(range(0x44,0x58))+list(range(0xa9,0xba))+
                         [0x21,0x95,0x96,0x98,0x99],range(1024))
    def set_input(address,value):
        word(cpu.x,address,value)
        if native:word(native_state.x,address,value)
    run(0x61cf)
    run(0x2bb2)
    # Synthetic qualification signals; these are NOT reconstructed from a log.
    set_input(0x1d6,100);set_input(0x303,100)
    run(0x236a)
    assert cpu.im[0xaa]==(6 if ordinary_gear is None else 0)
    assert cpu.im[0xb9]==(4 if ordinary_gear is None else ordinary_gear)
    rows=[]
    resumed=ordinary_gear is not None
    for tick in range(200):
        turbine=1858+tick*speed_step
        set_input(0x22f,turbine)
        run(0x236a)
        run(0x2bb2)
        assert cpu.im[0xb6]==3
        # Whole pressure routines and their callees; this is a pressure-schedule
        # harness, not the unported complete dispatcher/torque/adaptation loop.
        phase=cpu.im[0xaa]
        if phase==0 and ordinary_gear is not None:run(0x97ec)
        elif phase==6:run(0x9bf9)
        elif phase==1 and through_finish:
            run(0x4bc9);run(0x4fc0)
        elif phase in (2,3,4) and through_finish:run({2:0x96bb,3:0x9a6b,4:0x9934}[phase])
        else:raise AssertionError(('unexpected pressure phase',phase))
        # Transfer command pattern through the normal output gate in bank0.
        cpu.put(0x88,cpu.direct(0x88)&~16)
        run(0x6bcc,stop=0x6be2)
        rows.append({
            'tick':tick,'synthetic_turbine':turbine,
            'gear':cpu.im[0xb9],'shift_index':cpu.im[0xac],
            'phase':cpu.im[0xaa],'substate':cpu.im[0xb4],
            'mod_substate':cpu.im[0xb5],
            'circuit_commands':cpu.im[0x95]&7,
            'transferred_commands':cpu.im[0x21]&7,
            'mod_pressure_raw':cpu.im[0x44]*256+cpu.im[0x45],
            'clutch_pressure_raw':cpu.im[0x46]*256+cpu.im[0x47],
            'spc_pressure_raw':cpu.im[0x48]*256+cpu.im[0x49],
            'timer':cpu.im[0xb0],'emergency_timer':cpu.im[0xb7]*256+cpu.im[0xb8],
            'fill_credit':cpu.im[0xaf],
        })
        assert rows[-1]['circuit_commands']==rows[-1]['transferred_commands']
        if cpu.im[0xaa]!=6 and not resumed:
            assert cpu.im[0xaa]==1 and cpu.im[0xb9]==3 and cpu.im[0xac]==7
            assert cpu.im[0xb5]==3 and cpu.im[0x95]&7==4
            resumed=True
            if not through_finish:return rows
        if through_finish and cpu.im[0xb6]==0:
            assert resumed and cpu.im[0xaa]==0 and cpu.im[0x95]&7==0
            assert cpu.im[0xb9]==(3 if ordinary_gear is None else ordinary_gear)
            return rows
        run(0xe48d)
        cpu.put(0x88,cpu.direct(0x88)|16)
    raise AssertionError('synthetic trajectory failed to finish its requested boundary within 200 raw ticks')


def main():
    ap=argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--speed-step',type=int,default=30,help='synthetic turbine rise per raw tick; 0 tests timeout route')
    ap.add_argument('--compare-native',action='store_true',help='build native C and compare independent persistent state after every call')
    ap.add_argument('--through-finish',action='store_true',help='continue pressure phases1..4 through circuit release; excludes full dispatcher and torque production')
    ap.add_argument('--ordinary-gear',type=int,choices=range(1,5),help='start ordinary loaded downshift to this gear; requires --through-finish')
    args=ap.parse_args()
    if args.ordinary_gear is not None and not args.through_finish:ap.error('--ordinary-gear requires --through-finish')
    if args.speed_step<0 or args.speed_step>100:
        ap.error('--speed-step must be between 0 and 100')
    with tempfile.TemporaryDirectory(prefix='egs51-trajectory-') as td:
        native=None
        if args.compare_native:
            so=Path(td)/'model.so'
            subprocess.run(['cc','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-shared','-fPIC',
                            *map(str,sorted((ROOT/'reconstructed').glob('egs51_*.c'))),'-o',str(so)],check=True)
            native=c.CDLL(str(so))
        print(json.dumps({'source':'raw ROM, synthetic state', 'native_compared':bool(native),
                          'time_unit':'OEM timer-service calls',
                          'through_finish':args.through_finish,
                          'rows':trajectory(args.speed_step,native,args.through_finish,args.ordinary_gear)},indent=2))
if __name__=='__main__':main()
