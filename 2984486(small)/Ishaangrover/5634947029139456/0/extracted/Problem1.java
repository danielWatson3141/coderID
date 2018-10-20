import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;


public class Problem1 {
    public static void main(String[] args) {
        
        
        
        Scanner k = new Scanner(System.in);
        
        int num_cases = k.nextInt();
        
        for (int a = 0; a < num_cases; ++a) {
            
            int input_length = k.nextInt();
            
            int byte_length = k.nextInt();
           
            ArrayList<String> input = new ArrayList<String>();
            
            ArrayList<String> output = new ArrayList<String>();
            
            int poss = 0;
            int valPoss = 0;
            int ansFinal2 = Integer.MAX_VALUE;
            
            
            int totalComb = (int) Math.pow(2,byte_length);
            
            for (int i1 = 0; i1 < input_length; ++i1) {
                String val = "";
                val += k.next();
                input.add(val);
            }
            
            for (int i1 = 0; i1 < input_length; ++i1) {
                String val = "";
                val += k.next();
                output.add(val);
            }
            
            
            for (int i1 = 0; i1 < totalComb; ++i1) {
                ArrayList<String> modified = new ArrayList<String>();
                for (String s : input) {
                    long newVal = Long.parseLong(s, 2);
                    newVal = newVal ^ i1;
                    String s1 = Long.toBinaryString(newVal);
                    while (s1.length() < byte_length) {
                        s1 = "0" + s1;
                    }
                    modified.add(s1);
                }
                boolean isEqual = checkThings(modified, output);
                if (isEqual) {
                    poss = 1;
                    String bin = Long.toBinaryString(i1);
                    int finalAns = 0;
                    for (int i2 = 0; i2 < bin.length(); ++i2) {
                        if (bin.charAt(i2) == '1') {
                            finalAns++;
                        }
                    }
                    valPoss = finalAns;
                    if (ansFinal2 > valPoss) {
                        ansFinal2 = valPoss;
                    }
                    
                    
                }
            }
            
            if (poss == 1) {
                System.out.println("Case #" + (a+1) + ": " + ansFinal2);
            } else {
                System.out.println("Case #" + (a+1) + ": NOT POSSIBLE");
            }
        }
        
        
    }

    private static boolean checkThings(ArrayList<String> modified,
            ArrayList<String> answer) {
        
        Collections.sort(modified);
        Collections.sort(answer);
        
        return modified.equals(answer);
        
    }
}
