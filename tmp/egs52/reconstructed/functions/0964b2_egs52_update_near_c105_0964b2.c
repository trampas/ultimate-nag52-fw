/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0964b2; FLS offset 0x0164b2.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0964c6) */
/* WARNING: Removing unreachable block (ram,0x0964b8) */
/* WARNING: Removing unreachable block (ram,0x0964b2) */

void egs52_update_near_c105_0964b2(void)

{
  char cVar1;
  int iVar2;
  
  cVar1 = UNK_00c105;
  if (cVar1 == '\0') {
    UNK_00c105 = 0xff;
    iVar2 = egs52_call_095b6a_095abc(0xb);
    if (iVar2 == 0) {
      UNK_00c105 = 0;
    }
  }
  return;
}


