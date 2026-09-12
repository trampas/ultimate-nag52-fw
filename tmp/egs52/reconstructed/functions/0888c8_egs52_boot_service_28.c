/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0888c8; FLS offset 0x0088c8.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0888da) */
/* WARNING: Removing unreachable block (ram,0x0888d4) */
/* WARNING: Removing unreachable block (ram,0x0888d0) */
/* WARNING: Removing unreachable block (ram,0x0888c8) */
/* WARNING: Removing unreachable block (ram,0x0888ea) */
/* WARNING: Removing unreachable block (ram,0x0888de) */

void egs52_boot_service_28(void)

{
  uint uVar1;
  
  if (cRam00f469 == '\x02') {
    uVar1 = 0x24;
    if ((((uRam00f462 & 0xc000) != 0) && (uVar1 = 0x21, (uRam00f462 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uRam00f462 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    if (*(char *)((uint3)uVar1 << 0xe | (uint3)(uRam00f462 & 0x3fff)) == '\x01') {
      cRam00f469 = 1;
      uRam00f581 = 0;
      uVar1 = Ram00fdec;
      Ram00fdec = uVar1 | 0x800;
      return;
    }
  }
  uRam00f581 = 0x22;
  return;
}


