/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a2504; FLS offset 0x022504.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

undefined1 egs52_call_0a13da_0a2504(void)

{
  char cVar1;
  
  cVar1 = egs52_register_sequence_0a13da();
  if (cVar1 != '\0') {
    return 0xfe;
  }
  cVar1 = egs52_call_0a1288_0a2440();
  if (cVar1 != '\0') {
    return 0xfd;
  }
  cVar1 = egs52_update_near_f850_0a2834();
  if (cVar1 != '\0') {
    return 0xfc;
  }
  cVar1 = egs52_update_near_f84e_0a16c8(1);
  if (cVar1 == '\0') {
    cVar1 = egs52_update_near_f84c_09f874();
    if (cVar1 == '\0') {
      return 0;
    }
    return 0xff;
  }
  return 0xf9;
}


