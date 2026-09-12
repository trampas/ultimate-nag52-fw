/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x099a02; FLS offset 0x019a02.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x099a18) */
/* WARNING: Removing unreachable block (ram,0x099a0a) */
/* WARNING: Removing unreachable block (ram,0x099a02) */

void egs52_update_near_c105_099a02(void)

{
  uint uVar1;
  
  if (cRam00f469 == '\x01') {
    UNK_00c105 = 0;
    egs52_call_095b6a_095abc(0xb);
    UNK_00c105 = 0xaa;
  }
  uVar1 = Ram00fdec;
  Ram00fdec = uVar1 & 0xfffe;
  return;
}


