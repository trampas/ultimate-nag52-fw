/* A0215451432 bank1 B2C8..B707: OEM interpolation and signed adaptation cells. */
#include "egs51_internal.h"
static uint16_t absword(uint16_t v) { return signed16(v)<0?(uint16_t)(0-v):v; }
static int signed8(uint8_t v) { return v<128?v:(int)v-256; }
void egs51_adapt_weights(Egs51 *s,uint16_t x,uint16_t correction,uint16_t low,uint16_t high) {
    if(signed16(x)>=signed16(high)) x=high;
    if(signed16(x)<=signed16(low)) x=low;
    uint16_t sum=(uint16_t)(low+high);
    int32_t midpoint=signed16(sum); midpoint=midpoint>=0?midpoint/2:-((-midpoint+1)/2);
    if(signed16(x)<midpoint) {
        XP(0x2e5,correction);
        XP(0x38a,2u*egs51_signed_md(correction,(uint16_t)(x-low),(uint16_t)(high-low)));
    } else if(low==high) { XP(0x2e5,correction); XP(0x38a,correction); }
    else {
        XP(0x2e5,2u*egs51_signed_md(correction,(uint16_t)(high-x),(uint16_t)(high-low)));
        XP(0x38a,correction);
    }
}
uint8_t egs51_adapt_limit(const Egs51 *s,uint16_t value) {
    uint8_t limit=R(XW(0x3bc)+0x22);
    if(signed16(absword(value))<signed8(limit)) return (uint8_t)value;
    return signed16(value)<0?(uint8_t)(0-limit):limit;
}
static void add_cell(Egs51 *s,uint16_t cell,uint16_t correction) {
    assert(cell<sizeof(s->x));
    X(cell)=egs51_adapt_limit(s,(uint16_t)(signed8(X(cell))+correction));
}
void egs51_adapt_cells(Egs51 *s,uint16_t x,uint8_t offset) {
    uint16_t low=RW(XW(0x3bc)+0x26),high=RW(XW(0x3bc)+0x0c);
    if(x>=high) x=high;
    if(x<=low) x=low;
    int lower=x<(uint16_t)(low+high)/2;
    uint16_t distance=lower?(uint16_t)(x-low):(uint16_t)(high-x);
    uint16_t base=(uint16_t)(XW(0x305)+offset);
    uint16_t a=XW(0x38a),b=XW(0x2e5);
    uint16_t scaled_a=(uint16_t)(2u*egs51_signed_md(a,distance,(uint16_t)(high-low)));
    uint16_t scaled_b=(uint16_t)(2u*egs51_signed_md(b,distance,(uint16_t)(high-low)));
    add_cell(s,base,lower?a:scaled_a); add_cell(s,base+1,lower?scaled_a:a);
    add_cell(s,base+2,lower?b:scaled_b); add_cell(s,base+3,lower?scaled_b:b);
}
