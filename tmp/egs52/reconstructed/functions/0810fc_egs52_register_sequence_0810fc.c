/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0810fc; FLS offset 0x0010fc.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x081104) */
/* WARNING: Removing unreachable block (ram,0x081100) */

undefined1 egs52_register_sequence_0810fc(void)

{
  if ((iRam0b0000 == 0x2442) && (iRam0b0002 == -0x6fb8)) {
    return 1;
  }
  if ((iRam0b0000 == -1) && (iRam0b0002 == -1)) {
    return 2;
  }
  return 0;
}


