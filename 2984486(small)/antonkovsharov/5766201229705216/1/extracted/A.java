import java.util.*;
import java.io.*;

public class A {
	FastScanner in;
	PrintWriter out;

	ArrayList<Integer>[] g;
	int[] dp;
	int[] cnt;
	
	void dfs(int v, int p) {
		int countChildren = 0, best0 = -1, best1 = -1;
		for (int u : g[v]) {
			if (u != p) {
				dfs(u, v);
				if (best0 == -1 || cnt[u] >= cnt[best0]) {
					best1 = best0;
					best0 = u;
				} else if (best1 == -1 || cnt[u] >= cnt[best1]) {
					best1 = u;
				}
				countChildren++;
			}
		}
		cnt[v] = 1;
		for (int u : g[v]) {
			if (u != p) {
				if (countChildren == 1)
					dp[v] += cnt[u] + dp[u];
				else {
					if (u == best0 || u == best1)
					{
						cnt[v] += cnt[u];
						dp[v] += dp[u];
					} else {
						dp[v] += cnt[u] + dp[u];
					}
				}
			}
		}
	}
	
	public void solve() throws IOException {
		int n = in.nextInt();
		g = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<Integer>();
		}
		for (int i = 0; i < n - 1; i++) {
			int x = in.nextInt() - 1, y = in.nextInt() - 1;
			g[x].add(y);
			g[y].add(x);
		}
		int ans = Integer.MAX_VALUE;
		for (int root = 0; root < n; root++) {
			dp = new int[n];
			cnt = new int[n];
			dfs(root, -1);
			if (dp[root] < ans)
				ans = dp[root];
		}
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