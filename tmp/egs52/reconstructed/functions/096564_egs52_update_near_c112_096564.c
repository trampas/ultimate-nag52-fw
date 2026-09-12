/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x096564; FLS offset 0x016564.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x09658e) */
/* WARNING: Removing unreachable block (ram,0x09657c) */
/* WARNING: Removing unreachable block (ram,0x096574) */
/* WARNING: Removing unreachable block (ram,0x0965a2) */
/* WARNING: Removing unreachable block (ram,0x09659c) */
/* WARNING: Removing unreachable block (ram,0x096598) */
/* WARNING: Removing unreachable block (ram,0x09656c) */
/* WARNING: Removing unreachable block (ram,0x096564) */
/* WARNING: Removing unreachable block (ram,0x096594) */
/* WARNING: Removing unreachable block (ram,0x096578) */

void egs52_update_near_c112_096564(void)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  
  bVar1 = UNK_00c1ac;
  if ((bVar1 & 0x80) == 0) {
    bVar1 = UNK_00f802;
    if ((bVar1 & 1) == 0) {
      uVar4 = Ram00fdf2;
      Ram00c112 = uVar4;
      Ram00c110 = uVar4;
      bVar1 = UNK_00f802;
      UNK_00f802 = bVar1 | 1;
    }
    else {
      iVar3 = Ram00fdf2;
      Ram00c112 = iVar3;
      iVar2 = Ram00c110;
      if (999 < (uint)(iVar3 - iVar2)) {
        egs52_update_near_f402_09ff9a();
        bVar1 = UNK_00f802;
        UNK_00f802 = bVar1 & 0xfe;
        return;
      }
    }
  }
  return;
}


