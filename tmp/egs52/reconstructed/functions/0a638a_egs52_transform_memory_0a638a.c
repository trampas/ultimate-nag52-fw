/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a638a; FLS offset 0x02638a.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a6432) */
/* WARNING: Removing unreachable block (ram,0x0a6428) */
/* WARNING: Removing unreachable block (ram,0x0a6426) */
/* WARNING: Removing unreachable block (ram,0x0a6424) */
/* WARNING: Removing unreachable block (ram,0x0a641c) */
/* WARNING: Removing unreachable block (ram,0x0a6414) */
/* WARNING: Removing unreachable block (ram,0x0a63fc) */
/* WARNING: Removing unreachable block (ram,0x0a6408) */
/* WARNING: Removing unreachable block (ram,0x0a63f2) */
/* WARNING: Removing unreachable block (ram,0x0a640c) */
/* WARNING: Removing unreachable block (ram,0x0a6406) */
/* WARNING: Removing unreachable block (ram,0x0a63fa) */
/* WARNING: Removing unreachable block (ram,0x0a63f4) */
/* WARNING: Removing unreachable block (ram,0x0a63ea) */
/* WARNING: Removing unreachable block (ram,0x0a63dc) */
/* WARNING: Removing unreachable block (ram,0x0a63da) */
/* WARNING: Removing unreachable block (ram,0x0a63bc) */
/* WARNING: Removing unreachable block (ram,0x0a63c8) */
/* WARNING: Removing unreachable block (ram,0x0a63d8) */
/* WARNING: Removing unreachable block (ram,0x0a63e2) */
/* WARNING: Removing unreachable block (ram,0x0a63f8) */

void egs52_transform_memory_0a638a(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined1 *puVar4;
  uint uVar5;
  undefined1 *puVar6;
  undefined2 uVar7;
  undefined1 uVar8;
  int iVar9;
  uint uVar10;
  undefined1 auStack_11 [9];
  
  puVar6 = auStack_11 + 1;
  egs52_copy_bytes_registers();
  iVar9 = param_1 + 0xc;
  uVar10 = 0;
  while( true ) {
    uVar1 = 0x24;
    if ((((param_1 & 0xc000) != 0) && (uVar1 = 0x21, (param_1 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (param_1 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    if (*(byte *)((uint3)uVar1 << 0xe | (uint3)(param_1 & 0x3fff)) <= uVar10) break;
    uVar8 = egs52_call_096f56_0a644c(iVar9,param_1);
    puVar4 = puVar6 + uVar10;
    uVar1 = 0x24;
    if (((((uint)puVar4 & 0xc000) != 0) && (uVar1 = 0x21, ((uint)puVar4 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, ((uint)puVar4 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)((uint)puVar4 & 0x3fff)) = uVar8;
    iVar9 = iVar9 + 1;
    uVar10 = uVar10 + 1;
  }
  uVar5 = param_2 + 4;
  uVar1 = 0x24;
  if ((((uVar5 & 0xc000) != 0) && (uVar1 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  *(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(uVar5 & 0x3fff)) = 0;
  uVar1 = 0x24;
  if ((((param_2 & 0xc000) != 0) && (uVar1 = 0x21, (param_2 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (param_2 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  *(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(param_2 & 0x3fff)) = 0;
  uVar7 = Ram00fdf2;
  while (uVar10 = uVar10 - 1, uVar10 != 0) {
    uVar1 = 0x24;
    if ((((uVar5 & 0xc000) != 0) && (uVar1 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    puVar4 = puVar6 + uVar10;
    uVar2 = 0x24;
    if (((((uint)puVar4 & 0xc000) != 0) && (uVar2 = 0x21, ((uint)puVar4 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, ((uint)puVar4 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    uVar3 = 0x24;
    if ((((uVar5 & 0xc000) != 0) && (uVar3 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    *(uint *)((uint3)uVar3 << 0xe | (uint3)(uVar5 & 0x3fff)) =
         *(int *)((uint3)uVar1 << 0xe | (uint3)(uVar5 & 0x3fff)) +
         (*(byte *)((uint3)uVar2 << 0xe | (uint3)((uint)puVar4 & 0x3fff)) & 1);
    uVar1 = 0x24;
    if ((((uVar5 & 0xc000) != 0) && (uVar1 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    uVar2 = 0x24;
    if ((((uVar5 & 0xc000) != 0) && (uVar2 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar5 & 0x3fff)) =
         *(int *)((uint3)uVar1 << 0xe | (uint3)(uVar5 & 0x3fff)) << 1;
    uVar1 = 0x24;
    if ((((param_2 & 0xc000) != 0) && (uVar1 = 0x21, (param_2 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (param_2 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    uVar2 = 0x24;
    if (((((uint)puVar4 & 0xc000) != 0) && (uVar2 = 0x21, ((uint)puVar4 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, ((uint)puVar4 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    uVar3 = 0x24;
    if ((((param_2 & 0xc000) != 0) && (uVar3 = 0x21, (param_2 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (param_2 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    *(int *)((uint3)uVar3 << 0xe | (uint3)(param_2 & 0x3fff)) =
         *(int *)((uint3)uVar1 << 0xe | (uint3)(param_2 & 0x3fff)) +
         ((int)(*(byte *)((uint3)uVar2 << 0xe | (uint3)((uint)puVar4 & 0x3fff)) & 6) >> 1);
    uVar1 = 0x24;
    if ((((param_2 & 0xc000) != 0) && (uVar1 = 0x21, (param_2 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (param_2 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    uVar2 = 0x24;
    if ((((param_2 & 0xc000) != 0) && (uVar2 = 0x21, (param_2 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (param_2 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    *(int *)((uint3)uVar2 << 0xe | (uint3)(param_2 & 0x3fff)) =
         *(int *)((uint3)uVar1 << 0xe | (uint3)(param_2 & 0x3fff)) << 2;
  }
  uVar10 = 0x24;
  if ((((uVar5 & 0xc000) != 0) && (uVar10 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
     (uVar10 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
    uVar10 = 3;
  }
  uVar1 = 0x24;
  if (((((uint)puVar6 & 0xc000) != 0) && (uVar1 = 0x21, ((uint)puVar6 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, ((uint)puVar6 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  uVar2 = 0x24;
  if ((((uVar5 & 0xc000) != 0) && (uVar2 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar5 & 0x3fff)) =
       *(int *)((uint3)uVar10 << 0xe | (uint3)(uVar5 & 0x3fff)) +
       (*(byte *)((uint3)uVar1 << 0xe | (uint3)((uint)puVar6 & 0x3fff)) & 1);
  uVar10 = 0x24;
  if ((((param_2 & 0xc000) != 0) && (uVar10 = 0x21, (param_2 & 0xc000) != 0x4000)) &&
     (uVar10 = 0x2c, (param_2 & 0xc000) != 0x8000)) {
    uVar10 = 3;
  }
  uVar1 = 0x24;
  if (((((uint)puVar6 & 0xc000) != 0) && (uVar1 = 0x21, ((uint)puVar6 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, ((uint)puVar6 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  uVar5 = 0x24;
  if ((((param_2 & 0xc000) != 0) && (uVar5 = 0x21, (param_2 & 0xc000) != 0x4000)) &&
     (uVar5 = 0x2c, (param_2 & 0xc000) != 0x8000)) {
    uVar5 = 3;
  }
  *(int *)((uint3)uVar5 << 0xe | (uint3)(param_2 & 0x3fff)) =
       *(int *)((uint3)uVar10 << 0xe | (uint3)(param_2 & 0x3fff)) +
       ((int)(*(byte *)((uint3)uVar1 << 0xe | (uint3)((uint)puVar6 & 0x3fff)) & 6) >> 1);
  egs52_transform_memory_0a6498(uVar7);
  return;
}


