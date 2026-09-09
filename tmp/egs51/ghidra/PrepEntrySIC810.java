// Seed entry points for a Siemens SIC810 ("SIECO 51") image. Unlike a stock 8051 the
// interrupt vectors are THREE bytes apart from 0x0003 (reset at 0x0000), each a bare LJMP.
// Use instead of PrepEntry.java when the part is a SIC810 / 51C810; harmless on an 8051
// because it only seeds where the byte is 0x02 (LJMP).
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSpace;

public class PrepEntrySIC810 extends GhidraScript {
    public void run() throws Exception {
        AddressSpace sp = currentProgram.getAddressFactory().getDefaultAddressSpace();
        int ok = 0;
        for (int v = 0; v <= 0x33; v += (v == 0 ? 3 : 3)) {
            Address a = sp.getAddress(v);
            try {
                if ((getByte(a) & 0xff) != 0x02) continue;   // LJMP opcode
                int target = ((getByte(a.add(1)) & 0xff) << 8) | (getByte(a.add(2)) & 0xff);
                if (disassemble(a)) ok++;
                Address t = sp.getAddress(target);
                disassemble(t);
                if (getFunctionAt(t) == null) createFunction(t, "isr_vec" + (v / 3));
                setEOLComment(a, "SIC810 vector " + (v / 3));
            } catch (Exception e) { println("vector " + v + ": " + e); }
        }
        println("PrepEntrySIC810: seeded " + ok + " vectors (3-byte spacing)");
    }
}
