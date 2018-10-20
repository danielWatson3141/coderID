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
	private void solve() {
		int n = in.nextInt(), l = in.nextInt();
		int[] is = new int[n], gs = new int[n];
		for (int i = 0; i < n; i++) {
			is[i] = Integer.parseInt(in.next(), 2);
		}
		for (int i = 0; i < n; i++) {
			gs[i] = Integer.parseInt(in.next(), 2);
		}
		int ans = l + 1;
		for (int i = 0; i < (1 << l); i++) {
			if (fit(l, i, is, gs)) ans = min(ans, Integer.bitCount(i));
		}
		if (ans == l + 1) out.println(np);
		else out.println(ans);
	}

	private boolean fit(int l, int i, int[] is, int[] gs) {
		boolean[] bs = new boolean[1 << l];
		for (int j : is) bs[j ^ i] = true;
		for (int j : gs) if (!bs[j]) return false;
		return true;
	}

	void debug(Object... os) {
		System.err.println(deepToString(os));
	}

	public static void main(String[] args) {
		long start = System.nanoTime();
		if (LOCAL) {
			try {
//				System.setIn(new FileInputStream("./../in"));
				System.setIn(new FileInputStream("./../A-small-attempt0.in"));
				 System.setOut(new PrintStream("./../A-small-attempt0.out"));
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