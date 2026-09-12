/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d175c; FLS offset 0x05175c.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d1808) */
/* WARNING: Removing unreachable block (ram,0x0d1804) */
/* WARNING: Removing unreachable block (ram,0x0d17f8) */
/* WARNING: Removing unreachable block (ram,0x0d17ea) */
/* WARNING: Removing unreachable block (ram,0x0d17f4) */
/* WARNING: Removing unreachable block (ram,0x0d17dc) */
/* WARNING: Removing unreachable block (ram,0x0d17d6) */
/* WARNING: Removing unreachable block (ram,0x0d17d2) */
/* WARNING: Removing unreachable block (ram,0x0d17ce) */
/* WARNING: Removing unreachable block (ram,0x0d17c2) */
/* WARNING: Removing unreachable block (ram,0x0d17b6) */
/* WARNING: Removing unreachable block (ram,0x0d17b0) */
/* WARNING: Removing unreachable block (ram,0x0d17a2) */
/* WARNING: Removing unreachable block (ram,0x0d179e) */
/* WARNING: Removing unreachable block (ram,0x0d1796) */
/* WARNING: Removing unreachable block (ram,0x0d1792) */
/* WARNING: Removing unreachable block (ram,0x0d178e) */
/* WARNING: Removing unreachable block (ram,0x0d1780) */
/* WARNING: Removing unreachable block (ram,0x0d177c) */
/* WARNING: Removing unreachable block (ram,0x0d1776) */
/* WARNING: Removing unreachable block (ram,0x0d1770) */
/* WARNING: Removing unreachable block (ram,0x0d176c) */
/* WARNING: Removing unreachable block (ram,0x0d1760) */
/* WARNING: Removing unreachable block (ram,0x0d17f0) */
/* WARNING: Removing unreachable block (ram,0x0d17fe) */

void egs52_update_near_d59b_0d175c(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  char cVar6;
  byte bVar7;
  undefined1 uVar8;
  byte bVar9;
  int iVar10;
  
  uVar1 = Ram00fd34;
  if (((uVar1 & 4) != 0) && (uVar1 = Ram00fd34, (uVar1 & 8) == 0)) {
    uVar3 = Ram00d46e;
    bVar9 = UNK_00d477;
    iVar10 = Ram00f636;
    uVar1 = iVar10 + (uint)bVar9 * 2 + 0x18;
    uVar2 = 0x24;
    if (((uVar1 & 0xc000) != 0) &&
       ((uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000 && (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)))) {
      uVar2 = 3;
    }
    bVar9 = UNK_00d4e1;
    uVar3 = (uint)(((ulong)*(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) * (ulong)bVar9)
                  / (ulong)uVar3);
    iVar10 = Ram00f62c;
    uVar1 = iVar10 + 0x1e;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    iVar4 = Ram00d4d2;
    if ((uint)(*(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) + iVar4) <= uVar3) {
      uVar1 = iVar10 + 0x20;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      uVar1 = *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
      uVar2 = Ram00d500;
      uVar5 = Ram00d500;
      if (uVar1 == uVar5 || uVar1 < uVar2) {
        uVar1 = Ram00fd34;
        Ram00fd34 = uVar1 | 8;
        uVar1 = Ram00d4d2;
        uVar2 = Ram00d4d2;
        if (uVar3 == uVar2 || uVar3 < uVar1) {
          iVar10 = 1;
        }
        else {
          iVar10 = Ram00d4d2;
          iVar10 = uVar3 - iVar10;
        }
        cVar6 = UNK_00d59b;
        UNK_00d59b = -1 - cVar6;
        iVar4 = Ram00f62c;
        uVar1 = iVar4 + 0x22;
        uVar2 = 0x24;
        if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        bVar9 = UNK_00d579;
        uVar1 = (uint)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) &
                1 << (bVar9 - 1 & 0xf);
        if (uVar1 == 0) {
          uVar2 = iVar4 + 0x1b;
          uVar3 = 0x24;
          if ((((uVar2 & 0xc000) != 0) && (uVar3 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
             (uVar3 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
            uVar3 = 3;
          }
          bVar9 = *(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar2 & 0x3fff));
        }
        else {
          iVar4 = Ram00f62c;
          uVar2 = iVar4 + 0x1c;
          uVar3 = 0x24;
          if ((((uVar2 & 0xc000) != 0) && (uVar3 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
             (uVar3 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
            uVar3 = 3;
          }
          bVar9 = *(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar2 & 0x3fff));
        }
        bVar7 = UNK_00d59b;
        if (bVar9 < bVar7) {
          cVar6 = UNK_00d59b;
          UNK_00d59b = cVar6 - bVar9;
        }
        else {
          UNK_00d59b = 0;
        }
        uVar8 = UNK_00d59b;
        egs52_update_near_d431_0d1498(uVar8,uVar1,iVar10);
        return;
      }
    }
    uVar1 = Ram00fd34;
    Ram00fd34 = uVar1 & 0xfffb;
  }
  return;
}


