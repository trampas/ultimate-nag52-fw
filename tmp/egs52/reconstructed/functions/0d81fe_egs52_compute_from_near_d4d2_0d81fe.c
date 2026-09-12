/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d81fe; FLS offset 0x0581fe.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d82c6) */
/* WARNING: Removing unreachable block (ram,0x0d82ba) */
/* WARNING: Removing unreachable block (ram,0x0d82b4) */
/* WARNING: Removing unreachable block (ram,0x0d82ae) */
/* WARNING: Removing unreachable block (ram,0x0d8296) */
/* WARNING: Removing unreachable block (ram,0x0d8290) */
/* WARNING: Removing unreachable block (ram,0x0d8280) */
/* WARNING: Removing unreachable block (ram,0x0d827a) */
/* WARNING: Removing unreachable block (ram,0x0d8264) */
/* WARNING: Removing unreachable block (ram,0x0d8258) */
/* WARNING: Removing unreachable block (ram,0x0d8254) */
/* WARNING: Removing unreachable block (ram,0x0d8250) */
/* WARNING: Removing unreachable block (ram,0x0d8242) */
/* WARNING: Removing unreachable block (ram,0x0d823e) */
/* WARNING: Removing unreachable block (ram,0x0d822a) */
/* WARNING: Removing unreachable block (ram,0x0d8224) */
/* WARNING: Removing unreachable block (ram,0x0d8220) */
/* WARNING: Removing unreachable block (ram,0x0d821c) */
/* WARNING: Removing unreachable block (ram,0x0d820e) */
/* WARNING: Removing unreachable block (ram,0x0d820a) */
/* WARNING: Removing unreachable block (ram,0x0d8206) */

void egs52_compute_from_near_d4d2_0d81fe(byte param_1)

{
  uint uVar1;
  uint uVar2;
  ulong uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  byte bVar8;
  byte bVar9;
  undefined2 uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  uint uStack_6;
  
  iVar12 = Ram00d4d2;
  iVar13 = Ram00d4ac;
  iVar4 = Ram00d47c;
  uStack_6 = iVar12 + iVar13 + iVar4;
  if ((int)uStack_6 < 0) {
    uStack_6 = 0;
  }
  bVar9 = UNK_00d4e1;
  iVar12 = Ram00f63a;
  uVar11 = iVar12 + 0x4c;
  uVar1 = 0x24;
  if ((((uVar11 & 0xc000) != 0) && (uVar1 = 0x21, (uVar11 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uVar11 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  uVar7 = Ram00d4ae;
  bVar8 = UNK_00d4df;
  uVar6 = Ram00d492;
  iVar12 = Ram00d490;
  uVar5 = Ram00d490;
  iVar4 = Ram00f634;
  uVar2 = iVar4 + 0x16 + (uint)param_1;
  uVar14 = 0x24;
  if ((((uVar2 & 0xc000) != 0) && (uVar14 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
     (uVar14 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
    uVar14 = 3;
  }
  uVar3 = (ulong)uVar5 * (ulong)*(byte *)((uint3)uVar14 << 0xe | (uint3)(uVar2 & 0x3fff));
  uVar14 = (uint)uVar3;
  uVar11 = ((int)(((ulong)*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar11 & 0x3fff)) * (ulong)uVar7)
                 / (ulong)bVar9) + (int)(((ulong)bVar8 * (ulong)uVar6) / 100) + iVar12) -
           (int)(uVar3 / 100);
  uVar1 = Ram00d490;
  uVar2 = Ram00d490;
  if (uVar11 != uVar2 && uVar1 <= uVar11) {
    uVar11 = Ram00d490;
  }
  if (uStack_6 < uVar11) {
    iVar12 = 0;
  }
  else {
    bVar9 = UNK_00d4e1;
    uVar1 = Ram00d46a;
    uVar3 = (ulong)(uStack_6 - uVar11) * (ulong)uVar1;
    uVar14 = (uint)(uVar3 >> 0x10);
    iVar12 = (int)((uVar3 & 0xffff | (ulong)uVar14 << 0x10) / (ulong)bVar9);
  }
  iVar4 = Ram00d546;
  uVar11 = Ram00d532;
  if ((uint)(iVar12 + iVar4) < uVar11) {
    iVar13 = 0;
  }
  else {
    iVar13 = Ram00d532;
    iVar13 = (iVar12 + iVar4) - iVar13;
  }
  uVar10 = Ram00d556;
  egs52_compute_from_near_f626_0d7c4e(param_1,uVar10,iVar13,uVar14);
  return;
}


