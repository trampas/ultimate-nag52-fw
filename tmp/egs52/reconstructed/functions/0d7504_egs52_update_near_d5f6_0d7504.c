/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d7504; FLS offset 0x057504.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d765a) */
/* WARNING: Removing unreachable block (ram,0x0d7654) */
/* WARNING: Removing unreachable block (ram,0x0d7650) */
/* WARNING: Removing unreachable block (ram,0x0d7644) */
/* WARNING: Removing unreachable block (ram,0x0d763c) */
/* WARNING: Removing unreachable block (ram,0x0d7638) */
/* WARNING: Removing unreachable block (ram,0x0d762c) */
/* WARNING: Removing unreachable block (ram,0x0d7624) */
/* WARNING: Removing unreachable block (ram,0x0d7620) */
/* WARNING: Removing unreachable block (ram,0x0d761a) */
/* WARNING: Removing unreachable block (ram,0x0d7612) */
/* WARNING: Removing unreachable block (ram,0x0d760a) */
/* WARNING: Removing unreachable block (ram,0x0d75f8) */
/* WARNING: Removing unreachable block (ram,0x0d75f0) */
/* WARNING: Removing unreachable block (ram,0x0d75ec) */
/* WARNING: Removing unreachable block (ram,0x0d75e4) */
/* WARNING: Removing unreachable block (ram,0x0d75e0) */
/* WARNING: Removing unreachable block (ram,0x0d75d8) */
/* WARNING: Removing unreachable block (ram,0x0d75d0) */
/* WARNING: Removing unreachable block (ram,0x0d75ca) */
/* WARNING: Removing unreachable block (ram,0x0d75c6) */
/* WARNING: Removing unreachable block (ram,0x0d75c0) */
/* WARNING: Removing unreachable block (ram,0x0d75bc) */
/* WARNING: Removing unreachable block (ram,0x0d75b8) */
/* WARNING: Removing unreachable block (ram,0x0d75b6) */
/* WARNING: Removing unreachable block (ram,0x0d75b2) */
/* WARNING: Removing unreachable block (ram,0x0d75aa) */
/* WARNING: Removing unreachable block (ram,0x0d759c) */
/* WARNING: Removing unreachable block (ram,0x0d7594) */
/* WARNING: Removing unreachable block (ram,0x0d758c) */
/* WARNING: Removing unreachable block (ram,0x0d7580) */
/* WARNING: Removing unreachable block (ram,0x0d7578) */
/* WARNING: Removing unreachable block (ram,0x0d7570) */
/* WARNING: Removing unreachable block (ram,0x0d7552) */
/* WARNING: Removing unreachable block (ram,0x0d7548) */
/* WARNING: Removing unreachable block (ram,0x0d7542) */
/* WARNING: Removing unreachable block (ram,0x0d753e) */
/* WARNING: Removing unreachable block (ram,0x0d7538) */
/* WARNING: Removing unreachable block (ram,0x0d7534) */
/* WARNING: Removing unreachable block (ram,0x0d752e) */
/* WARNING: Removing unreachable block (ram,0x0d7526) */
/* WARNING: Removing unreachable block (ram,0x0d756a) */
/* WARNING: Removing unreachable block (ram,0x0d7566) */
/* WARNING: Removing unreachable block (ram,0x0d7512) */
/* WARNING: Removing unreachable block (ram,0x0d750e) */
/* WARNING: Removing unreachable block (ram,0x0d751c) */
/* WARNING: Removing unreachable block (ram,0x0d752a) */
/* WARNING: Removing unreachable block (ram,0x0d760e) */
/* WARNING: Removing unreachable block (ram,0x0d7628) */

void egs52_update_near_d5f6_0d7504(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  byte bVar5;
  uint uVar6;
  int iVar7;
  uchar uVar8;
  uchar uVar9;
  ushort uVar10;
  char cVar11;
  byte bVar12;
  
  uVar1 = Ram00fd54;
  if ((uVar1 & 0x80) == 0) {
    bVar12 = UNK_00d777;
    bVar5 = UNK_00d613;
    if ((bVar12 < bVar5) && (uVar1 = Ram00fd4a, (uVar1 & 2) == 0)) {
      uVar1 = Ram00d7a6;
      if ((int)uVar1 < 0) {
        cVar11 = '\n';
      }
      else {
        Ram00d5f6 = 10;
        iVar4 = Ram00f634;
        uVar2 = iVar4 + 3;
        uVar3 = 0x24;
        if ((((uVar2 & 0xc000) != 0) && (uVar3 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
           (uVar3 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
          uVar3 = 3;
        }
        Ram00d5f8 = (uint)*(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar2 & 0x3fff));
        uVar2 = iVar4 + 0x2a;
        uVar3 = 0x24;
        if ((((uVar2 & 0xc000) != 0) && (uVar3 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
           (uVar3 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
          uVar3 = 3;
        }
        Ram00d5fa = (uint)*(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar2 & 0x3fff));
        uVar2 = iVar4 + 0x2b;
        uVar3 = 0x24;
        if ((((uVar2 & 0xc000) != 0) && (uVar3 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
           (uVar3 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
          uVar3 = 3;
        }
        Ram00d5fc = (uint)*(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar2 & 0x3fff));
        Ram00d5fe = uVar1 / 10;
        uVar10 = egs52_lerp_unsigned_axis((ushort *)0xd5f6);
        cVar11 = (char)uVar10;
      }
      goto LAB_0d756e;
    }
  }
  iVar4 = Ram00f634;
  uVar1 = iVar4 + 3;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  cVar11 = *(char *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
LAB_0d756e:
  iVar4 = Ram00f63e;
  iVar7 = Ram00f63e;
  uVar9 = UNK_00d75d;
  uVar8 = egs52_curve_u8('\x04',(uchar *)(iVar4 + 0x168),(uchar *)(iVar7 + 0x16c),uVar9);
  iVar4 = Ram00f63e;
  iVar7 = Ram00f63e;
  uVar9 = UNK_00d570;
  uVar9 = egs52_curve_u8('\x04',(uchar *)(iVar4 + 0x170),(uchar *)(iVar7 + 0x174),uVar9);
  bVar12 = cVar11 + uVar8 + uVar9;
  iVar4 = Ram00f634;
  uVar2 = iVar4 + 3;
  uVar1 = 0x24;
  if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  if (*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) <= bVar12) {
    uVar1 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    bVar12 = *(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
  }
  iVar4 = Ram00f634;
  uVar1 = iVar4 + 0x4d;
  uVar3 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar3 = 3;
  }
  bVar5 = UNK_00d570;
  if (*(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)) < bVar5) {
    uVar1 = iVar4 + 0x58;
    uVar3 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    uVar6 = Ram00d500;
    if (((*(uint *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)) < uVar6) &&
        (cVar11 = UNK_00d577, cVar11 == '\x03')) && (cVar11 = UNK_00d579, cVar11 == '\x06')) {
      uVar1 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      UNK_00d442 = *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
    }
  }
  cVar11 = UNK_00d60e;
  if (cVar11 == '\x03') {
    iVar4 = Ram00f61e;
    uVar1 = iVar4 + 0x1d;
    uVar3 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    if ((*(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)) & 0x40) != 0) {
      cVar11 = UNK_00d7aa;
      if (cVar11 == '\x01') {
        iVar4 = Ram00f634;
        uVar1 = iVar4 + 0x4c;
        uVar2 = 0x24;
        if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        UNK_00d442 = *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
        bVar12 = 10;
      }
      else if (cVar11 == '\0') {
        uVar1 = 0x24;
        if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        UNK_00d442 = *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
      }
      else if (cVar11 == '\x02') {
        iVar4 = Ram00f634;
        uVar1 = iVar4 + 0x48;
        uVar2 = 0x24;
        if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        UNK_00d442 = *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
      }
    }
  }
  cVar11 = UNK_00d577;
  if (cVar11 == '\x02') {
    bVar12 = 10;
    UNK_00d442 = 10;
  }
  cVar11 = UNK_00d577;
  if ((cVar11 == '\x01') && (bVar5 = UNK_00d437, bVar5 < 4)) {
    bVar12 = 10;
    UNK_00d442 = 10;
  }
  bVar5 = UNK_00d442;
  if (bVar5 <= bVar12) {
    UNK_00d442 = bVar12;
  }
  return;
}


