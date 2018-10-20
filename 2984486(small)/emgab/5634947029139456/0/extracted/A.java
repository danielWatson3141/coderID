import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class A {

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new FileReader("A.in"));
		out = new PrintWriter("A.out");
		sc = new StringTokenizer("");
		int tc = nxtInt();
		for (int t = 1; t <= tc; t++) {
			int n = nxtInt();
			int m = nxtInt();
			int[] arr = new int[n];
			int[] dev = new int[n];
			for (int i = 0; i < n; i++) {
				char[] tmp = nxtCharArr();
				for (int j = m - 1; j > -1; j--) {
					if (tmp[j] == '1')
						arr[i] |= (1 << (m - j - 1));
				}
			}
			for (int i = 0; i < n; i++) {
				char[] tmp = nxtCharArr();
				for (int j = m - 1; j > -1; j--) {
					if (tmp[j] == '1')
						dev[i] |= (1 << (m - j - 1));
				}
			}
			Arrays.sort(dev);
			int ans = 99999999;
			for (int mask = 0; mask < 1 << m; mask++) {
				int[] tmp = Arrays.copyOf(arr, n);
				for (int i = 0; i < m; i++) {
					if ((mask & (1 << i)) == 0)
						continue;
					for (int j = 0; j < n; j++)
						tmp[j] ^= (1 << i);
				}
				Arrays.sort(tmp);
				boolean done = true;
				for (int i = 0; i < n && done; i++) {
					done &= tmp[i] == dev[i];
				}
				if (done)
					ans = Math.min(ans, Integer.bitCount(mask));
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