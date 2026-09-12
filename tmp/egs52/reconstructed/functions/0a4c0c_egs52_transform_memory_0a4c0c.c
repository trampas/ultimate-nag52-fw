/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a4c0c; FLS offset 0x024c0c.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a4d20) */
/* WARNING: Removing unreachable block (ram,0x0a4c46) */
/* WARNING: Removing unreachable block (ram,0x0a4c3c) */
/* WARNING: Removing unreachable block (ram,0x0a4c96) */
/* WARNING: Removing unreachable block (ram,0x0a4c8c) */
/* WARNING: Removing unreachable block (ram,0x0a4c7c) */
/* WARNING: Removing unreachable block (ram,0x0a4cb6) */
/* WARNING: Removing unreachable block (ram,0x0a4c9e) */
/* WARNING: Removing unreachable block (ram,0x0a4c64) */
/* WARNING: Removing unreachable block (ram,0x0a4c60) */
/* WARNING: Removing unreachable block (ram,0x0a4c5a) */
/* WARNING: Removing unreachable block (ram,0x0a4ce8) */
/* WARNING: Removing unreachable block (ram,0x0a4cd2) */
/* WARNING: Removing unreachable block (ram,0x0a4cce) */
/* WARNING: Removing unreachable block (ram,0x0a4cc8) */
/* WARNING: Removing unreachable block (ram,0x0a4c2e) */
/* WARNING: Removing unreachable block (ram,0x0a4c26) */
/* WARNING: Removing unreachable block (ram,0x0a4d4e) */
/* WARNING: Removing unreachable block (ram,0x0a4d3e) */
/* WARNING: Removing unreachable block (ram,0x0a4d3a) */
/* WARNING: Removing unreachable block (ram,0x0a4d1a) */
/* WARNING: Removing unreachable block (ram,0x0a4d28) */

undefined2 egs52_transform_memory_0a4c0c(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined2 uVar8;
  
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
          uVar8 = 0x28;
        }
        else {
          uVar8 = 0x24;
        }
      }
      else {
        uVar8 = 0;
      }
    }
    else if ((param_2 & 0x20) == 0) {
      uVar6 = uVar6 + 1;
      iVar5 = (param_1 & 0xff) * 0x14;
      uVar3 = (int)&LAB_09930c + iVar5;
      uVar2 = 0x24;
      if ((((uVar3 & 0xc000) != 0) && (uVar2 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      uVar7 = Ram00fdf2;
      if ((uVar7 & 0xfff) < uVar1 ||
          *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar3 & 0x3fff)) <= (uVar7 & 0xfff) - uVar1) {
        uVar1 = iVar5 + 0x930a;
        uVar3 = 0x24;
        if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
           (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
          uVar3 = 3;
        }
        if (uVar6 < *(uint *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff))) {
          uVar6 = Ram00fdf2;
          uVar1 = 0x24;
          if ((((uVar4 & 0xc000) != 0) && (uVar1 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
             (uVar1 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
            uVar1 = 3;
          }
          *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar4 & 0x3fff)) = uVar6 & 0xfff | 0x1000;
          uVar8 = 0;
        }
        else {
          uVar8 = 0x24;
        }
      }
      else {
        uVar3 = iVar5 + 0x930a;
        uVar2 = 0x24;
        if ((((uVar3 & 0xc000) != 0) && (uVar2 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        if (uVar6 < *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar3 & 0x3fff))) {
          uVar3 = 0x24;
          if ((((uVar4 & 0xc000) != 0) && (uVar3 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
             (uVar3 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
            uVar3 = 3;
          }
          *(uint *)((uint3)uVar3 << 0xe | (uint3)(uVar4 & 0x3fff)) = uVar6 * 0x1000 | uVar1;
          uVar8 = 0;
        }
        else {
          uVar8 = 0x24;
        }
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
      uVar8 = 0;
    }
  }
  else if ((param_2 & 1) == 0) {
    if ((param_2 & 0x20) == 0) {
      uVar1 = (param_1 & 0xff) * 2 + 0xcad0;
      uVar4 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar4 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar4 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar4 = 3;
      }
      iVar5 = Ram00fdf2;
      uVar6 = (param_1 & 0xff) * 0x14 + 0x930e;
      uVar3 = 0x24;
      if ((((uVar6 & 0xc000) != 0) && (uVar3 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      if ((uint)(iVar5 - *(int *)((uint3)uVar4 << 0xe | (uint3)(uVar1 & 0x3fff))) <
          *(uint *)((uint3)uVar3 << 0xe | (uint3)(uVar6 & 0x3fff))) {
        uVar8 = 4;
      }
      else {
        uVar8 = 0x28;
      }
    }
    else {
      uVar1 = (param_1 & 0xff) * 0x14 + 0x930e;
      uVar4 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar4 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar4 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar4 = 3;
      }
      if (*(int *)((uint3)uVar4 << 0xe | (uint3)(uVar1 & 0x3fff)) == 0) {
        uVar8 = 0x28;
      }
      else {
        uVar8 = Ram00fdf2;
        uVar1 = (param_1 & 0xff) * 2 + 0xcad0;
        uVar4 = 0x24;
        if ((((uVar1 & 0xc000) != 0) && (uVar4 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
           (uVar4 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
          uVar4 = 3;
        }
        *(undefined2 *)((uint3)uVar4 << 0xe | (uint3)(uVar1 & 0x3fff)) = uVar8;
        uVar8 = 4;
      }
    }
  }
  else {
    uVar8 = 0x24;
  }
  return uVar8;
}


