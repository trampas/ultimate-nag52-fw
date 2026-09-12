/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x09895a; FLS offset 0x01895a.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0989e0) */
/* WARNING: Removing unreachable block (ram,0x0989d0) */
/* WARNING: Removing unreachable block (ram,0x0989b8) */
/* WARNING: Removing unreachable block (ram,0x098986) */
/* WARNING: Removing unreachable block (ram,0x09897e) */
/* WARNING: Removing unreachable block (ram,0x0989a4) */
/* WARNING: Removing unreachable block (ram,0x09899a) */
/* WARNING: Removing unreachable block (ram,0x0989c2) */

void egs52_update_near_c19f_09895a(byte param_1,undefined1 param_2)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  undefined2 uVar4;
  
  if (param_1 == 1) {
    uVar1 = Ram00ff80;
    Ram00ff80 = uVar1 & 0xffbf;
    uVar1 = Ram00ff90;
    Ram00ff90 = uVar1 & 0xffbf;
    egs52_update_fault_status(0x47,0);
    bVar3 = UNK_00c19f;
    UNK_00c19f = bVar3 | 3;
  }
  else if (param_1 == 2) {
    uVar1 = Ram00ff82;
    Ram00ff82 = uVar1 & 0xffbf;
    uVar1 = Ram00ff92;
    Ram00ff92 = uVar1 & 0xffbf;
    egs52_update_fault_status(0x48,0);
    bVar3 = UNK_00c19f;
    UNK_00c19f = bVar3 | 0xc;
  }
  else if (param_1 == 3) {
    uVar1 = Ram00ff84;
    Ram00ff84 = uVar1 & 0xffbf;
    uVar1 = Ram00ff94;
    Ram00ff94 = uVar1 & 0xffbf;
    egs52_update_fault_status(0x49,0);
    bVar3 = UNK_00c19f;
    UNK_00c19f = bVar3 | 0x30;
  }
  uVar4 = egs52_call_09212e_098b9e(param_2);
  uVar1 = (uint)param_1 * 2 + 0xc194;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  *(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) = uVar4;
  uVar1 = Ram00ff9e;
  Ram00ff9e = uVar1 & 0xff7f;
  uVar1 = Ram00ff9e;
  Ram00ff9e = uVar1 | 0x40;
  uVar1 = param_1 + 0xc191;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) = 0x3c;
  return;
}


