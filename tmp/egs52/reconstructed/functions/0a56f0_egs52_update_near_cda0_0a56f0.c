/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a56f0; FLS offset 0x0256f0.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a57f2) */
/* WARNING: Removing unreachable block (ram,0x0a57ee) */
/* WARNING: Removing unreachable block (ram,0x0a57e6) */
/* WARNING: Removing unreachable block (ram,0x0a57e2) */
/* WARNING: Removing unreachable block (ram,0x0a57de) */
/* WARNING: Removing unreachable block (ram,0x0a57da) */
/* WARNING: Removing unreachable block (ram,0x0a57d6) */
/* WARNING: Removing unreachable block (ram,0x0a57ce) */
/* WARNING: Removing unreachable block (ram,0x0a57ca) */
/* WARNING: Removing unreachable block (ram,0x0a57c6) */
/* WARNING: Removing unreachable block (ram,0x0a57c2) */
/* WARNING: Removing unreachable block (ram,0x0a57ba) */
/* WARNING: Removing unreachable block (ram,0x0a57b6) */
/* WARNING: Removing unreachable block (ram,0x0a57ae) */
/* WARNING: Removing unreachable block (ram,0x0a57aa) */
/* WARNING: Removing unreachable block (ram,0x0a57a6) */
/* WARNING: Removing unreachable block (ram,0x0a57a2) */
/* WARNING: Removing unreachable block (ram,0x0a579e) */
/* WARNING: Removing unreachable block (ram,0x0a579a) */
/* WARNING: Removing unreachable block (ram,0x0a5796) */
/* WARNING: Removing unreachable block (ram,0x0a5792) */
/* WARNING: Removing unreachable block (ram,0x0a578e) */
/* WARNING: Removing unreachable block (ram,0x0a578a) */
/* WARNING: Removing unreachable block (ram,0x0a5786) */
/* WARNING: Removing unreachable block (ram,0x0a57d2) */

void egs52_update_near_cda0_0a56f0(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  
  egs52_end_initialization();
  Ram00ffae = 0xd001;
  __service_watchdog();
  egs52_update_near_f0b4_097ac6();
  egs52_update_near_f160_097954();
  egs52_register_sequence_097a40();
  egs52_initialize_capture_compare();
  egs52_clear_capture_compare_controls();
  egs52_call_09f858_0a24c8();
  egs52_initialize_operating_masks();
  egs52_update_near_f80c_099124();
  egs52_update_near_c189_0980fa();
  egs52_update_near_c17a_097ad6();
  egs52_update_near_f1de_0a6336();
  egs52_update_near_c172_097610();
  egs52_reset_receive_counters();
  egs52_update_near_c1ac_099688();
  egs52_compute_from_near_cace_0a47c0();
  egs52_update_near_c086_094dd2();
  egs52_update_near_c116_09677a();
  egs52_update_near_ccec_0a5198();
  egs52_update_near_caca_0a474e();
  egs52_update_near_cd16_0a549e();
  egs52_call_0a0000_094156();
  egs52_update_near_f1c2_097a84();
  egs52_call_09cb2e_093d4c();
  egs52_update_near_c1aa_099450();
  egs52_update_near_c1aa_09945a();
  egs52_call_0a00aa_09415c();
  egs52_enable_interrupts();
  egs52_call_0a2d18_09512a();
  egs52_update_near_c172_097678();
  egs52_update_near_f1c6_0a4430();
  egs52_update_near_f57f_0a4446();
  egs52_update_near_f402_09ff88();
  egs52_update_near_c112_096564();
  uVar1 = Ram00fdee;
  Ram00cda0 = uVar1 & 1;
  bVar4 = UNK_00f614;
  iVar2 = Ram00cda0;
  Ram00cda0 = iVar2 + (uint)bVar4;
  iVar2 = Ram00cda0;
  Ram00cda0 = iVar2 + (uint)bRam00f408;
  iVar3 = Ram00fdea;
  iVar2 = Ram00cda0;
  Ram00cda0 = iVar2 + iVar3;
  iVar2 = Ram00cda0;
  Ram00cda0 = iVar2 + (uint)bRam00f403;
  iVar3 = Ram00e7fe;
  iVar2 = Ram00cda0;
  Ram00cda0 = iVar2 + iVar3;
  iVar2 = Ram00cda0;
  Ram00cda0 = iVar2 + iRam0b0000;
  iVar2 = Ram00cda0;
  Ram00cda0 = iVar2 + iRam090000;
  iVar2 = Ram00cda0;
  Ram00cda0 = iVar2 + (uint)bRam0900d8;
  iVar2 = Ram00cda0;
  Ram00cda0 = iVar2 + iRam0b0082;
  iVar2 = Ram00cda0;
  Ram00cda0 = iVar2 + (uint)bRam0900d8;
  iVar2 = Ram00cda0;
  Ram00cda0 = iVar2 + iRam090010;
  iVar2 = Ram00cda0;
  Ram00cda0 = iVar2 + iRam090228;
  return;
}


