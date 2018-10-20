import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.*;

public class A {

    int n, l;

	private void solve() throws Exception {
        n = nextInt();
        l = nextInt();
        Set<Long> fr = new HashSet<>();
        long[] from = new long[n];
        for (int i = 0; i < n; ++i) {
            from[i] = Integer.parseInt(nextToken(), 2);
            fr.add(from[i]);
        }
        int[] to = new int[n];
        for (int i = 0; i < n; ++i) {
            to[i] = Integer.parseInt(nextToken(), 2);
        }
        int min = Integer.MAX_VALUE;
        for (int i = 0; i < n; ++i) {
            long diff = from[0] ^ to[i];
            boolean good = true;
            for (int k = 0; k < n; ++k) {
                if (!fr.contains(to[k] ^ diff)) {
                    good = false;
                    break;
                }
            }
            if (good) {
                min = Math.min(min, Long.bitCount(diff));
            }
        }

        if (min == Integer.MAX_VALUE) {
            out.println("NOT POSSIBLE");
        } else {
            out.println(min);
        }
    }

    public void run() {
		try {
			int tc = nextInt();
			for (int it = 1; it <= tc; ++it) {
				System.err.println(it);
				out.print("Case #" + it + ": ");
				solve();
			}
		} catch (Exception e) {
			NOO(e);
		} finally {
			out.close();
		}
	}

	PrintWriter out;
	BufferedReader in;
	StringTokenizer St;

	void NOO(Exception e) {
		e.printStackTrace();
		System.exit(42);
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}

	String nextToken() {
		while (!St.hasMoreTokens()) {
			try {
				String line = in.readLine();
				if (line == null)
					return null;
				St = new StringTokenizer(line);
			} catch (Exception e) {
				NOO(e);
			}
		}
		return St.nextToken();
	}

	private A(String name) {
		try {
			in = new BufferedReader(new FileReader(name + ".in"));
			St = new StringTokenizer("");
			out = new PrintWriter(new FileWriter(name + ".out"));
		} catch (Exception e) {
			NOO(e);
		}
	}

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		long start = System.currentTimeMillis();
		new A("A").run();
		System.err.println("Done in " + (System.currentTimeMillis() - start) + "ms");
	}
}
