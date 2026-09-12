/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x097052; FLS offset 0x017052.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0970ea) */
/* WARNING: Removing unreachable block (ram,0x0970e4) */
/* WARNING: Removing unreachable block (ram,0x0970c6) */
/* WARNING: Removing unreachable block (ram,0x097110) */
/* WARNING: Removing unreachable block (ram,0x09710a) */
/* WARNING: Removing unreachable block (ram,0x0970f4) */
/* WARNING: Removing unreachable block (ram,0x0970ba) */
/* WARNING: Removing unreachable block (ram,0x0970b4) */
/* WARNING: Removing unreachable block (ram,0x09709e) */
/* WARNING: Removing unreachable block (ram,0x097096) */
/* WARNING: Removing unreachable block (ram,0x09708a) */
/* WARNING: Removing unreachable block (ram,0x097084) */
/* WARNING: Removing unreachable block (ram,0x0970ce) */
/* WARNING: Removing unreachable block (ram,0x09706e) */

void egs52_update_near_c161_097052(char param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  undefined1 uVar3;
  
  if (param_1 == '\0') {
    uVar1 = Ram00f038;
    iVar2 = Ram00f038;
    Ram00fe30 = iVar2 - (int)((ulong)param_2 * (ulong)uVar1 >> 0x10);
  }
  else {
    if (param_1 == '\x01') {
      uVar1 = Ram00f03a;
      iVar2 = Ram00f03a;
      Ram00fe32 = iVar2 - (int)((ulong)param_2 * (ulong)uVar1 >> 0x10);
      return;
    }
    uVar3 = (undefined1)(param_2 >> 8);
    if (param_1 == '\x02') {
      UNK_00c161 = uVar3;
      uVar1 = Ram00f03c;
      iVar2 = Ram00f03c;
      Ram00fe34 = iVar2 - (int)((ulong)param_2 * (ulong)uVar1 >> 0x10);
      return;
    }
    if (param_1 == '\x03') {
      UNK_00c162 = uVar3;
      uVar1 = Ram00f03e;
      iVar2 = Ram00f03e;
      Ram00fe36 = iVar2 - (int)((ulong)param_2 * (ulong)uVar1 >> 0x10);
      return;
    }
  }
  return;
}


