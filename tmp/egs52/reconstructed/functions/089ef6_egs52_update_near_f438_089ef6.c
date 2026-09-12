/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x089ef6; FLS offset 0x009ef6.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x089fa8) */
/* WARNING: Removing unreachable block (ram,0x089fa4) */
/* WARNING: Removing unreachable block (ram,0x089fa0) */
/* WARNING: Removing unreachable block (ram,0x089f9c) */
/* WARNING: Removing unreachable block (ram,0x089f94) */
/* WARNING: Removing unreachable block (ram,0x089f8c) */
/* WARNING: Removing unreachable block (ram,0x089f84) */
/* WARNING: Removing unreachable block (ram,0x089f80) */
/* WARNING: Removing unreachable block (ram,0x089f7c) */
/* WARNING: Removing unreachable block (ram,0x089f76) */
/* WARNING: Removing unreachable block (ram,0x089f4e) */
/* WARNING: Removing unreachable block (ram,0x089f5e) */
/* WARNING: Removing unreachable block (ram,0x089f6e) */
/* WARNING: Removing unreachable block (ram,0x089f68) */
/* WARNING: Removing unreachable block (ram,0x089f5a) */
/* WARNING: Removing unreachable block (ram,0x089f52) */
/* WARNING: Removing unreachable block (ram,0x089f46) */
/* WARNING: Removing unreachable block (ram,0x089f40) */
/* WARNING: Removing unreachable block (ram,0x089f2e) */
/* WARNING: Removing unreachable block (ram,0x089f2a) */
/* WARNING: Removing unreachable block (ram,0x089f3c) */
/* WARNING: Removing unreachable block (ram,0x089f38) */
/* WARNING: Removing unreachable block (ram,0x089f04) */
/* WARNING: Removing unreachable block (ram,0x089efc) */
/* WARNING: Removing unreachable block (ram,0x089ef8) */
/* WARNING: Removing unreachable block (ram,0x089fb8) */
/* WARNING: Removing unreachable block (ram,0x089f20) */
/* WARNING: Removing unreachable block (ram,0x089f16) */
/* WARNING: Removing unreachable block (ram,0x089f54) */
/* WARNING: Heritage AFTER dead removal. Example location: r0x00f442 : 0x089f5e */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void egs52_update_near_f438_089ef6(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  byte bVar5;
  
  if (uRam00f45e < bRam00f44e) {
    uRam00f3e2 = 1;
  }
  else {
    if (uRam00f442 < 7) {
      for (bVar5 = 2; bVar5 < bRam08901a; bVar5 = bVar5 + 1) {
        uVar2 = bVar5 - 0xbc7;
        uVar1 = 0x24;
        if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) = 0xff;
      }
    }
    bRam00f439 = bRam00f451 | 0x20;
    bVar5 = 1;
    bRam00f438 = bRam08901a;
    for (; (bVar5 < bRam08901a && (uRam00f442 != 0)); uRam00f442 = uRam00f442 - 1) {
      uVar2 = 0x24;
      if (((uRam00f456 & 0xc000) != 0) &&
         ((uVar2 = 0x21, (uRam00f456 & 0xc000) != 0x4000 &&
          (uVar2 = 0x2c, (uRam00f456 & 0xc000) != 0x8000)))) {
        uVar2 = 3;
      }
      uVar4 = uRam00f456 & 0x3fff;
      uRam00f456 = uRam00f456 + 1;
      uVar1 = bVar5 - 0xbc7;
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
    uRam00f3e0 = 0xc9;
    uRam00f432 = 0x11;
    uRam00f434 = uRam089026;
    uRam00f436 = uRam089028;
    egs52_update_near_f422_0894ca(0xf432);
  }
  return;
}


