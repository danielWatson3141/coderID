package gcj2014.r1a;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class FullyBinaryTree {

    static PrintWriter out;

    public static void main(String[] args) throws IOException {
        String name = "gcj2014/r1a/B-small";
        Scanner s = new Scanner(new File(name + ".in"));
        int count = s.nextInt();
        out = new PrintWriter(new BufferedWriter(new FileWriter(name + ".out")));
        // out = new PrintWriter(System.out);
        for (int i = 1; i <= count; i++) {
            out.print("Case #" + i + ": ");
            int n = s.nextInt();
            boolean[][] b = new boolean[n][n];
            for (int j = 0; j < n - 1; j++) {
                int v1 = s.nextInt() - 1;
                int v2 = s.nextInt() - 1;
                b[v1][v2] = b[v2][v1] = true;
            }
            int res = solve(n, b);
            out.print(res);
            out.println();
        }
        out.close();
    }

    static int solve(int n, boolean[][] b) {
        int res = n;
        for (int i = 0; i < n; i++) {
        //    out.println("----- Root:" + i);
            Node root = new Node(i);
            dfs(root, n, b, new boolean[n]);
            res = Math.min(res, dfs2(root));
        }
        return res;
    }

    static int dfs(Node node, int n, boolean[][] b, boolean[] v) {
        int count = 1;
        v[node.id] = true;
        for (int i = 0; i < n; i++) {
            if (b[node.id][i] && !v[i]) {
                Node child = new Node(i);
                node.children.add(child);
                count += dfs(child, n, b, v);
            }
        }
        node.count = count;
        // out.println("dfs: id:" + node.id + " count:" + node.count);
        return count;
    }

    static int dfs2(Node node) {
        int c = node.children.size();
        int res = 0;
        if (c == 0) {
            res = 0;
        } else if (c == 1) {
            res = node.children.get(0).count;
        } else if (c == 2) {
            res = dfs2(node.children.get(0)) + dfs2(node.children.get(1));
        } else {
            int[] remain = new int[c];
            for (int i = 0; i < c; i++) {
                Node child = node.children.get(i);
                remain[i] = child.count - dfs2(child);
            }
            Arrays.sort(remain);
            res = node.count - (1 + remain[c - 1] + remain[c - 2]);
        }
        // out.println("nid:" + node.id + " dfs2:" + res);
        return res;
    }

    static class Node implements Comparable<Node> {
        public int count = 0;
        public int id;
        public ArrayList<Node> children = new ArrayList<Node>();

        public Node(int id) {
            this.id = id;
        }

        @Override
        public int compareTo(Node o) {
            return this.count = o.count;
        }

        public String toString() {
            StringBuilder sb = new StringBuilder();
            sb.append(" id:" + id);
            sb.append(" count:" + count);
            sb.append(" children:");
            for (Node n : children) {
                sb.append(n.id + " ");
            }
            return sb.toString();
        }
    }

}
