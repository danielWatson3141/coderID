import java.io.File;
import java.util.ArrayList;
import java.util.Formatter;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class B {
    private static final String ANS = "Case #%s: %s\n";

    public static void main(String[] args) throws Exception {
        try (Scanner in = new Scanner(new File("io/B/Bs.in.txt")); Formatter out = new Formatter("io/B/Bs.out.txt")) {
            int tests = in.nextInt();
            for (int i = 1; i <= tests; ++i) {
                new B().solve(i, in, out);
            }
        }
    }

    private void solve(int testNo, Scanner in, Formatter out) {
        int n = in.nextInt();
        @SuppressWarnings("unchecked")
        Set<Integer>[] nbs = new Set[n];
        for (int i = 1; i < n; i++) {
            int x = in.nextInt() - 1;
            int y = in.nextInt() - 1;
            add(nbs, x, y);
            add(nbs, y, x);
        }

        int min = Integer.MAX_VALUE;
        for (int r = 0; r < n; r++) {
            min = Math.min(min, cost(nbs, r));
        }
        out.format(ANS, testNo, min);
    }

    private int cost(Set<Integer>[] nbs, int root) {
        return cost(nbs, root, -1)[1];
    }

    private int[] cost(Set<Integer>[] nbs, int x, int parent) {
        List<int[]> kids = new ArrayList<>(nbs[x].size());

        for (int nb : nbs[x]) {
            if (nb != parent) {
                int[] c = cost(nbs, nb, x);
                kids.add(c);
            }
        }

        return new int[] { 1 + sum(kids, 0), kids.size() == 1 ? sum(kids, 0) : (removeMax(kids) + removeMax(kids) + sum(kids, 0)) };
    }

    private int removeMax(List<int[]> kids) {
        if (kids.isEmpty()) { return 0; }

        int max = -1;
        int ndx = 0;

        for (int i = 0; i < kids.size(); ++i) {
            int[] kid = kids.get(i);
            if (max < kid[0] - kid[1]) {
                max = kid[0] - kid[1];
                ndx = i;
            }
        }

        return kids.remove(ndx)[1];
    }

    private int sum(List<int[]> kids, int ndx) {
        int ret = 0;
        for (int[] kid : kids) {
            ret += kid[ndx];
        }
        return ret;
    }

    private void add(Set<Integer>[] nbs, int x, int y) {
        Set<Integer> set = nbs[x];
        if (null == set) {
            nbs[x] = set = new HashSet<Integer>();
        }
        set.add(y);
    }
}
