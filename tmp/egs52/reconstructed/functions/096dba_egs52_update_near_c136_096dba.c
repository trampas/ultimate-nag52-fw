/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x096dba; FLS offset 0x016dba.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x096df8) */
/* WARNING: Removing unreachable block (ram,0x096df2) */
/* WARNING: Removing unreachable block (ram,0x096dee) */
/* WARNING: Removing unreachable block (ram,0x096dda) */
/* WARNING: Removing unreachable block (ram,0x096dd6) */
/* WARNING: Removing unreachable block (ram,0x096dc2) */
/* WARNING: Removing unreachable block (ram,0x096e02) */
/* WARNING: Removing unreachable block (ram,0x096dc6) */

void egs52_update_near_c136_096dba(void)

{
  uint uVar1;
  undefined2 uVar2;
  byte bVar3;
  byte bVar4;
  undefined2 uVar5;
  byte bVar6;
  
  uVar1 = Ram00fd00;
  if ((uVar1 & 0x1000) == 0) {
    uVar1 = Ram00fd00;
    Ram00fd00 = uVar1 | 0x1000;
    uVar2 = Ram00fdf2;
    egs52_register_sequence_0d01a8(0);
    uVar5 = Ram00fdf2;
    bVar6 = (char)uVar5 - (char)uVar2;
    UNK_00c136 = bVar6;
    bVar3 = UNK_00c137;
    bVar4 = UNK_00c137;
    if (bVar6 != bVar4 && bVar3 <= bVar6) {
      UNK_00c137 = bVar6;
    }
  }
  else {
    uVar1 = Ram00fdf0;
    Ram00fdf0 = uVar1 | 0x2000;
  }
  uVar1 = Ram00fd00;
  Ram00fd00 = uVar1 & 0xefff;
  return;
}


