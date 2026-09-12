/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x088024; FLS offset 0x008024.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x08806a) */
/* WARNING: Removing unreachable block (ram,0x088066) */
/* WARNING: Removing unreachable block (ram,0x08805e) */
/* WARNING: Removing unreachable block (ram,0x088056) */
/* WARNING: Removing unreachable block (ram,0x08804e) */
/* WARNING: Removing unreachable block (ram,0x088042) */
/* WARNING: Removing unreachable block (ram,0x08803e) */
/* WARNING: Removing unreachable block (ram,0x08803a) */
/* WARNING: Removing unreachable block (ram,0x088032) */
/* WARNING: Removing unreachable block (ram,0x08802a) */

void egs52_boot_service_81(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = uRam00f462;
  uVar1 = Ram00fdea;
  Ram00fdea = uVar1 & 0x7fff;
  uVar1 = Ram00fdec;
  Ram00fdec = uVar1 | 2;
  uVar1 = 0x24;
  if ((((uRam00f462 & 0xc000) != 0) && (uVar1 = 0x21, (uRam00f462 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uRam00f462 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uRam00f462 & 0x3fff)) = 0xef;
  uVar2 = uVar2 + 1;
  uVar1 = 0x24;
  if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) = 0x8f;
  uRam00f469 = 3;
  uRam00f581 = 0;
  egs52_update_near_f57f_088f1e();
  uRam00f574 = 0x1f5;
  uRam00f576 = 5000;
  uRam00f578 = 0x37;
  uRam00f57c = 0x19;
  uRam00f5a0 = 0;
  return;
}


