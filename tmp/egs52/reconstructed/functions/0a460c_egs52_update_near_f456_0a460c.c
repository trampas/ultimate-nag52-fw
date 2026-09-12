/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a460c; FLS offset 0x02460c.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Function: egs52_call_far_indirect replaced with injection: call_far_indirect */
/* WARNING: Removing unreachable block (ram,0x0a4634) */
/* WARNING: Removing unreachable block (ram,0x0a4630) */
/* WARNING: Removing unreachable block (ram,0x0a462c) */
/* WARNING: Removing unreachable block (ram,0x0a4628) */
/* WARNING: Removing unreachable block (ram,0x0a4624) */
/* WARNING: Removing unreachable block (ram,0x0a4620) */
/* WARNING: Removing unreachable block (ram,0x0a461c) */
/* WARNING: Removing unreachable block (ram,0x0a4616) */
/* WARNING: Removing unreachable block (ram,0x0a4612) */
/* WARNING: Removing unreachable block (ram,0x0a460c) */

void egs52_update_near_f456_0a460c(void)

{
  iRam00f456 = iRam00f464 + -1;
  iRam00f454 = iRam00f462 + -1;
  uRam00f45a = (uint)bRam00f469;
  uRam00f458 = (uint)bRam00f468;
  (*(code *)((uint3)uRam09002c << 0x10 | (uint3)uRam09002a))();
  return;
}


