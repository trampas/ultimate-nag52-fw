/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x09ef1e; FLS offset 0x01ef1e.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x09efa2) */
/* WARNING: Removing unreachable block (ram,0x09ef98) */
/* WARNING: Removing unreachable block (ram,0x09ef96) */
/* WARNING: Removing unreachable block (ram,0x09ef92) */
/* WARNING: Removing unreachable block (ram,0x09ef8c) */
/* WARNING: Removing unreachable block (ram,0x09ef88) */
/* WARNING: Removing unreachable block (ram,0x09ef7a) */
/* WARNING: Removing unreachable block (ram,0x09ef76) */
/* WARNING: Removing unreachable block (ram,0x09ef72) */
/* WARNING: Removing unreachable block (ram,0x09ef52) */
/* WARNING: Removing unreachable block (ram,0x09ef48) */
/* WARNING: Removing unreachable block (ram,0x09ef44) */
/* WARNING: Removing unreachable block (ram,0x09ef20) */

void egs52_update_near_c332_09ef1e(void)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  ushort uVar5;
  ushort uStack_6;
  ushort uStack_4;
  uint uStack_2;
  
  bVar2 = UNK_00c32a;
  if ((bVar2 & 1) == 0) {
    uStack_6 = Ram00c332;
    uStack_4 = Ram00c334;
    uStack_2 = Ram00c336;
  }
  else {
    egs52_copy_words_registers(&uStack_6);
    egs52_transform_far_memory_09e4c8();
  }
  if (0x100 < uStack_2) {
    uStack_2 = 0x100;
  }
  uVar1 = Ram00c332;
  Ram00c332 = uVar1 + uStack_2;
  iVar3 = Ram00c334;
  Ram00c334 = iVar3 + (uint)CARRY2(uVar1,uStack_2);
  iVar3 = Ram00c336;
  Ram00c336 = iVar3 - uStack_2;
  uVar4 = Ram00c338;
  uVar1 = 0x24;
  if ((((uVar4 & 0xc000) != 0) && (uVar1 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  uVar5 = egs52_crc16_a001_far
                    (uStack_6,uStack_4,uStack_2,
                     *(ushort *)((uint3)uVar1 << 0xe | (uint3)(uVar4 & 0x3fff)));
  uVar4 = Ram00c338;
  uVar1 = 0x24;
  if ((((uVar4 & 0xc000) != 0) && (uVar1 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  *(ushort *)((uint3)uVar1 << 0xe | (uint3)(uVar4 & 0x3fff)) = uVar5;
  iVar3 = Ram00c336;
  if (iVar3 == 0) {
    bVar2 = UNK_00c32a;
    UNK_00c32a = bVar2 & 0xfb;
  }
  return;
}


