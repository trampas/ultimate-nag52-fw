"""Check only established ROM call signatures, not inferred host C types."""
import csv
import re
from pathlib import Path


def known_arities(tools: Path):
    names={r['address']:r['name'] for r in csv.DictReader((tools/'symbols.csv').open())}
    rows=list(csv.DictReader((tools/'native_abi.csv').open()))
    missing={r['address'] for r in rows}-names.keys()
    if missing:raise ValueError('ABI entries require names in symbols.csv: '+', '.join(sorted(missing)))
    return {names[r['address']]:(len(r['parameters'].split(';')) if r['parameters'] else 0) for r in rows}


def call_abi_errors(source, arities):
    # Comments and literals cannot introduce calls or argument separators.
    source=re.sub(r'/\*.*?\*/|//[^\n]*|"(?:\\.|[^"\\])*"|\'(?:\\.|[^\'\\])*\'',
                  lambda m: ' ' if m[0].startswith(('/*','//')) else '0',source,flags=re.S)
    errors=[]
    for match in re.finditer(r'\b(egs52_[A-Za-z0-9_]+)\s*\(',source):
        name=match[1]
        if name not in arities:continue
        start=match.end();stack=['('];commas=0;end=start
        for end in range(start,len(source)):
            c=source[end]
            if c in '([{':stack.append(c)
            elif c in ')]}':
                if not stack or stack.pop()!={')':'(',']':'[','}':'{'}[c]:
                    errors.append(f'{name}: unbalanced call');break
                if not stack:break
            elif c==',' and len(stack)==1:commas+=1
        if stack:
            errors.append(f'{name}: unterminated call');continue
        args=source[start:end].strip()
        count=0 if args in ('','void') else commas+1
        if count!=arities[name]:errors.append(f'{name}: expected {arities[name]} arguments; found {count}')
    return errors
