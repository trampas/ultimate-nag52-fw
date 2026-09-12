/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0994aa; FLS offset 0x0194aa.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0994b4) */
/* WARNING: Removing unreachable block (ram,0x0994aa) */

void egs52_update_near_c1aa_0994aa(void)

{
  uint uVar1;
  
  uVar1 = Ram00c1aa;
  if ((uVar1 & 0x100) != 0) {
    uVar1 = Ram00c1aa;
    Ram00c1aa = uVar1 | 2;
  }
  return;
}


