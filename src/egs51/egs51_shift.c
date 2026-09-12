/* Shift supervisor and its transition helpers. B6 is mode; AA is phase;
 * B4/B5 are substates. A9/B9/B3 retain address names where gear semantics are
 * not yet proven from all producers. Ranges below are bank1. */
#include "egs51_internal.h"
static void reset_phase(Egs51 *s) { I(0xaa)=I(0xb4)=I(0xb5)=0; } /* 1FE2 */
static void reset_timers(Egs51 *s) { I(0xb0)=I(0xb1)=I(0xb7)=I(0xb8)=0; } /* 0BF3 */
void egs51_gear_reset(Egs51 *s) { reset_phase(s); reset_timers(s); egs51_gear_map(s); }
/* 642B: mechanical byte at mech+7D+index, plus a slip-dependent byte term. */
uint8_t egs51_shift_factor(Egs51 *s) {
    uint8_t idx=(uint8_t)(I(0xac)-1),base=R(XW(0x3d4)+0x7d+idx);
    uint16_t threshold;
    if(I(0xb6)==3 || I(0xb6)==6) {
        threshold=I(0xb6)==3?md(1000,1000,RW(0x1050+2*idx)):md(1000,XW(0x2c9),XW(0x2b1));
        if(XW(0x398)<=threshold) X(0x2b3)=base;
        else if(XW(0x398)>=1000) X(0x2b3)=(uint8_t)(base+X(0x32e));
        else X(0x2b3)=(uint8_t)(base+md(X(0x32e),(uint16_t)(XW(0x398)-threshold),(uint16_t)(1000-threshold)));
    } else X(0x2b3)=(uint8_t)(base+X(0x32e));
    return X(0x2b3);
}
/* 6633..6783, R7=index, R5=byte parameter. Keeps each 16-bit truncation. */
uint16_t egs51_shift_threshold(Egs51 *s,uint8_t idx,uint8_t parameter) {
    uint16_t p,cal=XW(0x3ca);
    if(!(I(0x96)&0x40)) {
        uint16_t mean=(uint16_t)(XW(0x1d6)+XW(0x303)); mean>>=1;
        if(XW(0x303)<mean) mean=XW(0x303);
        p=(uint16_t)(10*(uint16_t)(XW(0x1d6)+mean));
        p=md(p,(uint16_t)(2*R(cal+0x1e)+parameter),egs51_shift_factor(s));
        p=md(p,R(0xfff7+idx),10);
        if(p<RW(cal+0x20)) p=RW(cal+0x20);
    } else p=RW(cal+((I(0x96)&0x80)?0x3e:0x20));
    return p<32767?p:32767;
}
/* 1DD0 and 1DF3: signed threshold decisions select modes 1/2 or 3/4. */
static uint8_t up_mode(Egs51 *s,uint16_t threshold) {
    return signed16(XW(0x2b9))<signed16((uint16_t)(0-threshold))?2:1;
}
static uint8_t down_mode(Egs51 *s,uint16_t first,uint16_t second) {
    uint16_t t=I(0xb9)>=X(0x334)?second:first;
    return ((signed16(XW(0x2b9))>signed16(t) || (I(0x96)&0x40)) && !(I(0x96)&0x20))?3:4;
}
void egs51_mode_transition(Egs51 *s,uint8_t mode,uint8_t variant) {
    uint8_t phase=I(0xaa); I(0x96)|=8;
    if(!phase) { I(0xaa)=0; I(0xb6)=mode; return; }
    if(!variant) { /* 1E36 */
        if(phase<=1 && (mode==3 || (mode==2 && I(0xb4)<=2))) {
            I(0xaa)=1; I(0xb6)=mode; I(0xb5)=I(0xb1)=0; return;
        }
        if(phase<=3 && mode==3) {
            I(0xaa)=1; I(0xb6)=mode; I(0xb4)=3; I(0xb5)=1; I(0xb0)=I(0xb1)=0; return;
        }
    } else if(phase<=1) { /* 1E9D */
        I(0xaa)=1; I(0xb6)=mode; I(0xb5)=I(0xb1)=0;
        if(I(0xb4)>3) { I(0xaa)=2; I(0xb4)=I(0xb0)=0; }
        return;
    }
    I(0x96)&=0xf7;
}
/* 1EEB..1FE1. Latches direction-related bits and adjusts B7:B8. */
void egs51_shift_direction(Egs51 *s) {
    uint8_t desired=I(0xa9),current=I(0xb9);
    if((I(0xb6)==0 && desired==current) || I(0xb6)==6 ||
       (X(0x1bc)&4) || desired>current || (I(0x95)&8) || desired>=X(0x334)) I(0x96)&=0x9f;
    else if(X(0x285)<R(XW(0x3ca)+0x31) && !(I(0x96)&0x60)) {
        if(desired==3 || desired==4) I(0x96)=(I(0x96)&0xbf)|0x20;
        else {
            I(0x96)=(I(0x96)|0x40)&0xdf;
            IP(0xb7,(uint16_t)(RW(0xffb7)-(uint16_t)(RW(0xffb5)-IW(0xb7))));
        }
    }
    flag(&I(0x96),0x80,(I(0x96)&0x40) && (I(0xac)==5 || I(0xac)==6));
}
static void new_up(Egs51 *s,uint8_t mode,int interrupted) {
    if(interrupted) I(0x96)|=4;
    ++I(0xb9); I(0xb3)=I(0xb9); I(0xac)=(uint8_t)(I(0xb9)-1); I(0xb6)=mode;
    if(interrupted) X(0x2fc)=0;
}
static void new_down(Egs51 *s,uint8_t mode,int interrupted) {
    if(interrupted) I(0x96)|=4;
    --I(0xb9); I(0xb3)=I(0xb9); I(0xac)=(uint8_t)(I(0xb9)+4); I(0xb6)=mode;
    if(interrupted) X(0x2fc)=0;
}
/* 236A..2BB1. Complete supervisor including its helper effects. It chooses
 * shift mode/phase; execution of pressure phase routines is a separate task. */
void egs51_shift_supervisor(Egs51 *s) {
    S(0x98)=4;
    if(X(0x78)&2) { I(0xb6)=0; egs51_gear_reset(s); return; }
    uint8_t mode,decision,phase,features;
    uint16_t cal=XW(0x3ca),tcc=XW(0x3c4);
    if((I(0x96)&5) && (!(I(0x96)&4) || I(0xa9)!=0 || !(X(0x1bd)&1))) goto tail;
    /* 2344 */
    flag(&I(0x98),0x20,I(0xb9)>=X(0x334) && (I(0x95)&0x10));
    egs51_shift_direction(s);
    if(I(0xa9)==0 || (X(0x334)==7 && I(0xb9)>=1 && I(0xb9)<=5)) {
        mode=I(0xb6);
        if(mode==5) goto finish_modes;
        if(mode!=0 && mode!=6 && mode!=7) egs51_shift_solenoid_select(s);
        flag(&I(0x94),0x40,(mode==0 && (I(0xb9)==4 || I(0xb9)==5)) ||
             (mode!=0 && mode!=6 && mode!=7 && (I(0xac)==8 || I(0xac)==7 || I(0xac)==4)));
        reset_phase(s); reset_timers(s); I(0x9a)&=0xf7; I(0xb6)=5; I(0xb9)=0;
        if(!I(0xac)) I(0xac)=5;
        goto finish_modes;
    }
    if(I(0xb9)==0 || (I(0x9a)&0x10)) {
        if(I(0xb6)==6 || !(I(0x9a)&8)) goto finish_modes;
        reset_phase(s); reset_timers(s); I(0xb6)=6;
        I(0xb9)=(I(0xa9)==3 || (I(0x94)&1))?4:I(0xa9);
        I(0x94)&=0xfe; I(0xb3)=I(0xb9); goto finish_modes;
    }
    if(I(0xb9)==6 || I(0xb9)==7) goto finish_modes;
    X(0x223)=I(0xb9); mode=I(0xb6);
    if((X(0x1c2)&0x10) || mode==7) {
        if(!mode) { reset_phase(s); reset_timers(s); I(0xb6)=7; }
        goto finish_modes;
    }
    if((X(0x1c2)&1) && !mode) goto finish_modes;
    features=R(XW(0x3c6)+1); phase=I(0xaa);
    if(I(0xa9)>I(0xb9)) {
        decision=up_mode(s,RW(cal+0x2d));
        if(mode==0) new_up(s,decision,0);
        else if(mode==3 && (features&4) && phase<3) {
            reset_timers(s); reset_phase(s);
            I(0xaa)=decision==1?(phase<1?6:7):(phase<1?7:8);
            new_up(s,decision,1);
        } else if(mode==4 && (features&2) && phase<4) {
            reset_timers(s); reset_phase(s);
            I(0xaa)=decision==2?(phase<=2?7:8):(phase<=2?6:7);
            new_up(s,decision,1);
        }
        goto finish_modes;
    }
    if(I(0xa9)>=I(0xb9)) goto finish_modes;
    decision=down_mode(s,RW(cal+0x2d),RW(cal+0x3a));
    switch(mode) {
    case 0: new_down(s,decision,0); break;
    case 1:
        if(!(features&2) || phase>=4) break;
        reset_timers(s); reset_phase(s);
        if(phase<=2 && signed16(XW(0x2bb))<signed16(RW(cal+0x20))) I(0xaa)=decision==3?7:6;
        else I(0xaa)=decision==3?8:7;
        new_down(s,decision,1); break;
    case 2:
        if(!(features&4) || phase>=3) break;
        reset_timers(s); reset_phase(s);
        I(0xaa)=decision==4?(phase<1?6:7):(phase<1?7:8);
        new_down(s,decision,1); break;
    case 3:
        if(decision!=3 || (I(0x96)&0x40) || X(0x76)<R(tcc+0xf) || X(0x202)<=R(tcc+0x20)) break;
        if(I(0xb9)==3 && !(X(0x1c5)&0x80) && XW(0x29a)<=RW(tcc+0x18)) break;
        I(0x96)|=2;
        if((I(0xb5)<=2 && I(0xb4)<=1) || phase!=1) break;
        if(signed16(XW(0x2bb))<signed16(RW(tcc+0x16))) break;
        {
            uint8_t p=R(tcc+(I(0xb9)==2?9:I(0xb9)==3?8:7));
            uint16_t limit=egs51_shift_threshold(s,(uint8_t)(I(0xac)-1),p);
            if(signed16(XW(0x357))>=signed16(limit)) break;
        }
        I(0x96)|=1; I(0xac)=(uint8_t)(I(0xb9)+4); I(0xb6)=decision;
        reset_phase(s); I(0xaa)=6; break;
    case 4:
        if(decision!=4 || (!(I(0x98)&0x20) && (I(0xb9)!=4 || X(0x285)>=R(cal+0x31)))) break;
        if(X(0x76)<R(tcc+0xf) || !((phase==3 && I(0xb4)==4) || phase==4)) break;
        I(0x95)&=0xf8; new_down(s,decision,0);
        I(0xb2)=R(tcc+0x24+I(0xb9)); reset_phase(s); break;
    default: break;
    }
finish_modes:
    if(!(R(XW(0x3c6)+1)&1) || (I(0x96)&5)) goto tail;
    switch(I(0xb6)) {
    case 1:
        decision=up_mode(s,RW(cal+0x2d));
        if(decision==2 && !(I(0x96)&8)) egs51_mode_transition(s,decision,0);
        break;
    case 4:
        decision=down_mode(s,RW(cal+0x2d),RW(cal+0x3a));
        if(decision==3 && !(I(0x96)&8)) egs51_mode_transition(s,decision,0);
        break;
    case 2:
        decision=up_mode(s,RW(cal+0x2f));
        if(decision==1) egs51_mode_transition(s,decision,1);
        break;
    case 3:
        decision=down_mode(s,RW(cal+0x2f),RW(cal+0x3c));
        if(decision==4) egs51_mode_transition(s,decision,1);
        break;
    default: break;
    }
tail:
    if((X(0x1c2)&2) && I(0xb6)!=5) {
        reset_phase(s); reset_timers(s); I(0x9a)&=0xf7; I(0xb6)=5; I(0xb9)=0;
        if(!I(0xac)) I(0xac)=5;
    }
    if(X(0x1c2)&0x20) { I(0xb9)=I(0xb3)=X(0x34c); X(0x223)=I(0xb9); }
}
