/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x096a60; FLS offset 0x016a60.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x096abc) */
/* WARNING: Removing unreachable block (ram,0x096ab6) */
/* WARNING: Removing unreachable block (ram,0x096ab2) */
/* WARNING: Removing unreachable block (ram,0x096a9e) */
/* WARNING: Removing unreachable block (ram,0x096a9a) */
/* WARNING: Removing unreachable block (ram,0x096a96) */
/* WARNING: Removing unreachable block (ram,0x096a68) */
/* WARNING: Removing unreachable block (ram,0x096acc) */
/* WARNING: Removing unreachable block (ram,0x096a6c) */

void egs52_update_near_c130_096a60(void)

{
  uint uVar1;
  char cVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  ushort uVar6;
  byte bVar7;
  
  uVar1 = Ram00fd00;
  if ((uVar1 & 0x100) == 0) {
    uVar1 = Ram00fd00;
    Ram00fd00 = uVar1 | 0x100;
    uVar1 = Ram00fdf2;
    egs52_update_near_c112_096564(0);
    egs52_update_near_f878_0965b0();
    egs52_register_sequence_0965ae();
    uVar6 = egs52_get_operating_mask();
    if (uVar6 != 0x100) {
      egs52_update_near_c16e_097350();
      egs52_update_near_c16e_097350();
    }
    cVar2 = UNK_00c12d;
    UNK_00c12d = cVar2 + '\x01';
    uVar5 = Ram00fdf2;
    bVar7 = (char)uVar5 - (char)uVar1;
    UNK_00c130 = bVar7;
    bVar3 = UNK_00c131;
    bVar4 = UNK_00c131;
    if (bVar7 != bVar4 && bVar3 <= bVar7) {
      UNK_00c131 = bVar7;
    }
    egs52_transform_memory_0a4678(1,-(uint)((uVar5 & 0xff) < (uVar1 & 0xff)));
  }
  else {
    uVar1 = Ram00fdf0;
    Ram00fdf0 = uVar1 | 0x800;
  }
  uVar1 = Ram00fd00;
  Ram00fd00 = uVar1 & 0xfeff;
  return;
}


