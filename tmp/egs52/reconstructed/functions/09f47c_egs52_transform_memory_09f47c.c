/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x09f47c; FLS offset 0x01f47c.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x09f4ee) */
/* WARNING: Removing unreachable block (ram,0x09f4e2) */
/* WARNING: Removing unreachable block (ram,0x09f4c0) */
/* WARNING: Removing unreachable block (ram,0x09f4b8) */
/* WARNING: Removing unreachable block (ram,0x09f4d6) */
/* WARNING: Removing unreachable block (ram,0x09f4d2) */
/* WARNING: Removing unreachable block (ram,0x09f4a8) */
/* WARNING: Removing unreachable block (ram,0x09f4a6) */
/* WARNING: Removing unreachable block (ram,0x09f48e) */
/* WARNING: Removing unreachable block (ram,0x09f49e) */
/* WARNING: Removing unreachable block (ram,0x09f4ce) */
/* WARNING: Removing unreachable block (ram,0x09f4ba) */

void egs52_transform_memory_09f47c(uint param_1,byte param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  if (param_2 < 2) {
    uVar5 = (uint)param_2 * 8 + 0xc390;
    uVar1 = 0x24;
    if ((((uVar5 & 0xc000) != 0) && (uVar1 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    uVar1 = *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar5 & 0x3fff));
    if (param_1 < 0x4b1) {
      uVar2 = 0x24;
      if ((((uVar5 & 0xc000) != 0) && (uVar2 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar5 & 0x3fff)) = param_1 * 10;
    }
    else {
      uVar2 = 0x24;
      if ((((uVar5 & 0xc000) != 0) && (uVar2 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      *(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar5 & 0x3fff)) = 12000;
    }
    uVar2 = 0x24;
    if ((((uVar5 & 0xc000) != 0) && (uVar2 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    if (uVar1 < *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar5 & 0x3fff))) {
      uVar6 = (uint)param_2 * 2 + 0xc39e;
      uVar2 = 0x24;
      if ((((uVar6 & 0xc000) != 0) && (uVar2 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      uVar3 = 0x24;
      if ((((uVar5 & 0xc000) != 0) && (uVar3 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      uVar4 = 0x24;
      if ((((uVar6 & 0xc000) != 0) && (uVar4 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
         (uVar4 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
        uVar4 = 3;
      }
      *(uint *)((uint3)uVar4 << 0xe | (uint3)(uVar6 & 0x3fff)) =
           *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar6 & 0x3fff)) +
           (*(int *)((uint3)uVar3 << 0xe | (uint3)(uVar5 & 0x3fff)) - uVar1);
    }
    else {
      uVar6 = (uint)param_2 * 2 + 0xc39e;
      uVar2 = 0x24;
      if ((((uVar6 & 0xc000) != 0) && (uVar2 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      uVar3 = 0x24;
      if ((((uVar5 & 0xc000) != 0) && (uVar3 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      uVar4 = 0x24;
      if ((((uVar6 & 0xc000) != 0) && (uVar4 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
         (uVar4 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
        uVar4 = 3;
      }
      *(uint *)((uint3)uVar4 << 0xe | (uint3)(uVar6 & 0x3fff)) =
           *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar6 & 0x3fff)) +
           (uVar1 - *(int *)((uint3)uVar3 << 0xe | (uint3)(uVar5 & 0x3fff)));
    }
    uVar5 = (uint)param_2 * 2 + 0xc39e;
    uVar1 = 0x24;
    if ((((uVar5 & 0xc000) != 0) && (uVar1 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    if (24000 < *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar5 & 0x3fff))) {
      uVar1 = 0x24;
      if ((((uVar5 & 0xc000) != 0) && (uVar1 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(uVar5 & 0x3fff)) = 24000;
    }
  }
  return;
}


