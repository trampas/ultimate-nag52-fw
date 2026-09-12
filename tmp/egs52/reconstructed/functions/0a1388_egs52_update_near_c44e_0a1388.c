/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a1388; FLS offset 0x021388.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a13c8) */
/* WARNING: Removing unreachable block (ram,0x0a139a) */
/* WARNING: Removing unreachable block (ram,0x0a139e) */
/* WARNING: Removing unreachable block (ram,0x0a13be) */
/* WARNING: Removing unreachable block (ram,0x0a13ce) */
/* WARNING: Removing unreachable block (ram,0x0a13c6) */

undefined1 egs52_update_near_c44e_0a1388(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = 0;
  do {
    uVar1 = uVar3 + 0xc4d0;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) = 0;
    uVar1 = uVar3 * 8 + 0xc456;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) = 0;
    egs52_transform_memory_0a1dd8(uVar3,0xff,1);
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x10);
  Ram00c43c = 0;
  UNK_00c44e = 0;
  Ram00f84e = 1;
  return 0;
}


