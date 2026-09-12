/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0dd674; FLS offset 0x05d674.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0dd7e8) */
/* WARNING: Removing unreachable block (ram,0x0dd7da) */
/* WARNING: Removing unreachable block (ram,0x0dd7d6) */
/* WARNING: Removing unreachable block (ram,0x0dd7c8) */
/* WARNING: Removing unreachable block (ram,0x0dd7d0) */
/* WARNING: Removing unreachable block (ram,0x0dd7c0) */
/* WARNING: Removing unreachable block (ram,0x0dd7b8) */
/* WARNING: Removing unreachable block (ram,0x0dd7b2) */
/* WARNING: Removing unreachable block (ram,0x0dd7ac) */
/* WARNING: Removing unreachable block (ram,0x0dd7a8) */
/* WARNING: Removing unreachable block (ram,0x0dd7a2) */
/* WARNING: Removing unreachable block (ram,0x0dd79e) */
/* WARNING: Removing unreachable block (ram,0x0dd798) */
/* WARNING: Removing unreachable block (ram,0x0dd794) */
/* WARNING: Removing unreachable block (ram,0x0dd78c) */
/* WARNING: Removing unreachable block (ram,0x0dd786) */
/* WARNING: Removing unreachable block (ram,0x0dd776) */
/* WARNING: Removing unreachable block (ram,0x0dd772) */
/* WARNING: Removing unreachable block (ram,0x0dd758) */
/* WARNING: Removing unreachable block (ram,0x0dd72a) */
/* WARNING: Removing unreachable block (ram,0x0dd722) */
/* WARNING: Removing unreachable block (ram,0x0dd71a) */
/* WARNING: Removing unreachable block (ram,0x0dd70e) */
/* WARNING: Removing unreachable block (ram,0x0dd706) */
/* WARNING: Removing unreachable block (ram,0x0dd6fe) */
/* WARNING: Removing unreachable block (ram,0x0dd6f8) */
/* WARNING: Removing unreachable block (ram,0x0dd6f4) */
/* WARNING: Removing unreachable block (ram,0x0dd76e) */
/* WARNING: Removing unreachable block (ram,0x0dd76a) */
/* WARNING: Removing unreachable block (ram,0x0dd766) */
/* WARNING: Removing unreachable block (ram,0x0dd762) */
/* WARNING: Removing unreachable block (ram,0x0dd6ea) */
/* WARNING: Removing unreachable block (ram,0x0dd6e0) */
/* WARNING: Removing unreachable block (ram,0x0dd6d8) */
/* WARNING: Removing unreachable block (ram,0x0dd6d2) */
/* WARNING: Removing unreachable block (ram,0x0dd6ce) */
/* WARNING: Removing unreachable block (ram,0x0dd6c8) */
/* WARNING: Removing unreachable block (ram,0x0dd6c4) */
/* WARNING: Removing unreachable block (ram,0x0dd6be) */
/* WARNING: Removing unreachable block (ram,0x0dd6ba) */
/* WARNING: Removing unreachable block (ram,0x0dd6b6) */
/* WARNING: Removing unreachable block (ram,0x0dd6ae) */
/* WARNING: Removing unreachable block (ram,0x0dd6a6) */
/* WARNING: Removing unreachable block (ram,0x0dd6a2) */
/* WARNING: Removing unreachable block (ram,0x0dd69e) */
/* WARNING: Removing unreachable block (ram,0x0dd694) */
/* WARNING: Removing unreachable block (ram,0x0dd690) */
/* WARNING: Removing unreachable block (ram,0x0dd680) */
/* WARNING: Removing unreachable block (ram,0x0dd67c) */
/* WARNING: Removing unreachable block (ram,0x0dd678) */
/* WARNING: Removing unreachable block (ram,0x0dd6f0) */
/* WARNING: Removing unreachable block (ram,0x0dd7f2) */

void egs52_update_near_d708_0dd674(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  byte bVar8;
  int iVar9;
  int iVar10;
  
  uVar1 = Ram00fd2c;
  Ram00fd2c = uVar1 & 0xffbf;
  Ram00d708 = 0;
  iVar9 = Ram00f652;
  uVar1 = iVar9 + 5;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  if ((*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) & 8) != 0) {
    uVar1 = iVar9 + 0xc0;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    iVar9 = Ram00d662;
    if ((*(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) < iVar9) &&
       (uVar1 = Ram00fd2c, (uVar1 & 0x40) == 0)) {
LAB_0dd6b6:
      iVar9 = Ram00f652;
      uVar1 = iVar9 + 0xc2;
      uVar2 = 0x24;
      if (((uVar1 & 0xc000) != 0) &&
         ((uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000 && (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000))))
      {
        uVar2 = 3;
      }
      uVar3 = Ram00d63e;
      if (*(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) < uVar3) {
        uVar1 = iVar9 + 0xc4;
        uVar2 = 0x24;
        if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        iVar10 = Ram00d63c;
        if (iVar10 <= *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff))) goto LAB_0dd6d8;
        uVar1 = iVar9 + 0xd0;
        uVar2 = 0x24;
        if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        iVar9 = *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
        iVar10 = Ram00d644;
        iVar4 = Ram00d644;
        if (iVar9 == iVar4 || iVar9 < iVar10) goto LAB_0dd6d8;
      }
      else {
LAB_0dd6d8:
        uVar1 = Ram00fd2c;
        if ((uVar1 & 0x40) == 0) goto LAB_0dd760;
      }
      cVar5 = UNK_00d704;
      if ((cVar5 == '\x03') && (cVar5 = UNK_00d650, cVar5 == '\0')) {
        iVar9 = Ram00d654;
        iVar10 = Ram00d6e8;
        iVar9 = iVar9 - iVar10;
        iVar10 = Ram00d654;
        iVar4 = Ram00d654;
        if (iVar9 != iVar4 && iVar10 <= iVar9) {
          iVar9 = Ram00d654;
        }
        Ram00d6e6 = iVar9;
        iVar4 = Ram00d6e6;
        iVar6 = Ram00f654;
        iVar7 = Ram00f654;
        iVar10 = Ram00d662;
        bVar8 = egs52_curve_u8('\n',(uchar *)(iVar6 + 0x6e),(uchar *)(iVar7 + 0x78),
                               (uchar)(iVar10 / 10));
        Ram00d708 = iVar9 - (int)(((long)iVar4 * (long)(int)(uint)bVar8) / 100);
        uVar1 = Ram00fd2c;
        Ram00fd2c = uVar1 | 0x40;
        goto LAB_0dd772;
      }
    }
    else {
      iVar9 = Ram00f652;
      uVar1 = iVar9 + 0xe2;
      uVar2 = 0x24;
      if (((uVar1 & 0xc000) != 0) &&
         ((uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000 && (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000))))
      {
        uVar2 = 3;
      }
      iVar9 = Ram00d662;
      if ((*(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) < iVar9) &&
         (uVar1 = Ram00fd2c, (uVar1 & 0x40) != 0)) goto LAB_0dd6b6;
    }
LAB_0dd760:
    uVar1 = Ram00fd2c;
    Ram00fd2c = uVar1 & 0xffbf;
    Ram00d708 = 0;
    iVar10 = Ram00d654;
    iVar9 = Ram00d63c;
    Ram00d6e8 = iVar10 - iVar9;
  }
LAB_0dd772:
  iVar9 = Ram00f652;
  uVar1 = iVar9 + 0xf4;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  if ((*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) & 0x20) == 0) {
    return;
  }
  iVar10 = Ram00d692;
  if (iVar10 == 0) {
LAB_0dd7f0:
    uVar1 = Ram00fd2c;
    Ram00fd2c = uVar1 & 0xffbf;
    Ram00d708 = 0;
  }
  else {
    cVar5 = UNK_00d704;
    if (cVar5 == '\x03') {
      uVar1 = iVar9 + 0x10e;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      uVar1 = *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
      uVar2 = Ram00d640;
      uVar3 = Ram00d640;
      if (uVar1 == uVar3 || uVar1 < uVar2) goto LAB_0dd7b8;
      uVar1 = iVar9 + 0x110;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      iVar9 = Ram00d644;
      if (iVar9 <= *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff))) goto LAB_0dd7b8;
      uVar1 = Ram00d64c;
      uVar2 = Ram00d6f2;
      uVar3 = Ram00d6f2;
      if ((uVar1 == uVar3 || uVar1 < uVar2) || (cVar5 = UNK_00d650, cVar5 != '\0')) goto LAB_0dd7b8;
    }
    else {
LAB_0dd7b8:
      uVar1 = Ram00fd2c;
      if ((uVar1 & 0x40) == 0) goto LAB_0dd7f0;
    }
    iVar9 = Ram00d63c;
    if (iVar9 < 0) {
      iVar9 = Ram00d63c;
      iVar9 = -iVar9;
    }
    else {
      iVar9 = Ram00d63c;
    }
    iVar10 = Ram00d64c;
    iVar4 = Ram00d6f2;
    iVar10 = iVar10 - iVar4;
    if (iVar10 < 1) {
      iVar10 = 0;
    }
    Ram00d708 = iVar9 - iVar10;
    uVar1 = Ram00fd2c;
    Ram00fd2c = uVar1 | 0x40;
  }
  return;
}


