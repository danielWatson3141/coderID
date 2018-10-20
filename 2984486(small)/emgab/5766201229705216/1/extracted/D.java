import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class D {

	static ArrayList<Integer>[] adj;
	static int[][] memo;
	static int[] dp;

	static int cnt(int u, int p) {
		if (memo[u][p] != -1)
			return memo[u][p];
		int ans = 1;
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u].get(i);
			if (v != p)
				ans += cnt(v, u);
		}
		return memo[u][p] = ans;
	}

	static int solve(int u, int p) {
		if (dp[u] != -1)
			return dp[u];
		int min = 0;
		int sz = adj[u].size();
		for (int i = 0; i < sz; i++) {
			int v = adj[u].get(i);
			if (v != p)
				min += cnt(v, u);
		}
		int tot = min;
		for (int i = 0; i < sz; i++) {
			int x = adj[u].get(i);
			if (x == p)
				continue;
			for (int j = 0; j < sz; j++) {
				if (i == j)
					continue;
				int y = adj[u].get(j);
				if (y == p)
					continue;
				min = Math.min(min, tot - cnt(x, u) - cnt(y, u) + solve(x, u)
						+ solve(y, u));
			}
		}
		return dp[u] = min;
	}

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new FileReader("B.in"));
		out = new PrintWriter("B.out");
		sc = new StringTokenizer("");
		int tc = nxtInt();
		for (int t = 1; t <= tc; t++) {
			int n = nxtInt();
			adj = new ArrayList[n];
			for (int i = 0; i < n; i++)
				adj[i] = new ArrayList<>();
			for (int i = 0; i < n - 1; i++) {
				int x = nxtInt() - 1;
				int y = nxtInt() - 1;
				adj[x].add(y);
				adj[y].add(x);
			}
			memo = new int[n][n];
			dp = new int[n];
			for (int[] a : memo)
				Arrays.fill(a, -1);
			int min = 99999999;
			for (int i = 0; i < n; i++) {
				Arrays.fill(dp, -1);
				min = Math.min(min, solve(i, i));
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