/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a5f28; FLS offset 0x025f28.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a5f70) */
/* WARNING: Removing unreachable block (ram,0x0a5f68) */
/* WARNING: Removing unreachable block (ram,0x0a5f64) */
/* WARNING: Removing unreachable block (ram,0x0a5f5e) */
/* WARNING: Removing unreachable block (ram,0x0a5f5a) */
/* WARNING: Removing unreachable block (ram,0x0a5f4e) */
/* WARNING: Removing unreachable block (ram,0x0a5f4a) */
/* WARNING: Removing unreachable block (ram,0x0a5f42) */
/* WARNING: Removing unreachable block (ram,0x0a5f3e) */
/* WARNING: Removing unreachable block (ram,0x0a5f38) */
/* WARNING: Removing unreachable block (ram,0x0a5f34) */
/* WARNING: Removing unreachable block (ram,0x0a5f28) */

void egs52_update_near_f186_0a5f28(void)

{
  uint uVar1;
  byte bVar2;
  
  bVar2 = UNK_00cda2;
  if ((bVar2 & 1) != 0) {
    uVar1 = Ram00ef00;
    Ram00ef00 = uVar1 & 0xfffe;
    uVar1 = Ram00ef00;
    Ram00ef00 = uVar1 | 2;
    uVar1 = Ram00f186;
    Ram00f186 = uVar1 | 0x40;
    bVar2 = UNK_00cda2;
    UNK_00cda2 = bVar2 | 2;
  }
  bVar2 = UNK_00cda2;
  if ((bVar2 & 4) != 0) {
    uVar1 = Ram00ee00;
    Ram00ee00 = uVar1 & 0xfffe;
    uVar1 = Ram00ee00;
    Ram00ee00 = uVar1 | 2;
    uVar1 = Ram00f18e;
    Ram00f18e = uVar1 | 0x40;
    bVar2 = UNK_00cda2;
    UNK_00cda2 = bVar2 | 8;
  }
  return;
}


