/* A0215451432 bank1 C9D1..CE9E: torque intervention latch decisions.
 * These gates do not replace the separate CE9F torque-demand controller.
 */
#include "egs51_internal.h"
static int enabled(Egs51 *s) {
    unsigned idx=(uint8_t)(I(0xac)-1);
    if(idx<8 && (R(XW(0x3c2)+1)&(1u<<idx))) return 1;
    I(0x97)&=0xfe;
    return 0;
}
static void latch(Egs51 *s,uint8_t delay) { I(0x97)|=1; X(0x2fc)=delay; }
void egs51_up_torque_enter(Egs51 *s) {
    if(!enabled(s) || (I(0x97)&1) || I(0xb6)!=1 || signed16(XW(0x2b9))<0) return;
    if(I(0xaa)==3) {
        if(I(0xb4)>=2 || signed16(XW(0x2bb))>signed16(RW(XW(0x3ca)+0x20))) latch(s,0);
        else if(I(0xb4)==1 && (uint8_t)(X(0x322)-I(0xb0))>=R(XW(0x3c2)+0xc)) latch(s,0);
    } else if(I(0xaa)==8 && (I(0xb4)==2 || signed16(XW(0x2bb))>signed16(RW(XW(0x3ca)+0x20)))) latch(s,0);
}
void egs51_down_torque_enter(Egs51 *s) {
    uint16_t threshold;
    if(!enabled(s) || (I(0x97)&1) || I(0xb6)!=3 || signed16(XW(0x2b9))<0 ||
       XW(0x347)<RW(XW(0x3c2)+4) || XW(0x275)<=RW(XW(0x3c2)+2)) return;
    if(IW(0xad)>RW(XW(0x3d4)+0x57+2*I(0xac))) { latch(s,0); return; }
    if(I(0x96)&2) return;
    threshold=egs51_shift_threshold(s,(uint8_t)(I(0xac)-1),R(XW(0x3ca)+2));
    if(signed16(XW(0x357))<signed16(threshold) &&
       signed16(XW(0x2bb))>signed16(RW(XW(0x3ca)+0x20))) { latch(s,3); return; }
    if(signed16(XW(0x357))<signed16(RW(XW(0x3ca)+0x20))) latch(s,3);
}
static void down_exit(Egs51 *s,int interrupted) {
    uint16_t pressure;
    if(!(I(0x97)&1)) return;
    if(I(0xb6)!=3 || (!interrupted && (I(0x96)&5))) { I(0x97)&=0xfe; return; }
    if(IW(0xad)>RW(XW(0x3d4)+0x5f+2*I(0xac))) {
        if(I(0xaa)>(interrupted?11:3)) I(0x97)&=0xfe;
        return;
    }
    pressure=(uint16_t)(XW(0x384)+XW(0x378)-XW(0x38c));
    pressure=(uint16_t)(egs51_signed_md(pressure,IW(0x54),X(0x2ab))+IW(0x4c));
    pressure=signed16(pressure)>0 && pressure>=IW(0x50)?pressure-IW(0x50):0;
    pressure=egs51_overlap_pressure(s,(uint8_t)(I(0xac)-1),IW(0x46),pressure);
    IP(0x5d,pressure);
    if(pressure>=IW(0x44) || I(0xaa)>(interrupted?10:2)) I(0x97)&=0xfe;
}
void egs51_down_torque_exit(Egs51 *s) { down_exit(s,0); }
void egs51_interrupted_torque_exit(Egs51 *s) { down_exit(s,1); }
uint16_t egs51_up_torque_threshold(Egs51 *s,uint8_t idx,uint8_t parameter) {
    uint16_t value=(uint16_t)(5u*(uint16_t)(XW(0x1d8)+XW(0x2be))+5u*XW(0x2f5));
    value=md(value,(uint16_t)(2u*R(XW(0x3be)+0x20)+parameter),egs51_shift_factor(s));
    value=md(value,R(0xfff7+idx),10);
    return value>RW(XW(0x3ca)+0x20)?value:RW(XW(0x3ca)+0x20);
}
void egs51_up_torque_exit(Egs51 *s) {
    if(!(I(0x97)&1)) return;
    if(I(0xb6)!=1) { I(0x97)&=0xfe; return; }
    uint16_t threshold=egs51_up_torque_threshold(s,(uint8_t)(I(0xac)-1),R(XW(0x3be)+3));
    if(signed16(XW(0x357))<signed16(threshold) || I(0xb4)>=3) I(0x97)&=0xfe;
}
