import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class ProblemB {
    final static String PROBLEM_NAME = "ProblemB";
    final static String WORK_DIR = "d:\\work\\idea_work\\CodeJam2014_R1A\\src\\";

    public void solve(Scanner sc, PrintWriter pw) {
        int result = Integer.MAX_VALUE;
        int N = sc.nextInt();

        Node[] tree = new Node[N+1];

        for (int idx = 0; idx <= N; idx++) {
            tree[idx] = new Node();
            tree[idx].idx = idx;
        }

        for (int i = 0; i < N-1; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            tree[x].children.add(y);
            tree[y].children.add(x);
        }

        for (int i = 1; i <= N; i++) {
            result = Math.min(result, doIt(tree, tree[i], 0));
        }

        pw.println(result);
    }

    int doIt(Node[] tree, Node node, int parent) {
        int childCount = 0;
        for (int i = 0; i < node.children.size(); i++) {
            if (node.children.get(i) != parent) {
                childCount++;
            }
        }

        if (childCount == 0) {
            return 0;
        }

        if (childCount == 1) {
            for (int i = 0; i < node.children.size(); i++) {
                if (node.children.get(i) != parent) {
                    return countAllChilds(tree, tree[node.children.get(i)], node.idx); // remove one children with all subchildrens.
                }
            }
        }

        if (childCount == 2) {
            int result = 0;
            for (int i = 0; i < node.children.size(); i++) {
                if (node.children.get(i) != parent) {
                    result += doIt(tree, tree[node.children.get(i)], node.idx);
                }
            }
            return result;
        }

        // Else, remove some of children (more than 1).
        int []childrenResults = new int[node.children.size()];
        int []removeCosts = new int[node.children.size()];
        for (int i = 0; i < childrenResults.length; i++) {
            childrenResults[i] = Integer.MAX_VALUE;
            removeCosts[i] = Integer.MAX_VALUE;
        }

        for (int i = 0; i < node.children.size(); i++) {
            if (node.children.get(i) != parent) {
                childrenResults[i] = doIt(tree, tree[node.children.get(i)], node.idx);
                removeCosts[i] = countAllChilds(tree, tree[node.children.get(i)], node.idx);
            }
        }

        int result = Integer.MAX_VALUE;
        for (int i = 0; i < childrenResults.length; i++) {
            for (int j = i+1; j < childrenResults.length; j++) {
                if (i != j && node.children.get(i) != parent && node.children.get(j) != parent) {
                    int removeCostsSum = 0;
                    for (int k = 0; k < removeCosts.length; k++) {
                        if (k != i && k != j && node.children.get(k) != parent) {
                            removeCostsSum += removeCosts[k];
                        }
                    }

                    result = Math.min(result, removeCostsSum+childrenResults[i]+childrenResults[j]);
                }

            }
        }

        return result;
    }

    private int countAllChilds(Node[] tree, Node node, int parent) {
        int result = 1; // node itself.

        for (int i = 0; i < node.children.size(); i++) {
            if (node.children.get(i) != parent) {
                result += countAllChilds(tree, tree[node.children.get(i)], node.idx);
            }
        }

        return result;
    }

    private static class Node {
        int idx;
        List<Integer> children = new ArrayList<Integer>();
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileReader(WORK_DIR + PROBLEM_NAME + ".in"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + PROBLEM_NAME + ".out"));

        int N = sc.nextInt();

        for (int testNum=1; testNum <= N; testNum++) {
            System.out.println("Processing test case: " + testNum);
            pw.print("Case #" + (testNum) + ": ");
            new ProblemB().solve(sc, pw);
        }

        pw.flush();
        pw.close();
        sc.close();
    }
}
