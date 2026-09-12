/* Bank0 206E..2498, including fault qualification and startup/steady filtering.
 * External ADC reads are supplied in their original order. Units remain raw. */
#include "egs51_internal.h"
static uint8_t convert_sample(uint16_t mean) {
    uint16_t v=(uint16_t)(177u*(uint8_t)mean+0xcc0bu);
    return (uint8_t)((uint16_t)(2u*v)>>8);
}
void egs51_analog_scan(Egs51 *s,const Egs51AnalogInputs *in) {
    X(0x1d)=in->page7; X(0x22)=in->page5; X(0x21)=in->page9;
    I(0x80)=in->page_b; X(0x1e)=in->page11; X(0x20)=in->page13;
    S(0x91)=0x0f;
    uint16_t raw=(uint16_t)(2u*in->page_f_first+(in->page_f_second>>1));
    unsigned process=1,update=0,first=0,difference=0,status;
    unsigned forward=X(0x75)>=1 && X(0x75)<=5 && !(I(0x23)&0x80) &&
        !(I(0x24)&1) && !(X(0x6e)&0x80) && !(X(0x6f)&1) && !(X(0x78)&8);
    X(0x15)&=0x7f;
    if(raw<51 || raw>307) {
        flag(&X(0x15),1,raw>307); flag(&X(0x15),2,raw<51);
        X(0x1f)=10; XP(0x23,0); process=0; X(0x15)&=0xfb;
        if(!(X(0x15)&8)) X(0x15)|=0x80;
        if(raw<51) { status=0; X(0x15)&=0xbf; }
        else if(forward && X(0x1b7)!=255) { status=1; X(0x15)&=0xbf; }
        else {
            status=2;
            if(X(0x75)==8 || X(0x75)==6 || (X(0x6e)&0x80) || (X(0x6f)&1)) {
                if(X(0x15)&0x40) {
                    if(X(0x18)) --X(0x18); else X(0x15)|=0x80;
                } else { X(0x18)=249; X(0x15)|=0x40; }
            } else X(0x15)&=0xbf;
        }
    } else {
        X(0x15)&=0xbc;
        if(raw<76) raw=76;
        if(raw>238) raw=238;
        if(X(0x1f)) {
            unsigned n=X(0x1f);
            if(n<=8) {
                X(0x15)|=8; XP(0x23,(uint16_t)(XW(0x23)+XW(0x19)));
                X(0x17)=convert_sample((uint16_t)(XW(0x23)/(9-n))); update=1;
            }
            --X(0x1f); process=0;
            if(!X(0x1f)) { X(0x16)=8; XP(0x23,0); }
        }
        status=forward?4:3;
    }
    if(process) {
        if(!X(0x16)) {
            uint8_t next=convert_sample(XW(0x23)>>3);
            XP(0x23,0); X(0x16)=8;
            if(!(X(0x15)&4)) { X(0x15)|=4; first=1; X(0x15)&=0xef; }
            else {
                difference=X(0x17)>next?X(0x17)-next:next-X(0x17);
                flag(&X(0x15),0x10,difference>B(0xff35));
            }
            if((X(0x6f)&4) || !(X(0x15)&0x10)) X(0x17)=next;
            update=1;
        } else { XP(0x23,(uint16_t)(XW(0x23)+raw)); --X(0x16); }
    }
    if(X(0x6f)&4) {
        X(0x15)|=0x80; X(0x15)&=0xef;
        flag(&I(0x24),4,!(status==4 && difference<B(0xff3b) && X(0x17)<B(0xff45) && !first && (X(0x15)&4)));
        X(0x15)|=0x20;
    } else {
        flag(&I(0x24),4,status<=1 || (X(0x15)&0x10));
        if(X(0x15)&0x20) update=1;
        X(0x15)&=0xdf;
    }
    if(X(0x15)&0x80) X(0x76)=X(0x97);
    else if(!(X(0x15)&0x10) && update) X(0x76)=X(0x17);
    if(!!(I(0x20)&0x20)==!!(X(0x15)&1)) {
        if(!X(0x1c)) flag(&I(0x20),0x10,X(0x15)&1);
    } else { X(0x1c)=3; flag(&I(0x20),0x20,X(0x15)&1); }
    if(!!(I(0x2b)&0x10)==!!(X(0x15)&2)) {
        if(!X(0x1b)) flag(&I(0x2b),0x40,X(0x15)&2);
    } else { X(0x1b)=3; flag(&I(0x2b),0x10,X(0x15)&2); }
    XP(0x19,raw);
}
