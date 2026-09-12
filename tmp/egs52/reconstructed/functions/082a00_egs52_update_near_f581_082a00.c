/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x082a00; FLS offset 0x002a00.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Function: egs52_boot_call_far_indirect replaced with injection: call_far_indirect */
/* WARNING: Removing unreachable block (ram,0x082a84) */
/* WARNING: Removing unreachable block (ram,0x082a82) */
/* WARNING: Removing unreachable block (ram,0x082a78) */
/* WARNING: Removing unreachable block (ram,0x082a66) */
/* WARNING: Removing unreachable block (ram,0x082a54) */
/* WARNING: Removing unreachable block (ram,0x082a44) */
/* WARNING: Removing unreachable block (ram,0x082a36) */
/* WARNING: Removing unreachable block (ram,0x082af4) */
/* WARNING: Removing unreachable block (ram,0x082af2) */
/* WARNING: Removing unreachable block (ram,0x082aea) */
/* WARNING: Removing unreachable block (ram,0x082ad8) */
/* WARNING: Removing unreachable block (ram,0x082ac6) */
/* WARNING: Removing unreachable block (ram,0x082ab6) */
/* WARNING: Removing unreachable block (ram,0x082aae) */
/* WARNING: Removing unreachable block (ram,0x082aa8) */
/* WARNING: Removing unreachable block (ram,0x082a16) */
/* WARNING: Removing unreachable block (ram,0x082a12) */
/* WARNING: Removing unreachable block (ram,0x082a0a) */
/* WARNING: Removing unreachable block (ram,0x082a3c) */

void egs52_update_near_f581_082a00(void)

{
  uint uVar1;
  uint uVar2;
  
  cRam00f581 = '\x11';
  uVar2 = Ram00fdee;
  if ((uVar2 & 1) == 0) {
    (*(code *)((uint3)uRam090094 << 0x10 | (uint3)uRam090092))();
  }
  uVar2 = Ram00fdec;
  if ((uVar2 & 1) == 0) {
    uVar2 = Ram00fde8;
    if ((uVar2 & 1) == 0) {
      uVar2 = 0x31c;
      uVar1 = 0;
      do {
        if (*(char *)((uint3)(uVar2 + 4 & 0x3fff) | 0x80000) == cRam00f582) {
          egs52_update_near_f581_082b14
                    ((*(byte *)((uint3)(uVar2 + 7 & 0x3fff) | 0x80000) & 0xf) << 8 |
                     (*(byte *)((uint3)(uVar2 + 6 & 0x3fff) | 0x80000) & 0xf) << 4 |
                     *(byte *)((uint3)(uVar2 + 5 & 0x3fff) | 0x80000) & 0xf);
          if (cRam00f581 != '\0') {
            return;
          }
          (*(code *)((uint3)*(uint *)((uint3)(uVar2 + 2 & 0x3fff) | 0x80000) << 0x10 |
                    (uint3)*(uint *)((uint3)(uVar2 & 0x3fff) | 0x80000)))();
          return;
        }
        uVar2 = uVar2 + 8;
        uVar1 = uVar1 + 1;
      } while (uVar1 < 0x11);
    }
    else {
      uVar2 = 0x28c;
      uVar1 = 0;
      do {
        if (*(char *)((uint3)(uVar2 + 4 & 0x3fff) | 0x80000) == cRam00f582) {
          egs52_update_near_f581_082b14
                    ((*(byte *)((uint3)(uVar2 + 7 & 0x3fff) | 0x80000) & 0xf) << 8 |
                     (*(byte *)((uint3)(uVar2 + 6 & 0x3fff) | 0x80000) & 0xf) << 4 |
                     *(byte *)((uint3)(uVar2 + 5 & 0x3fff) | 0x80000) & 0xf);
          if (cRam00f581 != '\0') {
            return;
          }
          (*(code *)((uint3)*(uint *)((uint3)(uVar2 + 2 & 0x3fff) | 0x80000) << 0x10 |
                    (uint3)*(uint *)((uint3)(uVar2 & 0x3fff) | 0x80000)))();
          return;
        }
        uVar2 = uVar2 + 8;
        uVar1 = uVar1 + 1;
      } while (uVar1 < 0x12);
    }
  }
  else {
    uVar2 = Ram00fdec;
    Ram00fdec = uVar2 & 0xfffe;
  }
  return;
}


