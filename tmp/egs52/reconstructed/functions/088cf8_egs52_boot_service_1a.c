/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x088cf8; FLS offset 0x008cf8.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x088e28) */
/* WARNING: Removing unreachable block (ram,0x088e24) */
/* WARNING: Removing unreachable block (ram,0x088e0e) */
/* WARNING: Removing unreachable block (ram,0x088d88) */
/* WARNING: Removing unreachable block (ram,0x088d92) */
/* WARNING: Removing unreachable block (ram,0x088d8a) */
/* WARNING: Removing unreachable block (ram,0x088d82) */
/* WARNING: Removing unreachable block (ram,0x088de8) */
/* WARNING: Removing unreachable block (ram,0x088dba) */
/* WARNING: Removing unreachable block (ram,0x088dce) */
/* WARNING: Removing unreachable block (ram,0x088db6) */
/* WARNING: Removing unreachable block (ram,0x088dfa) */
/* WARNING: Removing unreachable block (ram,0x088db2) */
/* WARNING: Removing unreachable block (ram,0x088daa) */
/* WARNING: Removing unreachable block (ram,0x088e06) */
/* WARNING: Removing unreachable block (ram,0x088d3a) */
/* WARNING: Removing unreachable block (ram,0x088d36) */
/* WARNING: Removing unreachable block (ram,0x088d32) */
/* WARNING: Removing unreachable block (ram,0x088d20) */
/* WARNING: Removing unreachable block (ram,0x088d1c) */
/* WARNING: Removing unreachable block (ram,0x088d18) */
/* WARNING: Removing unreachable block (ram,0x088e32) */
/* WARNING: Removing unreachable block (ram,0x088d64) */
/* WARNING: Removing unreachable block (ram,0x088d60) */
/* WARNING: Removing unreachable block (ram,0x088d4e) */
/* WARNING: Removing unreachable block (ram,0x088d4a) */
/* WARNING: Removing unreachable block (ram,0x088d00) */
/* WARNING: Removing unreachable block (ram,0x088d0a) */
/* WARNING: Removing unreachable block (ram,0x088d0e) */
/* WARNING: Removing unreachable block (ram,0x088dae) */
/* WARNING: Removing unreachable block (ram,0x088d7c) */
/* WARNING: Removing unreachable block (ram,0x088d8c) */
/* WARNING: Removing unreachable block (ram,0x088d96) */
/* WARNING: Removing unreachable block (ram,0x088e16) */
/* WARNING: Removing unreachable block (ram,0x088e20) */
/* WARNING: Removing unreachable block (ram,0x088ddc) */
/* WARNING: Removing unreachable block (ram,0x088de0) */
/* WARNING: Removing unreachable block (ram,0x088dd8) */
/* WARNING: Removing unreachable block (ram,0x088de4) */
/* WARNING: Heritage AFTER dead removal. Example location: r0x00f462 : 0x088d0a */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void egs52_boot_service_1a(undefined2 param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  char cVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uStack_a;
  
  iVar3 = iRam080266;
  uVar7 = uRam080264;
  if (bRam00f469 == 2) {
    uVar8 = 0x24;
    if ((((uRam00f462 & 0xc000) != 0) && (uVar8 = 0x21, (uRam00f462 & 0xc000) != 0x4000)) &&
       (uVar8 = 0x2c, (uRam00f462 & 0xc000) != 0x8000)) {
      uVar8 = 3;
    }
    cVar1 = *(char *)((uint3)uVar8 << 0xe | (uint3)(uRam00f462 & 0x3fff));
    uVar8 = Ram00fdee;
    if ((uVar8 & 1) == 0) {
      uVar7 = iRam0900c4 << 2 | uRam0900c2 >> 0xe;
      uVar8 = iRam0900c8 << 2 | uRam0900c6 >> 0xe;
      uStack_a = uRam0900c2;
      uVar2 = uRam0900c6;
    }
    else {
      *(uint *)((uint3)((uint)&uStack_a & 0x3fff) | 0x80000) = uRam080264;
      iVar4 = iRam08026a;
      uVar8 = uRam080268;
      uVar7 = iVar3 << 2 | uVar7 >> 0xe;
      *(uint *)((uint3)((uint)&uStack_a & 0x3fff) | 0x80000) = uRam080268;
      uVar8 = iVar4 << 2 | uVar8 >> 0xe;
      uVar2 = uStack_a;
    }
    uVar6 = uStack_a & 0x3fff;
    if (cVar1 == -0x7f) {
      do {
        uRam00f462 = uRam00f462 + 1;
        *(undefined1 *)((uint3)(uVar7 & 0x3ff) << 0xe | (uint3)(uRam00f462 & 0x3fff)) =
             *(undefined1 *)((uint3)(uVar7 & 0x3ff) << 0xe | (uint3)(uVar6 & 0x3fff));
        bRam00f469 = bRam00f469 + 1;
        uVar6 = uVar6 + 1;
        uVar8 = 0x24;
        if ((((uRam00f462 & 0xc000) != 0) && (uVar8 = 0x21, (uRam00f462 & 0xc000) != 0x4000)) &&
           (uVar8 = 0x2c, (uRam00f462 & 0xc000) != 0x8000)) {
          uVar8 = 3;
        }
      } while (*(char *)((uint3)uVar8 << 0xe | (uint3)(uRam00f462 & 0x3fff)) != -1);
    }
    else {
      cVar5 = '\0';
      while (*(char *)((uint3)(uVar7 & 0x3ff) << 0xe | (uint3)(uVar6 & 0x3fff)) != -1) {
        if (cVar1 == -0x80) {
          uRam00f586 = uVar6;
          uRam00f588 = uVar7;
          uRam00f58a = uVar2 & 0x3fff;
          uRam00f58c = uVar8;
          cRam00f585 = cVar5;
          egs52_update_near_f462_088ea2(param_1);
        }
        else if (*(char *)((uint3)(uVar7 & 0x3ff) << 0xe | (uint3)(uVar6 + 1 & 0x3fff)) == cVar1) {
          uRam00f586 = uVar6;
          uRam00f588 = uVar7;
          uRam00f58a = uVar2 & 0x3fff;
          uRam00f58c = uVar8;
          cRam00f585 = cVar5;
          egs52_update_near_f462_088ea2(param_1);
        }
        param_1 = 0;
        uVar6 = uVar6 + *(byte *)((uint3)(uVar7 & 0x3ff) << 0xe | (uint3)(uVar6 & 0x3fff));
        cVar5 = cVar5 + '\x01';
      }
    }
    if (bRam00f469 < 3) {
      uRam00f581 = 0x12;
    }
    else {
      uRam00f581 = 0;
    }
    uRam00f462 = uRam00f464;
  }
  else {
    uRam00f581 = 0x79;
  }
  return;
}


