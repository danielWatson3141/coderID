import java.io.File;
import java.io.PrintStream;
import java.util.Locale;
import java.util.Scanner;

/**
 * @author Alexander Gulko
 */
public class ProblemALarge {

    private static int n;
    private static int l;
    private static char[][] flows;
    private static char[][] devices;

    public static void main(String[] args) throws Exception {
        Locale.setDefault(Locale.US);

        String file = "A-large";
//        String file = "problem-a-test";

        String inFile = file + ".in";
        System.setOut(new PrintStream(file + ".out"));

        Scanner scan = new Scanner(new File(inFile));

        int tests = scan.nextInt();
        for (int test = 1; test <= tests; ++test) {
            solve(test, scan);
        }

        scan.close();
    }

    static void solve(int test, Scanner scan) {
        n = scan.nextInt();
        l = scan.nextInt();

        flows = new char[n][l];
        for (int i = 0; i < n; ++i) {
            String str = scan.next("\\d+");
            flows[i] = str.toCharArray();
            /*for (int k = 0; k < l; ++k) {
                devices[i][k] -= '0';
            }*/
        }

        devices = new char[n][l];
        for (int i = 0; i < n; ++i) {
            String str = scan.next("\\d+");
            devices[i] = str.toCharArray();
            /*for (int k = 0; k < l; ++k) {
                devices[i][k] -= '0';
            }*/
        }

        // sort
        sort(flows);
        sort(devices);

        //System.out.println(Arrays.deepToString(devices));

        int best = tryPos(0);
        if (best <= l) {
            System.out.printf("Case #%s: %s\n", test, best);
        } else {
            System.out.printf("Case #%s: %s\n", test, "NOT POSSIBLE");
        }
    }

    static int tryPos(int pos) {
        if (pos == l) {
            return 0;
        }

        int fbits = 0;
        int dbits = 0;
        for (int i = 0; i < n; ++i) {
            if (flows[i][pos] == '1') {
                ++fbits;
            }
            if (devices[i][pos] == '0') {
                ++dbits;
            }
        }

        if (fbits == dbits || fbits == (n - dbits)) {
            int c = l + 1;

            sort(flows);
            int i;
            for (i = 0; i < n; ++i) {
                if (devices[i][pos] != flows[i][pos]) {
                    break;
                }
            }
            if (i == n) {
                // ok
                return tryPos(pos + 1);
            }

            // flip
            for (i = 0; i < n; ++i) {
                if (flows[i][pos] == '0') {
                    flows[i][pos] = '1';
                } else {
                    flows[i][pos] = '0';
                }
            }
            sort(flows);
            for (i = 0; i < n; ++i) {
                if (devices[i][pos] != flows[i][pos]) {
                    break;
                }
            }
            if (i == n) {
                return 1 + tryPos(pos + 1);
            }

            return l + 1;
        } else {
            return l + 1;
        }
    }

    public static void sort(char[][] a) {
        int N = a.length;
        int R = 100;
        char[][] aux = new char[N][l];
        for (int d = l - 1; d >= 0; d--) {
            int[] count = new int[R + 1];
            for (int i = 0; i < N; i++)
                count[a[i][d] + 1]++;
            for (int r = 0; r < R; r++)
                count[r + 1] += count[r];
            for (int i = 0; i < N; i++)
                aux[count[a[i][d]]++] = a[i];
            for (int i = 0; i < N; i++)
                a[i] = aux[i];
        }
    }
}
