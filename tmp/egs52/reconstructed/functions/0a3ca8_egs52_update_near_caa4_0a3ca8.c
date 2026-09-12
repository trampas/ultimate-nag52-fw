/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a3ca8; FLS offset 0x023ca8.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a3cde) */
/* WARNING: Removing unreachable block (ram,0x0a3cf4) */
/* WARNING: Removing unreachable block (ram,0x0a3cb4) */
/* WARNING: Removing unreachable block (ram,0x0a3caa) */
/* WARNING: Removing unreachable block (ram,0x0a3cec) */

int egs52_update_near_caa4_0a3ca8(undefined2 param_1,undefined2 param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  cVar1 = UNK_00caa4;
  if (cVar1 == '\0') {
    UNK_00caa4 = 1;
    iVar2 = egs52_update_near_f876_0a3f66(param_2);
    if (iVar2 == 0) {
      UNK_00caa4 = 0;
      iVar3 = 0;
    }
    else {
      iVar3 = egs52_update_near_c166_0971e8(param_1,iVar2,param_2);
      if (iVar3 == 0) {
        egs52_free_small_heap_block(iVar2);
        UNK_00caa4 = 0;
        iVar3 = 0;
      }
      else {
        UNK_00caa4 = 0;
      }
    }
  }
  else {
    iVar3 = 0;
  }
  return iVar3;
}


