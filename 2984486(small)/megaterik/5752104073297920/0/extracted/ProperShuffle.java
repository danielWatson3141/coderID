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

public class ProperShuffle implements Runnable {

    BufferedReader in;
    PrintWriter out;
    StringTokenizer tok = new StringTokenizer("");

    public static void main(String[] args) {
        new Thread(null, new ProperShuffle(), "", 512 * (1L << 20)).start();
    }

    public void run() {
        try {
            long t1 = System.currentTimeMillis();
            //    in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);
            in = new BufferedReader(new FileReader("src/r1a2014/proper-shuffle.in"));
            out = new PrintWriter("src/r1a2014/proper-shuffle.out");

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
        double[] score = new double[testcases];
        double[] sortedScore = new double[testcases];
        for (int i = 0; i < testcases; i++) {
            score[i] = getScore();
            sortedScore[i] = score[i];
        }
        Arrays.sort(sortedScore);
        double threshold = sortedScore[score.length / 2];
        for (int i = 0; i < testcases; i++) {
            out.println("Case #" + (i + 1) + ": " + (score[i] > threshold ? "BAD" : "GOOD"));
        }

    }

    private double getScore() throws IOException {
        int n = readInt();
        int[] a = new int[n];
        int[] index = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = readInt();
            index[a[i]] = i;
        }
        double score = 0;
        for (int i = 0; i < n; i++) {
            if (index[i] > i) {
                score += Math.exp(((double)((index[i] - i))) / n);
            }
        }
        System.err.println(score);
        return score;
    }

}
