/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a0e7c; FLS offset 0x020e7c.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Function: egs52_read_far_u32_registers replaced with injection:
   egs52_read_far_u32_registers */
/* WARNING: Removing unreachable block (ram,0x0a0ef4) */
/* WARNING: Removing unreachable block (ram,0x0a1010) */
/* WARNING: Removing unreachable block (ram,0x0a0f22) */
/* WARNING: Removing unreachable block (ram,0x0a0ee0) */
/* WARNING: Removing unreachable block (ram,0x0a0ec6) */
/* WARNING: Removing unreachable block (ram,0x0a0f1c) */
/* WARNING: Removing unreachable block (ram,0x0a0f86) */
/* WARNING: Removing unreachable block (ram,0x0a0ff2) */
/* WARNING: Removing unreachable block (ram,0x0a0ea2) */
/* WARNING: Removing unreachable block (ram,0x0a0f7c) */
/* WARNING: Removing unreachable block (ram,0x0a0ef6) */
/* WARNING: Removing unreachable block (ram,0x0a1020) */
/* WARNING: Removing unreachable block (ram,0x0a0fe4) */
/* WARNING: Removing unreachable block (ram,0x0a0fa4) */
/* WARNING: Removing unreachable block (ram,0x0a0f76) */
/* WARNING: Removing unreachable block (ram,0x0a0f24) */
/* WARNING: Removing unreachable block (ram,0x0a0ee2) */
/* WARNING: Removing unreachable block (ram,0x0a0e9e) */
/* WARNING: Removing unreachable block (ram,0x0a1014) */
/* WARNING: Removing unreachable block (ram,0x0a1004) */
/* WARNING: Removing unreachable block (ram,0x0a0ff8) */
/* WARNING: Removing unreachable block (ram,0x0a0fe6) */
/* WARNING: Removing unreachable block (ram,0x0a0fd6) */
/* WARNING: Removing unreachable block (ram,0x0a0fca) */
/* WARNING: Removing unreachable block (ram,0x0a0fb8) */
/* WARNING: Removing unreachable block (ram,0x0a0fae) */
/* WARNING: Removing unreachable block (ram,0x0a0fa2) */
/* WARNING: Removing unreachable block (ram,0x0a0f90) */
/* WARNING: Removing unreachable block (ram,0x0a0f6a) */
/* WARNING: Removing unreachable block (ram,0x0a0f56) */
/* WARNING: Removing unreachable block (ram,0x0a0f4e) */
/* WARNING: Removing unreachable block (ram,0x0a0f40) */
/* WARNING: Removing unreachable block (ram,0x0a0f10) */
/* WARNING: Removing unreachable block (ram,0x0a0eee) */
/* WARNING: Removing unreachable block (ram,0x0a0ec4) */
/* WARNING: Removing unreachable block (ram,0x0a0eae) */
/* WARNING: Removing unreachable block (ram,0x0a0e8c) */
/* WARNING: Removing unreachable block (ram,0x0a0e80) */
/* WARNING: Removing unreachable block (ram,0x0a0eba) */
/* WARNING: Removing unreachable block (ram,0x0a0f0e) */
/* WARNING: Removing unreachable block (ram,0x0a0f42) */
/* WARNING: Removing unreachable block (ram,0x0a0f54) */
/* WARNING: Removing unreachable block (ram,0x0a0f68) */
/* WARNING: Removing unreachable block (ram,0x0a0f7e) */
/* WARNING: Removing unreachable block (ram,0x0a0f8e) */
/* WARNING: Removing unreachable block (ram,0x0a0f9c) */
/* WARNING: Removing unreachable block (ram,0x0a0fb6) */
/* WARNING: Removing unreachable block (ram,0x0a0fc4) */
/* WARNING: Removing unreachable block (ram,0x0a0fcc) */
/* WARNING: Removing unreachable block (ram,0x0a0ffa) */

char egs52_transform_far_memory_0a0e7c(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  byte bVar7;
  char cVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  
  cVar8 = '\0';
  bVar7 = UNK_00f842;
  uVar9 = (uint)bVar7 * 0x1c + 0x83c7;
  uVar1 = 0x24;
  if ((((uVar9 & 0xc000) != 0) && (uVar1 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  uVar9 = (uint)*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar9 & 0x3fff));
  while( true ) {
    bVar7 = UNK_00f842;
    uVar1 = (uint)bVar7 * 0x1c + 0x83c8;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    if (*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) < uVar9) break;
    uVar1 = 1 << (uVar9 & 0xf);
    uVar2 = Ram00c068;
    uVar10 = Ram00c06a;
    if ((uVar1 & uVar2) != 0 || ((int)uVar1 >> 0xf & uVar10) != 0) {
      cVar8 = cVar8 + '\x01';
      bVar7 = UNK_00f842;
      uVar1 = (uint)bVar7 * 0x1c + 0x83c2;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      iVar6 = uVar9 * 4;
      uVar2 = *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) + iVar6;
      uVar1 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      uVar10 = uVar2 + 2;
      uVar2 = *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
      uVar1 = 0x24;
      if ((((uVar10 & 0xc000) != 0) && (uVar1 = 0x21, (uVar10 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar10 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      uVar3 = param_1 + 1;
      uVar11 = 0x24;
      if ((((param_1 & 0xc000) != 0) && (uVar11 = 0x21, (param_1 & 0xc000) != 0x4000)) &&
         (uVar11 = 0x2c, (param_1 & 0xc000) != 0x8000)) {
        uVar11 = 3;
      }
      *(char *)((uint3)uVar11 << 0xe | (uint3)(param_1 & 0x3fff)) =
           (char)((uint)*(undefined2 *)
                         ((uint3)(*(int *)((uint3)uVar1 << 0xe | (uint3)(uVar10 & 0x3fff)) +
                                 (uint)(0xfffd < uVar2)) << 0x10 | (uint3)(uVar2 + 2)) >> 8);
      bVar7 = UNK_00f842;
      uVar1 = (uint)bVar7 * 0x1c + 0x83c2;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      uVar2 = *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) + iVar6;
      uVar1 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      uVar10 = uVar2 + 2;
      uVar2 = *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
      uVar1 = 0x24;
      if ((((uVar10 & 0xc000) != 0) && (uVar1 = 0x21, (uVar10 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar10 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      uVar4 = param_1 + 2;
      uVar11 = 0x24;
      if ((((uVar3 & 0xc000) != 0) && (uVar11 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
         (uVar11 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
        uVar11 = 3;
      }
      *(char *)((uint3)uVar11 << 0xe | (uint3)(uVar3 & 0x3fff)) =
           (char)*(undefined2 *)
                  ((uint3)(*(int *)((uint3)uVar1 << 0xe | (uint3)(uVar10 & 0x3fff)) +
                          (uint)(0xfffd < uVar2)) << 0x10 | (uint3)(uVar2 + 2));
      bVar7 = UNK_00f842;
      uVar1 = (uint)bVar7 * 0x1c + 0x83c2;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      uVar2 = *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) + iVar6;
      uVar1 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      uVar11 = uVar2 + 2;
      uVar10 = 0x24;
      if ((((uVar11 & 0xc000) != 0) && (uVar10 = 0x21, (uVar11 & 0xc000) != 0x4000)) &&
         (uVar10 = 0x2c, (uVar11 & 0xc000) != 0x8000)) {
        uVar10 = 3;
      }
      uVar5 = param_1 + 3;
      uVar3 = 0x24;
      if ((((uVar4 & 0xc000) != 0) && (uVar3 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      *(char *)((uint3)uVar3 << 0xe | (uint3)(uVar4 & 0x3fff)) =
           (char)((uint)*(undefined2 *)
                         ((uint3)*(uint *)((uint3)uVar10 << 0xe | (uint3)(uVar11 & 0x3fff)) << 0x10
                         | (uint3)*(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff))) >> 8);
      bVar7 = UNK_00f842;
      uVar1 = (uint)bVar7 * 0x1c + 0x83c2;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      uVar2 = *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) + iVar6;
      uVar1 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      uVar11 = uVar2 + 2;
      uVar10 = 0x24;
      if ((((uVar11 & 0xc000) != 0) && (uVar10 = 0x21, (uVar11 & 0xc000) != 0x4000)) &&
         (uVar10 = 0x2c, (uVar11 & 0xc000) != 0x8000)) {
        uVar10 = 3;
      }
      uVar4 = param_1 + 4;
      uVar3 = 0x24;
      if ((((uVar5 & 0xc000) != 0) && (uVar3 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      *(char *)((uint3)uVar3 << 0xe | (uint3)(uVar5 & 0x3fff)) =
           (char)*(undefined2 *)
                  ((uint3)*(uint *)((uint3)uVar10 << 0xe | (uint3)(uVar11 & 0x3fff)) << 0x10 |
                  (uint3)*(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)));
      bVar7 = UNK_00f842;
      uVar1 = (uint)bVar7 * 0x1c + 0x83c2;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      uVar2 = *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) + iVar6;
      uVar1 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      uVar10 = uVar2 + 2;
      uVar2 = *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
      uVar1 = 0x24;
      if ((((uVar10 & 0xc000) != 0) && (uVar1 = 0x21, (uVar10 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar10 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      uVar3 = param_1 + 5;
      uVar11 = 0x24;
      if ((((uVar4 & 0xc000) != 0) && (uVar11 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
         (uVar11 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
        uVar11 = 3;
      }
      *(char *)((uint3)uVar11 << 0xe | (uint3)(uVar4 & 0x3fff)) =
           (char)*(undefined2 *)
                  CONCAT12((char)*(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(uVar10 & 0x3fff)) +
                           (0xfff9 < uVar2),uVar2 + 6);
      bVar7 = UNK_00f842;
      uVar1 = (uint)bVar7 * 0x1c + 0x83c2;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      uVar2 = *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) + iVar6;
      uVar1 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      uVar10 = uVar2 + 2;
      uVar2 = *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
      uVar1 = 0x24;
      if ((((uVar10 & 0xc000) != 0) && (uVar1 = 0x21, (uVar10 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar10 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      uVar4 = param_1 + 6;
      uVar11 = 0x24;
      if ((((uVar3 & 0xc000) != 0) && (uVar11 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
         (uVar11 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
        uVar11 = 3;
      }
      *(char *)((uint3)uVar11 << 0xe | (uint3)(uVar3 & 0x3fff)) =
           (char)*(undefined2 *)
                  CONCAT12((char)*(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(uVar10 & 0x3fff)) +
                           (0xfff7 < uVar2),uVar2 + 8);
      bVar7 = UNK_00f842;
      uVar1 = (uint)bVar7 * 0x1c + 0x83c2;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      uVar2 = *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) + iVar6;
      uVar1 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      uVar10 = uVar2 + 2;
      uVar2 = *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
      uVar1 = 0x24;
      if ((((uVar10 & 0xc000) != 0) && (uVar1 = 0x21, (uVar10 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar10 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      uVar3 = param_1 + 7;
      uVar11 = 0x24;
      if ((((uVar4 & 0xc000) != 0) && (uVar11 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
         (uVar11 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
        uVar11 = 3;
      }
      *(char *)((uint3)uVar11 << 0xe | (uint3)(uVar4 & 0x3fff)) =
           (char)((uint)*(undefined2 *)
                         CONCAT12((char)*(undefined2 *)
                                         ((uint3)uVar1 << 0xe | (uint3)(uVar10 & 0x3fff)) +
                                  (0xfff5 < uVar2),uVar2 + 10) >> 8);
      bVar7 = UNK_00f842;
      uVar1 = (uint)bVar7 * 0x1c + 0x83c2;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      uVar2 = *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) + iVar6;
      uVar1 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      uVar10 = uVar2 + 2;
      uVar2 = *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
      uVar1 = 0x24;
      if ((((uVar10 & 0xc000) != 0) && (uVar1 = 0x21, (uVar10 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar10 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      param_1 = param_1 + 8;
      uVar11 = 0x24;
      if ((((uVar3 & 0xc000) != 0) && (uVar11 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
         (uVar11 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
        uVar11 = 3;
      }
      *(char *)((uint3)uVar11 << 0xe | (uint3)(uVar3 & 0x3fff)) =
           (char)*(undefined2 *)
                  CONCAT12((char)*(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(uVar10 & 0x3fff)) +
                           (0xfff5 < uVar2),uVar2 + 10);
    }
    uVar9 = uVar9 + 1;
  }
  return cVar8;
}


