/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x092780; FLS offset 0x012780.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0928ac) */
/* WARNING: Removing unreachable block (ram,0x092892) */
/* WARNING: Removing unreachable block (ram,0x092888) */
/* WARNING: Removing unreachable block (ram,0x092874) */
/* WARNING: Removing unreachable block (ram,0x092872) */
/* WARNING: Removing unreachable block (ram,0x0928cc) */
/* WARNING: Removing unreachable block (ram,0x092864) */
/* WARNING: Removing unreachable block (ram,0x0928d8) */
/* WARNING: Removing unreachable block (ram,0x092812) */
/* WARNING: Removing unreachable block (ram,0x09281e) */
/* WARNING: Removing unreachable block (ram,0x0927dc) */
/* WARNING: Removing unreachable block (ram,0x092818) */
/* WARNING: Removing unreachable block (ram,0x0927be) */
/* WARNING: Removing unreachable block (ram,0x09280c) */
/* WARNING: Removing unreachable block (ram,0x0927a8) */
/* WARNING: Removing unreachable block (ram,0x092842) */
/* WARNING: Removing unreachable block (ram,0x092796) */
/* WARNING: Removing unreachable block (ram,0x09284e) */
/* WARNING: Removing unreachable block (ram,0x092840) */
/* WARNING: Removing unreachable block (ram,0x092844) */
/* WARNING: Removing unreachable block (ram,0x0927aa) */
/* WARNING: Removing unreachable block (ram,0x092806) */
/* WARNING: Removing unreachable block (ram,0x0928ce) */
/* WARNING: Removing unreachable block (ram,0x0928b2) */
/* WARNING: Removing unreachable block (ram,0x0928b8) */
/* WARNING: Removing unreachable block (ram,0x092886) */
/* WARNING: Removing unreachable block (ram,0x092824) */
/* WARNING: Removing unreachable block (ram,0x0927bc) */
/* WARNING: Removing unreachable block (ram,0x0928be) */
/* WARNING: Removing unreachable block (ram,0x0927d0) */
/* WARNING: Removing unreachable block (ram,0x0927d2) */

void egs52_transform_memory_092780(void)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  
  uVar3 = 0x1b1a;
  while( true ) {
    while( true ) {
      while( true ) {
        while( true ) {
          uVar11 = 0x21;
          uVar2 = 0x24;
          if ((((uVar3 & 0xc000) != 0) && (uVar2 = uVar11, (uVar3 & 0xc000) != 0x4000)) &&
             (uVar2 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
            uVar2 = 3;
          }
          uVar4 = uVar3 + 2;
          iVar9 = *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar3 & 0x3fff));
          if (iVar9 != 1) break;
          uVar3 = uVar3 + 0xe;
        }
        if (iVar9 != 5) break;
        uVar2 = 0x24;
        if ((((uVar4 & 0xc000) != 0) && (uVar2 = uVar11, (uVar4 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        uVar7 = uVar3 + 4;
        uVar4 = *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar4 & 0x3fff));
        uVar2 = 0x24;
        if ((((uVar7 & 0xc000) != 0) && (uVar2 = uVar11, (uVar7 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        uVar8 = uVar3 + 6;
        uVar7 = *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar7 & 0x3fff));
        uVar2 = 0x24;
        if ((((uVar8 & 0xc000) != 0) && (uVar2 = uVar11, (uVar8 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar8 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        uVar3 = uVar3 + 8;
        iVar9 = *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar8 & 0x3fff));
        while (bVar1 = iVar9 != 0, iVar9 = iVar9 + -1, bVar1) {
          uVar2 = 0x24;
          if ((((uVar7 & 0xc000) != 0) && (uVar2 = uVar11, (uVar7 & 0xc000) != 0x4000)) &&
             (uVar2 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
            uVar2 = 3;
          }
          uVar5 = uVar7 & 0x3fff;
          uVar7 = uVar7 + 1;
          uVar8 = 0x24;
          if ((((uVar4 & 0xc000) != 0) && (uVar8 = uVar11, (uVar4 & 0xc000) != 0x4000)) &&
             (uVar8 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
            uVar8 = 3;
          }
          *(undefined1 *)((uint3)uVar8 << 0xe | (uint3)(uVar4 & 0x3fff)) =
               *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)uVar5);
          uVar4 = uVar4 + 1;
        }
      }
      if (iVar9 != 6) break;
      uVar2 = 0x24;
      if ((((uVar4 & 0xc000) != 0) && (uVar2 = uVar11, (uVar4 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      uVar7 = uVar3 + 4;
      uVar4 = *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar4 & 0x3fff)) & 0x3fff | 0x4000;
      uVar2 = 0x24;
      if ((((uVar7 & 0xc000) != 0) && (uVar2 = uVar11, (uVar7 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      uVar11 = *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar7 & 0x3fff));
      uVar7 = uVar3 + 6;
      uVar2 = 0x24;
      if ((((uVar7 & 0xc000) != 0) && (uVar2 = uVar11, (uVar7 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      uVar8 = uVar3 + 8;
      uVar7 = *(uint *)((uint3)(uVar2 & 0x3ff) << 0xe | (uint3)(uVar7 & 0x3fff)) & 0x3fff | 0x8000;
      uVar2 = 0x24;
      if ((((uVar8 & 0xc000) != 0) && (uVar2 = uVar11, (uVar8 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar8 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      uVar8 = *(uint *)((uint3)(uVar2 & 0x3ff) << 0xe | (uint3)(uVar8 & 0x3fff));
      uVar5 = uVar3 + 10;
      uVar2 = 0x24;
      if ((((uVar5 & 0xc000) != 0) && (uVar2 = uVar11, (uVar5 & 0xc000) != 0x4000)) &&
         (uVar2 = uVar8, (uVar5 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      uVar3 = uVar3 + 0xc;
      iVar9 = *(int *)((uint3)(uVar2 & 0x3ff) << 0xe | (uint3)(uVar5 & 0x3fff));
      while (bVar1 = iVar9 != 0, iVar9 = iVar9 + -1, bVar1) {
        uVar2 = 0x24;
        if ((((uVar7 & 0xc000) != 0) && (uVar2 = uVar11, (uVar7 & 0xc000) != 0x4000)) &&
           (uVar2 = uVar8, (uVar7 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        uVar6 = uVar7 & 0x3fff;
        uVar7 = uVar7 + 1;
        uVar5 = 0x24;
        if ((((uVar4 & 0xc000) != 0) && (uVar5 = uVar11, (uVar4 & 0xc000) != 0x4000)) &&
           (uVar5 = uVar8, (uVar4 & 0xc000) != 0x8000)) {
          uVar5 = 3;
        }
        *(undefined1 *)((uint3)(uVar5 & 0x3ff) << 0xe | (uint3)(uVar4 & 0x3fff)) =
             *(undefined1 *)((uint3)(uVar2 & 0x3ff) << 0xe | (uint3)uVar6);
        bVar1 = uVar4 == 0x7fff;
        uVar4 = uVar4 + 1;
        if (bVar1) {
          uVar4 = 0x4000;
          uVar11 = uVar11 + 1;
        }
      }
    }
    if (iVar9 != 7) break;
    uVar2 = 0x24;
    if ((((uVar4 & 0xc000) != 0) && (uVar2 = uVar11, (uVar4 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    uVar7 = uVar3 + 4;
    uVar4 = *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar4 & 0x3fff));
    uVar2 = 0x24;
    if ((((uVar7 & 0xc000) != 0) && (uVar2 = uVar11, (uVar7 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    uVar8 = uVar3 + 6;
    uVar11 = (*(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar7 & 0x3fff)) & 0xff) << 2 | uVar4 >> 0xe;
    uVar4 = uVar4 & 0x3fff | 0x4000;
    uVar2 = 0x24;
    if ((((uVar8 & 0xc000) != 0) && (uVar2 = uVar11, (uVar8 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar8 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    uVar5 = uVar3 + 8;
    uVar7 = *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar8 & 0x3fff));
    uVar2 = 0x24;
    if ((((uVar5 & 0xc000) != 0) && (uVar2 = uVar11, (uVar5 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    uVar6 = uVar3 + 10;
    uVar8 = (*(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar5 & 0x3fff)) & 0xff) << 2 | uVar7 >> 0xe;
    uVar7 = uVar7 & 0x3fff | 0x8000;
    uVar2 = 0x24;
    if ((((uVar6 & 0xc000) != 0) && (uVar2 = uVar11, (uVar6 & 0xc000) != 0x4000)) &&
       (uVar2 = uVar8, (uVar6 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    uVar5 = uVar3 + 0xc;
    iVar9 = *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar6 & 0x3fff));
    uVar2 = 0x24;
    if ((((uVar5 & 0xc000) != 0) && (uVar2 = uVar11, (uVar5 & 0xc000) != 0x4000)) &&
       (uVar2 = uVar8, (uVar5 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    uVar3 = uVar3 + 0xe;
    iVar10 = *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar5 & 0x3fff));
    while ((bVar1 = iVar9 != 0, iVar9 = iVar9 + -1, bVar1 ||
           (bVar1 = iVar10 != 0, iVar10 = iVar10 + -1, bVar1))) {
      uVar2 = 0x24;
      if (((uVar7 & 0xc000) != 0) &&
         ((uVar2 = uVar11, (uVar7 & 0xc000) != 0x4000 && (uVar2 = uVar8, (uVar7 & 0xc000) != 0x8000)
          ))) {
        uVar2 = 3;
      }
      uVar5 = 0x24;
      if ((((uVar4 & 0xc000) != 0) && (uVar5 = uVar11, (uVar4 & 0xc000) != 0x4000)) &&
         (uVar5 = uVar8, (uVar4 & 0xc000) != 0x8000)) {
        uVar5 = 3;
      }
      *(undefined1 *)((uint3)(uVar5 & 0x3ff) << 0xe | (uint3)(uVar4 & 0x3fff)) =
           *(undefined1 *)((uint3)(uVar2 & 0x3ff) << 0xe | (uint3)(uVar7 & 0x3fff));
      bVar1 = uVar4 == 0x7fff;
      uVar4 = uVar4 + 1;
      if (bVar1) {
        uVar4 = 0x4000;
        uVar11 = uVar11 + 1;
      }
      bVar1 = uVar7 == 0xbfff;
      uVar7 = uVar7 + 1;
      if (bVar1) {
        uVar7 = 0x8000;
        uVar8 = uVar8 + 1;
      }
    }
  }
  uVar3 = 0x1d9c;
  while( true ) {
    while( true ) {
      while( true ) {
        uVar11 = 0x21;
        uVar2 = 0x24;
        if ((((uVar3 & 0xc000) != 0) && (uVar2 = uVar11, (uVar3 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        uVar4 = uVar3 + 2;
        iVar9 = *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar3 & 0x3fff));
        if (iVar9 != 5) break;
        uVar2 = 0x24;
        if ((((uVar4 & 0xc000) != 0) && (uVar2 = uVar11, (uVar4 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        uVar7 = uVar3 + 4;
        uVar4 = *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar4 & 0x3fff));
        uVar2 = 0x24;
        if ((((uVar7 & 0xc000) != 0) && (uVar2 = uVar11, (uVar7 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        uVar3 = uVar3 + 6;
        iVar9 = *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar7 & 0x3fff));
        while (bVar1 = iVar9 != 0, iVar9 = iVar9 + -1, bVar1) {
          uVar2 = 0x24;
          if ((((uVar4 & 0xc000) != 0) && (uVar2 = uVar11, (uVar4 & 0xc000) != 0x4000)) &&
             (uVar2 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
            uVar2 = 3;
          }
          *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar4 & 0x3fff)) = 0;
          uVar4 = uVar4 + 1;
        }
      }
      if (iVar9 != 6) break;
      uVar2 = 0x24;
      if ((((uVar4 & 0xc000) != 0) && (uVar2 = uVar11, (uVar4 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      uVar7 = uVar3 + 4;
      uVar4 = *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar4 & 0x3fff)) & 0x3fff | 0x4000;
      uVar2 = 0x24;
      if ((((uVar7 & 0xc000) != 0) && (uVar2 = uVar11, (uVar7 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      uVar11 = *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar7 & 0x3fff));
      uVar7 = uVar3 + 6;
      uVar2 = 0x24;
      if ((((uVar7 & 0xc000) != 0) && (uVar2 = uVar11, (uVar7 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      uVar3 = uVar3 + 8;
      iVar9 = *(int *)((uint3)(uVar2 & 0x3ff) << 0xe | (uint3)(uVar7 & 0x3fff));
      while (bVar1 = iVar9 != 0, iVar9 = iVar9 + -1, bVar1) {
        uVar2 = 0x24;
        if ((((uVar4 & 0xc000) != 0) && (uVar2 = uVar11, (uVar4 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        *(undefined1 *)((uint3)(uVar2 & 0x3ff) << 0xe | (uint3)(uVar4 & 0x3fff)) = 0;
        uVar4 = uVar4 + 1;
      }
    }
    if (iVar9 != 7) break;
    uVar2 = 0x24;
    if ((((uVar4 & 0xc000) != 0) && (uVar2 = uVar11, (uVar4 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    uVar7 = uVar3 + 4;
    uVar4 = *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar4 & 0x3fff));
    uVar2 = 0x24;
    if ((((uVar7 & 0xc000) != 0) && (uVar2 = uVar11, (uVar7 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    uVar8 = uVar3 + 6;
    uVar11 = (*(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar7 & 0x3fff)) & 0xff) << 2 | uVar4 >> 0xe;
    uVar4 = uVar4 & 0x3fff | 0x4000;
    uVar2 = 0x24;
    if ((((uVar8 & 0xc000) != 0) && (uVar2 = uVar11, (uVar8 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar8 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    uVar7 = uVar3 + 8;
    iVar9 = *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar8 & 0x3fff));
    uVar2 = 0x24;
    if ((((uVar7 & 0xc000) != 0) && (uVar2 = uVar11, (uVar7 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    uVar3 = uVar3 + 10;
    iVar10 = *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar7 & 0x3fff));
    while ((bVar1 = iVar9 != 0, iVar9 = iVar9 + -1, bVar1 ||
           (bVar1 = iVar10 != 0, iVar10 = iVar10 + -1, bVar1))) {
      uVar2 = 0x24;
      if (((uVar4 & 0xc000) != 0) &&
         ((uVar2 = uVar11, (uVar4 & 0xc000) != 0x4000 && (uVar2 = 0x2c, (uVar4 & 0xc000) != 0x8000))
         )) {
        uVar2 = 3;
      }
      *(undefined1 *)((uint3)(uVar2 & 0x3ff) << 0xe | (uint3)(uVar4 & 0x3fff)) = 0;
      bVar1 = uVar4 == 0x7fff;
      uVar4 = uVar4 + 1;
      if (bVar1) {
        uVar4 = 0x4000;
        uVar11 = uVar11 + 1;
      }
    }
  }
  return;
}


