/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x082b50; FLS offset 0x002b50.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Function: egs52_boot_call_far_indirect replaced with injection: call_far_indirect */
/* WARNING: Removing unreachable block (ram,0x082bfa) */
/* WARNING: Removing unreachable block (ram,0x082be6) */
/* WARNING: Removing unreachable block (ram,0x082be2) */
/* WARNING: Removing unreachable block (ram,0x082bdc) */
/* WARNING: Removing unreachable block (ram,0x082bd8) */
/* WARNING: Removing unreachable block (ram,0x082c42) */
/* WARNING: Removing unreachable block (ram,0x082c2e) */
/* WARNING: Removing unreachable block (ram,0x082c2a) */
/* WARNING: Removing unreachable block (ram,0x082c24) */
/* WARNING: Removing unreachable block (ram,0x082c20) */
/* WARNING: Removing unreachable block (ram,0x082c1c) */
/* WARNING: Removing unreachable block (ram,0x082c18) */
/* WARNING: Removing unreachable block (ram,0x082c84) */
/* WARNING: Removing unreachable block (ram,0x082c70) */
/* WARNING: Removing unreachable block (ram,0x082c68) */
/* WARNING: Removing unreachable block (ram,0x082c60) */
/* WARNING: Removing unreachable block (ram,0x082c58) */
/* WARNING: Removing unreachable block (ram,0x082c54) */
/* WARNING: Removing unreachable block (ram,0x082c50) */
/* WARNING: Removing unreachable block (ram,0x082c4c) */
/* WARNING: Removing unreachable block (ram,0x082c0c) */
/* WARNING: Removing unreachable block (ram,0x082c90) */
/* WARNING: Removing unreachable block (ram,0x082bce) */
/* WARNING: Removing unreachable block (ram,0x082bca) */
/* WARNING: Removing unreachable block (ram,0x082bc6) */
/* WARNING: Removing unreachable block (ram,0x082d14) */
/* WARNING: Removing unreachable block (ram,0x082d10) */
/* WARNING: Removing unreachable block (ram,0x082d0a) */
/* WARNING: Removing unreachable block (ram,0x082d06) */
/* WARNING: Removing unreachable block (ram,0x082d00) */
/* WARNING: Removing unreachable block (ram,0x082cfa) */
/* WARNING: Removing unreachable block (ram,0x082cf4) */
/* WARNING: Removing unreachable block (ram,0x082cee) */
/* WARNING: Removing unreachable block (ram,0x082ce8) */
/* WARNING: Removing unreachable block (ram,0x082ce2) */
/* WARNING: Removing unreachable block (ram,0x082cdc) */
/* WARNING: Removing unreachable block (ram,0x082cd8) */
/* WARNING: Removing unreachable block (ram,0x082cd2) */
/* WARNING: Removing unreachable block (ram,0x082ccc) */
/* WARNING: Removing unreachable block (ram,0x082cc6) */
/* WARNING: Removing unreachable block (ram,0x082cc0) */
/* WARNING: Removing unreachable block (ram,0x082cba) */
/* WARNING: Removing unreachable block (ram,0x082cb2) */
/* WARNING: Removing unreachable block (ram,0x082d28) */
/* WARNING: Removing unreachable block (ram,0x082ca4) */
/* WARNING: Removing unreachable block (ram,0x082c9c) */
/* WARNING: Removing unreachable block (ram,0x082c98) */
/* WARNING: Removing unreachable block (ram,0x082d46) */
/* WARNING: Removing unreachable block (ram,0x082d40) */
/* WARNING: Removing unreachable block (ram,0x082d3c) */
/* WARNING: Removing unreachable block (ram,0x082d38) */
/* WARNING: Removing unreachable block (ram,0x082d52) */
/* WARNING: Removing unreachable block (ram,0x082ba2) */
/* WARNING: Removing unreachable block (ram,0x082b96) */
/* WARNING: Removing unreachable block (ram,0x082ef8) */
/* WARNING: Removing unreachable block (ram,0x082e4c) */
/* WARNING: Removing unreachable block (ram,0x082e46) */
/* WARNING: Removing unreachable block (ram,0x082e42) */
/* WARNING: Removing unreachable block (ram,0x082e3c) */
/* WARNING: Removing unreachable block (ram,0x082e38) */
/* WARNING: Removing unreachable block (ram,0x082e58) */
/* WARNING: Removing unreachable block (ram,0x082e26) */
/* WARNING: Removing unreachable block (ram,0x082e1c) */
/* WARNING: Removing unreachable block (ram,0x082eee) */
/* WARNING: Removing unreachable block (ram,0x082ee4) */
/* WARNING: Removing unreachable block (ram,0x082ed0) */
/* WARNING: Removing unreachable block (ram,0x082ec8) */
/* WARNING: Removing unreachable block (ram,0x082ec4) */
/* WARNING: Removing unreachable block (ram,0x082eb4) */
/* WARNING: Removing unreachable block (ram,0x082ea6) */
/* WARNING: Removing unreachable block (ram,0x082e9c) */
/* WARNING: Removing unreachable block (ram,0x082e68) */
/* WARNING: Removing unreachable block (ram,0x082e60) */
/* WARNING: Removing unreachable block (ram,0x082dd2) */
/* WARNING: Removing unreachable block (ram,0x082da6) */
/* WARNING: Removing unreachable block (ram,0x082e08) */
/* WARNING: Removing unreachable block (ram,0x082e02) */
/* WARNING: Removing unreachable block (ram,0x082dfe) */
/* WARNING: Removing unreachable block (ram,0x082dfa) */
/* WARNING: Removing unreachable block (ram,0x082dee) */
/* WARNING: Removing unreachable block (ram,0x082e14) */
/* WARNING: Removing unreachable block (ram,0x082d8c) */
/* WARNING: Removing unreachable block (ram,0x082d80) */
/* WARNING: Removing unreachable block (ram,0x082d68) */
/* WARNING: Removing unreachable block (ram,0x082d64) */
/* WARNING: Removing unreachable block (ram,0x082d5a) */
/* WARNING: Removing unreachable block (ram,0x082b8c) */
/* WARNING: Removing unreachable block (ram,0x082b84) */
/* WARNING: Removing unreachable block (ram,0x082b80) */
/* WARNING: Removing unreachable block (ram,0x082b78) */
/* WARNING: Removing unreachable block (ram,0x082b72) */
/* WARNING: Removing unreachable block (ram,0x082b6e) */
/* WARNING: Removing unreachable block (ram,0x082b6a) */
/* WARNING: Removing unreachable block (ram,0x082b54) */
/* WARNING: Removing unreachable block (ram,0x082de2) */
/* WARNING: Removing unreachable block (ram,0x082eda) */
/* WARNING: Removing unreachable block (ram,0x082c5c) */
/* WARNING: Removing unreachable block (ram,0x082c64) */
/* WARNING: Removing unreachable block (ram,0x082c6c) */
/* WARNING: Removing unreachable block (ram,0x082f02) */
/* WARNING: Heritage AFTER dead removal. Example location: r0x00f3f8 : 0x082da6 */
/* WARNING: Removing unreachable block (ram,0x082eba) */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void egs52_boot_service_31(void)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  undefined2 uVar4;
  undefined1 uStack_4;
  undefined1 uStack_3;
  
  if ((cRam00f407 == '\0') ||
     ((uVar3 = Ram00fdea, (uVar3 & 4) != 0 && (uVar3 = Ram00fdea, (uVar3 & 8) != 0)))) {
    uRam00f581 = 0;
    uVar3 = 0x24;
    if (((uRam00f462 & 0xc000) != 0) &&
       ((uVar3 = 0x21, (uRam00f462 & 0xc000) != 0x4000 &&
        (uVar3 = 0x2c, (uRam00f462 & 0xc000) != 0x8000)))) {
      uVar3 = 3;
    }
    if ((1 < *(byte *)((uint3)uVar3 << 0xe | (uint3)(uRam00f462 & 0x3fff))) || (bRam00f469 != 2)) {
      uVar3 = 0x24;
      if (((uRam00f462 & 0xc000) != 0) &&
         ((uVar3 = 0x21, (uRam00f462 & 0xc000) != 0x4000 &&
          (uVar3 = 0x2c, (uRam00f462 & 0xc000) != 0x8000)))) {
        uVar3 = 3;
      }
      if ((*(char *)((uint3)uVar3 << 0xe | (uint3)(uRam00f462 & 0x3fff)) != '\x06') ||
         (bRam00f469 != 5)) {
        if (bRam00f469 != 2) {
          uRam00f581 = 0x22;
          return;
        }
        uVar3 = 0x24;
        if ((((uRam00f462 & 0xc000) != 0) && (uVar3 = 0x21, (uRam00f462 & 0xc000) != 0x4000)) &&
           (uVar3 = 0x2c, (uRam00f462 & 0xc000) != 0x8000)) {
          uVar3 = 3;
        }
        cVar2 = *(char *)((uint3)uVar3 << 0xe | (uint3)(uRam00f462 & 0x3fff));
        if (cVar2 == '\x02') {
          if (((bRam00f57f & 0xe) == 0) || (cRam00f580 != '\x02')) {
            uRam00f581 = 0x33;
            return;
          }
          uVar3 = Ram00fdea;
          if ((((uVar3 & 4) == 0) || (uVar3 = Ram00fdea, (uVar3 & 8) == 0)) &&
             ((uVar3 = Ram00fdea, (uVar3 & 4) == 0 || (uVar3 = Ram00fdea, (uVar3 & 8) != 0)))) {
            uVar3 = Ram00fdea;
            Ram00fdea = uVar3 | 4;
            uVar3 = Ram00fdea;
            Ram00fdea = uVar3 & 0xfff7;
            uRam00f3f8 = uRam00f3f8 | 0x84;
            iRam00f464 = iRam00f464 + 2;
            uRam00f581 = 0x78;
            return;
          }
          if ((uRam00f3f8 & 0x108) != 0x108) {
            uRam00f581 = 0;
            return;
          }
          uVar3 = Ram00fdea;
          if (((uVar3 & 4) != 0) && (uVar3 = Ram00fdea, (uVar3 & 8) != 0)) {
            uVar3 = Ram00fdea;
            Ram00fdea = uVar3 & 0xfffb;
            uVar3 = Ram00fdea;
            Ram00fdea = uVar3 & 0xfff7;
            uVar3 = egs52_update_near_f3fe_081584();
            if ((uVar3 & 0x80) != 0) {
              return;
            }
            uRam00f581 = 0x22;
            return;
          }
          uVar3 = Ram00fdea;
          Ram00fdea = uVar3 | 4;
          uVar3 = Ram00fdea;
          Ram00fdea = uVar3 | 8;
          uRam00f581 = 0x78;
          return;
        }
        if (cVar2 == '\x03') {
          if (((bRam00f57f & 0xe) != 0) && (cRam00f580 == '\x02')) {
            uVar4 = egs52_update_near_f3fe_081584();
            uStack_3 = (undefined1)((uint)uVar4 >> 8);
            uVar3 = uRam00f462 + 1;
            uVar1 = 0x24;
            if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
               (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
              uVar1 = 3;
            }
            *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) = uStack_3;
            uStack_4 = (undefined1)uVar4;
            uVar3 = uRam00f462 + 2;
            uVar1 = 0x24;
            if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
               (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
              uVar1 = 3;
            }
            *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) = uStack_4;
            bRam00f469 = 4;
            return;
          }
          uRam00f581 = 0x33;
          return;
        }
        if (cVar2 != -6) {
          uRam00f581 = 0x12;
          return;
        }
        if (((bRam00f57f & 2) == 0) || ((cRam00f580 != '\x01' && (cRam00f580 != '\x04')))) {
          uRam00f581 = 0x33;
          return;
        }
        uVar3 = Ram00fdee;
        if (((uVar3 & 1) == 0) &&
           ((uVar3 = Ram00fdea, (uVar3 & 4) == 0 || (uVar3 = Ram00fdea, (uVar3 & 8) == 0)))) {
          uVar3 = Ram00fdea;
          Ram00fdea = uVar3 | 4;
          uVar3 = Ram00fdea;
          Ram00fdea = uVar3 | 8;
          iRam00f464 = iRam00f464 + 2;
          uRam00f581 = 0x78;
          return;
        }
        uVar3 = Ram00fdea;
        Ram00fdea = uVar3 & 0xfffb;
        uVar3 = Ram00fdea;
        Ram00fdea = uVar3 & 0xfff7;
        cVar2 = egs52_compute_from_near_fdee_083040();
        if (cVar2 == '\x01') {
          uRam00f581 = 0x22;
          return;
        }
        if (cVar2 == '\x02') {
          uRam00f581 = 0x40;
          return;
        }
        if (cVar2 == '\0') {
          uVar3 = Ram00fdec;
          Ram00fdec = uVar3 | 4;
          return;
        }
        uVar3 = Ram00fdec;
        Ram00fdec = uVar3 | 4;
        return;
      }
    }
    if (((bRam00f57f & 0xe) == 0) || (cRam00f580 != '\x02')) {
      uRam00f581 = 0x33;
    }
    else {
      uVar3 = Ram00fdea;
      if (((uVar3 & 4) == 0) || (uVar3 = Ram00fdea, (uVar3 & 8) == 0)) {
        uVar3 = Ram00fdea;
        Ram00fdea = uVar3 | 4;
        uVar3 = Ram00fdea;
        Ram00fdea = uVar3 | 8;
        uRam00f581 = 0x78;
        iRam00f464 = iRam00f464 + (uint)bRam00f469;
      }
      else {
        uVar3 = Ram00fdee;
        if ((uVar3 & 1) == 0) {
          (*(code *)((uint3)uRam09001c << 0x10 | (uint3)uRam09001a))();
          if (cRam00f405 == '\0') {
            Ram00ef00 = 0x74b;
            Ram00ef06 = 0;
            Ram00ef08 = 0;
            Ram00ef0a = 0;
            Ram00ef0c = 0;
            Ram00ef0e = 0;
            uVar3 = Ram00ef00;
            Ram00ef00 = uVar3 & 0xfffe;
            Ram00ee00 = 0x74b;
            Ram00ee06 = 0;
            Ram00ee08 = 0;
            Ram00ee0a = 0;
            Ram00ee0c = 0;
            Ram00ee0e = 0;
            uVar3 = Ram00ee00;
            Ram00ee00 = uVar3 & 0xfffe;
            (*(code *)((uint3)uRam080202 << 0x10 | (uint3)uRam080200))();
          }
          else {
            uVar3 = Ram00fdea;
            Ram00fdea = uVar3 & 0xfffb;
            uVar3 = Ram00fdea;
            Ram00fdea = uVar3 & 0xfff7;
            uRam00f581 = 0x22;
          }
        }
        else {
          uVar3 = Ram00fdea;
          Ram00fdea = uVar3 & 0xfffb;
          uVar3 = Ram00fdea;
          Ram00fdea = uVar3 & 0xfff7;
          uRam00f403 = 2;
          uVar3 = 0x24;
          if ((((uRam00f462 & 0xc000) != 0) && (uVar3 = 0x21, (uRam00f462 & 0xc000) != 0x4000)) &&
             (uVar3 = 0x2c, (uRam00f462 & 0xc000) != 0x8000)) {
            uVar3 = 3;
          }
          if (*(char *)((uint3)uVar3 << 0xe | (uint3)(uRam00f462 & 0x3fff)) == '\0') {
            uRam00f3f0 = 0x6000;
            uRam00f3f2 = 8;
            uRam00f3f4 = 2;
            uRam00f3f6 = 0;
            cVar2 = egs52_update_near_f3fe_08115c(1);
            if (cVar2 == '\0') {
              uRam00f581 = 0x22;
            }
          }
          else {
            cVar2 = egs52_register_sequence_08112c();
            if (cVar2 == '\x01') {
              if (bRam00f469 == 2) {
                uRam00f3f0 = uRam090252;
                uRam00f3f2 = uRam090254;
                uRam00f3f4 = 2;
                uRam00f3f6 = 0;
                cVar2 = egs52_update_near_f3fe_08115c(0);
                if (cVar2 == '\0') {
                  uRam00f581 = 0x22;
                }
              }
              else {
                uRam00f3f4 = 2;
                uRam00f3f6 = 0;
                uVar3 = uRam00f462 + 1;
                uVar1 = 0x24;
                if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
                   (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
                  uVar1 = 3;
                }
                uRam00f3f2 = (uint)*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff));
                uVar3 = uRam00f462 + 2;
                uVar1 = 0x24;
                if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
                   (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
                  uVar1 = 3;
                }
                    /* WARNING: Ignoring partial resolution of indirect */
                uRam00f3f0._1_1_ = *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff));
                uVar3 = uRam00f462 + 3;
                uVar1 = 0x24;
                if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
                   (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
                  uVar1 = 3;
                }
                    /* WARNING: Ignoring partial resolution of indirect */
                uRam00f3f0._0_1_ = *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff));
                cVar2 = egs52_update_near_f3fe_08115c(2);
                if (cVar2 == '\0') {
                  uRam00f581 = 0x22;
                }
              }
            }
            else {
              uRam00f581 = 0x91;
            }
          }
        }
      }
    }
  }
  else {
    uRam00f581 = 0x22;
  }
  return;
}


