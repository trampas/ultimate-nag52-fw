/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x096794; FLS offset 0x016794.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x096958) */
/* WARNING: Removing unreachable block (ram,0x09694e) */
/* WARNING: Removing unreachable block (ram,0x096946) */
/* WARNING: Removing unreachable block (ram,0x096942) */
/* WARNING: Removing unreachable block (ram,0x09693e) */
/* WARNING: Removing unreachable block (ram,0x096924) */
/* WARNING: Removing unreachable block (ram,0x09691a) */
/* WARNING: Removing unreachable block (ram,0x096916) */
/* WARNING: Removing unreachable block (ram,0x09690e) */
/* WARNING: Removing unreachable block (ram,0x0968f4) */
/* WARNING: Removing unreachable block (ram,0x0968ea) */
/* WARNING: Removing unreachable block (ram,0x0968e6) */
/* WARNING: Removing unreachable block (ram,0x0968de) */
/* WARNING: Removing unreachable block (ram,0x0968c4) */
/* WARNING: Removing unreachable block (ram,0x0968ba) */
/* WARNING: Removing unreachable block (ram,0x0968b6) */
/* WARNING: Removing unreachable block (ram,0x0968ae) */
/* WARNING: Removing unreachable block (ram,0x0968a4) */
/* WARNING: Removing unreachable block (ram,0x09689a) */
/* WARNING: Removing unreachable block (ram,0x096880) */
/* WARNING: Removing unreachable block (ram,0x096878) */
/* WARNING: Removing unreachable block (ram,0x096874) */
/* WARNING: Removing unreachable block (ram,0x09685a) */
/* WARNING: Removing unreachable block (ram,0x096852) */
/* WARNING: Removing unreachable block (ram,0x09684e) */
/* WARNING: Removing unreachable block (ram,0x096834) */
/* WARNING: Removing unreachable block (ram,0x09682c) */
/* WARNING: Removing unreachable block (ram,0x096812) */
/* WARNING: Removing unreachable block (ram,0x0967be) */
/* WARNING: Removing unreachable block (ram,0x096798) */
/* WARNING: Removing unreachable block (ram,0x0967b8) */

void egs52_update_near_d3e8_096794(void)

{
  uint uVar1;
  char cVar2;
  undefined1 uVar3;
  uchar uVar4;
  uint uVar5;
  ushort uVar6;
  byte bVar7;
  
  bVar7 = UNK_00c117;
  if ((bVar7 & 7) == 0) {
    uVar5 = egs52_update_near_c170_097904(bVar7 & 7);
    if ((uVar5 & 0x100) == 0) {
      bVar7 = UNK_00c116;
      if (((bVar7 & 0x80) != 0) && (cVar2 = egs52_match_fault_status_mask(10,1), cVar2 != '\0')) {
        egs52_update_near_fd6c_0a10ec(0,0x988e);
        egs52_update_near_fd6c_0a10ec(0,0x98a2);
        egs52_update_near_fd6c_0a10ec(0,0x98b6);
        egs52_update_near_fd6c_0a10ec(0,0x932a);
        egs52_update_near_fd6c_0a10ec(0,0x933e);
        egs52_update_near_fd6c_0a10ec(0,0x9352);
        bVar7 = UNK_00c116;
        UNK_00c116 = bVar7 & 0x7f;
      }
    }
    else {
      uVar5 = egs52_compute_from_near_c19f_0990f6();
      if ((uVar5 & 0xe0) == 0) {
        bVar7 = UNK_00c116;
        UNK_00c116 = bVar7 | 0x80;
      }
    }
  }
  cVar2 = egs52_test_flag_fd56_bit4();
  if ((cVar2 != '\0') && (uVar6 = egs52_get_operating_mask(), (uVar6 & 0x60f) != 0)) {
    bVar7 = UNK_00c118;
    if (((bVar7 & 1) == 0) && (bVar7 = UNK_00c117, (bVar7 & 1) == 0)) {
      egs52_update_fault_status(0x47,2);
      egs52_update_near_c19d_09887a(1);
      bVar7 = UNK_00c118;
      UNK_00c118 = bVar7 & 1;
    }
    bVar7 = UNK_00c118;
    if (((bVar7 & 2) == 0) && (bVar7 = UNK_00c117, (bVar7 & 2) == 0)) {
      egs52_update_fault_status(0x48,2);
      egs52_update_near_c19d_09887a(2);
      bVar7 = UNK_00c118;
      UNK_00c118 = bVar7 & 2;
    }
    bVar7 = UNK_00c118;
    if (((bVar7 & 4) == 0) && (bVar7 = UNK_00c117, (bVar7 & 4) == 0)) {
      egs52_update_fault_status(0x49,2);
      egs52_update_near_c19d_09887a(3);
      bVar7 = UNK_00c118;
      UNK_00c118 = bVar7 & 4;
    }
  }
  uVar3 = egs52_register_sequence_096962();
  UNK_00d3e8 = uVar3;
  egs52_transform_memory_098aaa(uVar3);
  uVar1 = iRam0904e2 + 0xe;
  uVar5 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar5 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar5 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar5 = 3;
  }
  bVar7 = UNK_00c117;
  if ((*(uint *)((uint3)uVar5 << 0xe | (uint3)(uVar1 & 0x3fff)) & 1) != (bVar7 & 1)) {
    uVar5 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar5 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar5 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar5 = 3;
    }
    if ((*(uint *)((uint3)uVar5 << 0xe | (uint3)(uVar1 & 0x3fff)) & 1) == 0) {
      egs52_update_near_c19f_0989ea(1);
    }
    else {
      uVar4 = egs52_return_fe();
      egs52_update_near_c19f_09895a(1,uVar4);
    }
  }
  uVar1 = iRam0904e2 + 0xe;
  uVar5 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar5 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar5 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar5 = 3;
  }
  bVar7 = UNK_00c117;
  if ((*(uint *)((uint3)uVar5 << 0xe | (uint3)(uVar1 & 0x3fff)) & 2) != (bVar7 & 2)) {
    uVar5 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar5 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar5 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar5 = 3;
    }
    if ((*(uint *)((uint3)uVar5 << 0xe | (uint3)(uVar1 & 0x3fff)) & 2) == 0) {
      egs52_update_near_c19f_0989ea(2);
    }
    else {
      uVar4 = egs52_return_fe();
      egs52_update_near_c19f_09895a(2,uVar4);
    }
  }
  uVar1 = iRam0904e2 + 0xe;
  uVar5 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar5 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar5 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar5 = 3;
  }
  bVar7 = UNK_00c117;
  if ((*(uint *)((uint3)uVar5 << 0xe | (uint3)(uVar1 & 0x3fff)) & 4) != (bVar7 & 4)) {
    uVar5 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar5 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar5 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar5 = 3;
    }
    if ((*(uint *)((uint3)uVar5 << 0xe | (uint3)(uVar1 & 0x3fff)) & 4) == 0) {
      egs52_update_near_c19f_0989ea(3);
    }
    else {
      uVar4 = egs52_return_fe();
      egs52_update_near_c19f_09895a(3,uVar4);
    }
  }
  uVar5 = iRam0904e2 + 0xe;
  uVar1 = 0x24;
  if ((((uVar5 & 0xc000) != 0) && (uVar1 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  bVar7 = (byte)*(undefined2 *)((uint3)uVar1 << 0xe | (uint3)(uVar5 & 0x3fff));
  UNK_00c117 = bVar7;
  uVar5 = Ram00d3e6;
  Ram00d3e6 = uVar5 & 0xffc7;
  uVar5 = Ram00d3e6;
  Ram00d3e6 = uVar5 | (uint)(bVar7 & 7) << 3;
  return;
}


