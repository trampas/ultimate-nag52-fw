import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.util.*;

public class MakeFuncs extends GhidraScript {
    public void run() throws Exception {
        Listing lst = currentProgram.getListing();
        Set<Address> targets = new TreeSet<>();
        InstructionIterator it = lst.getInstructions(true);
        while (it.hasNext() && !monitor.isCancelled()) {
            Instruction in = it.next();
            if (in.getFlowType().isCall()) {
                for (Address t : in.getFlows()) targets.add(t);
            }
        }
        int made = 0, existed = 0;
        for (Address a : targets) {
            if (monitor.isCancelled()) break;
            if (lst.getFunctionAt(a) != null) { existed++; continue; }
            try { if (createFunction(a, null) != null) made++; } catch (Exception e) {}
        }
        println("MakeFuncs: " + targets.size() + " call targets, created " + made + ", already had " + existed);
    }
}
