/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a4270; FLS offset 0x024270.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Function: egs52_call_far_indirect replaced with injection: call_far_indirect */
/* WARNING: Removing unreachable block (ram,0x0a429e) */
/* WARNING: Removing unreachable block (ram,0x0a429a) */
/* WARNING: Removing unreachable block (ram,0x0a428c) */
/* WARNING: Removing unreachable block (ram,0x0a427e) */
/* WARNING: Removing unreachable block (ram,0x0a433e) */
/* WARNING: Removing unreachable block (ram,0x0a433a) */
/* WARNING: Removing unreachable block (ram,0x0a4336) */
/* WARNING: Removing unreachable block (ram,0x0a4330) */
/* WARNING: Removing unreachable block (ram,0x0a432c) */
/* WARNING: Removing unreachable block (ram,0x0a43ce) */
/* WARNING: Removing unreachable block (ram,0x0a43c8) */
/* WARNING: Removing unreachable block (ram,0x0a43c0) */
/* WARNING: Removing unreachable block (ram,0x0a43b6) */
/* WARNING: Removing unreachable block (ram,0x0a43b2) */
/* WARNING: Removing unreachable block (ram,0x0a4398) */
/* WARNING: Removing unreachable block (ram,0x0a4392) */
/* WARNING: Removing unreachable block (ram,0x0a438e) */
/* WARNING: Removing unreachable block (ram,0x0a438a) */
/* WARNING: Removing unreachable block (ram,0x0a4388) */
/* WARNING: Removing unreachable block (ram,0x0a4384) */
/* WARNING: Removing unreachable block (ram,0x0a4380) */
/* WARNING: Removing unreachable block (ram,0x0a437e) */
/* WARNING: Removing unreachable block (ram,0x0a4378) */
/* WARNING: Removing unreachable block (ram,0x0a43aa) */
/* WARNING: Removing unreachable block (ram,0x0a43a4) */
/* WARNING: Removing unreachable block (ram,0x0a439e) */
/* WARNING: Removing unreachable block (ram,0x0a436e) */
/* WARNING: Removing unreachable block (ram,0x0a436a) */
/* WARNING: Removing unreachable block (ram,0x0a4362) */
/* WARNING: Removing unreachable block (ram,0x0a435e) */
/* WARNING: Removing unreachable block (ram,0x0a4356) */
/* WARNING: Removing unreachable block (ram,0x0a431a) */
/* WARNING: Removing unreachable block (ram,0x0a4316) */
/* WARNING: Removing unreachable block (ram,0x0a430e) */
/* WARNING: Removing unreachable block (ram,0x0a42fc) */
/* WARNING: Removing unreachable block (ram,0x0a42e6) */
/* WARNING: Removing unreachable block (ram,0x0a42e2) */
/* WARNING: Removing unreachable block (ram,0x0a42da) */
/* WARNING: Removing unreachable block (ram,0x0a42d6) */
/* WARNING: Removing unreachable block (ram,0x0a4414) */
/* WARNING: Removing unreachable block (ram,0x0a440c) */
/* WARNING: Removing unreachable block (ram,0x0a43fe) */
/* WARNING: Removing unreachable block (ram,0x0a43fa) */
/* WARNING: Removing unreachable block (ram,0x0a43f2) */
/* WARNING: Removing unreachable block (ram,0x0a43e6) */
/* WARNING: Removing unreachable block (ram,0x0a43e2) */
/* WARNING: Removing unreachable block (ram,0x0a43da) */
/* WARNING: Removing unreachable block (ram,0x0a4282) */
/* WARNING: Heritage AFTER dead removal. Example location: r0x00f444 : 0x0a4356 */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void egs52_update_near_f5b0_0a4270(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  char cVar5;
  
  uVar1 = Ram00fde8;
  if ((uVar1 & 1) == 0) {
    uVar1 = Ram00fdea;
    if ((uVar1 & 1) != 0) {
      uVar1 = Ram00fdea;
      uVar2 = Ram00fdea;
      uVar3 = Ram00fdea;
      cVar5 = (char)((uVar1 & 4) >> 2);
      if (((uVar3 & 2) == 0) &&
         ((uVar1 = Ram00fdea, (uVar1 & 4) == 0 || (uVar1 = Ram00fdea, (uVar1 & 8) == 0)))) {
        if (cVar5 == '\0') {
          uVar1 = Ram00fdea;
          uVar2 = Ram00fdea;
          Ram00fdea = uVar2 & 0xfffe | (uVar1 & 2) >> 1;
          if (iRam00f444 == 3) {
            iRam00f444 = 0;
          }
        }
        else {
          if (iRam00f444 == 0) {
            iRam00f444 = 3;
          }
          if (iRam00f444 == 3) {
            bRam00f582 = bRam00f582 & 0xbf;
            (*(code *)((uint3)uRam080212 << 0x10 | (uint3)uRam080210))();
          }
        }
      }
      else {
        uVar1 = Ram00fdea;
        if ((uVar1 & 2) == 0) {
          uVar1 = Ram00fdea;
          if (((uVar1 & 4) != 0) && (uVar1 = Ram00fdea, (uVar1 & 8) != 0)) {
            bRam00f582 = bRam00f582 & 0xbf;
            (*(code *)((uint3)uRam080212 << 0x10 | (uint3)uRam080210))();
          }
        }
        else {
          uVar1 = Ram00fdea;
          if ((uVar1 & 0x1000) == 0) {
            uRam00f462 = uRam00f464;
            (*(code *)((uint3)uRam080212 << 0x10 | (uint3)uRam080210))();
          }
          else {
            uVar1 = Ram00fdea;
            Ram00fdea = uVar1 & 0xefff;
            cRam00f581 = '\x10';
          }
        }
        bVar4 = bRam00f469;
        uVar1 = Ram00fdec;
        if ((uVar1 & 4) == 0) {
          if ((cVar5 == '\0') || ((cVar5 != '\0' && ((char)((uVar2 & 8) >> 3) != '\0')))) {
            if (iRam00f444 == 0) {
              iRam00f444 = 3;
            }
            if (iRam00f444 == 3) {
              if (cRam00f581 == '\0') {
                uVar2 = uRam00f464 - 1;
                uVar1 = 0x24;
                if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
                   (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
                  uVar1 = 3;
                }
                *(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) = bRam00f582 | 0x40;
              }
              else {
                uVar2 = uRam00f464 - 1;
                uVar1 = 0x24;
                if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
                   (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
                  uVar1 = 3;
                }
                *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) = 0x7f;
                uVar1 = 0x24;
                if ((((uRam00f464 & 0xc000) != 0) && (uVar1 = 0x21, (uRam00f464 & 0xc000) != 0x4000)
                    ) && (uVar1 = 0x2c, (uRam00f464 & 0xc000) != 0x8000)) {
                  uVar1 = 3;
                }
                *(byte *)((uint3)uVar1 << 0xe | (uint3)(uRam00f464 & 0x3fff)) = bRam00f582;
                uVar1 = uRam00f464 + 1;
                uVar2 = 0x24;
                if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
                   (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
                  uVar2 = 3;
                }
                *(char *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) = cRam00f581;
                bRam00f469 = 3;
              }
              egs52_update_near_f456_0a460c();
              if (cRam00f581 == 'x') {
                uRam00f464 = uRam00f464 - bVar4;
                iRam00f444 = 3;
              }
            }
          }
        }
        else {
          uVar1 = Ram00fdec;
          Ram00fdec = uVar1 & 0xfffb;
          uVar1 = Ram00fdea;
          if ((uVar1 & 2) != 0) {
            uRam00f464 = uRam00f462;
            iRam00f454 = uRam00f462 - 1;
            iRam00f444 = 0;
            iRam00f456 = iRam00f454;
          }
        }
        uVar1 = Ram00fdea;
        Ram00fdea = uVar1 & 0xfffd;
        bRam00f469 = bVar4;
      }
    }
  }
  else {
    (*(code *)((uint3)uRam080212 << 0x10 | (uint3)uRam080210))();
    uRam00f5b0 = 1;
    uVar1 = Ram00fdea;
    if ((uVar1 & 0x800) != 0) {
      uVar1 = Ram00fdea;
      Ram00fdea = uVar1 & 0xf7ff;
      Ram00f878 = uRam00f574;
    }
  }
  return;
}


