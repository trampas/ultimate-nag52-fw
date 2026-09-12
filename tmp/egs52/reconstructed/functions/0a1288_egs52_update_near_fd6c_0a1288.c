/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a1288; FLS offset 0x021288.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a12e2) */
/* WARNING: Removing unreachable block (ram,0x0a12ec) */
/* WARNING: Removing unreachable block (ram,0x0a12a4) */
/* WARNING: Removing unreachable block (ram,0x0a1290) */
/* WARNING: Removing unreachable block (ram,0x0a12ba) */

byte egs52_update_near_fd6c_0a1288(uint param_1,byte param_2,byte param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  byte bVar5;
  uint uVar6;
  
  iVar4 = Ram00f84e;
  if (iVar4 != 0) {
    iVar4 = (param_1 & 0xff) * 8;
    uVar1 = iVar4 + 0xc456;
    uVar6 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar6 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar6 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar6 = 3;
    }
    uVar1 = iVar4 + -0x3bb0 + (uint)*(byte *)((uint3)uVar6 << 0xe | (uint3)(uVar1 & 0x3fff)) * 6;
    uVar6 = 0;
    do {
      uVar2 = Ram00fd6c;
      Ram00fd6c = uVar2 & 0xfffe;
      uVar2 = uVar1 + 1;
      uVar3 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar3 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      bVar5 = *(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar2 & 0x3fff));
      if (bVar5 != 0xff) {
        if ((param_2 == 0xff) && (param_3 == 0xff)) {
          uVar2 = 0x24;
          if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
             (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
            uVar2 = 3;
          }
          uVar3 = 0x24;
          if ((((param_4 & 0xc000) != 0) && (uVar3 = 0x21, (param_4 & 0xc000) != 0x4000)) &&
             (uVar3 = 0x2c, (param_4 & 0xc000) != 0x8000)) {
            uVar3 = 3;
          }
          *(undefined1 *)((uint3)uVar3 << 0xe | (uint3)(param_4 & 0x3fff)) =
               *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
        }
        else if ((bVar5 & param_2) == param_3) {
          uVar2 = 0x24;
          if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
             (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
            uVar2 = 3;
          }
          uVar3 = 0x24;
          if ((((param_4 & 0xc000) != 0) && (uVar3 = 0x21, (param_4 & 0xc000) != 0x4000)) &&
             (uVar3 = 0x2c, (param_4 & 0xc000) != 0x8000)) {
            uVar3 = 3;
          }
          *(undefined1 *)((uint3)uVar3 << 0xe | (uint3)(param_4 & 0x3fff)) =
               *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
        }
        else {
          bVar5 = 0xff;
        }
      }
      uVar2 = Ram00fd6c;
      if ((uVar2 & 1) == 0) {
        return bVar5;
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < 4);
  }
  return 0xff;
}


