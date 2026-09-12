/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x081f30; FLS offset 0x001f30.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

void egs52_register_sequence_081f30(void)

{
  uint uVar1;
  undefined2 uVar2;
  uint uVar3;
  
  uVar1 = Ram00ffcc;
  uVar1 = uVar1 >> 5 & 1 ^ 1;
  __write_psw_bits(0x40,uVar1 << 6);
  uVar2 = Ram00ffcc;
  uVar3 = Ram00ffcc;
  Ram00ffcc = uVar3 & 0xffdf | uVar1 << 5;
  return;
}


