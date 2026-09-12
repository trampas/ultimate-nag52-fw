/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a1032; FLS offset 0x021032.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Function: egs52_read_far_u32_registers replaced with injection:
   egs52_read_far_u32_registers */
/* WARNING: Removing unreachable block (ram,0x0a106a) */
/* WARNING: Removing unreachable block (ram,0x0a1068) */
/* WARNING: Removing unreachable block (ram,0x0a1044) */
/* WARNING: Removing unreachable block (ram,0x0a1038) */
/* WARNING: Removing unreachable block (ram,0x0a1058) */
/* WARNING: Removing unreachable block (ram,0x0a104e) */
/* WARNING: Removing unreachable block (ram,0x0a1050) */
/* WARNING: Removing unreachable block (ram,0x0a105a) */

int egs52_compute_from_near_f842_0a1032(uint param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  iVar6 = 0;
  while( true ) {
    bVar3 = UNK_00f842;
    uVar1 = (uint)bVar3 * 0x1c + 0x83c2;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    uVar2 = *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) + iVar6 * 4;
    uVar1 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    uVar4 = uVar2 + 2;
    uVar5 = 0x24;
    if ((((uVar4 & 0xc000) != 0) && (uVar5 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
       (uVar5 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
      uVar5 = 3;
    }
    if (*(int *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) == 0 &&
        *(int *)((uint3)uVar5 << 0xe | (uint3)(uVar4 & 0x3fff)) == 0) break;
    uVar1 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    uVar5 = *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
    uVar1 = uVar2 + 2;
    uVar4 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar4 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar4 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar4 = 3;
    }
    uVar1 = *(uint *)((uint3)uVar4 << 0xe | (uint3)(uVar1 & 0x3fff));
    uVar4 = *(uint *)((uint3)uVar1 << 0x10 | (uint3)uVar5);
    if (*(int *)((uint3)(uVar1 + (0xfffd < uVar5)) << 0x10 | (uint3)(uVar5 + 2)) - param_2 ==
        (uint)(uVar4 < param_1) && uVar4 == param_1) break;
    iVar6 = iVar6 + 1;
  }
  uVar1 = 0x24;
  if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  uVar5 = uVar2 + 2;
  uVar4 = 0x24;
  if ((((uVar5 & 0xc000) != 0) && (uVar4 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
     (uVar4 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
    uVar4 = 3;
  }
  if (*(int *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) != 0 ||
      *(int *)((uint3)uVar4 << 0xe | (uint3)(uVar5 & 0x3fff)) != 0) {
    return iVar6;
  }
  return 0xff;
}


