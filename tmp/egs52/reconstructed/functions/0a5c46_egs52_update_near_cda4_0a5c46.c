/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a5c46; FLS offset 0x025c46.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Function: egs52_read_far_u32_registers replaced with injection:
   egs52_read_far_u32_registers */
/* WARNING: Removing unreachable block (ram,0x0a5f1a) */
/* WARNING: Removing unreachable block (ram,0x0a5e68) */
/* WARNING: Removing unreachable block (ram,0x0a5df8) */
/* WARNING: Removing unreachable block (ram,0x0a5e3e) */
/* WARNING: Removing unreachable block (ram,0x0a5ed4) */
/* WARNING: Removing unreachable block (ram,0x0a5e9e) */
/* WARNING: Removing unreachable block (ram,0x0a5f10) */
/* WARNING: Removing unreachable block (ram,0x0a5f02) */
/* WARNING: Removing unreachable block (ram,0x0a5ef4) */
/* WARNING: Removing unreachable block (ram,0x0a5dde) */
/* WARNING: Removing unreachable block (ram,0x0a5eac) */
/* WARNING: Removing unreachable block (ram,0x0a5f0e) */
/* WARNING: Removing unreachable block (ram,0x0a5ec0) */
/* WARNING: Removing unreachable block (ram,0x0a5df0) */
/* WARNING: Removing unreachable block (ram,0x0a5f08) */
/* WARNING: Removing unreachable block (ram,0x0a5ee8) */
/* WARNING: Removing unreachable block (ram,0x0a5e52) */
/* WARNING: Removing unreachable block (ram,0x0a5df6) */
/* WARNING: Removing unreachable block (ram,0x0a5de6) */
/* WARNING: Removing unreachable block (ram,0x0a5dc8) */
/* WARNING: Removing unreachable block (ram,0x0a5db4) */
/* WARNING: Removing unreachable block (ram,0x0a5d04) */
/* WARNING: Removing unreachable block (ram,0x0a5c96) */
/* WARNING: Removing unreachable block (ram,0x0a5cda) */
/* WARNING: Removing unreachable block (ram,0x0a5d6e) */
/* WARNING: Removing unreachable block (ram,0x0a5d38) */
/* WARNING: Removing unreachable block (ram,0x0a5daa) */
/* WARNING: Removing unreachable block (ram,0x0a5d9c) */
/* WARNING: Removing unreachable block (ram,0x0a5d8e) */
/* WARNING: Removing unreachable block (ram,0x0a5c7c) */
/* WARNING: Removing unreachable block (ram,0x0a5d46) */
/* WARNING: Removing unreachable block (ram,0x0a5da8) */
/* WARNING: Removing unreachable block (ram,0x0a5d5a) */
/* WARNING: Removing unreachable block (ram,0x0a5c8e) */
/* WARNING: Removing unreachable block (ram,0x0a5da2) */
/* WARNING: Removing unreachable block (ram,0x0a5d82) */
/* WARNING: Removing unreachable block (ram,0x0a5cee) */
/* WARNING: Removing unreachable block (ram,0x0a5c94) */
/* WARNING: Removing unreachable block (ram,0x0a5c84) */
/* WARNING: Removing unreachable block (ram,0x0a5c66) */
/* WARNING: Removing unreachable block (ram,0x0a5c52) */
/* WARNING: Removing unreachable block (ram,0x0a5c4e) */
/* WARNING: Removing unreachable block (ram,0x0a5c76) */
/* WARNING: Removing unreachable block (ram,0x0a5c82) */
/* WARNING: Removing unreachable block (ram,0x0a5d3c) */
/* WARNING: Removing unreachable block (ram,0x0a5d92) */
/* WARNING: Removing unreachable block (ram,0x0a5cec) */
/* WARNING: Removing unreachable block (ram,0x0a5d2e) */
/* WARNING: Removing unreachable block (ram,0x0a5d08) */
/* WARNING: Removing unreachable block (ram,0x0a5dd8) */
/* WARNING: Removing unreachable block (ram,0x0a5de4) */
/* WARNING: Removing unreachable block (ram,0x0a5ea2) */
/* WARNING: Removing unreachable block (ram,0x0a5ef8) */
/* WARNING: Removing unreachable block (ram,0x0a5e50) */
/* WARNING: Removing unreachable block (ram,0x0a5e94) */
/* WARNING: Removing unreachable block (ram,0x0a5e6c) */
/* WARNING: Removing unreachable block (ram,0x0a5d0a) */
/* WARNING: Removing unreachable block (ram,0x0a5e6e) */
/* WARNING: Removing unreachable block (ram,0x0a5d5e) */
/* WARNING: Removing unreachable block (ram,0x0a5ec4) */
/* WARNING: Removing unreachable block (ram,0x0a5d72) */
/* WARNING: Removing unreachable block (ram,0x0a5ed8) */

void egs52_update_near_cda4_0a5c46(undefined2 param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  byte bVar7;
  uint uVar8;
  uint uVar9;
  char cVar10;
  uint uVar11;
  uint uVar12;
  
  Ram00cda4 = param_1;
  UNK_00cda6 = 0;
  uVar9 = 0;
  do {
    uVar3 = uVar9 * 0x10 + 0xef10;
    uVar1 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    *(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) = 0x5955;
    uVar9 = uVar9 + 1;
  } while (uVar9 < 0xf);
  uVar9 = 0;
  while (uVar9 < 0xe) {
    bVar7 = UNK_00cda6;
    iVar4 = Ram00cda4;
    uVar3 = iVar4 + (uint)bVar7 * 4;
    uVar1 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    uVar11 = uVar3 + 2;
    uVar12 = 0x24;
    if ((((uVar11 & 0xc000) != 0) && (uVar12 = 0x21, (uVar11 & 0xc000) != 0x4000)) &&
       (uVar12 = 0x2c, (uVar11 & 0xc000) != 0x8000)) {
      uVar12 = 3;
    }
    if (*(int *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) == 0 &&
        *(int *)((uint3)uVar12 << 0xe | (uint3)(uVar11 & 0x3fff)) == 0) break;
    bVar7 = UNK_00cda6;
    iVar4 = Ram00cda4;
    uVar3 = iVar4 + (uint)bVar7 * 4;
    uVar1 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    uVar11 = *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff));
    uVar1 = uVar3 + 2;
    uVar12 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar12 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar12 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar12 = 3;
    }
    iVar4 = uVar11 + 4;
    cVar10 = (char)*(undefined2 *)((uint3)uVar12 << 0xe | (uint3)(uVar1 & 0x3fff)) +
             (0xfffb < uVar11);
    if ((*(byte *)CONCAT12(cVar10,iVar4) & 2) == 0) {
      uVar12 = uVar3 + 2;
      uVar1 = 0x24;
      if ((((uVar12 & 0xc000) != 0) && (uVar1 = 0x21, (uVar12 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar12 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      uVar12 = *(uint *)((uint3)*(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar12 & 0x3fff)) << 0x10 |
                        (uint3)*(uint *)CONCAT12(cVar10,uVar3));
      uVar3 = uVar9 * 0x10 + 0xef12;
      uVar1 = 0x24;
      if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) =
           (uVar12 & 0x7ff) >> 3 | uVar12 << 0xd;
      uVar3 = uVar9 * 0x10 + 0xef14;
      uVar1 = 0x24;
      if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) = 0;
    }
    else {
      uVar1 = 0x24;
      if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      uVar11 = *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff));
      uVar1 = uVar3 + 2;
      uVar12 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar12 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar12 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar12 = 3;
      }
      uVar1 = *(uint *)((uint3)uVar12 << 0xe | (uint3)(uVar1 & 0x3fff));
      uVar8 = *(uint *)((uint3)uVar1 << 0x10 | (uint3)uVar11);
      uVar11 = *(uint *)((uint3)(uVar1 + (0xfffd < uVar11)) << 0x10 | (uint3)(uVar11 + 2));
      uVar12 = uVar9 * 0x10 + 0xef12;
      uVar1 = 0x24;
      if ((((uVar12 & 0xc000) != 0) && (uVar1 = 0x21, (uVar12 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar12 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar12 & 0x3fff)) =
           (uVar11 & 0x1fff) >> 5 | (uint)(byte)((byte)(uVar11 << 3) | (byte)(uVar8 >> 0xd)) << 8;
      uVar1 = 0x24;
      if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      uVar11 = uVar3 + 2;
      uVar12 = 0x24;
      if ((((uVar11 & 0xc000) != 0) && (uVar12 = 0x21, (uVar11 & 0xc000) != 0x4000)) &&
         (uVar12 = 0x2c, (uVar11 & 0xc000) != 0x8000)) {
        uVar12 = 3;
      }
      uVar5 = uVar9 * 0x10 + 0xef14;
      uVar2 = 0x24;
      if ((((uVar5 & 0xc000) != 0) && (uVar2 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar5 & 0x3fff)) =
           (uVar8 & 0x1fff) >> 5 |
           *(int *)((uint3)*(uint *)((uint3)uVar12 << 0xe | (uint3)(uVar11 & 0x3fff)) << 0x10 |
                   (uint3)*(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff))) << 0xb;
    }
    iVar6 = uVar9 * 0x10;
    uVar3 = iVar6 + 0xef16;
    uVar1 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    *(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) =
         (*(byte *)CONCAT12(cVar10,iVar4) & 1) << 3 | (*(byte *)CONCAT12(cVar10,iVar4) & 2) << 2;
    if ((*(byte *)CONCAT12(cVar10,iVar4) & 4) != 0) {
      uVar3 = iVar6 + 0xef10;
      uVar1 = 0x24;
      if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) = 0xfffb;
    }
    if ((*(byte *)CONCAT12(cVar10,iVar4) & 8) != 0) {
      uVar3 = iVar6 + 0xef10;
      uVar1 = 0x24;
      if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) = 0xffef;
    }
    uVar3 = iVar6 + 0xef10;
    uVar1 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    *(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) = 0xf5bf;
    uVar9 = uVar9 + 1;
    cVar10 = UNK_00cda6;
    UNK_00cda6 = cVar10 + '\x01';
  }
  bVar7 = UNK_00cda2;
  UNK_00cda2 = bVar7 | 1;
  uVar9 = 0;
  do {
    uVar3 = uVar9 * 0x10 + 0xee10;
    uVar1 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    *(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) = 0x5955;
    uVar9 = uVar9 + 1;
  } while (uVar9 < 0xf);
  uVar9 = 0;
  while (uVar9 < 0xe) {
    bVar7 = UNK_00cda6;
    iVar4 = Ram00cda4;
    uVar3 = iVar4 + (uint)bVar7 * 4;
    uVar1 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    uVar11 = uVar3 + 2;
    uVar12 = 0x24;
    if ((((uVar11 & 0xc000) != 0) && (uVar12 = 0x21, (uVar11 & 0xc000) != 0x4000)) &&
       (uVar12 = 0x2c, (uVar11 & 0xc000) != 0x8000)) {
      uVar12 = 3;
    }
    if (*(int *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) == 0 &&
        *(int *)((uint3)uVar12 << 0xe | (uint3)(uVar11 & 0x3fff)) == 0) break;
    bVar7 = UNK_00cda6;
    iVar4 = Ram00cda4;
    uVar3 = iVar4 + (uint)bVar7 * 4;
    uVar1 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    uVar11 = *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff));
    uVar1 = uVar3 + 2;
    uVar12 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar12 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar12 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar12 = 3;
    }
    iVar4 = uVar11 + 4;
    cVar10 = (char)*(undefined2 *)((uint3)uVar12 << 0xe | (uint3)(uVar1 & 0x3fff)) +
             (0xfffb < uVar11);
    if ((*(byte *)CONCAT12(cVar10,iVar4) & 2) == 0) {
      uVar12 = uVar3 + 2;
      uVar1 = 0x24;
      if ((((uVar12 & 0xc000) != 0) && (uVar1 = 0x21, (uVar12 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar12 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      uVar12 = *(uint *)((uint3)*(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar12 & 0x3fff)) << 0x10 |
                        (uint3)*(uint *)CONCAT12(cVar10,uVar3));
      uVar3 = uVar9 * 0x10 + 0xee12;
      uVar1 = 0x24;
      if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) =
           (uVar12 & 0x7ff) >> 3 | uVar12 << 0xd;
      uVar3 = uVar9 * 0x10 + 0xee14;
      uVar1 = 0x24;
      if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) = 0;
    }
    else {
      uVar1 = 0x24;
      if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      uVar11 = *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff));
      uVar1 = uVar3 + 2;
      uVar12 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar12 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar12 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar12 = 3;
      }
      uVar1 = *(uint *)((uint3)uVar12 << 0xe | (uint3)(uVar1 & 0x3fff));
      uVar8 = *(uint *)((uint3)uVar1 << 0x10 | (uint3)uVar11);
      uVar11 = *(uint *)((uint3)(uVar1 + (0xfffd < uVar11)) << 0x10 | (uint3)(uVar11 + 2));
      uVar12 = uVar9 * 0x10 + 0xee12;
      uVar1 = 0x24;
      if ((((uVar12 & 0xc000) != 0) && (uVar1 = 0x21, (uVar12 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar12 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar12 & 0x3fff)) =
           (uVar11 & 0x1fff) >> 5 | (uint)(byte)((byte)(uVar11 << 3) | (byte)(uVar8 >> 0xd)) << 8;
      uVar1 = 0x24;
      if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      uVar11 = uVar3 + 2;
      uVar12 = 0x24;
      if ((((uVar11 & 0xc000) != 0) && (uVar12 = 0x21, (uVar11 & 0xc000) != 0x4000)) &&
         (uVar12 = 0x2c, (uVar11 & 0xc000) != 0x8000)) {
        uVar12 = 3;
      }
      uVar5 = uVar9 * 0x10 + 0xee14;
      uVar2 = 0x24;
      if ((((uVar5 & 0xc000) != 0) && (uVar2 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar5 & 0x3fff)) =
           (uVar8 & 0x1fff) >> 5 |
           *(int *)((uint3)*(uint *)((uint3)uVar12 << 0xe | (uint3)(uVar11 & 0x3fff)) << 0x10 |
                   (uint3)*(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff))) << 0xb;
    }
    iVar6 = uVar9 * 0x10;
    uVar3 = iVar6 + 0xee16;
    uVar1 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    *(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) =
         (*(byte *)CONCAT12(cVar10,iVar4) & 1) << 3 | (*(byte *)CONCAT12(cVar10,iVar4) & 2) << 2;
    if ((*(byte *)CONCAT12(cVar10,iVar4) & 4) != 0) {
      uVar3 = iVar6 + 0xee10;
      uVar1 = 0x24;
      if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) = 0xfffb;
    }
    if ((*(byte *)CONCAT12(cVar10,iVar4) & 8) != 0) {
      uVar3 = iVar6 + 0xee10;
      uVar1 = 0x24;
      if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) = 0xffef;
    }
    uVar3 = iVar6 + 0xee10;
    uVar1 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    *(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) = 0xf5bf;
    uVar9 = uVar9 + 1;
    cVar10 = UNK_00cda6;
    UNK_00cda6 = cVar10 + '\x01';
  }
  bVar7 = UNK_00cda2;
  UNK_00cda2 = bVar7 | 4;
  return;
}


