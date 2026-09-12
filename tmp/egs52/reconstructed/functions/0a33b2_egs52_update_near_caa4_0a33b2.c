/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a33b2; FLS offset 0x0233b2.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a33fc) */
/* WARNING: Removing unreachable block (ram,0x0a3412) */
/* WARNING: Removing unreachable block (ram,0x0a33c6) */
/* WARNING: Removing unreachable block (ram,0x0a33bc) */
/* WARNING: Removing unreachable block (ram,0x0a340a) */

int egs52_update_near_caa4_0a33b2(uchar *param_1,undefined2 param_2,ushort param_3)

{
  char cVar1;
  uchar *destination;
  int iVar2;
  
  cVar1 = UNK_00caa4;
  if (cVar1 == '\0') {
    UNK_00caa4 = 1;
    destination = (uchar *)egs52_update_near_f876_0a3f66(param_3);
    if (destination == (uchar *)0x0) {
      UNK_00caa4 = 0;
      iVar2 = 0;
    }
    else {
      egs52_memcpy_near(destination,param_1,param_3);
      iVar2 = egs52_update_near_c166_097172(destination,param_2,param_3,1,0);
      if (iVar2 == 0) {
        egs52_free_small_heap_block(destination);
        UNK_00caa4 = 0;
        iVar2 = 0;
      }
      else {
        UNK_00caa4 = 0;
      }
    }
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}


