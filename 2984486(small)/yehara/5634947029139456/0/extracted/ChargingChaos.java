package gcj2014.r1a;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class ChargingChaos {
    
    static PrintWriter out;

    public static void main(String[] args) throws IOException {
        String name = "gcj2014/r1a/A-small";
        Scanner s = new Scanner(new File(name + ".in"));
        int count = s.nextInt();
        out = new PrintWriter(new BufferedWriter(new FileWriter(name + ".out")));
        // out = new PrintWriter(System.out);
        for (int i = 1; i <= count; i++) {
            out.print("Case #" + i + ": ");
            int n = s.nextInt();
            int l = s.nextInt();
            long[] flow = new long[n];
            long[] device = new long[n];
            for(int j=0; j<n; j++) {
                flow[j] = Long.parseLong(new StringBuilder(s.next()).reverse().toString(), 2);
            }
            for(int j=0; j<n; j++) {
                device[j] = Long.parseLong(new StringBuilder(s.next()).reverse().toString(), 2);
            }
            int res = solve(n, l, flow, device);
            if(res == Integer.MAX_VALUE) {
                out.print("NOT POSSIBLE");
            } else {
                out.print(res);
            }
            out.println();          
        }
        out.close();
    }

    static int solve(int n, int l, long[] flow, long[] device) {
        int min = Integer.MAX_VALUE;
        OUTER: for(long i=0; i<(1L<<l); i++) {
            Set<Long> set = new HashSet<Long>();
            for(long d : device) {
                set.add(d);
            }
            for(int j=0; j<n; j++) {
                long a = flow[j] ^ i;
                if(set.contains(a)) {
                    set.remove(a);
                } else {
                    continue OUTER;
                }
            }
            min = Math.min(min, Long.bitCount(i));
        }
        return min;
    }

}
