/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x095f04; FLS offset 0x015f04.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x095f72) */
/* WARNING: Removing unreachable block (ram,0x095f6e) */
/* WARNING: Removing unreachable block (ram,0x095f5e) */
/* WARNING: Removing unreachable block (ram,0x095f40) */
/* WARNING: Removing unreachable block (ram,0x095f38) */
/* WARNING: Removing unreachable block (ram,0x095f2a) */
/* WARNING: Removing unreachable block (ram,0x095f54) */
/* WARNING: Removing unreachable block (ram,0x095f4e) */
/* WARNING: Removing unreachable block (ram,0x095f24) */
/* WARNING: Removing unreachable block (ram,0x095f1a) */
/* WARNING: Removing unreachable block (ram,0x095f86) */
/* WARNING: Removing unreachable block (ram,0x095f04) */
/* WARNING: Removing unreachable block (ram,0x095f80) */
/* WARNING: Removing unreachable block (ram,0x095f16) */
/* WARNING: Removing unreachable block (ram,0x095f5c) */
/* WARNING: Removing unreachable block (ram,0x095f32) */
/* WARNING: Removing unreachable block (ram,0x095f3c) */
/* WARNING: Removing unreachable block (ram,0x095f4a) */

undefined2 egs52_update_near_c0d4_095f04(void)

{
  int iVar1;
  byte bVar2;
  char cVar3;
  undefined2 uVar4;
  
  iVar1 = Ram00c0d6;
  if (iVar1 == 0) {
    UNK_00c0d2 = 3;
    Ram00c0d6 = 1;
  }
  else if (iVar1 == 1) {
    bVar2 = UNK_00c0d2;
    uVar4 = egs52_call_095b6a_095abc(*(undefined1 *)((uint3)(bVar2 + 0x4d0) | 0x90000));
    Ram00c0d4 = uVar4;
    while (iVar1 = Ram00c0d4, iVar1 != 0) {
      cVar3 = UNK_00c0d2;
      if (cVar3 == '\0') {
        Ram00c0d6 = 2;
        return 1;
      }
      cVar3 = UNK_00c0d2;
      UNK_00c0d2 = cVar3 + -1;
      bVar2 = UNK_00c0d2;
      uVar4 = egs52_call_095b6a_095abc(*(undefined1 *)((uint3)(bVar2 + 0x4d0) | 0x90000));
      Ram00c0d4 = uVar4;
    }
  }
  else {
    if (iVar1 != 2) {
      return 0;
    }
    uVar4 = Ram00c0d4;
    cVar3 = egs52_update_near_caa4_0a3d02(uVar4,0,0);
    if (cVar3 == '\x03') {
      Ram00c0d6 = 0;
      Ram00c0d4 = 0;
      return 2;
    }
  }
  return 1;
}


