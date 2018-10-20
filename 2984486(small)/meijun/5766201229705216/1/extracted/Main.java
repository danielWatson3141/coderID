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
	String np = "NOT POSSIBLE";
	private long[] is;
	private long[] gs;
	private int[] isb;
	private int[] gsb;
	long flip;
	private int n;
	private int l;
	private void solve() {
		n = in.nextInt();
		l = in.nextInt();
		is = new long[n];
		gs = new long[n];
		isb = new int[l];
		gsb = new int[l];
		for (int i = 0; i < n; i++) {
			is[i] = Long.parseLong(in.next(), 2);
		}
		for (int i = 0; i < n; i++) {
			gs[i] = Long.parseLong(in.next(), 2);
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < l; j++) {
				if ((is[i] & (1L << j)) != 0) {
					isb[j]++;
				}
				if ((gs[i] & (1L << j)) != 0) {
					gsb[j]++;
				}
			}
		}
		for (int i = 0; i < l; i++) {
			if (isb[i] != gsb[i] && isb[i] != n - gsb[i]) {
				out.println(np);
				return ;
			}
		}
		flip = 0;
		int ans = dfs(0);
		if (ans == -1) out.println(np);
		else out.println(ans);
	}

	private int dfs(int i) {
		
		if (i == l) {
			return 0;
		}
		if (isb[i] * 2 != n) {
			if (isb[i] == gsb[i] && fit(i)) return dfs(i + 1);
			else {
				flip ^= (1 << i);
				int ans = -1;
				if (fit(i)) {
					ans = dfs(i + 1);
				}
				flip ^= (1 << i);
				if (ans != -1) return ans + 1;
				return -1;
			}
		} else {
			int ans = -1;
			if (fit(i)) {
				ans = dfs(i + 1);
			}
			int ons = -1;
			flip ^= (1 << i);
			if (fit(i)) {
				ons = dfs(i + 1);
			}
			flip ^= (1 << i);
			if (ans == -1 && ons == -1) return -1;
			if (ans == -1) return ons + 1;
			if (ons == -1) return ans;
			return min(ans, ons + 1);
		}
	}

	private boolean fit(int c) {
		Map<Long, Integer> icnt = new TreeMap<Long, Integer>();
		Map<Long, Integer> gcnt = new TreeMap<Long, Integer>();
		for (long i : is) {
			inc(icnt, (i ^ flip) & ((1L << (c + 1)) - 1));
		}
		for (long i : gs) {
			inc(gcnt, i & ((1L << (c + 1)) - 1));
		}
		return icnt.equals(gcnt);
	}

	private void inc(Map<Long, Integer> icnt, long m) {
		if (icnt.containsKey(m)) icnt.put(m, 1 + icnt.get(m));
		else icnt.put(m, 1);
	}

	void debug(Object... os) {
		System.err.println(deepToString(os));
	}

	public static void main(String[] args) {
		long start = System.nanoTime();
		if (LOCAL) {
			try {
//				System.setIn(new FileInputStream("./../in"));
				System.setIn(new FileInputStream("./../A-large.in"));
				 System.setOut(new PrintStream("./../A-large.out"));
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