/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d8ea2; FLS offset 0x058ea2.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d8f44) */
/* WARNING: Removing unreachable block (ram,0x0d8f3e) */
/* WARNING: Removing unreachable block (ram,0x0d8f28) */
/* WARNING: Removing unreachable block (ram,0x0d8f1c) */
/* WARNING: Removing unreachable block (ram,0x0d8f0a) */
/* WARNING: Removing unreachable block (ram,0x0d8f04) */
/* WARNING: Removing unreachable block (ram,0x0d8efe) */
/* WARNING: Removing unreachable block (ram,0x0d8eea) */
/* WARNING: Removing unreachable block (ram,0x0d8ee4) */
/* WARNING: Removing unreachable block (ram,0x0d8ec4) */
/* WARNING: Removing unreachable block (ram,0x0d8ec0) */
/* WARNING: Removing unreachable block (ram,0x0d8eae) */
/* WARNING: Removing unreachable block (ram,0x0d8eaa) */

uint egs52_compute_from_near_d4d2_0d8ea2(uint param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  uint uStack_6;
  
  iVar2 = Ram00d4d2;
  iVar3 = Ram00d4ae;
  uStack_6 = iVar2 - iVar3;
  if ((int)uStack_6 < 0) {
    uStack_6 = 0;
  }
  bVar4 = UNK_00d4df;
  uVar6 = Ram00d4bc;
  uVar6 = (uint)(((ulong)bVar4 * (ulong)uVar6) / 100);
  if (uStack_6 < uVar6) {
    uStack_6 = 0;
  }
  else {
    uStack_6 = uStack_6 - uVar6;
  }
  bVar4 = UNK_00d4e1;
  uVar6 = Ram00d46a;
  iVar2 = Ram00d546;
  uStack_6 = (int)(((ulong)uStack_6 * (ulong)uVar6) / (ulong)bVar4) + iVar2;
  uVar6 = Ram00d532;
  uVar1 = Ram00d532;
  if (uStack_6 == uVar1 || uStack_6 < uVar6) {
    uStack_6 = 0;
  }
  else {
    iVar2 = Ram00d532;
    uStack_6 = uStack_6 - iVar2;
  }
  iVar2 = Ram00f634;
  uVar1 = iVar2 + 0x16 + (param_1 & 0xff);
  uVar6 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar6 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar6 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar6 = 3;
  }
  uVar6 = (uint)(((ulong)uStack_6 * (ulong)*(byte *)((uint3)uVar6 << 0xe | (uint3)(uVar1 & 0x3fff)))
                / 100);
  uVar1 = Ram00d552;
  uVar5 = Ram00d552;
  if (uVar6 != uVar5 && uVar1 <= uVar6) {
    uVar6 = Ram00d552;
  }
  return uVar6;
}


