/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0990f6; FLS offset 0x0190f6.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0990f6) */

uint egs52_compute_from_near_c19f_0990f6(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  
  bVar4 = UNK_00c19f;
  uVar1 = Ram00ffc0;
  uVar2 = Ram00ffc0;
  uVar3 = Ram00ffc0;
  return (uint)bVar4 << 8 | ((uVar1 & 0x40) >> 6) << 7 | ((uVar2 & 0x20) >> 5) << 6 |
         ((uVar3 & 0x10) >> 4) << 5 | 3;
}


