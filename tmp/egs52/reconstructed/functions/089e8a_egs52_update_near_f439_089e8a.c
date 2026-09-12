/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x089e8a; FLS offset 0x009e8a.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x089ee6) */
/* WARNING: Removing unreachable block (ram,0x089ede) */
/* WARNING: Removing unreachable block (ram,0x089eda) */
/* WARNING: Removing unreachable block (ram,0x089ed6) */
/* WARNING: Removing unreachable block (ram,0x089ed2) */
/* WARNING: Removing unreachable block (ram,0x089ece) */
/* WARNING: Removing unreachable block (ram,0x089ec6) */
/* WARNING: Removing unreachable block (ram,0x089ebe) */
/* WARNING: Removing unreachable block (ram,0x089eba) */
/* WARNING: Removing unreachable block (ram,0x089eb0) */
/* WARNING: Removing unreachable block (ram,0x089e98) */
/* WARNING: Removing unreachable block (ram,0x089e94) */
/* WARNING: Removing unreachable block (ram,0x089e90) */
/* WARNING: Removing unreachable block (ram,0x089ea6) */

void egs52_update_near_f439_089e8a(void)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  
  uRam00f439 = 0x30;
  uRam00f43a = 0;
  uRam00f43b = 0;
  for (bVar3 = 3; bVar3 < bRam08901a; bVar3 = bVar3 + 1) {
    uVar1 = bVar3 - 0xbc7;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) = 0xff;
  }
  bRam00f438 = bRam08901a;
  uRam00f432 = 0x11;
  uRam00f434 = uRam089026;
  uRam00f436 = uRam089028;
  uRam00f45e = 0;
  uRam00f3e0 = 0xc9;
  egs52_update_near_f422_0894ca(0xf432);
  return;
}


