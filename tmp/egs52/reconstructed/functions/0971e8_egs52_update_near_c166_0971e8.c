/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0971e8; FLS offset 0x0171e8.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x097212) */
/* WARNING: Removing unreachable block (ram,0x0971f6) */
/* WARNING: Removing unreachable block (ram,0x0971e8) */

undefined2 egs52_update_near_c166_0971e8(undefined2 param_1,undefined2 param_2,undefined2 param_3)

{
  int iVar1;
  undefined2 uVar2;
  char cVar3;
  
  iVar1 = Ram00c166;
  Ram00c166 = iVar1 + 1;
  uVar2 = Ram00c166;
  cVar3 = egs52_update_near_c168_09721c(3,param_1,param_3,uVar2,0,param_2);
  if (cVar3 == '\0') {
    return 0;
  }
  uVar2 = Ram00c166;
  return uVar2;
}


