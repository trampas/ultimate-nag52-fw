/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a6784; FLS offset 0x026784.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a6802) */
/* WARNING: Removing unreachable block (ram,0x0a67ee) */
/* WARNING: Removing unreachable block (ram,0x0a67dc) */
/* WARNING: Removing unreachable block (ram,0x0a67cc) */
/* WARNING: Removing unreachable block (ram,0x0a67c8) */
/* WARNING: Removing unreachable block (ram,0x0a67a6) */
/* WARNING: Removing unreachable block (ram,0x0a67b6) */
/* WARNING: Removing unreachable block (ram,0x0a67f2) */
/* WARNING: Removing unreachable block (ram,0x0a67a2) */

void egs52_update_near_cdb4_0a6784(char param_1)

{
  uint uVar1;
  undefined2 uVar2;
  
  if (param_1 == '\0') {
    uVar1 = Ram00f160;
    Ram00f160 = uVar1 & 0xff7f;
    uVar1 = Ram00f160;
    Ram00f160 = uVar1 & 0xffbf;
    __atomic(1);
    uVar1 = Ram00f122;
    Ram00f122 = uVar1 & 0xfff0 | 2;
    uVar2 = Ram00fcf8;
    Ram00cdb4 = uVar2;
    uVar1 = Ram00f160;
    Ram00f160 = uVar1 | 0x40;
    Ram00fecc = 0x5ff;
    Ram00fcfa = 0xff1c;
    return;
  }
  if (param_1 != '\x01') {
    if (param_1 == '\x02') {
      uVar1 = Ram00f166;
      Ram00f166 = uVar1 & 0xff7f;
      uVar1 = Ram00f166;
      Ram00f166 = uVar1 & 0xffbf;
      __atomic(1);
      uVar1 = Ram00f122;
      Ram00f122 = uVar1 & 0xfff | 0x2000;
      uVar2 = Ram00fcf0;
      Ram00cdb8 = uVar2;
      uVar1 = Ram00f166;
      Ram00f166 = uVar1 | 0x40;
      Ram00fec8 = 0x5ff;
      Ram00fcf2 = 0xff1c;
    }
    return;
  }
  uVar1 = Ram00f162;
  Ram00f162 = uVar1 & 0xff7f;
  uVar1 = Ram00f162;
  Ram00f162 = uVar1 & 0xffbf;
  __atomic(1);
  uVar1 = Ram00f122;
  Ram00f122 = uVar1 & 0xff0f | 0x20;
  uVar2 = Ram00fcec;
  Ram00cdb6 = uVar2;
  uVar1 = Ram00f162;
  Ram00f162 = uVar1 | 0x40;
  Ram00fec6 = 0x5ff;
  Ram00fcee = 0xff1c;
  return;
}


