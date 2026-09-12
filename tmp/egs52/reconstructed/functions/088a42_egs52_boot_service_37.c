/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x088a42; FLS offset 0x008a42.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x088a8a) */
/* WARNING: Removing unreachable block (ram,0x088a80) */
/* WARNING: Removing unreachable block (ram,0x088a76) */
/* WARNING: Removing unreachable block (ram,0x088a6c) */
/* WARNING: Removing unreachable block (ram,0x088a66) */
/* WARNING: Removing unreachable block (ram,0x088a5c) */
/* WARNING: Removing unreachable block (ram,0x088a58) */
/* WARNING: Removing unreachable block (ram,0x088a42) */
/* WARNING: Removing unreachable block (ram,0x088a48) */

void egs52_boot_service_37(void)

{
  char cVar1;
  
  if (cRam00f407 != '\0') {
    uRam00f581 = 0x22;
    return;
  }
  if (cRam00f469 != '\x01') {
    uRam00f581 = 0x79;
    return;
  }
  cVar1 = egs52_update_near_f3fe_08152a();
  if (cVar1 != '\x05') {
    uRam00f581 = 0x22;
    return;
  }
  if (iRam00f3f6 == 0 && iRam00f3f4 == 0) {
    uRam00f581 = 0;
    return;
  }
  uRam00f581 = 0x22;
  return;
}


