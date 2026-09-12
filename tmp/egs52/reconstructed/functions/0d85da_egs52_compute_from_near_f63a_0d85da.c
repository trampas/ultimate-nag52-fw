/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d85da; FLS offset 0x0585da.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d862e) */
/* WARNING: Removing unreachable block (ram,0x0d8628) */
/* WARNING: Removing unreachable block (ram,0x0d861a) */
/* WARNING: Removing unreachable block (ram,0x0d8614) */
/* WARNING: Removing unreachable block (ram,0x0d8610) */
/* WARNING: Removing unreachable block (ram,0x0d8606) */
/* WARNING: Removing unreachable block (ram,0x0d8600) */
/* WARNING: Removing unreachable block (ram,0x0d85fc) */
/* WARNING: Removing unreachable block (ram,0x0d85e8) */
/* WARNING: Removing unreachable block (ram,0x0d85e4) */
/* WARNING: Removing unreachable block (ram,0x0d85de) */
/* WARNING: Removing unreachable block (ram,0x0d85da) */

uint egs52_compute_from_near_f63a_0d85da(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  iVar1 = Ram00f63a;
  uVar4 = iVar1 + 0x4c;
  uVar5 = 0x24;
  if ((((uVar4 & 0xc000) != 0) && (uVar5 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
     (uVar5 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
    uVar5 = 3;
  }
  uVar2 = Ram00d46e;
  uVar3 = Ram00d4d2;
  iVar1 = Ram00d54a;
  uVar4 = (int)(((ulong)uVar2 * (ulong)uVar3) /
               (ulong)*(byte *)((uint3)uVar5 << 0xe | (uint3)(uVar4 & 0x3fff))) + iVar1;
  uVar5 = Ram00d536;
  uVar2 = Ram00d536;
  if (uVar4 == uVar2 || uVar4 < uVar5) {
    uVar4 = 0;
  }
  else {
    iVar1 = Ram00d536;
    uVar4 = uVar4 - iVar1;
  }
  uVar5 = Ram00d550;
  uVar2 = Ram00d536;
  uVar3 = Ram00d536;
  if (uVar5 == uVar3 || uVar5 < uVar2) {
    uVar5 = 0;
  }
  else {
    iVar1 = Ram00d536;
    uVar5 = uVar5 - iVar1;
  }
  if (uVar5 <= uVar4) {
    uVar5 = uVar4;
  }
  uVar4 = Ram00d552;
  uVar2 = Ram00d552;
  if (uVar5 != uVar2 && uVar4 <= uVar5) {
    uVar5 = Ram00d552;
  }
  return uVar5;
}


