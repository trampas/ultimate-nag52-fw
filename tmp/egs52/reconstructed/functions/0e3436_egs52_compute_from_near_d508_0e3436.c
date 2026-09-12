/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0e3436; FLS offset 0x063436.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0e3450) */
/* WARNING: Removing unreachable block (ram,0x0e344a) */
/* WARNING: Removing unreachable block (ram,0x0e3444) */
/* WARNING: Removing unreachable block (ram,0x0e343e) */
/* WARNING: Removing unreachable block (ram,0x0e3438) */

undefined1 egs52_compute_from_near_d508_0e3436(void)

{
  uint uVar1;
  int iVar2;
  undefined1 uVar3;
  
  iVar2 = Ram00d508;
  if ((((((iVar2 == 0) && (iVar2 = Ram00d50e, iVar2 == 0)) && (iVar2 = Ram00d512, iVar2 == 0)) &&
       ((iVar2 = Ram00d516, iVar2 == 0 && (iVar2 = Ram00d51a, iVar2 == 0)))) &&
      ((uVar1 = Ram00fd60, (uVar1 & 0x80) == 0 &&
       ((uVar1 = Ram00fd60, (uVar1 & 0x40) == 0 && (uVar1 = Ram00fd60, (uVar1 & 0x20) == 0)))))) &&
     ((uVar1 = Ram00fd60, (uVar1 & 0x10) == 0 && (uVar1 = Ram00fd60, (uVar1 & 8) == 0)))) {
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}


