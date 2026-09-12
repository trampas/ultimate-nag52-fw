#!/usr/bin/env python3
"""Regressions for the lost argument at the 0x0e0036 weighted-filter call."""
import sys
from pathlib import Path
sys.path.insert(0,str(Path(__file__).resolve().parents[1]/'tools'))
from c_listing_checks import call_abi_errors

name='egs52_weighted_average_s16'
arity={name:3}
assert call_abi_errors(f'{name}(weight, old);',arity)
assert not call_abi_errors(f'{name}(weight, next, old);',arity)
assert not call_abi_errors(f'{name}\n((uchar)*(base + offset), helper(x, y), old);',arity)
assert not call_abi_errors(f'/* {name}(bad) */ "{name}(bad)";',arity)
assert not call_abi_errors(f'{name}(a, (short[]){{1, 2}}[0], b);',arity)
assert call_abi_errors(f'{name}(a,b,c',arity)
assert not call_abi_errors('egs52_zero_args(void); egs52_zero_args();',{'egs52_zero_args':0})
assert call_abi_errors('egs52_zero_args(1);',{'egs52_zero_args':0})

# Literal tokens are real arguments; erase their contents, not their presence.
assert not call_abi_errors("egs52_one_arg('\\x02');",{'egs52_one_arg':1})
assert not call_abi_errors('egs52_one_arg("a,b");',{'egs52_one_arg':1})
assert not call_abi_errors("egs52_one_arg(',');",{'egs52_one_arg':1})
assert call_abi_errors('egs52_one_arg(/* absent */);',{'egs52_one_arg':1})
print('PASS: missing-argument, literal-argument and nested-expression listing regressions')
