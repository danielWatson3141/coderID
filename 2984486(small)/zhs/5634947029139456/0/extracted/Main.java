
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

/**
 *
 * @author zhs
 */
public class Main {

    private static StringBuffer get(CharSequence cs, ArrayList<Integer> list) {
        StringBuffer res = new StringBuffer();
        StringBuffer t = new StringBuffer();
        for (int i = 0; i < cs.length(); i++) {
            if (list.contains(i)) {
                t.append(cs.charAt(i));
            } else {
                res.append(cs.charAt(i));
            }
        }
        res.append(t);
        return res;
    }
    private static int n;
    private static int l;

    private static boolean cmp(StringBuffer[] a, String[] bs) {
        String[] as = new String[n];
        for (int i = 0; i < n; i++) {
            as[i] = a[i].toString();
        }
        Arrays.sort(as);
        for (int i = 0; i < n; i++) {
            if (!as[i].equals(bs[i])) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) throws FileNotFoundException {
        System.setIn(new FileInputStream(
                "/home/zhs/file/code/codejam/20140426/A-small-attempt2.in"));
        System.setOut(new PrintStream(
                "/home/zhs/file/code/codejam/20140426/A-small-attempt2.out"));
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        for (int cs = 1; cs <= t; cs++) {
            System.out.print("Case #" + cs + ": ");
            n = scanner.nextInt();
            l = scanner.nextInt();
            StringBuffer[] a = new StringBuffer[n];
            int[] an = new int[l];
            for (int i = 0; i < n; i++) {
                a[i] = new StringBuffer(scanner.next());
                for (int j = 0; j < l; j++) {
                    if (a[i].charAt(j) == '1') {
                        an[j]++;
                    }
                }
            }
            String[] bs = new String[n];
            int[] bn = new int[l];
            for (int i = 0; i < n; i++) {
                bs[i] = scanner.next();
                for (int j = 0; j < l; j++) {
                    if (bs[i].charAt(j) == '1') {
                        bn[j]++;
                    }
                }
            }
            boolean flag = true;
            int c = 0;
            ArrayList<Integer> list = new ArrayList<>();
            for (int j = 0; j < l; j++) {
                if (an[j] != bn[j] && an[j] + bn[j] != n) {
                    flag = false;
                    break;
                }
                if (an[j] + bn[j] == n && an[j] != bn[j]) {
                    for (int i = 0; i < n; i++) {
                        a[i].setCharAt(j, a[i].charAt(j) == '0' ? '1' : '0');
                    }
                    c++;
                }
                if (an[j] + bn[j] == n && an[j] == bn[j]) {
                    list.add(j);
                }
            }
            if (!flag) {
                System.out.println("NOT POSSIBLE");
                continue;
            }
            for (int i = 0; i < n; i++) {
                a[i] = get(a[i], list);
                bs[i] = get(bs[i], list).toString();
            }
            Arrays.sort(bs);

            int min = Integer.MAX_VALUE;
            for (int k = 0; k < 1 << list.size(); k++) {
                for (int j = 0; j < list.size(); j++) {
                    if ((k & (1 << j)) != 0) {
                        for (int i = 0; i < n; i++) {
                            a[i].setCharAt(l - list.size() + j, a[i].charAt(l - list.size() + j) == '0' ? '1' : '0');
                        }
                    }
                }
                if (cmp(a, bs)) {
                    min = Math.min(Integer.bitCount(k), min);
                }
                for (int j = 0; j < list.size(); j++) {
                    if ((k & (1 << j)) != 0) {
                        for (int i = 0; i < n; i++) {
                            a[i].setCharAt(l - list.size() + j, a[i].charAt(l - list.size() + j) == '0' ? '1' : '0');
                        }
                    }
                }
            }
            if (min != Integer.MAX_VALUE) {
                System.out.println(c + min);
            } else {
                System.out.println("NOT POSSIBLE");
            }
        }
    }
}
