#!/usr/bin/env python3
"""Build the native C and compare it with original C166 instructions."""
import ctypes as C
import random
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT=Path(__file__).resolve().parents[1]
sys.path.insert(0,str(ROOT/'tools'))
from decode_flash import transform, verify
from c166_oracle import C166
from psw_oracle import PswOracle
from boot_irq_oracle import BootIrqOracle


def main():
    raw=(ROOT/'A0325452132.FLS').read_bytes();rom=transform(raw);verify(raw,rom)
    rng=random.Random(0xE652);total=0;seen=set()
    with tempfile.TemporaryDirectory(prefix='egs52_verify_') as temp:
        so=Path(temp)/'math.so'
        subprocess.run(['cc','-std=c11','-Wall','-Wextra','-Werror','-pedantic',
            '-fsanitize=undefined','-fno-sanitize-recover=all','-fPIC','-shared',
            str(ROOT/'reconstructed/egs52_reconstructed_clean.c'),'-o',str(so)],check=True)
        lib=C.CDLL(str(so))
        psw_rng=random.Random(52)
        for name,entry in [('enable_interrupts',0x9792e),('disable_interrupts_save',0x97938),('exchange_interrupt_priority',0xa7d38)]:
            f=getattr(lib,'egs52_'+name)
            f.argtypes=[C.POINTER(C.c_uint16)] if name=='enable_interrupts' else [C.POINTER(C.c_uint16),C.c_uint16]
            f.restype=None if name=='enable_interrupts' else C.c_uint8 if name=='disable_interrupts_save' else C.c_uint16
            for old in range(65536):
                arg=[0,1,0x7fff,0x8000,0xffff][old] if old<5 else psw_rng.randrange(65536)
                cpu=PswOracle(rom,old);cpu.r[6]=arg;cpu.r[12]=arg
                expected=cpu.run(entry);psw=C.c_uint16(old)
                got=f(C.byref(psw)) if name=='enable_interrupts' else f(C.byref(psw),arg)
                assert psw.value==cpu.psw,(name,old,arg,psw.value,cpu.psw)
                if name!='enable_interrupts':assert got==expected,(name,old,arg,got,expected)
                assert cpu.r[6]==arg and cpu.r[0]==0xf800
                assert cpu.atomic==([] if name=='exchange_interrupt_priority' else [3])
                total+=1;seen.update(cpu.seen)
            print(name,65536,'PASS')
        extra_rng=random.Random(0x30f2)
        f=lib.egs52_lerp_signed_registers
        f.argtypes=[C.c_uint16,C.c_uint16,C.c_int16,C.c_int16,C.c_int16];f.restype=C.c_uint16
        for i in range(5000):
            x0=extra_rng.randrange(-30000,15000);x1=x0+extra_rng.randrange(1,min(30000,32767-x0)+1)
            x=extra_rng.choice([x0,x1,extra_rng.randrange(-32768,32768)])
            low=extra_rng.randrange(-15000,15000)&65535;high=extra_rng.randrange(-15000,15000)&65535
            cpu=C166(rom);cpu.r[12:16]=[low,high,x0&65535,x1&65535];cpu.wr(0xf800,x)
            assert cpu.run(0xd30f2)==f(low,high,x0,x1,x),(low,high,x0,x1,x)
            total+=1;seen.update(cpu.seen)
        print('lerp_signed_registers',5000,'PASS')
        f=lib.egs52_read_indexed_record_word
        f.argtypes=[C.POINTER(C.c_uint8),C.c_uint8];f.restype=C.c_uint16
        for limit in range(256):
            for index in range(256):
                cpu=C166(rom);cpu.r[12]=index|(extra_rng.randrange(256)<<8)
                cpu.r[6:8]=[extra_rng.randrange(65536),extra_rng.randrange(65536)];preserved=cpu.r[6:8]
                address=0xef10+16*index if index<14 else 0xee10+16*(index-14)
                # Preserve the oracle's synthetic outer return frame.
                if address!=0xf740:cpu.wr(address,extra_rng.randrange(65536))
                cpu.wr(0xcda6,limit,8)
                memory=(C.c_uint8*65536).from_buffer_copy(cpu.mem)
                assert cpu.run(0xa626c)==f(memory,index),(limit,index,address)
                assert cpu.r[6:8]==preserved
                total+=1;seen.update(cpu.seen)
        print('read_indexed_record_word',65536,'PASS')
        f=lib.egs52_test_fd02_bit0_clear
        f.argtypes=[C.c_uint16,C.POINTER(C.c_uint16)];f.restype=C.c_uint8
        for old in range(65536):
            fd02=extra_rng.randrange(65536);cpu=PswOracle(rom,old);cpu.mem[0xfd02]=fd02
            cpu.r[4]=extra_rng.randrange(65536);psw=C.c_uint16(old)
            actual=cpu.run(0x98164)&255
            assert actual==f(fd02,C.byref(psw)) and psw.value==cpu.psw,(old,fd02)
            total+=1;seen.update(cpu.seen)
        print('test_fd02_bit0_clear',65536,'PASS')
        f=lib.egs52_stage_request_words
        f.argtypes=[C.POINTER(C.c_uint8),C.c_uint16,C.c_uint16,C.c_uint16,C.c_uint16];f.restype=C.c_uint8
        for status in range(256):
            for repetition in range(32):
                words=[extra_rng.randrange(65536) for _ in range(4)]
                cpu=C166(rom);cpu.mem[0xc300:0xc360]=extra_rng.randbytes(0x60)
                cpu.wr(0xc32a,status,8);cpu.r[12:15]=words[:3];cpu.r[15]=words[3]^65535
                cpu.r[4]=extra_rng.randrange(65536);cpu.wr(0xf800,words[3])
                memory=(C.c_uint8*65536).from_buffer_copy(cpu.mem)
                assert cpu.run(0x9eee4)&255==f(memory,*words),(status,words)
                assert bytes(memory)[0xc300:0xc360]==bytes(cpu.mem)[0xc300:0xc360]
                total+=1;seen.update(cpu.seen)
        print('stage_request_words',8192,'PASS')
        class BootState(C.Structure):
            _fields_=[('psw',C.c_uint16),('dpp3',C.c_uint16),('mdh',C.c_uint16)]
        ReadWord=C.CFUNCTYPE(C.c_uint16,C.c_void_p,C.c_uint16)
        WriteWord=C.CFUNCTYPE(None,C.c_void_p,C.c_uint16,C.c_uint16)
        ControlEvent=C.CFUNCTYPE(None,C.c_void_p,C.c_uint8,C.c_uint32)
        for name,entry in [('interrupt_010',0x835f4),('interrupt_018',0x83600),('interrupt_028',0x8360c)]:
            f=getattr(lib,'egs52_'+name);f.argtypes=[C.POINTER(BootState),ReadWord,WriteWord,ControlEvent,C.c_void_p];f.restype=None
            for case in range(2048):
                initial=[extra_rng.randrange(65536) for _ in range(3)]
                words={0xfdee:extra_rng.randrange(65536),0xffac:extra_rng.randrange(65536),
                       0xe7fe:extra_rng.randrange(65536),0xe800:extra_rng.randrange(65536),0xffae:extra_rng.randrange(65536)}
                if case<8:words[0xffac]=[0,1,0x7fff,0x8000,0xffff,0xaaaa,0x5555,0xff][case]
                words[0xfdee]=(words[0xfdee]&~1)|(case&1)
                cpu=BootIrqOracle(rom,*initial,words);state=BootState(*initial);trace=[];memory=dict(words)
                def snapshot():return (state.psw,state.dpp3,state.mdh)
                def read_word(context,address):
                    value=memory[address];trace.append(('read',address,value,snapshot()));return value
                def write_word(context,address,value):
                    memory[address]=value;trace.append(('write',address,value,snapshot()))
                def event(context,kind,target):trace.append(('event',kind,target,snapshot()))
                cpu.run(entry);f(C.byref(state),ReadWord(read_word),WriteWord(write_word),ControlEvent(event),None)
                assert trace==cpu.trace,(name,case,trace,cpu.trace)
                assert memory==cpu.words and snapshot()==cpu.state(),(name,case)
                total+=1;seen.update(cpu.seen)
            print(name,2048,'PASS')
        cases=[('weighted_average_s16',0xdf1c6,3),('weighted_average_u16',0xdf1f8,3),('blend_percent_u16',0xdf222,3),
               ('blend_percent_s16',0xdf250,3),('ramp_u16',0xdf27e,3),
               ('sqrt_estimate_u16',0xdf2b0,1),('abs_s16_bits',0x9223a,1)]
        for name,entry,argc in cases:
            f=getattr(lib,'egs52_'+name);f.argtypes=[C.c_uint16]*argc;f.restype=C.c_uint16
            n=65536 if argc==1 else 5000
            for i in range(n):
                args=[i] if argc==1 else [rng.randrange(65536) for _ in range(argc)]
                if name.startswith('blend'):args[0]=rng.randrange(101)
                if name.startswith('weighted_average'):args[0]=rng.randrange(256)
                if name=='ramp_u16' and i<100:args[2]=i%3
                cpu=C166(rom);cpu.r[12:12+argc]=args
                actual=cpu.run(entry);expected=f(*args)
                assert actual==expected,(name,args,actual,expected)
                total+=1;seen.update(cpu.seen)
            print(name,n,'PASS')
        for name,entry in [('sqrt_estimate_u32',0xdf2ec),('vector_length_estimate',0xdf36e)]:
            f=getattr(lib,'egs52_'+name);f.restype=C.c_uint16
            f.argtypes=[C.c_uint32] if name=='sqrt_estimate_u32' else [C.c_uint16,C.c_uint16]
            boundaries=[0,1,7,8,99,100,101,4999,5000,5001,65535,65536,
                        99999,100000,100001,0x7fffffff,0x80000000,0xfffffffe,0xffffffff]
            for i in range(5000):
                cpu=C166(rom)
                if name=='sqrt_estimate_u32':
                    value=boundaries[i] if i<len(boundaries) else rng.randrange(1<<32)
                    args=[value];cpu.r[12:14]=[value&65535,value>>16]
                else:
                    args=[rng.randrange(65536),rng.randrange(65536)]
                    if i<16:args=[[0,1,32768,65535][i//4],[0,1,32768,65535][i%4]]
                    cpu.r[12:14]=args
                actual=cpu.run(entry);expected=f(*args)
                assert actual==expected,(name,args,actual,expected)
                total+=1;seen.update(cpu.seen)
            print(name,5000,'PASS')
        for name,entry in [('lerp_unsigned_axis',0xdf3a4),('lerp_signed_axis',0xdf3f8)]:
            f=getattr(lib,'egs52_'+name);f.argtypes=[C.POINTER(C.c_uint16)];f.restype=C.c_uint16
            for _ in range(5000):
                x0=rng.randrange(20000);x1=x0+rng.randrange(1,15000)
                x=rng.choice([x0,x1,rng.randrange(40000)])
                y0=rng.randrange(-15000,15000);y1=rng.randrange(-15000,15000)
                if name.endswith('signed_axis'):x0-=15000;x1-=15000;x-=15000
                values=[v&65535 for v in (y0,y1,x0,x1,x)]
                cpu=C166(rom);cpu.r[12]=0xc100
                for i,v in enumerate(values):cpu.wr(0xc100+2*i,v)
                actual=cpu.run(entry);expected=f((C.c_uint16*5)(*values))
                assert actual==expected,(name,values,actual,expected)
                total+=1;seen.update(cpu.seen)
            print(name,5000,'PASS')
        for name,entry,width in [('curve_u16',0xdf44c,16),('curve_u8',0xdf894,8)]:
            f=getattr(lib,'egs52_'+name);t=C.c_uint16 if width==16 else C.c_uint8
            f.argtypes=[C.c_uint16,C.POINTER(t),C.POINTER(t),t];f.restype=t
            for _ in range(3000):
                count=rng.randrange(2,20);axis=sorted(rng.sample(range(1<<width),count))
                vals=[rng.randrange(1<<width) for _ in axis]
                x=rng.choice([axis[0],axis[-1],rng.randrange(1<<width)])
                cpu=C166(rom);cpu.r[12:16]=[count,0xc100,0xc300,x]
                for i,v in enumerate(axis):cpu.wr(0xc100+i*(width//8),v,width)
                for i,v in enumerate(vals):cpu.wr(0xc300+i*(width//8),v,width)
                actual=cpu.run(entry)&((1<<width)-1);expected=f(count,(t*count)(*axis),(t*count)(*vals),x)
                assert actual==expected,(name,axis,vals,x,actual,expected)
                total+=1;seen.update(cpu.seen)
            print(name,3000,'PASS')
        f=lib.egs52_curve_s16
        f.argtypes=[C.c_uint8,C.POINTER(C.c_int16),C.POINTER(C.c_int16),C.c_int16];f.restype=C.c_uint16
        for _ in range(5000):
            count=rng.randrange(2,30)
            axis=sorted(rng.sample(range(-15000,15000),count))
            vals=[rng.randrange(-16000,16000) for _ in axis]
            x=rng.choice([axis[0],axis[-1],rng.randrange(-32768,32768)])
            cpu=C166(rom);cpu.r[12:16]=[count,0xc100,0xc300,x&65535]
            for i,v in enumerate(axis):cpu.wr(0xc100+2*i,v)
            for i,v in enumerate(vals):cpu.wr(0xc300+2*i,v)
            actual=cpu.run(0xdfc18);expected=f(count,(C.c_int16*count)(*axis),(C.c_int16*count)(*vals),x)
            assert actual==expected,('curve_s16',axis,vals,x,actual,expected)
            total+=1;seen.update(cpu.seen)
        print('curve_s16',5000,'PASS')
        for name,entry,t in [('map_u16',0xdf506,C.c_uint16),
                             ('map_s16',0xdf72e,C.c_int16),('map_u8',0xdf980,C.c_uint8)]:
            f=getattr(lib,'egs52_'+name)
            f.argtypes=[C.c_uint16,C.c_uint16,C.POINTER(t),C.POINTER(t),C.POINTER(t),t,t]
            f.restype=C.c_uint16 if t!=C.c_uint8 else t
            width=8 if t==C.c_uint8 else 16
            domain=range(256) if width==8 else range(-15000,15000) if t==C.c_int16 else range(65536)
            for case in range(5000):
                nx=rng.randrange(2,25);ny=rng.randrange(2,25)
                xs=sorted(rng.sample(domain,nx));ys=sorted(rng.sample(domain,ny))
                cells=[rng.choice(domain) for _ in range(max(256,nx*ny))]
                x=rng.choice([xs[0],xs[-1],rng.choice(domain)])
                y=rng.choice([ys[0],ys[-1],rng.choice(domain)])
                cpu=C166(rom);cpu.r[12:16]=[nx,ny,0xc100,0xc200]
                for i,v in enumerate(xs):cpu.wr(0xc100+i*width//8,v,width)
                for i,v in enumerate(ys):cpu.wr(0xc200+i*width//8,v,width)
                for i,v in enumerate(cells):cpu.wr(0xc400+i*width//8,v,width)
                for i,v in enumerate([0xc400,x,y]):cpu.wr(cpu.r[0]+2*i,v)
                actual=cpu.run(entry)&((1<<width)-1)
                expected=f(nx,ny,(t*nx)(*xs),(t*ny)(*ys),(t*len(cells))(*cells),x,y)
                assert actual==expected,(name,case,nx,ny,x,y,actual,expected)
                total+=1;seen.update(cpu.seen)
            print(name,5000,'PASS')
        callback=C.CFUNCTYPE(C.c_uint8,C.c_void_p,C.c_uint32)
        crc=lib.egs52_crc16_a001_far
        crc.argtypes=[callback,C.c_void_p,C.c_uint32,C.c_uint16,C.c_uint16];crc.restype=C.c_uint16
        for case in range(1000):
            count=rng.randrange(65);seed=rng.randrange(65536)
            address=rng.choice([0xfffff0,0xffff,0x8fff0,rng.randrange(1<<24)])
            data=bytes(rng.randrange(256) for _ in range(count))
            if case==0:count=9;seed=0;data=b'123456789'
            cpu=C166(rom);cpu.r[12:16]=[address&65535,address>>16,count,seed]
            cpu.far_mem={(address+i)&0xffffff:v for i,v in enumerate(data)}
            reads=[]
            def read_byte(context,a):
                reads.append(a)
                return data[(a-address)&0xffffff]
            actual=cpu.run(0x9efaa);expected=crc(callback(read_byte),None,address,count,seed)
            assert actual==expected,('crc16',address,data,seed,actual,expected)
            assert reads==[(address+i)&0xffffff for i in range(count)]
            if case==0:assert actual==0xbb3d
            total+=1;seen.update(cpu.seen)
        print('crc16_a001_far',1000,'PASS')
        copy=lib.egs52_memcpy_near
        copy.argtypes=[C.POINTER(C.c_uint8),C.c_uint16,C.c_uint16,C.c_uint16];copy.restype=C.c_uint16
        for _ in range(1000):
            count=rng.randrange(257);src=rng.randrange(0xc100,0xc500)
            dst=src+rng.randrange(-256,257)
            cpu=C166(rom)
            cpu.mem[0xc000:0xc800]=rng.randbytes(0x800)
            original=bytes(cpu.mem)
            cpu.r[12:15]=[dst,src,count]
            actual=cpu.run(0x92248)
            memory=(C.c_uint8*65536).from_buffer_copy(original)
            expected=copy(memory,dst,src,count)
            assert actual==expected==dst
            assert bytes(memory)[:0xfe00]==bytes(cpu.mem)[:0xfe00],('memcpy',src,dst,count)
            total+=1;seen.update(cpu.seen)
        print('memcpy_near',1000,'PASS')
        queries=[('test_fault_status_bit4',0x9f7d8),('test_fault_status_bit3',0x9f7ec),
                 ('test_fault_status_bit2',0x9f800),('test_fault_status_bit7',0x9f814),
                 ('test_fault_bitmap',0x9f828)]
        for name,entry in queries:
            f=getattr(lib,'egs52_'+name)
            f.argtypes=[C.POINTER(C.c_uint8),C.c_uint8];f.restype=C.c_uint8
            for case in range(4096):
                cpu=C166(rom);cpu.mem[0xc300:0xc500]=rng.randbytes(512)
                index=case%256;cpu.r[12]=index|(rng.randrange(256)<<8)
                memory=(C.c_uint8*65536).from_buffer_copy(cpu.mem)
                actual=cpu.run(entry)&255;expected=f(memory,index)
                assert actual==expected,(name,index,actual,expected)
                assert bytes(memory)[:0xfe00]==bytes(cpu.mem)[:0xfe00],('query unexpectedly wrote RAM',name)
                total+=1;seen.update(cpu.seen)
            print(name,4096,'PASS')
        runtime_cases=[('multiply_u32_registers',0x9212e),('divide_u32_registers',0x921b4),
                       ('divide_u32_wide_divisor',0x921ce),('divide_s32_registers',0x9214e)]
        boundaries=[0,1,2,65535,65536,65537,0x7fffffff,0x80000000,0xfffffffe,0xffffffff]
        for name,entry in runtime_cases:
            f=getattr(lib,'egs52_'+name);f.argtypes=[C.c_uint32,C.c_uint32];f.restype=C.c_uint32
            for case in range(5000):
                a=rng.randrange(1<<32);b=rng.randrange(1,1<<32)
                if case<100:a=boundaries[case//10];b=boundaries[case%10] or 1
                if name=='divide_u32_wide_divisor':b=max(b,65536)
                cpu=C166(rom);cpu.r[4:6]=[a&65535,a>>16];cpu.r[10:12]=[b&65535,b>>16]
                cpu.run(entry);actual=cpu.r[4]|cpu.r[5]<<16;expected=f(a,b)
                assert actual==expected,(name,a,b,actual,expected)
                total+=1;seen.update(cpu.seen)
            print(name,5000,'PASS')
        for name,entry in [('read_far_u32_registers',0x9222c),('boot_read_far_u32_registers',0x83138)]:
            f=getattr(lib,'egs52_'+name)
            f.argtypes=[callback,C.c_void_p,C.POINTER(C.c_uint32)];f.restype=C.c_uint32
            for case in range(1000):
                pointer=rng.randrange(1<<31)*2
                if case<4:pointer=[0xfffe,0xfffffe,0xfffffffe,0][case]
                data=rng.randbytes(4);cpu=C166(rom)
                cpu.r[4:6]=[pointer&65535,pointer>>16]
                cpu.far_mem={(pointer+i)&0xffffff:v for i,v in enumerate(data)}
                reads=[]
                def read_runtime_byte(context,a):
                    reads.append(a);return data[(a-(pointer&0xffffff))&0xffffff]
                cpu.run(entry);p=C.c_uint32(pointer)
                expected=f(callback(read_runtime_byte),None,C.byref(p))
                assert expected==cpu.r[10]|cpu.r[11]<<16
                assert p.value==cpu.r[4]|cpu.r[5]<<16
                assert reads==[(pointer+i)&0xffffff for i in range(4)]
                total+=1;seen.update(cpu.seen)
            print(name,1000,'PASS')
        for name,entry,width in [('copy_bytes_registers',0x9226c,1),('copy_words_registers',0x9227c,2)]:
            f=getattr(lib,'egs52_'+name);f.argtypes=[C.POINTER(C.c_uint8),C.POINTER(C.c_uint16)];f.restype=None
            for case in range(1000):
                count=case%257;source=rng.randrange(0xc100,0xc400)//width*width
                destination=(source+rng.randrange(-64,65)*width)&65535
                cpu=C166(rom);cpu.mem[0xc000:0xc800]=rng.randbytes(0x800)
                cpu.r[3]=count;cpu.r[4]=source;cpu.r[10]=destination
                memory=(C.c_uint8*65536).from_buffer_copy(cpu.mem)
                state=(C.c_uint16*3)(count,source,destination)
                cpu.run(entry);f(memory,state)
                assert list(state)==[cpu.r[3],cpu.r[4],cpu.r[10]],(name,count,source,destination)
                assert bytes(memory)[:0xfe00]==bytes(cpu.mem)[:0xfe00],(name,count,source,destination)
                total+=1;seen.update(cpu.seen)
            print(name,1000,'PASS')
        far_call=C.CFUNCTYPE(None,C.c_void_p,C.c_uint32)
        for name,entry in [('call_far_indirect',0x92226),('boot_call_far_indirect',0x83132)]:
            f=getattr(lib,'egs52_'+name);f.argtypes=[far_call,C.c_void_p,C.c_uint16,C.c_uint16];f.restype=None
            for case in range(1000):
                target=rng.choice([0x9223a,0xdf2b0]);value=rng.randrange(65536)
                segment=(target>>16)|(rng.randrange(256)<<8);offset=target&65535
                cpu=C166(rom);cpu.r[4]=offset;cpu.r[5]=segment;cpu.r[12]=value
                actual=cpu.run(entry);result=C.c_uint16(value);calls=[]
                def dispatch(context,address):
                    calls.append(address)
                    v=C.cast(context,C.POINTER(C.c_uint16))
                    v[0]=lib.egs52_abs_s16_bits(v[0]) if address==0x9223a else lib.egs52_sqrt_estimate_u16(v[0])
                f(far_call(dispatch),C.byref(result),segment,offset)
                assert calls==[target] and result.value==actual,(name,target,value,actual,result.value)
                assert cpu.rd(0xfe12)==0xf744
                assert cpu.rd(0xf73c)==offset and cpu.rd(0xf73e)==segment
                total+=1;seen.update(cpu.seen)
            print(name,1000,'PASS')
        control_cases=[
            ('clamp_d488_when_fd4e_bit5_set',0xd2008,[],None),
            ('update_d7d8_from_byte_delta',0xd2938,[C.c_uint8,C.c_uint8,C.c_uint16],None),
            ('scale_and_store_d4ae',0xd7b70,[C.c_uint16,C.c_uint8],None),
            ('combine_percent_term_d402',0xd7bc0,[],None),
            ('offset_and_clamp_u16',0xd7e64,[C.c_uint16],C.c_uint16),
            ('classify_negated_input',0xde014,[C.c_uint16],C.c_uint8),
            ('update_scaled_difference_d712',0xe0000,[],None),
            ('initialize_fault_status',0x9f858,[],C.c_uint8)]
        for name,entry,types,result_type in control_cases:
            f=getattr(lib,'egs52_'+name)
            f.argtypes=[C.POINTER(C.c_uint8),*types];f.restype=result_type
            for case in range(5000):
                cpu=C166(rom);cpu.mem[0xc000:0xf700]=rng.randbytes(0x3700)
                cpu.wr(0xfd4e,rng.randrange(65536))
                args=[rng.randrange(256 if t==C.c_uint8 else 65536) for t in types]
                if args and case<6:args[0]=[0,1,32767,32768,65534,65535][case] % (256 if types[0]==C.c_uint8 else 65536)
                if name=='scale_and_store_d4ae':cpu.wr(0xd46e,rng.randrange(256,65536))
                if name=='combine_percent_term_d402':cpu.wr(0xd4df,rng.randrange(101),8)
                if name=='update_scaled_difference_d712':
                    cpu.wr(0xf61e,0xc100);cpu.wr(0xf65a,0xc200);cpu.wr(0xf65e,0xc300)
                    cpu.wr(0xc124,rng.randrange(-299,300))
                    cpu.wr(0xff1c,0) # architectural ZEROS, not random RAM
                    if case%3==0:cpu.wr(0xd500,cpu.rd(0xc210))
                cpu.r[12:12+len(args)]=args
                memory=(C.c_uint8*65536).from_buffer_copy(cpu.mem)
                actual=cpu.run(entry);expected=f(memory,*args)
                if result_type is not None:
                    assert actual&((1<<(8 if result_type==C.c_uint8 else 16))-1)==expected,(name,args,actual,expected)
                # Compare all modeled data RAM and flags, excluding machine
                # scratch registers and the compiler's active user stack.
                assert bytes(memory)[0xc000:0xf700]==bytes(cpu.mem)[0xc000:0xf700],(name,case,args)
                assert bytes(memory)[0xf800:0xfe00]==bytes(cpu.mem)[0xf800:0xfe00]
                total+=1;seen.update(cpu.seen)
            print(name,5000,'PASS')
        f=lib.egs52_pid_step
        f.argtypes=[C.POINTER(C.c_uint16),C.POINTER(C.c_int16),C.c_int16,C.POINTER(C.c_int16)];f.restype=C.c_uint16
        for _ in range(5000):
            state=[rng.randrange(65536) for i in range(3)]
            gains=[rng.randrange(-999,1000) for i in range(3)]
            error=rng.randrange(-32768,32768)
            cpu=C166(rom);cpu.r[12:15]=[0xc100,0xc200,error&65535]
            for i,v in enumerate(state):cpu.wr(0xc100+i*2,v)
            for i,v in enumerate(gains):cpu.wr(0xc200+i*2,v)
            actual=cpu.run(0xdfce4)
            st=(C.c_uint16*3)(*state);gg=(C.c_int16*3)(*gains);term=C.c_int16()
            expected=f(st,gg,error,C.byref(term))
            assert actual==expected,('pid',state,gains,error,actual,expected)
            assert list(st)==[cpu.rd(0xc100+i*2) for i in range(3)]
            assert term.value&65535==cpu.rd(0xd494)
            total+=1;seen.update(cpu.seen)
        print('pid_step',5000,'PASS')
        reset=lib.egs52_pid_reset;reset.argtypes=[C.POINTER(C.c_uint16)]
        for _ in range(100):
            cpu=C166(rom);cpu.r[12]=0xc100
            st=(C.c_uint16*3)(*[rng.randrange(65536) for i in range(3)])
            for i,v in enumerate(st):cpu.wr(0xc100+i*2,v)
            cpu.run(0xdfcd6);reset(st)
            assert list(st)==[cpu.rd(0xc100+i*2) for i in range(3)]==[0,0,0]
            total+=1;seen.update(cpu.seen)
        print('pid_reset',100,'PASS')
        f=lib.egs52_near_to_physical;f.argtypes=[C.c_uint16,C.POINTER(C.c_uint16)];f.restype=C.c_uint32
        for _ in range(5000):
            ptr=rng.randrange(65536);pages=[rng.randrange(1024) for _ in range(4)]
            cpu=C166(rom);cpu.r[4]=ptr
            for k,v in enumerate(pages):cpu.wr(0xfe00+2*k,v)
            low=cpu.run(0x92118);actual=cpu.r[5]<<16|low
            assert actual==f(ptr,(C.c_uint16*4)(*pages)),(ptr,pages,actual)
            total+=1;seen.update(cpu.seen)
        print('near_to_physical',5000,'PASS')
    print(f'{total} original-instruction comparisons passed; {len(seen)} distinct instruction addresses.')


if __name__=='__main__':main()
