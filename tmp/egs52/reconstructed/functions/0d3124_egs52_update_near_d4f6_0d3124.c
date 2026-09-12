/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0d3124; FLS offset 0x053124.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0d33de) */
/* WARNING: Removing unreachable block (ram,0x0d33d4) */
/* WARNING: Removing unreachable block (ram,0x0d33d0) */
/* WARNING: Removing unreachable block (ram,0x0d333e) */
/* WARNING: Removing unreachable block (ram,0x0d3328) */
/* WARNING: Removing unreachable block (ram,0x0d3324) */
/* WARNING: Removing unreachable block (ram,0x0d3364) */
/* WARNING: Removing unreachable block (ram,0x0d3354) */
/* WARNING: Removing unreachable block (ram,0x0d3350) */
/* WARNING: Removing unreachable block (ram,0x0d334c) */
/* WARNING: Removing unreachable block (ram,0x0d331a) */
/* WARNING: Removing unreachable block (ram,0x0d3312) */
/* WARNING: Removing unreachable block (ram,0x0d330a) */
/* WARNING: Removing unreachable block (ram,0x0d3304) */
/* WARNING: Removing unreachable block (ram,0x0d32fa) */
/* WARNING: Removing unreachable block (ram,0x0d32e2) */
/* WARNING: Removing unreachable block (ram,0x0d32d2) */
/* WARNING: Removing unreachable block (ram,0x0d32ce) */
/* WARNING: Removing unreachable block (ram,0x0d32ca) */
/* WARNING: Removing unreachable block (ram,0x0d32c6) */
/* WARNING: Removing unreachable block (ram,0x0d32bc) */
/* WARNING: Removing unreachable block (ram,0x0d32b4) */
/* WARNING: Removing unreachable block (ram,0x0d32ae) */
/* WARNING: Removing unreachable block (ram,0x0d32a8) */
/* WARNING: Removing unreachable block (ram,0x0d328c) */
/* WARNING: Removing unreachable block (ram,0x0d327e) */
/* WARNING: Removing unreachable block (ram,0x0d3276) */
/* WARNING: Removing unreachable block (ram,0x0d326c) */
/* WARNING: Removing unreachable block (ram,0x0d325c) */
/* WARNING: Removing unreachable block (ram,0x0d3252) */
/* WARNING: Removing unreachable block (ram,0x0d324c) */
/* WARNING: Removing unreachable block (ram,0x0d3238) */
/* WARNING: Removing unreachable block (ram,0x0d3230) */
/* WARNING: Removing unreachable block (ram,0x0d3226) */
/* WARNING: Removing unreachable block (ram,0x0d3218) */
/* WARNING: Removing unreachable block (ram,0x0d3212) */
/* WARNING: Removing unreachable block (ram,0x0d320e) */
/* WARNING: Removing unreachable block (ram,0x0d31f6) */
/* WARNING: Removing unreachable block (ram,0x0d31e8) */
/* WARNING: Removing unreachable block (ram,0x0d31dc) */
/* WARNING: Removing unreachable block (ram,0x0d31d2) */
/* WARNING: Removing unreachable block (ram,0x0d31c2) */
/* WARNING: Removing unreachable block (ram,0x0d31b8) */
/* WARNING: Removing unreachable block (ram,0x0d31b2) */
/* WARNING: Removing unreachable block (ram,0x0d31a2) */
/* WARNING: Removing unreachable block (ram,0x0d319c) */
/* WARNING: Removing unreachable block (ram,0x0d3198) */
/* WARNING: Removing unreachable block (ram,0x0d33c8) */
/* WARNING: Removing unreachable block (ram,0x0d33be) */
/* WARNING: Removing unreachable block (ram,0x0d33b6) */
/* WARNING: Removing unreachable block (ram,0x0d33ac) */
/* WARNING: Removing unreachable block (ram,0x0d339c) */
/* WARNING: Removing unreachable block (ram,0x0d3392) */
/* WARNING: Removing unreachable block (ram,0x0d338c) */
/* WARNING: Removing unreachable block (ram,0x0d3378) */
/* WARNING: Removing unreachable block (ram,0x0d3370) */
/* WARNING: Removing unreachable block (ram,0x0d336a) */
/* WARNING: Removing unreachable block (ram,0x0d318e) */
/* WARNING: Removing unreachable block (ram,0x0d3186) */
/* WARNING: Removing unreachable block (ram,0x0d317e) */
/* WARNING: Removing unreachable block (ram,0x0d3170) */
/* WARNING: Removing unreachable block (ram,0x0d316a) */
/* WARNING: Removing unreachable block (ram,0x0d3166) */
/* WARNING: Removing unreachable block (ram,0x0d3138) */
/* WARNING: Removing unreachable block (ram,0x0d3134) */
/* WARNING: Removing unreachable block (ram,0x0d3130) */
/* WARNING: Removing unreachable block (ram,0x0d312c) */
/* WARNING: Removing unreachable block (ram,0x0d3176) */
/* WARNING: Removing unreachable block (ram,0x0d318a) */
/* WARNING: Removing unreachable block (ram,0x0d3374) */
/* WARNING: Removing unreachable block (ram,0x0d337c) */
/* WARNING: Removing unreachable block (ram,0x0d3396) */
/* WARNING: Removing unreachable block (ram,0x0d33ba) */
/* WARNING: Removing unreachable block (ram,0x0d31bc) */
/* WARNING: Removing unreachable block (ram,0x0d31e0) */
/* WARNING: Removing unreachable block (ram,0x0d31ec) */
/* WARNING: Removing unreachable block (ram,0x0d321e) */
/* WARNING: Removing unreachable block (ram,0x0d3234) */
/* WARNING: Removing unreachable block (ram,0x0d323c) */
/* WARNING: Removing unreachable block (ram,0x0d3256) */
/* WARNING: Removing unreachable block (ram,0x0d327a) */
/* WARNING: Removing unreachable block (ram,0x0d3282) */
/* WARNING: Removing unreachable block (ram,0x0d32a4) */
/* WARNING: Removing unreachable block (ram,0x0d32fe) */
/* WARNING: Removing unreachable block (ram,0x0d3346) */
/* WARNING: Removing unreachable block (ram,0x0d332e) */

void egs52_update_near_d4f6_0d3124(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  short sVar5;
  short x1;
  short sVar6;
  int iVar7;
  byte bVar8;
  char cVar9;
  ushort uVar10;
  ushort uVar11;
  
  iVar7 = Ram00f62e;
  uVar1 = iVar7 + 0x10;
  uVar3 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar3 = 3;
  }
  sVar5 = *(short *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff));
  uVar1 = iVar7 + 0xe;
  uVar3 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar3 = 3;
  }
  x1 = *(short *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff));
  cVar9 = UNK_00d577;
  if (cVar9 == '\x01') {
    egs52_update_d7d8_from_byte_delta('\x06','\x01',0xd30c);
    uVar2 = Ram00d500;
    bVar8 = UNK_00d454;
    iVar7 = Ram00f624;
    uVar1 = iVar7 + (uint)bVar8 * 2 + 4;
    uVar3 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    sVar6 = (short)(((ulong)uVar2 * (ulong)*(uint *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)))
                   / 1000);
    Ram00d4f6 = sVar6;
    iVar7 = Ram00f62e;
    uVar1 = iVar7 + 10;
    uVar3 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    iVar7 = Ram00d4c2;
    if (*(int *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)) < iVar7) {
      sVar6 = Ram00d4f6;
      uVar3 = Ram00d7d8;
      uVar1 = 0x24;
      if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      iVar7 = Ram00d7d8;
      uVar2 = iVar7 + 1;
      uVar4 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar4 = 3;
      }
      uVar10 = egs52_lerp_signed_registers
                         ((int)*(char *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)),
                          (int)*(char *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff)),sVar5,x1,
                          sVar6);
      sVar6 = Ram00d4f6;
      iVar7 = Ram00d7d8;
      uVar1 = iVar7 + 2;
      uVar3 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      uVar2 = iVar7 + 3;
      uVar4 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar4 = 3;
      }
      uVar11 = egs52_lerp_signed_registers
                         ((int)*(char *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)),
                          (int)*(char *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff)),sVar5,x1,
                          sVar6);
      sVar5 = Ram00d4c2;
      iVar7 = Ram00f62e;
      uVar1 = iVar7 + 10;
      uVar3 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      uVar2 = iVar7 + 0xc;
      uVar4 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar4 = 3;
      }
      uVar10 = egs52_lerp_signed_registers
                         (uVar11,uVar10,*(short *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)),
                          *(short *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff)),sVar5);
      Ram00d47c = uVar10;
    }
    else {
      iVar7 = Ram00d7d8;
      uVar1 = iVar7 + 2;
      uVar3 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      uVar2 = iVar7 + 3;
      uVar4 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar4 = 3;
      }
      uVar10 = egs52_lerp_signed_registers
                         ((int)*(char *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)),
                          (int)*(char *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff)),sVar5,x1,
                          sVar6);
      sVar6 = Ram00d4f6;
      iVar7 = Ram00d7d8;
      uVar1 = iVar7 + 4;
      uVar3 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      uVar2 = iVar7 + 5;
      uVar4 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar4 = 3;
      }
      uVar11 = egs52_lerp_signed_registers
                         ((int)*(char *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)),
                          (int)*(char *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff)),sVar5,x1,
                          sVar6);
      sVar5 = Ram00d4c2;
      iVar7 = Ram00f634;
      uVar1 = iVar7 + 0x2c;
      uVar3 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      iVar7 = Ram00f62e;
      uVar2 = iVar7 + 10;
      uVar4 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar4 = 3;
      }
      uVar10 = egs52_lerp_signed_registers
                         (uVar11,uVar10,-*(int *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)),
                          *(short *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff)),sVar5);
      Ram00d47c = uVar10;
    }
  }
  else if (cVar9 == '\x03') {
    egs52_update_d7d8_from_byte_delta('\x04','\x05',0xd32c);
    uVar2 = Ram00d500;
    bVar8 = UNK_00d454;
    iVar7 = Ram00f624;
    uVar1 = iVar7 + (uint)bVar8 * 2 + 6;
    uVar3 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    sVar6 = (short)(((ulong)uVar2 * (ulong)*(uint *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)))
                   / 1000);
    Ram00d4f6 = sVar6;
    uVar3 = Ram00d7d8;
    uVar1 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    iVar7 = Ram00d7d8;
    uVar2 = iVar7 + 1;
    uVar4 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar4 = 3;
    }
    uVar10 = egs52_lerp_signed_registers
                       ((int)*(char *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)),
                        (int)*(char *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff)),sVar5,x1,sVar6
                       );
    sVar6 = Ram00d4f6;
    iVar7 = Ram00d7d8;
    uVar1 = iVar7 + 2;
    uVar3 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    uVar2 = iVar7 + 3;
    uVar4 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar4 = 3;
    }
    uVar11 = egs52_lerp_signed_registers
                       ((int)*(char *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)),
                        (int)*(char *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff)),sVar5,x1,sVar6
                       );
    sVar5 = Ram00d4c2;
    iVar7 = Ram00f634;
    uVar1 = iVar7 + 0x2e;
    uVar3 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    iVar7 = Ram00f62e;
    uVar2 = iVar7 + 0xc;
    uVar4 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar4 = 3;
    }
    uVar10 = egs52_lerp_signed_registers
                       (uVar11,uVar10,*(short *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)),
                        *(short *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff)),sVar5);
    Ram00d47c = uVar10;
  }
  else if (cVar9 == '\x02') {
    egs52_update_d7d8_from_byte_delta('\x02','\x01',0xd324);
    uVar2 = Ram00d500;
    bVar8 = UNK_00d454;
    iVar7 = Ram00f624;
    uVar1 = iVar7 + (uint)bVar8 * 2 + 4;
    uVar3 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    sVar6 = (short)(((ulong)uVar2 * (ulong)*(uint *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)))
                   / 1000);
    Ram00d4f6 = sVar6;
    uVar3 = Ram00d7d8;
    uVar1 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    iVar7 = Ram00d7d8;
    uVar2 = iVar7 + 1;
    uVar4 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar4 = 3;
    }
    uVar10 = egs52_lerp_signed_registers
                       ((int)*(char *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)),
                        (int)*(char *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff)),sVar5,x1,sVar6
                       );
    Ram00d47c = uVar10;
  }
  else if (cVar9 == '\x04') {
    egs52_update_d7d8_from_byte_delta('\x04','\x05',0xd33c);
    uVar2 = Ram00d500;
    bVar8 = UNK_00d454;
    iVar7 = Ram00f624;
    uVar1 = iVar7 + (uint)bVar8 * 2 + 6;
    uVar3 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    sVar6 = (short)(((ulong)uVar2 * (ulong)*(uint *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)))
                   / 1000);
    Ram00d4f6 = sVar6;
    iVar7 = Ram00d4c2;
    if (iVar7 < 0) {
      iVar7 = Ram00d7d8;
      uVar1 = iVar7 + 2;
      uVar3 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      uVar2 = iVar7 + 3;
      uVar4 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar4 = 3;
      }
      uVar10 = egs52_lerp_signed_registers
                         ((int)*(char *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)),
                          (int)*(char *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff)),sVar5,x1,
                          sVar6);
      Ram00d47c = uVar10;
    }
    else {
      sVar6 = Ram00d4f6;
      uVar3 = Ram00d7d8;
      uVar1 = 0x24;
      if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      uVar2 = uVar3 + 1;
      uVar4 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar4 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar4 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar4 = 3;
      }
      uVar10 = egs52_lerp_signed_registers
                         ((int)*(char *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)),
                          (int)*(char *)((uint3)uVar4 << 0xe | (uint3)(uVar2 & 0x3fff)),sVar5,x1,
                          sVar6);
      Ram00d47c = uVar10;
    }
  }
  uVar1 = Ram00fd4a;
  if ((uVar1 & 0x20) != 0) {
    Ram00d47c = 0;
  }
  iVar7 = Ram00d47c;
  Ram00d47c = iVar7 * 3;
  return;
}


