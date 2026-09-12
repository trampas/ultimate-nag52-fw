/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d0086; FLS offset 0x050086.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d018e) */
/* WARNING: Removing unreachable block (ram,0x0d018a) */
/* WARNING: Removing unreachable block (ram,0x0d0186) */
/* WARNING: Removing unreachable block (ram,0x0d0182) */
/* WARNING: Removing unreachable block (ram,0x0d017e) */
/* WARNING: Removing unreachable block (ram,0x0d017a) */
/* WARNING: Removing unreachable block (ram,0x0d0176) */
/* WARNING: Removing unreachable block (ram,0x0d0172) */
/* WARNING: Removing unreachable block (ram,0x0d016a) */
/* WARNING: Removing unreachable block (ram,0x0d0160) */
/* WARNING: Removing unreachable block (ram,0x0d0156) */
/* WARNING: Removing unreachable block (ram,0x0d0112) */
/* WARNING: Removing unreachable block (ram,0x0d010e) */
/* WARNING: Removing unreachable block (ram,0x0d010a) */
/* WARNING: Removing unreachable block (ram,0x0d0106) */
/* WARNING: Removing unreachable block (ram,0x0d0102) */
/* WARNING: Removing unreachable block (ram,0x0d00fe) */
/* WARNING: Removing unreachable block (ram,0x0d00fa) */
/* WARNING: Removing unreachable block (ram,0x0d00f6) */
/* WARNING: Removing unreachable block (ram,0x0d00f2) */
/* WARNING: Removing unreachable block (ram,0x0d00ee) */
/* WARNING: Removing unreachable block (ram,0x0d00ea) */
/* WARNING: Removing unreachable block (ram,0x0d00e6) */
/* WARNING: Removing unreachable block (ram,0x0d00e2) */
/* WARNING: Removing unreachable block (ram,0x0d00de) */
/* WARNING: Removing unreachable block (ram,0x0d00da) */
/* WARNING: Removing unreachable block (ram,0x0d00d6) */
/* WARNING: Removing unreachable block (ram,0x0d00d2) */
/* WARNING: Removing unreachable block (ram,0x0d00ce) */
/* WARNING: Removing unreachable block (ram,0x0d00ca) */
/* WARNING: Removing unreachable block (ram,0x0d00c6) */
/* WARNING: Removing unreachable block (ram,0x0d00c2) */
/* WARNING: Removing unreachable block (ram,0x0d00be) */
/* WARNING: Removing unreachable block (ram,0x0d00ba) */
/* WARNING: Removing unreachable block (ram,0x0d00b6) */
/* WARNING: Removing unreachable block (ram,0x0d00b2) */
/* WARNING: Removing unreachable block (ram,0x0d00ae) */
/* WARNING: Removing unreachable block (ram,0x0d00aa) */
/* WARNING: Removing unreachable block (ram,0x0d00a6) */
/* WARNING: Removing unreachable block (ram,0x0d00a2) */
/* WARNING: Removing unreachable block (ram,0x0d009e) */
/* WARNING: Removing unreachable block (ram,0x0d009a) */
/* WARNING: Removing unreachable block (ram,0x0d0096) */
/* WARNING: Removing unreachable block (ram,0x0d0092) */
/* WARNING: Removing unreachable block (ram,0x0d008e) */
/* WARNING: Removing unreachable block (ram,0x0d008a) */
/* WARNING: Removing unreachable block (ram,0x0d0086) */

void egs52_update_near_d64a_0d0086(void)

{
  undefined2 uVar1;
  uint uVar2;
  uint uVar3;
  undefined1 uVar4;
  byte bVar5;
  
  uVar1 = Ram00d524;
  Ram00d64a = uVar1;
  uVar1 = Ram00d526;
  Ram00d640 = uVar1;
  uVar1 = Ram00d500;
  Ram00d64e = uVar1;
  uVar1 = Ram00d50c;
  Ram00d63e = uVar1;
  uVar1 = Ram00d4c8;
  Ram00d63c = uVar1;
  uVar1 = Ram00d4c4;
  Ram00d64c = uVar1;
  uVar1 = Ram00d572;
  Ram00d644 = uVar1;
  uVar4 = UNK_00d447;
  UNK_00d646 = uVar4;
  uVar4 = UNK_00d452;
  UNK_00d647 = uVar4;
  uVar4 = UNK_00d570;
  UNK_00d648 = uVar4;
  uVar4 = UNK_00d5cc;
  UNK_00d649 = uVar4;
  bVar5 = UNK_00d5cd;
  Ram00d658 = (uint)bVar5;
  uVar4 = UNK_00d577;
  UNK_00d650 = uVar4;
  uVar1 = Ram00d710;
  Ram00d652 = uVar1;
  uVar4 = UNK_00d437;
  UNK_00d651 = uVar4;
  uVar1 = Ram00d48a;
  Ram00d654 = uVar1;
  uVar1 = Ram00d464;
  Ram00d656 = uVar1;
  uVar4 = UNK_00d443;
  UNK_00d65a = uVar4;
  uVar1 = Ram00fd2a;
  uVar3 = Ram00fd60;
  uVar2 = Ram00fd2a;
  Ram00fd2a = uVar2 & 0xfff7 | (uVar3 & 1) << 3;
  uVar1 = Ram00fd2c;
  uVar3 = Ram00fd62;
  uVar2 = Ram00fd2c;
  Ram00fd2c = uVar2 & 0xfffe | (uVar3 & 4) >> 2;
  uVar1 = Ram00fd2a;
  uVar3 = Ram00fd60;
  uVar2 = Ram00fd2a;
  Ram00fd2a = uVar2 & 0xffef | ((uVar3 & 8) >> 3) << 4;
  uVar1 = Ram00fd2a;
  uVar3 = Ram00fd60;
  uVar2 = Ram00fd2a;
  Ram00fd2a = uVar2 & 0xfffb | ((uVar3 & 2) >> 1) << 2;
  uVar1 = Ram00fd2a;
  uVar3 = Ram00fd62;
  uVar2 = Ram00fd2a;
  Ram00fd2a = uVar2 & 0xffdf | ((uVar3 & 8) >> 3) << 5;
  uVar1 = Ram00fd2c;
  uVar3 = Ram00fd56;
  uVar2 = Ram00fd2c;
  Ram00fd2c = uVar2 & 0xfffd | ((uVar3 & 8) >> 3) << 1;
  uVar1 = Ram00fd2a;
  uVar3 = Ram00fd5a;
  uVar2 = Ram00fd2a;
  Ram00fd2a = uVar2 & 0xffbf | uVar3 & 0x40;
  uVar1 = Ram00fd2a;
  uVar3 = Ram00fd34;
  uVar2 = Ram00fd2a;
  Ram00fd2a = uVar2 & 0xff7f | (uVar3 & 1) << 7;
  uVar1 = Ram00fd2a;
  uVar3 = Ram00fd4a;
  uVar2 = Ram00fd2a;
  Ram00fd2a = uVar2 & 0xfeff | ((uVar3 & 0x40) >> 6) << 8;
  uVar1 = Ram00fd2a;
  uVar3 = Ram00fd4a;
  uVar2 = Ram00fd2a;
  Ram00fd2a = uVar2 & 0xfdff | ((uVar3 & 0x20) >> 5) << 9;
  uVar1 = Ram00fd2a;
  uVar3 = Ram00fd48;
  uVar2 = Ram00fd2a;
  Ram00fd2a = uVar2 & 0xfbff | ((uVar3 & 8) >> 3) << 10;
  uVar1 = Ram00fd2a;
  uVar3 = Ram00fd54;
  uVar2 = Ram00fd2a;
  Ram00fd2a = uVar2 & 0xf7ff | ((uVar3 & 0x20) >> 5) << 0xb;
  uVar1 = Ram00fd2a;
  uVar3 = Ram00fd54;
  uVar2 = Ram00fd2a;
  Ram00fd2a = uVar2 & 0xefff | (uVar3 & 1) << 0xc;
  uVar1 = Ram00fd2a;
  uVar3 = Ram00fd56;
  uVar2 = Ram00fd2a;
  Ram00fd2a = uVar2 & 0xdfff | (uVar3 & 1) << 0xd;
  uVar1 = Ram00fd2a;
  uVar3 = Ram00fd58;
  uVar2 = Ram00fd2a;
  Ram00fd2a = uVar2 & 0xbfff | ((uVar3 & 0x20) >> 5) << 0xe;
  uVar1 = Ram00fd2c;
  uVar3 = Ram00fd58;
  uVar2 = Ram00fd2c;
  Ram00fd2c = uVar2 & 0xffef | uVar3 & 0x10;
  uVar3 = Ram00fd5c;
  uVar2 = Ram00fd2c;
  Ram00fd2c = uVar2 & 0xfcff | (uVar3 >> 6 & 3) << 8;
  egs52_update_near_d6b6_0dd7fa();
  uVar4 = UNK_00d704;
  UNK_00d474 = uVar4;
  uVar1 = Ram00d706;
  Ram00d54e = uVar1;
  uVar1 = Ram00d69e;
  Ram00d40e = uVar1;
  uVar1 = Ram00d664;
  Ram00d420 = uVar1;
  uVar1 = Ram00fd46;
  uVar2 = Ram00fd2c;
  uVar3 = Ram00fd46;
  Ram00fd46 = uVar3 & 0xffef | ((uVar2 & 4) >> 2) << 4;
  uVar1 = Ram00fd46;
  uVar2 = Ram00fd2c;
  uVar3 = Ram00fd46;
  Ram00fd46 = uVar3 & 0xffdf | ((uVar2 & 8) >> 3) << 5;
  uVar1 = Ram00fd46;
  uVar2 = Ram00fd2a;
  uVar3 = Ram00fd46;
  Ram00fd46 = uVar3 & 0xfff7 | ((uVar2 & 2) >> 1) << 3;
  egs52_update_near_d3e0_0d6bee();
  return;
}


