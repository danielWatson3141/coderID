import java.util.*;

public class GCJ2014A1 {
    static int[] initial;
    static int[] current;
    static int[] required;
    static int n, l;

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int k = 1; k <= t; k++) {
            n = sc.nextInt();
            l = sc.nextInt();
            initial = new int[n];
            for (int i = 0; i < n; i++) {
                initial[i] = Integer.parseInt(sc.next(), 2);
            }
            required = new int[n];
            for (int i = 0; i < n; i++) {
                required[i] = Integer.parseInt(sc.next(), 2);
            }
            Arrays.sort(required);
            System.out.println("Case #" + k + ": " + solve());
        }
    }

    private static String solve() {
        current = new int[n];
        int min = 1000;
        for (int mask = 0; mask < (1 << l); mask++) {
            for (int i = 0; i < n; i++) {
                current[i] = initial[i];
            }
            int count = 0;
            for (int i = 0; i < l; i++) {
                if ((mask & (1 << i)) > 0) {
                    flip(i);
                    count++;
                }
            }
            Arrays.sort(current);
            if (Arrays.equals(current, required)) {
                min = Math.min(min, count);
            }
        }
        if (min < 1000) {
            return Integer.toString(min);
        }
        return "NOT POSSIBLE";
    }

    private static void flip(int k) {
        for (int i = 0; i < n; i++) {
            current[i] = (current[i] ^ (1 << k));
        }
    }
}
