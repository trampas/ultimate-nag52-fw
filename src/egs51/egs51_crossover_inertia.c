/* A0215451432 bank1 crossover inertia control and complete callees. */
#include "egs51_internal.h"
static uint16_t sub(uint16_t a,uint16_t b) { return a>b?a-b:0; }
static uint16_t pos(uint16_t v) { return signed16(v)>0?v:0; }
static uint16_t minp(uint16_t a,uint16_t b) { return a<b?a:b; }
static uint16_t maxp(uint16_t a,uint16_t b) { return a>b?a:b; }
static int direction(const Egs51 *s) {
    return ((I(0x95)&8) && signed16(XW(0x1fd))>0) || ((I(0x95)&0x10) && signed16(XW(0x1fd))<0);
}
static void apply(Egs51 *s,uint16_t p) { IP(0x46,p); IP(0x48,egs51_spc(s,I(0xac)-1,p)); }
uint8_t egs51_crossover_inertia_time(const Egs51 *s) { /* 6784 */
    uint16_t cal=XW(0x3be);
    return (uint8_t)egs51_lerp(R(cal+1),R(cal+2),RW(cal+0x1c),RW(cal+0x1e),IW(0xad));
}
void egs51_crossover_torque_map(Egs51 *s) { /* 6C32..6DC5 */
    uint16_t desc=RW(XW(0x3d2)+2*I(0xac)-2);
    uint16_t t=5u*egs51_map8(s,1,desc,(uint8_t)(XW(0x2ac)/30),(uint8_t)(IW(0xad)/5));
    if(I(0xb6)==1) {
        t=pos((uint16_t)(t-XW(0x37b)));
        if(signed16(XW(0x1fd))<0) t=pos((uint16_t)(t-2u*IW(0xad)));
    } else {
        if(I(0x98)&0x20) t=md(R(XW(0x3be)+0x22),t,10);
        if(signed16(XW(0x1fd))>0) t=pos((uint16_t)(t-2u*IW(0xad)));
        t=pos((uint16_t)(t+XW(0x37b)));
    }
    XP(0x2be,t);
}
void egs51_crossover_torque_margin(Egs51 *s) { /* 6E99..6F50 */
    uint16_t t=sub(md(X(0x2ab),IW(0xad),R(0xffd0)),IW(0xad));
    XP(0x1d8,minp(maxp(t,RW(XW(0x3be)+0x1a)),XW(0x2be)));
}
uint16_t egs51_crossover_momentum(const Egs51 *s) { /* 8F1F */
    uint16_t t=(uint16_t)(XW(0x2f5)+XW(0x2be)+XW(0x2f9));
    t=sub(t,md(XW(0x2f9),100,R(XW(0x3c2)+0xf)));
    if(!direction(s)) t=(uint16_t)(t+2u*IW(0xad));
    return pos((uint16_t)(t-XW(0x2fd)));
}
static uint16_t pressure(const Egs51 *s,uint16_t torque) {
    uint16_t p=sub((uint16_t)(md(pos(torque),IW(0x52),X(0x2ab))+IW(0x4a)),IW(0x4e));
    return minp(maxp(p,sub(XW(0x2dc),IW(0x4e))),XW(0x273));
}
uint16_t egs51_crossover_inertia_apply(const Egs51 *s) { /* 7F0E */
    return pressure(s,(uint16_t)(IW(0xad)+XW(0x2be)+XW(0x378)+XW(0x384)+XW(0x2f9)-XW(0x2fd)));
}
uint16_t egs51_crossover_settle_apply(const Egs51 *s) { /* 7FEB */
    return pressure(s,(uint16_t)(IW(0xad)+XW(0x1d8)+XW(0x384)+XW(0x378)-XW(0x2fd)));
}
static void momentum_control(Egs51 *s) {
    XP(0x20c,egs51_percent_filter(R(XW(0x3be)+0x19),XW(0x27c),XW(0x20c)));
    egs51_shift_momentum_control(s,XW(0x20c));
}
void egs51_crossover_inertia(Egs51 *s) { /* 8FEE..946F */
    uint16_t cal=XW(0x3be),t;
    egs51_crossover_momentum_target(s);
    switch(I(0xb4)) {
    case 0:
        I(0xb0)=egs51_crossover_inertia_time(s); I(0xb1)=R(cal+0x21); X(0x322)=I(0xb0);
        XP(0x317,XW(0x2ac)); XP(0x23b,XW(0x2b9));
        for(unsigned a=0x2d6;a<0x2dc;++a) X(a)=0;
        XP(0x20c,0); XP(0x27c,0); XP(0x2a9,XW(0x22f)); flag(&I(0x98),4,XW(0x1f6)>0);
        t=(uint16_t)(IW(0x46)+IW(0x4e));
        if(t>IW(0x4a)) {
            t=(uint16_t)(md(X(0x2ab),t-IW(0x4a),IW(0x52))+XW(0x2fd)-XW(0x378));
            t=direction(s)?(uint16_t)(t-IW(0xad)):(uint16_t)(t+XW(0x1fd));
            XP(0x27c,pos(t));
        }
        X(0x1e5)=0; XP(0x1ee,0); ++I(0xb4);
        /* fall through */
    case 1:
        egs51_shift_pressure_compensation(s); egs51_crossover_torque_map(s);
        XP(0x27c,egs51_lag(XW(0x27c),egs51_crossover_momentum(s),I(0xb0)));
        momentum_control(s);
        apply(s,egs51_lag(IW(0x46),egs51_crossover_inertia_apply(s),I(0xb0)));
        if(!I(0xb0) || signed16(XW(0x357))<signed16(egs51_up_torque_threshold(s,I(0xac)-1,R(cal+3)))) {
            ++I(0xb4);
            if(I(0xb0)) { I(0xb0)=R(cal+3); ++I(0xb4); }
        }
        break;
    case 2:
        egs51_shift_pressure_compensation(s); XP(0x27c,egs51_crossover_momentum(s)); momentum_control(s);
        egs51_crossover_torque_map(s); egs51_crossover_torque_margin(s);
        apply(s,egs51_crossover_inertia_apply(s));
        if(signed16(XW(0x357))<signed16(egs51_up_torque_threshold(s,I(0xac)-1,R(cal+3)))) { I(0xb0)=R(cal+3); ++I(0xb4); }
        break;
    case 3:
        egs51_shift_pressure_compensation(s); egs51_crossover_torque_margin(s);
        t=direction(s)?XW(0x1d8):(uint16_t)(XW(0x1d8)+2u*IW(0xad));
        XP(0x27c,egs51_lag(XW(0x27c),t,I(0xb0))); momentum_control(s);
        apply(s,egs51_lag(IW(0x46),egs51_crossover_settle_apply(s),I(0xb0)));
        if(!I(0xb0) || signed16(XW(0x357))<signed16(RW(XW(0x3ca)+0x20))) { I(0xb0)=R(cal+4); ++I(0xb4); }
        break;
    case 4:
        egs51_shift_pressure_compensation(s); egs51_crossover_torque_margin(s);
        apply(s,egs51_crossover_settle_apply(s)); if(!I(0xb0)) I(0xb4)=0;
        break;
    default: break;
    }
    IP(0x44,egs51_lag(IW(0x44),egs51_crossover_free_pressure(s,I(0xac)-1),I(0xb1)));
    if(!IW(0xb7) || !I(0xb4) || ((X(0x1bb)&1) && IW(0x46)>=XW(0x273))) { I(0xb4)=0; ++I(0xaa); }
}
