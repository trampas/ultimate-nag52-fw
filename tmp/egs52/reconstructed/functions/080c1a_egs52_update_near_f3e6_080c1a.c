/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x080c1a; FLS offset 0x000c1a.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x080c26) */
/* WARNING: Removing unreachable block (ram,0x080c22) */
/* WARNING: Removing unreachable block (ram,0x080c1e) */
/* WARNING: Removing unreachable block (ram,0x080c1a) */

void egs52_update_near_f3e6_080c1a
               (undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4)

{
  uRam00f3e6 = param_2;
  uRam00f3e8 = param_3;
  uRam00f3ea = param_1;
  uRam00f3ec = param_4;
  egs52_update_near_fdee_080960();
  return;
}


