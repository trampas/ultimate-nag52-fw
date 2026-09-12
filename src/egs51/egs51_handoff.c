/* Handoff dependencies, bank1. Full routines listed below, without hooks.
 * The phase6 dispatcher/9BF9 pressure state machine is not implemented here. */
#include "egs51_internal.h"
#include "../shifting_algo/egs51_handoff_math.h"

static uint16_t sub_floor(uint16_t a,uint16_t b) { return a>b?a-b:0; }

/* 4480..4534: next fill pressure selector. */
uint16_t egs51_handoff_high_pressure(const Egs51 *s,uint8_t mode) {
    if(mode==3 && (I(0xac)==5 || I(0xac)==6)) return 0;
    uint16_t cal=XW(0x3c6),p=RW(cal+0x43+2*I(0x56));
    if(p>XW(0x329)) p=XW(0x329);
    if((I(0x96)&0x20) && I(0xb9)==3 && X(0x76)>=R(cal+0x37)) p=10*R(cal+0x38);
    return p;
}
/* 4535..4666: lower pressure selector and signed continuation correction. */
uint16_t egs51_handoff_low_pressure(const Egs51 *s,uint8_t mode) {
    uint16_t cal=XW(0x3c6),p=0;
    if(!(mode==3 && (I(0xac)==5 || I(0xac)==6))) {
        p=RW(cal+0x18+2*I(0x56));
        if(I(0x96)&0x20) p=sub_floor(p,RW(cal+(I(0xb9)==3?0x3b:0x16)));
        if(mode==2) p=sub_floor(p,RW(cal+0x14));
    }
    if((I(0x96)&2) && I(0xac)>=6) {
        uint8_t raw=R(cal+0x2e + I(0xac));
        int correction=raw<128?raw:(int)raw-256;
        p=(uint16_t)(p+10*correction);
        if(signed16(p)<=0) p=0;
    }
    return p;
}
/* 719A..71EC: spring and centrifugal corrections plus available SPC cap. */
uint16_t egs51_handoff_clutch_pressure(const Egs51 *s,uint16_t base_pressure) {
    uint16_t p=sub_floor((uint16_t)(base_pressure+IW(0x4a)),IW(0x4e));
    p=sub_floor(p,XW(0x1e6));
    return p<XW(0x273)?p:XW(0x273);
}
/* 6192..61CE: reset feedback for the next gear context. */
void egs51_shift_feedback_reset(Egs51 *s) {
    XP(0x303,0); XP(0x1d6,0); XP(0x384,0); XP(0x2fd,0); X(0x380)=0;
    I(0x98)&=0xfe; I(0x99)&=0x3f; XP(0x282,XW(0x1fd));
}
/* 61CF..6397: refresh applying/releasing/strongest clutch context. */
void egs51_shift_clutch_context(Egs51 *s) {
    egs51_shift_feedback_reset(s);
    uint8_t mode=I(0xb6),gear=I(0xb9);
    if(mode<3) I(0xac)=(uint8_t)(gear-1);
    else if(mode<5) I(0xac)=(uint8_t)(gear+4);
    uint8_t idx=I(0xac); uint16_t mech=XW(0x3d4);
    I(0x56)=R(0xe65b+idx);
    IP(0x52,RW(mech+1+12*gear+2*I(0x56)));
    IP(0x4a,RW(mech+0x71+2*I(0x56)));
    IP(0x4e,egs51_speed_pressure(s,I(0x56)));
    I(0x57)=R(0xe663+idx);
    IP(0x4c,RW(mech+0x71+2*I(0x57)));
    IP(0x50,egs51_speed_pressure(s,I(0x57)));
    if(mode==1 || mode==2) {
        XP(0x37b,0x7fff); IP(0x54,RW(mech+12*gear-11+2*I(0x57)));
    } else {
        XP(0x37b,0x8000);
        if(mode==3 || mode==4) IP(0x54,RW(mech+12*gear+13+2*I(0x57)));
    }
    uint8_t a=R(0xe66a+2*idx),b=R(0xe66b+2*idx),strongest=a>b?a:b;
    X(0x319)=strongest;
    XP(0x33a,RW(mech+1+12*gear+2*strongest));
    XP(0x2a1,RW(mech+0x71+2*strongest));
    XP(0x231,egs51_speed_pressure(s,strongest));
}
/* 9ACE..9BF8, including 61CF, 4480, 0CE8 and arithmetic helpers. */
void egs51_downshift_handoff_advance(Egs51 *s) {
    --I(0xb9); I(0xb3)=I(0xb9);
    egs51_shift_clutch_context(s);
    X(0x202)=R(XW(0x3ca)+0x2c);
    uint16_t cal=XW(0x3c4);
    I(0xb0)=R(cal+(I(0xb9)==1?0x12:I(0xb9)==3?0x22:0x21));
    I(0xaf)=egs51_handoff_fill_credit(IW(0x46),IW(0x4e),IW(0x4a),
        egs51_handoff_high_pressure(s,I(0xb6)),I(0xb0),I(0xaf));
}
/* Exposed for exhaustive ROM differential tests of the portable arithmetic. */
uint16_t egs51_handoff_root_test(uint16_t v) { return egs51_handoff_root(v); }
