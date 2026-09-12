/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d5382; FLS offset 0x055382.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d54da) */
/* WARNING: Removing unreachable block (ram,0x0d54b8) */
/* WARNING: Removing unreachable block (ram,0x0d54b2) */
/* WARNING: Removing unreachable block (ram,0x0d54ac) */
/* WARNING: Removing unreachable block (ram,0x0d54a4) */
/* WARNING: Removing unreachable block (ram,0x0d54a0) */
/* WARNING: Removing unreachable block (ram,0x0d5492) */
/* WARNING: Removing unreachable block (ram,0x0d548e) */
/* WARNING: Removing unreachable block (ram,0x0d5486) */
/* WARNING: Removing unreachable block (ram,0x0d5472) */
/* WARNING: Removing unreachable block (ram,0x0d546a) */
/* WARNING: Removing unreachable block (ram,0x0d54d6) */
/* WARNING: Removing unreachable block (ram,0x0d54d2) */
/* WARNING: Removing unreachable block (ram,0x0d54ce) */
/* WARNING: Removing unreachable block (ram,0x0d54c6) */
/* WARNING: Removing unreachable block (ram,0x0d54c2) */
/* WARNING: Removing unreachable block (ram,0x0d54be) */
/* WARNING: Removing unreachable block (ram,0x0d5460) */
/* WARNING: Removing unreachable block (ram,0x0d545c) */
/* WARNING: Removing unreachable block (ram,0x0d544e) */
/* WARNING: Removing unreachable block (ram,0x0d544a) */
/* WARNING: Removing unreachable block (ram,0x0d5442) */
/* WARNING: Removing unreachable block (ram,0x0d543a) */
/* WARNING: Removing unreachable block (ram,0x0d5434) */
/* WARNING: Removing unreachable block (ram,0x0d5430) */
/* WARNING: Removing unreachable block (ram,0x0d542c) */
/* WARNING: Removing unreachable block (ram,0x0d5428) */
/* WARNING: Removing unreachable block (ram,0x0d5424) */
/* WARNING: Removing unreachable block (ram,0x0d5420) */
/* WARNING: Removing unreachable block (ram,0x0d541e) */
/* WARNING: Removing unreachable block (ram,0x0d5418) */
/* WARNING: Removing unreachable block (ram,0x0d540c) */
/* WARNING: Removing unreachable block (ram,0x0d5408) */
/* WARNING: Removing unreachable block (ram,0x0d53e2) */
/* WARNING: Removing unreachable block (ram,0x0d53c4) */
/* WARNING: Removing unreachable block (ram,0x0d53c0) */
/* WARNING: Removing unreachable block (ram,0x0d53bc) */
/* WARNING: Removing unreachable block (ram,0x0d53b8) */
/* WARNING: Removing unreachable block (ram,0x0d53b4) */
/* WARNING: Removing unreachable block (ram,0x0d53aa) */
/* WARNING: Removing unreachable block (ram,0x0d53a6) */
/* WARNING: Removing unreachable block (ram,0x0d53a2) */
/* WARNING: Removing unreachable block (ram,0x0d539e) */
/* WARNING: Removing unreachable block (ram,0x0d5394) */
/* WARNING: Removing unreachable block (ram,0x0d5388) */
/* WARNING: Removing unreachable block (ram,0x0d5384) */
/* WARNING: Removing unreachable block (ram,0x0d53de) */
/* WARNING: Removing unreachable block (ram,0x0d5480) */
/* WARNING: Removing unreachable block (ram,0x0d5478) */
/* WARNING: Removing unreachable block (ram,0x0d547c) */

void egs52_update_near_d477_0d5382(undefined2 param_1)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  char cVar6;
  byte bVar7;
  ushort old;
  int iVar8;
  char cVar9;
  undefined2 uVar10;
  uint uVar11;
  ushort uVar12;
  
  UNK_00d477 = 0;
  bVar3 = UNK_00d454;
  iVar8 = Ram00f624;
  uVar4 = iVar8 + 0x26 + (uint)bVar3 * 0xc;
  uVar1 = 0x24;
  if ((((uVar4 & 0xc000) != 0) && (uVar1 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  Ram00d46e = *(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(uVar4 & 0x3fff));
  iVar8 = Ram00f624;
  uVar1 = iVar8 + 0x96;
  uVar4 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar4 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar4 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar4 = 3;
  }
  Ram00d54a = *(undefined2 *)((uint3)uVar4 << 0xe | (uint3)(uVar1 & 0x3fff));
  uVar10 = egs52_compute_from_near_f624_0d41e8(0);
  Ram00d536 = uVar10;
  iVar8 = Ram00f648;
  uVar1 = iVar8 + 0x18;
  uVar4 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar4 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar4 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar4 = 3;
  }
  Ram00d56a = *(undefined2 *)((uint3)uVar4 << 0xe | (uint3)(uVar1 & 0x3fff));
  cVar6 = UNK_00d566;
  if (cVar6 == '\0') {
    uVar1 = Ram00fd48;
    Ram00fd48 = uVar1 | 1;
    iVar8 = Ram00f64a;
    uVar1 = iVar8 + 6;
    uVar4 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar4 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar4 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar4 = 3;
    }
    bVar3 = *(byte *)((uint3)uVar4 << 0xe | (uint3)(uVar1 & 0x3fff));
    uVar11 = egs52_update_near_d430_0d718c(param_1);
    iVar8 = Ram00f636;
    uVar1 = iVar8 + 0x22;
    uVar4 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar4 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar4 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar4 = 3;
    }
    bVar7 = UNK_00d477;
    uVar5 = iVar8 + 0x23 + (uint)bVar7;
    uVar2 = 0x24;
    if ((((uVar5 & 0xc000) != 0) && (uVar2 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    UNK_00d5b0 = (char)(((ulong)bVar3 * (ulong)(uVar11 & 0xff)) / 100) +
                 *(char *)((uint3)uVar4 << 0xe | (uint3)(uVar1 & 0x3fff)) +
                 *(char *)((uint3)uVar2 << 0xe | (uint3)(uVar5 & 0x3fff));
    iVar8 = Ram00f648;
    uVar1 = iVar8 + 0x31;
    uVar4 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar4 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar4 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar4 = 3;
    }
    UNK_00d5b2 = *(undefined1 *)((uint3)uVar4 << 0xe | (uint3)(uVar1 & 0x3fff));
    cVar6 = UNK_00d566;
    UNK_00d566 = cVar6 + '\x01';
  }
  else if (cVar6 != '\x01') {
    if (cVar6 == '\x02') {
      uVar1 = Ram00fd3a;
      if ((uVar1 & 0x80) == 0) {
        iVar8 = Ram00f648;
        uVar1 = iVar8 + 0x1a;
        uVar4 = 0x24;
        if ((((uVar1 & 0xc000) != 0) && (uVar4 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
           (uVar4 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
          uVar4 = 3;
        }
        uVar12 = *(ushort *)((uint3)uVar4 << 0xe | (uint3)(uVar1 & 0x3fff));
      }
      else {
        uVar12 = Ram00d552;
      }
      old = Ram00d556;
      bVar3 = UNK_00d5b1;
      uVar12 = egs52_ramp_u16(old,uVar12,(uint)bVar3);
      Ram00d556 = uVar12;
      cVar6 = UNK_00d579;
      uVar10 = egs52_update_near_d600_0d7cb8(cVar6 + -1,uVar12);
      Ram00d56c = uVar10;
      cVar6 = UNK_00d5b1;
      if (cVar6 == '\0') {
        uVar1 = Ram00fd48;
        Ram00fd48 = uVar1 & 0xfffe;
      }
      cVar6 = UNK_00d5b0;
      if (cVar6 == '\0') {
        UNK_00d566 = 0;
        UNK_00d437 = 1;
      }
    }
    goto LAB_0d54da;
  }
  bVar3 = UNK_00d477;
  iVar8 = Ram00f636;
  uVar1 = iVar8 + (uint)bVar3 * 2 + 0x3a;
  uVar4 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar4 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar4 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar4 = 3;
  }
  uVar10 = egs52_compute_from_near_d54a_0d7e30
                     (*(undefined2 *)((uint3)uVar4 << 0xe | (uint3)(uVar1 & 0x3fff)));
  Ram00d556 = uVar10;
  cVar6 = UNK_00d579;
  uVar10 = egs52_update_near_d600_0d7cb8(cVar6 + -1,uVar10);
  Ram00d56c = uVar10;
  cVar6 = UNK_00d5b0;
  if (cVar6 == '\0') {
    iVar8 = Ram00f648;
    uVar1 = iVar8 + 0x11;
    uVar4 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar4 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar4 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar4 = 3;
    }
    UNK_00d5b1 = *(undefined1 *)((uint3)uVar4 << 0xe | (uint3)(uVar1 & 0x3fff));
    cVar9 = egs52_update_near_d5f6_0d50d2();
    cVar6 = UNK_00d5b1;
    UNK_00d5b0 = cVar9 + cVar6;
    cVar6 = UNK_00d566;
    UNK_00d566 = cVar6 + '\x01';
  }
LAB_0d54da:
  cVar6 = UNK_00d5b2;
  if ((cVar6 == '\0') && (uVar1 = Ram00fd3a, (uVar1 & 0x10) == 0)) {
    uVar1 = Ram00fd48;
    Ram00fd48 = uVar1 | 4;
  }
  return;
}


