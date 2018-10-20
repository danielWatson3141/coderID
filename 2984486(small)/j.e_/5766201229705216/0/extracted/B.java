import java.util.*;
import java.io.*;
import java.math.*;
import static java.lang.Integer.*;
import static java.lang.System.*;
import static java.lang.Math.*;

public class B {
    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(in));

        int T = parseInt(br.readLine());
        for(int z=1;z<=T;z++) {
            int N = parseInt(br.readLine());

            LL[] arr = new LL[N];
            for(int i=0;i<N;i++) arr[i] = new LL();
            for (int i=1;i<N;i++) {
                String[] ss = br.readLine().trim().split("\\s+");
                int a = parseInt(ss[0])-1;
                int b = parseInt(ss[1])-1;

                arr[a].add(b);
                arr[b].add(a);
            }

            int min = 11111;
            for(int i=0;i<N;i++) {
                min = min(min, go(arr, i));
            }
            out.println("Case #"+z+": "+min);
        }
        
    }

    static Pair go(LL[] arr, int x, int p) {
        int nc = arr[x].size() - (p == -1 ? 0 : 1);
        if (nc == 0)
            return new Pair(0, 1);

        int k = 0;
        Pair[] narr = new Pair[nc];
        for (int ch : arr[x]) {
            if (ch == p) continue;
            narr[k++] = go(arr, ch, x);
        }
        if (nc == 1) {
            return new Pair(narr[0].v, narr[0].v + 1);
        //} else if (nc == 2) {
         //   int a = narr[0].v + narr[1].v;
          //  int b = narr[0].u + narr[1].u;
           // return new Pair(min(a, b), a + 1);
        } else {
            int a = 0;
            for(int i=0;i<nc;i++) a += narr[i].v;
            int tot = a;

            for(int i=0;i<nc;i++) {
                for(int j=i+1;j<nc;j++) {
                    int b = narr[i].u + narr[j].u + (tot - narr[i].v - narr[j].v);
                    if (b < a) {
                        a = b;
                    }
                }
            }
            return new Pair(a, tot + 1);
        }
    }

    static int go(LL[] arr, int root) {
        Pair h = go(arr, root, -1);
        //out.println(h);
        return h.u;
    }

    static class LL extends LinkedList<Integer> {}
    static class Pair {
        int u, v;

        Pair(int a, int b) {
            u = a;
            v = b;
        }

        public String toString() {
            return "(" + u + "," + v + ")";
        }
    }
}