
import java.io.*;
import java.util.Arrays;
import java.util.InputMismatchException;

public class ChargingChaos {
	FastScanner in = new FastScanner(System.in);
	PrintWriter out = new PrintWriter(System.out);

	long makeKey(String s1, String s2) {
		long x1 = Long.valueOf(s1, 2);
		long x2 = Long.valueOf(s2, 2);
		
		return x1 ^ x2;
	}
	
	boolean isConvertable(String s1, String s2, long key) {
		long x1 = Long.valueOf(s1, 2);
		long x2 = Long.valueOf(s2, 2);
		
		return ((x1 ^ key) == x2);
	}
	
	int count(long key) {
		int res = 0;
		
		while (key > 0) {
			if ((key & 1) == 1) res++;
			key >>= 1;
		}
		
		return res;
	}
	
	public void run() {
		int T = in.nextInt();
		for (int times = 1; times <= T; times++) {
			int res = Integer.MAX_VALUE;
			int N = in.nextInt(), L = in.nextInt();
			String[] base = new String[N];
			String[] goal = new String[N];
			boolean[] used = new boolean[N];

			for (int i = 0; i < base.length; i++) {
				base[i] = in.next();
			}
			for (int i = 0; i < goal.length; i++) {
				goal[i] = in.next();
			}
			
			loop : for (int i = 0; i < goal.length; i++) {
				Arrays.fill(used, false);
				long key = makeKey(base[0], goal[i]);
				used[i] = true;
				for (int j = 1; j < base.length; j++) {
					for (int k = 0; k < goal.length; k++) {
						if (used[k]) continue;
						
						if (isConvertable(base[j], goal[k], key)) {
							used[k] = true;
							break;
						}
					}
				}
				for (int j = 0; j < used.length; j++) {
					if (!used[j]) continue loop;
				}
				res = Math.min(res, count(key));
			}
			
			String ans = (res == Integer.MAX_VALUE) ? "NOT POSSIBLE" : res + "";
			out.println("Case #" + times + ": " + ans);
		}
		out.close();
	}

	public static void main(String[] args) {
		new ChargingChaos().run();
	}

	class FastScanner {
		private InputStream stream;
		private byte[] buf = new byte[1024];
		private int curChar;
		private int numChars;

		public FastScanner(InputStream stream) {
			this.stream = stream;
			//stream = new FileInputStream(new File("dec.in"));

		}

		int read() {
			if (numChars == -1)
				throw new InputMismatchException();
			if (curChar >= numChars) {
				curChar = 0;
				try {
					numChars = stream.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (numChars <= 0)
					return -1;
			}
			return buf[curChar++];
		}

		boolean isSpaceChar(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		boolean isEndline(int c) {
			return c == '\n' || c == '\r' || c == -1;
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

		String next() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isSpaceChar(c));
			return res.toString();
		}

		String nextLine() {
			int c = read();
			while (isEndline(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isEndline(c));
			return res.toString();
		}
	}
}

