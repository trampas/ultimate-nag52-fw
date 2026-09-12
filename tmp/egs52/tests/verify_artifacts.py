#!/usr/bin/env python3
"""Reject stale source, mismatched evidence, and known-invalid published C."""
import argparse
import csv
import hashlib
import json
import re
import subprocess
import sys
from pathlib import Path

ROOT=Path(__file__).resolve().parents[1]
sys.path.insert(0,str(ROOT/'tools'))
from decode_flash import transform, verify, RAW_TO_CPU
from c_listing_checks import known_arities, call_abi_errors


def main():
    raw=(ROOT/'A0325452132.FLS').read_bytes();decoded=transform(raw);verify(raw,decoded)
    # Every possible word has an inverse, not just words present in this dump.
    words=b''.join(i.to_bytes(2,'little') for i in range(65536))
    assert transform(transform(words),inverse=True)==words
    assert sorted(RAW_TO_CPU)==list(range(16))
    try:transform(b'x')
    except ValueError:pass
    else:raise AssertionError('Odd-length input was accepted')
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--artifact-root',type=Path,default=ROOT/'reconstructed')
    root=parser.parse_args().artifact_root;coverage=json.loads((root/'coverage.json').read_text())
    assert coverage['decoded_sha256']==hashlib.sha256(decoded).hexdigest()
    rows=list(csv.DictReader((root/'functions_index.csv').open()))
    assert len(rows)==coverage['functions_discovered']
    assert len({r['address'] for r in rows})==len(rows)
    assert len({r['name'] for r in rows})==len(rows), [(r['address'],r['name']) for r in rows if sum(x['name']==r['name'] for x in rows)>1]
    arities=known_arities(ROOT/'tools')
    sources=set();known_names={r['name'] for r in rows}
    blocked={r['address'] for r in rows if r['status'] in ('withheld','register_abi_in_fixups')}
    assert blocked=={r['address'] for r in csv.DictReader((root/'unresolved.csv').open())}
    for r in rows:
        assert int(r['address'],16)-0x80000==int(r['file_offset'],16)
        if r['source']:
            assert (root/r['source']).is_file(),r
        if r['status']=='decompiled_unverified':
            sources.add(r['source']);s=(root/r['source']).read_text()
            assert 'UNVERIFIED DECOMPILER C' in s
            assert not call_abi_errors(s,arities),(r['address'],call_abi_errors(s,arities))
            assert re.search(r'\b'+re.escape(r['name'])+r'\s*\(',s),r
            assert not re.search(r'\bBADTYPE\b|halt_baddata|Bad instruction|overlaps instruction|Could not recover jumptable|\b(?:unaff_|extraout_|in_)[A-Za-z0-9_]+',s),r
            for name in re.findall(r'\begs52_[A-Za-z0-9_]+(?=\s*\()',s):
                assert name in known_names,('Unindexed or stale function name',r['address'],name)
        elif r['status']=='verified_native':
            name=r['native_symbol']
            assert name in (root/r['source']).read_text()
        else:
            assert not list((root/'functions').glob(r['address']+'_*')),r
    assert sources=={str(p.relative_to(root)) for p in (root/'functions').glob('*.c')}
    assert len(sources)==coverage['decompiler_c_files']
    entries={int(r['address'],16) for r in rows}
    assert not entries.intersection({0xe0034,0xe0036,0xd2f00,0xa000a,0xa01f4}), 'Metadata or calibration values became function roots'
    # These callers previously lost their bodies to calibration-derived roots.
    by_address={r['address']:r for r in rows}
    for address,minimum in [('0a0000',170),('0a01a8',300),('0d2b08',1100)]:
        assert int(by_address[address]['body_bytes'])>=minimum,('Truncated by false root',address)
    expected_callbacks=[]
    for spec in csv.DictReader((ROOT/'tools/callback_tables.csv').open()):
        base=int(spec['base'],16);stride=int(spec['stride'])
        for slot in range(base,base+int(spec['count'])*stride,stride):
            off=slot-0x80000;callback=int.from_bytes(decoded[off:off+4],'little')
            metadata=int.from_bytes(decoded[off+4:off+8],'little') if stride==8 else 0
            assert callback==0 or callback in entries,('Missing audited callback',hex(slot),hex(callback))
            expected_callbacks.append((slot,callback,metadata,stride))
    actual_callbacks=[(int(a,16),int(b,16),int(c,16),int(d)) for a,b,c,d in re.findall(
        r'\{0x([0-9a-f]+)u, 0x([0-9a-f]+)u, 0x([0-9a-f]+)u, ([48])u\}',(root/'egs52_callback_tables.c').read_text())]
    assert actual_callbacks==expected_callbacks
    assert (root/'callback_tables.csv').read_bytes()==(ROOT/'tools/callback_tables.csv').read_bytes()
    subprocess.run(['cc','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-fsyntax-only',str(root/'egs52_callback_tables.c')],check=True)
    expected=[]
    for base,count in ((0x28c,18),(0x31c,17)):
        for slot in range(base,base+8*count,8):
            callback=int.from_bytes(decoded[slot:slot+4],'little')
            metadata=int.from_bytes(decoded[slot+4:slot+8],'little')
            assert callback in entries,('Missing boot service callback',hex(slot+0x80000))
            expected.append((slot+0x80000,callback,metadata))
    dispatch=(root/'egs52_boot_dispatch.c').read_text()
    actual=[tuple(int(x,16) for x in row) for row in re.findall(
        r'\{0x([0-9a-f]+)u, 0x([0-9a-f]+)u, 0x([0-9a-f]+)u\}',dispatch)]
    assert actual==expected, 'Boot dispatch data does not match decoded flash'
    subprocess.run(['cc','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-fsyntax-only',str(root/'egs52_boot_dispatch.c')],check=True)
    n=0
    for line in (root/'firmware.asm').read_text().splitlines():
        a,hexbytes,_=line.split(None,2);address=int(a,16);b=bytes.fromhex(hexbytes)
        assert decoded[address-0x80000:address-0x80000+len(b)]==b,line
        n+=1
    assert n==coverage['instruction_addresses']
    instructions={int(line.split()[0],16) for line in (root/'firmware.asm').read_text().splitlines()}
    jump_rows=list(csv.DictReader((root/'recovered_jumps.csv').open()))
    table_specs={r['site']:r for r in csv.DictReader((ROOT/'tools/jump_tables.csv').open())}
    assert len(jump_rows)==len(table_specs)
    indirect_sites={line.split()[0] for line in (root/'firmware.asm').read_text().splitlines()
                    if re.search(r'\bjmpi\b',line)}
    assert indirect_sites==set(table_specs)|{'0808dc','08095e'}, ('Unaudited indirect jumps',indirect_sites-set(table_specs))
    for row in jump_rows:
        spec=table_specs[row['site']]
        assert all(row[k]==spec[k] for k in ('site','table','count','bank'))
        table=int(row['table'],16);bank=int(row['bank'],16)<<16
        expected=[bank|int.from_bytes(decoded[table-0x80000+2*i:table-0x80000+2*i+2],'little') for i in range(int(row['count']))]
        assert [int(a,16) for a in row['targets'].split(';')]==expected
        assert set(expected)<=instructions,('Undecoded switch destinations',row)
    for name,sha in json.loads((root/'tool_manifest.json').read_text()).items():
        assert hashlib.sha256((ROOT/'tools'/name).read_bytes()).hexdigest()==sha,('Tool changed since rebuild',name)
    subprocess.run(['cc','-std=c11','-Wall','-Wextra','-Werror','-pedantic','-fsyntax-only',str(root/'egs52_vectors.c')],check=True)
    processor_checks=int(re.search(r'EXPECTED_CHECKS=(\d+)',(ROOT/'tools/CheckEgs52Processor.java').read_text())[1])
    assert f'PROCESSOR_REGRESSIONS_PASSED={processor_checks}' in (root/'processor_verification.txt').read_text()
    verification=(root/'verification.txt').read_text()
    counts=re.findall(r'^([a-z0-9_]+) (\d+) PASS$',verification,re.M)
    summary=re.search(r'^(\d+) original-instruction comparisons passed; (\d+) distinct instruction addresses\.$',verification,re.M)
    assert summary and sum(int(n) for _,n in counts)==int(summary[1])
    tested={'egs52_'+name for name,_ in counts}
    native={r['native_symbol'] for r in rows if r['status']=='verified_native'}
    assert native==tested,('Native tests and published implementations differ',native^tested)
    assert len(native)==coverage['native_functions']
    for name,sha in json.loads((root/'verification_manifest.json').read_text()).items():
        assert hashlib.sha256((ROOT/name).read_bytes()).hexdigest()==sha,('Verified source or test changed since rebuild',name)
    print(f'PASS: {len(rows)} indexed entries; {len(sources)} published C listings; {n} instruction-byte checks; no stale/known-invalid published bodies.')


if __name__=='__main__':main()
