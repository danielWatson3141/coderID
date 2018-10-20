package gcj2014.round1A;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.*;

/**
 * Created by khabat95 on 26/04/14.
 */
public class a {

    public static int rec(int N, int L, String[] o, String[] d, int pos, int changed) {
        if (pos == L) {
            Vector<String> v = new Vector<String>();
            v.addAll(Arrays.asList(o));
            for (int i=0; i<N; ++i) {
                if (!v.contains(d[i])) {
                    return L+1;
                }
                v.remove(d[i]);
            }
            return changed;
        }
        int res = rec(N, L, o, d, pos+1, changed);
        String[] oc = new String[N];
        for (int i=0; i<N; ++i) {
            String str = o[i];
            char[] c_str = str.toCharArray();
            c_str[pos] = (c_str[pos] == '0') ? '1' :'0';
            oc[i] = new String(c_str);
        }
        return Math.min(res, rec(N, L, oc, d, pos+1, changed+1));
    }

    public static String alg(int N, int L, String[] o, String[] d) {
        int res = rec(N, L, o, d, 0, 0);
        if (res > L)
            return "NOT POSSIBLE";
        return String.valueOf(res);
    }

    public static void main(String args[]) {
        try {
            Scanner sc = new Scanner(new FileReader("/home/khabat95/gcj2014/round1A/a1.in"));
            PrintWriter pw = new PrintWriter("/home/khabat95/gcj2014/round1A/a1.out");

            int T = sc.nextInt();
            for (int i = 0; i < T; i++) {
                int N = sc.nextInt();
                int L = sc.nextInt();
                String[] outlets = new String[N];
                for (int j=0; j<N; ++j) {
                    outlets[j] = sc.next();
                }
                String[] devices = new String[N];
                for (int j=0; j<N; ++j) {
                    devices[j] = sc.next();
                }
                System.out.println("Test case " + (i + 1) + "...");
                pw.println("Case #" + (i + 1) + ": " + alg(N, L, outlets, devices));
            }

            pw.flush();
            pw.close();
            sc.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }
}
