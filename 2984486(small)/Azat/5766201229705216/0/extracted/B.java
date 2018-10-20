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
	static boolean[]is, used;
	static int[]child;
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
			int ans = (int)1e9;
			for (int mask = 0; mask < (1 << n)-1; mask++) {
				is = new boolean[n+1];
				Arrays.fill(is, true);
				for (int i = 0; i < n; i++) {
					if ((mask & (1 << i)) != 0) {
						is[i+1] = false;
					}
				}
				int v = 0;
				used = new boolean[n+1];
				for (int i = 1; i <= n; i++) {
					if (is[i]) {
						v = i;
						break;
					}
				}
				child = new int[n+1];
				dfs(v);
				boolean tree = true;
				for (int i = 1; i <= n; i++) {
					if (is[i] && !used[i])
						tree = false;
				}
				if (tree) {
					for (int root = 1; root <= n; root++) {
						if (is[root]) {
							Arrays.fill(child, 0);
							Arrays.fill(used, false);
							dfs(root);
							boolean ok = true;
							for (int i = 1; i <= n; i++) {
								if (is[i]) {
									if (child[i] != 0 && child[i] != 2) {
										ok = false;
										break;
									}
								}
							}
							if (ok) {
								ans = Math.min(ans, Integer.bitCount(mask));
							}
						}
					}
				}
			}
			pw.println("Case #"+t+": "+ans);
		}
		pw.close();
	}

	private static void dfs(int v) {
		used[v] = true;
		for (int to : ages[v]) {
			if (!used[to] && is[to]) {
				child[v]++;
				dfs(to);
			}
		}
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
