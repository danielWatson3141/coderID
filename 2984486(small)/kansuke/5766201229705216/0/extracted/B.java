/**
 * Created by zwh on 4/25/14.
 */
import java.io.*;
import java.util.*;

public class B {
    static Scanner scan = new Scanner (System.in);
    static PrintStream out = System.out;

    private static void test () {
        int N = scan.nextInt();

        ArrayList<Set<Integer>> neighbor = new ArrayList<Set<Integer>>();

        for (int i = 0; i < N; ++i)
            neighbor.add(new HashSet<Integer>());

        for (int i = 0; i < N - 1; ++i) {
            int x1 = scan.nextInt() - 1, y1 = scan.nextInt() - 1;
            neighbor.get(x1).add(y1);
            neighbor.get(y1).add(x1);
        }

        int min = Integer.MAX_VALUE;
        for (int i = 0; i < N; ++i) {
            int r = i;

            if (neighbor.get(r).size() == 1) {
                min = Math.min(min, N - 1);
                continue;
            }

            int[] delete = new int[N];
            int[] count = new int[N];
            int[] parent = new int[N];
            Arrays.fill (delete, 0);
            Arrays.fill (count, 0);
            Arrays.fill (parent, -1);
            LinkedList<Integer> stack1 = new LinkedList<Integer>();
            LinkedList<Boolean> stack2 = new LinkedList<Boolean>();
            stack1.addLast(r);
            stack2.addLast(false);

            while (!stack1.isEmpty()) {
                int idx = stack1.removeLast();
                boolean check = stack2.removeLast();

                if (check == false) {
                    stack1.addLast(idx);
                    stack2.addLast(true);
                    for (int nei : neighbor.get(idx)) {
                        if (nei != r && parent[idx] != nei) {
                            parent[nei] = idx;
                            stack1.addLast(nei);
                            stack2.addLast (false);
                        }
                    }
                    continue;
                }

                // check = true.
                if (neighbor.get(idx).size() == 1) {
                    // idx is child.
                    delete[idx] = 0;
                    count[idx] = 1;
                    continue;
                }

                if (neighbor.get(idx).size() == 2 && idx != r) {
                    for (int nei : neighbor.get(idx)) {
                        if (parent[idx] != nei) {
                            delete[idx] += count[nei];
                            count[idx] = count[nei] + 1;
                        }
                    }
                    continue;
                }

                ArrayList<Integer> al = new ArrayList<Integer>();
                for (int nei : neighbor.get(idx)) {
                    if (nei != r && parent[idx] != nei) {
                        al.add(count[nei] - delete[nei]);
                        count[idx] += count[nei];
                    }
                }

                Collections.sort (al);
                int reserve = al.get(al.size() - 1) + al.get(al.size() - 2);
                delete[idx] = count[idx] - reserve;
                ++count[idx];
            }

            min = Math.min (min, delete[r]);

        }

        out.println (min);

    }

    public static void main (String[] args) throws Exception {
        int T = scan.nextInt();

        for (int i = 1; i <= T; ++i) {
            out.print ("Case #" + i + ": ");
            test ();
        }
    }

}
