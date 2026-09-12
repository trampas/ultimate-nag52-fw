/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x094e88; FLS offset 0x014e88.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x094ed2) */
/* WARNING: Removing unreachable block (ram,0x094ebc) */
/* WARNING: Removing unreachable block (ram,0x094eaa) */
/* WARNING: Removing unreachable block (ram,0x094ea2) */

void egs52_update_near_fd26_094e88(char param_1)

{
  undefined2 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = egs52_compute_from_near_f61e_0964d2();
  if ((uVar3 & 0x100) != 0) {
    uVar3 = Ram00fd26;
    Ram00fd26 = uVar3 | (uint)(param_1 == '\0') << 4;
    uVar3 = Ram00fd26;
    Ram00fd26 = uVar3 & 0xffef;
    uVar3 = param_1 == '\0' ^ 1;
    __write_psw_bits(0x40,uVar3 << 6);
    uVar1 = Ram00ffc4;
    uVar2 = Ram00ffc4;
    Ram00ffc4 = uVar2 & 0xfffe | uVar3;
    uVar3 = Ram00fd26;
    Ram00fd26 = uVar3 & 0xffdf;
    uVar3 = egs52_call_096f56_09c462(0xd,0);
    if (uVar3 < 0x134) {
      uVar3 = Ram00fd26;
      Ram00fd26 = uVar3 | 0x20;
    }
  }
  return;
}


