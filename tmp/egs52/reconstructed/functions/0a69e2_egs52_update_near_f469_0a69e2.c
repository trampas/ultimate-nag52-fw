/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a69e2; FLS offset 0x0269e2.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a6a70) */
/* WARNING: Removing unreachable block (ram,0x0a6a54) */
/* WARNING: Removing unreachable block (ram,0x0a6a4c) */
/* WARNING: Removing unreachable block (ram,0x0a6a40) */
/* WARNING: Removing unreachable block (ram,0x0a6a3a) */
/* WARNING: Removing unreachable block (ram,0x0a6a36) */
/* WARNING: Removing unreachable block (ram,0x0a6a2a) */
/* WARNING: Removing unreachable block (ram,0x0a6a20) */
/* WARNING: Removing unreachable block (ram,0x0a6a1c) */
/* WARNING: Removing unreachable block (ram,0x0a69f8) */
/* WARNING: Removing unreachable block (ram,0x0a6a68) */
/* WARNING: Removing unreachable block (ram,0x0a69e4) */
/* WARNING: Removing unreachable block (ram,0x0a69ee) */
/* WARNING: Removing unreachable block (ram,0x0a69f2) */
/* WARNING: Removing unreachable block (ram,0x0a6a5e) */
/* WARNING: Heritage AFTER dead removal. Example location: r0x00f469 : 0x0a6a3a */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void egs52_update_near_f469_0a69e2(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  char cVar4;
  
  if (bRam00f469 == 3) {
    uVar2 = 0x24;
    if ((((uRam00f462 & 0xc000) != 0) && (uVar2 = 0x21, (uRam00f462 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uRam00f462 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    uVar1 = uRam00f462 + 1;
    uVar3 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    cVar4 = egs52_update_near_cdf4_0a7ab6
                      (CONCAT11(*(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uRam00f462 & 0x3fff)),
                                *(undefined1 *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff))));
    if (cVar4 == -2) {
      bRam00f469 = 3;
      cRam00f581 = '\0';
    }
    else if (cVar4 == -4) {
      cRam00f581 = 'x';
      uVar2 = Ram00fdea;
      if ((uVar2 & 4) == 0) {
        uVar2 = Ram00fdea;
        Ram00fdea = uVar2 | 4;
        uVar2 = Ram00fdea;
        Ram00fdea = uVar2 | 8;
        cRam00f581 = 0x78;
        iRam00f464 = iRam00f464 + (uint)bRam00f469;
        return;
      }
      uVar2 = Ram00fdec;
      Ram00fdec = uVar2 | 4;
    }
    else if (cVar4 == -1) {
      bRam00f469 = 2;
      cRam00f581 = '1';
    }
    else {
      cRam00f581 = '\"';
    }
  }
  else {
    cRam00f581 = 'y';
  }
  uVar2 = Ram00fdea;
  if (((uVar2 & 4) != 0) && (cRam00f581 != 'x')) {
    uVar2 = Ram00fdea;
    Ram00fdea = uVar2 & 0xfffb;
    uVar2 = Ram00fdea;
    Ram00fdea = uVar2 & 0xfff7;
  }
  return;
}


