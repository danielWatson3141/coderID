package round1a;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.util.ArrayList;
import java.util.List;

public class B {
    public static void main(String[] args) throws FileNotFoundException {
        Kattio io;

//        io = new Kattio(System.in, System.out);
//        io = new Kattio(new FileInputStream("round1a/B-sample.in"), System.out);
//        io = new Kattio(new FileInputStream("round1a/B-small-0.in"), new FileOutputStream("round1a/B-small-0.out"));
        io = new Kattio(new FileInputStream("round1a/B-large.in"), new FileOutputStream("round1a/B-large.out"));

        int cases = io.getInt();
        for (int i = 1; i <= cases; i++) {
            io.print("Case #" + i + ": ");
            new B().solve(io);
        }
        io.close();
    }

    private List<List<Integer>> edges;
    private int subTreeSizeMemo[];
    private int findMinMemo[];

    private int subTreeSize(int root, int parent) {
        if (subTreeSizeMemo[root] > 0) return subTreeSizeMemo[root]-1;
        int count = 1;
        for (Integer x : edges.get(root)) {
            if (x != parent) count += subTreeSize(x, root);
        }
        subTreeSizeMemo[root] = count + 1;
        return count;
    }

    private int findMin(int root, int parent) {
        if (findMinMemo[root] > 0) return findMinMemo[root]-1;
        int best1 = -10000, best2 = -10000;
        // Either delete all children, or all children except 2 which we balance out
        int deleteAll = 0;
        for (Integer x : edges.get(root)) {
            if (x != parent) {
                int subSize = subTreeSize(x, root);
                deleteAll += subSize;
                int dif = subSize - findMin(x, root);
                if (dif > best1) { best2= best1; best1=dif; }
                else if (dif > best2) { best2 = dif; }
            }
        }
        int best = Math.min(deleteAll, deleteAll - best1 - best2);
        findMinMemo[root] = best + 1;
        return best;
    }

    private void solve(Kattio io) {
        int N = io.getInt();

        edges = new ArrayList<>(N);
        for (int i = 0; i < N; i++) {
            edges.add(new ArrayList<Integer>());
        }

        for (int i = 0; i < N-1; i++) {
            int x = io.getInt() - 1, y = io.getInt() - 1;
            edges.get(x).add(y);
            edges.get(y).add(x);
        }

        int best = Integer.MAX_VALUE;
        for (int i = 0; i < N; i++) {
            subTreeSizeMemo = new int[N];
            findMinMemo = new int[N];
            best = Math.min(best, findMin(i, -1));
        }
        io.println(best);
    }
}
