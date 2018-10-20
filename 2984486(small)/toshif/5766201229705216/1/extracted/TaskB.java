package gcj.round1A;

import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

/**
 * @author fuku
 */
public class TaskB {
    public static void main(String[] args) throws FileNotFoundException {
        InputStream inputStream = TaskB.class.getResourceAsStream("B-large.in");
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(new FileOutputStream("./out.txt"));

        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            System.out.println("------------------");
            System.out.println("test " + (i+1));
            SolB solver = new SolB();
            String ans = solver.solve(i, in, out);
            out.println("Case #" + (i+1) + ": " + ans);
            System.out.println("Case #" + (i+1) + ": " + ans);
        }
        out.close();
    }
}

class SolB {

    int N;
    int[][] g;
    boolean[] visited;

    public String solve(int testNumber, Scanner in, PrintWriter out) {
        N = in.nextInt();
        g = new int[N][N];
        visited = new boolean[N];

        for (int i = 0; i < N - 1; i++) {
            int from = in.nextInt() -1;
            int to = in.nextInt() -1;
            g[from][to] = 1;
            g[to][from] = 1;
        }

        int mi = 1000000;
        for (int i = 0; i < N; i++) {
            Arrays.fill(visited, false);
            int[] c = find(i);
            //System.out.printf("i=%s,c0=%s\n", i, c[0]);
            mi = Math.min(c[0], mi);
        }

        String ans = "" + mi;
        return ans;
    }

    int[] find(int n){
        //System.out.printf("find %s\n", n);
        visited[n] = true;

        int costs = 0;
        int leefs = 0;

        LinkedList<Integer> ca = new LinkedList<>();
        for (int i = 0; i < N; i++) {
            if (g[n][i] == 1 && !visited[i]) {
                leefs++;
                int[] c = find(i);
                costs += c[0];
                ca.add(c[1]);
            }
        }
        Collections.sort(ca);
        Collections.reverse(ca);

        if (leefs == 1) {
            costs += ca.get(0);
            ca.removeLast();
        } else if (leefs > 2) {
            while(ca.size() > 2) {
                costs += ca.getLast();
                ca.removeLast();
            }
        }

        int numNodes = 1;
        for (Integer nn : ca) {
            numNodes += nn;
        }

        return new int[]{costs, numNodes};
    }
}
