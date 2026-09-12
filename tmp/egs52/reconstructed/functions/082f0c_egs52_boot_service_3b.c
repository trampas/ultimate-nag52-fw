/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x082f0c; FLS offset 0x002f0c.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x083026) */
/* WARNING: Removing unreachable block (ram,0x083022) */
/* WARNING: Removing unreachable block (ram,0x08301e) */
/* WARNING: Removing unreachable block (ram,0x08301a) */
/* WARNING: Removing unreachable block (ram,0x083016) */
/* WARNING: Removing unreachable block (ram,0x082ffa) */
/* WARNING: Removing unreachable block (ram,0x082fe4) */
/* WARNING: Removing unreachable block (ram,0x082fa4) */
/* WARNING: Removing unreachable block (ram,0x082f86) */
/* WARNING: Removing unreachable block (ram,0x082f9e) */
/* WARNING: Removing unreachable block (ram,0x082f7e) */
/* WARNING: Removing unreachable block (ram,0x082f5e) */
/* WARNING: Removing unreachable block (ram,0x082f78) */
/* WARNING: Removing unreachable block (ram,0x082f54) */
/* WARNING: Removing unreachable block (ram,0x082f3a) */
/* WARNING: Removing unreachable block (ram,0x082f38) */
/* WARNING: Removing unreachable block (ram,0x082f34) */
/* WARNING: Removing unreachable block (ram,0x082f30) */
/* WARNING: Removing unreachable block (ram,0x083012) */
/* WARNING: Removing unreachable block (ram,0x082f1c) */
/* WARNING: Removing unreachable block (ram,0x082f18) */
/* WARNING: Removing unreachable block (ram,0x082f10) */
/* WARNING: Removing unreachable block (ram,0x082f28) */
/* WARNING: Removing unreachable block (ram,0x082fd6) */
/* WARNING: Removing unreachable block (ram,0x082fbe) */
/* WARNING: Removing unreachable block (ram,0x082fe0) */
/* WARNING: Removing unreachable block (ram,0x083008) */
/* WARNING: Removing unreachable block (ram,0x082ffe) */
/* WARNING: Heritage AFTER dead removal. Example location: r0x00f469 : 0x082fa4 */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void egs52_boot_service_3b(void)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  
  uRam00f3fe = 0x53;
  uRam00f3ff = 0xac;
  if (cRam00f407 == '\0') {
    uRam00f400 = 0xca;
    uRam00f401 = 0x35;
    uVar1 = 0x24;
    if ((((uRam00f462 & 0xc000) != 0) && (uVar1 = 0x21, (uRam00f462 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uRam00f462 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    uVar2 = uRam00f462 & 0x3fff;
    uRam00f462 = uRam00f462 + 1;
    cVar3 = *(char *)((uint3)uVar1 << 0xe | (uint3)uVar2);
    if (cVar3 == -0x76) {
      if (cRam00f469 == '\f') {
        egs52_update_near_f3e6_080c1a(uRam00f462,0x70,0xb,10);
      }
      else {
        cRam00f581 = 'y';
      }
    }
    else if (cVar3 == -0x75) {
      if (cRam00f469 == '\x06') {
        egs52_update_near_f3e6_080c1a(uRam00f462,0x7a,0xb,4);
      }
      else {
        cRam00f581 = 'y';
      }
    }
    else if (cVar3 == -6) {
      if (cRam00f469 == '\n') {
        egs52_update_near_f615_08172a(0x3e74,8,8,0);
        egs52_update_near_f3e6_080c1a(uRam00f462,0x3e74,8,8);
      }
      else {
        cRam00f581 = 'y';
      }
    }
    else {
      cRam00f581 = '\x12';
    }
    if ((cRam00f581 != '\x12') && (cRam00f581 != 'y')) {
      uVar1 = Ram00fdee;
      if ((uVar1 & 2) == 0) {
        cRam00f581 = '@';
      }
      else {
        cRam00f469 = '\x02';
        cRam00f581 = '\0';
      }
    }
  }
  else {
    cRam00f581 = '\"';
  }
  uRam00f401 = 0;
  uRam00f400 = 0;
  uRam00f3ff = 0;
  uRam00f3fe = 0;
  return;
}


