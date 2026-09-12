/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0e35c4; FLS offset 0x0635c4.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0e3618) */

void egs52_update_near_d47a_0e35c4(void)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  uchar uVar4;
  uint uVar5;
  
  uVar5 = egs52_compute_from_near_c06e_094d98();
  uVar1 = Ram00fd54;
  uVar2 = Ram00fd54;
  Ram00fd54 = uVar2 & 0xfdff | ((uVar1 & 8) >> 3) << 9;
  if ((uVar5 & 0x4000) == 0) {
    uVar1 = Ram00fd54;
    Ram00fd54 = uVar1 & 0xfffe;
  }
  else {
    uVar1 = Ram00fd54;
    Ram00fd54 = uVar1 | 1;
    uVar1 = Ram00fd3a;
    Ram00fd3a = uVar1 & 0xefff;
  }
  if ((uVar5 & 0x800) == 0) {
    uVar1 = Ram00fd54;
    Ram00fd54 = uVar1 & 0xdfff;
  }
  else {
    uVar1 = Ram00fd54;
    Ram00fd54 = uVar1 | 0x2000;
  }
  if ((uVar5 & 0x100) == 0) {
    uVar1 = Ram00fd54;
    Ram00fd54 = uVar1 & 0xfff7;
  }
  else {
    uVar1 = Ram00fd54;
    Ram00fd54 = uVar1 | 8;
  }
  cVar3 = egs52_match_fault_status_mask(0x30,1);
  if (cVar3 == '\x01') {
    uVar1 = Ram00fd60;
    Ram00fd60 = uVar1 | 0x100;
  }
  else {
    uVar1 = Ram00fd60;
    Ram00fd60 = uVar1 & 0xfeff;
  }
  uVar4 = egs52_call_0a1dd2_0964cc();
  UNK_00d47a = uVar4;
  return;
}


