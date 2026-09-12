/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a130c; FLS offset 0x02130c.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a1322) */
/* WARNING: Removing unreachable block (ram,0x0a1310) */

undefined1 egs52_update_near_fd6c_0a130c(uint param_1)

{
  uint uVar1;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar2;
  
  iVar3 = Ram00f84e;
  if (iVar3 != 0) {
    uVar7 = 0;
    do {
      uVar6 = Ram00fd6c;
      Ram00fd6c = uVar6 & 0xfffe;
      uVar6 = 0xc43c;
      uVar4 = 0;
      uVar5 = param_1;
      do {
        uVar1 = 0x24;
        if ((((uVar6 & 0xc000) != 0) && (uVar1 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        uVar2 = 0x24;
        if ((((uVar5 & 0xc000) != 0) && (uVar2 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar5 & 0x3fff)) =
             *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar6 & 0x3fff));
        uVar6 = uVar6 + 1;
        uVar5 = uVar5 + 1;
        uVar4 = uVar4 + 1;
      } while (uVar4 < 2);
      uVar6 = Ram00fd6c;
      if ((uVar6 & 1) == 0) {
        return 0;
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < 4);
  }
  return 0xfa;
}


