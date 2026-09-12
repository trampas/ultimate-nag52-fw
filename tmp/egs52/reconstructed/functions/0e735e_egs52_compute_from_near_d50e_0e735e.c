/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0e735e; FLS offset 0x06735e.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0e737a) */
/* WARNING: Removing unreachable block (ram,0x0e7372) */
/* WARNING: Removing unreachable block (ram,0x0e736a) */
/* WARNING: Removing unreachable block (ram,0x0e7362) */

char egs52_compute_from_near_d50e_0e735e(uint param_1)

{
  uint uVar1;
  char cVar2;
  
  uVar1 = Ram00d50e;
  cVar2 = param_1 < uVar1;
  uVar1 = Ram00d512;
  if (param_1 < uVar1) {
    cVar2 = cVar2 + '\x01';
  }
  uVar1 = Ram00d516;
  if (param_1 < uVar1) {
    cVar2 = cVar2 + '\x01';
  }
  uVar1 = Ram00d51a;
  if (param_1 < uVar1) {
    cVar2 = cVar2 + '\x01';
  }
  return cVar2;
}


