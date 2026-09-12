/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x094dcc; FLS offset 0x014dcc.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x094dcc) */
/* WARNING: Unknown calling convention */

ushort egs52_get_operating_mask(void)

{
  ushort uVar1;
  
  uVar1 = Ram00c070;
  return uVar1;
}


