/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d02e2; FLS offset 0x0502e2.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d0326) */
/* WARNING: Removing unreachable block (ram,0x0d0322) */
/* WARNING: Removing unreachable block (ram,0x0d031e) */
/* WARNING: Removing unreachable block (ram,0x0d031a) */
/* WARNING: Removing unreachable block (ram,0x0d0316) */
/* WARNING: Removing unreachable block (ram,0x0d0312) */
/* WARNING: Removing unreachable block (ram,0x0d030e) */
/* WARNING: Removing unreachable block (ram,0x0d030a) */
/* WARNING: Removing unreachable block (ram,0x0d0306) */
/* WARNING: Removing unreachable block (ram,0x0d02fe) */
/* WARNING: Removing unreachable block (ram,0x0d02fa) */
/* WARNING: Removing unreachable block (ram,0x0d02f6) */
/* WARNING: Removing unreachable block (ram,0x0d02f2) */
/* WARNING: Removing unreachable block (ram,0x0d02ee) */
/* WARNING: Removing unreachable block (ram,0x0d02e6) */
/* WARNING: Removing unreachable block (ram,0x0d02e2) */

void egs52_update_near_d23f_0d02e2(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  UNK_00d23f = 0xff;
  UNK_00d243 = 0xff;
  UNK_00d29b = 0x20;
  UNK_00d29c = 0x20;
  UNK_00d29d = 0xff;
  UNK_00d29f = 0xff;
  UNK_00d2a0 = 0xff;
  Ram00fd20 = 0x7ff;
  Ram00d472 = 0xffff;
  iVar3 = Ram00f67a;
  uVar1 = iVar3 + 10;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  UNK_00d5cd = *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
  UNK_00d5f4 = 0xff;
  UNK_00d5cb = 0xff;
  Ram00d4f4 = 0xffff;
  UNK_00d520 = 0xff;
  return;
}


