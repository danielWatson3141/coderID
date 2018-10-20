
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class B1 {

    private BufferedReader in;
    private StringTokenizer st;
    private PrintWriter out;

    ArrayList<Integer>[] tree;
    int[] c;
    boolean[] vis;
    int[] sol;

    int count(int i) {
        vis[i] = true;
        int ans = 1;
        for (int j : tree[i]) {
            if (!vis[j])
                ans += count(j);
        }
        return c[i] = ans;
    }

    int solve(int i) {
        vis[i] = true;
        int max1 = 0;
        int max2 = 0;
        int c = 0;
        for (int j = 0; j < tree[i].size(); j++) {
            if (vis[tree[i].get(j)]) {
                continue;
            }
            c++;
            int a = solve(tree[i].get(j));
            if (a > max1) {
                max2 = max1;
                max1 = a;
            } else if (a > max2) {
                max2 = a;
            }
        }
        if (c < 2) {
            return 1;
        }
        return 1 + max1 + max2;
    }

    void solve() throws IOException {

        int t = nextInt();
        int kase = 0;
        while (t-- > 0) {
            kase++;
            out.print("Case #" + kase + ": ");
            int n = nextInt();
            tree = new ArrayList[n + 1];
            c = new int[n + 1];
            for (int i = 1; i <= n; i++) {
                tree[i] = new ArrayList<Integer>();
            }
            for (int i = 0; i < n - 1; i++) {
                int a = nextInt();
                int b = nextInt();
                tree[a].add(b);
                tree[b].add(a);
            }
            int ans = 0;
            for (int i = 1; i <= n; i++) {
                vis = new boolean[n + 1];
                ans = Math.max(ans, solve(i));
            }
            out.println(n - ans);
        }
    }

    B1() throws IOException {
        in = new BufferedReader(new FileReader("input.txt"));
        out = new PrintWriter(new FileWriter("out.txt"));
        eat("");
        solve();
        out.close();
    }

    private void eat(String str) {
        st = new StringTokenizer(str);
    }

    String next() throws IOException {
        while (!st.hasMoreTokens()) {
            String line = in.readLine();
            if (line == null) {
                return null;
            }
            eat(line);
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    public static void main(String[] args) throws IOException {
        new B1();
    }

    int gcd(int a, int b) {
        if (b > a)
            return gcd(b, a);
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

}
