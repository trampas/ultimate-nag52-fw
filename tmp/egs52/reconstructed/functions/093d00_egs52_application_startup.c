/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x093d00; FLS offset 0x013d00.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: This function may have set the stack pointer */

void egs52_application_startup(void)

{
  Ram00f024 = 0xc03;
  Ram00ff12 = 0x28c;
  Ram00ff0c = 0x5be;
  Ram00ff14 = 0x858e;
  Ram00fe18 = 0x1007;
  Ram00ff16 = 0;
  Ram00fe1a = 0;
  Ram00fe14 = 0xfa0c;
  Ram00fe16 = 0xfc00;
  egs52_transform_memory_092780();
  egs52_update_near_fd02_0a7b9e(0,0,0);
  do {
    __idle();
  } while( true );
}


