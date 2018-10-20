import static java.lang.Integer.*;
import static java.lang.Math.*;
import static java.util.Arrays.*;

import java.util.*;

public class A {

	public Object solve() {
		int N = sc.nextInt();
		int L = sc.nextInt();
		char [][] a = sc.nextChars(N);
		char [][] b = sc.nextChars(N);

		int [] A = new int [N], B = new int [N];
		for (int i : rep(N))
			for (int j : rep(L)) {
				A[i] |= ((a[i][j] - '0') << j);
				B[i] |= ((b[i][j] - '0') << j);
			}
		sort(A); sort(B);

		int res = INF;
		for (int m : rep(1 << L)) {
			int [] C = A.clone();
			for (int i : rep(N))
				for (int j : rep(L))
					if ((m & (1 << j)) != 0)
						C[i] ^= (1 << j);
			sort(C);
			if (Arrays.equals(B, C))
				res = min(res, bitCount(m));
		}

		if (res == INF)
			return "NOT POSSIBLE";
		return res;
	}

	private static final int INF = (int) 1e9;
	private static int [] rep(int N) { return rep(0, N); }
	private static int [] rep(int S, int T) { if (T <= S) return new int [0]; int [] res = new int [T-S]; for (int i = S; i < T; ++i) res[i-S] = i; return res; }
	////////////////////////////////////////////////////////////////////////////////////
	private static IOUtils.MyScanner sc = new IOUtils.MyScanner();
	private static class IOUtils {
		public static class MyScanner {
			public String next() { return sc.next(); }
			public int nextInt() { return sc.nextInt(); }
			public char[] nextChars() { return next().toCharArray(); }
			public char[][] nextChars(int N) {
				char[][] res = new char[N][];
				for (int i = 0; i < N; ++i)
					res[i] = nextChars();
				return res;
			}
			private final java.util.Scanner sc;
			private MyScanner() {
				sc = new java.util.Scanner(System.in);
				sc.hasNext();
				start();
			}
		}
		private static String build(Object o, Object... a) { return buildDelim(" ", o, a); }
		private static String buildDelim(String delim, Object o, Object... a) {
			StringBuilder b = new StringBuilder();
			append(b, o, delim);
			for (Object p : a)
				append(b, p, delim);
			return b.substring(delim.length());
		}
		//////////////////////////////////////////////////////////////////////////////////
		private static void start() { if (t == 0) t = millis(); }
		private static void append(StringBuilder b, Object o, String delim) {
			if (o.getClass().isArray()) {
				int len = java.lang.reflect.Array.getLength(o);
				for (int i = 0; i < len; ++i)
					append(b, java.lang.reflect.Array.get(o, i), delim);
			} else if (o instanceof Iterable<?>)
				for (Object p : (Iterable<?>) o)
					append(b, p, delim);
			else {
				if (o instanceof Double)
					o = new java.text.DecimalFormat("#.#########").format(o);
				b.append(delim).append(o);
			}
		}
		private static void print(Object o) {
			err(o, '(', time(), ')');
			if (PRINT)
				System.out.println(o);
		}
		private static void err(Object ...o) { System.err.println(build(o)); }
		private static long t;
		private static long millis() { return System.currentTimeMillis(); }
		private static String time() { return "Time: " + (millis() - t) / 1000.0; }
		private static final boolean PRINT = System.getProperties().containsKey("PRINT");
		private static void run(int N) {
			for (int n = 1; n <= N; ++n)
				print("Case #" + n + ": " + build(new A().solve()));
			err("------------------");
			err(time());
		}
	}
	public static void main(String[] args) {
		int N = sc.nextInt();
		IOUtils.run(N);
	}
}
