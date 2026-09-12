/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x09600a; FLS offset 0x01600a.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x096136) */
/* WARNING: Removing unreachable block (ram,0x096132) */
/* WARNING: Removing unreachable block (ram,0x09612e) */
/* WARNING: Removing unreachable block (ram,0x09612a) */
/* WARNING: Removing unreachable block (ram,0x096126) */
/* WARNING: Removing unreachable block (ram,0x096122) */
/* WARNING: Removing unreachable block (ram,0x096120) */
/* WARNING: Removing unreachable block (ram,0x09611c) */
/* WARNING: Removing unreachable block (ram,0x09604c) */
/* WARNING: Removing unreachable block (ram,0x09603e) */
/* WARNING: Removing unreachable block (ram,0x096076) */
/* WARNING: Removing unreachable block (ram,0x096068) */
/* WARNING: Removing unreachable block (ram,0x0960c8) */
/* WARNING: Removing unreachable block (ram,0x0960c4) */
/* WARNING: Removing unreachable block (ram,0x0960c0) */
/* WARNING: Removing unreachable block (ram,0x0960bc) */
/* WARNING: Removing unreachable block (ram,0x0960b8) */
/* WARNING: Removing unreachable block (ram,0x0960ae) */
/* WARNING: Removing unreachable block (ram,0x0960aa) */
/* WARNING: Removing unreachable block (ram,0x0960a6) */
/* WARNING: Removing unreachable block (ram,0x0960a2) */
/* WARNING: Removing unreachable block (ram,0x09609e) */
/* WARNING: Removing unreachable block (ram,0x09609a) */
/* WARNING: Removing unreachable block (ram,0x0960da) */
/* WARNING: Removing unreachable block (ram,0x0960ce) */
/* WARNING: Removing unreachable block (ram,0x0960fe) */
/* WARNING: Removing unreachable block (ram,0x0960f0) */
/* WARNING: Removing unreachable block (ram,0x096110) */
/* WARNING: Removing unreachable block (ram,0x096114) */
/* WARNING: Removing unreachable block (ram,0x096118) */
/* WARNING: Removing unreachable block (ram,0x0960e2) */
/* WARNING: Heritage AFTER dead removal. Example location: r0x0904e2 : 0x09611c */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void egs52_transform_memory_09600a(void)

{
  uchar *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined2 uVar6;
  char cVar7;
  ushort uVar8;
  byte bVar9;
  
  uVar8 = egs52_get_operating_mask();
  if ((uVar8 == 1) || (uVar8 == 4)) {
    egs52_memcpy_near(puRam0904e0,(uchar *)0xfd26,2);
    egs52_memcpy_near(puRam0904e2,(uchar *)0xd3d8,0x12);
  }
  else if (uVar8 == 0x800) {
    cVar7 = egs52_compute_from_near_f672_0e352c();
    if (cVar7 == '\x01') {
      egs52_memcpy_near(puRam0904e0,(uchar *)0xfd26,2);
      egs52_memcpy_near(puRam0904e2,(uchar *)0xd3d8,0x12);
    }
    else {
      egs52_update_near_c170_097634(0);
      egs52_register_sequence_097676(0);
    }
  }
  else if (uVar8 != 2) {
    if (uVar8 == 8) {
      uVar3 = 0x24;
      if (((((uint)puRam0904e2 & 0xc000) != 0) &&
          (uVar3 = 0x21, ((uint)puRam0904e2 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, ((uint)puRam0904e2 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      uVar6 = Ram00d2a6;
      *(undefined2 *)((uint3)uVar3 << 0xe | (uint3)((uint)puRam0904e2 & 0x3fff)) = uVar6;
      uVar6 = Ram00d2a8;
      puVar1 = puRam0904e2 + 4;
      uVar3 = 0x24;
      if (((((uint)puVar1 & 0xc000) != 0) && (uVar3 = 0x21, ((uint)puVar1 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, ((uint)puVar1 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      *(undefined2 *)((uint3)uVar3 << 0xe | (uint3)((uint)puVar1 & 0x3fff)) = uVar6;
      bVar9 = UNK_00d2ab;
      puVar1 = puRam0904e2 + 8;
      uVar3 = 0x24;
      if (((((uint)puVar1 & 0xc000) != 0) && (uVar3 = 0x21, ((uint)puVar1 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, ((uint)puVar1 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      *(uint *)((uint3)uVar3 << 0xe | (uint3)((uint)puVar1 & 0x3fff)) = (uint)bVar9 * 0x101;
      bVar9 = UNK_00d2aa;
      puVar1 = puRam0904e2 + 0xe;
      uVar3 = 0x24;
      if (((((uint)puVar1 & 0xc000) != 0) && (uVar3 = 0x21, ((uint)puVar1 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, ((uint)puVar1 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      *(uint *)((uint3)uVar3 << 0xe | (uint3)((uint)puVar1 & 0x3fff)) = (uint)bVar9;
    }
    else if (uVar8 == 0x200) {
      cVar7 = UNK_00c104;
      if (cVar7 == '\x04') {
        bVar9 = 0;
        do {
          uVar3 = bVar9 + 0xc122;
          uVar4 = 0x24;
          if ((((uVar3 & 0xc000) != 0) && (uVar4 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
             (uVar4 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
            uVar4 = 3;
          }
          uVar2 = bVar9 + 0xc11a;
          uVar5 = 0x24;
          if ((((uVar2 & 0xc000) != 0) && (uVar5 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
             (uVar5 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
            uVar5 = 3;
          }
          *(byte *)((uint3)uVar5 << 0xe | (uint3)(uVar2 & 0x3fff)) =
               ~*(byte *)((uint3)uVar4 << 0xe | (uint3)(uVar3 & 0x3fff));
          bVar9 = bVar9 + 1;
        } while (bVar9 < 8);
      }
    }
    else if (uVar8 == 0x400) {
      egs52_memcpy_near(puRam0904e0,(uchar *)0xc0ec,2);
      egs52_memcpy_near(puRam0904e2,(uchar *)0xc0ee,0x12);
    }
    else {
      uVar3 = 0x24;
      if (((((uint)puRam0904e0 & 0xc000) != 0) &&
          (uVar3 = 0x21, ((uint)puRam0904e0 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, ((uint)puRam0904e0 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      uVar4 = 0x24;
      if (((((uint)puRam0904e0 & 0xc000) != 0) &&
          (uVar4 = 0x21, ((uint)puRam0904e0 & 0xc000) != 0x4000)) &&
         (uVar4 = 0x2c, ((uint)puRam0904e0 & 0xc000) != 0x8000)) {
        uVar4 = 3;
      }
      *(uint *)((uint3)uVar4 << 0xe | (uint3)((uint)puRam0904e0 & 0x3fff)) =
           *(uint *)((uint3)uVar3 << 0xe | (uint3)((uint)puRam0904e0 & 0x3fff)) & 0xfffe;
      uVar3 = 0x24;
      if (((((uint)puRam0904e2 & 0xc000) != 0) &&
          (uVar3 = 0x21, ((uint)puRam0904e2 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, ((uint)puRam0904e2 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      *(undefined2 *)((uint3)uVar3 << 0xe | (uint3)((uint)puRam0904e2 & 0x3fff)) = 0;
      puVar1 = puRam0904e2 + 4;
      uVar3 = 0x24;
      if (((((uint)puVar1 & 0xc000) != 0) && (uVar3 = 0x21, ((uint)puVar1 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, ((uint)puVar1 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      *(undefined2 *)((uint3)uVar3 << 0xe | (uint3)((uint)puVar1 & 0x3fff)) = 0;
      puVar1 = puRam0904e2 + 8;
      uVar3 = 0x24;
      if (((((uint)puVar1 & 0xc000) != 0) && (uVar3 = 0x21, ((uint)puVar1 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, ((uint)puVar1 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      *(undefined2 *)((uint3)uVar3 << 0xe | (uint3)((uint)puVar1 & 0x3fff)) = 0;
      puVar1 = puRam0904e2 + 0xe;
      uVar3 = 0x24;
      if (((((uint)puVar1 & 0xc000) != 0) && (uVar3 = 0x21, ((uint)puVar1 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, ((uint)puVar1 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      *(undefined2 *)((uint3)uVar3 << 0xe | (uint3)((uint)puVar1 & 0x3fff)) = 0;
    }
  }
  return;
}


