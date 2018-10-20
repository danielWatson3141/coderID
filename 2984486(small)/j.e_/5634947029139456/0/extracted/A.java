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
            int[] st = new int[N];
            for(int i=0;i<N;i++) st[i] = parseInt(ss[i], 2);
            int[] en = new int[N];
            ss = br.readLine().trim().split("\\s+");
            for(int i=0;i<N;i++) en[i] = parseInt(ss[i], 2);
            Arrays.sort(en);
            
            int min = INF;
            for(int i=0;i<(1<<L);i++) {
                int[] nn = new int[N];
                for (int j=0;j<N;j++) {
                    nn[j] = st[j] ^ i;
                }
                Arrays.sort(nn);
                boolean ok = true;
                for(int j=0;j<N;j++) {
                    if (nn[j] != en[j]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    min = min(min, Integer.bitCount(i));
                }
            }

            out.println("Case #"+z+": " + (min == INF ? "NOT POSSIBLE" : min));
        }
    }

    static int INF = 1 << 30;
}