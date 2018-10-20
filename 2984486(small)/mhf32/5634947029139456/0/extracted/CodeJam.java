package codejam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Arrays;

/**
 *
 * @author AdamaMahefa
 */
public class CodeJam {

    public static void main(String[] args) throws Exception {
        String downloadFilePath = "C:\\Users\\Study\\Downloads\\";
        String inFile = "A-small-attempt0.in";
        String outFile = "A-small-attempt0.out";
        String className = "Case5";
        Class c = Class.forName("codejam."+className);
        BufferedReader in = new BufferedReader(new FileReader(downloadFilePath+inFile));
        BufferedWriter out = new BufferedWriter(new FileWriter(downloadFilePath+outFile));       
        
        int N = Integer.valueOf(Utils.readLines(1, in)[0]);
        
        for (int i = 1; i <= N; i++) {
            CodeJamProblem cjp = (CodeJamProblem)c.newInstance();
            String[] input = Utils.readLines(cjp.inputLineNumber(), in);
            cjp.collectData(input);
            String[] answer = cjp.solve();
            answer[0] = "Case #"+i+": "+answer[0];
            System.out.println("writing "+Arrays.toString(answer));
            Utils.writeLines(answer, out);
        }
        
        in.close();
        out.close();        
    }
    
}
