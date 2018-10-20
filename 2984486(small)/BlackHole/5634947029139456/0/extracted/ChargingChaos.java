package Round1A.A;

import Qualification.D.DeceitfulWar;

import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;
import java.util.TreeSet;

/**
 * Created by mtian on 4/25/14.
 */
public class ChargingChaos {
    int N;
    int L;
    String[] in;
    String[] out;
    int[][] possible;

    public void trimZero(int col, Boolean flip) throws Exception {
        if (flip == null) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (possible[i][j] > 0) {
                        if (in[i].charAt(col) == out[j].charAt(col)) {
                            possible[i][j] = possible[i][j] * 2;
                        } else {
                            possible[i][j] = possible[i][j] * 2 + 1;
                        }
                    }
                }
            }
        } else if (!flip) {
            for (int i = 0; i < N; i++) {
                int count = 0;
                for (int j = 0; j < N; j++) {
                    if (possible[i][j] > 0) {
                        if (in[i].charAt(col) == out[j].charAt(col)) {
                            possible[i][j] = possible[i][j] * 2;
                            count++;
                        } else {
                            possible[i][j] = -1;
                        }
                    }
                }
                if (count == 0) {
                    throw new IllegalArgumentException();
                }
            }
        } else {
            for (int i = 0; i < N; i++) {
                int count = 0;
                for (int j = 0; j < N; j++) {
                    if (possible[i][j] > 0) {
                        if (in[i].charAt(col) == out[j].charAt(col)) {
                            possible[i][j] = -1;
                        } else {
                            possible[i][j] = possible[i][j] * 2 + 1;
                            count++;
                        }
                    }
                }
                if (count == 0) {
                    throw new IllegalArgumentException();
                }
            }
        }
    }

    public int getZero(String[] strings, int p) {
        int count = 0;
        for (int i = 0; i < strings.length; i++) {
            if (strings[i].charAt(p) == '0') {
                count++;
            }
        }
        return count;
    }

    public int getFlip(int k) {
        int count = -1;
        while (k > 0) {
            if (k % 2 != 0) {
                count++;
            }
            k = k / 2;
        }
        return count;
    }

    public void solve(Scanner sc, PrintWriter pw) throws Exception {
        N = sc.nextInt();
        L = sc.nextInt();
        in = new String[N];
        out = new String[N];

        for (int i = 0 ; i < N; i++) {
            in[i] = sc.next();
        }
        for (int i = 0 ; i < N; i++) {
            out[i] = sc.next();
        }

        possible = new int[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                possible[i][j] = 1;
            }
        }

        int flipCount = 0;
        try {
            for (int j = 0; j < L; j++) {
                int numZeroIn = getZero(in, j);
                int numZeroOut = getZero(out, j);
                if (numZeroIn + numZeroOut == N && numZeroIn == numZeroOut) {
                    trimZero(j, null);
                } else if (numZeroIn == numZeroOut) {
                    trimZero(j, false);
                } else if (numZeroIn + numZeroOut == N) {
                    trimZero(j, true);
                } else {
                    throw new IllegalArgumentException();
                }
            }

            TreeSet<Integer> path = new TreeSet<Integer>();
            for (int j = 0; j < N; j++) {
                if (possible[0][j] > 0) {
                    path.add(possible[0][j]);
                }
            }
            for (int i = 1; i < N; i++) {
                TreeSet<Integer> pathNew = new TreeSet<Integer>();
                TreeSet<Integer> pathOther = new TreeSet<Integer>();
                for (int j = 0; j < N; j++) {
                    if (possible[i][j] > 0) {
                        pathOther.add(possible[i][j]);
                    }
                }
                for (int k : path) {
                    if (pathOther.contains(k)) {
                        pathNew.add(k);
                    }
                }
                path = pathNew;

                if (path.size() == 0) {
                    throw new IllegalArgumentException();
                }
            }
            int minFlip = Integer.MAX_VALUE;
            for (int k : path) {
                minFlip = Math.min(minFlip, getFlip(k));
            }
            if (minFlip < 0) {
                throw new IllegalArgumentException();
            }
            flipCount = minFlip;

        } catch (IllegalArgumentException ex) {
            pw.println("NOT POSSIBLE");
            return;
        }

        pw.println(flipCount);
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileInputStream("A-small-attempt1.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("A-small-attempt1.out"));
        ChargingChaos solver = new ChargingChaos();
        int T = sc.nextInt();
        for (int caseNum = 1; caseNum <= T; caseNum++) {
            System.out.println("Processing test case " + caseNum);
            pw.print("Case #" + caseNum + ": ");
            solver.solve(sc, pw);
        }
        pw.flush();
        pw.close();
    }

}
