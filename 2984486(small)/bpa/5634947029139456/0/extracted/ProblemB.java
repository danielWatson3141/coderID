import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class ProblemB implements Runnable {

    void solveMultiTest() throws IOException {
        int testCases = nextInt();
        for (int testCase = 1; testCase <= testCases; testCase++) {
            out.println("Case #" + testCase + ": " + solveOneTest());
        }
    }

    String solveOneTest() throws IOException {
        int n = nextInt();
        int l = nextInt();
        int[] init = new int[n];
        for (int i = 0; i < n; i++) {
            init[i] = Integer.parseInt(nextToken(), 2);
        }
        int[] outs = new int[n];
        for (int i = 0; i < n; i++) {
            outs[i] = Integer.parseInt(nextToken(), 2);
        }
        Arrays.sort(outs);
        int min = 1000;
        for (int i = 0; i < (1 << l); i++) {
            int[] tmp = new int[n];
            for (int j = 0; j < n; j++) {
                tmp[j] = init[j] ^ i;
            }
            Arrays.sort(tmp);
            boolean f = true;
            for (int j = 0; j < n; j++)
                if (tmp[j] != outs[j])
                    f = false;
            if (f) {
                int x = Integer.bitCount(i);
                if (x < min)
                    min = x;
            }
        }
        return min < 1000 ? min + "" : "NOT POSSIBLE";
    }

    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;

    public void run() {
        try {
            InputStream input = System.in;
            PrintStream output = System.out;
            File file = new File("a.in");
            if (file.exists() && file.canRead()) {
                input = new FileInputStream(file);
                output = new PrintStream(new File("a.out"));
            }
            br = new BufferedReader(new InputStreamReader(input));
            out = new PrintWriter(output);
            solveMultiTest();
            out.close();
        } catch (IOException e) {
        }
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    String nextToken() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String line = br.readLine();
            if (line == null) {
                return null;
            }
            st = new StringTokenizer(line);
        }
        return st.nextToken();
    }

    public static void main(String[] args) {
        new Thread(new ProblemB()).run();
    }
}