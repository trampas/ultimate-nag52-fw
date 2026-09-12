/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x094f42; FLS offset 0x014f42.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x094f4a) */
/* WARNING: Removing unreachable block (ram,0x094f6e) */
/* WARNING: Removing unreachable block (ram,0x094f60) */
/* WARNING: Removing unreachable block (ram,0x094f4e) */

void egs52_update_near_fd26_094f42(void)

{
  char cVar1;
  uint uVar2;
  
  uVar2 = egs52_compute_from_near_c06e_094d98();
  if ((uVar2 & 0x200) != 0) {
    uVar2 = 0x24;
    if ((((uRam0904e0 & 0xc000) != 0) && (uVar2 = 0x21, (uRam0904e0 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uRam0904e0 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    egs52_update_near_fd26_094e88
              ((*(uint *)((uint3)uVar2 << 0xe | (uint3)(uRam0904e0 & 0x3fff)) & 0x10) >> 4);
    return;
  }
  uVar2 = Ram00fd26;
  Ram00fd26 = uVar2 & 0xfff7;
  cVar1 = egs52_update_near_c086_094f96();
  if (cVar1 == '\0') {
    egs52_update_near_fd26_094e88(1);
    return;
  }
  uVar2 = Ram00fd26;
  Ram00fd26 = uVar2 | 8;
  cVar1 = egs52_match_fault_status_mask(9,1);
  if (cVar1 != '\0') {
    egs52_update_near_fd26_094e88(1);
    return;
  }
  egs52_update_near_fd26_094e88(0);
  return;
}


