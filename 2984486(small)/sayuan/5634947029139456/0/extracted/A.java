import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.util.*;
import java.util.regex.*;
import static java.lang.Math.*;
import static java.lang.System.*;
public class A {

    void solve(int caseNum) {
        int n = in.nextInt();
        int l = in.nextInt();
        long[] outlets = new long[n];
        long[] devices = new long[n];
        for (int i=0; i<n; i++) outlets[i] = Long.parseLong(in.next(), 2);
        for (int i=0; i<n; i++) devices[i] = Long.parseLong(in.next(), 2);

        int ans = 1<<30;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                long mask = outlets[i]^devices[j];

                Map<Long, Integer> o = new HashMap();
                for (int k=0; k<n; k++) {
                    long key = outlets[k]^mask;
                    if (o.containsKey(key)) o.put(key, o.get(key)+1);
                    else o.put(key, 1);
                }

                Map<Long, Integer> d = new HashMap();
                for (int k=0; k<n; k++) {
                    long key = devices[k];
                    if (d.containsKey(key)) d.put(key, d.get(key)+1);
                    else d.put(key, 1);
                }

                if (o.equals(d)) {
                    ans = min(ans, Long.bitCount(mask));
                }
            }
        }
        if (ans==(1<<30)) out.println("NOT POSSIBLE");
        else out.println(ans);
    }

    // {{{
    Scanner in = new Scanner(System.in);
    public A() throws Exception {
        int caseCount = in.nextInt();
        for (int caseNum=1; caseNum<=caseCount; caseNum++) {
            out.printf("Case #%d: ", caseNum);
            solve(caseNum);
        }
    }
    public static void main(String[] args) throws Exception {
        new A();
    }
    public static void debug(Object... arr) {
        System.err.println(Arrays.deepToString(arr));
    }
    // }}}
}
