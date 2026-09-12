/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x09edae; FLS offset 0x01edae.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x09edbc) */
/* WARNING: Removing unreachable block (ram,0x09edce) */
/* WARNING: Removing unreachable block (ram,0x09edd4) */
/* WARNING: Removing unreachable block (ram,0x09edb8) */
/* WARNING: Removing unreachable block (ram,0x09edc4) */

int egs52_register_arithmetic_09edae(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = 0;
  iVar5 = 0;
  while( true ) {
    uVar2 = iVar5 * 4 + 0x782;
    uVar4 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar4 = 3;
    }
    if (*(int *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff)) == 0) {
      return iVar6;
    }
    uVar2 = iVar5 * 4 + 0x784;
    uVar4 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar4 = 3;
    }
    if (*(int *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff)) == 0) break;
    uVar2 = iVar5 * 4 + 0x782;
    uVar4 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar4 = 3;
    }
    uVar1 = iVar5 * 4 + 0x784;
    uVar3 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    uVar4 = (*(int *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff)) +
            *(int *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff))) - 6;
    uVar2 = 0x24;
    if ((((uVar4 & 0xc000) != 0) && (uVar2 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    iVar6 = iVar6 + *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar4 & 0x3fff));
    iVar5 = iVar5 + 1;
  }
  return iVar6;
}


