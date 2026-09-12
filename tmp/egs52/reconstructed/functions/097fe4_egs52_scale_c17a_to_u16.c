/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x097fe4; FLS offset 0x017fe4.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Function: egs52_divide_u32_registers replaced with injection: egs52_udiv32_registers */
/* WARNING: Removing unreachable block (ram,0x097fe4) */

ulong egs52_scale_c17a_to_u16(void)

{
  uint uVar1;
  
  uVar1 = Ram00c17a;
  return ((ulong)uVar1 * 0xffff) / 24000;
}


