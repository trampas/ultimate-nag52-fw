/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x097116; FLS offset 0x017116.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x097140) */
/* WARNING: Removing unreachable block (ram,0x097134) */
/* WARNING: Removing unreachable block (ram,0x097122) */
/* WARNING: Removing unreachable block (ram,0x097152) */

undefined2 egs52_compute_from_near_f03c_097116(char param_1)

{
  uint uVar1;
  uint uVar2;
  undefined2 uVar3;
  
  if (param_1 == '\x02') {
    uVar2 = Ram00fe34;
    uVar1 = Ram00f03c;
    uVar3 = (undefined2)(((ulong)uVar2 * 100) / (ulong)uVar1);
  }
  else if (param_1 == '\x03') {
    uVar1 = Ram00fe36;
    uVar2 = Ram00f03e;
    uVar3 = (undefined2)(((ulong)uVar1 * 100) / (ulong)uVar2);
  }
  else {
    uVar3 = 0xff;
  }
  return uVar3;
}


