import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;


public class B {

	static StringTokenizer st;
	static BufferedReader br;
	static PrintWriter pw;
	static ArrayList<Integer>[]ages;
	static boolean[]used;
	static boolean[]leaf;
	static int[][]dp;
	static int[]p, childer;
	public static void main(String[] args) throws IOException{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int test = nextInt();
		int t = 0;
		while (test-->0) {
			int n = nextInt();
			t++;
			ages = new ArrayList[n+1];
			for (int i = 1; i <= n; i++) {
				ages[i] = new ArrayList<>();
			}
			for (int i = 1; i < n; i++) {
				int v1 = nextInt();
				int v2 = nextInt();
				ages[v1].add(v2);
				ages[v2].add(v1);
			}
			childer = new int[n+1];
			int INF = (int)1e9;
			int ans = INF;
			dp = new int[n+1][2];
			leaf = new boolean[n+1];
			used = new boolean[n+1];
			p = new int[n+1];
			for (int root = 1; root <= n; root++) {
				Arrays.fill(leaf, true);
				Arrays.fill(used, false);
				Arrays.fill(childer, 0);
				dfs(root);
				for (int i = 1; i <= n; i++) {
					dp[i][0] = dp[i][1] = INF;
				}
				for (int i = 1; i <= n; i++) {
					if (leaf[i])
						dp[i][0] = 0;
				}
				Arrays.fill(used, false);
				Arrays.fill(p, 0);
				dfs2(root);
				ans = Math.min(ans, Math.min(dp[root][0], dp[root][1]));
			}
			pw.println("Case #"+t+": "+ans);
		}
		pw.close();
	}

	private static void dfs2(int v) {
		used[v] = true;
		for (int to : ages[v]) {
			if (!used[to]) {
				p[to] = v;
				dfs2(to);
			}
		}
		if (!leaf[v]) {
			dp[v][0] = childer[v]-1;
			int size = ages[v].size();
			for (int i = 0; i < size; i++) {
				int v1 = ages[v].get(i);
				if (v1==p[v])
					continue;
				for (int j = i+1; j < size; j++) {
					int v2 = ages[v].get(j);
					if (v2==p[v])
						continue;
					dp[v][1] = Math.min(dp[v][1], Math.min(dp[v1][0], dp[v1][1])+Math.min(dp[v2][0], dp[v2][1])+childer[v]-1-childer[v1]-childer[v2]);
				}
			}
		}
	}

	private static void dfs(int v) {
		used[v] = true;
		for (int to : ages[v]) {
			if (!used[to]) {
				leaf[v] = false;
				dfs(to);
				childer[v] += childer[to];
			}
		}
		childer[v]++;
	}

	private static int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	private static long nextLong() throws IOException {
		return Long.parseLong(next());
	}
	private static double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	private static String next() throws IOException{
		while (st==null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine());
		return st.nextToken();
	}

}
