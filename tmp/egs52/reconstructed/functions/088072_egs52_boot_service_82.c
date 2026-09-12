/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x088072; FLS offset 0x008072.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x08808c) */

void egs52_boot_service_82(void)

{
  uint uVar1;
  
  uVar1 = Ram00fdea;
  if (((uVar1 & 4) != 0) && (uVar1 = Ram00fdea, (uVar1 & 8) == 0)) {
    egs52_update_near_f1c6_08244a();
    egs52_update_near_f57f_082392();
    egs52_update_near_f406_081a2e();
    return;
  }
  uVar1 = Ram00fdea;
  Ram00fdea = uVar1 | 4;
  uVar1 = Ram00fdea;
  Ram00fdea = uVar1 & 0xfff7;
  uRam00f581 = 0;
  return;
}


