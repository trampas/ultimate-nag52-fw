/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a580a; FLS offset 0x02580a.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a581a) */

void egs52_compute_from_near_f581_0a580a(void)

{
  egs52_update_near_f462_0a5830();
  egs52_update_near_fdea_0a5874();
  egs52_update_near_f5b0_0a4270();
  egs52_update_near_c1ad_0a5856();
  if (cRam00f581 != '\0') {
    egs52_call_09997a_0999ca();
    return;
  }
  egs52_update_near_c2b0_0996a2();
  return;
}


