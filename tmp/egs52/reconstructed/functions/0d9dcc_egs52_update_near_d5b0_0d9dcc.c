/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d9dcc; FLS offset 0x059dcc.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d9e34) */
/* WARNING: Removing unreachable block (ram,0x0d9e2c) */
/* WARNING: Removing unreachable block (ram,0x0d9e28) */
/* WARNING: Removing unreachable block (ram,0x0d9e24) */
/* WARNING: Removing unreachable block (ram,0x0d9e14) */
/* WARNING: Removing unreachable block (ram,0x0d9e08) */
/* WARNING: Removing unreachable block (ram,0x0d9e04) */
/* WARNING: Removing unreachable block (ram,0x0d9dfc) */
/* WARNING: Removing unreachable block (ram,0x0d9df4) */
/* WARNING: Removing unreachable block (ram,0x0d9df0) */
/* WARNING: Removing unreachable block (ram,0x0d9dec) */
/* WARNING: Removing unreachable block (ram,0x0d9de8) */
/* WARNING: Removing unreachable block (ram,0x0d9de4) */
/* WARNING: Removing unreachable block (ram,0x0d9dd4) */
/* WARNING: Removing unreachable block (ram,0x0d9dd0) */

void egs52_update_near_d5b0_0d9dcc(void)

{
  uint uVar1;
  byte bVar2;
  char cVar3;
  byte bVar4;
  byte bVar5;
  undefined1 uVar6;
  undefined2 uVar7;
  
  uVar1 = Ram00fd48;
  Ram00fd48 = uVar1 & 0xfff8;
  cVar3 = UNK_00d566;
  if (cVar3 == '\0') {
    uVar6 = egs52_update_near_d5f6_0d714e();
    UNK_00d5b0 = uVar6;
    cVar3 = UNK_00d566;
    UNK_00d566 = cVar3 + '\x01';
  }
  else if (cVar3 != '\x01') goto LAB_0d9e08;
  uVar7 = Ram00d552;
  Ram00d556 = uVar7;
  cVar3 = UNK_00d579;
  uVar7 = Ram00d556;
  uVar7 = egs52_update_near_d600_0d7cb8(cVar3 + -1,uVar7);
  Ram00d56c = uVar7;
LAB_0d9e08:
  cVar3 = UNK_00d5b0;
  if (cVar3 == '\0') {
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
    bVar4 = UNK_00d777;
    bVar5 = UNK_00d777;
    if (bVar2 == bVar5 || bVar2 < bVar4) {
      UNK_00d442 = 10;
    }
  }
  return;
}


