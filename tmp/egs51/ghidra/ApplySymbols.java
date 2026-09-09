// Apply reconstructed/symbols.txt to the open program. Line formats (see that file):
//   B0:0x1234  name ; note      code label + plate comment, only if this program is bank 0
//   B1:0x1234  name ; note      same for bank 1
//   X:0x0012   name ; note      EXTMEM (on-chip XRAM) label
//   I:0x95     name ; note      INTMEM label
//   SFR:0x98   name ; note      SFR label
// Script args: [path-to-symbols.txt] [bank]. Bank defaults from the program name (EGS51A=0, EGS51B=1).
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.SourceType;
import java.io.*;
import java.util.regex.*;

public class ApplySymbols extends GhidraScript {
    public void run() throws Exception {
        String[] args = getScriptArgs();
        String path = args.length > 0 ? args[0] : "reconstructed/symbols.txt";
        int bank = args.length > 1 ? Integer.parseInt(args[1]) : (currentProgram.getName().contains("B") ? 1 : 0);
        AddressSpace code = currentProgram.getAddressFactory().getDefaultAddressSpace();
        AddressSpace xram = currentProgram.getAddressFactory().getAddressSpace("EXTMEM");
        AddressSpace iram = currentProgram.getAddressFactory().getAddressSpace("INTMEM");
        AddressSpace sfr  = currentProgram.getAddressFactory().getAddressSpace("SFR");
        Pattern pat = Pattern.compile("^(B0|B1|X|I|SFR):0x([0-9A-Fa-f]+)\\s+([A-Za-z_][A-Za-z0-9_]*)\\s*(?:;\\s*(.*))?$");
        int applied = 0;
        try (BufferedReader r = new BufferedReader(new FileReader(path))) {
            String line;
            while ((line = r.readLine()) != null) {
                Matcher m = pat.matcher(line.trim());
                if (!m.matches()) continue;
                String kind = m.group(1); long off = Long.parseLong(m.group(2), 16);
                String name = m.group(3); String note = m.group(4);
                AddressSpace sp = null;
                if (kind.equals("B0") || kind.equals("B1")) { if (Integer.parseInt(kind.substring(1)) != bank) continue; sp = code; }
                else if (kind.equals("X")) sp = xram; else if (kind.equals("I")) sp = iram; else sp = sfr;
                if (sp == null) continue;
                Address a = sp.getAddress(off);
                try {
                    if (sp == code) {
                        Function f = getFunctionAt(a);
                        if (f != null) f.setName(name, SourceType.USER_DEFINED); else createLabel(a, name, true, SourceType.USER_DEFINED);
                        if (note != null) setPlateComment(a, note);
                    } else {
                        createLabel(a, name, true, SourceType.USER_DEFINED);
                        if (note != null) setEOLComment(a, note);
                    }
                    applied++;
                } catch (Exception e) { println(line + ": " + e); }
            }
        }
        println("ApplySymbols: applied " + applied + " symbols for bank " + bank);
    }
}
