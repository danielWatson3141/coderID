import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class B {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int t = 1; t <= T; t++) {
            System.out.printf("Case #%d: ", t);
            solve(in);
        }

    }

    public static void solve(Scanner in) {
        int N = in.nextInt();

        List<Integer>[] adj = new List[N];
        for (int i = 0; i < N; i++)
            adj[i] = new ArrayList<Integer>();

        for (int i = 0; i < N - 1; i++) {
            int a = in.nextInt() - 1;
            int b = in.nextInt() - 1;
            adj[a].add(b);
            adj[b].add(a);
        }

        int cheapest = Integer.MAX_VALUE;

        for (int i = 0; i < N; i++) {
            int cost = fix(adj, i, -1);
            cheapest = Math.min(cost, cheapest);
        }
        System.out.println(cheapest);
    }

    public static int fix(List<Integer>[] adj, int root, int prev) {

        ArrayList<Integer> children = new ArrayList<Integer>();
        for (int i = 0; i < adj[root].size(); i++) {
            if (adj[root].get(i) != prev) children.add(adj[root].get(i));

        }

        if (children.size() == 0) return 0;
        if (children.size() == 1) { return size(adj, children.get(0), root); }
        if (children.size() == 2) { return fix(adj, children.get(0), root)
                + fix(adj, children.get(1), root); }

        int cheapest = Integer.MAX_VALUE;
        // Otherwise we have more than 2
        for (int i = 0; i < children.size(); i++) {
            for (int j = i + 1; j < children.size(); j++) {

                int cost = fix(adj, children.get(i), root);
                cost += fix(adj, children.get(j), root);

                for (int k = 0; k < children.size(); k++) {
                    if (k == i || k == j) continue;
                    cost += size(adj, children.get(k), root);
                }

                cheapest = Math.min(cheapest, cost);
            }
        }

        return cheapest;
    }

    public static int size(List<Integer>[] adj, int root, int prev) {
        int size = 1;
        for (Integer c : adj[root]) {
            if (c == prev) continue;

            size += size(adj, c, root);
        }
        return size;
    }
}
