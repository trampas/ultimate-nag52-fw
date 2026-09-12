/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x09be4e; FLS offset 0x01be4e.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x09be68) */
/* WARNING: Removing unreachable block (ram,0x09be62) */
/* WARNING: Removing unreachable block (ram,0x09be56) */
/* WARNING: Removing unreachable block (ram,0x09be70) */

char egs52_transform_memory_09be4e(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  char cVar4;
  byte bVar5;
  
  cVar4 = '\x02';
  while( true ) {
    uVar3 = 0x24;
    if ((((param_2 & 0xc000) != 0) && (uVar3 = 0x21, (param_2 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (param_2 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    if (*(int *)((uint3)uVar3 << 0xe | (uint3)(param_2 & 0x3fff)) == 0) break;
    uVar3 = param_2 + 2;
    uVar1 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    bVar5 = *(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff));
    cVar4 = cVar4 + bVar5;
    while (bVar5 != 0) {
      param_1 = param_1 + 1;
      bVar5 = bVar5 - 1;
      uVar3 = 0x24;
      if ((((param_2 & 0xc000) != 0) && (uVar3 = 0x21, (param_2 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (param_2 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      uVar1 = *(int *)((uint3)uVar3 << 0xe | (uint3)(param_2 & 0x3fff)) + (uint)bVar5;
      uVar3 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      uVar2 = 0x24;
      if ((((param_1 & 0xc000) != 0) && (uVar2 = 0x21, (param_1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (param_1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(param_1 & 0x3fff)) =
           *(undefined1 *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff));
    }
    param_2 = param_2 + 4;
  }
  return cVar4;
}


