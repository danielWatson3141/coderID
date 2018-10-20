import java.io.File;
import java.util.Formatter;
import java.util.Scanner;

public class C {
    private static final String ANS = "Case #%s: %s\n";
    private static final String GOOD = "GOOD";
    private static final String BAD = "BAD";

    public static void main(String[] args) throws Exception {
        try (Scanner in = new Scanner(new File("io/C/Cs.in.txt")); Formatter out = new Formatter("io/C/Cs.out.txt")) {
            int tests = in.nextInt();
            for (int i = 1; i <= tests; ++i) {
                new C().solve(i, in, out);
            }
        }
    }

    private void solve(int testNo, Scanner in, Formatter out) {
        int n = in.nextInt();
        int d = 0;
        int[] elems = new int[n];
        for (int i = 0; i < n; ++i) {
            elems[i] = in.nextInt();
        }

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (elems[i] < elems[j]) {
                    d++;
                }
            }
        }

        out.format(ANS, testNo, d > 250000 ? BAD : GOOD);
    }
}
