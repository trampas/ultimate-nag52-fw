/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0e32e6; FLS offset 0x0632e6.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0e3360) */
/* WARNING: Removing unreachable block (ram,0x0e3322) */
/* WARNING: Removing unreachable block (ram,0x0e3348) */

undefined1 egs52_call_092248_0e32e6(uchar *param_1)

{
  uchar *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined1 uVar5;
  byte bVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uchar auStack_30 [26];
  byte bStack_16;
  byte bStack_14;
  byte bStack_13;
  uint uStack_12;
  int iStack_10;
  int iStack_e;
  uint uStack_c;
  byte bStack_a;
  
  egs52_memcpy_near(auStack_30,param_1,0x28);
  uVar5 = 1;
  uVar7 = 0;
  uVar10 = 0;
  uVar11 = 0;
  uVar12 = 0;
  uVar8 = 0;
  uVar9 = 0;
  bVar6 = 0;
  do {
    uVar4 = (uint)*(byte *)CONCAT12((0xdff7 < bVar6) + '\v',bVar6 + 0x2008);
    uVar2 = uVar7 * 0x100;
    uVar3 = uVar7 >> 8;
    uVar7 = uVar2 + uVar4;
    uVar10 = (uVar10 << 8 | uVar3) + (uint)CARRY2(uVar2,uVar4);
    uVar4 = (uint)*(byte *)CONCAT12((0xdff3 < bVar6) + '\v',bVar6 + 0x200c);
    uVar2 = uVar11 * 0x100;
    uVar3 = uVar11 >> 8;
    uVar11 = uVar2 + uVar4;
    uVar12 = (uVar12 << 8 | uVar3) + (uint)CARRY2(uVar2,uVar4);
    puVar1 = auStack_30 + bVar6;
    uVar2 = 0x24;
    if (((((uint)puVar1 & 0xc000) != 0) && (uVar2 = 0x21, ((uint)puVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, ((uint)puVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    uVar4 = (uint)*(byte *)((uint3)uVar2 << 0xe | (uint3)((uint)puVar1 & 0x3fff));
    uVar2 = uVar8 * 0x100;
    uVar3 = uVar8 >> 8;
    uVar8 = uVar2 + uVar4;
    uVar9 = (uVar9 << 8 | uVar3) + (uint)CARRY2(uVar2,uVar4);
    bVar6 = bVar6 + 1;
  } while (bVar6 < 4);
  if (((uVar10 - uVar9 != (uint)(uVar7 < uVar8) || uVar7 != uVar8) &&
       (uVar9 <= uVar10 && (uVar10 != uVar9 || uVar7 >= uVar8))) ||
     (uVar12 < uVar9 || uVar12 == uVar9 && uVar11 < uVar8)) {
    uVar5 = 0;
  }
  if ((uStack_12 < 0x3e9) || (9999 < uStack_12)) {
    uVar5 = 0;
  }
  if ((uStack_c < 0x3e9) || (3999 < uStack_c)) {
    uVar5 = 0;
  }
  if ((bStack_a == 0) || (99 < bStack_a)) {
    uVar5 = 0;
  }
  if (((bStack_14 & 4) != 0) || ((bStack_13 & 1) != 0)) {
    if (iStack_10 == 0) {
      uVar5 = 0;
    }
    if (iStack_e == 0) {
      uVar5 = 0;
    }
  }
  if (((bStack_14 & 1) != 0) &&
     ((((bStack_16 & 1) != 0 || ((bStack_16 & 2) != 0)) || ((bStack_16 & 0x10) != 0)))) {
    uVar5 = 0;
  }
  if (((bStack_16 & 1) != 0) && (((bStack_14 & 1) != 0 || ((bStack_16 & 0x10) != 0)))) {
    uVar5 = 0;
  }
  if (((bStack_16 & 0x10) != 0) && (((bStack_16 & 1) != 0 || ((bStack_14 & 1) != 0)))) {
    uVar5 = 0;
  }
  return uVar5;
}


