/* Bank0 47A0..4CDB. CAN object bytes are supplied in original register order.
 * Hardware window timing and CAN identifier routing belong to the adapter. */
#include "egs51_internal.h"
static int pending(Egs51CanRx *rx,unsigned reg,unsigned bit) {
    int yes=rx->registers[reg]&bit; rx->registers[reg]&=(uint8_t)~bit; return yes;
}
static void valid_byte(Egs51 *s,unsigned value,unsigned dest,unsigned flags,unsigned mask) {
    flag(&I(flags),mask,value==255); if(value!=255) X(dest)=value;
}
static uint16_t raw_word(const Egs51CanRx *rx,unsigned high) {
    return (uint16_t)(rx->registers[high]*256u+rx->registers[high+1]);
}
void egs51_can_receive(Egs51 *s,Egs51CanRx *rx) {
#define C(a) (rx->registers[a])
    I(0x26)&=0x0b;
    if(pending(rx,5,8)) {
        valid_byte(s,C(0xde),0x9e,0x25,2); X(0x98)=C(0xdc);
        flag(&I(0x25),1,C(0xda)==255); if(C(0xda)!=255) I(0x86)=C(0xda);
        if(X(0x184)==3) X(0x7b)=((uint32_t)C(0xd9)*BW(0xff85))>>16;
        else { flag(&I(0x25),0x80,C(0xd9)==255);
            if(C(0xd9)!=255) X(0x7b)=((uint32_t)C(0xd9)*BW(0xff85))>>16; }
        X(0x96)=C(0xd8);
    } else I(0x26)|=0x20;
    if(pending(rx,4,0x10)) {
        valid_byte(s,C(0xa6),0x8b,0x25,0x20);
        if(C(0xa5)==255) I(0x25)|=8;
        else { X(0x86)=C(0xa5); valid_byte(s,C(0xa4),0x9b,0x25,8); }
        valid_byte(s,C(0xa3),0x7c,0x25,0x10); X(0x7a)=C(0xa2); X(0x80)=C(0xa0);
    } else I(0x26)|=0x20;
    if(pending(rx,4,0x20)) {
        flag(&I(0x26),4,C(0xa8)==255);
        if(C(0xa8)!=255) X(0x97)=C(0xa8)<216?C(0xa8)+10:225;
    } else I(0x26)|=4;
    if(X(0x183)<3) {
        if(pending(rx,4,0x40)) {
            XP(0xa0,raw_word(rx,0xb4)); flag(&I(0x24),0x40,XW(0xa0)==65535);
            if(XW(0xa0)!=65535) XP(0x84,XW(0xa0)>>1);
            XP(0xa0,raw_word(rx,0xb2)); flag(&I(0x24),0x80,XW(0xa0)==65535);
            if(XW(0xa0)!=65535) XP(0x81,XW(0xa0)>>1);
            X(0x91)=C(0xb1); X(0x8f)=C(0xb0);
            if(!(X(0x94)&1)) {
                if(!(X(0xa5)&8)) { X(0xa6)=5; X(0xa5)|=8; }
                flag(&X(0xa5),1,X(0x8f)&0x80);
                if((X(0xa5)&1)==((X(0xa5)>>1)&1)) {
                    if(!X(0xa6)) { flag(&X(0x94),2,X(0xa5)&1); X(0x94)|=1; }
                } else { X(0xa6)=5; flag(&X(0xa5),2,X(0xa5)&1); }
            }
        } else { I(0x26)|=0x10; if(X(0x71)&0x10) { X(0x94)&=0xfe; X(0xa6)=5; } }
        if(X(0x183)==2) {
            if(pending(rx,5,1)) {
                unsigned v=C(0xc0); flag(&I(0x26),0x80,(v&3)==3);
                if((v&3)==3) v=(v&0xfc)|(X(0x9c)&3);
                X(0x9c)=v;
            } else I(0x26)|=0x80;
        } else I(0x26)&=0x7f;
    } else if(X(0x183)==3 || X(0x183)==4) { I(0x24)&=15; I(0x26)&=0x6f; }
    if(pending(rx,4,1)) {
        XP(0xa0,raw_word(rx,0x86)); flag(&I(0x24),0x20,XW(0xa0)==65535);
        if(XW(0xa0)!=65535) XP(0x87,(X(0x94)&3)==3?md(XW(0xa0),4800,XW(0xa3)):XW(0xa0)>>1);
        XP(0xa0,raw_word(rx,0x84)); flag(&I(0x24),0x10,XW(0xa0)==65535);
        if(XW(0xa0)!=65535) {
            if((X(0x94)&3)==3) { if(I(0x24)&0x20) I(0x24)|=0x10; else XP(0x89,XW(0x87)); }
            else XP(0x89,XW(0xa0)>>1);
        }
        X(0x9d)=C(0x83)&0x7f; X(0x9f)=C(0x82); X(0x8e)=C(0x81); X(0x8d)=C(0x80);
    } else flag(&I(0x26),0x10,X(0x183)!=3 && X(0x183)!=4);
    if(pending(rx,4,8)) {
        X(0x7f)=C(0x9b); unsigned rpm=raw_word(rx,0x99);
        flag(&I(0x25),4,rpm==65535); if(rpm!=65535) IP(0x87,rpm);
        X(0x7d)=C(0x98);
    } else I(0x26)|=0x20;
    if(pending(rx,4,0x80)) X(0x8c)=C(0xb8);
    else flag(&I(0x26),0x40,B(0xff46)&0x40);
    if(X(0x184)==2) I(0x25)&=0xdd;
    else if(X(0x184)==255 || X(0x184)==0) { I(0x26)&=0x3f; X(0x94)=(X(0x94)|1)&0xfd; }
#undef C
}
