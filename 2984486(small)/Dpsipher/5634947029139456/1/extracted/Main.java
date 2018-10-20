import java.io.File;
import java.io.FileInputStream;
import java.io.InputStream;
import java.util.*;

/**
 * Codejam 2014
 * User: maurya
 * Date: 26/4/14
 * Time: 12:00 AM
 */
public class Main {
    private static List<Long> conf0, conf1;
    private static Map<Long,Integer> index;
    private static int l;
    private static int solve(long seq) {
        boolean m[] = new boolean[conf0.size()];
        Arrays.fill(m,false);
        for (int i = 0; i < conf0.size(); i++) {
            long key = conf0.get(i)^seq;
            if (index.containsKey(key) && m[index.get(key)] == false) {
                m[index.get(key)] = true;

            } else {
                return Integer.MAX_VALUE;
            }
        }
        int res = 0;
        for (int i = 0; i < l; i++) {
            if ((seq & (1l<<i)) != 0) {
                res++;
            }

        }
        return res;
    }
    public static void main(String args[]) throws Exception {

        InputStream is = System.in;
        if (args != null && args.length > 0 && args[0] != null) {
            is = new FileInputStream(new File(args[0]));
        }
        Scanner in = new Scanner(is);
        int _tests = in.nextInt();
        for (int _t = 1; _t <= _tests; _t++) {
            System.out.print("Case #" + _t + ": ");
            int n = in.nextInt();  l = in.nextInt();
            index = new HashMap<Long, Integer>();
            conf0 = new ArrayList<Long>();
            for (int  i = 0 ; i < n; i++) {
                conf0.add(Long.parseLong(in.next(),2));

            }
            conf1 = new ArrayList<Long>();
            for (int  i = 0 ; i < n; i++) {
                conf1.add(Long.parseLong(in.next(),2));
                index.put(conf1.get(i), i);
            }
            int res = Integer.MAX_VALUE;
            //for (long conf = 0; conf <= (1l<<(l+1)); conf++) {
            for (int j = 0; j < n; j++) {
                for (int i = 0;i < n; i++)
                    res = Math.min(res,solve(conf0.get(i)^conf1.get(j)));

            }
            if (res == Integer.MAX_VALUE) {
                System.out.println("NOT POSSIBLE");

            } else {
                System.out.println(res);
            }

        }

    }
}

