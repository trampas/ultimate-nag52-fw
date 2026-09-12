/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0e69be; FLS offset 0x0669be.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0e69da) */
/* WARNING: Removing unreachable block (ram,0x0e69fc) */
/* WARNING: Removing unreachable block (ram,0x0e6a38) */
/* WARNING: Removing unreachable block (ram,0x0e6a28) */
/* WARNING: Removing unreachable block (ram,0x0e6a2e) */
/* WARNING: Removing unreachable block (ram,0x0e6a22) */
/* WARNING: Removing unreachable block (ram,0x0e6a1e) */
/* WARNING: Removing unreachable block (ram,0x0e6a14) */
/* WARNING: Removing unreachable block (ram,0x0e6a0c) */
/* WARNING: Removing unreachable block (ram,0x0e69d0) */
/* WARNING: Removing unreachable block (ram,0x0e69c8) */
/* WARNING: Removing unreachable block (ram,0x0e69be) */
/* WARNING: Removing unreachable block (ram,0x0e69f2) */
/* WARNING: Removing unreachable block (ram,0x0e6a06) */
/* WARNING: Removing unreachable block (ram,0x0e69e4) */

void egs52_update_near_d486_0e69be(void)

{
  uint uVar1;
  undefined2 uVar2;
  uint uVar3;
  int iVar4;
  
  Ram00d486 = 0;
  uVar1 = Ram00fd12;
  Ram00fd12 = uVar1 & 0xbfff;
  uVar1 = Ram00fd5a;
  Ram00fd5a = uVar1 & 0xfbff;
  uVar1 = Ram00fd5a;
  Ram00fd5a = uVar1 & 0xfdff;
  uVar1 = Ram00fd4e;
  if (((uVar1 & 8) == 0) && (uVar1 = Ram00fd4e, (uVar1 & 0x20) == 0)) {
    uVar1 = Ram00fd2c;
    if ((uVar1 & 0x40) == 0) {
      uVar1 = Ram00fd5a;
      if (((uVar1 & 4) != 0) || (uVar1 = Ram00fd5a, (uVar1 & 0x800) != 0)) {
        uVar1 = Ram00fd12;
        Ram00fd12 = uVar1 | 0x4000;
        uVar1 = Ram00d4ba;
        uVar3 = Ram00d4b6;
        if (uVar1 < uVar3) {
          iVar4 = Ram00d4ba;
        }
        else {
          iVar4 = Ram00d4b6;
        }
        Ram00d486 = iVar4 * 4 + 2000;
      }
      return;
    }
    uVar1 = Ram00fd12;
    Ram00fd12 = uVar1 | 0x4000;
    iVar4 = Ram00d708;
    Ram00d486 = iVar4 * 4 + 2000;
    return;
  }
  uVar1 = Ram00fd12;
  Ram00fd12 = uVar1 | 0x4000;
  iVar4 = Ram00d4b8;
  Ram00d486 = iVar4 * 4 + 2000;
  uVar2 = Ram00fd5a;
  uVar1 = Ram00fd4e;
  uVar3 = Ram00fd5a;
  Ram00fd5a = uVar3 & 0xfbff | ((uVar1 & 0x10) >> 4) << 10;
  uVar2 = Ram00fd5a;
  uVar1 = Ram00fd4e;
  uVar3 = Ram00fd5a;
  Ram00fd5a = uVar3 & 0xfdff | ((uVar1 & 2) >> 1) << 9;
  return;
}


