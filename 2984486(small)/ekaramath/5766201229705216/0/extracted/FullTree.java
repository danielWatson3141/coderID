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
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;
import jdk.nashorn.internal.parser.Lexer;

/**
 *
 * @author ehsan
 */
public class FullTree {
    class Tree {
        int N;
        int min_cost;
        Tree(int N) {
            this.N = N;
            adj = new HashMap<>();
            for (int n = 0; n < N; n++) adj.put(n + 1, new ArrayList<>());
        }
        HashMap<Integer, ArrayList<Integer>> adj;
        void addEdge(int v1, int v2) {
            adj.get(v1).add(v2);
            adj.get(v2).add(v1);
        }
        void solve() {
            // assume some root
            min_cost = N - 1;            
            for (int i = 0; i < N; i++) {                                
                
                int c = check(0, i + 1);                
                if (c < min_cost) {
                    min_cost = c;
                }
                if (min_cost == 0) break;
            }
        }
        
        int check(int p, int v) {
            int size = adj.get(v).size();
            
            if (p == 0 && size == 1) return N - 1;
            
            if (p == 0 && size == 2) {
                return check(v, adj.get(v).get(0)) +
                        check(v, adj.get(v).get(1));
            }
            if (p == 0 && size == 3) {
                int c1 = check(v, adj.get(v).get(0));
                int c2 = check(v, adj.get(v).get(1));
                int c3 = check(v, adj.get(v).get(2));
                int d1 = count(v, adj.get(v).get(0));
                int d2 = count(v, adj.get(v).get(1));
                int d3 = count(v, adj.get(v).get(2));
                int e1 = d1 + c2 + c3;
                int e2 = d2 + c1 + c3;
                int e3 = d3 + c1 + c2;
                return Math.min(e1, Math.min(e2, e3));
            }
            if (size == 1) return 0;
            if (size == 3) {
                int c = 0;
                for (int j = 0; j < 3; j++) {
                    if (adj.get(v).get(j) != p) c += check(v, adj.get(v).get(j));
                }
                return c;
            }
            if (size == 2) {
                for (int j = 0; j < 2; j++) {
                    if (adj.get(v).get(j) != p) return count(v, adj.get(v).get(j));
                }
            }
            return 0;
            
        }
        int count(int p, int v) {
            int c = 1;
            for (int j = 0; j < adj.get(v).size(); j++) {
                if (adj.get(v).get(j) == p) continue;
                c += count(v, adj.get(v).get(j));
            }
            return c;
        }

        @Override
        public String toString() {
            return "" + min_cost;
        }
        
    }
    public void solve(String fname) throws FileNotFoundException, IOException {
        Scanner sc = new Scanner(new File("/home/ehsan/" + fname + ".in"));
        int T = Integer.parseInt(sc.nextLine());
        FileWriter fw = new FileWriter("/home/ehsan/" + fname + ".out");
        for (int t = 0; t < T; t++) {
            int N = Integer.parseInt(sc.nextLine());
            Tree tree = new Tree(N);
            for (int j = 0; j < N - 1; j++) {
                String[] e = sc.nextLine().split(" ");
                tree.addEdge(Integer.parseInt(e[0]), Integer.parseInt(e[1]));
            }
            tree.solve();
            String answer = "Case #" + (t + 1) + ": " + tree.toString() + "\n";
            fw.write(answer);            
        }
        fw.close();
    }
}
