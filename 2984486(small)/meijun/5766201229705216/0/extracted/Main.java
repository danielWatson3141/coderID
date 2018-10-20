import java.util.*;
import java.io.*;

import static java.util.Arrays.*;
import static java.lang.Math.*;

public class Main {
	static boolean LOCAL = System.getSecurityManager() == null;
	Scanner in = new Scanner(System.in);
	PrintWriter out = new PrintWriter(System.out);

	void run() {
		int t = in.nextInt();
		for (int i = 0; i < t; i++) {
			out.printf("Case #%d: ", i + 1);
			solve();
		}
	}
	
	int[] vs;
	private int[][] dp;
	private int n;
	private void solve() {
		n = in.nextInt();
		vs = new int[n];
		for (int i = 0; i < n - 1; i++) {
			int f = in.nextInt() - 1, t = in.nextInt() - 1;
			vs[f] |= 1 << t;
			vs[t] |= 1 << f;
		}
		int ans = 0;
		dp = new int[n][1 << n];
		for (int i = 0; i < n; i++) {
			ans = max(ans, dfs(i, ((1 << n) - 1) & (~(1 << i))));
		}
		out.println(n - ans);
	}

	private int dfs(int v, int st) {
		if (dp[v][st] != 0) return dp[v][st];
		int can = vs[v] & st;
		int b = Integer.bitCount(can);
		if (b < 2) return dp[v][st] = 1;
		int[] is = new int[b];
		for (int i = 0, j = 0; i < n; i++) if ((can & (1 << i)) != 0) {
			is[j++] = i;
		}
		int[] bs = new int[b];
		bs[b - 2] = bs[b - 1] = 1;
		int ans = 0;
		do {
			int tmp = 0;
			for (int i = 0; i < b; i++) if (bs[i] == 1) {
				tmp += dfs(is[i], st & (~(1 << is[i])));
			}
			ans = max(ans, tmp);
		} while (nextPermutation(bs));
		return dp[v][st] = 1 + ans;
	}
	boolean nextPermutation(int[] is) {
		int n = is.length;
		for (int i = n - 1; i > 0; i--) {
			if (is[i - 1] < is[i]) {
				int j = n;
				while (is[i - 1] >= is[--j])
					;
				swap(is, i - 1, j);
				rev(is, i, n);
				return true;
			}
		}
		rev(is, 0, n);
		return false;
	}

	void rev(int[] is, int b, int e) {
		for (int i = b, j = e - 1; i < j; i++, j--) {
			swap(is, i, j);
		}
	}

	void swap(int[] is, int i, int j) {
		int t = is[i];
		is[i] = is[j];
		is[j] = t;
	}

	void debug(Object... os) {
		System.err.println(deepToString(os));
	}

	public static void main(String[] args) {
		long start = System.nanoTime();
		if (LOCAL) {
			try {
//				System.setIn(new FileInputStream("./../in"));
				System.setIn(new FileInputStream("./../B-small-attempt1.in"));
				 System.setOut(new PrintStream("./../B-small-attempt1.out"));
			} catch (IOException e) {
				LOCAL = false;
			}
		}
		Main main = new Main();
		main.run();
		main.out.close();
		if (LOCAL)
			System.err.printf("[Time %.6fs]%n",
					(System.nanoTime() - start) * 1e-9);
	}
}

class Scanner {
	BufferedReader br;
	StringTokenizer st;

	Scanner(InputStream in) {
		br = new BufferedReader(new InputStreamReader(in));
		eat("");
	}

	private void eat(String string) {
		st = new StringTokenizer(string);
	}

	String nextLine() {
		try {
			return br.readLine();
		} catch (IOException e) {
			return null;
		}
	}

	boolean hasNext() {
		while (!st.hasMoreTokens()) {
			String s = nextLine();
			if (s == null)
				return false;
			eat(s);
		}
		return true;
	}

	String next() {
		hasNext();
		return st.nextToken();
	}

	int nextInt() {
		return Integer.parseInt(next());
	}

	long nextLong() {
		return Long.parseLong(next());
	}

	double nextDouble() {
		return Double.parseDouble(next());
	}
}