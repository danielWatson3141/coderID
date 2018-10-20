package codejama;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;

public class CodeJamA {
    
    static boolean bWriteToFile = true;
    
    public static BufferedReader inputFileReader;
    public static BufferedWriter outputFileWriter;

    public static void main(String[] args) {
        try {
            inputFileReader = new BufferedReader(new FileReader("D:/codejam/input.txt"));
            outputFileWriter = new BufferedWriter(new FileWriter("D:/codejam/output.txt", false));
            int cases = Integer.parseInt(inputFileReader.readLine());
            int loop = 0;
            
            String line;
            while ((line = inputFileReader.readLine()) != null) {
                loop++;
                
                String NL = line;
                String[] parts = NL.split(" ");
                int N = Integer.parseInt(parts[0]);
                int L = Integer.parseInt(parts[1]);
                
                String[] socketsS = (inputFileReader.readLine()).split(" ");
                String[] requireS = (inputFileReader.readLine()).split(" ");
                
                long set = (long)Math.pow(2, L);
                int min = L + 1000;
                boolean flagged = false;
                for (int j = 0; j < set; j++) {
                    String bin = Integer.toBinaryString(j);
                    bin = ("0000000000" + bin).substring(bin.length());
                    HashMap<String, Integer> hash = new HashMap<>();
                    for (int i = 0; i < N; i++) {
                        String bin2 = socketsS[i];
                        bin2 = ("0000000000" + bin2).substring(bin2.length());
                        
                        StringBuilder build = new StringBuilder(bin2);
                        int countBleed = 0;
                        for (int k = 0; k < bin2.length(); k++) {
                            if (bin.charAt(k) == '1'){
                                char amend = (bin2.charAt(k) == '1')? '0':'1';
                                build.setCharAt(k, amend);
                                countBleed++;
                            }
                        }
                        String finalBin = build.toString();
                        finalBin = finalBin.substring(finalBin.length() - L);
                        hash.put(finalBin, countBleed);
                    }
                    int u = 0;
                    boolean allmatch = true;
                    for (int i = 0; i < N; i++) {
                        if (hash.containsKey(requireS[i])) {
                            u = hash.get(requireS[i]);
                        } else {
                            allmatch = false;
                        }
                    }
                    if (allmatch) {
                        if (min > u) {
                            min = u;
                            flagged = true;
                        }
                    }
                }
                
                String out = flagged ? "" + min: "NOT POSSIBLE" ; 
                
                writeOutput("Case #" + loop + ": " + out);
            }
            
            inputFileReader.close();
            outputFileWriter.close();
        }
        catch (IOException e) {
            e.printStackTrace();
        }
        
    }
    
    public static void writeOutput(String sLine) throws IOException {    
        if (bWriteToFile) {
            outputFileWriter.write(sLine);
            outputFileWriter.newLine();
        } else {
            System.out.println(sLine);
        }
    }
    
}
