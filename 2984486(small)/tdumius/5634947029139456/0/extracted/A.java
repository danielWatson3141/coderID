import java.io.File;
import java.util.ArrayList;
import java.util.Formatter;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class A {
    private static final String ANS = "Case #%s: %s\n";
    private static final String IMPOSSIBLE = "NOT POSSIBLE";

    public static void main(String[] args) throws Exception {
        try (Scanner in = new Scanner(new File("io/A/As.in.txt")); Formatter out = new Formatter("io/A/As.out.txt")) {
            int tests = in.nextInt();
            for (int i = 1; i <= tests; ++i) {
                new A().solve(i, in, out);
            }
        }
    }

    private void solve(int testNo, Scanner in, Formatter out) {
        int n = in.nextInt();
        in.nextInt();
        List<String> initial = nextCfgs(n, in);
        Set<String> required = new HashSet<>(nextCfgs(n, in));
        String to = required.iterator().next();

        int min = Integer.MAX_VALUE;
        for (String from : initial) {
            int cost = cost(from, to);
            if (min > cost) {
                List<String> fin = transform(initial, from, to);
                if (required.containsAll(fin)) {
                    min = cost;
                }
            }

        }

        out.format(ANS, testNo, min == Integer.MAX_VALUE ? IMPOSSIBLE : min);
    }

    private List<String> transform(List<String> cfgs, String from, String to) {
        List<String> ret = new ArrayList<>(from.length());
        for (String cfg : cfgs) {
            ret.add(transform(cfg, from, to));
        }
        return ret;
    }

    private String transform(String cfg, String from, String to) {
        char[] ret = new char[cfg.length()];
        for (int i = 0; i < cfg.length(); ++i) {
            char c = cfg.charAt(i);
            if (from.charAt(i) != to.charAt(i)) {
                c = (char) ('0' + ((c - '0' + 1) % 2));
            }
            ret[i] = c;
        }
        return new String(ret);
    }

    private int cost(String a, String b) {
        int cost = 0;
        for (int i = 0; i < a.length(); ++i) {
            if (a.charAt(i) != b.charAt(i)) {
                cost++;
            }
        }
        return cost;
    }

    private List<String> nextCfgs(int n, Scanner in) {
        List<String> cfgs = new ArrayList<>(n);
        for (int i = 0; i < n; ++i) {
            cfgs.add(in.next());
        }
        return cfgs;
    }
}
