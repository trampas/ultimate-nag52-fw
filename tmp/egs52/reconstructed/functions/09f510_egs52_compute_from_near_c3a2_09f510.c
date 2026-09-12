/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x09f510; FLS offset 0x01f510.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Function: egs52_divide_s32_registers replaced with injection: egs52_sdiv32_registers */
/* WARNING: Function: egs52_multiply_u32_registers replaced with injection: egs52_mul32_registers */
/* WARNING: Removing unreachable block (ram,0x09f512) */

int egs52_compute_from_near_c3a2_09f510(uint param_1,int param_2,uint param_3)

{
  long lVar1;
  ulong uVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  
  bVar3 = UNK_00c3a2;
  if ((bVar3 & 4) == 0) {
    uVar2 = ((ulong)param_1 * 0xe61) / 0x100;
  }
  else {
    lVar1 = (long)((long)param_2 * (ulong)param_1) / 0x100;
    uVar5 = (uint)lVar1;
    uVar2 = CONCAT22((int)((ulong)lVar1 >> 0x10) + ((int)param_3 >> 0xf) +
                     (uint)CARRY2(uVar5,param_3),uVar5 + param_3);
  }
  uVar5 = (uint)(uVar2 >> 0x10);
  iVar4 = (int)uVar2;
  if (uVar5 == (iVar4 != -1) && iVar4 == -1 || (int)uVar5 < (int)(uint)(iVar4 != -1)) {
    if ((long)uVar2 < 0) {
      iVar4 = 0;
    }
  }
  else {
    iVar4 = -1;
  }
  return iVar4;
}


