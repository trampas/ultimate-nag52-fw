/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x09be7c; FLS offset 0x01be7c.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

char egs52_register_sequence_09be7c(byte param_1)

{
  char cVar1;
  
  if (param_1 < 0x30 || 0x39 < param_1) {
    if (param_1 < 0x41 || 0x46 < param_1) {
      cVar1 = -1;
    }
    else {
      cVar1 = param_1 - 0x37;
    }
  }
  else {
    cVar1 = param_1 - 0x30;
  }
  return cVar1;
}


