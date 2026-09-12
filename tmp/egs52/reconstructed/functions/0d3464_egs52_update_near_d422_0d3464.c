/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d3464; FLS offset 0x053464.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d34d8) */
/* WARNING: Removing unreachable block (ram,0x0d34cc) */
/* WARNING: Removing unreachable block (ram,0x0d34c8) */
/* WARNING: Removing unreachable block (ram,0x0d34c2) */
/* WARNING: Removing unreachable block (ram,0x0d34ba) */
/* WARNING: Removing unreachable block (ram,0x0d34a8) */
/* WARNING: Removing unreachable block (ram,0x0d34a2) */
/* WARNING: Removing unreachable block (ram,0x0d3498) */
/* WARNING: Removing unreachable block (ram,0x0d3490) */
/* WARNING: Removing unreachable block (ram,0x0d3488) */
/* WARNING: Removing unreachable block (ram,0x0d3484) */
/* WARNING: Removing unreachable block (ram,0x0d347c) */
/* WARNING: Removing unreachable block (ram,0x0d3470) */
/* WARNING: Removing unreachable block (ram,0x0d3468) */
/* WARNING: Removing unreachable block (ram,0x0d349e) */
/* WARNING: Removing unreachable block (ram,0x0d34ac) */

void egs52_update_near_d422_0d3464(void)

{
  uint uVar1;
  undefined1 uVar2;
  uint uVar3;
  byte bVar4;
  int iVar5;
  uint uVar6;
  byte bVar7;
  int iVar8;
  
  uVar2 = UNK_00d454;
  iVar5 = egs52_scale_d500_by_indexed_coefficient(uVar2);
  iVar8 = Ram00d508;
  iVar8 = iVar8 - iVar5;
  if (iVar8 < 0) {
    iVar8 = -iVar8;
  }
  iVar5 = Ram00d422;
  if (iVar5 <= iVar8) {
    Ram00d422 = iVar8;
  }
  uVar1 = Ram00fd56;
  if ((uVar1 & 0x20) == 0) {
    uVar2 = UNK_00d454;
    uVar6 = egs52_scale_d500_by_indexed_coefficient(uVar2);
    uVar1 = Ram00d508;
    if (uVar6 < uVar1) {
      iVar8 = Ram00f64a;
      uVar1 = iVar8 + 5;
      uVar6 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar6 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar6 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar6 = 3;
      }
      bVar7 = *(byte *)((uint3)uVar6 << 0xe | (uint3)(uVar1 & 0x3fff));
      goto LAB_0d34b0;
    }
  }
  iVar8 = Ram00f64a;
  uVar1 = iVar8 + 4;
  uVar6 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar6 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar6 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar6 = 3;
  }
  bVar7 = *(byte *)((uint3)uVar6 << 0xe | (uint3)(uVar1 & 0x3fff));
LAB_0d34b0:
  iVar8 = Ram00f624;
  bVar4 = UNK_00d579;
  uVar6 = iVar8 + 0xa1 + (uint)bVar4;
  uVar1 = 0x24;
  if ((((uVar6 & 0xc000) != 0) && (uVar1 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  uVar3 = Ram00d422;
  Ram00d4d8 = (int)(((ulong)*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar6 & 0x3fff)) * (ulong)uVar3)
                   / (ulong)((uint)bVar7 * 0x14));
  return;
}


