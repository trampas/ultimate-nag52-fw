/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x0a5b5e; FLS offset 0x025b5e.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Function: egs52_read_far_u32_registers replaced with injection:
   egs52_read_far_u32_registers */
/* WARNING: Removing unreachable block (ram,0x0a5c3a) */
/* WARNING: Removing unreachable block (ram,0x0a5c36) */
/* WARNING: Removing unreachable block (ram,0x0a5c30) */
/* WARNING: Removing unreachable block (ram,0x0a5c2c) */
/* WARNING: Removing unreachable block (ram,0x0a5c1e) */
/* WARNING: Removing unreachable block (ram,0x0a5c1a) */
/* WARNING: Removing unreachable block (ram,0x0a5c0c) */
/* WARNING: Removing unreachable block (ram,0x0a5c06) */
/* WARNING: Removing unreachable block (ram,0x0a5c02) */
/* WARNING: Removing unreachable block (ram,0x0a5bfc) */
/* WARNING: Removing unreachable block (ram,0x0a5bf8) */
/* WARNING: Removing unreachable block (ram,0x0a5bec) */
/* WARNING: Removing unreachable block (ram,0x0a5be6) */
/* WARNING: Removing unreachable block (ram,0x0a5bdc) */
/* WARNING: Removing unreachable block (ram,0x0a5bd8) */
/* WARNING: Removing unreachable block (ram,0x0a5bd2) */
/* WARNING: Removing unreachable block (ram,0x0a5bce) */
/* WARNING: Removing unreachable block (ram,0x0a5bb6) */
/* WARNING: Removing unreachable block (ram,0x0a5bb2) */
/* WARNING: Removing unreachable block (ram,0x0a5b9c) */
/* WARNING: Removing unreachable block (ram,0x0a5b96) */
/* WARNING: Removing unreachable block (ram,0x0a5b8a) */
/* WARNING: Removing unreachable block (ram,0x0a5b84) */
/* WARNING: Removing unreachable block (ram,0x0a5b80) */
/* WARNING: Removing unreachable block (ram,0x0a5b74) */
/* WARNING: Removing unreachable block (ram,0x0a5b6e) */

void egs52_transform_far_memory_0a5b5e(uint param_1,char param_2)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  uint uVar6;
  
  Ram00ef00 = 0x41;
  uVar1 = Ram00ef02;
  Ram00ef02 = uVar1 & 0xf8ff | 0x100;
  Ram00ef04 = *(undefined2 *)CONCAT12(param_2,param_1);
  cVar3 = param_2 + (0xfffd < param_1);
  Ram00ef06 = *(undefined2 *)CONCAT12(cVar3,param_1 + 2);
  uVar1 = param_1 + 4;
  cVar4 = param_2 + (0xfffb < param_1);
  Ram00ef0a = *(undefined2 *)CONCAT12(cVar4 + (0xfffd < uVar1),param_1 + 6);
  Ram00ef08 = *(undefined2 *)CONCAT12(cVar4,uVar1);
  uVar2 = param_1 + 8;
  cVar5 = param_2 + (0xfff7 < param_1);
  Ram00ef0e = *(undefined2 *)CONCAT12(cVar5 + (0xfffd < uVar2),param_1 + 10);
  Ram00ef0c = *(undefined2 *)CONCAT12(cVar5,uVar2);
  uVar6 = Ram00ef00;
  Ram00ef00 = uVar6 & 0xffbf;
  Ram00ee00 = 0x41;
  uVar6 = Ram00ee02;
  Ram00ee02 = uVar6 & 0xf8ff | 0x100;
  Ram00ee04 = *(undefined2 *)CONCAT12(param_2,param_1);
  Ram00ee06 = *(undefined2 *)CONCAT12(cVar3,param_1 + 2);
  Ram00ee0a = *(undefined2 *)CONCAT12(cVar4 + (0xfffd < uVar1),param_1 + 6);
  Ram00ee08 = *(undefined2 *)CONCAT12(cVar4,uVar1);
  Ram00ee0e = *(undefined2 *)CONCAT12(cVar5 + (0xfffd < uVar2),param_1 + 10);
  Ram00ee0c = *(undefined2 *)CONCAT12(cVar5,uVar2);
  uVar1 = Ram00ee00;
  Ram00ee00 = uVar1 & 0xffbf;
  return;
}


