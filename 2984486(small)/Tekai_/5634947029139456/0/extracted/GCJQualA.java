/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package gcj20141a;

import java.io.*;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author greg
 */
public class GCJQualA {

    public static void main(String[] args) {
        GCJQualA g = new GCJQualA();
        g.run();
    }

    private void run() {
        Scanner br = null;
        BufferedWriter bw;

        try {
            br = new Scanner(new File("src/gcj20141a/A-small-practice.in"));
            bw = new BufferedWriter(new FileWriter("src/gcj20141a/A-small-output.txt"));
//            bw = new BufferedWriter(new OutputStreamWriter(System.out));

            int numTests = br.nextInt();
            for (int i = 0; i < numTests; i++) {
                int N = br.nextInt();
                int L = br.nextInt();

                int[] flow = new int[N];
                int[] needs = new int[N];

                for (int j = 0; j < N; j++) {
                    flow[j] = Integer.parseInt(br.next(), 2);
                }

                for (int j = 0; j < N; j++) {
                    needs[j] = Integer.parseInt(br.next(), 2);
                }

                String answer = solvePuzzle(N, L, flow, needs);

                bw.write("Case #" + (i + 1) + ": ");
                bw.write(answer);
                bw.newLine();
            }
            bw.close();
        } catch (IOException ex) {
            Logger.getLogger(this.getClass().getName()).log(Level.SEVERE, null, ex);
        } finally {
            try {
                if (br != null) {
                    br.close();
                }
            } catch (Exception ex) {
                Logger.getLogger(this.getClass().getName()).log(Level.SEVERE, null, ex);
            }
        }

    }

    private String solvePuzzle(int N, int L, int[] flow, int[] needs) {
        String answer;

        int[] flow2 = new int[N];

        int count = 0;

        Set<Integer> possible = new HashSet<>();

        List<Integer> flowList = new ArrayList<>();
        List<Integer> needList = new ArrayList<>();
        for (int index = 0; index < N; index++) {
            flowList.add(flow[index]);
            needList.add(needs[index]);
        }

        if (!check(flowList, needList)) {
            count = -1;
            for (int i = 0; i < Math.pow(2, L); i++) {
                for (int j = 0; j < N; j++) {
                    flow2[j] = flow[j] ^ i;
                }
                flowList.clear();
                for (int index = 0; index < N; index++) {
                    flowList.add(flow2[index]);
                }
                if (check(flowList, needList)) {
                    possible.add(i);
                }
            }
        }

        if (!possible.isEmpty()) {
            count = -1;
            for (Integer eachAnswer : possible) {
                int bitCount = Integer.bitCount(eachAnswer);
                if (count < 0 || bitCount < count) {
                    count = bitCount;
                }
            }
        }
        if (count >= 0) {
            answer = "" + count;
        } else {
            answer = "NOT POSSIBLE";
        }
        return answer;
    }

    private boolean check(List<Integer> flowList, List<Integer> needList) {
        return (flowList.containsAll(needList));
    }
}
