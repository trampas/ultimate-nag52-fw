/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x09bb8a; FLS offset 0x01bb8a.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x09bbbe) */
/* WARNING: Removing unreachable block (ram,0x09bbb0) */
/* WARNING: Removing unreachable block (ram,0x09bbac) */
/* WARNING: Removing unreachable block (ram,0x09bba4) */
/* WARNING: Removing unreachable block (ram,0x09bba0) */
/* WARNING: Removing unreachable block (ram,0x09bb98) */
/* WARNING: Removing unreachable block (ram,0x09bbc8) */

void egs52_update_near_f469_09bb8a(void)

{
  uint uVar1;
  
  uVar1 = Ram00fdea;
  if (((uVar1 & 4) != 0) && (uVar1 = Ram00fdea, (uVar1 & 8) == 0)) {
    egs52_software_reset();
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
  if (*(char *)((uint3)uVar1 << 0xe | (uint3)(uRam00f462 & 0x3fff)) != '\x01') {
    uRam00f581 = 0x12;
    return;
  }
  cRam00f469 = 1;
  uRam00f581 = 0;
  uVar1 = Ram00fdea;
  Ram00fdea = uVar1 | 4;
  uVar1 = Ram00fdea;
  Ram00fdea = uVar1 & 0xfff7;
  return;
}


