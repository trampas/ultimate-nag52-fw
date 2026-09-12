/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x09f35a; FLS offset 0x01f35a.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x09f3b4) */
/* WARNING: Removing unreachable block (ram,0x09f39a) */
/* WARNING: Removing unreachable block (ram,0x09f3ae) */
/* WARNING: Removing unreachable block (ram,0x09f394) */
/* WARNING: Removing unreachable block (ram,0x09f36a) */
/* WARNING: Removing unreachable block (ram,0x09f3a6) */
/* WARNING: Removing unreachable block (ram,0x09f3a0) */

void egs52_update_near_c3a2_09f35a(void)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  ushort uVar4;
  
  egs52_update_near_f03c_096ff2();
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
  bVar3 = egs52_get_status_c160();
  if ((bVar3 & 1) != 0) {
    uVar4 = egs52_crc16_a001_far(0x3f28,8,0x10,0);
    if (uVar4 == uRam083fbe) {
      bVar3 = UNK_00c3a2;
      UNK_00c3a2 = bVar3 | 4;
    }
    else {
      bVar3 = UNK_00c3a2;
      UNK_00c3a2 = bVar3 & 0xfb;
    }
    bVar3 = UNK_00c3a2;
    UNK_00c3a2 = bVar3 | 1;
  }
  return;
}


