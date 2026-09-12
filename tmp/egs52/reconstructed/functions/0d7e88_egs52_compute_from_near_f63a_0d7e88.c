/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d7e88; FLS offset 0x057e88.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d7ed0) */
/* WARNING: Removing unreachable block (ram,0x0d7ebe) */
/* WARNING: Removing unreachable block (ram,0x0d7eb8) */
/* WARNING: Removing unreachable block (ram,0x0d7eb4) */
/* WARNING: Removing unreachable block (ram,0x0d7ea0) */
/* WARNING: Removing unreachable block (ram,0x0d7e9c) */
/* WARNING: Removing unreachable block (ram,0x0d7e96) */
/* WARNING: Removing unreachable block (ram,0x0d7e92) */

void egs52_compute_from_near_f63a_0d7e88(byte param_1,undefined2 param_2)

{
  uint uVar1;
  uint uVar2;
  ulong uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined2 uVar8;
  uint uVar9;
  
  iVar4 = Ram00f63a;
  uVar1 = iVar4 + 0x4c;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  uVar6 = Ram00d49c;
  uVar5 = Ram00d46a;
  uVar9 = (uint)((ulong)uVar6 * (ulong)uVar5 >> 0x10);
  iVar7 = Ram00d546;
  uVar1 = (int)(((ulong)uVar6 * (ulong)uVar5 & 0xffff | (ulong)uVar9 << 0x10) /
               (ulong)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff))) + iVar7;
  uVar2 = Ram00d532;
  uVar5 = Ram00d532;
  if (uVar1 == uVar5 || uVar1 < uVar2) {
    uVar8 = 0;
  }
  else {
    iVar7 = Ram00d532;
    uVar9 = iVar4 + 4 + (uint)param_1;
    uVar2 = 0x24;
    if ((((uVar9 & 0xc000) != 0) && (uVar2 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    uVar3 = (ulong)(uVar1 - iVar7) * (ulong)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar9 & 0x3fff))
    ;
    uVar9 = (uint)uVar3;
    uVar8 = (undefined2)(uVar3 / 100);
  }
  egs52_compute_from_near_f626_0d7c4e(param_1,param_2,uVar8,uVar9);
  return;
}


