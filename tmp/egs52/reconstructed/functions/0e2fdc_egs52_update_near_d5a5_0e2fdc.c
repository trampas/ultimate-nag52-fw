/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0e2fdc; FLS offset 0x062fdc.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0e315c) */
/* WARNING: Removing unreachable block (ram,0x0e318e) */
/* WARNING: Removing unreachable block (ram,0x0e3188) */
/* WARNING: Removing unreachable block (ram,0x0e3184) */
/* WARNING: Removing unreachable block (ram,0x0e3198) */
/* WARNING: Removing unreachable block (ram,0x0e3150) */
/* WARNING: Removing unreachable block (ram,0x0e314c) */
/* WARNING: Removing unreachable block (ram,0x0e31a4) */
/* WARNING: Removing unreachable block (ram,0x0e313c) */
/* WARNING: Removing unreachable block (ram,0x0e3122) */
/* WARNING: Removing unreachable block (ram,0x0e3116) */
/* WARNING: Removing unreachable block (ram,0x0e308c) */
/* WARNING: Removing unreachable block (ram,0x0e30a6) */
/* WARNING: Removing unreachable block (ram,0x0e3058) */
/* WARNING: Removing unreachable block (ram,0x0e3068) */
/* WARNING: Removing unreachable block (ram,0x0e304e) */
/* WARNING: Removing unreachable block (ram,0x0e304a) */
/* WARNING: Removing unreachable block (ram,0x0e3046) */
/* WARNING: Removing unreachable block (ram,0x0e303c) */
/* WARNING: Removing unreachable block (ram,0x0e3038) */
/* WARNING: Removing unreachable block (ram,0x0e3034) */
/* WARNING: Removing unreachable block (ram,0x0e301e) */
/* WARNING: Removing unreachable block (ram,0x0e3018) */
/* WARNING: Removing unreachable block (ram,0x0e3014) */
/* WARNING: Removing unreachable block (ram,0x0e300c) */
/* WARNING: Removing unreachable block (ram,0x0e3006) */
/* WARNING: Removing unreachable block (ram,0x0e3000) */
/* WARNING: Removing unreachable block (ram,0x0e2ffc) */
/* WARNING: Removing unreachable block (ram,0x0e2ff8) */
/* WARNING: Removing unreachable block (ram,0x0e2fe8) */
/* WARNING: Removing unreachable block (ram,0x0e2fe4) */
/* WARNING: Removing unreachable block (ram,0x0e2fe0) */
/* WARNING: Removing unreachable block (ram,0x0e302c) */
/* WARNING: Removing unreachable block (ram,0x0e3030) */
/* WARNING: Removing unreachable block (ram,0x0e3070) */
/* WARNING: Removing unreachable block (ram,0x0e30fc) */
/* WARNING: Removing unreachable block (ram,0x0e312a) */
/* WARNING: Removing unreachable block (ram,0x0e319e) */
/* WARNING: Removing unreachable block (ram,0x0e3166) */
/* WARNING: Removing unreachable block (ram,0x0e3192) */
/* WARNING: Removing unreachable block (ram,0x0e3160) */
/* WARNING: Removing unreachable block (ram,0x0e3138) */
/* WARNING: Removing unreachable block (ram,0x0e3106) */

void egs52_update_near_d5a5_0e2fdc(void)

{
  uint uVar1;
  byte bVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  undefined1 uVar6;
  byte bVar7;
  uint uVar8;
  char cVar9;
  uint uVar10;
  byte bVar11;
  
  iVar5 = Ram00f672;
  uVar1 = iVar5 + 0x10;
  uVar10 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar10 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar10 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar10 = 3;
  }
  uVar1 = *(uint *)((uint3)uVar10 << 0xe | (uint3)(uVar1 & 0x3fff));
  uVar10 = Ram00d508;
  uVar8 = Ram00d508;
  if (uVar1 == uVar8 || uVar1 < uVar10) {
    uVar1 = Ram00fd28;
    Ram00fd28 = uVar1 | 1;
    egs52_call_0a4f28_0964aa();
  }
  uVar1 = Ram00fd54;
  if ((uVar1 & 1) == 0) {
    iVar5 = Ram00f672;
    uVar1 = iVar5 + 0x12;
    uVar10 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar10 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar10 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar10 = 3;
    }
    bVar11 = *(byte *)((uint3)uVar10 << 0xe | (uint3)(uVar1 & 0x3fff));
    bVar2 = UNK_00d454;
    bVar7 = UNK_00d454;
    if (((bVar11 == bVar7 || bVar11 < bVar2) && (cVar9 = UNK_00d577, cVar9 == '\0')) &&
       (uVar1 = Ram00fd28, (uVar1 & 1) != 0)) {
      uVar1 = iVar5 + 0xe;
      uVar10 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar10 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar10 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar10 = 3;
      }
      uVar8 = Ram00d500;
      if (*(uint *)((uint3)uVar10 << 0xe | (uint3)(uVar1 & 0x3fff)) < uVar8) {
        cVar9 = UNK_00d5a5;
        if (cVar9 == '\0') {
          egs52_update_near_c105_0964b2();
          uVar1 = Ram00fd28;
          Ram00fd28 = uVar1 | 2;
        }
        goto LAB_0e3038;
      }
    }
  }
  iVar5 = Ram00f672;
  uVar1 = iVar5 + 0xc;
  uVar10 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar10 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar10 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar10 = 3;
  }
  UNK_00d5a5 = *(undefined1 *)((uint3)uVar10 << 0xe | (uint3)(uVar1 & 0x3fff));
LAB_0e3038:
  cVar9 = UNK_00d530;
  UNK_00d530 = cVar9 + '\x01';
  bVar11 = UNK_00d530;
  if (0x13 < bVar11) {
    UNK_00d530 = 0;
  }
  uVar6 = UNK_00d530;
  UNK_00d531 = uVar6;
  bVar11 = 0;
  bVar3 = false;
  bVar4 = true;
  do {
    bVar2 = UNK_00d530;
    iVar5 = Ram00f67e;
    uVar10 = iVar5 + 4 + (uint)bVar11 + (uint)bVar2 * 0x14;
    uVar1 = 0x24;
    if ((((uVar10 & 0xc000) != 0) && (uVar1 = 0x21, (uVar10 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar10 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    bVar2 = *(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar10 & 0x3fff));
    if (bVar2 != 0xff) {
      if (bVar2 < 0x80) {
        cVar9 = egs52_match_fault_status_mask(bVar2,1);
        UNK_00d433 = cVar9;
        if (cVar9 == '\x01') {
          cVar9 = egs52_match_fault_status_mask(bVar2,0x40);
          UNK_00d433 = cVar9;
          if (cVar9 == '\x01') {
            bVar3 = true;
          }
        }
        cVar9 = egs52_match_fault_status_mask(bVar2,8);
        if ((cVar9 == '\0') && (cVar9 = egs52_match_fault_status_mask(bVar2,0x20), cVar9 == '\x01'))
        {
          bVar4 = false;
        }
      }
      else if (bVar2 < 0x90) {
        uVar10 = 1 << (bVar2 - 0x80 & 0xf) & 0xff;
        uVar1 = Ram00fd50;
        if ((uVar10 & uVar1) != 0) {
          bVar3 = true;
        }
        uVar1 = Ram00fd52;
        if ((uVar10 & uVar1) == 0) {
          bVar4 = false;
        }
      }
    }
    bVar11 = bVar11 + 1;
  } while (bVar11 < 0x14);
  uVar1 = Ram00fd28;
  if ((uVar1 & 1) != 0) {
    if (bVar3) {
      bVar11 = UNK_00d531;
      UNK_00d531 = bVar11 | 0x80;
    }
    else if (bVar4) {
      bVar11 = UNK_00d531;
      UNK_00d531 = bVar11 | 0x40;
    }
  }
  uVar1 = Ram00fd56;
  if ((uVar1 & 0x2000) == 0) {
    UNK_00d57a = 0xff;
  }
  else {
    uVar1 = Ram00fd54;
    if ((uVar1 & 8) == 0) {
      bVar11 = UNK_00d531;
      UNK_00d531 = bVar11 | 0x20;
      bVar11 = UNK_00d530;
      if (bVar11 < 0x10) {
        uVar1 = bVar11 + 0xd2dc;
        uVar10 = 0x24;
        if ((((uVar1 & 0xc000) != 0) && (uVar10 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
           (uVar10 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
          uVar10 = 3;
        }
        UNK_00d57a = *(undefined1 *)((uint3)uVar10 << 0xe | (uint3)(uVar1 & 0x3fff));
      }
      else {
        cVar9 = UNK_00d530;
        if ((cVar9 == '\x10') || (cVar9 == '\x11')) {
          UNK_00d57a = 0;
        }
        else if (cVar9 == '\x12') {
          uVar6 = UNK_00c10b;
          UNK_00d57a = uVar6;
        }
        else if (cVar9 == '\x13') {
          uVar6 = UNK_00c10a;
          UNK_00d57a = uVar6;
        }
      }
    }
    else {
      UNK_00d57a = 0xff;
    }
  }
  return;
}


