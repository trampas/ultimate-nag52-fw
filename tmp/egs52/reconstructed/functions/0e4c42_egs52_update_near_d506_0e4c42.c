/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0e4c42; FLS offset 0x064c42.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0e4da0) */
/* WARNING: Removing unreachable block (ram,0x0e4d9c) */
/* WARNING: Removing unreachable block (ram,0x0e4d98) */
/* WARNING: Removing unreachable block (ram,0x0e4d78) */
/* WARNING: Removing unreachable block (ram,0x0e4d70) */
/* WARNING: Removing unreachable block (ram,0x0e4d6a) */
/* WARNING: Removing unreachable block (ram,0x0e4d62) */
/* WARNING: Removing unreachable block (ram,0x0e4d52) */
/* WARNING: Removing unreachable block (ram,0x0e4d94) */
/* WARNING: Removing unreachable block (ram,0x0e4d8c) */
/* WARNING: Removing unreachable block (ram,0x0e4d4c) */
/* WARNING: Removing unreachable block (ram,0x0e4d44) */
/* WARNING: Removing unreachable block (ram,0x0e4d3e) */
/* WARNING: Removing unreachable block (ram,0x0e4d3a) */
/* WARNING: Removing unreachable block (ram,0x0e4d30) */
/* WARNING: Removing unreachable block (ram,0x0e4d28) */
/* WARNING: Removing unreachable block (ram,0x0e4d24) */
/* WARNING: Removing unreachable block (ram,0x0e4d1e) */
/* WARNING: Removing unreachable block (ram,0x0e4d1a) */
/* WARNING: Removing unreachable block (ram,0x0e4d16) */
/* WARNING: Removing unreachable block (ram,0x0e4d12) */
/* WARNING: Removing unreachable block (ram,0x0e4d0e) */
/* WARNING: Removing unreachable block (ram,0x0e4cce) */
/* WARNING: Removing unreachable block (ram,0x0e4cc6) */
/* WARNING: Removing unreachable block (ram,0x0e4cb2) */
/* WARNING: Removing unreachable block (ram,0x0e4ca4) */
/* WARNING: Removing unreachable block (ram,0x0e4ca0) */
/* WARNING: Removing unreachable block (ram,0x0e4cbe) */
/* WARNING: Removing unreachable block (ram,0x0e4cba) */
/* WARNING: Removing unreachable block (ram,0x0e4c8a) */
/* WARNING: Removing unreachable block (ram,0x0e4c7e) */
/* WARNING: Removing unreachable block (ram,0x0e4c4c) */
/* WARNING: Removing unreachable block (ram,0x0e4c48) */
/* WARNING: Removing unreachable block (ram,0x0e4c44) */
/* WARNING: Removing unreachable block (ram,0x0e4c84) */
/* WARNING: Removing unreachable block (ram,0x0e4c96) */
/* WARNING: Removing unreachable block (ram,0x0e4c9a) */
/* WARNING: Removing unreachable block (ram,0x0e4cac) */
/* WARNING: Removing unreachable block (ram,0x0e4d88) */
/* WARNING: Removing unreachable block (ram,0x0e4d5c) */

void egs52_update_near_d506_0e4c42(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined2 uVar5;
  byte bVar6;
  byte bVar7;
  ushort *axis;
  undefined1 uVar8;
  char cVar9;
  ushort uVar10;
  ushort uVar11;
  
  uVar5 = Ram00d508;
  Ram00d506 = uVar5;
  bVar6 = UNK_00d264;
  if (((((bVar6 & 1) == 0) || (cVar9 = egs52_match_fault_status_mask(0x25,5), cVar9 == '\x01')) ||
      (cVar9 = egs52_match_fault_status_mask(0x27,5), cVar9 == '\x01')) ||
     (cVar9 = egs52_match_fault_status_mask(0x52,5), cVar9 == '\x01')) {
    UNK_00d7da = 0;
  }
  else {
    bVar6 = UNK_00d266;
    bVar7 = UNK_00d267;
    iVar4 = (uint)bVar6 * 0x100 + (uint)bVar7;
    if (iVar4 == -1) {
      iVar4 = Ram00f67a;
      uVar1 = iVar4 + 0x1c;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      uVar3 = Ram00fdf2;
      iVar4 = Ram00fdf4;
      if (iVar4 == 0 &&
          (iVar4 != 0 || uVar3 <= *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)))) {
        UNK_00d7da = 0;
      }
      else {
        UNK_00d7da = 3;
      }
    }
    else {
      UNK_00d7da = 2;
      Ram00d508 = iVar4;
    }
  }
  uVar8 = UNK_00d7da;
  uVar8 = egs52_update_fault_status(0x1c,uVar8);
  UNK_00d433 = uVar8;
  uVar1 = Ram00fd60;
  Ram00fd60 = uVar1 & 0xfff7;
  cVar9 = egs52_match_fault_status_mask(0x25,1);
  if (((cVar9 == '\x01') || (cVar9 = egs52_match_fault_status_mask(0x27,1), cVar9 == '\x01')) ||
     ((cVar9 = egs52_match_fault_status_mask(0x1c,1), cVar9 == '\x01' ||
      (cVar9 = egs52_match_fault_status_mask(0x52,1), cVar9 == '\x01')))) {
    uVar1 = Ram00fd60;
    Ram00fd60 = uVar1 | 8;
    iVar4 = Ram00f67a;
    uVar1 = iVar4 + 8;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    Ram00d508 = *(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
  }
  iVar4 = Ram00f652;
  uVar1 = iVar4 + 0x6f;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  uVar10 = Ram00d508;
  uVar11 = Ram00d50c;
  uVar10 = egs52_weighted_average_u16
                     (*(uchar *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)),uVar10,uVar11);
  Ram00d50c = uVar10;
  uVar1 = Ram00fd56;
  if ((uVar1 & 0x10) == 0) {
    axis = (ushort *)Ram00f670;
    iVar4 = Ram00f670;
    bVar6 = UNK_00d5cd;
    uVar11 = egs52_curve_u16(2,axis,(ushort *)(iVar4 + 4),(uint)bVar6);
    uVar1 = Ram00d508;
    uVar10 = Ram00d508;
    if (uVar11 == uVar10 || uVar11 < uVar1) {
      cVar9 = UNK_00d5aa;
      if (cVar9 == '\0') {
        uVar1 = Ram00fd56;
        Ram00fd56 = uVar1 | 0x10;
      }
      else {
        iVar4 = Ram00f66c;
        uVar2 = iVar4 + 7;
        uVar1 = 0x24;
        if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        uVar3 = 0x24;
        if ((((uVar2 & 0xc000) != 0) && (uVar3 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
           (uVar3 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
          uVar3 = 3;
        }
        bVar6 = UNK_00d5aa;
        if (((int)(uint)bVar6 <=
             (int)((uint)*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) * 4 -
                  (uint)*(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar2 & 0x3fff)))) &&
           ((bVar6 = UNK_00d613, bVar6 == 7 || (bVar6 < 6)))) {
          uVar1 = Ram00fd56;
          Ram00fd56 = uVar1 | 0x10;
        }
      }
    }
    else {
      iVar4 = Ram00f66c;
      uVar1 = iVar4 + 7;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      UNK_00d5aa = *(char *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) << 2;
    }
  }
  iVar4 = Ram00f66e;
  uVar1 = iVar4 + 0x2a;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  uVar1 = *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
  uVar2 = Ram00d508;
  uVar3 = Ram00d508;
  if (uVar1 == uVar3 || uVar1 < uVar2) {
    uVar1 = Ram00fd56;
    Ram00fd56 = uVar1 | 8;
  }
  else {
    uVar1 = Ram00fd56;
    Ram00fd56 = uVar1 & 0xfff7;
  }
  return;
}


