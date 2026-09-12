/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d8f58; FLS offset 0x058f58.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d8faa) */
/* WARNING: Removing unreachable block (ram,0x0d8f94) */
/* WARNING: Removing unreachable block (ram,0x0d8f8e) */
/* WARNING: Removing unreachable block (ram,0x0d8f88) */
/* WARNING: Removing unreachable block (ram,0x0d8f72) */
/* WARNING: Removing unreachable block (ram,0x0d8f6e) */
/* WARNING: Removing unreachable block (ram,0x0d8f68) */
/* WARNING: Removing unreachable block (ram,0x0d8f64) */
/* WARNING: Removing unreachable block (ram,0x0d8fb0) */

void egs52_compute_from_near_f63a_0d8f58(char param_1)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined2 uVar8;
  int iStack_6;
  
  bVar3 = param_1 + 4U & 7;
  iVar5 = Ram00f63a;
  uVar1 = iVar5 + 0x4c;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  uVar7 = Ram00d4d2;
  uVar6 = Ram00d46e;
  uVar4 = (uint)((ulong)uVar7 * (ulong)uVar6 >> 0x10);
  iVar5 = Ram00d54a;
  uVar1 = (int)(((ulong)uVar7 * (ulong)uVar6 & 0xffff | (ulong)uVar4 << 0x10) /
               (ulong)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff))) + iVar5;
  uVar2 = Ram00d536;
  if (uVar1 < uVar2) {
    iStack_6 = 0;
  }
  else {
    iStack_6 = Ram00d536;
    iStack_6 = uVar1 - iStack_6;
  }
  if ((bVar3 == 0) || (bVar3 == 1)) {
    uVar8 = Ram00d546;
  }
  else {
    uVar8 = Ram00d556;
  }
  egs52_compute_from_near_f626_0d7c4e(bVar3,uVar8,iStack_6,uVar4);
  return;
}


