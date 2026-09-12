/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0996a2; FLS offset 0x0196a2.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0996ca) */
/* WARNING: Removing unreachable block (ram,0x0996c4) */
/* WARNING: Removing unreachable block (ram,0x0996c0) */
/* WARNING: Removing unreachable block (ram,0x0996bc) */
/* WARNING: Removing unreachable block (ram,0x0996b8) */
/* WARNING: Removing unreachable block (ram,0x0996b0) */
/* WARNING: Removing unreachable block (ram,0x0996aa) */
/* WARNING: Removing unreachable block (ram,0x0996a2) */

void egs52_update_near_c2b0_0996a2(void)

{
  byte bVar1;
  char cVar2;
  
  bVar1 = UNK_00c1ac;
  if ((bVar1 & 0x80) != 0) {
    UNK_00c2b0 = 0;
    UNK_00c2b1 = 1;
    cVar2 = UNK_00c1af;
    UNK_00c1af = cVar2 + '@';
    UNK_00c2b3 = 0xff;
    UNK_00c2af = 0;
    cVar2 = UNK_00c1ad;
    UNK_00c2b2 = cVar2 + '\x01';
    egs52_update_near_d2d3_09bf7a(cVar2 + '\x01');
  }
  return;
}


