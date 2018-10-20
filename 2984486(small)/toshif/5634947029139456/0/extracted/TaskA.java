package gcj.round1A;

import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

/**
 * @author fuku
 */
public class TaskA {
    public static void main(String[] args) throws FileNotFoundException {
        InputStream inputStream = TaskA.class.getResourceAsStream("A-small-attempt0.in");
        Scanner in = new Scanner(inputStream);


        PrintWriter out = new PrintWriter(new FileOutputStream("./out.txt"));

        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            System.out.println("------------------");
            System.out.println("test " + (i+1));
            SolA solver = new SolA();
            String ans = solver.solve(i, in, out);
            out.println("Case #" + (i+1) + ": " + ans);
            System.out.println("Case #" + (i+1) + ": " + ans);
        }
        out.close();
    }
}

class SolA {

    int INP = 1000000;

    int[] flip;

    boolean[] doFlip;

    int N;
    int L;
    int[][] g;

    List<String> ts;

    public String solve(int testNumber, Scanner in, PrintWriter out) {
        N = in.nextInt();
        L = in.nextInt();

        g = new int[N][L];
        int[][] t = new int[N][L];
        ts = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            String s = in.next();
            System.out.println("s = " + s);
            for (int j = 0; j < s.length(); j++) {
                g[i][j] = Integer.valueOf("" + s.charAt(j)).intValue();
            }
            //System.out.println("Arrays.toString(g[i]) = " + Arrays.toString(g[i]));
        }

        for (int i = 0; i < N; i++) {
            String s = in.next();
            ts.add(s);
            System.out.println("s = " + s);
            for (int j = 0; j < s.length(); j++) {
                t[i][j] = Integer.valueOf("" + s.charAt(j)).intValue();
            }
            //System.out.println("2 Arrays.toString(t[i]) = " + Arrays.toString(t[i]));
        }
        Collections.sort(ts);

        doFlip = new boolean[L];

        flip = new int[L];
        int base = 0;
        for (int i = 0; i < L; i++) {
            int gB = 0;
            int tB = 0;
            for (int j = 0; j < N; j++) {
                gB += g[j][i];
                tB += t[j][i];
            }
            if (! (gB == tB || N - gB == tB) ) return "NOT POSSIBLE";

            if (N % 2 == 0 && N / 2 == gB) {
                flip[i] = 2; // can flip
            } else {
                if (N - gB == tB) {
                    flip[i] = 1; // should flip and ok
                    base++;
                    for (int j = 0; j < N; j++) {
                        if ( g[j][i] == 1 ) g[j][i] = 0;
                        else g[j][i] = 1;
                    }
                }
            }
        }

        int mi = INP;
        mi = Math.min(mi, flipc(0));

        if (mi == INP) {
            return "NOT POSSIBLE";
        }

        String ans = "" + (mi + base);
        return ans;
    }


    int flipc(int i){
        int mi = INP;

        if (i == L -1) {
            int totCost = INP;
            // check
            doFlip[i] = false;
            if ( check() ) {
                totCost = cost();
            }

            if (flip[i] == 2) {
                doFlip[i] = true;
                if ( check() ) {
                    totCost = Math.min(totCost, cost());
                }
            }

            return totCost;
        }

        doFlip[i] = false;
        mi = Math.min(mi, flipc(i + 1));

        if (flip[i] == 2) {
            doFlip[i] = true;
            mi = Math.min(mi, flipc(i+1));
        }

        return mi;
    }

    boolean check(){
        List<String> rs = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            String s = "";
            for (int j = 0; j < L; j++) {
                int a = g[i][j];
                if (doFlip[j]) {
                    if (a == 1) a = 0;
                    else a = 1;
                }
                s += a;
            }
            rs.add(s);
        }

        Collections.sort(rs);

        for (int i = 0; i < rs.size(); i++) {
            if (!rs.get(i).equals(ts.get(i))) return false;
        }

        return true;
    }

    int cost(){
        int tmpCost = 0;
        for (int j = 0; j < doFlip.length; j++) {
            if (doFlip[j])
                tmpCost++;
        }
        return tmpCost;
    }
}
