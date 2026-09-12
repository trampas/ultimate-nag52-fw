/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d40b6; FLS offset 0x0540b6.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d40f8) */
/* WARNING: Removing unreachable block (ram,0x0d40f2) */
/* WARNING: Removing unreachable block (ram,0x0d40ee) */
/* WARNING: Removing unreachable block (ram,0x0d40e0) */
/* WARNING: Removing unreachable block (ram,0x0d40dc) */
/* WARNING: Removing unreachable block (ram,0x0d40d8) */
/* WARNING: Removing unreachable block (ram,0x0d40d4) */
/* WARNING: Removing unreachable block (ram,0x0d40d0) */
/* WARNING: Removing unreachable block (ram,0x0d40cc) */
/* WARNING: Removing unreachable block (ram,0x0d40b6) */

void egs52_update_near_d5b0_0d40b6(void)

{
  uint uVar1;
  char cVar2;
  undefined1 uVar3;
  
  cVar2 = UNK_00d566;
  if (cVar2 == '\0') {
    uVar1 = Ram00fd48;
    Ram00fd48 = uVar1 & 0xfffe;
    uVar1 = Ram00fd48;
    Ram00fd48 = uVar1 | 2;
    uVar1 = Ram00fd48;
    Ram00fd48 = uVar1 | 4;
    uVar3 = egs52_update_near_d5f6_0d5094();
    UNK_00d5b0 = uVar3;
    cVar2 = UNK_00d566;
    UNK_00d566 = cVar2 + '\x01';
  }
  else if (cVar2 != '\x01') {
    return;
  }
  Ram00d556 = 0;
  Ram00d56c = 0;
  Ram00d56a = 0;
  cVar2 = UNK_00d5b0;
  if (cVar2 == '\0') {
    uVar1 = Ram00fd48;
    Ram00fd48 = uVar1 & 0xfffe;
    uVar1 = Ram00fd48;
    Ram00fd48 = uVar1 & 0xfffd;
    uVar1 = Ram00fd48;
    Ram00fd48 = uVar1 & 0xfffb;
    uVar1 = Ram00fd3a;
    Ram00fd3a = uVar1 | 0x10;
    UNK_00d566 = 0;
    UNK_00d567 = 0;
    UNK_00d437 = 1;
  }
  return;
}


