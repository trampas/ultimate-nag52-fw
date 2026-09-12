/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a24c8; FLS offset 0x0224c8.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

undefined1 egs52_call_09f858_0a24c8(void)

{
  uchar uVar1;
  char cVar2;
  
  uVar1 = egs52_initialize_fault_status();
  if (uVar1 != '\0') {
    return 0xff;
  }
  cVar2 = egs52_update_near_c44e_0a1388();
  if (cVar2 != '\0') {
    return 0xfe;
  }
  cVar2 = egs52_transform_memory_0a2418();
  if (cVar2 != '\0') {
    return 0xfd;
  }
  cVar2 = egs52_update_near_f850_0a27f6();
  if (cVar2 == '\0') {
    return 0;
  }
  return 0xfc;
}


