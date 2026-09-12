/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x096d68; FLS offset 0x016d68.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x096da6) */
/* WARNING: Removing unreachable block (ram,0x096da0) */
/* WARNING: Removing unreachable block (ram,0x096d9c) */
/* WARNING: Removing unreachable block (ram,0x096d88) */
/* WARNING: Removing unreachable block (ram,0x096d84) */
/* WARNING: Removing unreachable block (ram,0x096d70) */
/* WARNING: Removing unreachable block (ram,0x096db0) */
/* WARNING: Removing unreachable block (ram,0x096d74) */

void egs52_update_near_c134_096d68(void)

{
  uint uVar1;
  undefined2 uVar2;
  byte bVar3;
  byte bVar4;
  undefined2 uVar5;
  byte bVar6;
  
  uVar1 = Ram00fd00;
  if ((uVar1 & 0x800) == 0) {
    uVar1 = Ram00fd00;
    Ram00fd00 = uVar1 | 0x800;
    uVar2 = Ram00fdf2;
    egs52_call_096f56_0a41b6(0);
    uVar5 = Ram00fdf2;
    bVar6 = (char)uVar5 - (char)uVar2;
    UNK_00c134 = bVar6;
    bVar3 = UNK_00c135;
    bVar4 = UNK_00c135;
    if (bVar6 != bVar4 && bVar3 <= bVar6) {
      UNK_00c135 = bVar6;
    }
  }
  else {
    uVar1 = Ram00fdf0;
    Ram00fdf0 = uVar1 | 0x2000;
  }
  uVar1 = Ram00fd00;
  Ram00fd00 = uVar1 & 0xf7ff;
  return;
}


