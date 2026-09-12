/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x088e40; FLS offset 0x008e40.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x088e92) */
/* WARNING: Removing unreachable block (ram,0x088e88) */
/* WARNING: Removing unreachable block (ram,0x088e7a) */
/* WARNING: Removing unreachable block (ram,0x088e76) */
/* WARNING: Removing unreachable block (ram,0x088e6e) */
/* WARNING: Removing unreachable block (ram,0x088e6a) */
/* WARNING: Removing unreachable block (ram,0x088e62) */
/* WARNING: Removing unreachable block (ram,0x088e44) */
/* WARNING: Removing unreachable block (ram,0x088e9c) */

void egs52_boot_service_11(void)

{
  uint uVar1;
  
  uVar1 = Ram00fdee;
  if (((uVar1 & 1) == 0) && (cRam00f407 != '\0')) {
    uRam00f581 = 0x22;
    return;
  }
  uVar1 = Ram00fdea;
  if (((uVar1 & 4) != 0) && (uVar1 = Ram00fdea, (uVar1 & 8) == 0)) {
    __software_reset();
    return;
  }
  if (cRam00f469 != '\x02') {
    uRam00f581 = 0x79;
    return;
  }
  uVar1 = 0x24;
  if ((((uRam00f462 & 0xc000) != 0) && (uVar1 = 0x21, (uRam00f462 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uRam00f462 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  if (*(char *)((uint3)uVar1 << 0xe | (uint3)(uRam00f462 & 0x3fff)) == '\x01') {
    cRam00f469 = 1;
    uRam00f581 = 0;
    uVar1 = Ram00fdea;
    Ram00fdea = uVar1 | 4;
    uVar1 = Ram00fdea;
    Ram00fdea = uVar1 & 0xfff7;
    return;
  }
  uRam00f581 = 0x12;
  return;
}


