/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a44ec; FLS offset 0x0244ec.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a4530) */
/* WARNING: Removing unreachable block (ram,0x0a450a) */
/* WARNING: Removing unreachable block (ram,0x0a44fe) */
/* WARNING: Removing unreachable block (ram,0x0a4508) */
/* WARNING: Removing unreachable block (ram,0x0a4526) */
/* WARNING: Removing unreachable block (ram,0x0a4532) */

void egs52_update_near_f594_0a44ec(void)

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


