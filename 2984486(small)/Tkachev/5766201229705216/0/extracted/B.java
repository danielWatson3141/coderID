import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Locale;
import java.util.StringTokenizer;

public class B {

    int n;
    int[][] best;
    int[][] count;
    ArrayList<Integer>[] nei;

	private void solve() throws Exception {
        n = nextInt();
        best = new int[n][n + 1];
        for (int[] a : best) {
            Arrays.fill(a, -1);
        }
        count = new int[n][n + 1];
        for (int[] a : count) {
            Arrays.fill(a, -1);
        }
        nei = new ArrayList[n];
        for (int i = 0; i < n; ++i) {
            nei[i] = new ArrayList<>();
        }
        for (int i = 0; i < n - 1; ++i) {
            int from = nextInt() - 1, to = nextInt() - 1;
            nei[from].add(to);
            nei[to].add(from);
        }
        int res = Integer.MAX_VALUE;
        for (int i = 0; i < n; ++i) {
            res = Math.min(res, getBest(i, n));
        }
        out.println(res);
	}

    int getCount(int v, int prev) {
        if (count[v][prev] >= 0) {
            return count[v][prev];
        }
        int res = 1;
        for (int next : nei[v]) {
            if (next != prev) {
                res += getCount(next, v);
            }
        }
        return count[v][prev] = res;
    }

    int getBest(int v, int prev) {
        if (best[v][prev] >= 0) {
            return best[v][prev];
        }
        int res = 0;
        for (int next : nei[v]) {
            if (next != prev) {
                res += getCount(next, v);
            }
        }
        int mx1 = 0, mx2 = 0;
        int total = res;
        for (int next : nei[v]) {
            if (next != prev) {
                int cur = getCount(next, v) - getBest(next, v);
                if (cur > mx1) {
                    mx2 = mx1;
                    mx1 = cur;
                } else if (cur > mx2) {
                    mx2 = cur;
                }
            }
        }
        if (mx1 > 0 && mx2 > 0) {
            res = Math.min(res, total - mx1 - mx2);
        }
        return best[v][prev] = res;
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

	private B(String name) {
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
		new B("B").run();
		System.err.println("Done in " + (System.currentTimeMillis() - start) + "ms");
	}
}
