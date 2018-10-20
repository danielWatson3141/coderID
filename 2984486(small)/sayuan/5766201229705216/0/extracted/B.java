import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.util.*;
import java.util.regex.*;
import static java.lang.Math.*;
import static java.lang.System.*;
public class B {

    int r(int p, int c) {
        int ret = 1;
        if (degree[c]-(p==0?0:1)>=2) {
            List<Integer> list = new ArrayList<Integer>();
            for (int t: adj[c]) {
                if (t==p) continue;
                list.add(r(c, t));
            }
            Collections.sort(list);
            Collections.reverse(list);
            ret += list.get(0);
            ret += list.get(1);
        }
        return ret;
    }

    int n;
    int[] degree;
    List<Integer>[] adj;
    void solve(int caseNum) {
        n = in.nextInt();
        degree = new int[n+1];
        adj = new List[n+1];
        for (int i=1; i<=n; i++) adj[i] = new ArrayList();
        for (int i=0; i<n-1; i++) {
            int a = in.nextInt();
            int b = in.nextInt();
            degree[a]++;
            degree[b]++;
            adj[a].add(b);
            adj[b].add(a);
        }
        int ans = n-1;
        for (int i=1; i<=n; i++) {
            int remain = r(0, i);
            ans = min(ans, n-remain);
        }
        out.println(ans);
    }

    // {{{
    Scanner in = new Scanner(System.in);
    public B() throws Exception {
        int caseCount = in.nextInt();
        for (int caseNum=1; caseNum<=caseCount; caseNum++) {
            out.printf("Case #%d: ", caseNum);
            solve(caseNum);
        }
    }
    public static void main(String[] args) throws Exception {
        new B();
    }
    public static void debug(Object... arr) {
        System.err.println(Arrays.deepToString(arr));
    }
    // }}}
}
