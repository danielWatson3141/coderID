import java.io.*;
import java.util.Random;

/**
 * @author vilmantas baranauskas
 */
public class ProperShuffle {

    final static Random r = new Random();

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


//        double dev = 0;
//        int fremd = 0;
//        for (int i = 0; i < 1000; i++) {
//            dev = dev + dev(bad(identity(1000)), 0, 1000);
//        }
//
//        System.out.println( dev / 1000);
//

    }

    private static int[] identity(int n) {
        int[] p = new int[n];
        for (int i = 0; i < p.length; i++) {
            p[i] = i;

        }
        return p;
    }

    private static String solveTestCase(BufferedReader in) throws IOException {

        int n = Integer.parseInt(in.readLine());

        int[] p = readLineOfInts(in);

        double dev = dev(p, 0, n);
        if (dev > n / 2.5) {
            return "GOOD";
        } else {
            return "BAD";
        }
    }

    private static String isGood(int[] permutation) {
        int n = permutation.length;
        double dev = fremd(permutation, 0, n / 2);
        double dev2 = fremd(permutation, n / 2, n);

        return dev + " - " + dev2 + " = " + (dev - dev2);
    }

    private static int[] good(int[] permutation) {
        int n = permutation.length;
        for (int i = 0; i < n; i++) {
            int v = permutation[i];
            int j = i + r.nextInt(n - i);

            permutation[i] = permutation[j];
            permutation[j] = v;
        }
        return permutation;
    }

    private static int[] bad(int[] permutation) {
        int n = permutation.length;
        for (int i = 0; i < n; i++) {
            int v = permutation[i];
            int j = r.nextInt(n);

            permutation[i] = permutation[j];
            permutation[j] = v;
        }
        return permutation;
    }

    private static double dev(int[] permutation, int from, int to) {
        double dev = 0;
        for (int i = from; i < to; i++) {
            int v = permutation[i];
            int d = i - v;
            dev += d*d;
        }

        int n = to - from;
        return Math.sqrt(dev / n);
    }

    private static double avgDist(int[] permutation, int from, int to) {
        double dev = 0;
        for (int i = from; i < to; i++) {
            int v = permutation[i];
            int d = i - v;
            dev += d;
        }

        int n = to - from;
        return dev / n;
    }

    private static int fremd(int[] permutation, int from, int to) {
        int fremd = 0;
        for (int i = from; i < to; i++) {
            int v = permutation[i];
            if (v < from || v > to) {
                fremd++;
            }
        }

        return fremd;
    }


    private static int[] readLineOfInts(BufferedReader in) throws IOException {
        String[] v1Str = in.readLine().split(" ");
        int[] items = new int[v1Str.length];
        for (int i = 0; i < v1Str.length; i++) {
            items[i] = Integer.parseInt(v1Str[i]);
        }
        return items;
    }

}
