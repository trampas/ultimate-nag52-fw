/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a2c70; FLS offset 0x022c70.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a2d02) */
/* WARNING: Removing unreachable block (ram,0x0a2d00) */
/* WARNING: Removing unreachable block (ram,0x0a2cde) */
/* WARNING: Removing unreachable block (ram,0x0a2cb0) */
/* WARNING: Removing unreachable block (ram,0x0a2c9c) */
/* WARNING: Removing unreachable block (ram,0x0a2c94) */
/* WARNING: Removing unreachable block (ram,0x0a2cf2) */
/* WARNING: Removing unreachable block (ram,0x0a2cfa) */

undefined1 egs52_transform_memory_0a2c70(byte param_1,uint param_2)

{
  uint uVar1;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined1 uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar2;
  
  if (param_1 < 0x14) {
    iVar4 = (uint)param_1 * 0x38;
    uVar3 = iVar4 + 0xc608;
    uVar7 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar7 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar7 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar7 = 3;
    }
    uVar10 = 0x24;
    if ((((param_2 & 0xc000) != 0) && (uVar10 = 0x21, (param_2 & 0xc000) != 0x4000)) &&
       (uVar10 = 0x2c, (param_2 & 0xc000) != 0x8000)) {
      uVar10 = 3;
    }
    *(undefined1 *)((uint3)uVar10 << 0xe | (uint3)(param_2 & 0x3fff)) =
         *(undefined1 *)((uint3)uVar7 << 0xe | (uint3)(uVar3 & 0x3fff));
    uVar3 = iVar4 + 0xc63f;
    uVar7 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar7 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar7 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar7 = 3;
    }
    if (*(char *)((uint3)uVar7 << 0xe | (uint3)(uVar3 & 0x3fff)) == '\x02') {
      uVar7 = iVar4 + 0xc62d;
      uVar10 = param_2 + 0x13;
      uVar8 = 0;
      do {
        uVar5 = 0x24;
        if ((((uVar7 & 0xc000) != 0) && (uVar5 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
           (uVar5 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
          uVar5 = 3;
        }
        uVar9 = 0x24;
        if ((((uVar10 & 0xc000) != 0) && (uVar9 = 0x21, (uVar10 & 0xc000) != 0x4000)) &&
           (uVar9 = 0x2c, (uVar10 & 0xc000) != 0x8000)) {
          uVar9 = 3;
        }
        *(undefined1 *)((uint3)uVar9 << 0xe | (uint3)(uVar10 & 0x3fff)) =
             *(undefined1 *)((uint3)uVar5 << 0xe | (uint3)(uVar7 & 0x3fff));
        uVar7 = uVar7 + 1;
        uVar10 = uVar10 + 1;
        uVar8 = uVar8 + 1;
      } while (uVar8 < 0x12);
      uVar7 = 1;
    }
    else {
      uVar7 = 2;
    }
    for (uVar10 = 0; uVar10 < uVar7; uVar10 = uVar10 + 1) {
      uVar8 = iVar4 + -0x39f7 + uVar10 * 0x12;
      uVar5 = param_2 + 1 + uVar10 * 0x12;
      uVar9 = 0;
      do {
        uVar1 = 0x24;
        if ((((uVar8 & 0xc000) != 0) && (uVar1 = 0x21, (uVar8 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar8 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        uVar2 = 0x24;
        if ((((uVar5 & 0xc000) != 0) && (uVar2 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar5 & 0x3fff)) =
             *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar8 & 0x3fff));
        uVar8 = uVar8 + 1;
        uVar5 = uVar5 + 1;
        uVar9 = uVar9 + 1;
      } while (uVar9 < 0x12);
    }
    uVar7 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar7 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar7 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar7 = 3;
    }
    if (*(char *)((uint3)uVar7 << 0xe | (uint3)(uVar3 & 0x3fff)) == '\x02') {
      param_2 = param_2 + 0x25;
      uVar7 = 0x24;
      if ((((param_2 & 0xc000) != 0) && (uVar7 = 0x21, (param_2 & 0xc000) != 0x4000)) &&
         (uVar7 = 0x2c, (param_2 & 0xc000) != 0x8000)) {
        uVar7 = 3;
      }
      *(undefined1 *)((uint3)uVar7 << 0xe | (uint3)(param_2 & 0x3fff)) = 1;
    }
    else {
      uVar7 = 0x24;
      if ((((uVar3 & 0xc000) != 0) && (uVar7 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
         (uVar7 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
        uVar7 = 3;
      }
      param_2 = param_2 + 0x25;
      uVar10 = 0x24;
      if ((((param_2 & 0xc000) != 0) && (uVar10 = 0x21, (param_2 & 0xc000) != 0x4000)) &&
         (uVar10 = 0x2c, (param_2 & 0xc000) != 0x8000)) {
        uVar10 = 3;
      }
      *(undefined1 *)((uint3)uVar10 << 0xe | (uint3)(param_2 & 0x3fff)) =
           *(undefined1 *)((uint3)uVar7 << 0xe | (uint3)(uVar3 & 0x3fff));
    }
    uVar6 = 0;
  }
  else {
    uVar6 = 0xfe;
  }
  return uVar6;
}


