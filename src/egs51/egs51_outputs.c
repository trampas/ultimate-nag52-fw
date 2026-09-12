/* Output fragments of A0215451432. Board-trace channel identities from the
 * existing investigation: OUT1 Y5, OUT2 Y4, OUT3 Y3, OUT4 TCC.
 * SPI and TCC interrupt scheduling are NOT implemented by these fragments. */
#include "egs51_model.h"
void egs51_output_pattern(Egs51 *s) {
    if (s->x[0x1b3]) return; /* watchdog writes excluded */
    s->im[0x21]=(s->im[0x21]&0xf8)|(s->im[0x95]&7);
}
/* 0711: page9 input at XRAM21 is distinct from ATF at XRAM76. Neither its
 * physical units nor the duration of an inrush countdown tick are assumed.
 * Request bits08..0A and previous bits0C..0E alias IRAM21. */
void egs51_frame_compose(Egs51 *s) {
    uint8_t t=s->x[0x21],idx=t<105?5:t<131?4:3;
    s->x[0x14]=idx;
    if (s->x[0x78]&2) s->im[0x21]&=0xf8;
    s->sfr[0xa0-0x80]&=0xfb; /* P2.2 */
    uint8_t bits=s->im[0x21];
    if (bits&2) {
        if (!(bits&0x20)) s->x[0xd]=3;
        s->x[0x13]=egs51_rom8(s,0,s->x[0xd]?0x88d:0x87f+idx);
    } else s->x[0x13]=0;
    s->sfr[0x98-0x80]=0x40;
    if (bits&4) {
        if (!(bits&0x40)) s->x[0xe]=3;
        s->x[0x13]|=egs51_rom8(s,0,s->x[0xe]?0x89c:0x88e + idx);
    } else s->x[0x13]&=15;
    if (bits&1) {
        if (!(bits&0x10)) s->x[0xc]=3;
        s->x[0x12]=egs51_rom8(s,0,s->x[0xc]?0x88d:0x87f+idx);
    } else s->x[0x12]=0;
    s->sfr[0xa0-0x80]|=4;
    s->im[0x21]=(bits&0x8f)|((bits&7)<<4);
}
void egs51_shift_solenoid_select(Egs51 *s) {
    if (s->im[0xaa]) return;
    switch (s->im[0xac]) {
    case 1: case 4: case 5: case 8: s->im[0x95]|=1; break;
    case 2: case 6: s->im[0x95]|=2; break;
    case 3: case 7: s->im[0x95]|=4; break;
    default: break;
    }
}
void egs51_gear_map(Egs51 *s) {
    switch (s->x[0x334]) {
    case 8: s->im[0xb9]=0; s->x[0x223]=1; break;
    case 6: s->im[0xb9]=0; break;
    case 7: s->im[0xb9]=6; break;
    default: s->im[0xb9]=s->x[0x223]; break;
    }
}
