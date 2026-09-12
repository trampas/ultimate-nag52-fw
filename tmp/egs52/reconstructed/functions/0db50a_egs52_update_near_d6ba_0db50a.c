/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0db50a; FLS offset 0x05b50a.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0db758) */
/* WARNING: Removing unreachable block (ram,0x0db754) */
/* WARNING: Removing unreachable block (ram,0x0db73c) */
/* WARNING: Removing unreachable block (ram,0x0db708) */
/* WARNING: Removing unreachable block (ram,0x0db704) */
/* WARNING: Removing unreachable block (ram,0x0db700) */
/* WARNING: Removing unreachable block (ram,0x0db6fc) */
/* WARNING: Removing unreachable block (ram,0x0db6f0) */
/* WARNING: Removing unreachable block (ram,0x0db6ec) */
/* WARNING: Removing unreachable block (ram,0x0db6ea) */
/* WARNING: Removing unreachable block (ram,0x0db6e6) */
/* WARNING: Removing unreachable block (ram,0x0db6e2) */
/* WARNING: Removing unreachable block (ram,0x0db6e0) */
/* WARNING: Removing unreachable block (ram,0x0db6da) */
/* WARNING: Removing unreachable block (ram,0x0db6d2) */
/* WARNING: Removing unreachable block (ram,0x0db6ca) */
/* WARNING: Removing unreachable block (ram,0x0db6c0) */
/* WARNING: Removing unreachable block (ram,0x0db6ba) */
/* WARNING: Removing unreachable block (ram,0x0db738) */
/* WARNING: Removing unreachable block (ram,0x0db734) */
/* WARNING: Removing unreachable block (ram,0x0db730) */
/* WARNING: Removing unreachable block (ram,0x0db728) */
/* WARNING: Removing unreachable block (ram,0x0db71c) */
/* WARNING: Removing unreachable block (ram,0x0db714) */
/* WARNING: Removing unreachable block (ram,0x0db70e) */
/* WARNING: Removing unreachable block (ram,0x0db6b4) */
/* WARNING: Removing unreachable block (ram,0x0db6b0) */
/* WARNING: Removing unreachable block (ram,0x0db6aa) */
/* WARNING: Removing unreachable block (ram,0x0db6a6) */
/* WARNING: Removing unreachable block (ram,0x0db6a2) */
/* WARNING: Removing unreachable block (ram,0x0db69c) */
/* WARNING: Removing unreachable block (ram,0x0db698) */
/* WARNING: Removing unreachable block (ram,0x0db694) */
/* WARNING: Removing unreachable block (ram,0x0db682) */
/* WARNING: Removing unreachable block (ram,0x0db67a) */
/* WARNING: Removing unreachable block (ram,0x0db676) */
/* WARNING: Removing unreachable block (ram,0x0db666) */
/* WARNING: Removing unreachable block (ram,0x0db660) */
/* WARNING: Removing unreachable block (ram,0x0db654) */
/* WARNING: Removing unreachable block (ram,0x0db650) */
/* WARNING: Removing unreachable block (ram,0x0db648) */
/* WARNING: Removing unreachable block (ram,0x0db644) */
/* WARNING: Removing unreachable block (ram,0x0db640) */
/* WARNING: Removing unreachable block (ram,0x0db638) */
/* WARNING: Removing unreachable block (ram,0x0db630) */
/* WARNING: Removing unreachable block (ram,0x0db62a) */
/* WARNING: Removing unreachable block (ram,0x0db626) */
/* WARNING: Removing unreachable block (ram,0x0db622) */
/* WARNING: Removing unreachable block (ram,0x0db61a) */
/* WARNING: Removing unreachable block (ram,0x0db616) */
/* WARNING: Removing unreachable block (ram,0x0db60e) */
/* WARNING: Removing unreachable block (ram,0x0db606) */
/* WARNING: Removing unreachable block (ram,0x0db602) */
/* WARNING: Removing unreachable block (ram,0x0db5fa) */
/* WARNING: Removing unreachable block (ram,0x0db5f6) */
/* WARNING: Removing unreachable block (ram,0x0db5ee) */
/* WARNING: Removing unreachable block (ram,0x0db5e6) */
/* WARNING: Removing unreachable block (ram,0x0db590) */
/* WARNING: Removing unreachable block (ram,0x0db586) */
/* WARNING: Removing unreachable block (ram,0x0db576) */
/* WARNING: Removing unreachable block (ram,0x0db566) */
/* WARNING: Removing unreachable block (ram,0x0db55a) */
/* WARNING: Removing unreachable block (ram,0x0db546) */
/* WARNING: Removing unreachable block (ram,0x0db540) */
/* WARNING: Removing unreachable block (ram,0x0db5e2) */
/* WARNING: Removing unreachable block (ram,0x0db5de) */
/* WARNING: Removing unreachable block (ram,0x0db5da) */
/* WARNING: Removing unreachable block (ram,0x0db5d6) */
/* WARNING: Removing unreachable block (ram,0x0db5d2) */
/* WARNING: Removing unreachable block (ram,0x0db5ce) */
/* WARNING: Removing unreachable block (ram,0x0db5b6) */
/* WARNING: Removing unreachable block (ram,0x0db5ae) */
/* WARNING: Removing unreachable block (ram,0x0db5a6) */
/* WARNING: Removing unreachable block (ram,0x0db526) */
/* WARNING: Removing unreachable block (ram,0x0db518) */
/* WARNING: Removing unreachable block (ram,0x0db514) */
/* WARNING: Removing unreachable block (ram,0x0db534) */

int egs52_update_near_d6ba_0db50a(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  byte bVar5;
  uchar y;
  byte bVar6;
  ushort old;
  int iVar7;
  int iVar8;
  byte bVar9;
  char cVar10;
  uint uVar11;
  ushort uVar12;
  int iVar13;
  
  iVar13 = Ram00f652;
  uVar11 = iVar13 + 5;
  uVar1 = 0x24;
  if ((((uVar11 & 0xc000) != 0) && (uVar1 = 0x21, (uVar11 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uVar11 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  if (((*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar11 & 0x3fff)) & 0x80) != 0) &&
     (uVar11 = Ram00fd2c, (uVar11 & 0x300) == 0x200)) {
    iVar13 = Ram00d656;
    goto LAB_0db742;
  }
  uVar11 = Ram00fd2a;
  if ((uVar11 & 1) == 0) {
    iVar13 = Ram00f656;
    iVar3 = Ram00f656;
    uVar11 = Ram00d640;
    uVar11 = egs52_curve_u16(5,(ushort *)(iVar13 + 0x1a8),(ushort *)(iVar3 + 0x1b2),uVar11 / 0x1e);
    Ram00d6ba = 0;
    Ram00d6a2 = 0;
    Ram00d6bc = 0;
    iVar13 = Ram00f652;
    uVar1 = iVar13 + 0xce;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    Ram00d6e4 = *(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
  }
  else {
    y = UNK_00d648;
    uVar11 = Ram00d640;
    bVar9 = UNK_00d647;
    iVar13 = Ram00f656;
    bVar5 = UNK_00d647;
    iVar3 = Ram00f656;
    iVar7 = Ram00f656;
    bVar9 = egs52_map_u8('\x06','\x06',(uchar *)(iVar3 + -2 + (uint)bVar5 * 6),
                         (uchar *)(iVar7 + 0x1c + (uint)bVar5 * 6),
                         (uchar *)(iVar13 + 0x1c + (uint)bVar9 * 0x24),(uchar)(uVar11 / 0x1e),y);
    uVar11 = (uint)bVar9;
  }
  uVar1 = Ram00fd2a;
  if ((uVar1 & 0x400) != 0) {
    uVar1 = Ram00fd2a;
    if ((uVar1 & 1) == 0) {
      iVar13 = Ram00f652;
      uVar1 = iVar13 + 0xf4;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      if ((*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) & 8) != 0) goto LAB_0db60e;
    }
    iVar13 = Ram00f652;
    uVar1 = iVar13 + 0x7f;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    uVar11 = uVar11 + *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
  }
LAB_0db60e:
  uVar1 = Ram00fd5c;
  if ((uVar1 & 0x20) != 0) {
    iVar13 = Ram00f652;
    uVar1 = iVar13 + 0xca;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    uVar11 = uVar11 + *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
  }
  iVar13 = Ram00f652;
  uVar1 = iVar13 + 0xf7;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  bVar9 = *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
  bVar5 = UNK_00d649;
  bVar6 = UNK_00d649;
  if ((bVar9 != bVar6 && bVar5 <= bVar9) && (uVar1 = Ram00fd2c, (uVar1 & 0x20) != 0)) {
    uVar1 = iVar13 + 0xf8;
    uVar2 = 0x24;
    if (((uVar1 & 0xc000) != 0) &&
       ((uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000 && (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)))) {
      uVar2 = 3;
    }
    uVar11 = uVar11 + *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
  }
  iVar13 = Ram00f652;
  uVar1 = iVar13 + 0x5a;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  iVar3 = Ram00d644;
  if (*(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) < iVar3) {
    uVar1 = iVar13 + 0x58;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    uVar1 = *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
    uVar2 = Ram00d640;
    uVar4 = Ram00d640;
    if ((uVar1 == uVar4 || uVar1 < uVar2) || (uVar1 = Ram00fd2c, (uVar1 & 0x20) == 0))
    goto LAB_0db70e;
    cVar10 = UNK_00d650;
    if (cVar10 != '\0') {
      uVar1 = iVar13 + 0xf4;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      if ((*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) & 0x80) == 0) goto LAB_0db70e;
    }
    iVar13 = Ram00d6e0;
    iVar3 = Ram00d6e2;
    if (((iVar13 < iVar3) || (cVar10 = UNK_00d704, cVar10 != '\x03')) || (iVar13 < 0))
    goto LAB_0db70e;
    iVar3 = Ram00d6a2;
    iVar13 = Ram00d6e4;
    iVar13 = uVar11 + iVar3 + iVar13;
    iVar3 = Ram00d6e0;
    iVar7 = Ram00d6e0;
    if (iVar13 != iVar7 && iVar3 <= iVar13) {
      iVar13 = Ram00f652;
      uVar1 = iVar13 + 0x114;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      iVar3 = *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
      iVar7 = Ram00d6f6;
      iVar8 = Ram00d6f6;
      if (iVar3 != iVar8 && iVar7 <= iVar3) {
        uVar1 = iVar13 + 0x116;
        uVar2 = 0x24;
        if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        iVar13 = Ram00d644;
        if (*(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) < iVar13) goto LAB_0db6ba;
      }
      goto LAB_0db70e;
    }
LAB_0db6ba:
    iVar13 = Ram00d6e0;
    iVar3 = Ram00f652;
    uVar2 = iVar3 + 0x54;
    uVar1 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    iVar13 = (iVar13 - uVar11) - *(int *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
    if (iVar13 < 0) {
      iVar13 = 0;
    }
    iVar3 = Ram00f652;
    uVar4 = iVar3 + 0x18;
    uVar1 = 0x24;
    if ((((uVar4 & 0xc000) != 0) && (uVar1 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    if (*(int *)((uint3)uVar1 << 0xe | (uint3)(uVar4 & 0x3fff)) < iVar13) {
      uVar1 = 0x24;
      if ((((uVar4 & 0xc000) != 0) && (uVar1 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      iVar13 = *(int *)((uint3)uVar1 << 0xe | (uint3)(uVar4 & 0x3fff));
    }
    Ram00d6ba = iVar13;
    Ram00d6e4 = 0;
    uVar1 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    iVar13 = Ram00d6ba;
    iVar13 = *(int *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) + iVar13;
    Ram00d6a2 = iVar13;
    Ram00d6bc = iVar13 * 10;
    iVar13 = Ram00f652;
    uVar1 = iVar13 + 0x5c;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    Ram00d6a0 = *(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
  }
  else {
LAB_0db70e:
    old = Ram00d6bc;
    uVar12 = Ram00d6a0;
    uVar12 = egs52_ramp_u16(old,0,uVar12);
    Ram00d6bc = uVar12;
    Ram00d6a2 = uVar12 / 10;
    iVar13 = Ram00f652;
    uVar1 = iVar13 + 0xce;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    Ram00d6e4 = *(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
  }
  iVar13 = Ram00d6a2;
  iVar13 = uVar11 + iVar13;
LAB_0db742:
  cVar10 = egs52_match_fault_status_mask(0x35,1);
  if (cVar10 != '\0') {
    iVar13 = Ram00f652;
    uVar11 = iVar13 + 0x56;
    uVar1 = 0x24;
    if ((((uVar11 & 0xc000) != 0) && (uVar1 = 0x21, (uVar11 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar11 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    iVar13 = *(int *)((uint3)uVar1 << 0xe | (uint3)(uVar11 & 0x3fff));
  }
  return iVar13;
}


