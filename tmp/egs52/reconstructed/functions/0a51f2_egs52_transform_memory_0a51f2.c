/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a51f2; FLS offset 0x0251f2.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a529c) */
/* WARNING: Removing unreachable block (ram,0x0a5298) */
/* WARNING: Removing unreachable block (ram,0x0a528e) */
/* WARNING: Removing unreachable block (ram,0x0a5282) */
/* WARNING: Removing unreachable block (ram,0x0a527e) */
/* WARNING: Removing unreachable block (ram,0x0a527a) */
/* WARNING: Removing unreachable block (ram,0x0a5270) */
/* WARNING: Removing unreachable block (ram,0x0a5266) */
/* WARNING: Removing unreachable block (ram,0x0a5262) */
/* WARNING: Removing unreachable block (ram,0x0a5254) */
/* WARNING: Removing unreachable block (ram,0x0a53ae) */
/* WARNING: Removing unreachable block (ram,0x0a53aa) */
/* WARNING: Removing unreachable block (ram,0x0a5358) */
/* WARNING: Removing unreachable block (ram,0x0a534c) */
/* WARNING: Removing unreachable block (ram,0x0a5348) */
/* WARNING: Removing unreachable block (ram,0x0a5344) */
/* WARNING: Removing unreachable block (ram,0x0a533a) */
/* WARNING: Removing unreachable block (ram,0x0a537c) */
/* WARNING: Removing unreachable block (ram,0x0a5370) */
/* WARNING: Removing unreachable block (ram,0x0a536c) */
/* WARNING: Removing unreachable block (ram,0x0a5368) */
/* WARNING: Removing unreachable block (ram,0x0a535e) */
/* WARNING: Removing unreachable block (ram,0x0a53e8) */
/* WARNING: Removing unreachable block (ram,0x0a53e4) */
/* WARNING: Removing unreachable block (ram,0x0a53da) */
/* WARNING: Removing unreachable block (ram,0x0a53ce) */
/* WARNING: Removing unreachable block (ram,0x0a53ca) */
/* WARNING: Removing unreachable block (ram,0x0a53c0) */
/* WARNING: Removing unreachable block (ram,0x0a5310) */
/* WARNING: Removing unreachable block (ram,0x0a5304) */
/* WARNING: Removing unreachable block (ram,0x0a5302) */
/* WARNING: Removing unreachable block (ram,0x0a5300) */
/* WARNING: Removing unreachable block (ram,0x0a52fc) */
/* WARNING: Removing unreachable block (ram,0x0a52fa) */
/* WARNING: Removing unreachable block (ram,0x0a52ee) */
/* WARNING: Removing unreachable block (ram,0x0a52ec) */
/* WARNING: Removing unreachable block (ram,0x0a52ea) */
/* WARNING: Removing unreachable block (ram,0x0a52e0) */
/* WARNING: Removing unreachable block (ram,0x0a524a) */
/* WARNING: Removing unreachable block (ram,0x0a523e) */
/* WARNING: Removing unreachable block (ram,0x0a523c) */
/* WARNING: Removing unreachable block (ram,0x0a523a) */
/* WARNING: Removing unreachable block (ram,0x0a5236) */
/* WARNING: Removing unreachable block (ram,0x0a5234) */
/* WARNING: Removing unreachable block (ram,0x0a5228) */
/* WARNING: Removing unreachable block (ram,0x0a5226) */
/* WARNING: Removing unreachable block (ram,0x0a5224) */
/* WARNING: Removing unreachable block (ram,0x0a5220) */
/* WARNING: Removing unreachable block (ram,0x0a521a) */
/* WARNING: Removing unreachable block (ram,0x0a52e6) */
/* WARNING: Removing unreachable block (ram,0x0a525e) */
/* WARNING: Heritage AFTER dead removal. Example location: r0x0904d6 : 0x0a5368 */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void egs52_transform_memory_0a51f2(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined2 uVar4;
  undefined1 uVar5;
  char cVar6;
  uint uVar7;
  undefined1 uVar8;
  byte bStack_8;
  
  egs52_transform_memory_0a638a(0x8560,0xccfa);
  egs52_transform_memory_0a638a(0x8574,0xcd08);
  uVar7 = egs52_compute_from_near_f61e_0964d2();
  if ((uVar7 & 4) != 0) {
    uVar2 = uRam0904d6 + 2;
    uVar7 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar7 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar7 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar7 = 3;
    }
    uVar1 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) =
         *(uint *)((uint3)uVar7 << 0xe | (uint3)(uVar2 & 0x3fff)) & 0xfff7;
    uVar7 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar7 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar7 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar7 = 3;
    }
    uVar3 = Ram00ccfe;
    uVar1 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) =
         *(uint *)((uint3)uVar7 << 0xe | (uint3)(uVar2 & 0x3fff)) | (~uVar3 & 1) << 3;
    uVar7 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar7 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar7 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar7 = 3;
    }
    uVar1 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) =
         *(uint *)((uint3)uVar7 << 0xe | (uint3)(uVar2 & 0x3fff)) & 0xffef;
    uVar7 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar7 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar7 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar7 = 3;
    }
    uVar3 = Ram00cd02;
    uVar1 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) =
         *(uint *)((uint3)uVar7 << 0xe | (uint3)(uVar2 & 0x3fff)) | (~uVar3 & 1) << 4;
  }
  uVar7 = egs52_compute_from_near_f61e_0964d2();
  if ((uVar7 & 0x4000) == 0) {
    uVar7 = egs52_compute_from_near_f61e_0964d2();
    if ((((uVar7 & 1) != 0) || (uVar7 = egs52_compute_from_near_f61e_0964d2(), (uVar7 & 0x10) == 0))
       && (uVar7 = egs52_compute_from_near_f61e_0964d2(), (uVar7 & 2) != 0)) {
      uVar2 = uRam0904d6 + 2;
      uVar7 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar7 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar7 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar7 = 3;
      }
      uVar1 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) =
           *(uint *)((uint3)uVar7 << 0xe | (uint3)(uVar2 & 0x3fff)) & 0xfffd;
      uVar7 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar7 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar7 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar7 = 3;
      }
      uVar3 = Ram00cd0c;
      uVar1 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) =
           *(uint *)((uint3)uVar7 << 0xe | (uint3)(uVar2 & 0x3fff)) | (uVar3 >> 4 & 1) << 1;
      uVar7 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar7 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar7 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar7 = 3;
      }
      uVar1 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) =
           *(uint *)((uint3)uVar7 << 0xe | (uint3)(uVar2 & 0x3fff)) & 0xfffb;
      uVar7 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar7 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar7 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar7 = 3;
      }
      uVar3 = Ram00cd10;
      uVar1 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) =
           *(uint *)((uint3)uVar7 << 0xe | (uint3)(uVar2 & 0x3fff)) | (uVar3 >> 4 & 1) << 2;
    }
    uVar7 = egs52_compute_from_near_f61e_0964d2();
    if (((uVar7 & 0x11) == 0) || (cVar6 = egs52_match_fault_status_mask(0x11,1), cVar6 != '\0')) {
      uVar7 = egs52_compute_from_near_f61e_0964d2();
      if ((uVar7 & 1) != 0) {
        uVar4 = Ram00ccf0;
        uVar7 = uRam0904d6 + 1;
        uVar2 = 0x24;
        if ((((uVar7 & 0xc000) != 0) && (uVar2 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar7 & 0x3fff)) = (byte)uVar4 & 0xf;
      }
      uVar7 = egs52_compute_from_near_f61e_0964d2();
      if ((uVar7 & 0x10) != 0) {
        uVar4 = Ram00ccf0;
        uVar7 = uRam0904d6 + 1;
        uVar2 = 0x24;
        if ((((uVar7 & 0xc000) != 0) && (uVar2 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar7 & 0x3fff)) = (byte)uVar4 & 0x1f;
      }
      uVar4 = 0;
      uVar8 = 0;
      uVar5 = 0;
    }
    else {
      uVar7 = egs52_compute_from_near_f61e_0964d2();
      if ((uVar7 & 1) == 0) {
        uVar4 = Ram00ccf0;
        uVar7 = uRam0904d6 + 1;
        uVar2 = 0x24;
        if ((((uVar7 & 0xc000) != 0) && (uVar2 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar7 & 0x3fff)) = (byte)uVar4 & 0x1f;
        uVar7 = Ram00ccf4;
        uVar7 = (uVar7 & 0x1f) + 0x8520;
        uVar2 = 0x24;
        if ((((uVar7 & 0xc000) != 0) && (uVar2 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        cVar6 = *(char *)((uint3)uVar2 << 0xe | (uint3)(uVar7 & 0x3fff));
      }
      else {
        uVar4 = Ram00ccf0;
        uVar7 = uRam0904d6 + 1;
        uVar2 = 0x24;
        if ((((uVar7 & 0xc000) != 0) && (uVar2 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar7 & 0x3fff)) = (byte)uVar4 & 0xf;
        uVar7 = Ram00ccf4;
        uVar7 = (uVar7 & 0xf) + 0x8510;
        uVar2 = 0x24;
        if ((((uVar7 & 0xc000) != 0) && (uVar2 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        cVar6 = *(char *)((uint3)uVar2 << 0xe | (uint3)(uVar7 & 0x3fff));
      }
      if (cVar6 == '\x0f') {
        uVar8 = 3;
        uVar4 = 2;
        uVar5 = 2;
      }
      else if (cVar6 == '\0') {
        uVar4 = 3;
        uVar8 = 2;
        uVar5 = 2;
      }
      else if (cVar6 == '/') {
        uVar5 = 3;
        uVar4 = 2;
        uVar8 = 2;
      }
      else {
        uVar7 = 0x24;
        if ((((uRam0904d6 & 0xc000) != 0) && (uVar7 = 0x21, (uRam0904d6 & 0xc000) != 0x4000)) &&
           (uVar7 = 0x2c, (uRam0904d6 & 0xc000) != 0x8000)) {
          uVar7 = 3;
        }
        *(char *)((uint3)uVar7 << 0xe | (uint3)(uRam0904d6 & 0x3fff)) = cVar6;
        uVar4 = 2;
        uVar8 = 2;
        uVar5 = 2;
      }
    }
    uVar7 = egs52_compute_from_near_f61e_0964d2();
    if ((uVar7 & 0x11) == 0) {
      egs52_update_fault_status(0x11,0x40);
    }
    else {
      bStack_8 = egs52_update_fault_status(0x11,uVar4);
    }
    uVar7 = egs52_compute_from_near_f61e_0964d2();
    if ((uVar7 & 0x10) == 0) {
      egs52_update_fault_status(0x4c,0x40);
    }
    else {
      egs52_update_fault_status(0x4c,uVar5);
    }
    uVar7 = egs52_compute_from_near_f61e_0964d2();
    if ((uVar7 & 1) == 0) {
      egs52_update_fault_status(0x12,0x40);
    }
    else {
      egs52_update_fault_status(0x12,uVar8);
    }
    if ((bStack_8 & 4) != 0) {
      egs52_update_near_fd6c_0a10ec(0,0x946a);
    }
  }
  else {
    uVar4 = Ram00cd0c;
    uVar7 = uRam0904d6 + 1;
    uVar2 = 0x24;
    if ((((uVar7 & 0xc000) != 0) && (uVar2 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar7 & 0x3fff)) = (byte)uVar4 & 0x1f;
    uVar7 = Ram00cd10;
    uVar7 = (uVar7 & 7) + 0x8540;
    uVar2 = 0x24;
    if ((((uVar7 & 0xc000) != 0) && (uVar2 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    cVar6 = *(char *)((uint3)uVar2 << 0xe | (uint3)(uVar7 & 0x3fff));
    if (cVar6 != -1) {
      uVar7 = uRam0904d6 + 4;
      uVar2 = 0x24;
      if ((((uVar7 & 0xc000) != 0) && (uVar2 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      *(char *)((uint3)uVar2 << 0xe | (uint3)(uVar7 & 0x3fff)) = cVar6;
    }
    uVar7 = Ram00cd10;
    uVar7 = (uVar7 >> 3 & 3) + 0x8548;
    uVar2 = 0x24;
    if ((((uVar7 & 0xc000) != 0) && (uVar2 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    cVar6 = *(char *)((uint3)uVar2 << 0xe | (uint3)(uVar7 & 0x3fff));
    if (cVar6 != -1) {
      uVar7 = uRam0904d6 + 5;
      uVar2 = 0x24;
      if ((((uVar7 & 0xc000) != 0) && (uVar2 = 0x21, (uVar7 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar7 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      *(char *)((uint3)uVar2 << 0xe | (uint3)(uVar7 & 0x3fff)) = cVar6;
    }
    egs52_update_fault_status(0x11,0x40);
    egs52_update_fault_status(0x4c,0x40);
    egs52_update_fault_status(0x12,0x40);
  }
  return;
}


