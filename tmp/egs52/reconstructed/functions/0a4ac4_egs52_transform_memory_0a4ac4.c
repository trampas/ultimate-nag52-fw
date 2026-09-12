/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a4ac4; FLS offset 0x024ac4.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a4af4) */
/* WARNING: Removing unreachable block (ram,0x0a4b4a) */
/* WARNING: Removing unreachable block (ram,0x0a4b40) */
/* WARNING: Removing unreachable block (ram,0x0a4b2a) */
/* WARNING: Removing unreachable block (ram,0x0a4b26) */
/* WARNING: Removing unreachable block (ram,0x0a4b20) */
/* WARNING: Removing unreachable block (ram,0x0a4b62) */
/* WARNING: Removing unreachable block (ram,0x0a4b5c) */
/* WARNING: Removing unreachable block (ram,0x0a4ae2) */
/* WARNING: Removing unreachable block (ram,0x0a4ada) */
/* WARNING: Removing unreachable block (ram,0x0a4b66) */
/* WARNING: Removing unreachable block (ram,0x0a4b7c) */
/* WARNING: Removing unreachable block (ram,0x0a4b10) */
/* WARNING: Removing unreachable block (ram,0x0a4afe) */

undefined1 egs52_transform_memory_0a4ac4(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined1 uVar7;
  
  if ((param_2 & 4) == 0) {
    uVar4 = (param_1 & 0xff) * 2 + 0xcad0;
    uVar1 = 0x24;
    if ((((uVar4 & 0xc000) != 0) && (uVar1 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    uVar6 = *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar4 & 0x3fff)) >> 0xc;
    uVar1 = 0x24;
    if ((((uVar4 & 0xc000) != 0) && (uVar1 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    uVar1 = *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar4 & 0x3fff)) & 0xfff;
    if ((param_2 & 1) == 0) {
      iVar5 = (param_1 & 0xff) * 0x14;
      uVar4 = (int)&LAB_09930c + iVar5;
      uVar3 = 0x24;
      if ((((uVar4 & 0xc000) != 0) && (uVar3 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      uVar2 = Ram00fdf2;
      if ((uVar2 & 0xfff) < uVar1 ||
          *(uint *)((uint3)uVar3 << 0xe | (uint3)(uVar4 & 0x3fff)) <= (uVar2 & 0xfff) - uVar1) {
        uVar1 = iVar5 + 0x930a;
        uVar4 = 0x24;
        if ((((uVar1 & 0xc000) != 0) && (uVar4 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
           (uVar4 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
          uVar4 = 3;
        }
        if (uVar6 < *(uint *)((uint3)uVar4 << 0xe | (uint3)(uVar1 & 0x3fff))) {
          uVar7 = 0x28;
        }
        else {
          uVar7 = 0x24;
        }
      }
      else {
        uVar7 = 0;
      }
    }
    else {
      if ((param_2 & 0x20) == 0) {
        iVar5 = (param_1 & 0xff) * 0x14;
        uVar3 = iVar5 + 0x930a;
        uVar2 = 0x24;
        if ((((uVar3 & 0xc000) != 0) && (uVar2 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        if (*(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar3 & 0x3fff)) <= uVar6 + 1) {
          return 0x24;
        }
        uVar6 = (int)&LAB_09930c + iVar5;
        uVar3 = 0x24;
        if ((((uVar6 & 0xc000) != 0) && (uVar3 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
           (uVar3 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
          uVar3 = 3;
        }
        uVar2 = Ram00fdf2;
        if ((uVar2 & 0xfff) < uVar1 ||
            *(uint *)((uint3)uVar3 << 0xe | (uint3)(uVar6 & 0x3fff)) <= (uVar2 & 0xfff) - uVar1) {
          uVar6 = Ram00fdf2;
          uVar1 = 0x24;
          if ((((uVar4 & 0xc000) != 0) && (uVar1 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
             (uVar1 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
            uVar1 = 3;
          }
          *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar4 & 0x3fff)) = uVar6 & 0xfff | 0x1000;
        }
      }
      else {
        uVar6 = Ram00fdf2;
        uVar1 = 0x24;
        if ((((uVar4 & 0xc000) != 0) && (uVar1 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar4 & 0x3fff)) = uVar6 & 0xfff | 0x1000;
      }
      uVar7 = 0;
    }
  }
  else {
    uVar7 = 0x24;
  }
  return uVar7;
}


