/* Complete bank1 pressure helpers and phase6 handler. OEM word/byte units;
 * no hardware access, substitute control law, or executable ROM dependency. */
#include "egs51_internal.h"
static uint16_t subfloor(uint16_t a,uint16_t b) { return a>b?a-b:0; }
static uint16_t positive(uint16_t v) { return signed16(v)>0?v:0; }
/* 0C20: signed operands, truncate toward zero, then keep the low word. */
uint16_t egs51_signed_md(uint16_t a,uint16_t b,uint16_t d) {
    assert(d); return (uint16_t)(signed16(a)*signed16(b)/signed16(d));
}
/* C0D3: signed axes AND ordinates; upper clamp precedes lower clamp. */
uint16_t egs51_signed_lerp(uint16_t y0,uint16_t y1,uint16_t x0,uint16_t x1,uint16_t x) {
    if(signed16(x)>=signed16(x1)) return y1;
    if(signed16(x)<=signed16(x0)) return y0;
    return (uint16_t)(y0+egs51_signed_md((uint16_t)(y1-y0),(uint16_t)(x-x0),(uint16_t)(x1-x0)));
}
/* 6FEE..7092: spring correction is signed; positive addition wraps before cap. */
uint16_t egs51_overlap_pressure(const Egs51 *s,uint8_t idx,uint16_t on,uint16_t off) {
    uint16_t cal=XW(0x3ce);
    uint16_t p=(uint16_t)(md(RW(cal+7+2*idx),on,1000)+md(RW(cal+0x17+2*idx),off,1000));
    uint16_t spring=RW(cal+0x27+2*idx);
    p=signed16(spring)<0?subfloor(p,(uint16_t)(0u-spring)):(uint16_t)(p+spring);
    return p<XW(0x329)?p:XW(0x329);
}
/* 74C8..7560 */
uint16_t egs51_shift_mod_pressure(const Egs51 *s,uint8_t idx) {
    uint16_t t=subfloor(positive((uint16_t)(IW(0xad)+XW(0x378))),XW(0x303));
    t=subfloor((uint16_t)(md(t,IW(0x54),X(0x2ab))+IW(0x4c)),IW(0x50));
    return egs51_overlap_pressure(s,idx,IW(0x46),t);
}
/* 75FD..762E */
uint16_t egs51_shift_net_torque(const Egs51 *s) {
    return (uint16_t)(IW(0xad)+XW(0x378)-XW(0x303)-XW(0x38c));
}
/* 7561..75FC */
uint16_t egs51_shift_signed_mod_pressure(const Egs51 *s,uint8_t idx) {
    uint16_t t=(uint16_t)(egs51_signed_md(egs51_shift_net_torque(s),IW(0x54),X(0x2ab))+IW(0x4c));
    return egs51_overlap_pressure(s,idx,IW(0x46),subfloor(positive(t),IW(0x50)));
}
/* 762F..7710 */
uint16_t egs51_handoff_mod_pressure(const Egs51 *s,uint8_t idx) {
    uint16_t t=(uint16_t)(egs51_shift_net_torque(s)+XW(0x384));
    uint16_t minimum=(uint16_t)(0u-RW(XW(0x3c6)+0x39));
    if(signed16(t)<signed16(minimum)) t=minimum;
    t=(uint16_t)(egs51_signed_md(t,IW(0x54),X(0x2ab))+IW(0x4c));
    return egs51_overlap_pressure(s,idx,IW(0x46),subfloor(positive(t),IW(0x50)));
}
/* 6B7A..6C31: byte map inputs intentionally truncate after division. */
void egs51_shift_fill_torque(Egs51 *s) {
    uint16_t desc=RW(XW(0x3cc)+2*I(0xac)-2);
    uint16_t t=5u*egs51_map8(s,1,desc,(uint8_t)(XW(0x2ac)/30),(uint8_t)(IW(0xad)/5));
    if(I(0xb6)==3) { t=md(X(0x202),t,10); if(t>IW(0xad)) t=IW(0xad); }
    XP(0x303,t);
}
/* B3F8..B414. A byte subtraction precedes the unsigned multiply. */
void egs51_shift_adapt_address(Egs51 *s,uint8_t stride,uint8_t first,uint16_t base) {
    XP(0x305,base+(uint8_t)(I(0xac)-first)*stride);
}
static uint16_t signed_byte(uint8_t v) { return v<128?v:(uint16_t)(v-256); }
static uint16_t adapt_pair(const Egs51 *s,uint16_t a,uint16_t lo,uint16_t hi) {
    assert(a+1u<sizeof(s->x));
    return egs51_signed_lerp(signed_byte(X(a)),signed_byte(X(a+1)),lo,hi,XW(0x298));
}
/* C144..C610, all mode branches. Reads OEM adaptation cells, does not learn
 * new values. Unknown modes still execute the common inhibit/scaling tail. */
void egs51_shift_pressure_compensation(Egs51 *s) {
    uint16_t cal=XW(0x3bc),lo=RW(cal+0x26),hi=RW(cal+0xc),a=0;
    uint8_t mode=I(0xb6);
    if(mode>=1 && mode<=4) {
        egs51_shift_adapt_address(s,mode==1?6:mode==2?2:4,mode<=2?1:5,
                                 mode==1?0x127:mode==2?0x13f:mode==3?0x147:0x157);
        XP(0x298,md(XW(0x2ac),RW((mode<=2?0x103e:0x1040)+2*I(0xb9)),1000));
        a=XW(0x305);
        uint16_t value;
        if(mode==2) value=adapt_pair(s,a,lo,hi);
        else if(mode==4) value=adapt_pair(s,a+(signed16(XW(0x2b9))<0?2:0),lo,hi);
        else {
            uint16_t y0,y1,x0,x1;
            if(mode==3 || signed16(XW(0x2b9))>signed16(RW(cal+8))) {
                y0=adapt_pair(s,a+2,lo,hi); y1=adapt_pair(s,a,lo,hi);
                x0=mode==3?RW(XW(0x3ca)+0x2f):RW(cal+8); x1=RW(cal+0xa);
            } else {
                y0=adapt_pair(s,a+4,lo,hi); y1=adapt_pair(s,a+2,lo,hi);
                x0=(uint16_t)(0u-RW(XW(0x3ca)+0x2d)); x1=RW(cal+8);
            }
            value=egs51_signed_lerp(y0,y1,x0,x1,XW(0x2b9));
        }
        XP(0x378,value);
    }
    if(I(0x96)&0x20) XP(0x378,0);
    XP(0x378,3u*XW(0x378));
}
/* D9A0..D9C7 */
uint16_t egs51_gear_sync_speed(const Egs51 *s,uint8_t gear) {
    return md(XW(0x2ac),RW(0x1040+2*gear),1000);
}
static void set_clutch(Egs51 *s,uint16_t p) {
    IP(0x46,p); IP(0x48,egs51_spc(s,I(0xac)-1,p));
}
/* 9BF9..9F90: complete coordinated downshift handoff. This owns both circuit
 * command bits until the speed/timer condition permits old-circuit release.
 * Timers are serviced by the caller, exactly as in the OEM scheduler. */
void egs51_downshift_handoff(Egs51 *s) {
    uint16_t cal=XW(0x3c4);
    if(I(0xb4)==0) {
        set_clutch(s,egs51_handoff_clutch_pressure(s,egs51_handoff_low_pressure(s,I(0xb6))));
        IP(0x44,egs51_handoff_mod_pressure(s,I(0xac)-1)); I(0x96)&=0xfd;
        IP(0xb7,R(cal+1)); I(0xaf)=I(0xb0)=I(0xb1)=0;
        if(I(0xb9)==2) {
            if(IW(0x44)>RW(cal+0xb)) { I(0xb0)=R(cal+0xa); I(0xb1)=(uint8_t)(I(0xb0)+R(cal+3)); }
        } else if(I(0xb9)!=4 && IW(0x44)>RW(cal+0x14)) I(0xb0)=I(0xb1)=R(cal+0xa);
        ++I(0xb4);
    }
    if(I(0xb4)==1) {
        ++I(0xaf); I(0x95)|=R(0xe67e + I(0xb9));
        uint16_t target=IW(0x44),offset=0;
        if(I(0xb9)==2) { if(target>RW(cal+0xb)) target=RW(cal+0xb); }
        else if(I(0xb9)!=4) {
            uint16_t base=RW(cal+0x1a);
            offset=egs51_lerp(base,(uint16_t)(base*R(cal+0x11)),RW(cal+0x1e),RW(cal+0x1c),XW(0x2ac));
            if(target>RW(cal+0x14)) target=RW(cal+0x14);
        }
        IP(0x44,egs51_lag(IW(0x44),target,I(0xb0)));
        if(((uint16_t)(XW(0x22f)+offset)<egs51_gear_sync_speed(s,I(0xb9)) || I(0xb1)) && IW(0xb7)) return;
        I(0x95)&=(uint8_t)~R(0xe67b + I(0xac)); ++I(0xb4);
        I(0xb0)=R(cal+(I(0xb9)==2?4:I(0xb9)==4?0x24:0x23));
        if(!I(0xb0)) { I(0xb4)=3; egs51_downshift_handoff_advance(s); }
        return;
    }
    if(I(0xb4)==2) {
        ++I(0xaf);
        if(I(0xb0) && IW(0xb7)) return;
        ++I(0xb4); egs51_downshift_handoff_advance(s); return;
    }
    if(I(0xb4)!=3) return;
    egs51_shift_fill_torque(s); egs51_shift_pressure_compensation(s);
    uint8_t fill=egs51_fill_term(s);
    int high=I(0xaf)<=fill && I(0xac)!=6;
    uint16_t target=egs51_handoff_clutch_pressure(s,high?egs51_handoff_high_pressure(s,I(0xb6)):egs51_handoff_low_pressure(s,I(0xb6)));
    set_clutch(s,egs51_lag(IW(0x46),target,I(0xb0)));
    if(!I(0xb0)) I(0xb4)=high?0:2;
    IP(0x44,egs51_lag(IW(0x44),egs51_shift_mod_pressure(s,I(0xac)-1),I(0xb0)));
    if(I(0xb0) && IW(0xb7)) return;
    I(0x96)&=0xfe; IP(0xb7,RW(0xffb5)); I(0xb5)=3; I(0xaa)=1;
    for(unsigned a=0x2d6;a<0x2dc;++a) X(a)=0;
    XP(0x27c,0); XP(0x20c,0); X(0x1e5)=0; XP(0x1ee,0); XP(0x38c,0);
}
/* 6F51..6F84: applying-clutch capacity; zero net pressure avoids division. */
void egs51_applying_capacity(Egs51 *s,uint16_t pressure,uint8_t gain) {
    uint16_t net=subfloor((uint16_t)(pressure+IW(0x4e)),IW(0x4a));
    XP(0x1d6,net?md(net,gain,IW(0x52)):0);
}
static uint16_t absword(uint16_t v) { return v<0x8000?v:(uint16_t)(0u-v); }
/* 4BC9..4ED8: all seven applying-clutch substates used in mode2/3 phase1.
 * In particular state0 consumes handoff credit rather than restarting fill. */
void egs51_release_apply(Egs51 *s) {
    uint16_t low=egs51_handoff_low_pressure(s,I(0xb6));
    uint16_t high=egs51_handoff_high_pressure(s,I(0xb6));
    uint16_t cal=XW(0x3ca);
    if(I(0xb4)==0) {
        I(0xb0)=(uint8_t)subfloor(egs51_fill_term(s),I(0xaf)); I(0xaf)=0; ++I(0xb4);
    }
    switch(I(0xb4)) {
    case 1:
        XP(0x1d6,0); set_clutch(s,egs51_handoff_clutch_pressure(s,high));
        if(!I(0xb0)) { I(0xb0)=R(XW(0x3c6)+0x22); ++I(0xb4); } return;
    case 2:
        XP(0x1d6,0);
        set_clutch(s,egs51_lag(IW(0x46),egs51_handoff_clutch_pressure(s,low),I(0xb0)));
        if(!I(0xb0)) { I(0xb0)=R(XW(0x3c6)+0x23+I(0x56)); ++I(0xb4); } return;
    case 3:
        XP(0x1d6,0); set_clutch(s,egs51_handoff_clutch_pressure(s,low));
        if(!I(0xb0)) ++I(0xb4);
        return;
    case 4:
        set_clutch(s,egs51_handoff_clutch_pressure(s,low));
        egs51_applying_capacity(s,IW(0x46),X(0x2ab));
        if(signed16(XW(0x357))>=signed16(RW(cal+0x20)) &&
           signed16(absword(XW(0x2bb)))>=signed16(RW(cal+0x20)) && !(I(0x96)&0x80)) return;
        XP(0x28e,0); ++I(0xb4); return;
    case 5: {
        uint16_t ramp=(uint16_t)(XW(0x28e)+RW(cal+4));
        XP(0x28e,ramp<XW(0x273)?ramp:XW(0x273));
        /* Fall through to the common pressure/capacity update below. */
        break;
    }
    case 6: break;
    default: return;
    }
    uint16_t pressure=(uint16_t)(egs51_handoff_clutch_pressure(s,low)+XW(0x28e));
    set_clutch(s,pressure<XW(0x273)?pressure:XW(0x273));
    egs51_applying_capacity(s,IW(0x46),X(0x2ab));
    if(I(0xb4)==5) {
        if((signed16(absword(XW(0x2bb)))<=signed16(RW(cal+0x20)) || (I(0x96)&0x80)) &&
           signed16(XW(0x357))>=signed16(egs51_shift_threshold(s,I(0xac)-1,R(cal+2)))) return;
        ++I(0xb4);
    }
}
