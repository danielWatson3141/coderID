import java.io.*;
import java.util.*;

public class B {
	public static void main(String[] args) {
		new B().run();
	}

	BufferedReader br;
	StringTokenizer in;
	PrintWriter out;

	public String nextToken() throws IOException {
		while (in == null || !in.hasMoreTokens()) {
			in = new StringTokenizer(br.readLine());
		}
		return in.nextToken();
	}

	public int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	ArrayList<Integer>[] g;
	int[] ans;
	int[] size;

	public void dfs(int u) {
		ans[u] = Integer.MAX_VALUE;
		size[u] = 1;
		int m1 = Integer.MAX_VALUE;
		int m2 = Integer.MAX_VALUE;
		for (int v : g[u]) {
			if (ans[v] != -1)
				continue;
			dfs(v);
			if (ans[v] - size[v] < m1) {
				m2 = m1;
				m1 = ans[v] - size[v];
			} else if (ans[v] - size[v] < m2) {
				m2 = ans[v] - size[v];
			}
			size[u] += size[v];
		}

		if (m2 == Integer.MAX_VALUE)
			ans[u] = size[u] - 1;
		else
			ans[u] = Math.min(size[u] - 1 + m1 + m2, size[u] - 1);
	}

	public void solve() throws IOException {
		int n = nextInt();
		g = new ArrayList[n];

		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<Integer>();
		}

		size = new int[n];
		ans = new int[n];
		Arrays.fill(ans, -1);
		for (int i = 0; i < n - 1; i++) {
			int u = nextInt() - 1;
			int v = nextInt() - 1;
			g[u].add(v);
			g[v].add(u);
		}

		int best = Integer.MAX_VALUE;
		for (int i = 0; i < n; i++) {
			Arrays.fill(ans, -1);
			dfs(i);

			System.err.println(i + " " + ans[i]);

			best = Math.min(best, ans[i]);
		}

		out.println(best);
	}

	public void run() {
		try {
			br = new BufferedReader(new FileReader("input.txt"));
			out = new PrintWriter("output.txt");

			int t = nextInt();
			for (int i = 0; i < t; i++) {
				out.print(String.format("Case #%d: ", i + 1));
				solve();
			}

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
