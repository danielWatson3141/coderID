package round1a;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Problem1 {

    public static void main(String[] args) throws FileNotFoundException {
        // System.out.println("start");
        Scanner sc = new Scanner(new File("src/round1a/A-small-attempt2.in"));
        PrintWriter pw = new PrintWriter(new File("src/round1a/out.txt"));
        int T = sc.nextInt();
        for (int tc = 0; tc < T; tc++) {
            String out = "";
            int N = sc.nextInt();
            int L = sc.nextInt();
            char[][] outlets = new char[N][L];
            for (int i = 0; i < N; i++) {
                outlets[i] = sc.next().toCharArray();
            }
            char[][] devices = new char[N][L];
            for (int i = 0; i < N; i++) {
                devices[i] = sc.next().toCharArray();
            }

            int[] dparities = new int[L];
            for (int i = 0; i < L; i++) {
                int z = 0, o = 0;
                for (int j = 0; j < N; j++) {
                    if (devices[j][i] == '0') {
                        z++;
                    } else {
                        o++;
                    }
                }
                dparities[i] = o - z;
            }

            int[] oparities = new int[L];
            for (int i = 0; i < L; i++) {
                int z = 0, o = 0;
                for (int j = 0; j < N; j++) {
                    if (outlets[j][i] == '0') {
                        z++;
                    } else {
                        o++;
                    }
                }
                oparities[i] = o - z;
            }
            int switches = 0;
            for (int i = 0; i < L; i++) {
                if (oparities[i] != 0 && oparities[i] == -dparities[i]) {
                    switches++;
                    for (int j = 0; j < N; j++) {
                        if (outlets[j][i] == '0') {
                            outlets[j][i] = '1';
                        } else {
                            outlets[j][i] = '0';
                        }
                    }
                } else if (oparities[i] != dparities[i]) {
                    out = "NOT POSSIBLE ";
                    break;
                }
            }
            if (out.length() == 0) {
                int n = switchEvens(outlets, devices, oparities, 0, switches);
                if (n == -1) {
                    out = "NOT POSSIBLE";
                } else {
                    out = "" + n;
                }
            }
            System.out.println("Case #" + (tc + 1) + ": " + out);
            pw.println("Case #" + (tc + 1) + ": " + out);
        }
        pw.close();
    }

    public static boolean check(char[][] outs, char[][] devs) {
        String[] outlets = new String[outs.length];
        String[] devices = new String[devs.length];
        for (int i = 0; i < outs.length; i++) {
            outlets[i] = new String(outs[i]);
            devices[i] = new String(devs[i]);
        }
        Arrays.sort(outlets);
        Arrays.sort(devices);
        for (int i = 0; i < outs.length; i++) {
            //System.out.println(outlets[i] + " " + devices[i]);
            if (!(outlets[i].equals(devices[i]))) {
                return false;
            }
        }
        return true;

    }

    public static int switchEvens(char[][] outlets, char[][] devices, int[] parities, int index, int switches) {

        if (check(outlets, devices)) {
            return switches;
        }

        if (index >= outlets[0].length) {
            return -1;
        }

        // no switch
        int n = switchEvens(outlets, devices, parities, index + 1, switches);

        // do the switch
        for (int i = 0; i < outlets.length; i++) {
            if (outlets[i][index] == '0') {
                outlets[i][index] = '1';
            } else {
                outlets[i][index] = '0';
            }
        }

        int m = switchEvens(outlets, devices, parities, index + 1, switches + 1);

        // unswitch
        for (int i = 0; i < outlets.length; i++) {
            if (outlets[i][index] == '0') {
                outlets[i][index] = '1';
            } else {
                outlets[i][index] = '0';
            }
        }
        if (n == -1)
            return m;
        if (m == -1)
            return n;
        return Math.min(n,m);
    }
}
