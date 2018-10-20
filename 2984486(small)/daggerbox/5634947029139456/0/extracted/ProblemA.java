package com.forthgo.contest.g2014.r1a;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;


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
        Set<Long> flow = new HashSet<>();
        for (int i = 0; i < N; i++) {
            initial[i] = in.nextLong(2);
        }
        for (int i = 0; i < N; i++) {
            flow.add(in.nextLong(2));
        }

        long pL = 1 << L;
        int best = L + 1;
        bitPattern:
        for (long iBits = 0; iBits < pL; iBits++) {
            for (int j = 0; j < N; j++) {
                long bits = iBits;
                long x = initial[j];
                while (bits != 0) {
                    long b = Long.highestOneBit(bits);
                    bits = bits & ~b;
                    x = x ^ b;
                }
                if (!flow.contains(x)) {
                    continue bitPattern;
                }
            }
            // success
            int flips = Long.bitCount(iBits);
            if (flips < best)
                best = flips;
        }
        if (best <= L)
            out.print(best);
        else
            out.print("NOT POSSIBLE");
    }

}

