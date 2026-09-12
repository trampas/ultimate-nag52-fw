/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x08272c; FLS offset 0x00272c.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x082786) */
/* WARNING: Removing unreachable block (ram,0x082782) */
/* WARNING: Removing unreachable block (ram,0x08277e) */
/* WARNING: Removing unreachable block (ram,0x08277a) */
/* WARNING: Removing unreachable block (ram,0x082776) */
/* WARNING: Removing unreachable block (ram,0x08276c) */
/* WARNING: Removing unreachable block (ram,0x082762) */
/* WARNING: Removing unreachable block (ram,0x08275e) */
/* WARNING: Removing unreachable block (ram,0x082750) */
/* WARNING: Removing unreachable block (ram,0x08274c) */
/* WARNING: Removing unreachable block (ram,0x082746) */
/* WARNING: Removing unreachable block (ram,0x082742) */
/* WARNING: Removing unreachable block (ram,0x08273e) */
/* WARNING: Removing unreachable block (ram,0x08273c) */
/* WARNING: Removing unreachable block (ram,0x082738) */
/* WARNING: Removing unreachable block (ram,0x082734) */
/* WARNING: Removing unreachable block (ram,0x082730) */

void egs52_update_near_f471_08272c(void)

{
  uint uVar1;
  uint uVar2;
  
  uRam00f471 = 0x7f;
  uVar1 = 0x24;
  if ((((uRam00f464 & 0xc000) != 0) && (uVar1 = 0x21, (uRam00f464 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uRam00f464 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uRam00f464 & 0x3fff)) = uRam00f582;
  uVar1 = uRam00f464 + 1;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) = uRam00f581;
  uRam00f46c = 3;
  if ((bRam00f46d & 0xc0) != 0) {
    bRam00f46d = 0x80;
  }
  bRam00f46d = bRam00f46d & 0xc0 | 3;
  uVar1 = Ram00fdea;
  Ram00fdea = uVar1 & 0xfdff;
  uRam00f460 = 0xf46d;
  uRam00f46e = uRam00f46f;
  uRam00f46f = uRam00f594;
  return;
}


