import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.*;

/**
 * by dt on 4/25/14, 5:38 PM
 */
public class A {
    public static void main(String[] args) throws FileNotFoundException {
//        Scanner sc = new Scanner(System.in);
//        PrintWriter pw = new PrintWriter(System.out);
        Scanner sc = new Scanner(new File("./GCJ14R1/A-small-attempt0.in"));
        PrintWriter pw = new PrintWriter(new File("./GCJ14R1/A-small-attempt0.out"));
        int T = sc.nextInt();
        for(int t = 1; t <= T; t ++) {
            int n = sc.nextInt();
            int l = sc.nextInt();
            sc.nextLine();
            String[] dev = sc.nextLine().split(" ");
            String[] outlets = sc.nextLine().split(" ");

            int res = minSwitch(dev, outlets, l);
            pw.println("Case #" + t + ": " + (res != -1 ? res : "NOT POSSIBLE"));
            pw.flush();
        }
    }

    private static int minSwitch(String[] dev, String[] outlets, int l) {
        int res = -1;
        Set<String> v = new HashSet<String>();
        Queue<String> q = new LinkedList<String>();
        String start = "";
        for (int i = 0; i < l; i ++) {
            start += '0';
        }

        v.add(start);
        q.add(start);

        char[][] outlets2 = new char[outlets.length][l];
        int c = 0;
        for (String o : outlets) {
            outlets2[c] = o.toCharArray();
            c ++;
        }
        Set<String> devc = new HashSet<String>(Arrays.asList(dev));

        while (!q.isEmpty()) {
            String s = q.poll();
            Set<String> o = combine(outlets2, s);
            if (o.containsAll(devc)) {
                res = diff(s, start);
                q.clear();
            } else {
                for (String m : permute(s)) {
                    if (!v.contains(m)) {
                        v.add(m);
                        q.add(m);
                    }
                }
            }
        }
        return res;
    }

    private static Set<String> combine(char[][] outlets, String s) {
        char[][] res = new char[outlets.length][s.length()];
        char[] sa = s.toCharArray();

        for (int i = 0; i < sa.length; i ++) {
            for (int j = 0; j < res.length; j ++) {
                if (sa[i] == '0') {
                    res[j][i] = outlets[j][i];
                } else {
                    res[j][i] = invert(outlets[j][i]);
                }
            }
        }

        Set<String> res2 = new HashSet<String>();
        for (char[] r : res) {
            res2.add(new String(r));
        }
        return res2;
    }

    private static char invert(char c) {
        if (c == '0') {
            c = '1';
        } else  {
            c = '0';
        }
        return c;
    }

    private static String[] permute(String s) {
        String[] m = new String[s.length()];

        for (int i = 0; i < s.length(); i ++) {
            char[] a = s.toCharArray();
            a[i] = invert(a[i]);
            m[i] = new String(a);
        }
        return m;
    }

    private static int diff(String s, String start) {
        int c = 0;
        for (int i = 0; i < s.length(); i ++) {
            if (s.charAt(i) != start.charAt(i)) {
                c ++;
            }
        }
        return c;
    }

}