/* Bank-common SPI transaction and TCC interrupt state machine. Timing is in
 * hardware counter ticks; callbacks describe external transfers/compare writes. */
#include "egs51_internal.h"
void egs51_spi_exchange(Egs51 *s,uint8_t mode,const Egs51Io *io) {
    if(mode!=1 && mode!=2) return;
    assert(io && io->spi_byte);
    S(0xc7)=mode==1?3:6;
    if(mode==1) S(0x80)&=0x7f; else S(0x88)|=0x80;
    unsigned n=mode==1?2:X(0xfc);
    if(!n) n=1; /* mode2 loop body precedes the length test */
    for(unsigned j=0;j<n;j++) {
        S(0xc6)=X(0xfd+j); S(0xc7)|=0x80;
        S(0xc6)=io->spi_byte(io->context,S(0xc6)); S(0xc7)&=0x7f;
        X(0xfd+j)=S(0xc6);
        if(mode==2 && j==1 && X(0x195)==1) S(0xc7)=2;
    }
    if(mode==1) S(0x80)|=0x80; else S(0x88)&=0x7f;
}
static void next_tcc(Egs51 *s,uint16_t delta) {
    uint16_t next=(uint16_t)(XW(8)+delta); XP(8,next);
    S(0xef)=(uint8_t)(next>>8); S(0xee)=(uint8_t)next;
}
static void match(Egs51 *s,const Egs51Io *io,uint16_t delta,uint8_t control) {
    uint16_t next=(uint16_t)(((S(0xfb)<<8)|S(0xfa))+delta);
    S(0xf4)=(uint8_t)(next>>8); S(0xf3)=(uint8_t)next; S(0xdd)=control;
    if(io->compare) io->compare(io->context,next,control);
}
void egs51_tcc_interrupt(Egs51 *s,const Egs51Io *io) {
    I(0x2a)&=0xfe; X(0x12)&=15;
    if(X(0x78)&2) I(0x36)=0;
    switch(X(7)) {
    case 0:
        if(I(0x36)<14) {
            I(0x36)=0; next_tcc(s,5000); I(0x2a)&=0xfd; I(0x2a)|=1;
        } else {
            if(I(0x36)>238) {
                I(0x36)=255;
                X(0x12)|=(I(0x2a)&2)?B(0x88e + X(0xb)):B(0x89c);
                next_tcc(s,5000);
            } else {
                XP(5,BW(0x89d+2*I(0x36))); X(0x12)|=B(0x89c);
                if(I(0x36)<46) { next_tcc(s,(uint16_t)(5000-XW(5))); X(7)=2; }
                else { next_tcc(s,750); X(7)=1; }
            }
            I(0x2a)|=2;
        }
        if(X(0xa)==255) { I(0x2a)|=1; X(0x11)=2; }
        else if(X(0xa)<=55) { I(0x2a)|=1; X(0x11)=1; }
        X(0xa)=I(0x36);
        break;
    case 1:
        X(0x12)|=B(0x88e + X(0xb));
        next_tcc(s,(uint16_t)(4250-XW(5))); X(7)=2;
        break;
    case 2:
        next_tcc(s,XW(5)); X(7)=0; I(0x2a)&=0xfd;
        if(X(0xa)>55) { I(0x2a)|=1; X(0x11)=3; }
        break;
    default: break;
    }
    X(0xfd)=X(0x12); X(0xfe)=X(0x13);
    egs51_spi_exchange(s,1,io);
    if(!(I(0x2a)&2)) match(s,io,4,0x88);
    X(0xf)=X(0xfd);
    if(I(0x2a)&1) { X(0x10)=X(0xfe); flag(&I(0x2a),8,I(0x21)&0x80); }
    else X(0x10)=(X(0x10)&0xc0)|(X(0xfe)&0x3f);
    flag(&I(0x2a),4,I(0x21)&0x10);
    flag(&I(0x2a),0x10,I(0x21)&0x20);
    flag(&I(0x2a),0x20,I(0x21)&0x40);
    flag(&I(0x21),0x80,I(0x2a)&2);
    match(s,io,125,0x08);
}
/* B77B..B837: final TCC demand conversion, not the upstream slip controller. */
void egs51_tcc_demand(Egs51 *s) {
    if(!I(0x56)) { I(0x36)=0; return; }
    uint8_t curve=(uint8_t)egs51_curve16(s,0,0xedec,IW(0x4e));
    uint8_t temp=X(0x76)<B(0xfe66)?X(0x76):B(0xfe66);
    int32_t correction=signed16(BW(0xfe63))*temp/1000;
    X(0x360)=(uint8_t)(correction+B(0xfe65));
    int32_t v=curve+(X(0x360)<128?X(0x360):(int32_t)X(0x360)-256)
                   +(X(0x11e)<128?X(0x11e):(int32_t)X(0x11e)-256);
    uint16_t limit=BW(BW(0xedf0)+2*(B(0xeded)-1));
    I(0x36)=v<=0?0:(uint8_t)(v<limit?v:limit);
}
static uint16_t absword(uint16_t value) { return value<0x8000?value:(uint16_t)(0-value); }
/* 9F23..A04A: slip-related diagnostic timer and neutral demand override. */
void egs51_tcc_override(Egs51 *s) {
    if((X(0x1ca)&8) || (X(0x1cb)&12) || (X(0x73)&4) || I(0x56) ||
       absword(XW(0x1d4))<=BW(0xfe6c) || I(0xb6) || !(X(0x1c6)&8)) X(0x383)=B(0xfe78);
    else if(absword(XW(0x386))>=BW(0xfe6a)) {
        I(0x64)=6; I(0x65)=4; /* bank0 0BF3 diagnostic event bytes */
        X(0x383)=B(0xfe78);
    } else if(!X(0x383)) {
        I(0x64)=6; I(0x65)=4; X(0x1c0)|=0x10;
    }
    if(!I(0xb9) && (X(0x1c6)&8) && !(X(0x1c0)&0x20)) {
        if(!X(0x316)) X(0x1c0)|=0x20;
        else I(0x36)=(uint8_t)BW(BW(0xedf0)+2*(B(0xeded)-1));
    } else X(0x316)=B(0xfe79);
}
