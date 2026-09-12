/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d52c0; FLS offset 0x0552c0.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d536e) */
/* WARNING: Removing unreachable block (ram,0x0d5362) */
/* WARNING: Removing unreachable block (ram,0x0d535e) */
/* WARNING: Removing unreachable block (ram,0x0d5354) */
/* WARNING: Removing unreachable block (ram,0x0d5350) */
/* WARNING: Removing unreachable block (ram,0x0d534c) */
/* WARNING: Removing unreachable block (ram,0x0d5344) */
/* WARNING: Removing unreachable block (ram,0x0d5338) */
/* WARNING: Removing unreachable block (ram,0x0d5326) */
/* WARNING: Removing unreachable block (ram,0x0d5322) */
/* WARNING: Removing unreachable block (ram,0x0d5314) */
/* WARNING: Removing unreachable block (ram,0x0d5310) */
/* WARNING: Removing unreachable block (ram,0x0d5308) */
/* WARNING: Removing unreachable block (ram,0x0d5300) */
/* WARNING: Removing unreachable block (ram,0x0d52fc) */
/* WARNING: Removing unreachable block (ram,0x0d52f4) */
/* WARNING: Removing unreachable block (ram,0x0d52f0) */
/* WARNING: Removing unreachable block (ram,0x0d52ea) */
/* WARNING: Removing unreachable block (ram,0x0d52e6) */
/* WARNING: Removing unreachable block (ram,0x0d52e2) */
/* WARNING: Removing unreachable block (ram,0x0d52de) */
/* WARNING: Removing unreachable block (ram,0x0d52da) */
/* WARNING: Removing unreachable block (ram,0x0d52d6) */
/* WARNING: Removing unreachable block (ram,0x0d52d2) */
/* WARNING: Removing unreachable block (ram,0x0d52ce) */
/* WARNING: Removing unreachable block (ram,0x0d52c0) */

void egs52_update_near_d5b0_0d52c0(void)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  uint uVar4;
  byte bVar5;
  int iVar6;
  ushort uVar7;
  undefined2 uVar8;
  
  cVar3 = UNK_00d566;
  if (cVar3 == '\0') {
    iVar6 = Ram00f648;
    uVar1 = iVar6 + 0xf;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    UNK_00d5b0 = *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
    uVar1 = iVar6 + 0x26;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    Ram00d5a6 = *(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
    cVar3 = UNK_00d566;
    UNK_00d566 = cVar3 + '\x01';
  }
  else if (cVar3 != '\x01') {
    return;
  }
  uVar7 = Ram00d56a;
  iVar6 = Ram00f648;
  uVar1 = iVar6 + 0x18;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  bVar5 = UNK_00d5b0;
  uVar7 = egs52_ramp_u16(uVar7,*(ushort *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)),
                         (uint)bVar5);
  Ram00d56a = uVar7;
  uVar7 = Ram00d556;
  bVar5 = UNK_00d5b0;
  uVar7 = egs52_ramp_u16(uVar7,3000,(uint)bVar5);
  Ram00d556 = uVar7;
  cVar3 = UNK_00d579;
  uVar8 = egs52_update_near_d600_0d7cb8(cVar3 + -1,uVar7);
  Ram00d56c = uVar8;
  cVar3 = UNK_00d5b0;
  if (cVar3 == '\0') {
    uVar1 = Ram00fd48;
    Ram00fd48 = uVar1 & 0xfffe;
    uVar1 = Ram00fd48;
    Ram00fd48 = uVar1 & 0xfffd;
    uVar1 = Ram00fd3a;
    Ram00fd3a = uVar1 & 0xfffd;
    uVar1 = Ram00fd3a;
    Ram00fd3a = uVar1 & 0xfff7;
    uVar1 = Ram00fd30;
    if ((((uVar1 & 2) != 0) || (bVar5 = UNK_00d613, 5 < bVar5)) &&
       ((uVar1 = Ram00fd30, (uVar1 & 1) != 0 || (cVar3 = UNK_00d613, cVar3 != '\a')))) {
      egs52_reset_state_d437();
      return;
    }
    iVar6 = Ram00f64a;
    uVar1 = iVar6 + 0x40;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    uVar1 = *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
    uVar2 = Ram00d508;
    uVar4 = Ram00d508;
    if (uVar1 == uVar4 || uVar1 < uVar2) {
      Ram00d556 = 500;
      cVar3 = UNK_00d579;
      uVar8 = egs52_update_near_d600_0d7cb8(cVar3 + -1);
      Ram00d56c = uVar8;
      return;
    }
    egs52_reset_state_d437();
    uVar1 = Ram00fd3a;
    Ram00fd3a = uVar1 | 8;
  }
  return;
}


