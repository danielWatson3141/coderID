package codejam.problem.A;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class ProblemA {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long start = System.currentTimeMillis();

        int t = sc.nextInt();
        for (int q = 1; q <= t; q++) {
            int n = sc.nextInt();
            int l = sc.nextInt();
            Map<String, Integer> m = new HashMap<String, Integer>();
            char[][] o = new char[n][l];
            char[][] d = new char[n][l];
            for (int i = 0; i < n; i++) {
                o[i] = sc.next().toCharArray();
            }
            for (int i = 0; i < n; i++) {
                d[i] = sc.next().toCharArray();
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    String changes = "";
                    for (int k = 0; k < l; k++) {
                        if (o[i][k] != d[j][k]) {
                            changes += k + "-";
                        }
                    }
                    Integer p = m.get(changes);
                    m.put(changes, p == null ? 1 : p + 1);
                }
            }
            List<Integer> noOfChanges = new ArrayList<Integer>();
            for (String s : m.keySet()) {
                if (m.get(s) == n) {
                    if(!s.contains("-")){
                        noOfChanges.add(0);
                    }
                    noOfChanges.add(s.split("-").length);
                }
            }
            System.out.print("Case #"+q+": ");
            if (noOfChanges.isEmpty()) {
                System.out.println("NOT POSSIBLE");
            } else {
                Collections.sort(noOfChanges);
                System.out.println(noOfChanges.get(0));
            }
        }
        //System.out.printf("Time taken : %.5f minutes\n", (System.currentTimeMillis() - start) / 60000.0);
    }
}
