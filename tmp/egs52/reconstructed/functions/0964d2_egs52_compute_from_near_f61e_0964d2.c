/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0964d2; FLS offset 0x0164d2.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x096508) */
/* WARNING: Removing unreachable block (ram,0x0964f8) */
/* WARNING: Removing unreachable block (ram,0x0964e2) */
/* WARNING: Removing unreachable block (ram,0x0964d8) */
/* WARNING: Removing unreachable block (ram,0x0964d2) */

undefined4 egs52_compute_from_near_f61e_0964d2(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  
  iVar9 = Ram00f61e;
  if (iVar9 != 0) {
    uVar1 = iVar9 + 0x1a;
    uVar5 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar5 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar5 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar5 = 3;
    }
    uVar2 = iVar9 + 0x1b;
    uVar6 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar6 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar6 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar6 = 3;
    }
    uVar3 = iVar9 + 0x1c;
    uVar7 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar7 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar7 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar7 = 3;
    }
    uVar4 = iVar9 + 0x1d;
    uVar8 = 0x24;
    if ((((uVar4 & 0xc000) != 0) && (uVar8 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
       (uVar8 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
      uVar8 = 3;
    }
    return CONCAT22(CONCAT11(*(undefined1 *)((uint3)uVar8 << 0xe | (uint3)(uVar4 & 0x3fff)),
                             *(undefined1 *)((uint3)uVar7 << 0xe | (uint3)(uVar3 & 0x3fff))),
                    CONCAT11(*(undefined1 *)((uint3)uVar6 << 0xe | (uint3)(uVar2 & 0x3fff)),
                             *(undefined1 *)((uint3)uVar5 << 0xe | (uint3)(uVar1 & 0x3fff))));
  }
  return 0;
}


