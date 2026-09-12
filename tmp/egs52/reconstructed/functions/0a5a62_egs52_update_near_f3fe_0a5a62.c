/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a5a62; FLS offset 0x025a62.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Function: egs52_call_far_indirect replaced with injection: call_far_indirect */
/* WARNING: Removing unreachable block (ram,0x0a5b50) */
/* WARNING: Removing unreachable block (ram,0x0a5b4c) */
/* WARNING: Removing unreachable block (ram,0x0a5b44) */
/* WARNING: Removing unreachable block (ram,0x0a5b3c) */
/* WARNING: Removing unreachable block (ram,0x0a5b34) */
/* WARNING: Removing unreachable block (ram,0x0a5b2c) */
/* WARNING: Removing unreachable block (ram,0x0a5b24) */
/* WARNING: Removing unreachable block (ram,0x0a5b1c) */
/* WARNING: Removing unreachable block (ram,0x0a5b14) */
/* WARNING: Removing unreachable block (ram,0x0a5b0c) */
/* WARNING: Removing unreachable block (ram,0x0a5b08) */
/* WARNING: Removing unreachable block (ram,0x0a5af6) */
/* WARNING: Removing unreachable block (ram,0x0a5af2) */
/* WARNING: Removing unreachable block (ram,0x0a5aea) */
/* WARNING: Removing unreachable block (ram,0x0a5ae2) */
/* WARNING: Removing unreachable block (ram,0x0a5ada) */
/* WARNING: Removing unreachable block (ram,0x0a5ad2) */
/* WARNING: Removing unreachable block (ram,0x0a5aca) */
/* WARNING: Removing unreachable block (ram,0x0a5ac2) */
/* WARNING: Removing unreachable block (ram,0x0a5aba) */
/* WARNING: Removing unreachable block (ram,0x0a5ab2) */
/* WARNING: Removing unreachable block (ram,0x0a5aae) */
/* WARNING: Removing unreachable block (ram,0x0a5aa2) */
/* WARNING: Removing unreachable block (ram,0x0a5a9e) */
/* WARNING: Removing unreachable block (ram,0x0a5a96) */
/* WARNING: Removing unreachable block (ram,0x0a5a92) */
/* WARNING: Removing unreachable block (ram,0x0a5a8e) */
/* WARNING: Removing unreachable block (ram,0x0a5a86) */
/* WARNING: Removing unreachable block (ram,0x0a5a7e) */
/* WARNING: Removing unreachable block (ram,0x0a5a76) */
/* WARNING: Removing unreachable block (ram,0x0a5a6e) */

void egs52_update_near_f3fe_0a5a62(uint param_1,int param_2)

{
  uint uVar1;
  byte bVar2;
  
  uRam00f3fe = 0x65;
  uRam00f3ff = 0xac;
  uRam00f400 = 0xca;
  uRam00f401 = 0x35;
  bVar2 = UNK_00f615;
  UNK_00f615 = bVar2 | 0x20;
  uRam00f3e6 = param_1;
  iRam00f3e8 = param_2;
  (*(code *)((uint3)uRam08020a << 0x10 | (uint3)uRam080208))();
  uVar1 = Ram00fdee;
  if ((uVar1 & 4) != 0) {
    uRam00f3ea = 0xc000;
    uRam00f3ec = 0x1800;
    bVar2 = UNK_00f615;
    UNK_00f615 = bVar2 | 0x20;
    uRam00f3fe = 0x53;
    uRam00f3ff = 0xac;
    uRam00f400 = 0xca;
    uRam00f401 = 0x35;
    uRam00f3e6 = param_1;
    iRam00f3e8 = param_2;
    (*(code *)((uint3)uRam08020e << 0x10 | (uint3)uRam08020c))();
    uVar1 = Ram00fdee;
    if ((uVar1 & 2) != 0) {
      uRam00f3e6 = param_1 + 0x1800;
      iRam00f3e8 = param_2 + (uint)(0xe7ff < param_1);
      uRam00f3ea = 0xe000;
      uRam00f3ec = 0x800;
      bVar2 = UNK_00f615;
      UNK_00f615 = bVar2 | 0x20;
      uRam00f3fe = 0x53;
      uRam00f3ff = 0xac;
      uRam00f400 = 0xca;
      uRam00f401 = 0x35;
      (*(code *)((uint3)uRam08020e << 0x10 | (uint3)uRam08020c))();
    }
  }
  return;
}


