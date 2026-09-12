/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d7e30; FLS offset 0x057e30.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d7e5c) */
/* WARNING: Removing unreachable block (ram,0x0d7e56) */
/* WARNING: Removing unreachable block (ram,0x0d7e50) */
/* WARNING: Removing unreachable block (ram,0x0d7e46) */
/* WARNING: Removing unreachable block (ram,0x0d7e40) */
/* WARNING: Removing unreachable block (ram,0x0d7e36) */
/* WARNING: Removing unreachable block (ram,0x0d7e30) */

uint egs52_compute_from_near_d54a_0d7e30(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  iVar1 = Ram00d54a;
  uVar5 = Ram00d536;
  if ((uint)(param_1 + iVar1) < uVar5) {
    uVar5 = 0;
  }
  else {
    iVar3 = Ram00d536;
    uVar5 = (param_1 + iVar1) - iVar3;
    uVar2 = Ram00d42a;
    if (uVar5 < uVar2) {
      uVar5 = 0;
    }
    else {
      iVar1 = Ram00d42a;
      uVar5 = uVar5 - iVar1;
    }
  }
  uVar2 = Ram00d552;
  uVar4 = Ram00d552;
  if (uVar5 != uVar4 && uVar2 <= uVar5) {
    uVar5 = Ram00d552;
  }
  return uVar5;
}


