/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0e1852; FLS offset 0x061852.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0e1a38) */
/* WARNING: Removing unreachable block (ram,0x0e1a32) */
/* WARNING: Removing unreachable block (ram,0x0e1a2c) */
/* WARNING: Removing unreachable block (ram,0x0e1a46) */
/* WARNING: Removing unreachable block (ram,0x0e1a42) */
/* WARNING: Removing unreachable block (ram,0x0e1a26) */
/* WARNING: Removing unreachable block (ram,0x0e1a24) */
/* WARNING: Removing unreachable block (ram,0x0e1a1c) */
/* WARNING: Removing unreachable block (ram,0x0e1a12) */
/* WARNING: Removing unreachable block (ram,0x0e1a0e) */
/* WARNING: Removing unreachable block (ram,0x0e1a0a) */
/* WARNING: Removing unreachable block (ram,0x0e1a04) */
/* WARNING: Removing unreachable block (ram,0x0e1a00) */
/* WARNING: Removing unreachable block (ram,0x0e19fc) */
/* WARNING: Removing unreachable block (ram,0x0e19f2) */
/* WARNING: Removing unreachable block (ram,0x0e19ee) */
/* WARNING: Removing unreachable block (ram,0x0e19ea) */
/* WARNING: Removing unreachable block (ram,0x0e19de) */
/* WARNING: Removing unreachable block (ram,0x0e19d8) */
/* WARNING: Removing unreachable block (ram,0x0e19d4) */
/* WARNING: Removing unreachable block (ram,0x0e19d0) */
/* WARNING: Removing unreachable block (ram,0x0e19c2) */
/* WARNING: Removing unreachable block (ram,0x0e19be) */
/* WARNING: Removing unreachable block (ram,0x0e19b6) */
/* WARNING: Removing unreachable block (ram,0x0e19ae) */
/* WARNING: Removing unreachable block (ram,0x0e19a0) */
/* WARNING: Removing unreachable block (ram,0x0e199c) */
/* WARNING: Removing unreachable block (ram,0x0e1998) */
/* WARNING: Removing unreachable block (ram,0x0e198e) */
/* WARNING: Removing unreachable block (ram,0x0e1986) */
/* WARNING: Removing unreachable block (ram,0x0e197a) */
/* WARNING: Removing unreachable block (ram,0x0e1972) */
/* WARNING: Removing unreachable block (ram,0x0e1968) */
/* WARNING: Removing unreachable block (ram,0x0e1960) */
/* WARNING: Removing unreachable block (ram,0x0e1958) */
/* WARNING: Removing unreachable block (ram,0x0e194e) */
/* WARNING: Removing unreachable block (ram,0x0e193e) */
/* WARNING: Removing unreachable block (ram,0x0e1938) */
/* WARNING: Removing unreachable block (ram,0x0e1930) */
/* WARNING: Removing unreachable block (ram,0x0e1922) */
/* WARNING: Removing unreachable block (ram,0x0e191a) */
/* WARNING: Removing unreachable block (ram,0x0e18fa) */
/* WARNING: Removing unreachable block (ram,0x0e18f6) */
/* WARNING: Removing unreachable block (ram,0x0e18ea) */
/* WARNING: Removing unreachable block (ram,0x0e18e0) */
/* WARNING: Removing unreachable block (ram,0x0e18de) */
/* WARNING: Removing unreachable block (ram,0x0e18d4) */
/* WARNING: Removing unreachable block (ram,0x0e18d0) */
/* WARNING: Removing unreachable block (ram,0x0e18ca) */
/* WARNING: Removing unreachable block (ram,0x0e18c2) */
/* WARNING: Removing unreachable block (ram,0x0e18be) */
/* WARNING: Removing unreachable block (ram,0x0e18ba) */
/* WARNING: Removing unreachable block (ram,0x0e18ae) */
/* WARNING: Removing unreachable block (ram,0x0e18aa) */
/* WARNING: Removing unreachable block (ram,0x0e19aa) */
/* WARNING: Removing unreachable block (ram,0x0e18a0) */
/* WARNING: Removing unreachable block (ram,0x0e1898) */
/* WARNING: Removing unreachable block (ram,0x0e1890) */
/* WARNING: Removing unreachable block (ram,0x0e1888) */
/* WARNING: Removing unreachable block (ram,0x0e187c) */
/* WARNING: Removing unreachable block (ram,0x0e1878) */
/* WARNING: Removing unreachable block (ram,0x0e1868) */
/* WARNING: Removing unreachable block (ram,0x0e1864) */
/* WARNING: Removing unreachable block (ram,0x0e185c) */
/* WARNING: Removing unreachable block (ram,0x0e1858) */
/* WARNING: Removing unreachable block (ram,0x0e19a6) */
/* WARNING: Removing unreachable block (ram,0x0e18b4) */
/* WARNING: Removing unreachable block (ram,0x0e19f8) */
/* WARNING: Removing unreachable block (ram,0x0e19e4) */
/* WARNING: Removing unreachable block (ram,0x0e1a3e) */
/* WARNING: Removing unreachable block (ram,0x0e1a34) */

void egs52_update_near_d722_0e1852(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined1 uVar7;
  byte bVar8;
  char cVar9;
  int iVar10;
  int iVar11;
  uchar input;
  char cVar12;
  byte bVar13;
  ushort uVar14;
  
  Ram00d722 = 0;
  uVar1 = Ram00fd56;
  if ((uVar1 & 1) == 0) {
LAB_0e1870:
    uVar1 = Ram00fd56;
    if ((uVar1 & 1) != 0) goto LAB_0e19fc;
    iVar5 = Ram00f65a;
    uVar1 = iVar5 + 1;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    if ((*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) & 2) == 0) goto LAB_0e19fc;
  }
  else {
    iVar5 = Ram00f65a;
    uVar1 = iVar5 + 1;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    if ((*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) & 0x20) == 0) goto LAB_0e1870;
  }
  iVar5 = Ram00f65e;
  bVar13 = UNK_00d774;
  uVar2 = iVar5 + 8 + (uint)bVar13 * 2;
  uVar1 = 0x24;
  if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  if (*(int *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) == 0) goto LAB_0e19fc;
  iVar5 = Ram00d7a6;
  if (iVar5 < 1) {
    uVar7 = UNK_00d570;
    UNK_00d79f = uVar7;
  }
  else {
    iVar5 = Ram00f65a;
    uVar1 = iVar5 + 0x2e;
    uVar3 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    iVar5 = Ram00d7a6;
    if (iVar5 <= (int)(uint)*(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff))) {
      uVar7 = UNK_00d570;
      UNK_00d79f = uVar7;
    }
    iVar5 = Ram00f65e;
    bVar13 = UNK_00d76f;
    uVar3 = iVar5 + 0x6f + (uint)bVar13;
    uVar1 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    iVar5 = Ram00d7d4;
    uVar3 = (uint)*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) * iVar5;
    uVar1 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    uVar6 = Ram00d500;
    if (*(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) < uVar6) {
      uVar14 = 0;
    }
    else {
      uVar1 = Ram00d500;
      iVar5 = Ram00d500;
      if (uVar3 - iVar5 == 0 || uVar3 < uVar1) {
        uVar1 = 0x24;
        if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        iVar5 = Ram00d500;
        uVar14 = (ushort)(((ulong)(iVar5 - uVar3) * 100) /
                         (ulong)(*(int *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) - uVar3));
      }
      else {
        uVar14 = 100;
      }
    }
    iVar5 = Ram00f668;
    iVar4 = Ram00f668;
    uVar14 = egs52_curve_u16(6,(ushort *)(iVar5 + 0x18),(ushort *)(iVar4 + 0x24),uVar14);
    iVar5 = Ram00f65e;
    bVar13 = UNK_00d774;
    uVar2 = iVar5 + 0x10 + (uint)bVar13;
    uVar1 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    Ram00d7a2 = (int)(((ulong)uVar14 *
                      (ulong)*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff))) / 100);
    iVar5 = Ram00f668;
    iVar4 = Ram00f668;
    input = UNK_00d79f;
    bVar13 = egs52_curve_u8('\x03',(uchar *)(iVar5 + 0x30),(uchar *)(iVar4 + 0x33),input);
    Ram00d7a4 = (uint)bVar13;
    uVar1 = Ram00d7a2;
    iVar5 = (int)(((ulong)uVar1 * (ulong)(uint)bVar13) / 100);
    Ram00d7a2 = iVar5;
    iVar4 = Ram00d7a6;
    if ((iVar5 < iVar4) && (uVar1 = Ram00fd58, (uVar1 & 0x10) == 0)) {
      iVar5 = Ram00f65a;
      uVar1 = iVar5 + 5;
      uVar2 = 0x24;
      if (((uVar1 & 0xc000) != 0) &&
         ((uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000 && (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000))))
      {
        uVar2 = 3;
      }
      UNK_00d7b8 = *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
    }
  }
  cVar9 = UNK_00d7b8;
  if (cVar9 == '\0') {
    cVar9 = UNK_00d60e;
    if (cVar9 == '\x02') {
      iVar5 = Ram00f65a;
      uVar1 = iVar5 + 3;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      if ((*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) & 8) != 0) goto LAB_0e19d0;
    }
  }
  else {
LAB_0e19d0:
    cVar12 = UNK_00d7d2;
    cVar9 = UNK_00d71b;
    bVar13 = UNK_00d570;
    bVar8 = UNK_00d570;
    if ((byte)(cVar12 - cVar9) == bVar8 || (byte)(cVar12 - cVar9) < bVar13) {
      bVar13 = UNK_00d774;
      iVar5 = Ram00f65e;
      uVar1 = iVar5 + (uint)bVar13 * 2 + 8;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      iVar5 = Ram00d78c;
      Ram00d722 = *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) - iVar5;
      goto LAB_0e19fc;
    }
  }
  Ram00d722 = 0;
LAB_0e19fc:
  iVar5 = Ram00f65e;
  uVar1 = iVar5 + 6;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  iVar4 = *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
  iVar10 = Ram00d710;
  iVar11 = Ram00d710;
  if (iVar4 != iVar11 && iVar10 <= iVar4) {
    cVar12 = UNK_00d7d2;
    cVar9 = UNK_00d71b;
    bVar13 = UNK_00d570;
    if ((byte)(cVar12 - cVar9) < bVar13) {
      bVar13 = UNK_00d774;
      uVar2 = iVar5 + 8 + (uint)bVar13 * 2;
      uVar1 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      uVar1 = *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
      uVar3 = Ram00d78c;
      uVar6 = Ram00d78c;
      if (uVar1 != uVar6 && uVar3 <= uVar1) {
        iVar5 = Ram00d7b6;
        if (iVar5 != 0) {
          return;
        }
        uVar1 = 0x24;
        if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        iVar5 = Ram00d78c;
        Ram00d722 = *(int *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) - iVar5;
        return;
      }
    }
  }
  iVar5 = Ram00f65a;
  uVar1 = iVar5 + 0x12;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  Ram00d7b6 = *(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
  return;
}


