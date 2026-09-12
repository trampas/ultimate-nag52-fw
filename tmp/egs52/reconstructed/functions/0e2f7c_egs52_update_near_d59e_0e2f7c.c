/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0e2f7c; FLS offset 0x062f7c.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0e2fb2) */
/* WARNING: Removing unreachable block (ram,0x0e2f9a) */
/* WARNING: Removing unreachable block (ram,0x0e2f96) */
/* WARNING: Removing unreachable block (ram,0x0e2f92) */
/* WARNING: Removing unreachable block (ram,0x0e2f8e) */
/* WARNING: Removing unreachable block (ram,0x0e2f88) */
/* WARNING: Removing unreachable block (ram,0x0e2f7c) */
/* WARNING: Removing unreachable block (ram,0x0e2fa8) */

void egs52_update_near_d59e_0e2f7c(void)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  char cVar4;
  int iVar5;
  
  uVar1 = Ram00fd56;
  if (((uVar1 & 0x10) != 0) && (uVar1 = Ram00fd54, (uVar1 & 8) == 0)) {
    iVar5 = Ram00d59e;
    if (iVar5 == 0) {
      iVar5 = Ram00f674;
      uVar1 = iVar5 + 4;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      Ram00d59e = *(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
      bVar3 = UNK_00d439;
      if (bVar3 < 5) {
        egs52_call_095b6a_095abc(bVar3);
        cVar4 = UNK_00d439;
        UNK_00d439 = cVar4 + '\x01';
      }
      else {
        uVar1 = Ram00fd38;
        Ram00fd38 = uVar1 | 2;
        UNK_00d439 = 2;
        egs52_call_095b6a_095abc(6);
      }
    }
    uVar1 = Ram00fd38;
    if (((uVar1 & 1) != 0) && (uVar1 = Ram00fd38, (uVar1 & 2) != 0)) {
      egs52_call_095b6a_095abc(5);
      uVar1 = Ram00fd38;
      Ram00fd38 = uVar1 & 0xfffe;
      uVar1 = Ram00fd38;
      Ram00fd38 = uVar1 & 0xfffd;
    }
    uVar1 = Ram00fd5a;
    if ((uVar1 & 0x80) != 0) {
      egs52_call_095b6a_095abc(7);
      uVar1 = Ram00fd5a;
      Ram00fd5a = uVar1 & 0xff7f;
    }
  }
  return;
}


