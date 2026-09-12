/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d9ac6; FLS offset 0x059ac6.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d9bda) */
/* WARNING: Removing unreachable block (ram,0x0d9bd6) */
/* WARNING: Removing unreachable block (ram,0x0d9bd0) */
/* WARNING: Removing unreachable block (ram,0x0d9bca) */
/* WARNING: Removing unreachable block (ram,0x0d9bc6) */
/* WARNING: Removing unreachable block (ram,0x0d9bbe) */
/* WARNING: Removing unreachable block (ram,0x0d9b8c) */
/* WARNING: Removing unreachable block (ram,0x0d9b84) */
/* WARNING: Removing unreachable block (ram,0x0d9b7c) */
/* WARNING: Removing unreachable block (ram,0x0d9bb0) */
/* WARNING: Removing unreachable block (ram,0x0d9bac) */
/* WARNING: Removing unreachable block (ram,0x0d9ba8) */
/* WARNING: Removing unreachable block (ram,0x0d9b6e) */
/* WARNING: Removing unreachable block (ram,0x0d9b6a) */
/* WARNING: Removing unreachable block (ram,0x0d9b5c) */
/* WARNING: Removing unreachable block (ram,0x0d9b58) */
/* WARNING: Removing unreachable block (ram,0x0d9b50) */
/* WARNING: Removing unreachable block (ram,0x0d9b4a) */
/* WARNING: Removing unreachable block (ram,0x0d9b40) */
/* WARNING: Removing unreachable block (ram,0x0d9b32) */
/* WARNING: Removing unreachable block (ram,0x0d9b2e) */
/* WARNING: Removing unreachable block (ram,0x0d9b28) */
/* WARNING: Removing unreachable block (ram,0x0d9b24) */
/* WARNING: Removing unreachable block (ram,0x0d9b20) */
/* WARNING: Removing unreachable block (ram,0x0d9b08) */
/* WARNING: Removing unreachable block (ram,0x0d9b1c) */
/* WARNING: Removing unreachable block (ram,0x0d9b16) */
/* WARNING: Removing unreachable block (ram,0x0d9b0e) */
/* WARNING: Removing unreachable block (ram,0x0d9af4) */
/* WARNING: Removing unreachable block (ram,0x0d9af0) */
/* WARNING: Removing unreachable block (ram,0x0d9aec) */
/* WARNING: Removing unreachable block (ram,0x0d9ae8) */
/* WARNING: Removing unreachable block (ram,0x0d9ae4) */
/* WARNING: Removing unreachable block (ram,0x0d9ad4) */
/* WARNING: Removing unreachable block (ram,0x0d9aca) */
/* WARNING: Removing unreachable block (ram,0x0d9afc) */
/* WARNING: Removing unreachable block (ram,0x0d9b76) */
/* WARNING: Removing unreachable block (ram,0x0d9b94) */
/* WARNING: Removing unreachable block (ram,0x0d9b80) */
/* WARNING: Removing unreachable block (ram,0x0d9b98) */

void egs52_update_near_d550_0d9ac6(void)

{
  uint uVar1;
  uint uVar2;
  undefined1 uVar3;
  int iVar4;
  char cVar5;
  int iVar6;
  byte bVar7;
  ushort uVar8;
  ushort target;
  ushort uVar9;
  undefined2 uVar10;
  
  uVar3 = UNK_00d577;
  uVar8 = egs52_update_near_d426_0d4338(uVar3);
  cVar5 = UNK_00d566;
  if (cVar5 == '\0') {
    uVar1 = Ram00fd48;
    Ram00fd48 = uVar1 | 0x40;
    iVar6 = Ram00d556;
    iVar4 = Ram00d536;
    Ram00d550 = iVar6 + iVar4;
    UNK_00d5b1 = 0;
    bVar7 = UNK_00d579;
    if (bVar7 < 5) {
      iVar4 = Ram00f634;
      uVar2 = iVar4 + 0x34 + (uint)bVar7;
      uVar1 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      UNK_00d5b0 = *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
    }
    else {
      iVar4 = Ram00f634;
      bVar7 = UNK_00d579;
      uVar2 = iVar4 + 0x30 + (uint)bVar7;
      uVar1 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      UNK_00d5b0 = *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
    }
    iVar4 = Ram00f634;
    uVar1 = iVar4 + 0x39;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    UNK_00d5b1 = *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
    iVar4 = Ram00f63a;
    uVar1 = iVar4 + 0x4c;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    egs52_scale_and_store_d4ae(uVar8,*(uchar *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)));
    egs52_update_near_d402_0d7b8a();
    cVar5 = UNK_00d566;
    UNK_00d566 = cVar5 + '\x01';
  }
  else if (cVar5 != '\x01') goto LAB_0d9bca;
  target = egs52_compute_from_near_f63a_0d85da();
  uVar9 = Ram00d556;
  bVar7 = UNK_00d5b0;
  uVar9 = egs52_ramp_u16(uVar9,target,(uint)bVar7);
  Ram00d556 = uVar9;
  cVar5 = UNK_00d579;
  uVar10 = egs52_update_near_d600_0d7cb8(cVar5 + -1,uVar9,target);
  Ram00d56c = uVar10;
  cVar5 = UNK_00d579;
  if (cVar5 == '\a') {
    cVar5 = UNK_00d5b1;
    if (cVar5 == '\0') {
      uVar8 = Ram00d402;
      uVar9 = Ram00d4d2;
      bVar7 = UNK_00d5b0;
      uVar8 = egs52_ramp_u16(uVar8,uVar9,(uint)bVar7);
      Ram00d402 = uVar8;
    }
    else {
      iVar4 = Ram00f63a;
      uVar1 = iVar4 + 0x4c;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      egs52_scale_and_store_d4ae(uVar8,*(uchar *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)));
      egs52_update_near_d402_0d7b8a();
    }
  }
  else {
    uVar10 = Ram00d556;
    iVar4 = Ram00f63a;
    uVar1 = iVar4 + 0x4c;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    egs52_update_near_d4ae_0d7b3e
              (uVar10,*(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)));
    egs52_combine_percent_term_d402();
  }
  uVar3 = UNK_00d579;
  uVar10 = egs52_compute_from_near_f634_0d83e8(uVar3);
  Ram00d56a = uVar10;
LAB_0d9bca:
  iVar4 = Ram00d5a6;
  if ((iVar4 == 0) || (cVar5 = UNK_00d5b0, cVar5 == '\0')) {
    UNK_00d566 = 0;
    cVar5 = UNK_00d437;
    UNK_00d437 = cVar5 + '\x01';
  }
  return;
}


