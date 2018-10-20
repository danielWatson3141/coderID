package round1a;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class Problem2 {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("src/round1a/B-small-attempt1.in"));
        PrintWriter pw = new PrintWriter(new File("src/round1a/out.txt"));
        int T = sc.nextInt();
        for (int tc = 0; tc < T; tc++) {
            String out = "";

            int N = sc.nextInt();

            int[][] edges = new int[N - 1][2];
            int[] numedges = new int[N + 1];
            for (int i = 0; i < N - 1; i++) {
                edges[i][0] = sc.nextInt();
                edges[i][1] = sc.nextInt();
                numedges[edges[i][0]]++;
                numedges[edges[i][1]]++;

            }

            int minPrunes = N;
            for (int root = 1; root <= N; root++) {
                if (numedges[root] > 0 && numedges[root] < 3) {
                    // System.out.println("root "+root);
                    Node n = new Node();
                    n.num = root;
                    boolean[] used = new boolean[N + 1];
                    used[root] = true;
                    fillInTree(n, used, edges, N);
                    //System.out.println(countNodes(n));
                    int numPrunes = pruneTree(n);
                    if (numPrunes < minPrunes) {
                        //System.out.println(root + " " + numPrunes);
                        minPrunes = numPrunes;
                    }
                }
            }
            out += minPrunes;

            System.out.println("Case #" + (tc + 1) + ": " + out);
            pw.println("Case #" + (tc + 1) + ": " + out);
        }
        pw.close();
    }

    public static int pruneTree(Node n) {
        if (n.children.size() == 0) {
            return 0;
        }
        if (n.children.size() == 1) {
            return countNodes(n.children.get(0));
        }
        int prune = 0;
        while (n.children.size() > 2) {
            Node p = n.children.get(0);
            for (int i = 1; i < n.children.size(); i++) {
                if (countNodes(n.children.get(i)) < countNodes(p)) {
                    p = n.children.get(i);
                }
            }
            prune += countNodes(p);
            n.children.remove(p);
        }
        for (Node c : n.children) {
            prune += pruneTree(c);
        }
        return prune;
    }

    public static int countNodes(Node n) {
        if (n == null) {
            return 0;
        }
        int count = 1;
        for (Node c : n.children) {
            count += countNodes(c);
        }
        return count;
    }

    public static void fillInTree(Node n, boolean[] used, int[][] edges, int N) {
       // System.out.println("fillin"); // first get the children
        Node c1 = null, c2 = null;
        // first child
        do {
            for (int i = 0; i < edges.length; i++) {
                c1 = null;
                if (edges[i][0] == n.num && !used[edges[i][1]]) {
                    c1 = new Node();
                    c1.num = edges[i][1];
                    used[c1.num] = true;
                    break;
                } else if (edges[i][1] == n.num && !used[edges[i][0]]) {
                    c1 = new Node();
                    c1.num = edges[i][0];
                    used[c1.num] = true;
                    break;
                }
            }
            if (c1 != null) {
                n.children.add(c1);
            }
           // System.out.println(c1);
        } while (c1 != null);
        for (Node c: n.children) {
            fillInTree(c, used, edges, N);
        }
    }
}

class Node {

    int num;
    ArrayList<Node> children = new ArrayList<Node>();
}
