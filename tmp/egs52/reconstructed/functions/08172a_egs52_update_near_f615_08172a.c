/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x08172a; FLS offset 0x00172a.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x081a1e) */
/* WARNING: Removing unreachable block (ram,0x0819e4) */
/* WARNING: Removing unreachable block (ram,0x0817d6) */
/* WARNING: Removing unreachable block (ram,0x08184e) */
/* WARNING: Removing unreachable block (ram,0x081892) */
/* WARNING: Removing unreachable block (ram,0x0818d6) */
/* WARNING: Removing unreachable block (ram,0x0818ce) */
/* WARNING: Removing unreachable block (ram,0x0818ba) */
/* WARNING: Removing unreachable block (ram,0x0818b6) */
/* WARNING: Removing unreachable block (ram,0x0818a2) */
/* WARNING: Removing unreachable block (ram,0x08189e) */
/* WARNING: Removing unreachable block (ram,0x081928) */
/* WARNING: Removing unreachable block (ram,0x081904) */
/* WARNING: Removing unreachable block (ram,0x0818f0) */
/* WARNING: Removing unreachable block (ram,0x0818ec) */
/* WARNING: Removing unreachable block (ram,0x081876) */
/* WARNING: Removing unreachable block (ram,0x081872) */
/* WARNING: Removing unreachable block (ram,0x08185e) */
/* WARNING: Removing unreachable block (ram,0x08185a) */
/* WARNING: Removing unreachable block (ram,0x081832) */
/* WARNING: Removing unreachable block (ram,0x08182e) */
/* WARNING: Removing unreachable block (ram,0x08181c) */
/* WARNING: Removing unreachable block (ram,0x081818) */
/* WARNING: Removing unreachable block (ram,0x0817fc) */
/* WARNING: Removing unreachable block (ram,0x0817f8) */
/* WARNING: Removing unreachable block (ram,0x0817e6) */
/* WARNING: Removing unreachable block (ram,0x0817e2) */
/* WARNING: Removing unreachable block (ram,0x0817b8) */
/* WARNING: Removing unreachable block (ram,0x0817b4) */
/* WARNING: Removing unreachable block (ram,0x0817a2) */
/* WARNING: Removing unreachable block (ram,0x08179e) */
/* WARNING: Removing unreachable block (ram,0x081952) */
/* WARNING: Removing unreachable block (ram,0x08196e) */
/* WARNING: Removing unreachable block (ram,0x0819ae) */
/* WARNING: Removing unreachable block (ram,0x0819e0) */
/* WARNING: Removing unreachable block (ram,0x081732) */
/* WARNING: Removing unreachable block (ram,0x081938) */
/* WARNING: Removing unreachable block (ram,0x081908) */

uint egs52_update_near_f615_08172a(uint param_1,uint param_2,uint param_3,int param_4)

{
  bool bVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  
  UNK_00f615 = 0;
  uVar3 = param_1 + param_3;
  uVar4 = param_2 + param_4 + (uint)CARRY2(param_1,param_3);
  if (param_4 != 0 || param_3 != 0) {
    bVar1 = uVar3 == 0;
    uVar3 = uVar3 - 1;
    uVar4 = uVar4 - bVar1;
  }
  if ((((param_2 - 9 != (uint)(param_1 < 0xf) || param_1 != 0xf) &&
        (8 < param_2 && (param_2 != 9 || param_1 >= 0xf))) || (uVar4 < 9)) &&
     (((param_2 - 0xb != (uint)(param_1 < 0xf) || param_1 != 0xf) &&
       (10 < param_2 && (param_2 != 0xb || param_1 >= 0xf)) || (uVar4 < 0xb)))) {
    cVar2 = egs52_register_sequence_08112c();
    if (cVar2 == '\x01') {
      if ((param_2 < uRam09024c || param_2 == uRam09024c && param_1 < uRam09024a) ||
         ((param_2 - uRam090250 != (uint)(param_1 < uRam09024e) || param_1 != uRam09024e) &&
          (uRam090250 <= param_2 && (param_2 != uRam090250 || param_1 >= uRam09024e)))) {
        if ((((uRam09023c <= param_2 && (param_2 != uRam09023c || uRam09023a <= param_1)) &&
             (param_2 - uRam090240 == (uint)(param_1 < uRam09023e) && param_1 == uRam09023e ||
              (param_2 < uRam090240 || param_2 == uRam090240 && param_1 < uRam09023e))) &&
            (uVar4 - uRam090240 == (uint)(uVar3 < uRam09023e) && uVar3 == uRam09023e ||
             (uVar4 < uRam090240 || uVar4 == uRam090240 && uVar3 < uRam09023e))) ||
           (((uRam090244 <= param_2 && (param_2 != uRam090244 || uRam090242 <= param_1) &&
             (param_2 - uRam090248 == (uint)(param_1 < uRam090246) && param_1 == uRam090246 ||
              (param_2 < uRam090248 || param_2 == uRam090248 && param_1 < uRam090246))) &&
            (uVar4 - uRam090248 == (uint)(uVar3 < uRam090246) && uVar3 == uRam090246 ||
             (uVar4 < uRam090248 || uVar4 == uRam090248 && uVar3 < uRam090246))))) {
          UNK_00f615 = 0x24;
        }
        else if ((param_2 < uRam090232 || param_2 == uRam090232 && param_1 < uRam090230) ||
                ((param_2 - uRam090236 != (uint)(param_1 < uRam090234) || param_1 != uRam090234) &&
                 (uRam090236 <= param_2 && (param_2 != uRam090236 || param_1 >= uRam090234)))) {
          if (((uRam09022a <= param_2 && (param_2 != uRam09022a || uRam090228 <= param_1)) &&
              (param_2 - uRam09022e == (uint)(param_1 < uRam09022c) && param_1 == uRam09022c ||
               (param_2 < uRam09022e || param_2 == uRam09022e && param_1 < uRam09022c))) &&
             (uVar4 - uRam09022e == (uint)(uVar3 < uRam09022c) && uVar3 == uRam09022c ||
              (uVar4 < uRam09022e || uVar4 == uRam09022e && uVar3 < uRam09022c))) {
            UNK_00f615 = 0x22;
          }
        }
        else if (uVar4 - uRam090236 == (uint)(uVar3 < uRam090234) && uVar3 == uRam090234 ||
                 (uVar4 < uRam090236 || uVar4 == uRam090236 && uVar3 < uRam090234)) {
          UNK_00f615 = 0x12;
        }
        else if ((uRam09022a <= uVar4 && (uVar4 != uRam09022a || uRam090228 <= uVar3)) &&
                (uVar4 - uRam09022e == (uint)(uVar3 < uRam09022c) && uVar3 == uRam09022c ||
                 (uVar4 < uRam09022e || uVar4 == uRam09022e && uVar3 < uRam09022c))) {
          UNK_00f615 = 0x12;
          param_3 = (uRam090234 - param_1) + 1;
        }
      }
      else if (uVar4 - uRam090250 == (uint)(uVar3 < uRam09024e) && uVar3 == uRam09024e ||
               (uVar4 < uRam090250 || uVar4 == uRam090250 && uVar3 < uRam09024e)) {
        UNK_00f615 = 0x14;
      }
    }
    else if (param_2 == 0 && param_1 == 0) {
      if (uVar4 == 0 && uVar3 == 0) {
        UNK_00f615 = 0x12;
      }
      else if (uVar4 - 8 == (uint)(uVar3 < 0x7fff) && uVar3 == 0x7fff ||
               (uVar4 < 8 || uVar4 == 8 && uVar3 < 0x7fff)) {
        UNK_00f615 = 0x12;
        param_3 = 1 - param_1;
      }
    }
    else if ((param_2 < 8 || param_2 == 8 && param_1 < 0x6000) ||
            ((param_2 - 8 != (uint)(param_1 < 0x7fff) || param_1 != 0x7fff) &&
             (7 < param_2 && (param_2 != 8 || param_1 >= 0x7fff)))) {
      if (((8 < param_2) &&
          (param_2 - 0xf == (uint)(param_1 != 0xffff) && param_1 == 0xffff ||
           (param_2 < 0xf || param_2 == 0xf && param_1 != 0xffff))) &&
         (uVar4 - 0xf == (uint)(uVar3 != 0xffff) && uVar3 == 0xffff ||
          (uVar4 < 0xf || uVar4 == 0xf && uVar3 != 0xffff))) {
        UNK_00f615 = 0x22;
      }
    }
    else if (uVar4 - 8 == (uint)(uVar3 < 0x7fff) && uVar3 == 0x7fff ||
             (uVar4 < 8 || uVar4 == 8 && uVar3 < 0x7fff)) {
      UNK_00f615 = 0x22;
    }
    cVar2 = UNK_00f615;
    if ((((cVar2 == '\0') && (7 < param_2 && (param_2 != 8 || 0x3e73 < param_1))) &&
        (param_2 - 8 == (uint)(param_1 < 0x3fff) && param_1 == 0x3fff ||
         (param_2 < 8 || param_2 == 8 && param_1 < 0x3fff))) &&
       ((7 < uVar4 && (uVar4 != 8 || 0x3e73 < uVar3) &&
        (uVar4 - 8 == (uint)(uVar3 < 0x3fff) && uVar3 == 0x3fff ||
         (uVar4 < 8 || uVar4 == 8 && uVar3 < 0x3fff))))) {
      UNK_00f615 = 0x21;
    }
  }
  return param_3;
}


