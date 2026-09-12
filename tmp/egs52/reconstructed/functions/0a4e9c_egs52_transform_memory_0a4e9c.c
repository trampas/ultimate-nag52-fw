/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a4e9c; FLS offset 0x024e9c.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a4f16) */
/* WARNING: Removing unreachable block (ram,0x0a4f12) */
/* WARNING: Removing unreachable block (ram,0x0a4f08) */
/* WARNING: Removing unreachable block (ram,0x0a4efc) */
/* WARNING: Removing unreachable block (ram,0x0a4ef4) */
/* WARNING: Removing unreachable block (ram,0x0a4ed2) */
/* WARNING: Removing unreachable block (ram,0x0a4ebe) */
/* WARNING: Removing unreachable block (ram,0x0a4eac) */

undefined1 egs52_transform_memory_0a4e9c(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uchar index;
  int iVar4;
  uchar uVar5;
  
  iVar4 = (param_1 & 0xff) * 8;
  uVar1 = iVar4 + 0xc456;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  uVar2 = iVar4 + -0x3bb0 + (uint)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) * 6;
  uVar1 = 0x24;
  if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  index = *(uchar *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
  uVar5 = egs52_test_fault_status_bit4(index);
  if (uVar5 != '\0') {
    uVar1 = uVar2 + 1;
    uVar3 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    if ((*(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)) & 0x40) == 0) {
      egs52_update_near_cce8_0a4fc0(index,0);
    }
    else {
      egs52_update_near_cce8_0a4fc0(index,1);
    }
  }
  uVar1 = uVar2 + 1;
  uVar3 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar3 = 3;
  }
  if ((*(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)) & 0x20) != 0) {
    uVar1 = uVar2 + 2;
    uVar3 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    if (*(byte *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)) < 2) {
      return 0;
    }
  }
  uVar2 = uVar2 + 4;
  uVar1 = 0x24;
  if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  if (*(char *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) == -1) {
    return 0;
  }
  uVar1 = 0x24;
  if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  uVar3 = 0x24;
  if ((((uVar2 & 0xc000) != 0) && (uVar3 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
     (uVar3 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
    uVar3 = 3;
  }
  *(char *)((uint3)uVar3 << 0xe | (uint3)(uVar2 & 0x3fff)) =
       *(char *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) + '\x01';
  return 1;
}


