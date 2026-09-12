/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0e4958; FLS offset 0x064958.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0e4ac6) */
/* WARNING: Removing unreachable block (ram,0x0e4afc) */
/* WARNING: Removing unreachable block (ram,0x0e4af4) */
/* WARNING: Removing unreachable block (ram,0x0e4b2a) */
/* WARNING: Removing unreachable block (ram,0x0e4b22) */
/* WARNING: Removing unreachable block (ram,0x0e4b4e) */
/* WARNING: Removing unreachable block (ram,0x0e4b46) */
/* WARNING: Removing unreachable block (ram,0x0e4b3c) */
/* WARNING: Removing unreachable block (ram,0x0e4b32) */
/* WARNING: Removing unreachable block (ram,0x0e4b18) */
/* WARNING: Removing unreachable block (ram,0x0e4b0e) */
/* WARNING: Removing unreachable block (ram,0x0e4b04) */
/* WARNING: Removing unreachable block (ram,0x0e4aea) */
/* WARNING: Removing unreachable block (ram,0x0e4ae0) */
/* WARNING: Removing unreachable block (ram,0x0e4abc) */
/* WARNING: Removing unreachable block (ram,0x0e4ab2) */
/* WARNING: Removing unreachable block (ram,0x0e4aa8) */
/* WARNING: Removing unreachable block (ram,0x0e4aa0) */
/* WARNING: Removing unreachable block (ram,0x0e49f4) */
/* WARNING: Removing unreachable block (ram,0x0e4a28) */
/* WARNING: Removing unreachable block (ram,0x0e4a6a) */
/* WARNING: Removing unreachable block (ram,0x0e4a60) */
/* WARNING: Removing unreachable block (ram,0x0e4a58) */
/* WARNING: Removing unreachable block (ram,0x0e4a4e) */
/* WARNING: Removing unreachable block (ram,0x0e4a44) */
/* WARNING: Removing unreachable block (ram,0x0e4a9c) */
/* WARNING: Removing unreachable block (ram,0x0e4a8e) */
/* WARNING: Removing unreachable block (ram,0x0e4a84) */
/* WARNING: Removing unreachable block (ram,0x0e4a7a) */
/* WARNING: Removing unreachable block (ram,0x0e4a70) */
/* WARNING: Removing unreachable block (ram,0x0e4a3a) */
/* WARNING: Removing unreachable block (ram,0x0e4a30) */
/* WARNING: Removing unreachable block (ram,0x0e4a1a) */
/* WARNING: Removing unreachable block (ram,0x0e4a10) */
/* WARNING: Removing unreachable block (ram,0x0e4a06) */
/* WARNING: Removing unreachable block (ram,0x0e49e6) */
/* WARNING: Removing unreachable block (ram,0x0e49dc) */
/* WARNING: Removing unreachable block (ram,0x0e49d2) */
/* WARNING: Removing unreachable block (ram,0x0e49ca) */
/* WARNING: Removing unreachable block (ram,0x0e49c4) */
/* WARNING: Removing unreachable block (ram,0x0e49c0) */
/* WARNING: Removing unreachable block (ram,0x0e49b8) */
/* WARNING: Removing unreachable block (ram,0x0e49ae) */
/* WARNING: Removing unreachable block (ram,0x0e49aa) */
/* WARNING: Removing unreachable block (ram,0x0e49a6) */
/* WARNING: Removing unreachable block (ram,0x0e4996) */
/* WARNING: Removing unreachable block (ram,0x0e4964) */
/* WARNING: Removing unreachable block (ram,0x0e4960) */
/* WARNING: Removing unreachable block (ram,0x0e495c) */
/* WARNING: Removing unreachable block (ram,0x0e4958) */
/* WARNING: Removing unreachable block (ram,0x0e49fc) */
/* WARNING: Removing unreachable block (ram,0x0e4ad6) */
/* WARNING: Removing unreachable block (ram,0x0e4ace) */

void egs52_update_near_d5ca_0e4958(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  byte bVar5;
  undefined1 uVar6;
  int iVar7;
  char cVar8;
  
  uVar6 = UNK_00d5cc;
  UNK_00d5ca = uVar6;
  uVar6 = UNK_00d3d4;
  UNK_00d5cc = uVar6;
  uVar1 = Ram00fd60;
  Ram00fd60 = uVar1 & 0xfffd;
  cVar8 = egs52_match_fault_status_mask(0x14,1);
  if (((cVar8 == '\x01') || (cVar8 = egs52_match_fault_status_mask(0x4a,1), cVar8 == '\x01')) ||
     (cVar8 = egs52_match_fault_status_mask(0x4b,1), cVar8 == '\x01')) {
    uVar1 = Ram00fd60;
    Ram00fd60 = uVar1 | 2;
  }
  uVar1 = Ram00fd60;
  if ((uVar1 & 2) != 0) {
    uVar1 = Ram00fd54;
    Ram00fd54 = uVar1 & 0xefff;
    return;
  }
  uVar1 = Ram00fd54;
  if ((uVar1 & 0x1000) == 0) {
    iVar7 = Ram00f66c;
    uVar1 = iVar7 + 0x25;
    uVar3 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    bVar5 = UNK_00d5cc;
    if (*(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)) < bVar5) {
      uVar1 = Ram00fd54;
      Ram00fd54 = uVar1 | 0x1000;
      goto LAB_0e49dc;
    }
  }
  uVar1 = Ram00fd54;
  if ((uVar1 & 0x1000) != 0) {
    iVar7 = Ram00f66c;
    uVar1 = iVar7 + 0x25;
    uVar3 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    uVar2 = iVar7 + 0x26;
    uVar4 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar4 = 3;
    }
    bVar5 = UNK_00d5cc;
    if ((int)(uint)bVar5 <
        (int)((uint)*(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)) -
             (uint)*(byte *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff)))) {
      uVar1 = Ram00fd54;
      Ram00fd54 = uVar1 & 0xefff;
    }
  }
LAB_0e49dc:
  bVar5 = UNK_00d5cc;
  if ((bVar5 < 0x97) && (bVar5 = UNK_00d5ca, 0x96 < bVar5)) {
    Ram00d5bc = 30000;
  }
  else {
    bVar5 = UNK_00d5cc;
    if (((bVar5 < 0xab) && (bVar5 = UNK_00d5ca, 0xaa < bVar5)) ||
       ((bVar5 = UNK_00d5cc, bVar5 < 0xbf && (bVar5 = UNK_00d5ca, 0xbe < bVar5)))) {
      Ram00d5bc = 3000;
    }
    else {
      bVar5 = UNK_00d5cc;
      if ((bVar5 < 0x97) || (bVar5 = UNK_00d5ca, 0x96 < bVar5)) {
        bVar5 = UNK_00d5cc;
        if (((0xaa < bVar5) && (bVar5 = UNK_00d5ca, bVar5 < 0xab)) ||
           ((bVar5 = UNK_00d5cc, 0xbe < bVar5 && (bVar5 = UNK_00d5ca, bVar5 < 0xbf)))) {
          Ram00d5bc = 3000;
        }
      }
      else {
        uVar1 = Ram00d5bc;
        if ((uVar1 < 15000) &&
           ((iVar7 = Ram00d392, iVar7 != -1 && (cVar8 = UNK_00d613, cVar8 == '\x05')))) {
          iVar7 = Ram00d392;
          Ram00d392 = iVar7 + 1;
          uVar1 = Ram00fd5a;
          Ram00fd5a = uVar1 | 0x80;
        }
        Ram00d5bc = 3000;
      }
    }
  }
  iVar7 = Ram00d5bc;
  if ((iVar7 == 0) && (cVar8 = UNK_00d613, cVar8 == '\x05')) {
    bVar5 = UNK_00d5cc;
    if ((bVar5 < 0x97) && (iVar7 = Ram00d392, iVar7 != -1)) {
      iVar7 = Ram00d392;
      Ram00d392 = iVar7 + 1;
      Ram00d5bc = 30000;
      uVar1 = Ram00fd5a;
      Ram00fd5a = uVar1 | 0x80;
      return;
    }
    bVar5 = UNK_00d5cc;
    if (((0x96 < bVar5) && (bVar5 = UNK_00d5cc, bVar5 < 0xab)) && (iVar7 = Ram00d390, iVar7 != -1))
    {
      iVar7 = Ram00d390;
      Ram00d390 = iVar7 + 1;
      Ram00d5bc = 3000;
      uVar1 = Ram00fd5a;
      Ram00fd5a = uVar1 | 0x80;
      return;
    }
    bVar5 = UNK_00d5cc;
    if (((0xaa < bVar5) && (bVar5 = UNK_00d5cc, bVar5 < 0xbf)) && (iVar7 = Ram00d38e, iVar7 != -1))
    {
      iVar7 = Ram00d38e;
      Ram00d38e = iVar7 + 1;
      Ram00d5bc = 3000;
      uVar1 = Ram00fd5a;
      Ram00fd5a = uVar1 | 0x80;
      return;
    }
    bVar5 = UNK_00d5cc;
    if ((0xbe < bVar5) && (cVar8 = UNK_00d38d, cVar8 != -1)) {
      cVar8 = UNK_00d38d;
      UNK_00d38d = cVar8 + '\x01';
      Ram00d5bc = 3000;
      uVar1 = Ram00fd5a;
      Ram00fd5a = uVar1 | 0x80;
    }
  }
  return;
}


