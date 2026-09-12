/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x093de4; FLS offset 0x013de4.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x093e08) */
/* WARNING: Removing unreachable block (ram,0x093e04) */
/* WARNING: Removing unreachable block (ram,0x093e00) */

char egs52_update_near_c040_093de4(undefined1 param_1)

{
  char cVar1;
  
  cVar1 = egs52_update_near_c34c_09e9da(param_1);
  if (cVar1 == '\0') {
    UNK_00c040 = 0;
    UNK_00c041 = 0;
    UNK_00c042 = 0;
  }
  return cVar1;
}


