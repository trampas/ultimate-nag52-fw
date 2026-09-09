// Find the calibration 2-D map descriptors this compiler emits:
//   { x_intmem_addr, nx, y_intmem_addr, ny, x_axis_ptr(2), y_axis_ptr(2), z_ptr(2) }
// with the three pointers ascending and exactly nx / ny (u8 axes) or 2*nx / 2*ny (u16 axes)
// apart. For each hit: clear any swept instructions, create the descriptor and the three
// arrays as data, label them map_XXXX_desc/_x/_y/_z and reference them from the descriptor.
// The map lookup routine reads the descriptor through R6:R7 (map2d_rom, 0x14F3 on EGS51).
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import ghidra.program.model.symbol.*;

public class FindMapDescriptors extends GhidraScript {
    public void run() throws Exception {
        Memory mem = currentProgram.getMemory();
        AddressSpace sp = currentProgram.getAddressFactory().getDefaultAddressSpace();
        int found = 0;
        for (MemoryBlock blk : mem.getBlocks()) {
            if (!blk.getStart().getAddressSpace().equals(sp)) continue;
            long lo = blk.getStart().getOffset(), hi = blk.getEnd().getOffset();
            for (long i = lo; i + 10 <= hi; i++) {
                if (monitor.isCancelled()) return;
                int xa = u8(i), nx = u8(i+1), ya = u8(i+2), ny = u8(i+3);
                if (nx < 2 || nx > 20 || ny < 2 || ny > 20 || xa < 0x30 || ya < 0x30 || xa >= 0xF0 || ya >= 0xF0) continue;
                long px = u16(i+4), py = u16(i+6), pz = u16(i+8);
                if (!(px < py && py < pz) || px < lo || pz > hi) continue;
                int w;
                if (py - px == nx && pz - py == ny) w = 1;
                else if (py - px == 2L*nx && pz - py == 2L*ny) w = 2;
                else continue;
                make(sp, i, xa, nx, ya, ny, px, py, pz, w);
                found++;
            }
        }
        println("FindMapDescriptors: " + found + " descriptors");
    }
    int u8(long a) throws Exception { return getByte(toAddr(a)) & 0xff; }
    long u16(long a) throws Exception { return ((long)u8(a) << 8) | u8(a+1); }
    void make(AddressSpace sp, long d, int xa, int nx, int ya, int ny, long px, long py, long pz, int w) throws Exception {
        String tag = String.format("map_%04x", d);
        DataType el = (w == 1) ? ByteDataType.dataType : WordDataType.dataType;
        Address ad = sp.getAddress(d);
        try {
            clearListing(ad, ad.add(9));
            createData(ad, new ArrayDataType(ByteDataType.dataType, 4, 1));
            createData(ad.add(4), new ArrayDataType(WordDataType.dataType, 3, 2));
            createLabel(ad, tag + "_desc", true, SourceType.USER_DEFINED);
            setEOLComment(ad, String.format("%dx%d map, x in INTMEM 0x%02x, y in INTMEM 0x%02x, %s", nx, ny, xa, ya, w == 1 ? "u8" : "u16"));
            long[][] arr = {{px, nx, 0}, {py, ny, 1}, {pz, (long)nx*ny, 2}};
            String[] nm = {"_x", "_y", "_z"};
            for (long[] a : arr) {
                Address s = sp.getAddress(a[0]);
                clearListing(s, s.add(a[1]*w - 1));
                createData(s, new ArrayDataType(el, (int)a[1], w));
                createLabel(s, tag + nm[(int)a[2]], true, SourceType.USER_DEFINED);
                currentProgram.getReferenceManager().addMemoryReference(ad.add(4 + 2*a[2]), s, RefType.DATA, SourceType.USER_DEFINED, 0);
            }
        } catch (Exception e) { println(tag + ": " + e); }
    }
}
