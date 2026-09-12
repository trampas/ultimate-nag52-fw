/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d2856; FLS offset 0x052856.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d2894) */
/* WARNING: Removing unreachable block (ram,0x0d2888) */
/* WARNING: Removing unreachable block (ram,0x0d2884) */
/* WARNING: Removing unreachable block (ram,0x0d2880) */
/* WARNING: Removing unreachable block (ram,0x0d287c) */
/* WARNING: Removing unreachable block (ram,0x0d2878) */
/* WARNING: Removing unreachable block (ram,0x0d2874) */
/* WARNING: Removing unreachable block (ram,0x0d286a) */
/* WARNING: Removing unreachable block (ram,0x0d2866) */
/* WARNING: Removing unreachable block (ram,0x0d2856) */

void egs52_update_near_d5b0_0d2856(void)

{
  uint uVar1;
  char cVar2;
  undefined1 uVar3;
  undefined2 uVar4;
  
  cVar2 = UNK_00d566;
  if (cVar2 == '\0') {
    uVar3 = egs52_update_near_d5f6_0d5094();
    UNK_00d5b0 = uVar3;
    cVar2 = UNK_00d566;
    UNK_00d566 = cVar2 + '\x01';
  }
  else if (cVar2 != '\x01') goto LAB_0d2888;
  uVar1 = Ram00fd48;
  Ram00fd48 = uVar1 | 1;
  uVar4 = egs52_update_near_d5b8_0d4f4c();
  Ram00d56a = uVar4;
  uVar4 = Ram00d552;
  Ram00d556 = uVar4;
  uVar4 = Ram00d54c;
  Ram00d56c = uVar4;
LAB_0d2888:
  cVar2 = UNK_00d5b0;
  if (cVar2 == '\0') {
    uVar1 = Ram00fd48;
    Ram00fd48 = uVar1 & 0xfffe;
    egs52_reset_state_d437();
    UNK_00d577 = 0;
  }
  return;
}


