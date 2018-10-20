package at.jaki.round1A.B;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;

public class B {

    //private static final String INPUT = "B-large.in";
    private static final String INPUT = "B-small-attempt0.in";
    //private static final String INPUT = "B-test.in";
    //private static final String INPUT = "B-large.out";
    private static final String OUTPUT = "B-small-attempt0.out";
    //private static final String OUTPUT = "B-test.out";

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader(INPUT));
        PrintWriter pw = new PrintWriter(OUTPUT);
        int totalTests = Integer.parseInt(br.readLine());
        for (int testNo = 1; testNo <= totalTests; testNo++) {
            int n = Integer.parseInt(br.readLine());

            Map<Integer, List<Integer>> graph = new HashMap<Integer, List<Integer>>();
            for (int i = 1; i <= n; i++) {
                graph.put(i, new ArrayList<Integer>());
            }

            int[] counts = new int[n + 1];
            String[] temp;
            for (int i = 0; i < n - 1; i++) {
                temp = br.readLine().split(" ");
                int a = Integer.parseInt(temp[0]);
                int b = Integer.parseInt(temp[1]);
                graph.get(a).add(b);
                graph.get(b).add(a);
                counts[a]++;
                counts[b]++;
            }

            int bestResult = n - 1;
            for (int i = 1; i <= n; i++) {
                int x = countRoot(i, graph);
                bestResult = Math.min(bestResult, x);
            }

            pw.print("Case #" + testNo + ": ");
            pw.println(bestResult);
        }

        pw.flush();
        pw.close();

    }

    private static int countRoot(Integer rootCandidate, Map<Integer, List<Integer>> graph) {
        List<Integer> conns = graph.get(rootCandidate);
        int c = conns.size();
        if (c == 0) {
            return 0;
        } else if (c == 2) {
            int[] r = new int[2];
            int x = 0;
            for (int conn : conns) {
                graph.get(conn).remove(rootCandidate);
                r[x++] = countRoot(conn, graph);
                graph.get(conn).add(rootCandidate);
            }
            return r[0] + r[1];
        } else if (c == 1) {
            int v = conns.get(0);
            graph.get(v).remove(rootCandidate);
            int r = sizeOf(v, graph);
            graph.get(v).add(rootCandidate);
            return r;
        } else if (c > 2) {
            int[] r = new int[c];
            int x = 0;
            for (int conn : conns) {
                graph.get(conn).remove(rootCandidate);
                int q1 = countRoot(conn, graph);
                int q2 = sizeOf(conn, graph);
                r[x++] = q2 - q1;
                graph.get(conn).add(rootCandidate);
            }
            Arrays.sort(r);
            int maxSave = r[r.length - 1] + r[r.length - 2];
            return sizeOf(rootCandidate, graph) - maxSave - 1;
        } else {
            throw new IllegalStateException("!!");
        }
    }

    private static int sizeOf(int v, Map<Integer, List<Integer>> graph) {
        Set<Integer> visited = new HashSet<Integer>();
        PriorityQueue<Integer> toVisit = new PriorityQueue<Integer>();
        toVisit.add(v);
        while (!toVisit.isEmpty()) {
            int curr = toVisit.poll();
            visited.add(curr);
            for (int n : graph.get(curr)) {
                if (!visited.contains(n)) {
                    toVisit.add(n);
                }
            }
        }
        return visited.size();
    }
}
