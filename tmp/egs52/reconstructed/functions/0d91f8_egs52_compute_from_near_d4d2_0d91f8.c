/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d91f8; FLS offset 0x0591f8.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d9252) */
/* WARNING: Removing unreachable block (ram,0x0d9244) */
/* WARNING: Removing unreachable block (ram,0x0d923e) */
/* WARNING: Removing unreachable block (ram,0x0d9238) */
/* WARNING: Removing unreachable block (ram,0x0d9220) */
/* WARNING: Removing unreachable block (ram,0x0d921a) */
/* WARNING: Removing unreachable block (ram,0x0d920a) */
/* WARNING: Removing unreachable block (ram,0x0d9206) */
/* WARNING: Removing unreachable block (ram,0x0d9202) */

void egs52_compute_from_near_d4d2_0d91f8(char param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  byte bVar6;
  undefined2 uVar7;
  undefined2 uStack_4;
  
  iVar2 = Ram00d4d2;
  iVar5 = Ram00d4da;
  iVar4 = Ram00d4ac;
  uVar1 = iVar2 + iVar5 + iVar4;
  if ((int)uVar1 < 0) {
    uStack_4 = 0;
  }
  else {
    bVar6 = UNK_00d4e1;
    uVar3 = Ram00d46e;
    uStack_4 = (int)(((ulong)uVar1 * (ulong)uVar3) / (ulong)bVar6);
  }
  iVar2 = Ram00d54a;
  uVar1 = Ram00d536;
  if ((uint)(uStack_4 + iVar2) < uVar1) {
    uStack_4 = 0;
  }
  else {
    iVar4 = Ram00d536;
    uStack_4 = (uStack_4 + iVar2) - iVar4;
  }
  uVar7 = Ram00d546;
  egs52_compute_from_near_f626_0d7c4e(param_1 + 4U & 7,uVar7,uStack_4);
  return;
}


