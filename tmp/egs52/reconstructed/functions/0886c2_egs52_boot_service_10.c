/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0886c2; FLS offset 0x0086c2.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x088866) */
/* WARNING: Removing unreachable block (ram,0x08888e) */
/* WARNING: Removing unreachable block (ram,0x088886) */
/* WARNING: Removing unreachable block (ram,0x0888a0) */
/* WARNING: Removing unreachable block (ram,0x088898) */
/* WARNING: Removing unreachable block (ram,0x08887a) */
/* WARNING: Removing unreachable block (ram,0x08885a) */
/* WARNING: Removing unreachable block (ram,0x088856) */
/* WARNING: Removing unreachable block (ram,0x088852) */
/* WARNING: Removing unreachable block (ram,0x08884e) */
/* WARNING: Removing unreachable block (ram,0x08884a) */
/* WARNING: Removing unreachable block (ram,0x0888b4) */
/* WARNING: Removing unreachable block (ram,0x088840) */
/* WARNING: Removing unreachable block (ram,0x0888be) */
/* WARNING: Removing unreachable block (ram,0x088828) */
/* WARNING: Removing unreachable block (ram,0x088820) */
/* WARNING: Removing unreachable block (ram,0x0887f2) */
/* WARNING: Removing unreachable block (ram,0x0887ea) */
/* WARNING: Removing unreachable block (ram,0x0887e2) */
/* WARNING: Removing unreachable block (ram,0x088802) */
/* WARNING: Removing unreachable block (ram,0x0887d8) */
/* WARNING: Removing unreachable block (ram,0x0887d4) */
/* WARNING: Removing unreachable block (ram,0x0887ce) */
/* WARNING: Removing unreachable block (ram,0x0887c6) */
/* WARNING: Removing unreachable block (ram,0x0887b2) */
/* WARNING: Removing unreachable block (ram,0x08879c) */
/* WARNING: Removing unreachable block (ram,0x088798) */
/* WARNING: Removing unreachable block (ram,0x088792) */
/* WARNING: Removing unreachable block (ram,0x08878a) */
/* WARNING: Removing unreachable block (ram,0x088788) */
/* WARNING: Removing unreachable block (ram,0x088778) */
/* WARNING: Removing unreachable block (ram,0x088774) */
/* WARNING: Removing unreachable block (ram,0x088770) */
/* WARNING: Removing unreachable block (ram,0x088814) */
/* WARNING: Removing unreachable block (ram,0x088764) */
/* WARNING: Removing unreachable block (ram,0x08875e) */
/* WARNING: Removing unreachable block (ram,0x088752) */
/* WARNING: Removing unreachable block (ram,0x08874e) */
/* WARNING: Removing unreachable block (ram,0x088748) */
/* WARNING: Removing unreachable block (ram,0x08873c) */
/* WARNING: Removing unreachable block (ram,0x088738) */
/* WARNING: Removing unreachable block (ram,0x088730) */
/* WARNING: Removing unreachable block (ram,0x08871e) */
/* WARNING: Removing unreachable block (ram,0x08870e) */
/* WARNING: Removing unreachable block (ram,0x0886f8) */
/* WARNING: Removing unreachable block (ram,0x0886f4) */
/* WARNING: Removing unreachable block (ram,0x0886ee) */
/* WARNING: Removing unreachable block (ram,0x0886e2) */
/* WARNING: Removing unreachable block (ram,0x088706) */
/* WARNING: Removing unreachable block (ram,0x088702) */
/* WARNING: Removing unreachable block (ram,0x0886d6) */
/* WARNING: Removing unreachable block (ram,0x0886de) */
/* WARNING: Removing unreachable block (ram,0x088784) */
/* WARNING: Removing unreachable block (ram,0x08883a) */
/* WARNING: Removing unreachable block (ram,0x088844) */
/* WARNING: Removing unreachable block (ram,0x088876) */
/* WARNING: Removing unreachable block (ram,0x08886a) */
/* WARNING: Removing unreachable block (ram,0x088768) */
/* WARNING: Heritage AFTER dead removal. Example location: r0x00f462 : 0x0886de */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void egs52_boot_service_10(void)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  
  uVar1 = Ram00fde8;
  if ((uVar1 & 1) == 0) {
    if (cRam00f469 == '\x02') {
      bVar3 = 0;
      do {
        uVar1 = 0x24;
        if ((((uRam00f462 & 0xc000) != 0) && (uVar1 = 0x21, (uRam00f462 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uRam00f462 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        if (*(char *)((uint3)(bVar3 + 3) | 0x88000) ==
            *(char *)((uint3)uVar1 << 0xe | (uint3)(uRam00f462 & 0x3fff))) {
          cRam00f580 = bVar3 + 1;
          uRam00f581 = 0;
          uRam00f57c = 0;
          uRam00f578 = 0;
          uVar1 = 0x24;
          if ((((uRam00f462 & 0xc000) != 0) && (uVar1 = 0x21, (uRam00f462 & 0xc000) != 0x4000)) &&
             (uVar1 = 0x2c, (uRam00f462 & 0xc000) != 0x8000)) {
            uVar1 = 3;
          }
          if (*(char *)((uint3)uVar1 << 0xe | (uint3)(uRam00f462 & 0x3fff)) == -0x7f) {
            uRam00f576 = 0xfffd;
            uRam00f574 = 0;
            egs52_update_near_f57f_088f1e();
            uVar1 = Ram00fdec;
            Ram00fdec = uVar1 & 0xf7ff;
          }
          else {
            uVar1 = 0x24;
            if ((((uRam00f462 & 0xc000) != 0) && (uVar1 = 0x21, (uRam00f462 & 0xc000) != 0x4000)) &&
               (uVar1 = 0x2c, (uRam00f462 & 0xc000) != 0x8000)) {
              uVar1 = 3;
            }
            if (*(char *)((uint3)uVar1 << 0xe | (uint3)(uRam00f462 & 0x3fff)) == -0x7b) {
              uRam00f576 = 16000;
              uRam00f574 = 0x641;
            }
            else {
              uRam00f576 = 5000;
              uRam00f574 = 0x1f5;
            }
          }
          uVar1 = Ram00fdec;
          Ram00fdec = uVar1 & 0xfff7;
          uVar1 = Ram00fdec;
          Ram00fdec = uVar1 & 0xffef;
          return;
        }
        bVar3 = bVar3 + 1;
      } while (bVar3 < 3);
      uRam00f581 = 0x22;
    }
    else {
      uRam00f581 = 0x79;
    }
  }
  else {
    uVar1 = Ram00fdea;
    if (((uVar1 & 4) == 0) || (uVar1 = Ram00fdea, (uVar1 & 8) != 0)) {
      if ((cRam00f469 == '\x02') || (cRam00f469 == '\x03')) {
        uVar1 = Ram00fdec;
        if (((uVar1 & 0x20) != 0) && (cRam00f469 == '\x03')) {
          uVar1 = uRam00f462 + 1;
          uVar2 = 0x24;
          if (((uVar1 & 0xc000) != 0) &&
             ((uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000 &&
              (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)))) {
            uVar2 = 3;
          }
          uRam00f57a = *(undefined2 *)
                        ((uint3)((uint)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) * 2
                                + 0x18) | 0x88000);
          Ram00feb4 = uRam00f57a;
        }
        bVar3 = 0;
        do {
          uVar1 = 0x24;
          if ((((uRam00f462 & 0xc000) != 0) && (uVar1 = 0x21, (uRam00f462 & 0xc000) != 0x4000)) &&
             (uVar1 = 0x2c, (uRam00f462 & 0xc000) != 0x8000)) {
            uVar1 = 3;
          }
          if (*(char *)((uint3)bVar3 | 0x88000) ==
              *(char *)((uint3)uVar1 << 0xe | (uint3)(uRam00f462 & 0x3fff))) {
            cRam00f580 = bVar3 + 1;
            uRam00f581 = 0;
            uVar1 = 0x24;
            if ((((uRam00f462 & 0xc000) != 0) && (uVar1 = 0x21, (uRam00f462 & 0xc000) != 0x4000)) &&
               (uVar1 = 0x2c, (uRam00f462 & 0xc000) != 0x8000)) {
              uVar1 = 3;
            }
            if (*(char *)((uint3)uVar1 << 0xe | (uint3)(uRam00f462 & 0x3fff)) == -0x7e) {
              uVar1 = 0x24;
              if ((((uRam00f464 & 0xc000) != 0) && (uVar1 = 0x21, (uRam00f464 & 0xc000) != 0x4000))
                 && (uVar1 = 0x2c, (uRam00f464 & 0xc000) != 0x8000)) {
                uVar1 = 3;
              }
              *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uRam00f464 & 0x3fff)) = 0x82;
              if (cRam00f469 == '\x03') {
                uVar2 = uRam00f462 + 1;
                uVar1 = 0x24;
                if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
                   (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
                  uVar1 = 3;
                }
                if (*(char *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) != '\0') {
                  uVar1 = 0x24;
                  if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
                     (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
                    uVar1 = 3;
                  }
                  if (*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) < 6) {
                    uVar1 = Ram00fdec;
                    Ram00fdec = uVar1 & 0xfeff;
                    uVar1 = Ram00fdea;
                    Ram00fdea = uVar1 | 4;
                    uVar1 = Ram00fdea;
                    Ram00fdea = uVar1 | 8;
                    uVar1 = Ram00fdec;
                    Ram00fdec = uVar1 | 0x20;
                    return;
                  }
                }
                uRam00f581 = 0x31;
                return;
              }
              uVar1 = Ram00fdec;
              Ram00fdec = uVar1 & 0xfeff;
              uVar1 = Ram00fdea;
              Ram00fdea = uVar1 | 4;
              uVar1 = Ram00fdea;
              Ram00fdea = uVar1 | 8;
              uVar1 = Ram00fdec;
              Ram00fdec = uVar1 | 0x20;
              return;
            }
            if (cRam00f469 == '\x02') {
LAB_0887de:
              uVar1 = Ram00fdea;
              Ram00fdea = uVar1 | 4;
              uVar1 = Ram00fdea;
              Ram00fdea = uVar1 & 0xfff7;
              uRam00f574 = 0x1f5;
              uRam00f581 = 0;
              uRam00f576 = 5000;
              uRam00f578 = 0x37;
              return;
            }
            uVar2 = uRam00f462 + 1;
            uVar1 = 0x24;
            if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
               (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
              uVar1 = 3;
            }
            if (*(char *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) != '\0') {
              uVar1 = 0x24;
              if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
                 (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
                uVar1 = 3;
              }
              if (*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) < 6) goto LAB_0887de;
            }
            uRam00f581 = 0x31;
            return;
          }
          bVar3 = bVar3 + 1;
        } while (bVar3 < 3);
        uRam00f581 = 0x22;
      }
      else {
        uRam00f581 = 0x79;
      }
    }
    else {
      if (cRam00f469 == '\x03') {
        uVar1 = uRam00f462 + 1;
        uVar2 = 0x24;
        if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        uRam00f57a = *(undefined2 *)
                      ((uint3)((uint)*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) * 2 +
                              0x18) | 0x88000);
        Ram00feb4 = uRam00f57a;
      }
      else {
        uRam00f57a = 0x47;
        Ram00feb4 = 0x47;
      }
      uRam00f57c = 0x19;
      uVar1 = Ram00fdec;
      Ram00fdec = uVar1 & 0xfff7;
      uVar1 = Ram00fdec;
      Ram00fdec = uVar1 & 0xffef;
      uVar1 = Ram00fdea;
      Ram00fdea = uVar1 & 0xfffb;
      uVar1 = Ram00fdea;
      Ram00fdea = uVar1 & 0xfff7;
    }
  }
  return;
}


