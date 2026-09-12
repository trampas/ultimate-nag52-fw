/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0e31ae; FLS offset 0x0631ae.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Function: egs52_divide_u32_registers replaced with injection: egs52_udiv32_registers */
/* WARNING: Removing unreachable block (ram,0x0e32e0) */
/* WARNING: Removing unreachable block (ram,0x0e32ce) */
/* WARNING: Removing unreachable block (ram,0x0e32b6) */
/* WARNING: Removing unreachable block (ram,0x0e32b2) */
/* WARNING: Removing unreachable block (ram,0x0e32ae) */
/* WARNING: Removing unreachable block (ram,0x0e32a6) */
/* WARNING: Removing unreachable block (ram,0x0e3296) */
/* WARNING: Removing unreachable block (ram,0x0e3292) */
/* WARNING: Removing unreachable block (ram,0x0e3278) */
/* WARNING: Removing unreachable block (ram,0x0e3270) */
/* WARNING: Removing unreachable block (ram,0x0e3266) */
/* WARNING: Removing unreachable block (ram,0x0e3258) */
/* WARNING: Removing unreachable block (ram,0x0e3262) */
/* WARNING: Removing unreachable block (ram,0x0e3250) */
/* WARNING: Removing unreachable block (ram,0x0e324c) */
/* WARNING: Removing unreachable block (ram,0x0e3248) */
/* WARNING: Removing unreachable block (ram,0x0e323a) */
/* WARNING: Removing unreachable block (ram,0x0e321e) */
/* WARNING: Removing unreachable block (ram,0x0e3234) */
/* WARNING: Removing unreachable block (ram,0x0e3230) */
/* WARNING: Removing unreachable block (ram,0x0e3216) */
/* WARNING: Removing unreachable block (ram,0x0e3210) */
/* WARNING: Removing unreachable block (ram,0x0e320c) */
/* WARNING: Removing unreachable block (ram,0x0e3208) */
/* WARNING: Removing unreachable block (ram,0x0e31ea) */
/* WARNING: Removing unreachable block (ram,0x0e31de) */
/* WARNING: Removing unreachable block (ram,0x0e31d2) */
/* WARNING: Removing unreachable block (ram,0x0e31ca) */
/* WARNING: Removing unreachable block (ram,0x0e31c2) */
/* WARNING: Removing unreachable block (ram,0x0e31b2) */
/* WARNING: Removing unreachable block (ram,0x0e31fa) */
/* WARNING: Removing unreachable block (ram,0x0e322c) */
/* WARNING: Removing unreachable block (ram,0x0e3242) */
/* WARNING: Removing unreachable block (ram,0x0e325e) */
/* WARNING: Removing unreachable block (ram,0x0e327e) */
/* WARNING: Removing unreachable block (ram,0x0e32a0) */
/* WARNING: Removing unreachable block (ram,0x0e32c8) */
/* WARNING: Removing unreachable block (ram,0x0e32d2) */
/* WARNING: Unknown calling convention */

void egs52_pack_scaled_status_fields(void)

{
  uint uVar1;
  uint uVar2;
  undefined2 uVar3;
  int iVar4;
  undefined1 uVar5;
  byte bVar6;
  char cVar7;
  undefined2 uVar8;
  
  uVar2 = Ram00fd54;
  uVar1 = Ram00fd3e;
  Ram00fd3e = uVar1 & 0xfffe | (uVar2 & 0x20) >> 5;
  uVar2 = Ram00d3be;
  uVar1 = Ram00fd3e;
  Ram00fd3e = uVar1 & 0xfffd | (uVar2 & 1) << 1;
  uVar2 = Ram00fd54;
  uVar1 = Ram00fd3e;
  Ram00fd3e = uVar1 & 0xfffb | ((uVar2 & 0x40) >> 6) << 2;
  uVar2 = Ram00fd5a;
  uVar1 = Ram00fd3e;
  Ram00fd3e = uVar1 & 0xfff7 | ((uVar2 & 0x20) >> 5) << 3;
  uVar2 = Ram00d3e6;
  uVar1 = Ram00fd3e;
  Ram00fd3e = uVar1 & 0xffef | (uVar2 & 1) << 4;
  uVar2 = Ram00d3e6;
  uVar1 = Ram00fd3e;
  Ram00fd3e = uVar1 & 0xffdf | ((uVar2 & 2) >> 1) << 5;
  uVar2 = Ram00d3e6;
  uVar1 = Ram00fd3e;
  Ram00fd3e = uVar1 & 0xffbf | ((uVar2 & 4) >> 2) << 6;
  uVar2 = Ram00fd42;
  uVar1 = Ram00fd3e;
  Ram00fd3e = uVar1 & 0xff7f | ((uVar2 & 2) >> 1) << 7;
  bVar6 = UNK_00d615;
  if ((((bVar6 == 0) || (5 < bVar6)) && (cVar7 = UNK_00d615, cVar7 != '\t')) && (cVar7 != '\n')) {
    iVar4 = Ram00f672;
    uVar1 = iVar4 + 0x16;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    Ram00d5c4 = *(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
    uVar1 = Ram00fd3e;
    Ram00fd3e = uVar1 & 0xfeff;
  }
  else {
    iVar4 = Ram00d5c4;
    if (iVar4 == 0) {
      uVar1 = Ram00fd3e;
      Ram00fd3e = uVar1 | 0x100;
    }
    else {
      uVar1 = Ram00fd3e;
      Ram00fd3e = uVar1 & 0xfeff;
    }
  }
  uVar1 = Ram00d3be;
  if ((uVar1 & 1) == 0) {
    iVar4 = Ram00d592;
    if (iVar4 == 0) {
      uVar1 = Ram00fd3e;
      Ram00fd3e = uVar1 | 0x200;
    }
    else {
      uVar1 = Ram00fd3e;
      Ram00fd3e = uVar1 & 0xfdff;
    }
  }
  else {
    iVar4 = Ram00f672;
    uVar1 = iVar4 + 0x18;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    Ram00d592 = *(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
    uVar1 = Ram00fd3e;
    Ram00fd3e = uVar1 & 0xfdff;
  }
  uVar1 = Ram00fd60;
  if ((uVar1 & 2) == 0) {
    uVar5 = UNK_00d5cc;
    UNK_00d5cb = uVar5;
  }
  else {
    UNK_00d5cb = 0xff;
  }
  uVar1 = Ram00fd62;
  if ((uVar1 & 1) == 0) {
    uVar3 = Ram00d4fa;
    Ram00d4f4 = uVar3;
  }
  else {
    Ram00d4f4 = 0xffff;
  }
  uVar1 = Ram00d524;
  if ((uVar1 < 0x1de3) && (uVar1 = Ram00fd62, (uVar1 & 4) == 0)) {
    uVar1 = Ram00d524;
    UNK_00d520 = (char)(uVar1 / 0x1e);
  }
  else {
    UNK_00d520 = 0xff;
  }
  uVar1 = Ram00d3ae;
  if (uVar1 < 0x3fd) {
    uVar1 = Ram00d3ae;
    UNK_00d5f4 = (char)(uVar1 >> 2);
  }
  else {
    UNK_00d5f4 = 0xff;
  }
  uVar1 = Ram00fdf2;
  uVar2 = Ram00fdf4;
  if (uVar2 - 0x3df == (uint)(uVar1 < 0xd240) && uVar1 == 0xd240 ||
      (uVar2 < 0x3df || uVar2 == 0x3df && uVar1 < 0xd240)) {
    uVar3 = Ram00fdf2;
    uVar8 = Ram00fdf4;
    Ram00d5f2 = (int)(CONCAT22(uVar8,uVar3) / 1000);
    return;
  }
  Ram00d5f2 = 65000;
  return;
}


