/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0e7216; FLS offset 0x067216.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0e7354) */
/* WARNING: Removing unreachable block (ram,0x0e734e) */
/* WARNING: Removing unreachable block (ram,0x0e7342) */
/* WARNING: Removing unreachable block (ram,0x0e733e) */
/* WARNING: Removing unreachable block (ram,0x0e733a) */
/* WARNING: Removing unreachable block (ram,0x0e7330) */
/* WARNING: Removing unreachable block (ram,0x0e7324) */
/* WARNING: Removing unreachable block (ram,0x0e7310) */
/* WARNING: Removing unreachable block (ram,0x0e72e4) */
/* WARNING: Removing unreachable block (ram,0x0e72dc) */
/* WARNING: Removing unreachable block (ram,0x0e72d4) */
/* WARNING: Removing unreachable block (ram,0x0e72ce) */
/* WARNING: Removing unreachable block (ram,0x0e72ca) */
/* WARNING: Removing unreachable block (ram,0x0e72c6) */
/* WARNING: Removing unreachable block (ram,0x0e72c0) */
/* WARNING: Removing unreachable block (ram,0x0e72bc) */
/* WARNING: Removing unreachable block (ram,0x0e72b8) */
/* WARNING: Removing unreachable block (ram,0x0e72b2) */
/* WARNING: Removing unreachable block (ram,0x0e7282) */
/* WARNING: Removing unreachable block (ram,0x0e7260) */
/* WARNING: Removing unreachable block (ram,0x0e7224) */
/* WARNING: Removing unreachable block (ram,0x0e721c) */
/* WARNING: Removing unreachable block (ram,0x0e734a) */
/* WARNING: Removing unreachable block (ram,0x0e7358) */

void egs52_update_near_d60f_0e7216(void)

{
  uint uVar1;
  uint uVar2;
  undefined1 uVar3;
  char cVar4;
  char cVar5;
  int iVar6;
  uint uVar7;
  byte bVar8;
  
  bVar8 = egs52_register_arithmetic_0a1b54();
  uVar1 = Ram00fd42;
  Ram00fd42 = uVar1 & 0xfffe | bVar8 & 1;
  uVar1 = Ram00fd14;
  uVar2 = Ram00fd42;
  Ram00fd42 = uVar2 & 0xfffd | ((uVar1 & 0x1000) >> 0xc) << 1;
  uVar1 = Ram00fd08;
  uVar2 = Ram00fd42;
  Ram00fd42 = uVar2 & 0xfffb | ((uVar1 & 0x1000) >> 0xc) << 2;
  uVar1 = Ram00fd0e;
  uVar2 = Ram00fd42;
  Ram00fd42 = uVar2 & 0xfff7 | ((uVar1 & 0x2000) >> 0xd) << 3;
  uVar1 = Ram00fd14;
  uVar2 = Ram00fd42;
  Ram00fd42 = uVar2 & 0xffef | ((uVar1 & 0x4000) >> 0xe) << 4;
  uVar1 = Ram00fd12;
  uVar2 = Ram00fd42;
  Ram00fd42 = uVar2 & 0xffdf | ((uVar1 & 0x4000) >> 0xe) << 5;
  uVar2 = Ram00fd4a;
  uVar1 = Ram00fd42;
  Ram00fd42 = uVar1 & 0xffbf | ((uVar2 & 4) >> 2) << 6;
  uVar2 = Ram00fd4a;
  uVar1 = Ram00fd42;
  Ram00fd42 = uVar1 & 0xff7f | (uVar2 & 1) << 7;
  uVar2 = Ram00fd48;
  uVar1 = Ram00fd42;
  Ram00fd42 = uVar1 & 0xfeff | ((uVar2 & 0x10) >> 4) << 8;
  uVar2 = Ram00fd48;
  uVar1 = Ram00fd42;
  Ram00fd42 = uVar1 & 0xfdff | ((uVar2 & 8) >> 3) << 9;
  uVar1 = Ram00fd10;
  uVar2 = Ram00fd42;
  Ram00fd42 = uVar2 & 0xfbff | ((uVar1 & 0x20) >> 5) << 10;
  uVar1 = Ram00fd10;
  uVar2 = Ram00fd42;
  Ram00fd42 = uVar2 & 0xf7ff | ((uVar1 & 0x40) >> 6) << 0xb;
  uVar2 = Ram00fd48;
  uVar1 = Ram00fd42;
  Ram00fd42 = uVar1 & 0xefff | ((uVar2 & 0x20) >> 5) << 0xc;
  uVar2 = Ram00fd56;
  uVar1 = Ram00fd42;
  Ram00fd42 = uVar1 & 0xdfff | ((uVar2 & 0x400) >> 10) << 0xd;
  uVar2 = Ram00fd56;
  uVar1 = Ram00fd42;
  Ram00fd42 = uVar1 & 0xbfff | ((uVar2 & 0x800) >> 0xb) << 0xe;
  cVar4 = UNK_00d474;
  if (cVar4 == '\0') {
    uVar1 = Ram00fd42;
    Ram00fd42 = uVar1 & 0x7fff;
  }
  else {
    uVar1 = Ram00fd42;
    Ram00fd42 = uVar1 | 0x8000;
  }
  uVar2 = Ram00fd48;
  uVar1 = Ram00fd40;
  Ram00fd40 = uVar1 & 0xdfff | (uVar2 & 1) << 0xd;
  uVar2 = Ram00fd48;
  uVar1 = Ram00fd40;
  Ram00fd40 = uVar1 & 0xbfff | ((uVar2 & 2) >> 1) << 0xe;
  uVar2 = Ram00fd48;
  uVar1 = Ram00fd40;
  Ram00fd40 = uVar1 & 0x7fff | ((uVar2 & 4) >> 2) << 0xf;
  uVar1 = Ram00fd26;
  uVar2 = Ram00fd40;
  Ram00fd40 = uVar2 & 0xefff | ((uVar1 & 0x20) >> 5) << 0xc;
  uVar1 = Ram00fd26;
  uVar2 = Ram00fd40;
  Ram00fd40 = uVar2 & 0xf7ff | ((uVar1 & 4) >> 2) << 0xb;
  uVar2 = Ram00d3be;
  uVar1 = Ram00fd40;
  Ram00fd40 = uVar1 & 0xfbff | (uVar2 & 1) << 10;
  uVar1 = Ram00fd14;
  uVar2 = Ram00fd40;
  Ram00fd40 = uVar2 & 0xfdff | ((uVar1 & 0x2000) >> 0xd) << 9;
  uVar1 = Ram00fd14;
  uVar2 = Ram00fd40;
  Ram00fd40 = uVar2 & 0xfeff | ((uVar1 & 0x400) >> 10) << 8;
  uVar1 = Ram00fd3c;
  uVar2 = Ram00fd40;
  Ram00fd40 = uVar2 & 0xff7f | ((uVar1 & 0x800) >> 0xb) << 7;
  uVar2 = Ram00fd56;
  uVar1 = Ram00fd40;
  Ram00fd40 = uVar1 & 0xffbf | ((uVar2 & 0x1000) >> 0xc) << 6;
  uVar2 = Ram00fd58;
  uVar1 = Ram00fd40;
  Ram00fd40 = uVar1 & 0xffdf | uVar2 & 0x20;
  uVar1 = Ram00fd30;
  uVar2 = Ram00fd40;
  Ram00fd40 = uVar2 & 0xffef | ((uVar1 & 0x40) >> 6) << 4;
  uVar2 = Ram00fd68;
  uVar1 = Ram00fd40;
  Ram00fd40 = uVar1 & 0xfff7 | (uVar2 & 1) << 3;
  uVar2 = Ram00fd56;
  uVar1 = Ram00fd40;
  Ram00fd40 = uVar1 & 0xfffb | ((uVar2 & 0x200) >> 9) << 2;
  uVar2 = Ram00fd56;
  uVar1 = Ram00fd40;
  Ram00fd40 = uVar1 & 0xfffd | ((uVar2 & 0x100) >> 8) << 1;
  uVar2 = Ram00fd56;
  uVar1 = Ram00fd40;
  Ram00fd40 = uVar1 & 0xfffe | (uVar2 & 0x80) >> 7;
  cVar4 = UNK_00d613;
  cVar5 = UNK_00d775;
  UNK_00d60f = cVar4 * '\x10' + cVar5;
  cVar5 = UNK_00d450;
  cVar4 = UNK_00d44d;
  UNK_00d44f = cVar5 * '\x10' + cVar4;
  uVar1 = Ram00fd1c;
  uVar2 = Ram00fd1e;
  uVar7 = Ram00fd36;
  Ram00fd36 = uVar7 & 0xfffe | uVar1 & 1 | uVar2 & 1;
  uVar2 = Ram00fd58;
  uVar1 = Ram00fd36;
  Ram00fd36 = uVar1 & 0xfffd | ((uVar2 & 8) >> 3) << 1;
  uVar1 = Ram00fd0c;
  uVar2 = Ram00fd36;
  Ram00fd36 = uVar2 & 0xfffb | ((uVar1 & 2) >> 1) << 2;
  uVar1 = Ram00fd04;
  uVar2 = Ram00fd36;
  Ram00fd36 = uVar2 & 0xfff7 | ((uVar1 & 0x100) >> 8) << 3;
  uVar1 = Ram00fd0c;
  uVar2 = Ram00fd36;
  Ram00fd36 = uVar2 & 0xffef | ((uVar1 & 4) >> 2) << 4;
  uVar1 = Ram00fd16;
  uVar2 = Ram00fd36;
  Ram00fd36 = uVar2 & 0xffdf | uVar1 & 0x20;
  uVar1 = Ram00fd0c;
  uVar2 = Ram00fd36;
  Ram00fd36 = uVar2 & 0xffbf | ((uVar1 & 0x10) >> 4) << 6;
  uVar1 = Ram00fd0a;
  uVar2 = Ram00fd36;
  Ram00fd36 = uVar2 & 0xff7f | (uVar1 & 1) << 7;
  uVar1 = Ram00fd1a;
  uVar2 = Ram00fd36;
  Ram00fd36 = uVar2 & 0xfeff | ((uVar1 & 0x20) >> 5) << 8;
  uVar1 = Ram00fd06;
  uVar2 = Ram00fd36;
  Ram00fd36 = uVar2 & 0xfdff | (uVar1 >> 0xf) << 9;
  uVar1 = Ram00fd1a;
  uVar2 = Ram00fd36;
  Ram00fd36 = uVar2 & 0xfbff | (uVar1 & 1) << 10;
  uVar1 = Ram00fd08;
  if ((uVar1 & 0x6000) == 0x6000) {
    uVar1 = Ram00fd36;
    Ram00fd36 = uVar1 | 0x800;
  }
  else {
    uVar1 = Ram00fd36;
    Ram00fd36 = uVar1 & 0xf7ff;
  }
  uVar1 = Ram00fd08;
  uVar2 = Ram00fd36;
  Ram00fd36 = uVar2 & 0xfff | (uVar1 >> 8) << 0xc;
  iVar6 = Ram00f61e;
  uVar1 = iVar6 + 0x1c;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  if ((*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) & 1) == 0) {
    uVar3 = UNK_00d3bd;
    UNK_00d43a = uVar3;
    return;
  }
  uVar3 = UNK_00fd16;
  UNK_00d43a = uVar3;
  return;
}


