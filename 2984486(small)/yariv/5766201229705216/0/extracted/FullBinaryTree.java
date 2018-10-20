import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class FullBinaryTree {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(reader.readLine());
        for (int i=1; i<=T; i++) {
            int N = Integer.parseInt(reader.readLine());
            Map<Integer, Set<Integer>> edges = new HashMap<Integer, Set<Integer>>(N);
            for (int j=0; j<N; j++) {
                edges.put(j+1, new HashSet<Integer>());
            }
            for (int j=0; j<N-1; j++) {
                StringTokenizer tok = new StringTokenizer(reader.readLine());
                int X = Integer.parseInt(tok.nextToken());
                int Y = Integer.parseInt(tok.nextToken());
                edges.get(X).add(Y);
                edges.get(Y).add(X);
            }
            int min = N;
            for (int j=0; j<N; j++) {
                Pair p = maxRootedBinaryTreeSize(edges, j+1, null);
                if (min > p.left-p.right) {
                    min = p.left-p.right;
                }
            }

            System.out.printf("Case #%d: %d\n", i, min);
        }
    }

    public static Pair maxRootedBinaryTreeSize(Map<Integer, Set<Integer>> edges, int root, Integer ignoreEdge) {
        Set<Pair> subAnswers = new HashSet<Pair>();
        for (Integer node : edges.get(root)) {
            if (!node.equals(ignoreEdge)) {
                subAnswers.add(maxRootedBinaryTreeSize(edges, node, root));
            }
        }
        if (subAnswers.size() == 0) return new Pair(1,1);
        if (subAnswers.size() == 1) return new Pair(1+subAnswers.iterator().next().left,1);
        int total = 1;
        int max = 0;
        int second = 0;
        for (Pair sub : subAnswers) {
            total += sub.left;
            if (sub.right > max) {
                second = max;
                max = sub.right;
            }
            else if (sub.right > second) {
                second = sub.right;
            }
        }
        return new Pair(total, max+second+1);
    }

    public static class Pair {
        public final int left;
        public final int right;

        public Pair(int left, int right) {
            this.left = left;
            this.right = right;
        }
    }
}

