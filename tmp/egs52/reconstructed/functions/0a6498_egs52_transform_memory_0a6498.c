/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a6498; FLS offset 0x026498.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a64ec) */
/* WARNING: Removing unreachable block (ram,0x0a64e6) */
/* WARNING: Removing unreachable block (ram,0x0a64e4) */
/* WARNING: Removing unreachable block (ram,0x0a64d6) */
/* WARNING: Removing unreachable block (ram,0x0a64c6) */
/* WARNING: Removing unreachable block (ram,0x0a64c4) */
/* WARNING: Removing unreachable block (ram,0x0a64c2) */
/* WARNING: Removing unreachable block (ram,0x0a64be) */
/* WARNING: Removing unreachable block (ram,0x0a64b8) */
/* WARNING: Removing unreachable block (ram,0x0a64b4) */
/* WARNING: Removing unreachable block (ram,0x0a64ac) */
/* WARNING: Removing unreachable block (ram,0x0a64aa) */
/* WARNING: Removing unreachable block (ram,0x0a64a6) */
/* WARNING: Removing unreachable block (ram,0x0a649e) */
/* WARNING: Removing unreachable block (ram,0x0a64d2) */
/* WARNING: Removing unreachable block (ram,0x0a64dc) */

void egs52_transform_memory_0a6498(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar5 = param_2 + 4;
  uVar1 = 0x24;
  if ((((uVar5 & 0xc000) != 0) && (uVar1 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  uVar6 = param_2 + 6;
  uVar2 = 0x24;
  if ((((uVar6 & 0xc000) != 0) && (uVar2 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  if (*(int *)((uint3)uVar1 << 0xe | (uint3)(uVar5 & 0x3fff)) ==
      *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar6 & 0x3fff))) {
    uVar1 = 0x24;
    if ((((param_2 & 0xc000) != 0) && (uVar1 = 0x21, (param_2 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (param_2 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    uVar2 = param_2 + 2;
    uVar3 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar3 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    if (*(int *)((uint3)uVar1 << 0xe | (uint3)(param_2 & 0x3fff)) ==
        *(int *)((uint3)uVar3 << 0xe | (uint3)(uVar2 & 0x3fff))) {
      uVar1 = 0x24;
      if ((((param_2 & 0xc000) != 0) && (uVar1 = 0x21, (param_2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (param_2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      if (*(int *)((uint3)uVar1 << 0xe | (uint3)(param_2 & 0x3fff)) == 0) {
        uVar2 = param_2 + 0xc;
        uVar1 = 0x24;
        if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        if (*(char *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) == '\0') {
          return;
        }
        uVar1 = param_2 + 10;
        uVar6 = 0x24;
        if ((((uVar1 & 0xc000) != 0) && (uVar6 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
           (uVar6 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
          uVar6 = 3;
        }
        uVar3 = param_1 + 10;
        uVar4 = 0x24;
        if ((((uVar3 & 0xc000) != 0) && (uVar4 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
           (uVar4 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
          uVar4 = 3;
        }
        if ((uint)(param_3 - *(int *)((uint3)uVar6 << 0xe | (uint3)(uVar1 & 0x3fff))) <
            *(uint *)((uint3)uVar4 << 0xe | (uint3)(uVar3 & 0x3fff))) {
          return;
        }
        uVar1 = 0x24;
        if ((((uVar5 & 0xc000) != 0) && (uVar1 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        param_2 = param_2 + 8;
        uVar6 = 0x24;
        if ((((param_2 & 0xc000) != 0) && (uVar6 = 0x21, (param_2 & 0xc000) != 0x4000)) &&
           (uVar6 = 0x2c, (param_2 & 0xc000) != 0x8000)) {
          uVar6 = 3;
        }
        *(undefined2 *)((uint3)uVar6 << 0xe | (uint3)(param_2 & 0x3fff)) =
             *(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(uVar5 & 0x3fff));
        uVar1 = 0x24;
        if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) = 0;
        return;
      }
    }
  }
  uVar1 = param_2 + 10;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) = param_3;
  uVar1 = param_2 + 0xc;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) = 1;
  uVar1 = 0x24;
  if ((((uVar5 & 0xc000) != 0) && (uVar1 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  uVar2 = 0x24;
  if ((((uVar6 & 0xc000) != 0) && (uVar2 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  *(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar6 & 0x3fff)) =
       *(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(uVar5 & 0x3fff));
  uVar1 = 0x24;
  if ((((param_2 & 0xc000) != 0) && (uVar1 = 0x21, (param_2 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (param_2 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  uVar5 = param_2 + 2;
  uVar2 = 0x24;
  if ((((uVar5 & 0xc000) != 0) && (uVar2 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  *(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar5 & 0x3fff)) =
       *(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(param_2 & 0x3fff));
  return;
}


