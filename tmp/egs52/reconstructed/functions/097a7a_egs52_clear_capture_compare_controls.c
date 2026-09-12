/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x097a7a; FLS offset 0x017a7a.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

void egs52_clear_capture_compare_controls(void)

{
  Ram00ff30 = 0;
  Ram00ff32 = 0;
  return;
}


