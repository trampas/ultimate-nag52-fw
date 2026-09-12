/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d8cf8; FLS offset 0x058cf8.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d8d1c) */
/* WARNING: Removing unreachable block (ram,0x0d8d00) */
/* WARNING: Removing unreachable block (ram,0x0d8cf8) */

undefined2 egs52_update_near_d4ae_0d8cf8(uint param_1)

{
  ulong uVar1;
  uint uVar2;
  undefined1 uVar3;
  uint uVar4;
  
  uVar2 = Ram00d46e;
  uVar3 = UNK_00d577;
  uVar4 = egs52_update_near_d426_0d4338(uVar3);
  uVar1 = (ulong)uVar4 * (ulong)(param_1 & 0xff);
  Ram00d4ae = (int)(uVar1 / uVar2);
  return (int)uVar1;
}


