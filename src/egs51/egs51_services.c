/* Calibration setup and scheduler services, instruction-derived pass 5. */
#include "egs51_internal.h"
/* bank1 20BC..2343. Every coding nibble value is legal to index; FFFF is
 * still written to RAM and sets the return fault, rather than being skipped. */
uint8_t egs51_cal_select(Egs51 *s) {
    static const struct { uint16_t cell,table; uint8_t byte,shift; } t[]={
        {0x3b2,0xe8c2,0,0},{0x3b4,0xe8e2,0,0},{0x3bc,0xe902,0,4},
        {0x3ba,0xe922,0,4},{0x3c2,0xe9e2,0,4},{0x3ca,0xea22,0,4},
        {0x3be,0xe942,0,4},{0x3c8,0xe982,0,4},{0x3c6,0xe962,0,4},
        {0x3c0,0xe9a2,0,4},{0x3c4,0xe9c2,0,4},{0x3d0,0xea02,1,0},
        {0x3cc,0xea42,1,0},{0x3d2,0xea62,1,0},{0x3d4,0xe8a2,1,4},
        {0x3ce,0xe882,1,4}
    };
    uint8_t bad=0;
    for(unsigned k=0;k<sizeof(t)/sizeof(t[0]);k++) {
        unsigned n=(X(0x17b+t[k].byte)>>t[k].shift)&15;
        uint16_t p=RW(t[k].table+2*n);
        XP(t[k].cell,p); bad|=p==0xffff;
    }
    return bad;
}
/* Bank0 7138..7330. Independent coding cells/tables from bank1; coding179
 * nibble F selects variant0, while startup disables TCC for that coding. */
uint8_t egs51_cal_select_bank0(Egs51 *s) {
    static const struct { uint16_t cell,table,coding; uint8_t shift; } t[]={
        {0x3ac,0xecf0,0x177,0},{0x3a8,0xed70,0x177,4},
        {0x3aa,0xed90,0x177,4},{0x3a4,0xed10,0x178,0},
        {0x3a6,0xed30,0x178,0},{0x3ae,0xed50,0x178,4},
        {0x3b8,0xec90,0x179,0},{0x3b0,0xecb0,0x179,0},
        {0x3b6,0xecd0,0x17a,4}
    };
    uint8_t bad=0;
    for(unsigned k=0;k<sizeof(t)/sizeof(t[0]);k++) {
        unsigned n=(X(t[k].coding)>>t[k].shift)&15;
        if(t[k].coding==0x179 && n==15) n=0;
        uint16_t p=BW(t[k].table+2*n); XP(t[k].cell,p); bad|=p==0xffff;
    }
    if(X(0x183)>2 || X(0x184)<2 || X(0x184)>3) bad=1;
    X(0x32e)=X(0x185); if(!X(0x32e)) bad=1;
    if((X(0x175)!=B(0xfbfb) || X(0x176)<B(0xfbfc) || X(0x176)>B(0xfbfd)) &&
       (B(0xfbfc) || B(0xfbfd))) bad=1;
    return bad;
}
/* bank0 E48D..E603. All counters saturate at zero. No time-unit assumption. */
void egs51_timers_tick(Egs51 *s) {
    static const uint16_t bytes[]={0x2f4,0x2f3,0x380,0x20f,0x267,0x35f,
        0x335,0x338,0x2a3,0x37a,0x331,0x37d,0x383,0x316,0x2a4,
        0x359,0x34b,0x352,0x2a8,0x1ff,0x216,0x29c,0x284,0x2bd,0x215,0x38f};
    for(unsigned j=0;j<sizeof(bytes)/sizeof(bytes[0]);j++) if(X(bytes[j])) --X(bytes[j]);
    decword(&I(0xb7));
    for(unsigned a=0xb0;a<=0xb2;a++) if(I(a)) --I(a);
    decword(&X(0x354)); decword(&X(0x1dc)); decword(&X(0x2df));
    if(X(0x1c6)&0x10) { decword(&X(0x381)); decword(&X(0x27e)); }
}
/* bank0 CFB1..D258: logical GS218 transmit fields. No invented physical
 * meaning for unidentified bits. Torque request is floor(XRAM2F7 / 3), low
 * byte; FE is the inactive sentinel. The enable is a latched bit. */
void egs51_gs218_compose(Egs51 *s) {
    flag(&X(0x90),1,(I(0x97)&1) && ((X(0x90)&1) || XW(0x2f5)>0));
    flag(&X(0x1c8),2,X(0x90)&1);
    flag(&X(0x90),8,!(X(0x6f)&4) && (I(0x20)&0x10));
    flag(&X(0x90),2,I(0x20)&0x40);
    flag(&X(0x90),4,I(0x9a)&0x20);
    if(!(I(0x9a)&0x20)) X(0x29c)=B(0xffa1);
    if(!X(0x29c)) X(0x90)&=0xfb;
    flag(&X(0x90),0x10,X(0x1c5)&0x40);
    flag(&X(0x90),0x20,X(0x1bd)&0x40);
    uint8_t mode=I(0xb6),gear=I(0xb9),target=X(0x334);
    if((X(0x1cb)&0x80) || (((X(0x78)|X(0x73))&2) && target<=5) ||
       ((X(0x1c2)&0x40) && (X(0x1c6)&0x10))) {
        X(0x92)=255; X(0x226)=gear;
    } else if(mode==0 || mode==5) {
        if(target==8) { X(0x92)=0x88; X(0x226)=8; }
        else if(!(X(0x1c6)&0x10) || (I(0x9a)&0x10)) { X(0x92)=0; X(0x226)=gear; }
        else if(X(0x226)!=8 || target==6 || mode==0) {
            X(0x92)=(uint8_t)(((gear<<4)&0xf0)+gear); X(0x226)=gear;
        }
    } else X(0x92)=(uint8_t)(((gear<<4)&0xf0)+X(0x226));
    X(0x93)=B(0x1060)==1?0x10:0;
    flag(&X(0x93),2,I(0x20)&1);
    flag(&X(0x93),4,I(0x95)&0x40);
    flag(&X(0x93),8,X(0x78)&2);
    /* X264 is mode56 in the saved TCC context, not selector position. */
    static const uint8_t tcc_mode_bits[]={0x40,0xc0,0xc0,0x80,0xa0,0xa0,0x20};
    if(X(0x264)<7) X(0x93)|=tcc_mode_bits[X(0x264)];
    I(0x85)=(X(0x1cb)&0x10)?255:X(0x397);
    X(0x83)=(X(0x90)&1)?(uint8_t)(XW(0x2f7)/3):254;
    X(0x7e)=X(0x21e);
    if((X(0x73)&0xc0) || (X(0x74)&0x73)) { X(0x92)=255; I(0x85)=255; }
}
/* bank0 5ACA..5B4F, ISR register bank3. R3 is a signed-magnitude trim;
 * accumulator saturation uses OV, followed by the ROM's asymmetric rounding. */
uint8_t egs51_feedback_scale(uint8_t raw,uint8_t trim,uint16_t offset) {
    int32_t v=signed16(offset)+(trim&0x80 ? -1:1)*(int32_t)raw*(trim&0x7f);
    if(v < -32768) v=-32768;
    if(v > 32767) v=32767;
    uint16_t bits=(uint16_t)v; unsigned hi=bits>>8; unsigned out=raw;
    if(hi&0x80) {
        unsigned magnitude=(256-hi)&255;
        if(magnitude>=out) return 0;
        out-=magnitude;
        if((bits&0x80) && out) --out;
    } else {
        out+=hi;
        if(out>255) return 255;
        if((bits&0x80) && out<255) ++out;
    }
    return (uint8_t)out;
}
void egs51_current_interrupt(Egs51 *s,uint8_t page1,uint8_t page3) {
    uint16_t next=(uint16_t)(((S(0xfb)<<8)|S(0xfa))+BW(0xb3a));
    S(0xed)=(uint8_t)(next>>8); S(0xec)=(uint8_t)next;
    I(0x42)=egs51_feedback_scale(page1,X(0x188),XW(0x18a));
    I(0x43)=egs51_feedback_scale(page3,X(0x189),XW(0x18c));
    S(0x91)=3;
    if(X(0x78)&2) { I(0x37)=0; I(0x35)=0; }
    if(!I(0x37)) IP(0x31,B(0xb3c)<<8);
    if(!I(0x35)) IP(0x33,B(0xb3c)<<8);
    egs51_current_control(s);
    X(0)=S(0xf8)&15;
    if(X(0x101)==X(0)) ++X(3);
    else { X(0x101)=X(0); X(3)=0; }
}
