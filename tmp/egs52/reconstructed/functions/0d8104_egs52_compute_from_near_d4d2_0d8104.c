/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d8104; FLS offset 0x058104.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d8154) */
/* WARNING: Removing unreachable block (ram,0x0d8140) */
/* WARNING: Removing unreachable block (ram,0x0d813a) */
/* WARNING: Removing unreachable block (ram,0x0d8130) */
/* WARNING: Removing unreachable block (ram,0x0d8120) */
/* WARNING: Removing unreachable block (ram,0x0d811c) */
/* WARNING: Removing unreachable block (ram,0x0d8116) */
/* WARNING: Removing unreachable block (ram,0x0d8112) */
/* WARNING: Removing unreachable block (ram,0x0d810e) */
/* WARNING: Removing unreachable block (ram,0x0d810a) */

void egs52_compute_from_near_d4d2_0d8104(undefined1 param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  byte bVar7;
  uint uVar8;
  int iVar9;
  undefined2 uVar10;
  undefined2 uStack_4;
  
  iVar2 = Ram00d4d2;
  iVar4 = Ram00d47c;
  iVar5 = Ram00d490;
  iVar6 = Ram00d4b2;
  bVar7 = UNK_00d4e1;
  iVar3 = Ram00d46a;
  iVar9 = Ram00d546;
  uVar1 = (int)(((long)(((iVar2 + iVar4) - iVar5) - iVar6) * (long)iVar3) / (long)(int)(uint)bVar7)
          + iVar9;
  if ((int)uVar1 < 1) {
    uStack_4 = 0;
  }
  else {
    uVar8 = Ram00d532;
    if (uVar1 < uVar8) {
      uStack_4 = 0;
    }
    else {
      uStack_4 = Ram00d532;
      uStack_4 = uVar1 - uStack_4;
    }
  }
  uVar10 = Ram00d556;
  egs52_compute_from_near_f626_0d7c4e(param_1,uVar10,uStack_4);
  return;
}


