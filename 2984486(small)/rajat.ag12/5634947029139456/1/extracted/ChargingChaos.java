import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class ChargingChaos {
    final static String PROBLEM_NAME = "src";
    final static String WORK_DIR = "/users/rajatag12/Desktop/topcoder/Contests/GCJ/" + PROBLEM_NAME + "/";
    final static String OUTPUT_FILE_NAME = "output.txt";

    static void preprocess() {
    }

    void solve(Scanner sc, PrintWriter pw) {
        int N = sc.nextInt();
        int L = sc.nextInt();
        
        long[] outlets = new long[N];
        for (int i = 0; i < N; i++) {
            outlets[i] = Long.parseLong(sc.next(), 2);
        }
        long[] devices = new long[N];
        for (int i = 0; i < N; i++) {
            devices[i] = Long.parseLong(sc.next(), 2);
        }

        long[][] xors = new long[N][N];
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                xors[i][j] = outlets[i] ^ devices[j];
            }
        }

        int res = L + 1;
        for (long x : xors[0]) {
            long sum = 0;
            for (long[] a : xors) {
                for (int i = 0; i < N; ++i) {
                    if (a[i] == x) {
                        sum += i + 1;
                        break;
                    }
                }
            }
            if (sum == N * (N + 1) / 2) {
                res = Math.min(res, Long.bitCount(x));
            }
        }

        pw.println(res <= L ? res : "NOT POSSIBLE");
    }

    public static void main(String[] args) throws Exception {
        preprocess();

        Scanner sc = new Scanner(System.in);
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR
                + OUTPUT_FILE_NAME));
        int caseCnt = sc.nextInt();
        for (int caseNum = 0; caseNum < caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum + 1) + ": ");
            new ChargingChaos().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
