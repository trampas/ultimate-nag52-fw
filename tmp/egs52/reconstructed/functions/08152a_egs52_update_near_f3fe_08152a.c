/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x08152a; FLS offset 0x00152a.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x08157a) */
/* WARNING: Removing unreachable block (ram,0x081576) */
/* WARNING: Removing unreachable block (ram,0x08156e) */
/* WARNING: Removing unreachable block (ram,0x08156a) */
/* WARNING: Removing unreachable block (ram,0x081566) */
/* WARNING: Removing unreachable block (ram,0x08155e) */
/* WARNING: Removing unreachable block (ram,0x08155a) */
/* WARNING: Removing unreachable block (ram,0x081552) */
/* WARNING: Removing unreachable block (ram,0x08154a) */
/* WARNING: Removing unreachable block (ram,0x08153e) */
/* WARNING: Removing unreachable block (ram,0x08153a) */
/* WARNING: Removing unreachable block (ram,0x081532) */

undefined1 egs52_update_near_f3fe_08152a(void)

{
  uint uVar1;
  undefined1 uVar2;
  
  uVar2 = 5;
  uRam00f3fe = 0x53;
  uRam00f3ff = 0xac;
  if (cRam00f403 == '\x02') {
    uRam00f400 = 0xca;
    uRam00f401 = 0x35;
    uVar1 = Ram00fdee;
    if ((uVar1 & 0x100) != 0) {
      egs52_update_near_f615_081aa4(uRam00f5cc,uRam00f5ce);
    }
    uRam00f400 = 0;
    uRam00f401 = 0;
    uRam00f406 = 0;
  }
  else {
    uVar2 = 0;
  }
  uRam00f3fe = 0;
  uRam00f3ff = 0;
  return uVar2;
}


