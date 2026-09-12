/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a48ca; FLS offset 0x0248ca.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a48fc) */
/* WARNING: Removing unreachable block (ram,0x0a48f2) */
/* WARNING: Removing unreachable block (ram,0x0a48ea) */
/* WARNING: Removing unreachable block (ram,0x0a48da) */

undefined1 egs52_transform_memory_0a48ca(uint param_1,char param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if (param_2 == '\0') {
    uVar1 = (param_1 & 0xff) * 2 + 0xcad0;
    uVar3 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    *(undefined2 *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)) = 0;
  }
  else {
    uVar1 = (param_1 & 0xff) * 0x14 + 0x930a;
    uVar3 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    uVar2 = (param_1 & 0xff) * 2 + 0xcad0;
    uVar4 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar4 = 3;
    }
    *(undefined2 *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff)) =
         *(undefined2 *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff));
  }
  uVar1 = (param_1 & 0xff) * 2 + 0xcbd0;
  uVar3 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar3 = 3;
  }
  *(undefined2 *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)) = 0;
  return 0;
}


