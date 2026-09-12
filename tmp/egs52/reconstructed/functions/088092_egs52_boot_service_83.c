/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x088092; FLS offset 0x008092.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x08816c) */
/* WARNING: Removing unreachable block (ram,0x088164) */
/* WARNING: Removing unreachable block (ram,0x088154) */
/* WARNING: Removing unreachable block (ram,0x088194) */
/* WARNING: Removing unreachable block (ram,0x08818e) */
/* WARNING: Removing unreachable block (ram,0x088184) */
/* WARNING: Removing unreachable block (ram,0x0881cc) */
/* WARNING: Removing unreachable block (ram,0x0881c6) */
/* WARNING: Removing unreachable block (ram,0x0881be) */
/* WARNING: Removing unreachable block (ram,0x0881b6) */
/* WARNING: Removing unreachable block (ram,0x0881f2) */
/* WARNING: Removing unreachable block (ram,0x0881ee) */
/* WARNING: Removing unreachable block (ram,0x0881ea) */
/* WARNING: Removing unreachable block (ram,0x0881e4) */
/* WARNING: Removing unreachable block (ram,0x0881de) */
/* WARNING: Removing unreachable block (ram,0x0881d6) */
/* WARNING: Removing unreachable block (ram,0x08823e) */
/* WARNING: Removing unreachable block (ram,0x088238) */
/* WARNING: Removing unreachable block (ram,0x088230) */
/* WARNING: Removing unreachable block (ram,0x088228) */
/* WARNING: Removing unreachable block (ram,0x088222) */
/* WARNING: Removing unreachable block (ram,0x088218) */
/* WARNING: Removing unreachable block (ram,0x088214) */
/* WARNING: Removing unreachable block (ram,0x08820c) */
/* WARNING: Removing unreachable block (ram,0x088204) */
/* WARNING: Removing unreachable block (ram,0x0881fe) */
/* WARNING: Removing unreachable block (ram,0x0881a4) */
/* WARNING: Removing unreachable block (ram,0x0881a0) */
/* WARNING: Removing unreachable block (ram,0x08819c) */
/* WARNING: Removing unreachable block (ram,0x088268) */
/* WARNING: Removing unreachable block (ram,0x088260) */
/* WARNING: Removing unreachable block (ram,0x088258) */
/* WARNING: Removing unreachable block (ram,0x088250) */
/* WARNING: Removing unreachable block (ram,0x088290) */
/* WARNING: Removing unreachable block (ram,0x08828a) */
/* WARNING: Removing unreachable block (ram,0x088282) */
/* WARNING: Removing unreachable block (ram,0x08827a) */
/* WARNING: Removing unreachable block (ram,0x088366) */
/* WARNING: Removing unreachable block (ram,0x088362) */
/* WARNING: Removing unreachable block (ram,0x08835e) */
/* WARNING: Removing unreachable block (ram,0x088356) */
/* WARNING: Removing unreachable block (ram,0x08834e) */
/* WARNING: Removing unreachable block (ram,0x088348) */
/* WARNING: Removing unreachable block (ram,0x088340) */
/* WARNING: Removing unreachable block (ram,0x088336) */
/* WARNING: Removing unreachable block (ram,0x088330) */
/* WARNING: Removing unreachable block (ram,0x088324) */
/* WARNING: Removing unreachable block (ram,0x08831a) */
/* WARNING: Removing unreachable block (ram,0x088310) */
/* WARNING: Removing unreachable block (ram,0x088308) */
/* WARNING: Removing unreachable block (ram,0x088302) */
/* WARNING: Removing unreachable block (ram,0x0882fa) */
/* WARNING: Removing unreachable block (ram,0x0882ee) */
/* WARNING: Removing unreachable block (ram,0x0882e2) */
/* WARNING: Removing unreachable block (ram,0x0882d6) */
/* WARNING: Removing unreachable block (ram,0x0882cc) */
/* WARNING: Removing unreachable block (ram,0x0882c2) */
/* WARNING: Removing unreachable block (ram,0x0882ac) */
/* WARNING: Removing unreachable block (ram,0x0882a8) */
/* WARNING: Removing unreachable block (ram,0x0882a4) */
/* WARNING: Removing unreachable block (ram,0x08829e) */
/* WARNING: Removing unreachable block (ram,0x0880f8) */
/* WARNING: Removing unreachable block (ram,0x0880f6) */
/* WARNING: Removing unreachable block (ram,0x0880f0) */
/* WARNING: Removing unreachable block (ram,0x0880e8) */
/* WARNING: Removing unreachable block (ram,0x0880e0) */
/* WARNING: Removing unreachable block (ram,0x0880da) */
/* WARNING: Removing unreachable block (ram,0x08811e) */
/* WARNING: Removing unreachable block (ram,0x08811c) */
/* WARNING: Removing unreachable block (ram,0x088118) */
/* WARNING: Removing unreachable block (ram,0x088110) */
/* WARNING: Removing unreachable block (ram,0x088108) */
/* WARNING: Removing unreachable block (ram,0x088102) */
/* WARNING: Removing unreachable block (ram,0x088142) */
/* WARNING: Removing unreachable block (ram,0x088140) */
/* WARNING: Removing unreachable block (ram,0x08813c) */
/* WARNING: Removing unreachable block (ram,0x088138) */
/* WARNING: Removing unreachable block (ram,0x088134) */
/* WARNING: Removing unreachable block (ram,0x08812e) */
/* WARNING: Removing unreachable block (ram,0x088126) */
/* WARNING: Removing unreachable block (ram,0x0880c2) */
/* WARNING: Removing unreachable block (ram,0x0880be) */
/* WARNING: Removing unreachable block (ram,0x0880ba) */
/* WARNING: Removing unreachable block (ram,0x08809e) */
/* WARNING: Removing unreachable block (ram,0x08809a) */
/* WARNING: Removing unreachable block (ram,0x088096) */
/* WARNING: Removing unreachable block (ram,0x0881b0) */
/* WARNING: Removing unreachable block (ram,0x088180) */
/* WARNING: Removing unreachable block (ram,0x08815c) */

void egs52_boot_service_83(void)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = uRam00f464;
  uRam00f581 = 0x12;
  uVar1 = 0x24;
  if ((((uRam00f462 & 0xc000) != 0) && (uVar1 = 0x21, (uRam00f462 & 0xc000) != 0x4000)) &&
     (uVar1 = 0x2c, (uRam00f462 & 0xc000) != 0x8000)) {
    uVar1 = 3;
  }
  cVar2 = *(char *)((uint3)uVar1 << 0xe | (uint3)(uRam00f462 & 0x3fff));
  if (cVar2 == '\0') {
    uRam00f469 = 7;
    if (cRam00f580 == '\x01') {
      uVar3 = uRam00f464 + 1;
      uVar1 = 0x24;
      if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) = 4;
      uVar3 = uVar4 + 2;
      uVar1 = 0x24;
      if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) = 1;
      uVar3 = uVar4 + 3;
      uVar1 = 0x24;
      if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) = 0x38;
      uVar3 = uVar4 + 4;
      uVar1 = 0x24;
      if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) = 0x14;
      uVar4 = uVar4 + 5;
      uVar1 = 0x24;
      if ((((uVar4 & 0xc000) != 0) && (uVar1 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar4 & 0x3fff)) = 0;
      uRam00f581 = 0;
      return;
    }
    if (cRam00f580 == '\x02') {
      uVar3 = uRam00f464 + 1;
      uVar1 = 0x24;
      if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) = 0;
      uVar3 = uVar4 + 2;
      uVar1 = 0x24;
      if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) = 2;
      uVar3 = uVar4 + 3;
      uVar1 = 0x24;
      if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) = 0x18;
      uVar3 = uVar4 + 4;
      uVar1 = 0x24;
      if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) = 0x78;
      uVar4 = uVar4 + 5;
      uVar1 = 0x24;
      if ((((uVar4 & 0xc000) != 0) && (uVar1 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar4 & 0x3fff)) = 0;
      uRam00f581 = 0;
      return;
    }
    if (cRam00f580 == '\x03') {
      uVar1 = 0x24;
      if ((((uRam00f464 & 0xc000) != 0) && (uVar1 = 0x21, (uRam00f464 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uRam00f464 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uRam00f464 & 0x3fff)) = 0;
      uVar3 = uVar4 + 1;
      uVar1 = 0x24;
      if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) = 0x12;
      uVar3 = uVar4 + 2;
      uVar1 = 0x24;
      if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) = 1;
      uVar3 = uVar4 + 3;
      uVar1 = 0x24;
      if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) = 0;
      uVar3 = uVar4 + 4;
      uVar1 = 0x24;
      if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) = 1;
      uVar4 = uVar4 + 5;
      uVar1 = 0x24;
      if ((((uVar4 & 0xc000) != 0) && (uVar1 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar4 & 0x3fff)) = 0;
      uRam00f581 = 0;
      return;
    }
  }
  else {
    if (cVar2 == '\x01') {
      uVar1 = Ram00fdea;
      if (((uVar1 & 4) != 0) && (uVar1 = Ram00fdea, (uVar1 & 8) == 0)) {
        uRam00f57c = 0x19;
        uRam00f574 = 0x1f5;
        uRam00f576 = 5000;
        uRam00f578 = 0x37;
        uVar1 = Ram00fdec;
        Ram00fdec = uVar1 & 0xfff7;
        uVar1 = Ram00fdec;
        Ram00fdec = uVar1 & 0xffef;
        uVar1 = Ram00fdea;
        Ram00fdea = uVar1 & 0xfffb;
        uVar1 = Ram00fdea;
        Ram00fdea = uVar1 & 0xfff7;
        return;
      }
      uVar1 = Ram00fdec;
      if ((uVar1 & 0x20) == 0) {
        uVar1 = Ram00fdea;
        Ram00fdea = uVar1 | 4;
        uVar1 = Ram00fdea;
        Ram00fdea = uVar1 & 0xfff7;
      }
      else {
        uVar1 = 0x24;
        if ((((uRam00f464 & 0xc000) != 0) && (uVar1 = 0x21, (uRam00f464 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uRam00f464 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uRam00f464 & 0x3fff)) = 1;
        uVar1 = Ram00fdec;
        Ram00fdec = uVar1 & 0xfeff;
      }
      uRam00f581 = 0;
      uRam00f469 = 2;
      return;
    }
    if (cVar2 == '\x02') {
      uRam00f469 = 7;
      uRam00f581 = 0;
      uVar1 = Ram00fdec;
      if ((uVar1 & 8) != 0) {
        uVar3 = uRam00f464 + 1;
        uVar1 = 0x24;
        if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) = 4;
        uVar3 = uVar4 + 2;
        uVar1 = 0x24;
        if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) = 1;
        uVar3 = uVar4 + 3;
        uVar1 = 0x24;
        if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) = 0x38;
        uVar3 = uVar4 + 4;
        uVar1 = 0x24;
        if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) = 0x14;
        uVar4 = uVar4 + 5;
        uVar1 = 0x24;
        if ((((uVar4 & 0xc000) != 0) && (uVar1 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar4 & 0x3fff)) = 0;
        return;
      }
      uVar1 = Ram00fdec;
      if ((uVar1 & 0x100) == 0) {
        uVar1 = Ram00fdec;
        if ((uVar1 & 0x10) == 0) {
          uVar3 = uRam00f464 + 1;
          uVar1 = 0x24;
          if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
             (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
            uVar1 = 3;
          }
          *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) = 0x32;
          uVar3 = uVar4 + 2;
          uVar1 = 0x24;
          if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
             (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
            uVar1 = 3;
          }
          *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) = 2;
          uVar3 = uVar4 + 3;
          uVar1 = 0x24;
          if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
             (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
            uVar1 = 3;
          }
          *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) = 0x6e;
          uVar3 = uVar4 + 4;
          uVar1 = 0x24;
          if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
             (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
            uVar1 = 3;
          }
          *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) = 0x14;
          uVar4 = uVar4 + 5;
          uVar1 = 0x24;
          if ((((uVar4 & 0xc000) != 0) && (uVar1 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
             (uVar1 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
            uVar1 = 3;
          }
          *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar4 & 0x3fff)) = 10;
          return;
        }
        uVar3 = uRam00f464 + 1;
        uVar1 = 0x24;
        if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) = 0;
        uVar3 = uVar4 + 2;
        uVar1 = 0x24;
        if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) = 2;
        uVar3 = uVar4 + 3;
        uVar1 = 0x24;
        if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) = 0x18;
        uVar3 = uVar4 + 4;
        uVar1 = 0x24;
        if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) = 0x78;
        uVar4 = uVar4 + 5;
        uVar1 = 0x24;
        if ((((uVar4 & 0xc000) != 0) && (uVar1 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
           (uVar1 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
          uVar1 = 3;
        }
        *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar4 & 0x3fff)) = 0;
        return;
      }
      uVar1 = 0x24;
      if ((((uRam00f464 & 0xc000) != 0) && (uVar1 = 0x21, (uRam00f464 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uRam00f464 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uRam00f464 & 0x3fff)) = 2;
      uVar3 = uVar4 + 1;
      uVar1 = 0x24;
      if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) = 0x12;
      uVar3 = uVar4 + 2;
      uVar1 = 0x24;
      if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) = 1;
      uVar3 = uVar4 + 3;
      uVar1 = 0x24;
      if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) = 0;
      uVar3 = uVar4 + 4;
      uVar1 = 0x24;
      if ((((uVar3 & 0xc000) != 0) && (uVar1 = 0x21, (uVar3 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar3 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar3 & 0x3fff)) = 1;
      uVar4 = uVar4 + 5;
      uVar1 = 0x24;
      if ((((uVar4 & 0xc000) != 0) && (uVar1 = 0x21, (uVar4 & 0xc000) != 0x4000)) &&
         (uVar1 = 0x2c, (uVar4 & 0xc000) != 0x8000)) {
        uVar1 = 3;
      }
      *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uVar4 & 0x3fff)) = 0;
      return;
    }
    if (cVar2 == '\x03') {
      uVar1 = Ram00fdea;
      if (((uVar1 & 4) == 0) || (uVar1 = Ram00fdea, (uVar1 & 8) != 0)) {
        uRam00f581 = 0x22;
        uRam00f469 = 2;
        if (cRam00f580 == '\x01') {
          uVar1 = uRam00f462 + 1;
          uVar4 = 0x24;
          if ((((uVar1 & 0xc000) != 0) && (uVar4 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
             (uVar4 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
            uVar4 = 3;
          }
          if (*(char *)((uint3)uVar4 << 0xe | (uint3)(uVar1 & 0x3fff)) == '\x04') {
            uVar1 = uRam00f462 + 2;
            uVar4 = 0x24;
            if ((((uVar1 & 0xc000) != 0) && (uVar4 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
               (uVar4 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
              uVar4 = 3;
            }
            if (*(char *)((uint3)uVar4 << 0xe | (uint3)(uVar1 & 0x3fff)) == '\x01') {
              uVar1 = uRam00f462 + 3;
              uVar4 = 0x24;
              if ((((uVar1 & 0xc000) != 0) && (uVar4 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
                 (uVar4 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
                uVar4 = 3;
              }
              if (*(char *)((uint3)uVar4 << 0xe | (uint3)(uVar1 & 0x3fff)) == '8') {
                uVar1 = uRam00f462 + 4;
                uVar4 = 0x24;
                if ((((uVar1 & 0xc000) != 0) && (uVar4 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
                   (uVar4 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
                  uVar4 = 3;
                }
                if (*(char *)((uint3)uVar4 << 0xe | (uint3)(uVar1 & 0x3fff)) == '\x14') {
                  uVar1 = uRam00f462 + 5;
                  uVar4 = 0x24;
                  if ((((uVar1 & 0xc000) != 0) && (uVar4 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
                     (uVar4 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
                    uVar4 = 3;
                  }
                  if (*(char *)((uint3)uVar4 << 0xe | (uint3)(uVar1 & 0x3fff)) == '\0') {
                    uVar1 = Ram00fdea;
                    Ram00fdea = uVar1 | 4;
                    uVar1 = Ram00fdea;
                    Ram00fdea = uVar1 & 0xfff7;
                    uRam00f581 = 0;
                    uVar1 = Ram00fdec;
                    Ram00fdec = uVar1 | 8;
                    return;
                  }
                }
              }
            }
          }
        }
        else if (cRam00f580 == '\x02') {
          uVar1 = uRam00f462 + 1;
          uVar4 = 0x24;
          if ((((uVar1 & 0xc000) != 0) && (uVar4 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
             (uVar4 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
            uVar4 = 3;
          }
          if (*(char *)((uint3)uVar4 << 0xe | (uint3)(uVar1 & 0x3fff)) == '\0') {
            uVar1 = uRam00f462 + 2;
            uVar4 = 0x24;
            if ((((uVar1 & 0xc000) != 0) && (uVar4 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
               (uVar4 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
              uVar4 = 3;
            }
            if (*(char *)((uint3)uVar4 << 0xe | (uint3)(uVar1 & 0x3fff)) == '\x02') {
              uVar1 = uRam00f462 + 3;
              uVar4 = 0x24;
              if ((((uVar1 & 0xc000) != 0) && (uVar4 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
                 (uVar4 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
                uVar4 = 3;
              }
              if (*(char *)((uint3)uVar4 << 0xe | (uint3)(uVar1 & 0x3fff)) == '\x18') {
                uVar1 = uRam00f462 + 4;
                uVar4 = 0x24;
                if ((((uVar1 & 0xc000) != 0) && (uVar4 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
                   (uVar4 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
                  uVar4 = 3;
                }
                if (*(char *)((uint3)uVar4 << 0xe | (uint3)(uVar1 & 0x3fff)) == 'x') {
                  uVar1 = uRam00f462 + 5;
                  uVar4 = 0x24;
                  if ((((uVar1 & 0xc000) != 0) && (uVar4 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
                     (uVar4 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
                    uVar4 = 3;
                  }
                  if (*(char *)((uint3)uVar4 << 0xe | (uint3)(uVar1 & 0x3fff)) == '\0') {
                    uVar1 = Ram00fdec;
                    Ram00fdec = uVar1 | 0x10;
                    uVar1 = Ram00fdea;
                    Ram00fdea = uVar1 | 4;
                    uVar1 = Ram00fdea;
                    Ram00fdea = uVar1 & 0xfff7;
                    uRam00f581 = 0;
                    return;
                  }
                }
              }
            }
          }
        }
        else if (cRam00f580 == '\x03') {
          uVar1 = uRam00f462 + 1;
          uVar4 = 0x24;
          if ((((uVar1 & 0xc000) != 0) && (uVar4 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
             (uVar4 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
            uVar4 = 3;
          }
          if (*(char *)((uint3)uVar4 << 0xe | (uint3)(uVar1 & 0x3fff)) == '\x12') {
            uVar1 = uRam00f462 + 2;
            uVar4 = 0x24;
            if ((((uVar1 & 0xc000) != 0) && (uVar4 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
               (uVar4 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
              uVar4 = 3;
            }
            if (*(char *)((uint3)uVar4 << 0xe | (uint3)(uVar1 & 0x3fff)) == '\x01') {
              uVar1 = uRam00f462 + 3;
              uVar4 = 0x24;
              if ((((uVar1 & 0xc000) != 0) && (uVar4 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
                 (uVar4 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
                uVar4 = 3;
              }
              if (*(char *)((uint3)uVar4 << 0xe | (uint3)(uVar1 & 0x3fff)) == '\0') {
                uVar1 = uRam00f462 + 4;
                uVar4 = 0x24;
                if ((((uVar1 & 0xc000) != 0) && (uVar4 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
                   (uVar4 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
                  uVar4 = 3;
                }
                if (*(char *)((uint3)uVar4 << 0xe | (uint3)(uVar1 & 0x3fff)) == '\x01') {
                  uVar1 = uRam00f462 + 5;
                  uVar4 = 0x24;
                  if ((((uVar1 & 0xc000) != 0) && (uVar4 = 0x21, (uVar1 & 0xc000) != 0x4000)) &&
                     (uVar4 = 0x2c, (uVar1 & 0xc000) != 0x8000)) {
                    uVar4 = 3;
                  }
                  if (*(char *)((uint3)uVar4 << 0xe | (uint3)(uVar1 & 0x3fff)) == '\0') {
                    uVar1 = 0x24;
                    if ((((uRam00f464 & 0xc000) != 0) &&
                        (uVar1 = 0x21, (uRam00f464 & 0xc000) != 0x4000)) &&
                       (uVar1 = 0x2c, (uRam00f464 & 0xc000) != 0x8000)) {
                      uVar1 = 3;
                    }
                    *(undefined1 *)((uint3)uVar1 << 0xe | (uint3)(uRam00f464 & 0x3fff)) = 3;
                    uVar1 = Ram00fdec;
                    Ram00fdec = uVar1 | 0x100;
                    uRam00f581 = 0;
                  }
                }
              }
            }
          }
        }
      }
      else {
        uVar1 = Ram00fdec;
        if ((uVar1 & 8) != 0) {
          uRam00f57c = 2;
          uRam00f574 = 0x1f5;
          uRam00f576 = 5000;
          uRam00f578 = 0x1c;
          uVar1 = Ram00fdea;
          Ram00fdea = uVar1 & 0xfffb;
          uVar1 = Ram00fdea;
          Ram00fdea = uVar1 & 0xfff7;
          return;
        }
        uVar1 = Ram00fdec;
        if ((uVar1 & 0x10) != 0) {
          uRam00f57c = 0;
          uRam00f574 = 0xbb9;
          uRam00f576 = 30000;
          uRam00f578 = 0xc;
          uVar1 = Ram00fdea;
          Ram00fdea = uVar1 & 0xfffb;
          uVar1 = Ram00fdea;
          Ram00fdea = uVar1 & 0xfff7;
          return;
        }
      }
    }
  }
  return;
}


