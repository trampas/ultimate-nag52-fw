/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x093f90; FLS offset 0x013f90.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x094150) */
/* WARNING: Removing unreachable block (ram,0x094148) */
/* WARNING: Removing unreachable block (ram,0x094140) */
/* WARNING: Removing unreachable block (ram,0x094138) */
/* WARNING: Removing unreachable block (ram,0x094130) */
/* WARNING: Removing unreachable block (ram,0x094128) */
/* WARNING: Removing unreachable block (ram,0x094120) */
/* WARNING: Removing unreachable block (ram,0x094118) */
/* WARNING: Removing unreachable block (ram,0x094110) */
/* WARNING: Removing unreachable block (ram,0x094108) */
/* WARNING: Removing unreachable block (ram,0x094100) */
/* WARNING: Removing unreachable block (ram,0x0940de) */
/* WARNING: Removing unreachable block (ram,0x0940d0) */
/* WARNING: Removing unreachable block (ram,0x0940ae) */
/* WARNING: Removing unreachable block (ram,0x0940a0) */
/* WARNING: Removing unreachable block (ram,0x094098) */
/* WARNING: Removing unreachable block (ram,0x094074) */
/* WARNING: Removing unreachable block (ram,0x094064) */
/* WARNING: Removing unreachable block (ram,0x09405c) */
/* WARNING: Removing unreachable block (ram,0x094054) */
/* WARNING: Removing unreachable block (ram,0x09404c) */
/* WARNING: Removing unreachable block (ram,0x094044) */
/* WARNING: Removing unreachable block (ram,0x09403c) */
/* WARNING: Removing unreachable block (ram,0x094034) */
/* WARNING: Removing unreachable block (ram,0x094010) */
/* WARNING: Removing unreachable block (ram,0x093fe6) */
/* WARNING: Removing unreachable block (ram,0x093fc6) */
/* WARNING: Removing unreachable block (ram,0x093f9e) */
/* WARNING: Removing unreachable block (ram,0x093f98) */
/* WARNING: Removing unreachable block (ram,0x093f92) */
/* WARNING: Removing unreachable block (ram,0x093fbc) */
/* WARNING: Removing unreachable block (ram,0x093ff0) */
/* WARNING: Removing unreachable block (ram,0x09401a) */
/* WARNING: Removing unreachable block (ram,0x09402a) */
/* WARNING: Removing unreachable block (ram,0x09407e) */
/* WARNING: Removing unreachable block (ram,0x09408e) */
/* WARNING: Removing unreachable block (ram,0x0940b8) */
/* WARNING: Removing unreachable block (ram,0x0940c6) */
/* WARNING: Removing unreachable block (ram,0x0940e8) */
/* WARNING: Removing unreachable block (ram,0x0940f6) */

void egs52_update_near_c068_093f90(void)

{
  uint uVar1;
  ushort uVar2;
  
  uVar1 = Ram00c068;
  Ram00c068 = uVar1 | 1;
  uVar1 = Ram00c068;
  Ram00c068 = uVar1 | 2;
  uVar1 = Ram00c068;
  Ram00c068 = uVar1 | 4;
  uVar1 = egs52_compute_from_near_c06e_094d98();
  if ((((uVar1 & 0x20) == 0) || (uVar2 = egs52_read_c34e_forwarder(), uVar2 >> 0xc != 0)) &&
     (uVar1 = Ram00fdec, (uVar1 & 0x800) == 0)) {
    uVar1 = Ram00c068;
    Ram00c068 = uVar1 | 8;
  }
  else {
    uVar1 = Ram00c068;
    Ram00c068 = uVar1 & 0xfff7;
  }
  uVar1 = egs52_compute_from_near_c06e_094d98();
  if ((((uVar1 & 0x20) == 0) || (uVar2 = egs52_read_c34e_forwarder(), uVar2 >> 0xc != 0)) &&
     (uVar1 = Ram00fdec, (uVar1 & 0x800) == 0)) {
    uVar1 = Ram00c068;
    Ram00c068 = uVar1 | 0x10;
  }
  else {
    uVar1 = Ram00c068;
    Ram00c068 = uVar1 & 0xffef;
  }
  uVar1 = egs52_compute_from_near_c06e_094d98();
  if ((((uVar1 & 0x20) == 0) || (uVar2 = egs52_read_c34e_forwarder(), uVar2 >> 0xc != 0)) &&
     (uVar1 = Ram00fdec, (uVar1 & 0x800) == 0)) {
    uVar1 = Ram00c068;
    Ram00c068 = uVar1 | 0x20;
  }
  else {
    uVar1 = Ram00c068;
    Ram00c068 = uVar1 & 0xffdf;
  }
  uVar1 = egs52_compute_from_near_f61e_0964d2();
  if ((uVar1 & 0x40) == 0) {
    uVar1 = Ram00c068;
    Ram00c068 = uVar1 & 0xffbf;
  }
  else {
    uVar1 = Ram00c068;
    Ram00c068 = uVar1 | 0x40;
  }
  uVar1 = Ram00c068;
  Ram00c068 = uVar1 | 0x80;
  uVar1 = Ram00c068;
  Ram00c068 = uVar1 | 0x100;
  uVar1 = Ram00c068;
  Ram00c068 = uVar1 | 0x200;
  uVar1 = Ram00c068;
  Ram00c068 = uVar1 | 0x400;
  uVar1 = Ram00c068;
  Ram00c068 = uVar1 | 0x800;
  uVar1 = Ram00c068;
  Ram00c068 = uVar1 | 0x1000;
  uVar1 = egs52_compute_from_near_f61e_0964d2();
  if ((uVar1 & 2) == 0) {
    uVar1 = Ram00c068;
    Ram00c068 = uVar1 & 0xdfff;
  }
  else {
    uVar1 = Ram00c068;
    Ram00c068 = uVar1 | 0x2000;
  }
  uVar1 = egs52_compute_from_near_f61e_0964d2();
  if ((uVar1 & 4) == 0) {
    uVar1 = Ram00c068;
    Ram00c068 = uVar1 & 0xbfff;
  }
  else {
    uVar1 = Ram00c068;
    Ram00c068 = uVar1 | 0x4000;
  }
  uVar1 = Ram00c068;
  Ram00c068 = uVar1 | 0x8000;
  uVar1 = egs52_compute_from_near_f61e_0964d2();
  if ((uVar1 & 1) == 0) {
    uVar1 = Ram00c06a;
    Ram00c06a = uVar1 & 0xfffe;
  }
  else {
    uVar1 = Ram00c06a;
    Ram00c06a = uVar1 | 1;
  }
  uVar1 = egs52_compute_from_near_f61e_0964d2();
  if ((uVar1 & 0x10) == 0) {
    uVar1 = Ram00c06a;
    Ram00c06a = uVar1 & 0xfffd;
  }
  else {
    uVar1 = Ram00c06a;
    Ram00c06a = uVar1 | 2;
  }
  uVar1 = egs52_compute_from_near_f61e_0964d2();
  if ((uVar1 & 8) == 0) {
    uVar1 = Ram00c06a;
    Ram00c06a = uVar1 & 0xfffb;
  }
  else {
    uVar1 = Ram00c06a;
    Ram00c06a = uVar1 | 4;
  }
  uVar1 = egs52_compute_from_near_f61e_0964d2();
  if ((uVar1 & 0x20) == 0) {
    uVar1 = Ram00c06a;
    Ram00c06a = uVar1 & 0xfff7;
  }
  else {
    uVar1 = Ram00c06a;
    Ram00c06a = uVar1 | 8;
  }
  uVar1 = Ram00c06a;
  Ram00c06a = uVar1 | 0x10;
  uVar1 = Ram00c06a;
  Ram00c06a = uVar1 & 0xffdf;
  uVar1 = Ram00c06a;
  Ram00c06a = uVar1 & 0xffbf;
  uVar1 = Ram00c06a;
  Ram00c06a = uVar1 & 0xff7f;
  uVar1 = Ram00c06a;
  Ram00c06a = uVar1 & 0xfeff;
  uVar1 = Ram00c06a;
  Ram00c06a = uVar1 & 0xfdff;
  uVar1 = Ram00c06a;
  Ram00c06a = uVar1 & 0xfbff;
  uVar1 = Ram00c06a;
  Ram00c06a = uVar1 & 0xf7ff;
  uVar1 = Ram00c06a;
  Ram00c06a = uVar1 & 0xefff;
  uVar1 = Ram00c06a;
  Ram00c06a = uVar1 & 0xdfff;
  return;
}


