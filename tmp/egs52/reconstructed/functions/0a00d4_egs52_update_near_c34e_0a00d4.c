/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a00d4; FLS offset 0x0200d4.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a0138) */
/* WARNING: Removing unreachable block (ram,0x0a0128) */
/* WARNING: Removing unreachable block (ram,0x0a0110) */
/* WARNING: Removing unreachable block (ram,0x0a0106) */
/* WARNING: Removing unreachable block (ram,0x0a0100) */
/* WARNING: Removing unreachable block (ram,0x0a00f6) */
/* WARNING: Removing unreachable block (ram,0x0a00f0) */
/* WARNING: Removing unreachable block (ram,0x0a00d8) */
/* WARNING: Removing unreachable block (ram,0x0a00ec) */
/* WARNING: Removing unreachable block (ram,0x0a0130) */

void egs52_update_near_c34e_0a00d4(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = Ram00ef00;
  if ((uVar1 & 0x8000) == 0) {
    egs52_update_fault_status(0x25,2);
    Ram00f844 = 0x32;
    Ram00f846 = 0xfa;
    uVar1 = Ram00c34e;
    Ram00c34e = uVar1 & 0xffef;
    return;
  }
  egs52_update_fault_status(0x25,3);
  uVar1 = Ram00c34e;
  Ram00c34e = uVar1 | 0x10;
  iVar2 = Ram00f844;
  if (iVar2 == 0) {
    iVar2 = Ram00f846;
    if (iVar2 == 0) {
      Ram00f846 = 0xfa;
      egs52_update_near_c34e_0a00aa();
      return;
    }
    iVar2 = Ram00f846;
    Ram00f846 = iVar2 + -1;
    return;
  }
  iVar3 = Ram00f844;
  Ram00f844 = iVar3 + -1;
  egs52_update_near_c34e_0a00aa(iVar2);
  return;
}


