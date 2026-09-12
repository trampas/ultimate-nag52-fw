/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x09c448; FLS offset 0x01c448.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

void egs52_call_096eec_09c448(void)

{
  byte bVar1;
  
  egs52_update_near_fd00_096eec();
  bVar1 = 0;
  do {
    egs52_transform_memory_09c652(bVar1);
    bVar1 = bVar1 + 1;
  } while (bVar1 < 0xe);
  return;
}


