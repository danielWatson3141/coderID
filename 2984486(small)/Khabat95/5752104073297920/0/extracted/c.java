package gcj2014.round1A;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Random;
import java.util.Scanner;

/**
 * Created by khabat95 on 26/04/14.
 */
public class c {

    public static Random rnd = new Random();
    public static double badCount = 0;
    public static double goodCount = 0;
    public static HashMap<String, Double> badMem = new HashMap<String, Double>();
    public static HashMap<String, Double> goodMem = new HashMap<String, Double>();
    public static HashMap<String, String> mem = new HashMap<String, String>();

    public static void bad(int N) {
        badCount++;
        int[] res = new int[N];
        for (int k=0; k<N; k++) {
            res[k] = k;
        }
        for (int k=0; k<N; k++) {
            int p = rnd.nextInt(N);
            int temp = res[k];
            res[k] = res[p];
            res[p] = temp;
        }
        StringBuilder sb = new StringBuilder();
        for (int i=0; i<N; i++) {
            sb.append(res[i]);
            sb.append(' ');
        }
        String str = sb.toString();
        if (!badMem.containsKey(str)) {
            badMem.put(str, badCount);
        }
    }

    public static void good(int N) {
        goodCount++;
        int[] res = new int[N];
        for (int k=0; k<N; k++) {
            res[k] = k;
        }
        for (int k=0; k<N; k++) {
            int p = k + rnd.nextInt(N-k);
            int temp = res[k];
            res[k] = res[p];
            res[p] = temp;
        }
        StringBuilder sb = new StringBuilder();
        for (int i=0; i<N; i++) {
            sb.append(res[i]);
            sb.append(' ');
        }
        String str = sb.toString();
        if (!goodMem.containsKey(str)) {
            goodMem.put(str, goodCount);
        }
    }

    public static String alg(int N, String str) {
        if (mem.containsKey(str)) {
            return mem.get(str);
        }
        while (!badMem.containsKey(str) && !goodMem.containsKey(str)) {
            bad(N);
            good(N);
        }
        if (!badMem.containsKey(str)) {
            mem.put(str, "GOOD");
            return "GOOD";
        }
        if (!goodMem.containsKey(str)) {
            mem.put(str, "BAD");
            return "BAD";
        }
        String res = (badMem.get(str) < goodMem.get(str)) ? "BAD" : "GOOD";
        mem.put(str, res);
        return res;
    }

    public static void main(String args[]) {
        try {
            Scanner sc = new Scanner(new FileReader("/home/khabat95/gcj2014/round1A/c1.in"));
            PrintWriter pw = new PrintWriter("/home/khabat95/gcj2014/round1A/c1.out");

            int T = sc.nextInt();
            for (int i = 0; i < T; i++) {
                System.out.println("Test case " + (i + 1) + "...");
                int N = sc.nextInt();
                StringBuilder sb = new StringBuilder();
                for (int j=0; j<N; j++) {
                    sb.append(sc.next());
                    sb.append(' ');
                }
                String res;
                if (mem.containsKey(sb.toString())) {
                    res = mem.get(sb.toString());
                } else {
                    int test = rnd.nextInt(2);
                    res = (test == 0) ? "GOOD" : "BAD";
                }

                pw.println("Case #" + (i + 1) + ": " + res);
            }

            pw.flush();
            pw.close();
            sc.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }
}
