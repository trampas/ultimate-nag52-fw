/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a463e; FLS offset 0x02463e.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a4672) */
/* WARNING: Removing unreachable block (ram,0x0a466c) */
/* WARNING: Removing unreachable block (ram,0x0a4664) */
/* WARNING: Removing unreachable block (ram,0x0a465a) */
/* WARNING: Removing unreachable block (ram,0x0a4656) */
/* WARNING: Removing unreachable block (ram,0x0a4652) */
/* WARNING: Removing unreachable block (ram,0x0a464e) */
/* WARNING: Removing unreachable block (ram,0x0a464a) */
/* WARNING: Removing unreachable block (ram,0x0a4646) */
/* WARNING: Removing unreachable block (ram,0x0a4642) */
/* WARNING: Removing unreachable block (ram,0x0a463e) */

void egs52_update_near_f878_0a463e(void)

{
  Ram00f878 = uRam00f574;
  uRam00f572 = 0;
  uRam00f456 = uRam00f454;
  bRam00f469 = bRam00f46a;
  if (cRam00f581 == 'x') {
    iRam00f464 = iRam00f464 - (uint)bRam00f46a;
    uRam00f444 = 3;
  }
  return;
}


