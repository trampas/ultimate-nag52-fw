/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d01aa; FLS offset 0x0501aa.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d02be) */
/* WARNING: Removing unreachable block (ram,0x0d02a4) */
/* WARNING: Removing unreachable block (ram,0x0d0290) */
/* WARNING: Removing unreachable block (ram,0x0d0270) */
/* WARNING: Removing unreachable block (ram,0x0d025c) */
/* WARNING: Removing unreachable block (ram,0x0d0240) */
/* WARNING: Removing unreachable block (ram,0x0d0224) */
/* WARNING: Removing unreachable block (ram,0x0d01be) */

void egs52_update_near_d588_0d01aa(void)

{
  uint uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  
  egs52_update_near_d5a6_0dedbc();
  egs52_update_near_d47a_0e35c4();
  uVar1 = Ram00fd54;
  if ((uVar1 & 8) == 0) {
    uVar1 = Ram00fd54;
    if ((uVar1 & 0x200) != 0) {
      uVar1 = Ram00fd54;
      Ram00fd54 = uVar1 | 0x800;
      egs52_update_near_d468_0d032c();
    }
    uVar2 = egs52_read_register_f052();
    egs52_update_near_d212_0e3672();
    egs52_update_near_d7da_0e3ecc();
    egs52_update_near_fd54_0e403c();
    egs52_update_near_d443_0e5e30();
    egs52_update_near_d614_0e40a0();
    egs52_update_near_d60e_0e46f4();
    egs52_update_near_d5ca_0e4958();
    egs52_update_near_d7da_0e4b56();
    egs52_update_near_d506_0e4c42();
    egs52_update_near_d462_0e4db0();
    egs52_update_near_d433_0e4e30();
    egs52_update_near_d777_0e0742();
    egs52_update_near_d4e8_0e58be();
    egs52_update_near_d4e4_0e5ae0();
    egs52_update_near_d47b_0de4f0();
    egs52_update_near_d4e4_0e5ae0();
    egs52_update_near_d526_0e5df0();
    egs52_update_near_d482_0e5eb4();
    egs52_pack_scaled_status_fields();
    uVar3 = egs52_read_register_f052();
    Ram00d588 = uVar3 - uVar2;
    uVar3 = egs52_read_register_f052();
    egs52_update_near_d56a_0d072a();
    egs52_update_near_d436_0d202e();
    egs52_update_near_d5a4_0d269c();
    uVar4 = egs52_read_register_f052();
    Ram00d584 = uVar4 - uVar3;
    uVar3 = egs52_read_register_f052();
    egs52_update_near_d435_0d1816();
    egs52_update_near_d4cc_0d0c8e();
    egs52_update_near_d4fe_0d2b08();
    uVar4 = egs52_read_register_f052();
    Ram00d582 = uVar4 - uVar3;
    uVar3 = egs52_read_register_f052();
    egs52_update_near_d64a_0d0086();
    uVar4 = egs52_read_register_f052();
    Ram00d58a = uVar4 - uVar3;
    uVar3 = egs52_read_register_f052();
    egs52_update_near_d45e_0e7468();
    egs52_update_near_d5a5_0e2fdc();
    egs52_select_client3_operating_mask();
    egs52_update_near_fd38_0e357c();
    uVar4 = egs52_read_register_f052();
    Ram00d58c = uVar4 - uVar3;
    uVar3 = egs52_read_register_f052();
    egs52_update_near_d7b6_0e1ffc();
    uVar4 = egs52_read_register_f052();
    Ram00d58e = uVar4 - uVar3;
    egs52_update_near_d59e_0e2f7c();
    egs52_update_near_d486_0e69be();
    egs52_update_near_d23f_0e6a92();
    egs52_update_near_d60f_0e7216();
    uVar3 = egs52_read_register_f052();
    Ram00d586 = uVar3 - uVar2;
  }
  else {
    egs52_update_near_d212_0e3672();
    egs52_update_near_d614_0e40a0();
    egs52_update_near_d5a5_0e2fdc();
    egs52_pack_scaled_status_fields();
    egs52_update_near_d23f_0e6a92();
    egs52_update_near_d60f_0e7216();
  }
  return;
}


