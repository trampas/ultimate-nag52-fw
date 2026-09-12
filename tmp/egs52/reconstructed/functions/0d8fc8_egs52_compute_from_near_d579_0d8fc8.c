/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d8fc8; FLS offset 0x058fc8.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d916a) */
/* WARNING: Removing unreachable block (ram,0x0d9164) */
/* WARNING: Removing unreachable block (ram,0x0d9152) */
/* WARNING: Removing unreachable block (ram,0x0d914e) */
/* WARNING: Removing unreachable block (ram,0x0d913c) */
/* WARNING: Removing unreachable block (ram,0x0d9138) */
/* WARNING: Removing unreachable block (ram,0x0d9126) */
/* WARNING: Removing unreachable block (ram,0x0d9122) */
/* WARNING: Removing unreachable block (ram,0x0d911e) */
/* WARNING: Removing unreachable block (ram,0x0d9116) */
/* WARNING: Removing unreachable block (ram,0x0d9064) */
/* WARNING: Removing unreachable block (ram,0x0d9060) */
/* WARNING: Removing unreachable block (ram,0x0d9048) */
/* WARNING: Removing unreachable block (ram,0x0d9044) */
/* WARNING: Removing unreachable block (ram,0x0d9030) */
/* WARNING: Removing unreachable block (ram,0x0d902c) */
/* WARNING: Removing unreachable block (ram,0x0d901a) */
/* WARNING: Removing unreachable block (ram,0x0d9016) */
/* WARNING: Removing unreachable block (ram,0x0d9006) */
/* WARNING: Removing unreachable block (ram,0x0d9002) */
/* WARNING: Removing unreachable block (ram,0x0d8ffa) */
/* WARNING: Removing unreachable block (ram,0x0d8ff6) */
/* WARNING: Removing unreachable block (ram,0x0d8ff2) */
/* WARNING: Removing unreachable block (ram,0x0d90fe) */
/* WARNING: Removing unreachable block (ram,0x0d90fa) */
/* WARNING: Removing unreachable block (ram,0x0d90ea) */
/* WARNING: Removing unreachable block (ram,0x0d90e4) */
/* WARNING: Removing unreachable block (ram,0x0d90de) */
/* WARNING: Removing unreachable block (ram,0x0d90c6) */
/* WARNING: Removing unreachable block (ram,0x0d90c0) */
/* WARNING: Removing unreachable block (ram,0x0d90a4) */
/* WARNING: Removing unreachable block (ram,0x0d90a0) */
/* WARNING: Removing unreachable block (ram,0x0d908a) */
/* WARNING: Removing unreachable block (ram,0x0d9086) */
/* WARNING: Removing unreachable block (ram,0x0d9082) */
/* WARNING: Removing unreachable block (ram,0x0d907e) */
/* WARNING: Removing unreachable block (ram,0x0d8fea) */
/* WARNING: Removing unreachable block (ram,0x0d8fe2) */
/* WARNING: Removing unreachable block (ram,0x0d8fde) */
/* WARNING: Removing unreachable block (ram,0x0d8fcc) */
/* WARNING: Removing unreachable block (ram,0x0d8fda) */
/* WARNING: Removing unreachable block (ram,0x0d911a) */

uint egs52_compute_from_near_d579_0d8fc8(void)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  int iVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  byte bVar9;
  byte bVar10;
  uint uVar11;
  int iVar12;
  
  cVar5 = UNK_00d579;
  if ((cVar5 == '\x05') || (cVar5 == '\x06')) {
    iVar12 = Ram00f634;
    uVar11 = iVar12 + 0x34;
    uVar1 = 0x24;
    if ((((uVar11 & 0xc000) != 0) && (uVar1 = 0x21, (uVar11 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar11 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    bVar3 = *(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar11 & 0x3fff));
    bVar9 = UNK_00d570;
    bVar10 = UNK_00d570;
    if ((bVar3 == bVar10 || bVar3 < bVar9) || (uVar11 = Ram00fd4a, (uVar11 & 0x40) == 0)) {
      iVar7 = Ram00d4d2;
      iVar12 = Ram00d47c;
      iVar4 = Ram00d4ac;
      iVar6 = Ram00d4b2;
      uVar11 = (iVar7 + iVar12 + iVar4) - iVar6;
      if ((int)uVar11 < 1) {
        uVar11 = 0;
      }
      bVar3 = UNK_00d4df;
      uVar1 = Ram00d492;
      uVar1 = (uint)(((ulong)bVar3 * (ulong)uVar1) / 100);
      if (uVar11 < uVar1) {
        iVar12 = 0;
      }
      else {
        bVar3 = UNK_00d4e1;
        uVar2 = Ram00d46a;
        iVar12 = (int)(((ulong)(uVar11 - uVar1) * (ulong)uVar2) / (ulong)bVar3);
      }
      iVar4 = Ram00d546;
      uVar11 = Ram00d532;
      if ((uint)(iVar12 + iVar4) < uVar11) {
        uVar11 = 0;
      }
      else {
        iVar6 = Ram00d532;
        uVar11 = (iVar12 + iVar4) - iVar6;
      }
      iVar12 = Ram00f634;
      uVar1 = iVar12 + 0x1f;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      uVar11 = (uint)(((ulong)uVar11 *
                      (ulong)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff))) / 100);
    }
    else {
      iVar12 = Ram00d47c;
      iVar4 = Ram00d4ac;
      iVar6 = Ram00d4b2;
      bVar3 = UNK_00d4df;
      uVar11 = Ram00d492;
      iVar12 = ((iVar12 + iVar4) - iVar6) - (int)(((ulong)bVar3 * (ulong)uVar11) / 100);
      iVar4 = Ram00f636;
      uVar11 = iVar4 + 0x34;
      uVar1 = 0x24;
      if (((uVar11 & 0xc000) != 0) &&
         ((uVar1 = 0x21, (uVar11 & 0xc000) != 0x4000 && (uVar1 = 0x2c, (uVar11 & 0xc000) != 0x8000))
         )) {
        uVar1 = 3;
      }
      iVar4 = -*(int *)((uint3)uVar1 << 0xe | (uint3)(uVar11 & 0x3fff));
      if (iVar12 <= iVar4) {
        iVar12 = iVar4;
      }
      bVar3 = UNK_00d4e1;
      iVar4 = Ram00d46a;
      iVar7 = Ram00d546;
      iVar6 = Ram00d532;
      uVar11 = ((int)(((long)iVar12 * (long)iVar4) / (long)(int)(uint)bVar3) + iVar7) - iVar6;
      if ((int)uVar11 < 1) {
        uVar11 = 0;
      }
      iVar12 = Ram00f634;
      uVar1 = iVar12 + 0x1f;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      uVar11 = (uint)(((ulong)uVar11 *
                      (ulong)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff))) / 100);
    }
  }
  else {
    iVar8 = Ram00d4d2;
    iVar4 = Ram00d47c;
    iVar6 = Ram00d4ac;
    iVar7 = Ram00d4b2;
    iVar12 = Ram00d402;
    uVar11 = ((iVar8 + iVar4 + iVar6) - iVar7) - iVar12;
    if ((int)uVar11 < 1) {
      uVar11 = 0;
    }
    bVar3 = UNK_00d4e1;
    uVar1 = Ram00d46a;
    iVar4 = Ram00d546;
    iVar12 = Ram00d532;
    uVar11 = ((int)(((ulong)uVar11 * (ulong)uVar1) / (ulong)bVar3) + iVar4) - iVar12;
    if ((int)uVar11 < 1) {
      uVar11 = 0;
    }
  }
  uVar1 = Ram00d552;
  uVar2 = Ram00d552;
  if (uVar11 != uVar2 && uVar1 <= uVar11) {
    uVar11 = Ram00d552;
  }
  return uVar11;
}


