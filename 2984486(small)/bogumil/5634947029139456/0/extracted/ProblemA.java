import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class ProblemA {
    final static String PROBLEM_NAME = "ProblemA";
    final static String WORK_DIR = "d:\\work\\idea_work\\CodeJam2014_R1A\\src\\";

    public void solve(Scanner sc, PrintWriter pw) {
        int N = sc.nextInt();
        int L = sc.nextInt();

        String [] flow = new String[N];
        String [] devices = new String[N];

        for (int i = 0; i < N; i++) {
            flow[i] = sc.next();
        }

        for (int i =0; i < N; i++) {
            devices[i] = sc.next();
        }

        Arrays.sort(flow);
        Arrays.sort(devices);

        int result = 0;

        for (int ith = 0; ith < L; ith++) {
            for (int idx = 0; idx < N; idx++) {
                if (flow[idx].charAt(ith) != devices[idx].charAt(ith)) {
                    flow = flip(flow, ith);
                    result++;
                    Arrays.sort(flow);
                    Arrays.sort(devices);
                    break;
                }
            }
        }

        boolean isOk = true;

        for (int i = 0; i < N; i++) {
            if (!flow[i].equals(devices[i])) {
                isOk = false;
                break;
            }
        }

        if (isOk) {
            pw.println(result);
        } else {
            pw.println("NOT POSSIBLE");
        }
    }

    String [] flip(String[] flow, int ith) {
        for (int i = 0; i < flow.length; i++) {
            StringBuilder sb = new StringBuilder(flow[i]);
            if (flow[i].charAt(ith) == '0') {
                sb.setCharAt(ith, '1');
            } else if (flow[i].charAt(ith) == '1') {
                sb.setCharAt(ith, '0');
            }
            flow[i] = sb.toString();
        }

        return flow;
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileReader(WORK_DIR + PROBLEM_NAME + ".in"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + PROBLEM_NAME + ".out"));

        int N = sc.nextInt();

        for (int testNum=1; testNum <= N; testNum++) {
            System.out.println("Processing test case: " + testNum);
            pw.print("Case #" + (testNum) + ": ");
            new ProblemA().solve(sc, pw);
        }

        pw.flush();
        pw.close();
        sc.close();
    }
}
