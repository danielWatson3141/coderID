/*
 * CodeJam 2014
 * Round 1A 4/25/2014
 */
package jam.y2014.r1a;

/**
 *
 * @author shiryap
 */
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
import java.util.Arrays;

public class A {

    static Scanner in;
    static PrintStream out;
    static final String filepath = System.getProperty("user.dir") + "//src//jam//y2014//r1a//A-small-attempt1.in";

    public static void main(String[] args) throws FileNotFoundException {
        System.out.println(filepath);
        in = new Scanner(new File(filepath));
        out = new PrintStream(new File(filepath + ".out"));

        int T = in.nextInt();
        int t = 0;
        while (t++ < T) {
            int N = in.nextInt();
            int L = in.nextInt();
            in.nextLine();

            int ll = (int) Math.pow(2, L);
            System.out.println("Case #" + t + "  N = " + N + "  L = " + L + "   LL = " + ll);
            int f1[] = new int[N];
            int f2[] = new int[N];
            readFlow(f1);
            readFlow(f2);

            Arrays.sort(f1);
            Arrays.sort(f2);
            System.out.println(Arrays.toString(f1));
            //System.out.println(Arrays.toString(f2));
            //System.out.print(0+ "  "); display(f1);
            int sol = -1;
            for (int l = 0; l < ll; l++) {
                int f[] = new int[N];
                for (int i = 0; i < f1.length; i++) {
                    f[i] = f1[i] ^ l;
                }

                //System.out.print(l+ "  "); display(f);
                Arrays.sort(f);

                if (Arrays.equals(f, f2)) {
                    sol = l;
                    break;
                }
            }

            out.print("Case #" + t + ": ");
            if (sol == -1) {
                out.println("NOT POSSIBLE");
                System.out.println("NOT POSSIBLE");
            } else {
                out.println(Long.bitCount(sol));
                System.out.println(Long.bitCount(sol));
            }

        }

        in.close();
        out.close();

    }

    public static void display(int b[]) {
        for (int i : b) {
            System.out.print(Integer.toBinaryString(i) + " ");
        }

        System.out.println();
    }

    public static void readFlow(int n[]) {
        String s[] = in.nextLine().split(" ");
        for (int i = 0; i < s.length; i++) {
            String ss = s[i];
            n[i] = 0;
            int r = 1;
            for (int j = ss.length() - 1; j >= 0; j--) {
                n[i] += ss.charAt(j) == '1' ? r : 0;
                r *= 2;

            }

        }

    }

}
