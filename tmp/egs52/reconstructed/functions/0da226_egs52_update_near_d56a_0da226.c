/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0da226; FLS offset 0x05a226.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0da2fa) */
/* WARNING: Removing unreachable block (ram,0x0da2f6) */
/* WARNING: Removing unreachable block (ram,0x0da2f0) */
/* WARNING: Removing unreachable block (ram,0x0da2da) */
/* WARNING: Removing unreachable block (ram,0x0da2cc) */
/* WARNING: Removing unreachable block (ram,0x0da2c8) */
/* WARNING: Removing unreachable block (ram,0x0da2c0) */
/* WARNING: Removing unreachable block (ram,0x0da2b8) */
/* WARNING: Removing unreachable block (ram,0x0da2b2) */
/* WARNING: Removing unreachable block (ram,0x0da2ae) */
/* WARNING: Removing unreachable block (ram,0x0da2a8) */
/* WARNING: Removing unreachable block (ram,0x0da2a2) */
/* WARNING: Removing unreachable block (ram,0x0da29e) */
/* WARNING: Removing unreachable block (ram,0x0da2ec) */
/* WARNING: Removing unreachable block (ram,0x0da2e8) */
/* WARNING: Removing unreachable block (ram,0x0da2e4) */
/* WARNING: Removing unreachable block (ram,0x0da2e0) */
/* WARNING: Removing unreachable block (ram,0x0da298) */
/* WARNING: Removing unreachable block (ram,0x0da294) */
/* WARNING: Removing unreachable block (ram,0x0da286) */
/* WARNING: Removing unreachable block (ram,0x0da282) */
/* WARNING: Removing unreachable block (ram,0x0da27a) */
/* WARNING: Removing unreachable block (ram,0x0da276) */
/* WARNING: Removing unreachable block (ram,0x0da26c) */
/* WARNING: Removing unreachable block (ram,0x0da268) */
/* WARNING: Removing unreachable block (ram,0x0da262) */
/* WARNING: Removing unreachable block (ram,0x0da25e) */
/* WARNING: Removing unreachable block (ram,0x0da25a) */
/* WARNING: Removing unreachable block (ram,0x0da252) */
/* WARNING: Removing unreachable block (ram,0x0da24e) */
/* WARNING: Removing unreachable block (ram,0x0da236) */
/* WARNING: Removing unreachable block (ram,0x0da232) */
/* WARNING: Removing unreachable block (ram,0x0da226) */
/* WARNING: Removing unreachable block (ram,0x0da24a) */
/* WARNING: Removing unreachable block (ram,0x0da2bc) */

void egs52_update_near_d56a_0da226(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char cVar6;
  byte bVar7;
  char cVar8;
  undefined2 uVar9;
  ushort uVar10;
  ushort uVar11;
  
  cVar8 = UNK_00d579;
  uVar9 = egs52_compute_from_near_f63a_0d8846(cVar8 + -1);
  Ram00d56a = uVar9;
  cVar8 = UNK_00d566;
  if (cVar8 == '\0') {
    uVar1 = Ram00fd48;
    Ram00fd48 = uVar1 & 0xffbf;
    iVar3 = Ram00f63a;
    uVar1 = iVar3 + 0x2e;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    UNK_00d5b0 = *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
    cVar8 = egs52_update_near_d5f6_0d7110();
    iVar3 = Ram00f63a;
    uVar1 = iVar3 + 0x2f;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    cVar6 = UNK_00d5b0;
    UNK_00d5b1 = *(char *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) + cVar6 + cVar8;
    cVar8 = UNK_00d566;
    UNK_00d566 = cVar8 + '\x01';
  }
  else if (cVar8 != '\x01') {
    if (cVar8 == '\x02') {
      uVar10 = Ram00d556;
      uVar11 = Ram00d552;
      bVar7 = UNK_00d5b0;
      uVar11 = egs52_ramp_u16(uVar10,uVar11,(uint)bVar7);
      Ram00d556 = uVar11;
      cVar8 = UNK_00d579;
      uVar9 = egs52_update_near_d600_0d7cb8(cVar8 + -1,uVar11);
      Ram00d56c = uVar9;
    }
    goto LAB_0da2f0;
  }
  uVar10 = egs52_compute_from_near_d4d2_0d8ac8();
  uVar11 = Ram00d556;
  bVar7 = UNK_00d5b0;
  uVar11 = egs52_ramp_u16(uVar11,uVar10,(uint)bVar7);
  Ram00d556 = uVar11;
  cVar8 = UNK_00d579;
  uVar9 = egs52_update_near_d600_0d7cb8(cVar8 + -1,uVar11);
  Ram00d56c = uVar9;
  cVar8 = UNK_00d5b0;
  if (cVar8 == '\0') {
    iVar3 = Ram00f63a;
    uVar1 = iVar3 + 0x2f;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    UNK_00d5b0 = *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
    cVar8 = UNK_00d566;
    UNK_00d566 = cVar8 + '\x01';
  }
  else {
    iVar3 = Ram00f634;
    uVar1 = iVar3 + 0x20;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    iVar3 = *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
    iVar4 = Ram00d41c;
    iVar5 = Ram00d41c;
    if (-iVar5 != iVar3 && iVar4 <= -iVar3) {
      UNK_00d5b0 = 0;
      cVar8 = UNK_00d566;
      UNK_00d566 = cVar8 + '\x01';
    }
  }
LAB_0da2f0:
  cVar8 = UNK_00d5b1;
  if (cVar8 == '\0') {
    UNK_00d566 = 0;
    cVar8 = UNK_00d437;
    UNK_00d437 = cVar8 + '\x01';
  }
  return;
}


