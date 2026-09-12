/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x09e9da; FLS offset 0x01e9da.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Function: egs52_near_to_far_registers replaced with injection:
   egs52_near_to_far_registers */
/* WARNING: Removing unreachable block (ram,0x09eb54) */
/* WARNING: Removing unreachable block (ram,0x09eb8e) */
/* WARNING: Removing unreachable block (ram,0x09eb7e) */
/* WARNING: Removing unreachable block (ram,0x09eb40) */
/* WARNING: Removing unreachable block (ram,0x09eb36) */
/* WARNING: Removing unreachable block (ram,0x09ecce) */
/* WARNING: Removing unreachable block (ram,0x09ed22) */
/* WARNING: Removing unreachable block (ram,0x09ecf6) */
/* WARNING: Removing unreachable block (ram,0x09ecea) */
/* WARNING: Removing unreachable block (ram,0x09ecbc) */
/* WARNING: Removing unreachable block (ram,0x09ebb6) */
/* WARNING: Removing unreachable block (ram,0x09eca0) */
/* WARNING: Removing unreachable block (ram,0x09eb06) */
/* WARNING: Removing unreachable block (ram,0x09eb26) */
/* WARNING: Removing unreachable block (ram,0x09eaf0) */
/* WARNING: Removing unreachable block (ram,0x09ea0a) */
/* WARNING: Removing unreachable block (ram,0x09ea3c) */
/* WARNING: Removing unreachable block (ram,0x09ea06) */
/* WARNING: Removing unreachable block (ram,0x09ea20) */
/* WARNING: Removing unreachable block (ram,0x09ea38) */
/* WARNING: Removing unreachable block (ram,0x09ea1c) */
/* WARNING: Removing unreachable block (ram,0x09eb2a) */
/* WARNING: Removing unreachable block (ram,0x09eaf4) */
/* WARNING: Removing unreachable block (ram,0x09eb0a) */
/* WARNING: Removing unreachable block (ram,0x09ec88) */
/* WARNING: Removing unreachable block (ram,0x09ea4a) */

undefined1 egs52_update_near_c34c_09e9da(uchar *param_1,uint param_2,uchar *param_3,uchar *param_4)

{
  uint uVar1;
  uchar *puVar2;
  uchar *puVar3;
  int iVar4;
  bool bVar5;
  undefined1 uVar6;
  byte bVar7;
  char cVar8;
  uint uVar9;
  uint uVar10;
  undefined2 uVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  uchar *puVar15;
  uchar *puStack_1c;
  int iStack_1a;
  ushort uStack_18;
  
  bVar5 = false;
  iVar13 = 0;
  puVar15 = param_4;
  while (!bVar5) {
    uVar14 = iVar13 * 4 - 0x7e6;
    uVar1 = 0x24;
    if ((((uVar14 & 0xc000) != 0) && (uVar1 = 0x21, (uVar14 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar14 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    uVar9 = iVar13 * 4 - 0x7e4;
    uVar10 = 0x24;
    if ((((uVar9 & 0xc000) != 0) && (uVar10 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
       (uVar10 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
      uVar10 = 3;
    }
    if (*(int *)((uint3)uVar1 << 0xe | (uint3)(uVar14 & 0x3fff)) == 0 &&
        *(int *)((uint3)uVar10 << 0xe | (uint3)(uVar9 & 0x3fff)) == 0) break;
    iVar4 = iVar13 * 4;
    uVar14 = iVar4 - 0x7e6;
    uVar1 = 0x24;
    if ((((uVar14 & 0xc000) != 0) && (uVar1 = 0x21, (uVar14 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar14 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    puVar3 = *(uchar **)((uint3)uVar1 << 0xe | (uint3)(uVar14 & 0x3fff));
    uVar14 = iVar4 - 0x7e4;
    uVar1 = 0x24;
    if ((((uVar14 & 0xc000) != 0) && (uVar1 = 0x21, (uVar14 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar14 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    uVar14 = *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar14 & 0x3fff));
    puVar15 = param_1;
    if (param_2 - uVar14 == (uint)(param_1 < puVar3) && param_1 == puVar3 ||
        (param_2 < uVar14 || param_2 == uVar14 && param_1 < puVar3)) {
      uVar9 = param_2 + CARRY2((uint)param_1,(uint)param_4 & 0xff);
      uVar14 = iVar4 - 0x7ea;
      uVar1 = 0x24;
      if ((((uVar14 & 0xc000) != 0) && (uVar1 = 0x21, (uVar14 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar14 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      puVar3 = *(uchar **)((uint3)uVar1 << 0xe | (uint3)(uVar14 & 0x3fff));
      uVar14 = iVar4 - 0x7e8;
      uVar1 = 0x24;
      if ((((uVar14 & 0xc000) != 0) && (uVar1 = 0x21, (uVar14 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar14 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      uVar14 = *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar14 & 0x3fff));
      puVar15 = param_1 + ((uint)param_4 & 0xff) + -(int)puVar3;
      if (uVar9 < uVar14 || uVar9 == uVar14 && param_1 + ((uint)param_4 & 0xff) < puVar3)
      goto LAB_09ea2e;
      bVar5 = true;
    }
    else {
LAB_09ea2e:
      iVar13 = iVar13 + 2;
    }
  }
  if (bVar5) {
    bVar7 = UNK_00c32a;
    if ((bVar7 & 2) == 0) {
      uVar6 = 0x22;
    }
    else {
      egs52_copy_words_registers(puVar15,&puStack_1c);
      egs52_transform_far_memory_09e4c8();
      if ((iStack_1a == 0 && puStack_1c < (uchar *)0xe800) &&
         (iStack_1a != 0 || (uchar *)0xe3ff < puStack_1c)) {
        if (uStack_18 == ((uint)param_4 & 0xff)) {
          egs52_memcpy_near(puStack_1c,param_3,uStack_18);
          uVar6 = 0;
        }
        else {
          uVar6 = 0x43;
        }
      }
      else {
        uVar6 = 0x42;
      }
    }
  }
  else {
    uVar14 = 0;
    bVar5 = false;
    while (!bVar5) {
      uVar1 = uVar14 * 4 - 0x7d6;
      uVar9 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar9 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar9 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar9 = 3;
      }
      uVar10 = uVar14 * 4 - 0x7d4;
      uVar12 = 0x24;
      if ((((uVar10 & 0xc000) != 0) && (uVar12 = 0x21, (uVar10 & 0xc000) != 0x4000)) &&
         (uVar12 = 0x2c, (uVar10 & 0xc000) != 0x8000)) {
        uVar12 = 3;
      }
      if (*(int *)((uint3)uVar9 << 0xe | (uint3)(uVar1 & 0x3fff)) == 0 &&
          *(int *)((uint3)uVar12 << 0xe | (uint3)(uVar10 & 0x3fff)) == 0) break;
      iVar13 = uVar14 * 4;
      uVar1 = iVar13 - 0x7da;
      uVar9 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar9 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar9 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar9 = 3;
      }
      uVar10 = (int)egs52_test_fault_bitmap + iVar13;
      uVar12 = 0x24;
      if ((((uVar10 & 0xc000) != 0) && (uVar12 = 0x21, (uVar10 & 0xc000) != 0x4000)) &&
         (uVar12 = 0x2c, (uVar10 & 0xc000) != 0x8000)) {
        uVar12 = 3;
      }
      uVar10 = *(uint *)((uint3)uVar12 << 0xe | (uint3)(uVar10 & 0x3fff));
      puVar15 = param_1;
      if (param_2 < uVar10 ||
          param_2 == uVar10 && param_1 < *(uchar **)((uint3)uVar9 << 0xe | (uint3)(uVar1 & 0x3fff)))
      {
LAB_09eb1c:
        uVar14 = uVar14 + 2;
      }
      else {
        puVar3 = param_1 + ((uint)param_4 & 0xff);
        uVar10 = param_2 + CARRY2((uint)param_1,(uint)param_4 & 0xff);
        uVar1 = iVar13 - 0x7d6;
        uVar9 = 0x24;
        if ((((uVar1 & 0xc000) != 0) && (uVar9 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
           (uVar9 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
          uVar9 = 3;
        }
        uVar12 = *(uint *)((uint3)uVar9 << 0xe | (uint3)(uVar1 & 0x3fff));
        uVar1 = iVar13 - 0x7d4;
        uVar9 = 0x24;
        if ((((uVar1 & 0xc000) != 0) && (uVar9 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
           (uVar9 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
          uVar9 = 3;
        }
        puVar2 = (uchar *)(uVar12 + 1);
        uVar1 = *(int *)((uint3)uVar9 << 0xe | (uint3)(uVar1 & 0x3fff)) + (uint)(0xfffe < uVar12);
        puVar15 = puVar3 + -(int)puVar2;
        if ((uVar10 - uVar1 != (uint)(puVar3 < puVar2) || puVar15 != (uchar *)0x0) &&
            (uVar1 <= uVar10 && (uVar10 != uVar1 || puVar3 >= puVar2))) goto LAB_09eb1c;
        bVar5 = true;
      }
    }
    if (bVar5) {
      if ((bRam00f57f & 10) == 0) {
        uVar6 = 0x33;
      }
      else {
        iVar13 = Ram00c34c;
        if (iVar13 == 0) {
          iVar13 = egs52_update_near_caa4_0a33b2(param_3,param_1,(uint)param_4 & 0xff);
          Ram00c34c = iVar13;
          if (iVar13 == 0) {
            Ram00c34c = 0;
            uVar6 = 0x21;
          }
          else {
            uVar6 = 0x78;
          }
        }
        else {
          cVar8 = egs52_call_0a3d02_095b58(iVar13,0,(uint)param_4 & 0xff,puVar15);
          if (cVar8 == '\x03') {
            Ram00c34c = 0;
            uVar6 = 0;
          }
          else {
            uVar6 = 0x78;
          }
        }
      }
    }
    else {
      iVar13 = 0;
      bVar7 = egs52_return_35();
      cVar8 = '\0';
      while( true ) {
        uVar1 = iVar13 - 0x7c6;
        uVar9 = 0x24;
        if ((((uVar1 & 0xc000) != 0) && (uVar9 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
           (uVar9 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
          uVar9 = 3;
        }
        if (((uint)bVar7 < (uint)*(byte *)((uint3)uVar9 << 0xe | (uint3)(uVar1 & 0x3fff))) ||
           (cVar8 != '\0')) break;
        uVar14 = iVar13 - 0x7c6;
        uVar1 = 0x24;
        if ((((uVar14 & 0xc000) != 0) && (uVar1 = 0x21, (uVar14 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar14 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        uVar14 = (uint)*(byte *)((uint3)uVar1 << 0xe | (uint3)(uVar14 & 0x3fff));
        while( true ) {
          uVar1 = iVar13 - 0x7c5;
          uVar9 = 0x24;
          if ((((uVar1 & 0xc000) != 0) && (uVar9 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
             (uVar9 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
            uVar9 = 3;
          }
          if (((*(byte *)((uint3)uVar9 << 0xe | (uint3)(uVar1 & 0x3fff)) < uVar14) ||
              (bVar7 < uVar14)) || (cVar8 != '\0')) break;
          uVar9 = egs52_read_channel_table_word(uVar14);
          uVar1 = 0x24;
          if ((((uVar9 & 0xc000) != 0) && (uVar1 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
             (uVar1 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
            uVar1 = 3;
          }
          uVar10 = uVar1 >> 2;
          bVar5 = param_1 < (uchar *)(uVar9 & 0x3fff | uVar1 << 0xe);
          if (param_2 < uVar10 || param_2 == uVar10 && bVar5) {
LAB_09ec26:
            uVar9 = egs52_read_channel_table_word(uVar14);
            uVar1 = 0x24;
            if ((((uVar9 & 0xc000) != 0) && (uVar1 = 0x21, (uVar9 & 0xc000) != 0x4000)) &&
               (uVar1 = 0x2c, (uVar9 & 0xc000) != 0x8000)) {
              uVar1 = 3;
            }
            uVar12 = uVar1 >> 2;
            uVar10 = param_2 + CARRY2((uint)param_1,(uint)param_4 & 0xff);
            bVar5 = param_1 + ((uint)param_4 & 0xff) < (uchar *)(uVar9 & 0x3fff | uVar1 << 0xe);
            if (uVar12 <= uVar10 && (uVar10 != uVar12 || !bVar5)) {
              uVar9 = egs52_register_arithmetic_095b76(uVar14,(uVar10 - uVar12) - (uint)bVar5);
              uVar10 = egs52_read_channel_table_word(uVar14);
              uVar1 = 0x24;
              if ((((uVar10 & 0xc000) != 0) && (uVar1 = 0x21, (uVar10 & 0xc000) != 0x4000)) &&
                 (uVar1 = 0x2c, (uVar10 & 0xc000) != 0x8000)) {
                uVar1 = 3;
              }
              uVar10 = uVar10 & 0x3fff | uVar1 << 0xe;
              uVar1 = (uVar1 >> 2) + (uint)CARRY2(uVar10,uVar9);
              if (param_2 < uVar1 || param_2 == uVar1 && param_1 < (uchar *)(uVar10 + uVar9)) {
                cVar8 = '\x02';
              }
            }
          }
          else {
            uVar9 = egs52_register_arithmetic_095b76(uVar14,(param_2 - uVar10) - (uint)bVar5);
            uVar10 = egs52_read_channel_table_word(uVar14);
            uVar1 = 0x24;
            if ((((uVar10 & 0xc000) != 0) && (uVar1 = 0x21, (uVar10 & 0xc000) != 0x4000)) &&
               (uVar1 = 0x2c, (uVar10 & 0xc000) != 0x8000)) {
              uVar1 = 3;
            }
            uVar10 = uVar10 & 0x3fff | uVar1 << 0xe;
            puVar15 = (uchar *)(uVar10 + uVar9);
            uVar1 = (uVar1 >> 2) + (uint)CARRY2(uVar10,uVar9);
            puVar3 = param_1 + ((uint)param_4 & 0xff);
            uVar9 = param_2 + CARRY2((uint)param_1,(uint)param_4 & 0xff);
            if ((uVar9 - uVar1 != (uint)(puVar3 < puVar15) || puVar3 != puVar15) &&
                (uVar1 <= uVar9 && (uVar9 != uVar1 || puVar3 >= puVar15))) goto LAB_09ec26;
            cVar8 = '\x01';
          }
          uVar14 = uVar14 + 1;
        }
        iVar13 = iVar13 + 2;
      }
      if (cVar8 == '\0') {
        uVar6 = 0xff;
      }
      else {
        uVar14 = uVar14 - 1;
        iVar13 = Ram00c34c;
        if (iVar13 == 0) {
          if (cVar8 == '\x01') {
            bVar7 = 0;
            while( true ) {
              uVar1 = bVar7 - 0x7c9;
              uVar9 = 0x24;
              if ((((uVar1 & 0xc000) != 0) && (uVar9 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
                 (uVar9 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
                uVar9 = 3;
              }
              if (uVar14 <= *(byte *)((uint3)uVar9 << 0xe | (uint3)(uVar1 & 0x3fff))) break;
              bVar7 = bVar7 + 2;
            }
            uVar1 = bVar7 - 0x7ca;
            uVar9 = 0x24;
            if ((((uVar1 & 0xc000) != 0) && (uVar9 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
               (uVar9 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
              uVar9 = 3;
            }
            if (uVar14 < *(byte *)((uint3)uVar9 << 0xe | (uint3)(uVar1 & 0x3fff))) {
              uVar6 = 0x42;
            }
            else {
              egs52_memcpy_near(param_1,param_3,(uint)param_4 & 0xff);
              uVar11 = egs52_read_channel_table_word(uVar14);
              iVar13 = egs52_update_near_caa4_0a2fba(uVar14,uVar11);
              Ram00c34c = iVar13;
              if (iVar13 == 0) {
                uVar6 = 0x21;
              }
              else {
                uVar6 = 0x78;
              }
            }
          }
          else {
            uVar6 = 0x43;
          }
        }
        else {
          cVar8 = egs52_call_095b6a_095b38(iVar13,uVar14);
          if (cVar8 == '\x03') {
            Ram00c34c = 0;
            uVar6 = 0;
          }
          else {
            uVar6 = 0x78;
          }
        }
      }
    }
  }
  return uVar6;
}


