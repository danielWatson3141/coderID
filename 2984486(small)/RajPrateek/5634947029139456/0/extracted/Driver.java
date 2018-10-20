import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;


public class Driver{
    @SuppressWarnings("resource")
	public static void main(String[] args) {
        
        
        
        Scanner scanner = new Scanner(System.in);
        
        int T = scanner.nextInt();
        
        for (int i = 0; i < T; ++i) {
            
            int N = scanner.nextInt();
            
            int L = scanner.nextInt();
           
            ArrayList<String> inp = new ArrayList<>();
            
            ArrayList<String> answer = new ArrayList<>();
            
            int possible = 0;
            int possibleVal = 0;
            int finalAns2 = Integer.MAX_VALUE;
            
            
            int maxCombinations = (int) Math.pow(2,L);
            
            for (int i1 = 0; i1 < N; ++i1) {
                String val = "";
                val += scanner.next();
                inp.add(val);
            }
            
            for (int i1 = 0; i1 < N; ++i1) {
                String val = "";
                val += scanner.next();
                answer.add(val);
            }
            
            
            for (int i1 = 0; i1 < maxCombinations; ++i1) {
                ArrayList<String> changed = new ArrayList<>();
                for (String s : inp) {
                    long newVal = Long.parseLong(s, 2);
                    newVal = newVal ^ i1;
                    String s1 = Long.toBinaryString(newVal);
                    while (s1.length() < L) {
                        s1 = "0" + s1;
                    }
                    changed.add(s1);
                }
                Collections.sort(changed);
                Collections.sort(answer);
                
                boolean isEqual = changed.equals(answer);
                if (isEqual) {
                    possible = 1;
                    String bin = Long.toBinaryString(i1);
                    int finalAns = 0;
                    for (int i2 = 0; i2 < bin.length(); ++i2) {
                        if (bin.charAt(i2) == '1') {
                            finalAns++;
                        }
                    }
                    possibleVal = finalAns;
                    if (finalAns2 > possibleVal) {
                        finalAns2 = possibleVal;
                    }
                    
                    
                }
            }
            
            if (possible == 1) {
                System.out.println("Case #" + (i+1) + ": " + finalAns2);
            } else {
                System.out.println("Case #" + (i+1) + ": NOT POSSIBLE");
            }
        }
        
        
    }


}
