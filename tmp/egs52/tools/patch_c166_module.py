#!/usr/bin/env python3
"""Apply narrowly scoped C166 SLEIGH corrections; keeps an upstream backup.

BFLDL operand order: Infineon C166 instruction manual v2.0 p53.
EXTR/EXTP/EXTS: prefix context must be committed to the next instruction.
"""
from pathlib import Path
import argparse
import difflib
import hashlib


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('extension',type=Path)
    args=parser.parse_args()
    path=args.extension/'data/languages/c166.sinc'
    original=path.read_text()
    if '# EGS52 corrections' in original:
        original=path.with_suffix('.sinc.upstream').read_text()
    expected='fe4cc16e49509ec9cbdbc904372731648818bda78011eaa25e024baa1d88c6f0'
    if hashlib.sha256(original.encode()).hexdigest()!=expected:
        raise SystemExit('Unrecognized C166 module baseline. Review/update the patch and run processor regressions before exporting C.')
    text=original
    # C166 manual pp47 and 120-122: low four count bits only; right-shift
    # carry is the last bit out, V is the OR of bits shifted out BEFORE it.
    text=text.replace('((a & (1 << (b-1))) > 1)', '((a & (1 << (b-1))) != 0)')
    text=text.replace('(b != 0) && ((a s>> b) << b) != a', '(b > 1) && ((a & ((1 << (b-1)) - 1)) != 0)')
    text=text.replace('(b != 0) && ((a >> b) << b) != a', '(b > 1) && ((a & ((1 << (b-1)) - 1)) != 0)')
    for macro in ('Ashr','Rol','Ror','Shl','Shr'):
        start=text.index('macro '+macro+'(');end=text.index('\n}',start)+2
        block=text[start:end].replace('local tmpB = b;', 'local tmpB = b & 0xf;')
        if macro=='Ror':block=block.replace('setPreFlagsShr(tmpA, tmpB);', 'setPreFlagsShr(tmpA, tmpB);\n\t$(PSW_V) = 0;')
        text=text[:start]+block+text[end:]
    text=text.replace('mask8 = (8,15)', 'mask8 = (8,15)\n\tmask_low = (0,7)\n\tdata_high = (8,15)')
    a=text.index(':bfldl ');z=text.index('\n}',a)+2
    body=text[a:z].replace('"#"^mask8, DataImmB','"#"^mask_low, "#"^data_high')
    body=body.replace('DataImmB & mask8','mask_low & data_high').replace('mask8:1','mask_low:1').replace('zext(DataImmB)','zext(data_high:1)')
    text=text[:a]+body+text[z:]
    text=text.replace('globalset(inst_start,', 'globalset(inst_next,')
    # Prefix constructors must not run the generic context reset after setting
    # their own context. Ghidra evaluates the subtables before that reset.
    for op in ('extr','extp','extpr','exts','extsr','atomic'):
        import re
        text=re.sub(r'(:'+op+r' [^\n]*? is )ExtCountDec & ', r'\1',text)
    text=re.sub(r'ExtCountDec: is Counter=1 \[.*?\] \{', 'ExtCountDec: is Counter=1 [ Counter=0; globalset(inst_next, Counter); ] {', text)
    # Represent DPP register accesses as the same registers used in address
    # calculation. Otherwise writes went to unrelated RAM varnodes.
    text=text.replace('define register offset=0xFE10 size=2 [ CP ];', 'define register offset=0xFE10 size=2 [ CP SP ];')
    start=text.index('macro Push(a)');end=text.index('macro ReturnIntra()',start)
    text=text[:start]+text[start:end].replace('r0','SP').replace('segment(0:2, SP)','zext(SP)')+text[end:]
    # Remove the special MOV Rn,[Rn] switch heuristic: it ignored EXTP/EXTS
    # and did not implement MOV flags. The ordinary constructor is correct.
    text=re.sub(r':mov rwn, \[rwm\] is [^\n]*RWnRWmEqual \{.*?\n\}', '', text, flags=re.S)
    aliases={0:"DPP0",1:"DPP1",2:"DPP2",3:"DPP3",4:"CSP",9:"SP",0x88:"PSW"}
    definitions=[]
    for number,name in aliases.items():
        address=0xfe00+2*number
        definitions += [f"ShortMemAddrW: regoff is ExtrEn=0 & reg=0x{number:x} & reg [ regoff=0x{address:x}; ] {{ export {name}; }}",
                        f"LongMemAddrW: memoff is ExtsEn=0 & ExtpEn=0 & mem=0x{address:x} & mem [ memoff=0x{address:x}; ] {{ export {name}; }}"]
    # Replace the Java address injectors: they substituted raw offsets or page
    # zero for dynamic EXTS/EXTP and selected a DPP before register addition.
    text=text.replace("DataImmW: ", Path(__file__).with_name('c166_addressing.sinc').read_text()+"\nDataImmW: ",1)
    lines=[]
    for line in text.splitlines():
        if re.match(r'(RwnInd|RwmInd)',line) and 'Counter=0' in line:
            continue
        if 'c166_reg_offset_addr(' in line or 'GetPagedOffset(' in line:
            if ': is ' not in line and ': ' not in line:
                lines.append(line);continue
            line=line.replace(' is mem {',' is mem & AddressMode {')
            line=re.sub(r'( is [^{]*?)( \{)',r'\1 & AddressMode\2',line) if 'AddressMode' not in line else line
            line=re.sub(r'local (\w+):3 = GetPagedOffset\(mem:2\);',r'local \1:3; egs52Address(\1, mem:2, AddressMode);',line)
            line=re.sub(r'local (\w+):3 = c166_reg_offset_addr\((rwm|rwn), ([^;]+)\);',r'local \1:3; local sum:2 = \2 + \3; egs52Address(\1, sum, AddressMode);',line)
        lines.append(line)
    text='\n'.join(lines)+'\n'
    # R0 is the ABI's internal-RAM user stack. Preserve Ghidra's stack model
    # outside prefixes; other register-indirect addresses remain fully paged.
    stack_lines=[line for line in original.splitlines() if re.match(r'(RwnInd|RwmInd)',line) and 'Counter=0' in line]
    text+='\n'+'\n'.join(stack_lines)+'\n'

    # Compact arithmetic indirect operands need the same paging semantics.
    text=re.sub(r'^IndexImm[WB]:.*?rwi=0.*?\n','',text,flags=re.M)
    text=text.replace('is idx_imm=1 & idx_mode=0 & rwi { local addr:3 = segment(0:2, rwi);',
                      'is idx_imm=1 & idx_mode=0 & rwi & AddressMode { local addr:3; egs52Address(addr, rwi, AddressMode);')
    text=text.replace('is idx_imm=1 & idx_mode=1 & rwi { local addr:3 = segment(0:2, rwi);',
                      'is idx_imm=1 & idx_mode=1 & rwi & AddressMode { local addr:3; egs52Address(addr, rwi, AddressMode);')
    # The runtime value is assigned by the prefix, never guessed as zero.
    for op,assignment in [('extp','ExtpValue = rwm;'),('extpr','ExtpValue = rwm;'),
                          ('exts','ExtsValue = rwm:1;'),('extsr','ExtsValue = rwm:1;')]:
        text=re.sub(r'(:'+op+r' SetExt[ps]Ind is [^\n]*?)\{ local NOP:1 = 0; \}', r'\1{ '+assignment+' }',text)
    for op,assignment in [('extp','ExtpValue = page;'),('extpr','ExtpValue = page;'),
                          ('exts','ExtsValue = seg:1;'),('extsr','ExtsValue = seg:1;')]:
        # page/seg are nested fields: export the value from SetExtp/SetExts.
        arg='SetExtp' if 'extp' in op else 'SetExts'
        assignment=assignment.replace('page',arg).replace('seg:1',arg+':1')
        text=re.sub(r'(:'+op+' '+arg+r' is [^\n]*?)\{ local NOP:1 = 0; \}',r'\1{ '+assignment+' }',text)
    text=re.sub(r'(SetExtp: [^\n]*?)\{ local NOP:1 = 0; \}',r'\1{ local value:2 = page; export value; }',text)
    text=re.sub(r'(SetExts: [^\n]*?)\{ local NOP:1 = 0; \}',r'\1{ local value:2 = seg; export value; }',text)
    # Indirect prefix fields are also nested; use the subtable export.
    text=re.sub(r'(SetExtpInd: [^\n]*?)\{ local NOP:1 = 0; \}',r'\1{ export rwm; }',text)
    text=re.sub(r'(SetExtsInd: [^\n]*?)\{ local NOP:1 = 0; \}',r'\1{ export rwm; }',text)
    text=text.replace('ExtpValue = rwm;', 'ExtpValue = SetExtpInd;').replace('ExtsValue = rwm:1;', 'ExtsValue = SetExtsInd:1;')
    text+='\n'+'\n'.join(definitions)+'\n'
    text+='BitoffAddr: regoff is ExtrEn=0 & reg=0x88 & bitoff [ regoff=0xff10; ] { export PSW; }\n'
    text+='BitoffAddrZ: regoff is ExtrEn=0 & z=0x8 & z_2=0x8 [ regoff=0xff10; ] { export PSW; }\n'
    text+='\n'+Path(__file__).with_name('c166_psw.sinc').read_text()+'\n'
    # The target's ordinary data pointers and int are 16 bits. Long is 32.
    cspec=path.with_name('c166.cspec');csbackup=cspec.with_suffix('.cspec.upstream')
    if not csbackup.exists():csbackup.write_text(cspec.read_text())
    cs=csbackup.read_text().replace('<pointer_size value="3"/>','<pointer_size value="2"/>\n        <integer_size value="2"/>\n        <long_size value="4"/>')
    cs=cs.replace('</compiler_spec>', Path(__file__).with_name('c166_runtime_fixups.xml').read_text()+'\n</compiler_spec>')
    cspec.write_text(cs)
    text='# EGS52 corrections (see tools/patch_c166_module.py)\n'+text
    backup=path.with_suffix('.sinc.upstream')
    if not backup.exists():backup.write_text(original)
    path.write_text(text)
    Path(__file__).with_suffix('.patch').write_text(''.join(difflib.unified_diff(original.splitlines(True),text.splitlines(True),fromfile='c166.sinc.upstream',tofile='c166.sinc')))
    sla=path.with_name('c166.sla')
    if sla.exists():sla.unlink()
    print('Applied EGS52 processor and compiler-model corrections')


if __name__=='__main__':main()
