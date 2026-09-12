/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a081a; FLS offset 0x02081a.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a08e0) */
/* WARNING: Removing unreachable block (ram,0x0a08dc) */
/* WARNING: Removing unreachable block (ram,0x0a08da) */
/* WARNING: Removing unreachable block (ram,0x0a08d0) */
/* WARNING: Removing unreachable block (ram,0x0a08ce) */
/* WARNING: Removing unreachable block (ram,0x0a08c8) */
/* WARNING: Removing unreachable block (ram,0x0a08bc) */
/* WARNING: Removing unreachable block (ram,0x0a086a) */
/* WARNING: Removing unreachable block (ram,0x0a0860) */
/* WARNING: Removing unreachable block (ram,0x0a085e) */
/* WARNING: Removing unreachable block (ram,0x0a08ae) */
/* WARNING: Removing unreachable block (ram,0x0a08a4) */
/* WARNING: Removing unreachable block (ram,0x0a08a2) */
/* WARNING: Removing unreachable block (ram,0x0a089c) */
/* WARNING: Removing unreachable block (ram,0x0a0892) */
/* WARNING: Removing unreachable block (ram,0x0a0890) */
/* WARNING: Removing unreachable block (ram,0x0a088c) */
/* WARNING: Removing unreachable block (ram,0x0a0856) */
/* WARNING: Removing unreachable block (ram,0x0a084a) */
/* WARNING: Removing unreachable block (ram,0x0a0848) */
/* WARNING: Removing unreachable block (ram,0x0a083e) */
/* WARNING: Removing unreachable block (ram,0x0a0830) */
/* WARNING: Removing unreachable block (ram,0x0a087c) */
/* WARNING: Removing unreachable block (ram,0x0a089e) */

void egs52_transform_far_memory_0a081a(byte param_1,byte param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  byte bVar4;
  ushort uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  char cVar10;
  
  uVar5 = egs52_get_operating_mask();
  if ((uVar5 & 0x400) == 0) {
    bVar4 = UNK_00f842;
    uVar1 = (uint)bVar4 * 0x1c + 0x83c2;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    iVar3 = (uint)param_1 * 4;
    uVar2 = *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) + iVar3;
    uVar1 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    uVar7 = *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
    uVar1 = uVar2 + 2;
    uVar9 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar9 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar9 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar9 = 3;
    }
    if (param_2 < *(byte *)CONCAT12((char)*(undefined2 *)
                                           ((uint3)uVar9 << 0xe | (uint3)(uVar1 & 0x3fff)) +
                                    (0xfff3 < uVar7),uVar7 + 0xc)) {
      uVar1 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      uVar9 = uVar2 + 2;
      uVar2 = *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
      uVar1 = 0x24;
      if ((((uVar9 & 0xc000) != 0) && (uVar1 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      iVar6 = egs52_transform_far_memory_0a612e
                        (param_1,*(undefined2 *)
                                  CONCAT12((char)*(undefined2 *)
                                                  ((uint3)uVar1 << 0xe | (uint3)(uVar9 & 0x3fff)) +
                                           (0xfff1 < uVar2),uVar2 + 0xe),param_2);
    }
    else {
      bVar4 = UNK_00f842;
      uVar2 = (uint)bVar4 * 0x1c + 0x83c2;
      uVar1 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      uVar9 = *(int *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) + iVar3;
      uVar1 = 0x24;
      if ((((uVar9 & 0xc000) != 0) && (uVar1 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      uVar7 = uVar9 + 2;
      uVar9 = *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar9 & 0x3fff));
      uVar1 = 0x24;
      if ((((uVar7 & 0xc000) != 0) && (uVar1 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      cVar10 = (char)*(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(uVar7 & 0x3fff)) +
               (0xfff1 < uVar9);
      uVar7 = *(int *)CONCAT12(cVar10,uVar2) + iVar3;
      uVar1 = 0x24;
      if ((((uVar7 & 0xc000) != 0) && (uVar1 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      uVar8 = uVar7 + 2;
      uVar7 = *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar7 & 0x3fff));
      uVar1 = 0x24;
      if ((((uVar8 & 0xc000) != 0) && (uVar1 = 0x21, (uVar8 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar8 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      iVar6 = egs52_transform_far_memory_0a612e
                        (param_1,*(undefined2 *)CONCAT12(cVar10,uVar9 + 0xe),
                         *(undefined1 *)
                          CONCAT12((char)*(undefined2 *)
                                          ((uint3)uVar1 << 0xe | (uint3)(uVar8 & 0x3fff)) +
                                   (0xfff3 < uVar7),uVar7 + 0xc),uVar2);
    }
    if (iVar6 != 0) {
      bVar4 = UNK_00f842;
      uVar1 = (uint)bVar4 * 0x1c + 0x83c2;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      uVar2 = *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) + iVar3;
      uVar1 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      uVar9 = uVar2 + 2;
      uVar2 = *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
      uVar1 = 0x24;
      if ((((uVar9 & 0xc000) != 0) && (uVar1 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      cVar10 = (char)*(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(uVar9 & 0x3fff)) +
               (0xffef < uVar2);
      uVar2 = *(uint *)CONCAT12(cVar10,uVar2 + 0x10);
      uVar1 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) = *(byte *)CONCAT12(cVar10,uVar2) | 3
      ;
    }
  }
  return;
}


