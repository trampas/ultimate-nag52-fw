/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d1498; FLS offset 0x051498.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d14fe) */
/* WARNING: Removing unreachable block (ram,0x0d1510) */
/* WARNING: Removing unreachable block (ram,0x0d14e2) */
/* WARNING: Removing unreachable block (ram,0x0d14dc) */
/* WARNING: Removing unreachable block (ram,0x0d14d0) */
/* WARNING: Removing unreachable block (ram,0x0d14cc) */
/* WARNING: Removing unreachable block (ram,0x0d14b2) */
/* WARNING: Removing unreachable block (ram,0x0d14a2) */
/* WARNING: Removing unreachable block (ram,0x0d150a) */

void egs52_update_near_d431_0d1498(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined1 uVar6;
  byte bVar7;
  ushort uVar8;
  ushort uVar9;
  uint uVar10;
  
  uVar6 = UNK_00d577;
  uVar8 = egs52_compute_from_near_d579_0d42a6(uVar6);
  uVar8 = egs52_sqrt_estimate_u16(uVar8);
  uVar6 = UNK_00d577;
  uVar9 = egs52_update_near_d426_0d4338(uVar6);
  uVar9 = egs52_sqrt_estimate_u16(uVar9);
  uVar10 = egs52_update_near_d430_0d718c();
  iVar5 = Ram00f636;
  uVar1 = iVar5 + 0x22;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  bVar7 = UNK_00d477;
  uVar4 = iVar5 + 0x23 + (uint)bVar7;
  uVar3 = 0x24;
  if ((((uVar4 & 0xc000) != 0) && (uVar3 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
     (uVar3 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
    uVar3 = 3;
  }
  iVar5 = (int)(((long)(int)uVar9 *
                (long)(int)((((param_1 & 0xff) - (uVar10 & 0xff)) -
                            (uint)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff))) -
                           (uint)(*(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar4 & 0x3fff)) >> 1))) /
               (long)(int)uVar8);
  if (iVar5 == 0) {
    UNK_00d431 = 0;
  }
  else if (iVar5 < 1) {
    UNK_00d431 = 0xff;
  }
  else {
    UNK_00d431 = 1;
  }
  return;
}


