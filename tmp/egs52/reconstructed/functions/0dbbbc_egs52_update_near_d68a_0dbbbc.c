/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0dbbbc; FLS offset 0x05bbbc.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Function: egs52_divide_s32_registers replaced with injection: egs52_sdiv32_registers */
/* WARNING: Function: egs52_multiply_u32_registers replaced with injection: egs52_mul32_registers */
/* WARNING: Removing unreachable block (ram,0x0dbdd4) */
/* WARNING: Removing unreachable block (ram,0x0dbdc6) */
/* WARNING: Removing unreachable block (ram,0x0dbdc2) */
/* WARNING: Removing unreachable block (ram,0x0dbdae) */
/* WARNING: Removing unreachable block (ram,0x0dbe08) */
/* WARNING: Removing unreachable block (ram,0x0dbe00) */
/* WARNING: Removing unreachable block (ram,0x0dbdf2) */
/* WARNING: Removing unreachable block (ram,0x0dbde2) */
/* WARNING: Removing unreachable block (ram,0x0dbd9c) */
/* WARNING: Removing unreachable block (ram,0x0dbd98) */
/* WARNING: Removing unreachable block (ram,0x0dbd8c) */
/* WARNING: Removing unreachable block (ram,0x0dbd88) */
/* WARNING: Removing unreachable block (ram,0x0dbd84) */
/* WARNING: Removing unreachable block (ram,0x0dbd70) */
/* WARNING: Removing unreachable block (ram,0x0dbd6c) */
/* WARNING: Removing unreachable block (ram,0x0dbd68) */
/* WARNING: Removing unreachable block (ram,0x0dbd58) */
/* WARNING: Removing unreachable block (ram,0x0dbd4e) */
/* WARNING: Removing unreachable block (ram,0x0dbd4a) */
/* WARNING: Removing unreachable block (ram,0x0dbd46) */
/* WARNING: Removing unreachable block (ram,0x0dbd42) */
/* WARNING: Removing unreachable block (ram,0x0dbd3e) */
/* WARNING: Removing unreachable block (ram,0x0dbd2a) */
/* WARNING: Removing unreachable block (ram,0x0dbd26) */
/* WARNING: Removing unreachable block (ram,0x0dbd20) */
/* WARNING: Removing unreachable block (ram,0x0dbd1c) */
/* WARNING: Removing unreachable block (ram,0x0dbd16) */
/* WARNING: Removing unreachable block (ram,0x0dbd12) */
/* WARNING: Removing unreachable block (ram,0x0dbd0a) */
/* WARNING: Removing unreachable block (ram,0x0dbd02) */
/* WARNING: Removing unreachable block (ram,0x0dbcfe) */
/* WARNING: Removing unreachable block (ram,0x0dbcfa) */
/* WARNING: Removing unreachable block (ram,0x0dbcf6) */
/* WARNING: Removing unreachable block (ram,0x0dbcf2) */
/* WARNING: Removing unreachable block (ram,0x0dbcd6) */
/* WARNING: Removing unreachable block (ram,0x0dbcd2) */
/* WARNING: Removing unreachable block (ram,0x0dbc0a) */
/* WARNING: Removing unreachable block (ram,0x0dbc02) */
/* WARNING: Removing unreachable block (ram,0x0dbbfa) */
/* WARNING: Removing unreachable block (ram,0x0dbbf2) */
/* WARNING: Removing unreachable block (ram,0x0dbbec) */
/* WARNING: Removing unreachable block (ram,0x0dbbe4) */
/* WARNING: Removing unreachable block (ram,0x0dbbdc) */
/* WARNING: Removing unreachable block (ram,0x0dbcc6) */
/* WARNING: Removing unreachable block (ram,0x0dbcc2) */
/* WARNING: Removing unreachable block (ram,0x0dbca2) */
/* WARNING: Removing unreachable block (ram,0x0dbc9e) */
/* WARNING: Removing unreachable block (ram,0x0dbc72) */
/* WARNING: Removing unreachable block (ram,0x0dbc6e) */
/* WARNING: Removing unreachable block (ram,0x0dbc64) */
/* WARNING: Removing unreachable block (ram,0x0dbc60) */
/* WARNING: Removing unreachable block (ram,0x0dbc58) */
/* WARNING: Removing unreachable block (ram,0x0dbc50) */
/* WARNING: Removing unreachable block (ram,0x0dbc48) */
/* WARNING: Removing unreachable block (ram,0x0dbc3a) */
/* WARNING: Removing unreachable block (ram,0x0dbc36) */
/* WARNING: Removing unreachable block (ram,0x0dbc32) */
/* WARNING: Removing unreachable block (ram,0x0dbc2c) */
/* WARNING: Removing unreachable block (ram,0x0dbc28) */
/* WARNING: Removing unreachable block (ram,0x0dbc20) */
/* WARNING: Removing unreachable block (ram,0x0dbc18) */
/* WARNING: Removing unreachable block (ram,0x0dbc14) */
/* WARNING: Removing unreachable block (ram,0x0dbbca) */
/* WARNING: Removing unreachable block (ram,0x0dbbc6) */
/* WARNING: Removing unreachable block (ram,0x0dbbc2) */
/* WARNING: Removing unreachable block (ram,0x0dbbbe) */
/* WARNING: Removing unreachable block (ram,0x0dbbd4) */
/* WARNING: Removing unreachable block (ram,0x0dbd60) */
/* WARNING: Removing unreachable block (ram,0x0dbdde) */
/* WARNING: Removing unreachable block (ram,0x0dbdb2) */

void egs52_update_near_d68a_0dbbbc(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  ulong uVar4;
  long lVar5;
  undefined2 uVar6;
  uint uVar7;
  char cVar8;
  undefined2 uVar9;
  byte bVar10;
  int iVar11;
  int iVar12;
  short *axis;
  short sVar13;
  int iVar14;
  
  uVar6 = Ram00d670;
  uVar9 = Ram00d672;
  Ram00d68a = uVar6;
  Ram00d68c = uVar9;
  uVar1 = Ram00fd2a;
  if ((uVar1 & 1) == 0) {
    iVar14 = Ram00f654;
    iVar3 = Ram00f654;
    sVar13 = Ram00d662;
    sVar13 = egs52_curve_s16('\x05',(short *)(iVar14 + 0x14),(short *)(iVar3 + 0x1e),sVar13);
    Ram00d69a = sVar13;
    iVar14 = Ram00f654;
    iVar3 = Ram00f654;
    sVar13 = Ram00d662;
    sVar13 = egs52_curve_s16('\x05',(short *)(iVar14 + 0x3c),(short *)(iVar3 + 0x46),sVar13);
    Ram00d69c = sVar13;
  }
  else {
    axis = (short *)Ram00f654;
    iVar14 = Ram00f654;
    sVar13 = Ram00d662;
    sVar13 = egs52_curve_s16('\x05',axis,(short *)(iVar14 + 10),sVar13);
    Ram00d69a = sVar13;
    iVar14 = Ram00d692;
    if (iVar14 != 0) {
      bVar10 = UNK_00d697;
      iVar14 = Ram00f652;
      uVar1 = iVar14 + 0x6e;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      if ((int)(*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) - 1) <= (int)(uint)bVar10)
      {
        iVar3 = Ram00d69a;
        iVar14 = Ram00d662;
        uVar4 = ((long)iVar3 * (long)iVar14) / 1000;
        iVar3 = Ram00d69c;
        iVar14 = Ram00d662;
        lVar5 = ((ulong)(uint)((int)uVar4 >> 0xf) << 0x10 | uVar4 & 0xffff) * -10 -
                (long)(int)(((long)(int)(((long)iVar3 * (long)iVar14) / 100) * 0x14) / 100);
        Ram00d670 = (int)lVar5;
        Ram00d672 = (int)((ulong)lVar5 >> 0x10);
        goto LAB_0dbcca;
      }
    }
    iVar14 = Ram00f654;
    iVar3 = Ram00f654;
    sVar13 = Ram00d662;
    sVar13 = egs52_curve_s16('\x05',(short *)(iVar14 + 0x28),(short *)(iVar3 + 0x32),sVar13);
    Ram00d69c = sVar13;
    Ram00d692 = 0;
  }
LAB_0dbcca:
  iVar3 = Ram00d69c;
  iVar14 = Ram00d662;
  uVar1 = (uint)(((long)(int)(((long)iVar3 * (long)iVar14) / 100) * 0x14) / 100);
  uVar2 = Ram00d670;
  Ram00d670 = uVar2 + uVar1;
  iVar14 = Ram00d672;
  Ram00d672 = iVar14 + ((int)uVar1 >> 0xf) + (uint)CARRY2(uVar2,uVar1);
  iVar14 = Ram00f652;
  uVar1 = iVar14 + 0x52;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  iVar3 = *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
  iVar11 = Ram00d6f6;
  iVar12 = Ram00d6f6;
  if ((iVar3 != iVar12 && iVar11 <= iVar3) && (uVar1 = Ram00fd2c, (uVar1 & 0x20) != 0)) {
    uVar1 = iVar14 + 0xd2;
    uVar2 = 0x24;
    if (((uVar1 & 0xc000) != 0) &&
       ((uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000 && (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)))) {
      uVar2 = 3;
    }
    uVar1 = *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
    uVar2 = Ram00d640;
    uVar7 = Ram00d640;
    if (uVar1 != uVar7 && uVar2 <= uVar1) {
      uVar1 = iVar14 + 0x10;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      iVar3 = Ram00d644;
      if (*(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) < iVar3) {
        iVar3 = Ram00d644;
        uVar1 = iVar14 + 0x12;
        uVar2 = 0x24;
        if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        uVar1 = (uint)(((long)iVar3 * (long)*(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)))
                      / 100);
        uVar2 = Ram00d670;
        Ram00d670 = uVar2 - uVar1;
        iVar14 = Ram00d672;
        Ram00d672 = (iVar14 - ((int)uVar1 >> 0xf)) - (uint)(uVar2 < uVar1);
      }
      iVar14 = Ram00f652;
      uVar1 = iVar14 + 0xc;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      iVar14 = Ram00d644;
      if (iVar14 <= *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff))) {
        iVar14 = Ram00d644;
        if (iVar14 < 0) {
          iVar14 = Ram00d644;
          iVar14 = -iVar14;
        }
        else {
          iVar14 = Ram00d644;
        }
        iVar3 = Ram00f652;
        uVar1 = iVar3 + 0xe;
        uVar2 = 0x24;
        if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        uVar1 = (uint)(((long)iVar14 * (long)*(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff))
                       ) / 100);
        uVar2 = Ram00d670;
        Ram00d670 = uVar2 - uVar1;
        iVar14 = Ram00d672;
        Ram00d672 = (iVar14 - ((int)uVar1 >> 0xf)) - (uint)(uVar2 < uVar1);
      }
    }
  }
  cVar8 = UNK_00d650;
  if (cVar8 == '\x01') {
    uVar1 = Ram00fd2a;
    if ((uVar1 & 1) == 0) {
      iVar14 = Ram00f652;
      uVar1 = iVar14 + 0xf4;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      if ((*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) & 8) != 0) goto LAB_0dbdaa;
    }
    iVar11 = Ram00d69a;
    iVar14 = Ram00d662;
    iVar3 = Ram00d666;
    lVar5 = (long)(iVar3 - (int)(((long)iVar11 * (long)iVar14) / 1000)) * 10;
    Ram00d670 = (int)lVar5;
    Ram00d672 = (int)((ulong)lVar5 >> 0x10);
  }
  else {
LAB_0dbdaa:
    iVar14 = Ram00d69a;
    iVar3 = Ram00d662;
    uVar6 = Ram00d670;
    uVar9 = Ram00d672;
    Ram00d666 = (int)(((long)iVar14 * (long)iVar3) / 1000) + (int)(CONCAT22(uVar9,uVar6) / 10);
  }
  return;
}


