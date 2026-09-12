/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a4430; FLS offset 0x024430.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

void egs52_update_near_f1c6_0a4430(void)

{
  uint uVar1;
  
  uVar1 = Ram00ffc4;
  Ram00ffc4 = uVar1 | 0x400;
  uVar1 = Ram00f1c6;
  Ram00f1c6 = uVar1 & 0xfbff;
  uVar1 = Ram00ffc6;
  Ram00ffc6 = uVar1 | 0x400;
  Ram00feb4 = 0xea5;
  Ram00ffb0 = 0x8011;
  Ram00ff6e = 0x4d;
  return;
}


