/* A0215451432 bank0 diagnostic/status tasks; each entry is identified below.
 * Preserve raw flags and timer units; this is not a replacement fault policy. */
#include "egs51_internal.h"
void egs51_diagnostic_latches(Egs51 *s) { /* E01E..E0CA */
    uint8_t enable=B(0xfef5);
    if(enable&0x20) {
        if(X(0x73)&0x20) { I(0x28)&=0xdf; X(0x2e8)=0; }
        else if(X(0x2e8)>B(0xff37)) I(0x28)|=0x20;
    }
    if(enable&0x10) {
        if(X(0x73)&0x10) { I(0x28)&=0xef; X(0x2fb)=0; }
        else if(X(0x2fb)>B(0xff38)) I(0x28)|=0x10;
    }
    if(enable&4) {
        if(X(0x73)&4) { I(0x28)&=0xfb; X(0x1c0)&=0xef; }
        else if(X(0x1c0)&0x10) I(0x28)|=4;
    }
    if(enable&8) {
        if(X(0x73)&8) {
            I(0x28)&=0xf7;
            if(!(I(0x2b)&0x80) && !(X(0x79)&2)) X(0x120)&=0xf0;
        } else if((X(0x120)&15)>B(0xff39) || (X(0x120)&0x80)) I(0x28)|=8;
    }
}
static uint8_t bit8(unsigned n) { return n<8?(uint8_t)(1u<<n):0; }
void egs51_diagnostic_scan(Egs51 *s) { /* E0CB..E213 */
    if(XW(0x275)>=450) X(0x78)|=0x20;
    if(!(X(0x78)&2) && I(0xb9)>=B(0xff7f) && !I(0xb6) && XW(0x2ac)>BW(0xff80)) {
        if(!X(0x34b) && (X(0x78)&0x20)) X(0x78)|=0x10;
    } else X(0x34b)=B(0xff7e);
    X(0x2ae)++; if(X(0x2ae)>16) X(0x2ae)=1;
    X(0x21e)=X(0x2ae);
    int fault=0;
    if(X(0x78)&1) {
        /* The low product byte is added to 7B before carrying into FE;
         * MUL's high byte is deliberately discarded by the ROM. */
        uint16_t row=(uint16_t)(0xfe7b+(uint8_t)(7u*X(0x2ae)));
        for(unsigned k=0;k<7;k++) {
            uint8_t source=B(row+k);
            if(source==255) continue;
            if(source<128) fault|=!!(X(0xdb+(source>>3))&bit8(source&7));
            else if(source<136) fault|=!!(X(0x1ca)&bit8(source-128));
            else fault|=!!(X(0x1cb)&bit8((uint8_t)(source+0x78)));
        }
    }
    if(fault && (X(0x78)&0x20)) X(0x21e)|=0x80;
    else if(!(X(0x78)&0x10)) X(0x21e)|=0x40;
}
void egs51_input_fault_summary(Egs51 *s) { /* E214..E25F */
    flag(&X(0x78),4,(X(0x6e)&0x1c) || (X(0x1cb)&0x41) || (X(0x71)&9) || (X(0x73)&0x20));
}

void egs51_range_speed_latches(Egs51 *s) { /* bank0 913D..920E */
    if(X(0x1cb)&1) { X(0x1bd)&=0xfc; I(0x20)&=0x7f; return; }
    uint16_t speed=XW(0x2ef);
    if(speed>BW(0xfc3e)) {
        if(speed<=BW(0xfc84)) X(0x1bd)&=0xdf;
        if(X(0x334)==7 && !(X(0x1bd)&1)) {
            X(0x1bd)|=0x10;
            if(speed>BW(0xfc86)) X(0x1bd)|=0x20;
        } else { X(0x1bd)|=1; I(0x20)|=0x80; }
    } else if(speed<=BW(0xfc3c)) { X(0x1bd)&=0xce; I(0x20)&=0x7f; }
    flag(&X(0x1bd),2,X(0x1bd)&((X(0x1c6)&4)?0x10:0x20));
}
void egs51_status_compose(Egs51 *s) { /* bank0 D259..D3A4 */
    X(0x1c4)=(uint8_t)((X(0x328)<<4) | ((X(0x1c5)&0x10)>>4) |
        ((X(0x1c5)&8)>>2) | ((X(0x1c8)&0x40)>>4) | ((X(0x1c7)&0x20)>>2));
    X(0x1c3)=(X(0x1c3)&0x80) | ((X(0x1c8)&8)>>3) |
        ((X(0x1c7)&8)>>2) | ((X(0x1c8)&0x10)>>2) |
        ((X(0x1c5)&0x20)>>2) | ((X(0x1c5)&3)<<4) | ((X(0x1c7)&0x10)<<2);
    X(0x1c1)=(X(0x1c1)&0xe8) | ((I(0x20)&0x10)>>4) |
        ((I(0x20)&0x40)>>5) | ((I(0x2b)&0x20)>>3) | ((I(0x20)&0x80)>>3);
    X(0x1d3)=(X(0x94)&0x7f) | (X(0x8f)&0x80);
}

static uint32_t counter32(Egs51 *s,unsigned a) {
    return ((uint32_t)XW(a)<<16) | XW(a+2);
}
static void put_counter32(Egs51 *s,unsigned a,uint32_t value) {
    XP(a,(uint16_t)(value>>16)); XP(a+2,(uint16_t)value);
}
void egs51_usage_counters(Egs51 *s) { /* bank0 E260..E48C */
    if(!(X(0x1c6)&0x10)) return;
    if(!XW(0x27e)) {
        put_counter32(s,0x28a,counter32(s,0x28a)+1u);
        uint32_t total=counter32(s,0x119);
        XP(0x27e,BW(0xff56));
        uint8_t input=X(0x76);
        if(X(0x334)==6 || X(0x334)==8) {
            if(X(0x1ca)&4) input=B(0xff53);
        } else if(X(0x1ca)&2) input=(X(0x1ca)&4)?B(0xff53):X(0x97);
        if(input>B(0xff54)) {
            input=B(0xff54); X(0x297)++;
            if(X(0x297)>=B(0xff55)) { total=0x00ffffffu; X(0x297)=0; }
        } else X(0x297)=0;
        int index=((int)input-61)/10;
        if(index<0) index=0;
        total+=(uint32_t)X(0x388)*B(0xff5a+(unsigned)index);
        if(total>=0x00ffffffu) total=0x00ffffffu;
        if(!(X(0x79)&2)) put_counter32(s,0x119,total);
    }
    if(!XW(0x381)) {
        X(0x388)=1;
        if(!(I(0x2b)&0x80) && !(X(0x218)&X(0x79))) {
            XP(0x381,BW(0xff58));
            if(X(0x218)<16) { X(0x79)|=X(0x218); X(0x218)<<=1; }
            else { X(0x1bf)|=2; X(0x218)=2; }
        }
    }
    if(I(0x2b)&0x80) return;
    if((X(0x1bf)&3)==3 && !(X(0x79)&0x10)) {
        put_counter32(s,0x169,counter32(s,0x28a));
        X(0x79)|=0x10; X(0x1bf)&=0xfc;
    }
    if((X(0x1c8)&0x80) && !(X(0x79)&0x20)) { X(0x79)|=0x20; X(0x1c8)&=0x7f; }
}
