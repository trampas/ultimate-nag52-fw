// Keil C51 emits `switch` as LCALL ?C?CCASE (0x1CED on EGS51) followed IN-LINE by a table of
// 3-byte entries {target_hi, target_lo, case_value}, terminated by a 0x0000 target and then a
// 2-byte default target. A linear sweep decodes the table as instructions. This script turns
// every such table back into data, adds jump references from the call to each target and
// disassembles the targets. Script arg: the dispatcher address (hex), default 1CED.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.util.*;

public class KeilSwitchTables extends GhidraScript {
    public void run() throws Exception {
        String[] args = getScriptArgs();
        long disp = args.length > 0 ? Long.parseLong(args[0], 16) : 0x1CED;
        AddressSpace sp = currentProgram.getAddressFactory().getDefaultAddressSpace();
        Listing lst = currentProgram.getListing();
        List<Address> calls = new ArrayList<>();
        InstructionIterator it = lst.getInstructions(true);
        while (it.hasNext()) {
            Instruction in = it.next();
            if (in.getFlowType().isCall())
                for (Address t : in.getFlows()) if (t.getOffset() == disp) calls.add(in.getAddress());
        }
        int tables = 0, cases = 0;
        for (Address c : calls) {
            Address p = c.add(3);
            List<Address> targets = new ArrayList<>();
            int n = 0;
            while (n < 64) {
                int hi = getByte(p.add(3L*n)) & 0xff, lo = getByte(p.add(3L*n+1)) & 0xff;
                if (hi == 0 && lo == 0) break;
                targets.add(sp.getAddress((hi << 8) | lo));
                n++;
            }
            if (n == 0 || n >= 64) continue;
            int dhi = getByte(p.add(3L*n+2)) & 0xff, dlo = getByte(p.add(3L*n+3)) & 0xff;
            Address dflt = sp.getAddress((dhi << 8) | dlo);
            Address end = p.add(3L*n+3);
            try {
                clearListing(p, end);
                for (int k = 0; k < n; k++) {
                    createData(p.add(3L*k), WordDataType.dataType);
                    createData(p.add(3L*k+2), ByteDataType.dataType);
                    setEOLComment(p.add(3L*k), "case " + (getByte(p.add(3L*k+2)) & 0xff) + " -> " + targets.get(k));
                }
                createData(p.add(3L*n), WordDataType.dataType);
                createData(p.add(3L*n+2), WordDataType.dataType);
                setEOLComment(p.add(3L*n+2), "default -> " + dflt);
                targets.add(dflt);
                for (Address t : targets) {
                    currentProgram.getReferenceManager().addMemoryReference(c, t, RefType.COMPUTED_JUMP, SourceType.USER_DEFINED, 0);
                    disassemble(t);
                }
                setEOLComment(c, "switch, " + n + " cases (table follows)");
                tables++; cases += n;
            } catch (Exception e) { println("table at " + p + ": " + e); }
        }
        println("KeilSwitchTables: " + tables + " tables, " + cases + " cases");
    }
}
