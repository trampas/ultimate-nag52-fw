/* Map primitives and fill schedule. Addresses are bank-relative. */
#include "egs51_internal.h"
static unsigned byte_interval(const Egs51 *s,unsigned bank,uint16_t axis,unsigned n,uint8_t *v) {
    assert(n>=2);
    uint8_t lo=egs51_rom8(s,bank,axis),hi=egs51_rom8(s,bank,(uint16_t)(axis+n-1));
    if(*v<=lo) { *v=lo; return 1; }
    if(*v>=hi) { *v=hi; return n-1; }
    unsigned j=1;
    while(*v>egs51_rom8(s,bank,(uint16_t)(axis+j))) ++j;
    return j;
}
uint8_t egs51_map8(const Egs51 *s,unsigned bank,uint16_t desc,uint8_t x,uint8_t y) {
    unsigned nx=egs51_rom8(s,bank,desc+1),ny=egs51_rom8(s,bank,desc+3);
    uint16_t ax=egs51_rom16(s,bank,desc+4),ay=egs51_rom16(s,bank,desc+6),z=egs51_rom16(s,bank,desc+8);
    unsigned ix=byte_interval(s,bank,ax,nx,&x),iy=byte_interval(s,bank,ay,ny,&y);
    uint8_t x0=egs51_rom8(s,bank,ax+ix-1),x1=egs51_rom8(s,bank,ax+ix),row[2];
    for(unsigned k=0;k<2;k++) {
        unsigned off=(iy-1+k)*nx+ix-1;
        row[k]=(uint8_t)egs51_lerp(egs51_rom8(s,bank,z+off),egs51_rom8(s,bank,z+off+1),x0,x1,x);
    }
    return (uint8_t)egs51_lerp(row[0],row[1],egs51_rom8(s,bank,ay+iy-1),egs51_rom8(s,bank,ay+iy),y);
}
/* 12BE..1411: descriptor {input IRAM addr,count,axis word ptr,z word ptr}. */
uint16_t egs51_curve16(const Egs51 *s,unsigned bank,uint16_t desc,uint16_t x) {
    unsigned n=egs51_rom8(s,bank,desc+1);
    uint16_t ax=egs51_rom16(s,bank,desc+2),z=egs51_rom16(s,bank,desc+4);
    assert(n>=2);
    if(x<=egs51_rom16(s,bank,ax)) return egs51_rom16(s,bank,z);
    if(x>=egs51_rom16(s,bank,ax+2*(n-1))) return egs51_rom16(s,bank,z+2*(n-1));
    unsigned j=1;
    while(x>egs51_rom16(s,bank,ax+2*j)) ++j;
    return egs51_lerp(egs51_rom16(s,bank,z+2*(j-1)),egs51_rom16(s,bank,z+2*j),
                     egs51_rom16(s,bank,ax+2*(j-1)),egs51_rom16(s,bank,ax+2*j),x);
}
/* 6856..68BA: input comes from IRAM56, not entry R7. Index8 uses adaptive
 * byte XRAM173; other shifts use XRAM16D+IRAM56. Byte wrap precedes sign clamp. */
uint8_t egs51_fill_term(Egs51 *s) {
    uint8_t value=egs51_map8(s,1,XW(0x3c8),I(0x56),X(0x76));
    value=(uint8_t)(value+X(0x16d+(I(0xac)==8?6:I(0x56))));
    X(0x339)=value<128?value:0;
    return X(0x339);
}
/* 1838..1903: byte axis and byte values; firmware takes the low input byte. */
uint8_t egs51_curve8(const Egs51 *s,unsigned bank,uint16_t desc,uint8_t x) {
    unsigned n=egs51_rom8(s,bank,desc+1);
    uint16_t ax=egs51_rom16(s,bank,desc+2),z=egs51_rom16(s,bank,desc+4);
    unsigned j=byte_interval(s,bank,ax,n,&x);
    return (uint8_t)egs51_lerp(egs51_rom8(s,bank,z+j-1),egs51_rom8(s,bank,z+j),
        egs51_rom8(s,bank,ax+j-1),egs51_rom8(s,bank,ax+j),x);
}
