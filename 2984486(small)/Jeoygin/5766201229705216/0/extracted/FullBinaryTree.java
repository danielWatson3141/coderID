package gcj14.round1a;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class FullBinaryTree {
    void solve(Scanner scan) {
        int n = scan.nextInt();
        boolean[][] adj = new boolean[n][n];

        for (int i = 0; i < n - 1; i++) {
            int a = scan.nextInt();
            int b = scan.nextInt();
            a--;
            b--;
            adj[a][b] = adj[b][a] = true;
        }

        int ans = 10000;
        for (int i = 0; i < n; i++) {
            boolean[] used = new boolean[n];
            int cnt = dp(adj, used, i, n);
            if (cnt < ans) {
                ans = cnt;
            }
        }
        System.out.println(ans);
    }

    int dp(boolean[][] adj, boolean[] used, int i, int n) {
        used[i] = true;
        List<Integer> children = new ArrayList<Integer>();

        int ans = 0;

        for (int j = 0; j < n; j++) {
            if (adj[i][j] && !used[j]) {
                children.add(j);
            }
        }

        if (children.size() == 1) {
            ans += getNodes(adj, used.clone(), children.get(0), n);
        } else if (children.size() == 2) {
            ans += dp(adj, used.clone(), children.get(0), n);
            ans += dp(adj, used.clone(), children.get(1), n);
        } else if (children.size() > 2) {
            int[] val1 = new int[children.size()];
            int[] val2 = new int[children.size()];
            int val = 0;

            for (int j = 0; j < children.size(); j++) {
                val1[j] = dp(adj, used.clone(), children.get(j), n);
                val2[j] = getNodes(adj, used.clone(), children.get(j), n);
                val += val2[j];
            }


            int min = 100000;
            for (int j = 0; j < children.size(); j++) {
                for (int k = j + 1; k < children.size(); k++) {
                    min = Math.min(min, val - val2[j] - val2[k] + val1[j] + val1[k]);
                }
            }
            ans += min;
        }

        return ans;
    }

    int getNodes(boolean[][] adj, boolean[] used, int i, int n) {
        int ans = 1;
        used[i] = true;
        for (int j = 0; j < n; j++) {
            if (adj[i][j] && !used[j]) {
                ans += getNodes(adj, used, j, n);
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int t = scan.nextInt();
        for (int i = 1; i <= t; i++) {
            System.out.printf("Case #%d: ", i);
            new FullBinaryTree().solve(scan);
        }
    }
}
