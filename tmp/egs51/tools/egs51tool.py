#!/usr/bin/env python3
"""
egs51tool.py - query a Keil-C51 banked EGS ROM without opening Ghidra.

Works on the Ghidra exports (disasm/bankN.bin.asm, disasm/bankN.bin.c from
DumpAll.java) plus the raw image. Everything here was needed at least once
during the EGS51 A0215451432 pass and would be needed again for an EGS52 image
(same compiler, same MDU idiom, same calibration conventions).

    egs51tool.py asm  BANK LO HI          listing slice by address (hex)
    egs51tool.py fn   BANK ADDR           enclosing function of an address
    egs51tool.py xrefs BANK ADDR          every instruction naming ADDR (calls, jumps, DPTR loads)
    egs51tool.py calrefs BANK LO [HI]     'MOV DPTR,#imm' references in [LO,HI) grouped by function
    egs51tool.py desc [--cal cal_data.h]  scan for 2-D map descriptors, print axes/z, match nag52 arrays
    egs51tool.py map  BANK ADDR           print one descriptor's map as a table
    egs51tool.py calsets                  decode the coding-selected calibration pointer tables
    egs51tool.py find HEXBYTES            byte pattern search (both banks) with enclosing function
    egs51tool.py mdu  BANK                census of MDU / library helper calls with their semantics
    egs51tool.py vectors                  the SIC810 3-byte-spaced vector table
    egs51tool.py export                   verified calibration JSON with bank/address/width metadata
    egs51tool.py verify [--cal cal_data.h] check the decoded block layouts against the TCU's
                                          own calibration; exit 1 on any mismatch

Options: --rom PATH --disasm DIR (defaults: ../EGS51_A0215451432.bin, ../disasm relative to
this file). Nothing here writes anything.
"""
import argparse, bisect, collections, hashlib, json, os, re, sys

HERE = os.path.dirname(os.path.abspath(__file__))

# Library helper addresses of this ROM. Do not assume the whole surrounding
# region is identical between banks: it also contains bank-specific routines.
# MDU register map on the SIC810: A5=MD0 A6=MD1 A7=MD2 AD=MD3 AE=MD4 AF=MD5; the
# write ORDER selects the operation exactly as on the 80C517A.
HELPERS = {
    0x0BCC: "(R6:R7 * R4:R5) / R2:R3 -> R6:R7, unsigned (MDU mul then 32/16 div)",
    0x0C20: "(R6:R7 * R4:R5) / R2:R3 -> R6:R7, signed (abs, count sign flips, negate)",
    0x0C0C: "R6:R7 * R4:R5 -> R4:R5:R6:R7 (32-bit product, R7 lo)",
    0x0C7B: "R4:R5:R6:R7 / INTMEM{0x75:0x76} -> quotient (32/16 div, divisor in RAM)",
    0x1061: "lag: R6:R7 += (R4:R5 - R6:R7) / R3; R3==0 -> returns R4:R5 (16/16 div)",
    0x1412: "lerp1d(desc@R7 in INTMEM: y0,y1,x0,x1,x as u16) clamped at both ends",
    0x14F3: "map2d(desc@R6:R7 in ROM: xaddr,nx,yaddr,ny,xaxis,yaxis,z) bilinear, u16 axes, u16 z",
    0x1CA2: "DPTR += A*B (array index helper)",
    0x1CED: "Keil switch dispatcher: 3-byte {addr,case} table follows the call",
    0x1DCA: "MDU timing pad (RET); write order selects operation, including 16/16 divide",
    0x1DCB: "MDU timing pad (4 NOP + RET); write order selects operation",
    0x0B3F: "bank switch helper (TCON.4), DPTR = target",
    0x0B57: "bank switch helper (other bank), DPTR = target",
}

# Calibration pointer tables of A0215451432 (from bank1 FUN_20BC): XRAM cell <- ROM[table + 2*nibble].
CALSETS = [
    ("0x3b2", 0xE8C2, "0x17b", "lo", "block after hydr (+0x60): u16/u8 params"),
    ("0x3b4", 0xE8E2, "0x17b", "lo", "4x4 map descriptor (gear x temp)"),
    ("0x3bc", 0xE902, "0x17b", "hi", "shift-decision parameter block"),
    ("0x3ba", 0xE922, "0x17b", "hi", "parameter block (+0x12..+0x1e)"),
    ("0x3c2", 0xE9E2, "0x17b", "hi", "4x4 map descriptor (distinct table from 0x3b4)"),
    ("0x3ca", 0xEA22, "0x17b", "hi", "shift-timing parameter block (most used)"),
    ("0x3be", 0xE942, "0x17b", "hi", "shift parameter block (+5+idx % , +0x26 u16)"),
    ("0x3c8", 0xE982, "0x17b", "hi", "5x4 map descriptor (gear x temp)"),
    ("0x3c6", 0xE962, "0x17b", "hi", "parameter block (+0x14..+0x4f)"),
    ("0x3c0", 0xE9A2, "0x17b", "hi", "unidentified"),
    ("0x3c4", 0xE9C2, "0x17b", "hi", "bank1 shift parameter block (9BF9); detailed meaning pending"),
    ("0x3d0", 0xEA02, "0x17c", "lo", "list of 4 descriptors: 6x8 maps per upshift"),
    ("0x3cc", 0xEA42, "0x17c", "lo", "list of 4 descriptors: 3x2 maps"),
    ("0x3d2", 0xEA62, "0x17c", "lo", "list of 4 descriptors: 6x8 maps"),
    ("0x3d4", 0xE8A2, "0x17c", "hi", "MECH block (friction_map at +1, release_spring at +0x71)"),
    ("0x3ce", 0xE882, "0x17c", "hi", "HYDR block (p_multi_1 at +1 ... mpc_flush_time at +0x58)"),
]
CALSETS_BANK0 = [
    ("0x3ac",0xECF0,"0x177","lo","unidentified bank0 parameter block"),
    ("0x3a8",0xED70,"0x177","hi","unidentified bank0 parameter block"),
    ("0x3aa",0xED90,"0x177","hi","unidentified bank0 parameter block"),
    ("0x3a4",0xED10,"0x178","lo","unidentified bank0 parameter block"),
    ("0x3a6",0xED30,"0x178","lo","unidentified bank0 parameter block"),
    ("0x3ae",0xED50,"0x178","hi","unidentified bank0 parameter block"),
    ("0x3b8",0xEC90,"0x179","lo","TCC thresholds/gains/adaptation parameters"),
    ("0x3b0",0xECB0,"0x179","lo","TCC curve pointers, feedforward curves and slip map"),
    ("0x3b6",0xECD0,"0x17a","hi","unidentified bank0 parameter block"),
]


class Rom:
    def __init__(self, rom, disasm, banks=(0, 1)):
        self.rom = open(rom, "rb").read()
        if len(self.rom) != 0x20000:
            raise ValueError("expected exactly two 64 KiB ROM banks")
        self.banks = banks
        self.asm, self.c, self.fnstarts = {}, {}, {}
        for b in banks:
            a = os.path.join(disasm, f"bank{b}.bin.asm")
            c = os.path.join(disasm, f"bank{b}.bin.c")
            self.asm[b] = open(a).read().splitlines() if os.path.exists(a) else []
            self.c[b] = open(c).read() if os.path.exists(c) else ""
            self.fnstarts[b] = sorted(int(m.group(1), 16) for m in
                                      re.finditer(r"// ======== FUN_CODE_([0-9a-f]+) @", self.c[b]))

    def bank(self, b):
        return self.rom[b * 0x10000:(b + 1) * 0x10000]

    def fn_of(self, b, a):
        s = self.fnstarts[b]
        i = bisect.bisect_right(s, a) - 1
        return "FUN_%04x" % s[i] if i >= 0 else "?"

    def instrs(self, b):
        for l in self.asm[b]:
            m = re.match(r"CODE:([0-9a-f]{4})\s+(.*)", l)
            if m:
                yield int(m.group(1), 16), m.group(2), l

    def asm_slice(self, b, lo, hi):
        return "\n".join(l for a, _, l in self.instrs(b) if lo <= a < hi)

    def descriptors(self, b, u16_ok=True):
        d = self.bank(b)
        out = []
        for i in range(0, 0x10000 - 10):
            xa, nx, ya, ny = d[i], d[i + 1], d[i + 2], d[i + 3]
            if not (1 < nx <= 20 and 1 < ny <= 20 and 0x30 <= xa < 0xF0 and 0x30 <= ya < 0xF0):
                continue
            p = [int.from_bytes(d[i + 4 + 2 * k:i + 6 + 2 * k], "big") for k in range(3)]
            if not all(0xE000 <= q < 0x10000 for q in p) or not (p[0] < p[1] < p[2]):
                continue
            if (p[1] - p[0]) == nx and (p[2] - p[1]) == ny:
                out.append((i, xa, nx, ya, ny, p, 1))
            elif u16_ok and (p[1] - p[0]) == 2 * nx and (p[2] - p[1]) == 2 * ny:
                out.append((i, xa, nx, ya, ny, p, 2))
        return out

    def map_values(self, b, desc):
        i, xa, nx, ya, ny, p, w = desc
        d = self.bank(b)
        rd = (lambda a, n: list(d[a:a + n])) if w == 1 else \
             (lambda a, n: [int.from_bytes(d[a + 2 * k:a + 2 * k + 2], "big") for k in range(n)])
        return rd(p[0], nx), rd(p[1], ny), rd(p[2], nx * ny)


def cmd_asm(r, a):
    print(r.asm_slice(int(a.bank), int(a.lo, 16), int(a.hi, 16)))


def cmd_fn(r, a):
    print(r.fn_of(int(a.bank), int(a.addr, 16)))


def cmd_xrefs(r, a):
    b, t = int(a.bank), int(a.addr, 16)
    pat = re.compile(r"\b0x%x\b" % t)
    for ad, ins, l in r.instrs(b):
        if pat.search(ins):
            print(f"{r.fn_of(b, ad):10s} {l}")


def cmd_calrefs(r, a):
    b, lo = int(a.bank), int(a.lo, 16)
    hi = int(a.hi, 16) if a.hi else 0x10000
    refs = collections.defaultdict(set)
    for ad, ins, _ in r.instrs(b):
        m = re.match(r"MOV DPTR,#0x([0-9a-f]+)$", ins)
        if m and lo <= int(m.group(1), 16) < hi:
            refs[r.fn_of(b, ad)].add(int(m.group(1), 16))
    for f in sorted(refs):
        print(f, " ".join("%04x" % x for x in sorted(refs[f])))


def load_cal_arrays(path):
    if not path or not os.path.exists(path):
        return {}
    txt = open(path).read()
    return {m.group(1): [int(v) for v in m.group(2).split(",")]
            for m in re.finditer(r"\.(\w+) = \{([-0-9,\s]+)\}", txt)}


def cmd_desc(r, a):
    arrs = load_cal_arrays(a.cal)
    for b in r.banks:
        for desc in r.descriptors(b):
            i, xa, nx, ya, ny, p, w = desc
            x, y, z = r.map_values(b, desc)
            zs = [v - 256 if v > 127 else v for v in z] if w == 1 else z
            hits = [k for k, v in arrs.items() if v in (x, y, z, zs)]
            print(f"bank{b} desc {i:04x} {nx}x{ny} u{8*w} x@{xa:02x}={x} y@{ya:02x}={y} "
                  f"z@{p[2]:04x}[:6]={z[:6]} {'MATCH '+str(hits) if hits else ''}")


def cmd_map(r, a):
    b, ad = int(a.bank), int(a.addr, 16)
    for desc in r.descriptors(b):
        if desc[0] == ad:
            x, y, z = r.map_values(b, desc)
            nx = len(x)
            print("y\\x  " + " ".join("%5d" % v for v in x))
            for j, yv in enumerate(y):
                print("%4d  " % yv + " ".join("%5d" % v for v in z[j * nx:(j + 1) * nx]))
            return
    print("no descriptor at that address (run 'desc' to list them)")


def cmd_calsets(r, a):
    print("bank xram   table   coding  | idx0  idx1  idx2  idx3   what (export includes all 16 entries)")
    for bank,tables in ((0,CALSETS_BANK0),(1,CALSETS)):
        d=r.bank(bank)
        for x,t,cb,nib,what in tables:
            vals=[int.from_bytes(d[t+2*k:t+2*k+2],"big") for k in range(4)]
            suffix="; nibble F selects 0" if bank==0 and cb=="0x179" else ""
            print(f"{bank}    {x:6s} {t:04x}    {cb}.{nib:2s} | " + "  ".join("%04x"%v for v in vals)+"   "+what+suffix)


def cmd_find(r, a):
    pat = bytes.fromhex(a.hex)
    for b in r.banks:
        d = r.bank(b)
        j = d.find(pat)
        while j >= 0:
            print(f"bank{b} {j:04x} in {r.fn_of(b, j)}")
            j = d.find(pat, j + 1)


def cmd_mdu(r, a):
    b = int(a.bank)
    counts = collections.Counter()
    byfn = collections.defaultdict(collections.Counter)
    for ad, ins, _ in r.instrs(b):
        m = re.match(r"LCALL 0x([0-9a-f]{4})$", ins)
        if m and int(m.group(1), 16) in HELPERS:
            t = int(m.group(1), 16)
            counts[t] += 1
            byfn[r.fn_of(b, ad)][t] += 1
    for t, n in counts.most_common():
        print(f"0x{t:04x} x{n:4d}  {HELPERS[t]}")
    if a.by_function:
        for f in sorted(byfn):
            print(f, " ".join(f"{t:04x}x{n}" for t, n in sorted(byfn[f].items())))


# Block layouts decoded in README section 13.3, as (name, offset, count, width, signed).
# 'verify' reads them at the coding-selected base and compares with nag52's cal_data.h.
HYDR_BASE, MECH_BASE = 0xF17A, 0xF0DA
HYDR_FIELDS = [
    ("p_multi_1", 0x01, 1, 2, 0), ("p_multi_other", 0x03, 1, 2, 0),
    ("lp_reg_spring_pressure", 0x05, 1, 2, 0),
    ("overlap_circuit_factor_spc", 0x07, 8, 2, 0),
    ("overlap_circuit_factor_mpc", 0x17, 8, 2, 0),
    ("overlap_circuit_spring_pressure", 0x27, 8, 2, 1),
    ("shift_reg_spring_pressure", 0x37, 1, 2, 0),
    ("shift_spc_gain", 0x39, 8, 2, 0), ("min_mpc_pressure", 0x4F, 1, 2, 0),
    ("filter_factor", 0x51, 1, 1, 0), ("mpc_flush_temp_threshold", 0x52, 1, 1, 0),
    ("mpc_no_flush_time", 0x56, 1, 2, 0), ("mpc_flush_time", 0x58, 1, 2, 0),
]
MECH_FIELDS = [
    ("friction_map", 0x01, 48, 2, 0), ("max_torque_on_clutch", 0x61, 4, 2, 0),
    ("max_torque_off_clutch", 0x69, 4, 2, 0), ("release_spring_pressure", 0x71, 6, 2, 0),
    ("strongest_loaded_clutch_idx", 0x87, 8, 1, 0),
]
LOOSE = [  # fields outside both blocks, at fixed bank1 addresses. The seven from
    # 0xFFD3 and 0xFFE3..0xFFEB were located in pass 5 by matching the constants that
    # egs51_pressure_demand() reads (README section 13.10); all are used by nag52's
    # PressureManager::calc_current_linear_sol in the same roles.
    ("shift_pressure_addr_percent", 0xFFD3, 1, 1, 0), ("inlet_pressure_offset", 0xFFD4, 1, 2, 0),
    ("inlet_pressure_input_min", 0xFFD6, 1, 2, 0), ("inlet_pressure_input_max", 0xFFD8, 1, 2, 0),
    ("inlet_pressure_output_min", 0xFFDA, 1, 2, 0), ("inlet_pressure_output_max", 0xFFDC, 1, 2, 0),
    ("extra_pressure_pump_speed_min", 0xFFE3, 1, 2, 0), ("extra_pressure_pump_speed_max", 0xFFE5, 1, 2, 0),
    ("extra_pressure_adder_r1_1", 0xFFE7, 1, 2, 0), ("extra_pressure_adder_other_gears", 0xFFE9, 1, 2, 0),
    ("shift_pressure_factor_percent", 0xFFEB, 1, 2, 0),
    ("pcs_map_x", 0xFF21, 7, 2, 0), ("pcs_map_y", 0xFF2F, 4, 2, 0), ("pcs_map_z", 0xFF37, 28, 2, 0),
]


def cmd_verify(r, a):
    arrs = load_cal_arrays(a.cal)
    scal = {m.group(1): int(m.group(2)) for m in re.finditer(r"\.(\w+) = (-?\d+)", open(a.cal).read())} if os.path.exists(a.cal) else {}
    if not arrs and not scal:
        print("NO DATA: could not read %s" % a.cal); sys.exit(1)
    d = r.bank(1)

    def read(off, n, w, sg):
        if w == 1:
            v = list(d[off:off + n])
        else:
            v = [int.from_bytes(d[off + 2 * k:off + 2 * k + 2], "big") for k in range(n)]
            if sg:
                v = [x - 65536 if x > 32767 else x for x in v]
        return v if n > 1 else v[0]

    bad = checked = 0
    for label, base, fields in (("hydr", HYDR_BASE, HYDR_FIELDS), ("mech", MECH_BASE, MECH_FIELDS), ("", 0, LOOSE)):
        for name, off, n, w, sg in fields:
            want = arrs.get(name, scal.get(name))
            if want is None:
                print("  SKIP %-34s not in cal_data.h" % name); continue
            got = read(base + off, n, w, sg)
            checked += 1
            if got == want:
                print("  OK   %-34s %s+0x%02X" % (name, label or "rom", off if base else 0))
            else:
                bad += 1
                print("  BAD  %-34s rom=%s cal=%s" % (name, got, want))
    print("%d fields checked, %d mismatches" % (checked, bad))
    if not checked:
        print("NO DATA: nothing was compared")
    sys.exit(1 if (bad or not checked) else 0)


def cmd_vectors(r, a):
    d = r.bank(0)
    print("SIC810 vectors are 3 bytes apart from 0x0003 (not the 8051's 8):")
    for k, v in enumerate(range(0x0000, 0x0036, 3)):
        if d[v] == 0x02:
            print(f"  vec {k:2d} @ {v:04x}: LJMP {int.from_bytes(d[v+1:v+3],'big'):04x}")


def cmd_export(r, a):
    """Machine-readable extraction; addresses and raw temperature units retained."""
    expected = "46be22165b2489d311a28bb489885825"
    digest = hashlib.md5(r.rom).hexdigest()
    if digest != expected:
        raise ValueError("export layouts are verified only for A0215451432 " + expected)
    d = r.bank(1)
    def fields(base, layout, bank=1):
        data=r.bank(bank)
        return {name: {"bank": bank, "address": base + off, "width_bytes": w,
                       "signed": bool(sg),
                       "values": [int.from_bytes(data[base+off+k*w:base+off+(k+1)*w],
                                                 "big", signed=bool(sg)) for k in range(n)]}
                for name, off, n, w, sg in layout}
    # Every field below has a consumer in the complete bank0 TCC C model.
    tcc_layout=[(name,off,1,width,sign) for name,off,width,sign in [
        ('direction_high',0x01,1,1),('direction_low',0x02,1,1),('direction_hysteresis',0x03,1,1),
        ('integral_retention_percent',0x08,1,0),('supervisor_input_1f3_limit_div100',0x0c,1,0),
        ('adapt_input_1f3_limit_div100',0x0f,1,0),('adapt_input_224_upper',0x10,2,1),
        ('adapt_speed_340_upper',0x12,2,0),('global_factor_speed_340_lower',0x14,2,0),
        ('global_factor_average_center',0x16,2,1),('bias_input_1d4_lower',0x18,1,0),
        ('bias_average_lower',0x19,1,0),('bias_average_upper',0x1a,1,0),('bias_signed_limit',0x1b,1,1),
        ('factor_sample_count',0x1c,1,0),('global_factor_slip_error_max',0x1d,1,0),
        ('global_factor_input_lower',0x1e,1,1),('global_factor_input_upper',0x1f,1,1),
        ('factor_upper',0x20,1,0),('factor_lower',0x21,1,0),
        ('gear_base_factor_input_lower',0x22,1,0),('gear_base_factor_input_upper',0x23,1,0),
        ('gear_gain_factor_input_lower',0x24,1,0),('gear_gain_factor_input_upper',0x25,2,1),
        ('gear_gain_average_deadband',0x27,2,1),('base_average_deadband',0x29,2,1),
        ('excess_slip_factor_increment',0x2b,1,0),('feedforward_gain',0x31,2,0),
        ('transition_integral_subtract',0x33,2,0),('entry_target_minimum',0x35,2,0),
        ('entry_initial_target',0x37,2,0),('entry_timer1_base',0x39,1,0),
        ('entry_timer2',0x3a,1,0),('entry_timer3',0x3b,1,0),('entry_timer4',0x3c,1,0),
        ('entry_direction1_percent',0x3d,1,0),('entry_direction0_percent',0x3e,1,0),
    ]]
    tcc_variants=[]
    for n in range(16):
        data=r.bank(0)
        param=int.from_bytes(data[0xec90+2*n:0xec92+2*n],'big')
        curves=int.from_bytes(data[0xecb0+2*n:0xecb2+2*n],'big')
        if param!=0xffff and curves!=0xffff:
            tcc_variants.append({'coding_179_low_nibble':n,'parameter_address':param,
                                 'curve_block_address':curves,'bank':0,
                                 'fields':fields(param,tcc_layout,0)})
    # These cells have code references in 56A6/56DE/5BB6/D76E; no guessed units.
    cells = [(name, off, 1, width, 0) for name, off, width in [
        ("fill_cold", 0xFF73, 1), ("fill_hot", 0xFF9E, 1),
        ("hold_cold", 0xFF76, 1), ("hold_hot", 0xFF71, 1),
        ("temperature_axis_low_raw", 0xFF91, 1), ("temperature_axis_high_raw", 0xFF92, 1),
        ("ramp_divisor", 0xFF78, 1), ("hold_extension", 0xFF7B, 1),
        ("mpc_fill_target", 0xFF87, 2), ("minimum_arm_time", 0xFF9F, 1),
        ("neutral_timer", 0xFFA1, 1), ("neutral_temperature_raw", 0xFFA2, 1),
        ("y3_speed_threshold", 0xFF81, 2), ("normal_exit_speed", 0xFFA7, 2),
        ("fast_exit_speed_inclusive", 0xFFAD, 2), ("inlet_correction_gain", 0xFFD3, 1),
        ("inlet_correction_offset_word", 0xFFD4, 2),
    ]]
    pointers = []
    for bank, tables in ((0,CALSETS_BANK0),(1,CALSETS)):
        data=r.bank(bank)
        for cell, table, coding, nibble, description in tables:
            pointers.append({"xram": cell, "table_bank": bank, "table_address": table,
                             "coding_xram": coding, "nibble": nibble, "description": description,
                             "nibble_f_selects_zero": bank==0 and coding=="0x179",
                             "entries": [int.from_bytes(data[table+2*k:table+2*k+2], "big")
                                         for k in range(16)]})
    print(json.dumps({"rom_md5": digest, "word_byte_order": "big",
                      "temperature_units": "raw; Celsius offset not established by these tests",
                      "timer_units": "scheduler invocations; elapsed duration not established",
                      "reference_variant": {"coding_17c_high_nibble": 2,
                                            "hydraulic": fields(HYDR_BASE, HYDR_FIELDS),
                                            "mechanical": fields(MECH_BASE, MECH_FIELDS)},
                      "loose_calibration": fields(0, LOOSE),
                      "engagement_and_pressure": fields(0, cells),
                      "tcc_variants":tcc_variants,
                      "coding_pointer_tables": pointers}, indent=2))


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--rom", default=os.path.join(HERE, "..", "EGS51_A0215451432.bin"))
    ap.add_argument("--disasm", default=os.path.join(HERE, "..", "disasm"))
    sub = ap.add_subparsers(dest="cmd", required=True)
    s = sub.add_parser("asm"); s.add_argument("bank"); s.add_argument("lo"); s.add_argument("hi"); s.set_defaults(f=cmd_asm)
    s = sub.add_parser("fn"); s.add_argument("bank"); s.add_argument("addr"); s.set_defaults(f=cmd_fn)
    s = sub.add_parser("xrefs"); s.add_argument("bank"); s.add_argument("addr"); s.set_defaults(f=cmd_xrefs)
    s = sub.add_parser("calrefs"); s.add_argument("bank"); s.add_argument("lo"); s.add_argument("hi", nargs="?"); s.set_defaults(f=cmd_calrefs)
    s = sub.add_parser("desc"); s.add_argument("--cal", default=os.path.join(HERE, "..", "..", "shift_replay", "cal_data.h")); s.set_defaults(f=cmd_desc)
    s = sub.add_parser("map"); s.add_argument("bank"); s.add_argument("addr"); s.set_defaults(f=cmd_map)
    s = sub.add_parser("calsets"); s.set_defaults(f=cmd_calsets)
    s = sub.add_parser("find"); s.add_argument("hex"); s.set_defaults(f=cmd_find)
    s = sub.add_parser("mdu"); s.add_argument("bank"); s.add_argument("--by-function", action="store_true"); s.set_defaults(f=cmd_mdu)
    s = sub.add_parser("vectors"); s.set_defaults(f=cmd_vectors)
    s = sub.add_parser("export", help="export verified A0215451432 calibration as JSON"); s.set_defaults(f=cmd_export)
    s = sub.add_parser("verify"); s.add_argument("--cal", default=os.path.join(HERE, "..", "..", "shift_replay", "cal_data.h")); s.set_defaults(f=cmd_verify)
    a = ap.parse_args()
    r = Rom(a.rom, a.disasm)
    a.f(r, a)


if __name__ == "__main__":
    main()
