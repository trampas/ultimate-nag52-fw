/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d9176; FLS offset 0x059176.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d91da) */
/* WARNING: Removing unreachable block (ram,0x0d91d4) */
/* WARNING: Removing unreachable block (ram,0x0d91ce) */
/* WARNING: Removing unreachable block (ram,0x0d91b6) */
/* WARNING: Removing unreachable block (ram,0x0d91b0) */
/* WARNING: Removing unreachable block (ram,0x0d919e) */
/* WARNING: Removing unreachable block (ram,0x0d919a) */
/* WARNING: Removing unreachable block (ram,0x0d9196) */
/* WARNING: Removing unreachable block (ram,0x0d9190) */
/* WARNING: Removing unreachable block (ram,0x0d9184) */
/* WARNING: Removing unreachable block (ram,0x0d9180) */
/* WARNING: Removing unreachable block (ram,0x0d918a) */

void egs52_compute_from_near_d4dc_0d9176(char param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  byte bVar7;
  int iVar8;
  undefined2 uStack_4;
  
  uVar1 = Ram00d4dc;
  uVar2 = Ram00d4da;
  uVar6 = Ram00d4da;
  if (uVar1 == uVar6 || uVar1 < uVar2) {
    iVar8 = Ram00d4da;
  }
  else {
    iVar8 = Ram00d4dc;
  }
  iVar5 = Ram00d4d2;
  iVar3 = Ram00d492;
  iVar4 = Ram00d4ac;
  uVar1 = iVar5 + iVar3 + iVar4 + iVar8;
  if ((int)uVar1 < 0) {
    uStack_4 = 0;
  }
  else {
    bVar7 = UNK_00d4e1;
    uVar2 = Ram00d46e;
    uStack_4 = (int)(((ulong)uVar1 * (ulong)uVar2) / (ulong)bVar7);
  }
  iVar8 = Ram00d54a;
  uVar1 = Ram00d536;
  if ((uint)(uStack_4 + iVar8) < uVar1) {
    uStack_4 = 0;
  }
  else {
    iVar3 = Ram00d536;
    uStack_4 = (uStack_4 + iVar8) - iVar3;
  }
  egs52_compute_from_near_f626_0d7c4e(param_1 + 4U & 7,0,uStack_4);
  return;
}


