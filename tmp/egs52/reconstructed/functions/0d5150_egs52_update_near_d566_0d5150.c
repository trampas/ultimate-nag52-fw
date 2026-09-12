/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d5150; FLS offset 0x055150.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d52b0) */
/* WARNING: Removing unreachable block (ram,0x0d529e) */
/* WARNING: Removing unreachable block (ram,0x0d529a) */
/* WARNING: Removing unreachable block (ram,0x0d528a) */
/* WARNING: Removing unreachable block (ram,0x0d5286) */
/* WARNING: Removing unreachable block (ram,0x0d52b8) */
/* WARNING: Removing unreachable block (ram,0x0d5278) */
/* WARNING: Removing unreachable block (ram,0x0d5280) */
/* WARNING: Removing unreachable block (ram,0x0d526e) */
/* WARNING: Removing unreachable block (ram,0x0d526a) */
/* WARNING: Removing unreachable block (ram,0x0d5266) */
/* WARNING: Removing unreachable block (ram,0x0d5248) */
/* WARNING: Removing unreachable block (ram,0x0d5238) */
/* WARNING: Removing unreachable block (ram,0x0d5228) */
/* WARNING: Removing unreachable block (ram,0x0d51f0) */
/* WARNING: Removing unreachable block (ram,0x0d5216) */
/* WARNING: Removing unreachable block (ram,0x0d5220) */
/* WARNING: Removing unreachable block (ram,0x0d520c) */
/* WARNING: Removing unreachable block (ram,0x0d5208) */
/* WARNING: Removing unreachable block (ram,0x0d5204) */
/* WARNING: Removing unreachable block (ram,0x0d51f8) */
/* WARNING: Removing unreachable block (ram,0x0d51e6) */
/* WARNING: Removing unreachable block (ram,0x0d51de) */
/* WARNING: Removing unreachable block (ram,0x0d51d6) */
/* WARNING: Removing unreachable block (ram,0x0d51c4) */
/* WARNING: Removing unreachable block (ram,0x0d51bc) */
/* WARNING: Removing unreachable block (ram,0x0d51b4) */
/* WARNING: Removing unreachable block (ram,0x0d51ac) */
/* WARNING: Removing unreachable block (ram,0x0d51a4) */
/* WARNING: Removing unreachable block (ram,0x0d519c) */
/* WARNING: Removing unreachable block (ram,0x0d5190) */
/* WARNING: Removing unreachable block (ram,0x0d5184) */
/* WARNING: Removing unreachable block (ram,0x0d5178) */
/* WARNING: Removing unreachable block (ram,0x0d5166) */
/* WARNING: Removing unreachable block (ram,0x0d515e) */
/* WARNING: Removing unreachable block (ram,0x0d5156) */
/* WARNING: Removing unreachable block (ram,0x0d5152) */
/* WARNING: Removing unreachable block (ram,0x0d51ce) */
/* WARNING: Removing unreachable block (ram,0x0d5240) */
/* WARNING: Removing unreachable block (ram,0x0d525a) */
/* WARNING: Removing unreachable block (ram,0x0d52a8) */

void egs52_update_near_d566_0d5150(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  char cVar4;
  byte bVar5;
  int iVar6;
  
  UNK_00d566 = 0;
  UNK_00d567 = 0;
  uVar1 = Ram00fd3a;
  Ram00fd3a = uVar1 & 0xffdf;
  uVar1 = Ram00fd4e;
  Ram00fd4e = uVar1 & 0xfffe;
  bVar5 = UNK_00d775;
  if ((((bVar5 < 3) && (cVar4 = UNK_00d579, cVar4 != '\x06')) &&
      (uVar1 = Ram00fd3a, (uVar1 & 2) == 0)) && (uVar1 = Ram00fd3a, (uVar1 & 0x10) == 0)) {
    uVar1 = Ram00fd48;
    Ram00fd48 = uVar1 | 4;
  }
  uVar1 = Ram00fd3a;
  if ((((uVar1 & 0x10) != 0) && (uVar1 = Ram00fd3c, (uVar1 & 0x80) == 0)) &&
     ((bVar5 = UNK_00d613, bVar5 < 6 || ((bVar5 == 7 || (uVar1 = Ram00fd4a, (uVar1 & 4) != 0)))))) {
    uVar1 = Ram00fd4a;
    Ram00fd4a = uVar1 & 0xfffb;
    uVar1 = Ram00fd3c;
    Ram00fd3c = uVar1 | 0x80;
  }
  uVar1 = Ram00fd30;
  if ((((uVar1 & 2) == 0) || (cVar4 = UNK_00d613, cVar4 == '\a')) &&
     (((uVar1 = Ram00fd30, (uVar1 & 1) == 0 || (bVar5 = UNK_00d613, bVar5 < 6)) &&
      ((uVar1 = Ram00fd68, (uVar1 & 2) == 0 && (uVar1 = Ram00fd5c, (uVar1 & 2) == 0)))))) {
    uVar1 = Ram00fd3a;
    if ((uVar1 & 2) == 0) {
      cVar4 = UNK_00d579;
      if ((cVar4 == '\a') || (cVar4 == '\b')) {
        UNK_00d437 = 5;
      }
      else {
        uVar1 = Ram00fd3a;
        if (((uVar1 & 0x10) == 0) &&
           ((cVar4 = UNK_00d579, cVar4 != '\x06' || (uVar1 = Ram00fd56, (uVar1 & 0x20) != 0)))) {
          uVar1 = Ram00fd48;
          Ram00fd48 = uVar1 | 4;
        }
        uVar1 = Ram00fd5a;
        if ((uVar1 & 0x20) == 0) {
          cVar4 = UNK_00d775;
          if ((cVar4 == '\x01') || (cVar4 == '\x05')) {
            iVar6 = Ram00f648;
            uVar1 = iVar6 + 10;
            uVar2 = 0x24;
            if (((uVar1 & 0xc000) != 0) &&
               ((uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000 &&
                (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)))) {
              uVar2 = 3;
            }
            iVar6 = Ram00d4ec;
            if (*(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) < iVar6) {
              UNK_00d437 = 3;
            }
            else {
              UNK_00d437 = 1;
            }
          }
          else {
            iVar6 = Ram00d4e6;
            iVar3 = Ram00d4ec;
            iVar6 = iVar6 - iVar3;
            if (iVar6 < 0) {
              iVar6 = -iVar6;
            }
            iVar3 = Ram00f648;
            uVar1 = iVar3 + 10;
            uVar2 = 0x24;
            if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
               (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
              uVar2 = 3;
            }
            if (*(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) < iVar6) {
              UNK_00d437 = 3;
            }
            else {
              UNK_00d437 = 1;
            }
          }
        }
        else {
          UNK_00d437 = 4;
        }
      }
    }
    else {
      cVar4 = UNK_00d775;
      if ((cVar4 == '\x01') && (uVar1 = Ram00fd56, (uVar1 & 0x20) != 0)) {
        UNK_00d437 = 3;
      }
      else {
        cVar4 = UNK_00d775;
        if ((cVar4 == '\x01') || (cVar4 == '\x05')) {
          iVar6 = Ram00f648;
          uVar1 = iVar6 + 10;
          uVar2 = 0x24;
          if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
             (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
            uVar2 = 3;
          }
          iVar6 = Ram00d4ec;
          if (*(int *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) < iVar6) {
            UNK_00d437 = 3;
            return;
          }
        }
        UNK_00d437 = 1;
      }
    }
  }
  else {
    UNK_00d437 = 5;
  }
  return;
}


