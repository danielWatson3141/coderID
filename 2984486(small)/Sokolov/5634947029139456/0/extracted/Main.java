import java.io.*;
import java.util.*;
import java.math.*;


public class Main {
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	
	static void solve() throws Exception {
		int t = nextInt();
		for (int tt = 1; tt <= t; tt++) {
			int n = nextInt();
			int l = nextInt();
			char[][] a = new char[n][l];
			for (int i = 0; i < n; i++) {
				a[i] = next().toCharArray();
			}
			char[][] b = new char[n][l];
			for (int i = 0; i < n; i++) {
				b[i] = next().toCharArray();
			}
			int res = Integer.MAX_VALUE;
			for (int mask = 0; mask < (1<<l); mask++) {
				ArrayList<Integer> v1 = new ArrayList<Integer>();
				ArrayList<Integer> v2 = new ArrayList<Integer>();
				for (int i = 0; i < n; i++) {
					int v = 0;
					for (int j = 0; j < l; j++) {
						if ((mask & (1<<j)) != 0 && a[i][j] == '0') {
							v += 1<<j;
						} else if ((mask & (1<<j)) == 0 && a[i][j] == '1') {
							v += 1<<j;
						}
					}
					v1.add(v);
					v = 0;
					for (int j = 0; j < l; j++) {
						if (b[i][j] == '1') {
							v += 1<<j;
						}
					}
					v2.add(v);
				}
				Collections.sort(v1);
				Collections.sort(v2);
				if (v1.equals(v2)) {
					int cnt = 0;
					for (int j = 0; j < l; j++) {
						if ((mask & (1<<j)) != 0) {
							cnt++;
						}
					}
					res = Math.min(cnt, res);
				}
				
			}
			out.print("Case #" + tt + ": ");
			if (res == Integer.MAX_VALUE) {
				out.println("NOT POSSIBLE");
			} else {
				out.println(res);
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