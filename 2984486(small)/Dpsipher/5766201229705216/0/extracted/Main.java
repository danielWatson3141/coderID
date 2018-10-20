import java.io.File;
import java.io.FileInputStream;
import java.io.InputStream;
import java.util.*;

/**
 * Codejam 2014
 * User: maurya
 * Date: 26/4/14
 * Time: 7:45 AM
 */
public class Main {
    private static List<Integer> G[];
    private static int count(int root, boolean vis[]) {
        if(G[root].size() == 1) {
            return 1;
        }
        int res = 0;
        vis[root] = true;
        for (int i = 0;i < G[root].size(); i++) {
            if (!vis[G[root].get(i)]) {
                res += count(G[root].get(i), vis);
            }
        }
        return res + 1;

    }
    private static int solve(int root, boolean vis[]) {
        if(G[root].size() == 1) {
            return 0;
        }
        int res = 0;
        vis[root] = true;

        if (G[root].size() == 2) {

            for (int i = 0;i < G[root].size(); i++)
                if (!vis[G[root].get(i)]) {
                    return count(G[root].get(i),vis);
                }
        }

        for (int i = 0;i < G[root].size(); i++) {
            if (!vis[G[root].get(i)]) {
                int v = solve(G[root].get(i), vis);
                res += v;
            }
        }
        return res;

    }
    public static void main(String args[]) throws Exception {
        InputStream is = System.in;
        if (args != null && args.length > 0 && args[0] != null) {
            is = new FileInputStream(new File(args[0]));
        }
        Scanner in = new Scanner(is);
        int _tests = in.nextInt();
        for (int _t = 1; _t <= _tests; _t++) {
            System.out.print("Case #" + _t + ": ");
            int n = in.nextInt();
            G = new List[n+1];
            for (int i = 0; i <= n; i++) {
                G[i] = new ArrayList<Integer>();
            }
            for (int i= 0; i < n - 1; i++) {
                int u= in.nextInt();
                int v = in.nextInt();
                G[u].add(v);
                G[v].add(u);
            }
            int res = Integer.MAX_VALUE;
            for (int i = 1; i <= n; i++) {
                boolean vis[] = new boolean[n+1];
                vis[i] = true;
                int v = 0;
                for (int j = 0; j < G[i].size(); j++) {
                    v += solve(G[i].get(j), vis);
                }
                res = Math.min(res, v);

            }
            if (res == Integer.MAX_VALUE) {
                System.out.println(Math.min(n-1,1));
            }
            else {
                System.out.println(res);
            }
        }

    }
}

