import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(new FileReader("B-small-attempt1.in"));
        //Scanner in = new Scanner(new FileReader("Input.in"));
        PrintWriter out = new PrintWriter(new FileWriter("Output4.out"));

        int testCases = in.nextInt();
        Task solver = new Task();
        for (int i = 1; i <= testCases; ++i)
            solver.solve(i, in, out);

        in.close();
        out.close();
    }
}

class Task {
    public final int INF = (int) (1e6);

    int[][] graph;
    boolean[] visited;
    int[] weight;
    int[] size;

    public void solve(int testNumber, Scanner in, PrintWriter out) {
        int n = in.nextInt();
        int[] from = new int[n - 1];
        int[] to = new int[n - 1];
        for (int i = 0; i < n - 1; ++i) {
            from[i] = in.nextInt() - 1;
            to[i] = in.nextInt() - 1;
        }

        graph = makeGraph(n, from, to);
        int res = n;
        for (int i = 0; i < n; ++i) {
            visited = new boolean[n];
            size = new int[n];
            rec(i, -1);

            visited = new boolean[n];
            weight = new int[n];
            Arrays.fill(weight, INF);
            res = Math.min(res, solve(i, -1));
        }

        System.out.println(testNumber);
        out.println("Case #" + testNumber + ": " + res);
    }

    public int solve(int u, int p) {
        if (visited[u]) return weight[u];
        int length = 0;
        for (int v : graph[u]) if (v != p) ++length;
        if (length == 0) weight[u] = 0;
        else if (length == 1) {
            for (int v : graph[u]) if (v != p) {
                weight[u] = size[v];
                break;
            }
        }
        else {
            int max1 = -1, max2 = -1;
            for (int i = 0; i < graph[u].length; ++i) {
                int v = graph[u][i];
                if (v == p) continue;
                int w = size[v] - solve(v, u);
                if (max1 == -1 || w > size[max1] - weight[max1]) {
                    max2 = max1;
                    max1 = v;
                }
                else if (max2 == -1 || w > size[max2] - weight[max2]) {
                    max2 = v;
                }
            }
            weight[u] = Math.min(size[u] - 1, size[u] - 1 - (size[max1] - weight[max1]) - (size[max2] - weight[max2]));
        }
        visited[u] = true;
        return weight[u];
    }

    public int rec(int u, int p) {
        if (visited[u]) return size[u];
        size[u] = 1;
        for (int v : graph[u]) {
            if (v == p) continue;
            size[u] += rec(v, u);
        }
        visited[u] = true;
        return size[u];
    }

    public int[][] makeGraph(int n, int[] from, int[] to) {
        int[] deg = new int[n];
        for (int u : from) ++deg[u];
        for (int v : to) ++deg[v];

        int[][] graph = new int[n][];
        for (int i = 0; i < n; ++i) graph[i] = new int[deg[i]];

        for (int i = 0; i < n - 1; ++i) graph[from[i]][--deg[from[i]]] = to[i];
        for (int i = 0; i < n - 1; ++i) graph[to[i]][--deg[to[i]]] = from[i];
        return graph;
    }
}
