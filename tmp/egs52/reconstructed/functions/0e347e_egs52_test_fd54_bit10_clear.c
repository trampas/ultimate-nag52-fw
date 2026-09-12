/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0e347e; FLS offset 0x06347e.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0e3480) */

bool egs52_test_fd54_bit10_clear(void)

{
  uint uVar1;
  
  uVar1 = Ram00fd54;
  return (uVar1 & 0x400) == 0;
}


