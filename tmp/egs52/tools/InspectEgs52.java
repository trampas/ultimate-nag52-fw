// Read-only inspection; invalid decompiler bodies go to the console, never publication.
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import java.io.*;
import java.util.*;
public class InspectEgs52 extends GhidraScript {
    public void run() throws Exception {
        DecompInterface di=new DecompInterface();di.openProgram(currentProgram);
        try {
            String[] args=getScriptArgs();boolean summary=args.length>0 && args[0].equals("summary");
            ArrayList<String> addresses=new ArrayList<>();
            if(summary) {
                try(BufferedReader br=new BufferedReader(new FileReader(args[1]))) {
                    br.readLine();String line;while((line=br.readLine())!=null)addresses.add(line.split(",")[0]);
                }
            } else addresses.addAll(Arrays.asList(args));
            for(String arg:addresses) {
                Function f=getFunctionAt(toAddr(Long.parseLong(arg,16)));
                if(f==null){println("MISSING="+arg);continue;}
                DecompileResults r=di.decompileFunction(f,30,monitor);
                if(summary) {
                    String source=r.decompileCompleted() && r.getDecompiledFunction()!=null ? r.getDecompiledFunction().getC() : "DECOMPILE_FAILED";
                    java.util.regex.Matcher m=java.util.regex.Pattern.compile("(?:unaff_|extraout_|in_)[A-Za-z0-9_]+").matcher(source);
                    TreeSet<String> unknown=new TreeSet<>();while(m.find())unknown.add(m.group());
                    println("ABI_ISSUE="+arg+" "+String.join(";",unknown));continue;
                }
                println("BEGIN="+arg+" "+f.getSignature());
                if(r.decompileCompleted() && r.getDecompiledFunction()!=null)println(r.getDecompiledFunction().getC());
                else println("ERROR="+r.getErrorMessage());
                println("END="+arg);
            }
        } finally {di.dispose();}
    }
}
