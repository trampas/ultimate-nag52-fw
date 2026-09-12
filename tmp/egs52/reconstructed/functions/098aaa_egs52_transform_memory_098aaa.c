/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x098aaa; FLS offset 0x018aaa.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x098b1c) */
/* WARNING: Removing unreachable block (ram,0x098b0e) */
/* WARNING: Removing unreachable block (ram,0x098aea) */
/* WARNING: Removing unreachable block (ram,0x098ad4) */
/* WARNING: Removing unreachable block (ram,0x098ae4) */
/* WARNING: Removing unreachable block (ram,0x098af6) */
/* WARNING: Removing unreachable block (ram,0x098ad6) */
/* WARNING: Removing unreachable block (ram,0x098ace) */
/* WARNING: Removing unreachable block (ram,0x098ac4) */
/* WARNING: Removing unreachable block (ram,0x098b14) */

void egs52_transform_memory_098aaa(undefined1 param_1)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  uint uVar4;
  byte bVar5;
  int iVar6;
  int iVar7;
  
  iVar6 = egs52_call_09212e_098b9e(param_1);
  iVar7 = 0;
  do {
    uVar4 = iVar7 + 0xc192;
    uVar1 = 0x24;
    if ((((uVar4 & 0xc000) != 0) && (uVar1 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    if (*(char *)((uint3)uVar1 << 0xe | (uint3)(uVar4 & 0x3fff)) == -1) {
      uVar4 = iVar7 * 2 + 0xc196;
      uVar1 = 0x24;
      if ((((uVar4 & 0xc000) != 0) && (uVar1 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      if (*(int *)((uint3)uVar1 << 0xe | (uint3)(uVar4 & 0x3fff)) != 0) {
        uVar1 = 0x24;
        if ((((uVar4 & 0xc000) != 0) && (uVar1 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        if (*(int *)((uint3)uVar1 << 0xe | (uint3)(uVar4 & 0x3fff)) != iVar6) {
          uVar1 = 0x24;
          if ((((uVar4 & 0xc000) != 0) && (uVar1 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
             (uVar1 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
            uVar1 = 3;
          }
          *(int *)((uint3)uVar1 << 0xe | (uint3)(uVar4 & 0x3fff)) = iVar6;
          uVar1 = Ram00ff9e;
          Ram00ff9e = uVar1 & 0xff7f;
          uVar1 = Ram00ff9e;
          Ram00ff9e = uVar1 | 0x40;
        }
      }
    }
    else {
      uVar1 = 0x24;
      if ((((uVar4 & 0xc000) != 0) && (uVar1 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      uVar2 = 0x24;
      if ((((uVar4 & 0xc000) != 0) && (uVar2 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      *(char *)((uint3)uVar2 << 0xe | (uint3)(uVar4 & 0x3fff)) =
           *(char *)((uint3)uVar1 << 0xe | (uint3)(uVar4 & 0x3fff)) + -0x14;
      uVar1 = 0x24;
      if ((((uVar4 & 0xc000) != 0) && (uVar1 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      if (*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar4 & 0x3fff)) < 0x14) {
        uVar1 = 0x24;
        if ((((uVar4 & 0xc000) != 0) && (uVar1 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar4 & 0x3fff)) = 0xff;
        uVar1 = iVar7 * 2 + 0xc196;
        uVar4 = 0x24;
        if ((((uVar1 & 0xc000) != 0) && (uVar4 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
           (uVar4 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
          uVar4 = 3;
        }
        *(int *)((uint3)uVar4 << 0xe | (uint3)(uVar1 & 0x3fff)) = iVar6;
        bVar5 = UNK_00c19f;
        UNK_00c19f = bVar5 & ~(byte)(1 << (iVar7 * 2 + 1U & 0xf));
        uVar1 = Ram00ff9e;
        Ram00ff9e = uVar1 & 0xff7f;
        uVar1 = Ram00ff9e;
        Ram00ff9e = uVar1 | 0x40;
      }
    }
    bVar3 = iVar7 < 2;
    iVar7 = iVar7 + 1;
  } while (bVar3);
  return;
}


