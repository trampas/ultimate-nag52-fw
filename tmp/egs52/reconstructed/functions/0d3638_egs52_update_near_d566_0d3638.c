/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d3638; FLS offset 0x053638.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d36aa) */
/* WARNING: Removing unreachable block (ram,0x0d36a0) */
/* WARNING: Removing unreachable block (ram,0x0d36d2) */
/* WARNING: Removing unreachable block (ram,0x0d36cc) */
/* WARNING: Removing unreachable block (ram,0x0d36c8) */
/* WARNING: Removing unreachable block (ram,0x0d36f2) */
/* WARNING: Removing unreachable block (ram,0x0d36ec) */
/* WARNING: Removing unreachable block (ram,0x0d36e8) */
/* WARNING: Removing unreachable block (ram,0x0d3702) */
/* WARNING: Removing unreachable block (ram,0x0d36fe) */
/* WARNING: Removing unreachable block (ram,0x0d36e2) */
/* WARNING: Removing unreachable block (ram,0x0d36de) */
/* WARNING: Removing unreachable block (ram,0x0d36da) */
/* WARNING: Removing unreachable block (ram,0x0d36b4) */
/* WARNING: Removing unreachable block (ram,0x0d368a) */
/* WARNING: Removing unreachable block (ram,0x0d3682) */
/* WARNING: Removing unreachable block (ram,0x0d367e) */
/* WARNING: Removing unreachable block (ram,0x0d367a) */
/* WARNING: Removing unreachable block (ram,0x0d366e) */
/* WARNING: Removing unreachable block (ram,0x0d366a) */
/* WARNING: Removing unreachable block (ram,0x0d3666) */
/* WARNING: Removing unreachable block (ram,0x0d3662) */
/* WARNING: Removing unreachable block (ram,0x0d3658) */
/* WARNING: Removing unreachable block (ram,0x0d3654) */
/* WARNING: Removing unreachable block (ram,0x0d364c) */
/* WARNING: Removing unreachable block (ram,0x0d3644) */
/* WARNING: Removing unreachable block (ram,0x0d365e) */
/* WARNING: Removing unreachable block (ram,0x0d3674) */
/* WARNING: Removing unreachable block (ram,0x0d36b0) */
/* WARNING: Removing unreachable block (ram,0x0d36a4) */

void egs52_update_near_d566_0d3638(void)

{
  char cVar1;
  int iVar2;
  byte bVar3;
  undefined1 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar6 = Ram00fd3a;
  Ram00fd3a = uVar6 & 0xffdf;
  uVar6 = Ram00fd3c;
  Ram00fd3c = uVar6 & 0xf7ff;
  uVar6 = Ram00fd4e;
  Ram00fd4e = uVar6 & 0xfffe;
  uVar6 = Ram00fd3a;
  if (((uVar6 & 0x80) == 0) && (uVar6 = Ram00fd3a, (uVar6 & 0x40) == 0)) {
    iVar2 = Ram00f648;
    uVar6 = iVar2 + 0x22;
    uVar7 = 0x24;
    if (((uVar6 & 0xc000) != 0) &&
       ((uVar7 = 0x21, (uVar6 & 0xc000) != 0x4000 && (uVar7 = 0x2c, (uVar6 & 0xc000) != 0x8000)))) {
      uVar7 = 3;
    }
    uVar6 = *(uint *)((uint3)uVar7 << 0xe | (uint3)(uVar6 & 0x3fff));
  }
  else {
    iVar2 = Ram00f648;
    uVar6 = iVar2 + 0x16;
    uVar7 = 0x24;
    if ((((uVar6 & 0xc000) != 0) && (uVar7 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
       (uVar7 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
      uVar7 = 3;
    }
    uVar6 = *(uint *)((uint3)uVar7 << 0xe | (uint3)(uVar6 & 0x3fff));
  }
  iVar2 = Ram00f648;
  uVar7 = iVar2 + 0x32;
  uVar8 = 0x24;
  if ((((uVar7 & 0xc000) != 0) && (uVar8 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
     (uVar8 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
    uVar8 = 3;
  }
  bVar3 = UNK_00d570;
  if (*(byte *)((uint3)uVar8 << 0xe | (uint3)(uVar7 & 0x3fff)) < bVar3) {
    uVar7 = iVar2 + 0x36;
    uVar8 = 0x24;
    if ((((uVar7 & 0xc000) != 0) && (uVar8 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
       (uVar8 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
      uVar8 = 3;
    }
    uVar7 = *(uint *)((uint3)uVar8 << 0xe | (uint3)(uVar7 & 0x3fff));
  }
  else {
    iVar2 = Ram00f648;
    uVar7 = iVar2 + 0x14;
    uVar8 = 0x24;
    if ((((uVar7 & 0xc000) != 0) && (uVar8 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
       (uVar8 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
      uVar8 = 3;
    }
    uVar7 = *(uint *)((uint3)uVar8 << 0xe | (uint3)(uVar7 & 0x3fff));
  }
  uVar4 = UNK_00d454;
  iVar5 = egs52_scale_d500_by_indexed_coefficient(uVar4);
  iVar2 = Ram00d524;
  uVar8 = iVar2 - iVar5;
  if ((int)uVar8 < 0) {
    uVar8 = -uVar8;
  }
  if (uVar7 < uVar8) {
    iVar2 = Ram00d508;
    iVar5 = Ram00d524;
    uVar7 = iVar2 - iVar5;
    if ((int)uVar7 < 0) {
      uVar7 = -uVar7;
    }
    if (uVar6 < uVar7) {
      UNK_00d566 = 0;
      UNK_00d567 = 0;
      UNK_00d437 = 2;
    }
    else {
      uVar6 = Ram00fd3a;
      Ram00fd3a = uVar6 | 0x20;
      iVar2 = Ram00f648;
      uVar6 = iVar2 + 0x12;
      uVar7 = 0x24;
      if ((((uVar6 & 0xc000) != 0) && (uVar7 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
         (uVar7 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
        uVar7 = 3;
      }
      uVar6 = *(uint *)((uint3)uVar7 << 0xe | (uint3)(uVar6 & 0x3fff));
      uVar7 = Ram00d500;
      uVar8 = Ram00d500;
      if (uVar6 == uVar8 || uVar6 < uVar7) {
        UNK_00d566 = 0;
        UNK_00d567 = 0;
        UNK_00d437 = 4;
      }
      else {
        uVar6 = Ram00fd48;
        Ram00fd48 = uVar6 & 0xfffb;
        uVar4 = egs52_update_near_d5f6_0d50d2();
        UNK_00d5b0 = uVar4;
        cVar1 = UNK_00d566;
        UNK_00d566 = cVar1 + '\x01';
      }
    }
  }
  else {
    UNK_00d566 = 0;
    UNK_00d567 = 0;
    UNK_00d437 = 2;
  }
  return;
}


