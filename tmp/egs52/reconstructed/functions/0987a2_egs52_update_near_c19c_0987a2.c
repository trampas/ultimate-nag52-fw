/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0987a2; FLS offset 0x0187a2.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x098854) */
/* WARNING: Removing unreachable block (ram,0x098850) */
/* WARNING: Removing unreachable block (ram,0x09884c) */
/* WARNING: Removing unreachable block (ram,0x098848) */
/* WARNING: Removing unreachable block (ram,0x098834) */
/* WARNING: Removing unreachable block (ram,0x098828) */
/* WARNING: Removing unreachable block (ram,0x098824) */
/* WARNING: Removing unreachable block (ram,0x098818) */
/* WARNING: Removing unreachable block (ram,0x09880c) */
/* WARNING: Removing unreachable block (ram,0x098800) */
/* WARNING: Removing unreachable block (ram,0x0987fc) */
/* WARNING: Removing unreachable block (ram,0x0987f0) */
/* WARNING: Removing unreachable block (ram,0x0987e4) */
/* WARNING: Removing unreachable block (ram,0x0987d8) */
/* WARNING: Removing unreachable block (ram,0x0987c8) */
/* WARNING: Removing unreachable block (ram,0x0987aa) */
/* WARNING: Removing unreachable block (ram,0x0987d4) */

void egs52_update_near_c19c_0987a2(void)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  int iVar4;
  
  iVar4 = 0;
  do {
    uVar1 = iVar4 + 0xc192;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) = 0xff;
    bVar3 = iVar4 < 2;
    iVar4 = iVar4 + 1;
  } while (bVar3);
  Ram00fe56 = 0xf447;
  uVar1 = Ram00ff50;
  Ram00ff50 = uVar1 & 0xf7ff;
  uVar1 = Ram00ff50;
  Ram00ff50 = uVar1 | 0x4000;
  uVar1 = Ram00ffc0;
  Ram00ffc0 = uVar1 | 1;
  uVar1 = Ram00ffc0;
  Ram00ffc0 = uVar1 | 2;
  uVar1 = Ram00ffc0;
  Ram00ffc0 = uVar1 | 4;
  Ram00fe80 = 0;
  Ram00fe90 = 0;
  uVar1 = Ram00ff52;
  Ram00ff52 = uVar1 & 0xfff0 | 0xd;
  uVar1 = Ram00ff56;
  Ram00ff56 = uVar1 & 0xfff0 | 0xc;
  Ram00fe82 = 0;
  Ram00fe92 = 0;
  uVar1 = Ram00ff52;
  Ram00ff52 = uVar1 & 0xff0f | 0xd0;
  uVar1 = Ram00ff56;
  Ram00ff56 = uVar1 & 0xff0f | 0xc0;
  Ram00fe84 = 0;
  Ram00fe94 = 0;
  uVar1 = Ram00ff52;
  Ram00ff52 = uVar1 & 0xf0ff | 0xd00;
  uVar1 = Ram00ff56;
  Ram00ff56 = uVar1 & 0xf0ff | 0xc00;
  iVar4 = 0;
  do {
    egs52_update_near_c19f_0989ea(iVar4 + 1);
    bVar3 = iVar4 < 2;
    iVar4 = iVar4 + 1;
  } while (bVar3);
  UNK_00c19c = 3;
  UNK_00c19d = 3;
  UNK_00c19e = 3;
  UNK_00c19f = 0;
  return;
}


