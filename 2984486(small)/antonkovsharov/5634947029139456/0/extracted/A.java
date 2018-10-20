import java.util.*;
import java.io.*;

public class A {
	FastScanner in;
	PrintWriter out;

	int ans, n, l;
	int[][] s, t;
	boolean[][][] ok;
	
	boolean good(int curBit) {
		for (int i = 0; i < n; i++) {
			boolean was = false;
			for (int j = 0; j < n; j++) {
				if ((curBit == 0 || ok[curBit - 1][i][j]) && s[i][curBit] == t[j][curBit]) {
					ok[curBit][i][j] = true;
					was = true;
				} else {
					ok[curBit][i][j] = false;
				}
			}
			if (!was) {
				return false;
			}
		}
		return true;
	}
	
	void gen(int curBit, int cntChange) {
		if (curBit == l) {
			if (cntChange < ans)
				ans = cntChange;
			return;
		}
		if (good(curBit))
			gen(curBit + 1, cntChange);
		for (int i = 0; i < n; i++)
			s[i][curBit] = 1 - s[i][curBit];
		if (good(curBit))
			gen(curBit + 1, cntChange + 1);
		for (int i = 0; i < n; i++)
			s[i][curBit] = 1 - s[i][curBit];
	}
	
	public void solve() throws IOException {
		n = in.nextInt();
		l = in.nextInt();
		ans = Integer.MAX_VALUE;
		s = new int[n][];
		t = new int[n][];
		for (int i = 0; i < n; i++) {
			char tmp[] = in.next().toCharArray();
			s[i] = new int[tmp.length];
			for (int j = 0; j < l; j++)
				s[i][j] = tmp[j] - '0';
		}
		for (int i = 0; i < n; i++) {
			char tmp[] = in.next().toCharArray();
			t[i] = new int[tmp.length];
			for (int j = 0; j < l; j++)
				t[i][j] = tmp[j] - '0';
		}
		ok = new boolean[l][n][n];
		for (int i = 0; i < n; i++)
			Arrays.fill(ok[0][i], true);
		gen(0, 0);
		if (ans == Integer.MAX_VALUE)
			out.println("NOT POSSIBLE");
		else
			out.println(ans);
	}

	public void run() {
		try {
			in = new FastScanner(new File("task.in"));
			out = new PrintWriter(new File("task.out"));

			int tests = in.nextInt();

			for (int i = 0; i < tests; ++i) {
				out.print("Case #" + (i + 1) + ": ");
				solve();
			}

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
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

	public static void main(String[] arg) {
		new A().run();
	}
}