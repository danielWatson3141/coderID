import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

public class A {
    static Scanner input;
    static BufferedWriter output;

    public static void main(String[] args) throws IOException {
        input = new Scanner(new File(args[0]));
        output = new BufferedWriter(new FileWriter("small.out"));

        int numCase = input.nextInt();

        for (int i = 0; i < numCase; i++) {
            output.write("Case #" + (i + 1) + ": ");
            
            int N = input.nextInt();
            int L = input.nextInt();
            
            int[] outlet = new int[N];
            int[] result = new int[N];
            int[] attempt = new int[N];
            
            for (int j = 0; j < N; j++) {
                outlet[j] = Integer.parseInt(input.next(), 2);
            }
            
            for (int j = 0; j < N; j++) {
                result[j] = Integer.parseInt(input.next(), 2);
            }
            
            Arrays.sort(result);
            
            int minAction = L + 1;
            
            for (int j = 0; j < Math.pow(2, L) + 1; j++) {
                for (int k = 0; k < N; k++) {
                    attempt[k] = (outlet[k] ^ j);
                }
                
                Arrays.sort(attempt);
                
                if (Arrays.equals(result, attempt)) {
                    int action = 0;
                    
                    for (int k = 1; action < minAction && k < Math.pow(2, L); k *= 2) {
                        if ((k & j) != 0)
                            action++;
                    }
                    
                    if (action < minAction)
                        minAction = action;
                }
            }
            
            if (minAction < L + 1) {
                output.write(minAction + "\n");
            }
            else
                output.write("NOT POSSIBLE\n");
        }
        
        
        output.close();
    }
    
}