/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x096f56; FLS offset 0x016f56.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x096f86) */

uint egs52_update_near_fd00_096f56(uint param_1)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  
  cVar3 = -0x80;
  while (uVar1 = Ram00fd00, (uVar1 & 0x8000) == 0) {
    if (cVar3 == '\0') {
      uVar1 = Ram00fd00;
      Ram00fd00 = uVar1 | 0x8000;
      egs52_update_fault_status(0x44,3);
    }
    else {
      cVar3 = cVar3 + -1;
    }
  }
  uVar1 = (0xe - (param_1 & 0xff)) * 2 + 0xc142;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  return *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) & 0x3ff;
}


