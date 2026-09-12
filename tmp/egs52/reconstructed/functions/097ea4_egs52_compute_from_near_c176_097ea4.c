/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x097ea4; FLS offset 0x017ea4.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x097f04) */
/* WARNING: Removing unreachable block (ram,0x097ef2) */
/* WARNING: Removing unreachable block (ram,0x097eec) */
/* WARNING: Removing unreachable block (ram,0x097ecc) */
/* WARNING: Removing unreachable block (ram,0x097ebc) */
/* WARNING: Removing unreachable block (ram,0x097eb2) */
/* WARNING: Removing unreachable block (ram,0x097ea4) */
/* WARNING: Removing unreachable block (ram,0x097ec6) */

undefined2 egs52_compute_from_near_c176_097ea4(void)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = Ram00c176;
  if (uVar3 < 0x655) {
    return 0;
  }
  bVar1 = UNK_00c0eb;
  if ((bVar1 < 10) || (bVar1 = UNK_00c0eb, 0x14 < bVar1)) {
    bVar1 = UNK_00c0eb;
    if (bVar1 < 10) {
      uVar3 = 10;
    }
    else {
      uVar3 = 0x14;
    }
  }
  else {
    bVar1 = UNK_00c0eb;
    uVar3 = (uint)bVar1;
  }
  uVar2 = Ram00c176;
  if (uVar2 <= uVar3 * 3000 - 0x5dc) {
    uVar3 = Ram00c176;
    uVar2 = Ram00c178;
    return (int)(((ulong)uVar3 * 0xffff) / (ulong)uVar2);
  }
  return 0xffff;
}


