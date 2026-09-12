/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x093dae; FLS offset 0x013dae.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x093dc8) */
/* WARNING: Removing unreachable block (ram,0x093db8) */
/* WARNING: Removing unreachable block (ram,0x093db4) */
/* WARNING: Removing unreachable block (ram,0x093db0) */
/* WARNING: Removing unreachable block (ram,0x093dd6) */

undefined1 egs52_transform_memory_093dae(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined1 uVar6;
  byte bVar7;
  
  uVar1 = 0x24;
  if ((((uRam09027c & 0xc000) != 0) && (uVar1 = 0x21, (uRam09027c & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uRam09027c & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  if (*(int *)((uint3)uVar1 << 0xe | (uint3)(uRam09027c & 0x3fff)) == 0) {
    uVar6 = 0x22;
  }
  else {
    uVar1 = 0x24;
    if ((((uRam09027c & 0xc000) != 0) && (uVar1 = 0x21, (uRam09027c & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uRam09027c & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    iVar3 = *(int *)((uint3)uVar1 << 0xe | (uint3)(uRam09027c & 0x3fff));
    bVar7 = 0;
    do {
      uVar4 = iVar3 + (uint)bVar7;
      uVar5 = param_1 + (uint)bVar7;
      uVar1 = 0x24;
      if ((((uVar4 & 0xc000) != 0) && (uVar1 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      uVar2 = 0x24;
      if ((((uVar5 & 0xc000) != 0) && (uVar2 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar5 & 0x3fff)) =
           *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar4 & 0x3fff));
      bVar7 = bVar7 + 1;
    } while (bVar7 < 0x2e);
    uVar1 = 0x24;
    if ((((param_2 & 0xc000) != 0) && (uVar1 = 0x21, (param_2 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (param_2 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(param_2 & 0x3fff)) = 0x2e;
    uVar6 = 0;
  }
  return uVar6;
}


