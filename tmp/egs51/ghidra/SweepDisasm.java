import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.MemoryBlock;

public class SweepDisasm extends GhidraScript {
    public void run() throws Exception {
        AddressSpace sp = currentProgram.getAddressFactory().getDefaultAddressSpace();
        Listing lst = currentProgram.getListing();
        int made = 0;
        for (MemoryBlock b : currentProgram.getMemory().getBlocks()) {
            if (!b.isInitialized()) continue;
            long start = b.getStart().getOffset(), end = b.getEnd().getOffset();
            for (long off = start; off <= end && !monitor.isCancelled(); off++) {
                Address a = sp.getAddress(off);
                if (lst.getInstructionAt(a) != null) continue;
                if (lst.getDefinedDataAt(a) != null) continue;
                try { if (disassemble(a)) made++; } catch (Exception e) {}
            }
        }
        println("SweepDisasm: disassembled " + made + " new locations");
    }
}
