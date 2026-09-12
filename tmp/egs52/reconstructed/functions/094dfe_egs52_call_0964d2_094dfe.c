/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x094dfe; FLS offset 0x014dfe.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

void egs52_call_0964d2_094dfe(uint param_1)

{
  undefined2 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = egs52_compute_from_near_f61e_0964d2(param_1);
  if ((uVar3 & 0x200) != 0) {
    uVar3 = (param_1 & 0xff) == 0 ^ 1;
    __write_psw_bits(0x40,uVar3 << 6);
    uVar1 = Ram00ffc0;
    uVar2 = Ram00ffc0;
    Ram00ffc0 = uVar2 & 0xefff | uVar3 << 0xc;
  }
  return;
}


