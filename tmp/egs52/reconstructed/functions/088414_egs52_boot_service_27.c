/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x088414; FLS offset 0x008414.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0885e0) */
/* WARNING: Removing unreachable block (ram,0x0886ac) */
/* WARNING: Removing unreachable block (ram,0x08869e) */
/* WARNING: Removing unreachable block (ram,0x088698) */
/* WARNING: Removing unreachable block (ram,0x088694) */
/* WARNING: Removing unreachable block (ram,0x08868c) */
/* WARNING: Removing unreachable block (ram,0x088688) */
/* WARNING: Removing unreachable block (ram,0x08867e) */
/* WARNING: Removing unreachable block (ram,0x088678) */
/* WARNING: Removing unreachable block (ram,0x08866e) */
/* WARNING: Removing unreachable block (ram,0x08865e) */
/* WARNING: Removing unreachable block (ram,0x08864a) */
/* WARNING: Removing unreachable block (ram,0x088656) */
/* WARNING: Removing unreachable block (ram,0x088650) */
/* WARNING: Removing unreachable block (ram,0x088642) */
/* WARNING: Removing unreachable block (ram,0x088636) */
/* WARNING: Removing unreachable block (ram,0x088634) */
/* WARNING: Removing unreachable block (ram,0x088624) */
/* WARNING: Removing unreachable block (ram,0x088666) */
/* WARNING: Removing unreachable block (ram,0x088612) */
/* WARNING: Removing unreachable block (ram,0x08860c) */
/* WARNING: Removing unreachable block (ram,0x088608) */
/* WARNING: Removing unreachable block (ram,0x0885fe) */
/* WARNING: Removing unreachable block (ram,0x0885fa) */
/* WARNING: Removing unreachable block (ram,0x0886a8) */
/* WARNING: Removing unreachable block (ram,0x0885f2) */
/* WARNING: Removing unreachable block (ram,0x0885f0) */
/* WARNING: Removing unreachable block (ram,0x0885ec) */
/* WARNING: Removing unreachable block (ram,0x0885e8) */
/* WARNING: Removing unreachable block (ram,0x0885d2) */
/* WARNING: Removing unreachable block (ram,0x0885ca) */
/* WARNING: Removing unreachable block (ram,0x0885c6) */
/* WARNING: Removing unreachable block (ram,0x0885c0) */
/* WARNING: Removing unreachable block (ram,0x0885bc) */
/* WARNING: Removing unreachable block (ram,0x0885b2) */
/* WARNING: Removing unreachable block (ram,0x0885aa) */
/* WARNING: Removing unreachable block (ram,0x0885a4) */
/* WARNING: Removing unreachable block (ram,0x0886b6) */
/* WARNING: Removing unreachable block (ram,0x08859a) */
/* WARNING: Removing unreachable block (ram,0x088590) */
/* WARNING: Removing unreachable block (ram,0x08858a) */
/* WARNING: Removing unreachable block (ram,0x088582) */
/* WARNING: Removing unreachable block (ram,0x08857a) */
/* WARNING: Removing unreachable block (ram,0x088488) */
/* WARNING: Removing unreachable block (ram,0x088484) */
/* WARNING: Removing unreachable block (ram,0x08847e) */
/* WARNING: Removing unreachable block (ram,0x08847a) */
/* WARNING: Removing unreachable block (ram,0x088476) */
/* WARNING: Removing unreachable block (ram,0x088472) */
/* WARNING: Removing unreachable block (ram,0x08846e) */
/* WARNING: Removing unreachable block (ram,0x088562) */
/* WARNING: Removing unreachable block (ram,0x0884fc) */
/* WARNING: Removing unreachable block (ram,0x0884f6) */
/* WARNING: Removing unreachable block (ram,0x0884f2) */
/* WARNING: Removing unreachable block (ram,0x0884ee) */
/* WARNING: Removing unreachable block (ram,0x0884ea) */
/* WARNING: Removing unreachable block (ram,0x0884e6) */
/* WARNING: Removing unreachable block (ram,0x0884e0) */
/* WARNING: Removing unreachable block (ram,0x0884d6) */
/* WARNING: Removing unreachable block (ram,0x0884d0) */
/* WARNING: Removing unreachable block (ram,0x08855e) */
/* WARNING: Removing unreachable block (ram,0x088546) */
/* WARNING: Removing unreachable block (ram,0x088554) */
/* WARNING: Removing unreachable block (ram,0x08852c) */
/* WARNING: Removing unreachable block (ram,0x088526) */
/* WARNING: Removing unreachable block (ram,0x088522) */
/* WARNING: Removing unreachable block (ram,0x088518) */
/* WARNING: Removing unreachable block (ram,0x088514) */
/* WARNING: Removing unreachable block (ram,0x088510) */
/* WARNING: Removing unreachable block (ram,0x08850a) */
/* WARNING: Removing unreachable block (ram,0x088502) */
/* WARNING: Removing unreachable block (ram,0x0884c4) */
/* WARNING: Removing unreachable block (ram,0x0884bc) */
/* WARNING: Removing unreachable block (ram,0x0884b2) */
/* WARNING: Removing unreachable block (ram,0x0884a8) */
/* WARNING: Removing unreachable block (ram,0x0884a0) */
/* WARNING: Removing unreachable block (ram,0x08849c) */
/* WARNING: Removing unreachable block (ram,0x088498) */
/* WARNING: Removing unreachable block (ram,0x088490) */
/* WARNING: Removing unreachable block (ram,0x088462) */
/* WARNING: Removing unreachable block (ram,0x08844e) */
/* WARNING: Removing unreachable block (ram,0x088446) */
/* WARNING: Removing unreachable block (ram,0x08843c) */
/* WARNING: Removing unreachable block (ram,0x088432) */
/* WARNING: Removing unreachable block (ram,0x08842e) */
/* WARNING: Removing unreachable block (ram,0x08841a) */
/* WARNING: Removing unreachable block (ram,0x0884ae) */
/* WARNING: Removing unreachable block (ram,0x08856a) */
/* WARNING: Removing unreachable block (ram,0x08856e) */
/* WARNING: Removing unreachable block (ram,0x0884b8) */
/* WARNING: Removing unreachable block (ram,0x088550) */
/* WARNING: Removing unreachable block (ram,0x088548) */
/* WARNING: Removing unreachable block (ram,0x088426) */
/* WARNING: Removing unreachable block (ram,0x08863e) */
/* WARNING: Heritage AFTER dead removal. Example location: r0x00f404 : 0x088642 */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void egs52_boot_service_27(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uStack_8;
  
  if ((bRam00f402 & 4) == 0) {
    cRam00f581 = '7';
  }
  else {
    uVar1 = 0x24;
    if ((((uRam00f462 & 0xc000) != 0) && (uVar1 = 0x21, (uRam00f462 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uRam00f462 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    if ((*(byte *)((uint3)uVar1 << 0xe | (uint3)(uRam00f462 & 0x3fff)) & 1) == 0) {
      if (((uint)bRam00f469 == bRam00f5a2 + 2) && (3 < bRam00f469)) {
        if ((cRam00f5a1 == '\0') || (((byte)(2 << (bRam00f5a3 & 0xf)) & bRam00f57f) != 0)) {
          uVar1 = uRam00f462 + 1;
          uVar3 = 0x24;
          if (((uVar1 & 0xc000) != 0) &&
             ((uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000 &&
              (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)))) {
            uVar3 = 3;
          }
          *(undefined1 *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)) = 0x34;
          bRam00f469 = 3;
          cRam00f581 = '\0';
        }
        else if (cRam00f5a1 == -1) {
          cRam00f581 = '\"';
        }
        else {
          cRam00f5a1 = cRam00f5a1 + '\x01';
          uVar1 = 0x24;
          if ((((uRam00f462 & 0xc000) != 0) && (uVar1 = 0x21, (uRam00f462 & 0xc000) != 0x4000)) &&
             (uVar1 = 0x2c, (uRam00f462 & 0xc000) != 0x8000)) {
            uVar1 = 3;
          }
          if (*(char *)((uint3)uVar1 << 0xe | (uint3)(uRam00f462 & 0x3fff)) == cRam00f5a1) {
            cRam00f581 = '\0';
            uVar1 = *(uint *)((uint3)((uint)bRam00f5a3 * 4 + 8) | 0x88000);
            uVar3 = *(uint *)((uint3)((uint)bRam00f5a3 * 4 + 10) | 0x88000);
            *(uint *)((uint3)((uint)&uStack_8 & 0x3fff) | 0x88000) = uVar1;
            for (uVar5 = 0; uVar5 < bRam00f5a2; uVar5 = uVar5 + 1) {
              uVar4 = uRam00f462 + 1 + uVar5;
              uVar2 = 0x24;
              if ((((uVar4 & 0xc000) != 0) && (uVar2 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
                 (uVar2 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
                uVar2 = 3;
              }
              if (*(char *)((uint3)((uVar3 & 0xff) << 2 | uVar1 >> 0xe) << 0xe |
                           (uint3)((uStack_8 & 0x3fff) + uVar5 + bRam00f5a2 & 0x3fff)) !=
                  *(char *)((uint3)uVar2 << 0xe | (uint3)(uVar4 & 0x3fff))) {
                cRam00f404 = cRam00f404 == '\0';
                if (!(bool)cRam00f404) {
                  bRam00f402 = 1;
                }
                cRam00f581 = '5';
                break;
              }
            }
            if (cRam00f581 == '\0') {
              egs52_update_near_f57f_088f1e();
              bRam00f57f = bRam00f57f | 1 | (byte)(2 << (bRam00f5a3 & 0xf));
              cRam00f5a1 = '\0';
              uVar1 = uRam00f462 + 1;
              uVar3 = 0x24;
              if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
                 (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
                uVar3 = 3;
              }
              *(undefined1 *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)) = 0x34;
              bRam00f469 = 3;
            }
          }
          else {
            cRam00f581 = '3';
          }
          bRam00f5a2 = 0;
        }
      }
      else {
        cRam00f581 = 'y';
      }
    }
    else if (bRam00f469 == 2) {
      bRam00f5a2 = 0;
      if (((cRam083e7c == -1) || (cRam083e7c == -4)) && (cRam083fcc == -1)) {
        uVar1 = uRam00f462 + 1;
        uVar3 = 0x24;
        if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
           (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
          uVar3 = 3;
        }
        *(undefined1 *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)) = 0;
        uVar1 = uRam00f462 + 2;
        uVar3 = 0x24;
        if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
           (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
          uVar3 = 3;
        }
        *(undefined1 *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)) = 0;
        cRam00f5a1 = '\0';
        bRam00f469 = 4;
        cRam00f581 = '\0';
      }
      else {
        cRam00f5a1 = -1;
        cRam00f581 = '\"';
        bRam00f5a3 = 0;
        do {
          uVar1 = 0x24;
          if ((((uRam00f462 & 0xc000) != 0) && (uVar1 = 0x21, (uRam00f462 & 0xc000) != 0x4000)) &&
             (uVar1 = 0x2c, (uRam00f462 & 0xc000) != 0x8000)) {
            uVar1 = 3;
          }
          if (*(char *)((uint3)(bRam00f5a3 + 0x14) | 0x88000) ==
              *(char *)((uint3)uVar1 << 0xe | (uint3)(uRam00f462 & 0x3fff))) {
            uVar1 = 0x24;
            if ((((uRam00f462 & 0xc000) != 0) && (uVar1 = 0x21, (uRam00f462 & 0xc000) != 0x4000)) &&
               (uVar1 = 0x2c, (uRam00f462 & 0xc000) != 0x8000)) {
              uVar1 = 3;
            }
            cRam00f5a1 = *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uRam00f462 & 0x3fff));
            if (((uint)bRam00f57f & 2 << (bRam00f5a3 & 0xf)) == 0) {
              bRam00f469 = *(byte *)((uint3)(bRam00f5a3 + 0x17) | 0x88000);
              uVar1 = *(uint *)((uint3)((uint)bRam00f5a3 * 4 + 8) | 0x88000);
              uVar3 = *(uint *)((uint3)((uint)bRam00f5a3 * 4 + 10) | 0x88000);
              bRam00f5a2 = bRam00f469;
              *(uint *)((uint3)((uint)&uStack_8 & 0x3fff) | 0x88000) = uVar1;
              for (uVar5 = 0; uVar5 < bRam00f5a2; uVar5 = uVar5 + 1) {
                uVar4 = uRam00f462 + 1 + uVar5;
                uVar2 = 0x24;
                if ((((uVar4 & 0xc000) != 0) && (uVar2 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
                   (uVar2 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
                  uVar2 = 3;
                }
                *(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar4 & 0x3fff)) =
                     *(undefined1 *)
                      ((uint3)((uVar3 & 0xff) << 2 | uVar1 >> 0xe) << 0xe |
                      (uint3)((uStack_8 & 0x3fff) + uVar5 & 0x3fff));
              }
              bRam00f469 = bRam00f469 + 2;
            }
            else {
              egs52_update_near_f57f_088f1e();
              bRam00f57f = bRam00f57f | 1 | (byte)(2 << (bRam00f5a3 & 0xf));
              uVar1 = uRam00f462 + 1;
              uVar3 = 0x24;
              if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
                 (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
                uVar3 = 3;
              }
              *(undefined1 *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)) = 0;
              uVar1 = uRam00f462 + 2;
              uVar3 = 0x24;
              if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
                 (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
                uVar3 = 3;
              }
              *(undefined1 *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)) = 0;
              cRam00f5a1 = 0;
              bRam00f469 = '\x04';
            }
            cRam00f581 = 0;
            return;
          }
          bRam00f5a3 = bRam00f5a3 + 1;
        } while (bRam00f5a3 < 3);
      }
    }
    else {
      cRam00f5a1 = -1;
      cRam00f581 = 'y';
    }
  }
  return;
}


