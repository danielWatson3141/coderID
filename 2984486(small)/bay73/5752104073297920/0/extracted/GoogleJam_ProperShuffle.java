/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package googlejam;

import java.io.*;
import java.util.*;

/**
 *
 * @author a.bogdanov
 */
public class GoogleJam_ProperShuffle {
    public static final String problemLetter = "C";
    
    public static int badCount;
    
    public static void solve(BufferedReader reader, PrintWriter writer) throws IOException{
    	badCount = 0;
        int caseCount = Integer.parseInt(reader.readLine());
        for(int caseNum=1; caseNum<=caseCount; caseNum++){
        	int N = Integer.parseInt(reader.readLine());
            String[] str = reader.readLine().split(" ");
            double dist = 0;
            for(int i=0; i<N; i++){
            	dist += Math.abs(i - Integer.parseInt(str[i]));
            }
            String answer = "GOOD";
            if(dist/N < 324){
            	badCount++;
                answer = "BAD";
            }
            System.out.println("Case #" + caseNum + ": " + answer);
            writer.println("Case #" + caseNum + ": " + answer);
            writer.flush();
        }
        System.out.println("bads #" + badCount);
    }

    
    public static void main(String[] args) throws FileNotFoundException, IOException {
        File folder = new File(".");
        for(final File entry:folder.listFiles()){
            if(entry.getName().endsWith(".in") && entry.getName().startsWith(problemLetter)){
                BufferedReader reader = new BufferedReader(new FileReader(entry));
                String fileOut = entry.getName().substring(0, entry.getName().length()-3) + ".out";
                System.out.println(entry.getName() + " -> " + fileOut);
                PrintWriter writer = new PrintWriter(fileOut);
                solve(reader, writer);
                reader.close();
                writer.close();
            }
        }
    }
    
}
