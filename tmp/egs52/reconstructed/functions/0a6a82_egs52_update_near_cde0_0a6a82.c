/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a6a82; FLS offset 0x026a82.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a6be8) */
/* WARNING: Removing unreachable block (ram,0x0a6be4) */
/* WARNING: Removing unreachable block (ram,0x0a6bde) */
/* WARNING: Removing unreachable block (ram,0x0a6bc4) */
/* WARNING: Removing unreachable block (ram,0x0a6bb4) */
/* WARNING: Removing unreachable block (ram,0x0a6bda) */
/* WARNING: Removing unreachable block (ram,0x0a6bcc) */
/* WARNING: Removing unreachable block (ram,0x0a6bac) */
/* WARNING: Removing unreachable block (ram,0x0a6ba6) */
/* WARNING: Removing unreachable block (ram,0x0a6ba0) */
/* WARNING: Removing unreachable block (ram,0x0a6b8c) */
/* WARNING: Removing unreachable block (ram,0x0a6b96) */
/* WARNING: Removing unreachable block (ram,0x0a6b64) */
/* WARNING: Removing unreachable block (ram,0x0a6b60) */
/* WARNING: Removing unreachable block (ram,0x0a6b5a) */
/* WARNING: Removing unreachable block (ram,0x0a6b44) */
/* WARNING: Removing unreachable block (ram,0x0a6b30) */
/* WARNING: Removing unreachable block (ram,0x0a6b56) */
/* WARNING: Removing unreachable block (ram,0x0a6b4e) */
/* WARNING: Removing unreachable block (ram,0x0a6b48) */
/* WARNING: Removing unreachable block (ram,0x0a6b28) */
/* WARNING: Removing unreachable block (ram,0x0a6b22) */
/* WARNING: Removing unreachable block (ram,0x0a6b20) */
/* WARNING: Removing unreachable block (ram,0x0a6b78) */
/* WARNING: Removing unreachable block (ram,0x0a6b12) */
/* WARNING: Removing unreachable block (ram,0x0a6b06) */
/* WARNING: Removing unreachable block (ram,0x0a6afc) */
/* WARNING: Removing unreachable block (ram,0x0a6af8) */
/* WARNING: Removing unreachable block (ram,0x0a6aee) */
/* WARNING: Removing unreachable block (ram,0x0a6ae6) */
/* WARNING: Removing unreachable block (ram,0x0a6ad8) */
/* WARNING: Removing unreachable block (ram,0x0a6ad4) */
/* WARNING: Removing unreachable block (ram,0x0a6ac2) */
/* WARNING: Removing unreachable block (ram,0x0a6aba) */
/* WARNING: Removing unreachable block (ram,0x0a6ab6) */
/* WARNING: Removing unreachable block (ram,0x0a6aa4) */
/* WARNING: Removing unreachable block (ram,0x0a6a9a) */
/* WARNING: Removing unreachable block (ram,0x0a6a86) */
/* WARNING: Removing unreachable block (ram,0x0a6a96) */
/* WARNING: Removing unreachable block (ram,0x0a6bd2) */
/* WARNING: Removing unreachable block (ram,0x0a6bb8) */
/* WARNING: Removing unreachable block (ram,0x0a6bc8) */
/* WARNING: Removing unreachable block (ram,0x0a6b34) */
/* WARNING: Removing unreachable block (ram,0x0a6b40) */
/* WARNING: Heritage AFTER dead removal. Example location: r0x00f468 : 0x0a6aa4 */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void egs52_update_near_cde0_0a6a82(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined1 uVar4;
  byte bVar5;
  byte bVar6;
  undefined1 uVar7;
  uint uVar8;
  char cVar9;
  int iVar10;
  uint uVar11;
  undefined2 uStack_4;
  
  uVar8 = uRam00f464;
  uVar11 = Ram00fdea;
  if (((uVar11 & 4) == 0) || (uVar11 = Ram00fdea, (uVar11 & 8) == 0)) {
    cRam00f581 = '\0';
    if ((bRam00f469 == 4) && ((bRam00f468 == 0xff || (uVar11 = Ram00fdec, (uVar11 & 0x20) == 0)))) {
      uVar11 = uRam00f462 + 1;
      uVar2 = 0x24;
      if (((uVar11 & 0xc000) != 0) &&
         ((uVar2 = 0x21, (uVar11 & 0xc000) != 0x4000 && (uVar2 = 0x2c, (uVar11 & 0xc000) != 0x8000))
         )) {
        uVar2 = 3;
      }
      uVar1 = uRam00f462 + 2;
      uVar3 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      uStack_4 = CONCAT11(*(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar11 & 0x3fff)),
                          *(undefined1 *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)));
      if ((uStack_4 == 0) || (uStack_4 == 0xff00)) {
        uVar11 = 0x24;
        if ((((uRam00f462 & 0xc000) != 0) && (uVar11 = 0x21, (uRam00f462 & 0xc000) != 0x4000)) &&
           (uVar11 = 0x2c, (uRam00f462 & 0xc000) != 0x8000)) {
          uVar11 = 3;
        }
        cVar9 = *(char *)((uint3)uVar11 << 0xe | (uint3)(uRam00f462 & 0x3fff));
        if (cVar9 == '\x02') {
          UNK_00cde0 = 2;
        }
        else if (cVar9 == '\x03') {
          UNK_00cde0 = 3;
        }
        else {
          cRam00f581 = '\x12';
        }
        if (cRam00f581 == '\0') {
          uVar4 = UNK_00cde0;
          cVar9 = egs52_update_near_cdf1_0a77dc(uRam00f464,uVar4,0xff);
          UNK_00cde1 = cVar9;
          if (cVar9 == -1) {
            cRam00f581 = '\x12';
          }
          else {
            iVar10 = uVar8 + 1;
            uVar11 = 0x24;
            if ((((uVar8 & 0xc000) != 0) && (uVar11 = 0x21, (uVar8 & 0xc000) != 0x4000)) &&
               (uVar11 = 0x2c, (uVar8 & 0xc000) != 0x8000)) {
              uVar11 = 3;
            }
            *(char *)((uint3)uVar11 << 0xe | (uint3)(uVar8 & 0x3fff)) = cVar9;
            UNK_00cde2 = 0;
            bRam00f469 = 2;
            while (bRam00f469 + 3 <= (uint)bRam00f468) {
              bVar6 = UNK_00cde2;
              bVar5 = UNK_00cde1;
              if (bVar5 <= bVar6) break;
              uVar4 = UNK_00cde0;
              uVar7 = UNK_00cde2;
              egs52_update_near_cdf1_0a77dc(iVar10,uVar4,uVar7);
              iVar10 = iVar10 + 3;
              bRam00f469 = bRam00f469 + 3;
              cVar9 = UNK_00cde2;
              UNK_00cde2 = cVar9 + '\x01';
            }
            bVar6 = UNK_00cde2;
            bVar5 = UNK_00cde1;
            if (bVar6 < bVar5) {
              uVar11 = Ram00fdea;
              Ram00fdea = uVar11 | 4;
              uVar11 = Ram00fdea;
              Ram00fdea = uVar11 | 8;
            }
          }
        }
      }
      else if ((uStack_4 & 0x3fff) == 0) {
        cRam00f581 = '1';
      }
      else {
        cRam00f581 = '\x12';
      }
    }
    else {
      cRam00f581 = 'y';
    }
  }
  else {
    cRam00f581 = '\0';
    bRam00f469 = 1;
    uVar11 = uRam00f464;
    while (bRam00f469 + 3 <= (uint)bRam00f468) {
      bVar6 = UNK_00cde2;
      bVar5 = UNK_00cde1;
      if (bVar5 <= bVar6) break;
      uVar4 = UNK_00cde0;
      uVar7 = UNK_00cde2;
      egs52_update_near_cdf1_0a77dc(uVar11,uVar4,uVar7);
      uVar11 = uVar11 + 3;
      bRam00f469 = bRam00f469 + 3;
      cVar9 = UNK_00cde2;
      UNK_00cde2 = cVar9 + '\x01';
    }
    bVar6 = UNK_00cde2;
    bVar5 = UNK_00cde1;
    if (bVar5 <= bVar6) {
      uVar11 = Ram00fdea;
      Ram00fdea = uVar11 & 0xfffb;
      uVar11 = Ram00fdea;
      Ram00fdea = uVar11 & 0xfff7;
    }
  }
  return;
}


