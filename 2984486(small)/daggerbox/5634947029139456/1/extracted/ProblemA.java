package com.forthgo.contest.g2014.r1a;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;


public class ProblemA {
    public static void main(String[] args) {
        try {
            Scanner in = new Scanner(new File("A.in.txt"));
            PrintWriter out = new PrintWriter(new FileWriter("A.out.txt"));
//            PrintWriter out = new PrintWriter(System.out);
            int n = in.nextInt();
            in.nextLine();
            for (int i = 0; i < n; i++) {
                out.printf("Case #%d: ", i + 1);
                solve(in, out);
                out.println();
                out.flush();
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

    }

    private static void solve(Scanner in, PrintWriter out) {
        int N = in.nextInt();
        int L = in.nextInt();
        long[] initial = new long[N];
        for (int i = 0; i < N; i++) {
            initial[i] = in.nextLong(2);
        }
        Set<Long> flow = new HashSet<>();
        Set<Long>[] flows = new HashSet[L];
        for (int i = 0; i < L; i++) {
            flows[i] = new HashSet<Long>();
        }
        for (int i = 0; i < N; i++) {
            long k = in.nextLong(2);
            long mask = 1L << (L - 1);
            for (int j = 0; j < L; j++) {
                flows[j].add(k & mask);
                mask = mask | (mask >> 1);
            }
        }

        long mask = 1L << (L - 1);
        int best = L + 1;
        List<Long> cur = new ArrayList<>();
        cur.add(0L);
        long step = 1L << (L - 1);
        for (int i = 0; i < L; i++) {

            List<Long> next = new ArrayList<>();
            for (int j = 0; j < cur.size(); j++) {
                long iBits = cur.get(j);
                for (int k = 0; k < 2; k++) {
                    boolean success = true;
                    for (int ii = 0; ii < N; ii++) {
                        long bits = iBits;
                        long x = initial[ii] & mask;
                        while (bits != 0) {
                            long b = Long.highestOneBit(bits);
                            bits = bits & ~b;
                            x = x ^ b;
                        }
                        if (!flows[i].contains(x)) {
                            success = false;
                            break;
                        }
                    }
                    if (success) {
                        if (i == L - 1) {
                            int flips = Long.bitCount(iBits);
                            if (flips < best)
                                best = flips;
                        }
                        else {
                            next.add(iBits);
                        }
                    }
                    iBits += step;
                }
            }
            cur = next;
            step /= 2;
            mask = mask | (mask >> 1);
        }
        if (best <= L)
            out.print(best);
        else
            out.print("NOT POSSIBLE");
    }

}

