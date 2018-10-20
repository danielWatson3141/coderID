import java.io.*;
import java.util.*;
import java.math.*;
import static java.lang.Integer.*;
import static java.lang.System.*;
import static java.lang.Math.*;


public class A {
    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(in));

        int T = parseInt(br.readLine());
        for(int z=1;z<=T;z++) {
            String[] ss = br.readLine().trim().split("\\s+");
            int N = parseInt(ss[0]);
            int L = parseInt(ss[1]);

            ss = br.readLine().trim().split("\\s+");
            long[] st = new long[N];
            for(int i=0;i<N;i++) st[i] = Long.parseLong(ss[i], 2);
            long[] en = new long[N];
            ss = br.readLine().trim().split("\\s+");
            for(int i=0;i<N;i++) en[i] = Long.parseLong(ss[i], 2);
            Arrays.sort(st);
            Arrays.sort(en);
            
            long ans = go(N, L, st, en, L-1);
            out.println("Case #"+z+": " + (ans == INF ? "NOT POSSIBLE" : ans));
        }
    }

    static long go(int N, int L, long[] st, long[] en, int k) {
        //out.println(N+" "+L+" "+k+" "+Arrays.toString(st) + " "+ Arrays.toString(en));
        if (k == -1) {
            for (int i=0;i<N;i++) {
                if (st[i] != en[i]) return INF;
            }
            return 0;
        }

        boolean ok = true;
        for (int i=0;i<N;i++) {
            long a = st[i] >> k;
            long b = en[i] >> k;
            if (a != b) {
                ok = false;
            }
        }
        long ans = INF;
        if (ok) {
            ans = min(ans, go(N, L, st, en, k-1));
        }
        long[] nn = new long[N];
        for(int i=0;i<N;i++) {
            nn[i] = st[i] ^ (1 << k);
        }
        Arrays.sort(nn);
        for(int i=0;i<N;i++) {
            long a = nn[i] >> k;
            long b = en[i] >> k;
            if (a != b) return min(ans, INF);
        }
        return min(ans, go(N, L, nn, en, k-1) + 1);
    }

    static long INF = 1L << 30;
}