/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x081db0; FLS offset 0x001db0.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x081e8a) */
/* WARNING: Removing unreachable block (ram,0x081ec2) */
/* WARNING: Removing unreachable block (ram,0x081e82) */
/* WARNING: Removing unreachable block (ram,0x081e92) */
/* WARNING: Removing unreachable block (ram,0x081e48) */
/* WARNING: Removing unreachable block (ram,0x081ed4) */
/* WARNING: Removing unreachable block (ram,0x081eb8) */
/* WARNING: Removing unreachable block (ram,0x081e96) */
/* WARNING: Removing unreachable block (ram,0x081e7e) */
/* WARNING: Removing unreachable block (ram,0x081e70) */
/* WARNING: Removing unreachable block (ram,0x081e62) */
/* WARNING: Removing unreachable block (ram,0x081e4c) */
/* WARNING: Removing unreachable block (ram,0x081e44) */
/* WARNING: Removing unreachable block (ram,0x081e40) */
/* WARNING: Removing unreachable block (ram,0x081e2e) */
/* WARNING: Removing unreachable block (ram,0x081e28) */
/* WARNING: Removing unreachable block (ram,0x081e20) */
/* WARNING: Removing unreachable block (ram,0x081e18) */
/* WARNING: Removing unreachable block (ram,0x081e12) */
/* WARNING: Removing unreachable block (ram,0x081e0c) */
/* WARNING: Removing unreachable block (ram,0x081e04) */
/* WARNING: Removing unreachable block (ram,0x081dfc) */
/* WARNING: Removing unreachable block (ram,0x081df8) */
/* WARNING: Removing unreachable block (ram,0x081df2) */
/* WARNING: Removing unreachable block (ram,0x081dea) */
/* WARNING: Removing unreachable block (ram,0x081de6) */
/* WARNING: Removing unreachable block (ram,0x081dde) */
/* WARNING: Removing unreachable block (ram,0x081dda) */
/* WARNING: Removing unreachable block (ram,0x081dd4) */
/* WARNING: Removing unreachable block (ram,0x081dcc) */
/* WARNING: Removing unreachable block (ram,0x081e5a) */
/* WARNING: Removing unreachable block (ram,0x081e6c) */
/* WARNING: Removing unreachable block (ram,0x081e7a) */
/* WARNING: Removing unreachable block (ram,0x081eae) */
/* WARNING: Removing unreachable block (ram,0x081ec6) */
/* WARNING: Removing unreachable block (ram,0x081ee6) */
/* WARNING: Removing unreachable block (ram,0x081eb4) */
/* WARNING: Removing unreachable block (ram,0x081ed0) */
/* WARNING: Removing unreachable block (ram,0x081e9e) */
/* WARNING: Removing unreachable block (ram,0x081ed8) */
/* WARNING: Heritage AFTER dead removal. Example location: r0x00f45e : 0x081e7a */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void egs52_update_near_fdee_081db0(void)

{
  int iVar1;
  bool bVar2;
  uint uVar3;
  undefined2 uVar4;
  uint uVar5;
  
  __write_psw_bits(0x800,0);
  uVar3 = Ram00fdee;
  Ram00fdee = uVar3 | 1;
  uVar3 = Ram00ffce;
  Ram00ffce = uVar3 | 0x20;
  uVar3 = Ram00f1ce;
  Ram00f1ce = uVar3 & 0xffdf;
  uVar3 = Ram00ffcc;
  Ram00ffcc = uVar3 & 0xffdf;
  uVar3 = Ram00ffc6;
  Ram00ffc6 = uVar3 | 1;
  uVar3 = Ram00f1c6;
  Ram00f1c6 = uVar3 & 0xfffe;
  uVar3 = Ram00ffc4;
  Ram00ffc4 = uVar3 | 1;
  uVar3 = Ram00ffc6;
  Ram00ffc6 = uVar3 | 2;
  uVar3 = Ram00f1c6;
  Ram00f1c6 = uVar3 & 0xfffd;
  uVar3 = Ram00ffc4;
  Ram00ffc4 = uVar3 & 0xfffd;
  uVar3 = Ram00ffc2;
  Ram00ffc2 = uVar3 | 0x1007;
  uVar4 = Ram00f1c2;
  Ram00f1c2 = uVar4;
  uVar3 = Ram00ffc0;
  Ram00ffc0 = uVar3 | 0x1007;
  uVar3 = Ram00ffd2;
  Ram00ffd2 = uVar3 | 0xd;
  uVar4 = Ram00f1d2;
  Ram00f1d2 = uVar4;
  uVar3 = Ram00ffd0;
  Ram00ffd0 = uVar3 | 0xd;
  egs52_register_sequence_081f1e();
  iRam00f5ae = Ram00fe52;
  iRam00f5a6 = 5;
  iRam00f5a8 = 2;
  iRam00f5aa = 0x15;
  iRam00f5ac = 200;
  uRam00f5b0 = 1;
  uVar3 = Ram00fde8;
  if ((uVar3 & 1) != 0) {
    uVar4 = Ram00fde8;
    uVar3 = Ram00fde8;
    uVar5 = Ram00fde8;
    Ram00fde8 = uVar5 & 0xffef | (uVar3 & 1) << 4;
  }
  egs52_update_near_f186_089090();
  uRam00f5b0 = 1;
  uRam00f3f8 = 0;
  do {
    iVar1 = Ram00fe52;
    if (3000 < (uint)(iVar1 - iRam00f5ae)) {
      iRam00f5ae = iRam00f5ae + 3000;
      egs52_register_sequence_081f30();
      if (uRam00f572 < 0xfffc) {
        uRam00f572 = uRam00f572 + 1;
      }
      if (uRam00f45e < 0xfffd) {
        uRam00f45e = uRam00f45e + 1;
      }
      iRam00f5a6 = iRam00f5a6 + -1;
    }
    if (iRam00f5a6 == 0) {
      iRam00f5a6 = 5;
      egs52_transform_far_memory_089e22(0);
      iRam00f5a8 = iRam00f5a8 + -1;
      if (iRam00f5a8 == 0) {
        iRam00f5a8 = 2;
        Ram00ffae = 0x9201;
        __service_watchdog();
        egs52_update_near_fdea_081f3c(0);
        if ((iRam00f5b2 != 0) &&
           (iVar1 = iRam00f5b2 + -1, bVar2 = iRam00f5b2 == 0, iRam00f5b2 = iVar1, bVar2)) {
          egs52_call_08244a_082384(0);
        }
      }
      iRam00f5aa = iRam00f5aa + -1;
      if (iRam00f5aa == 0) {
        iRam00f5aa = 0x14;
      }
      iVar1 = iRam00f5ac + -1;
      bVar2 = iRam00f5ac == 0;
      iRam00f5ac = iVar1;
      if (bVar2) {
        egs52_update_near_f402_081d84(0);
        iRam00f5ac = 200;
      }
    }
    uVar3 = Ram00ff6e;
    if ((uVar3 & 0x80) != 0) {
      func_0x000188();
    }
    uVar3 = Ram00f18e;
    if (((uVar3 & 0x80) != 0) && (uVar3 = Ram00f18e, (uVar3 & 0x40) != 0)) {
      uVar3 = Ram00f18e;
      Ram00f18e = uVar3 & 0xff7f;
    }
    uVar3 = Ram00f186;
    if (((uVar3 & 0x80) != 0) && (uVar3 = Ram00f186, (uVar3 & 0x40) != 0)) {
      uVar3 = Ram00f186;
      Ram00f186 = uVar3 & 0xff7f;
      egs52_update_near_f41e_088f56();
    }
    egs52_update_near_f3f8_080c4a();
  } while( true );
}


