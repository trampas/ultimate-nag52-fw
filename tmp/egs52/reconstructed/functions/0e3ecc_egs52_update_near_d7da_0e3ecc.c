/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0e3ecc; FLS offset 0x063ecc.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0e4030) */
/* WARNING: Removing unreachable block (ram,0x0e401e) */
/* WARNING: Removing unreachable block (ram,0x0e4016) */
/* WARNING: Removing unreachable block (ram,0x0e400e) */
/* WARNING: Removing unreachable block (ram,0x0e400a) */
/* WARNING: Removing unreachable block (ram,0x0e4006) */
/* WARNING: Removing unreachable block (ram,0x0e3ff4) */
/* WARNING: Removing unreachable block (ram,0x0e3fec) */
/* WARNING: Removing unreachable block (ram,0x0e3fe4) */
/* WARNING: Removing unreachable block (ram,0x0e3fe0) */
/* WARNING: Removing unreachable block (ram,0x0e3fdc) */
/* WARNING: Removing unreachable block (ram,0x0e3fd8) */
/* WARNING: Removing unreachable block (ram,0x0e3fc8) */
/* WARNING: Removing unreachable block (ram,0x0e3fc4) */
/* WARNING: Removing unreachable block (ram,0x0e3fc0) */
/* WARNING: Removing unreachable block (ram,0x0e3fb0) */
/* WARNING: Removing unreachable block (ram,0x0e3faa) */
/* WARNING: Removing unreachable block (ram,0x0e3fa6) */
/* WARNING: Removing unreachable block (ram,0x0e3fa2) */
/* WARNING: Removing unreachable block (ram,0x0e3f62) */
/* WARNING: Removing unreachable block (ram,0x0e3f5c) */
/* WARNING: Removing unreachable block (ram,0x0e3f5a) */
/* WARNING: Removing unreachable block (ram,0x0e3f54) */
/* WARNING: Removing unreachable block (ram,0x0e3f4c) */
/* WARNING: Removing unreachable block (ram,0x0e3f44) */
/* WARNING: Removing unreachable block (ram,0x0e3f2c) */
/* WARNING: Removing unreachable block (ram,0x0e3f1e) */
/* WARNING: Removing unreachable block (ram,0x0e3f1a) */
/* WARNING: Removing unreachable block (ram,0x0e3f3c) */
/* WARNING: Removing unreachable block (ram,0x0e3f38) */
/* WARNING: Removing unreachable block (ram,0x0e3f34) */
/* WARNING: Removing unreachable block (ram,0x0e3f06) */
/* WARNING: Removing unreachable block (ram,0x0e3ece) */
/* WARNING: Removing unreachable block (ram,0x0e3f00) */
/* WARNING: Removing unreachable block (ram,0x0e3f10) */
/* WARNING: Removing unreachable block (ram,0x0e3f14) */
/* WARNING: Removing unreachable block (ram,0x0e3f26) */

undefined2 egs52_update_near_d7da_0e3ecc(void)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  int iVar4;
  ulong uVar5;
  byte bVar6;
  byte bVar7;
  int iVar8;
  uint uVar9;
  undefined1 uVar10;
  char cVar11;
  short sVar12;
  
  bVar3 = UNK_00d22a;
  if (((((bVar3 & 1) == 0) || (cVar11 = egs52_match_fault_status_mask(0x25,5), cVar11 == '\x01')) ||
      (cVar11 = egs52_match_fault_status_mask(0x27,5), cVar11 == '\x01')) ||
     (cVar11 = egs52_match_fault_status_mask(0x52,5), cVar11 == '\x01')) {
    UNK_00d7da = 0;
  }
  else {
    cVar11 = UNK_00d22d;
    if (cVar11 == -1) {
      iVar4 = Ram00f67a;
      uVar1 = iVar4 + 0x1c;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      uVar9 = Ram00fdf2;
      iVar4 = Ram00fdf4;
      if (iVar4 == 0 &&
          (iVar4 != 0 || uVar9 <= *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)))) {
        UNK_00d7da = 0;
      }
      else {
        UNK_00d7da = 3;
      }
    }
    else {
      UNK_00d7da = 2;
      uVar10 = UNK_00d22d;
      UNK_00d56f = uVar10;
    }
  }
  uVar10 = UNK_00d7da;
  uVar10 = egs52_update_fault_status(0x1a,uVar10);
  UNK_00d433 = uVar10;
  uVar1 = Ram00fd5a;
  if ((uVar1 & 0x10) != 0) {
    iVar4 = Ram00f66c;
    uVar2 = iVar4 + 6;
    uVar1 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    bVar3 = *(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
    bVar6 = UNK_00d56f;
    bVar7 = UNK_00d56f;
    if (bVar3 == bVar7 || bVar3 < bVar6) {
      uVar1 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      UNK_00d56f = *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
    }
  }
  uVar1 = Ram00fd60;
  Ram00fd60 = uVar1 & 0xfffe;
  cVar11 = egs52_match_fault_status_mask(0x25,1);
  if (((cVar11 == '\x01') || (cVar11 = egs52_match_fault_status_mask(0x27,1), cVar11 == '\x01')) ||
     ((cVar11 = egs52_match_fault_status_mask(0x1a,1), cVar11 == '\x01' ||
      (cVar11 = egs52_match_fault_status_mask(0x52,1), cVar11 == '\x01')))) {
    uVar1 = Ram00fd60;
    Ram00fd60 = uVar1 | 1;
    iVar4 = Ram00f67a;
    uVar1 = iVar4 + 0xb;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    UNK_00d56f = *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
  }
  bVar3 = UNK_00d56f;
  UNK_00d570 = (char)(((ulong)bVar3 * 4) / 10);
  bVar6 = UNK_00d56f;
  bVar3 = UNK_00d56e;
  iVar4 = ((uint)bVar6 - (uint)bVar3) * 100;
  uVar10 = UNK_00d56f;
  UNK_00d56e = uVar10;
  iVar8 = Ram00f652;
  uVar1 = iVar8 + 0x71;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  sVar12 = Ram00d574;
  sVar12 = egs52_weighted_average_s16
                     (*(uchar *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)),iVar4,sVar12);
  Ram00d574 = sVar12;
  Ram00d572 = (int)((long)((long)sVar12 * 4 & 0xffffU |
                          (((long)sVar12 & 0x3fffffffU) >> 0xe) << 0x10) / 0x14);
  iVar8 = Ram00f65a;
  uVar1 = iVar8 + 0x7d;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  sVar12 = Ram00d7a8;
  sVar12 = egs52_weighted_average_s16
                     (*(uchar *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)),iVar4,sVar12);
  Ram00d7a8 = sVar12;
  uVar5 = (long)sVar12 * 4;
  Ram00d7a6 = (int)((long)(uVar5 & 0xffff | (((long)sVar12 & 0x3fffffffU) >> 0xe) << 0x10) / 0x14);
  return (int)uVar5;
}


