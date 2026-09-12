/* Bank1 line-pressure scheduling; raw units and 16-bit intermediate wrap. */
#include "egs51_internal.h"
/* 5480..56A5: complete MPC line target, flush state and asymmetric filtering.
 * Previous demand is I44:45; this routine returns the next value to its caller. */
uint16_t egs51_mpc_line(Egs51 *s) {
    uint16_t cal=XW(0x3ce),target=0,minimum=RW(cal+0x4f);
    if(I(0xb9)) {
        target=(uint16_t)(IW(0x4a)+md(IW(0xad),IW(0x52),R(0xffd1)));
        target=md(target,RW(cal+((I(0xb9)==1 || I(0xb9)==6)?1:3)),1000);
        uint16_t spring=RW(cal+5); target=target<spring?0:target-spring;
    }
    if(target>XW(0x329)) target=XW(0x329);
    if(!target && IW(0x44)<=minimum && X(0x76)>=R(cal+0x52) && RW(cal+0x56)) {
        if(!XW(0x2df)) {
            if(I(0x98)&8) { XP(0x2df,RW(cal+0x56)); I(0x98)&=0xf7; I(0x98)|=0x10; }
            else { I(0x98)|=8; XP(0x2df,RW(cal+0x58)); }
        }
    } else { I(0x98)&=0xf7; XP(0x2df,0); }
    if(!(I(0x98)&8)) {
        if(target<minimum) target=minimum;
        if(IW(0x44)>target) {
            uint8_t weight=R(cal+0x51);
            uint16_t next=(uint16_t)(target*8u),old=(uint16_t)(IW(0x44)*8u);
            target=(uint16_t)(((uint32_t)old*weight+next)/(weight+1));
            target>>=3;
        }
    }
    return target;
}
/* 43C5..447F: squared-speed pressure term, selected by caller's R7. */
uint16_t egs51_speed_pressure(const Egs51 *s,uint8_t selector) {
    uint16_t term=0,coefficient=(uint16_t)(RW(0xffed)-(uint16_t)(RW(0xffef)*X(0x76))/100);
    if(selector==1) term=md(md(XW(0x22f),XW(0x22f),1000),coefficient,RW(0xfff3));
    else if(selector==2) {
        uint16_t speed=XW(0x1ea); if(speed>=32768) speed=(uint16_t)(0u-speed);
        term=md(md(speed,speed,1000),coefficient,RW(0xfff5));
    }
    return term/10;
}
/* 6A50..6AA2: temperature-dependent gain only in mode1/index1. */
void egs51_shift_gain(Egs51 *s) {
    X(0x2ab)=I(0xb6)==1 && I(0xac)==1 ?
        (uint8_t)egs51_lerp(R(0xffe0),R(0xffd2),R(0xffde),R(0xffdf),X(0x76)):R(0xffd2);
}
/* 2BB2..2C4E: complete setup including both squared-speed terms, gain and
 * available SPC pressure. Subtraction before the SPC gain wraps unsigned. */
void egs51_shift_setup(Egs51 *s) {
    IP(0x4e,egs51_speed_pressure(s,I(0x56))); IP(0x50,egs51_speed_pressure(s,I(0x57)));
    uint16_t limit=RW(XW(0x3c6)+2); XP(0x233,IW(0xad)>limit?IW(0xad):limit);
    egs51_shift_gain(s);
    uint16_t hydr=XW(0x3ce);
    XP(0x273,md((uint16_t)(XW(0x329)-RW(hydr+0x37)),RW(hydr+0x37+2*I(0xac)),1000));
}
