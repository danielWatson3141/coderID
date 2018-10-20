import java.io.*;
import java.util.*;

public class A {
    private static String NP = "NOT POSSIBLE";
    public static void main(String[] args) throws Exception {
//        InputStream in = System.in;
        InputStream in = new FileInputStream("/home/floris/Downloads/A-large.in");
        System.setOut(new PrintStream("/home/floris/temp/codejam2014/src/A.out"));
        Scanner sc = new Scanner(in);

        for (int c = 1, cases = sc.nextInt(); c <= cases; c++) {
            int N = sc.nextInt();
            int L = sc.nextInt();
            String[] outlets = new String[N];
            String[] devices = new String[N];
            for (int i = 0; i < N; i++) outlets[i] = sc.next();
            for (int i = 0; i < N; i++) devices[i] = sc.next();

            int x = solve(N, L, outlets, devices, 0, 0, new boolean[N*N]);
            System.out.printf("Case #%d: %s%n", c, x==Integer.MAX_VALUE?NP:x);
        }
    }
    
    private static int solve(int N, int L, String[] outlets, String[] devices, int level, int flips, boolean[] notmatches) {
        if (level == L) return flips;
        int a = countOnes(devices, level);
        int b = countOnes(outlets, level);
        if (a != b && a != N-b) return Integer.MAX_VALUE;
        if (a != N-a) {
            boolean invert = a!=b;
            for (int j = 0; j < N; j++) {
                int i = 0;
                for (int k = 0; k < N; k++) {
                    if (invert ^ (devices[j].charAt(level) != outlets[k].charAt(level))) notmatches[j*N+k] = true;
                    if (notmatches[j*N+k]) i++;
                }
                if (i == N) return Integer.MAX_VALUE;
            }
            if (invert) flips++;
            return solve(N, L, outlets, devices, level+1, flips, notmatches);
        } else {
            boolean[] notmatches2 = Arrays.copyOf(notmatches, N*N);
            boolean err= false;
            for (int j = 0; j < N; j++) {
                int i = 0;
                for (int k = 0; k < N; k++) {
                    if ((devices[j].charAt(level) != outlets[k].charAt(level))) notmatches2[j*N+k] = true;
                    if (notmatches2[j*N+k]) i++;
                }
                if (i == N) err = true;
            }
            int a1 = err?Integer.MAX_VALUE:solve(N, L, outlets, devices, level+1, flips, notmatches2);
            notmatches2 = Arrays.copyOf(notmatches, N*N);
            err = false;
            for (int j = 0; j < N; j++) {
                int i = 0;
                for (int k = 0; k < N; k++) {
                    if ((devices[j].charAt(level) == outlets[k].charAt(level))) notmatches2[j*N+k] = true;
                    if (notmatches2[j*N+k]) i++;
                }
                if (i == N) err = true;
            }
            int a2 = err?Integer.MAX_VALUE:solve(N, L, outlets, devices, level+1, flips+1, notmatches2);
            return Math.min(a1, a2);
        }
    }

    private static int countOnes(String[] x, int pos) {
        int result = 0;
        for (int i = 0; i < x.length; i++) {
            if (x[i].charAt(pos) == '1') result++;
        }
        return result;
    }
}
