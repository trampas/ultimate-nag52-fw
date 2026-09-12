/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x09c4d8; FLS offset 0x01c4d8.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x09c58a) */
/* WARNING: Removing unreachable block (ram,0x09c522) */
/* WARNING: Removing unreachable block (ram,0x09c5e0) */
/* WARNING: Removing unreachable block (ram,0x09c5ce) */
/* WARNING: Removing unreachable block (ram,0x09c5be) */
/* WARNING: Removing unreachable block (ram,0x09c618) */
/* WARNING: Removing unreachable block (ram,0x09c608) */
/* WARNING: Removing unreachable block (ram,0x09c5f8) */
/* WARNING: Removing unreachable block (ram,0x09c624) */
/* WARNING: Removing unreachable block (ram,0x09c638) */
/* WARNING: Removing unreachable block (ram,0x09c5ee) */
/* WARNING: Removing unreachable block (ram,0x09c5ea) */
/* WARNING: Removing unreachable block (ram,0x09c5b4) */
/* WARNING: Removing unreachable block (ram,0x09c502) */
/* WARNING: Removing unreachable block (ram,0x09c4e6) */
/* WARNING: Removing unreachable block (ram,0x09c5aa) */
/* WARNING: Removing unreachable block (ram,0x09c52a) */
/* WARNING: Removing unreachable block (ram,0x09c544) */
/* WARNING: Removing unreachable block (ram,0x09c558) */
/* WARNING: Removing unreachable block (ram,0x09c550) */
/* WARNING: Removing unreachable block (ram,0x09c57a) */
/* WARNING: Removing unreachable block (ram,0x09c572) */

uint egs52_call_0a1b8c_09c4d8(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  bool bVar7;
  char cVar8;
  
  uVar1 = (param_2 & 0xff) + 0x84e6;
  uVar2 = 0x24;
  if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
     (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
    uVar2 = 3;
  }
  cVar8 = egs52_match_fault_status_mask
                    (*(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)),1);
  if (cVar8 == '\0') {
    uVar1 = (param_2 & 0xff) + 0x84d6;
    uVar2 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar2 = 3;
    }
    cVar8 = egs52_match_fault_status_mask
                      (*(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)),1);
    if (cVar8 == '\0') {
      iVar6 = (param_2 & 0xff) * 2;
      uVar2 = iVar6 + 0x8464;
      uVar1 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      if (param_1 < *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff))) {
        uVar1 = (param_2 & 0xff) + 0x84e6;
        uVar3 = 0x24;
        if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
           (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
          uVar3 = 3;
        }
        egs52_update_fault_status(*(undefined1 *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)),3);
        if ((1 << (param_2 & 0xf) & 0xfffeU) == 0) {
          return param_1;
        }
        uVar1 = 0x24;
        if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        return *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
      }
      uVar2 = iVar6 + 0x8484;
      uVar1 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      puVar4 = (uint *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
      if (param_1 == *puVar4 || param_1 < *puVar4) {
        uVar1 = (param_2 & 0xff) + 0x84e6;
        uVar2 = 0x24;
        if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        egs52_update_fault_status(*(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)),2);
        uVar1 = (param_2 & 0xff) + 0x84d6;
        uVar2 = 0x24;
        if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
           (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
          uVar2 = 3;
        }
        egs52_update_fault_status(*(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)),2);
        return param_1;
      }
      uVar1 = (param_2 & 0xff) + 0x84d6;
      uVar3 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      egs52_update_fault_status(*(undefined1 *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)),3);
      if ((1 << (param_2 & 0xf) & 0xfffeU) == 0) {
        return param_1;
      }
      uVar1 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      return *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
    }
    bVar7 = false;
  }
  else {
    bVar7 = true;
  }
  iVar6 = (param_2 & 0xff) * 2;
  uVar2 = iVar6 + 0x8464;
  uVar1 = 0x24;
  if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  uVar5 = iVar6 + 0x84a4;
  uVar3 = 0x24;
  if ((((uVar5 & 0xc000) != 0) && (uVar3 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
     (uVar3 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
    uVar3 = 3;
  }
  if (param_1 < (uint)(*(int *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) +
                      *(int *)((uint3)uVar3 << 0xe | (uint3)(uVar5 & 0x3fff)))) {
    uVar1 = (param_2 & 0xff) + 0x84e6;
    uVar3 = 0x24;
    if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    egs52_update_fault_status(*(undefined1 *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)),3);
    uVar1 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    if ((param_1 < *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff))) &&
       ((1 << (param_2 & 0xf) & 0xfffeU) != 0)) {
      uVar1 = 0x24;
      if (((uVar2 & 0xc000) != 0) &&
         ((uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000 && (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000))))
      {
        uVar1 = 3;
      }
      param_1 = *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
    }
  }
  else {
    uVar2 = iVar6 + 0x8484;
    uVar1 = 0x24;
    if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
       (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
      uVar1 = 3;
    }
    uVar3 = 0x24;
    if ((((uVar5 & 0xc000) != 0) && (uVar3 = 0x21, (uVar5 & 0xc000) != 0x4000)) &&
       (uVar3 = 0x2c, (uVar5 & 0xc000) != 0x8000)) {
      uVar3 = 3;
    }
    if ((uint)(*(int *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff)) -
              *(int *)((uint3)uVar3 << 0xe | (uint3)(uVar5 & 0x3fff))) < param_1) {
      uVar1 = (param_2 & 0xff) + 0x84d6;
      uVar3 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar3 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar3 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar3 = 3;
      }
      egs52_update_fault_status(*(undefined1 *)((uint3)uVar3 << 0xe | (uint3)(uVar1 & 0x3fff)),3);
      uVar1 = 0x24;
      if ((((uVar2 & 0xc000) != 0) && (uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      puVar4 = (uint *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
      if ((param_1 != *puVar4 && *puVar4 <= param_1) && ((1 << (param_2 & 0xf) & 0xfffeU) != 0)) {
        uVar1 = 0x24;
        if (((uVar2 & 0xc000) != 0) &&
           ((uVar1 = 0x21, (uVar2 & 0xc000) != 0x4000 && (uVar1 = 0x2c, (uVar2 & 0xc000) != 0x8000))
           )) {
          uVar1 = 3;
        }
        param_1 = *(uint *)((uint3)uVar1 << 0xe | (uint3)(uVar2 & 0x3fff));
      }
    }
    else if (bVar7) {
      uVar1 = (param_2 & 0xff) + 0x84e6;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      egs52_update_fault_status(*(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)),2);
    }
    else {
      uVar1 = (param_2 & 0xff) + 0x84d6;
      uVar2 = 0x24;
      if ((((uVar1 & 0xc000) != 0) && (uVar2 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
         (uVar2 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
        uVar2 = 3;
      }
      egs52_update_fault_status(*(undefined1 *)((uint3)uVar2 << 0xe | (uint3)(uVar1 & 0x3fff)),2);
    }
  }
  return param_1;
}


