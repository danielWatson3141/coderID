import java.io.*;
import java.util.*;

public class Main {
    
    static int N, L;
    static long[] device, outlet;
    static String impossible = "NOT POSSIBLE";
    static long[] backup;
    static boolean check(long val) {
        boolean[] used = new boolean[N];
    outer:
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (used[j]) {
                    continue;
                } else if (device[i] == (outlet[j] ^ val)) {
                    used[j] = true;
                    continue outer;
                }
            }
            return false;
        }
        return true;
    }
    
    static int bitCount(long val) {
        int res = 0;
        for (int i = 0; i < L; ++i) {
            if (get(val, i)) {
                ++res;
            }
        }
        return res;
    }
    
    static boolean get(long val, int bitIndex) {
        return ((val >> bitIndex) & 1) != 0;
    }
    static String solve() {
        int res = Integer.MAX_VALUE;
        for (long val = 0; val < 1024; ++val) {
            int count = bitCount(val);
            if (check(val)) {
                res = Math.min(res, count);
            }
        }
        return res == Integer.MAX_VALUE ? impossible : Integer.toString(res);
    }
    
    public static void main(String[] args) throws Exception {
        FastScanner scan = new FastScanner(System.in);
        int taskCount = scan.nextInt();
        for (int taskIndex = 1; taskIndex <= taskCount; ++taskIndex) {
            N = scan.nextInt();
            L = scan.nextInt();
            device = new long[N];
            outlet = new long[N];
            backup = new long[N];
            for (int i = 0; i < N; ++i) {
                outlet[i] = scan.nextLong();
            }
            for (int i = 0; i < N; ++i) {
                device[i] = scan.nextLong();
            }
            Arrays.sort(device);
            String res = solve();
            System.out.println(String.format("Case #%d: %s", taskIndex, res));
        }
    }
}

class FastScanner {
    BufferedReader in;
    StringTokenizer tok;
    
    public FastScanner(InputStream in) {
        this.in = new BufferedReader(new InputStreamReader(in));
        tok = new StringTokenizer("");
    }
    
    private String tryReadNextLine() {
        try {
            return in.readLine();
        } catch (Exception e) {
            throw new InputMismatchException();
        }
    }
    
    public String nextToken() {
        while (!tok.hasMoreTokens()) {
            tok = new StringTokenizer(next());
        }
        return tok.nextToken();
    }
    
    public String next() {
        String newLine = tryReadNextLine();
        if (newLine == null)
            throw new InputMismatchException();
        return newLine;
    }
    
    public int nextInt() {
        return Integer.parseInt(nextToken());
    }
    
    public double nextDouble() {
        return Double.parseDouble(nextToken());
    }
    
    public long nextLong() {
        return Long.parseLong(nextToken());
    }
    
}