/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d6f4e; FLS offset 0x056f4e.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d7000) */
/* WARNING: Removing unreachable block (ram,0x0d6fd8) */
/* WARNING: Removing unreachable block (ram,0x0d6fd4) */
/* WARNING: Removing unreachable block (ram,0x0d6fca) */
/* WARNING: Removing unreachable block (ram,0x0d6fba) */
/* WARNING: Removing unreachable block (ram,0x0d6fb4) */
/* WARNING: Removing unreachable block (ram,0x0d6f86) */
/* WARNING: Removing unreachable block (ram,0x0d6f82) */
/* WARNING: Removing unreachable block (ram,0x0d6f74) */
/* WARNING: Removing unreachable block (ram,0x0d6f6c) */
/* WARNING: Removing unreachable block (ram,0x0d6f66) */
/* WARNING: Removing unreachable block (ram,0x0d6f5c) */
/* WARNING: Removing unreachable block (ram,0x0d6fe8) */
/* WARNING: Removing unreachable block (ram,0x0d6fe4) */
/* WARNING: Removing unreachable block (ram,0x0d6ff2) */
/* WARNING: Removing unreachable block (ram,0x0d6fee) */
/* WARNING: Removing unreachable block (ram,0x0d6fdc) */
/* WARNING: Removing unreachable block (ram,0x0d6f60) */

uint egs52_update_near_d418_0d6f4e(uint param_1,uint param_2)

{
  uint uVar1;
  uint *puVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar7 = Ram00fd4a;
  if ((uVar7 & 0x40) == 0) {
    iVar4 = Ram00d490;
    iVar5 = Ram00d4ae;
    uVar7 = (uint)(iVar4 + iVar5) >> 1;
    uVar8 = Ram00d490;
    uVar1 = Ram00d490;
    if (uVar7 != uVar1 && uVar8 <= uVar7) {
      uVar7 = Ram00d490;
    }
    iVar4 = Ram00d4ae;
    iVar5 = Ram00f634;
    uVar8 = iVar5 + 0x1e;
    uVar1 = 0x24;
    if ((((uVar8 & 0xc000) != 0) && (uVar1 = 0x21, (uVar8 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar8 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    bVar3 = *(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar8 & 0x3fff));
    uVar6 = egs52_lookup_and_offset_d467();
    iVar5 = Ram00f624;
    uVar8 = iVar5 + (param_1 & 0xff) * 2 + 0xb2;
    uVar1 = 0x24;
    if ((((uVar8 & 0xc000) != 0) && (uVar1 = 0x21, (uVar8 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar8 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    uVar8 = (uint)(((((ulong)((uVar7 + iVar4) * 10) * (ulong)((param_2 & 0xff) + (uint)bVar3 * 2)) /
                     (ulong)(uVar6 & 0xff) & 0xffff) *
                   (ulong)*(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar8 & 0x3fff))) / 10);
    iVar4 = Ram00f634;
    uVar1 = iVar4 + 0x20;
    uVar7 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar7 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar7 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar7 = 3;
    }
    puVar2 = (uint *)((uint3)uVar7 << 0xe | (uint3)(uVar1 & 0x3fff));
    if (uVar8 == *puVar2 || (int)uVar8 < (int)*puVar2) {
      uVar7 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar7 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar7 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar7 = 3;
      }
      uVar8 = *(uint *)((uint3)uVar7 << 0xe | (uint3)(uVar1 & 0x3fff));
    }
  }
  else {
    uVar7 = Ram00fd4a;
    if ((uVar7 & 0x80) == 0) {
      iVar4 = Ram00f634;
      uVar7 = iVar4 + 0x20;
      uVar8 = 0x24;
      if ((((uVar7 & 0xc000) != 0) && (uVar8 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
         (uVar8 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
        uVar8 = 3;
      }
      uVar8 = *(uint *)((uint3)uVar8 << 0xe | (uint3)(uVar7 & 0x3fff));
    }
    else {
      iVar4 = Ram00f634;
      uVar7 = iVar4 + 0x22;
      uVar8 = 0x24;
      if ((((uVar7 & 0xc000) != 0) && (uVar8 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
         (uVar8 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
        uVar8 = 3;
      }
      uVar8 = *(uint *)((uint3)uVar8 << 0xe | (uint3)(uVar7 & 0x3fff));
    }
  }
  if (0x7ffe < uVar8) {
    uVar8 = 0x7fff;
  }
  Ram00d418 = uVar8;
  return uVar8;
}


