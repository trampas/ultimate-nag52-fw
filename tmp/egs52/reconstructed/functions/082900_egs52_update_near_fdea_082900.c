/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x082900; FLS offset 0x002900.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x082978) */
/* WARNING: Removing unreachable block (ram,0x08296c) */
/* WARNING: Removing unreachable block (ram,0x082966) */
/* WARNING: Removing unreachable block (ram,0x082962) */
/* WARNING: Removing unreachable block (ram,0x08295c) */
/* WARNING: Removing unreachable block (ram,0x082958) */
/* WARNING: Removing unreachable block (ram,0x082954) */
/* WARNING: Removing unreachable block (ram,0x082944) */
/* WARNING: Removing unreachable block (ram,0x08294a) */
/* WARNING: Removing unreachable block (ram,0x082938) */
/* WARNING: Removing unreachable block (ram,0x08292e) */
/* WARNING: Removing unreachable block (ram,0x08292a) */
/* WARNING: Removing unreachable block (ram,0x082926) */
/* WARNING: Removing unreachable block (ram,0x082916) */
/* WARNING: Removing unreachable block (ram,0x082910) */
/* WARNING: Removing unreachable block (ram,0x08290a) */
/* WARNING: Removing unreachable block (ram,0x082904) */
/* WARNING: Removing unreachable block (ram,0x082922) */
/* WARNING: Removing unreachable block (ram,0x08297e) */
/* WARNING: Heritage AFTER dead removal. Example location: r0x00f576 : 0x082978 */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void egs52_update_near_fdea_082900(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = Ram00fdec;
  if (((((uVar1 & 0x400) == 0) && (uRam00f572 <= iRam00f576 + 1U)) && (uRam00f578 <= uRam00f572 + 1)
      ) || (uVar1 = Ram00fdea, (uVar1 & 0x100) == 0)) {
    uVar1 = Ram00fdea;
    Ram00fdea = uVar1 & 0xfeff;
    uRam00f572 = 0;
    uRam00f5b2 = 0;
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


