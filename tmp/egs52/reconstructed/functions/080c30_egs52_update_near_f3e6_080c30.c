/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x080c30; FLS offset 0x000c30.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x080c34) */
/* WARNING: Removing unreachable block (ram,0x080c30) */

void egs52_update_near_f3e6_080c30(undefined2 param_1,undefined2 param_2)

{
  uRam00f3e6 = param_1;
  uRam00f3e8 = param_2;
  egs52_update_near_f615_08172a(param_1,param_2,0,0);
  egs52_update_near_fdee_080b22();
  return;
}


