/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x099a20; FLS offset 0x019a20.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x099a88) */
/* WARNING: Removing unreachable block (ram,0x099ab4) */
/* WARNING: Removing unreachable block (ram,0x099aae) */
/* WARNING: Removing unreachable block (ram,0x099aaa) */
/* WARNING: Removing unreachable block (ram,0x099ac4) */
/* WARNING: Removing unreachable block (ram,0x099a7c) */
/* WARNING: Removing unreachable block (ram,0x099a76) */
/* WARNING: Removing unreachable block (ram,0x099a64) */
/* WARNING: Removing unreachable block (ram,0x099a42) */
/* WARNING: Removing unreachable block (ram,0x099a3e) */
/* WARNING: Removing unreachable block (ram,0x099a34) */
/* WARNING: Removing unreachable block (ram,0x099a2e) */
/* WARNING: Removing unreachable block (ram,0x099a28) */
/* WARNING: Removing unreachable block (ram,0x099ace) */
/* WARNING: Removing unreachable block (ram,0x099a4e) */
/* WARNING: Removing unreachable block (ram,0x099aa6) */
/* WARNING: Removing unreachable block (ram,0x099a8e) */
/* WARNING: Heritage AFTER dead removal. Example location: r0x00f462 : 0x099a3e */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void egs52_update_near_f581_099a20(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  char cVar8;
  
  uVar7 = uRam00f462 + 3;
  uVar2 = 0x24;
  if ((((uVar7 & 0xc000) != 0) && (uVar2 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  if ((uint)bRam00f469 == *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar7 & 0x3fff)) + 5) {
    uVar2 = uRam00f462 + 2;
    uVar3 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar3 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    uVar1 = uRam00f462 + 1;
    uVar4 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar4 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar4 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar4 = 3;
    }
    uVar5 = 0x24;
    if ((((uRam00f462 & 0xc000) != 0) && (uVar5 = 0x21, (uRam00f462 & 0xc000) != 0x4000)) &&
       (uVar5 = 0x2c, (uRam00f462 & 0xc000) != 0x8000)) {
      uVar5 = 3;
    }
    uVar6 = 0x24;
    if ((((uVar7 & 0xc000) != 0) && (uVar6 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
       (uVar6 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
      uVar6 = 3;
    }
    cVar8 = egs52_update_near_c040_093de4
                      (CONCAT11(*(undefined1 *)((uint3)uVar4 << 0xe | (uint3)(uVar1 & 0x3fff)),
                                *(undefined1 *)((uint3)uVar3 << 0xe | (uint3)(uVar2 & 0x3fff))),
                       *(undefined1 *)((uint3)uVar5 << 0xe | (uint3)(uRam00f462 & 0x3fff)),
                       uRam00f462 + 4,*(undefined1 *)((uint3)uVar6 << 0xe | (uint3)(uVar7 & 0x3fff))
                      );
    if (cVar8 == '\0') {
      cRam00f581 = '\0';
      bRam00f469 = 1;
      uVar2 = Ram00fdea;
      Ram00fdea = uVar2 & 0xfffb;
      uVar2 = Ram00fdea;
      Ram00fdea = uVar2 & 0xfff7;
      cVar8 = cRam00f581;
    }
    else if (cVar8 == 'x') {
      uVar2 = Ram00fdea;
      Ram00fdea = uVar2 | 4;
      uVar2 = Ram00fdea;
      Ram00fdea = uVar2 | 8;
      cRam00f581 = 'x';
      iRam00f464 = iRam00f464 + (uint)bRam00f469;
      cVar8 = cRam00f581;
    }
    else if (cVar8 == -1) {
      uVar2 = Ram00fdec;
      Ram00fdec = uVar2 & 0xfffe;
      cVar8 = cRam00f581;
    }
  }
  else {
    cRam00f581 = 'y';
    cVar8 = cRam00f581;
  }
  cRam00f581 = cVar8;
  return;
}


