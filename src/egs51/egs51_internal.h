#ifndef EGS51_INTERNAL_H
#define EGS51_INTERNAL_H
#include "egs51_model.h"
#define I(a) s->im[(a)]
#define X(a) s->x[(a)]
#define S(a) s->sfr[(a)-0x80]
#define IW(a) egs51_word(&I(a))
#define XW(a) egs51_word(&X(a))
#define IP(a,v) egs51_put(&I(a),(uint16_t)(v))
#define XP(a,v) egs51_put(&X(a),(uint16_t)(v))
#define R(a) egs51_rom8(s,1,(uint16_t)(a))
#define RW(a) egs51_rom16(s,1,(uint16_t)(a))
#define B(a) egs51_rom8(s,0,(uint16_t)(a))
#define BW(a) egs51_rom16(s,0,(uint16_t)(a))
static inline int32_t signed16(uint16_t v) { return v<0x8000?v:(int32_t)v-65536; }
static inline uint16_t md(uint16_t a,uint16_t b,uint16_t c) { assert(c); return (uint16_t)((uint32_t)a*b/c); }
static inline void flag(uint8_t *p,unsigned mask,int set) { *p=(uint8_t)((*p&~mask)|(set?mask:0)); }
static inline void decword(uint8_t *p) { uint16_t v=egs51_word(p); if(v) egs51_put(p,v-1); }
#endif
