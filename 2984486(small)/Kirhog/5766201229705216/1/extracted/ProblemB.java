import java.io.File;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Locale;
import java.util.Scanner;
import java.util.Set;

/**
 * @author Alexander Gulko
 */
public class ProblemB {

    private static int n;
    private static int l;
    private static boolean[][] m;
    private static Set<Integer>[] adj;
    private static int[] deg;

    public static void main(String[] args) throws Exception {
        Locale.setDefault(Locale.US);

        String file = "B-large";

        String inFile = file + ".in";
        System.setOut(new PrintStream(file + ".out"));

        Scanner scan = new Scanner(new File(inFile));

        int tests = scan.nextInt();
        for (int test = 1; test <= tests; ++test) {
            solve(test, scan);
        }

        scan.close();
    }

    @SuppressWarnings("unchecked")
    static void solve(int test, Scanner scan) {
        n = scan.nextInt();

        m = new boolean[n + 1][n + 1];
        adj = new Set[n + 1];
        for (int i = 0; i <= n; ++i) {
            adj[i] = new HashSet<Integer>();
        }

        deg = new int[n + 1];

        for (int i = 0; i < n - 1; ++i) {
            int v1 = scan.nextInt();
            int v2 = scan.nextInt();

            m[v1][v2] = m[v2][v1] = true;

            adj[v1].add(v2);
            adj[v2].add(v1);

            deg[v1]++;
            deg[v2]++;
        }

        int best = n - 1;
        for (int v = 1; v <= n; ++v) {
            int count = tryV(v);
            int remove = n - count;
            //System.out.printf("Count with %s: %s\n", v, count);
            if (remove < best) {
                best = remove;
            }
        }

        System.out.printf("Case #%s: %s\n", test, best);
    }

    static int tryV(int v) {
        return countInTree(0, v);
    }

    static int countInTree(int parent, int v) {
        int count = 0;
        int childs = 0;
        List<Integer> vCount = new ArrayList<Integer>();
        for (int to : adj[v]) {
            if (to != parent) {
                ++childs;

                int c = countInTree(v, to);

                vCount.add(c);
                count += c;
            }
        }

        if (childs == 2 || childs == 0) {
            return 1 + count;
        }

        if (count > 0 && childs == 1) {
            return 1; // remove all subtree
        }

        // childs > 2
        // remain 2 childs
        Collections.sort(vCount, Collections.reverseOrder());
        return 1 + vCount.get(0) + vCount.get(1);
    }
}
