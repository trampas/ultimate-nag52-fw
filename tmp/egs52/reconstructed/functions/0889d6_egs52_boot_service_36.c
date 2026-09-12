/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0889d6; FLS offset 0x0089d6.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x088a14) */
/* WARNING: Removing unreachable block (ram,0x088a10) */
/* WARNING: Removing unreachable block (ram,0x088a30) */
/* WARNING: Removing unreachable block (ram,0x088a26) */
/* WARNING: Removing unreachable block (ram,0x088a00) */
/* WARNING: Removing unreachable block (ram,0x0889fc) */
/* WARNING: Removing unreachable block (ram,0x0889ec) */
/* WARNING: Removing unreachable block (ram,0x0889e8) */
/* WARNING: Removing unreachable block (ram,0x0889e2) */
/* WARNING: Removing unreachable block (ram,0x088a3a) */
/* WARNING: Removing unreachable block (ram,0x0889d8) */
/* WARNING: Removing unreachable block (ram,0x0889de) */
/* WARNING: Removing unreachable block (ram,0x0889f6) */

void egs52_boot_service_36(void)

{
  uint uVar1;
  char cVar2;
  
  if (cRam00f407 == '\0') {
    bRam00f469 = bRam00f469 - 1;
    uVar1 = (uint)bRam00f469;
    if (-iRam00f3f6 == (uint)(uVar1 < uRam00f3f4) && uVar1 == uRam00f3f4 ||
        (iRam00f3f6 != 0 || iRam00f3f6 == 0 && uVar1 < uRam00f3f4)) {
      cVar2 = egs52_update_near_f3fe_081334(uRam00f462,bRam00f469);
      if (cVar2 == '\x01') {
        bRam00f469 = 1;
        uRam00f581 = 0;
      }
      else if ((cVar2 == '\x03') || (cVar2 == '\x02')) {
        uRam00f581 = 0x42;
      }
      else {
        uRam00f581 = 0x22;
      }
    }
    else {
      uRam00f581 = 0x79;
    }
  }
  else {
    uRam00f581 = 0x22;
  }
  return;
}


