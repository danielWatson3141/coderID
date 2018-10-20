import java.util.*;

public class TaskB {
    private static List<List<Integer>> g;
    private static boolean[] used;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int tests = scanner.nextInt();
        for (int test = 1; test <= tests; test++) {
            int n = scanner.nextInt();

            g = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                g.add(new ArrayList<Integer>());
            }
            used = new boolean[n];

            for (int i = 0; i < n - 1; i++) {
                int a = scanner.nextInt() - 1;
                int b = scanner.nextInt() - 1;
                g.get(a).add(b);
                g.get(b).add(a);
            }

            int result = Integer.MAX_VALUE;

            for (int i = 0; i < n; i++) {
                Arrays.fill(used, false);
                result = Math.min(result, dfs(i).keep);
            }

            System.out.println("Case #" + test + ": " + result);
        }

        scanner.close();
    }

    private static Pair dfs(int v) {
        used[v] = true;

        List<Pair> children = new ArrayList<>();

        for (int next : g.get(v)) {
            if (used[next]) {
                continue;
            }

            children.add(dfs(next));
        }

        Collections.sort(children);

        int keep = 0;
        int remove = 0;

        for (int i = 2; i < children.size(); i++) {
            keep += children.get(i).remove;
            remove += children.get(i).remove;
        }

        if (children.size() == 1) {
            keep += children.get(0).remove;
            remove += children.get(0).remove;
        } else {
            for (int i = 0; i < Math.min(children.size(), 2); i++) {
                keep += children.get(i).keep;
                remove += children.get(i).remove;
            }
        }

        remove++;

        return new Pair(keep, remove);
    }

    private static class Pair implements Comparable<Pair> {
        private final int keep;
        private final int remove;

        public Pair(int keep, int remove) {
            this.keep = keep;
            this.remove = remove;
        }

        public int compareTo(Pair other) {
            return Integer.compare(other.remove, remove);
        }
    }
}
