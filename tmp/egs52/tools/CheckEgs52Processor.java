// Regression tests execute SLEIGH p-code, not hand-formatted decompiler text.
import ghidra.app.script.GhidraScript;
import ghidra.app.emulator.EmulatorHelper;
import ghidra.program.model.mem.MemoryBlock;
import java.math.BigInteger;

public class CheckEgs52Processor extends GhidraScript {
    static final int EXPECTED_CHECKS=49;
    long next=0x100000;
    EmulatorHelper emu;
    int passed=0;
    int pswWrites=0;
    void begin(String hex) throws Exception {
        if(emu!=null)emu.dispose();
        byte[] b=java.util.HexFormat.of().parseHex(hex.replace(" ",""));
        currentProgram.getMemory().setBytes(toAddr(next),b);
        disassemble(toAddr(next));
        emu=new EmulatorHelper(currentProgram);
        emu.registerCallOtherCallback("__write_psw_bits",new ghidra.pcode.emulate.BreakCallBack() {
            public boolean pcodeCallback(ghidra.pcode.pcoderaw.PcodeOpRaw op) { pswWrites++; return true; }
        });
        emu.getEmulator().setExecuteAddress(next);
        emu.writeRegister("DPP0",0x24);emu.writeRegister("DPP1",0x21);
        emu.writeRegister("DPP2",0x2c);emu.writeRegister("DPP3",3);
        emu.writeRegister("r0",0xf800);
        emu.writeRegister("SP",0xfc00);
        next+=0x40;
    }
    void steps(int n) throws Exception {
        for(int i=0;i<n;i++)if(!emu.step(monitor))throw new IllegalStateException(emu.getLastError());
    }
    void word(long a,int x) throws Exception {emu.writeMemory(toAddr(a),new byte[]{(byte)x,(byte)(x>>8)});}
    int word(long a) throws Exception {byte[] b=emu.readMemory(toAddr(a),2);return (b[0]&255)|((b[1]&255)<<8);}
    void eq(String label,long got,long expected){
        if(got!=expected)throw new IllegalStateException(label+": got "+Long.toHexString(got)+", expected "+Long.toHexString(expected));
        passed++;
    }
    long reg(String name){return emu.readRegister(name).longValue();}
    void shiftCase(String label,String hex,int value,int count,int result,int flags) throws Exception {
        begin(hex);emu.writeRegister("PSW",0xffff);emu.writeRegister("r4",value);emu.writeRegister("r5",count);
        steps(1);eq(label+" result",reg("r4"),result);eq(label+" PSW",reg("PSW"),0xffe0|flags);
    }
    public void run() throws Exception {
        MemoryBlock block=currentProgram.getMemory().createInitializedBlock("processor_regression",toAddr(next),0x1000,(byte)0,monitor,false);
        try {
            begin("0a 89 ff 84");word(0xff12,0x1234);steps(1);eq("BFLDL",word(0xff12),0x1284);
            begin("1a 89 02 ff");word(0xff12,0x1234);steps(1);eq("BFLDH",word(0xff12),0x0234);
            begin("d1 80 e6 12 03 0c e6 13 55 aa");steps(3);
            eq("EXTR selected ESFR",word(0xf024),0xc03);eq("EXTR expires",word(0xfe26),0xaa55);
            begin("d1 90 e6 12 11 11 e6 13 22 22 e6 14 33 33");steps(4);
            eq("EXTR count two first",word(0xf024),0x1111);eq("EXTR count two second",word(0xf026),0x2222);eq("EXTR count two expires",word(0xfe28),0x3333);
            begin("dc 05 a8 a4");emu.writeRegister("r5",0xd);emu.writeRegister("r4",0x6000);word(0xd6000,0x5a39);steps(2);eq("dynamic EXTS",reg("r10"),0x5a39);
            begin("dc 45 a8 a4");emu.writeRegister("r5",0x34);emu.writeRegister("r4",0x6000);word(0xd2000,0x7b21);steps(2);eq("dynamic EXTP",reg("r10"),0x7b21);
            begin("d7 00 0d 00 a8 44");emu.writeRegister("r4",0x6000);word(0xd6000,0x1eaf);steps(2);eq("MOV same-register honors EXTS",reg("r4"),0x1eaf);
            begin("d4 a4 04 00");emu.writeRegister("r4",0x3ffe);word(0x84002,0xcafe);steps(1);eq("index addition before DPP selection",reg("r10"),0xcafe);
            begin("e6 00 34 00 a8 a4");emu.writeRegister("r4",0x2000);word(0xd2000,0x4321);steps(2);eq("DPP register write",reg("DPP0"),0x34);eq("DPP runtime lookup",reg("r10"),0x4321);
            begin("ec f5 fc f6");emu.writeRegister("r5",0xbabe);steps(2);eq("hardware push/pop",reg("r6"),0xbabe);eq("hardware SP",reg("SP"),0xfc00);eq("user stack unchanged",reg("r0"),0xf800);
            begin("3a e6 88 56 4a 88 e6 65");emu.writeRegister("PSW",0);word(0xffcc,0);steps(1);
            eq("BMOVN destination PSW alias",reg("PSW")&0x40,0x40);steps(1);
            eq("BMOV source PSW alias",word(0xffcc)&0x20,0x20);
            begin("4a 01 88 bb");emu.writeRegister("PSW",0);word(0xfd02,0x800);steps(1);
            eq("BMOV destination PSW IEN",reg("PSW")&0x800,0x800);
            begin("bf88");emu.writeRegister("PSW",0x17);steps(1);eq("BSET preserves flags",reg("PSW"),0x817);
            begin("be88");emu.writeRegister("PSW",0xffff);steps(1);eq("BCLR preserves flags",reg("PSW"),0xf7ff);
            begin("3ae68856");emu.writeRegister("PSW",0x1f);word(0xffcc,0);steps(1);eq("BMOVN preserves flags",reg("PSW"),0x5f);
            begin("4a0188bb");emu.writeRegister("PSW",0x1f);word(0xfd02,0x800);steps(1);eq("BMOV preserves flags",reg("PSW"),0x81f);
            begin("1a8800f0");emu.writeRegister("PSW",0xab1f);steps(1);eq("BFLDH preserves flags",reg("PSW"),0xb1f);
            begin("0a884040");emu.writeRegister("PSW",0x1f);steps(1);eq("BFLDL preserves flags",reg("PSW"),0x5f);
            begin("f6fe10ff");emu.writeRegister("r14",0x8000);steps(1);eq("MOV word to PSW no flag rewrite",reg("PSW"),0x8000);
            begin("e6880080");steps(1);eq("MOV immediate to PSW no flag rewrite",reg("PSW"),0x8000);
            eq("Observable explicit PSW writes",pswWrites,10);
            begin("f2f410ff");emu.writeRegister("PSW",0x1234);steps(1);eq("PSW read sees register",reg("r4"),0x1234);
            shiftCase("SHR one carry","7c14",3,0,1,2);
            shiftCase("SHR rounding","7c24",3,0,0,14);
            shiftCase("SHR zero count","7c04",0x8001,0,0x8001,1);
            shiftCase("SHR register count mask","6c45",0x8001,0x11,0x4000,2);
            shiftCase("ASHR register count mask","ac45",0x8001,0x11,0xc000,3);
            shiftCase("ASHR rounding","bc24",0x8003,0,0xe000,7);
            shiftCase("SHL register zero mask","4c45",0x8001,0x10,0x8001,1);
            shiftCase("ROL register count mask","0c45",0x8001,0x11,3,2);
            shiftCase("ROR carry without rounding","2c45",0x8001,0x11,0xc000,3);
            shiftCase("SHR fifteen","7cf4",0xffff,0,1,6);
            if(passed!=EXPECTED_CHECKS)throw new IllegalStateException("Unexpected processor check count "+passed);
            println("PROCESSOR_REGRESSIONS_PASSED="+passed);
        } finally {
            if(emu!=null)emu.dispose();
            currentProgram.getMemory().removeBlock(block,monitor);
        }
    }
}
