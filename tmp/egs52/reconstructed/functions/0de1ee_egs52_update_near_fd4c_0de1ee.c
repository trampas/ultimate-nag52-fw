/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0de1ee; FLS offset 0x05e1ee.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0de1f8) */
/* WARNING: Removing unreachable block (ram,0x0de1f2) */
/* WARNING: Removing unreachable block (ram,0x0de1ee) */

void egs52_update_near_fd4c_0de1ee(void)

{
  uint uVar1;
  byte bVar2;
  byte bVar3;
  
  bVar2 = UNK_00d454;
  bVar3 = UNK_00d613;
  if ((bVar3 <= bVar2) && (uVar1 = Ram00fd48, (uVar1 & 0x10) != 0)) {
    uVar1 = Ram00fd4c;
    Ram00fd4c = uVar1 | 0x20;
    return;
  }
  uVar1 = Ram00fd4c;
  Ram00fd4c = uVar1 & 0xffdf;
  return;
}


