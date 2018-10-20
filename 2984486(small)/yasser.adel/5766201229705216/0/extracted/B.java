package round1A_2014;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class B {
	InputReader in;

	boolean[] removed;
	boolean[] visit;
	ArrayList<Integer> g[];

	public int dfs(int cur) {

		int all = 1;
		int direct = 0;
		for (int next : g[cur]) {
			if (!removed[next] && !visit[next]) {
				direct++;
				visit[next] = true;
				all += dfs(next);
			}
		}
		if (direct != 0 && direct != 2) {
			all = 1 << 25;
		}
		return Math.min(1<<25, all);
	}

	public String solve() throws Exception {

		int N = in.nextInt();
		g = new ArrayList[N];
		for (int i = 0; i < N; i++)
			g[i] = new ArrayList<Integer>();
		for (int i = 0; i < N - 1; i++) {
			int x = in.nextInt() - 1;
			int y = in.nextInt() - 1;
			g[x].add(y);
			g[y].add(x);
		}

		removed = new boolean[N];
		visit = new boolean[N];
		int ans = N;

		for (int root = 0; root < N; root++) {

			for (int mask = 0; mask < (1 << N); mask++) {
				Arrays.fill(removed, false);
				for (int i = 0; i < N; i++) {
					if ((mask & (1 << i)) != 0) {
						removed[i] = true;
					}
				}
				if (removed[root])
					continue;
				Arrays.fill(visit, false);
				visit[root] = true;
				int cnt = dfs(root);
				if (cnt == 1 << 25)
					continue;
				ans = Math.min(ans, N - cnt);
			}
		}
		return ans + "";
	}

	public void answer() throws Exception {
		in = new InputReader("in.in");
		FileWriter out = new FileWriter("out.out");
		int t = in.nextInt();
		for (int i = 1; i <= t; i++) {
			out.write("Case #" + i + ": " + solve() + "\n");
		}
		out.close();
	}

	public static void main(String[] args) throws Exception {
		new B().answer();
	}

	static class InputReader {
		BufferedReader in;
		StringTokenizer st;

		public InputReader(String filename) throws IOException {
			in = new BufferedReader(new FileReader(filename));
			st = new StringTokenizer(in.readLine());

		}

		public String next() throws IOException {

			while (!st.hasMoreElements())
				st = new StringTokenizer(in.readLine());
			return st.nextToken();
		}

		public int nextInt() throws NumberFormatException, IOException {
			return Integer.parseInt(next());
		}

		public long nextLong() throws NumberFormatException, IOException {
			return Long.parseLong(next());
		}
	}
}
