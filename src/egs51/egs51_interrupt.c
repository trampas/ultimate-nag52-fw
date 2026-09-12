/* A0215451432 shared interrupted-shift pressure recovery. */
#include "egs51_internal.h"
void egs51_interrupt_match(Egs51 *s) { /* A855..A8BF */
    if(!I(0xb4)) {
        I(0x95)|=0x40; I(0xb0)=R(0xffc6);
        I(0xb1)=(uint8_t)(I(0xb0)+egs51_lerp(R(0xffb2),R(0xffbe),R(0xffb3),R(0xffb4),X(0x76)));
        ++I(0xb4);
    }
    if(I(0xb4)==1) {
        IP(0x46,egs51_lag(IW(0x46),0,I(0xb0)));
        IP(0x48,egs51_lag(IW(0x48),0,I(0xb0)));
        IP(0x44,egs51_lag(IW(0x44),XW(0x329),I(0xb0)));
    }
    if(!I(0xb1)) { I(0xb4)=0; ++I(0xaa); }
}
void egs51_interrupt_finish(Egs51 *s) { /* A8C0..A92F */
    I(0x95)&=0xf8;
    if(!I(0xb4)) {
        I(0xb0)=(uint8_t)egs51_lerp(R(0xffbb),R(0xffbc),R(0xffbd),R(0xffc7),X(0x76));
        ++I(0xb4);
    }
    if(I(0xb4)==1) { IP(0x46,0); IP(0x48,0); IP(0x44,XW(0x329)); }
    if(!I(0xb0)) {
        I(0x96)&=0x9a;
        IP(0xb7,0); I(0xb0)=I(0xb1)=I(0xaf)=I(0xb6)=I(0xb4)=I(0xb5)=I(0xaa)=0;
        if(I(0xb9)<=I(0xa9)) X(0x202)=10;
    }
}
void egs51_interrupt_context(Egs51 *s) { /* 8520..875C */
    egs51_shift_feedback_reset(s); XP(0x37b,0);
    uint8_t gear=I(0xb9),up=I(0xb6)==1 || I(0xb6)==2;
    I(0xac)=up?(uint8_t)(gear-1):(uint8_t)(gear+4);
    uint8_t idx=I(0xac); uint16_t mech=XW(0x3d4);
    I(0x56)=R(0xe65b+idx); I(0x57)=R(0xe663+idx);
    IP(0x52,RW(mech+1+12*gear+2*I(0x56)));
    IP(0x4a,RW(mech+0x71+2*I(0x56))); IP(0x4e,egs51_speed_pressure(s,I(0x56)));
    IP(0x4c,RW(mech+0x71+2*I(0x57))); IP(0x50,egs51_speed_pressure(s,I(0x57)));
    IP(0x54,RW(mech+12*gear+(up?-11:13)+2*I(0x57)));
    uint8_t a=R(0xe66a+2*idx),b=R(0xe66b+2*idx);
    uint16_t ca=RW(mech+1+12*gear+2*a),cb=RW(mech+1+12*gear+2*b);
    uint8_t strongest=ca>cb?a:b; X(0x319)=strongest; XP(0x33a,ca>cb?ca:cb);
    XP(0x2a1,RW(mech+0x71+2*strongest)); XP(0x231,egs51_speed_pressure(s,strongest));
    XP(0x273,md((uint16_t)(XW(0x329)-RW(XW(0x3ce)+0x37)),RW(XW(0x3ce)+0x37+2*idx),1000));
}
static uint16_t sub(uint16_t a,uint16_t b) { return a>b?a-b:0; }
static uint16_t interrupt_pressure(const Egs51 *s,uint8_t idx,uint16_t torque,uint16_t on) {
    uint16_t p=signed16(torque)<0?0:md(torque,IW(0x52),X(0x2ab));
    p=sub((uint16_t)(p+IW(0x4a)),IW(0x4e));
    return egs51_overlap_pressure(s,(idx+4)&7,on,p);
}
uint16_t egs51_interrupt_inertia_pressure(const Egs51 *s,uint8_t idx) { /* 8DD5 */
    uint16_t t=XW(0x1d8)>XW(0x2be)?XW(0x1d8):XW(0x2be);
    return interrupt_pressure(s,idx,(uint16_t)(t+IW(0xad)+XW(0x2f9)+XW(0x384)),0);
}
uint16_t egs51_interrupt_settle_pressure(const Egs51 *s,uint8_t idx) { /* 8E8D */
    return interrupt_pressure(s,idx,(uint16_t)(IW(0xad)+XW(0x1d8)+XW(0x384)),IW(0x4c));
}
static void momentum(Egs51 *s) {
    XP(0x20c,egs51_percent_filter(R(XW(0x3be)+0x19),XW(0x27c),XW(0x20c)));
    egs51_shift_momentum_control(s,XW(0x20c));
}
void egs51_interrupt_crossover(Egs51 *s) { /* A558..A854 */
    egs51_crossover_torque_map(s); egs51_crossover_torque_margin(s);
    uint16_t cal=XW(0x3be);
    switch(I(0xb4)) {
    case 0:
        I(0xb0)=egs51_crossover_inertia_time(s); X(0x322)=I(0xb0);
        IP(0xb7,RW(0xffb5)); I(0x95)|=0x40; ++I(0xb4);
        /* fall through */
    case 1:
        IP(0x46,egs51_lag(IW(0x46),0,I(0xb0))); IP(0x48,egs51_lag(IW(0x48),0,I(0xb0)));
        IP(0x44,egs51_lag(IW(0x44),egs51_interrupt_inertia_pressure(s,I(0xac)-1),I(0xb0)));
        if(!I(0xb0) || signed16(XW(0x357))<signed16(egs51_up_torque_threshold(s,I(0xac)-1,R(cal+3)))) {
            for(unsigned a=0x2d6;a<0x2dc;++a) X(a)=0;
            XP(0x20c,0); XP(0x27c,0); XP(0x2a9,XW(0x22f)); flag(&I(0x98),4,XW(0x1f6)>0);
            ++I(0xb4);
        }
        break;
    case 2:
        XP(0x27c,sub((uint16_t)(XW(0x2f5)+XW(0x2be)+XW(0x2f9)),md(XW(0x2f9),100,R(XW(0x3c2)+0xf))));
        momentum(s); IP(0x46,0); IP(0x48,0);
        IP(0x44,egs51_interrupt_inertia_pressure(s,I(0xac)-1));
        if(signed16(XW(0x357))<signed16(egs51_up_torque_threshold(s,I(0xac)-1,R(cal+3)))) { I(0xb0)=R(cal+3); ++I(0xb4); }
        break;
    case 3:
        XP(0x27c,egs51_lag(XW(0x27c),XW(0x1d8),I(0xb0))); momentum(s);
        IP(0x46,0); IP(0x48,0);
        IP(0x44,egs51_lag(IW(0x44),egs51_interrupt_settle_pressure(s,I(0xac)-1),I(0xb0)));
        if(!I(0xb0) || signed16(XW(0x357))<signed16(RW(XW(0x3ca)+0x20))) { I(0xb0)=R(cal+4); ++I(0xb4); }
        break;
    case 4:
        IP(0x46,0); IP(0x48,0); IP(0x44,egs51_interrupt_settle_pressure(s,I(0xac)-1));
        if(!I(0xb0)) I(0xb4)=0;
        break;
    default: break;
    }
    if(!IW(0xb7) || !I(0xb4) || ((X(0x1bb)&1) && IW(0x46)>=XW(0x273))) {
        I(0xb0)=I(0xb1)=I(0xb4)=I(0xb5)=0; I(0xaa)=9;
    }
}
