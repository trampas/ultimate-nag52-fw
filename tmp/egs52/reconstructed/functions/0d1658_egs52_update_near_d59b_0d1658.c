/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d1658; FLS offset 0x051658.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d1748) */
/* WARNING: Removing unreachable block (ram,0x0d1744) */
/* WARNING: Removing unreachable block (ram,0x0d1738) */
/* WARNING: Removing unreachable block (ram,0x0d172a) */
/* WARNING: Removing unreachable block (ram,0x0d1734) */
/* WARNING: Removing unreachable block (ram,0x0d171c) */
/* WARNING: Removing unreachable block (ram,0x0d1716) */
/* WARNING: Removing unreachable block (ram,0x0d1712) */
/* WARNING: Removing unreachable block (ram,0x0d170e) */
/* WARNING: Removing unreachable block (ram,0x0d1704) */
/* WARNING: Removing unreachable block (ram,0x0d16f8) */
/* WARNING: Removing unreachable block (ram,0x0d16f2) */
/* WARNING: Removing unreachable block (ram,0x0d16e6) */
/* WARNING: Removing unreachable block (ram,0x0d16de) */
/* WARNING: Removing unreachable block (ram,0x0d16d8) */
/* WARNING: Removing unreachable block (ram,0x0d16d4) */
/* WARNING: Removing unreachable block (ram,0x0d16ca) */
/* WARNING: Removing unreachable block (ram,0x0d16c4) */
/* WARNING: Removing unreachable block (ram,0x0d16be) */
/* WARNING: Removing unreachable block (ram,0x0d16ba) */
/* WARNING: Removing unreachable block (ram,0x0d16aa) */
/* WARNING: Removing unreachable block (ram,0x0d16a6) */
/* WARNING: Removing unreachable block (ram,0x0d169e) */
/* WARNING: Removing unreachable block (ram,0x0d168c) */
/* WARNING: Removing unreachable block (ram,0x0d1688) */
/* WARNING: Removing unreachable block (ram,0x0d1682) */
/* WARNING: Removing unreachable block (ram,0x0d167c) */
/* WARNING: Removing unreachable block (ram,0x0d1678) */
/* WARNING: Removing unreachable block (ram,0x0d165e) */
/* WARNING: Removing unreachable block (ram,0x0d1730) */
/* WARNING: Removing unreachable block (ram,0x0d173e) */

void egs52_update_near_d59b_0d1658(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  char cVar6;
  byte bVar7;
  undefined1 uVar8;
  int iVar9;
  byte bVar10;
  int iVar11;
  
  uVar1 = Ram00fd34;
  if (((uVar1 & 4) != 0) && (uVar1 = Ram00fd34, (uVar1 & 8) == 0)) {
    iVar9 = egs52_update_near_d412_0d1464();
    uVar3 = Ram00d46e;
    bVar10 = UNK_00d477;
    iVar11 = Ram00f636;
    uVar1 = iVar11 + (uint)bVar10 * 2 + 0x18;
    uVar2 = 0x24;
    if (((uVar1 & 0xc000) != 0) &&
       ((uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000 && (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)))) {
      uVar2 = 3;
    }
    bVar10 = UNK_00d4e1;
    uVar1 = (uint)(((ulong)*(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) * (ulong)bVar10)
                  / (ulong)uVar3);
    uVar2 = Ram00d4d2;
    uVar3 = Ram00d4d2;
    if (uVar1 == uVar3 || uVar1 < uVar2) {
      uVar1 = Ram00fd34;
      Ram00fd34 = uVar1 & 0xfffb;
    }
    else {
      iVar11 = Ram00f62c;
      uVar2 = iVar11 + 0x18;
      uVar3 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar3 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      if (*(int *)((uint3)uVar3 << 0xe | (uint3)(uVar2 & 0x3fff)) < iVar9) {
        uVar3 = iVar11 + 5;
        uVar2 = 0x24;
        if ((((uVar3 & 0xc000) != 0) && (uVar2 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        iVar11 = Ram00d508;
        uVar2 = iVar11 - (uint)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar3 & 0x3fff));
        uVar4 = Ram00d524;
        uVar5 = Ram00d524;
        if ((uVar2 == uVar5 || uVar2 < uVar4) || (uVar2 = Ram00fd48, (uVar2 & 8) == 0)) {
          uVar2 = 0x24;
          if (((uVar3 & 0xc000) != 0) &&
             ((uVar2 = 0x21, (uVar3 & 0xc000) != 0x4000 &&
              (uVar2 = 0x2c, (uVar3 & 0xc000) != 0x8000)))) {
            uVar2 = 3;
          }
          iVar11 = Ram00d524;
          uVar2 = iVar11 - (uint)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar3 & 0x3fff));
          uVar3 = Ram00d508;
          uVar4 = Ram00d508;
          if (uVar2 == uVar4 || uVar2 < uVar3) {
            return;
          }
          uVar2 = Ram00fd48;
          if ((uVar2 & 0x10) == 0) {
            return;
          }
        }
        uVar2 = Ram00fd34;
        Ram00fd34 = uVar2 | 8;
        uVar2 = Ram00d4d2;
        uVar3 = Ram00d4d2;
        if (uVar1 == uVar3 || uVar1 < uVar2) {
          iVar11 = 1;
        }
        else {
          iVar11 = Ram00d4d2;
          iVar11 = uVar1 - iVar11;
        }
        cVar6 = UNK_00d59b;
        UNK_00d59b = -1 - cVar6;
        iVar9 = Ram00f62c;
        uVar1 = iVar9 + 0x22;
        uVar2 = 0x24;
        if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        bVar10 = UNK_00d579;
        if (((uint)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) &
            1 << (bVar10 - 1 & 0xf)) == 0) {
          uVar1 = iVar9 + 0x1b;
          uVar2 = 0x24;
          if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
             (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
            uVar2 = 3;
          }
          bVar10 = *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
        }
        else {
          iVar9 = Ram00f62c;
          uVar1 = iVar9 + 0x1c;
          uVar2 = 0x24;
          if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
             (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
            uVar2 = 3;
          }
          bVar10 = *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
        }
        bVar7 = UNK_00d59b;
        if (bVar10 < bVar7) {
          cVar6 = UNK_00d59b;
          UNK_00d59b = cVar6 - bVar10;
        }
        else {
          UNK_00d59b = 0;
        }
        uVar8 = UNK_00d59b;
        egs52_update_near_d431_0d1498(uVar8,iVar11);
      }
    }
  }
  return;
}


