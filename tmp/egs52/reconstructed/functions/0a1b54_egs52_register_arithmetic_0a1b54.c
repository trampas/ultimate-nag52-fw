/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a1b54; FLS offset 0x021b54.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a1b72) */
/* WARNING: Removing unreachable block (ram,0x0a1b5c) */
/* WARNING: Removing unreachable block (ram,0x0a1b6c) */

undefined1 egs52_register_arithmetic_0a1b54(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  byte bVar4;
  
  bVar4 = 0;
  do {
    uVar1 = (uint)bVar4 * 8 + 0xc456;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    iVar3 = (uint)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) * 6 + (uint)bVar4 * 8;
    uVar1 = iVar3 + 0xc450;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    if (*(char *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) != '\0') {
      uVar1 = iVar3 + 0xc451;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      if ((*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) & 0x40) != 0) {
        return 1;
      }
    }
    bVar4 = bVar4 + 1;
    if (0xf < bVar4) {
      return 0;
    }
  } while( true );
}


