/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0964a2; FLS offset 0x0164a2.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0964a2) */
/* WARNING: Unknown calling convention */

ushort egs52_read_register_f052(void)

{
  ushort uVar1;
  
  uVar1 = Ram00f052;
  return uVar1;
}


