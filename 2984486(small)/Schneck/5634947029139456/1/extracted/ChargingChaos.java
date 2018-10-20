
import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class ChargingChaos {
    public static final PrintStream out = System.out;
    public static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    public int numCases;
    
    public void doCase(int caseNumber) throws Exception {
        String line = in.readLine();
        Scanner scan = new Scanner(line);
        int N = scan.nextInt();
        int L = scan.nextInt();
        
        line = in.readLine();
        scan = new Scanner(line);
        long[] outlets = new long[N];
        for (int i = 0; i < N; i++) {
            outlets[i] = scan.nextLong(2);
        }
        
        line = in.readLine();
        scan = new Scanner(line);
        long[] devices = new long[N];
        for (int i = 0; i < N; i++) {
            devices[i] = scan.nextLong(2);
        }
        
        Set<Long> work = null;
        for (int i = 0; i < N; i++) {
            Set<Long> thisWork = new HashSet<Long>();
            for (int j = 0; j < N; j++) {
                long xor = devices[i] ^ outlets[j];
                thisWork.add(xor);
            }
            if (work == null) work = thisWork;
            else work.retainAll(thisWork);
            if (work.isEmpty()) break;
        }
        
        if (work.isEmpty()) {
            System.out.println("NOT POSSIBLE");
            return;
        }
        
        int least = Integer.MAX_VALUE;
        for (long xor : work) {
            int num = countBits(xor);
            if (num < least) least = num;
        }
        System.out.println(least);
    }

    int countBits(long xor) {
        return BigInteger.valueOf(xor).bitCount();
    }
    
    public void run() throws Exception {
        numCases = Integer.parseInt(in.readLine().trim());
        for (int i = 1; i <= numCases; i++) {
            out.print("Case #" + i + ": ");
            doCase(i);
        }
    }
    
    public static void main(String[] args) throws Exception {
        new ChargingChaos().run();
    }

}
