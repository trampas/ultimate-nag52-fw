/* Bank1 2C4F..31AD complete pressure dispatcher and shared workspace handling.
 * This is a native semantic scheduler stage; physical I/O and timing are supplied
 * by the caller. Pressure commands survive the later torque workspace swap. */
#include "egs51_internal.h"
/* 6398..642A */
static void steady_context(Egs51 *s) {
    egs51_shift_feedback_reset(s);
    uint16_t mech=XW(0x3d4); uint8_t gear=I(0xb9);
    I(0x56)=R(mech+0x87+gear);
    IP(0x52,RW(mech+1+12*gear+2*I(0x56)));
    IP(0x4a,RW(mech+0x71+2*I(0x56))); IP(0x4e,egs51_speed_pressure(s,I(0x56)));
    I(0x57)=255; IP(0x54,0); IP(0x4c,0); IP(0x50,0);
    X(0x319)=255; XP(0x33a,0); XP(0x2a1,0); XP(0x231,0);
}
/* 2CA7..2E10 */
static void steady_pressure(Egs51 *s) {
    I(0x95)&=0xf8; I(0xaa)=I(0xb4)=I(0xb5)=0;
    steady_context(s); I(0x95)&=0x87; I(0x96)&=0xf0; I(0x9a)=(I(0x9a)&0xc9)|8;
    IP(0x44,egs51_lag(IW(0x44),egs51_mpc_line(s),I(0xb0)));
    IP(0x46,egs51_lag(IW(0x46),XW(0x273),I(0xb0)));
    IP(0x48,egs51_lag(IW(0x48),XW(0x329),I(0xb0)));
    if(X(0x1c2)&8) IP(0x44,XW(0x329));
    if(I(0xb9)<5) {
        uint8_t idx=R(0xe65b+I(0xb9)),raw=X(0x16d+idx);
        int adapt=raw<128?raw:(int)raw-256;
        uint16_t t=egs51_map8(s,1,XW(0x3c8),idx,X(0x76));
        XP(0x31c,t+R(XW(0x3c6)+0x22)+R(XW(0x3c6)+0x23+idx)+R(XW(0x3ca)+0x23)+R(0xffb0)+adapt);
    } else XP(0x31c,0);
}
void egs51_pressure_tick(Egs51 *s) {
    uint8_t mode=I(0xb6),phase=I(0xaa);
    S(0x98)=0xf7;
    for(unsigned n=0;n<20;++n) I(0x44+n)=X(0x361+n);
    if(!(X(0x1c6)&0x10)) { IP(0x48,0); IP(0x44,750); }
    else {
        egs51_shift_setup(s);
        if(mode==0) { steady_pressure(s); goto outputs; }
        if(mode>=5) {
            if(mode==5 || mode==6) {
                I(0x95)&=0x87;
                if(mode==5) {
                    flag(&I(0x9a),0x20,X(0x334)!=6 && X(0x334)!=8 && !(I(0x9a)&0x10));
                    if(X(0x334)==8) I(0x9a)&=0xeb;
                }
                flag(&I(0x9a),0x80,X(0x76)<R(0xff93)); flag(&I(0x9a),0x40,X(0x76)<R(0xff74));
            }
            if(mode==5) {
                switch(phase) {
                case 0: egs51_garage_select(s); break;
                case 1: egs51_garage_release(s); break;
                case 3: egs51_garage_prefill(s); break;
                case 4: egs51_garage_inhibit(s); break;
                case 5: egs51_engagement(s); break;
                default: break;
                }
            } else if(mode==6) {
                switch(phase) {
                case 0: egs51_engage_prepare(s); break;
                case 1: egs51_engage_control(s); break;
                case 2: egs51_engage_finish(s); break;
                case 3: egs51_engage_abort(s); break;
                case 4: egs51_engage_resolve(s); break;
                default: break;
                }
            } else if(mode==7) egs51_fault_pressure(s);
            goto outputs;
        }
        if(mode==1 || mode==4) {
            uint16_t delta=(uint16_t)(XW(0x1fd)-XW(0x282));
            if(signed16(delta)<0) delta=(uint16_t)(0-delta);
            if(delta>RW(XW(0x3c6)+0x4d)) I(0x98)|=1;
        }
        XP(0x1e6,(I(0x96)&0x80)?RW(XW(0x3c6)+0x3d):0);
        egs51_shift_demand_factor(s);
        flag(&I(0x95),0x20,mode==2 || mode==3);
        flag(&I(0x95),8,mode==1 || mode==2); flag(&I(0x95),0x10,mode==3 || mode==4);
        if(mode==1 || mode==4) {
            XP(0x38c,0);
            switch(phase) {
            case 0: I(0x95)&=0xbf; egs51_release_entry(s); break;
            case 1: egs51_crossover_fill(s); egs51_adapt_fill_observe(s); break;
            case 2: egs51_crossover_transfer(s); egs51_up_torque_enter(s); egs51_adapt_transfer_observe(s); break;
            case 3: egs51_crossover_inertia(s); egs51_up_torque_enter(s); egs51_up_torque_exit(s); egs51_adapt_inertia_observe(s); break;
            case 4: egs51_crossover_match(s); egs51_up_torque_exit(s); break;
            case 5: egs51_shift_finish(s); break;
            case 6: egs51_interrupt_context(s); I(0xaa)=9; break;
            case 7: egs51_interrupt_context(s); ++I(0xaa);
                /* fall through */
            case 8: egs51_interrupt_crossover(s); egs51_up_torque_enter(s); egs51_up_torque_exit(s); break;
            case 9: egs51_interrupt_match(s); break;
            case 10: egs51_interrupt_finish(s); break;
            default: break;
            }
        } else {
            switch(phase) {
            case 0: I(0x95)&=0xbf; egs51_release_entry(s); egs51_down_torque_enter(s); break;
            case 1: egs51_release_apply(s); egs51_release_modulate(s); egs51_down_torque_enter(s); break;
            case 2: egs51_release_transfer(s); egs51_down_torque_exit(s); break;
            case 3: egs51_release_match(s); egs51_down_torque_exit(s); break;
            case 4: egs51_shift_finish(s); egs51_down_torque_exit(s); break;
            case 6: egs51_downshift_handoff(s); egs51_down_torque_exit(s); break;
            case 7: egs51_interrupt_context(s); I(0xaa)=11; break;
            case 8: egs51_interrupt_context(s); egs51_down_torque_exit(s); ++I(0xaa);
                /* fall through */
            case 9: egs51_interrupt_release(s); egs51_down_torque_enter(s); egs51_interrupted_torque_exit(s); break;
            case 10: egs51_interrupt_release_transfer(s); egs51_interrupted_torque_exit(s); break;
            case 11: egs51_interrupt_match(s); egs51_interrupted_torque_exit(s); break;
            case 12: egs51_interrupt_finish(s); egs51_interrupted_torque_exit(s); break;
            default: break;
            }
        }
    }
outputs:
    XP(0x282,XW(0x1fd)); X(0x3a3)=X(0x334);
    I(0x35)=(uint8_t)egs51_pressure_demand(s,IW(0x48));
    I(0x37)=(uint8_t)egs51_pressure_demand(s,IW(0x44));
    for(unsigned n=0;n<20;++n) X(0x361+n)=I(0x44+n);
}
/* Compatibility entry point retains its original checked forward-only contract. */
int egs51_forward_pressure_tick(Egs51 *s) {
    if((X(0x1c6)&0x10) && I(0xb6)>4) return 0;
    egs51_pressure_tick(s); return 1;
}

/* Bank0 6E94..6EA2: five consecutive bank1 stages of the normal scheduler.
 * Caller owns upstream input/supervisor tasks and the timer service. This is
 * not the full normal loop. Outputs are I35/I37 and saved X361..374 pressure,
 * never the live I44 workspace after torque/adaptation have used it. */
void egs51_shift_control_tick(Egs51 *s) {
    egs51_pressure_tick(s);
    egs51_torque_control(s);
    egs51_shift_adaptation(s);
    egs51_pressure_adaptation(s);
    egs51_shift_cell_adaptation(s);
}
