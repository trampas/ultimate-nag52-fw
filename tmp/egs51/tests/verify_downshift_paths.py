#!/usr/bin/env python3
"""Targeted raw-ROM downshift gates and command-order evidence.

Full supervisor calls use real selected calibration. Pressure-handler fragments
are explicitly isolated: they prove command operations, not a complete hydraulic
trajectory or reachability from boot. No instruction/callee is hooked.
"""
from verify_model import ROM, base, word


def fixture(mode=3):
    cpu = base()
    cpu.x[0x17b] = 0x20
    cpu.x[0x17c] = 0x22
    cpu.run(0x20bc)
    assert cpu.r(7) == 0
    for address, value in ((0xa9, 3), (0xb9, 4), (0xb3, 4), (0xac, 8),
                           (0xb6, mode), (0xaa, 1 if mode == 3 else 3),
                           (0xb4, 2 if mode == 3 else 4), (0xb5, 3), (0x95, 1)):
        cpu.im[address] = value
    for address, value in ((0x334, 5), (0x76, 200), (0x202, 255),
                           (0x285, 255 if mode == 3 else 0)):
        cpu.x[address] = value
    for address, value in ((0x2b9, 2000 if mode == 3 else 0), (0x2bb, 30000),
                           (0x1d6, 100), (0x303, 100), (0x398, 0)):
        word(cpu.x, address, value)
    return cpu


def main():
    cpu = fixture()
    cpu.run(0x236a)
    assert 0x295e in cpu.visited
    assert (cpu.im[0xb9], cpu.im[0xac], cpu.im[0xaa], cpu.im[0x96] & 3) == (4, 8, 6, 3)
    assert cpu.im[0xb4] == cpu.im[0xb5] == 0
    print('PASS: mode3 further-downshift request enters phase6 without decrementing B9')

    # Each condition independently prevents the phase6 entry in the same fixture.
    for label, changes in (
        ('no further demand', [('im', 0xa9, 4)]),
        ('wrong phase', [('im', 0xaa, 2)]),
        ('substates too early', [('im', 0xb4, 1), ('im', 0xb5, 2)]),
        ('raw temperature below threshold', [('x', 0x76, 69)]),
        ('qualification counter at threshold', [('x', 0x202, 0)]),
        ('signed threshold input too low', [('word', 0x2bb, 0)]),
        ('comparison input at maximum', [('word', 0x357, 32767)]),
    ):
        test = fixture()
        for space, address, value in changes:
            if space == 'word':
                word(test.x, address, value)
            else:
                getattr(test, space)[address] = value
        test.run(0x236a)
        assert 0x295e not in test.visited, label
    print('PASS: seven independent demand/phase/substate/temperature/threshold veto fixtures')
    test = fixture()
    test.x[0x76] = 70
    test.run(0x236a)
    assert 0x295e in test.visited
    print('PASS: raw temperature equality70 permits entry for selected calibration')

    for phase, substate, permitted in ((2, 4, False), (3, 3, False), (3, 4, True), (4, 0, True)):
        test = fixture(4)
        test.im[0xaa], test.im[0xb4] = phase, substate
        test.run(0x236a)
        assert (0x29e3 in test.visited) == permitted
        if permitted:
            assert (test.im[0xb9], test.im[0xac], test.im[0xaa], test.im[0x95] & 7) == (3, 7, 0, 0)
    print('PASS: mode4 advances only at phase3/substate4 or phase4 in fixture')

    # The raw dispatcher table maps mode3 phase6 to 3007 -> LCALL 9BF9.
    bank = ROM[65536:]
    assert bank[0x2fbc:0x2fbf] == bytes.fromhex('02 30 07')
    assert bank[0x3007:0x300a] == bytes.fromhex('12 9b f9')
    # Execute exact command fragments with the supervisor's resulting B9/AC.
    cpu.run(0x9cf3, stop=0x9cff)
    assert cpu.im[0x95] & 7 == 5  # Y3 + Y4 command bits
    cpu.run(0x9e21, stop=0x9e2d)
    assert cpu.im[0x95] & 7 == 4  # Y4 remains after old AC8/Y3 clear
    cpu.run(0x9ace, stop=0x9ad5)
    assert cpu.im[0xb9] == cpu.im[0xb3] == 3
    print('PASS: isolated phase6 fragments command Y3 -> Y3+Y4 -> Y4, then B9/B3=3')
    print('LIMIT: fragments omit intervening pressure/timer conditions; no physical timing claim')


if __name__ == '__main__':
    main()
