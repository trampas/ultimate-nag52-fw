/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x097036; FLS offset 0x017036.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x097044) */
/* WARNING: Removing unreachable block (ram,0x097036) */

void egs52_compute_from_near_c160_097036(void)

{
  uint uVar1;
  byte bVar2;
  
  bVar2 = UNK_00c160;
  if ((bVar2 & 1) != 0) {
    uVar1 = Ram00ff30;
    Ram00ff30 = uVar1 | 4;
    uVar1 = Ram00ff30;
    Ram00ff30 = uVar1 | 8;
    bVar2 = UNK_00c160;
    UNK_00c160 = bVar2 | 2;
  }
  return;
}


