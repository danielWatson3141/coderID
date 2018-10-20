import java.util.HashMap;
import java.io.PrintStream;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.List;
import java.util.Map;
import java.util.BitSet;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.Set;
import java.io.Reader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Niyaz Nigmatullin
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		FastPrinter out = new FastPrinter(outputStream);
		ChargingChaos solver = new ChargingChaos();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class ChargingChaos {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        System.err.println(testNumber);
        int n = in.nextInt();
        int m = in.nextInt();
        BitSet[] a = readSet(in, n);
        BitSet[] b = readSet(in, n);
        Map<List<Integer>, Integer> count = new HashMap<>();
        for (BitSet e : a) {
            for (BitSet f : b) {
                BitSet c = new BitSet();
                c.or(e);
                c.xor(f);
                List<Integer> z = new ArrayList<>();
                for (int i = 0; i < m; i++) if (c.get(i)) z.add(i);
                Integer d = count.get(z);
                if (d == null) d = 0;
                count.put(z, d + 1);
            }
        }
        int ans = Integer.MAX_VALUE;
        for (List<Integer> e : count.keySet()) {
            if (count.get(e) != n) continue;
            ans = Math.min(ans, e.size());
        }
        out.print("Case #" + testNumber + ": ");
        out.println(ans == Integer.MAX_VALUE ? "NOT POSSIBLE" : ans);
    }

    private BitSet[] readSet(FastScanner in, int n) {
        BitSet[] ret = new BitSet[n];
        for (int i = 0; i < n; i++) {
            ret[i] = new BitSet();
            String s = in.next();
            for (int j = 0; j < s.length(); j++) {
                if (s.charAt(j) == '1') {
                    ret[i].set(j);
                }
            }
        }
        return ret;
    }
}

class FastScanner extends BufferedReader {

    public FastScanner(InputStream is) {
        super(new InputStreamReader(is));
    }

    public int read() {
        try {
            int ret = super.read();
//            if (isEOF && ret < 0) {
//                throw new InputMismatchException();
//            }
//            isEOF = ret == -1;
            return ret;
        } catch (IOException e) {
            throw new InputMismatchException();
        }
    }

    public String next() {
        StringBuilder sb = new StringBuilder();
        int c = read();
        while (isWhiteSpace(c)) {
            c = read();
        }
        if (c < 0) {
            return null;
        }
        while (c >= 0 && !isWhiteSpace(c)) {
            sb.appendCodePoint(c);
            c = read();
        }
        return sb.toString();
    }

    static boolean isWhiteSpace(int c) {
        return c >= 0 && c <= 32;
    }

    public int nextInt() {
        int c = read();
        while (isWhiteSpace(c)) {
            c = read();
        }
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int ret = 0;
        while (c >= 0 && !isWhiteSpace(c)) {
            if (c < '0' || c > '9') {
                throw new NumberFormatException("digit expected " + (char) c
                        + " found");
            }
            ret = ret * 10 + c - '0';
            c = read();
        }
        return ret * sgn;
    }

    public String readLine() {
        try {
            return super.readLine();
        } catch (IOException e) {
            return null;
        }
    }

    }

class FastPrinter extends PrintWriter {

    public FastPrinter(OutputStream out) {
        super(out);
    }

    public FastPrinter(Writer out) {
        super(out);
    }


}

