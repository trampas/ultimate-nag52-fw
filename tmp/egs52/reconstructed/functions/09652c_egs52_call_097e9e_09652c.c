/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x09652c; FLS offset 0x01652c.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x096532) */
/* WARNING: Removing unreachable block (ram,0x09652c) */

void egs52_call_097e9e_09652c(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = iRam0904e2 + 8;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  egs52_set_target_c174(*(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)));
  return;
}


