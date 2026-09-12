/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d9264; FLS offset 0x059264.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d92ca) */
/* WARNING: Removing unreachable block (ram,0x0d92c0) */
/* WARNING: Removing unreachable block (ram,0x0d92b8) */
/* WARNING: Removing unreachable block (ram,0x0d92b0) */
/* WARNING: Removing unreachable block (ram,0x0d92a8) */
/* WARNING: Removing unreachable block (ram,0x0d92a0) */
/* WARNING: Removing unreachable block (ram,0x0d927e) */
/* WARNING: Removing unreachable block (ram,0x0d9278) */
/* WARNING: Removing unreachable block (ram,0x0d9274) */
/* WARNING: Removing unreachable block (ram,0x0d9270) */
/* WARNING: Removing unreachable block (ram,0x0d926c) */
/* WARNING: Removing unreachable block (ram,0x0d9268) */

int egs52_compute_from_near_d4dc_0d9264(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  iVar7 = Ram00d4dc;
  iVar6 = Ram00d4bc;
  iVar4 = Ram00d492;
  uVar3 = iVar7 + iVar6 + iVar4;
  iVar7 = Ram00f638;
  uVar1 = iVar7 + 0xe;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  uVar5 = Ram00d492;
  uVar1 = (uint)(((ulong)uVar5 * 100) /
                (ulong)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)));
  if (uVar1 < uVar3) {
    iVar7 = uVar3 - uVar1;
  }
  else {
    iVar7 = 0;
  }
  uVar1 = Ram00fd48;
  if ((((uVar1 & 8) == 0) || (iVar4 = Ram00d4d0, iVar4 < 1)) &&
     ((uVar1 = Ram00fd48, (uVar1 & 0x10) == 0 || (iVar4 = Ram00d4d0, -1 < iVar4)))) {
    iVar4 = Ram00d4d2;
    iVar7 = iVar7 + iVar4 * 2;
  }
  iVar4 = Ram00d4aa;
  iVar7 = iVar7 - iVar4;
  if (iVar7 < 0) {
    iVar7 = 0;
  }
  return iVar7;
}


