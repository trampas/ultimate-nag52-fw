/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x09f3f8; FLS offset 0x01f3f8.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x09f460) */
/* WARNING: Removing unreachable block (ram,0x09f408) */
/* WARNING: Removing unreachable block (ram,0x09f44c) */
/* WARNING: Removing unreachable block (ram,0x09f434) */
/* WARNING: Removing unreachable block (ram,0x09f41e) */
/* WARNING: Removing unreachable block (ram,0x09f420) */
/* WARNING: Removing unreachable block (ram,0x09f446) */

void egs52_transform_far_memory_09f3f8(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined2 uVar4;
  byte bVar5;
  
  bVar5 = 0;
  do {
    uVar3 = (uint)bVar5 * 4;
    uVar4 = egs52_update_near_fd00_096f56(*(undefined1 *)((uint3)(uVar3 + 0x9a2) | 0x90000),0);
    uVar2 = (uint)bVar5 * 8 + 0xc38e;
    uVar1 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    *(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) = uVar4;
    uVar1 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    uVar4 = egs52_compute_from_near_c3a2_09f510
                      (*(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)),
                       *(undefined2 *)CONCAT12((0xc0d7 < uVar3) + '\b',uVar3 + 0x3f28),
                       *(undefined2 *)CONCAT12((0xc0d5 < uVar3) + '\b',uVar3 + 0x3f2a));
    uVar1 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    *(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) = uVar4;
    uVar4 = egs52_update_near_c3a8_09f592(uVar2,0x9aa,9);
    egs52_update_near_c161_097052(*(undefined1 *)((uint3)(uVar3 + 0x9a3) | 0x90000),uVar4);
    bVar5 = bVar5 + 1;
  } while (bVar5 < 2);
  return;
}


