/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x09c724; FLS offset 0x01c724.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x09cb14) */
/* WARNING: Removing unreachable block (ram,0x09cb10) */
/* WARNING: Removing unreachable block (ram,0x09cae2) */
/* WARNING: Removing unreachable block (ram,0x09cb0c) */
/* WARNING: Removing unreachable block (ram,0x09cb02) */
/* WARNING: Removing unreachable block (ram,0x09cafa) */
/* WARNING: Removing unreachable block (ram,0x09caf6) */
/* WARNING: Removing unreachable block (ram,0x09cad0) */
/* WARNING: Removing unreachable block (ram,0x09caca) */
/* WARNING: Removing unreachable block (ram,0x09cab4) */
/* WARNING: Removing unreachable block (ram,0x09cab0) */
/* WARNING: Removing unreachable block (ram,0x09caac) */
/* WARNING: Removing unreachable block (ram,0x09cac6) */
/* WARNING: Removing unreachable block (ram,0x09cac2) */
/* WARNING: Removing unreachable block (ram,0x09c9ac) */
/* WARNING: Removing unreachable block (ram,0x09c994) */
/* WARNING: Removing unreachable block (ram,0x09c98e) */
/* WARNING: Removing unreachable block (ram,0x09c98a) */
/* WARNING: Removing unreachable block (ram,0x09c96c) */
/* WARNING: Removing unreachable block (ram,0x09c93e) */
/* WARNING: Removing unreachable block (ram,0x09c930) */
/* WARNING: Removing unreachable block (ram,0x09c924) */
/* WARNING: Removing unreachable block (ram,0x09c91c) */
/* WARNING: Removing unreachable block (ram,0x09c918) */
/* WARNING: Removing unreachable block (ram,0x09c910) */
/* WARNING: Removing unreachable block (ram,0x09c90c) */
/* WARNING: Removing unreachable block (ram,0x09c904) */
/* WARNING: Removing unreachable block (ram,0x09c900) */
/* WARNING: Removing unreachable block (ram,0x09c8fc) */
/* WARNING: Removing unreachable block (ram,0x09c8e8) */
/* WARNING: Removing unreachable block (ram,0x09c8e0) */
/* WARNING: Removing unreachable block (ram,0x09c976) */
/* WARNING: Removing unreachable block (ram,0x09c972) */
/* WARNING: Removing unreachable block (ram,0x09c8ca) */
/* WARNING: Removing unreachable block (ram,0x09c7a2) */
/* WARNING: Removing unreachable block (ram,0x09c816) */
/* WARNING: Removing unreachable block (ram,0x09c80a) */
/* WARNING: Removing unreachable block (ram,0x09c822) */
/* WARNING: Removing unreachable block (ram,0x09c7fc) */
/* WARNING: Removing unreachable block (ram,0x09c7f2) */
/* WARNING: Removing unreachable block (ram,0x09c7ee) */
/* WARNING: Removing unreachable block (ram,0x09c7dc) */
/* WARNING: Removing unreachable block (ram,0x09c7d8) */
/* WARNING: Removing unreachable block (ram,0x09c7ca) */
/* WARNING: Removing unreachable block (ram,0x09c7c6) */
/* WARNING: Removing unreachable block (ram,0x09c8b6) */
/* WARNING: Removing unreachable block (ram,0x09c8b2) */
/* WARNING: Removing unreachable block (ram,0x09c8ae) */
/* WARNING: Removing unreachable block (ram,0x09c8aa) */
/* WARNING: Removing unreachable block (ram,0x09c8a6) */
/* WARNING: Removing unreachable block (ram,0x09c89c) */
/* WARNING: Removing unreachable block (ram,0x09c896) */
/* WARNING: Removing unreachable block (ram,0x09c890) */
/* WARNING: Removing unreachable block (ram,0x09c85c) */
/* WARNING: Removing unreachable block (ram,0x09c858) */
/* WARNING: Removing unreachable block (ram,0x09c854) */
/* WARNING: Removing unreachable block (ram,0x09c846) */
/* WARNING: Removing unreachable block (ram,0x09c780) */
/* WARNING: Removing unreachable block (ram,0x09c77c) */
/* WARNING: Removing unreachable block (ram,0x09c79e) */
/* WARNING: Removing unreachable block (ram,0x09c8d2) */
/* WARNING: Removing unreachable block (ram,0x09c964) */
/* WARNING: Removing unreachable block (ram,0x09cadc) */
/* WARNING: Removing unreachable block (ram,0x09cae8) */
/* WARNING: Removing unreachable block (ram,0x09caee) */

undefined1 egs52_update_near_c31e_09c724(uint param_1)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  undefined1 uVar4;
  int iVar5;
  int iVar6;
  undefined2 uVar7;
  char cVar8;
  char cVar9;
  ushort uVar10;
  char cVar11;
  char cVar12;
  undefined2 uStack_8;
  
  cVar9 = egs52_match_fault_status_mask(0x4b,1);
  param_1 = param_1 >> 1;
  uVar1 = Ram00fd6a;
  if ((uVar1 & 0x8000) == 0) {
    if (param_1 < 0x4c) {
      uStack_8._0_1_ = 0x4c;
    }
    else if (uStack_8 < 0xef) {
      uStack_8._0_1_ = (byte)param_1;
    }
    else {
      uStack_8._0_1_ = 0xee;
    }
    uStack_8._1_1_ = (undefined1)(((uint)(byte)uStack_8 * 0xb1 + -0x3412) * 2 >> 8);
    UNK_00c31e = uStack_8._1_1_;
    UNK_00c31f = uStack_8._1_1_;
    uVar1 = Ram00fd6a;
    Ram00fd6a = uVar1 | 0x8000;
  }
  uVar1 = Ram00fd6a;
  Ram00fd6a = uVar1 | 0x200;
  uVar1 = Ram00fd6a;
  Ram00fd6a = uVar1 & 0xf7ff;
  uVar1 = Ram00fd6a;
  Ram00fd6a = uVar1 & 0xdfff;
  uVar1 = Ram00fd6a;
  Ram00fd6a = uVar1 & 0xfbff;
  cVar12 = '\0';
  if (param_1 < 0x33) {
    uVar1 = Ram00fd6a;
    Ram00fd6a = uVar1 & 0xfffe;
    uVar1 = Ram00fd6a;
    Ram00fd6a = uVar1 | 2;
    UNK_00c31a = 0x1b;
    Ram00c322 = 0;
    uVar1 = Ram00fd6a;
    Ram00fd6a = uVar1 & 0xfdff;
    uVar1 = Ram00fd6a;
    Ram00fd6a = uVar1 & 0xefff;
    uVar1 = Ram00fd6a;
    if ((uVar1 & 0x100) == 0) {
      uVar1 = Ram00fd6a;
      Ram00fd6a = uVar1 | 0x400;
    }
    cVar11 = '\0';
    uVar1 = Ram00fd6a;
    Ram00fd6a = uVar1 & 0xffef;
  }
  else if (param_1 < 0x134) {
    uVar1 = Ram00fd6a;
    Ram00fd6a = uVar1 & 0xfffe;
    uVar1 = Ram00fd6a;
    Ram00fd6a = uVar1 & 0xfffd;
    if (param_1 < 0x4c) {
      param_1 = 0x4c;
    }
    else if (0xee < param_1) {
      param_1 = 0xee;
    }
    bVar3 = UNK_00c31a;
    if (bVar3 != 0) {
      if (bVar3 < 0x1a) {
        uVar1 = Ram00fd6a;
        Ram00fd6a = uVar1 | 0x100;
        iVar6 = Ram00c326;
        iVar5 = Ram00c322;
        Ram00c322 = iVar5 + iVar6;
        uVar1 = Ram00c322;
        uStack_8._1_1_ = (undefined1)(((uVar1 / (0x1a - bVar3) & 0xff) * 0xb1 + -0x3412) * 2 >> 8);
        UNK_00c31f = uStack_8._1_1_;
        uVar1 = Ram00fd6a;
        Ram00fd6a = uVar1 | 0x800;
      }
      cVar11 = UNK_00c31a;
      UNK_00c31a = cVar11 + -1;
      uVar1 = Ram00fd6a;
      Ram00fd6a = uVar1 & 0xfdff;
      cVar11 = UNK_00c31a;
      if (cVar11 == '\0') {
        UNK_00c320 = 0x19;
        Ram00c322 = 0;
        UNK_00c325 = 0;
      }
    }
    uVar1 = 0x24;
    if ((((uRam0904de & 0xc000) != 0) && (uVar1 = 0x21, (uRam0904de & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uRam0904de & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    if (*(char *)((uint3)uVar1 << 0xe | (uint3)(uRam0904de & 0x3fff)) == '\x05') {
      cVar11 = '\x04';
    }
    else {
      cVar11 = '\x03';
    }
    uVar1 = Ram00fd6a;
    Ram00fd6a = uVar1 & 0xffef;
  }
  else {
    uVar1 = Ram00fd6a;
    Ram00fd6a = uVar1 | 1;
    uVar1 = Ram00fd6a;
    Ram00fd6a = uVar1 & 0xfffd;
    UNK_00c31a = 0x1b;
    Ram00c322 = 0;
    uVar1 = Ram00fd6a;
    Ram00fd6a = uVar1 & 0xfdff;
    uVar1 = Ram00fd6a;
    Ram00fd6a = uVar1 & 0xefff;
    uVar1 = Ram00fd6a;
    if ((uVar1 & 0x100) == 0) {
      uVar1 = Ram00fd6a;
      Ram00fd6a = uVar1 | 0x400;
    }
    uVar1 = 0x24;
    if ((((uRam0904de & 0xc000) != 0) && (uVar1 = 0x21, (uRam0904de & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uRam0904de & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    if (*(char *)((uint3)uVar1 << 0xe | (uint3)(uRam0904de & 0x3fff)) == '\x05') {
      uVar1 = Ram00fd6a;
      Ram00fd6a = uVar1 & 0xffef;
      cVar11 = '\x01';
    }
    else {
      cVar11 = '\x02';
      uVar1 = 0x24;
      if ((((uRam0904de & 0xc000) != 0) && (uVar1 = 0x21, (uRam0904de & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uRam0904de & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      if (*(char *)((uint3)uVar1 << 0xe | (uint3)(uRam0904de & 0x3fff)) != '\b') {
        uVar1 = 0x24;
        if ((((uRam0904de & 0xc000) != 0) && (uVar1 = 0x21, (uRam0904de & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uRam0904de & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        if (*(char *)((uint3)uVar1 << 0xe | (uint3)(uRam0904de & 0x3fff)) != '\x06')
        goto LAB_09c8c6;
      }
      uVar1 = Ram00fd6a;
      if ((uVar1 & 0x10) == 0) {
        UNK_00c324 = 0xf9;
        uVar1 = Ram00fd6a;
        Ram00fd6a = uVar1 | 0x10;
        cVar11 = '\x02';
      }
      else {
        cVar8 = UNK_00c324;
        if (cVar8 == '\0') {
          uVar1 = Ram00fd6a;
          Ram00fd6a = uVar1 | 0x400;
        }
        else {
          cVar8 = UNK_00c324;
          UNK_00c324 = cVar8 + -1;
        }
      }
    }
  }
LAB_09c8c6:
  uVar1 = Ram00fd6a;
  if ((uVar1 & 0x200) != 0) {
    cVar8 = UNK_00c320;
    if (cVar8 == '\0') {
      uVar1 = Ram00c322;
      Ram00c322 = uVar1 / 0x19;
      bVar3 = UNK_00c322;
      Ram00c322 = ((uint)bVar3 * 0xb1 + -0x3412) * 2;
      uVar4 = UNK_00c323;
      UNK_00c329 = uVar4;
      UNK_00c320 = 0x19;
      Ram00c322 = 0;
      uVar1 = Ram00fd6a;
      if ((uVar1 & 0x1000) == 0) {
        uVar1 = Ram00fd6a;
        Ram00fd6a = uVar1 | 0x1000;
        uVar1 = Ram00fd6a;
        Ram00fd6a = uVar1 | 0x2000;
        uVar1 = Ram00fd6a;
        Ram00fd6a = uVar1 & 0xbfff;
      }
      else {
        cVar12 = UNK_00c329;
        cVar8 = UNK_00c31f;
        cVar12 = cVar12 - cVar8;
        if (((cVar12 < '\0') || (cVar8 = UNK_00c325, cVar8 < '\0')) &&
           ((-1 < cVar12 || (cVar8 = UNK_00c325, -1 < cVar8)))) {
          cVar8 = UNK_00c325;
          uVar10 = egs52_abs_s16_bits((int)cVar8);
          cVar8 = (char)uVar10 + '\n';
        }
        else {
          cVar8 = '\n';
        }
        uVar10 = egs52_abs_s16_bits((int)cVar12);
        if ((int)uVar10 < (int)cVar8) {
          uVar1 = Ram00fd6a;
          Ram00fd6a = uVar1 & 0xbfff;
          UNK_00c325 = cVar12;
        }
        else {
          uVar1 = Ram00fd6a;
          Ram00fd6a = uVar1 | 0x4000;
          UNK_00c325 = 0;
        }
      }
      uVar1 = Ram00fd6a;
      if (((uVar1 & 0x4000) == 0) || (cVar9 != '\0')) {
        uVar4 = UNK_00c329;
        UNK_00c31f = uVar4;
      }
      uVar1 = Ram00fd6a;
      Ram00fd6a = uVar1 | 0x800;
    }
    else {
      iVar5 = Ram00c322;
      Ram00c322 = iVar5 + param_1;
      cVar8 = UNK_00c320;
      UNK_00c320 = cVar8 + -1;
    }
  }
  uVar1 = Ram00fd6a;
  if ((uVar1 & 0x800) == 0) {
    uVar1 = Ram00fd6a;
    if ((uVar1 & 0x1000) == 0) {
      egs52_update_fault_status(0x4b,0);
    }
  }
  else if (cVar9 == '\0') {
    uVar1 = Ram00fd6a;
    if (((uVar1 & 0x2000) == 0) && (uVar1 = Ram00fd6a, (uVar1 & 0x1000) != 0)) {
      uVar1 = Ram00fd6a;
      if ((uVar1 & 0x4000) == 0) {
        egs52_update_fault_status(0x4b,2);
      }
      else {
        egs52_update_fault_status(0x4b,3);
      }
    }
    else {
      egs52_update_fault_status(0x4b,0);
    }
    uVar1 = Ram00fd6a;
    if ((uVar1 & 0x80) != 0) {
      uVar1 = Ram00fd6a;
      Ram00fd6a = uVar1 | 0x800;
    }
    uVar1 = Ram00fd6a;
    Ram00fd6a = uVar1 & 0xff7f;
  }
  else {
    uVar1 = Ram00fd6a;
    Ram00fd6a = uVar1 | 0x400;
    uVar1 = Ram00fd6a;
    Ram00fd6a = uVar1 & 0xbfff;
    uVar1 = Ram00fd6a;
    if (((uVar1 & 0x2000) == 0) && (uVar1 = Ram00fd6a, (uVar1 & 0x1000) != 0)) {
      bVar3 = UNK_00c31f;
      if ((bVar3 < 0xdd) && (uVar10 = egs52_abs_s16_bits((int)cVar12), (int)uVar10 < 3)) {
        egs52_update_fault_status(0x4b,2);
      }
      else {
        egs52_update_fault_status(0x4b,3);
      }
    }
    else {
      egs52_update_fault_status(0x4b,0);
    }
    uVar1 = Ram00fd6a;
    Ram00fd6a = uVar1 | 0x80;
  }
  cVar9 = egs52_match_fault_status_mask(0x14,1);
  if (cVar9 == '\0') {
    uVar1 = Ram00fd6a;
    if ((uVar1 & 0x20) != 0) {
      uVar1 = Ram00fd6a;
      Ram00fd6a = uVar1 | 0x800;
    }
    uVar1 = Ram00fd6a;
    Ram00fd6a = uVar1 & 0xffdf;
  }
  else {
    uVar1 = Ram00fd6a;
    Ram00fd6a = uVar1 | 0x400;
    uVar1 = Ram00fd6a;
    Ram00fd6a = uVar1 | 0x20;
  }
  if (cVar11 == '\0') {
    egs52_update_fault_status(0x14,3);
  }
  else {
    egs52_update_fault_status(0x14,2);
  }
  cVar9 = egs52_match_fault_status_mask(0x4a,1);
  if (cVar9 == '\0') {
    uVar1 = Ram00fd6a;
    if ((uVar1 & 0x40) != 0) {
      uVar1 = Ram00fd6a;
      Ram00fd6a = uVar1 | 0x800;
    }
    uVar1 = Ram00fd6a;
    Ram00fd6a = uVar1 & 0xffbf;
  }
  else {
    uVar1 = Ram00fd6a;
    Ram00fd6a = uVar1 | 0x400;
    uVar1 = Ram00fd6a;
    Ram00fd6a = uVar1 | 0x40;
  }
  if (cVar11 == '\x01') {
    egs52_update_fault_status(0x4a,3);
  }
  else if (cVar11 == '\x04') {
    egs52_update_fault_status(0x4a,2);
  }
  else {
    egs52_update_fault_status(0x4a,0);
  }
  uVar1 = Ram00fd6a;
  if ((uVar1 & 0x400) == 0) {
    uVar1 = Ram00fd6a;
    if (((uVar1 & 0x4000) == 0) && (uVar1 = Ram00fd6a, (uVar1 & 0x800) != 0)) {
      uVar4 = UNK_00c31f;
      UNK_00c31e = uVar4;
    }
  }
  else {
    uVar1 = iRam0904dc + 1;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    UNK_00c31e = *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
  }
  uVar1 = Ram00fd6a;
  uVar2 = Ram00fd6a;
  if ((uVar1 & 3) == (uVar2 >> 2 & 3)) {
    cVar9 = UNK_00c328;
    if (cVar9 == '\0') {
      uVar7 = Ram00fd6a;
      UNK_00c31b = (byte)uVar7 & 3;
    }
    else {
      cVar9 = UNK_00c328;
      UNK_00c328 = cVar9 + -1;
    }
  }
  else {
    UNK_00c328 = 2;
    uVar2 = Ram00fd6a;
    uVar1 = Ram00fd6a;
    Ram00fd6a = uVar1 & 0xfff3 | (uVar2 & 3) << 2;
  }
  Ram00c326 = param_1;
  uVar4 = UNK_00c31e;
  return uVar4;
}


