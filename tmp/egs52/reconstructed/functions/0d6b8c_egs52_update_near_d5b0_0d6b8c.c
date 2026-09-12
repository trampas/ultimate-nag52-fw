/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d6b8c; FLS offset 0x056b8c.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d6be8) */
/* WARNING: Removing unreachable block (ram,0x0d6be0) */
/* WARNING: Removing unreachable block (ram,0x0d6bdc) */
/* WARNING: Removing unreachable block (ram,0x0d6bd8) */
/* WARNING: Removing unreachable block (ram,0x0d6bc8) */
/* WARNING: Removing unreachable block (ram,0x0d6bbc) */
/* WARNING: Removing unreachable block (ram,0x0d6bb8) */
/* WARNING: Removing unreachable block (ram,0x0d6bb4) */
/* WARNING: Removing unreachable block (ram,0x0d6bb0) */
/* WARNING: Removing unreachable block (ram,0x0d6bac) */
/* WARNING: Removing unreachable block (ram,0x0d6ba8) */
/* WARNING: Removing unreachable block (ram,0x0d6ba4) */
/* WARNING: Removing unreachable block (ram,0x0d6b94) */
/* WARNING: Removing unreachable block (ram,0x0d6b90) */

void egs52_update_near_d5b0_0d6b8c(void)

{
  uint uVar1;
  byte bVar2;
  undefined2 uVar3;
  char cVar4;
  byte bVar5;
  byte bVar6;
  undefined1 uVar7;
  
  uVar1 = Ram00fd48;
  Ram00fd48 = uVar1 & 0xfff8;
  cVar4 = UNK_00d566;
  if (cVar4 == '\0') {
    uVar7 = egs52_update_near_d5f6_0d714e();
    UNK_00d5b0 = uVar7;
    cVar4 = UNK_00d566;
    UNK_00d566 = cVar4 + '\x01';
  }
  else if (cVar4 != '\x01') goto LAB_0d6bbc;
  Ram00d556 = 0;
  Ram00d56c = 0;
  uVar3 = Ram00d54c;
  Ram00d56a = uVar3;
LAB_0d6bbc:
  cVar4 = UNK_00d5b0;
  if (cVar4 == '\0') {
    uVar1 = Ram00fd4a;
    Ram00fd4a = uVar1 & 0xffbf;
    uVar1 = Ram00fd4a;
    Ram00fd4a = uVar1 & 0xffdf;
    uVar1 = Ram00fd4e;
    Ram00fd4e = uVar1 & 0xfffb;
    UNK_00d590 = 0;
    egs52_update_near_fd48_0d6c32();
    egs52_reset_state_d5b0();
    egs52_reset_state_d437();
    UNK_00d577 = 0;
    bVar2 = UNK_00d454;
    bVar5 = UNK_00d777;
    bVar6 = UNK_00d777;
    if (bVar2 == bVar6 || bVar2 < bVar5) {
      UNK_00d442 = 10;
    }
  }
  return;
}


