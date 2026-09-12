/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a2fba; FLS offset 0x022fba.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x0a30dc) */
/* WARNING: Removing unreachable block (ram,0x0a30b8) */
/* WARNING: Removing unreachable block (ram,0x0a30a8) */
/* WARNING: Removing unreachable block (ram,0x0a3090) */
/* WARNING: Removing unreachable block (ram,0x0a3028) */
/* WARNING: Removing unreachable block (ram,0x0a301e) */
/* WARNING: Removing unreachable block (ram,0x0a334a) */
/* WARNING: Removing unreachable block (ram,0x0a3330) */
/* WARNING: Removing unreachable block (ram,0x0a332a) */
/* WARNING: Removing unreachable block (ram,0x0a3320) */
/* WARNING: Removing unreachable block (ram,0x0a331c) */
/* WARNING: Removing unreachable block (ram,0x0a3310) */
/* WARNING: Removing unreachable block (ram,0x0a3306) */
/* WARNING: Removing unreachable block (ram,0x0a32ec) */
/* WARNING: Removing unreachable block (ram,0x0a32e2) */
/* WARNING: Removing unreachable block (ram,0x0a32dc) */
/* WARNING: Removing unreachable block (ram,0x0a32d2) */
/* WARNING: Removing unreachable block (ram,0x0a32c8) */
/* WARNING: Removing unreachable block (ram,0x0a32c6) */
/* WARNING: Removing unreachable block (ram,0x0a32be) */
/* WARNING: Removing unreachable block (ram,0x0a32b4) */
/* WARNING: Removing unreachable block (ram,0x0a32b0) */
/* WARNING: Removing unreachable block (ram,0x0a32ac) */
/* WARNING: Removing unreachable block (ram,0x0a32aa) */
/* WARNING: Removing unreachable block (ram,0x0a32a2) */
/* WARNING: Removing unreachable block (ram,0x0a329e) */
/* WARNING: Removing unreachable block (ram,0x0a3296) */
/* WARNING: Removing unreachable block (ram,0x0a3290) */
/* WARNING: Removing unreachable block (ram,0x0a328e) */
/* WARNING: Removing unreachable block (ram,0x0a328a) */
/* WARNING: Removing unreachable block (ram,0x0a3276) */
/* WARNING: Removing unreachable block (ram,0x0a3254) */
/* WARNING: Removing unreachable block (ram,0x0a323e) */
/* WARNING: Removing unreachable block (ram,0x0a323a) */
/* WARNING: Removing unreachable block (ram,0x0a3220) */
/* WARNING: Removing unreachable block (ram,0x0a3206) */
/* WARNING: Removing unreachable block (ram,0x0a3202) */
/* WARNING: Removing unreachable block (ram,0x0a31f6) */
/* WARNING: Removing unreachable block (ram,0x0a31f0) */
/* WARNING: Removing unreachable block (ram,0x0a31e6) */
/* WARNING: Removing unreachable block (ram,0x0a31d0) */
/* WARNING: Removing unreachable block (ram,0x0a31c6) */
/* WARNING: Removing unreachable block (ram,0x0a31c0) */
/* WARNING: Removing unreachable block (ram,0x0a31b6) */
/* WARNING: Removing unreachable block (ram,0x0a31b4) */
/* WARNING: Removing unreachable block (ram,0x0a319c) */
/* WARNING: Removing unreachable block (ram,0x0a3186) */
/* WARNING: Removing unreachable block (ram,0x0a3182) */
/* WARNING: Removing unreachable block (ram,0x0a3176) */
/* WARNING: Removing unreachable block (ram,0x0a3170) */
/* WARNING: Removing unreachable block (ram,0x0a3166) */
/* WARNING: Removing unreachable block (ram,0x0a314c) */
/* WARNING: Removing unreachable block (ram,0x0a3140) */
/* WARNING: Removing unreachable block (ram,0x0a313a) */
/* WARNING: Removing unreachable block (ram,0x0a3130) */
/* WARNING: Removing unreachable block (ram,0x0a312e) */
/* WARNING: Removing unreachable block (ram,0x0a3112) */
/* WARNING: Removing unreachable block (ram,0x0a3104) */
/* WARNING: Removing unreachable block (ram,0x0a339a) */
/* WARNING: Removing unreachable block (ram,0x0a3352) */
/* WARNING: Removing unreachable block (ram,0x0a30e8) */
/* WARNING: Removing unreachable block (ram,0x0a2fde) */
/* WARNING: Removing unreachable block (ram,0x0a2fd6) */
/* WARNING: Removing unreachable block (ram,0x0a2fca) */
/* WARNING: Removing unreachable block (ram,0x0a30c2) */

undefined2 egs52_update_near_caa4_0a2fba(byte param_1,uchar *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  char cVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  undefined2 uVar10;
  int iVar11;
  int iStack_12;
  int iStack_10;
  int iStack_e;
  int iStack_c;
  
  cVar5 = UNK_00caa4;
  if (cVar5 != '\0') {
    return 0;
  }
  UNK_00caa4 = 1;
  iVar7 = (uint)param_1 * 8;
  cVar5 = *(char *)((uint3)(iVar7 + 0x7f2) | 0x90000);
  if (cVar5 == '\x01') {
    iStack_12 = egs52_update_near_f876_0a3f66(0xc);
    if (iStack_12 == 0) {
      UNK_00caa4 = 0;
      return 0;
    }
    iStack_10 = egs52_update_near_f876_0a3f66(0xc);
    if (iStack_10 == 0) {
      egs52_free_small_heap_block(iStack_12);
      UNK_00caa4 = 0;
      return 0;
    }
  }
  else if (cVar5 == '\x02') {
    iStack_12 = egs52_update_near_f876_0a3f66(0xc);
    if (iStack_12 == 0) {
      UNK_00caa4 = 0;
      return 0;
    }
    iStack_10 = egs52_update_near_f876_0a3f66(0xc);
    if (iStack_10 == 0) {
      egs52_free_small_heap_block(iStack_12);
      UNK_00caa4 = 0;
      return 0;
    }
    iStack_e = egs52_update_near_f876_0a3f66(0xc);
    if (iStack_e == 0) {
      egs52_free_small_heap_block(iStack_12);
      egs52_free_small_heap_block(iStack_10);
      UNK_00caa4 = 0;
      return 0;
    }
    iStack_c = egs52_update_near_f876_0a3f66(0xc);
    if (iStack_c == 0) {
      egs52_free_small_heap_block(iStack_12);
      egs52_free_small_heap_block(iStack_10);
      egs52_free_small_heap_block(iStack_e);
      UNK_00caa4 = 0;
      return 0;
    }
  }
  else if ((cVar5 == '\x03') && (iStack_12 = egs52_update_near_f876_0a3f66(0xc), iStack_12 == 0)) {
    UNK_00caa4 = 0;
    return 0;
  }
  uVar9 = egs52_update_near_f876_0a3f66(*(undefined2 *)((uint3)(iVar7 + 0x7f4) | 0x90000));
  if (uVar9 == 0) {
    cVar5 = *(char *)((uint3)(iVar7 + 0x7f2) | 0x90000);
    if (cVar5 == '\x01') {
      egs52_free_small_heap_block(iStack_12);
      egs52_free_small_heap_block(iStack_10);
    }
    else if (cVar5 == '\x02') {
      egs52_free_small_heap_block(iStack_12);
      egs52_free_small_heap_block(iStack_10);
      egs52_free_small_heap_block(iStack_e);
      egs52_free_small_heap_block(iStack_c);
    }
    else if (cVar5 == '\x03') {
      egs52_free_small_heap_block(iStack_12);
    }
    UNK_00caa4 = 0;
    uVar10 = 0;
  }
  else {
    egs52_memcpy_near((uchar *)(uVar9 + 4),param_2,*(int *)((uint3)(iVar7 + 0x7f4) | 0x90000) - 4);
    cVar5 = *(char *)((uint3)(iVar7 + 0x7f2) | 0x90000);
    if (cVar5 == '\x01') {
      uVar1 = 0x24;
      if ((((uVar9 & 0xc000) != 0) && (uVar1 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar9 & 0x3fff)) = 0xaa;
      uVar1 = uVar9 + 1;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) = param_1;
      uVar2 = uVar9 + 2;
      uVar1 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) = 0;
      uVar6 = uVar9 + 3;
      uVar1 = 0x24;
      if ((((uVar6 & 0xc000) != 0) && (uVar1 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar6 & 0x3fff)) = 0;
      uVar10 = egs52_call_092118_0a3d74(uVar9,*(undefined2 *)((uint3)(iVar7 + 0x7f4) | 0x90000));
      uVar1 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(char *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) = (char)uVar10;
      uVar1 = 0x24;
      if ((((uVar6 & 0xc000) != 0) && (uVar1 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(char *)((uint3)uVar1 << 0xe | (uint3)(uVar6 & 0x3fff)) = (char)((uint)uVar10 >> 8);
      uVar1 = 0x24;
      if ((((uVar9 & 0xc000) != 0) && (uVar1 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar9 & 0x3fff)) = 0x55;
      egs52_update_near_c166_097172
                (uVar9,*(undefined2 *)((uint3)(iVar7 + 0x7f0) | 0x90000),
                 *(undefined2 *)((uint3)(iVar7 + 0x7f4) | 0x90000),1,iStack_12);
      uVar10 = egs52_update_near_c166_097172
                         (0xf852,*(undefined2 *)((uint3)(iVar7 + 0x7f0) | 0x90000),1,0,iStack_10);
    }
    else if (cVar5 == '\x02') {
      uVar1 = 0x24;
      if ((((uVar9 & 0xc000) != 0) && (uVar1 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar9 & 0x3fff)) = 0xaa;
      uVar1 = uVar9 + 1;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      *(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) = param_1;
      uVar2 = uVar9 + 2;
      uVar1 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) = 0;
      uVar6 = uVar9 + 3;
      uVar1 = 0x24;
      if ((((uVar6 & 0xc000) != 0) && (uVar1 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar6 & 0x3fff)) = 0;
      uVar10 = egs52_call_092118_0a3d74(uVar9,*(undefined2 *)((uint3)(iVar7 + 0x7f4) | 0x90000));
      uVar1 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(char *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) = (char)uVar10;
      uVar1 = 0x24;
      if ((((uVar6 & 0xc000) != 0) && (uVar1 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(char *)((uint3)uVar1 << 0xe | (uint3)(uVar6 & 0x3fff)) = (char)((uint)uVar10 >> 8);
      uVar1 = 0x24;
      if ((((uVar9 & 0xc000) != 0) && (uVar1 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar9 & 0x3fff)) = 0x55;
      egs52_update_near_c166_097172
                (uVar9,uRam0907f0,*(undefined2 *)((uint3)(iVar7 + 0x7f4) | 0x90000),0,iStack_12);
      egs52_update_near_c166_097172(0xf852,uRam0907f0,1,0,iStack_10);
      egs52_update_near_c166_097172
                (uVar9,*(undefined2 *)((uint3)(iVar7 + 0x7f0) | 0x90000),
                 *(undefined2 *)((uint3)(iVar7 + 0x7f4) | 0x90000),1,iStack_e);
      uVar10 = egs52_update_near_c166_097172
                         (0xf852,*(undefined2 *)((uint3)(iVar7 + 0x7f0) | 0x90000),1,0,iStack_c);
    }
    else if (cVar5 == '\x03') {
      iVar11 = 0;
      while( true ) {
        iVar8 = iVar11 * 6;
        uVar1 = iVar8 + 0xca80;
        uVar2 = 0x24;
        if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        if (*(byte *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)) == param_1) break;
        iVar11 = iVar11 + 1;
      }
      uVar2 = iVar8 + 0xca84;
      uVar1 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      cVar5 = *(char *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) + '\x01';
      uVar1 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(char *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) = cVar5;
      if (cVar5 == *(char *)((uint3)(iVar7 + 0x7f3U) | 0x90000)) {
        uVar1 = 0x24;
        if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) = 0;
        uVar6 = iVar8 + 0xca82;
        uVar1 = 0x24;
        if ((((uVar6 & 0xc000) != 0) && (uVar1 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        uVar3 = 0x24;
        if ((((uVar6 & 0xc000) != 0) && (uVar3 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
           (uVar3 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
          uVar3 = 3;
        }
        *(int *)((uint3)uVar3 << 0xe | (uint3)(uVar6 & 0x3fff)) =
             *(int *)((uint3)uVar1 << 0xe | (uint3)(uVar6 & 0x3fff)) + 1;
      }
      uVar6 = iVar8 + 0xca85;
      uVar1 = 0x24;
      if ((((uVar6 & 0xc000) != 0) && (uVar1 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      if (*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar6 & 0x3fff)) <
          *(byte *)((uint3)(iVar7 + 0x7f3U) | 0x90000)) {
        uVar1 = 0x24;
        if ((((uVar6 & 0xc000) != 0) && (uVar1 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        uVar3 = 0x24;
        if ((((uVar6 & 0xc000) != 0) && (uVar3 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
           (uVar3 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
          uVar3 = 3;
        }
        *(char *)((uint3)uVar3 << 0xe | (uint3)(uVar6 & 0x3fff)) =
             *(char *)((uint3)uVar1 << 0xe | (uint3)(uVar6 & 0x3fff)) + '\x01';
      }
      uVar6 = iVar8 + 0xca82;
      uVar1 = 0x24;
      if ((((uVar6 & 0xc000) != 0) && (uVar1 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      uVar3 = 0x24;
      if ((((uVar9 & 0xc000) != 0) && (uVar3 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      *(char *)((uint3)uVar3 << 0xe | (uint3)(uVar9 & 0x3fff)) =
           (char)*(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(uVar6 & 0x3fff));
      uVar1 = 0x24;
      if ((((uVar6 & 0xc000) != 0) && (uVar1 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      uVar3 = uVar9 + 1;
      uVar4 = 0x24;
      if ((((uVar3 & 0xc000) != 0) && (uVar4 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
         (uVar4 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
        uVar4 = 3;
      }
      *(char *)((uint3)uVar4 << 0xe | (uint3)(uVar3 & 0x3fff)) =
           (char)((uint)*(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(uVar6 & 0x3fff)) >> 8);
      uVar6 = uVar9 + 2;
      uVar1 = 0x24;
      if ((((uVar6 & 0xc000) != 0) && (uVar1 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar6 & 0x3fff)) = 0;
      uVar3 = uVar9 + 3;
      uVar1 = 0x24;
      if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) = 0;
      uVar10 = egs52_call_092118_0a3d74(*(undefined2 *)((uint3)(iVar7 + 0x7f4) | 0x90000));
      uVar1 = 0x24;
      if ((((uVar6 & 0xc000) != 0) && (uVar1 = 0x21, (uVar6 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar6 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(char *)((uint3)uVar1 << 0xe | (uint3)(uVar6 & 0x3fff)) = (char)uVar10;
      uVar1 = 0x24;
      if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(char *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) = (char)((uint)uVar10 >> 8);
      uVar1 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      uVar10 = egs52_update_near_c166_097172
                         (uVar9,*(int *)((uint3)(iVar7 + 0x7f0) | 0x90000) +
                                *(int *)((uint3)(iVar7 + 0x7f4) | 0x90000) *
                                (uint)*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)),
                          *(undefined2 *)((uint3)(iVar7 + 0x7f4) | 0x90000),1,iStack_12);
    }
    else {
      egs52_free_small_heap_block();
      uVar10 = 0xffff;
    }
    UNK_00caa4 = 0;
  }
  return uVar10;
}


