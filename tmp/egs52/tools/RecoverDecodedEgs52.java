// Recover from decoded CPU-order bytes, never the scrambled FLS.
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import ghidra.program.model.data.*;
import ghidra.program.model.pcode.JumpTable;
import ghidra.app.cmd.function.CreateFunctionCmd;
import java.io.*;
import java.util.*;

public class RecoverDecodedEgs52 extends GhidraScript {
    TreeMap<Long,String> seeds = new TreeMap<>();
    ArrayList<String> flowRecords=new ArrayList<>();
    void seed(long a, String name) throws Exception {
        if (a < 0x80000 || a >= 0x100000 || (a & 1) != 0) return;
        seeds.putIfAbsent(a,name);
        if (getInstructionAt(toAddr(a)) == null) disassemble(toAddr(a));
        if (getInstructionAt(toAddr(a)) == null) return;
        Function f=getFunctionAt(toAddr(a));
        if (f==null) f=createFunction(toAddr(a),name);
        if(f!=null && !name.startsWith("egs52_sub_")) f.setName(name,SourceType.USER_DEFINED);
    }
    DataType abiType(String name) {
        switch(name) {
            case "void": return VoidDataType.dataType;
            case "u8": return UnsignedCharDataType.dataType;
            case "u16": return UnsignedShortDataType.dataType;
            case "s16": return ShortDataType.dataType;
            case "p8": return new PointerDataType(UnsignedCharDataType.dataType,2);
            case "p16": return new PointerDataType(UnsignedShortDataType.dataType,2);
            case "ps16": return new PointerDataType(ShortDataType.dataType,2);
            default: throw new IllegalArgumentException(name);
        }
    }
    void applyNativeAbi(File file) throws Exception {
        int count=0;
        try(BufferedReader br=new BufferedReader(new FileReader(file))) {
            br.readLine();String line;
            while((line=br.readLine())!=null) {
                String[] fields=line.split(",",4);
                Function f=getFunctionAt(toAddr(Long.parseLong(fields[0],16)));
                if(f==null) throw new IllegalStateException("Missing ABI function "+fields[0]);
                DataType result=abiType(fields[1]);
                ReturnParameterImpl ret=fields[1].equals("void") ?
                    new ReturnParameterImpl(result,VariableStorage.VOID_STORAGE,currentProgram) :
                    new ReturnParameterImpl(result,currentProgram.getRegister("r4").getAddress(),currentProgram);
                ArrayList<Variable> params=new ArrayList<>();
                for(String spec:fields[2].isEmpty() ? new String[0] : fields[2].split(";")) {
                    String[] part=spec.split(":");DataType type=abiType(part[0]);
                    Address address=part[2].startsWith("stack") ?
                        currentProgram.getAddressFactory().getStackSpace().getAddress(Integer.parseInt(part[2].substring(5))) :
                        currentProgram.getRegister(part[2]).getAddress();
                    params.add(new ParameterImpl(part[1],type,address,currentProgram));
                }
                f.updateFunction(null,ret,params,Function.FunctionUpdateType.CUSTOM_STORAGE,true,SourceType.USER_DEFINED);
                count++;
            }
        }
        println("NATIVE_ABI_APPLIED="+count);
    }
    void applyLeafAbis() throws Exception {
        int count=0;
        FunctionIterator all=currentProgram.getFunctionManager().getFunctions(true);
        while(all.hasNext()) {
            Function f=all.next();if(f.hasCustomVariableStorage())continue;
            InstructionIterator ii=currentProgram.getListing().getInstructions(f.getBody(),true);
            ArrayList<Instruction> body=new ArrayList<>();while(ii.hasNext())body.add(ii.next());
            if(body.size()!=2 || !body.get(1).getMnemonicString().equals("rets"))continue;
            Instruction first=body.get(0);String op=first.getMnemonicString();
            if(!(op.equals("mov") || op.equals("movb")))continue;
            String out=first.getDefaultOperandRepresentation(0);
            if(!(out.equalsIgnoreCase("r4") || out.equalsIgnoreCase("RL4")))continue;
            if(!first.getDefaultOperandRepresentation(1).matches("#?0x[0-9a-fA-F]+"))continue;
            DataType type=op.equals("movb") ? UnsignedCharDataType.dataType : UnsignedShortDataType.dataType;
            ReturnParameterImpl ret=new ReturnParameterImpl(type,currentProgram.getRegister("r4").getAddress(),currentProgram);
            f.updateFunction(null,ret,new ArrayList<Variable>(),Function.FunctionUpdateType.CUSTOM_STORAGE,true,SourceType.USER_DEFINED);
            count++;
        }
        // A sole CALLS followed by RETS forwards the established callee ABI.
        for(int pass=0;pass<8;pass++) {
            boolean changed=false;all=currentProgram.getFunctionManager().getFunctions(true);
            while(all.hasNext()) {
                Function f=all.next();if(f.hasCustomVariableStorage())continue;
                InstructionIterator ii=currentProgram.getListing().getInstructions(f.getBody(),true);
                ArrayList<Instruction> body=new ArrayList<>();while(ii.hasNext())body.add(ii.next());
                if(body.size()!=2 || !body.get(1).getMnemonicString().equals("rets"))continue;
                Instruction call=body.get(0);
                if(!call.getMnemonicString().equals("calls") || call.getFlows().length!=1)continue;
                Function callee=getFunctionAt(call.getFlows()[0]);
                if(callee==null || !callee.hasCustomVariableStorage() || callee.getCallFixup()!=null)continue;
                ArrayList<Variable> params=new ArrayList<>();
                for(Parameter p:callee.getParameters())params.add(new ParameterImpl(p,currentProgram));
                f.updateFunction(null,new ReturnParameterImpl(callee.getReturn(),currentProgram),params,
                    Function.FunctionUpdateType.CUSTOM_STORAGE,true,SourceType.USER_DEFINED);
                changed=true;count++;
            }
            if(!changed)break;
        }
        println("PROVEN_LEAF_OR_FORWARD_ABIS="+count);
    }
    void nameStructuralFunctions(File directory) throws Exception {
        try(PrintWriter report=new PrintWriter(new File(directory,"structural_names.csv"))) {
            report.println("address,name,evidence,confidence");
            FunctionIterator all=currentProgram.getFunctionManager().getFunctions(true);
            while(all.hasNext()) {
                Function f=all.next();String old=f.getName();
                if(!(old.startsWith("egs52_sub_") || old.startsWith("egs52_thunk_")))continue;
                LinkedHashSet<String> writes=new LinkedHashSet<>(),reads=new LinkedHashSet<>();
                ArrayList<String> calls=new ArrayList<>();boolean indirect=false,far=false,arithmetic=false;
                InstructionIterator ii=currentProgram.getListing().getInstructions(f.getBody(),true);
                while(ii.hasNext()) {
                    Instruction i=ii.next();String op=i.getMnemonicString();
                    far|=op.equals("exts") || op.equals("extp");
                    arithmetic|=op.startsWith("mul") || op.startsWith("div") || op.equals("shl") || op.equals("shr");
                    if(i.getFlowType().isCall())for(Address target:i.getFlows())calls.add(String.format("%06x",target.getOffset()));
                    for(int k=0;k<i.getNumOperands();k++) {
                        String operand=i.getDefaultOperandRepresentation(k);
                        if(k==0 && operand.startsWith("[") && !operand.contains("r0") && (op.equals("mov") || op.equals("movb")))indirect=true;
                        java.util.regex.Matcher m=java.util.regex.Pattern.compile("^0x([c-fC-F][0-9a-fA-F]{3})(?:\\.0x[0-9a-fA-F]+)?$").matcher(operand);
                        if(!m.matches())continue;
                        int address=Integer.parseInt(m.group(1),16);
                        if(address>=0xfe00)continue; // CPU core scratch registers are not state roles.
                        String cell=String.format("%04x",address);
                        boolean write=k==0 && (op.equals("mov") || op.equals("movb") || op.equals("bset") || op.equals("bclr") || op.equals("add") || op.equals("sub") || op.equals("and") || op.equals("or") || op.equals("xor"));
                        if(write)writes.add(cell);else reads.add(cell);
                    }
                }
                String role,evidence;
                if(!writes.isEmpty()) {
                    String cell=writes.iterator().next();
                    for(String value:writes)if(value.startsWith("c") || value.startsWith("d")){cell=value;break;}
                    role="update_near_"+cell;
                    evidence="Instruction destination near addresses "+String.join(";",writes);
                } else if(indirect) {
                    role=far?"transform_far_memory":"transform_memory";
                    evidence="Indirect non-R0 memory destinations in decoded instructions";
                } else if(!reads.isEmpty()) {
                    role="compute_from_near_"+reads.iterator().next();
                    evidence="Instruction source near addresses "+String.join(";",reads);
                } else if(!calls.isEmpty()) {
                    role="call_"+calls.get(0);
                    evidence="Direct call targets "+String.join(";",new LinkedHashSet<String>(calls));
                } else {
                    role=arithmetic?"register_arithmetic":"register_sequence";
                    evidence="Register-level instruction sequence; higher-level role unresolved";
                }
                long address=f.getEntryPoint().getOffset();
                String name=String.format("egs52_%s_%06x",role,address);
                f.setName(name,SourceType.USER_DEFINED);
                report.printf("%06x,%s,%s,structural%n",address,name,evidence);
            }
        }
    }
    void recoverIndirectFlows(File tableFile) throws Exception {
        int recovered=0;
        try(BufferedReader br=new BufferedReader(new FileReader(tableFile))) {
            br.readLine();String line;
            while((line=br.readLine())!=null) {
                String[] fields=line.split(",",5);
                Address site=toAddr(Long.parseLong(fields[0],16));
                long table=Long.parseLong(fields[1],16),bank=Long.parseLong(fields[3],16)<<16;
                int count=Integer.parseInt(fields[2]);
                Instruction jump=getInstructionAt(site);
                if(jump==null || !jump.getMnemonicString().equals("jmpi"))
                    throw new IllegalStateException("Missing computed jump "+site);
                Function f=getFunctionContaining(site);
                if(f==null)throw new IllegalStateException("No jump owner at "+site);
                ArrayList<Address> targets=new ArrayList<>();
                for(int i=0;i<count;i++) {
                    int offset=getShort(toAddr(table+2*i))&65535;
                    if(offset==65535 || (offset&1)!=0)throw new IllegalStateException("Bad jump target "+site);
                    Address target=toAddr(bank|offset);
                    disassemble(target);
                    if(getInstructionAt(target)==null)throw new IllegalStateException("Undecodable target "+target);
                    targets.add(target);
                    currentProgram.getReferenceManager().addMemoryReference(site,target,RefType.COMPUTED_JUMP,SourceType.USER_DEFINED,0);
                }
                StringBuilder targetList=new StringBuilder();
                for(Address target:targets){if(targetList.length()>0)targetList.append(";");targetList.append(String.format("%06x",target.getOffset()));}
                flowRecords.add(String.format("%06x,%s,%06x,%d,%02x,%s",f.getEntryPoint().getOffset(),fields[0],table,count,bank>>16,targetList));
                new JumpTable(site,targets,true,0).writeOverride(f);
                f.setBody(CreateFunctionCmd.getFunctionBody(currentProgram,f.getEntryPoint(),false,monitor));
                recovered++;
            }
        }
        // RAM self-test uses R4 as a continuation rather than CALL/RET.
        Address site=toAddr(0x808dc);
        Function boot=getFunctionAt(toAddr(0x805d0));
        for(long address:new long[]{0x807a6,0x807ba,0x807ce}) {
            Address target=toAddr(address);disassemble(target);
            currentProgram.getReferenceManager().addMemoryReference(site,target,RefType.COMPUTED_JUMP,SourceType.USER_DEFINED,0);
        }
        for(long address:new long[]{0x807e2,0x807f4}) {
            Address target=toAddr(address);disassemble(target);
            currentProgram.getReferenceManager().addMemoryReference(toAddr(0x8095e),target,RefType.COMPUTED_JUMP,SourceType.USER_DEFINED,0);
        }
        boot.setBody(CreateFunctionCmd.getFunctionBody(currentProgram,boot.getEntryPoint(),false,monitor));
        println("INDIRECT_TABLES_RECOVERED="+recovered);
    }
    public void run() throws Exception {
        String[] args=getScriptArgs();
        File dir=new File(args[0]); dir.mkdirs(); new File(dir,"functions").mkdirs();
        if(currentProgram.getMemory().getBlock(toAddr(0))==null)
            currentProgram.getMemory().createUninitializedBlock("RAM_SFR",toAddr(0),0xc000,false);
        int[] pages={0x24,0x21,0x2c,3};
        for(int k=0;k<4;k++) currentProgram.getProgramContext().setValue(currentProgram.getRegister("DPP"+k),toAddr(0x80000),toAddr(0xfffff),java.math.BigInteger.valueOf(pages[k]));
        // 0x088000..0x088023 currently contains a header, not instructions.
        // A guarded boot jump can enter this mutable flash region on another
        // image; do not manufacture code from this image's header bytes.
        createData(toAddr(0x88000),new ghidra.program.model.data.ArrayDataType(ghidra.program.model.data.ByteDataType.dataType,0x24,1));
        for(int v=0;v<0x200;v+=4){
            long a=0x80000+v;
            if((getByte(toAddr(a))&255)!=0xfa) continue;
            long target=((getByte(toAddr(a+1))&255)<<16)|(getShort(toAddr(a+2))&65535);
            seed(a,String.format("egs52_vector_%03x",v));
            seed(target,v==0?"egs52_reset_startup":String.format("egs52_interrupt_%03x",v));
        }
        seed(0x93b00,"egs52_application_reset_vector");
        seed(0x93d00,"egs52_application_startup");
        // CALLS opcodes in established code windows provide additional roots,
        // including dispatch-table-only routines. Targets must be aligned code.
        long[][] windows={{0x805d0,0x83e00},{0x88024,0x8a400},{0x92200,0xa8000},{0xd0000,0xe8200}};
        for(long[] w:windows) for(long a=w[0];a<w[1]-3;a+=2){
            if((getByte(toAddr(a))&255)!=0xda)continue;
            Instruction containing=getInstructionContaining(toAddr(a));
            if(containing!=null && (!containing.getAddress().equals(toAddr(a)) || !containing.getFlowType().isCall()))continue;
            long target=((getByte(toAddr(a+1))&255)<<16)|(getShort(toAddr(a+2))&65535);
            boolean valid=false; for(long[] v:windows)if(target>=v[0]&&target<v[1])valid=true;
            if(valid)seed(target,String.format("egs52_sub_%06x",target));
        }
        for(int pass=0;pass<12;pass++){
            int before=seeds.size();
            ArrayList<Long> targets=new ArrayList<>();
            InstructionIterator ii=currentProgram.getListing().getInstructions(true);
            while(ii.hasNext()){
                Instruction i=ii.next();
                if(i.getFlowType().isCall()) for(Address a:i.getFlows()) targets.add(a.getOffset());
            }
            for(long a:targets) seed(a,String.format("egs52_sub_%06x",a));
            println("RECOVERY_PASS="+pass+" seeds="+seeds.size());
            if(seeds.size()==before)break;
        }
        // Boot dispatch records are {far callback, packed service metadata}.
        // Metadata such as 0x000e0036 is NOT a code pointer. Memory descriptors
        // beside these records likewise contain flash endpoints, not callbacks.
        long[][] bootTables={{0x8028c,18},{0x8031c,17}};
        for(long[] table:bootTables) for(int row=0;row<table[1];row++) {
            long slot=table[0]+8*row;
            long callback=getInt(toAddr(slot))&0xffffffffL;
            int service=getByte(toAddr(slot+4))&255;
            if(callback<0x805d0 || callback>=0x8a400 || (callback&1)!=0)
                throw new IllegalStateException("Invalid boot callback at "+Long.toHexString(slot));
            seed(callback,String.format("egs52_boot_service_%02x",service));
        }
        // Only audited callback layouts seed data-driven roots. Arbitrary
        // calibration words can resemble pointers and split real functions.
        int callbackCells=0;
        try(BufferedReader br=new BufferedReader(new FileReader(new File(new File(args[1]).getParentFile(),"callback_tables.csv")))) {
            br.readLine();String line;
            while((line=br.readLine())!=null) {
                String[] fields=line.split(",",4);long base=Long.parseLong(fields[0],16);
                int count=Integer.parseInt(fields[1]),stride=Integer.parseInt(fields[2]);
                if(stride!=4 && stride!=8)throw new IllegalStateException("Bad callback stride");
                for(int k=0;k<count;k++) {
                    long slot=base+(long)k*stride,target=getInt(toAddr(slot))&0xffffffffL;
                    callbackCells++;if(target==0)continue;
                    boolean valid=false;for(long[] w:windows)valid|=target>=w[0]&&target<w[1];
                    if(!valid || (target&1)!=0)throw new IllegalStateException("Bad callback at "+Long.toHexString(slot));
                    seed(target,String.format("egs52_sub_%06x",target));
                    if(getFunctionAt(toAddr(target))==null)throw new IllegalStateException("Missing callback function "+Long.toHexString(target));
                }
            }
        }
        println("AUDITED_CALLBACK_CELLS="+callbackCells);
        // Newly seeded table-only callers can expose additional direct calls.
        for(int pass=0;pass<12;pass++) {
            int before=seeds.size();ArrayList<Long> targets=new ArrayList<>();
            InstructionIterator ii=currentProgram.getListing().getInstructions(true);
            while(ii.hasNext()) {Instruction i=ii.next();if(i.getFlowType().isCall())for(Address target:i.getFlows())targets.add(target.getOffset());}
            for(long target:targets)seed(target,String.format("egs52_sub_%06x",target));
            if(seeds.size()==before)break;
        }
        recoverIndirectFlows(new File(new File(args[1]).getParentFile(),"jump_tables.csv"));
        try(PrintWriter out=new PrintWriter(new File(dir,"recovered_jumps.csv"))) {
            out.println("owner,site,table,count,bank,targets");
            for(String row:flowRecords)out.println(row);
        }
        // Auto switch speculation is deliberately disabled.

        // Ghidra aliases default thunk names to their targets. Keep these as
        // explicit forwarding functions so the exported C has unique symbols.
        FunctionIterator thunks=currentProgram.getFunctionManager().getFunctions(true);
        while(thunks.hasNext()){
            Function f=thunks.next();
            if(f.isThunk()){
                long a=f.getEntryPoint().getOffset();
                f.setThunkedFunction(null);
                f.setName(String.format("egs52_thunk_%06x",a),SourceType.USER_DEFINED);
            }
        }
        File symbolFile=new File(args[1]);
        try(BufferedReader br=new BufferedReader(new FileReader(symbolFile))){
            br.readLine();String line;
            while((line=br.readLine())!=null){
                String[] fields=line.split(",",4);long address=Long.parseLong(fields[0],16);
                Function f=getFunctionAt(toAddr(address));
                if(f!=null)f.setName(fields[1],SourceType.USER_DEFINED);
            }
        }
        FunctionIterator rename=currentProgram.getFunctionManager().getFunctions(true);
        while(rename.hasNext()){
            Function f=rename.next();long a=f.getEntryPoint().getOffset();
            if(f.getName().startsWith("FUN_"))f.setName(String.format("egs52_sub_%06x",a),SourceType.USER_DEFINED);
            else if(f.getName().startsWith("egs52_sub_") && !f.getName().equals(String.format("egs52_sub_%06x",a)))
                f.setName(String.format("egs52_thunk_%06x",a),SourceType.USER_DEFINED);
        }
        long[] fixAddresses={0x92118,0x9212e,0x9214e,0x921b4,0x92226,0x9222c,0x83132,0x83138};
        String[] fixNames={"egs52_near_to_far_registers","egs52_mul32_registers","egs52_sdiv32_registers","egs52_udiv32_registers","call_far_indirect","egs52_read_far_u32_registers","call_far_indirect","egs52_read_far_u32_registers"};
        for(int k=0;k<fixAddresses.length;k++){
            Function f=getFunctionAt(toAddr(fixAddresses[k]));if(f!=null)f.setCallFixup(fixNames[k]);
        }
        applyNativeAbi(new File(symbolFile.getParentFile(),"native_abi.csv"));
        applyLeafAbis();
        nameStructuralFunctions(dir);
        // Prefix smoke check catches the upstream off-by-one EXTR context bug.
        Instruction smoke=getInstructionAt(toAddr(0x805e4));
        if(smoke==null || !smoke.toString().contains("0xf024"))
            throw new IllegalStateException("EXTR decode failed: "+smoke);
        DecompInterface di=new DecompInterface(); di.openProgram(currentProgram);
        try(PrintWriter idx=new PrintWriter(new File(dir,"functions_index.csv"));
            PrintWriter asm=new PrintWriter(new File(dir,"firmware.asm"));
            PrintWriter calls=new PrintWriter(new File(dir,"calls.csv"))){
            idx.println("address,file_offset,name,body_bytes,instructions,decompiled,warnings");
            calls.println("caller,site,target,kind");
            InstructionIterator ii=currentProgram.getListing().getInstructions(true);
            while(ii.hasNext()){
                Instruction i=ii.next(); StringBuilder bytes=new StringBuilder();
                for(byte b:i.getBytes())bytes.append(String.format("%02x",b&255));
                asm.printf("%06x  %-8s  %s%n",i.getAddress().getOffset(),bytes,i);
                if(i.getFlowType().isCall() || i.getFlowType().isComputed()){
                    Function f=getFunctionContaining(i.getAddress());
                    for(Address a:i.getFlows()) calls.printf("%s,%s,%s,%s%n",f==null?"":f.getName(),i.getAddress(),a,i.getFlowType());
                }
            }
            FunctionIterator fi=currentProgram.getFunctionManager().getFunctions(true);
            int total=0,ok=0;
            while(fi.hasNext()){
                Function f=fi.next(); long a=f.getEntryPoint().getOffset(); if(a<0x80000)continue;
                if(f.getName().startsWith("FUN_"))f.setName(String.format("egs52_sub_%06x",a),SourceType.USER_DEFINED);
                DecompileResults r=di.decompileFunction(f,10,monitor);
                String c=r.decompileCompleted() && r.getDecompiledFunction()!=null?r.getDecompiledFunction().getC():null;
                int n=0; ii=currentProgram.getListing().getInstructions(f.getBody(),true); while(ii.hasNext()){ii.next();n++;}
                idx.printf("%06x,%06x,%s,%d,%d,%s,%d%n",a,a-0x80000,f.getName(),f.getBody().getNumAddresses(),n,c!=null,c==null?0:c.split("WARNING",-1).length-1);
                try(PrintWriter out=new PrintWriter(new File(dir,"functions/"+String.format("%06x_%s.c",a,f.getName())))){
                    out.printf("/* Decoded EGS52; CPU 0x%06x; FLS offset 0x%06x.\n * Ghidra decompiler output: inferred types and ABI; consult firmware.asm. */%n",a,a-0x80000);
                    if(c!=null){out.println(c);ok++;}else out.println("/* DECOMPILATION FAILED: "+r.getErrorMessage()+" */");
                }
                total++;
            }
            println("EXPORTED="+total+" DECOMPILED="+ok);
        } finally {di.dispose();}
    }
}
