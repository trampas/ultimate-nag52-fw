// Name and comment the Keil-C51 / SIC810 library helpers and every call to them.
// The six "reserved" SFRs A5 A6 A7 AD AE AF are the 80C517-style MDU (MD0..MD5, in that
// order); the write ORDER selects the operation: MD0,MD4,MD1,MD5 = 16x16 multiply,
// MD0,MD1,MD4,MD5 = 16/16 divide, MD0..MD5 = 32/16 divide. The addresses below are those
// of A0215451432; pass a different table via script args "addr=name=comment;..." if needed.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.SourceType;
import java.util.*;

public class MduAnnotate extends GhidraScript {
    static final String[][] TABLE = {
        {"0BCC", "mdu_muldiv_u16", "(R6:R7 * R4:R5) / R2:R3 -> R6:R7 unsigned"},
        {"0C20", "mdu_muldiv_s16", "(R6:R7 * R4:R5) / R2:R3 -> R6:R7 signed"},
        {"0C0C", "mdu_mul16_32",   "R6:R7 * R4:R5 -> R4:R5:R6:R7 (32-bit)"},
        {"0C7B", "mdu_div32_ram75","R4:R5:R6:R7 / INTMEM{75:76} -> quotient"},
        {"1061", "lag_div",        "R6:R7 += (R4:R5 - R6:R7)/R3 ; R3==0 -> R4:R5"},
        {"1412", "lerp1d_intmem",  "lerp(desc@R7: y0,y1,x0,x1,x u16) clamped"},
        {"14F3", "map2d_rom",      "bilinear(desc@R6:R7: xaddr,nx,yaddr,ny,xax,yax,z)"},
        {"1CA2", "dptr_add_a_mul_b","DPTR += A*B"},
        {"1CED", "keil_switch",    "switch dispatcher; {addr,case} x3 table follows call"},
        {"1DCA", "mdu_pad4",       "MDU timing pad after multiply"},
        {"1DCB", "mdu_pad8",       "MDU timing pad after divide"},
        {"0B3F", "bank_call_same", "bank switch (TCON.4) helper"},
        {"0B57", "bank_call_other","bank switch (TCON.4) helper"},
    };
    static final String[][] SFRS = {
        {"A5","MDU_MD0"},{"A6","MDU_MD1"},{"A7","MDU_MD2"},{"AD","MDU_MD3"},{"AE","MDU_MD4"},{"AF","MDU_MD5"},
        {"91","XPAGE"},{"92","PAGED_IN"},{"98","WDT_SEQ"},{"9A","WDT_CTRL"},{"B8","CAN_CTRL"},{"B9","CAN_DATA"},
        {"BA","CAN_ADDR"},{"BC","CAN_PAGE"},{"C6","SPI_DATA"},{"C7","SPI_CTRL"},{"D9","PWM_MPC_DUTY"},{"DA","PWM_SPC_DUTY"},
        {"DD","PWM_SETCLR"},{"EC","CMP_ISR_LO"},{"ED","CMP_ISR_HI"},{"EE","CMP_TCC_LO"},{"EF","CMP_TCC_HI"},
        {"F3","CMP_LO"},{"F4","CMP_HI"},{"FA","CNT_LO"},{"FB","CNT_HI"},{"FD","CAP_RANGE_A"},{"FE","CAP_RANGE_B"},
        {"E3","CAP1_LO"},{"E4","CAP1_HI"},{"E5","CAP2_LO"},{"E6","CAP2_HI"},
    };
    public void run() throws Exception {
        AddressSpace code = currentProgram.getAddressFactory().getDefaultAddressSpace();
        Map<Long,String[]> byAddr = new HashMap<>();
        for (String[] t : TABLE) byAddr.put(Long.parseLong(t[0],16), t);
        Listing lst = currentProgram.getListing();
        int named = 0, commented = 0;
        for (String[] t : TABLE) {
            Address a = code.getAddress(Long.parseLong(t[0],16));
            Function f = lst.getFunctionAt(a);
            if (f == null) { try { f = createFunction(a, t[1]); } catch (Exception e) {} }
            if (f != null) { try { f.setName(t[1], SourceType.USER_DEFINED); named++; } catch (Exception e) {} }
            setPlateComment(a, t[1] + ": " + t[2]);
        }
        InstructionIterator it = lst.getInstructions(true);
        while (it.hasNext() && !monitor.isCancelled()) {
            Instruction in = it.next();
            if (!in.getFlowType().isCall()) continue;
            for (Address tgt : in.getFlows()) {
                String[] t = byAddr.get(tgt.getOffset());
                if (t != null) { setEOLComment(in.getAddress(), t[1] + " = " + t[2]); commented++; }
            }
        }
        AddressSpace sfr = currentProgram.getAddressFactory().getAddressSpace("SFR");
        int sfrs = 0;
        if (sfr != null) {
            for (String[] s : SFRS) {
                try { createLabel(sfr.getAddress(Long.parseLong(s[0],16)), s[1], true, SourceType.USER_DEFINED); sfrs++; }
                catch (Exception e) {}
            }
        }
        println("MduAnnotate: named " + named + " helpers, commented " + commented + " calls, " + sfrs + " SFR labels");
    }
}
