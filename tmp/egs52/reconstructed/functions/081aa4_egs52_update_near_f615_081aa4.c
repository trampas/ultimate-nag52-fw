/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x081aa4; FLS offset 0x001aa4.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x081ae4) */
/* WARNING: Removing unreachable block (ram,0x081abe) */
/* WARNING: Removing unreachable block (ram,0x081aaa) */
/* WARNING: Removing unreachable block (ram,0x081ac6) */

void egs52_update_near_f615_081aa4(undefined2 param_1,undefined2 param_2)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  undefined1 uVar4;
  uint uVar5;
  
  uVar5 = 0;
  do {
    uVar1 = uVar5 - 0xa2c;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    cVar3 = *(char *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
    uVar5 = uVar5 + 1;
  } while ((uVar5 < 0x40) && (cVar3 == '\0'));
  if (cVar3 != '\0') {
    uVar4 = UNK_00f615;
    UNK_00f615 = 0x10;
    egs52_update_near_f3e6_080c1a(0xf5d4,param_1,param_2,0x40);
    uVar5 = Ram00fdee;
    if ((uVar5 & 2) == 0) {
      uVar5 = Ram00fdee;
      Ram00fdee = uVar5 | 0x200;
    }
    UNK_00f615 = uVar4;
  }
  uVar5 = Ram00fdee;
  Ram00fdee = uVar5 & 0xfeff;
  return;
}


