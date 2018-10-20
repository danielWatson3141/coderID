import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class E {

	static long shift(long k) {
		return 1L << k;
	}

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new FileReader("A.in"));
		out = new PrintWriter("A.out");
		sc = new StringTokenizer("");
		int tc = nxtInt();
		for (int t = 1; t <= tc; t++) {
			int n = nxtInt();
			int m = nxtInt();
			long[] arr = new long[n];
			long[] dev = new long[n];
			long[][] diff = new long[n][n];
			for (int i = 0; i < n; i++) {
				char[] tmp = nxtCharArr();
				for (int j = m - 1; j > -1; j--) {
					if (tmp[j] == '1')
						arr[i] |= shift(m - j - 1);
				}
			}
			for (int i = 0; i < n; i++) {
				char[] tmp = nxtCharArr();
				for (int j = m - 1; j > -1; j--) {
					if (tmp[j] == '1')
						dev[i] |= shift(m - j - 1);
				}
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					for (int k = 0; k < m; k++) {
						boolean bit1 = (arr[i] & shift(k)) == 0;
						boolean bit2 = (dev[j] & shift(k)) == 0;
						if (bit1 == bit2)
							continue;
						diff[i][j] |= shift(k);
					}
				}
			}
			int ans = 99999999;
			for (int i = 0; i < n; i++) {
				long tmp = diff[0][i];
				boolean[] v = new boolean[n];
				v[i] = true;
				for (int j = 1; j < n; j++) {
					for (int k = 0; k < n; k++) {
						if (diff[j][k] == tmp) {
							if (!v[k]) {
								v[k] = true;
								break;
							}
						}
					}
				}
				boolean done = true;
				for (int j = 0; j < v.length; j++)
					done &= v[j];
				if (done)
					ans = Math.min(ans, Long.bitCount(tmp));
			}
			System.out.println("Case #" + t + ": "
					+ (ans < 99999999 ? ans : "NOT POSSIBLE"));
			out.println("Case #" + t + ": "
					+ (ans < 99999999 ? ans : "NOT POSSIBLE"));
		}
		br.close();
		out.close();
	}

	static BufferedReader br;
	static StringTokenizer sc;
	static PrintWriter out;

	static String nxtTok() throws IOException {
		while (!sc.hasMoreTokens()) {
			String s = br.readLine();
			if (s == null)
				return null;
			sc = new StringTokenizer(s.trim());
		}
		return sc.nextToken();
	}

	static int nxtInt() throws IOException {
		return Integer.parseInt(nxtTok());
	}

	static long nxtLng() throws IOException {
		return Long.parseLong(nxtTok());
	}

	static double nxtDbl() throws IOException {
		return Double.parseDouble(nxtTok());
	}

	static int[] nxtIntArr(int n) throws IOException {
		int[] a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = nxtInt();
		return a;
	}

	static long[] nxtLngArr(int n) throws IOException {
		long[] a = new long[n];
		for (int i = 0; i < n; i++)
			a[i] = nxtLng();
		return a;
	}

	static char[] nxtCharArr() throws IOException {
		return nxtTok().toCharArray();
	}
}