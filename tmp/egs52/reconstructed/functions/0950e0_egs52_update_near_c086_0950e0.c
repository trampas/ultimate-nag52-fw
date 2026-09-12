/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0950e0; FLS offset 0x0150e0.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x095118) */
/* WARNING: Removing unreachable block (ram,0x09510e) */

void egs52_update_near_c086_0950e0(void)

{
  uint uVar1;
  char cVar2;
  
  cVar2 = egs52_match_fault_status_mask(0x14,1);
  if (((cVar2 == '\0') && (cVar2 = egs52_match_fault_status_mask(0x4a,1), cVar2 == '\0')) &&
     (cVar2 = egs52_match_fault_status_mask(0x4b,1), cVar2 == '\0')) {
    uVar1 = Ram00c086;
    Ram00c086 = uVar1 & 0xfbff;
    return;
  }
  uVar1 = Ram00c086;
  Ram00c086 = uVar1 | 0x400;
  return;
}


