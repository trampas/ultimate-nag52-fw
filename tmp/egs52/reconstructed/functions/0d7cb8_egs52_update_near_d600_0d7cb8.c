/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d7cb8; FLS offset 0x057cb8.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d7e20) */
/* WARNING: Removing unreachable block (ram,0x0d7e1c) */
/* WARNING: Removing unreachable block (ram,0x0d7e0c) */
/* WARNING: Removing unreachable block (ram,0x0d7e06) */
/* WARNING: Removing unreachable block (ram,0x0d7dfe) */
/* WARNING: Removing unreachable block (ram,0x0d7df8) */
/* WARNING: Removing unreachable block (ram,0x0d7de4) */
/* WARNING: Removing unreachable block (ram,0x0d7de0) */
/* WARNING: Removing unreachable block (ram,0x0d7dd8) */
/* WARNING: Removing unreachable block (ram,0x0d7dd0) */
/* WARNING: Removing unreachable block (ram,0x0d7dc8) */
/* WARNING: Removing unreachable block (ram,0x0d7dc4) */
/* WARNING: Removing unreachable block (ram,0x0d7dbc) */
/* WARNING: Removing unreachable block (ram,0x0d7da8) */
/* WARNING: Removing unreachable block (ram,0x0d7da4) */
/* WARNING: Removing unreachable block (ram,0x0d7da0) */
/* WARNING: Removing unreachable block (ram,0x0d7d9c) */
/* WARNING: Removing unreachable block (ram,0x0d7d94) */
/* WARNING: Removing unreachable block (ram,0x0d7d90) */
/* WARNING: Removing unreachable block (ram,0x0d7d84) */
/* WARNING: Removing unreachable block (ram,0x0d7d80) */
/* WARNING: Removing unreachable block (ram,0x0d7d7a) */
/* WARNING: Removing unreachable block (ram,0x0d7d76) */
/* WARNING: Removing unreachable block (ram,0x0d7d70) */
/* WARNING: Removing unreachable block (ram,0x0d7d3e) */
/* WARNING: Removing unreachable block (ram,0x0d7d32) */
/* WARNING: Removing unreachable block (ram,0x0d7d30) */
/* WARNING: Removing unreachable block (ram,0x0d7d28) */
/* WARNING: Removing unreachable block (ram,0x0d7cc8) */
/* WARNING: Removing unreachable block (ram,0x0d7cc4) */
/* WARNING: Removing unreachable block (ram,0x0d7cd0) */
/* WARNING: Removing unreachable block (ram,0x0d7cf2) */
/* WARNING: Removing unreachable block (ram,0x0d7d18) */
/* WARNING: Removing unreachable block (ram,0x0d7cd8) */
/* WARNING: Removing unreachable block (ram,0x0d7d08) */

int egs52_update_near_d600_0d7cb8(byte param_1,int param_2)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  char cVar6;
  int iVar7;
  byte bVar8;
  ushort uVar9;
  int iVar10;
  uint uVar11;
  
  iVar10 = Ram00f632;
  uVar11 = iVar10 + 0x10;
  uVar3 = 0x24;
  if ((((uVar11 & 0xc000) != 0) && (uVar3 = 0x21, (uVar11 & 0xc000) != 0x4000)) &&
     (uVar3 = 0x2c, (uVar11 & 0xc000) != 0x8000)) {
    uVar3 = 3;
  }
  if ((*(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar11 & 0x3fff)) & 1) == 0) {
    cVar6 = UNK_00d577;
    if (cVar6 == '\x06') {
      cVar6 = UNK_00d359;
      iVar10 = cVar6 * 0x14;
    }
    else if ((param_1 == 0) || (param_1 == 4)) {
      cVar6 = UNK_00d357;
      iVar10 = cVar6 * 0x14;
    }
    else if (param_1 == 6) {
      cVar6 = UNK_00d359;
      iVar10 = cVar6 * 0x14;
    }
    else {
      cVar6 = UNK_00d358;
      iVar10 = cVar6 * 0x14;
    }
  }
  else {
    iVar10 = Ram00f632;
    uVar3 = iVar10 + 0x12;
    uVar11 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar11 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar11 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar11 = 3;
    }
    bVar8 = UNK_00d5cc;
    bVar1 = *(byte *)((uint3)uVar11 << 0xe | (uint3)(uVar3 & 0x3fff)) < bVar8;
    cVar6 = UNK_00d577;
    if (cVar6 == '\x06') {
      bVar8 = 8;
    }
    else if ((param_1 == 0) || (param_1 == 4)) {
      bVar8 = 6;
    }
    else if (param_1 == 6) {
      bVar8 = 8;
    }
    else {
      bVar8 = 7;
    }
    iVar10 = (uint)bVar8 + (uint)bVar1 * 9;
    uVar11 = iVar10 + 0xd351;
    uVar4 = 0x24;
    if ((((uVar11 & 0xc000) != 0) && (uVar4 = 0x21, (uVar11 & 0xc000) != 0x4000)) &&
       (uVar4 = 0x2c, (uVar11 & 0xc000) != 0x8000)) {
      uVar4 = 3;
    }
    Ram00d600 = (int)*(char *)((uint3)uVar4 << 0xe | (uint3)(uVar11 & 0x3fff));
    uVar11 = iVar10 + 0xd35a;
    uVar4 = 0x24;
    if ((((uVar11 & 0xc000) != 0) && (uVar4 = 0x21, (uVar11 & 0xc000) != 0x4000)) &&
       (uVar4 = 0x2c, (uVar11 & 0xc000) != 0x8000)) {
      uVar4 = 3;
    }
    Ram00d602 = (int)*(char *)((uint3)uVar4 << 0xe | (uint3)(uVar11 & 0x3fff));
    iVar10 = Ram00f632;
    uVar4 = iVar10 + 0x11 + (uint)bVar1;
    uVar11 = 0x24;
    if ((((uVar4 & 0xc000) != 0) && (uVar11 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
       (uVar11 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
      uVar11 = 3;
    }
    Ram00d604 = (uint)*(byte *)((uint3)uVar11 << 0xe | (uint3)(uVar4 & 0x3fff));
    uVar3 = uVar3 + bVar1;
    uVar11 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar11 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar11 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar11 = 3;
    }
    Ram00d606 = (uint)*(byte *)((uint3)uVar11 << 0xe | (uint3)(uVar3 & 0x3fff));
    bVar8 = UNK_00d5cc;
    Ram00d608 = (uint)bVar8;
    uVar9 = egs52_lerp_signed_axis((ushort *)0xd600);
    iVar10 = uVar9 * 0x14;
  }
  cVar6 = UNK_00d60e;
  if (cVar6 == '\x03') {
    iVar7 = Ram00f61e;
    uVar11 = iVar7 + 0x1d;
    uVar3 = 0x24;
    if ((((uVar11 & 0xc000) != 0) && (uVar3 = 0x21, (uVar11 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar11 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    if ((((*(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar11 & 0x3fff)) & 0x40) != 0) &&
        (cVar6 = UNK_00d7aa, cVar6 == '\x02')) && (cVar6 = UNK_00d577, cVar6 == '\x03')) {
      iVar7 = Ram00f634;
      uVar11 = iVar7 + 0x4a;
      uVar3 = 0x24;
      if ((((uVar11 & 0xc000) != 0) && (uVar3 = 0x21, (uVar11 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar11 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      param_2 = param_2 + *(int *)((uint3)uVar3 << 0xe | (uint3)(uVar11 & 0x3fff));
    }
  }
  uVar11 = param_2 + iVar10;
  if ((int)uVar11 < 1) {
    uVar11 = 0;
  }
  uVar3 = Ram00d552;
  if (uVar3 <= uVar11) {
    uVar11 = Ram00d552;
  }
  iVar10 = Ram00f626;
  uVar3 = iVar10 + (uint)param_1 * 2 + 0x3c;
  uVar4 = 0x24;
  if ((((uVar3 & 0xc000) != 0) && (uVar4 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
     (uVar4 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
    uVar4 = 3;
  }
  iVar10 = Ram00f626;
  uVar2 = iVar10 + 0x3a;
  uVar5 = 0x24;
  if ((((uVar2 & 0xc000) != 0) && (uVar5 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
     (uVar5 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
    uVar5 = 3;
  }
  return (int)(((ulong)uVar11 * 1000) /
              (ulong)*(uint *)((uint3)uVar4 << 0xe | (uint3)(uVar3 & 0x3fff))) +
         *(int *)((uint3)uVar5 << 0xe | (uint3)(uVar2 & 0x3fff));
}


