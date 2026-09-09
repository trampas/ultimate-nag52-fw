// The other jump-table form in this ROM: `MOV DPTR,#table ; ... JMP @A+DPTR` where the
// table is a run of LJMP instructions (3 bytes each), indexed by state*3. Ghidra reports
// "Could not recover jumptable" and leaves the indirect jump with no outgoing flow, so the
// case bodies stay unreachable and the decompiler shows a call through a code pointer
// (bank1 0x5C65 -> the engagement state machine's nine states is the example).
//
// This script finds every `MOV DPTR,#imm` whose immediate starts a run of >= 3 LJMPs,
// labels the table, and adds a COMPUTED_JUMP reference from the nearest following
// `JMP @A+DPTR` to each target, creating a function at each one. Run after MakeFuncs.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.util.*;

public class LjmpTables extends GhidraScript {
    static final int MIN_ENTRIES = 3, MAX_ENTRIES = 64, MAX_SCAN = 40;

    public void run() throws Exception {
        AddressSpace sp = currentProgram.getAddressFactory().getDefaultAddressSpace();
        Listing lst = currentProgram.getListing();
        int tables = 0, targets = 0;
        InstructionIterator it = lst.getInstructions(true);
        List<Instruction> all = new ArrayList<>();
        while (it.hasNext()) all.add(it.next());

        for (int i = 0; i < all.size(); i++) {
            if (monitor.isCancelled()) break;
            Instruction in = all.get(i);
            if (!in.getMnemonicString().equalsIgnoreCase("MOV")) continue;
            Object[] o0 = in.getOpObjects(0), o1 = in.getOpObjects(1);
            if (o0.length == 0 || !o0[0].toString().equalsIgnoreCase("DPTR")) continue;
            if (o1.length == 0 || !(o1[0] instanceof ghidra.program.model.scalar.Scalar)) continue;
            long base = ((ghidra.program.model.scalar.Scalar) o1[0]).getUnsignedValue();

            // count the LJMP run at `base`
            List<Address> tgts = new ArrayList<>();
            try {
                for (int k = 0; k < MAX_ENTRIES; k++) {
                    Address e = sp.getAddress(base + 3L * k);
                    if ((getByte(e) & 0xff) != 0x02) break;         // LJMP opcode
                    int t = ((getByte(e.add(1)) & 0xff) << 8) | (getByte(e.add(2)) & 0xff);
                    if (t == 0 || t == 0xFFFF) break;
                    tgts.add(sp.getAddress(t));
                }
            } catch (Exception e) { continue; }
            if (tgts.size() < MIN_ENTRIES) continue;

            // find the indirect jump that consumes it, within a few instructions
            Instruction jmp = null;
            for (int k = i + 1; k < all.size() && k < i + MAX_SCAN; k++) {
                Instruction c = all.get(k);
                String s = c.toString().replaceAll("\\s+", "");
                if (s.equalsIgnoreCase("JMP@A+DPTR")) { jmp = c; break; }
                if (c.getMnemonicString().equalsIgnoreCase("MOV")) {
                    Object[] p = c.getOpObjects(0);
                    if (p.length > 0 && p[0].toString().equalsIgnoreCase("DPTR") && k > i) break; // DPTR reloaded
                }
            }
            if (jmp == null) continue;

            Address tbl = sp.getAddress(base);
            try { createLabel(tbl, String.format("jumptbl_%04x", base), true, SourceType.USER_DEFINED); } catch (Exception e) {}
            setEOLComment(jmp.getAddress(), "computed jump, " + tgts.size() + " entries at " + tbl);
            for (int k = 0; k < tgts.size(); k++) {
                Address t = tgts.get(k);
                currentProgram.getReferenceManager().addMemoryReference(
                        jmp.getAddress(), t, RefType.COMPUTED_JUMP, SourceType.USER_DEFINED, 0);
                try {
                    disassemble(t);
                    if (getFunctionAt(t) == null) createFunction(t, String.format("case_%04x_%d", base, k));
                    setPlateComment(t, String.format("case %d of jumptbl_%04x", k, base));
                } catch (Exception e) {}
                targets++;
            }
            tables++;
        }
        println("LjmpTables: " + tables + " tables, " + targets + " targets");
    }
}
