/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0965b0; FLS offset 0x0165b0.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0965c4) */
/* WARNING: Removing unreachable block (ram,0x0965ba) */
/* WARNING: Removing unreachable block (ram,0x0965b6) */
/* WARNING: Removing unreachable block (ram,0x0965b0) */

void egs52_update_near_f878_0965b0(void)

{
  int iVar1;
  byte bVar2;
  
  iVar1 = Ram00f878;
  if (iVar1 != 0) {
    iVar1 = Ram00f878;
    Ram00f878 = iVar1 + -1;
    iVar1 = Ram00f878;
    if (iVar1 == 0) {
      egs52_call_0a4426_0965a8(0);
    }
  }
  bVar2 = UNK_00c1ac;
  if ((bVar2 & 0x80) == 0) {
    egs52_update_near_f5b0_0a4270();
  }
  return;
}


