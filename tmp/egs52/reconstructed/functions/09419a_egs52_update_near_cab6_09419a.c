/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x09419a; FLS offset 0x01419a.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Function: egs52_call_far_indirect replaced with injection: call_far_indirect */
/* WARNING: Removing unreachable block (ram,0x0947d4) */
/* WARNING: Removing unreachable block (ram,0x0947ce) */
/* WARNING: Removing unreachable block (ram,0x0947c4) */
/* WARNING: Removing unreachable block (ram,0x0947ac) */
/* WARNING: Removing unreachable block (ram,0x09477a) */
/* WARNING: Removing unreachable block (ram,0x094776) */
/* WARNING: Removing unreachable block (ram,0x09476e) */
/* WARNING: Removing unreachable block (ram,0x094764) */
/* WARNING: Removing unreachable block (ram,0x094754) */
/* WARNING: Removing unreachable block (ram,0x094740) */
/* WARNING: Removing unreachable block (ram,0x094730) */
/* WARNING: Removing unreachable block (ram,0x0946ea) */
/* WARNING: Removing unreachable block (ram,0x0946da) */
/* WARNING: Removing unreachable block (ram,0x0946d6) */
/* WARNING: Removing unreachable block (ram,0x0946d2) */
/* WARNING: Removing unreachable block (ram,0x0946cc) */
/* WARNING: Removing unreachable block (ram,0x094716) */
/* WARNING: Removing unreachable block (ram,0x094714) */
/* WARNING: Removing unreachable block (ram,0x094708) */
/* WARNING: Removing unreachable block (ram,0x094706) */
/* WARNING: Removing unreachable block (ram,0x0946fc) */
/* WARNING: Removing unreachable block (ram,0x0946f6) */
/* WARNING: Removing unreachable block (ram,0x0946f2) */
/* WARNING: Removing unreachable block (ram,0x0946c4) */
/* WARNING: Removing unreachable block (ram,0x09468c) */
/* WARNING: Removing unreachable block (ram,0x094690) */
/* WARNING: Removing unreachable block (ram,0x094660) */
/* WARNING: Removing unreachable block (ram,0x09466e) */
/* WARNING: Removing unreachable block (ram,0x09465c) */
/* WARNING: Removing unreachable block (ram,0x094666) */
/* WARNING: Removing unreachable block (ram,0x094658) */
/* WARNING: Removing unreachable block (ram,0x0946b2) */
/* WARNING: Removing unreachable block (ram,0x0946a8) */
/* WARNING: Removing unreachable block (ram,0x094640) */
/* WARNING: Removing unreachable block (ram,0x094638) */
/* WARNING: Removing unreachable block (ram,0x094630) */
/* WARNING: Removing unreachable block (ram,0x09462a) */
/* WARNING: Removing unreachable block (ram,0x09461e) */
/* WARNING: Removing unreachable block (ram,0x094604) */
/* WARNING: Removing unreachable block (ram,0x094600) */
/* WARNING: Removing unreachable block (ram,0x0945fc) */
/* WARNING: Removing unreachable block (ram,0x0945f8) */
/* WARNING: Removing unreachable block (ram,0x0945f2) */
/* WARNING: Removing unreachable block (ram,0x0945ec) */
/* WARNING: Removing unreachable block (ram,0x0945da) */
/* WARNING: Removing unreachable block (ram,0x0945d6) */
/* WARNING: Removing unreachable block (ram,0x0945ba) */
/* WARNING: Removing unreachable block (ram,0x0945be) */
/* WARNING: Removing unreachable block (ram,0x0945b0) */
/* WARNING: Removing unreachable block (ram,0x0945d0) */
/* WARNING: Removing unreachable block (ram,0x09459e) */
/* WARNING: Removing unreachable block (ram,0x09459a) */
/* WARNING: Removing unreachable block (ram,0x094596) */
/* WARNING: Removing unreachable block (ram,0x094592) */
/* WARNING: Removing unreachable block (ram,0x09457e) */
/* WARNING: Removing unreachable block (ram,0x094572) */
/* WARNING: Removing unreachable block (ram,0x0947ea) */
/* WARNING: Removing unreachable block (ram,0x0947e8) */
/* WARNING: Removing unreachable block (ram,0x094554) */
/* WARNING: Removing unreachable block (ram,0x09454a) */
/* WARNING: Removing unreachable block (ram,0x094544) */
/* WARNING: Removing unreachable block (ram,0x094540) */
/* WARNING: Removing unreachable block (ram,0x09453c) */
/* WARNING: Removing unreachable block (ram,0x09450a) */
/* WARNING: Removing unreachable block (ram,0x094526) */
/* WARNING: Removing unreachable block (ram,0x0944f6) */
/* WARNING: Removing unreachable block (ram,0x0944f2) */
/* WARNING: Removing unreachable block (ram,0x0944ee) */
/* WARNING: Removing unreachable block (ram,0x0944ea) */
/* WARNING: Removing unreachable block (ram,0x0944ce) */
/* WARNING: Removing unreachable block (ram,0x09445e) */
/* WARNING: Removing unreachable block (ram,0x09443a) */
/* WARNING: Removing unreachable block (ram,0x09442c) */
/* WARNING: Removing unreachable block (ram,0x094486) */
/* WARNING: Removing unreachable block (ram,0x094482) */
/* WARNING: Removing unreachable block (ram,0x094470) */
/* WARNING: Removing unreachable block (ram,0x094408) */
/* WARNING: Removing unreachable block (ram,0x094400) */
/* WARNING: Removing unreachable block (ram,0x0943de) */
/* WARNING: Removing unreachable block (ram,0x0943aa) */
/* WARNING: Removing unreachable block (ram,0x0943a2) */
/* WARNING: Removing unreachable block (ram,0x09439c) */
/* WARNING: Removing unreachable block (ram,0x094398) */
/* WARNING: Removing unreachable block (ram,0x09438c) */
/* WARNING: Removing unreachable block (ram,0x094378) */
/* WARNING: Removing unreachable block (ram,0x094374) */
/* WARNING: Removing unreachable block (ram,0x09436c) */
/* WARNING: Removing unreachable block (ram,0x094368) */
/* WARNING: Removing unreachable block (ram,0x094364) */
/* WARNING: Removing unreachable block (ram,0x094360) */
/* WARNING: Removing unreachable block (ram,0x094356) */
/* WARNING: Removing unreachable block (ram,0x094326) */
/* WARNING: Removing unreachable block (ram,0x094320) */
/* WARNING: Removing unreachable block (ram,0x09431a) */
/* WARNING: Removing unreachable block (ram,0x094302) */
/* WARNING: Removing unreachable block (ram,0x0942fc) */
/* WARNING: Removing unreachable block (ram,0x09430e) */
/* WARNING: Removing unreachable block (ram,0x09430a) */
/* WARNING: Removing unreachable block (ram,0x0942f6) */
/* WARNING: Removing unreachable block (ram,0x0942f0) */
/* WARNING: Removing unreachable block (ram,0x0942ea) */
/* WARNING: Removing unreachable block (ram,0x0942e6) */
/* WARNING: Removing unreachable block (ram,0x094342) */
/* WARNING: Removing unreachable block (ram,0x09433e) */
/* WARNING: Removing unreachable block (ram,0x094336) */
/* WARNING: Removing unreachable block (ram,0x094332) */
/* WARNING: Removing unreachable block (ram,0x09432e) */
/* WARNING: Removing unreachable block (ram,0x0942e0) */
/* WARNING: Removing unreachable block (ram,0x0942dc) */
/* WARNING: Removing unreachable block (ram,0x0942d2) */
/* WARNING: Removing unreachable block (ram,0x0942ca) */
/* WARNING: Removing unreachable block (ram,0x0942c4) */
/* WARNING: Removing unreachable block (ram,0x0942b8) */
/* WARNING: Removing unreachable block (ram,0x09429c) */
/* WARNING: Removing unreachable block (ram,0x094818) */
/* WARNING: Removing unreachable block (ram,0x094810) */
/* WARNING: Removing unreachable block (ram,0x09480c) */
/* WARNING: Removing unreachable block (ram,0x0947fc) */
/* WARNING: Removing unreachable block (ram,0x094214) */
/* WARNING: Removing unreachable block (ram,0x0941fa) */
/* WARNING: Removing unreachable block (ram,0x0941fc) */
/* WARNING: Removing unreachable block (ram,0x0941f6) */
/* WARNING: Removing unreachable block (ram,0x09420e) */
/* WARNING: Removing unreachable block (ram,0x0941ee) */
/* WARNING: Removing unreachable block (ram,0x094284) */
/* WARNING: Removing unreachable block (ram,0x09427c) */
/* WARNING: Removing unreachable block (ram,0x094278) */
/* WARNING: Removing unreachable block (ram,0x094272) */
/* WARNING: Removing unreachable block (ram,0x09425e) */
/* WARNING: Removing unreachable block (ram,0x094250) */
/* WARNING: Removing unreachable block (ram,0x09424a) */
/* WARNING: Removing unreachable block (ram,0x094244) */
/* WARNING: Removing unreachable block (ram,0x09423a) */
/* WARNING: Removing unreachable block (ram,0x094236) */
/* WARNING: Removing unreachable block (ram,0x094220) */
/* WARNING: Removing unreachable block (ram,0x09421c) */
/* WARNING: Removing unreachable block (ram,0x0941e4) */
/* WARNING: Removing unreachable block (ram,0x0941d6) */
/* WARNING: Removing unreachable block (ram,0x09426e) */
/* WARNING: Removing unreachable block (ram,0x0943d6) */
/* WARNING: Removing unreachable block (ram,0x094420) */
/* WARNING: Removing unreachable block (ram,0x094448) */
/* WARNING: Removing unreachable block (ram,0x0944c0) */
/* WARNING: Removing unreachable block (ram,0x09451e) */
/* WARNING: Removing unreachable block (ram,0x094506) */
/* WARNING: Removing unreachable block (ram,0x09450e) */
/* WARNING: Removing unreachable block (ram,0x09452c) */
/* WARNING: Removing unreachable block (ram,0x094530) */
/* WARNING: Removing unreachable block (ram,0x094556) */
/* WARNING: Removing unreachable block (ram,0x094564) */
/* WARNING: Removing unreachable block (ram,0x0945b4) */
/* WARNING: Removing unreachable block (ram,0x094614) */
/* WARNING: Removing unreachable block (ram,0x094688) */
/* WARNING: Removing unreachable block (ram,0x094672) */
/* WARNING: Removing unreachable block (ram,0x09466a) */
/* WARNING: Removing unreachable block (ram,0x09469a) */
/* WARNING: Removing unreachable block (ram,0x0946c0) */
/* WARNING: Removing unreachable block (ram,0x0947b6) */
/* WARNING: Removing unreachable block (ram,0x0947c8) */
/* WARNING: Removing unreachable block (ram,0x09425a) */
/* WARNING: Removing unreachable block (ram,0x09424e) */
/* WARNING: Removing unreachable block (ram,0x0941c4) */
/* WARNING: Removing unreachable block (ram,0x0947a8) */
/* WARNING: Removing unreachable block (ram,0x09479e) */
/* WARNING: Removing unreachable block (ram,0x094798) */
/* WARNING: Removing unreachable block (ram,0x094782) */
/* WARNING: Removing unreachable block (ram,0x09477e) */
/* WARNING: Removing unreachable block (ram,0x094768) */
/* WARNING: Removing unreachable block (ram,0x094514) */
/* WARNING: Removing unreachable block (ram,0x094518) */
/* WARNING: Removing unreachable block (ram,0x094678) */
/* WARNING: Removing unreachable block (ram,0x0947a4) */
/* WARNING: Removing unreachable block (ram,0x094206) */
/* WARNING: Removing unreachable block (ram,0x09446a) */
/* WARNING: Heritage AFTER dead removal. Example location: r0x00f442 : 0x0945ec */
/* WARNING: Removing unreachable block (ram,0x094696) */
/* WARNING: Removing unreachable block (ram,0x0945ac) */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void egs52_update_near_cab6_09419a(char param_1,byte param_2)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  byte bVar5;
  byte bVar6;
  uint uVar7;
  uint uVar8;
  char cVar9;
  uint uVar10;
  uint uVar11;
  bool bVar12;
  
  cVar9 = '\0';
  if (param_1 == '\0') {
    uVar7 = Ram00fde8;
    if ((((uVar7 & 1) == 0) && (((iRam00f444 == 3 || (iRam00f444 == 6)) || (iRam00f444 == 4)))) &&
       ((iRam00f444 == 3 || (iRam00f444 == 4)))) {
      if (uRam00f45a < 8) {
        UNK_00f7b5 = (char)uRam00f45a;
        for (bVar5 = 0; bVar5 < uRam00f45a; bVar5 = bVar5 + 1) {
          uVar7 = 0x24;
          if ((((uRam00f456 & 0xc000) != 0) && (uVar7 = 0x21, (uRam00f456 & 0xc000) != 0x4000)) &&
             (uVar7 = 0x2c, (uRam00f456 & 0xc000) != 0x8000)) {
            uVar7 = 3;
          }
          uVar10 = uRam00f456 & 0x3fff;
          uRam00f456 = uRam00f456 + 1;
          uVar8 = bVar5 - 0x84a;
          uVar1 = 0x24;
          if ((((uVar8 & 0xc000) != 0) && (uVar1 = 0x21, (uVar8 & 0xc000) != 0x4000)) &&
             (uVar1 = 0x2c, (uVar8 & 0xc000) != 0x8000)) {
            uVar1 = 3;
          }
          *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar8 & 0x3fff)) =
               *(undefined1 *)((uint3)uVar7 << 0xe | (uint3)uVar10);
        }
        for (bVar5 = (byte)uRam00f45a; bVar5 < 7; bVar5 = bVar5 + 1) {
          uVar7 = bVar5 - 0x84a;
          uVar8 = 0x24;
          if ((((uVar7 & 0xc000) != 0) && (uVar8 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
             (uVar8 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
            uVar8 = 3;
          }
          *(undefined1 *)((uint3)uVar8 << 0xe | (uint3)(uVar7 & 0x3fff)) = 0xff;
        }
        iRam00f444 = 4;
        uRam00f45e = 0;
        Ram00cab6 = 0x7e;
        egs52_transform_far_memory_0a0770(2,8);
      }
      else {
        uRam00f442 = uRam00f45a;
        if (uRam00f45a < 0x1000) {
          UNK_00f7b5 = (byte)(uRam00f45a >> 8) & 0xf | 0x10;
          UNK_00f7b6 = (char)uRam00f45a;
          bVar5 = 0;
          do {
            uVar7 = 0x24;
            if ((((uRam00f456 & 0xc000) != 0) && (uVar7 = 0x21, (uRam00f456 & 0xc000) != 0x4000)) &&
               (uVar7 = 0x2c, (uRam00f456 & 0xc000) != 0x8000)) {
              uVar7 = 3;
            }
            uVar10 = uRam00f456 & 0x3fff;
            uRam00f456 = uRam00f456 + 1;
            uVar8 = bVar5 - 0x849;
            uVar1 = 0x24;
            if ((((uVar8 & 0xc000) != 0) && (uVar1 = 0x21, (uVar8 & 0xc000) != 0x4000)) &&
               (uVar1 = 0x2c, (uVar8 & 0xc000) != 0x8000)) {
              uVar1 = 3;
            }
            *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar8 & 0x3fff)) =
                 *(undefined1 *)((uint3)uVar7 << 0xe | (uint3)uVar10);
            uRam00f442 = uRam00f442 - 1;
            bVar5 = bVar5 + 1;
          } while (bVar5 < 6);
          uRam00f451 = 1;
          bRam00f452 = 0;
          iRam00f444 = 5;
          uRam00f45e = 0;
          Ram00cab6 = 0x7e;
          egs52_transform_far_memory_0a0770(2,8);
        }
      }
    }
  }
  else if (param_1 == '\x01') {
    if (param_2 == 5) {
      if (iRam00f444 == 1) {
        if (uRam00f45e < 0x3e9) {
          uRam00f45e = 0;
          Ram00cab6 = 9;
        }
        else {
          egs52_update_near_f878_09492a();
        }
      }
      else if (iRam00f444 == 6) {
        if (uRam00f45e < 0x3e9) {
          Ram00cab6 = 0xffff;
          if (uRam00f442 == 0) {
            iRam00f444 = 0;
            iVar4 = Ram00f7b2;
            iVar3 = Ram00f7b0;
            if (iVar4 != 0 || iVar3 != 0) {
              uVar7 = Ram00f7b0;
              uVar8 = Ram00f7b2;
              (*(code *)((uint3)uVar8 << 0x10 | (uint3)uVar7))();
            }
          }
          else if ((bRam00f452 < bRam00f450) || (bRam00f450 == 0)) {
            if (bRam00f44f == 0) {
              uRam00f45e = (uint)bRam00f44e;
              egs52_update_near_cab6_09488a();
            }
            else {
              uRam00f45e = 0;
              Ram00cab2 = (uint)bRam00f44f;
            }
          }
          else {
            uRam00f45e = 0;
            Ram00cab6 = 4;
            iRam00f444 = 2;
          }
        }
        else {
          egs52_update_near_f878_09492a();
        }
      }
      else if (iRam00f444 == 4) {
        if (uRam00f45e < 0x3e9) {
          iRam00f444 = 0;
          Ram00cab6 = 0xffff;
          iVar4 = Ram00f7b2;
          iVar3 = Ram00f7b0;
          if (iVar4 != 0 || iVar3 != 0) {
            uVar7 = Ram00f7b0;
            uVar8 = Ram00f7b2;
            (*(code *)((uint3)uVar8 << 0x10 | (uint3)uVar7))();
          }
        }
        else {
          egs52_update_near_f878_09492a();
        }
      }
      else if (iRam00f444 == 5) {
        if (uRam00f45e < 0x3e9) {
          iRam00f444 = 2;
          uRam00f45e = 0;
          Ram00cab6 = 4;
          uVar7 = Ram00fde8;
          Ram00fde8 = uVar7 | 4;
          uVar7 = Ram00fde8;
          Ram00fde8 = uVar7 | 8;
          cRam00f447 = '\0';
        }
        else {
          egs52_update_near_f878_09492a();
        }
      }
    }
  }
  else if (((param_1 == '\x02') && (2 < param_2)) && (param_2 < 5)) {
    uRam00f45c = 0xf46d;
    uRam00f458 = 0xff;
    uVar7 = Ram00fde8;
    if ((uVar7 & 1) == 0) {
      egs52_transform_far_memory_0a081a(0,8);
      uVar1 = (uint)(byte)(param_2 - 3);
      iVar3 = (uint)(byte)(param_2 - 3) * 0x14;
      uVar7 = iVar3 - 0x87d;
      uVar8 = 0x24;
      if ((((uVar7 & 0xc000) != 0) && (uVar8 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
         (uVar8 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
        uVar8 = 3;
      }
      if (((iRam00f444 == 0) || (iRam00f444 == 1)) || (iRam00f444 == 2)) {
        bVar12 = true;
        if ((*(byte *)((uint3)uVar8 << 0xe | (uint3)(uVar7 & 0x3fff)) & 2) == 0) {
          bVar5 = 0;
          uVar7 = iVar3 - 0x873;
          uVar8 = 0x24;
          if ((((uVar7 & 0xc000) != 0) && (uVar8 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
             (uVar8 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
            uVar8 = 3;
          }
          cVar9 = (char)((int)(*(byte *)((uint3)uVar8 << 0xe | (uint3)(uVar7 & 0x3fff)) & 0xf0) >> 4
                        );
          if (((-iRam00f44a == (uint)(uVar1 < uRam00f448) && uVar1 == uRam00f448) || (cVar9 == '\0')
              ) || ((cVar9 == '\x01' || ((cVar9 == '\x03' && (uVar7 = Ram00fde8, (uVar7 & 8) != 0)))
                    ))) {
            bVar12 = false;
            bVar5 = 0;
          }
        }
        else {
          bVar5 = 1;
          uVar7 = iVar3 - 0x873;
          uVar8 = 0x24;
          if ((((uVar7 & 0xc000) != 0) && (uVar8 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
             (uVar8 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
            uVar8 = 3;
          }
          cVar2 = *(char *)((uint3)uVar8 << 0xe | (uint3)(uVar7 & 0x3fff));
          if (cVar2 == cRam090b64) {
            uVar7 = iVar3 - 0x872;
            uVar8 = 0x24;
            if ((((uVar7 & 0xc000) != 0) && (uVar8 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
               (uVar8 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
              uVar8 = 3;
            }
            cVar9 = (char)((int)(*(byte *)((uint3)uVar8 << 0xe | (uint3)(uVar7 & 0x3fff)) & 0xf0) >>
                          4);
            if (((cVar2 == cRam00f447) || (cVar9 == '\0')) ||
               ((cVar9 == '\x01' || ((cVar9 == '\x03' && (uVar7 = Ram00fde8, (uVar7 & 8) != 0))))))
            {
              bVar12 = false;
              cRam00f447 = cVar2;
            }
          }
        }
        if (!bVar12) {
          if (cVar9 == '\0') {
            if (iRam00f444 != 2) {
              uVar7 = ((uint)bVar5 + iVar3) - 0x873;
              uVar8 = 0x24;
              if ((((uVar7 & 0xc000) != 0) && (uVar8 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
                 (uVar8 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
                uVar8 = 3;
              }
              bVar6 = *(byte *)((uint3)uVar8 << 0xe | (uint3)(uVar7 & 0x3fff));
              uVar7 = bVar6 & 0xf;
              if (((bVar6 & 0xf) != 0) && (uVar7 <= 7 - bVar5)) {
                uRam00f456 = uRam00f45c;
                uRam00f454 = uRam00f45c;
                uRam00f45a = uVar7;
                for (bVar6 = 1; (bVar6 <= uRam00f45a && (bVar6 <= uRam00f458)); bVar6 = bVar6 + 1) {
                  uVar7 = ((uint)bVar6 + (uint)bVar5 + iVar3) - 0x873;
                  uVar8 = 0x24;
                  if (((uVar7 & 0xc000) != 0) &&
                     ((uVar8 = 0x21, (uVar7 & 0xc000) != 0x4000 &&
                      (uVar8 = 0x2c, (uVar7 & 0xc000) != 0x8000)))) {
                    uVar8 = 3;
                  }
                  uVar10 = 0x24;
                  if ((((uRam00f454 & 0xc000) != 0) &&
                      (uVar10 = 0x21, (uRam00f454 & 0xc000) != 0x4000)) &&
                     (uVar10 = 0x2c, (uRam00f454 & 0xc000) != 0x8000)) {
                    uVar10 = 3;
                  }
                  uVar11 = uRam00f454 & 0x3fff;
                  uRam00f454 = uRam00f454 + 1;
                  *(undefined1 *)((uint3)uVar10 << 0xe | (uint3)uVar11) =
                       *(undefined1 *)((uint3)uVar8 << 0xe | (uint3)(uVar7 & 0x3fff));
                }
                if (uRam00f458 < uRam00f45a) {
                  uVar7 = Ram00fde8;
                  Ram00fde8 = uVar7 | 2;
                }
                else {
                  uVar7 = Ram00fde8;
                  Ram00fde8 = uVar7 & 0xfffd;
                }
                iRam00f44a = 0;
                cRam00f447 = '\0';
                iRam00f444 = 3;
                uVar8 = iVar3 - 0x87c;
                uVar7 = 0x24;
                if ((((uVar8 & 0xc000) != 0) && (uVar7 = 0x21, (uVar8 & 0xc000) != 0x4000)) &&
                   (uVar7 = 0x2c, (uVar8 & 0xc000) != 0x8000)) {
                  uVar7 = 3;
                }
                uVar10 = iVar3 - 0x87a;
                uVar11 = 0x24;
                if ((((uVar10 & 0xc000) != 0) && (uVar11 = 0x21, (uVar10 & 0xc000) != 0x4000)) &&
                   (uVar11 = 0x2c, (uVar10 & 0xc000) != 0x8000)) {
                  uVar11 = 3;
                }
                uRam00f448 = uVar1;
                if (*(int *)((uint3)uVar7 << 0xe | (uint3)(uVar8 & 0x3fff)) != 0 ||
                    *(int *)((uint3)uVar11 << 0xe | (uint3)(uVar10 & 0x3fff)) != 0) {
                  uVar7 = 0x24;
                  if ((((uVar8 & 0xc000) != 0) && (uVar7 = 0x21, (uVar8 & 0xc000) != 0x4000)) &&
                     (uVar7 = 0x2c, (uVar8 & 0xc000) != 0x8000)) {
                    uVar7 = 3;
                  }
                  uVar11 = iVar3 - 0x87a;
                  uVar10 = 0x24;
                  if ((((uVar11 & 0xc000) != 0) && (uVar10 = 0x21, (uVar11 & 0xc000) != 0x4000)) &&
                     (uVar10 = 0x2c, (uVar11 & 0xc000) != 0x8000)) {
                    uVar10 = 3;
                  }
                  (*(code *)((uint3)*(uint *)((uint3)uVar10 << 0xe | (uint3)(uVar11 & 0x3fff)) <<
                             0x10 | (uint3)*(uint *)((uint3)uVar7 << 0xe | (uint3)(uVar8 & 0x3fff)))
                  )();
                }
              }
            }
          }
          else if (cVar9 == '\x01') {
            if (iRam00f444 != 2) {
              uVar7 = ((uint)bVar5 + iVar3) - 0x873;
              uVar8 = 0x24;
              if ((((uVar7 & 0xc000) != 0) && (uVar8 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
                 (uVar8 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
                uVar8 = 3;
              }
              uVar10 = ((uint)bVar5 + iVar3) - 0x872;
              uVar11 = 0x24;
              if ((((uVar10 & 0xc000) != 0) && (uVar11 = 0x21, (uVar10 & 0xc000) != 0x4000)) &&
                 (uVar11 = 0x2c, (uVar10 & 0xc000) != 0x8000)) {
                uVar11 = 3;
              }
              uVar7 = (*(byte *)((uint3)uVar8 << 0xe | (uint3)(uVar7 & 0x3fff)) & 0xf) << 8 |
                      (uint)*(byte *)((uint3)uVar11 << 0xe | (uint3)(uVar10 & 0x3fff));
              if (7 - bVar5 < uVar7) {
                uRam00f454 = uRam00f456;
                uRam00f442 = uVar7;
                uRam00f45a = uVar7;
                for (bVar6 = bVar5 + 2; (bVar6 < 8 && ((uint)bVar6 - (bVar5 + 2) < uRam00f458));
                    bVar6 = bVar6 + 1) {
                  uVar7 = ((uint)bVar6 + iVar3) - 0x873;
                  uVar8 = 0x24;
                  if (((uVar7 & 0xc000) != 0) &&
                     ((uVar8 = 0x21, (uVar7 & 0xc000) != 0x4000 &&
                      (uVar8 = 0x2c, (uVar7 & 0xc000) != 0x8000)))) {
                    uVar8 = 3;
                  }
                  uVar10 = 0x24;
                  if ((((uRam00f454 & 0xc000) != 0) &&
                      (uVar10 = 0x21, (uRam00f454 & 0xc000) != 0x4000)) &&
                     (uVar10 = 0x2c, (uRam00f454 & 0xc000) != 0x8000)) {
                    uVar10 = 3;
                  }
                  uVar11 = uRam00f454 & 0x3fff;
                  uRam00f454 = uRam00f454 + 1;
                  *(undefined1 *)((uint3)uVar10 << 0xe | (uint3)uVar11) =
                       *(undefined1 *)((uint3)uVar8 << 0xe | (uint3)(uVar7 & 0x3fff));
                }
                if (uRam00f458 < uRam00f45a) {
                  uVar7 = Ram00fde8;
                  Ram00fde8 = uVar7 | 2;
                }
                else {
                  uVar7 = Ram00fde8;
                  Ram00fde8 = uVar7 & 0xfffd;
                }
                uRam00f442 = uRam00f442 - (6 - (uint)bVar5);
                iRam00f444 = 1;
                bRam00f44c = 1;
                iRam00f44a = 0;
                cRam00f44d = '\0';
                uRam00f448 = uVar1;
                egs52_update_near_fdea_0a454e();
                egs52_update_near_cab6_094840();
              }
            }
          }
          else if (cVar9 == '\x02') {
            if (iRam00f444 == 1) {
              if (uRam00f45e < 0x47) {
                uRam00f45e = 0;
                Ram00cab6 = 9;
                uVar7 = ((uint)bVar5 + iVar3) - 0x873;
                uVar8 = 0x24;
                if ((((uVar7 & 0xc000) != 0) && (uVar8 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
                   (uVar8 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
                  uVar8 = 3;
                }
                if ((*(byte *)((uint3)uVar8 << 0xe | (uint3)(uVar7 & 0x3fff)) & 0xf) == bRam00f44c)
                {
                  uVar7 = 1;
                  while( true ) {
                    uVar8 = 7 - bVar5;
                    if (uRam00f442 <= uVar8) {
                      uVar8 = uRam00f442;
                    }
                    if (uVar8 < uVar7) break;
                    uVar8 = Ram00fde8;
                    if ((uVar8 & 2) == 0) {
                      uVar8 = (uVar7 + bVar5 + iVar3) - 0x873;
                      uVar1 = 0x24;
                      if ((((uVar8 & 0xc000) != 0) && (uVar1 = 0x21, (uVar8 & 0xc000) != 0x4000)) &&
                         (uVar1 = 0x2c, (uVar8 & 0xc000) != 0x8000)) {
                        uVar1 = 3;
                      }
                      uVar10 = 0x24;
                      if ((((uRam00f454 & 0xc000) != 0) &&
                          (uVar10 = 0x21, (uRam00f454 & 0xc000) != 0x4000)) &&
                         (uVar10 = 0x2c, (uRam00f454 & 0xc000) != 0x8000)) {
                        uVar10 = 3;
                      }
                      uVar11 = uRam00f454 & 0x3fff;
                      uRam00f454 = uRam00f454 + 1;
                      *(undefined1 *)((uint3)uVar10 << 0xe | (uint3)uVar11) =
                           *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar8 & 0x3fff));
                    }
                    else if (uVar7 + uRam00f45a <= uRam00f458 + uRam00f442) {
                      uVar8 = (uVar7 + bVar5 + iVar3) - 0x873;
                      uVar1 = 0x24;
                      if ((((uVar8 & 0xc000) != 0) && (uVar1 = 0x21, (uVar8 & 0xc000) != 0x4000)) &&
                         (uVar1 = 0x2c, (uVar8 & 0xc000) != 0x8000)) {
                        uVar1 = 3;
                      }
                      uVar10 = 0x24;
                      if ((((uRam00f454 & 0xc000) != 0) &&
                          (uVar10 = 0x21, (uRam00f454 & 0xc000) != 0x4000)) &&
                         (uVar10 = 0x2c, (uRam00f454 & 0xc000) != 0x8000)) {
                        uVar10 = 3;
                      }
                      uVar11 = uRam00f454 & 0x3fff;
                      uRam00f454 = uRam00f454 + 1;
                      *(undefined1 *)((uint3)uVar10 << 0xe | (uint3)uVar11) =
                           *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar8 & 0x3fff));
                    }
                    uVar7 = (uint)(byte)((char)uVar7 + 1);
                  }
                  uRam00f442 = uRam00f442 - uVar8;
                  if (uRam00f442 == 0) {
                    cRam00f447 = '\0';
                    Ram00cab6 = 0xffff;
                    iRam00f444 = 3;
                    uVar8 = iVar3 - 0x87c;
                    uVar7 = 0x24;
                    if ((((uVar8 & 0xc000) != 0) && (uVar7 = 0x21, (uVar8 & 0xc000) != 0x4000)) &&
                       (uVar7 = 0x2c, (uVar8 & 0xc000) != 0x8000)) {
                      uVar7 = 3;
                    }
                    uVar1 = iVar3 - 0x87a;
                    uVar10 = 0x24;
                    if ((((uVar1 & 0xc000) != 0) && (uVar10 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
                       (uVar10 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
                      uVar10 = 3;
                    }
                    if (*(int *)((uint3)uVar7 << 0xe | (uint3)(uVar8 & 0x3fff)) != 0 ||
                        *(int *)((uint3)uVar10 << 0xe | (uint3)(uVar1 & 0x3fff)) != 0) {
                      uVar7 = 0x24;
                      if ((((uVar8 & 0xc000) != 0) && (uVar7 = 0x21, (uVar8 & 0xc000) != 0x4000)) &&
                         (uVar7 = 0x2c, (uVar8 & 0xc000) != 0x8000)) {
                        uVar7 = 3;
                      }
                      uVar10 = iVar3 - 0x87a;
                      uVar1 = 0x24;
                      if ((((uVar10 & 0xc000) != 0) && (uVar1 = 0x21, (uVar10 & 0xc000) != 0x4000))
                         && (uVar1 = 0x2c, (uVar10 & 0xc000) != 0x8000)) {
                        uVar1 = 3;
                      }
                      (*(code *)((uint3)*(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar10 & 0x3fff)) <<
                                 0x10 | (uint3)*(uint *)((uint3)uVar7 << 0xe |
                                                        (uint3)(uVar8 & 0x3fff))))();
                    }
                  }
                  else {
                    bRam00f44c = bRam00f44c + 1 & 0xf;
                    cRam00f44d = cRam00f44d + '\x01';
                    if (cRam00f44d == '\b') {
                      egs52_update_near_cab6_094840();
                      cRam00f44d = '\0';
                    }
                  }
                }
                else {
                  egs52_update_near_f878_09492a();
                }
              }
              else {
                egs52_update_near_f878_09492a();
              }
            }
          }
          else if ((cVar9 == '\x03') && (iRam00f444 == 2)) {
            iVar3 = (uint)bVar5 + iVar3;
            uVar7 = iVar3 - 0x873;
            uVar8 = 0x24;
            if (((uVar7 & 0xc000) != 0) &&
               ((uVar8 = 0x21, (uVar7 & 0xc000) != 0x4000 &&
                (uVar8 = 0x2c, (uVar7 & 0xc000) != 0x8000)))) {
              uVar8 = 3;
            }
            cVar9 = *(char *)((uint3)uVar8 << 0xe | (uint3)(uVar7 & 0x3fff));
            if (cVar9 == '0') {
              if (uRam00f45e < 0x1f) {
                uVar7 = Ram00fde8;
                if ((uVar7 & 8) != 0) {
                  iRam00f44a = 0;
                  uVar7 = Ram00fde8;
                  Ram00fde8 = uVar7 & 0xfff7;
                  uRam00f448 = uVar1;
                }
                Ram00cab6 = 0xffff;
                uVar7 = Ram00fde8;
                if ((uVar7 & 4) != 0) {
                  uVar7 = iVar3 - 0x872;
                  uVar8 = 0x24;
                  if ((((uVar7 & 0xc000) != 0) && (uVar8 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
                     (uVar8 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
                    uVar8 = 3;
                  }
                  bRam00f450 = *(byte *)((uint3)uVar8 << 0xe | (uint3)(uVar7 & 0x3fff));
                  uVar7 = iVar3 - 0x871;
                  uVar8 = 0x24;
                  if ((((uVar7 & 0xc000) != 0) && (uVar8 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
                     (uVar8 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
                    uVar8 = 3;
                  }
                  bRam00f44e = *(byte *)((uint3)uVar8 << 0xe | (uint3)(uVar7 & 0x3fff));
                  bRam00f44f = (byte)((bRam00f44e + 3) / 4);
                  uVar7 = Ram00fde8;
                  Ram00fde8 = uVar7 & 0xfffb;
                }
                bRam00f452 = 0;
                iRam00f444 = 6;
                uRam00f45e = (uint)bRam00f44e;
                egs52_update_near_cab6_09488a();
              }
              else {
                egs52_update_near_f878_09492a();
              }
            }
            else if (cVar9 == '1') {
              if (uRam00f45e < 0x1f) {
                uVar7 = Ram00fde8;
                if ((uVar7 & 8) != 0) {
                  iRam00f44a = 0;
                  uVar7 = Ram00fde8;
                  Ram00fde8 = uVar7 & 0xfff7;
                  uRam00f448 = uVar1;
                }
                uRam00f45e = 0;
                Ram00cab6 = 4;
              }
              else {
                egs52_update_near_f878_09492a();
              }
            }
          }
        }
      }
    }
  }
  return;
}


