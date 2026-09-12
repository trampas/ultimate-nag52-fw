#!/usr/bin/env python3
"""Read-only scan of the supported EGS52 dump in its decoded CPU byte order."""
import argparse
import re
from pathlib import Path
from tools.decode_flash import ROOT, transform, verify


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('path',nargs='?',type=Path,default=ROOT/'A0325452132.FLS')
    args=parser.parse_args()
    raw=args.path.read_bytes();decoded=transform(raw);report=verify(raw,decoded)
    print(f'Input: {args.path}\nBytes: {len(raw)}')
    print('Raw SHA256: '+report['raw_sha256'])
    print('Decoded SHA256: '+report['decoded_sha256'])
    print('128 primary vectors valid; exact inverse transform verified.')
    print('CPU flash base: 0x080000. Addresses below are CPU addresses.')
    print('Decoded printable strings (minimum 12 characters; may include data coincidences):')
    for match in re.finditer(rb'[ -~]{12,}',decoded):
        print(f'{match.start()+0x80000:06x}: {match.group().decode("ascii")}')


if __name__=='__main__':main()
