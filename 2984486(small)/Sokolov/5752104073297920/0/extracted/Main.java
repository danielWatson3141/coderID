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
			int[] a = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = nextInt();
			}
			/*boolean good = true;
			for (int i = 0; i < n; i++) {
				if (a[i] < i) {
					good = false;
					break;
				}
			}*/
			Random r = new Random();
			if (r.nextBoolean() == true) {
				out.println("Case #" + tt + ": GOOD");
			} else {
				out.println("Case #" + tt + ": BAD");
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