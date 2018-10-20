
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.StringTokenizer;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author Trung Pham
 */
public class Solution {

    public static long Mod = 1000000007;
    public static long[][][][] dp;

    public static void main(String[] args) throws FileNotFoundException {
        PrintWriter out = new PrintWriter(new FileOutputStream(new File("output1.txt")));
        //PrintWriter out = new PrintWriter(System.out);
        Scanner in = new Scanner();
        int t = in.nextInt();



        for (int z = 0; z < t; z++) {
            int n = in.nextInt();

            boolean[][] map = new boolean[n][n];
            int[] count = new int[n];
            for (int i = 0; i < n - 1; i++) {
                int a = in.nextInt() - 1;
                int b = in.nextInt() - 1;
                count[a]++;
                count[b]++;
                map[a][b] = true;
                map[b][a] = true;
            }
            if (n == 2) {
                System.out.println(z);
                if (map[0][1]) {
                    out.println("Case #" + (z + 1) + ": " + 0);
                } else {
                    out.println("Case #" + (z + 1) + ": " + 1);
                }
                continue;
            }


            int re = -1;
            for (int i = 0; i < (1 << n); i++) {
                int c = 0;
                for (int j = 0; j < n; j++) {
                    if (((1 << j) & i) != 0) {
                        c++;
                        for (int k = 0; k < n; k++) {
                            if (map[j][k] && ((1<<k) & i) == 0) {
                                count[k]--;                                
                            }
                        }
                    }
                }
                boolean ok = true;
                int two = 0;
                int root = -1;
                for (int j = 0; j < n; j++) {

                    if (((1 << j) & i) == 0) {
                        if (count[j] == 2) {

                            root = j;
                            two++;

                        }
                    }
                }
                for (int j = 0; j < n; j++) {
                    if (((1 << j) & i) != 0) {

                        for (int k = 0; k < n; k++) {
                            if (map[j][k] && ((1 <<k) & i) == 0) {
                                count[k]++;                                
                            }
                        }
                    }
                }
                if (ok && two == 1) {                   
                    if (z == 0 && i == 0) {
                        System.out.println(root);
                    }
                    int[] check = new int[n];
                    Arrays.fill(check, -1);
                    ok = bfs(i, map, check, root);

                    for (int j = 0; j < n; j++) {
                        if (check[j] == -1 && ((1 << j) & i) == 0) {
                            
                            ok = false;
                            break;
                        }
                    }
                    if (!ok) {
                        continue;
                    }
                    if (re == -1 || re > c) {
                        re = c;
                    }
                }

            }

            if (re != -1) {
                out.println("Case #" + (z + 1) + ": " + re);
            } else {
                out.println("Case #" + (z + 1) + ": NOT POSSIBLE");
            }
        }
        out.close();
    }

    public static boolean bfs(int mask, boolean[][] map, int[] check, int node) {
        LinkedList<Integer> q = new LinkedList();
        q.add(node);
        check[node] = 0;
        int []child = new int[map.length];
        while (!q.isEmpty()) {
            int val = q.remove(0);
            for (int i = 0; i < map.length; i++) {
                if (map[val][i] && ((1 << i) & mask) == 0) {
                    if (check[i] == -1) {
                        check[i] = check[val] + 1;
                        q.add(i);
                        child[val]++;
                    } 
                }
            }
        }
        for(int i = 0; i < child.length;i++){
            if(((1<<i) & mask) == 0){
                if(child[i] != 0 && child[i] != 2){
                    return false;
                }
            }
        }
        return true;
    }

    public static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    static class Scanner {

        BufferedReader br;
        StringTokenizer st;

        public Scanner() throws FileNotFoundException {
            //System.setOut(new PrintStream(new BufferedOutputStream(System.out), true));
           // br = new BufferedReader(new InputStreamReader(System.in));
            br = new BufferedReader(new FileReader(new File("B-small-attempt5.in")));
        }

        public String next() {


            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (Exception e) {
                    throw new RuntimeException();
                }
            }
            return st.nextToken();
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public String nextLine() {
            st = null;
            try {
                return br.readLine();
            } catch (Exception e) {
                throw new RuntimeException();
            }
        }

        public boolean endLine() {
            try {
                String next = br.readLine();
                while (next != null && next.trim().isEmpty()) {
                    next = br.readLine();
                }
                if (next == null) {
                    return true;
                }
                st = new StringTokenizer(next);
                return st.hasMoreTokens();
            } catch (Exception e) {
                throw new RuntimeException();
            }
        }
    }
}
