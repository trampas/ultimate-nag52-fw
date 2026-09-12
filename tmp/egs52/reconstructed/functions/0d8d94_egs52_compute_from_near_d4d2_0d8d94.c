/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d8d94; FLS offset 0x058d94.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d8e94) */
/* WARNING: Removing unreachable block (ram,0x0d8e8a) */
/* WARNING: Removing unreachable block (ram,0x0d8e66) */
/* WARNING: Removing unreachable block (ram,0x0d8e60) */
/* WARNING: Removing unreachable block (ram,0x0d8e5c) */
/* WARNING: Removing unreachable block (ram,0x0d8e52) */
/* WARNING: Removing unreachable block (ram,0x0d8e44) */
/* WARNING: Removing unreachable block (ram,0x0d8e3e) */
/* WARNING: Removing unreachable block (ram,0x0d8e34) */
/* WARNING: Removing unreachable block (ram,0x0d8e1c) */
/* WARNING: Removing unreachable block (ram,0x0d8e02) */
/* WARNING: Removing unreachable block (ram,0x0d8de2) */
/* WARNING: Removing unreachable block (ram,0x0d8ddc) */
/* WARNING: Removing unreachable block (ram,0x0d8dd6) */
/* WARNING: Removing unreachable block (ram,0x0d8dc2) */
/* WARNING: Removing unreachable block (ram,0x0d8dba) */
/* WARNING: Removing unreachable block (ram,0x0d8db6) */
/* WARNING: Removing unreachable block (ram,0x0d8da8) */
/* WARNING: Removing unreachable block (ram,0x0d8da4) */
/* WARNING: Removing unreachable block (ram,0x0d8da0) */
/* WARNING: Removing unreachable block (ram,0x0d8dfe) */
/* WARNING: Removing unreachable block (ram,0x0d8e20) */

uint egs52_compute_from_near_d4d2_0d8d94(char param_1,undefined2 param_2)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  ulong uVar4;
  int iVar5;
  undefined1 uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uStack_8;
  
  iVar9 = Ram00d4d2;
  iVar5 = Ram00d4ac;
  iVar7 = Ram00d490;
  uStack_8 = (iVar9 + iVar5) - iVar7;
  if ((int)uStack_8 < 0) {
    uStack_8 = 0;
  }
  iVar9 = Ram00f63a;
  uVar8 = iVar9 + 0x4b;
  uVar1 = 0x24;
  if ((((uVar8 & 0xc000) != 0) && (uVar1 = 0x21, (uVar8 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uVar8 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  uVar3 = Ram00d46c;
  iVar9 = Ram00d548;
  uStack_8 = (int)(((ulong)uStack_8 * (ulong)uVar3) /
                  (ulong)*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar8 & 0x3fff))) + iVar9;
  uVar8 = Ram00d534;
  uVar1 = Ram00d534;
  if (uStack_8 == uVar1 || uStack_8 < uVar8) {
    uStack_8 = 0;
  }
  else {
    iVar9 = Ram00d534;
    uStack_8 = uStack_8 - iVar9;
  }
  if ((param_1 == '\0') || (param_1 == '\x04')) {
    iVar9 = Ram00f626;
    uVar8 = iVar9 + 4;
    uVar1 = 0x24;
    if ((((uVar8 & 0xc000) != 0) && (uVar1 = 0x21, (uVar8 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar8 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    uVar4 = (ulong)uStack_8 * (ulong)*(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar8 & 0x3fff));
    uVar8 = (uint)(uVar4 >> 0x10);
    uStack_8 = (uint)((uVar4 & 0xffff | (ulong)uVar8 << 0x10) / 1000);
  }
  else {
    iVar9 = Ram00f626;
    uVar8 = iVar9 + 6;
    uVar1 = 0x24;
    if (((uVar8 & 0xc000) != 0) &&
       ((uVar1 = 0x21, (uVar8 & 0xc000) != 0x4000 && (uVar1 = 0x2c, (uVar8 & 0xc000) != 0x8000)))) {
      uVar1 = 3;
    }
    uVar4 = (ulong)uStack_8 * (ulong)*(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar8 & 0x3fff));
    uVar8 = (uint)(uVar4 >> 0x10);
    uStack_8 = (uint)((uVar4 & 0xffff | (ulong)uVar8 << 0x10) / 1000);
  }
  iVar9 = Ram00f626;
  uVar3 = iVar9 + 8;
  uVar1 = 0x24;
  if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  puVar2 = (uint *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff));
  if (uStack_8 == *puVar2 || uStack_8 < *puVar2) {
    uStack_8 = 0;
  }
  else {
    uVar1 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    uStack_8 = uStack_8 - *(int *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff));
  }
  uVar6 = UNK_00d577;
  iVar7 = egs52_update_near_d426_0d4338(uVar6,uVar8);
  iVar9 = Ram00d54a;
  uVar8 = iVar7 + iVar9;
  uVar1 = Ram00d536;
  uVar3 = Ram00d536;
  if (uVar8 == uVar3 || uVar8 < uVar1) {
    iVar9 = 0;
  }
  else {
    iVar9 = Ram00d536;
    iVar9 = uVar8 - iVar9;
  }
  uVar8 = egs52_compute_from_near_f626_0d7c4e(param_1 + 4U & 7,param_2,iVar9);
  if (uStack_8 <= uVar8) {
    uStack_8 = uVar8;
  }
  uVar8 = Ram00d54c;
  if (uVar8 <= uStack_8) {
    uStack_8 = Ram00d54c;
  }
  return uStack_8;
}


