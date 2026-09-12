/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a01a8; FLS offset 0x0201a8.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a02ce) */
/* WARNING: Removing unreachable block (ram,0x0a0286) */
/* WARNING: Removing unreachable block (ram,0x0a02ae) */
/* WARNING: Removing unreachable block (ram,0x0a01fa) */
/* WARNING: Removing unreachable block (ram,0x0a01ee) */
/* WARNING: Removing unreachable block (ram,0x0a0298) */
/* WARNING: Removing unreachable block (ram,0x0a0206) */
/* WARNING: Removing unreachable block (ram,0x0a02ac) */
/* WARNING: Removing unreachable block (ram,0x0a01e4) */
/* WARNING: Removing unreachable block (ram,0x0a0284) */
/* WARNING: Removing unreachable block (ram,0x0a02c8) */
/* WARNING: Removing unreachable block (ram,0x0a0290) */
/* WARNING: Removing unreachable block (ram,0x0a0266) */
/* WARNING: Removing unreachable block (ram,0x0a01e0) */
/* WARNING: Removing unreachable block (ram,0x0a02da) */
/* WARNING: Removing unreachable block (ram,0x0a02ba) */
/* WARNING: Removing unreachable block (ram,0x0a02ee) */
/* WARNING: Removing unreachable block (ram,0x0a01c8) */
/* WARNING: Removing unreachable block (ram,0x0a01bc) */
/* WARNING: Removing unreachable block (ram,0x0a02e2) */
/* WARNING: Removing unreachable block (ram,0x0a027c) */
/* WARNING: Removing unreachable block (ram,0x0a02a4) */
/* WARNING: Removing unreachable block (ram,0x0a02cc) */
/* WARNING: Removing unreachable block (ram,0x0a027e) */
/* WARNING: Removing unreachable block (ram,0x0a02de) */
/* WARNING: Removing unreachable block (ram,0x0a0254) */
/* WARNING: Removing unreachable block (ram,0x0a02d8) */
/* WARNING: Removing unreachable block (ram,0x0a0270) */
/* WARNING: Removing unreachable block (ram,0x0a0230) */
/* WARNING: Removing unreachable block (ram,0x0a0224) */
/* WARNING: Removing unreachable block (ram,0x0a0242) */
/* WARNING: Removing unreachable block (ram,0x0a0272) */
/* WARNING: Removing unreachable block (ram,0x0a02bc) */
/* WARNING: Removing unreachable block (ram,0x0a0248) */

void egs52_transform_far_memory_0a01a8(void)

{
  bool bVar1;
  int iVar2;
  byte bVar3;
  ushort uVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  char cVar11;
  
  uVar4 = egs52_get_operating_mask();
  if ((uVar4 & 0x400) == 0) {
    bVar5 = UNK_00f842;
    uVar10 = (uint)bVar5 * 0x1c + 0x83c5;
    uVar6 = 0x24;
    if ((((uVar10 & 0xc000) != 0) && (uVar6 = 0x21, (uVar10 & 0xc000) != 0x4000)) &&
       (uVar6 = 0x2c, (uVar10 & 0xc000) != 0x8000)) {
      uVar6 = 3;
    }
    bVar5 = *(byte *)((uint3)uVar6 << 0xe | (uint3)(uVar10 & 0x3fff));
    while( true ) {
      bVar3 = UNK_00f842;
      uVar10 = (uint)bVar3 * 0x1c + 0x83c6;
      uVar6 = 0x24;
      if ((((uVar10 & 0xc000) != 0) && (uVar6 = 0x21, (uVar10 & 0xc000) != 0x4000)) &&
         (uVar6 = 0x2c, (uVar10 & 0xc000) != 0x8000)) {
        uVar6 = 3;
      }
      if (*(byte *)((uint3)uVar6 << 0xe | (uint3)(uVar10 & 0x3fff)) < bVar5) break;
      uVar6 = (uint)bVar5;
      uVar7 = 1;
      uVar10 = 0;
      while (bVar1 = uVar6 != 0, uVar6 = uVar6 - 1, bVar1) {
        bVar1 = CARRY2(uVar7,uVar7);
        uVar7 = uVar7 * 2;
        uVar10 = uVar10 * 2 + (uint)bVar1;
      }
      uVar6 = Ram00c068;
      uVar8 = Ram00c06a;
      if ((uVar7 & uVar6) != 0 || (uVar10 & uVar8) != 0) {
        bVar3 = UNK_00f842;
        uVar10 = (uint)bVar3 * 0x1c + 0x83c5;
        uVar6 = 0x24;
        if ((((uVar10 & 0xc000) != 0) && (uVar6 = 0x21, (uVar10 & 0xc000) != 0x4000)) &&
           (uVar6 = 0x2c, (uVar10 & 0xc000) != 0x8000)) {
          uVar6 = 3;
        }
        uVar10 = ((uint)bVar5 - (uint)*(byte *)((uint3)uVar6 << 0xe | (uint3)(uVar10 & 0x3fff))) * 2
                 + 0xc35c;
        uVar6 = 0x24;
        if ((((uVar10 & 0xc000) != 0) && (uVar6 = 0x21, (uVar10 & 0xc000) != 0x4000)) &&
           (uVar6 = 0x2c, (uVar10 & 0xc000) != 0x8000)) {
          uVar6 = 3;
        }
        if (*(uint *)((uint3)uVar6 << 0xe | (uint3)(uVar10 & 0x3fff)) < 0x15) {
          uVar4 = egs52_read_indexed_record_word(bVar5);
          if ((uVar4 & 0x300) != 0x200) {
            bVar3 = UNK_00f842;
            uVar6 = (uint)bVar3 * 0x1c + 0x83c2;
            uVar10 = 0x24;
            if ((((uVar6 & 0xc000) != 0) && (uVar10 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
               (uVar10 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
              uVar10 = 3;
            }
            iVar2 = (uint)bVar5 * 4;
            uVar7 = *(int *)((uint3)uVar10 << 0xe | (uint3)(uVar6 & 0x3fff)) + iVar2;
            uVar10 = 0x24;
            if ((((uVar7 & 0xc000) != 0) && (uVar10 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
               (uVar10 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
              uVar10 = 3;
            }
            uVar8 = uVar7 + 2;
            uVar7 = *(uint *)((uint3)uVar10 << 0xe | (uint3)(uVar7 & 0x3fff));
            uVar10 = 0x24;
            if ((((uVar8 & 0xc000) != 0) && (uVar10 = 0x21, (uVar8 & 0xc000) != 0x4000)) &&
               (uVar10 = 0x2c, (uVar8 & 0xc000) != 0x8000)) {
              uVar10 = 3;
            }
            cVar11 = (char)*(undefined2 *)((uint3)uVar10 << 0xe | (uint3)(uVar8 & 0x3fff)) +
                     (0xfff1 < uVar7);
            uVar8 = *(int *)CONCAT12(cVar11,uVar6) + iVar2;
            uVar10 = 0x24;
            if ((((uVar8 & 0xc000) != 0) && (uVar10 = 0x21, (uVar8 & 0xc000) != 0x4000)) &&
               (uVar10 = 0x2c, (uVar8 & 0xc000) != 0x8000)) {
              uVar10 = 3;
            }
            uVar9 = uVar8 + 2;
            uVar8 = *(uint *)((uint3)uVar10 << 0xe | (uint3)(uVar8 & 0x3fff));
            uVar10 = 0x24;
            if ((((uVar9 & 0xc000) != 0) && (uVar10 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
               (uVar10 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
              uVar10 = 3;
            }
            egs52_transform_far_memory_0a6006
                      (bVar5,*(undefined2 *)CONCAT12(cVar11,uVar7 + 0xe),
                       *(undefined1 *)
                        CONCAT12((char)*(undefined2 *)
                                        ((uint3)uVar10 << 0xe | (uint3)(uVar9 & 0x3fff)) +
                                 (0xfff3 < uVar8),uVar8 + 0xc),uVar6);
            bVar3 = UNK_00f842;
            uVar10 = (uint)bVar3 * 0x1c + 0x83c2;
            uVar6 = 0x24;
            if ((((uVar10 & 0xc000) != 0) && (uVar6 = 0x21, (uVar10 & 0xc000) != 0x4000)) &&
               (uVar6 = 0x2c, (uVar10 & 0xc000) != 0x8000)) {
              uVar6 = 3;
            }
            uVar6 = *(int *)((uint3)uVar6 << 0xe | (uint3)(uVar10 & 0x3fff)) + iVar2;
            uVar10 = 0x24;
            if ((((uVar6 & 0xc000) != 0) && (uVar10 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
               (uVar10 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
              uVar10 = 3;
            }
            uVar8 = *(uint *)((uint3)uVar10 << 0xe | (uint3)(uVar6 & 0x3fff));
            uVar10 = uVar6 + 2;
            uVar7 = 0x24;
            if ((((uVar10 & 0xc000) != 0) && (uVar7 = 0x21, (uVar10 & 0xc000) != 0x4000)) &&
               (uVar7 = 0x2c, (uVar10 & 0xc000) != 0x8000)) {
              uVar7 = 3;
            }
            cVar11 = (char)*(undefined2 *)((uint3)uVar7 << 0xe | (uint3)(uVar10 & 0x3fff)) +
                     (0xfff5 < uVar8);
            uVar10 = ((uint)bVar5 - (uint)*(byte *)CONCAT12(cVar11,(uint)bVar3 * 0x1c + -0x7c3b)) *
                     2 + 0xc35c;
            uVar7 = 0x24;
            if ((((uVar10 & 0xc000) != 0) && (uVar7 = 0x21, (uVar10 & 0xc000) != 0x4000)) &&
               (uVar7 = 0x2c, (uVar10 & 0xc000) != 0x8000)) {
              uVar7 = 3;
            }
            *(undefined2 *)((uint3)uVar7 << 0xe | (uint3)(uVar10 & 0x3fff)) =
                 *(undefined2 *)CONCAT12(cVar11,uVar8 + 10);
            uVar10 = 0x24;
            if ((((uVar6 & 0xc000) != 0) && (uVar10 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
               (uVar10 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
              uVar10 = 3;
            }
            uVar7 = uVar6 + 2;
            uVar6 = *(uint *)((uint3)uVar10 << 0xe | (uint3)(uVar6 & 0x3fff));
            uVar10 = 0x24;
            if ((((uVar7 & 0xc000) != 0) && (uVar10 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
               (uVar10 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
              uVar10 = 3;
            }
            cVar11 = (char)*(undefined2 *)((uint3)uVar10 << 0xe | (uint3)(uVar7 & 0x3fff)) +
                     (0xffef < uVar6);
            uVar6 = *(uint *)CONCAT12(cVar11,uVar6 + 0x10);
            uVar10 = 0x24;
            if ((((uVar6 & 0xc000) != 0) && (uVar10 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
               (uVar10 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
              uVar10 = 3;
            }
            *(byte *)((uint3)uVar10 << 0xe | (uint3)(uVar6 & 0x3fff)) =
                 *(byte *)CONCAT12(cVar11,uVar6) | 1;
          }
        }
        else {
          bVar3 = UNK_00f842;
          uVar10 = (uint)bVar3 * 0x1c + 0x83c5;
          uVar6 = 0x24;
          if ((((uVar10 & 0xc000) != 0) && (uVar6 = 0x21, (uVar10 & 0xc000) != 0x4000)) &&
             (uVar6 = 0x2c, (uVar10 & 0xc000) != 0x8000)) {
            uVar6 = 3;
          }
          uVar6 = ((uint)bVar5 - (uint)*(byte *)((uint3)uVar6 << 0xe | (uint3)(uVar10 & 0x3fff))) *
                  2 + 0xc35c;
          uVar10 = 0x24;
          if ((((uVar6 & 0xc000) != 0) && (uVar10 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
             (uVar10 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
            uVar10 = 3;
          }
          uVar7 = 0x24;
          if ((((uVar6 & 0xc000) != 0) && (uVar7 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
             (uVar7 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
            uVar7 = 3;
          }
          *(int *)((uint3)uVar7 << 0xe | (uint3)(uVar6 & 0x3fff)) =
               *(int *)((uint3)uVar10 << 0xe | (uint3)(uVar6 & 0x3fff)) + -0x14;
        }
      }
      bVar5 = bVar5 + 1;
    }
  }
  return;
}


