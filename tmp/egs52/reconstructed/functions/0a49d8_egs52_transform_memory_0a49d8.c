/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a49d8; FLS offset 0x0249d8.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a49fa) */
/* WARNING: Removing unreachable block (ram,0x0a49e4) */
/* WARNING: Removing unreachable block (ram,0x0a4a10) */
/* WARNING: Removing unreachable block (ram,0x0a4a06) */
/* WARNING: Removing unreachable block (ram,0x0a49e8) */

undefined1 egs52_transform_memory_0a49d8(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined2 uVar5;
  int iVar6;
  
  if ((param_2 & 2) == 0) {
    uVar5 = Ram00fdf2;
    uVar2 = (param_1 & 0xff) * 2 + 0xcbd0;
    uVar4 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar4 = 3;
    }
    *(undefined2 *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff)) = uVar5;
  }
  else {
    uVar2 = (param_1 & 0xff) * 2 + 0xcbd0;
    uVar4 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar4 = 3;
    }
    iVar6 = Ram00fdf2;
    uVar1 = (param_1 & 0xff) * 0x14 + 0x930a;
    uVar3 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    if (*(uint *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)) <=
        (uint)(iVar6 - *(int *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff)))) {
      return 0;
    }
  }
  return 1;
}


