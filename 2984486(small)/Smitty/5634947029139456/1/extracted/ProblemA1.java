import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class ProblemA1 {

	public static void main(String... argv) throws Exception {
		String filename = ProblemA1.class.getSimpleName();
		Scanner in = new Scanner(new File(filename + ".in"));
		PrintWriter out = new PrintWriter(new File(filename + ".out"));
		solve(in, out);
		out.flush();
		out.close();
	}

	private static final void solve(final Scanner in, final PrintWriter out) throws Exception {
		int testCount = in.nextInt();
		for (int testCase = 1; testCase <= testCount; ++testCase) {
			String result = solveTest(in, out);
			out.println(String.format("Case #%d: %s", testCase, result));
		}
	}

	private static final String solveTest(final Scanner in, final PrintWriter out) throws Exception {

		int n = in.nextInt();
		int l = in.nextInt();

		long[] a = new long[n];
		long[] b = new long[n];

		for (int i = 0; i < n; ++i) {
			a[i] = Long.parseLong(in.next(), 2);
		}
		for (int i = 0; i < n; ++i) {
			b[i] = Long.parseLong(in.next(), 2);
		}

		int minCount = Integer.MAX_VALUE;
		boolean[] was = new boolean[n];
		int[] x = new int[n];
		int[] y = new int[n];

		Set<Long> masks = new HashSet<Long>();
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				masks.add(a[i] ^ b[j]);
			}
		}

		for (long i : masks) {
			int count = 0;
			long t = i;
			while (t > 0) {
				++count;
				t &= t - 1;
			}
			if (count > minCount) {
				continue;
			}
			Arrays.fill(x, -1);
			Arrays.fill(y, -1);
			boolean ok = true;
			for (int q = 0; q < n; ++q) {
				if (x[q] == -1) {
					Arrays.fill(was, false);
					if (!dfs(was, x, y, a, b, q, i)) {
						ok = false;
						break;
					}
				}
			}
			if (ok) {
				minCount = count;
			}
		}

		String result = minCount == Integer.MAX_VALUE ? "NOT POSSIBLE" : "" + minCount;
		return result;
	}

	private static final boolean dfs(boolean was[], int from[], int to[], long[] a, long[] b, int num, long mask) {
		was[num] = true;

		for (int i = 0; i < a.length; ++i) {
			if ((a[num] ^ mask) == b[i]) {
				if (to[i] == -1 || !was[to[i]] && dfs(was, from, to, a, b, to[i], mask)) {
					from[num] = i;
					to[i] = num;
					return true;
				}
			}
		}

		return false;
	}
}
