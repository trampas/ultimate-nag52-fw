/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0812e8; FLS offset 0x0012e8.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x08132a) */
/* WARNING: Removing unreachable block (ram,0x081312) */
/* WARNING: Removing unreachable block (ram,0x08130a) */
/* WARNING: Removing unreachable block (ram,0x081306) */
/* WARNING: Removing unreachable block (ram,0x081302) */
/* WARNING: Removing unreachable block (ram,0x0812fe) */
/* WARNING: Removing unreachable block (ram,0x0812f8) */
/* WARNING: Removing unreachable block (ram,0x0812ec) */
/* WARNING: Removing unreachable block (ram,0x081320) */

undefined1 egs52_update_near_f406_0812e8(void)

{
  uint uVar1;
  byte bVar2;
  undefined1 uVar3;
  
  uVar3 = 0;
  if (((cRam00f403 == '\x02') && (uVar1 = Ram00fdee, (uVar1 & 1) != 0)) && (cRam00f406 == '\0')) {
    egs52_update_near_f615_08172a(uRam00f3f0,uRam00f3f2,uRam00f3f4,uRam00f3f6);
    bVar2 = UNK_00f615;
    if ((bVar2 & 4) == 0) {
      if ((bVar2 & 2) != 0) {
        cRam00f406 = '\x02';
        uVar3 = 1;
      }
    }
    else {
      uVar3 = 1;
      cRam00f406 = '\x01';
    }
  }
  return uVar3;
}


