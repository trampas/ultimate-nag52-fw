/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x099adc; FLS offset 0x019adc.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x099b46) */
/* WARNING: Removing unreachable block (ram,0x099b70) */
/* WARNING: Removing unreachable block (ram,0x099b6a) */
/* WARNING: Removing unreachable block (ram,0x099b66) */
/* WARNING: Removing unreachable block (ram,0x099b80) */
/* WARNING: Removing unreachable block (ram,0x099b36) */
/* WARNING: Removing unreachable block (ram,0x099b32) */
/* WARNING: Removing unreachable block (ram,0x099b28) */
/* WARNING: Removing unreachable block (ram,0x099b18) */
/* WARNING: Removing unreachable block (ram,0x099af2) */
/* WARNING: Removing unreachable block (ram,0x099aee) */
/* WARNING: Removing unreachable block (ram,0x099ae4) */
/* WARNING: Removing unreachable block (ram,0x099b8a) */
/* WARNING: Removing unreachable block (ram,0x099b02) */
/* WARNING: Removing unreachable block (ram,0x099b62) */
/* WARNING: Removing unreachable block (ram,0x099b4a) */
/* WARNING: Heritage AFTER dead removal. Example location: r0x00f464 : 0x099b32 */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void egs52_update_near_f581_099adc(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  char cVar7;
  uint uVar8;
  char cVar9;
  
  if (bRam00f469 == 5) {
    uVar3 = 0x24;
    if ((((uRam00f462 & 0xc000) != 0) && (uVar3 = 0x21, (uRam00f462 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uRam00f462 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    uVar1 = uRam00f462 + 1;
    uVar4 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar4 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar4 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar4 = 3;
    }
    uVar2 = uRam00f462 + 2;
    uVar5 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar5 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar5 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar5 = 3;
    }
    uVar8 = uRam00f462 + 3;
    uVar6 = 0x24;
    if ((((uVar8 & 0xc000) != 0) && (uVar6 = 0x21, (uVar8 & 0xc000) != 0x4000)) &&
       (uVar6 = 0x2c, (uVar8 & 0xc000) != 0x8000)) {
      uVar6 = 3;
    }
    cVar7 = *(char *)((uint3)uVar6 << 0xe | (uint3)(uVar8 & 0x3fff));
    uVar6 = 0x24;
    if ((((uVar8 & 0xc000) != 0) && (uVar6 = 0x21, (uVar8 & 0xc000) != 0x4000)) &&
       (uVar6 = 0x2c, (uVar8 & 0xc000) != 0x8000)) {
      uVar6 = 3;
    }
    cVar9 = egs52_update_near_c34a_09e304
                      (CONCAT11(*(undefined1 *)((uint3)uVar4 << 0xe | (uint3)(uVar1 & 0x3fff)),
                                *(undefined1 *)((uint3)uVar5 << 0xe | (uint3)(uVar2 & 0x3fff))),
                       *(undefined1 *)((uint3)uVar3 << 0xe | (uint3)(uRam00f462 & 0x3fff)),
                       iRam00f464,*(undefined1 *)((uint3)uVar6 << 0xe | (uint3)(uVar8 & 0x3fff)));
    if (cVar9 == '\0') {
      cRam00f581 = '\0';
      uVar3 = Ram00fdea;
      Ram00fdea = uVar3 & 0xfffb;
      uVar3 = Ram00fdea;
      Ram00fdea = uVar3 & 0xfff7;
      bRam00f469 = cVar7 + 1;
      cVar9 = cRam00f581;
    }
    else if (cVar9 == 'x') {
      uVar3 = Ram00fdea;
      Ram00fdea = uVar3 | 4;
      uVar3 = Ram00fdea;
      Ram00fdea = uVar3 | 8;
      cRam00f581 = 'x';
      iRam00f464 = iRam00f464 + (uint)bRam00f469;
      cVar9 = cRam00f581;
    }
    else if (cVar9 == -1) {
      uVar3 = Ram00fdec;
      Ram00fdec = uVar3 & 0xfffe;
      cVar9 = cRam00f581;
    }
  }
  else {
    cRam00f581 = 'y';
    cVar9 = cRam00f581;
  }
  cRam00f581 = cVar9;
  return;
}


