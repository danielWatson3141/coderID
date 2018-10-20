import java.io.*;
import java.util.*;

public class ProblemA {

	static boolean help(String[] a, String[] b) {
		boolean fl = true;
		for (int i = 0; i < a.length; i++) {
			if (!a[i].equals(b[i]))
				fl = false;
		}
		return fl;
	}

	static String[] Mask(String[] c, String mask, int n, int l) {
		for (int i = 0; i < n; i++) {
			String m = "";
			for (int o = 0; o < l; o++) {
				if (mask.charAt(o) == '1') {
					if (c[i].charAt(o) == '1')
						m += "0";
					else
						m += "1";
				} else if (c[i].charAt(o) == '1')
					m += "1";
				else
					m += "0";
			}
			c[i] = m;
		}
		return c;
	}
	
	static String [] dubl(String [] a) {
		String [] c = new String [a.length];
		for (int i = 0; i < a.length; i++) 
			c[i] = a[i];
		return c;
	}

	static void solve() throws IOException {
		int m = nextInt();
		for (int t = 1; t <= m; t++) {
			int n = nextInt();
			int l = nextInt();
			String[] a = new String[n];
			String[] b = new String[n];
			for (int i = 0; i < n; i++)
				a[i] = nextToken();
			for (int i = 0; i < n; i++)
				b[i] = nextToken();
			Arrays.sort(a);
			Arrays.sort(b);
			String [] c = dubl(a); 
			int min = l + 1;
			if (help(a, b) == true) {
				out.println("Case #" + t + ": " + "0");
				continue;
			}
			for (int i = 0; i < n; i++) {
				String w = a[0];
				String e = b[i];
				String mask = "";
				int q = 0;
				for (int j = 0; j < w.length(); j++) {
					if (w.charAt(j) == e.charAt(j))
						mask += "0";
					else {
						mask += "1";
						q++;
					}
				}
				c = Mask(c, mask, n, l);
				Arrays.sort(c);
				if (help(b, c) == true) 
					if (q < min)
						min = q;
				c = dubl(a);
			}
			if (min == l + 1) out.println("Case #" + t + ": " + "NOT POSSIBLE");
			else out.println("Case #" + t + ": " + min);
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