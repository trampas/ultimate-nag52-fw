/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a57f8; FLS offset 0x0257f8.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

void egs52_register_sequence_0a57f8(void)

{
  uint uVar1;
  
  uVar1 = Ram00ff6c;
  Ram00ff6c = uVar1 & 0xffbf;
  uVar1 = Ram00ff6e;
  Ram00ff6e = uVar1 & 0xffbf;
  uVar1 = Ram00ff70;
  Ram00ff70 = uVar1 & 0xffbf;
  return;
}


