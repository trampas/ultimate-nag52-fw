/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x099450; FLS offset 0x019450.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x099454) */

void egs52_update_near_c1aa_099450(void)

{
  uint uVar1;
  
  uVar1 = Ram00ffcc;
  Ram00ffcc = uVar1 & 0xffdf;
  Ram00c1aa = 1;
  return;
}


