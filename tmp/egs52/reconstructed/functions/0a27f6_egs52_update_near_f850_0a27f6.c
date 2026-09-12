/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a27f6; FLS offset 0x0227f6.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a2820) */
/* WARNING: Removing unreachable block (ram,0x0a2800) */
/* WARNING: Removing unreachable block (ram,0x0a2806) */
/* WARNING: Removing unreachable block (ram,0x0a280c) */
/* WARNING: Removing unreachable block (ram,0x0a282c) */

undefined1 egs52_update_near_f850_0a27f6(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = 0xc608;
  uVar3 = 0;
  do {
    uVar1 = uVar4 + 0x37;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) = 0xff;
    uVar1 = 0x24;
    if ((((uVar4 & 0xc000) != 0) && (uVar1 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar4 & 0x3fff)) = 0;
    uVar4 = uVar4 + 0x38;
    uVar1 = uVar3 + 0xca6c;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) = 0;
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x14);
  uVar4 = 0;
  do {
    uVar3 = uVar4 * 2 + 0xca68;
    uVar1 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    *(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) = 0;
    uVar4 = uVar4 + 1;
  } while (uVar4 < 2);
  Ram00f850 = 1;
  return 0;
}


