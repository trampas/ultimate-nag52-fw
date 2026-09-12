/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x095f8e; FLS offset 0x015f8e.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

void egs52_update_near_fd00_095f8e(char param_1)

{
  uint uVar1;
  
  if (param_1 == '\x01') {
    uVar1 = Ram00fd00;
    Ram00fd00 = uVar1 | 2;
  }
  return;
}


