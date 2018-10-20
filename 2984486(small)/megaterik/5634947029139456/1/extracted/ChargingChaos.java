/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
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

public class ChargingChaos implements Runnable {

    BufferedReader in;
    PrintWriter out;
    StringTokenizer tok = new StringTokenizer("");

    public static void main(String[] args) {
        new Thread(null, new ChargingChaos(), "", 512 * (1L << 20)).start();
    }

    public void run() {
        try {
            long t1 = System.currentTimeMillis();
            //    in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);
            in = new BufferedReader(new FileReader("src/r1a2014/charging-chaos.in"));
            out = new PrintWriter("src/r1a2014/charging-chaos.out");

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

    private static final int INF = Integer.MAX_VALUE / 2;

    private void solveTestCase(int testcase) throws IOException {
        int best = INF;
        int n = readInt();
        readInt();
        long[] a = new long[n];
        long[] b = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = Long.parseLong(readString(), 2);
        }
        for (int i = 0; i < n; i++) {
            b[i] = Long.parseLong(readString(), 2);
        }
        Arrays.sort(b);
        for (int connectFirst = 0; connectFirst < n; connectFirst++) {
            long change = (a[0] ^ b[connectFirst]);
            int cost = countOnes(Long.toBinaryString(change));

            long[] changedA = new long[n];
            for (int i = 0; i < n; i++) {
                changedA[i] = a[i] ^ change;
            }
            Arrays.sort(changedA);
            for (int i = 0; i < changedA.length; i++) {
                if (changedA[i] != b[i]) {
                    break;
                } else if (i == changedA.length - 1) {
                    best = Math.min(best, cost);
                }
            }
        }
        out.println("Case #" + testcase + ": " + (best == INF ? "NOT POSSIBLE" : best));
    }

    private int countOnes(String toBinaryString) {
        int res = 0;
        for (char x : toBinaryString.toCharArray()) {
            if (x == '1') {
                res++;
            }
        }
        return res;
    }

}
