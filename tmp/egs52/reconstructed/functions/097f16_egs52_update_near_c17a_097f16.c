/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x097f16; FLS offset 0x017f16.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Function: egs52_divide_u32_registers replaced with injection: egs52_udiv32_registers */
/* WARNING: Removing unreachable block (ram,0x097fda) */
/* WARNING: Removing unreachable block (ram,0x097f86) */
/* WARNING: Removing unreachable block (ram,0x097f76) */
/* WARNING: Removing unreachable block (ram,0x097f6c) */
/* WARNING: Removing unreachable block (ram,0x097f52) */
/* WARNING: Removing unreachable block (ram,0x097f36) */
/* WARNING: Removing unreachable block (ram,0x097f26) */
/* WARNING: Removing unreachable block (ram,0x097f1c) */
/* WARNING: Removing unreachable block (ram,0x097f30) */
/* WARNING: Removing unreachable block (ram,0x097f80) */
/* WARNING: Removing unreachable block (ram,0x097fbc) */

undefined2 egs52_update_near_c17a_097f16(uint param_1)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
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
  uVar2 = Ram00c174;
  bVar1 = UNK_00c0eb;
  if ((bVar1 < 10) || (bVar1 = UNK_00c0eb, 0x14 < bVar1)) {
    bVar1 = UNK_00c0eb;
    if (bVar1 < 10) {
      uVar4 = 10;
    }
    else {
      uVar4 = 0x14;
    }
  }
  else {
    bVar1 = UNK_00c0eb;
    uVar4 = (uint)bVar1;
  }
  if ((uVar4 * 3000 - 0x5dc < (uint)(((ulong)(uVar3 * 3000) * (ulong)uVar2) / 0xffff)) &&
     (param_1 < 0x4000)) {
    param_1 = 0x4000;
  }
  Ram00c17a = (int)(((ulong)param_1 * 24000) / 0xffff);
  return 0;
}


