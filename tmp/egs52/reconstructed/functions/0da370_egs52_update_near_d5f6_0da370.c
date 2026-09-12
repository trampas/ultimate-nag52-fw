/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0da370; FLS offset 0x05a370.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0da4fe) */
/* WARNING: Removing unreachable block (ram,0x0da4f8) */
/* WARNING: Removing unreachable block (ram,0x0da4ea) */
/* WARNING: Removing unreachable block (ram,0x0da4e2) */
/* WARNING: Removing unreachable block (ram,0x0da4de) */
/* WARNING: Removing unreachable block (ram,0x0da49a) */
/* WARNING: Removing unreachable block (ram,0x0da494) */
/* WARNING: Removing unreachable block (ram,0x0da490) */
/* WARNING: Removing unreachable block (ram,0x0da47e) */
/* WARNING: Removing unreachable block (ram,0x0da47a) */
/* WARNING: Removing unreachable block (ram,0x0da476) */
/* WARNING: Removing unreachable block (ram,0x0da472) */
/* WARNING: Removing unreachable block (ram,0x0da46e) */
/* WARNING: Removing unreachable block (ram,0x0da46a) */
/* WARNING: Removing unreachable block (ram,0x0da466) */
/* WARNING: Removing unreachable block (ram,0x0da462) */
/* WARNING: Removing unreachable block (ram,0x0da45e) */
/* WARNING: Removing unreachable block (ram,0x0da45a) */
/* WARNING: Removing unreachable block (ram,0x0da438) */
/* WARNING: Removing unreachable block (ram,0x0da434) */
/* WARNING: Removing unreachable block (ram,0x0da430) */
/* WARNING: Removing unreachable block (ram,0x0da3a2) */
/* WARNING: Removing unreachable block (ram,0x0da384) */
/* WARNING: Removing unreachable block (ram,0x0da41a) */
/* WARNING: Removing unreachable block (ram,0x0da416) */
/* WARNING: Removing unreachable block (ram,0x0da412) */
/* WARNING: Removing unreachable block (ram,0x0da40e) */
/* WARNING: Removing unreachable block (ram,0x0da3f8) */
/* WARNING: Removing unreachable block (ram,0x0da3ea) */
/* WARNING: Removing unreachable block (ram,0x0da3e4) */
/* WARNING: Removing unreachable block (ram,0x0da3e0) */
/* WARNING: Removing unreachable block (ram,0x0da3dc) */
/* WARNING: Removing unreachable block (ram,0x0da3d8) */
/* WARNING: Removing unreachable block (ram,0x0da3cc) */
/* WARNING: Removing unreachable block (ram,0x0da3c8) */
/* WARNING: Removing unreachable block (ram,0x0da3c4) */
/* WARNING: Removing unreachable block (ram,0x0da3c0) */
/* WARNING: Removing unreachable block (ram,0x0da3bc) */
/* WARNING: Removing unreachable block (ram,0x0da3b8) */
/* WARNING: Removing unreachable block (ram,0x0da3b4) */
/* WARNING: Removing unreachable block (ram,0x0da3b0) */
/* WARNING: Removing unreachable block (ram,0x0da37e) */
/* WARNING: Removing unreachable block (ram,0x0da3ac) */
/* WARNING: Removing unreachable block (ram,0x0da39e) */
/* WARNING: Removing unreachable block (ram,0x0da4b4) */
/* WARNING: Removing unreachable block (ram,0x0da394) */
/* WARNING: Removing unreachable block (ram,0x0da390) */

void egs52_update_near_d5f6_0da370(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  char cVar6;
  int iVar7;
  undefined1 uVar8;
  byte bVar9;
  int iVar10;
  int iVar11;
  undefined2 uVar12;
  ushort uVar13;
  uint uVar14;
  uint uStack_8;
  
  uVar13 = 0;
  cVar6 = UNK_00d577;
  if (cVar6 == '\0') {
    cVar6 = UNK_00d454;
    if ((cVar6 == '\x01') || (cVar6 == '\x06')) {
      iVar7 = Ram00f626;
      uVar1 = iVar7 + 4;
      uVar3 = 0x24;
      if (((uVar1 & 0xc000) != 0) &&
         ((uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000 && (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000))))
      {
        uVar3 = 3;
      }
      uStack_8 = *(uint *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff));
    }
    else {
      iVar7 = Ram00f626;
      uVar1 = iVar7 + 6;
      uVar3 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      uStack_8 = *(uint *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff));
    }
  }
  else {
    Ram00d5f6 = 0;
    iVar7 = Ram00f626;
    uVar1 = iVar7 + 0x62;
    uVar3 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    Ram00d5fa = *(undefined2 *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff));
    uVar1 = iVar7 + 100;
    uVar3 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    Ram00d5fc = *(undefined2 *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff));
    uVar12 = Ram00d508;
    Ram00d5fe = uVar12;
    cVar6 = UNK_00d579;
    if ((cVar6 == '\x01') || (cVar6 == '\x05')) {
      iVar7 = Ram00f626;
      uVar1 = iVar7 + 0x66;
      uVar3 = 0x24;
      if (((uVar1 & 0xc000) != 0) &&
         ((uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000 && (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000))))
      {
        uVar3 = 3;
      }
      Ram00d5f8 = *(undefined2 *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff));
      uVar1 = iVar7 + 4;
      uVar3 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      uStack_8 = *(uint *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff));
      uVar8 = UNK_00d579;
    }
    else {
      iVar7 = Ram00f626;
      uVar1 = iVar7 + 0x68;
      uVar3 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      Ram00d5f8 = *(undefined2 *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff));
      uVar1 = iVar7 + 6;
      uVar3 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      uStack_8 = *(uint *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff));
    }
    uVar13 = egs52_lerp_unsigned_axis((ushort *)0xd5f6);
  }
  iVar7 = Ram00f626;
  uVar1 = iVar7 + 8;
  uVar3 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar3 = 3;
  }
  iVar7 = Ram00d56a;
  uStack_8 = (int)(((ulong)(uint)(*(int *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)) + iVar7) *
                   1000) / (ulong)uStack_8) + uVar13;
  if (uStack_8 == 0) {
    uStack_8 = 0;
  }
  iVar7 = Ram00f626;
  uVar1 = iVar7 + 0x5e;
  uVar3 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar3 = 3;
  }
  Ram00d5f6 = *(undefined2 *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff));
  uVar1 = iVar7 + 0x60;
  uVar3 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar3 = 3;
  }
  Ram00d5f8 = *(undefined2 *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff));
  uVar1 = iVar7 + 0x5a;
  uVar3 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar3 = 3;
  }
  Ram00d5fa = *(undefined2 *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff));
  uVar1 = iVar7 + 0x5c;
  uVar3 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar3 = 3;
  }
  Ram00d5fc = *(undefined2 *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff));
  Ram00d5fe = uStack_8;
  uVar13 = egs52_lerp_unsigned_axis((ushort *)0xd5f6);
  iVar7 = Ram00f626;
  uVar1 = iVar7 + 0x56;
  uVar3 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar3 = 3;
  }
  uVar2 = iVar7 + 0x60;
  uVar4 = 0x24;
  if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
     (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
    uVar4 = 3;
  }
  if (param_1 < uVar13) {
    uVar14 = iVar7 + 0x58;
    uVar5 = 0x24;
    if ((((uVar14 & 0xc000) != 0) && (uVar5 = 0x21, (uVar14 & 0xc000) != 0x4000)) &&
       (uVar5 = 0x2c, (uVar14 & 0xc000) != 0x8000)) {
      uVar5 = 3;
    }
    uVar14 = param_1 + *(int *)((uint3)uVar5 << 0xe | (uint3)(uVar14 & 0x3fff));
    if ((int)uVar14 < 0) {
      uVar14 = 0;
    }
    uVar13 = param_1 + (int)(((((ulong)*(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)) *
                               (ulong)(*(int *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff)) -
                                      uVar13)) / 1000) * (ulong)uVar14) / 1000);
  }
  else {
    uVar13 = Ram00d54c;
  }
  bVar9 = UNK_00d5cc;
  iVar7 = Ram00f628;
  iVar10 = Ram00f628;
  iVar11 = Ram00f628;
  egs52_map_u16(7,4,(ushort *)(iVar10 + 4),(ushort *)(iVar11 + 0x12),(ushort *)(iVar7 + 0x1a),uVar13
                ,(uint)bVar9);
  return;
}


