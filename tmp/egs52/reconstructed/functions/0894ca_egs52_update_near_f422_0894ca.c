/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0894ca; FLS offset 0x0094ca.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0895f0) */
/* WARNING: Removing unreachable block (ram,0x0895ec) */
/* WARNING: Removing unreachable block (ram,0x0895e4) */
/* WARNING: Removing unreachable block (ram,0x0895ae) */
/* WARNING: Removing unreachable block (ram,0x0895a2) */
/* WARNING: Removing unreachable block (ram,0x089594) */
/* WARNING: Removing unreachable block (ram,0x08958e) */
/* WARNING: Removing unreachable block (ram,0x089586) */
/* WARNING: Removing unreachable block (ram,0x089582) */
/* WARNING: Removing unreachable block (ram,0x08957c) */
/* WARNING: Removing unreachable block (ram,0x089578) */
/* WARNING: Removing unreachable block (ram,0x089554) */
/* WARNING: Removing unreachable block (ram,0x089550) */
/* WARNING: Removing unreachable block (ram,0x089548) */
/* WARNING: Removing unreachable block (ram,0x089534) */
/* WARNING: Removing unreachable block (ram,0x08952e) */
/* WARNING: Removing unreachable block (ram,0x08952a) */
/* WARNING: Removing unreachable block (ram,0x089524) */
/* WARNING: Removing unreachable block (ram,0x089520) */
/* WARNING: Removing unreachable block (ram,0x089514) */
/* WARNING: Removing unreachable block (ram,0x089644) */
/* WARNING: Removing unreachable block (ram,0x08963e) */
/* WARNING: Removing unreachable block (ram,0x08963a) */
/* WARNING: Removing unreachable block (ram,0x08962e) */
/* WARNING: Removing unreachable block (ram,0x08962c) */
/* WARNING: Removing unreachable block (ram,0x089626) */
/* WARNING: Removing unreachable block (ram,0x089618) */
/* WARNING: Removing unreachable block (ram,0x08960c) */
/* WARNING: Removing unreachable block (ram,0x089602) */
/* WARNING: Removing unreachable block (ram,0x0895fc) */
/* WARNING: Removing unreachable block (ram,0x0895f8) */
/* WARNING: Removing unreachable block (ram,0x0894e6) */
/* WARNING: Removing unreachable block (ram,0x0894de) */
/* WARNING: Removing unreachable block (ram,0x0894d2) */
/* WARNING: Removing unreachable block (ram,0x089560) */
/* WARNING: Removing unreachable block (ram,0x0895c4) */
/* WARNING: Removing unreachable block (ram,0x0895ba) */

void egs52_update_near_f422_0894ca(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  byte bVar7;
  char cVar8;
  
  uVar2 = 0x24;
  if ((((param_1 & 0xc000) != 0) && (uVar2 = 0x21, (param_1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (param_1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  cVar8 = *(char *)((uint3)uVar2 << 0xe | (uint3)(param_1 & 0x3fff));
  if (cVar8 == '\0') {
    uVar3 = param_1 + 2;
    uVar2 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar2 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    if ((*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar3 & 0x3fff)) & 2) != 0) {
      cVar8 = '\n';
    }
    uVar2 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar2 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    if ((*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar3 & 0x3fff)) & 1) != 0) {
      cVar8 = '\v';
    }
  }
  if (cVar8 == '\x11') {
    uVar2 = param_1 + 2;
    uVar3 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar3 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    uVar1 = param_1 + 4;
    uVar4 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar4 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar4 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar4 = 3;
    }
    uVar3 = *(uint *)((uint3)(*(uint *)((uint3)uVar4 << 0xe | (uint3)(uVar1 & 0x3fff)) & 0x3ff) <<
                      0xe | (uint3)(*(int *)((uint3)uVar3 << 0xe | (uint3)(uVar2 & 0x3fff)) + 4U &
                                   0x3fff));
    uVar2 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar2 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    *(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar3 & 0x3fff)) = 0xfaff;
    egs52_register_sequence_089e70(uVar3 + 7,param_1 + 7,uRam00f438);
    uVar1 = uVar3 + 6;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    uVar4 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar4 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar4 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar4 = 3;
    }
    *(byte *)((uint3)uVar4 << 0xe | (uint3)(uVar1 & 0x3fff)) =
         *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) & 0xf;
    param_1 = param_1 + 6;
    uVar2 = 0x24;
    if ((((param_1 & 0xc000) != 0) && (uVar2 = 0x21, (param_1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (param_1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    uVar4 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar4 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar4 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar4 = 3;
    }
    uVar5 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar5 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar5 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar5 = 3;
    }
    *(byte *)((uint3)uVar5 << 0xe | (uint3)(uVar1 & 0x3fff)) =
         *(byte *)((uint3)uVar4 << 0xe | (uint3)(uVar1 & 0x3fff)) |
         *(char *)((uint3)uVar2 << 0xe | (uint3)(param_1 & 0x3fff)) << 4;
    uVar2 = 0x24;
    if ((((uVar3 & 0xc000) != 0) && (uVar2 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    *(undefined2 *)((uint3)uVar2 << 0xe | (uint3)(uVar3 & 0x3fff)) = 0xe7ff;
  }
  else if (cVar8 == '\v') {
    bVar7 = egs52_update_near_f186_08a00c(param_1 + 4);
    uRam00f422 = 0xc;
    iRam00f424 = *(int *)((uint3)((uint)bVar7 * 4 + 0x102a) | 0x88000);
    uRam00f426 = *(uint *)((uint3)((uint)bVar7 * 4 + 0x102c) | 0x88000);
    uRam00f428 = 3;
    egs52_update_near_f439_089650(0xf422);
    uVar2 = Ram00f186;
    Ram00f186 = uVar2 & 0xffbf;
    uVar2 = param_1 + 4;
    uVar3 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar3 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    if (*(int *)((uint3)uVar3 << 0xe | (uint3)(uVar2 & 0x3fff)) == 0) {
      param_1 = param_1 + 2;
      uVar2 = 0x24;
      if ((((param_1 & 0xc000) != 0) && (uVar2 = 0x21, (param_1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (param_1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      uVar3 = 0x24;
      if ((((param_1 & 0xc000) != 0) && (uVar3 = 0x21, (param_1 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (param_1 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      *(byte *)((uint3)uVar3 << 0xe | (uint3)(param_1 & 0x3fff)) =
           *(byte *)((uint3)uVar2 << 0xe | (uint3)(param_1 & 0x3fff)) & 0xfe;
    }
    uVar2 = Ram00f186;
    Ram00f186 = uVar2 | 0x40;
  }
  else if (cVar8 == '\n') {
    uRam00f422 = 0xd;
    bVar7 = egs52_update_near_f186_08a00c(param_1 + 6);
    iRam00f424 = *(int *)((uint3)((uint)bVar7 * 4 + 0x102a) | 0x88000);
    uRam00f426 = *(uint *)((uint3)((uint)bVar7 * 4 + 0x102c) | 0x88000);
    bVar6 = false;
    uVar2 = *(uint *)((uint3)(uRam00f426 & 0x3ff) << 0xe | (uint3)(iRam00f424 + 4U & 0x3fff));
    uRam00f428 = (undefined1)
                 ((int)(*(byte *)((uint3)(uRam00f426 & 0x3ff) << 0xe | (uint3)(uVar2 + 6 & 0x3fff))
                       & 0xf0) >> 4);
    while( true ) {
      uVar3 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar3 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      if ((*(uint *)((uint3)uVar3 << 0xe | (uint3)(uVar2 & 0x3fff)) | 0xfcff) != 0xfeff) break;
      bVar6 = true;
      uVar3 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar3 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      *(undefined2 *)((uint3)uVar3 << 0xe | (uint3)(uVar2 & 0x3fff)) = 0xfdff;
      egs52_register_sequence_089e70(0xf429,uVar2 + 7,uRam00f428);
    }
    if (bVar6) {
      egs52_update_near_f439_089650(0xf422);
    }
    uVar2 = Ram00f186;
    Ram00f186 = uVar2 & 0xffbf;
    uVar2 = param_1 + 6;
    uVar3 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar3 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    if (*(int *)((uint3)uVar3 << 0xe | (uint3)(uVar2 & 0x3fff)) == 0) {
      param_1 = param_1 + 2;
      uVar2 = 0x24;
      if ((((param_1 & 0xc000) != 0) && (uVar2 = 0x21, (param_1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (param_1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      uVar3 = 0x24;
      if ((((param_1 & 0xc000) != 0) && (uVar3 = 0x21, (param_1 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (param_1 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      *(byte *)((uint3)uVar3 << 0xe | (uint3)(param_1 & 0x3fff)) =
           *(byte *)((uint3)uVar2 << 0xe | (uint3)(param_1 & 0x3fff)) & 0xfd;
    }
    uVar2 = Ram00f186;
    Ram00f186 = uVar2 | 0x40;
  }
  return;
}


