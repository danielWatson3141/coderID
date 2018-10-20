package at.jaki.round1A.A;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;

public class A2 {

    //private static final String INPUT = "A-large.in";
    private static final String INPUT = "A-small-attempt2.in";
    //private static final String INPUT = "A-test.in";
    //private static final String INPUT = "A-large.out";
    private static final String OUTPUT = "A-small-attempt2.out";
    //private static final String OUTPUT = "A-test.out";

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader(INPUT));
        PrintWriter pw = new PrintWriter(OUTPUT);
        int totalTests = Integer.parseInt(br.readLine());
        for (int testNo = 1; testNo <= totalTests; testNo++) {
            String[] temp = br.readLine().split(" ");
            int n = Integer.parseInt(temp[0]);
            int l = Integer.parseInt(temp[1]);
            String[] have = br.readLine().split(" ");
            String[] need = br.readLine().split(" ");

            int res = -1;
            for (String need1 : need) {
                String tr = transform(have[0], need1);
                String[] haveTr = transformAll(have, tr);
                int x = validate(haveTr, need) ? count(tr) : -1;
                if (x != -1) {
                    if (res == -1 || x < res) {
                        res = x;
                    }
                }
            }

            pw.print("Case #" + testNo + ": ");
            if (res == -1) {
                pw.println("NOT POSSIBLE");
            } else {
                pw.println(res);
            }
        }

        pw.flush();
        pw.close();
    }

    private static String[] transformAll(String[] have, String tr) {
        String[] res = new String[have.length];
        for (int i = 0; i < have.length; i++) {
            StringBuilder sb = new StringBuilder();
            for (int j = 0; j < have[i].length(); j++) {
                if (tr.charAt(j) == '0' && have[i].charAt(j) == '0') {
                    sb.append('0');
                } else if (tr.charAt(j) == '1' && have[i].charAt(j) == '1') {
                    sb.append('0');
                } else {
                    sb.append('1');
                }
            }
            res[i] = sb.toString();
        }
        return res;
    }

    private static String transform(String s, String need1) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == need1.charAt(i)) {
                sb.append('0');
            } else {
                sb.append('1');
            }
        }
        return sb.toString();
    }

    private static int count(String tr) {
        int c = 0;
        for (char ch : tr.toCharArray()) {
            if (ch == '1') c++;
        }
        return c;
    }

    private static boolean validate(String[] a, String[] b) {
        String[] a2 = Arrays.copyOf(a, a.length);
        String[] b2 = Arrays.copyOf(b, a.length);
        Arrays.sort(a2);
        Arrays.sort(b2);
        for (int i = 0; i < a2.length; i++) {
            if (!a2[i].equals(b2[i])) {
                return false;
            }
        }
        return true;
    }


}
