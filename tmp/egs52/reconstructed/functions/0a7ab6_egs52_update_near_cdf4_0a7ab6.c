/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a7ab6; FLS offset 0x027ab6.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a7b76) */
/* WARNING: Removing unreachable block (ram,0x0a7b6c) */
/* WARNING: Removing unreachable block (ram,0x0a7b66) */
/* WARNING: Removing unreachable block (ram,0x0a7b5c) */
/* WARNING: Removing unreachable block (ram,0x0a7b3a) */
/* WARNING: Removing unreachable block (ram,0x0a7b36) */
/* WARNING: Removing unreachable block (ram,0x0a7b32) */
/* WARNING: Removing unreachable block (ram,0x0a7b00) */
/* WARNING: Removing unreachable block (ram,0x0a7af8) */
/* WARNING: Removing unreachable block (ram,0x0a7af0) */
/* WARNING: Removing unreachable block (ram,0x0a7aba) */
/* WARNING: Removing unreachable block (ram,0x0a7b52) */
/* WARNING: Removing unreachable block (ram,0x0a7b84) */

undefined1 egs52_update_near_cdf4_0a7ab6(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined2 uVar3;
  char cVar4;
  undefined1 uVar5;
  uint uStack_8;
  uint uStack_6;
  undefined2 uStack_4;
  undefined1 auStack_2 [2];
  
  cVar4 = UNK_00cdf4;
  if (cVar4 == '\0') {
    egs52_copy_six_status_bytes(0xcdf6);
    if ((param_1 == 0) || (param_1 == -0x100)) {
      cVar4 = egs52_update_near_fd6c_0a107a(1);
      if (cVar4 == '\0') {
        UNK_00cdf4 = 1;
        iVar1 = Ram00cdf6;
        Ram00cdf6 = iVar1 + 0x10;
        iVar1 = Ram00cdf8;
        Ram00cdf8 = iVar1 + 0x14;
        uVar5 = 0xfc;
      }
      else {
        uVar5 = 0x22;
      }
    }
    else {
      cVar4 = egs52_update_near_fd6c_0a10ec(0,auStack_2);
      if (cVar4 == -0xe) {
        uVar5 = 0x22;
      }
      else if (cVar4 == '\0') {
        UNK_00cdf4 = 1;
        iVar1 = Ram00cdf6;
        Ram00cdf6 = iVar1 + 1;
        iVar1 = Ram00cdf8;
        Ram00cdf8 = iVar1 + 1;
        uVar5 = 0xfc;
      }
      else {
        uVar5 = 0xff;
      }
    }
  }
  else if (cVar4 == '\x01') {
    egs52_copy_six_status_bytes(&uStack_8);
    uVar2 = Ram00cdf6;
    if ((uVar2 <= uStack_8) && (uVar2 = Ram00cdf8, uVar2 <= uStack_6)) {
      Ram00cdfa = uStack_4;
      UNK_00cdf4 = 2;
    }
    uVar5 = 0xfc;
  }
  else if (cVar4 == '\x02') {
    uVar3 = Ram00cdfa;
    cVar4 = egs52_call_095b6a_095b38(uVar3,0);
    if (cVar4 == '\x03') {
      UNK_00cdf4 = 0;
      uVar5 = 0xfe;
    }
    else {
      uVar5 = 0xfc;
    }
  }
  else {
    uVar5 = 0x31;
  }
  return uVar5;
}


