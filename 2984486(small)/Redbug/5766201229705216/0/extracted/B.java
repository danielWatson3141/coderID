import static java.lang.Integer.*;
import static java.lang.Math.*;
import static java.util.Arrays.*;

public class B {

	public Object solve() {
		int N = sc.nextInt();
		int [][] F = sc.nextInts(N-1);
		dec(F);

		int res = INF;
		out: for (int m : rep(1 << N)) {
			int C = 0;
			int [][] E = new int [N-1][];
			for (int i : rep(N-1))
				if ((m & (1 << F[i][0])) == 0)
					if ((m & (1 << F[i][1])) == 0)
						E[C++] = F[i];
			E = copyOf(E, C);

			int [] cc = cc(E, N);
			for (int i : rep(N))
				for (int j : rep(N))
					if ((m & (1 << i)) == 0)
						if ((m & (1 << j)) == 0)
							if (cc[i] != cc [j])
								continue out;

			int [][] G = graph(N, E);
			for (int i : rep(N))
				if ((m & (1 << i)) == 0)
					if (dfs(G, i, -1)) {
						res = min(res, bitCount(m));
						break;
					}

		}

		return res;
	}

	boolean dfs(int [][] G, int r, int p) {
		int L = 0, C = 2;
		if (p != -1) { ++L; ++C; };

		if (G[r].length == L)
			return true;
		if (G[r].length != C)
			return false;

		for (int i : G[r])
			if (i != p)
				if (!dfs(G, i, r))
					return false;

		return true;
	}

	private static final int INF = (int) 1e9;
	private static int [] cc (int [][] E, int N) {
		int [] res = singletons(N);
		dsu(E, 0, E.length, res);
		for (int i = 0; i < N; ++i)
			res[i] = root(res, i);
		return res;
	}
	private static int [][] dec(int [][] E) {
		for (int [] e : E)
			for (int i = 0; i < e.length; ++i)
				--e[i];
		return E;
	}
	private static boolean dsu(int u, int v, int [] C) {
		u = root(C, u);
		v = root(C, v);
		C[u] = C[v];
		return u != v;
	}
	private static int dsu(int [][] E, int s, int t, int [] C) {
		int res = 0;
		for (int i = s; i < t; ++i)
			if (dsu(E[i][0], E[i][1], C))
				++res;
		return res;
	}
	private static int [][] graph (int N, int [][] E) { return wgraph(N, E)[0]; }
	private static int [] rep(int N) { return rep(0, N); }
	private static int [] rep(int S, int T) { if (T <= S) return new int [0]; int [] res = new int [T-S]; for (int i = S; i < T; ++i) res[i-S] = i; return res; }
	private static int root (int [] C, int s) {
		int res = s;
		while (C[res] != res)
			res = C[res];
		int v = s;
		while (v != res) {
			v = C[v];
			C[v] = res;
		}
		return C[s] = res;
	}
	private static int [] singletons(int N) { return rep(N); }
	private static int [][][] wgraph(int N, int [][] E) {
		int [] D = new int [N];
		for (int [] e : E) {
			int x = e[0], y = e[1];
			++D[x]; ++D[y];
		}
		int [][][] res = new int [2][N][];
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < N; ++j)
				res[i][j] = new int [D[j]];
		D = new int [N];
		for (int [] e : E) {
			int x = e[0], y = e[1], z = e.length > 2 ? e[2] : 1;
			res[0][x][D[x]] = y; res[0][y][D[y]] = x;
			res[1][x][D[x]] = res[1][y][D[y]] = z;
			++D[x]; ++D[y];
		}
		return res;
	}
	////////////////////////////////////////////////////////////////////////////////////
	private static IOUtils.MyScanner sc = new IOUtils.MyScanner();
	private static class IOUtils {
		public static class MyScanner {
			public int nextInt() { return sc.nextInt(); }
			public String nextLine() {
				String line = sc.nextLine().trim();
				if ("".equals(line)) // If at end of line, read next line
					line = sc.nextLine();
				return line;
			}
			public String[] nextStrings() {return nextLine().split(" "); }
			public int[] nextInts() {
				String[] L = nextStrings();
				int[] res = new int[L.length];
				for (int i = 0; i < L.length; ++i)
					res[i] = Integer.parseInt(L[i]);
				return res;
			}
			public int[][] nextInts(int N) {
				int[][] res = new int[N][];
				for (int i = 0; i < N; ++i)
					res[i] = nextInts();
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
				print("Case #" + n + ": " + build(new B().solve()));
			err("------------------");
			err(time());
		}
	}
	public static void main(String[] args) {
		int N = sc.nextInt();
		IOUtils.run(N);
	}
}
