import java.util.List;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Locale;
import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.File;
import java.util.StringTokenizer;
import java.io.FilenameFilter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		InputStream inputStream;
		try {
			final String regex = "B-(small|large).*[.]in";
			File directory = new File(".");
			File[] candidates = directory.listFiles(new FilenameFilter() {
				public boolean accept(File dir, String name) {
					return name.matches(regex);
				}
			});
			File toRun = null;
			for (File candidate : candidates) {
				if (toRun == null || candidate.lastModified() > toRun.lastModified())
					toRun = candidate;
			}
			inputStream = new FileInputStream(toRun);
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("b.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskB solver = new TaskB();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskB {
	public void solve(int testNumber, InputReader in, PrintWriter out) {
		int n = in.nextInt();
		List<Integer>[] tree = new List[n];
		for (int i = 0; i < n; i++) {
			tree[i] = new ArrayList<>();
		}
		for (int i = 0; i < n - 1; i++) {
			int x = in.nextInt() - 1;
			int y = in.nextInt() - 1;
			tree[x].add(y);
			tree[y].add(x);
		}

		int res = n;

		for (int root = 0; root < n; root++) {
			int[] sizes = new int[n];
			dfs1(tree, sizes, root, -1);

			int cur = dfs2(tree, sizes, root, -1);
			res = Math.min(res, cur);
		}

		out.println("Case #" + testNumber + ": " + res);
	}

	int dfs1(List<Integer>[] tree, int[] sizes, int u, int p) {
		sizes[u] = 1;
		for (int v : tree[u]) {
			if (v == p)
				continue;
			sizes[u] += dfs1(tree, sizes, v, u);
		}
		return sizes[u];
	}

	int dfs2(List<Integer>[] tree, int[] sizes, int u, int p) {
		List<Integer> list = new ArrayList<>();
		List<Integer> sz = new ArrayList<>();
		int sum = 0;
		for (int v : tree[u]) {
			if (v == p)
				continue;
			list.add(dfs2(tree, sizes, v, u));
			sz.add(sizes[v]);
			sum += sizes[v];
		}

		int res = sizes[u] - 1;

		for (int i = 0; i < sz.size(); i++) {
			for (int j = i + 1; j < sz.size(); j++) {
				int cur = list.get(i) + list.get(j) + sum - sz.get(i) - sz.get(j);
				res = Math.min(res, cur);
			}
		}

		return res;
	}
}

class InputReader {
	public BufferedReader reader;
	public StringTokenizer tokenizer;

	public InputReader(InputStream stream) {
		reader = new BufferedReader(new InputStreamReader(stream));
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
}

