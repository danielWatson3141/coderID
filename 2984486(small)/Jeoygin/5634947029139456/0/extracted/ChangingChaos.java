package gcj14.round1a;

import java.util.BitSet;
import java.util.Scanner;

public class ChangingChaos {
    public void solve(Scanner scan) {
        int n = scan.nextInt();
        int l = scan.nextInt();
        String[] outlets = new String[n];
        String[] devices = new String[n];

        for (int i = 0; i < n; i++) {
            outlets[i] = scan.next();
        }

        for (int i = 0; i < n; i++) {
            devices[i] = scan.next();
        }

        int ans = 0;
        boolean[] used = new boolean[n];
        for (int i = 0; i < n; i++) {
            boolean found = false;
            for (int j = 0; j < n && !found; j++) {
                if (!used[j] && devices[i].equals(outlets[j])) {
                    found = true;
                    used[j] = true;
                    break;
                }
            }
            for (int j = 0; j < n && !found; j++) {
                char[] chars = outlets[i].toCharArray();
                for (int k = 0; k < chars.length; k++) {
                    chars[k] = (char)('1' - chars[k] + '0');
                }
                String flipped = new String(chars);
                if (!used[j] && devices[i].equals(flipped)) {
                    found = true;
                    used[j] = true;
                    ans++;
                    break;
                }
            }
            if (!found) {
                // System.out.println("NOT POSSIBLE");
                // return;
            }
        }

        int res = 100000;
        for (int mask = (1 << n) - 1; mask >= 0; mask --) {
            int cnt = 0;
            boolean stop = false;
            for (int i = 0; i < n; i++) {
                String flow = outlets[i];
                if ((mask & (1 << i)) > 0) {
                    cnt ++;
                    flow = flip(flow);
                }
                boolean found = false;
                for (int j = 0; j < n; j++) {
                    if (devices[j].equals(flow)) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    stop = true;
                    break;
                }
            }
            if (!stop) {
                if (cnt < res) {
                    res = cnt;
                }
            }
        }

        if (res > n) {
            System.out.println("NOT POSSIBLE");
        } else {
            System.out.println(res);
        }
    }

    public String flip(String flow) {
        char[] chars = flow.toCharArray();
        for (int k = 0; k < chars.length; k++) {
            chars[k] = (char)('1' - chars[k] + '0');
        }
        return new String (chars);
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int t = scan.nextInt();
        ChangingChaos solver = new ChangingChaos();
        for (int i = 1; i <= t; i++) {
            System.out.printf("Case #%d: ", i);
            solver.solve(scan);
        }
    }
}
