/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a134c; FLS offset 0x02134c.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a136c) */
/* WARNING: Removing unreachable block (ram,0x0a1352) */
/* WARNING: Removing unreachable block (ram,0x0a1364) */

uint egs52_register_arithmetic_0a134c(char param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = -0x3bb0;
  uVar4 = 0;
  do {
    uVar1 = iVar3 + 6;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    uVar2 = iVar3 + (uint)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) * 6;
    uVar1 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    if (*(char *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) == param_1) {
      uVar1 = uVar4 + 0xc4d0;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      if (*(char *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) == '\0') {
        return uVar4;
      }
    }
    iVar3 = iVar3 + 8;
    uVar4 = uVar4 + 1;
    if (0xf < uVar4) {
      return 0xfd;
    }
  } while( true );
}


