/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x097ad6; FLS offset 0x017ad6.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x097b04) */
/* WARNING: Removing unreachable block (ram,0x097afe) */

void egs52_update_near_c17a_097ad6(void)

{
  uint uVar1;
  
  Ram00fe7c = 0;
  uVar1 = Ram00ff30;
  Ram00ff30 = uVar1 & 0xfeff;
  uVar1 = Ram00ff30;
  Ram00ff30 = uVar1 & 0xfffe;
  uVar1 = Ram00ff30;
  Ram00ff30 = uVar1 & 0xffef;
  uVar1 = Ram00ff30;
  Ram00ff30 = uVar1 & 0xefff;
  uVar1 = Ram00ff32;
  Ram00ff32 = uVar1 | 1;
  uVar1 = Ram00ff32;
  Ram00ff32 = uVar1 & 0xffef;
  uVar1 = Ram00ff32;
  Ram00ff32 = uVar1 & 0xefff;
  Ram00f030 = 0;
  Ram00f038 = 24000;
  Ram00fe30 = 0;
  uVar1 = Ram00ffd0;
  Ram00ffd0 = uVar1 & 0xfffe;
  uVar1 = Ram00ffc4;
  Ram00ffc4 = uVar1 & 0xfffb;
  Ram00c17a = 4000;
  Ram00f806 = 1;
  return;
}


