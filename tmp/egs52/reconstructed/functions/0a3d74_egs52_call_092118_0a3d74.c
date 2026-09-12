/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a3d74; FLS offset 0x023d74.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Function: egs52_near_to_far_registers replaced with injection:
   egs52_near_to_far_registers */

void egs52_call_092118_0a3d74(uint param_1,ushort param_2)

{
  uint uVar1;
  
  uVar1 = 0x24;
  if ((((param_1 & 0xc000) != 0) && (uVar1 = 0x21, (param_1 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (param_1 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  egs52_crc16_a001_far(param_1 & 0x3fff | uVar1 << 0xe,uVar1 >> 2,param_2,0);
  return;
}


