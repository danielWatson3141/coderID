import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class FullBinaryTree {
	static String problem = "B2";
	static ArrayList<Integer> adj[];

	static class P implements Comparable<P> {
		int v, index, size;

		public P(int vv, int ii) {
			v = vv;
			index = ii;
		}

		@Override
		public int compareTo(P arg0) {
			return v - arg0.v;
		}
	}

	static int go3(P[] values, int index, int taken, int len) {
		if (index == len) {
			if (taken == 2 || taken == 0)
				return 0;
			return 1 << 28;
		}
		int way1 = values[index].v + go3(values, index + 1, taken + 1, len);
		int way2 = values[index].size + go3(values, index + 1, taken, len);
		return Math.min(way1, way2);
	}

	static int go(int node, int parent) {
		P[] values = new P[adj[node].size()];
		int k = 0;
		for (int x : adj[node]) {
			if (x == parent)
				continue;
			values[k++] = new P(go(x, node), x);
		}
		Arrays.sort(values, 0, k);
		if (k == 0)
			return 0;
		if (k == 1) {
			return go2(values[0].index, node);
		}
		for (int i = 0; i < k; i++)
			values[i].size = go2(values[i].index, node);

		return go3(values, 0, 0, k);
	}

	static int go2(int node, int parent) {
		int size = 1;
		for (int x : adj[node]) {
			if (x == parent)
				continue;
			size += go2(x, node);
		}
		return size;
	}
	public static void main(String[] args) throws Exception {
//		 InputReader r = new InputReader(System.in);
//		 PrintWriter out = new PrintWriter(System.out);
		InputReader r = new InputReader(new FileReader(problem + ".in"));
		PrintWriter out = new PrintWriter(new FileWriter(problem
				+ "Solution.out"));
		int T = r.nextInt();
		int test = 1;
		while (T-- > 0) {
			int n = r.nextInt();
			adj = new ArrayList[n];
			for (int i = 0; i < n; i++) {
				adj[i] = new ArrayList<Integer>();
			}
			for (int i = 0; i < n - 1; i++) {
				int from = r.nextInt() - 1;
				int to = r.nextInt() - 1;
				adj[from].add(to);
				adj[to].add(from);
			}
			int res = 1 << 28;
			for (int i = 0; i < n; i++) {
				res = Math.min(res, go(i, -1));
			}
			out.printf("Case #%d: %d\n", test++, res);
		}
		out.close();
	}

	static class InputReader {
		private BufferedReader reader;
		private StringTokenizer tokenizer;

		public InputReader(InputStream stream) {
			reader = new BufferedReader(new InputStreamReader(stream));
			tokenizer = null;
		}

		public InputReader(FileReader stream) {
			reader = new BufferedReader(stream);
			tokenizer = null;
		}

		public String nextLine() {
			try {
				return reader.readLine();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				return null;
			}
		}

		public String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(reader.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public long nextLong() {
			return Long.parseLong(next());
		}
	}
}
