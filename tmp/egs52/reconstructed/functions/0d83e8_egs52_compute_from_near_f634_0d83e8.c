/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d83e8; FLS offset 0x0583e8.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d85c4) */
/* WARNING: Removing unreachable block (ram,0x0d85ae) */
/* WARNING: Removing unreachable block (ram,0x0d85aa) */
/* WARNING: Removing unreachable block (ram,0x0d8598) */
/* WARNING: Removing unreachable block (ram,0x0d8594) */
/* WARNING: Removing unreachable block (ram,0x0d8582) */
/* WARNING: Removing unreachable block (ram,0x0d857e) */
/* WARNING: Removing unreachable block (ram,0x0d857a) */
/* WARNING: Removing unreachable block (ram,0x0d8572) */
/* WARNING: Removing unreachable block (ram,0x0d84a0) */
/* WARNING: Removing unreachable block (ram,0x0d849a) */
/* WARNING: Removing unreachable block (ram,0x0d8496) */
/* WARNING: Removing unreachable block (ram,0x0d8484) */
/* WARNING: Removing unreachable block (ram,0x0d8480) */
/* WARNING: Removing unreachable block (ram,0x0d8468) */
/* WARNING: Removing unreachable block (ram,0x0d8464) */
/* WARNING: Removing unreachable block (ram,0x0d8450) */
/* WARNING: Removing unreachable block (ram,0x0d844c) */
/* WARNING: Removing unreachable block (ram,0x0d843a) */
/* WARNING: Removing unreachable block (ram,0x0d8436) */
/* WARNING: Removing unreachable block (ram,0x0d8426) */
/* WARNING: Removing unreachable block (ram,0x0d8422) */
/* WARNING: Removing unreachable block (ram,0x0d841a) */
/* WARNING: Removing unreachable block (ram,0x0d8416) */
/* WARNING: Removing unreachable block (ram,0x0d8412) */
/* WARNING: Removing unreachable block (ram,0x0d8554) */
/* WARNING: Removing unreachable block (ram,0x0d8550) */
/* WARNING: Removing unreachable block (ram,0x0d853e) */
/* WARNING: Removing unreachable block (ram,0x0d8538) */
/* WARNING: Removing unreachable block (ram,0x0d8534) */
/* WARNING: Removing unreachable block (ram,0x0d852a) */
/* WARNING: Removing unreachable block (ram,0x0d8524) */
/* WARNING: Removing unreachable block (ram,0x0d851e) */
/* WARNING: Removing unreachable block (ram,0x0d8506) */
/* WARNING: Removing unreachable block (ram,0x0d8500) */
/* WARNING: Removing unreachable block (ram,0x0d84e4) */
/* WARNING: Removing unreachable block (ram,0x0d84e0) */
/* WARNING: Removing unreachable block (ram,0x0d84ca) */
/* WARNING: Removing unreachable block (ram,0x0d84c6) */
/* WARNING: Removing unreachable block (ram,0x0d84c2) */
/* WARNING: Removing unreachable block (ram,0x0d84be) */
/* WARNING: Removing unreachable block (ram,0x0d840a) */
/* WARNING: Removing unreachable block (ram,0x0d8402) */
/* WARNING: Removing unreachable block (ram,0x0d83fe) */
/* WARNING: Removing unreachable block (ram,0x0d83fa) */
/* WARNING: Removing unreachable block (ram,0x0d8576) */

undefined2 egs52_compute_from_near_f634_0d83e8(char param_1)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  byte bVar9;
  byte bVar10;
  int iVar11;
  undefined2 uVar12;
  uint uVar13;
  int iVar14;
  
  if ((param_1 == '\x05') || (param_1 == '\x06')) {
    iVar14 = Ram00f634;
    uVar13 = iVar14 + 0x34;
    uVar1 = 0x24;
    if ((((uVar13 & 0xc000) != 0) && (uVar1 = 0x21, (uVar13 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar13 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    bVar3 = *(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar13 & 0x3fff));
    bVar9 = UNK_00d570;
    bVar10 = UNK_00d570;
    if ((bVar3 == bVar10 || bVar3 < bVar9) || (uVar13 = Ram00fd4a, (uVar13 & 0x40) == 0)) {
      iVar7 = Ram00d4d2;
      iVar14 = Ram00d47c;
      iVar4 = Ram00d4ac;
      iVar5 = Ram00d4b2;
      uVar13 = (iVar7 + iVar14 + iVar4) - iVar5;
      if ((int)uVar13 < 1) {
        uVar13 = 0;
      }
      bVar3 = UNK_00d4df;
      uVar1 = Ram00d492;
      uVar1 = (uint)(((ulong)bVar3 * (ulong)uVar1) / 100);
      if (uVar13 < uVar1) {
        iVar14 = 0;
      }
      else {
        bVar3 = UNK_00d4e1;
        uVar2 = Ram00d46a;
        iVar14 = (int)(((ulong)(uVar13 - uVar1) * (ulong)uVar2) / (ulong)bVar3);
      }
      iVar4 = Ram00d546;
      uVar13 = Ram00d532;
      if ((uint)(iVar14 + iVar4) < uVar13) {
        uVar13 = 0;
      }
      else {
        iVar5 = Ram00d532;
        uVar13 = (iVar14 + iVar4) - iVar5;
      }
      uVar2 = Ram00d550;
      uVar1 = Ram00d536;
      if (uVar2 < uVar1) {
        iVar14 = 0;
      }
      else {
        iVar14 = Ram00d536;
        iVar14 = uVar2 - iVar14;
      }
      iVar4 = Ram00f634;
      uVar1 = iVar4 + 0x1f;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      uVar12 = egs52_compute_from_near_f626_0d7c4e
                         (param_1 + -1,iVar14,
                          (int)(((ulong)uVar13 *
                                (ulong)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff))) /
                               100));
    }
    else {
      iVar14 = Ram00d47c;
      iVar4 = Ram00d4ac;
      iVar5 = Ram00d4b2;
      bVar3 = UNK_00d4df;
      uVar13 = Ram00d492;
      iVar14 = ((iVar14 + iVar4) - iVar5) - (int)(((ulong)bVar3 * (ulong)uVar13) / 100);
      iVar4 = Ram00f636;
      uVar13 = iVar4 + 0x34;
      uVar1 = 0x24;
      if (((uVar13 & 0xc000) != 0) &&
         ((uVar1 = 0x21, (uVar13 & 0xc000) != 0x4000 && (uVar1 = 0x2c, (uVar13 & 0xc000) != 0x8000))
         )) {
        uVar1 = 3;
      }
      iVar4 = -*(int *)((uint3)uVar1 << 0xe | (uint3)(uVar13 & 0x3fff));
      if (iVar14 <= iVar4) {
        iVar14 = iVar4;
      }
      bVar3 = UNK_00d4e1;
      iVar4 = Ram00d46a;
      iVar7 = Ram00d546;
      iVar5 = Ram00d532;
      uVar13 = ((int)(((long)iVar14 * (long)iVar4) / (long)(int)(uint)bVar3) + iVar7) - iVar5;
      if ((int)uVar13 < 1) {
        uVar13 = 0;
      }
      iVar14 = Ram00f634;
      uVar1 = iVar14 + 0x1f;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      uVar8 = Ram00d550;
      uVar6 = Ram00d536;
      if (uVar8 < uVar6) {
        iVar14 = 0;
      }
      else {
        iVar14 = Ram00d536;
        iVar14 = uVar8 - iVar14;
      }
      uVar12 = egs52_compute_from_near_f626_0d7c4e
                         (param_1 + -1,iVar14,
                          (int)(((ulong)uVar13 *
                                (ulong)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff))) /
                               100));
    }
  }
  else {
    iVar14 = Ram00d4d2;
    iVar5 = Ram00d47c;
    iVar7 = Ram00d4ac;
    iVar11 = Ram00d4b2;
    iVar4 = Ram00d402;
    uVar13 = ((iVar14 + iVar5 + iVar7) - iVar11) - iVar4;
    if ((int)uVar13 < 1) {
      uVar13 = 0;
    }
    bVar3 = UNK_00d4e1;
    uVar1 = Ram00d46a;
    iVar4 = Ram00d546;
    iVar14 = Ram00d532;
    iVar14 = ((int)(((ulong)uVar13 * (ulong)uVar1) / (ulong)bVar3) + iVar4) - iVar14;
    if (iVar14 < 1) {
      iVar14 = 0;
    }
    uVar12 = Ram00d556;
    uVar12 = egs52_compute_from_near_f626_0d7c4e(param_1 + -1,uVar12,iVar14,iVar14);
  }
  return uVar12;
}


