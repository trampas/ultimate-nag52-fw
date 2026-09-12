/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x09653c; FLS offset 0x01653c.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x096558) */
/* WARNING: Removing unreachable block (ram,0x096540) */

void egs52_update_near_d3e2_09653c(void)

{
  undefined2 uVar1;
  int iVar2;
  
  uVar1 = egs52_compute_from_near_c176_097ea4();
  Ram00d3e2 = uVar1;
  iVar2 = egs52_scale_c17a_to_u16();
  UNK_00d3e4 = (char)((uint)(iVar2 * 100) / 0xffff);
  return;
}


