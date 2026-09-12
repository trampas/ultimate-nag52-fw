/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x095f98; FLS offset 0x015f98.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

void egs52_copy_six_status_bytes(uchar *param_1)

{
  egs52_memcpy_near(param_1,(uchar *)0xc0b2,6);
  return;
}


