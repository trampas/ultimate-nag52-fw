/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d282c; FLS offset 0x05282c.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d2840) */
/* WARNING: Removing unreachable block (ram,0x0d283a) */
/* WARNING: Removing unreachable block (ram,0x0d2830) */

undefined2 egs52_scale_d500_by_indexed_coefficient(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = Ram00d500;
  iVar4 = Ram00f624;
  uVar1 = iVar4 + (param_1 & 0xff) * 2 + 6;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  return (int)(((ulong)uVar3 * (ulong)*(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff))) /
              1000);
}


