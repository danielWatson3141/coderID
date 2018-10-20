import java.io.File;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Locale;
import java.util.Scanner;

/**
 * @author Alexander Gulko
 */
public class ProblemA {

    private static int n;
    private static int l;

    public static void main(String[] args) throws Exception {
        Locale.setDefault(Locale.US);

        String file = "A-small-attempt1";

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

        int[] flows = new int[n];
        for (int i = 0; i < n; ++i) {
            String str = scan.next("\\d+");
            flows[i] = Integer.parseInt(str, 2);
        }

        int[] devices = new int[n];
        for (int i = 0; i < n; ++i) {
            String str = scan.next("\\d+");
            devices[i] = Integer.parseInt(str, 2);
        }
        //Arrays.sort(devices);

        int best = l + 1;
        for (int k = 0; k < 1 << l; ++k) {
            if (check(flows.clone(), devices, k)) {
                int count = Integer.bitCount(k);
                if (count < best) {
                    best = count;
                    if (best == 0) {
                        break;
                    }
                }
            }
        }

        if (best <= l) {
            System.out.printf("Case #%s: %s\n", test, best);
        } else {
            System.out.printf("Case #%s: %s\n", test, "NOT POSSIBLE");
        }
    }

    static boolean check(int[] flows, int[] arrDevices, int bits) {
        List<Integer> devices = new ArrayList<Integer>();
        for (int device : arrDevices) {
            devices.add(device);
        }

        for (int i = 0; i < n; ++i) {
            for (int k = 0; k < l; ++k) {
                int bit = (1 << k) & bits;
                if (bit != 0) {
                    // flip
                    flows[i] ^= bit;
                }
            }
            devices.remove((Integer) flows[i]);
        }

        return devices.isEmpty();
    }
}
