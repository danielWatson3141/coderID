/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package codejamronea;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

/**
 *
 * @author ehsan
 */
public class ElectricFlow {
    public class Example {
        String[] inflow;
        String[] outflow;
        int N;
        int L;
        int min_cost;
        int[] best_operations;
        int[] operations;
        public Example(int N, int L, String[] inf, String[] outf) {
            this.N = N;
            this.L = L;
            this.inflow = inf;            
            this.outflow = outf;
            min_cost = L + 1;
        }
        public void solve() {
            operations = new int[L];
            for (int oi = 0; oi < N; oi++) {
                for (int di = 0; di < N; di++) {
                    assign(oi, di);
                }
            }
        }
        
        void assign(int oi, int di) {
            String outlet = inflow[oi];
            String device = outflow[di];
            operations = new int[L];
            for (int j = 0; j < L; j++) operations[j] = device.charAt(j) == outlet.charAt(j) ? 0 : 1;
            int tmp_cost = cost();
            if (tmp_cost < min_cost && valid(oi, di)) {
                min_cost = tmp_cost;
                best_operations = operations;
            }
        }
        
        boolean valid(int oi, int di) {
            String[] converted  = new String[N];
            for (int i = 0; i < N; i++) {
                converted[i] = convert(inflow[i]);
                int j = 0;
                for (; j < N; j++) {
                    if (same(converted[i], outflow[j]))
                        break;
                }
                if (j == N) return false;
            }
            return true;            
        }
        boolean same(String s1, String s2) {
            for (int i = 0; i < L; i++) if (s1.charAt(i) != s2.charAt(i)) return false;
            return true;
        }
        String convert(String s) {
            String o = "";
            for (int i = 0; i < L; i++) {                
                o = (s.charAt(i) == '1' && operations[i] == 0) || (s.charAt(i) == '0' && operations[i] == 1) ? o + "1" : o + "0";
            }
            return o;
        }
        int cost() {
            int c = 0;
            for (int i : operations) if (i == 1) c++;
            return c;
        }
               
        @Override
        public String toString() {
            if (min_cost == L + 1) return "NOT POSSIBLE";
            else return "" + min_cost;
        }
        
    }
    public void solve(String fname) throws FileNotFoundException, IOException {
        Scanner sc = new Scanner(new File("/home/ehsan/" + fname + ".in"));
        int T = Integer.parseInt(sc.nextLine());
        Example[] examples = new Example[T];
        FileWriter fw = new FileWriter("/home/ehsan/" + fname + ".out");
        for (int t = 0; t < T; t++) {
            String[] NL = sc.nextLine().split(" ");
            String[] iflows = sc.nextLine().split(" ");
            String[] oflows = sc.nextLine().split(" ");
            examples[t] = new Example(Integer.parseInt(NL[0]),
                    Integer.parseInt(NL[1]),
                    iflows, oflows);
            examples[t].solve();
            String answer = examples[t].toString();
            fw.write("Case #" + (t + 1) + ": " + answer + "\n");
        }
        fw.close();
        
    }
}
