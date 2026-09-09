import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import java.io.*;

public class DumpAll extends GhidraScript {
    public void run() throws Exception {
        String out = "/home/trampas/egs51_disasm/out";
        String name = currentProgram.getName();
        PrintWriter dec = new PrintWriter(new BufferedWriter(new FileWriter(out + "/" + name + ".c")));
        DecompInterface di = new DecompInterface();
        di.openProgram(currentProgram);
        FunctionIterator fi = currentProgram.getFunctionManager().getFunctions(true);
        int n = 0;
        while (fi.hasNext() && !monitor.isCancelled()) {
            Function f = fi.next();
            dec.println("// ======== " + f.getName() + " @ " + f.getEntryPoint());
            try {
                DecompileResults r = di.decompileFunction(f, 45, monitor);
                if (r != null && r.decompileCompleted()) dec.println(r.getDecompiledFunction().getC());
                else dec.println("// decompile failed");
            } catch (Exception e) { dec.println("// exception: " + e); }
            n++;
        }
        dec.close();
        PrintWriter lst = new PrintWriter(new BufferedWriter(new FileWriter(out + "/" + name + ".asm")));
        InstructionIterator ii = currentProgram.getListing().getInstructions(true);
        while (ii.hasNext() && !monitor.isCancelled()) {
            Instruction in = ii.next();
            lst.println(in.getAddress() + "  " + in.toString());
        }
        lst.close();
        println("DumpAll: " + n + " functions for " + name);
    }
}
