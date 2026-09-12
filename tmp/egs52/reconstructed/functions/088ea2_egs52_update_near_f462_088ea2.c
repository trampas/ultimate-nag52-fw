/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x088ea2; FLS offset 0x008ea2.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x088f0c) */
/* WARNING: Removing unreachable block (ram,0x088f00) */
/* WARNING: Removing unreachable block (ram,0x088f0e) */
/* WARNING: Removing unreachable block (ram,0x088f06) */
/* WARNING: Removing unreachable block (ram,0x088ef0) */
/* WARNING: Removing unreachable block (ram,0x088eee) */
/* WARNING: Removing unreachable block (ram,0x088eec) */
/* WARNING: Removing unreachable block (ram,0x088ee4) */
/* WARNING: Removing unreachable block (ram,0x088eb8) */
/* WARNING: Removing unreachable block (ram,0x088ec6) */
/* WARNING: Removing unreachable block (ram,0x088eb4) */
/* WARNING: Removing unreachable block (ram,0x088eae) */
/* WARNING: Removing unreachable block (ram,0x088eaa) */
/* WARNING: Removing unreachable block (ram,0x088ebc) */
/* WARNING: Removing unreachable block (ram,0x088ed6) */
/* WARNING: Removing unreachable block (ram,0x088eda) */
/* WARNING: Removing unreachable block (ram,0x088ee0) */

void egs52_update_near_f462_088ea2(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  char cVar4;
  char cVar5;
  byte bVar6;
  uint uVar7;
  uint uStack_6;
  
  bVar6 = 2;
  cVar5 = '\0';
  cVar4 = *(char *)((uint3)(uRam00f588 & 0x3ff) << 0xe | (uint3)(uRam00f586 & 0x3fff)) + -2;
  do {
    cVar5 = cVar5 + (*(byte *)((uint3)(uRam00f588 & 0x3ff) << 0xe |
                              (uint3)(uRam00f586 + bVar6 & 0x3fff)) & 0xf);
    cVar4 = cVar4 + -1;
    bVar6 = bVar6 + 1;
  } while (cVar4 != '\0');
  cRam00f469 = cRam00f469 + cVar5;
  uVar7 = iRam00f58a + (uint)bRam00f585 * 4;
  uVar2 = *(uint *)((uint3)(uRam00f58c & 0x3ff) << 0xe | (uint3)(uVar7 & 0x3fff));
  iVar1 = *(int *)((uint3)(uRam00f58c & 0x3ff) << 0xe | (uint3)(uVar7 + 2 & 0x3fff));
  *(uint *)((uint3)(uRam00f58c & 0x3ff) << 0xe | (uint3)((uint)&uStack_6 & 0x3fff)) = uVar2;
  uVar2 = uVar2 >> 0xe;
  uVar3 = iVar1 << 2;
  uVar7 = uStack_6 & 0x3fff;
  for (; cVar5 != '\0'; cVar5 = cVar5 + -1) {
    uRam00f462 = uRam00f462 + 1;
    *(undefined1 *)((uint3)(uVar3 & 0x3ff | uVar2) << 0xe | (uint3)(uRam00f462 & 0x3fff)) =
         *(undefined1 *)((uint3)(uVar3 & 0x3ff | uVar2) << 0xe | (uint3)(uVar7 & 0x3fff));
    uVar7 = uVar7 + 1;
  }
  return;
}


