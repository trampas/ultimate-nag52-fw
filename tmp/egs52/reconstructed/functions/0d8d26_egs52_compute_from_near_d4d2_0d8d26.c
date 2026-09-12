/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d8d26; FLS offset 0x058d26.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d8d84) */
/* WARNING: Removing unreachable block (ram,0x0d8d7e) */
/* WARNING: Removing unreachable block (ram,0x0d8d6a) */
/* WARNING: Removing unreachable block (ram,0x0d8d64) */
/* WARNING: Removing unreachable block (ram,0x0d8d5a) */
/* WARNING: Removing unreachable block (ram,0x0d8d4a) */
/* WARNING: Removing unreachable block (ram,0x0d8d46) */
/* WARNING: Removing unreachable block (ram,0x0d8d34) */
/* WARNING: Removing unreachable block (ram,0x0d8d30) */
/* WARNING: Removing unreachable block (ram,0x0d8d2c) */
/* WARNING: Removing unreachable block (ram,0x0d8d28) */

uint egs52_compute_from_near_d4d2_0d8d26(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uStack_2;
  
  iVar1 = Ram00d4d2;
  iVar3 = Ram00d4ac;
  iVar2 = Ram00d490;
  iVar7 = Ram00d4b2;
  iVar7 = ((iVar1 + iVar3) - iVar2) - iVar7;
  if (iVar7 < 1) {
    iVar7 = 0;
  }
  bVar4 = UNK_00d4e1;
  iVar1 = Ram00d46a;
  iVar2 = Ram00d546;
  uStack_2 = (int)(((long)iVar7 * (long)iVar1) / (long)(int)(uint)bVar4) + iVar2;
  if ((int)uStack_2 < 1) {
    uStack_2 = 0;
  }
  else {
    uVar5 = Ram00d532;
    uVar6 = Ram00d532;
    if (uStack_2 == uVar6 || uStack_2 < uVar5) {
      uStack_2 = 0;
    }
    else {
      iVar7 = Ram00d532;
      uStack_2 = uStack_2 - iVar7;
    }
  }
  uVar5 = Ram00d552;
  uVar6 = Ram00d552;
  if (uStack_2 != uVar6 && uVar5 <= uStack_2) {
    uStack_2 = Ram00d552;
  }
  return uStack_2;
}


