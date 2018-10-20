package at.jaki.round1A.C;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;

public class C {

    //private static final String INPUT = "C-large.in";
    private static final String INPUT = "C-small-attempt1.in";
    //private static final String INPUT = "C-test.in";
    //private static final String INPUT = "C-large.out";
    private static final String OUTPUT = "C-small-attempt1.out";
    //private static final String OUTPUT = "C-test.out";

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader(INPUT));
        PrintWriter pw = new PrintWriter(OUTPUT);
        int totalTests = Integer.parseInt(br.readLine());


        int[][] x = new int[totalTests][2];
        for (int testNo = 1; testNo <= totalTests; testNo++) {
            int n = Integer.parseInt(br.readLine());
            int[] t = new int[n];
            String[] temp = br.readLine().split(" ");
            for (int i = 0; i < n; i++) {
                t[i] = Integer.parseInt(temp[i]);
            }
            int sum1 = 0;
            int sum2 = 0;
            for (int i = 0; i < n / 2; i++) {
                sum1 += t[i];
            }
            for (int i = n / 2; i < n; i++) {
                sum2 += t[i];
            }
            x[testNo - 1][1] = Math.abs(sum2 - sum1);
            x[testNo - 1][0] = testNo;
            //pw.print("Case #" + testNo + ": ");
        }
        Arrays.sort(x, new Comparator<int[]>() {
            @Override
            public int compare(int[] a, int[] b) {
                return a[1] - b[1];
            }
        });

        System.out.println("goods:");
        String[] results = new String[totalTests + 1];
        for (int i = 0; i < totalTests / 2; i++) {
            int index = x[i][0];
            System.out.println(x[i][1]);
            results[index] = "GOOD";
        }
        System.out.println("bads:");
        for (int i = totalTests / 2; i < totalTests; i++) {
            int index = x[i][0];
            System.out.println(x[i][1]);
            results[index] = "BAD";
        }

        for (int i = 1; i <= totalTests; i++) {
            if (results[i] == null) {
                results[i] = "BAD";
                System.out.println("Something is wrong");
            }
            pw.println("Case #" + i + ": " + results[i]);
        }

        pw.flush();
        pw.close();

    }
}
