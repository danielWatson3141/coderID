/**
 * Created by zwh on 4/25/14.
 */
import java.io.*;
import java.util.*;
public class A {
    static Scanner scan = new Scanner (System.in);
    static PrintStream out = System.out;

    private static void test () {
        int N = scan.nextInt(), L = scan.nextInt();

        long[] A = new long[N], B = new long[N];
        for (int i = 0; i < N; ++i) {
            String s = scan.next();
            for (char c : s.toCharArray()) {
                long d = c == '1' ? 1 : 0;
                A[i] = A[i] * 2 + d;
            }
        }

        for (int i = 0; i < N; ++i) {
            String s = scan.next();
            for (char c : s.toCharArray()) {
                long d = c == '1' ? 1 : 0;
                B[i] = B[i] * 2 + d;
            }
        }

        long ans = Long.MAX_VALUE;
        for (int i = 0; i < N; ++i) {
            long tmp = A[0] ^ B[i];

            Set<Long> result1 = new HashSet<Long>();
            Set<Long> result2 = new HashSet<Long>();
            for (long a : A)
                result1.add(a ^ tmp);
            for (long b : B)
                result2.add (b);
            result1.removeAll(result2);
            if (result1.isEmpty()) {
                long t = 0;
                while (tmp != 0) {
                    ++t;
                    tmp &= tmp-1;
                }
                ans = Math.min (ans, t);
            }
        }

        if (ans == Long.MAX_VALUE)
            out.println ("NOT POSSIBLE");
        else
            out.println (ans);

    }

    public static void main (String[] args) {
        int T = scan.nextInt();

        for (int i = 1; i <= T; ++i) {
            out.print ("Case #" + i + ": ");
            test ();
        }
    }
}
