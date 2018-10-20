import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("chaos.in");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("chaos.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		Chaos solver = new Chaos();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class Chaos {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int bitLength = in.nextInt();
        long[] a = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = Long.parseLong(in.nextToken(), 2);
        }
        long[] b = new long[n];
        for (int i = 0; i < n; i++) {
            b[i] = Long.parseLong(in.nextToken(), 2);
        }
        Arrays.sort(a);
        int best = bitLength + 1;
        for (int check = 0; check < n; check++) {
            long mask = a[0] ^ b[check];
            long[] cur = new long[n];
            for (int i = 0; i < n; i++) {
                cur[i] = b[i] ^ mask;
            }
            Arrays.sort(cur);
            if (Arrays.equals(a, cur)) {
                best = Math.min(best, Long.bitCount(mask));
            }
        }
        out.print("Case #" + testNumber + ": ");
        if (best > bitLength) {
            out.println("NOT POSSIBLE");
        } else {
            out.println(best);
        }
    }
}

class InputReader {
    BufferedReader br;
    StringTokenizer st;

    public InputReader(InputStream stream) {
        br = new BufferedReader(new InputStreamReader(stream));
    }

    public String next() {
        return nextToken();
    }

    public String nextToken() {
        while (st == null || !st.hasMoreTokens()) {
            String line = null;
            try {
                line = br.readLine();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
            if (line == null) {
                return null;
            }
            st = new StringTokenizer(line);
        }
        return st.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(nextToken());
    }

}

