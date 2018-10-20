import java.util.*;
public class B {
    static Scanner s;
    public static void main(String[] args) {
        s = new Scanner(System.in);
        int n = s.nextInt();
        for (int i = 1; i <= n; i++) {
            System.out.printf("Case #%d: %d\n", i, solve());
        }
    }

    public static int solve() {
        int N = s.nextInt();
        Map<Integer, Set<Integer>> graph = new HashMap<>();
        for (int i = 1; i <= N; i++) {
            graph.put(i, new HashSet<Integer>());
        }
        for (int i = 0; i < N-1; i++) {
            int a = s.nextInt();
            int b = s.nextInt();
            graph.get(a).add(b);
            graph.get(b).add(a);
        }
        Set<Integer> evens = new HashSet<Integer>();
        Map<Integer, Integer> deg = new HashMap<Integer, Integer>();
        for (Integer node : graph.keySet()) {
            int size = graph.get(node).size();
            if (size > 3 || size == 2) {
                evens.add(node);
                deg.put(node, size);
            }
        }

        Set<Integer> removed = new HashSet<>();
        while (evens.size() > 1) {
            // Find adjacent states by removing evens
            int min = 10000000;
            int node11 = -1;
            Set<Integer> minRemove = null;
outer:
            for (Integer node : evens) {
                for (Integer node2 : graph.get(node)) {
                    Set<Integer> v = new HashSet<Integer>();
                    Queue<Integer> q = new ArrayDeque<>();
                    q.add(node2);
                    while (!q.isEmpty()) {
                        int curr2 = q.poll();
                        v.add(curr2);
                        for (Integer n3 : graph.get(curr2)) {
                            if (!v.contains(n3) && n3 != node) {
                                q.add(n3);
                            }
                        }
                    }
                    if (v.size() < min) {
                        min = v.size();
                        minRemove = v;
                        node11 = node;
                        if (min == 1) break outer;
                    }
                }
            }
            evens.removeAll(minRemove);
            int currDeg = deg.get(node11) - 1;
            if (currDeg == 1 || currDeg == 3) {
                evens.remove(node11);
            } else {
                deg.put(node11, currDeg);
            }
            evens.remove(node11);
            removed.addAll(minRemove);
        }
        return removed.size();
    }

    public static class State implements Comparable<State> {
        Set<Integer> removed;
        Set<Integer> evens;
        public State(Set<Integer> r, Set<Integer> e) {
            removed = r;
            evens = e;
        }

        public int compareTo(State other) {
            return this.removed.size() - other.removed.size();
        }
    }
}
               // // Remove the node
               // Set<Integer> eve = new HashSet<>(curr.evens);
               // eve.remove(node);
               // // Get Subtrees
               // Map<Integer, Set<Integer>> subs = new HashMap<>();
               // for (Integer node2 : graph.get(node)) {
               //     if (curr.removed.contains(node2)) continue;
               //     Set<Integer> v = new HashSet<Integer>();
               //     Queue<Integer> q = new ArrayDeque<>();
               //     q.add(node2);
               //     while (!q.isEmpty()) {
               //         int curr2 = q.poll();
               //         v.add(curr2);
               //         for (Integer n3 : graph.get(curr2)) {
               //             if (!v.contains(n3) && n3 != node) {
               //                 q.add(n3);
               //             }
               //         }
               //     }
               //     subs.put(node2, v);
               // }
               // for (Integer n1 : subs.keySet()) {
               //     Set<Integer> eve2 = new HashSet<>(eve);
               //     eve2.removeAll(subs.get(n1));
               //     Set<Integer> rem2 = new HashSet<>(curr.removed);
               //     rem2.addAll(subs.get(n1));
               //     if (!visited.contains(eve2)) {
               //         pq.add(new State(rem2, eve2));
               //     }
               // }
