package cj.r1a;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.*;

public class CC {
    public static void main(String[] args) throws Exception {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintStream out = System.out;
        int testCaseCount = Integer.parseInt(in.readLine());
        for (int i = 0; i < testCaseCount; i++) {
            out.printf("Case #%d: %s%n", i + 1, solve(in, out));
        }
    }

    private static String solve(BufferedReader in, PrintStream out) throws Exception {
        String[] line = in.readLine().split(" ");
        int N = Integer.parseInt(line[0]);
        int L = Integer.parseInt(line[1]);
        long[] outlets = readData(in);
        long[] flows = readData(in);
        long[][] data = new long[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                data[i][j] = outlets[i] ^ flows[j];
            }
        }
        Set<Long> possible = new HashSet<Long>();
        toSet(data[0], possible);
        Set<Long> row = new HashSet<Long>();
        for (int i = 1; i < N; i++) {
            toSet(data[i], row);
            possible.retainAll(row);
        }
        if (possible.isEmpty()) {
            return "NOT POSSIBLE";
        } else {
            int min = L + 1;
            for (long p : possible) {
                min = Math.min(min, Long.bitCount(p));
            }
            return String.valueOf(min);
        }


    }

    private static void toSet(long[] src, Set<Long> dst) {
        dst.clear();
        for (long el : src) {
            dst.add(el);
        }
    }

    private static long[] readData(BufferedReader in) throws IOException {
        String[] raw = in.readLine().split(" ");
        long[] data = new long[raw.length];
        for (int i = 0; i < raw.length; i++) {
            data[i] = Long.parseLong(raw[i], 2);
        }
        return data;
    }
}
