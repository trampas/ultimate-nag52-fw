/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x099124; FLS offset 0x019124.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x09918c) */
/* WARNING: Removing unreachable block (ram,0x0991f4) */
/* WARNING: Removing unreachable block (ram,0x099182) */
/* WARNING: Removing unreachable block (ram,0x099160) */
/* WARNING: Removing unreachable block (ram,0x09915c) */
/* WARNING: Removing unreachable block (ram,0x099158) */
/* WARNING: Removing unreachable block (ram,0x099154) */
/* WARNING: Removing unreachable block (ram,0x099150) */
/* WARNING: Removing unreachable block (ram,0x09914c) */
/* WARNING: Removing unreachable block (ram,0x099148) */
/* WARNING: Removing unreachable block (ram,0x099144) */
/* WARNING: Removing unreachable block (ram,0x099140) */
/* WARNING: Removing unreachable block (ram,0x099138) */
/* WARNING: Removing unreachable block (ram,0x099270) */
/* WARNING: Removing unreachable block (ram,0x09926c) */
/* WARNING: Removing unreachable block (ram,0x099268) */
/* WARNING: Removing unreachable block (ram,0x099264) */
/* WARNING: Removing unreachable block (ram,0x099260) */
/* WARNING: Removing unreachable block (ram,0x09925c) */
/* WARNING: Removing unreachable block (ram,0x099258) */
/* WARNING: Removing unreachable block (ram,0x099254) */
/* WARNING: Removing unreachable block (ram,0x099286) */
/* WARNING: Removing unreachable block (ram,0x099282) */
/* WARNING: Removing unreachable block (ram,0x09927e) */
/* WARNING: Removing unreachable block (ram,0x09927a) */
/* WARNING: Removing unreachable block (ram,0x099276) */
/* WARNING: Removing unreachable block (ram,0x099214) */
/* WARNING: Removing unreachable block (ram,0x09913c) */
/* WARNING: Removing unreachable block (ram,0x0991e2) */
/* WARNING: Removing unreachable block (ram,0x0991ac) */

void egs52_update_near_f80c_099124(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined1 uVar3;
  int iVar4;
  uint uVar5;
  ushort uVar6;
  
  uVar6 = egs52_get_status_fdfe();
  if (((uVar6 & 0x400) == 0) || (uVar6 = egs52_get_status_fdfe(), (uVar6 & 0x1a00) != 0)) {
    egs52_update_fault_status(0x3d,2);
    if (cRam083e7c == -2) {
      egs52_update_fault_status(0x44,0x40);
      egs52_update_fault_status(0x45,0x40);
    }
    else {
      egs52_update_fault_status(0x44,2);
      egs52_update_fault_status(0x45,2);
    }
    uVar6 = egs52_get_status_fdfe();
    if ((uVar6 & 0x200) != 0) {
      uVar1 = Ram00fdf2;
      uVar2 = Ram00fdf4;
      Ram00f80c = uVar1;
      Ram00f80e = uVar2;
      uVar3 = UNK_00fdfc;
      UNK_00f810 = uVar3;
      uVar3 = UNK_00fdfd;
      UNK_00f811 = uVar3;
      return;
    }
    UNK_00f80a = 0;
    UNK_00fdfb = 0;
    Ram00fdf6 = 0;
    Ram00fdf8 = 0;
    UNK_00fdfa = 0;
    egs52_update_operating_masks(0x100,6);
  }
  else {
    uVar1 = Ram00fdf2;
    uVar2 = Ram00fdf4;
    Ram00f80c = uVar1;
    Ram00f80e = uVar2;
    uVar3 = UNK_00fdfc;
    UNK_00f810 = uVar3;
    uVar3 = UNK_00fdfd;
    UNK_00f811 = uVar3;
    uVar1 = Ram00fdf0;
    Ram00f812 = uVar1;
    uVar5 = Ram00fdf6;
    if ((uVar5 & 0x8000) == 0) {
      egs52_update_fault_status(0x3d,2);
    }
    else {
      egs52_update_fault_status(0x3d,3);
    }
    if (cRam083e7c != -2) {
      uVar5 = Ram00fdf6;
      if ((uVar5 & 0x7fff) == 0) {
        egs52_update_fault_status(0x44,2);
      }
      else {
        egs52_update_fault_status(0x44,3);
      }
      iVar4 = Ram00fdf0;
      if (iVar4 != 0) {
        egs52_update_fault_status(0x45,3);
        return;
      }
      egs52_update_fault_status(0x45,2);
      return;
    }
    egs52_update_fault_status(0x44,0x40);
    egs52_update_fault_status(0x45,0x40);
    uVar5 = Ram00fdf6;
    if ((uVar5 & 0x7fff) != 0) {
      egs52_update_near_c44e_0a1d8c(0x44);
    }
    iVar4 = Ram00fdf0;
    if (iVar4 != 0) {
      egs52_update_near_c44e_0a1d8c(0x45);
      return;
    }
  }
  return;
}


