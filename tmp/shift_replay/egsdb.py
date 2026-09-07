"""Decode the config app's egs_db.bin (LZ4 block + bincode legacy) into Python dicts."""
import struct, json, sys

def lz4_block_decompress(src):
    out = bytearray(); i = 0; n = len(src)
    while i < n:
        token = src[i]; i += 1
        lit = token >> 4
        if lit == 15:
            while True:
                b = src[i]; i += 1; lit += b
                if b != 255: break
        out += src[i:i+lit]; i += lit
        if i >= n: break
        off = src[i] | (src[i+1] << 8); i += 2
        ml = token & 0xF
        if ml == 15:
            while True:
                b = src[i]; i += 1; ml += b
                if b != 255: break
        ml += 4
        start = len(out) - off
        for k in range(ml):
            out.append(out[start + k])
    return bytes(out)

class R:
    def __init__(self, b): self.b = b; self.p = 0
    def u8(self): v = self.b[self.p]; self.p += 1; return v
    def u16(self): v = struct.unpack_from('<H', self.b, self.p)[0]; self.p += 2; return v
    def i16(self): v = struct.unpack_from('<h', self.b, self.p)[0]; self.p += 2; return v
    def u64(self): v = struct.unpack_from('<Q', self.b, self.p)[0]; self.p += 8; return v
    def string(self):
        n = self.u64(); s = self.b[self.p:self.p+n].decode(); self.p += n; return s
    def arr(self, f, n): return [f() for _ in range(n)]
    def vec(self, f): n = self.u64(); return [f() for _ in range(n)]

SHIFT_FIELDS = [
 ('momentum_1_2_x',3),('momentum_2_3_x',3),('momentum_3_4_x',3),('momentum_4_5_x',3),
 ('momentum_1_2_y',2),('momentum_2_3_y',2),('momentum_3_4_y',2),('momentum_4_5_y',2),
 ('momentum_1_2_z',6),('momentum_2_3_z',6),('momentum_3_4_z',6),('momentum_4_5_z',6),
 ('momentum_2_1_x',6),('momentum_3_2_x',6),('momentum_4_3_x',6),('momentum_5_4_x',6),
 ('momentum_2_1_y',10),('momentum_3_2_y',10),('momentum_4_3_y',10),('momentum_5_4_y',10),
 ('momentum_2_1_z',60),('momentum_3_2_z',60),('momentum_4_3_z',60),('momentum_5_4_z',60),
 ('trq_adder_1_2_x',6),('trq_adder_2_3_x',6),('trq_adder_3_4_x',6),('trq_adder_4_5_x',6),
 ('trq_adder_1_2_y',8),('trq_adder_2_3_y',8),('trq_adder_3_4_y',8),('trq_adder_4_5_y',8),
 ('trq_adder_1_2_z',48),('trq_adder_2_3_z',48),('trq_adder_3_4_z',48),('trq_adder_4_5_z',48),
 ('trq_adder_2_1_x',3),('trq_adder_3_2_x',3),('trq_adder_4_3_x',3),('trq_adder_5_4_x',3),
 ('trq_adder_2_1_y',4),('trq_adder_3_2_y',4),('trq_adder_4_3_y',4),('trq_adder_5_4_y',4),
 ('trq_adder_2_1_z',12),('trq_adder_3_2_z',12),('trq_adder_4_3_z',12),('trq_adder_5_4_z',12)]

def shift_cfg(r):
    return {name: r.arr(r.u8, n) for name, n in SHIFT_FIELDS}

def hydr_cfg(r):
    d = {}
    d['p_multi_1']=r.u16(); d['p_multi_other']=r.u16(); d['lp_reg_spring_pressure']=r.u16()
    d['overlap_circuit_factor_spc']=r.arr(r.u16,8); d['overlap_circuit_factor_mpc']=r.arr(r.u16,8)
    d['overlap_circuit_spring_pressure']=r.arr(r.i16,8); d['shift_reg_spring_pressure']=r.u16()
    d['shift_spc_gain']=r.arr(r.u16,8); d['min_mpc_pressure']=r.u16()
    d['filter_factor']=r.u8(); d['mpc_flush_temp_threshold']=r.u8(); d['mpc_no_flush_time']=r.u16(); d['mpc_flush_time']=r.u16(); d['extra_p_not_shifting']=r.u16()
    for k in ['shift_pressure_addr_percent','inlet_pressure_offset','inlet_pressure_input_min','inlet_pressure_input_max','inlet_pressure_output_min','inlet_pressure_output_max','extra_pressure_pump_speed_min','extra_pressure_pump_speed_max','extra_pressure_adder_r1_1','extra_pressure_adder_other_gears','shift_pressure_factor_percent']:
        d[k]=r.u16()
    d['pcs_map_x']=r.arr(r.u16,7); d['pcs_map_y']=r.arr(r.u16,4); d['pcs_map_z']=r.arr(r.u16,28)
    return d

def mech_cfg(r):
    d = {}
    d['gb_ty']=r.u8(); d['ratio_table']=r.arr(r.u16,8); d['intertia_factor']=r.arr(r.u16,8); d['friction_map']=r.arr(r.u16,48)
    d['max_torque_on_clutch']=r.arr(r.u16,4); d['max_torque_off_clutch']=r.arr(r.u16,4); d['release_spring_pressure']=r.arr(r.u16,6)
    d['intertia_torque']=r.arr(r.u16,8); d['strongest_loaded_clutch_idx']=r.arr(r.u8,8); d['turbine_drag']=r.arr(r.u16,8)
    d['atf_density_minus_50c']=r.u16(); d['atf_density_drop_per_c']=r.u16(); d['atf_density_centrifugal_force_factor']=r.arr(r.u16,3)
    return d

def tcc_cfg(r):
    return {'multiplier_map_x': r.arr(r.u16,2), 'multiplier_map_z': r.arr(r.u16,2), 'pump_map_x': r.arr(r.u16,11), 'pump_map_z': r.arr(r.u16,11)}

def record(r, f):
    name = r.string(); data = f(r); pns = r.vec(r.string)
    return {'name': name, 'data': data, 'valid_egs_pns': pns}

def chassis(r):
    return {k: r.string() for k in ['gearbox','chassis','hydr_cfg','mech_cfg','tcc_cfg','shift_algo_cfg']}

def egs(r):
    return {'pn': r.string(), 'chassis': r.vec(lambda: chassis(r))}

def load(path):
    raw = open(path,'rb').read()
    b = lz4_block_decompress(raw)
    r = R(b)
    db = {}
    db['egs_list'] = r.vec(lambda: egs(r))
    db['hydr'] = r.vec(lambda: record(r, hydr_cfg))
    db['mech'] = r.vec(lambda: record(r, mech_cfg))
    db['tcc'] = r.vec(lambda: record(r, tcc_cfg))
    db['shift_algo'] = r.vec(lambda: record(r, shift_cfg))
    assert r.p == len(b), (r.p, len(b))
    return db

if __name__ == '__main__':
    db = load(sys.argv[1])
    print(len(db['egs_list']), 'EGS PNs;', len(db['hydr']), 'hydr;', len(db['mech']), 'mech;', len(db['tcc']), 'tcc;', len(db['shift_algo']), 'shift_algo')
    json.dump(db, open('egs_db.json','w'))
    for m in db['mech']:
        print('MECH', m['name'], 'ratios', m['data']['ratio_table'], 'springs', m['data']['release_spring_pressure'])
    for h in db['hydr']:
        print('HYDR', h['name'], 'gain', h['data']['shift_spc_gain'], 'shift_reg_spring', h['data']['shift_reg_spring_pressure'], 'pcs_x', h['data']['pcs_map_x'])
    for t in db['tcc']:
        print('TCC', t['name'], t['data']['multiplier_map_x'], t['data']['multiplier_map_z'])
    for s in db['shift_algo']:
        print('SHIFT', s['name'])
