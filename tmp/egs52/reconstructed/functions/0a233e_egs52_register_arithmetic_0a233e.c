/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a233e; FLS offset 0x02233e.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a23b6) */
/* WARNING: Removing unreachable block (ram,0x0a2390) */
/* WARNING: Removing unreachable block (ram,0x0a2352) */
/* WARNING: Removing unreachable block (ram,0x0a238a) */
/* WARNING: Removing unreachable block (ram,0x0a23d8) */

undefined1 egs52_register_arithmetic_0a233e(byte param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined1 uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar1 = (uint)param_1 * 0x14 + 0x9308;
  uVar6 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar6 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar6 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar6 = 3;
  }
  uVar1 = (uint)*(byte *)((uint3)uVar6 << 0xe | (uint3)(uVar1 & 0x3fff)) * 6 + 0x9000;
  uVar6 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar6 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar6 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar6 = 3;
  }
  uVar1 = *(uint *)((uint3)uVar6 << 0xe | (uint3)(uVar1 & 0x3fff));
  uVar6 = Ram00c606;
  if ((uVar6 & uVar1) == uVar1) {
    uVar6 = 0;
    uVar5 = uVar1;
    do {
      if (uVar5 == 0) break;
      if ((uVar5 & 1) != 0) {
        uVar2 = (uint)(param_1 >> 4) * 2 + (uVar6 & 0xff) * 0x10 + 0xc506;
        uVar3 = 0x24;
        if ((((uVar2 & 0xc000) != 0) && (uVar3 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
           (uVar3 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
          uVar3 = 3;
        }
        if ((*(uint *)((uint3)uVar3 << 0xe | (uint3)(uVar2 & 0x3fff)) & 1 << (uint)param_1 % 0x10)
            == 0) {
          return 0;
        }
      }
      uVar5 = uVar5 >> 1;
      uVar6 = uVar6 + 1;
    } while (uVar6 < 0x10);
    if (uVar1 == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = 1;
    }
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}


