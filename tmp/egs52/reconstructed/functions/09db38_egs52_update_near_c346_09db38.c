/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x09db38; FLS offset 0x01db38.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Function: egs52_near_to_far_registers replaced with injection:
   egs52_near_to_far_registers */
/* WARNING: Removing unreachable block (ram,0x09ddf8) */
/* WARNING: Removing unreachable block (ram,0x09ddfc) */
/* WARNING: Removing unreachable block (ram,0x09dde2) */
/* WARNING: Removing unreachable block (ram,0x09de1e) */
/* WARNING: Removing unreachable block (ram,0x09ddee) */
/* WARNING: Removing unreachable block (ram,0x09dddc) */
/* WARNING: Removing unreachable block (ram,0x09de26) */
/* WARNING: Removing unreachable block (ram,0x09dde6) */
/* WARNING: Removing unreachable block (ram,0x09ddd4) */
/* WARNING: Removing unreachable block (ram,0x09ddcc) */
/* WARNING: Removing unreachable block (ram,0x09de60) */
/* WARNING: Removing unreachable block (ram,0x09de50) */
/* WARNING: Removing unreachable block (ram,0x09ddba) */
/* WARNING: Removing unreachable block (ram,0x09ddb4) */
/* WARNING: Removing unreachable block (ram,0x09ddb0) */
/* WARNING: Removing unreachable block (ram,0x09ddac) */
/* WARNING: Removing unreachable block (ram,0x09dd98) */
/* WARNING: Removing unreachable block (ram,0x09dd94) */
/* WARNING: Removing unreachable block (ram,0x09dd90) */
/* WARNING: Removing unreachable block (ram,0x09dd8a) */
/* WARNING: Removing unreachable block (ram,0x09dd82) */
/* WARNING: Removing unreachable block (ram,0x09dd76) */
/* WARNING: Removing unreachable block (ram,0x09dd60) */
/* WARNING: Removing unreachable block (ram,0x09dd78) */
/* WARNING: Removing unreachable block (ram,0x09dd6e) */
/* WARNING: Removing unreachable block (ram,0x09dd64) */
/* WARNING: Removing unreachable block (ram,0x09dd5a) */
/* WARNING: Removing unreachable block (ram,0x09dd52) */
/* WARNING: Removing unreachable block (ram,0x09dd50) */
/* WARNING: Removing unreachable block (ram,0x09dd4a) */
/* WARNING: Removing unreachable block (ram,0x09dd46) */
/* WARNING: Removing unreachable block (ram,0x09dd42) */
/* WARNING: Removing unreachable block (ram,0x09dd3e) */
/* WARNING: Removing unreachable block (ram,0x09dd3c) */
/* WARNING: Removing unreachable block (ram,0x09dd38) */
/* WARNING: Removing unreachable block (ram,0x09dd34) */
/* WARNING: Removing unreachable block (ram,0x09dd1c) */
/* WARNING: Removing unreachable block (ram,0x09dd12) */
/* WARNING: Removing unreachable block (ram,0x09dd0e) */
/* WARNING: Removing unreachable block (ram,0x09dcd2) */
/* WARNING: Removing unreachable block (ram,0x09dcdc) */
/* WARNING: Removing unreachable block (ram,0x09dcea) */
/* WARNING: Removing unreachable block (ram,0x09dcd8) */
/* WARNING: Removing unreachable block (ram,0x09dcce) */
/* WARNING: Removing unreachable block (ram,0x09dcf6) */
/* WARNING: Removing unreachable block (ram,0x09dcec) */
/* WARNING: Removing unreachable block (ram,0x09dcb8) */
/* WARNING: Removing unreachable block (ram,0x09dcb0) */
/* WARNING: Removing unreachable block (ram,0x09dcc8) */
/* WARNING: Removing unreachable block (ram,0x09dcc2) */
/* WARNING: Removing unreachable block (ram,0x09dcbe) */
/* WARNING: Removing unreachable block (ram,0x09dc9c) */
/* WARNING: Removing unreachable block (ram,0x09dbba) */
/* WARNING: Removing unreachable block (ram,0x09dba2) */
/* WARNING: Removing unreachable block (ram,0x09dc0c) */
/* WARNING: Removing unreachable block (ram,0x09dbb6) */
/* WARNING: Removing unreachable block (ram,0x09dc4c) */
/* WARNING: Removing unreachable block (ram,0x09dba4) */
/* WARNING: Removing unreachable block (ram,0x09dc86) */
/* WARNING: Removing unreachable block (ram,0x09db98) */
/* WARNING: Removing unreachable block (ram,0x09dc5c) */
/* WARNING: Removing unreachable block (ram,0x09dc40) */
/* WARNING: Removing unreachable block (ram,0x09dc20) */
/* WARNING: Removing unreachable block (ram,0x09dc0e) */
/* WARNING: Removing unreachable block (ram,0x09dbe8) */
/* WARNING: Removing unreachable block (ram,0x09db9e) */
/* WARNING: Removing unreachable block (ram,0x09dd9e) */
/* WARNING: Removing unreachable block (ram,0x09dc82) */
/* WARNING: Removing unreachable block (ram,0x09db80) */
/* WARNING: Removing unreachable block (ram,0x09db7c) */
/* WARNING: Removing unreachable block (ram,0x09db78) */
/* WARNING: Removing unreachable block (ram,0x09db72) */
/* WARNING: Removing unreachable block (ram,0x09db6c) */
/* WARNING: Removing unreachable block (ram,0x09db68) */
/* WARNING: Removing unreachable block (ram,0x09db5e) */
/* WARNING: Removing unreachable block (ram,0x09db54) */
/* WARNING: Removing unreachable block (ram,0x09db40) */
/* WARNING: Removing unreachable block (ram,0x09dc1c) */
/* WARNING: Removing unreachable block (ram,0x09dc70) */
/* WARNING: Removing unreachable block (ram,0x09dc52) */
/* WARNING: Removing unreachable block (ram,0x09dbdc) */
/* WARNING: Removing unreachable block (ram,0x09dbec) */
/* WARNING: Removing unreachable block (ram,0x09dbaa) */
/* WARNING: Removing unreachable block (ram,0x09dc54) */
/* WARNING: Removing unreachable block (ram,0x09dc7e) */
/* WARNING: Removing unreachable block (ram,0x09dc92) */
/* WARNING: Removing unreachable block (ram,0x09dce0) */
/* WARNING: Removing unreachable block (ram,0x09dd32) */
/* WARNING: Removing unreachable block (ram,0x09dd6a) */
/* WARNING: Removing unreachable block (ram,0x09dd7e) */
/* WARNING: Removing unreachable block (ram,0x09dda8) */
/* WARNING: Removing unreachable block (ram,0x09ddc8) */
/* WARNING: Removing unreachable block (ram,0x09de2a) */
/* WARNING: Removing unreachable block (ram,0x09dde8) */
/* WARNING: Removing unreachable block (ram,0x09de40) */
/* WARNING: Removing unreachable block (ram,0x09de38) */
/* WARNING: Removing unreachable block (ram,0x09de06) */
/* WARNING: Removing unreachable block (ram,0x09dce6) */
/* WARNING: Removing unreachable block (ram,0x09dc14) */
/* WARNING: Removing unreachable block (ram,0x09dc34) */
/* WARNING: Removing unreachable block (ram,0x09dbc4) */
/* WARNING: Removing unreachable block (ram,0x09dc3a) */
/* WARNING: Removing unreachable block (ram,0x09dbf6) */
/* WARNING: Removing unreachable block (ram,0x09dbda) */
/* WARNING: Removing unreachable block (ram,0x09dc12) */
/* WARNING: Removing unreachable block (ram,0x09dc76) */
/* WARNING: Removing unreachable block (ram,0x09de1c) */
/* WARNING: Removing unreachable block (ram,0x09dc2e) */

undefined2 egs52_update_near_c346_09db38(undefined1 param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  byte bVar8;
  byte bVar9;
  undefined1 uVar10;
  undefined2 uVar11;
  char cVar12;
  
  bVar7 = false;
  bVar8 = UNK_00c32a;
  if (((bVar8 & 1) == 0) || ((bVar8 & 2) != 0)) {
    UNK_00c32b = 0xff;
    UNK_00c33a = 0;
  }
  else {
    cVar12 = UNK_00c32b;
    if ((cVar12 == -1) && (cVar12 = UNK_00c33a, cVar12 == '\0')) {
      Ram00c346 = 0xe7ff;
      bVar8 = UNK_00c32c;
      Ram00c33e = bVar8 - 1;
      UNK_00c33b = param_1;
      UNK_00c33c = 0;
    }
    cVar12 = UNK_00c33a;
    if (cVar12 == '\0') {
      while( true ) {
        bVar8 = UNK_00c33c;
        uVar5 = (uint)bVar8;
        iVar2 = Ram00c33e;
        uVar4 = Ram00c33e;
        if ((uVar5 != uVar4 && (int)(uVar5 - uVar4) < 0 == SBORROW2(uVar5,iVar2)) ||
           (cVar12 = UNK_00c33a, cVar12 != '\0')) break;
        iVar2 = Ram00c330;
        if (iVar2 == 0) {
LAB_09dbaa:
          iVar2 = Ram00c330;
          if (iVar2 == 0) {
            uVar4 = Ram00f682;
            uVar11 = Ram00f684;
            iVar2 = Ram00c33e;
            uVar5 = (uint)((long)iVar2 * 0xc);
            cVar12 = UNK_00c33b;
            if (*(char *)CONCAT12((char)uVar11 + (0xfff5 < uVar4) +
                                  (char)((ulong)((long)iVar2 * 0xc) >> 0x10) +
                                  CARRY2(uVar4 + 10,uVar5),uVar4 + 10 + uVar5) == cVar12)
            goto LAB_09dbe4;
          }
          iVar2 = Ram00c33e;
          Ram00c33e = iVar2 + -1;
        }
        else {
          iVar3 = Ram00c33e;
          uVar4 = iVar2 + iVar3;
          uVar5 = 0x24;
          if ((((uVar4 & 0xc000) != 0) && (uVar5 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
             (uVar5 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
            uVar5 = 3;
          }
          cVar12 = UNK_00c33b;
          if (*(char *)((uint3)uVar5 << 0xe | (uint3)(uVar4 & 0x3fff)) != cVar12) goto LAB_09dbaa;
LAB_09dbe4:
          uVar5 = Ram00f682;
          uVar11 = Ram00f684;
          iVar2 = Ram00c33e;
          uVar6 = (uint)((long)iVar2 * 0xc);
          cVar12 = (char)((ulong)((long)iVar2 * 0xc) >> 0x10);
          uVar4 = *(uint *)CONCAT12((char)uVar11 + (0xfff7 < uVar5) + cVar12 +
                                    CARRY2(uVar5 + 8,uVar6),uVar5 + 8 + uVar6);
          Ram00c340 = uVar4;
          uVar5 = 0x24;
          if ((((uVar4 & 0xc000) != 0) && (uVar5 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
             (uVar5 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
            uVar5 = 3;
          }
          iVar2 = *(int *)((uint3)uVar5 << 0xe | (uint3)(uVar4 & 0x3fff));
          Ram00c348 = iVar2;
          uVar5 = Ram00f682;
          uVar11 = Ram00f684;
          iVar3 = uVar5 + 4 + uVar6;
          cVar12 = (char)uVar11 + (0xfffb < uVar5) + cVar12 + CARRY2(uVar5 + 4,uVar6);
          Ram00c348 = iVar2 + *(int *)CONCAT12(cVar12,iVar3) + -1;
          if ((*(uint *)CONCAT12(cVar12,iVar3) & 1) != 0) {
            uVar5 = Ram00c346;
            iVar2 = 0;
            if ((((uVar5 & 0xc000) != 0) && (iVar2 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
               (iVar2 = 0, (uVar5 & 0xc000) != 0x8000)) {
              iVar2 = 3;
            }
            Ram00c346 = uVar5 & 0x3ffe | iVar2 << 0xe;
          }
          iVar2 = Ram00c346;
          uVar5 = (iVar2 - *(int *)CONCAT12(cVar12,iVar3)) + 1;
          Ram00c342 = uVar5;
          uVar4 = 0x24;
          if ((((uVar5 & 0xc000) != 0) && (uVar4 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
             (uVar4 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
            uVar4 = 3;
          }
          if (uVar4 >> 2 == 0 && (uVar5 & 0x3fff | uVar4 << 0xe) < 0xe400) {
            iVar2 = Ram00c33e;
            Ram00c33e = iVar2 + -1;
            bVar7 = true;
          }
          else {
            UNK_00c33a = 1;
          }
        }
      }
    }
    else if (cVar12 == '\x01') {
      uVar5 = Ram00c346;
      iVar2 = 0;
      if ((((uVar5 & 0xc000) != 0) && (iVar2 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
         (iVar2 = 0, (uVar5 & 0xc000) != 0x8000)) {
        iVar2 = 3;
      }
      uVar4 = Ram00c342;
      iVar3 = 0;
      if ((((uVar4 & 0xc000) != 0) && (iVar3 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
         (iVar3 = 0, (uVar4 & 0xc000) != 0x8000)) {
        iVar3 = 3;
      }
      if ((uVar5 & 0x3fff | iVar2 << 0xe) - (uVar4 & 0x3fff | iVar3 << 0xe) < 0x11) {
        uVar11 = Ram00c342;
        Ram00c344 = uVar11;
        UNK_00c33a = 2;
      }
      else {
        iVar2 = Ram00c346;
        Ram00c344 = iVar2 + -0x10;
      }
      while( true ) {
        uVar5 = Ram00c346;
        iVar2 = 0;
        if ((((uVar5 & 0xc000) != 0) && (iVar2 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
           (iVar2 = 0, (uVar5 & 0xc000) != 0x8000)) {
          iVar2 = 3;
        }
        uVar4 = Ram00c344;
        iVar3 = 0;
        if ((((uVar4 & 0xc000) != 0) && (iVar3 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
           (iVar3 = 0, (uVar4 & 0xc000) != 0x8000)) {
          iVar3 = 3;
        }
        if ((uVar5 & 0x3fff | iVar2 << 0xe) < (uVar4 & 0x3fff | iVar3 << 0xe)) break;
        uVar4 = Ram00c348;
        iVar2 = Ram00c348;
        Ram00c348 = iVar2 + -1;
        uVar6 = Ram00c346;
        iVar2 = Ram00c346;
        Ram00c346 = iVar2 + -1;
        uVar5 = 0x24;
        if ((((uVar4 & 0xc000) != 0) && (uVar5 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
           (uVar5 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
          uVar5 = 3;
        }
        uVar1 = 0x24;
        if ((((uVar6 & 0xc000) != 0) && (uVar1 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar6 & 0x3fff)) =
             *(undefined1 *)((uint3)uVar5 << 0xe | (uint3)(uVar4 & 0x3fff));
      }
    }
    else if (cVar12 == '\x02') {
      uVar4 = Ram00f682;
      uVar11 = Ram00f684;
      iVar2 = Ram00c33e;
      uVar5 = (uint)((long)iVar2 * 0xc);
      uVar4 = *(uint *)CONCAT12((char)uVar11 + (0xfff7 < uVar4) +
                                (char)((ulong)((long)iVar2 * 0xc) >> 0x10) + CARRY2(uVar4 + 8,uVar5)
                                ,uVar4 + 8 + uVar5);
      Ram00c340 = uVar4;
      uVar11 = Ram00c342;
      uVar5 = 0x24;
      if ((((uVar4 & 0xc000) != 0) && (uVar5 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
         (uVar5 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
        uVar5 = 3;
      }
      *(undefined2 *)((uint3)uVar5 << 0xe | (uint3)(uVar4 & 0x3fff)) = uVar11;
      uVar10 = UNK_00c33e;
      UNK_00c32b = uVar10;
      uVar4 = (iRam090782 + iRam090784) - 4;
      uVar5 = 0x24;
      if ((((uVar4 & 0xc000) != 0) && (uVar5 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
         (uVar5 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
        uVar5 = 3;
      }
      uVar6 = Ram00c33e;
      if (*(uint *)((uint3)uVar5 << 0xe | (uint3)(uVar4 & 0x3fff)) < uVar6) {
        UNK_00c33d = 1;
        while( true ) {
          bVar8 = UNK_00c33d;
          iVar2 = (uint)bVar8 * 4;
          uVar4 = (*(int *)((uint3)(iVar2 + 0x782) | 0x90000) +
                  *(int *)((uint3)(iVar2 + 0x784) | 0x90000)) - 4;
          uVar5 = 0x24;
          if ((((uVar4 & 0xc000) != 0) && (uVar5 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
             (uVar5 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
            uVar5 = 3;
          }
          uVar6 = Ram00c33e;
          if (uVar6 <= *(uint *)((uint3)uVar5 << 0xe | (uint3)(uVar4 & 0x3fff))) break;
          cVar12 = UNK_00c33d;
          UNK_00c33d = cVar12 + '\x01';
        }
        uVar4 = (*(int *)((uint3)(iVar2 + 0x77e) | 0x90000) +
                *(int *)((uint3)(iVar2 + 0x780) | 0x90000)) - 4;
        uVar5 = 0x24;
        if ((((uVar4 & 0xc000) != 0) && (uVar5 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
           (uVar5 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
          uVar5 = 3;
        }
        UNK_00c33c = (char)*(undefined2 *)((uint3)uVar5 << 0xe | (uint3)(uVar4 & 0x3fff)) + '\x01';
      }
      iVar2 = Ram00c33e;
      Ram00c33e = iVar2 + -1;
      UNK_00c33a = 0;
    }
  }
  bVar8 = UNK_00c32b;
  bVar9 = UNK_00c32c;
  if (((bVar9 <= bVar8) && (cVar12 = UNK_00c33a, cVar12 == '\0')) || (bVar7)) {
    cVar12 = UNK_00c32b;
    if (cVar12 == -1) {
      uVar11 = 0x31;
    }
    else {
      UNK_00c32b = 0xff;
      if (bVar7) {
        uVar11 = 0x43;
      }
      else {
        uVar11 = 0x22;
      }
    }
  }
  else {
    bVar8 = UNK_00c33c;
    iVar2 = Ram00c33e;
    uVar5 = Ram00c33e;
    if (bVar8 == uVar5 || (int)(uint)bVar8 < iVar2) {
      uVar11 = 0x78;
    }
    else {
      cVar12 = UNK_00c33c;
      bVar7 = false;
      if (cVar12 != '\0') {
        while (iVar2 = Ram00c33e, -1 < iVar2) {
          iVar2 = Ram00c330;
          if (iVar2 == 0) {
LAB_09ddee:
            iVar2 = Ram00c330;
            if (iVar2 == 0) {
              uVar4 = Ram00f682;
              uVar11 = Ram00f684;
              iVar2 = Ram00c33e;
              uVar5 = (uint)((long)iVar2 * 0xc);
              cVar12 = UNK_00c33b;
              if (*(char *)CONCAT12((char)uVar11 + (0xfff5 < uVar4) +
                                    (char)((ulong)((long)iVar2 * 0xc) >> 0x10) +
                                    CARRY2(uVar4 + 10,uVar5),uVar4 + 10 + uVar5) == cVar12)
              goto LAB_09de24;
            }
          }
          else {
            iVar3 = Ram00c33e;
            uVar4 = iVar2 + iVar3;
            uVar5 = 0x24;
            if ((((uVar4 & 0xc000) != 0) && (uVar5 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
               (uVar5 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
              uVar5 = 3;
            }
            cVar12 = UNK_00c33b;
            if (*(char *)((uint3)uVar5 << 0xe | (uint3)(uVar4 & 0x3fff)) != cVar12) goto LAB_09ddee;
LAB_09de24:
            bVar7 = true;
          }
          iVar2 = Ram00c33e;
          Ram00c33e = iVar2 + -1;
        }
      }
      if (bVar7) {
        UNK_00c32b = 0xff;
        uVar11 = 0x40;
      }
      else {
        bVar8 = UNK_00c32a;
        UNK_00c32a = bVar8 | 2;
        uVar11 = 0;
      }
    }
  }
  return uVar11;
}


