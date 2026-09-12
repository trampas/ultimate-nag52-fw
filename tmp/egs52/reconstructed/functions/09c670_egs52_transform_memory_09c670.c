/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x09c670; FLS offset 0x01c670.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x09c6c2) */
/* WARNING: Removing unreachable block (ram,0x09c6be) */
/* WARNING: Removing unreachable block (ram,0x09c6ba) */
/* WARNING: Removing unreachable block (ram,0x09c6b2) */
/* WARNING: Removing unreachable block (ram,0x09c6ae) */
/* WARNING: Removing unreachable block (ram,0x09c6a0) */
/* WARNING: Removing unreachable block (ram,0x09c69e) */
/* WARNING: Removing unreachable block (ram,0x09c69c) */
/* WARNING: Removing unreachable block (ram,0x09c698) */
/* WARNING: Removing unreachable block (ram,0x09c68a) */
/* WARNING: Removing unreachable block (ram,0x09c706) */
/* WARNING: Removing unreachable block (ram,0x09c704) */
/* WARNING: Removing unreachable block (ram,0x09c700) */
/* WARNING: Removing unreachable block (ram,0x09c6fc) */
/* WARNING: Removing unreachable block (ram,0x09c6ee) */
/* WARNING: Removing unreachable block (ram,0x09c6ec) */
/* WARNING: Removing unreachable block (ram,0x09c6e4) */
/* WARNING: Removing unreachable block (ram,0x09c6e0) */
/* WARNING: Removing unreachable block (ram,0x09c6de) */
/* WARNING: Removing unreachable block (ram,0x09c6da) */
/* WARNING: Removing unreachable block (ram,0x09c6d0) */
/* WARNING: Removing unreachable block (ram,0x09c680) */
/* WARNING: Removing unreachable block (ram,0x09c6cc) */
/* WARNING: Removing unreachable block (ram,0x09c68e) */

uint egs52_transform_memory_09c670(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  
  iVar7 = (param_2 & 0xff) * 2;
  uVar5 = iVar7 + 0xc2fe;
  uVar1 = 0x24;
  if ((((uVar5 & 0xc000) != 0) && (uVar1 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  if (*(int *)((uint3)uVar1 << 0xe | (uint3)(uVar5 & 0x3fff)) == 0) {
    uVar6 = iVar7 + 0xc2d4;
    uVar1 = 0x24;
    if ((((uVar6 & 0xc000) != 0) && (uVar1 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    uVar3 = 0x24;
    if ((((uVar6 & 0xc000) != 0) && (uVar3 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    *(int *)((uint3)uVar3 << 0xe | (uint3)(uVar6 & 0x3fff)) =
         *(int *)((uint3)uVar1 << 0xe | (uint3)(uVar6 & 0x3fff)) + param_1;
    uVar3 = (param_2 & 0xff) + 0xc2f0;
    uVar1 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    uVar8 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar8 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar8 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar8 = 3;
    }
    *(char *)((uint3)uVar8 << 0xe | (uint3)(uVar3 & 0x3fff)) =
         *(char *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) + '\x01';
    uVar1 = 0x24;
    if ((((uVar6 & 0xc000) != 0) && (uVar1 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    uVar8 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar8 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar8 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar8 = 3;
    }
    uVar8 = *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar6 & 0x3fff)) /
            (uint)*(byte *)((uint3)uVar8 << 0xe | (uint3)(uVar3 & 0x3fff));
    uVar1 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    uVar4 = (param_2 & 0xff) + 0x84c6;
    uVar2 = 0x24;
    if ((((uVar4 & 0xc000) != 0) && (uVar2 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    if (*(char *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) ==
        *(char *)((uint3)uVar2 << 0xe | (uint3)(uVar4 & 0x3fff))) {
      uVar1 = 0x24;
      if ((((uVar5 & 0xc000) != 0) && (uVar1 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar5 & 0x3fff)) = uVar8;
      uVar1 = 0x24;
      if ((((uVar6 & 0xc000) != 0) && (uVar1 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(uVar6 & 0x3fff)) = 0;
      uVar1 = 0x24;
      if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) = 0;
    }
  }
  else {
    uVar6 = iVar7 + 0xc2d4;
    uVar1 = 0x24;
    if ((((uVar6 & 0xc000) != 0) && (uVar1 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    uVar3 = 0x24;
    if ((((uVar6 & 0xc000) != 0) && (uVar3 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    *(int *)((uint3)uVar3 << 0xe | (uint3)(uVar6 & 0x3fff)) =
         *(int *)((uint3)uVar1 << 0xe | (uint3)(uVar6 & 0x3fff)) + param_1;
    uVar3 = (param_2 & 0xff) + 0xc2f0;
    uVar1 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    uVar8 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar8 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar8 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar8 = 3;
    }
    *(char *)((uint3)uVar8 << 0xe | (uint3)(uVar3 & 0x3fff)) =
         *(char *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) + '\x01';
    uVar1 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    uVar8 = (param_2 & 0xff) + 0x84c6;
    uVar4 = 0x24;
    if ((((uVar8 & 0xc000) != 0) && (uVar4 = 0x21, (uVar8 & 0xc000) != 0x4000)) &&
       (uVar4 = 0x2c, (uVar8 & 0xc000) != 0x8000)) {
      uVar4 = 3;
    }
    if (*(char *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) ==
        *(char *)((uint3)uVar4 << 0xe | (uint3)(uVar8 & 0x3fff))) {
      uVar1 = 0x24;
      if ((((uVar6 & 0xc000) != 0) && (uVar1 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      uVar8 = 0x24;
      if ((((uVar3 & 0xc000) != 0) && (uVar8 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
         (uVar8 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
        uVar8 = 3;
      }
      uVar4 = 0x24;
      if ((((uVar5 & 0xc000) != 0) && (uVar4 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
         (uVar4 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
        uVar4 = 3;
      }
      *(uint *)((uint3)uVar4 << 0xe | (uint3)(uVar5 & 0x3fff)) =
           *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar6 & 0x3fff)) /
           (uint)*(byte *)((uint3)uVar8 << 0xe | (uint3)(uVar3 & 0x3fff));
      uVar1 = 0x24;
      if ((((uVar6 & 0xc000) != 0) && (uVar1 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(uVar6 & 0x3fff)) = 0;
      uVar1 = 0x24;
      if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) = 0;
    }
    uVar1 = 0x24;
    if ((((uVar5 & 0xc000) != 0) && (uVar1 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    uVar8 = *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar5 & 0x3fff));
  }
  return uVar8;
}


