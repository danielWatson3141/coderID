import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class B {

	static int[][] edg;
	static boolean[] v;

	static void dfs(int u, int mask) {
		v[u] = true;
		for (int i = 0; i < edg.length; i++) {
			if (edg[i][0] == u) {
				if ((mask & (1 << edg[i][1])) != 0)
					continue;
				if (!v[edg[i][1]])
					dfs(edg[i][1], mask);
			} else if (edg[i][1] == u) {
				if ((mask & (1 << edg[i][0])) != 0)
					continue;
				if (!v[edg[i][0]])
					dfs(edg[i][0], mask);
			}
		}
	}

	static boolean isConnected(int mask) {
		v = new boolean[edg.length + 1];
		for (int i = 0; i < v.length; i++) {
			if ((mask & (1 << i)) != 0)
				continue;
			dfs(i, mask);
			break;
		}
		for (int i = 0; i < v.length; i++) {
			if ((mask & (1 << i)) != 0)
				continue;
			if (!v[i])
				return false;
		}
		return true;
	}

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new FileReader("B.in"));
		out = new PrintWriter("B.out");
		sc = new StringTokenizer("");
		int tc = nxtInt();
		for (int t = 1; t <= tc; t++) {
			int n = nxtInt();
			edg = new int[n - 1][2];
			for (int i = 0; i < n - 1; i++)
				for (int j = 0; j < 2; j++)
					edg[i][j] = nxtInt() - 1;
			int min = 9999999;
			for (int mask = 0; mask < 1 << n; mask++) {
				int[] cnt = new int[n];
				for (int i = 0; i < n - 1; i++) {
					if ((mask & (1 << edg[i][0])) != 0)
						continue;
					if ((mask & (1 << edg[i][1])) != 0)
						continue;
					cnt[edg[i][0]]++;
					cnt[edg[i][1]]++;
				}
				boolean done = isConnected(mask);
				if (done) {
					done = false;
					for (int i = 0; i < n && !done; i++) {
						if ((mask & (1 << i)) != 0)
							continue;
						boolean tmp = true;
						for (int j = 0; j < n; j++) {
							if ((mask & (1 << j)) != 0)
								continue;
							if (i == j)
								tmp &= cnt[j] == 0 || cnt[j] == 2;
							else
								tmp &= cnt[j] == 1 || cnt[j] == 3;
						}
						done |= tmp;
					}
				}
				if (done)
					min = Math.min(min, Integer.bitCount(mask));
			}
			System.out.println("Case #" + t + ": " + min);
			out.println("Case #" + t + ": " + min);
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