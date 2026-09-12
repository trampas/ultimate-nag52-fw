/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0e352c; FLS offset 0x06352c.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0e355c) */
/* WARNING: Removing unreachable block (ram,0x0e3540) */
/* WARNING: Removing unreachable block (ram,0x0e353a) */
/* WARNING: Removing unreachable block (ram,0x0e3534) */
/* WARNING: Removing unreachable block (ram,0x0e352c) */
/* WARNING: Removing unreachable block (ram,0x0e356c) */

uint egs52_compute_from_near_f672_0e352c(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  char cVar4;
  
  iVar3 = Ram00f672;
  uVar2 = iVar3 + 0x1a;
  uVar1 = 0x24;
  if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  if ((*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) & 1) == 0) {
    return 0;
  }
  uVar1 = 0x24;
  if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  if ((*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) & 2) == 0) {
    uVar1 = Ram00fd3a;
    return uVar1 >> 0xe & 1;
  }
  cVar4 = UNK_00d569;
  if (((cVar4 == '\x02') && (uVar1 = Ram00fd60, (uVar1 & 0x80) == 0)) &&
     ((uVar1 = Ram00fd60, (uVar1 & 0x40) == 0 &&
      (((uVar1 = Ram00fd60, (uVar1 & 0x20) == 0 && (uVar1 = Ram00fd60, (uVar1 & 0x10) == 0)) &&
       (uVar1 = Ram00fd62, (uVar1 & 1) == 0)))))) {
    uVar1 = Ram00fd3a;
    return uVar1 >> 0xe & 1;
  }
  return 0;
}


