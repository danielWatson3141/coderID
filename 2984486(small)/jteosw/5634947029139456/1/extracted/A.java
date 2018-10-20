import java.util.*;
public class A {
    static Scanner s;
    public static void main(String[] args) {
        s = new Scanner(System.in);
        int n = s.nextInt();
        for (int i = 1; i <= n; i++) {
            System.out.printf("Case #%d: %s\n", i, solve());
        }
    }

    public static String solve() {
        int N = s.nextInt();
        int L = s.nextInt();
        Set<Long> socks = new HashSet<Long>();
        long[] devices = new long[N];
        for (int i = 0; i < N; i++) {
            socks.add(Long.parseLong(s.next(), 2));
        }
        for (int i = 0; i < N; i++) {
            devices[i] = Long.parseLong(s.next(), 2);
        }
        int min = 100;
        boolean pass = false;
        for (Long sock : socks) {
            long xor = sock ^ devices[0];
            boolean flag = true;
            for (int i = 0; i < N; i++) {
                if (!socks.contains(devices[i] ^ xor)) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                int count = countBits(xor);
                if (count < min) {
                    min = count;
                }
                pass = true;
            }
        }
        if (pass) {
            return "" + min;
        } else {
            return "NOT POSSIBLE";
        }

    }

    public static int countBits(long x) {
        int count = 0;
        while (x > 0) {
            if (x % 2 != 0) {
                count++;
            }
            x /= 2;
        }
        return count;
    }
}
