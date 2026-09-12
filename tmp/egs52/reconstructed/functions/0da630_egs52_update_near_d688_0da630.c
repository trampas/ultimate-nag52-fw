/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0da630; FLS offset 0x05a630.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0da8d6) */
/* WARNING: Removing unreachable block (ram,0x0da8ce) */
/* WARNING: Removing unreachable block (ram,0x0da8c6) */
/* WARNING: Removing unreachable block (ram,0x0da8b6) */
/* WARNING: Removing unreachable block (ram,0x0da8b2) */
/* WARNING: Removing unreachable block (ram,0x0da8ae) */
/* WARNING: Removing unreachable block (ram,0x0da8a4) */
/* WARNING: Removing unreachable block (ram,0x0da8a0) */
/* WARNING: Removing unreachable block (ram,0x0da832) */
/* WARNING: Removing unreachable block (ram,0x0da82a) */
/* WARNING: Removing unreachable block (ram,0x0da81a) */
/* WARNING: Removing unreachable block (ram,0x0da816) */
/* WARNING: Removing unreachable block (ram,0x0da810) */
/* WARNING: Removing unreachable block (ram,0x0da806) */
/* WARNING: Removing unreachable block (ram,0x0da802) */
/* WARNING: Removing unreachable block (ram,0x0da7fe) */
/* WARNING: Removing unreachable block (ram,0x0da7f8) */
/* WARNING: Removing unreachable block (ram,0x0da7f4) */
/* WARNING: Removing unreachable block (ram,0x0da7ec) */
/* WARNING: Removing unreachable block (ram,0x0da7e0) */
/* WARNING: Removing unreachable block (ram,0x0da890) */
/* WARNING: Removing unreachable block (ram,0x0da888) */
/* WARNING: Removing unreachable block (ram,0x0da878) */
/* WARNING: Removing unreachable block (ram,0x0da874) */
/* WARNING: Removing unreachable block (ram,0x0da86e) */
/* WARNING: Removing unreachable block (ram,0x0da864) */
/* WARNING: Removing unreachable block (ram,0x0da860) */
/* WARNING: Removing unreachable block (ram,0x0da85c) */
/* WARNING: Removing unreachable block (ram,0x0da850) */
/* WARNING: Removing unreachable block (ram,0x0da848) */
/* WARNING: Removing unreachable block (ram,0x0da7d8) */
/* WARNING: Removing unreachable block (ram,0x0da7d4) */
/* WARNING: Removing unreachable block (ram,0x0da762) */
/* WARNING: Removing unreachable block (ram,0x0da758) */
/* WARNING: Removing unreachable block (ram,0x0da748) */
/* WARNING: Removing unreachable block (ram,0x0da744) */
/* WARNING: Removing unreachable block (ram,0x0da73e) */
/* WARNING: Removing unreachable block (ram,0x0da734) */
/* WARNING: Removing unreachable block (ram,0x0da730) */
/* WARNING: Removing unreachable block (ram,0x0da72c) */
/* WARNING: Removing unreachable block (ram,0x0da724) */
/* WARNING: Removing unreachable block (ram,0x0da720) */
/* WARNING: Removing unreachable block (ram,0x0da718) */
/* WARNING: Removing unreachable block (ram,0x0da70c) */
/* WARNING: Removing unreachable block (ram,0x0da7c4) */
/* WARNING: Removing unreachable block (ram,0x0da7ba) */
/* WARNING: Removing unreachable block (ram,0x0da7aa) */
/* WARNING: Removing unreachable block (ram,0x0da7a6) */
/* WARNING: Removing unreachable block (ram,0x0da7a0) */
/* WARNING: Removing unreachable block (ram,0x0da796) */
/* WARNING: Removing unreachable block (ram,0x0da792) */
/* WARNING: Removing unreachable block (ram,0x0da78e) */
/* WARNING: Removing unreachable block (ram,0x0da782) */
/* WARNING: Removing unreachable block (ram,0x0da77a) */
/* WARNING: Removing unreachable block (ram,0x0da704) */
/* WARNING: Removing unreachable block (ram,0x0da700) */
/* WARNING: Removing unreachable block (ram,0x0da6da) */
/* WARNING: Removing unreachable block (ram,0x0da6ea) */
/* WARNING: Removing unreachable block (ram,0x0da6f6) */
/* WARNING: Removing unreachable block (ram,0x0da6ee) */
/* WARNING: Removing unreachable block (ram,0x0da6e4) */
/* WARNING: Removing unreachable block (ram,0x0da6d0) */
/* WARNING: Removing unreachable block (ram,0x0da6c0) */
/* WARNING: Removing unreachable block (ram,0x0da6ba) */
/* WARNING: Removing unreachable block (ram,0x0da6a2) */
/* WARNING: Removing unreachable block (ram,0x0da698) */
/* WARNING: Removing unreachable block (ram,0x0da652) */
/* WARNING: Removing unreachable block (ram,0x0da64e) */
/* WARNING: Removing unreachable block (ram,0x0da674) */
/* WARNING: Removing unreachable block (ram,0x0da680) */
/* WARNING: Removing unreachable block (ram,0x0da68e) */
/* WARNING: Removing unreachable block (ram,0x0da684) */
/* WARNING: Removing unreachable block (ram,0x0da67a) */
/* WARNING: Removing unreachable block (ram,0x0da670) */
/* WARNING: Removing unreachable block (ram,0x0da660) */
/* WARNING: Removing unreachable block (ram,0x0da648) */
/* WARNING: Removing unreachable block (ram,0x0da63e) */
/* WARNING: Removing unreachable block (ram,0x0da658) */
/* WARNING: Removing unreachable block (ram,0x0da6ac) */
/* WARNING: Removing unreachable block (ram,0x0da6b0) */
/* WARNING: Removing unreachable block (ram,0x0da776) */
/* WARNING: Removing unreachable block (ram,0x0da710) */
/* WARNING: Removing unreachable block (ram,0x0da844) */
/* WARNING: Removing unreachable block (ram,0x0da7e4) */

int egs52_update_near_d688_0da630(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int *piVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  char cVar13;
  byte bVar14;
  byte bVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  undefined2 uStack_1c;
  
  iVar17 = Ram00f652;
  uVar9 = iVar17 + 0x26;
  uVar2 = 0x24;
  if ((((uVar9 & 0xc000) != 0) && (uVar2 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  piVar8 = (int *)((uint3)uVar2 << 0xe | (uint3)(uVar9 & 0x3fff));
  if (param_1 == *piVar8 || param_1 < *piVar8) {
    UNK_00d688 = 1;
    uVar2 = 0x24;
    if ((((uVar9 & 0xc000) != 0) && (uVar2 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    param_1 = *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar9 & 0x3fff));
  }
  else {
    UNK_00d688 = 6;
    iVar17 = Ram00f652;
    uVar9 = iVar17 + 0x32;
    uVar2 = 0x24;
    if ((((uVar9 & 0xc000) != 0) && (uVar2 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    if (param_1 < *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar9 & 0x3fff))) {
      UNK_00d688 = 1;
      while( true ) {
        bVar14 = UNK_00d688;
        uVar9 = iVar17 + 0x26 + (uint)bVar14 * 2;
        uVar2 = 0x24;
        if ((((uVar9 & 0xc000) != 0) && (uVar2 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        piVar8 = (int *)((uint3)uVar2 << 0xe | (uint3)(uVar9 & 0x3fff));
        if (param_1 == *piVar8 || param_1 < *piVar8) break;
        cVar13 = UNK_00d688;
        UNK_00d688 = cVar13 + '\x01';
      }
    }
    else {
      uVar2 = 0x24;
      if ((((uVar9 & 0xc000) != 0) && (uVar2 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      param_1 = *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar9 & 0x3fff));
    }
  }
  uStack_1c = param_2 & 0xff;
  iVar17 = Ram00f652;
  uVar9 = iVar17 + 0x3e;
  uVar2 = 0x24;
  if ((((uVar9 & 0xc000) != 0) && (uVar2 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  if (*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar9 & 0x3fff)) < uStack_1c) {
    UNK_00d689 = 3;
    iVar17 = Ram00f652;
    uVar9 = iVar17 + 0x41;
    uVar2 = 0x24;
    if ((((uVar9 & 0xc000) != 0) && (uVar2 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    if (uStack_1c < *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar9 & 0x3fff))) {
      UNK_00d689 = 1;
      while( true ) {
        bVar14 = UNK_00d689;
        uVar9 = iVar17 + 0x3e + (uint)bVar14;
        uVar2 = 0x24;
        if ((((uVar9 & 0xc000) != 0) && (uVar2 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        if (uStack_1c <= *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar9 & 0x3fff))) break;
        cVar13 = UNK_00d689;
        UNK_00d689 = cVar13 + '\x01';
      }
    }
    else {
      uVar2 = 0x24;
      if ((((uVar9 & 0xc000) != 0) && (uVar2 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      uStack_1c = (uint)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar9 & 0x3fff));
    }
  }
  else {
    UNK_00d689 = 1;
    uVar2 = 0x24;
    if ((((uVar9 & 0xc000) != 0) && (uVar2 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    uStack_1c = (uint)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar9 & 0x3fff));
  }
  iVar17 = Ram00f652;
  uVar2 = iVar17 + 5;
  uVar9 = 0x24;
  if ((((uVar2 & 0xc000) != 0) && (uVar9 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
     (uVar9 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
    uVar9 = 3;
  }
  if ((*(byte *)((uint3)uVar9 << 0xe | (uint3)(uVar2 & 0x3fff)) & 4) == 0) {
    bVar14 = UNK_00d689;
    bVar15 = UNK_00d688;
    iVar17 = (uint)bVar14 + (uint)bVar15 * 4;
    iVar18 = Ram00f6fe;
    uVar9 = iVar18 + 3 + iVar17;
    uVar2 = 0x24;
    if ((((uVar9 & 0xc000) != 0) && (uVar2 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    iVar18 = Ram00f6fe;
    uVar10 = iVar18 + -1 + iVar17;
    uVar3 = 0x24;
    if ((((uVar10 & 0xc000) != 0) && (uVar3 = 0x21, (uVar10 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar10 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    uVar4 = 0x24;
    if ((((uVar10 & 0xc000) != 0) && (uVar4 = 0x21, (uVar10 & 0xc000) != 0x4000)) &&
       (uVar4 = 0x2c, (uVar10 & 0xc000) != 0x8000)) {
      uVar4 = 3;
    }
    bVar14 = UNK_00d688;
    iVar17 = (uint)bVar14 * 2;
    iVar18 = Ram00f652;
    uVar1 = iVar18 + iVar17 + 0x26;
    uVar5 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar5 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar5 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar5 = 3;
    }
    iVar18 = Ram00f652;
    uVar11 = iVar18 + 0x24 + iVar17;
    uVar6 = 0x24;
    if ((((uVar11 & 0xc000) != 0) && (uVar6 = 0x21, (uVar11 & 0xc000) != 0x4000)) &&
       (uVar6 = 0x2c, (uVar11 & 0xc000) != 0x8000)) {
      uVar6 = 3;
    }
    uVar12 = iVar18 + 0x24 + iVar17;
    uVar7 = 0x24;
    if ((((uVar12 & 0xc000) != 0) && (uVar7 = 0x21, (uVar12 & 0xc000) != 0x4000)) &&
       (uVar7 = 0x2c, (uVar12 & 0xc000) != 0x8000)) {
      uVar7 = 3;
    }
    iVar17 = (uint)*(byte *)((uint3)uVar4 << 0xe | (uint3)(uVar10 & 0x3fff)) +
             (int)(((long)(int)((uint)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar9 & 0x3fff)) -
                               (uint)*(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar10 & 0x3fff))) *
                   (long)(param_1 - *(int *)((uint3)uVar7 << 0xe | (uint3)(uVar12 & 0x3fff)))) /
                  (long)(*(int *)((uint3)uVar5 << 0xe | (uint3)(uVar1 & 0x3fff)) -
                        *(int *)((uint3)uVar6 << 0xe | (uint3)(uVar11 & 0x3fff))));
  }
  else {
    bVar15 = UNK_00d689;
    bVar14 = UNK_00d688;
    iVar17 = (uint)bVar15 + (uint)bVar14 * 4;
    uVar2 = iVar17 + 0xd6bf;
    uVar9 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar9 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar9 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar9 = 3;
    }
    uVar10 = iVar17 + 0xd6bb;
    uVar3 = 0x24;
    if ((((uVar10 & 0xc000) != 0) && (uVar3 = 0x21, (uVar10 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar10 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    uVar4 = 0x24;
    if ((((uVar10 & 0xc000) != 0) && (uVar4 = 0x21, (uVar10 & 0xc000) != 0x4000)) &&
       (uVar4 = 0x2c, (uVar10 & 0xc000) != 0x8000)) {
      uVar4 = 3;
    }
    bVar14 = UNK_00d688;
    iVar17 = (uint)bVar14 * 2;
    iVar18 = Ram00f652;
    uVar1 = iVar18 + iVar17 + 0x26;
    uVar5 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar5 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar5 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar5 = 3;
    }
    iVar18 = Ram00f652;
    uVar11 = iVar18 + 0x24 + iVar17;
    uVar6 = 0x24;
    if ((((uVar11 & 0xc000) != 0) && (uVar6 = 0x21, (uVar11 & 0xc000) != 0x4000)) &&
       (uVar6 = 0x2c, (uVar11 & 0xc000) != 0x8000)) {
      uVar6 = 3;
    }
    uVar12 = iVar18 + 0x24 + iVar17;
    uVar7 = 0x24;
    if ((((uVar12 & 0xc000) != 0) && (uVar7 = 0x21, (uVar12 & 0xc000) != 0x4000)) &&
       (uVar7 = 0x2c, (uVar12 & 0xc000) != 0x8000)) {
      uVar7 = 3;
    }
    iVar17 = (uint)*(byte *)((uint3)uVar4 << 0xe | (uint3)(uVar10 & 0x3fff)) +
             (int)(((long)(int)((uint)*(byte *)((uint3)uVar9 << 0xe | (uint3)(uVar2 & 0x3fff)) -
                               (uint)*(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar10 & 0x3fff))) *
                   (long)(param_1 - *(int *)((uint3)uVar7 << 0xe | (uint3)(uVar12 & 0x3fff)))) /
                  (long)(*(int *)((uint3)uVar5 << 0xe | (uint3)(uVar1 & 0x3fff)) -
                        *(int *)((uint3)uVar6 << 0xe | (uint3)(uVar11 & 0x3fff))));
  }
  iVar18 = Ram00f652;
  uVar2 = iVar18 + 5;
  uVar9 = 0x24;
  if ((((uVar2 & 0xc000) != 0) && (uVar9 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
     (uVar9 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
    uVar9 = 3;
  }
  if ((*(byte *)((uint3)uVar9 << 0xe | (uint3)(uVar2 & 0x3fff)) & 4) == 0) {
    bVar15 = UNK_00d689;
    bVar14 = UNK_00d688;
    iVar18 = (uint)bVar15 + (uint)bVar14 * 4;
    iVar16 = Ram00f6fe;
    uVar9 = iVar16 + 4 + iVar18;
    uVar2 = 0x24;
    if ((((uVar9 & 0xc000) != 0) && (uVar2 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    iVar16 = Ram00f6fe;
    uVar10 = iVar16 + iVar18;
    uVar3 = 0x24;
    if ((((uVar10 & 0xc000) != 0) && (uVar3 = 0x21, (uVar10 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar10 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    uVar4 = 0x24;
    if ((((uVar10 & 0xc000) != 0) && (uVar4 = 0x21, (uVar10 & 0xc000) != 0x4000)) &&
       (uVar4 = 0x2c, (uVar10 & 0xc000) != 0x8000)) {
      uVar4 = 3;
    }
    bVar14 = UNK_00d688;
    iVar18 = (uint)bVar14 * 2;
    iVar16 = Ram00f652;
    uVar1 = iVar16 + iVar18 + 0x26;
    uVar5 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar5 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar5 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar5 = 3;
    }
    iVar16 = Ram00f652;
    uVar11 = iVar16 + 0x24 + iVar18;
    uVar6 = 0x24;
    if ((((uVar11 & 0xc000) != 0) && (uVar6 = 0x21, (uVar11 & 0xc000) != 0x4000)) &&
       (uVar6 = 0x2c, (uVar11 & 0xc000) != 0x8000)) {
      uVar6 = 3;
    }
    uVar12 = iVar16 + 0x24 + iVar18;
    uVar7 = 0x24;
    if ((((uVar12 & 0xc000) != 0) && (uVar7 = 0x21, (uVar12 & 0xc000) != 0x4000)) &&
       (uVar7 = 0x2c, (uVar12 & 0xc000) != 0x8000)) {
      uVar7 = 3;
    }
    iVar18 = (uint)*(byte *)((uint3)uVar4 << 0xe | (uint3)(uVar10 & 0x3fff)) +
             (int)(((long)(int)((uint)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar9 & 0x3fff)) -
                               (uint)*(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar10 & 0x3fff))) *
                   (long)(param_1 - *(int *)((uint3)uVar7 << 0xe | (uint3)(uVar12 & 0x3fff)))) /
                  (long)(*(int *)((uint3)uVar5 << 0xe | (uint3)(uVar1 & 0x3fff)) -
                        *(int *)((uint3)uVar6 << 0xe | (uint3)(uVar11 & 0x3fff))));
  }
  else {
    bVar15 = UNK_00d689;
    bVar14 = UNK_00d688;
    iVar18 = (uint)bVar15 + (uint)bVar14 * 4;
    uVar2 = iVar18 + 0xd6c0;
    uVar9 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar9 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar9 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar9 = 3;
    }
    uVar10 = iVar18 + 0xd6bc;
    uVar3 = 0x24;
    if ((((uVar10 & 0xc000) != 0) && (uVar3 = 0x21, (uVar10 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar10 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    uVar4 = 0x24;
    if ((((uVar10 & 0xc000) != 0) && (uVar4 = 0x21, (uVar10 & 0xc000) != 0x4000)) &&
       (uVar4 = 0x2c, (uVar10 & 0xc000) != 0x8000)) {
      uVar4 = 3;
    }
    bVar14 = UNK_00d688;
    iVar18 = (uint)bVar14 * 2;
    iVar16 = Ram00f652;
    uVar1 = iVar16 + iVar18 + 0x26;
    uVar5 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar5 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar5 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar5 = 3;
    }
    iVar16 = Ram00f652;
    uVar11 = iVar16 + 0x24 + iVar18;
    uVar6 = 0x24;
    if ((((uVar11 & 0xc000) != 0) && (uVar6 = 0x21, (uVar11 & 0xc000) != 0x4000)) &&
       (uVar6 = 0x2c, (uVar11 & 0xc000) != 0x8000)) {
      uVar6 = 3;
    }
    uVar12 = iVar16 + 0x24 + iVar18;
    uVar7 = 0x24;
    if ((((uVar12 & 0xc000) != 0) && (uVar7 = 0x21, (uVar12 & 0xc000) != 0x4000)) &&
       (uVar7 = 0x2c, (uVar12 & 0xc000) != 0x8000)) {
      uVar7 = 3;
    }
    iVar18 = (uint)*(byte *)((uint3)uVar4 << 0xe | (uint3)(uVar10 & 0x3fff)) +
             (int)(((long)(int)((uint)*(byte *)((uint3)uVar9 << 0xe | (uint3)(uVar2 & 0x3fff)) -
                               (uint)*(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar10 & 0x3fff))) *
                   (long)(param_1 - *(int *)((uint3)uVar7 << 0xe | (uint3)(uVar12 & 0x3fff)))) /
                  (long)(*(int *)((uint3)uVar5 << 0xe | (uint3)(uVar1 & 0x3fff)) -
                        *(int *)((uint3)uVar6 << 0xe | (uint3)(uVar11 & 0x3fff))));
  }
  bVar14 = UNK_00d689;
  iVar16 = Ram00f652;
  uVar9 = iVar16 + 0x3e + (uint)bVar14;
  uVar2 = 0x24;
  if ((((uVar9 & 0xc000) != 0) && (uVar2 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  bVar14 = UNK_00d689;
  iVar16 = Ram00f652;
  uVar10 = iVar16 + 0x3d + (uint)bVar14;
  uVar3 = 0x24;
  if ((((uVar10 & 0xc000) != 0) && (uVar3 = 0x21, (uVar10 & 0xc000) != 0x4000)) &&
     (uVar3 = 0x2c, (uVar10 & 0xc000) != 0x8000)) {
    uVar3 = 3;
  }
  bVar14 = UNK_00d689;
  uVar1 = iVar16 + 0x3d + (uint)bVar14;
  uVar4 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar4 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar4 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar4 = 3;
  }
  return iVar17 + (int)(((long)(iVar18 - iVar17) *
                        (long)(int)(uStack_1c -
                                   *(byte *)((uint3)uVar4 << 0xe | (uint3)(uVar1 & 0x3fff)))) /
                       (long)(int)((uint)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar9 & 0x3fff)) -
                                  (uint)*(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar10 & 0x3fff))));
}


