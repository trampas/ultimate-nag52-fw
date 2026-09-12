/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a5856; FLS offset 0x025856.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a5868) */
/* WARNING: Removing unreachable block (ram,0x0a5862) */
/* WARNING: Removing unreachable block (ram,0x0a5856) */
/* WARNING: Removing unreachable block (ram,0x0a585e) */
/* WARNING: Removing unreachable block (ram,0x0a586e) */

void egs52_update_near_c1ad_0a5856(void)

{
  if (cRam00f581 != '\0') {
    UNK_00c1ad = 2;
    UNK_00c1b1 = cRam00f581;
    return;
  }
  UNK_00c1ad = cRam00f469 + -1;
  return;
}


