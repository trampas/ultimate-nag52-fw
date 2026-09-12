import sys,ctypes as c,tempfile
from pathlib import Path
sys.path.insert(0,str(Path.cwd()/'sim'))
import egs51
from verify_model import base,state,word
with tempfile.TemporaryDirectory() as td:
 lib,_=egs51.build(Path(td));cpu=base(0)
 cpu.x[0x175]=egs51.ROM[0xfbfb];cpu.x[0x176]=egs51.ROM[0xfbfc]
 cpu.x[0x183]=1;cpu.x[0x184]=3;cpu.x[0x185]=10;cpu.x[0x17b]=32;cpu.x[0x17c]=34;cpu.x[0x75]=8
 word(cpu.x,0x181,1975);word(cpu.x,0x17f,3070);word(cpu.im,0x87,750)
 s=state(cpu)
 def call(n):
  f=getattr(lib,'egs51_'+n);f.argtypes=[c.POINTER(egs51.State)];f(c.byref(s))
 call('controller_init');call('pressure_init')
 for t in range(1000):
  s.x[0x75]=8 if t<100 else 5
  word(s.im,0x87,750);word(s.im,0x81,750);word(s.im,0x83,0)
  s.x[0x76]=110;s.im[0x80]=120;s.x[0x7c]=255
  s.x[0x86]=10;s.x[0x9b]=20;s.x[0x9e]=20;s.x[0x9f]=110;s.x[0x8b]=110
  call('scheduler_tick')
  if t%25==0: print(t,list(s.im[0xa9:0xae]),'mode',s.im[0xb6],'gear',s.im[0xb9], 'flags',hex(s.im[0x9a]),hex(s.x[0x1c6]),'p',list(s.x[0x361:0x36b]),flush=True)
