/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0dbe10; FLS offset 0x05be10.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0dbeec) */
/* WARNING: Removing unreachable block (ram,0x0dbee4) */
/* WARNING: Removing unreachable block (ram,0x0dbee0) */
/* WARNING: Removing unreachable block (ram,0x0dbe9a) */
/* WARNING: Removing unreachable block (ram,0x0dbe8a) */
/* WARNING: Removing unreachable block (ram,0x0dbec6) */
/* WARNING: Removing unreachable block (ram,0x0dbebe) */
/* WARNING: Removing unreachable block (ram,0x0dbe80) */
/* WARNING: Removing unreachable block (ram,0x0dbe7c) */
/* WARNING: Removing unreachable block (ram,0x0dbe76) */
/* WARNING: Removing unreachable block (ram,0x0dbe70) */
/* WARNING: Removing unreachable block (ram,0x0dbe6a) */
/* WARNING: Removing unreachable block (ram,0x0dbe66) */
/* WARNING: Removing unreachable block (ram,0x0dbe5c) */
/* WARNING: Removing unreachable block (ram,0x0dbe44) */
/* WARNING: Removing unreachable block (ram,0x0dbe3c) */
/* WARNING: Removing unreachable block (ram,0x0dbe34) */
/* WARNING: Removing unreachable block (ram,0x0dbe2e) */
/* WARNING: Removing unreachable block (ram,0x0dbe1a) */
/* WARNING: Removing unreachable block (ram,0x0dbf76) */
/* WARNING: Removing unreachable block (ram,0x0dbf72) */
/* WARNING: Removing unreachable block (ram,0x0dbf6e) */
/* WARNING: Removing unreachable block (ram,0x0dbf6a) */
/* WARNING: Removing unreachable block (ram,0x0dbf44) */
/* WARNING: Removing unreachable block (ram,0x0dbf36) */
/* WARNING: Removing unreachable block (ram,0x0dbf32) */
/* WARNING: Removing unreachable block (ram,0x0dbf62) */
/* WARNING: Removing unreachable block (ram,0x0dbf56) */
/* WARNING: Removing unreachable block (ram,0x0dbf52) */
/* WARNING: Removing unreachable block (ram,0x0dbf26) */
/* WARNING: Removing unreachable block (ram,0x0dbf22) */
/* WARNING: Removing unreachable block (ram,0x0dbf1e) */
/* WARNING: Removing unreachable block (ram,0x0dbf0e) */
/* WARNING: Removing unreachable block (ram,0x0dbf16) */
/* WARNING: Removing unreachable block (ram,0x0dbf06) */
/* WARNING: Removing unreachable block (ram,0x0dbefe) */
/* WARNING: Removing unreachable block (ram,0x0dbe12) */
/* WARNING: Removing unreachable block (ram,0x0dbef6) */
/* WARNING: Removing unreachable block (ram,0x0dbe1e) */
/* WARNING: Removing unreachable block (ram,0x0dbeb6) */
/* WARNING: Removing unreachable block (ram,0x0dbe92) */

ushort egs52_update_near_d6b4_0dbe10(void)

{
  uint uVar1;
  uint uVar2;
  ulong uVar3;
  byte bVar4;
  undefined1 uVar5;
  undefined2 uVar6;
  int iVar7;
  ushort old;
  int iVar8;
  byte bVar9;
  uchar weight;
  int iVar10;
  ushort uVar11;
  
  uVar1 = Ram00fd2a;
  if ((uVar1 & 1) == 0) {
    iVar7 = Ram00f654;
    iVar8 = Ram00f654;
    iVar10 = Ram00d65e;
    if (iVar10 < 0) {
      iVar10 = Ram00d65e;
      uVar11 = -iVar10;
    }
    else {
      uVar11 = Ram00d65e;
    }
    uVar11 = egs52_curve_u16(5,(ushort *)(iVar7 + 0x5a),(ushort *)(iVar8 + 100),uVar11);
    Ram00d686 = uVar11;
    iVar10 = Ram00f652;
    uVar1 = iVar10 + 5;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    if ((*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) & 4) == 0) {
      iVar10 = Ram00f6fe;
      uVar1 = iVar10 + 2;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      uVar3 = (ulong)uVar11 * (ulong)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
      uVar11 = (ushort)uVar3;
      Ram00d686 = (int)(uVar3 / 100);
    }
    else {
      uVar1 = Ram00d686;
      bVar4 = UNK_00d6dc;
      Ram00d686 = (int)(((ulong)uVar1 * (ulong)bVar4) / 100);
    }
    iVar7 = Ram00d686;
    iVar10 = Ram00d660;
    Ram00d678 = iVar7 + iVar10;
    Ram00d6f8 = iVar7 + iVar10;
  }
  else {
    uVar6 = Ram00d65e;
    uVar5 = UNK_00d649;
    iVar10 = egs52_update_near_d688_0da630(uVar6,uVar5);
    Ram00d6b4 = iVar10 * 0xc;
    iVar10 = Ram00f654;
    iVar7 = Ram00f654;
    uVar1 = Ram00d640;
    bVar9 = egs52_curve_u8('\x05',(uchar *)(iVar10 + 0x50),(uchar *)(iVar7 + 0x55),
                           (uchar)(uVar1 / 0x1e));
    Ram00d68e = (uint)bVar9;
    iVar10 = Ram00d6b4;
    bVar4 = UNK_00d647;
    iVar7 = Ram00f652;
    uVar1 = iVar7 + (uint)bVar4 * 2 + 0x5c;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    Ram00d678 = (uint)bVar9 * 3 + iVar10 + *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
    iVar10 = Ram00d644;
    if (iVar10 < 0) {
      iVar10 = Ram00f654;
      iVar7 = Ram00f654;
      uVar1 = Ram00d640;
      weight = egs52_curve_u8('\x05',(uchar *)(iVar10 + 0xda),(uchar *)(iVar7 + 0xdf),
                              (uchar)(uVar1 / 0x1e));
    }
    else {
      iVar10 = Ram00f654;
      iVar7 = Ram00f654;
      uVar1 = Ram00d640;
      weight = egs52_curve_u8('\x05',(uchar *)(iVar10 + 0xd0),(uchar *)(iVar7 + 0xd5),
                              (uchar)(uVar1 / 0x1e));
    }
    uVar11 = Ram00d678;
    old = Ram00d6f8;
    uVar11 = egs52_weighted_average_u16(weight,uVar11,old);
    Ram00d6f8 = uVar11;
  }
  return uVar11;
}


