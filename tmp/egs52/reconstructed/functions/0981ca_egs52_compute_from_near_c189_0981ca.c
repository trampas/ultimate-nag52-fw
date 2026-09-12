/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0981ca; FLS offset 0x0181ca.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0981de) */
/* WARNING: Removing unreachable block (ram,0x0981d2) */

undefined1 egs52_compute_from_near_c189_0981ca(char param_1)

{
  undefined1 uVar1;
  
  if (param_1 == '\x01') {
    uVar1 = UNK_00c189;
  }
  else if (param_1 == '\x02') {
    uVar1 = UNK_00c18a;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


