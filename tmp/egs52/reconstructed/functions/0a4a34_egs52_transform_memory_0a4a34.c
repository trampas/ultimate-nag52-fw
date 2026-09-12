/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a4a34; FLS offset 0x024a34.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a4a5a) */
/* WARNING: Removing unreachable block (ram,0x0a4a88) */
/* WARNING: Removing unreachable block (ram,0x0a4a78) */
/* WARNING: Removing unreachable block (ram,0x0a4a74) */
/* WARNING: Removing unreachable block (ram,0x0a4a54) */
/* WARNING: Removing unreachable block (ram,0x0a4a62) */

undefined1 egs52_transform_memory_0a4a34(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined2 uVar6;
  undefined1 uVar7;
  
  if ((param_2 & 4) == 0) {
    if ((param_2 & 1) == 0) {
      uVar7 = 0x28;
    }
    else if ((param_2 & 0x20) == 0) {
      uVar1 = (param_1 & 0xff) * 2 + 0xcad0;
      uVar3 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      iVar5 = Ram00fdf2;
      uVar2 = (param_1 & 0xff) * 0x14 + 0x930a;
      uVar4 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar4 = 3;
      }
      if ((uint)(iVar5 - *(int *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff))) <
          *(uint *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff))) {
        uVar7 = 0;
      }
      else {
        uVar7 = 0x24;
      }
    }
    else {
      uVar1 = (param_1 & 0xff) * 0x14 + 0x930a;
      uVar3 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      if (*(int *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)) == 0) {
        uVar7 = 0x24;
      }
      else {
        uVar6 = Ram00fdf2;
        uVar1 = (param_1 & 0xff) * 2 + 0xcad0;
        uVar3 = 0x24;
        if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
           (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
          uVar3 = 3;
        }
        *(undefined2 *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)) = uVar6;
        uVar7 = 0;
      }
    }
  }
  else {
    uVar7 = 0x24;
  }
  return uVar7;
}


