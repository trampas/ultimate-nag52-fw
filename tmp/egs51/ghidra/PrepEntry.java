import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSpace;

public class PrepEntry extends GhidraScript {
    public void run() throws Exception {
        AddressSpace sp = currentProgram.getAddressFactory().getDefaultAddressSpace();
        // 8051 reset + interrupt vectors, 8 bytes apart from 0x0003
        int[] vec = {0x0000,0x0003,0x000B,0x0013,0x001B,0x0023,0x002B,0x0033,0x003B,0x0043,0x004B,0x0053,0x005B,0x0063};
        int ok = 0;
        for (int v : vec) {
            Address a = sp.getAddress(v);
            try { if (disassemble(a)) { createFunction(a, null); ok++; } } catch (Exception e) {}
        }
        println("PrepEntry: seeded " + ok + " vectors in " + sp.getName());
    }
}
