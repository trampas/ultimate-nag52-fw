/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a013e; FLS offset 0x02013e.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a01a2) */
/* WARNING: Removing unreachable block (ram,0x0a0192) */
/* WARNING: Removing unreachable block (ram,0x0a017a) */
/* WARNING: Removing unreachable block (ram,0x0a0170) */
/* WARNING: Removing unreachable block (ram,0x0a016a) */
/* WARNING: Removing unreachable block (ram,0x0a0160) */
/* WARNING: Removing unreachable block (ram,0x0a015a) */
/* WARNING: Removing unreachable block (ram,0x0a0142) */
/* WARNING: Removing unreachable block (ram,0x0a0156) */
/* WARNING: Removing unreachable block (ram,0x0a019a) */

void egs52_update_near_c34e_0a013e(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = Ram00ee00;
  if ((uVar1 & 0x8000) == 0) {
    egs52_update_fault_status(0x2d,2);
    Ram00f848 = 0x32;
    Ram00f84a = 0xfa;
    uVar1 = Ram00c34e;
    Ram00c34e = uVar1 & 0xffdf;
    return;
  }
  egs52_update_fault_status(0x2d,3);
  uVar1 = Ram00c34e;
  Ram00c34e = uVar1 | 0x20;
  iVar2 = Ram00f848;
  if (iVar2 == 0) {
    iVar2 = Ram00f84a;
    if (iVar2 == 0) {
      Ram00f84a = 0xfa;
      egs52_update_near_c34e_0a00aa();
      return;
    }
    iVar2 = Ram00f84a;
    Ram00f84a = iVar2 + -1;
    return;
  }
  iVar3 = Ram00f848;
  Ram00f848 = iVar3 + -1;
  egs52_update_near_c34e_0a00aa(iVar2);
  return;
}


