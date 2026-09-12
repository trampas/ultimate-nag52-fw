/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x09488a; FLS offset 0x01488a.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x094904) */
/* WARNING: Removing unreachable block (ram,0x0948fc) */
/* WARNING: Removing unreachable block (ram,0x0948f8) */
/* WARNING: Removing unreachable block (ram,0x0948f4) */
/* WARNING: Removing unreachable block (ram,0x0948ee) */
/* WARNING: Removing unreachable block (ram,0x0948da) */
/* WARNING: Removing unreachable block (ram,0x0948e6) */
/* WARNING: Removing unreachable block (ram,0x0948d0) */
/* WARNING: Removing unreachable block (ram,0x0948ca) */
/* WARNING: Removing unreachable block (ram,0x0948c2) */
/* WARNING: Removing unreachable block (ram,0x0948bc) */
/* WARNING: Removing unreachable block (ram,0x0948aa) */
/* WARNING: Removing unreachable block (ram,0x094914) */
/* WARNING: Removing unreachable block (ram,0x094892) */
/* WARNING: Removing unreachable block (ram,0x09488e) */
/* WARNING: Removing unreachable block (ram,0x09489a) */
/* WARNING: Removing unreachable block (ram,0x0948ce) */
/* WARNING: Removing unreachable block (ram,0x0948d6) */
/* WARNING: Heritage AFTER dead removal. Example location: r0x00f442 : 0x0948da */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void egs52_update_near_cab6_09488a(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  byte bVar5;
  
  if (uRam00f45e < bRam00f44e) {
    Ram00cab2 = 1;
  }
  else {
    if (uRam00f442 < 7) {
      bVar5 = 2;
      do {
        uVar2 = bVar5 - 0x84b;
        uVar1 = 0x24;
        if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) = 0xff;
        bVar5 = bVar5 + 1;
      } while (bVar5 < 8);
    }
    UNK_00f7b5 = bRam00f451 | 0x20;
    bVar5 = 1;
    for (; (bVar5 < 8 && (uRam00f442 != 0)); uRam00f442 = uRam00f442 - 1) {
      uVar2 = 0x24;
      if (((uRam00f456 & 0xc000) != 0) &&
         ((uVar2 = 0x21, (uRam00f456 & 0xc000) != 0x4000 &&
          (uVar2 = 0x2c, (uRam00f456 & 0xc000) != 0x8000)))) {
        uVar2 = 3;
      }
      uVar4 = uRam00f456 & 0x3fff;
      uRam00f456 = uRam00f456 + 1;
      uVar1 = bVar5 - 0x84b;
      uVar3 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      *(undefined1 *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)) =
           *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)uVar4);
      bVar5 = bVar5 + 1;
    }
    bRam00f451 = bRam00f451 + 1 & 0xf;
    cRam00f452 = cRam00f452 + '\x01';
    uRam00f45e = 0;
    Ram00cab6 = 0x7e;
    egs52_transform_far_memory_0a0770(2,8);
  }
  return;
}


