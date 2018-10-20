import java.io.*;
import java.util.*;

public class ProblemC {

	static boolean help(int [] a, int[] b) {
		boolean fl = true;
		for (int i = 0; i < a.length; i++) {
			if (a[i] != b[i])
				fl = false;
		}
		return fl;
	}
	
	static void solve() throws IOException {
		int m = nextInt();
		for (int t = 1; t <= m; t++) {
			int n = nextInt();
			int [] a = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = i;
			}
			int [] b = new int[n];
			for (int i = 0; i < n; i++) {
				b[i] = nextInt();
			}
			
			if (help(a, b)) {
				out.println("Case #" + t + ": " + "BAD");
			} else
				out.println("Case #" + t + ": " + "GOOD");
		}	
	}

	public static void main(String[] args) throws Exception {
		File file = new File("a.in");
		InputStream input = System.in;
		PrintStream output = System.out;
		if (file.exists() && file.canRead()) {
			input = new FileInputStream(file);
			output = new PrintStream("a.out");
		}
		br = new BufferedReader(new InputStreamReader(input));
		out = new PrintWriter(output);
		solve();
		out.close();
	}

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

	static boolean hasNextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String line = br.readLine();
			if (line == null) {
				return false;
			}
			st = new StringTokenizer(line);
		}
		return true;
	}

	static String nextToken() throws IOException {
		return hasNextToken() ? st.nextToken() : null;
	}

	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}