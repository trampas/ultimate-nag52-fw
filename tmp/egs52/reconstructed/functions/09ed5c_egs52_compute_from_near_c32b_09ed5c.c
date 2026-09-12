/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x09ed5c; FLS offset 0x01ed5c.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x09eda4) */
/* WARNING: Removing unreachable block (ram,0x09ed8e) */
/* WARNING: Removing unreachable block (ram,0x09ed84) */
/* WARNING: Removing unreachable block (ram,0x09ed80) */
/* WARNING: Removing unreachable block (ram,0x09ed6e) */
/* WARNING: Removing unreachable block (ram,0x09ed66) */
/* WARNING: Removing unreachable block (ram,0x09ed60) */
/* WARNING: Removing unreachable block (ram,0x09ed5c) */
/* WARNING: Removing unreachable block (ram,0x09ed78) */

undefined1 egs52_compute_from_near_c32b_09ed5c(void)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  undefined2 uVar4;
  byte bVar5;
  byte bVar6;
  int iVar7;
  
  bVar3 = UNK_00c32b;
  bVar5 = UNK_00c32c;
  bVar6 = UNK_00c32c;
  if ((bVar3 == bVar6 || bVar3 < bVar5) && (bVar5 = UNK_00c32a, (bVar5 & 2) != 0)) {
    iVar7 = Ram00c330;
    if (iVar7 != 0) {
      uVar2 = iVar7 + (uint)bVar3;
      uVar1 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      return *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
    }
    uVar1 = Ram00f682;
    uVar4 = Ram00f684;
    bVar3 = UNK_00c32b;
    return *(undefined1 *)
            CONCAT12((char)uVar4 + (0xfff5 < uVar1) + CARRY2(uVar1 + 10,(uint)bVar3 * 0xc),
                     uVar1 + 10 + (uint)bVar3 * 0xc);
  }
  return 0xff;
}


