/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a68b2; FLS offset 0x0268b2.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Function: egs52_call_far_indirect replaced with injection: call_far_indirect */
/* WARNING: Removing unreachable block (ram,0x0a6918) */
/* WARNING: Removing unreachable block (ram,0x0a6916) */
/* WARNING: Removing unreachable block (ram,0x0a690a) */
/* WARNING: Removing unreachable block (ram,0x0a68f8) */
/* WARNING: Removing unreachable block (ram,0x0a68e6) */
/* WARNING: Removing unreachable block (ram,0x0a68d6) */
/* WARNING: Removing unreachable block (ram,0x0a68c8) */
/* WARNING: Removing unreachable block (ram,0x0a698a) */
/* WARNING: Removing unreachable block (ram,0x0a6988) */
/* WARNING: Removing unreachable block (ram,0x0a697e) */
/* WARNING: Removing unreachable block (ram,0x0a696c) */
/* WARNING: Removing unreachable block (ram,0x0a695a) */
/* WARNING: Removing unreachable block (ram,0x0a694a) */
/* WARNING: Removing unreachable block (ram,0x0a6942) */
/* WARNING: Removing unreachable block (ram,0x0a693c) */
/* WARNING: Removing unreachable block (ram,0x0a68ce) */

void egs52_update_near_fdec_0a68b2(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = Ram00fde8;
  if ((uVar2 & 1) == 0) {
    uVar2 = 0xbd6;
    uVar1 = 0;
    do {
      if (*(char *)((uint3)(uVar2 + 4 & 0x3fff) | 0x90000) == cRam00f582) {
        egs52_update_near_f581_0a69a6
                  ((*(byte *)((uint3)(uVar2 + 7 & 0x3fff) | 0x90000) & 0xf) << 8 |
                   (*(byte *)((uint3)(uVar2 + 6 & 0x3fff) | 0x90000) & 0xf) << 4 |
                   *(byte *)((uint3)(uVar2 + 5 & 0x3fff) | 0x90000) & 0xf);
        if (cRam00f581 != '\0') {
          return;
        }
        uVar1 = Ram00fdec;
        Ram00fdec = uVar1 | 1;
        (*(code *)((uint3)*(uint *)((uint3)(uVar2 + 2 & 0x3fff) | 0x90000) << 0x10 |
                  (uint3)*(uint *)((uint3)(uVar2 & 0x3fff) | 0x90000)))();
        return;
      }
      uVar2 = uVar2 + 8;
      uVar1 = uVar1 + 1;
    } while (uVar1 < 0xc);
  }
  else {
    uVar2 = 0xb66;
    uVar1 = 0;
    do {
      if (*(char *)((uint3)(uVar2 + 4 & 0x3fff) | 0x90000) == cRam00f582) {
        egs52_update_near_f581_0a69a6
                  ((*(byte *)((uint3)(uVar2 + 7 & 0x3fff) | 0x90000) & 0xf) << 8 |
                   (*(byte *)((uint3)(uVar2 + 6 & 0x3fff) | 0x90000) & 0xf) << 4 |
                   *(byte *)((uint3)(uVar2 + 5 & 0x3fff) | 0x90000) & 0xf);
        if (cRam00f581 != '\0') {
          return;
        }
        uVar1 = Ram00fdec;
        Ram00fdec = uVar1 | 1;
        (*(code *)((uint3)*(uint *)((uint3)(uVar2 + 2 & 0x3fff) | 0x90000) << 0x10 |
                  (uint3)*(uint *)((uint3)(uVar2 & 0x3fff) | 0x90000)))();
        return;
      }
      uVar2 = uVar2 + 8;
      uVar1 = uVar1 + 1;
    } while (uVar1 < 0xe);
  }
  return;
}


