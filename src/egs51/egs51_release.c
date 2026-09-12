/* Bank1 release-family pressure control (modes2/3), raw OEM units. */
#include "egs51_internal.h"
static uint16_t sf(uint16_t a,uint16_t b) { return a>b?a-b:0; }
static uint16_t pos(uint16_t v) { return signed16(v)>0?v:0; }
static uint16_t aw(uint16_t v) { return v<0x8000?v:(uint16_t)(0u-v); }
static uint16_t clamp16(int32_t v) { return (uint16_t)(v>32767?32767:v< -32768?-32768:v); }
/* 0DD6..0F96, including integrator saturation and derivative word wrap. */
uint16_t egs51_shift_pid(Egs51 *s,uint16_t memory,uint16_t cal,uint16_t error) {
    assert(memory+5u<sizeof(s->x));
    int32_t p=signed16(egs51_signed_md(RW(cal),error,1000));
    XP(memory+2,clamp16(signed16(XW(memory+2))+signed16(error)));
    uint16_t i=egs51_signed_md(XW(memory+2),RW(cal+2),1000); XP(0x206,i);
    uint16_t d=egs51_signed_md((uint16_t)(error-XW(memory)),RW(cal+4),1000);
    XP(memory,error);
    return clamp16(p+signed16(i)+signed16(d));
}
/* 0F97..0FD1: separate unsigned products, including underflow for weight>100. */
uint16_t egs51_percent_filter(uint8_t weight,uint16_t next,uint16_t old) {
    return (uint16_t)(md((uint16_t)(100-weight),old,100)+md(weight,next,100));
}
/* 68BB..69C6 */
uint8_t egs51_release_hold_time(Egs51 *s,uint8_t idx) {
    uint8_t t=0;
    if(idx!=5 && idx!=6) {
        uint16_t cal=XW(0x3c6);
        t=(uint8_t)(R(cal+0x23+I(0x56))+R(cal+0x22)+X(0x339));
        uint16_t correction;
        if(XW(0x303)) {
            correction=md(aw(XW(0x357)),egs51_shift_factor(s),XW(0x303));
            assert(R(0xfff6+idx)); correction/=R(0xfff6+idx);
        } else correction=md(aw(XW(0x357)),egs51_shift_factor(s),R(0xfff6+idx));
        t=(uint8_t)sf(t,correction>255?255:correction);
        if(X(0x76)<R(XW(0x3ca)+0x39) && t<X(0x339)) t=X(0x339);
    }
    XP(0x22d,t); return t;
}
/* 69C7..6A4F */
uint8_t egs51_release_ramp_time(const Egs51 *s,uint8_t idx) {
    uint8_t t=R(XW(0x3ca)+1);
    if(idx<5 || idx>8) {
        uint8_t sum=(uint8_t)(R(XW(0x3c6)+0x22)+X(0x339));
        if(sum>XW(0x22d) && sum-XW(0x22d)>t) t=(uint8_t)(sum-XW(0x22d));
    }
    return t;
}
/* 7402..74C7 */
uint16_t egs51_release_initial_pressure(const Egs51 *s,uint8_t idx) {
    uint16_t on=0,k=RW(XW(0x3ca)+8);
    if(IW(0x4a)>IW(0x4e)) on=(uint16_t)(md((uint16_t)(1000-k),IW(0x4a)-IW(0x4e),1000)+md(k,IW(0x46),1000));
    uint16_t off=sf((uint16_t)(md(XW(0x233),IW(0x54),R(0xffd0))+IW(0x4c)),IW(0x50));
    return egs51_overlap_pressure(s,idx,on,off);
}
static uint16_t release_reduction(const Egs51 *s,uint8_t idx) {
    uint16_t t=(uint16_t)(md(R(0xffd0),XW(0x1d6),X(0x2ab))+md(X(0x397),XW(0x2f9),100));
    t=(uint16_t)(t+XW(0x303)-md(XW(0x303),R(XW(0x3ca)+0xa+idx),100));
    return t<XW(0x303)?t:XW(0x303);
}
/* 4ED9..4FBF. AC is one-based here; 7711 uses its zero-based input instead. */
uint16_t egs51_release_momentum(const Egs51 *s) {
    return sf((uint16_t)(release_reduction(s,I(0xac))+XW(0x1d6)),md(X(0x397),XW(0x2f5),100));
}
/* 7711..7850 */
uint16_t egs51_release_final_pressure(const Egs51 *s,uint8_t idx) {
    uint16_t t=pos((uint16_t)(IW(0xad)+XW(0x384)+XW(0x378)));
    t=md(sf(t,release_reduction(s,idx)),IW(0x54),X(0x2ab));
    t=sf((uint16_t)(t+IW(0x4c)),IW(0x50));
    return egs51_overlap_pressure(s,idx,IW(0x46),t);
}
/* C611..C9D0: valid OEM controller modes1,2,3,4,6. Other modes would consume
 * stale compiler scratch in the ROM's learning tail and are not callable here. */
void egs51_shift_momentum_control(Egs51 *s,uint16_t momentum) {
    uint8_t mode=I(0xb6);
    assert((mode>=1 && mode<=4) || mode==6);
    uint16_t delta=md(momentum,20,egs51_shift_factor(s));
    if(mode==3 || mode==4) XP(0x2a9,XW(0x2a9)+delta);
    else XP(0x2a9,pos((uint16_t)(XW(0x2a9)-delta)));
    uint16_t error=(uint16_t)(XW(0x22f)-XW(0x2a9));
    uint16_t cal=mode==1?XW(0x3be)+0xd:mode==2?XW(0x3ca)+0x18:
                 mode==3?XW(0x3ca)+0x12:mode==4?XW(0x3be)+0x13:XW(0x3b2)+0x34;
    XP(0x384,egs51_shift_pid(s,0x2d6,cal,error));
    if(XW(0x1f6)) I(0x98)|=4;
    if(!(I(0x98)&4)) return;
    if(!(I(0x95)&0x20)) {
        uint16_t p=sf(XW(0x2dc),IW(0x4e));
        if(IW(0x46)<=p) I(0x99)|=I(0x99)&0x80?0x40:0x80;
        if(IW(0x46)>=XW(0x273) || X(0x1e5)>=R(XW(0x3bc)+0x21)) return;
    }
    ++X(0x1e5);
    uint16_t n=R(XW(0x3bc)+0x20); if(n<X(0x1e5)) n=X(0x1e5);
    XP(0x1ee,XW(0x1ee)+egs51_signed_md(egs51_shift_factor(s),error,(uint16_t)(20*n)));
    if((I(0x95)&0x20) && signed16(egs51_shift_net_torque(s))<=signed16((uint16_t)(0u-RW(XW(0x3c6)+0x39)))) I(0x99)|=0x40;
}
static void release_filter_control(Egs51 *s) {
    XP(0x20c,egs51_percent_filter(R(XW(0x3be)+0x19),XW(0x27c),XW(0x20c)));
    egs51_shift_momentum_control(s,XW(0x20c));
}
/* 4FC0..547F: all seven modulating-pressure substates and phase-exit gates. */
void egs51_release_modulate(Egs51 *s) {
    egs51_shift_fill_torque(s);
    uint16_t cal=XW(0x3ca),limit=RW(cal+0x20);
    uint8_t idx=I(0xac)-1;
    if(I(0xb5)==0) {
        I(0xb1)=egs51_release_hold_time(s,I(0xac));
        for(unsigned a=0x2d6;a<0x2dc;++a) X(a)=0;
        XP(0x27c,0); XP(0x20c,0); X(0x1e5)=0; XP(0x1ee,0); ++I(0xb5);
    }
    switch(I(0xb5)) {
    case 1: {
        uint16_t minimum=RW(XW(0x3c6)+2);
        XP(0x233,IW(0xad)>minimum?IW(0xad):minimum);
        IP(0x44,egs51_release_initial_pressure(s,idx));
        if(!I(0xb1)) { I(0xb1)=egs51_release_ramp_time(s,I(0xac)); ++I(0xb5); }
        break;
    }
    case 2:
        egs51_shift_pressure_compensation(s);
        IP(0x44,egs51_lag(IW(0x44),egs51_shift_mod_pressure(s,idx),I(0xb1)));
        if(!I(0xb1) || (signed16(XW(0x357))<signed16(egs51_shift_threshold(s,idx,R(cal+2))) &&
                        signed16(XW(0x2bb))>signed16(limit))) {
            ++I(0xb5); XP(0x38c,0); XP(0x26e,0);
        }
        break;
    case 3:
        if(signed16(aw(XW(0x2bb)))>signed16(limit) ||
           signed16(egs51_shift_net_torque(s))<=signed16((uint16_t)(0u-RW(XW(0x3c6)+0x39)))) {
            ++I(0xb5); XP(0x317,XW(0x2ac)); XP(0x23b,XW(0x2b9));
            XP(0x27c,XW(0x1d6)+XW(0x303)); XP(0x20c,XW(0x27c)); XP(0x2a9,XW(0x22f));
            flag(&I(0x98),4,XW(0x1f6)>0);
        } else {
            egs51_shift_pressure_compensation(s);
            uint16_t ramp=(uint16_t)(md(R(cal+0x38),XW(0x26e),100)+(uint16_t)(2u*RW(cal+6)));
            XP(0x26e,XW(0x26e)+md(X(0x202),ramp,10)); XP(0x38c,XW(0x26e)>>1);
            IP(0x44,egs51_shift_signed_mod_pressure(s,idx));
        }
        break;
    case 4:
        egs51_shift_pressure_compensation(s); XP(0x27c,XW(0x1d6)+XW(0x303));
        release_filter_control(s); IP(0x44,egs51_handoff_mod_pressure(s,idx));
        if(signed16(XW(0x357))<signed16(egs51_shift_threshold(s,idx,R(cal+2))) && !(I(0x96)&2)) {
            I(0xb1)=R(cal+2); ++I(0xb5);
        }
        break;
    case 5:
        I(0x95)|=0x40; egs51_shift_pressure_compensation(s);
        XP(0x27c,egs51_lag(XW(0x27c),egs51_release_momentum(s),I(0xb1)));
        release_filter_control(s);
        IP(0x44,egs51_lag(IW(0x44),egs51_release_final_pressure(s,idx),I(0xb1)));
        if(!I(0xb1)) { I(0xb1)=R(cal+3); ++I(0xb5); }
        break;
    case 6:
        egs51_shift_pressure_compensation(s); XP(0x27c,egs51_release_momentum(s));
        release_filter_control(s);
        IP(0x44,egs51_lag(IW(0x44),egs51_release_final_pressure(s,idx),I(0xb1)));
        if(!I(0xb1)) I(0xb5)=0;
        break;
    default: break;
    }
    if(!IW(0xb7) || !I(0xb5) ||
       (I(0xb5)>1 && ((signed16(XW(0x357))<signed16(limit) && !(I(0x96)&0x80)) ||
                      (signed16(XW(0x357))<signed16(RW(cal+0x3e)) && (I(0x96)&0x80))))) {
        I(0x95)|=0x40; I(0xb4)=I(0xb5)=0; ++I(0xaa);
    }
}
