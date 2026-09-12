/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a20ea; FLS offset 0x0220ea.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a20ea) */

bool egs52_compute_from_near_c504_0a20ea(void)

{
  byte bVar1;
  
  bVar1 = UNK_00c504;
  return (bVar1 & 8) != 0;
}


