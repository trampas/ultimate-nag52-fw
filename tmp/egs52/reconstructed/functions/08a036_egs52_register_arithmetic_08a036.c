/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x08a036; FLS offset 0x00a036.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

undefined4 egs52_register_arithmetic_08a036(uint param_1,uint param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = (param_1 & 0xff) << 3 | param_1 >> 0xd;
  iVar1 = 0;
  if ((param_3 & 4) != 0) {
    iVar1 = uVar2 << 2;
    uVar2 = ((param_1 & 0x1f00) >> 8) << 0xd | (param_2 & 0xff) << 5 | param_2 >> 0xb;
  }
  return CONCAT22(iVar1,uVar2);
}


