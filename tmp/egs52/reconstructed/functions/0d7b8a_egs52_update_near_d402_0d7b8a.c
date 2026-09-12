/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d7b8a; FLS offset 0x057b8a.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d7bb8) */
/* WARNING: Removing unreachable block (ram,0x0d7bb4) */
/* WARNING: Removing unreachable block (ram,0x0d7bac) */
/* WARNING: Removing unreachable block (ram,0x0d7ba8) */
/* WARNING: Removing unreachable block (ram,0x0d7b94) */
/* WARNING: Removing unreachable block (ram,0x0d7b90) */

void egs52_update_near_d402_0d7b8a(void)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  bVar1 = UNK_00d4df;
  uVar4 = Ram00d492;
  iVar3 = Ram00d4ae;
  uVar4 = (int)(((ulong)bVar1 * (ulong)uVar4) / 100) + iVar3;
  uVar2 = Ram00d490;
  if (uVar2 <= uVar4) {
    uVar4 = Ram00d490;
  }
  Ram00d402 = uVar4;
  return;
}


