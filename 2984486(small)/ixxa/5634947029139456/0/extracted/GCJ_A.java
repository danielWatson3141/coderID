import java.io.*;
import java.math.*;
import java.util.*;

public class GCJ_A {

	public static void main(String[] args) throws Exception {
		new GCJ_A().solve();
		// new FileInputStream(new File("input.txt")),
		// new PrintStream(new FileOutputStream(new File("output.txt"))));
	}

	void solve() throws IOException {
		String iname = "A-small-attempt1.in";
		String oname = "output.txt";
		FastScanner sc = new FastScanner(new FileInputStream(iname));
		PrintStream out = new PrintStream(new FileOutputStream(new File(oname)));

		int T = sc.nextInt();

		for (int _t = 0; _t < T; _t++) {
			// N,L,A,B
			N = sc.nextInt();
			L = sc.nextInt();
			A = new long[N];
			B = new long[N];
			for (int i = 0; i < N; i++) {
				A[i] = Long.parseLong(sc.next(), 2);
			}
			for (int i = 0; i < N; i++) {
				B[i] = Long.parseLong(sc.next(), 2);
			}
			Arrays.sort(A);
			Arrays.sort(B);

			int d = dfs(L - 1);

			out.println("Case #" + (_t + 1) + ": " +
					(d >= 0 ? d : "NOT POSSIBLE"));
		}
	}
	int N, L;
	long[] A, B;

	int dfs0(int _i) {
		int ret = Integer.MAX_VALUE;
		for (int mask = 0; mask < 1 << L; mask++) {
			int c = 0;
			for (int bi = 0; bi < L; bi++) {
				if ((mask >> bi & 1) == 1) {
					flip(bi);
					c++;
				}
			}

			for (int i = 0; i < N; i++) {
				if (A[i] != B[i]) {
					c = Integer.MAX_VALUE;
				}
			}
			ret = Math.min(ret, c);

			for (int bi = 0; bi < L; bi++) {
				if ((mask >> bi & 1) == 1) {
					flip(bi);
				}
			}
		}
		return ret;
	}

	void test() {
		System.out.println("---");
		for (int i = 0; i < N; i++) {
			System.out.println(Long.toBinaryString(A[i]));
		}
	}

	int dfs(int bi) {

		if (!check(bi)) {
			return -1;
		}

		if (bi == -1) {
			return 0;
		} else {
			int r1 = dfs(bi - 1);

			flip(bi);
			int r2 = dfs(bi - 1);
			flip(bi);
			if (r2 != -1) {
				r2++;
			}

			return mmin(r1, r2);
		}
	}

	void flip(int bi) {
		for (int i = 0; i < N; i++) {
			A[i] ^= 1L << bi;
		}
		Arrays.sort(A);
	}


	boolean check(int bi) {
		for (int i = 0; i < N; i++) {
			if ((A[i] >> (bi + 1) != (B[i] >> (bi + 1)))) {
				return false;
			}
		}
		return true;
	}
	int mmin(int a, int b) {
		if (a == -1) {
			return b;
		} else if (b == -1) {
			return a;
		} else {
			return Math.min(a, b);
		}
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
