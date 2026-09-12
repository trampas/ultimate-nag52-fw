/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d82da; FLS offset 0x0582da.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d834e) */
/* WARNING: Removing unreachable block (ram,0x0d8334) */
/* WARNING: Removing unreachable block (ram,0x0d832a) */
/* WARNING: Removing unreachable block (ram,0x0d831e) */
/* WARNING: Removing unreachable block (ram,0x0d8318) */
/* WARNING: Removing unreachable block (ram,0x0d8312) */
/* WARNING: Removing unreachable block (ram,0x0d82fe) */
/* WARNING: Removing unreachable block (ram,0x0d82f6) */
/* WARNING: Removing unreachable block (ram,0x0d82f2) */
/* WARNING: Removing unreachable block (ram,0x0d82ee) */
/* WARNING: Removing unreachable block (ram,0x0d82e6) */
/* WARNING: Removing unreachable block (ram,0x0d82e2) */

void egs52_compute_from_near_d4d2_0d82da(byte param_1,undefined2 param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  ulong uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined2 uVar8;
  int iVar9;
  int iVar10;
  undefined2 uVar11;
  
  iVar10 = 0;
  uVar2 = Ram00d4d2;
  uVar3 = Ram00d4ae;
  if (uVar3 <= uVar2) {
    iVar10 = Ram00d4ae;
    iVar7 = Ram00f63a;
    uVar3 = iVar7 + 0x4c;
    uVar1 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    uVar5 = Ram00d46a;
    uVar4 = (ulong)(uVar2 - iVar10) * (ulong)uVar5;
    param_2 = (undefined2)uVar4;
    iVar10 = (int)(uVar4 / *(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)));
  }
  iVar7 = Ram00d546;
  uVar2 = Ram00d532;
  if ((uint)(iVar10 + iVar7) < uVar2) {
    uVar11 = 0;
  }
  else {
    iVar6 = Ram00d532;
    iVar9 = Ram00f63a;
    uVar3 = iVar9 + 4 + (uint)param_1;
    uVar2 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar2 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    uVar4 = (ulong)(uint)((iVar10 + iVar7) - iVar6) *
            (ulong)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar3 & 0x3fff));
    param_2 = (undefined2)uVar4;
    uVar11 = (undefined2)(uVar4 / 100);
  }
  uVar8 = Ram00d556;
  egs52_compute_from_near_f626_0d7c4e(param_1,uVar8,uVar11,param_2);
  return;
}


