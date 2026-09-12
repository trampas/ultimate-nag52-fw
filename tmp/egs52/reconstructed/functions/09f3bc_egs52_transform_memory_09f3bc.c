/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x09f3bc; FLS offset 0x01f3bc.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x09f3dc) */
/* WARNING: Removing unreachable block (ram,0x09f3be) */
/* WARNING: Removing unreachable block (ram,0x09f3e8) */

void egs52_transform_memory_09f3bc(void)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  
  bVar3 = UNK_00c3a2;
  if ((bVar3 & 1) != 0) {
    egs52_compute_from_near_c160_097036();
    bVar3 = egs52_get_status_c160();
    if ((bVar3 & 2) != 0) {
      bVar3 = 0;
      do {
        uVar1 = (uint)bVar3 * 2 + 0xc39e;
        uVar2 = 0x24;
        if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        *(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) = 3000;
        bVar3 = bVar3 + 1;
      } while (bVar3 < 2);
      bVar3 = UNK_00c3a2;
      UNK_00c3a2 = bVar3 | 2;
    }
  }
  return;
}


