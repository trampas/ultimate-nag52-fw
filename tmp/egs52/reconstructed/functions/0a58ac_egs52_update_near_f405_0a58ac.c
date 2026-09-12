/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a58ac; FLS offset 0x0258ac.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a58c0) */
/* WARNING: Removing unreachable block (ram,0x0a58bc) */

void egs52_update_near_f405_0a58ac(void)

{
  uint uVar1;
  
  egs52_disable_interrupts_save();
  egs52_compute_from_near_cace_0a47c0();
  egs52_compute_from_near_c116_096786();
  egs52_call_097b0a_09655e();
  uRam00f405 = 0;
  uRam00f407 = 0;
  egs52_update_near_c170_097634(0);
  egs52_update_near_c1aa_0994da();
  egs52_service_watchdog(0xe001);
  uVar1 = Ram00fdee;
  Ram00fdee = uVar1 | 1;
  return;
}


