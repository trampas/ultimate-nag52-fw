/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0829c6; FLS offset 0x0029c6.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0829fa) */
/* WARNING: Removing unreachable block (ram,0x0829f4) */
/* WARNING: Removing unreachable block (ram,0x0829ec) */
/* WARNING: Removing unreachable block (ram,0x0829e2) */
/* WARNING: Removing unreachable block (ram,0x0829de) */
/* WARNING: Removing unreachable block (ram,0x0829da) */
/* WARNING: Removing unreachable block (ram,0x0829d6) */
/* WARNING: Removing unreachable block (ram,0x0829d2) */
/* WARNING: Removing unreachable block (ram,0x0829ce) */
/* WARNING: Removing unreachable block (ram,0x0829ca) */
/* WARNING: Removing unreachable block (ram,0x0829c6) */

void egs52_update_near_f5b2_0829c6(void)

{
  uRam00f5b2 = uRam00f574;
  uRam00f572 = 0;
  uRam00f456 = uRam00f454;
  bRam00f469 = bRam00f46a;
  if (cRam00f581 == 'x') {
    iRam00f464 = iRam00f464 - (uint)bRam00f46a;
    uRam00f444 = 3;
  }
  return;
}


