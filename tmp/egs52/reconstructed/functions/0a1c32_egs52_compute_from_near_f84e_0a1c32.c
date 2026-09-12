/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a1c32; FLS offset 0x021c32.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a1c74) */
/* WARNING: Removing unreachable block (ram,0x0a1c4c) */
/* WARNING: Removing unreachable block (ram,0x0a1c36) */
/* WARNING: Removing unreachable block (ram,0x0a1c5e) */

byte egs52_compute_from_near_f84e_0a1c32(int param_1)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  int iVar4;
  byte bVar5;
  
  iVar4 = Ram00f84e;
  if (iVar4 != 0) {
    bVar5 = 0;
    do {
      uVar1 = (uint)bVar5 * 8 + 0xc456;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      uVar2 = (uint)bVar5 * 8 + -0x3bb0 +
              (uint)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) * 6;
      uVar1 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      bVar3 = *(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
      if ((bVar3 < 0x80) && (bVar3 != 0)) {
        uVar1 = (uint)bVar3 * 0x14 + 0x9302;
        uVar2 = 0x24;
        if (((uVar1 & 0xc000) != 0) &&
           ((uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000 && (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000))
           )) {
          uVar2 = 3;
        }
        if (param_1 == *(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff))) {
          return bVar3;
        }
      }
      bVar5 = bVar5 + 1;
    } while (bVar5 < 0x10);
  }
  return 0xf2;
}


