/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d7b3e; FLS offset 0x057b3e.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d7b60) */
/* WARNING: Removing unreachable block (ram,0x0d7b50) */
/* WARNING: Removing unreachable block (ram,0x0d7b4a) */
/* WARNING: Removing unreachable block (ram,0x0d7b44) */
/* WARNING: Removing unreachable block (ram,0x0d7b3e) */
/* WARNING: Removing unreachable block (ram,0x0d7b6a) */

void egs52_update_near_d4ae_0d7b3e(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar2 = Ram00d536;
  uVar1 = param_1 + iVar2;
  uVar3 = Ram00d54a;
  uVar4 = Ram00d54a;
  if (uVar1 == uVar4 || uVar1 < uVar3) {
    Ram00d4ae = 0;
    return;
  }
  iVar2 = Ram00d54a;
  uVar3 = Ram00d46e;
  Ram00d4ae = (int)(((ulong)(uVar1 - iVar2) * (ulong)(param_2 & 0xff)) / (ulong)uVar3);
  return;
}


