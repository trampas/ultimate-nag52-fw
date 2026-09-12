/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a6bf8; FLS offset 0x026bf8.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a6c64) */
/* WARNING: Removing unreachable block (ram,0x0a6c50) */
/* WARNING: Removing unreachable block (ram,0x0a6c4e) */
/* WARNING: Removing unreachable block (ram,0x0a6c46) */
/* WARNING: Removing unreachable block (ram,0x0a6c5c) */
/* WARNING: Removing unreachable block (ram,0x0a6c58) */
/* WARNING: Removing unreachable block (ram,0x0a6c32) */
/* WARNING: Removing unreachable block (ram,0x0a6c2e) */
/* WARNING: Removing unreachable block (ram,0x0a6c22) */
/* WARNING: Removing unreachable block (ram,0x0a6c1c) */
/* WARNING: Removing unreachable block (ram,0x0a6c0a) */
/* WARNING: Removing unreachable block (ram,0x0a6c02) */
/* WARNING: Removing unreachable block (ram,0x0a6bfe) */
/* WARNING: Removing unreachable block (ram,0x0a6c18) */
/* WARNING: Removing unreachable block (ram,0x0a6c6c) */

void egs52_update_near_f469_0a6bf8(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  char cVar6;
  undefined2 uStack_6;
  
  uVar5 = uRam00f464;
  if ((cRam00f469 == '\x03') && ((cRam00f468 == -1 || (uVar2 = Ram00fdec, (uVar2 & 0x20) == 0)))) {
    uVar2 = 0x24;
    if (((uRam00f462 & 0xc000) != 0) &&
       ((uVar2 = 0x21, (uRam00f462 & 0xc000) != 0x4000 &&
        (uVar2 = 0x2c, (uRam00f462 & 0xc000) != 0x8000)))) {
      uVar2 = 3;
    }
    uVar1 = uRam00f462 + 1;
    uVar3 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    uStack_6 = CONCAT11(*(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uRam00f462 & 0x3fff)),
                        *(undefined1 *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)));
    iVar4 = uRam00f464 + 1;
    uVar2 = 0x24;
    if ((((uRam00f464 & 0xc000) != 0) && (uVar2 = 0x21, (uRam00f464 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uRam00f464 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uRam00f464 & 0x3fff)) = 0;
    cRam00f469 = '\x05';
    cVar6 = egs52_transform_memory_0a79fc(iVar4,uStack_6);
    if (cVar6 == -0xe) {
      cRam00f469 = '\x02';
      uRam00f581 = 0;
    }
    else {
      cRam00f469 = cRam00f469 + cVar6;
      uVar2 = 0x24;
      if ((((uVar5 & 0xc000) != 0) && (uVar2 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar5 & 0x3fff)) = 1;
      uRam00f581 = 0;
    }
  }
  else {
    cRam00f469 = '\x02';
    uRam00f581 = 0x79;
  }
  return;
}


