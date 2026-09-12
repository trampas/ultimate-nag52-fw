/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d34e2; FLS offset 0x0534e2.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d3580) */
/* WARNING: Removing unreachable block (ram,0x0d3578) */
/* WARNING: Removing unreachable block (ram,0x0d3574) */
/* WARNING: Removing unreachable block (ram,0x0d356c) */
/* WARNING: Removing unreachable block (ram,0x0d358a) */
/* WARNING: Removing unreachable block (ram,0x0d3564) */
/* WARNING: Removing unreachable block (ram,0x0d354c) */
/* WARNING: Removing unreachable block (ram,0x0d3618) */
/* WARNING: Removing unreachable block (ram,0x0d3614) */
/* WARNING: Removing unreachable block (ram,0x0d360c) */
/* WARNING: Removing unreachable block (ram,0x0d3608) */
/* WARNING: Removing unreachable block (ram,0x0d3604) */
/* WARNING: Removing unreachable block (ram,0x0d35fe) */
/* WARNING: Removing unreachable block (ram,0x0d35f8) */
/* WARNING: Removing unreachable block (ram,0x0d3626) */
/* WARNING: Removing unreachable block (ram,0x0d3622) */
/* WARNING: Removing unreachable block (ram,0x0d361e) */
/* WARNING: Removing unreachable block (ram,0x0d35ee) */
/* WARNING: Removing unreachable block (ram,0x0d35d6) */
/* WARNING: Removing unreachable block (ram,0x0d35c8) */
/* WARNING: Removing unreachable block (ram,0x0d35c4) */
/* WARNING: Removing unreachable block (ram,0x0d35b6) */
/* WARNING: Removing unreachable block (ram,0x0d35b2) */
/* WARNING: Removing unreachable block (ram,0x0d35aa) */
/* WARNING: Removing unreachable block (ram,0x0d35a6) */
/* WARNING: Removing unreachable block (ram,0x0d35a2) */
/* WARNING: Removing unreachable block (ram,0x0d35ea) */
/* WARNING: Removing unreachable block (ram,0x0d35e0) */
/* WARNING: Removing unreachable block (ram,0x0d35dc) */
/* WARNING: Removing unreachable block (ram,0x0d3524) */
/* WARNING: Removing unreachable block (ram,0x0d352e) */
/* WARNING: Removing unreachable block (ram,0x0d351c) */
/* WARNING: Removing unreachable block (ram,0x0d3518) */
/* WARNING: Removing unreachable block (ram,0x0d3514) */
/* WARNING: Removing unreachable block (ram,0x0d3500) */
/* WARNING: Removing unreachable block (ram,0x0d34f8) */
/* WARNING: Removing unreachable block (ram,0x0d352a) */
/* WARNING: Removing unreachable block (ram,0x0d3546) */
/* WARNING: Removing unreachable block (ram,0x0d3554) */
/* WARNING: Removing unreachable block (ram,0x0d3586) */
/* WARNING: Removing unreachable block (ram,0x0d3570) */

undefined1 egs52_update_near_d556_0d34e2(byte param_1,char param_2,char param_3,char param_4)

{
  uint uVar1;
  undefined1 uVar2;
  int iVar3;
  ushort uVar4;
  byte bVar5;
  char cVar6;
  char cVar7;
  int iVar8;
  undefined2 uVar9;
  ushort uVar10;
  uint uVar11;
  uint uVar12;
  undefined1 uStack_e;
  
  uStack_e = 0;
  uVar2 = UNK_00d454;
  iVar8 = egs52_scale_d500_by_indexed_coefficient(uVar2);
  iVar3 = Ram00d524;
  uVar11 = iVar3 - iVar8;
  if ((int)uVar11 < 0) {
    uVar11 = -uVar11;
  }
  iVar3 = Ram00f648;
  uVar12 = iVar3 + 0x32;
  uVar1 = 0x24;
  if ((((uVar12 & 0xc000) != 0) && (uVar1 = 0x21, (uVar12 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uVar12 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  bVar5 = UNK_00d570;
  if (*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar12 & 0x3fff)) < bVar5) {
    uVar12 = iVar3 + 0x36;
    uVar1 = 0x24;
    if ((((uVar12 & 0xc000) != 0) && (uVar1 = 0x21, (uVar12 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar12 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    uVar12 = *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar12 & 0x3fff));
  }
  else {
    iVar3 = Ram00f648;
    uVar12 = iVar3 + 0x14;
    uVar1 = 0x24;
    if ((((uVar12 & 0xc000) != 0) && (uVar1 = 0x21, (uVar12 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar12 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    uVar12 = *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar12 & 0x3fff));
  }
  if ((param_3 == '\0') && (uVar11 <= uVar12)) {
    uVar1 = Ram00fd3a;
    Ram00fd3a = uVar1 & 0xffdf;
    uVar1 = Ram00fd3c;
    Ram00fd3c = uVar1 & 0xf7ff;
    uVar1 = Ram00fd4e;
    Ram00fd4e = uVar1 & 0xfffe;
  }
  if (param_1 == 0) {
    iVar3 = Ram00d5a6;
    if (iVar3 != 0) {
      uVar11 = Ram00fd3a;
      if (((uVar11 & 0x80) == 0) && (uVar11 = Ram00fd3a, (uVar11 & 0x40) == 0)) {
        uVar11 = Ram00fd3a;
        Ram00fd3a = uVar11 & 0xffdf;
        uVar11 = Ram00fd4e;
        Ram00fd4e = uVar11 & 0xfffe;
      }
      uVar11 = Ram00fd48;
      Ram00fd48 = uVar11 & 0xfff8;
    }
    if (param_4 == '\x01') {
      uVar9 = Ram00d552;
      Ram00d556 = uVar9;
      uVar9 = Ram00d54c;
      Ram00d56c = uVar9;
      Ram00d56a = 5000;
    }
    else {
      uVar9 = Ram00d54c;
      Ram00d56a = uVar9;
    }
    if (param_2 == '\0') {
      uStack_e = 1;
    }
  }
  else {
    if (param_4 == '\x01') {
      uVar4 = Ram00d556;
      uVar10 = Ram00d552;
      bVar5 = UNK_00d5b0;
      uVar10 = egs52_ramp_u16(uVar4,uVar10,(uint)bVar5);
      Ram00d556 = uVar10;
      cVar6 = UNK_00d579;
      uVar9 = egs52_update_near_d600_0d7cb8(cVar6 + -1,uVar10);
      Ram00d56c = uVar9;
      uVar10 = Ram00d56a;
      uVar10 = egs52_ramp_u16(uVar10,5000,(uint)param_1);
      Ram00d56a = uVar10;
    }
    else {
      uVar10 = Ram00d56a;
      uVar4 = Ram00d54c;
      uVar10 = egs52_ramp_u16(uVar10,uVar4,(uint)param_1);
      Ram00d56a = uVar10;
    }
    cVar6 = UNK_00d618;
    if (cVar6 != '\0') {
      if (uVar12 < uVar11) {
        iVar3 = Ram00f648;
        uVar11 = iVar3 + 0x3c;
        uVar12 = 0x24;
        if ((((uVar11 & 0xc000) != 0) && (uVar12 = 0x21, (uVar11 & 0xc000) != 0x4000)) &&
           (uVar12 = 0x2c, (uVar11 & 0xc000) != 0x8000)) {
          uVar12 = 3;
        }
        UNK_00d618 = *(undefined1 *)((uint3)uVar12 << 0xe | (uint3)(uVar11 & 0x3fff));
      }
      else {
        cVar6 = UNK_00d618;
        UNK_00d618 = cVar6 + -1;
        uVar11 = Ram00fd3c;
        Ram00fd3c = uVar11 & 0xf7ff;
        cVar6 = UNK_00d618;
        if (cVar6 == '\0') {
          iVar3 = Ram00f648;
          uVar11 = iVar3 + 0x11;
          uVar12 = 0x24;
          if ((((uVar11 & 0xc000) != 0) && (uVar12 = 0x21, (uVar11 & 0xc000) != 0x4000)) &&
             (uVar12 = 0x2c, (uVar11 & 0xc000) != 0x8000)) {
            uVar12 = 3;
          }
          UNK_00d5b0 = *(undefined1 *)((uint3)uVar12 << 0xe | (uint3)(uVar11 & 0x3fff));
          cVar7 = egs52_update_near_d5f6_0d50d2();
          cVar6 = UNK_00d5b0;
          UNK_00d5b1 = cVar7 + cVar6;
        }
      }
    }
  }
  return uStack_e;
}


