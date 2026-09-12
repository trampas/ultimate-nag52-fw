/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x098002; FLS offset 0x018002.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0980ce) */
/* WARNING: Removing unreachable block (ram,0x0980a8) */
/* WARNING: Removing unreachable block (ram,0x09809e) */
/* WARNING: Removing unreachable block (ram,0x098094) */
/* WARNING: Removing unreachable block (ram,0x09805a) */
/* WARNING: Removing unreachable block (ram,0x098054) */
/* WARNING: Removing unreachable block (ram,0x098034) */
/* WARNING: Removing unreachable block (ram,0x098024) */
/* WARNING: Removing unreachable block (ram,0x09801a) */
/* WARNING: Removing unreachable block (ram,0x09802e) */
/* WARNING: Removing unreachable block (ram,0x0980ae) */

void egs52_compute_from_near_c0eb_098002(void)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = egs52_update_near_c170_097904();
  if (((uVar3 & 0x100) == 0) || (uVar3 = egs52_update_near_c170_097904(), (uVar3 & 0x200) == 0)) {
    egs52_update_fault_status(5,0);
    return;
  }
  bVar1 = UNK_00c0eb;
  if ((bVar1 < 10) || (bVar1 = UNK_00c0eb, 0x14 < bVar1)) {
    bVar1 = UNK_00c0eb;
    if (bVar1 < 10) {
      uVar3 = 10;
    }
    else {
      uVar3 = 0x14;
    }
  }
  else {
    bVar1 = UNK_00c0eb;
    uVar3 = (uint)bVar1;
  }
  uVar2 = Ram00c176;
  if ((uVar2 <= uVar3 * 3000 - 0x5dc) && (uVar3 = Ram00c176, 0x654 < uVar3)) {
    uVar3 = Ram00ff86;
    if ((uVar3 & 0x80) != 0) {
      uVar3 = Ram00ff86;
      Ram00ff86 = uVar3 & 0xff7f;
      egs52_update_fault_status(5,2);
      return;
    }
    egs52_update_fault_status(5,3);
    return;
  }
  uVar3 = egs52_compute_from_near_c189_0981ca(2);
  if ((uVar3 & 3) == 3) {
    bVar1 = UNK_00c0eb;
    if ((bVar1 < 10) || (bVar1 = UNK_00c0eb, 0x14 < bVar1)) {
      bVar1 = UNK_00c0eb;
      if (bVar1 < 10) {
        uVar3 = 10;
      }
      else {
        uVar3 = 0x14;
      }
    }
    else {
      bVar1 = UNK_00c0eb;
      uVar3 = (uint)bVar1;
    }
    uVar2 = Ram00c176;
    if (uVar3 * 3000 - 0x5dc < uVar2) {
      egs52_update_fault_status(5,2);
    }
    else {
      egs52_update_fault_status(5,0);
    }
  }
  else {
    egs52_update_fault_status(5,3);
  }
  uVar3 = Ram00ff86;
  Ram00ff86 = uVar3 & 0xff7f;
  return;
}


