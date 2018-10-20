
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
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
         PrintWriter out = new PrintWriter(new FileOutputStream(new File("output.txt")));
        //PrintWriter out = new PrintWriter(System.out);
        Scanner in = new Scanner();
        int t = in.nextInt();



        for (int k = 0; k < t; k++) {
            int n = in.nextInt();
            int l = in.nextInt();
            int re = -1;
            char[][] a = new char[n][l];
            char[][] b = new char[n][l];
            for (int i = 0; i < n; i++) {
                a[i] = in.next().toCharArray();
            }
            String[] outlet = new String[n];

            for (int i = 0; i < n; i++) {
                outlet[i] = in.next();
                b[i] = outlet[i].toCharArray();
            }
            Arrays.sort(outlet);
            for (int i = 0; i < (1 << l); i++) {
                int c = 0;
                for (int j = 0; j < l; j++) {
                    if (((1 << j) & i) != 0) {
                        c++;
                        for (int z = 0; z < n; z++) {
                            if (a[z][j] == '0') {
                                a[z][j] = '1';
                            } else {
                                a[z][j] = '0';
                            }
                        }
                    }
                }
                String[] temp = new String[n];
                for (int j = 0; j < n; j++) {
                    temp[j] = new String(a[j]);
               //     System.out.print(temp[j] + " ");
                }
                //System.out.println();
                Arrays.sort(temp);
                boolean ok = true;
                for (int j = 0; j < n; j++) {
                    if (!temp[j].equals(outlet[j])) {
                        ok = false;
                        break;
                    }
                }
                for (int j = 0; j < l; j++) {
                    if (((1 << j) & i) != 0) {                       
                        for (int z = 0; z < n; z++) {
                            if (a[z][j] == '0') {
                                a[z][j] = '1';
                            } else {
                                a[z][j] = '0';
                            }
                        }
                    }
                }
                if (ok) {
                    if (re == -1 || re > c) {
                        re = c;
                    }
                }

            }
            if (re != -1) {
                out.println("Case #" + (k + 1) + ": " + re);
            } else {
                out.println("Case #" + (k + 1) + ": NOT POSSIBLE");
            }
        }
        out.close();
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
            //br = new BufferedReader(new InputStreamReader(System.in));
             br = new BufferedReader(new FileReader(new File("A-small-attempt0.in")));
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
