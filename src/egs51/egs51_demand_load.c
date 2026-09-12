/* Bank0 8814..913C: acceleration, road-load estimate and demand corrections. */
#include "egs51_internal.h"
static uint16_t avg(uint16_t old,uint16_t next,uint8_t n) {
    return (uint16_t)((signed16(old)*n+signed16(next))/(n+1));
}
static uint16_t mag(uint16_t n) { return n&0x8000?(uint16_t)(0u-n):n; }
static int enabled(Egs51 *s) { return X(0x377)&((X(0x1c6)&1)?0x40:4); }
void egs51_vehicle_acceleration(Egs51 *s) { /* 8814 */
    XP(0x1d1,egs51_signed_md((uint16_t)(XW(0x2ef)-XW(0x208)),XW(0x181),300));
    XP(0x208,XW(0x2ef));
    XP(0x213,XW(0x2ac)>BW(0xfc90)?avg(XW(0x213),XW(0x1d1),B(XW(0x3a8)+0x45)):0);
}
void egs51_road_load(Egs51 *s) { /* 889C */
    if(!enabled(s) || (X(0x1cb)&0x28)) { XP(0x1f3,0); return; }
    if(X(0x1c5)&0x20) { X(0x335)=B(0xfc49); return; }
    if(I(0xb6) || (X(0x1c7)&4)) { X(0x338)=B(0xfc4a); return; }
    if(X(0x335) || X(0x338)) return;
    uint16_t table=XW(0x3a4); uint8_t n; uint16_t divisor;
    if(signed16(XW(0x224))>0 || signed16(XW(0x1fb))>0) {
        n=B(XW(0x3a8)+0x43); divisor=md(BW(table+11),100,B(table+I(0xb9)));
    } else {
        n=B(XW(0x3a8)+0x44); divisor=md(BW(table+11),B(table+I(0xb9)+5),100);
    }
    if(XW(0x2ac)<=BW(0xfc90)) return;
    XP(0x235,avg(XW(0x235),egs51_signed_md(XW(0x1fb),100,4),n));
    uint16_t value=egs51_signed_md(XW(0x235),XW(0x270),divisor);
    value=egs51_signed_md(value,BW(0x1040+2u*I(0xb9)),750);
    XP(0x1cf,avg(XW(0x1cf),value,B(table+0x23)));
    XP(0x350,33u*egs51_curve8(s,0,XW(0x3a6),X(0x219)));
    value=egs51_signed_md(XW(0x213),BW(table+((X(0x1c5)&0x40)?0x15:11)+2u*I(0xb9)),3);
    XP(0x211,avg(XW(0x211),value,B(table+0x23+I(0xb9))));
    if(XW(0x2ac)>BW(0xfc40)) XP(0x393,XW(0x1cf)-XW(0x350)-XW(0x211));
    else XP(0x393,signed16(XW(0x393))/3);
    if(!(X(0x1c5)&8) && X(0x97)>(uint8_t)(B(0xfc82)-X(0x237))) X(0x237)=B(0xfc83);
    else { X(0x237)=0; if(signed16(XW(0x393))>0) XP(0x393,0); }
    int32_t raw=signed16(XW(0x393));
    XP(0x393,raw>10000?30000:raw<-10000?-30000:raw*3);
    int32_t old=signed16(XW(0x1f3)),next=signed16(XW(0x393));
    int32_t threshold=signed16(BW(0xfc92)),negative=signed16((uint16_t)(0u-BW(0xfc92)));
    if((old>threshold && next<negative) || (old<negative && next>threshold)) XP(0x1f3,XW(0x393));
    else {
        unsigned cal=(signed16(mag(XW(0x393)))>signed16(mag(XW(0x1f3))) &&
                      signed16(mag(XW(0x1f3)))>signed16(BW(0xfc75)))?0xfc72:0xfc73;
        XP(0x1f3,avg(XW(0x1f3),XW(0x393),B(cal)));
    }
}
void egs51_load_scale(Egs51 *s) { /* 8D72 */
    uint16_t table=XW(0x3b6),threshold;
    if(X(0x1c5)&0x40) threshold=BW(0xfc8e);
    else {
        threshold=BW(0xfc8c);
        if(signed16(XW(0x1f3))>0) threshold=(uint16_t)(threshold-md(B(table+0x3b),X(0x1cc),100));
    }
    uint16_t ceiling;
    if(XW(0x2ac)>md(B(0xfc43),BW(table+1),100)) ceiling=(uint16_t)(threshold*B(0xfc44));
    else {
        uint16_t p=md(100,XW(0x2ac),BW(table+1));
        ceiling=md(threshold,(uint16_t)(10000u-(uint16_t)((uint32_t)p*p)),100);
    }
    uint16_t floor=md(ceiling,B(0xfc45),100),load=mag(XW(0x1f3));
    uint16_t result=load>floor?md((uint16_t)(load-floor),100,(uint16_t)(ceiling-floor)):0;
    XP(0x29d,result>100?100:result);
}
void egs51_load_corrections(Egs51 *s) { /* 8EF9 */
    if(!enabled(s)) { X(0x38e)=0; XP(0x221,0); XP(0x244,0); return; }
    uint16_t table=XW(0x3b6); unsigned up=X(0x2d1),down=X(0x2eb);
    if(signed16(XW(0x1f3))>0) {
        uint16_t limit=md(BW(XW(0x3a8)+1),1000,BW(0x1040+2u*X(0x227)));
        uint16_t offset=BW(table+3+2u*up);
        XP(0x2b7,md((uint16_t)(XW(0x2ac)+offset),100,(uint16_t)(limit+offset)));
        uint16_t correction=md(md(XW(0x29d),XW(0x2b7),100),B(table+11+up),100);
        XP(0x221,md(XW(0x29d),BW(table+0x17+2u*up),100));
        X(0x38e)=(uint8_t)correction;
        XP(0x244,md(XW(0x29d),BW(table+15+2u*down),100)); X(0x1bc)&=0xfe;
    } else {
        X(0x38e)=0;
        XP(0x221,md(XW(0x29d),BW(table+0x27+2u*up),100));
        XP(0x244,md(XW(0x29d),BW(table+0x1f+2u*down),100));
        flag(&X(0x1bc),1,XW(0x244)>0 && XW(0x29d)>B(0xfc79));
    }
}
