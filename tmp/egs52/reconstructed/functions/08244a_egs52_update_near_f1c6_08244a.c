/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x08244a; FLS offset 0x00244a.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Function: egs52_boot_call_far_indirect replaced with injection: call_far_indirect */
/* WARNING: Removing unreachable block (ram,0x082468) */
/* WARNING: Removing unreachable block (ram,0x082464) */

void egs52_update_near_f1c6_08244a(void)

{
  uint uVar1;
  
  uVar1 = Ram00fdee;
  if ((uVar1 & 1) == 0) {
    (*(code *)((uint3)uRam09009c << 0x10 | (uint3)uRam09009a))();
    return;
  }
  uVar1 = Ram00ffc4;
  Ram00ffc4 = uVar1 | 0x400;
  uVar1 = Ram00f1c6;
  Ram00f1c6 = uVar1 & 0xfbff;
  uVar1 = Ram00ffc6;
  Ram00ffc6 = uVar1 | 0x400;
  Ram00feb4 = 0xea5;
  Ram00ffb0 = 0x8011;
  Ram00ff6e = 0x4d;
  return;
}


