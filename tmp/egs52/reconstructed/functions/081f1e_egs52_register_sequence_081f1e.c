/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x081f1e; FLS offset 0x001f1e.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

void egs52_register_sequence_081f1e(void)

{
  uint uVar1;
  
  Ram00fe56 = 0;
  Ram00ff9e = 0;
  uVar1 = Ram00ff50;
  Ram00ff50 = uVar1 & 0xff;
  uVar1 = Ram00ff50;
  Ram00ff50 = uVar1 | 0x4000;
  return;
}


