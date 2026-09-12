/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d405a; FLS offset 0x05405a.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d40a2) */
/* WARNING: Removing unreachable block (ram,0x0d409e) */
/* WARNING: Removing unreachable block (ram,0x0d409a) */
/* WARNING: Removing unreachable block (ram,0x0d4096) */
/* WARNING: Removing unreachable block (ram,0x0d4092) */
/* WARNING: Removing unreachable block (ram,0x0d407e) */
/* WARNING: Removing unreachable block (ram,0x0d4072) */
/* WARNING: Removing unreachable block (ram,0x0d406e) */
/* WARNING: Removing unreachable block (ram,0x0d406a) */
/* WARNING: Removing unreachable block (ram,0x0d4066) */
/* WARNING: Removing unreachable block (ram,0x0d405e) */

void egs52_update_near_d56a_0d405a(void)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  undefined2 uVar5;
  
  uVar1 = Ram00fd48;
  Ram00fd48 = uVar1 & 0xfff8;
  Ram00d56a = 0x13ec;
  uVar5 = Ram00d552;
  Ram00d556 = uVar5;
  cVar3 = UNK_00d579;
  uVar5 = egs52_update_near_d600_0d7cb8(cVar3 + -1);
  Ram00d56c = uVar5;
  egs52_update_near_fd48_0d6c32();
  egs52_reset_state_d5b0();
  egs52_reset_state_d437();
  uVar1 = Ram00fd3a;
  Ram00fd3a = uVar1 & 0xfffe;
  uVar1 = Ram00fd5a;
  Ram00fd5a = uVar1 & 0xfeff;
  UNK_00d577 = 0;
  iVar4 = Ram00f648;
  uVar1 = iVar4 + 0xd;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  UNK_00d5b0 = *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
  cVar3 = UNK_00d613;
  if (cVar3 != '\a') {
    uVar1 = Ram00fd3c;
    Ram00fd3c = uVar1 | 4;
    uVar1 = Ram00fd3c;
    Ram00fd3c = uVar1 & 0xfff7;
    return;
  }
  uVar1 = Ram00fd3c;
  Ram00fd3c = uVar1 & 0xfffb;
  uVar1 = Ram00fd3c;
  Ram00fd3c = uVar1 | 8;
  return;
}


