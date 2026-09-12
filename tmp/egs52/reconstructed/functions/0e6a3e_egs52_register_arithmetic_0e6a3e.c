/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0e6a3e; FLS offset 0x066a3e.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

uint egs52_register_arithmetic_0e6a3e(uint param_1)

{
  byte bVar1;
  
  bVar1 = 8;
  do {
    param_1 = param_1 ^ param_1 >> bVar1;
    bVar1 = bVar1 >> 1;
  } while (1 < bVar1);
  return (param_1 & 3) + 1 >> 1 & 1;
}


