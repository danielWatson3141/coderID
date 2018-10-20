package round1;

import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class ProperShuffle {
    
    public static void main(String[] args) throws Exception {
        File inputFile = new File("C-small-attempt0.in");
        Scanner in = new Scanner(inputFile);
        File outputFile = new File("output.txt");
        PrintWriter out = new PrintWriter(outputFile);

        int T = in.nextInt();
        for (int t=0; t<T; t++) {
            int N = in.nextInt();
            long sum = 0;
            for (int n=0; n<N; n++) {
                int an = in.nextInt();                
                if (an != 0 && n != N-1) {
                    sum += an-(n+1);
                    if (an < n) {
                        sum += N;
                    }
                }
            }
            boolean good = (497540-sum < sum-469145);
            
            out.println("Case #"+(t+1)+": "+(good ? "GOOD" : "BAD"));
        }

        out.close();
    }
    
}
