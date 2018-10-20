package round1A_2014;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BLarge {
	InputReader in;

	ArrayList<Integer> g[];
	boolean[] visited;
	boolean[][] direction;
	int[] children;
	int[] firstChildren;
	int[] memo;

	public void dfs(int i) {
		for (int next : g[i]) {
			if (!visited[next]) {
				visited[next] = true;

				direction[i][next] = true;
				direction[next][i] = false;
				firstChildren[i]++;
				dfs(next);
				children[i] += (1 + children[next]);
			}
		}
	}

	int N;

	public int go(int index) {

		if (memo[index] != -1)
			return memo[index];

		if (firstChildren[index] == 0) {
			return memo[index] = 0;
		} else if (firstChildren[index] == 1) {
			return memo[index] = children[index];
		}

		ArrayList<Integer> childs = new ArrayList<Integer>(firstChildren[index]);
		for (int next : g[index]) {
			if (direction[index][next]) {
				childs.add(next);
			}
		}
		int ans = Math.min(N,children[index]);
		for (int i = 0; i < firstChildren[index]; i++) {
			for (int j = i + 1; j < firstChildren[index]; j++) {
				int firstChild = childs.get(i);
				int secondChild = childs.get(j);
				ans = Math.min(ans, go(firstChild) + go(secondChild)
						+ children[index] - children[firstChild]
						- children[secondChild] - 2);
			}
		}
		return memo[index] = ans;
	}

	public String solve() throws Exception {

		N = in.nextInt();
		g = new ArrayList[N];
		for (int i = 0; i < N; i++)
			g[i] = new ArrayList<Integer>();
		for (int i = 0; i < N - 1; i++) {
			int x = in.nextInt() - 1;
			int y = in.nextInt() - 1;
			g[x].add(y);
			g[y].add(x);
		}

		direction = new boolean[N][N];
		visited = new boolean[N];
		children = new int[N];
		firstChildren = new int[N];
		memo = new int[N + 4];

		int ans = N;
		for (int root = 0; root < N; root++) {
			Arrays.fill(visited, false);
			visited[root] = true;
			Arrays.fill(children, 0);
			Arrays.fill(firstChildren, 0);
			dfs(root);
			Arrays.fill(memo, -1);
			ans = Math.min(ans, go(root));
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
		new BLarge().answer();
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
