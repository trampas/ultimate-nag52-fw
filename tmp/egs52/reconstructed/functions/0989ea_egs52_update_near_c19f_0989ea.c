/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0989ea; FLS offset 0x0189ea.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x098a40) */
/* WARNING: Removing unreachable block (ram,0x098a36) */
/* WARNING: Removing unreachable block (ram,0x098a14) */
/* WARNING: Removing unreachable block (ram,0x098a72) */
/* WARNING: Removing unreachable block (ram,0x098a68) */
/* WARNING: Removing unreachable block (ram,0x098a50) */
/* WARNING: Removing unreachable block (ram,0x098aa4) */
/* WARNING: Removing unreachable block (ram,0x098a9a) */
/* WARNING: Removing unreachable block (ram,0x098a82) */
/* WARNING: Removing unreachable block (ram,0x098a78) */
/* WARNING: Removing unreachable block (ram,0x0989fe) */
/* WARNING: Removing unreachable block (ram,0x0989f2) */
/* WARNING: Removing unreachable block (ram,0x098a46) */
/* WARNING: Removing unreachable block (ram,0x098a1e) */

void egs52_update_near_c19f_0989ea(byte param_1)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  
  uVar1 = param_1 + 0xc191;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) = 0xff;
  uVar1 = (uint)param_1 * 2 + 0xc194;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  *(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) = 0;
  if (param_1 != 1) {
    if (param_1 != 2) {
      if (param_1 == 3) {
        uVar1 = Ram00ff54;
        Ram00ff54 = uVar1 & 0xf8ff | 0x200;
        uVar1 = Ram00ff84;
        Ram00ff84 = uVar1 & 0xff7f;
        uVar1 = Ram00ffc0;
        if ((uVar1 & 0x40) == 0) {
          uVar1 = Ram00ff84;
          Ram00ff84 = uVar1 | 0x80;
        }
        Ram00fe84 = 0;
        Ram00fe94 = 0;
        uVar1 = Ram00ffc0;
        Ram00ffc0 = uVar1 | 4;
        uVar1 = Ram00ff84;
        Ram00ff84 = uVar1 | 0x40;
        bVar3 = UNK_00c19f;
        UNK_00c19f = bVar3 & 0xcf;
      }
      return;
    }
    uVar1 = Ram00ff54;
    Ram00ff54 = uVar1 & 0xff8f | 0x20;
    uVar1 = Ram00ff82;
    Ram00ff82 = uVar1 & 0xff7f;
    uVar1 = Ram00ffc0;
    if ((uVar1 & 0x20) == 0) {
      uVar1 = Ram00ff82;
      Ram00ff82 = uVar1 | 0x80;
    }
    Ram00fe82 = 0;
    Ram00fe92 = 0;
    uVar1 = Ram00ffc0;
    Ram00ffc0 = uVar1 | 2;
    uVar1 = Ram00ff82;
    Ram00ff82 = uVar1 | 0x40;
    bVar3 = UNK_00c19f;
    UNK_00c19f = bVar3 & 0xf3;
    return;
  }
  uVar1 = Ram00ff54;
  Ram00ff54 = uVar1 & 0xfff8 | 2;
  uVar1 = Ram00ff80;
  Ram00ff80 = uVar1 & 0xff7f;
  uVar1 = Ram00ffc0;
  if ((uVar1 & 0x10) == 0) {
    uVar1 = Ram00ff80;
    Ram00ff80 = uVar1 | 0x80;
  }
  Ram00fe80 = 0;
  Ram00fe90 = 0;
  uVar1 = Ram00ffc0;
  Ram00ffc0 = uVar1 | 1;
  uVar1 = Ram00ff80;
  Ram00ff80 = uVar1 | 0x40;
  bVar3 = UNK_00c19f;
  UNK_00c19f = bVar3 & 0xfc;
  return;
}


