/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a58e2; FLS offset 0x0258e2.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a5996) */
/* WARNING: Removing unreachable block (ram,0x0a5978) */
/* WARNING: Removing unreachable block (ram,0x0a595a) */
/* WARNING: Removing unreachable block (ram,0x0a593c) */
/* WARNING: Removing unreachable block (ram,0x0a591e) */
/* WARNING: Removing unreachable block (ram,0x0a5900) */
/* WARNING: Removing unreachable block (ram,0x0a58e2) */

void egs52_compute_from_near_f3e4_0a58e2(void)

{
  if ((uRam00f3e4 & 4) == 0) {
    egs52_update_fault_status(0x3e,2);
  }
  else {
    egs52_update_fault_status(0x3e,3);
  }
  if ((uRam00f3e4 & 2) == 0) {
    egs52_update_fault_status(0x3e,2);
  }
  else {
    egs52_update_fault_status(0x3e,3);
  }
  if ((uRam00f3e4 & 8) == 0) {
    egs52_update_fault_status(0x3e,2);
  }
  else {
    egs52_update_fault_status(0x3e,3);
  }
  if ((uRam00f3e4 & 0x10) == 0) {
    egs52_update_fault_status(0x42,2);
  }
  else {
    egs52_update_fault_status(0x42,3);
  }
  if ((uRam00f3e4 & 0x20) == 0) {
    egs52_update_fault_status(0x43,2);
  }
  else {
    egs52_update_fault_status(0x43,3);
  }
  if ((uRam00f3e4 & 0x400) == 0) {
    egs52_update_fault_status(0x3a,2);
  }
  else {
    egs52_update_fault_status(0x3a,3);
  }
  if ((uRam00f3e4 & 0x800) == 0) {
    egs52_update_fault_status(0x3c,2);
    return;
  }
  egs52_update_fault_status(0x3c,3);
  return;
}


