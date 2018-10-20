//package denxx;

import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.*;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.File;
import java.io.Writer;
import java.math.BigInteger;
import java.io.FilenameFilter;
import java.io.InputStream;

public class Main {

    private static int dfs(ArrayList<ArrayList<Integer>> g, int[] dp, int root, boolean[] visited) {
        dp[root] = 0;
        int sum = 0;
        int sums = 0;
        int nonz = 0;
        int child = 0;
        ArrayList<Integer> ress = new ArrayList<Integer>();
        ArrayList<Integer> sizes = new ArrayList<Integer>();
        for (int i = 0; i < g.get(root).size(); ++i) {
            int v = g.get(root).get(i);
            if (!visited[v]) {
                ++child;
                visited[v] = true;
                sizes.add(dfs(g, dp, v, visited));
                sums += sizes.get(sizes.size() - 1);
                if (sizes.get(sizes.size() - 1) > 0)
                    ++nonz;
                sum += dp[v];
                ress.add(dp[v]);
            }
        }
        if (child == 0) {
            dp[root] = 0;
            return 1;
        } else if (nonz == 1) {
            dp[root] = sum + sums;
            return 1;
        } else if (nonz > 2) {
            Collections.sort(sizes);
            dp[root] = sum;
            for (int i = 0; i < sizes.size() - 2; ++i) {
                dp[root] += sizes.get(i);
            }
            return 1 + sizes.get(sizes.size() - 1) + sizes.get(sizes.size() - 2);
        } else {
            dp[root] = sum;
            return sums + 1;
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int t = 1; t <= T; ++t) {
            int n = in.nextInt();
            ArrayList<ArrayList<Integer>> g = new ArrayList<ArrayList<Integer>>();
            for (int i = 0; i < n; ++i) {
                g.add(new ArrayList<Integer>());
            }
            for (int i = 0; i < n - 1; ++i) {
                int a = in.nextInt() - 1;
                int b = in.nextInt() - 1;
                g.get(a).add(b);
                g.get(b).add(a);
            }

            int res = n - 1;
            for (int root = 0; root < n; ++root) {
                int[] dp = new int[n];
                boolean[] visited = new boolean[n];
                visited[root] = true;
                dfs(g, dp, root, visited);
                res = Math.min(res, dp[root]);
            }

            System.out.println("Case #" + t + ": " + res);
        }
    }
}