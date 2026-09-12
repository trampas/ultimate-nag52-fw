/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0969da; FLS offset 0x0169da.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x096a08) */
/* WARNING: Removing unreachable block (ram,0x096a04) */
/* WARNING: Removing unreachable block (ram,0x0969f8) */

void egs52_compute_from_near_c13e_0969da(void)

{
  char cVar1;
  ushort uVar2;
  
  egs52_update_near_c2c3_09b302();
  egs52_call_0a638a_0a5490();
  uVar2 = egs52_get_operating_mask();
  if (uVar2 == 0x100) {
    egs52_update_near_c16e_097350();
    egs52_update_near_c0bc_095130();
    egs52_update_near_c16e_097350();
  }
  cVar1 = UNK_00c13e;
  if (cVar1 != '\0') {
    egs52_update_near_cacc_0a476e(0);
    cVar1 = UNK_00c13e;
    UNK_00c13e = cVar1 + -1;
  }
  cVar1 = UNK_00c12a;
  UNK_00c12a = cVar1 + '\x01';
  return;
}


