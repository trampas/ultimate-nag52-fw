/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a3d02; FLS offset 0x023d02.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a3d62) */
/* WARNING: Removing unreachable block (ram,0x0a3d4a) */
/* WARNING: Removing unreachable block (ram,0x0a3d52) */
/* WARNING: Removing unreachable block (ram,0x0a3d18) */
/* WARNING: Removing unreachable block (ram,0x0a3d0e) */
/* WARNING: Removing unreachable block (ram,0x0a3d5a) */

char egs52_update_near_caa4_0a3d02(undefined2 param_1,uchar *param_2,ushort param_3)

{
  char cVar1;
  uchar *source;
  
  cVar1 = UNK_00caa4;
  if (cVar1 == '\0') {
    UNK_00caa4 = 1;
    cVar1 = egs52_update_near_c168_09729a(param_1);
    if (cVar1 == '\x01') {
      source = (uchar *)egs52_update_near_c168_0972dc(param_1);
      if (source == (uchar *)0x0) {
        UNK_00caa4 = 0;
        cVar1 = '\x03';
      }
      else {
        egs52_memcpy_near(param_2,source,param_3);
        egs52_free_small_heap_block(source);
        UNK_00caa4 = 0;
        cVar1 = '\x01';
      }
    }
    else if (cVar1 == '\x02') {
      UNK_00caa4 = 0;
      cVar1 = '\x02';
    }
    else if (cVar1 == '\x03') {
      UNK_00caa4 = 0;
      cVar1 = '\x03';
    }
  }
  else {
    cVar1 = '\x02';
  }
  return cVar1;
}


