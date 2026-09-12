/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x08112c; FLS offset 0x00112c.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x081134) */
/* WARNING: Removing unreachable block (ram,0x081130) */

uint egs52_register_sequence_08112c(void)

{
  uint uVar1;
  
  if ((uRam090000 == 0x4890) && (iRam090002 == 0x4224)) {
    uVar1 = 0x4801;
  }
  else if ((uRam090000 == 0xffff) && (iRam090002 == -1)) {
    uVar1 = 0xff02;
  }
  else {
    uVar1 = uRam090000 & 0xff00;
  }
  return uVar1;
}


