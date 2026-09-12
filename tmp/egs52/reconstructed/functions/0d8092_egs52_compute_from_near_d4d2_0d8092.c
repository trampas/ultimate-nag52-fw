/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d8092; FLS offset 0x058092.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d80f2) */
/* WARNING: Removing unreachable block (ram,0x0d80e4) */
/* WARNING: Removing unreachable block (ram,0x0d80de) */
/* WARNING: Removing unreachable block (ram,0x0d80d8) */
/* WARNING: Removing unreachable block (ram,0x0d80c4) */
/* WARNING: Removing unreachable block (ram,0x0d80be) */
/* WARNING: Removing unreachable block (ram,0x0d80b2) */
/* WARNING: Removing unreachable block (ram,0x0d80ac) */
/* WARNING: Removing unreachable block (ram,0x0d809c) */
/* WARNING: Removing unreachable block (ram,0x0d8098) */

void egs52_compute_from_near_d4d2_0d8092(undefined1 param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  byte bVar4;
  uint uVar5;
  undefined2 uVar6;
  undefined2 uStack_4;
  
  iVar1 = Ram00d4d2;
  iVar3 = Ram00d47c;
  uStack_4 = iVar1 + iVar3;
  if ((int)uStack_4 < 0) {
    uStack_4 = 0;
  }
  uVar2 = Ram00d490;
  if (uStack_4 < uVar2) {
    uStack_4 = 0;
  }
  else {
    iVar1 = Ram00d490;
    uStack_4 = uStack_4 - iVar1;
  }
  bVar4 = UNK_00d4e1;
  uVar2 = Ram00d46a;
  iVar1 = Ram00d546;
  uStack_4 = (int)(((ulong)uStack_4 * (ulong)uVar2) / (ulong)bVar4) + iVar1;
  uVar2 = Ram00d532;
  uVar5 = Ram00d532;
  if (uStack_4 == uVar5 || uStack_4 < uVar2) {
    uStack_4 = 0;
  }
  else {
    iVar1 = Ram00d532;
    uStack_4 = uStack_4 - iVar1;
  }
  uVar6 = Ram00d556;
  egs52_compute_from_near_f626_0d7c4e(param_1,uVar6,uStack_4);
  return;
}


