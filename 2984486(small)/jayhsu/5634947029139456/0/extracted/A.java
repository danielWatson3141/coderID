import java.util.HashSet;
import java.util.Iterator;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

public class A {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int t = 1; t <= T; t++) {
            int N = in.nextInt();
            int L = in.nextInt();

            Set<Integer> s1 = new HashSet<Integer>();
            Set<Integer> s2 = new HashSet<Integer>();

            for (int i = 0; i < N; i++)
                s1.add(Integer.parseInt(in.next(), 2));
            for (int i = 0; i < N; i++)
                s2.add(Integer.parseInt(in.next(), 2));
            TreeSet<Integer> left = new TreeSet<Integer>();
            for (int i = 0; i < Math.pow(2, L); i++) {
                int ret = swit(i, s1, s2);
                left.add(ret);
            }
            left.remove(new Integer(-1));
            if (!left.isEmpty())
                System.out.printf("Case #%d: %d%n", t, count(left.first()));
            else
                System.out.printf("Case #%d: NOT POSSIBLE%n", t);

        }
    }

    static int swit(Integer in, Set<Integer> device, Set<Integer> out) {
        Iterator<Integer> itr = out.iterator();
        HashSet<Integer> s3 = new HashSet<Integer>();
        int ret = -1;
        while (itr.hasNext()) {
            Integer o = itr.next();
            s3.add(o ^ in);
        }
        itr = device.iterator();
        while (itr.hasNext()) {
            s3.remove(itr.next());
        }

        if (s3.isEmpty())
            ret = in;

        return ret;
    }

    static int count(Integer i) {
        String s = i.toBinaryString(i);
        s= s.replace("0", "");
        return s.length();
    }
}
