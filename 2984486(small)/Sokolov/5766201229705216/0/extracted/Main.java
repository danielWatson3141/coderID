import java.io.*;
import java.util.*;
import java.math.*;


public class Main {
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	static int[] d;
	static int n;
	static ArrayList<Integer>[] a;
	static boolean[] used;
	static boolean ok;
	
	static void solve() throws Exception {
		int t = nextInt();
		for (int tt = 1; tt <= t; tt++) {
			n = nextInt();
			a = new ArrayList[n];
			for (int i = 0; i < n; i++) {
				a[i] = new ArrayList<Integer>();
			}
			for (int i = 0; i < n-1; i++) {
				int x = nextInt()-1;
				int y = nextInt()-1;
				a[x].add(y);
				a[y].add(x);
			}
			int res = Integer.MAX_VALUE;
			for (int mask = 1; mask < (1<<n); mask++) {
				int cnt = 0;
				for (int i = 0; i < n; i++) {
					if ((mask & (1<<i)) != 0) {
						cnt++;
					}
				}
				if (cnt % 2 == 1) {
					for (int i = 0; i < n; i++) {
						if ((mask & (1<<i)) != 0) {
							d = new int[20];
							used = new boolean[n];
							ok = true;
							dfs(i, mask, 0);
							if (ok) {
								res = Math.min(n-cnt, res);
							}
						}
					}
				}
			}
			out.println("Case #" + tt + ": " + res);
		}
	}

	static void dfs(int node, int mask, int len) {
		d[len]++;
		used[node] = true;
		int cnt = 0;
		for (int i = 0; i < a[node].size(); i++) {
			if (!used[a[node].get(i)] && (mask & (1<<(a[node].get(i)))) != 0) {
				cnt++;
			}
		}
		if (cnt != 0 && cnt != 2) {
			ok = false;
			return;
		}
		for (int i = 0; i < a[node].size(); i++) {
			if (!used[a[node].get(i)] && (mask & (1<<(a[node].get(i)))) != 0) {				
				dfs(a[node].get(i), mask, len+1);
			}
		}
	}
	
	static int sqr(int x) {
		return x*x;
	}
	
	static int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	static long nextLong() throws IOException {
		return Long.parseLong(next());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	static BigInteger nextBigInteger() throws IOException {
		return new BigInteger(next());
	}
	
	static String next() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}
	
	static String nextLine() throws IOException {
		tok = new StringTokenizer("");
		return in.readLine();
	}

	static boolean hasNext() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			String s = in.readLine();
			if (s == null) {
				return false;
			}
			tok = new StringTokenizer(s);
		}
		return true;
	}

	public static void main(String args[]) {
		try {
			//in = new BufferedReader(new InputStreamReader(System.in));
			//out = new PrintWriter(new OutputStreamWriter(System.out));
			in = new BufferedReader(new FileReader("1.in"));
			out = new PrintWriter(new FileWriter("1.out"));
			solve();
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			java.lang.System.exit(1);
		}
	}
}