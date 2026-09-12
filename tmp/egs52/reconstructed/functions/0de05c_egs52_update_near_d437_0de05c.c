/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0de05c; FLS offset 0x05e05c.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0de06a) */
/* WARNING: Removing unreachable block (ram,0x0de09a) */
/* WARNING: Removing unreachable block (ram,0x0de096) */
/* WARNING: Removing unreachable block (ram,0x0de092) */
/* WARNING: Removing unreachable block (ram,0x0de08e) */
/* WARNING: Removing unreachable block (ram,0x0de0c4) */
/* WARNING: Removing unreachable block (ram,0x0de0c0) */
/* WARNING: Removing unreachable block (ram,0x0de0bc) */
/* WARNING: Removing unreachable block (ram,0x0de0b8) */
/* WARNING: Removing unreachable block (ram,0x0de0b2) */
/* WARNING: Removing unreachable block (ram,0x0de0ae) */
/* WARNING: Removing unreachable block (ram,0x0de0a0) */
/* WARNING: Removing unreachable block (ram,0x0de084) */
/* WARNING: Removing unreachable block (ram,0x0de062) */
/* WARNING: Removing unreachable block (ram,0x0de074) */
/* WARNING: Removing unreachable block (ram,0x0de06e) */

void egs52_update_near_d437_0de05c(char param_1)

{
  uint uVar1;
  char cVar2;
  byte bVar3;
  
  uVar1 = Ram00fd4a;
  Ram00fd4a = uVar1 | 8;
  cVar2 = UNK_00d437;
  if (cVar2 == '\0') {
    UNK_00d437 = 0;
    UNK_00d577 = param_1;
  }
  else {
    bVar3 = UNK_00d437;
    if ((bVar3 < 2) &&
       ((param_1 == '\x03' || ((param_1 == '\x02' && (bVar3 = UNK_00d566, bVar3 < 3)))))) {
      UNK_00d437 = 1;
      UNK_00d577 = param_1;
      UNK_00d567 = 0;
      UNK_00d5b1 = 0;
    }
    else {
      bVar3 = UNK_00d437;
      if ((bVar3 < 4) && (param_1 == '\x03')) {
        UNK_00d437 = 1;
        UNK_00d577 = 3;
        UNK_00d566 = 3;
        UNK_00d567 = 1;
        UNK_00d5b0 = 0;
        UNK_00d5b1 = 0;
      }
      else {
        uVar1 = Ram00fd4a;
        Ram00fd4a = uVar1 & 0xfff7;
      }
    }
  }
  return;
}


