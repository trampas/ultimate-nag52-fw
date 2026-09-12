/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x098b9e; FLS offset 0x018b9e.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Function: egs52_multiply_u32_registers replaced with injection: egs52_mul32_registers */
/* WARNING: Function: egs52_divide_s32_registers replaced with injection: egs52_sdiv32_registers */
/* WARNING: Removing unreachable block (ram,0x098bc4) */
/* WARNING: Removing unreachable block (ram,0x098b9e) */

undefined4 egs52_call_09212e_098b9e(uint param_1)

{
  ulong uVar1;
  int iVar2;
  
  iVar2 = Ram00fe56;
  uVar1 = ((ulong)(-iVar2 - 1) * (ulong)(param_1 & 0xff)) / 0xff;
  iVar2 = Ram00fe56;
  return CONCAT22((int)(uVar1 >> 0x10),(int)uVar1 + iVar2);
}


