/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0e357c; FLS offset 0x06357c.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0e35aa) */
/* WARNING: Removing unreachable block (ram,0x0e35a2) */
/* WARNING: Removing unreachable block (ram,0x0e3586) */
/* WARNING: Removing unreachable block (ram,0x0e357c) */
/* WARNING: Removing unreachable block (ram,0x0e3590) */

void egs52_update_near_fd38_0e357c(void)

{
  uint uVar1;
  char cVar2;
  
  uVar1 = Ram00d3b0;
  if (uVar1 < 0x265) {
    uVar1 = Ram00fd38;
    Ram00fd38 = uVar1 & 0xfffb;
    uVar1 = Ram00fd38;
    Ram00fd38 = uVar1 & 0xfff7;
    return;
  }
  cVar2 = UNK_00d615;
  if (cVar2 == '\a') {
    uVar1 = Ram00fd38;
    Ram00fd38 = uVar1 & 0xfffb;
    uVar1 = Ram00fd38;
    if ((uVar1 & 8) == 0) {
      uVar1 = Ram00fd38;
      Ram00fd38 = uVar1 | 8;
      return;
    }
    uVar1 = Ram00fd38;
    Ram00fd38 = uVar1 | 0x10;
    return;
  }
  uVar1 = Ram00fd38;
  Ram00fd38 = uVar1 & 0xfff7;
  cVar2 = UNK_00d615;
  if (cVar2 != '\x05') {
    uVar1 = Ram00fd38;
    Ram00fd38 = uVar1 & 0xfffb;
    return;
  }
  uVar1 = Ram00fd38;
  if ((uVar1 & 4) == 0) {
    uVar1 = Ram00fd38;
    Ram00fd38 = uVar1 | 4;
    return;
  }
  uVar1 = Ram00fd38;
  Ram00fd38 = uVar1 | 0x10;
  return;
}


