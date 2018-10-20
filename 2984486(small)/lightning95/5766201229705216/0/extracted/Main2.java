import java.io.*;
import java.util.*;

public class Main2 {
    boolean eof;
    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;

    public static void main(String[] args) throws IOException {
        new Main2().run();
    }

    public String nextToken() {
        while (st == null || !st.hasMoreTokens()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (Exception e) {
                eof = true;
                return "-1";
            }
        }
        return st.nextToken();
    }

    void run() throws IOException {
        InputStream input = System.in;
        PrintStream output = System.out;
        String name = "name";
        try {
            File f = new File(name + ".in");
            if (f.exists() && f.canRead()) {
                input = new FileInputStream(f);
                output = new PrintStream(name + ".out");
            }
        } catch (Throwable e) {
            e.printStackTrace();
        }
        br = new BufferedReader(new InputStreamReader(input));
        out = new PrintWriter(output);
        solve();
        br.close();
        out.close();
    }

    public int nextInt() {
        return Integer.parseInt(nextToken());
    }

    //ArrayList<Integer> [] edges;

    boolean[] us;

    boolean isBin(int[][] edges, int root) {
        int cnt = 0;
        us[root] = true;
        for (int i = 0; i < edges.length; ++i){
            cnt += edges[root][i];
        }
        if (cnt % 2 != 0){
            return false;
        }
        for (int i = 0; i < edges.length; ++i){
            if (edges[root][i] == 1){
                edges[i][root] = 0;
                boolean res = isBin(edges, i);
                edges[i][root] = 1;
                if (!res){
                    return false;
                }
            }
        }
        return true;
    }

    void solve() {
        for (int test_id = 1, test_num = nextInt(); test_id <= test_num; ++test_id) {
            out.print("Case #" + test_id + ": ");
            int n = nextInt();
            //edges = new ArrayList[n];
            int[][] edges = new int[n][n];
            for (int i = 1; i < n; ++i) {
                int x = nextInt() - 1, y = nextInt() - 1;
                edges[x][y] = 1;
                edges[y][x] = 1;
            }
            int ans = n;
            for (int i = 0; i < 1 << n; ++i) {
                String s = Integer.toString(i, 2);
                int[][] edges2 = new int[n][n];
                for (int j = 0; j < n; ++j){
                    for (int k = 0; k < n; ++k){
                        edges2[j][k] = edges[j][k];
                    }
                }
                int cur = n;
                for (int j = 0; j < s.length(); ++j) {
                    if (s.charAt(s.length() - j - 1) == '1') {
                        --cur;
                        for (int k = 0; k < n; ++k) {
                            edges2[j][k] = 0;
                            edges2[k][j] = 0;
                        }
                    }
                }
                for (int j = 0; j < n; ++j) {
                    us = new boolean[n];
                    if (isBin(edges2, j)) {
                        int cnt = 0;
                        for (int k = 0; k < n; ++k){
                            if (us[k]){
                                ++cnt;
                            }
                        }
                        if (cnt != cur){
                            continue;
                        }
                        ans = Math.min(ans, n - cur);
                        break;
                    }
                }
            }
            out.println(ans);
        }
    }
}