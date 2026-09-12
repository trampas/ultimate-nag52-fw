/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0e46f4; FLS offset 0x0646f4.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0e493c) */
/* WARNING: Removing unreachable block (ram,0x0e4936) */
/* WARNING: Removing unreachable block (ram,0x0e492e) */
/* WARNING: Removing unreachable block (ram,0x0e490e) */
/* WARNING: Removing unreachable block (ram,0x0e4902) */
/* WARNING: Removing unreachable block (ram,0x0e48f4) */
/* WARNING: Removing unreachable block (ram,0x0e48e6) */
/* WARNING: Removing unreachable block (ram,0x0e48de) */
/* WARNING: Removing unreachable block (ram,0x0e48da) */
/* WARNING: Removing unreachable block (ram,0x0e48c8) */
/* WARNING: Removing unreachable block (ram,0x0e48c4) */
/* WARNING: Removing unreachable block (ram,0x0e48c0) */
/* WARNING: Removing unreachable block (ram,0x0e48ba) */
/* WARNING: Removing unreachable block (ram,0x0e48b6) */
/* WARNING: Removing unreachable block (ram,0x0e48b0) */
/* WARNING: Removing unreachable block (ram,0x0e48a8) */
/* WARNING: Removing unreachable block (ram,0x0e48a4) */
/* WARNING: Removing unreachable block (ram,0x0e4894) */
/* WARNING: Removing unreachable block (ram,0x0e4780) */
/* WARNING: Removing unreachable block (ram,0x0e477c) */
/* WARNING: Removing unreachable block (ram,0x0e478a) */
/* WARNING: Removing unreachable block (ram,0x0e4774) */
/* WARNING: Removing unreachable block (ram,0x0e476a) */
/* WARNING: Removing unreachable block (ram,0x0e4762) */
/* WARNING: Removing unreachable block (ram,0x0e4770) */
/* WARNING: Removing unreachable block (ram,0x0e4746) */
/* WARNING: Removing unreachable block (ram,0x0e4742) */
/* WARNING: Removing unreachable block (ram,0x0e47be) */
/* WARNING: Removing unreachable block (ram,0x0e47c8) */
/* WARNING: Removing unreachable block (ram,0x0e47b4) */
/* WARNING: Removing unreachable block (ram,0x0e4852) */
/* WARNING: Removing unreachable block (ram,0x0e4874) */
/* WARNING: Removing unreachable block (ram,0x0e486c) */
/* WARNING: Removing unreachable block (ram,0x0e4866) */
/* WARNING: Removing unreachable block (ram,0x0e4864) */
/* WARNING: Removing unreachable block (ram,0x0e485c) */
/* WARNING: Removing unreachable block (ram,0x0e4858) */
/* WARNING: Removing unreachable block (ram,0x0e484c) */
/* WARNING: Removing unreachable block (ram,0x0e484a) */
/* WARNING: Removing unreachable block (ram,0x0e4842) */
/* WARNING: Removing unreachable block (ram,0x0e483e) */
/* WARNING: Removing unreachable block (ram,0x0e4834) */
/* WARNING: Removing unreachable block (ram,0x0e4830) */
/* WARNING: Removing unreachable block (ram,0x0e482a) */
/* WARNING: Removing unreachable block (ram,0x0e4822) */
/* WARNING: Removing unreachable block (ram,0x0e481e) */
/* WARNING: Removing unreachable block (ram,0x0e4818) */
/* WARNING: Removing unreachable block (ram,0x0e4810) */
/* WARNING: Removing unreachable block (ram,0x0e480c) */
/* WARNING: Removing unreachable block (ram,0x0e4806) */
/* WARNING: Removing unreachable block (ram,0x0e47fe) */
/* WARNING: Removing unreachable block (ram,0x0e47fa) */
/* WARNING: Removing unreachable block (ram,0x0e47f4) */
/* WARNING: Removing unreachable block (ram,0x0e47f0) */
/* WARNING: Removing unreachable block (ram,0x0e47ec) */
/* WARNING: Removing unreachable block (ram,0x0e47e4) */
/* WARNING: Removing unreachable block (ram,0x0e47d8) */
/* WARNING: Removing unreachable block (ram,0x0e4886) */
/* WARNING: Removing unreachable block (ram,0x0e487e) */
/* WARNING: Removing unreachable block (ram,0x0e479c) */
/* WARNING: Removing unreachable block (ram,0x0e4792) */
/* WARNING: Removing unreachable block (ram,0x0e473c) */
/* WARNING: Removing unreachable block (ram,0x0e4734) */
/* WARNING: Removing unreachable block (ram,0x0e472a) */
/* WARNING: Removing unreachable block (ram,0x0e470e) */
/* WARNING: Removing unreachable block (ram,0x0e4706) */
/* WARNING: Removing unreachable block (ram,0x0e4700) */
/* WARNING: Removing unreachable block (ram,0x0e46f8) */
/* WARNING: Removing unreachable block (ram,0x0e4716) */
/* WARNING: Removing unreachable block (ram,0x0e488e) */
/* WARNING: Removing unreachable block (ram,0x0e489e) */

void egs52_update_near_d60e_0e46f4(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined2 uVar4;
  char cVar5;
  byte bVar6;
  int iVar7;
  undefined1 uVar8;
  char cVar9;
  uint uVar10;
  byte bVar11;
  byte bVar12;
  
  iVar7 = Ram00f61e;
  uVar2 = iVar7 + 0x1c;
  uVar1 = 0x24;
  if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  if ((*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) & 4) == 0) {
    iVar7 = Ram00f61e;
    uVar3 = iVar7 + 0x1a;
    uVar1 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    if ((*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) & 0x10) == 0) {
      uVar1 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      if ((*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) & 1) == 0) {
        uVar1 = 0x24;
        if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        if ((*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) & 2) != 0) {
          uVar1 = Ram00d3be;
          if ((uVar1 & 2) == 0) {
            UNK_00d60e = 0;
          }
          else {
            UNK_00d60e = 1;
          }
        }
      }
      else {
        iVar7 = Ram00f61e;
        uVar2 = iVar7 + 0x1d;
        uVar1 = 0x24;
        if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        if ((*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) & 0x40) == 0) {
          uVar1 = Ram00fd16;
          bVar12 = (byte)(uVar1 >> 6) & 1;
          uVar1 = Ram00fd16;
          bVar11 = (byte)(uVar1 >> 7) & 1;
          if ((bVar12 != 1) || (bVar11 != 1)) {
            if (bVar11 == 1) {
              cVar5 = UNK_00d60d;
              if (cVar5 == '\x03') {
                UNK_00d60e = 3;
              }
              else {
                UNK_00d60e = 1;
              }
            }
            else if (bVar12 == 1) {
              uVar1 = Ram00fd5a;
              Ram00fd5a = uVar1 | 1;
              uVar1 = Ram00fd58;
              if (((uVar1 & 0x40) == 0) && (uVar1 = Ram00fd54, (uVar1 & 1) == 0)) {
                cVar5 = UNK_00d60e;
                UNK_00d60e = cVar5 + '\x01';
                bVar6 = UNK_00d60e;
                bVar11 = UNK_00d60d;
                bVar12 = UNK_00d60d;
                if (bVar6 != bVar12 && bVar11 <= bVar6) {
                  UNK_00d60e = 0;
                }
                cVar5 = UNK_00d60e;
                if (cVar5 == '\x01') {
                  uVar1 = 0x24;
                  if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
                     (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
                    uVar1 = 3;
                  }
                  if ((*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) & 4) == 0) {
                    cVar5 = UNK_00d60e;
                    UNK_00d60e = cVar5 + '\x01';
                  }
                }
                cVar5 = UNK_00d60e;
                if (cVar5 == '\x02') {
                  uVar1 = 0x24;
                  if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
                     (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
                    uVar1 = 3;
                  }
                  if ((*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) & 0x10) == 0) {
                    cVar5 = UNK_00d60e;
                    UNK_00d60e = cVar5 + '\x01';
                  }
                }
                cVar5 = UNK_00d60e;
                if (cVar5 == '\x03') {
                  uVar1 = 0x24;
                  if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
                     (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
                    uVar1 = 3;
                  }
                  if ((*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) & 8) == 0) {
                    UNK_00d60e = 0;
                  }
                }
                bVar11 = UNK_00d446;
                Ram00d5c8 = (uint)bVar11 * 500;
                iVar7 = Ram00f66c;
                uVar2 = iVar7 + 0x14;
                uVar1 = 0x24;
                if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
                   (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
                  uVar1 = 3;
                }
                uVar3 = Ram00d5c8;
                if (*(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) < uVar3) {
                  uVar1 = 0x24;
                  if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
                     (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
                    uVar1 = 3;
                  }
                  Ram00d5c8 = *(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
                }
                else {
                  cVar5 = UNK_00d446;
                  UNK_00d446 = cVar5 + '\x01';
                  iVar7 = Ram00f66c;
                  uVar2 = iVar7 + 0x22;
                  uVar1 = 0x24;
                  if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
                     (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
                    uVar1 = 3;
                  }
                  uVar1 = *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
                  uVar3 = Ram00d5c8;
                  uVar10 = Ram00d5c8;
                  if ((uVar1 != uVar10 && uVar3 <= uVar1) && (bVar11 = UNK_00d60d, 1 < bVar11)) {
                    uVar1 = 0x24;
                    if (((uVar2 & 0xc000) != 0) &&
                       ((uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000 &&
                        (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)))) {
                      uVar1 = 3;
                    }
                    Ram00d5c8 = *(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
                  }
                }
                uVar1 = Ram00fd5a;
                Ram00fd5a = uVar1 & 0xff7f;
                uVar1 = Ram00fd58;
                Ram00fd58 = uVar1 | 0x40;
              }
            }
            else {
              uVar1 = Ram00fd5a;
              if ((uVar1 & 1) == 0) {
                UNK_00d60e = 0;
              }
              uVar1 = Ram00fd58;
              Ram00fd58 = uVar1 & 0xffbf;
            }
          }
        }
        else {
          cVar5 = UNK_00d3c0;
          cVar9 = UNK_00d577;
          if ((cVar9 == '\0') || (cVar9 == '\x05')) {
            if (cVar5 == '\0') {
              UNK_00d60e = 0;
            }
            else if (cVar5 == '\x01') {
              UNK_00d60e = 1;
            }
            else if (cVar5 == '\x02') {
              UNK_00d60e = 3;
            }
            cVar5 = UNK_00d60e;
            if (cVar5 == '\x03') {
              uVar8 = UNK_00d3c1;
              UNK_00d7aa = uVar8;
            }
            else {
              UNK_00d7aa = 1;
            }
          }
        }
      }
      uVar1 = Ram00fd5a;
      if (((uVar1 & 1) != 0) && (iVar7 = Ram00d5c8, iVar7 == 0)) {
        cVar9 = UNK_00d60e;
        cVar5 = UNK_00d38c;
        if (cVar9 != cVar5) {
          iVar7 = Ram00f66c;
          uVar1 = iVar7 + 0x16;
          uVar2 = 0x24;
          if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
             (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
            uVar2 = 3;
          }
          uVar1 = *(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff));
          uVar2 = Ram00d60a;
          uVar3 = Ram00d60a;
          if ((uVar1 != uVar3 && uVar2 <= uVar1) &&
             (((cVar9 == '\0' || (cVar9 == '\x01')) || (cVar9 == '\x02')))) {
            uVar8 = UNK_00d60e;
            UNK_00d38c = uVar8;
            uVar1 = Ram00fd5a;
            Ram00fd5a = uVar1 | 0x80;
          }
        }
      }
      uVar1 = Ram00fd56;
      Ram00fd56 = uVar1 & 0xefff;
      cVar5 = UNK_00d60e;
      if (cVar5 == '\x01') {
        uVar1 = Ram00fd56;
        Ram00fd56 = uVar1 | 0x80;
      }
      else {
        uVar1 = Ram00fd56;
        Ram00fd56 = uVar1 & 0xff7f;
        cVar5 = UNK_00d60e;
        if (cVar5 == '\x03') {
          uVar1 = Ram00fd56;
          Ram00fd56 = uVar1 | 0x1000;
        }
      }
      uVar1 = Ram00fd56;
      uVar2 = Ram00fd56;
      Ram00fd56 = uVar2 & 0xfffe | (uVar1 & 0x80) >> 7;
      uVar1 = Ram00fd5a;
      if ((uVar1 & 0x10) != 0) {
        uVar1 = Ram00fd56;
        Ram00fd56 = uVar1 & 0xfffe;
        uVar1 = Ram00fd56;
        Ram00fd56 = uVar1 & 0xefff;
      }
      cVar5 = UNK_00d613;
      if (cVar5 != '\a') {
        uVar1 = Ram00fd56;
        if (((uVar1 & 2) == 0) && (uVar1 = Ram00fd44, (uVar1 & 8) == 0)) {
          uVar4 = Ram00fd56;
          uVar1 = Ram00fd56;
          uVar2 = Ram00fd56;
          Ram00fd56 = uVar2 & 0xfffb | (uVar1 & 1) << 2;
          return;
        }
        bVar11 = UNK_00d613;
        if ((5 < bVar11) || (cVar5 = UNK_00d577, cVar5 != '\0')) {
          cVar5 = UNK_00d613;
          if ((cVar5 != '\x06') && (cVar5 != '\b')) {
            return;
          }
          uVar4 = Ram00fd56;
          uVar1 = Ram00fd56;
          if ((bool)((byte)uVar4 & 1 ^ (byte)((uVar1 & 4) >> 2))) {
            return;
          }
        }
        uVar1 = Ram00fd56;
        Ram00fd56 = uVar1 & 0xfffd;
        return;
      }
      uVar4 = Ram00fd56;
      uVar1 = Ram00fd56;
      if (!(bool)((byte)uVar4 & 1 ^ (byte)((uVar1 & 4) >> 2))) {
        return;
      }
      uVar1 = Ram00fd56;
      Ram00fd56 = uVar1 | 2;
      return;
    }
  }
  UNK_00d60e = 4;
  uVar4 = Ram00fd56;
  uVar1 = Ram00fd54;
  uVar2 = Ram00fd56;
  Ram00fd56 = uVar2 & 0xff7f | ((uVar1 & 0x40) >> 6) << 7;
  uVar4 = Ram00fd56;
  uVar1 = Ram00fd54;
  uVar2 = Ram00fd56;
  Ram00fd56 = uVar2 & 0xfffe | (uVar1 & 0x40) >> 6;
  uVar4 = Ram00fd56;
  uVar1 = Ram00fd54;
  uVar2 = Ram00fd56;
  Ram00fd56 = uVar2 & 0xfffb | ((uVar1 & 0x40) >> 6) << 2;
  return;
}


