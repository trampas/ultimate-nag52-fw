/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d151e; FLS offset 0x05151e.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d1642) */
/* WARNING: Removing unreachable block (ram,0x0d1648) */
/* WARNING: Removing unreachable block (ram,0x0d163a) */
/* WARNING: Removing unreachable block (ram,0x0d1632) */
/* WARNING: Removing unreachable block (ram,0x0d162e) */
/* WARNING: Removing unreachable block (ram,0x0d161c) */
/* WARNING: Removing unreachable block (ram,0x0d160e) */
/* WARNING: Removing unreachable block (ram,0x0d1608) */
/* WARNING: Removing unreachable block (ram,0x0d1604) */
/* WARNING: Removing unreachable block (ram,0x0d1600) */
/* WARNING: Removing unreachable block (ram,0x0d15ec) */
/* WARNING: Removing unreachable block (ram,0x0d15e6) */
/* WARNING: Removing unreachable block (ram,0x0d15e2) */
/* WARNING: Removing unreachable block (ram,0x0d15de) */
/* WARNING: Removing unreachable block (ram,0x0d15d4) */
/* WARNING: Removing unreachable block (ram,0x0d15c8) */
/* WARNING: Removing unreachable block (ram,0x0d15c2) */
/* WARNING: Removing unreachable block (ram,0x0d15b0) */
/* WARNING: Removing unreachable block (ram,0x0d15ac) */
/* WARNING: Removing unreachable block (ram,0x0d15a6) */
/* WARNING: Removing unreachable block (ram,0x0d15a0) */
/* WARNING: Removing unreachable block (ram,0x0d159c) */
/* WARNING: Removing unreachable block (ram,0x0d1592) */
/* WARNING: Removing unreachable block (ram,0x0d158a) */
/* WARNING: Removing unreachable block (ram,0x0d1584) */
/* WARNING: Removing unreachable block (ram,0x0d1580) */
/* WARNING: Removing unreachable block (ram,0x0d1576) */
/* WARNING: Removing unreachable block (ram,0x0d1570) */
/* WARNING: Removing unreachable block (ram,0x0d156a) */
/* WARNING: Removing unreachable block (ram,0x0d1566) */
/* WARNING: Removing unreachable block (ram,0x0d1556) */
/* WARNING: Removing unreachable block (ram,0x0d1552) */
/* WARNING: Removing unreachable block (ram,0x0d1546) */
/* WARNING: Removing unreachable block (ram,0x0d1542) */
/* WARNING: Removing unreachable block (ram,0x0d153e) */
/* WARNING: Removing unreachable block (ram,0x0d1538) */
/* WARNING: Removing unreachable block (ram,0x0d1524) */
/* WARNING: Removing unreachable block (ram,0x0d15fa) */
/* WARNING: Removing unreachable block (ram,0x0d1614) */
/* WARNING: Removing unreachable block (ram,0x0d1622) */

void egs52_update_near_d412_0d151e(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  char cVar4;
  byte bVar5;
  undefined1 uVar6;
  byte bVar7;
  int iVar8;
  uint uVar9;
  byte bVar10;
  int iVar11;
  
  uVar1 = Ram00fd34;
  if (((uVar1 & 4) != 0) && (uVar1 = Ram00fd34, (uVar1 & 8) == 0)) {
    cVar4 = UNK_00d59b;
    if (cVar4 == '\0') {
      Ram00d412 = 0;
      UNK_00d59b = 0xff;
      UNK_00d431 = 0;
      uVar1 = Ram00fd34;
      Ram00fd34 = uVar1 & 0xfff7;
    }
    iVar8 = egs52_update_near_d412_0d1464();
    iVar11 = Ram00f62c;
    uVar1 = iVar11 + 0x18;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    if (*(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) < iVar8) {
      uVar2 = iVar11 + 5;
      uVar1 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      iVar11 = Ram00d508;
      uVar1 = iVar11 - (uint)*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
      uVar9 = Ram00d524;
      uVar3 = Ram00d524;
      if ((uVar1 == uVar3 || uVar1 < uVar9) || (uVar1 = Ram00fd48, (uVar1 & 8) == 0)) {
        uVar1 = 0x24;
        if (((uVar2 & 0xc000) != 0) &&
           ((uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000 && (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000))
           )) {
          uVar1 = 3;
        }
        iVar11 = Ram00d524;
        uVar1 = iVar11 - (uint)*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
        uVar2 = Ram00d508;
        uVar9 = Ram00d508;
        if (uVar1 == uVar9 || uVar1 < uVar2) {
          return;
        }
        uVar1 = Ram00fd48;
        if ((uVar1 & 0x10) == 0) {
          return;
        }
      }
      uVar1 = Ram00fd34;
      Ram00fd34 = uVar1 | 8;
      uVar9 = Ram00d46e;
      bVar10 = UNK_00d477;
      iVar11 = Ram00f636;
      uVar1 = iVar11 + (uint)bVar10 * 2 + 0x18;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      bVar10 = UNK_00d4e1;
      uVar1 = (uint)(((ulong)*(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) *
                     (ulong)bVar10) / (ulong)uVar9);
      uVar2 = Ram00d4d2;
      uVar9 = Ram00d4d2;
      if (uVar1 == uVar9 || uVar1 < uVar2) {
        iVar11 = 1;
      }
      else {
        iVar11 = Ram00d4d2;
        iVar11 = uVar1 - iVar11;
      }
      cVar4 = UNK_00d59b;
      UNK_00d59b = -1 - cVar4;
      iVar8 = Ram00f62c;
      uVar1 = iVar8 + 0x22;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      bVar10 = UNK_00d579;
      uVar1 = (uint)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) &
              1 << (bVar10 - 1 & 0xf);
      if (uVar1 == 0) {
        uVar2 = iVar8 + 0x1b;
        uVar9 = 0x24;
        if ((((uVar2 & 0xc000) != 0) && (uVar9 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
           (uVar9 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
          uVar9 = 3;
        }
        bVar10 = *(byte *)((uint3)uVar9 << 0xe | (uint3)(uVar2 & 0x3fff));
      }
      else {
        iVar8 = Ram00f62c;
        uVar2 = iVar8 + 0x1c;
        uVar9 = 0x24;
        if ((((uVar2 & 0xc000) != 0) && (uVar9 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
           (uVar9 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
          uVar9 = 3;
        }
        bVar10 = *(byte *)((uint3)uVar9 << 0xe | (uint3)(uVar2 & 0x3fff));
      }
      bVar5 = UNK_00d59b;
      if (bVar10 < bVar5) {
        cVar4 = UNK_00d59b;
        UNK_00d59b = cVar4 - bVar10;
      }
      else {
        UNK_00d59b = 0;
      }
      bVar7 = egs52_update_near_d430_0d718c(uVar1,iVar11);
      bVar10 = UNK_00d59b;
      bVar5 = UNK_00d59b;
      if (bVar7 == bVar5 || bVar7 < bVar10) {
        uVar9 = egs52_update_near_d430_0d718c(iVar11);
        iVar11 = Ram00f636;
        uVar1 = iVar11 + 0x22;
        uVar2 = 0x24;
        if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        bVar10 = UNK_00d59b;
        if ((uint)bVar10 <
            (uVar9 & 0xff) + (uint)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff))) {
          UNK_00d431 = 0xff;
        }
        else {
          uVar6 = UNK_00d59b;
          egs52_update_near_d431_0d1498(uVar6);
        }
      }
      else {
        UNK_00d431 = 0xff;
      }
    }
  }
  return;
}


