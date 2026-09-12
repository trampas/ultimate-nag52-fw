/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x094e52; FLS offset 0x014e52.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x094e5e) */
/* WARNING: Removing unreachable block (ram,0x094e5a) */

void egs52_call_0964d2_094e52(void)

{
  char cVar1;
  uint uVar2;
  
  uVar2 = egs52_compute_from_near_f61e_0964d2();
  if ((uVar2 & 0x200) != 0) {
    uVar2 = 0x24;
    if ((((uRam0904e0 & 0xc000) != 0) && (uVar2 = 0x21, (uRam0904e0 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uRam0904e0 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    if ((*(uint *)((uint3)uVar2 << 0xe | (uint3)(uRam0904e0 & 0x3fff)) & 1) != 0) {
      cVar1 = egs52_match_fault_status_mask(8,1);
      if (cVar1 != '\0') {
        egs52_call_0964d2_094dfe(1);
        return;
      }
      egs52_call_0964d2_094dfe(0);
      return;
    }
    egs52_call_0964d2_094dfe(1);
  }
  return;
}


