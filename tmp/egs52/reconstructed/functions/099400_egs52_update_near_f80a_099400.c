/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x099400; FLS offset 0x019400.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x099418) */
/* WARNING: Removing unreachable block (ram,0x09940a) */

void egs52_update_near_f80a_099400(void)

{
  char cVar1;
  
  egs52_update_fault_status(0x3b,2);
  cVar1 = UNK_00fdfb;
  if (cVar1 == 'i') {
    UNK_00f80a = 0x69;
  }
  return;
}


