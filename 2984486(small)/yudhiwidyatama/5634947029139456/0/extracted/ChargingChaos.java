package yudhi.pkg;

import java.util.Arrays;
import java.util.HashMap;
import java.util.PriorityQueue;
import java.util.Scanner;

/**
 * Created by yudhi on 26-4-2014.
 */
public class ChargingChaos {
    int devicesN, switchesL;
    char[][] initialFlow;
    char[][] targetFlow;
    int [] onesInit;
    int [] onesTarget;
    HashMap<String,Integer> targetHash = new HashMap<String, Integer>();
    //

    //
    class State implements Comparable<State> {
        char [] [] currentFlow;
        int [] ones;
        int steps;
        boolean [] chosen = new boolean[switchesL];
        void flip(int idx)
        {
            steps++;
            ones[idx] = devicesN - ones[idx];
            for (int i=0; i<devicesN; i++)
            {
                if (currentFlow[i][idx] == '0') currentFlow[i][idx]= '1';
                else
                    currentFlow[i][idx]= '0';

            }
        }
        boolean matches()

        {
            for (int i=0; i<devicesN; i++)
                if (!targetHash.containsKey(String.valueOf(currentFlow[i])))
                {
                     return false;
                }
            return true;
        }
        State(char[][] iFlow, int[] ones) {
            currentFlow = new char[iFlow.length][];
            for (int i = 0; i < iFlow.length; i++)
                currentFlow[i] = Arrays.copyOf(iFlow[i], iFlow[i].length);
            this.ones = Arrays.copyOf(ones, ones.length);
        }
        State(State s)
        {
            this(s.currentFlow, s.ones);
            this.steps = s.steps;
            this.chosen = Arrays.copyOf(s.chosen,s.chosen.length);
        }
        @Override
        public int compareTo(State o) {
            if (this.steps != o.steps) return this.steps - o.steps;
            return hashCode() - o.hashCode();
        }

    }
    public int bruteSearch()
    {
          State initial = new State(initialFlow,onesInit);
        PriorityQueue<State> q = new PriorityQueue<State>();
        q.add(initial);
        while (!(q.isEmpty())) {
            State s = q.poll();
            if (s.matches()) return s.steps;
            int minV = 3;
            int fnd = 0;
            boolean unChosen = false;
            for (int i = 0; i < switchesL; i++) {
                if (s.chosen[i]) continue;
                unChosen = true;
                int cV;
                int currentOnes = s.ones[i];
                int flippedOnes = devicesN - currentOnes;
                if (currentOnes == flippedOnes) cV = 2;
                else if (currentOnes == onesTarget[i]) cV = 1;
                else if (flippedOnes == onesTarget[i]) cV = 1;
                else
                    cV = 0;
                if (cV < minV) {
                    fnd = i;
                    minV = cV;
                }

            }
            if (!unChosen) continue; // dead end
            if (minV == 3) {
                for (int i = 0; i < switchesL; i++) {
                    if (s.chosen[i]) continue;
                    fnd = i;
                    break;
                }
            }
            if (minV == 1) {
                if (s.ones[fnd] == onesTarget[fnd]) {
                    State ns = new State(s);
                    ns.chosen[fnd] = true;
                    q.add(ns);
                } else {
                    State ns = new State(s);
                    ns.chosen[fnd] = true;
                    ns.flip(fnd);
                    q.add(ns);
                }
            }
            if (minV == 2) {
                State ns = new State(s);
                ns.chosen[fnd] = true;
                q.add(ns);
                ns = new State(s);
                ns.chosen[fnd] = true;
                ns.flip(fnd);
                q.add(ns);
            }
            if (minV == 0) {
                continue; // dead end too
            }
        }
        return -1;
    }

    public ChargingChaos(int devicesN, int switchesL, String[] initialFlow, String[] targetFlow) {
      String s;
        this.devicesN = devicesN;
        this.switchesL = switchesL;
      this.initialFlow = new char[devicesN][];

        onesInit = new int[switchesL];
      for (int i=0; i<devicesN;i++) {
          this.initialFlow[i] = initialFlow[i].toCharArray();
          for (int j=0; j<switchesL; j++)
              if (this.initialFlow[i][j] == '1') onesInit[j]++;

      }
        onesTarget = new int[switchesL];
        this.targetFlow= new char[devicesN][];
        for (int i=0; i<devicesN;i++) {
            this.targetFlow[i] = targetFlow[i].toCharArray();
            targetHash.put(targetFlow[i],1) ;
            for (int j=0; j<switchesL; j++)
                if (this.targetFlow[i][j] == '1') onesTarget[j]++;

        }
    }

    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        int cases = scanner.nextInt();
        for (int caseNo=1; caseNo<=cases; caseNo++)
        {
            int devicesN = scanner.nextInt();
            int switchesL = scanner.nextInt();
            String initialFlow[] = new String[devicesN];
            String targetFlow[] = new String[devicesN];
            for (int i=0; i<devicesN; i++)
                initialFlow[i] = scanner.next();
            for (int i=0; i<devicesN; i++)
                targetFlow[i] = scanner.next();
            ChargingChaos c = new ChargingChaos(devicesN,switchesL,initialFlow,targetFlow);
            int res = c.bruteSearch();
            if (res<0) System.out.println("Case #"+caseNo+": NOT POSSIBLE");
            else System.out.println("Case #"+caseNo+": " + res);
        }
    }
}
