/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0994c8; FLS offset 0x0194c8.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0994d4) */
/* WARNING: Removing unreachable block (ram,0x0994d0) */
/* WARNING: Removing unreachable block (ram,0x0994c8) */

void egs52_service_watchdog(undefined2 param_1)

{
  undefined1 uVar1;
  
  Ram00ffae = param_1;
  __service_watchdog();
  uVar1 = UNK_00fdf2;
  UNK_00fdfc = uVar1;
  return;
}


