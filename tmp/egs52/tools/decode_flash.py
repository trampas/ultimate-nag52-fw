#!/usr/bin/env python3
"""Convert this EGS52 FLS's data-line permutation into CPU-order bytes.

No address permutation, XOR key, byte insertion, or instruction patching.
CPU address = decoded/file offset + 0x80000. See reconstructed/README.md.
"""
from pathlib import Path
import argparse
import hashlib
import json

# Index is the raw little-endian word bit; value is its CPU word bit.
RAW_TO_CPU = (15, 13, 11, 9, 7, 5, 3, 1, 14, 12, 10, 8, 6, 4, 2, 0)
ROOT = Path(__file__).resolve().parents[1]


def permute(word, mapping=RAW_TO_CPU):
    return sum(((word >> source) & 1) << dest for source, dest in enumerate(mapping))


def transform(data, inverse=False):
    if len(data) % 2:
        raise ValueError('flash image must contain whole 16-bit words')
    mapping = tuple(RAW_TO_CPU.index(i) for i in range(16)) if inverse else RAW_TO_CPU
    lut = [permute(i, mapping).to_bytes(2, 'little') for i in range(65536)]
    return b''.join(lut[data[i] | data[i+1] << 8] for i in range(0, len(data), 2))


def verify(raw, decoded):
    assert hashlib.sha256(raw).hexdigest() == 'ebfcce5f29d80ef9d636872ac557a5ced7efc3619f7c842a31d8789f1c7e4099', 'Unsupported or modified input image'
    assert len(raw) == len(decoded) == 0x80000
    assert transform(decoded, inverse=True) == raw
    assert decoded[:4] == bytes.fromhex('fa08d005')
    assert decoded[0x5d0:0x5e2] == bytes.fromhex('e60800f2cc00e6002400e6012100e6022c00')
    for off in (0x5658, 0x32016):
        assert decoded[off:off+11] == b'A0325452132'
    vectors = []
    for off in range(0, 0x200, 4):
        assert decoded[off] == 0xfa
        target = decoded[off+1] << 16 | int.from_bytes(decoded[off+2:off+4], 'little')
        assert 0x80000 <= target < 0x100000 and target % 2 == 0
        vectors.append({'vector': f'{off:03x}', 'target': f'{target:06x}'})
    return {'raw_sha256': hashlib.sha256(raw).hexdigest(),
            'decoded_sha256': hashlib.sha256(decoded).hexdigest(),
            'bytes': len(raw), 'raw_bit_to_cpu_bit': RAW_TO_CPU,
            'cpu_base': '080000', 'roundtrip': True, 'vectors': vectors}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('input', nargs='?', type=Path, default=ROOT/'A0325452132.FLS')
    parser.add_argument('--output', type=Path, default=ROOT/'decoded/A0325452132.bin')
    args = parser.parse_args()
    raw = args.input.read_bytes()
    decoded = transform(raw)
    report = verify(raw, decoded)
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_bytes(decoded)
    args.output.with_suffix('.json').write_text(json.dumps(report, indent=2)+'\n')
    print(f'Decoded {len(decoded)} bytes; all 128 vectors valid; exact inverse verified.')
    print(f'SHA256: {report["decoded_sha256"]}')


if __name__ == '__main__':
    main()
