/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a6336; FLS offset 0x026336.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

void egs52_update_near_f1de_0a6336(void)

{
  uint uVar1;
  
  uVar1 = Ram00f1de;
  Ram00f1de = uVar1 | 8;
  egs52_update_fault_status(0x39,2);
  return;
}


