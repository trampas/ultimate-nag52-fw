/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0810cc; FLS offset 0x0010cc.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0810d6) */
/* WARNING: Removing unreachable block (ram,0x0810d8) */

char egs52_register_arithmetic_0810cc(uint param_1,char param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  char cVar4;
  
  cVar4 = '\x01';
  while ((cVar4 == '\x01' && (param_2 != '\0'))) {
    if ((param_3 & 0x8000) != 0) {
      uVar2 = 0x24;
      if ((((param_1 & 0xc000) != 0) && (uVar2 = 0x21, (param_1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (param_1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      uVar1 = param_1 + 0x10;
      uVar3 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      if (*(char *)((uint3)uVar2 << 0xe | (uint3)(param_1 & 0x3fff)) !=
          *(char *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff))) {
        cVar4 = '\0';
      }
    }
    param_3 = param_3 << 1;
    param_1 = param_1 + 1;
    param_2 = param_2 + -1;
  }
  return cVar4;
}


