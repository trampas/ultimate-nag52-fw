/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a1220; FLS offset 0x021220.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a1264) */
/* WARNING: Removing unreachable block (ram,0x0a122a) */
/* WARNING: Removing unreachable block (ram,0x0a1252) */

undefined1 egs52_update_near_fd6c_0a1220(undefined1 param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  byte bVar5;
  uint uVar6;
  
  iVar3 = Ram00f84e;
  if (iVar3 != 0) {
    uVar6 = 0;
    do {
      uVar1 = Ram00fd6c;
      Ram00fd6c = uVar1 & 0xfffe;
      bVar5 = egs52_register_arithmetic_0a134c(param_1);
      if (bVar5 == 0xfd) {
        return 0xff;
      }
      iVar3 = (uint)bVar5 * 8;
      uVar1 = iVar3 + 0xc456;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      uVar2 = iVar3 + -0x3baf + (uint)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) * 6;
      uVar1 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      uVar4 = Ram00fd6c;
      if ((uVar4 & 1) == 0) {
        return *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < 4);
  }
  return 0xff;
}


