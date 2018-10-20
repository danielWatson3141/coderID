import java.util.Arrays;
import java.util.Scanner;

public class TaskA {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int tests = scanner.nextInt();
        for (int test = 1; test <= tests; test++) {
            int n = scanner.nextInt();
            scanner.nextInt();

            String[] has = new String[n];
            for (int i = 0; i < n; i++) {
                has[i] = scanner.next();
            }

            String[] required = new String[n];
            for (int i = 0; i < n; i++) {
                required[i] = scanner.next();
            }

            System.out.println("Case #" + test + ": " + solve(has, required));
        }

        scanner.close();
    }

    private static String solve(String[] has, String[] required) {
        int l = has[0].length();

        Arrays.sort(required);

        int result = Integer.MAX_VALUE;

        for (int mask = 0; mask < (1 << l); mask++) {
            if (ok(has, required, mask)) {
                result = Math.min(result, Integer.bitCount(mask));
            }
        }

        if (result < Integer.MAX_VALUE) {
            return result + "";
        } else {
            return "NOT POSSIBLE";
        }
    }

    private static boolean ok(String[] has, String[] required, int mask) {
        int n = has.length;
        int l = has[0].length();
        String[] a = new String[n];

        for (int i = 0; i < n; i++) {
            StringBuilder s = new StringBuilder(has[i]);
            for (int j = 0; j < l; j++) {
                if ((mask & (1 << j)) != 0) {
                    s.setCharAt(j, invert(s.charAt(j)));
                }
            }
            a[i] = s.toString();
        }

        Arrays.sort(a);

        for (int i = 0; i < n; i++) {
            if (!a[i].equals(required[i])) {
                return false;
            }
        }

        return true;
    }

    private static char invert(char c) {
        if (c == '0') {
            return '1';
        } else if (c == '1') {
            return '0';
        } else {
            throw new IllegalStateException();
        }
    }
}
