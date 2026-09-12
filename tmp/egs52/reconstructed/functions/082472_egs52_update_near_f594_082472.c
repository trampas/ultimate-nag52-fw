/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x082472; FLS offset 0x002472.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0824b6) */
/* WARNING: Removing unreachable block (ram,0x082490) */
/* WARNING: Removing unreachable block (ram,0x082484) */
/* WARNING: Removing unreachable block (ram,0x08248e) */
/* WARNING: Removing unreachable block (ram,0x0824ac) */
/* WARNING: Removing unreachable block (ram,0x0824b8) */

void egs52_update_near_f594_082472(void)

{
  char cVar1;
  
  cVar1 = '\x02';
  do {
    if (*(char *)((uint3)((int)cVar1 + 0x3e7eU & 0x3fff) | 0x80000) != -1) {
      uRam00f594 = *(undefined1 *)((uint3)((int)cVar1 + 0x3e7eU & 0x3fff) | 0x80000);
      break;
    }
    cVar1 = cVar1 + -1;
  } while (-1 < cVar1);
  cVar1 = '\x02';
  do {
    if (*(char *)((uint3)((int)cVar1 + 0x3e81U & 0x3fff) | 0x80000) != -1) {
      uRam00f595 = *(undefined1 *)((uint3)((int)cVar1 + 0x3e81U & 0x3fff) | 0x80000);
      return;
    }
    cVar1 = cVar1 + -1;
  } while (-1 < cVar1);
  return;
}


