/* UNVERIFIED DECOMPILER C. Register ABI, memory aliasing and hardware
 * effects require review. Native verified equivalents are indexed separately.
 * C166 types: int/uint = 16 bits; long/ulong = 32; near pointers = 16.
 */
/* Decoded EGS52; CPU 0x081058; FLS offset 0x001058.
 * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */

/* WARNING: Removing unreachable block (ram,0x081082) */
/* WARNING: Removing unreachable block (ram,0x08106a) */
/* WARNING: Removing unreachable block (ram,0x08107a) */
/* WARNING: Removing unreachable block (ram,0x081084) */

bool egs52_transform_far_memory_081058(uint param_1,char param_2,int param_3,byte param_4)

{
  bool bVar1;
  bool bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  
  bVar2 = false;
  bVar3 = 1;
  bVar4 = 0;
  bVar5 = param_4;
  while ((bVar3 < 4 && (!bVar2))) {
    if (*(char *)CONCAT12(param_2,param_1) ==
        *(char *)CONCAT12(param_2 + CARRY2(param_1,(uint)bVar5),param_1 + bVar5)) {
      *(undefined1 *)CONCAT12(param_2,param_3) = *(undefined1 *)CONCAT12(param_2,param_1);
      param_3 = param_3 + 1;
      bVar1 = 0xfffe < param_1;
      param_1 = param_1 + 1;
      param_2 = param_2 + bVar1;
      bVar4 = bVar4 + 1;
      if (bVar4 == param_4) {
        bVar2 = true;
      }
    }
    else {
      bVar3 = bVar3 + 1;
      param_3 = param_3 - (uint)bVar4;
      bVar1 = param_1 < bVar4;
      param_1 = param_1 - bVar4;
      param_2 = param_2 - bVar1;
      if (bVar3 == 2) {
        bVar5 = param_4 << 1;
      }
      else {
        bVar1 = CARRY2(param_1,(uint)param_4);
        param_1 = param_1 + param_4;
        param_2 = param_2 + bVar1;
        bVar5 = param_4;
      }
      bVar4 = 0;
    }
  }
  return bVar2;
}


