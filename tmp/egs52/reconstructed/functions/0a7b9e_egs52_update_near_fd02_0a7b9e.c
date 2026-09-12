/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a7b9e; FLS offset 0x027b9e.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Function: egs52_call_far_indirect replaced with injection: call_far_indirect */
/* WARNING: Removing unreachable block (ram,0x0a7bfa) */
/* WARNING: Removing unreachable block (ram,0x0a7c0c) */
/* WARNING: Removing unreachable block (ram,0x0a7be6) */
/* WARNING: Removing unreachable block (ram,0x0a7bdc) */
/* WARNING: Removing unreachable block (ram,0x0a7bb6) */
/* WARNING: Removing unreachable block (ram,0x0a7bc4) */
/* WARNING: Removing unreachable block (ram,0x0a7bb2) */
/* WARNING: Removing unreachable block (ram,0x0a7ba0) */
/* WARNING: Removing unreachable block (ram,0x0a7bc8) */
/* WARNING: Removing unreachable block (ram,0x0a7bd4) */
/* WARNING: Removing unreachable block (ram,0x0a7be0) */
/* WARNING: Removing unreachable block (ram,0x0a7c10) */
/* WARNING: Removing unreachable block (ram,0x0a7bfe) */

void egs52_update_near_fd02_0a7b9e(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  int iVar6;
  
  uVar1 = Ram00fd02;
  Ram00fd02 = uVar1 | 0x1000;
  Ram00f8b4 = 0xffff;
  __write_psw_bits(0xf000,0xd000);
  iVar6 = 0;
  while( true ) {
    uVar1 = iVar6 * 4 + 0xab2;
    uVar3 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    uVar2 = iVar6 * 4 + 0xab4;
    uVar4 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar4 = 3;
    }
    if (*(int *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)) == 0 &&
        *(int *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff)) == 0) break;
    uVar1 = iVar6 * 4 + 0xab2;
    uVar3 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    uVar2 = iVar6 * 4 + 0xab4;
    uVar4 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar4 = 3;
    }
    (*(code *)((uint3)*(uint *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff)) << 0x10 |
              (uint3)*(uint *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff))))();
    iVar6 = iVar6 + 1;
  }
  iVar6 = 0;
  do {
    uVar1 = iVar6 - 0x744;
    uVar3 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    *(undefined1 *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)) = 0;
    bVar5 = iVar6 < 3;
    iVar6 = iVar6 + 1;
  } while (bVar5);
  Ram00f8b6 = 0;
  Ram00f8ba = 0;
  Ram00f8b8 = 5;
  egs52_update_near_f8c0_0a7d0e(0);
  __write_psw_bits(0xf000,0);
  do {
    iVar6 = 0;
    while( true ) {
      uVar1 = iVar6 * 4 + 0xace;
      uVar3 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      uVar2 = iVar6 * 4 + 0xad0;
      uVar4 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar4 = 3;
      }
      if (*(int *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)) == 0 &&
          *(int *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff)) == 0) break;
      uVar1 = iVar6 * 4 + 0xace;
      uVar3 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      uVar2 = iVar6 * 4 + 0xad0;
      uVar4 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar4 = 3;
      }
      (*(code *)((uint3)*(uint *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff)) << 0x10 |
                (uint3)*(uint *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff))))();
      iVar6 = iVar6 + 1;
    }
    egs52_update_near_f8c0_0a7d0e(0);
  } while( true );
}


