/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0e5df0; FLS offset 0x065df0.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0e5e20) */
/* WARNING: Removing unreachable block (ram,0x0e5e10) */
/* WARNING: Removing unreachable block (ram,0x0e5e0a) */
/* WARNING: Removing unreachable block (ram,0x0e5e06) */
/* WARNING: Removing unreachable block (ram,0x0e5dfe) */
/* WARNING: Removing unreachable block (ram,0x0e5dfa) */
/* WARNING: Removing unreachable block (ram,0x0e5df4) */
/* WARNING: Removing unreachable block (ram,0x0e5df0) */
/* WARNING: Removing unreachable block (ram,0x0e5e2a) */

void egs52_update_near_d526_0e5df0(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  ushort old;
  ushort uVar4;
  
  iVar3 = Ram00f652;
  uVar1 = iVar3 + 0x70;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  uVar4 = Ram00d524;
  old = Ram00d526;
  uVar4 = egs52_weighted_average_u16
                    (*(uchar *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)),uVar4,old);
  Ram00d526 = uVar4;
  uVar1 = Ram00d4fa;
  if (uVar1 == 0) {
    Ram00d460 = 0;
    return;
  }
  uVar2 = Ram00d524;
  Ram00d460 = (int)(((ulong)uVar2 * 1000) / (ulong)uVar1);
  return;
}


