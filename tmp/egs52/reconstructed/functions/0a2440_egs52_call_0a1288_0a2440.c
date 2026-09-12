/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a2440; FLS offset 0x022440.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a248e) */
/* WARNING: Removing unreachable block (ram,0x0a2472) */
/* WARNING: Removing unreachable block (ram,0x0a2480) */

undefined1 egs52_call_0a1288_0a2440(void)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  byte abStack_a [2];
  
  uVar5 = 0;
  do {
    bVar4 = egs52_update_near_fd6c_0a1288(uVar5,0xff,0xff,abStack_a);
    if ((bVar4 != 0xff) && (abStack_a[0] != 0)) {
      uVar1 = (uint)abStack_a[0] * 0x14 + 0x9308;
      uVar2 = 0x24;
      if (((uVar1 & 0xc000) != 0) &&
         ((uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000 && (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000))))
      {
        uVar2 = 3;
      }
      uVar1 = (uint)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) * 6 + 0x9002;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      bVar3 = *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
      if ((bVar4 & 0x40) == 0) {
        if (((bVar3 & 2) == 0) && ((bVar4 & 0x10) != 0)) {
          egs52_update_near_fd6c_0a2120(abStack_a[0]);
        }
      }
      else if ((bVar3 & 4) == 0) {
        uVar1 = (uint)abStack_a[0] * 0x14 + 0x9300;
        uVar2 = 0x24;
        if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        if ((*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) & 0x20) == 0) {
          egs52_update_near_fd6c_0a2120(abStack_a[0]);
        }
      }
    }
    uVar5 = uVar5 + 1;
  } while (uVar5 < 0x10);
  return 0;
}


