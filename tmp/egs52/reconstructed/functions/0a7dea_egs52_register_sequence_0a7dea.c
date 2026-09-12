/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a7dea; FLS offset 0x027dea.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a7dfa) */

int egs52_register_sequence_0a7dea(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = -1;
  if ((param_1 & 0xff) != 0) {
    uVar2 = 0xa88;
    do {
      uVar3 = uVar2;
      uVar1 = 0x24;
      if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      uVar2 = uVar3 + 2;
    } while ((param_1 & *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff))) == 0);
    iVar4 = ((int)(uVar3 - 0xa86) >> 1) + -1;
  }
  return iVar4;
}


