/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d6ac2; FLS offset 0x056ac2.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d6b84) */
/* WARNING: Removing unreachable block (ram,0x0d6b80) */
/* WARNING: Removing unreachable block (ram,0x0d6b7a) */
/* WARNING: Removing unreachable block (ram,0x0d6b76) */
/* WARNING: Removing unreachable block (ram,0x0d6b6c) */
/* WARNING: Removing unreachable block (ram,0x0d6b68) */
/* WARNING: Removing unreachable block (ram,0x0d6b5e) */
/* WARNING: Removing unreachable block (ram,0x0d6b4a) */
/* WARNING: Removing unreachable block (ram,0x0d6b3e) */
/* WARNING: Removing unreachable block (ram,0x0d6b36) */
/* WARNING: Removing unreachable block (ram,0x0d6b2a) */
/* WARNING: Removing unreachable block (ram,0x0d6b1e) */
/* WARNING: Removing unreachable block (ram,0x0d6b1a) */
/* WARNING: Removing unreachable block (ram,0x0d6b12) */
/* WARNING: Removing unreachable block (ram,0x0d6b0a) */
/* WARNING: Removing unreachable block (ram,0x0d6b04) */
/* WARNING: Removing unreachable block (ram,0x0d6b00) */
/* WARNING: Removing unreachable block (ram,0x0d6af8) */
/* WARNING: Removing unreachable block (ram,0x0d6af2) */
/* WARNING: Removing unreachable block (ram,0x0d6aee) */
/* WARNING: Removing unreachable block (ram,0x0d6aea) */
/* WARNING: Removing unreachable block (ram,0x0d6ae6) */
/* WARNING: Removing unreachable block (ram,0x0d6ade) */
/* WARNING: Removing unreachable block (ram,0x0d6ad8) */
/* WARNING: Removing unreachable block (ram,0x0d6ad4) */
/* WARNING: Removing unreachable block (ram,0x0d6ac4) */

void egs52_update_near_d5b0_0d6ac2(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  char cVar5;
  ushort target;
  ushort old;
  byte bVar6;
  int iVar7;
  char cVar8;
  ushort uVar9;
  
  cVar5 = UNK_00d566;
  if (cVar5 == '\0') {
    uVar1 = Ram00fd48;
    Ram00fd48 = uVar1 | 0x40;
    iVar7 = Ram00f63a;
    uVar1 = iVar7 + 0x30;
    uVar3 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    UNK_00d5b0 = (char)*(undefined2 *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff));
    cVar8 = egs52_update_near_d5f6_0d7110();
    cVar5 = UNK_00d5b0;
    UNK_00d5b1 = cVar8 + cVar5;
    cVar5 = UNK_00d566;
    UNK_00d566 = cVar5 + '\x01';
  }
  else if (cVar5 != '\x01') goto LAB_0d6b7a;
  uVar9 = Ram00d556;
  bVar6 = UNK_00d5b0;
  uVar9 = egs52_ramp_u16(uVar9,0,(uint)bVar6);
  Ram00d556 = uVar9;
  uVar9 = Ram00d56c;
  bVar6 = UNK_00d5b0;
  uVar9 = egs52_ramp_u16(uVar9,0,(uint)bVar6);
  Ram00d56c = uVar9;
  iVar7 = Ram00f63a;
  uVar1 = iVar7 + 0x72;
  uVar3 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar3 = 3;
  }
  uVar2 = iVar7 + 0x30;
  uVar4 = 0x24;
  if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
     (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
    uVar4 = 3;
  }
  bVar6 = UNK_00d5b0;
  if ((uint)(((ulong)(100 - *(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff))) *
             (ulong)*(uint *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff))) / 100) < (uint)bVar6)
  {
    uVar1 = iVar7 + 0x72;
    uVar3 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    uVar2 = iVar7 + 0x30;
    uVar4 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar4 = 3;
    }
    bVar6 = UNK_00d5b0;
    uVar9 = (uint)bVar6 -
            (int)(((ulong)(100 - *(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff))) *
                  (ulong)*(uint *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff))) / 100);
  }
  else {
    uVar9 = 0;
  }
  old = Ram00d56a;
  target = Ram00d54c;
  uVar9 = egs52_ramp_u16(old,target,uVar9);
  Ram00d56a = uVar9;
LAB_0d6b7a:
  cVar5 = UNK_00d5b1;
  if (cVar5 == '\0') {
    UNK_00d566 = 0;
    cVar5 = UNK_00d437;
    UNK_00d437 = cVar5 + '\x01';
  }
  return;
}


