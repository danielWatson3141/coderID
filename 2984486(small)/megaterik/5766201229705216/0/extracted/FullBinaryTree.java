package r1a2014;

/**
 *
 * @author coldhands
 */
import java.awt.Point;
import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.lang.Math.*;

public class FullBinaryTree implements Runnable {

    BufferedReader in;
    PrintWriter out;
    StringTokenizer tok = new StringTokenizer("");

    public static void main(String[] args) {
        new Thread(null, new FullBinaryTree(), "", 512 * (1L << 20)).start();
    }

    public void run() {
        try {
            long t1 = System.currentTimeMillis();
            //    in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);
            in = new BufferedReader(new FileReader("src/r1a2014/full-binary.in"));
            out = new PrintWriter("src/r1a2014/full-binary.out");

            Locale.setDefault(Locale.US);
            solve();
            in.close();
            out.close();
            long t2 = System.currentTimeMillis();
            System.err.println("Time = " + (t2 - t1));
        } catch (Throwable t) {
            t.printStackTrace(System.err);
            System.exit(-1);
        }
    }

    private String readString() throws IOException {
        while (!tok.hasMoreTokens()) {
            tok = new StringTokenizer(in.readLine());
        }
        return tok.nextToken();
    }

    private int readInt() throws IOException {
        return Integer.parseInt(readString());
    }

    private long readLong() throws IOException {
        return Long.parseLong(readString());
    }

    private double readDouble() throws IOException {
        return Double.parseDouble(readString());
    }

    // solution
    void solve() throws IOException {
        int testcases = readInt();
        int i = 0;
        while (testcases-- > 0) {
            solveTestCase(++i);
        }
    }

    private Edge[] first;

    private void solveTestCase(int testcase) throws IOException {
        int n = readInt();
        first = new Edge[n];
        for (int i = 0; i < n - 1; i++) {
            int a = readInt() - 1;
            int b = readInt() - 1;
            first[a] = new Edge(a, b, first[a]);
            first[b] = new Edge(b, a, first[b]);
        }
        int[][] f = new int[n][n];
        for (int i = 0; i < f.length; i++) {
            Arrays.fill(f[i], -1);
        }
        int keepNodes = Integer.MIN_VALUE / 2;
        for (int i = 0; i < f.length; i++) {
            keepNodes = Math.max(keepNodes, calculate(f, i, i));
        }
        out.println("Case #" + testcase + ": " + (n - keepNodes));
    }

    private int calculate(int[][] f, int i, int prev) {
        if (f[i][prev] != -1) {
            return f[i][prev];
        }

        for (Edge edge = first[i]; edge != null; edge = edge.next) {
            if (edge.b != prev) {
                calculate(f, edge.b, edge.a);
            }
        }
        int keepNodes = 1;
        for (Edge firstSon = first[i]; firstSon != null; firstSon = firstSon.next) {
            for (Edge secondSon = first[i]; secondSon != null; secondSon = secondSon.next) {
                if (firstSon != secondSon && firstSon.b != prev && secondSon.b != prev) {
                    keepNodes = Math.max(keepNodes, 1 + f[firstSon.b][i] + f[secondSon.b][i]);
                }
            }
        }
        f[i][prev] = keepNodes;
        return f[i][prev];
    }

    class Edge {

        int a;
        int b;
        Edge next;

        Edge(int a, int b, Edge next) {
            this.a = a;
            this.b = b;
            this.next = next;
        }
    }
}
