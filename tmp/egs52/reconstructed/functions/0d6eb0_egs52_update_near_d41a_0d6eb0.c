/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d6eb0; FLS offset 0x056eb0.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d6f40) */
/* WARNING: Removing unreachable block (ram,0x0d6f3e) */
/* WARNING: Removing unreachable block (ram,0x0d6f3a) */
/* WARNING: Removing unreachable block (ram,0x0d6f30) */
/* WARNING: Removing unreachable block (ram,0x0d6f1c) */
/* WARNING: Removing unreachable block (ram,0x0d6f16) */
/* WARNING: Removing unreachable block (ram,0x0d6f02) */
/* WARNING: Removing unreachable block (ram,0x0d6ef6) */
/* WARNING: Removing unreachable block (ram,0x0d6ece) */
/* WARNING: Removing unreachable block (ram,0x0d6eca) */
/* WARNING: Removing unreachable block (ram,0x0d6ec0) */
/* WARNING: Removing unreachable block (ram,0x0d6ebc) */
/* WARNING: Removing unreachable block (ram,0x0d6eb8) */

int egs52_update_near_d41a_0d6eb0(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  byte bVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  
  iVar11 = Ram00d4dc;
  iVar8 = Ram00d4da;
  iVar7 = Ram00d4bc;
  iVar9 = Ram00f63a;
  uVar1 = iVar9 + 0x1e;
  uVar3 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar3 = 3;
  }
  bVar6 = *(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff));
  uVar10 = egs52_lookup_and_offset_d467();
  iVar9 = Ram00f63a;
  uVar3 = iVar9 + 0x62 + (param_1 & 0xff);
  uVar1 = 0x24;
  if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  iVar9 = Ram00f624;
  uVar2 = iVar9 + (param_1 & 0xff) * 2 + 0xb2;
  uVar4 = 0x24;
  if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
     (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
    uVar4 = 3;
  }
  iVar11 = (int)(((((((ulong)(uint)((iVar11 + iVar8 + iVar7) * 5) *
                     (ulong)((param_2 & 0xff) + (uint)bVar6 * 2)) / (ulong)(uVar10 & 0xff) & 0xffff)
                   * (ulong)*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff))) / 100 & 0xffff
                  ) * (ulong)*(uint *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff))) / 10);
  iVar7 = Ram00f634;
  uVar3 = iVar7 + 0x20;
  uVar1 = 0x24;
  if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  piVar5 = (int *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff));
  if (iVar11 == *piVar5 || iVar11 < *piVar5) {
    uVar1 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    iVar11 = *(int *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff));
  }
  Ram00d41a = iVar11;
  return iVar11;
}


