/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0de02a; FLS offset 0x05e02a.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0de048) */
/* WARNING: Removing unreachable block (ram,0x0de042) */
/* WARNING: Removing unreachable block (ram,0x0de036) */
/* WARNING: Removing unreachable block (ram,0x0de030) */
/* WARNING: Removing unreachable block (ram,0x0de02c) */

undefined1 egs52_compute_from_near_d454_0de02a(int param_1,int param_2)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  byte bVar4;
  undefined1 uVar5;
  
  bVar2 = UNK_00d454;
  bVar4 = UNK_00d613;
  if ((bVar4 <= bVar2) || (uVar1 = Ram00fd2e, (uVar1 & 4) != 0)) {
    param_1 = param_2;
  }
  uVar5 = 3;
  iVar3 = Ram00d4c2;
  if (((iVar3 <= param_1) && (uVar1 = Ram00fd4a, (uVar1 & 0x40) == 0)) ||
     (uVar1 = Ram00fd4a, (uVar1 & 0x20) != 0)) {
    uVar5 = 4;
  }
  return uVar5;
}


