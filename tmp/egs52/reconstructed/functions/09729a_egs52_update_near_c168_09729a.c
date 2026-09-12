/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x09729a; FLS offset 0x01729a.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0972d4) */
/* WARNING: Removing unreachable block (ram,0x0972be) */
/* WARNING: Removing unreachable block (ram,0x0972b4) */
/* WARNING: Removing unreachable block (ram,0x0972b6) */
/* WARNING: Removing unreachable block (ram,0x0972a8) */
/* WARNING: Removing unreachable block (ram,0x0972a0) */
/* WARNING: Removing unreachable block (ram,0x09729c) */
/* WARNING: Removing unreachable block (ram,0x0972c4) */
/* WARNING: Removing unreachable block (ram,0x0972cc) */
/* WARNING: Removing unreachable block (ram,0x0972ac) */

undefined1 egs52_update_near_c168_09729a(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  UNK_00c168 = 1;
  uVar3 = Ram00c164;
  if (uVar3 == 0) {
    UNK_00c168 = 0;
    return 3;
  }
  while( true ) {
    uVar1 = uVar3 + 10;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    if (*(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) == param_1) break;
    uVar1 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    if (*(int *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) == 0) {
      UNK_00c168 = 0;
      return 3;
    }
    uVar1 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    uVar3 = *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff));
  }
  uVar3 = uVar3 + 2;
  uVar1 = 0x24;
  if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  if (*(char *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) == '\0') {
    UNK_00c168 = 0;
    return 1;
  }
  UNK_00c168 = 0;
  return 2;
}


