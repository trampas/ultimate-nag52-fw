/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0de0d0; FLS offset 0x05e0d0.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0de0de) */
/* WARNING: Removing unreachable block (ram,0x0de110) */
/* WARNING: Removing unreachable block (ram,0x0de10c) */
/* WARNING: Removing unreachable block (ram,0x0de108) */
/* WARNING: Removing unreachable block (ram,0x0de0fe) */
/* WARNING: Removing unreachable block (ram,0x0de0fa) */
/* WARNING: Removing unreachable block (ram,0x0de0f6) */
/* WARNING: Removing unreachable block (ram,0x0de0f2) */
/* WARNING: Removing unreachable block (ram,0x0de0d2) */
/* WARNING: Removing unreachable block (ram,0x0de0ec) */
/* WARNING: Removing unreachable block (ram,0x0de0e4) */

void egs52_update_near_d437_0de0d0(undefined1 param_1)

{
  uint uVar1;
  byte bVar2;
  
  uVar1 = Ram00fd4a;
  Ram00fd4a = uVar1 | 8;
  bVar2 = UNK_00d437;
  if (bVar2 < 2) {
    if (bVar2 == 0) {
      UNK_00d437 = 0;
      UNK_00d577 = param_1;
      return;
    }
    UNK_00d437 = 1;
    UNK_00d577 = param_1;
    UNK_00d567 = 0;
    UNK_00d5b1 = 0;
    bVar2 = UNK_00d566;
    if (3 < bVar2) {
      UNK_00d437 = 2;
      UNK_00d566 = 0;
      UNK_00d5b0 = 0;
      return;
    }
  }
  else {
    uVar1 = Ram00fd4a;
    Ram00fd4a = uVar1 & 0xfff7;
  }
  return;
}


