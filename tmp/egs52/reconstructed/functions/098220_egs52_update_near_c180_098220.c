/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x098220; FLS offset 0x018220.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x098244) */
/* WARNING: Removing unreachable block (ram,0x098236) */
/* WARNING: Removing unreachable block (ram,0x098232) */
/* WARNING: Removing unreachable block (ram,0x09822c) */

bool egs52_update_near_c180_098220(undefined2 param_1,undefined1 param_2,undefined2 param_3)

{
  bool bVar1;
  undefined2 uVar2;
  uint uVar3;
  
  __write_psw_bits(0x40,0x40);
  uVar2 = Ram00fd02;
  uVar3 = Ram00fd02;
  bVar1 = (uVar3 & 1) == 1;
  if (bVar1) {
    __write_psw_bits(0x40,0);
  }
  else {
    uVar3 = Ram00fd02;
    Ram00fd02 = uVar3 | 1;
    Ram00c180 = param_1;
    UNK_00c182 = param_2;
    Ram00c184 = param_3;
    uVar3 = Ram00ffb2;
    Ram00ffb2 = uVar3 & 0x7fff;
    uVar3 = Ram00ffb2;
    Ram00ffb2 = uVar3 | 0x20;
    uVar3 = Ram00ffb2;
    Ram00ffb2 = uVar3 | 0x10;
    uVar3 = Ram00ffb2;
    Ram00ffb2 = uVar3 | 0x8000;
    UNK_00c17e = 2;
    uVar3 = Ram00ff74;
    Ram00ff74 = uVar3 | 0x80;
  }
  return !bVar1;
}


