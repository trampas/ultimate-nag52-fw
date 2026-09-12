/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0e3520; FLS offset 0x063520.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0e3520) */

uint egs52_test_flag_fd56_bit4(void)

{
  uint uVar1;
  
  uVar1 = Ram00fd56;
  return uVar1 >> 4 & 1;
}


