/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x09941e; FLS offset 0x01941e.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x09943a) */
/* WARNING: Removing unreachable block (ram,0x09942c) */
/* WARNING: Removing unreachable block (ram,0x09941e) */

undefined2 egs52_compute_from_near_f80a_09941e(void)

{
  char cVar1;
  undefined2 uVar2;
  
  cVar1 = UNK_00f80a;
  if (cVar1 == -0x6a) {
    uVar2 = 4;
  }
  else {
    cVar1 = UNK_00fdfb;
    if (cVar1 == 'i') {
      uVar2 = 2;
    }
    else {
      cVar1 = UNK_00fdfb;
      if (cVar1 == -0x19) {
        uVar2 = 0x10;
      }
      else {
        uVar2 = 0;
      }
    }
  }
  return uVar2;
}


