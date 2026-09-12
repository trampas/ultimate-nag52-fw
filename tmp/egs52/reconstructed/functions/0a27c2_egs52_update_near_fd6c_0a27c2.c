/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a27c2; FLS offset 0x0227c2.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a27d2) */

undefined1 egs52_update_near_fd6c_0a27c2(uint param_1)

{
  uint uVar1;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar2;
  
  uVar6 = 0;
  while( true ) {
    uVar5 = Ram00fd6c;
    Ram00fd6c = uVar5 & 0xfffd;
    uVar5 = 0xca68;
    uVar4 = 0;
    uVar3 = param_1;
    do {
      uVar1 = 0x24;
      if ((((uVar5 & 0xc000) != 0) && (uVar1 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      uVar2 = 0x24;
      if ((((uVar3 & 0xc000) != 0) && (uVar2 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      *(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar3 & 0x3fff)) =
           *(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(uVar5 & 0x3fff));
      uVar5 = uVar5 + 2;
      uVar3 = uVar3 + 2;
      uVar4 = uVar4 + 1;
    } while (uVar4 < 2);
    uVar5 = Ram00fd6c;
    if ((uVar5 & 2) == 0) break;
    uVar6 = uVar6 + 1;
    if (3 < uVar6) {
      return 0xfa;
    }
  }
  return 0;
}


