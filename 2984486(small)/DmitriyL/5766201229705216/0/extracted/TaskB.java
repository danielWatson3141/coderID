import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class TaskB {
    private static int n;
    private static List<Integer>[] g;
    private static boolean[] used;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int tests = scanner.nextInt();
        for (int test = 1; test <= tests; test++) {
            n = scanner.nextInt();

            g = new List[n];
            for (int i = 0; i < n; i++) {
                g[i] = new ArrayList<>();
            }

            for (int i = 0; i < n - 1; i++) {
                int a = scanner.nextInt() - 1;
                int b = scanner.nextInt() - 1;
                g[a].add(b);
                g[b].add(a);
            }

            int result = Integer.MAX_VALUE;

            for (int mask = 0; mask < (1 << n); mask++) {
                if (ok(mask)) {
                    result = Math.min(result, Integer.bitCount(mask));
                }
            }

            System.out.println("Case #" + test + ": " + result);
        }

        scanner.close();
    }

    private static boolean ok(int mask) {
        for (int startVertex = 0; startVertex < n; startVertex++) {
            used = new boolean[n];
            boolean correctConfiguration = dfs(startVertex, mask);
            boolean allUsed = true;

            for (int i = 0; i < n; i++) {
                if ((mask & (1 << i)) == 0 && !used[i]) {
                    allUsed = false;
                    break;
                }
            }

            if (correctConfiguration && allUsed) {
                return true;
            }
        }

        return false;
    }

    private static boolean dfs(int v, int mask) {
        used[v] = true;

        int children = 0;

        boolean result = true;

        for (int next : g[v]) {
            if (!used[next] && (mask & (1 << next)) == 0) {
                children++;
                result &= dfs(next, mask);
            }
        }

        return result && (children == 0 || children == 2);
    }
}
