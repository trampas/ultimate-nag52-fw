/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a4aa8; FLS offset 0x024aa8.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a4abc) */
/* WARNING: Removing unreachable block (ram,0x0a4ab8) */
/* WARNING: Removing unreachable block (ram,0x0a4ab4) */
/* WARNING: Removing unreachable block (ram,0x0a4aa8) */

undefined1 egs52_transform_memory_0a4aa8(uint param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined2 uVar4;
  
  uVar4 = Ram00fdf2;
  iVar3 = (param_1 & 0xff) * 2;
  uVar1 = iVar3 + 0xcad0;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  *(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) = uVar4;
  uVar4 = Ram00fdf2;
  uVar1 = iVar3 + 0xcbd0;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  *(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) = uVar4;
  return 0;
}


