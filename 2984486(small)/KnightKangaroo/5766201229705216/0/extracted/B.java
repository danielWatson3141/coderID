import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class B {
    static Scanner input;
    static BufferedWriter output;

    public static void main(String[] args) throws IOException {
        input = new Scanner(new File(args[0]));
        output = new BufferedWriter(new FileWriter("small.out"));

        int numCase = input.nextInt();

        for (int i = 0; i < numCase; i++) {
            output.write("Case #" + (i + 1) + ": ");
            
            int N = input.nextInt();
            int binCount = 0;
            
            int[] count = new int[N + 1];
            
            for (int j = 0; j < N - 1; j++) {
                int X = input.nextInt();
                int Y = input.nextInt();
                
                count[X]++;
                count[Y]++;
            }
            
            if (N > 2) {
                for (int j = 1; j < N + 1; j++) {
                    if (count[j] == 2)
                        binCount++;
                    else if (count[j] > 3) {
                        if (binCount > 0)
                            binCount += count[j] - 3;
                        else
                            binCount += count[j] - 2;
                    }
                        
                }
                
                binCount--;
            }
            
            output.write(binCount + "\n");
        }
        
        output.close();
    }
    
}