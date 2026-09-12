/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0e586e; FLS offset 0x06586e.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0e58b6) */
/* WARNING: Removing unreachable block (ram,0x0e589a) */
/* WARNING: Removing unreachable block (ram,0x0e5896) */
/* WARNING: Removing unreachable block (ram,0x0e5892) */
/* WARNING: Removing unreachable block (ram,0x0e588c) */
/* WARNING: Removing unreachable block (ram,0x0e5880) */
/* WARNING: Removing unreachable block (ram,0x0e587c) */
/* WARNING: Removing unreachable block (ram,0x0e5878) */
/* WARNING: Removing unreachable block (ram,0x0e5874) */
/* WARNING: Removing unreachable block (ram,0x0e5870) */

void egs52_update_near_d524_0e586e(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  
  Ram00d524 = 0;
  iVar8 = Ram00f624;
  uVar1 = iVar8 + 10;
  uVar3 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar3 = 3;
  }
  uVar2 = iVar8 + 8;
  uVar4 = 0x24;
  if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
     (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
    uVar4 = 3;
  }
  uVar5 = Ram00d4e6;
  iVar6 = Ram00d4ec;
  uVar2 = (int)(((ulong)*(uint *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff)) * (ulong)uVar5) /
               (ulong)*(uint *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff))) + iVar6;
  uVar1 = iVar8 + 10;
  uVar3 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar3 = 3;
  }
  uVar4 = iVar8 + 8;
  uVar5 = 0x24;
  if ((((uVar4 & 0xc000) != 0) && (uVar5 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
     (uVar5 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
    uVar5 = 3;
  }
  uVar7 = Ram00d4ec;
  uVar1 = (uint)(((ulong)*(uint *)((uint3)uVar5 << 0xe | (uint3)(uVar4 & 0x3fff)) * (ulong)uVar7) /
                (ulong)*(uint *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)));
  if (uVar1 < uVar2) {
    Ram00d524 = uVar2 - uVar1;
  }
  return;
}


