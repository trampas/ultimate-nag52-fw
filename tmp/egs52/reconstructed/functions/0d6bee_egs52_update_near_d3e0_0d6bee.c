/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d6bee; FLS offset 0x056bee.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d6c24) */
/* WARNING: Removing unreachable block (ram,0x0d6c14) */
/* WARNING: Removing unreachable block (ram,0x0d6c10) */
/* WARNING: Removing unreachable block (ram,0x0d6c02) */
/* WARNING: Removing unreachable block (ram,0x0d6bf6) */
/* WARNING: Removing unreachable block (ram,0x0d6bf0) */
/* WARNING: Removing unreachable block (ram,0x0d6c2a) */
/* WARNING: Removing unreachable block (ram,0x0d6bfc) */

void egs52_update_near_d3e0_0d6bee(void)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  ushort *xs;
  int iVar4;
  ushort uVar5;
  
  cVar1 = UNK_00d474;
  if (cVar1 == '\0') {
    Ram00d3e0 = 0;
  }
  else {
    bVar2 = UNK_00d5cc;
    uVar5 = Ram00d54e;
    iVar3 = Ram00f658;
    xs = (ushort *)Ram00f658;
    iVar4 = Ram00f658;
    uVar5 = egs52_map_u16(7,5,xs,(ushort *)(iVar4 + 0xe),(ushort *)(iVar3 + 0x18),uVar5,(uint)bVar2)
    ;
    Ram00d3e0 = uVar5;
  }
  return;
}


