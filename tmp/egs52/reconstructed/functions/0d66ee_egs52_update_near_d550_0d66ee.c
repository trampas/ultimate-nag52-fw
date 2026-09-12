/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d66ee; FLS offset 0x0566ee.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d685c) */
/* WARNING: Removing unreachable block (ram,0x0d6856) */
/* WARNING: Removing unreachable block (ram,0x0d6852) */
/* WARNING: Removing unreachable block (ram,0x0d684c) */
/* WARNING: Removing unreachable block (ram,0x0d6848) */
/* WARNING: Removing unreachable block (ram,0x0d6844) */
/* WARNING: Removing unreachable block (ram,0x0d683c) */
/* WARNING: Removing unreachable block (ram,0x0d6836) */
/* WARNING: Removing unreachable block (ram,0x0d682c) */
/* WARNING: Removing unreachable block (ram,0x0d681e) */
/* WARNING: Removing unreachable block (ram,0x0d681a) */
/* WARNING: Removing unreachable block (ram,0x0d6816) */
/* WARNING: Removing unreachable block (ram,0x0d6812) */
/* WARNING: Removing unreachable block (ram,0x0d680e) */
/* WARNING: Removing unreachable block (ram,0x0d6808) */
/* WARNING: Removing unreachable block (ram,0x0d6802) */
/* WARNING: Removing unreachable block (ram,0x0d67fe) */
/* WARNING: Removing unreachable block (ram,0x0d67f6) */
/* WARNING: Removing unreachable block (ram,0x0d67f0) */
/* WARNING: Removing unreachable block (ram,0x0d67e2) */
/* WARNING: Removing unreachable block (ram,0x0d67de) */
/* WARNING: Removing unreachable block (ram,0x0d67d0) */
/* WARNING: Removing unreachable block (ram,0x0d67cc) */
/* WARNING: Removing unreachable block (ram,0x0d67c4) */
/* WARNING: Removing unreachable block (ram,0x0d67be) */
/* WARNING: Removing unreachable block (ram,0x0d6786) */
/* WARNING: Removing unreachable block (ram,0x0d677e) */
/* WARNING: Removing unreachable block (ram,0x0d677a) */
/* WARNING: Removing unreachable block (ram,0x0d678e) */
/* WARNING: Removing unreachable block (ram,0x0d6770) */
/* WARNING: Removing unreachable block (ram,0x0d67aa) */
/* WARNING: Removing unreachable block (ram,0x0d67a6) */
/* WARNING: Removing unreachable block (ram,0x0d6768) */
/* WARNING: Removing unreachable block (ram,0x0d6764) */
/* WARNING: Removing unreachable block (ram,0x0d6756) */
/* WARNING: Removing unreachable block (ram,0x0d6752) */
/* WARNING: Removing unreachable block (ram,0x0d674c) */
/* WARNING: Removing unreachable block (ram,0x0d6748) */
/* WARNING: Removing unreachable block (ram,0x0d6744) */
/* WARNING: Removing unreachable block (ram,0x0d672c) */
/* WARNING: Removing unreachable block (ram,0x0d6720) */
/* WARNING: Removing unreachable block (ram,0x0d6740) */
/* WARNING: Removing unreachable block (ram,0x0d673a) */
/* WARNING: Removing unreachable block (ram,0x0d6718) */
/* WARNING: Removing unreachable block (ram,0x0d6714) */
/* WARNING: Removing unreachable block (ram,0x0d6710) */
/* WARNING: Removing unreachable block (ram,0x0d670c) */
/* WARNING: Removing unreachable block (ram,0x0d66fc) */
/* WARNING: Removing unreachable block (ram,0x0d66f2) */
/* WARNING: Removing unreachable block (ram,0x0d6732) */
/* WARNING: Removing unreachable block (ram,0x0d67a2) */
/* WARNING: Removing unreachable block (ram,0x0d6776) */
/* WARNING: Removing unreachable block (ram,0x0d6824) */
/* WARNING: Removing unreachable block (ram,0x0d6830) */
/* WARNING: Removing unreachable block (ram,0x0d6792) */

void egs52_update_near_d550_0d66ee(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  char cVar4;
  undefined1 uVar5;
  int iVar6;
  int iVar7;
  byte bVar8;
  ushort uVar9;
  ushort uVar10;
  undefined2 uVar11;
  
  uVar5 = UNK_00d577;
  uVar9 = egs52_update_near_d426_0d4338(uVar5);
  cVar4 = UNK_00d566;
  if (cVar4 == '\0') {
    uVar1 = Ram00fd48;
    Ram00fd48 = uVar1 | 0x40;
    uVar11 = Ram00d556;
    Ram00d550 = uVar11;
    UNK_00d5b1 = 0;
    bVar8 = UNK_00d579;
    if (bVar8 < 5) {
      iVar2 = Ram00f634;
      uVar3 = iVar2 + 0x34 + (uint)bVar8;
      uVar1 = 0x24;
      if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      UNK_00d5b0 = *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff));
    }
    else {
      iVar2 = Ram00f634;
      bVar8 = UNK_00d579;
      uVar3 = iVar2 + 0x30 + (uint)bVar8;
      uVar1 = 0x24;
      if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      UNK_00d5b0 = *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff));
    }
    iVar2 = Ram00f634;
    uVar1 = iVar2 + 0x39;
    uVar3 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    UNK_00d5b1 = *(undefined1 *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff));
    iVar2 = Ram00f63a;
    uVar1 = iVar2 + 0x4c;
    uVar3 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    egs52_scale_and_store_d4ae(uVar9,*(uchar *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)));
    egs52_update_near_d402_0d7b8a();
    cVar4 = UNK_00d566;
    UNK_00d566 = cVar4 + '\x01';
LAB_0d6768:
    cVar4 = UNK_00d579;
    if (cVar4 == '\a') {
      cVar4 = UNK_00d5b1;
      if (cVar4 == '\0') {
        uVar9 = Ram00d402;
        uVar10 = Ram00d4d2;
        bVar8 = UNK_00d5b0;
        uVar9 = egs52_ramp_u16(uVar9,uVar10,(uint)bVar8);
        Ram00d402 = uVar9;
      }
      else {
        iVar2 = Ram00f63a;
        uVar1 = iVar2 + 0x4c;
        uVar3 = 0x24;
        if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
           (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
          uVar3 = 3;
        }
        egs52_scale_and_store_d4ae(uVar9,*(uchar *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)));
        egs52_update_near_d402_0d7b8a();
      }
    }
    else {
      uVar11 = Ram00d556;
      iVar2 = Ram00f63a;
      uVar1 = iVar2 + 0x4c;
      uVar3 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      egs52_update_near_d4ae_0d7b3e
                (uVar11,*(undefined1 *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)));
      egs52_combine_percent_term_d402();
    }
    uVar10 = egs52_compute_from_near_d579_0d8fc8();
    uVar9 = Ram00d556;
    bVar8 = UNK_00d5b0;
    uVar9 = egs52_ramp_u16(uVar9,uVar10,(uint)bVar8);
    Ram00d556 = uVar9;
    cVar4 = UNK_00d579;
    uVar11 = egs52_update_near_d600_0d7cb8(cVar4 + -1,uVar9,uVar10);
    Ram00d56c = uVar11;
    cVar4 = UNK_00d579;
    uVar10 = egs52_compute_from_near_f63a_0d8f58(cVar4 + -1);
    uVar9 = Ram00d56a;
    bVar8 = UNK_00d5b0;
    uVar9 = egs52_ramp_u16(uVar9,uVar10,(uint)bVar8);
    Ram00d56a = uVar9;
  }
  else if (cVar4 == '\x01') goto LAB_0d6768;
  iVar2 = Ram00d5a6;
  if ((iVar2 == 0) || (cVar4 = UNK_00d5b0, cVar4 == '\0')) {
    UNK_00d5b0 = 0;
    UNK_00d5b1 = 0;
    UNK_00d566 = 0;
    UNK_00d567 = 0;
    cVar4 = UNK_00d437;
    UNK_00d437 = cVar4 + '\x01';
    return;
  }
  cVar4 = UNK_00d577;
  if (cVar4 == '\x02') {
    iVar2 = Ram00f634;
    uVar1 = iVar2 + 0x2e;
    uVar3 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    iVar2 = Ram00d4c2;
    if (-*(int *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)) < iVar2) goto LAB_0d6852;
  }
  cVar4 = UNK_00d577;
  if (cVar4 != '\x03') {
    return;
  }
  iVar2 = Ram00f634;
  uVar1 = iVar2 + 0x32;
  uVar3 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar3 = 3;
  }
  iVar2 = *(int *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff));
  iVar6 = Ram00d4c2;
  iVar7 = Ram00d4c2;
  if (iVar2 == iVar7 || iVar2 < iVar6) {
    return;
  }
LAB_0d6852:
  UNK_00d566 = 0;
  UNK_00d567 = 0;
  UNK_00d437 = 0xb;
  return;
}


