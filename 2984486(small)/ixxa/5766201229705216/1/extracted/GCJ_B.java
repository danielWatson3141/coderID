import java.io.*;
import java.util.*;

public class GCJ_B {
	public static void main(String[] args) throws Exception {
		new GCJ_B().solve();
	}

	void solve() throws IOException {
		String iname = "B-large (1).in";
		String oname = "output.txt";
		FastScanner sc = new FastScanner(new FileInputStream(iname));
		PrintStream out = new PrintStream(new FileOutputStream(new File(oname)));

		int T = sc.nextInt();
		for (int _t = 0; _t < T; _t++) {

			{
				N = sc.nextInt();
				nei = new ArrayList[N];
				for (int i = 0; i < nei.length; i++) {
					nei[i] = new ArrayList<Integer>();
				}
				for (int i = 0; i < N - 1; i++) {
					int x = sc.nextInt() - 1;
					int y = sc.nextInt() - 1;
					nei[x].add(y);
					nei[y].add(x);
				}

				md = new int[N][N];
				mc = new int[N][N];
				for (int i = 0; i < N; i++) {
					Arrays.fill(md[i], -1);
					Arrays.fill(mc[i], -1);
				}
			}

			int ret = N - 1;
			for (int r = 0; r < N; r++) {
				if (nei[r].size() >= 2) {
					int min = Integer.MAX_VALUE;
					for (int c1 : nei[r]) {
						for (int c2 : nei[r]) {
							if (c1 != c2) {
								int v = 0;
								v += dfs(r, c1) + dfs(r, c2);
								for (int c3 : nei[r]) {
									if (c3 != c1 && c3 != c2) {
										v += count(r, c3);
									}
								}
								min = Math.min(min, v);
							}
						}
					}
					ret = Math.min(ret, min);

				}
			}

			out.println("Case #" + (_t + 1) + ": " + ret);
		}
	}
	int N;
	ArrayList<Integer>[] nei;



	int[][] md, mc;
	int dfs(int p, int v) {
		if (md[p][v] != -1) {
			return md[p][v];
		} else {

			int ret = count(p, v) - 1;
			for (int c1 : nei[v]) {
				for (int c2 : nei[v]) {
					if (c1 != p && c2 != p && c1 != c2) {
						int r = 0;
						r += dfs(v, c1) + dfs(v, c2);
						for (int c3 : nei[v]) {
							if (c3 != c1 && c3 != c2 && c3 != p) {
								r += count(v, c3);
							}
						}
						ret = Math.min(ret, r);
					}
				}
			}
			return md[p][v] = ret;
		}
	}
	int count(int p, int v) {
		if (mc[p][v] != -1) {
			return mc[p][v];
		} else {
			int ret = 1;
			for (int c : nei[v]) {
				if (c != p) {
					ret += count(v, c);
				}
			}
			return mc[p][v] = ret;
		}
	}


	class FastScanner {

		private InputStream _stream;
		private byte[] _buf = new byte[1024];
		private int _curChar;
		private int _numChars;
		private StringBuilder _sb = new StringBuilder();

		FastScanner(InputStream stream) {
			this._stream = stream;
		}

		public int read() {
			if (_numChars == -1) throw new InputMismatchException();
			if (_curChar >= _numChars) {
				_curChar = 0;
				try {
					_numChars = _stream.read(_buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (_numChars <= 0) return -1;
			}
			return _buf[_curChar++];
		}

		public String next() {
			int c = read();
			while (isWhitespace(c)) {
				c = read();
			}
			_sb.setLength(0);
			do {
				_sb.appendCodePoint(c);
				c = read();
			} while (!isWhitespace(c));
			return _sb.toString();
		}

		public int nextInt() {
			return (int) nextLong();
		}
		public long nextLong() {
			int c = read();
			while (isWhitespace(c)) {
				c = read();
			}
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			long res = 0;
			do {
				if (c < '0' || c > '9') throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			} while (!isWhitespace(c));
			return res * sgn;
		}

		public boolean isWhitespace(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}
	}
}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
