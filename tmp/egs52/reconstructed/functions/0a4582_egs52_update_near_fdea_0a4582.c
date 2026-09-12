/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a4582; FLS offset 0x024582.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a45fa) */
/* WARNING: Removing unreachable block (ram,0x0a45ee) */
/* WARNING: Removing unreachable block (ram,0x0a45e8) */
/* WARNING: Removing unreachable block (ram,0x0a45e4) */
/* WARNING: Removing unreachable block (ram,0x0a45de) */
/* WARNING: Removing unreachable block (ram,0x0a45da) */
/* WARNING: Removing unreachable block (ram,0x0a45d6) */
/* WARNING: Removing unreachable block (ram,0x0a45c6) */
/* WARNING: Removing unreachable block (ram,0x0a45cc) */
/* WARNING: Removing unreachable block (ram,0x0a45ba) */
/* WARNING: Removing unreachable block (ram,0x0a45b0) */
/* WARNING: Removing unreachable block (ram,0x0a45ac) */
/* WARNING: Removing unreachable block (ram,0x0a45a8) */
/* WARNING: Removing unreachable block (ram,0x0a4598) */
/* WARNING: Removing unreachable block (ram,0x0a4592) */
/* WARNING: Removing unreachable block (ram,0x0a458c) */
/* WARNING: Removing unreachable block (ram,0x0a4586) */
/* WARNING: Removing unreachable block (ram,0x0a45a4) */
/* WARNING: Removing unreachable block (ram,0x0a4600) */
/* WARNING: Heritage AFTER dead removal. Example location: r0x00f576 : 0x0a45fa */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void egs52_update_near_fdea_0a4582(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = Ram00fdec;
  if (((((uVar1 & 0x400) == 0) && (uRam00f572 <= iRam00f576 + 1U)) && (uRam00f578 <= uRam00f572 + 1)
      ) || (uVar1 = Ram00fdea, (uVar1 & 0x100) == 0)) {
    uVar1 = Ram00fdea;
    Ram00fdea = uVar1 & 0xfeff;
    uRam00f572 = 0;
    Ram00f878 = 0;
    uVar1 = 0x24;
    if ((((uRam00f45c & 0xc000) != 0) && (uVar1 = 0x21, (uRam00f45c & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uRam00f45c & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    uRam00f582 = *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uRam00f45c & 0x3fff));
    uVar1 = Ram00fde8;
    uVar2 = Ram00fdea;
    Ram00fdea = uVar2 & 0xefff | ((uVar1 & 2) >> 1) << 0xc;
    uVar1 = Ram00fde8;
    Ram00fde8 = uVar1 & 0xfffd;
    if (uRam00f45a < 0x100) {
      uRam00f469 = (undefined1)uRam00f45a;
    }
    else {
      uRam00f469 = 0xff;
      uVar1 = Ram00fdea;
      Ram00fdea = uVar1 | 0x1000;
    }
    uVar1 = Ram00fdea;
    Ram00fdea = uVar1 | 1;
    uVar1 = Ram00fdea;
    Ram00fdea = uVar1 | 2;
    uRam00f456 = uRam00f45c;
    uRam00f454 = uRam00f45c;
    iRam00f462 = uRam00f45c + 1;
    iRam00f464 = uRam00f45c + 1;
  }
  else {
    uVar1 = Ram00fdea;
    Ram00fdea = uVar1 | 0x100;
    uVar1 = Ram00fdec;
    if (((uVar1 & 0x400) == 0) && (iRam00f576 + 1U < uRam00f572)) {
      uVar1 = Ram00fdea;
      Ram00fdea = uVar1 | 0x800;
    }
  }
  uVar1 = Ram00fdec;
  Ram00fdec = uVar1 & 0xfbff;
  return;
}


