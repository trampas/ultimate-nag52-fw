/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x095bbc; FLS offset 0x015bbc.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x095e92) */
/* WARNING: Removing unreachable block (ram,0x095cce) */
/* WARNING: Removing unreachable block (ram,0x095c7e) */
/* WARNING: Removing unreachable block (ram,0x095cda) */
/* WARNING: Removing unreachable block (ram,0x095c8a) */
/* WARNING: Removing unreachable block (ram,0x095cc2) */
/* WARNING: Removing unreachable block (ram,0x095d94) */
/* WARNING: Removing unreachable block (ram,0x095eae) */
/* WARNING: Removing unreachable block (ram,0x095d5c) */
/* WARNING: Removing unreachable block (ram,0x095e50) */
/* WARNING: Removing unreachable block (ram,0x095c68) */
/* WARNING: Removing unreachable block (ram,0x095dea) */
/* WARNING: Removing unreachable block (ram,0x095cb8) */
/* WARNING: Removing unreachable block (ram,0x095e24) */
/* WARNING: Removing unreachable block (ram,0x095cf2) */
/* WARNING: Removing unreachable block (ram,0x095eee) */
/* WARNING: Removing unreachable block (ram,0x095dd8) */
/* WARNING: Removing unreachable block (ram,0x095cd6) */
/* WARNING: Removing unreachable block (ram,0x095ee0) */
/* WARNING: Removing unreachable block (ram,0x095c90) */
/* WARNING: Removing unreachable block (ram,0x095e9a) */
/* WARNING: Removing unreachable block (ram,0x095dae) */
/* WARNING: Removing unreachable block (ram,0x095c86) */
/* WARNING: Removing unreachable block (ram,0x095d80) */
/* WARNING: Removing unreachable block (ram,0x095c5c) */
/* WARNING: Removing unreachable block (ram,0x095e84) */
/* WARNING: Removing unreachable block (ram,0x095d66) */
/* WARNING: Removing unreachable block (ram,0x095c56) */
/* WARNING: Removing unreachable block (ram,0x095d86) */
/* WARNING: Removing unreachable block (ram,0x095c9e) */
/* WARNING: Removing unreachable block (ram,0x095c2c) */
/* WARNING: Removing unreachable block (ram,0x095e42) */
/* WARNING: Removing unreachable block (ram,0x095c44) */
/* WARNING: Removing unreachable block (ram,0x095e3c) */
/* WARNING: Removing unreachable block (ram,0x095d48) */
/* WARNING: Removing unreachable block (ram,0x095cee) */
/* WARNING: Removing unreachable block (ram,0x095be2) */
/* WARNING: Removing unreachable block (ram,0x095ed6) */
/* WARNING: Removing unreachable block (ram,0x095dfc) */
/* WARNING: Removing unreachable block (ram,0x095c96) */
/* WARNING: Removing unreachable block (ram,0x095c34) */
/* WARNING: Removing unreachable block (ram,0x095bfe) */
/* WARNING: Removing unreachable block (ram,0x095c72) */
/* WARNING: Removing unreachable block (ram,0x095d20) */
/* WARNING: Removing unreachable block (ram,0x095e0c) */
/* WARNING: Removing unreachable block (ram,0x095edc) */
/* WARNING: Removing unreachable block (ram,0x095ca4) */
/* WARNING: Removing unreachable block (ram,0x095e5e) */
/* WARNING: Removing unreachable block (ram,0x095d8c) */
/* WARNING: Removing unreachable block (ram,0x095c40) */
/* WARNING: Removing unreachable block (ram,0x095d30) */
/* WARNING: Removing unreachable block (ram,0x095e4a) */
/* WARNING: Removing unreachable block (ram,0x095d9a) */
/* WARNING: Removing unreachable block (ram,0x095ed0) */
/* WARNING: Removing unreachable block (ram,0x095dce) */
/* WARNING: Removing unreachable block (ram,0x095db8) */
/* WARNING: Removing unreachable block (ram,0x095c10) */
/* WARNING: Removing unreachable block (ram,0x095ea8) */
/* WARNING: Removing unreachable block (ram,0x095d7c) */
/* WARNING: Removing unreachable block (ram,0x095cac) */
/* WARNING: Removing unreachable block (ram,0x095d28) */
/* WARNING: Removing unreachable block (ram,0x095ec8) */
/* WARNING: Removing unreachable block (ram,0x095e32) */
/* WARNING: Removing unreachable block (ram,0x095dc6) */
/* WARNING: Removing unreachable block (ram,0x095d74) */
/* WARNING: Removing unreachable block (ram,0x095de6) */
/* WARNING: Removing unreachable block (ram,0x095dd2) */
/* WARNING: Removing unreachable block (ram,0x095e58) */
/* WARNING: Removing unreachable block (ram,0x095da2) */
/* WARNING: Removing unreachable block (ram,0x095ee4) */
/* WARNING: Removing unreachable block (ram,0x095ea0) */
/* WARNING: Removing unreachable block (ram,0x095da8) */
/* WARNING: Removing unreachable block (ram,0x095ce6) */
/* WARNING: Removing unreachable block (ram,0x095cb2) */
/* WARNING: Removing unreachable block (ram,0x095d4c) */
/* WARNING: Removing unreachable block (ram,0x095ce0) */
/* WARNING: Removing unreachable block (ram,0x095e6c) */
/* WARNING: Removing unreachable block (ram,0x095dde) */
/* WARNING: Removing unreachable block (ram,0x095e66) */
/* WARNING: Removing unreachable block (ram,0x095d04) */

void egs52_update_near_c0c6_095bbc(void)

{
  uint uVar1;
  uint uVar2;
  undefined2 uVar3;
  byte bVar4;
  undefined1 uVar5;
  char cVar6;
  uchar uVar7;
  char cVar8;
  int iVar9;
  
  cVar6 = egs52_update_near_fd6c_0a130c(0xc0d0);
  if ((cVar6 == '\0') && (cVar6 = egs52_update_near_fd6c_0a27c2(0xc0cc), cVar6 == '\0')) {
    cVar6 = '\x14';
    do {
      iVar9 = Ram00c0c8;
      if (iVar9 == 0) {
        bVar4 = UNK_00c0ca;
        if (bVar4 < 0x10) {
          uVar1 = (uint)(bVar4 >> 4) * 2 + 0xc0d0;
          uVar2 = 0x24;
          if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
             (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
            uVar2 = 3;
          }
          if ((*(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) & 1 << (uint)bVar4 % 0x10)
              == 0) goto LAB_095c2c;
        }
        else {
LAB_095c2c:
          iVar9 = Ram00c0c6;
          if (iVar9 == 0) {
            Ram00c0c8 = 1;
            goto LAB_095cf2;
          }
        }
        iVar9 = Ram00c0c6;
        if (iVar9 == 0) {
          Ram00c0c6 = 0xc08a;
          uVar5 = UNK_00c0ca;
          egs52_compute_from_near_f84e_0a1c96(uVar5);
          uVar7 = egs52_return_false_095f00();
          if (uVar7 == '\0') {
            uVar5 = UNK_00c0ca;
            uVar3 = Ram00c0c6;
            cVar8 = egs52_update_near_fd6c_0a160c(uVar5,1,uVar3);
            if (cVar8 == '\0') {
              cVar8 = UNK_00c0ca;
              uVar3 = Ram00c0c6;
              iVar9 = egs52_update_near_caa4_0a2fba(cVar8 + '\x10',uVar3);
              if (iVar9 == 0) {
                Ram00c0c8 = 0;
                return;
              }
              Ram00c0b6 = iVar9;
              iVar9 = Ram00c0b2;
              Ram00c0b2 = iVar9 + 1;
              Ram00c0c8 = 1;
              Ram00c0c6 = 0;
            }
            else {
              Ram00c0c8 = 1;
              Ram00c0c6 = 0;
            }
          }
          else {
            Ram00c0c8 = 1;
            Ram00c0c6 = 0;
          }
        }
        else {
          cVar8 = UNK_00c0ca;
          uVar3 = Ram00c0c6;
          iVar9 = egs52_update_near_caa4_0a2fba(cVar8 + '\x10',uVar3);
          if (iVar9 == 0) {
            Ram00c0c8 = 0;
            return;
          }
          Ram00c0b6 = iVar9;
          iVar9 = Ram00c0b2;
          Ram00c0b2 = iVar9 + 1;
          Ram00c0c8 = 1;
          Ram00c0c6 = 0;
        }
LAB_095cf2:
        bVar4 = UNK_00c0ca;
        if (bVar4 < 0x14) {
          uVar1 = (uint)(bVar4 >> 4) * 2 + 0xc0cc;
          uVar2 = 0x24;
          if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
             (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
            uVar2 = 3;
          }
          if ((*(uint *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) & 1 << (uint)bVar4 % 0x10)
              == 0) goto LAB_095d20;
LAB_095d28:
          iVar9 = Ram00c0c4;
          if (iVar9 == 0) {
            uVar5 = UNK_00c0ca;
            egs52_register_arithmetic_0a2b52(uVar5);
            uVar7 = egs52_return_false_095f00();
            if (uVar7 == '\0') {
              Ram00c0c4 = 0xc08a;
              uVar5 = UNK_00c0ca;
              cVar8 = egs52_update_near_fd6c_0a283e(uVar5,1,0xc08a);
              if (cVar8 == '\0') {
                cVar8 = UNK_00c0ca;
                uVar3 = Ram00c0c4;
                iVar9 = egs52_update_near_caa4_0a2fba(cVar8 + ' ',uVar3);
                if (iVar9 == 0) {
                  Ram00c0c8 = 1;
                  return;
                }
                Ram00c0b6 = iVar9;
                iVar9 = Ram00c0b4;
                Ram00c0b4 = iVar9 + 1;
                Ram00c0c8 = 2;
                Ram00c0c4 = 0;
              }
              else {
                Ram00c0c8 = 2;
                Ram00c0c4 = 0;
              }
            }
            else {
              Ram00c0c8 = 2;
              Ram00c0c4 = 0;
            }
          }
          else {
            cVar8 = UNK_00c0ca;
            uVar3 = Ram00c0c4;
            iVar9 = egs52_update_near_caa4_0a2fba(cVar8 + ' ',uVar3);
            if (iVar9 == 0) {
              Ram00c0c8 = 1;
              return;
            }
            Ram00c0b6 = iVar9;
            iVar9 = Ram00c0b4;
            Ram00c0b4 = iVar9 + 1;
            Ram00c0c8 = 2;
            Ram00c0c4 = 0;
          }
        }
        else {
LAB_095d20:
          iVar9 = Ram00c0c4;
          if (iVar9 != 0) goto LAB_095d28;
          Ram00c0c8 = 2;
        }
LAB_095dea:
        iVar9 = Ram00c0c2;
        if (iVar9 == 0) {
          if (cVar6 == '\x14') {
            Ram00c0c2 = 0xc08a;
            cVar8 = egs52_update_near_c44e_0a1586(0xc08a,1);
            if (cVar8 == '\0') {
              cVar8 = UNK_00c105;
              if (cVar8 == -1) {
                uVar3 = Ram00c0c2;
                iVar9 = egs52_update_near_caa4_0a2fba(0x34,uVar3);
                if (iVar9 == 0) {
                  Ram00c0c8 = 2;
                  return;
                }
                Ram00c0c8 = 3;
                Ram00c0c2 = 0;
              }
              else {
                Ram00c0c8 = 3;
                Ram00c0c2 = 0;
              }
            }
            else {
              Ram00c0c8 = 3;
              Ram00c0c2 = 0;
            }
          }
          else {
            Ram00c0c8 = 3;
          }
        }
        else {
          cVar8 = UNK_00c105;
          if (cVar8 == -1) {
            uVar3 = Ram00c0c2;
            iVar9 = egs52_update_near_caa4_0a2fba(0x34,uVar3);
            if (iVar9 == 0) {
              Ram00c0c8 = 2;
              return;
            }
            Ram00c0c8 = 3;
            Ram00c0c2 = 0;
          }
          else {
            Ram00c0c8 = 3;
            Ram00c0c2 = 0;
          }
        }
LAB_095eb2:
        if (cVar6 == '\x14') {
          uVar1 = Ram00fd00;
          if ((uVar1 & 2) == 0) {
            Ram00c0c8 = 0;
          }
          else {
            iVar9 = egs52_call_095b6a_095abc(1);
            if (iVar9 == 0) {
              Ram00c0c8 = 3;
              return;
            }
            uVar1 = Ram00fd00;
            Ram00fd00 = uVar1 & 0xfffd;
            Ram00c0c8 = 0;
          }
        }
        else {
          Ram00c0c8 = 0;
        }
      }
      else {
        if (iVar9 == 1) goto LAB_095cf2;
        if (iVar9 == 2) goto LAB_095dea;
        if (iVar9 == 3) goto LAB_095eb2;
      }
      cVar8 = UNK_00c0ca;
      UNK_00c0ca = cVar8 + '\x01';
      bVar4 = UNK_00c0ca;
      if (0x13 < bVar4) {
        UNK_00c0ca = 0;
      }
      cVar6 = cVar6 + -1;
    } while (cVar6 != '\0');
  }
  return;
}


