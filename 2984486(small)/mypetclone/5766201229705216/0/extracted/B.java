import java.io.*;
import java.util.*;

/**
 * Created by jwolfe on 4/25/14.
 */
public class B {
    static int[] parents;
    static List<Integer>[] neighbors;

    public static void main(String[] args) throws FileNotFoundException {
        Scanner s = new Scanner(new File("B.in"));
//        PrintStream out = System.out;
        PrintStream out = new PrintStream(new FileOutputStream("B.out"), true);
        final int t = s.nextInt();
        for (int i = 0; i < t; i++) {
            final int n = s.nextInt();
            parents = new int[n];
            //noinspection unchecked
            neighbors = new List[n];
            int[] neighborCount = new int[n];
            for (int j = 0; j < n; j++) {
                neighbors[j] = new ArrayList<>();
            }
            for (int j = 0; j < n - 1; j++) {
                int x = s.nextInt() - 1;
                int y = s.nextInt() - 1;
                neighbors[x].add(y);
                neighborCount[x]++;
                neighbors[y].add(x);
                neighborCount[y]++;
            }
            int best = n - 1;
            for (int rootChoice = 0; rootChoice < n; rootChoice++) {
                Arrays.fill(parents, -1);
                findParents(rootChoice);
                final int sz = treeSize(rootChoice);
                final int deleted = n - sz;
                best = Math.min(best, deleted);
            }
            out.println("Case #" + (i + 1) + ": " + best);
        }
        out.close();
    }

    private static void findParents(int rootChoice) {
        Queue<Integer> toProcess = new ArrayDeque<>();
        toProcess.add(rootChoice);
        parents[rootChoice] = -2;
        while (!toProcess.isEmpty()) {
            int parent = toProcess.poll();
            for (int neighbor : neighbors[parent]) {
                if (parents[neighbor] == -1) {
                    parents[neighbor] = parent;
                    toProcess.add(neighbor);
                }
            }
        }
    }

    public static int treeSize(int start) {
        final int parent = parents[start];
        PriorityQueue<Integer> childrenSizes = new PriorityQueue<>();
        for (int child : neighbors[start]) {
            if (child == parent) continue;
            int childTreeSize = treeSize(child);
            if (childTreeSize != 0) {
                childrenSizes.add(childTreeSize);
                if (childrenSizes.size() > 2) {
                    childrenSizes.poll();
                }
            }
        }
        if (childrenSizes.size() < 2) {
            return 1;
        }
//        System.out.println("childrenSizes = " + childrenSizes);
        // Safe, amirite?
        return 1 + childrenSizes.poll() + childrenSizes.poll();
    }
}
