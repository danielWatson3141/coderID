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
        int n = has.length;

        long[][] a = new long[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = getMask(has[i], required[j]);
            }
        }

        int result = Integer.MAX_VALUE;

        for (int i = 0; i < n; i++) {
            long mask = a[0][i];

            boolean allHasMasks = true;

            for (int j = 1; j < n; j++) {
                boolean hasMask = false;
                for (int k = 0; k < n; k++) {
                    if (a[j][k] == mask) {
                        hasMask = true;
                        break;
                    }
                }

                if (!hasMask) {
                    allHasMasks = false;
                    break;
                }
            }

            if (allHasMasks) {
                result = Math.min(result, Long.bitCount(mask));
            }
        }

        if (result < Integer.MAX_VALUE) {
            return result + "";
        } else {
            return "NOT POSSIBLE";
        }
    }

    private static long getMask(String a, String b) {
        int l = a.length();

        long result = 0;

        for (int i = 0; i < l; i++) {
            if (a.charAt(i) != b.charAt(i)) {
                result |= (1L << i);
            }
        }

        return result;
    }
}
