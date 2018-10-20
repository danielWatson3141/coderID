import java.io.*;
import java.util.HashSet;

/**
 * @author vilmantas baranauskas
 */
public class ChargingChaos {


    public static void main(String[] args) throws IOException {

        BufferedReader in = new BufferedReader(new FileReader("in.txt"));
        BufferedWriter out = new BufferedWriter(new FileWriter("out.txt"));

        // number of test cases
        int t = Integer.parseInt(in.readLine());

        for (int i = 0; i < t; i++) {
            CharSequence solution = "Case #" + (i + 1) + ": " + solveTestCase(in);
            System.out.println(solution);
            out.write(solution.toString());
            out.newLine();
        }

        in.close();
        out.close();

    }

    private static String solveTestCase(BufferedReader in) throws IOException {

        int[] config = readLineOfInts(in);

        int n = config[0];
        int l = config[1];

        char[][] outlets = readLineOfStringsAsChars(in);
        char[][] devices = readLineOfStringsAsChars(in);

        int[] sumsOutlets = new int[l];
        int[] sumsDevices = new int[l];
        for (int i = 0; i < n; i++) {
            char[] outlet = outlets[i];
            char[] device = devices[i];
            for (int j = 0; j < l; j++) {
                sumsOutlets[j] += Integer.parseInt("" + outlet[j]);
                sumsDevices[j] += Integer.parseInt("" + device[j]);
            }
        }

        for (int i = 0; i < sumsOutlets.length; i++) {
            int sumOutlet = sumsOutlets[i];
            int sumDevice = sumsDevices[i];
            if (sumDevice != sumOutlet && sumDevice != n - sumOutlet) {
                return "NOT POSSIBLE";
            }
        }

        HashSet<String> dSet = new HashSet<String>();
        for (int i = 0; i < outlets.length; i++) {
            dSet.add(new String(devices[i]));
        }

        int solution = findSolution(outlets, sumsOutlets, sumsDevices, 0, dSet, 0);
        if (solution >= 0) {
            return String.valueOf(solution);
        } else {
            return "NOT POSSIBLE";
        }

    }

    private static int findSolution(char[][] outlets, int[] sumsOutlets, int[] sumsDevices, int i, HashSet<String> dSet, int s) {

        if (i == sumsOutlets.length) {
            HashSet<String> oSet = new HashSet<String>();
            for (int j = 0; j < outlets.length; j++) {
                oSet.add(new String(outlets[j]));
            }
            if (oSet.equals(dSet)) {
                return s;
            } else {
                return Integer.MIN_VALUE;
            }
        }

        int s2 = findSolution(outlets, sumsOutlets, sumsDevices, i + 1, dSet, s);
        if (s2 >= 0) {
            return s2;
        } else {
            switchI(outlets, i);
            int solution = findSolution(outlets, sumsOutlets, sumsDevices, i + 1, dSet, s + 1);
            switchI(outlets, i);
            return solution;
        }

    }

    private static void switchI(char[][] outlets, int i) {
        for (char[] outlet : outlets) {
            if (outlet[i] == '0') {
                outlet[i] = '1';
            } else {
                outlet[i] = '0';
            }
        }
    }


    private static int[] readLineOfInts(BufferedReader in) throws IOException {
        String[] v1Str = in.readLine().split(" ");
        int[] items = new int[v1Str.length];
        for (int i = 0; i < v1Str.length; i++) {
            items[i] = Integer.parseInt(v1Str[i]);
        }
        return items;
    }

    private static char[][] readLineOfStringsAsChars(BufferedReader in) throws IOException {
        String[] v1Str = in.readLine().split(" ");
        char[][] items = new char[v1Str.length][];
        for (int i = 0; i < v1Str.length; i++) {
            items[i] = v1Str[i].toCharArray();
        }
        return items;
    }

}
