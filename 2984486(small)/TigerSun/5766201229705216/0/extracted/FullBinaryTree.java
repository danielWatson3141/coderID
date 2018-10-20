import java.util.BitSet;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.Scanner;

/**
 * FileName: FullBinaryTree.java
 * @Description:
 * 
 * @author Xunhu(Tiger) Sun
 *         email: sunx2013@my.fit.edu
 * @date Apr 25, 2014 10:23:58 PM
 */
public class FullBinaryTree {
    public static void main (final String[] args) {
        final Scanner s = new Scanner(System.in);
        final int tc = s.nextInt();
        s.nextLine();
        for (int tci = 1; tci <= tc; tci++) {
            final int n = s.nextInt();
            s.nextLine();
            final BitSet[] g = new BitSet[n];
            for (int ni = 0; ni < n; ni++) {
                g[ni] = new BitSet(n);
            }

            for (int ni = 0; ni < n-1; ni++) {
                final int x = s.nextInt() - 1;
                final int y = s.nextInt() - 1;
                s.nextLine();
                g[x].set(y);
                g[y].set(x);
                
            }
            int max = 0;
            for (int ni = 0; ni < n; ni++) {
                final int temp = checkFromRoot(g, ni);
                if (max < temp) {
                    max = temp;
                }
            }

            System.out.printf("Case #%d: %d%n", tci, n - max);
        }
        s.close();
    }

    private static int checkFromRoot (BitSet[] g, int father) {
        if (g[father].cardinality() == 0) {
            return 0;
        }

        if (g[father].cardinality() == 1) {
            return 1;
        }
        // >=2
        final PriorityQueue<Integer> que = new PriorityQueue<Integer>(g.length, Collections.reverseOrder());
        for (int i = g[father].nextSetBit(0); i >= 0; i = g[father].nextSetBit(i+1)) {
            final int d = check(g, i, father);
            que.add(d);
        }
        int sum = 1;
        sum+= que.remove();
        sum+= que.remove();
        return sum;
    }

    private static int check (BitSet[] g, int self, int father) {
        if (g[self].cardinality() == 1) {
            return 1;
        }
        if (g[self].cardinality() == 2) {
            return 1;
        }
        // >=3
        final PriorityQueue<Integer> que = new PriorityQueue<Integer>(g.length, Collections.reverseOrder());
        for (int i = g[self].nextSetBit(0); i >= 0; i = g[self].nextSetBit(i+1)) {
            if (i != father){
                final int d = check(g, i, self);
                que.add(d);
            }
        }
        int sum = 1;
        sum+= que.remove();
        sum+= que.remove();
        return sum;
    }
}
