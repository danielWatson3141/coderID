import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(new FileReader("A-small-attempt1.in"));
        //Scanner in = new Scanner(new FileReader("Input.in"));
        PrintWriter out = new PrintWriter(new FileWriter("Output2.out"));

        int testCases = in.nextInt();
        Task solver = new Task();
        for (int i = 1; i <= testCases; ++i)
            solver.solve(i, in, out);

        in.close();
        out.close();
    }
}

class Task {
    public void solve(int testNumber, Scanner in, PrintWriter out) {
        int n = in.nextInt();
        int l = in.nextInt();
        long[] a = new long[n];
        for (int i = 0; i < n; ++i)
            a[i] = Long.parseLong(in.next(), 2);
        long[] b = new long[n];
        for (int i = 0; i < n; ++i)
            b[i] = Long.parseLong(in.next(), 2);

        int res = solve2(n, l, a, b);
        System.out.println("TestNumber #" + testNumber);
        out.println("Case #" + testNumber + ": " + (res == -1 ? "NOT POSSIBLE" : res));
    }

    public int solve(int n, int l, long[] a, long[] b) {
        int res = 0;
        long canFlip = 0;
        for (int j = 0; j < l; ++j) {
            int cntA = 0, cntB = 0;
            for (int i = 0; i < n; ++i) {
                if ((a[i] & (1L << j)) == 0) ++cntA;
                if ((b[i] & (1L << j)) == 0) ++cntB;
            }
            if (cntA == cntB) {
                if (2 * cntA == n) canFlip |= (1L << j);
            }
            else if (cntA == n - cntB) {
                ++res;
                for (int i = 0; i < n; ++i)
                    a[i] ^= (1L << j);
            }
            else {
                return -1;
            }
        }
        for (int j = l - 1; j >= 0; --j) {
            if ((canFlip & (1L << j)) == 0) continue;
            HashSet<Long> setA = new HashSet<Long>();
            HashSet<Long> negSetA = new HashSet<Long>();
            HashSet<Long> setB = new HashSet<Long>();
            for (int i = 0; i < n; ++i) {
                setA.add((a[i] >> j));
                negSetA.add(((a[i] >> j) ^ 1L));
                setB.add((b[i] >> j));
            }
            if (setA.equals(setB)) {}
            else if (setA.equals(negSetA)) {
                ++res;
                for (int i = 0; i < n; ++i)
                    a[i] ^= (1L << j);
            }
            else {
                return -1;
            }
        }
        return res;
    }

    public int solve2(int n, int l, long[] a, long[] b) {
        int res = Integer.MAX_VALUE;
        boolean possible = false;
        for (long flip = 0; flip < (1L << l); ++flip) {
            long[] A = a.clone();
            for (int j = 0; j < l; ++j) {
                if ((flip & (1L << j)) == 0) continue;
                for (int i = 0; i < n; ++i)
                    A[i] ^= (1L << j);
            }
            Arrays.sort(A);
            Arrays.sort(b);
            if (Arrays.equals(A, b)) {
                possible = true;
                res = Math.min(res, Long.bitCount(flip));
            }
        }
        return possible ? res : -1;
    }
}
