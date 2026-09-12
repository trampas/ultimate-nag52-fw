/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a5a0e; FLS offset 0x025a0e.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Function: egs52_call_far_indirect replaced with injection: call_far_indirect */
/* WARNING: Removing unreachable block (ram,0x0a5a4e) */
/* WARNING: Removing unreachable block (ram,0x0a5a4a) */
/* WARNING: Removing unreachable block (ram,0x0a5a42) */
/* WARNING: Removing unreachable block (ram,0x0a5a3a) */
/* WARNING: Removing unreachable block (ram,0x0a5a32) */
/* WARNING: Removing unreachable block (ram,0x0a5a2a) */
/* WARNING: Removing unreachable block (ram,0x0a5a22) */
/* WARNING: Removing unreachable block (ram,0x0a5a1a) */
/* WARNING: Removing unreachable block (ram,0x0a5a16) */
/* WARNING: Removing unreachable block (ram,0x0a5a12) */
/* WARNING: Removing unreachable block (ram,0x0a5a0e) */
/* WARNING: Unknown calling convention */

uchar egs52_boot_request_53(ushort arg0,ushort arg1,ushort arg2,ushort arg3)

{
  uint uVar1;
  byte bVar2;
  
  uRam00f3fe = 0x53;
  uRam00f3ff = 0xac;
  uRam00f400 = 0xca;
  uRam00f401 = 0x35;
  bVar2 = UNK_00f615;
  UNK_00f615 = bVar2 | 0x20;
  uRam00f3e6 = arg0;
  uRam00f3e8 = arg1;
  uRam00f3ea = arg2;
  uRam00f3ec = arg3;
  (*(code *)((uint3)uRam08020e << 0x10 | (uint3)uRam08020c))();
  uVar1 = Ram00fdee;
  if ((uVar1 & 2) == 0) {
    return '\0';
  }
  return '\x01';
}


