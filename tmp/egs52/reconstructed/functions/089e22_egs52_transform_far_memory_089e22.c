/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x089e22; FLS offset 0x009e22.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Function: egs52_boot_call_far_indirect replaced with injection: call_far_indirect */
/* WARNING: Removing unreachable block (ram,0x089e3a) */
/* WARNING: Removing unreachable block (ram,0x089e4c) */
/* WARNING: Removing unreachable block (ram,0x089e32) */
/* WARNING: Removing unreachable block (ram,0x089e36) */
/* WARNING: Removing unreachable block (ram,0x089e48) */

void egs52_transform_far_memory_089e22(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = 0;
  do {
    uVar2 = uVar4 * 2 - 0xc20;
    uVar1 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    if (*(int *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) != 0) {
      uVar1 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      iVar3 = *(int *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) + -1;
      uVar1 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(int *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) = iVar3;
      if (iVar3 == 0) {
        (*(code *)((uint3)*(uint *)((uint3)(uVar4 * 4 + 0x1088 & 0x3fff) | 0x88000) << 0x10 |
                  (uint3)*(uint *)((uint3)(uVar4 * 4 + 0x1086 & 0x3fff) | 0x88000)))();
      }
    }
    uVar4 = uVar4 + 1;
  } while (uVar4 < 2);
  return;
}


