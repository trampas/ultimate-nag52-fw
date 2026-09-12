/* OEM capture-period processing, bank0 547F / 5635. Interrupt acquisition
 * supplies the capture words and ready bits; physical timer units are external. */
#include "egs51_internal.h"
static void shaft_capture(Egs51 *s,unsigned channel) {
    unsigned ready=4u<<channel,overflow=0x40u<<channel,expired=0x10u<<channel;
    unsigned timer=0xfa+channel,config=0xf3+channel,shift=channel?0:4;
    unsigned mode=(X(config)>>shift)&7,clock=0x10u<<channel;
    uint16_t period=IW(0x5d),speed=IW(0x5f);
    if(I(0x2d)&ready) {
        I(0x2d)&=(uint8_t)~ready; period=IW(0x8a+2*channel); I(0x2e)|=4;
        uint32_t numerator=mode==1?500000u:mode==3?2000000u:mode==4?4000000u:0;
        if(numerator) { assert(period); speed=(uint16_t)(numerator/period); }
    } else {
        I(0x2e)&=0xfb;
        if(!X(timer)) { period=65535; speed=0; S(0xc8)&=(uint8_t)~clock;
            I(0x2d)&=(uint8_t)~overflow; I(0x2d)|=expired; }
    }
    if(!(I(0x2e)&4) && X(timer)) return;
    unsigned next=mode;
    if(mode==3) { if(period<1250) next=4; else if(period>3333) next=1; }
    else if(mode==4) { if(period>3333) next=3; }
    else if(mode==1) { if(period<625) next=3; }
    else next=3;
    if(next!=mode) {
        S(0xc8)&=(uint8_t)~clock; X(config)=(X(config)&(uint8_t)~(7u<<shift))|(next<<shift);
        S(channel?0xfd:0xfe)=X(config); I(0x2d)&=(uint8_t)~overflow;
    }
    if(!(S(0xc8)&clock)) {
        if(S(0xa8)&clock) I(0x89)|=2u<<channel;
        S(0xc8)|=clock;
    }
    X(0xef+channel)+=(uint8_t)(1-X(timer));
    unsigned count=X(0xef+channel),limit=count<2?(channel?800:600)*count:65535;
    int delta=signed16((uint16_t)(IW(0x81+2*channel)-speed)); if(delta<0) delta=-delta;
    if((unsigned)delta<=limit) {
        X(0xef+channel)=0;
        if(speed<60) IP(0x81+2*channel,0);
        else if(speed<=8000) IP(0x81+2*channel,speed);
    }
    X(timer)=1;
    /* Retain the workspace because an invalid capture mode reuses it in ROM. */
    IP(0x5d,limit); IP(0x5f,speed);
}
void egs51_shaft_capture_n2(Egs51 *s) { shaft_capture(s,0); }
void egs51_shaft_capture_n3(Egs51 *s) { S(0x98)=1; shaft_capture(s,1); }
