/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a290e; FLS offset 0x02290e.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a2a7c) */
/* WARNING: Removing unreachable block (ram,0x0a2a44) */
/* WARNING: Removing unreachable block (ram,0x0a2a6a) */
/* WARNING: Removing unreachable block (ram,0x0a2a50) */
/* WARNING: Removing unreachable block (ram,0x0a2a2e) */
/* WARNING: Removing unreachable block (ram,0x0a2a16) */
/* WARNING: Removing unreachable block (ram,0x0a29f4) */
/* WARNING: Removing unreachable block (ram,0x0a29d8) */
/* WARNING: Removing unreachable block (ram,0x0a2988) */
/* WARNING: Removing unreachable block (ram,0x0a297c) */
/* WARNING: Removing unreachable block (ram,0x0a29b8) */
/* WARNING: Removing unreachable block (ram,0x0a299c) */
/* WARNING: Removing unreachable block (ram,0x0a294e) */
/* WARNING: Removing unreachable block (ram,0x0a2946) */
/* WARNING: Removing unreachable block (ram,0x0a2966) */
/* WARNING: Removing unreachable block (ram,0x0a2994) */
/* WARNING: Removing unreachable block (ram,0x0a29a0) */
/* WARNING: Removing unreachable block (ram,0x0a29ba) */
/* WARNING: Removing unreachable block (ram,0x0a29fc) */
/* WARNING: Removing unreachable block (ram,0x0a2a3a) */
/* WARNING: Removing unreachable block (ram,0x0a2a4c) */
/* WARNING: Removing unreachable block (ram,0x0a2a68) */

undefined2 egs52_transform_far_memory_0a290e(byte param_1)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  undefined2 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  char cVar13;
  
  uVar4 = egs52_update_near_fd6c_0a2bd4(param_1);
  uVar4 = uVar4 & 0xff;
  if (uVar4 == 0xfe) {
    uVar5 = 0xfd;
  }
  else {
    iVar12 = uVar4 * 0x38;
    uVar10 = 0x1028;
    uVar7 = 0;
    uVar9 = iVar12 + 0xc63f;
    uVar6 = 0x24;
    if ((((uVar9 & 0xc000) != 0) && (uVar6 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
       (uVar6 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
      uVar6 = 3;
    }
    if (*(char *)((uint3)uVar6 << 0xe | (uint3)(uVar9 & 0x3fff)) == '\x02') {
      uVar6 = 0x24;
      if ((((uVar9 & 0xc000) != 0) && (uVar6 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
         (uVar6 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
        uVar6 = 3;
      }
      iVar11 = iVar12 + -0x39f7 +
               (uint)(byte)(*(char *)((uint3)uVar6 << 0xe | (uint3)(uVar9 & 0x3fff)) - 1) * 0x12;
    }
    else {
      uVar6 = 0x24;
      if ((((uVar9 & 0xc000) != 0) && (uVar6 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
         (uVar6 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
        uVar6 = 3;
      }
      iVar11 = iVar12 + -0x39f7 +
               (uint)(byte)(*(char *)((uint3)uVar6 << 0xe | (uint3)(uVar9 & 0x3fff)) + 1) * 0x12;
    }
    uVar6 = 0;
    do {
      uVar8 = 0x24;
      if ((((uVar10 & 0xc000) != 0) && (uVar8 = 0x21, (uVar10 & 0xc000) != 0x4000)) &&
         (uVar8 = 0x2c, (uVar10 & 0xc000) != 0x8000)) {
        uVar8 = 3;
      }
      iVar3 = (uint)*(byte *)((uint3)uVar8 << 0xe | (uint3)(uVar10 & 0x3fff)) * 6;
      uVar8 = *(uint *)((uint3)(iVar3 + 0x1334) | 0x90000);
      uVar7 = uVar7 + uVar8;
      if (0xc < uVar7) break;
      uVar1 = 0x24;
      if ((((uVar10 & 0xc000) != 0) && (uVar1 = 0x21, (uVar10 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar10 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      if (*(char *)((uint3)uVar1 << 0xe | (uint3)(uVar10 & 0x3fff)) == -1) break;
      uVar1 = *(uint *)((uint3)(iVar3 + 0x1336) | 0x90000);
      uVar5 = *(undefined2 *)((uint3)(iVar3 + 0x1338) | 0x90000);
      while (uVar8 != 0) {
        uVar8 = uVar8 - 1;
        cVar13 = (char)uVar5 + CARRY2(uVar1,uVar8);
        *(undefined1 *)CONCAT12(cVar13,iVar11) = *(undefined1 *)CONCAT12(cVar13,uVar1 + uVar8);
        iVar11 = iVar11 + 1;
      }
      uVar10 = uVar10 + 1;
      uVar6 = uVar6 + 1;
    } while (uVar6 < 0xc);
    uVar6 = (uint)param_1 * 0x14 + 0x9306;
    uVar7 = 0x24;
    if ((((uVar6 & 0xc000) != 0) && (uVar7 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
       (uVar7 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
      uVar7 = 3;
    }
    uVar7 = (uint)*(byte *)((uint3)uVar7 << 0xe | (uint3)(uVar6 & 0x3fff)) * 6 + 0x1034;
    uVar10 = 0;
    uVar6 = 0x24;
    if ((((uVar9 & 0xc000) != 0) && (uVar6 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
       (uVar6 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
      uVar6 = 3;
    }
    if (*(char *)((uint3)uVar6 << 0xe | (uint3)(uVar9 & 0x3fff)) == '\x02') {
      uVar6 = 0x24;
      if ((((uVar9 & 0xc000) != 0) && (uVar6 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
         (uVar6 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
        uVar6 = 3;
      }
      bVar2 = *(char *)((uint3)uVar6 << 0xe | (uint3)(uVar9 & 0x3fff)) - 1;
    }
    else {
      uVar6 = 0x24;
      if ((((uVar9 & 0xc000) != 0) && (uVar6 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
         (uVar6 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
        uVar6 = 3;
      }
      bVar2 = *(char *)((uint3)uVar6 << 0xe | (uint3)(uVar9 & 0x3fff)) + 1;
    }
    iVar12 = iVar12 + (uint)bVar2 * 0x12 + -0x39eb;
    uVar6 = 0;
    do {
      uVar9 = 0x24;
      if ((((uVar7 & 0xc000) != 0) && (uVar9 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
         (uVar9 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
        uVar9 = 3;
      }
      iVar11 = (uint)*(byte *)((uint3)uVar9 << 0xe | (uint3)(uVar7 & 0x3fff)) * 6;
      uVar9 = *(uint *)((uint3)(iVar11 + 0x1334) | 0x90000);
      uVar10 = uVar10 + uVar9;
      if (6 < uVar10) break;
      uVar8 = 0x24;
      if ((((uVar7 & 0xc000) != 0) && (uVar8 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
         (uVar8 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
        uVar8 = 3;
      }
      if (*(char *)((uint3)uVar8 << 0xe | (uint3)(uVar7 & 0x3fff)) == -1) break;
      uVar8 = *(uint *)((uint3)(iVar11 + 0x1336) | 0x90000);
      uVar5 = *(undefined2 *)((uint3)(iVar11 + 0x1338) | 0x90000);
      while (uVar9 != 0) {
        uVar9 = uVar9 - 1;
        cVar13 = (char)uVar5 + CARRY2(uVar8,uVar9);
        *(undefined1 *)CONCAT12(cVar13,iVar12) = *(undefined1 *)CONCAT12(cVar13,uVar8 + uVar9);
        iVar12 = iVar12 + 1;
      }
      uVar7 = uVar7 + 1;
      uVar6 = uVar6 + 1;
    } while (uVar6 < 6);
    uVar4 = uVar4 + 0xca6c;
    uVar6 = 0x24;
    if ((((uVar4 & 0xc000) != 0) && (uVar6 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
       (uVar6 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
      uVar6 = 3;
    }
    *(undefined1 *)((uint3)uVar6 << 0xe | (uint3)(uVar4 & 0x3fff)) = 0;
    uVar5 = 0;
  }
  return uVar5;
}


