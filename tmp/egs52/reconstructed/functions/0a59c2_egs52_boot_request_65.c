/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a59c2; FLS offset 0x0259c2.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Function: egs52_call_far_indirect replaced with injection: call_far_indirect */
/* WARNING: Removing unreachable block (ram,0x0a59fa) */
/* WARNING: Removing unreachable block (ram,0x0a59f6) */
/* WARNING: Removing unreachable block (ram,0x0a59ee) */
/* WARNING: Removing unreachable block (ram,0x0a59e6) */
/* WARNING: Removing unreachable block (ram,0x0a59de) */
/* WARNING: Removing unreachable block (ram,0x0a59d6) */
/* WARNING: Removing unreachable block (ram,0x0a59ce) */
/* WARNING: Removing unreachable block (ram,0x0a59c6) */
/* WARNING: Removing unreachable block (ram,0x0a59c2) */
/* WARNING: Unknown calling convention */

uchar egs52_boot_request_65(ushort arg0,ushort arg1)

{
  uint uVar1;
  byte bVar2;
  
  uRam00f3fe = 0x65;
  uRam00f3ff = 0xac;
  uRam00f400 = 0xca;
  uRam00f401 = 0x35;
  bVar2 = UNK_00f615;
  UNK_00f615 = bVar2 | 0x20;
  uRam00f3e6 = arg0;
  uRam00f3e8 = arg1;
  (*(code *)((uint3)uRam08020a << 0x10 | (uint3)uRam080208))();
  uVar1 = Ram00fdee;
  if ((uVar1 & 4) == 0) {
    return '\0';
  }
  return '\x01';
}


