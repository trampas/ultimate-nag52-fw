/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d817a; FLS offset 0x05817a.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d81ea) */
/* WARNING: Removing unreachable block (ram,0x0d81d6) */
/* WARNING: Removing unreachable block (ram,0x0d81d0) */
/* WARNING: Removing unreachable block (ram,0x0d81c6) */
/* WARNING: Removing unreachable block (ram,0x0d81b2) */
/* WARNING: Removing unreachable block (ram,0x0d81ae) */
/* WARNING: Removing unreachable block (ram,0x0d819c) */
/* WARNING: Removing unreachable block (ram,0x0d8198) */
/* WARNING: Removing unreachable block (ram,0x0d8192) */
/* WARNING: Removing unreachable block (ram,0x0d818e) */
/* WARNING: Removing unreachable block (ram,0x0d818a) */
/* WARNING: Removing unreachable block (ram,0x0d8186) */
/* WARNING: Removing unreachable block (ram,0x0d8182) */

void egs52_compute_from_near_d4d2_0d817a(undefined1 param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  byte bVar7;
  undefined2 uVar8;
  int iVar9;
  int iStack_6;
  
  iVar3 = Ram00d4d2;
  iVar4 = Ram00d47c;
  iVar5 = Ram00d490;
  iVar6 = Ram00d4ac;
  iVar9 = Ram00d4b2;
  iVar9 = (((iVar3 + iVar4) - iVar5) + iVar6) - iVar9;
  iVar3 = Ram00f636;
  uVar1 = iVar3 + 0x34;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  iVar3 = -*(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
  if (iVar9 <= iVar3) {
    iVar9 = iVar3;
  }
  bVar7 = UNK_00d4e1;
  iVar3 = Ram00d46a;
  iVar4 = Ram00d546;
  uVar1 = (int)(((long)iVar9 * (long)iVar3) / (long)(int)(uint)bVar7) + iVar4;
  if ((int)uVar1 < 1) {
    iStack_6 = 0;
  }
  else {
    uVar2 = Ram00d532;
    if (uVar1 < uVar2) {
      iStack_6 = 0;
    }
    else {
      iStack_6 = Ram00d532;
      iStack_6 = uVar1 - iStack_6;
    }
  }
  uVar8 = Ram00d556;
  egs52_compute_from_near_f626_0d7c4e(param_1,uVar8,iStack_6);
  return;
}


