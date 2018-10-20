import java.io.*;
import java.util.*;

public class B {

	public static void main(String[] args) {
		new B().run();
	}

	private void run() {
		Locale.setDefault(Locale.US);
		try {
			br = new BufferedReader(new FileReader(FNAME + ".in"));
			out = new PrintWriter(FNAME + ".out");
			solve();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(566);
		}
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof = false;
	Random rand = new Random(12345);

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken();
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	String FNAME = "b";
	ArrayList<Integer>[] g;
	int[] a;
	int[] size;

	private void solve() throws IOException {
		int testn = nextInt();
		for (int test = 1; test <= testn; test++) {
			out.print("Case #" + test + ": ");
			int n = nextInt();
			g = new ArrayList[n];
			for (int i = 0; i < g.length; i++) {
				g[i] = new ArrayList<>();
			}
			for (int i = 0; i < n - 1; i++) {
				int x = nextInt() - 1;
				int y = nextInt() - 1;
				g[x].add(y);
				g[y].add(x);
			}
			int ans = Integer.MAX_VALUE / 2;
			a = new int[n];
			size = new int[n];
			for (int root = 0; root < g.length; root++) {
				Arrays.fill(a, Integer.MAX_VALUE / 2);
				dfs(root, root);
				ans = Math.min(ans, a[root]);
			}
			out.println(ans);
		}
	}

	private void dfs(int x, int parent) {
		int children = 0;
		int sum = 0;
		int max1 = Integer.MIN_VALUE / 2;
		int max2 = Integer.MIN_VALUE / 2;
		for (int i : g[x]) {
			if (i != parent) {
				dfs(i, x);
				children++;
				sum += size[i];
				int diff = size[i] - a[i];
				if (diff > max1) {
					max2 = max1;
					max1 = diff;
				} else if (size[i] > max2) {
					max2 = diff;
				}
			}
		}
		if (children >= 2) {
			a[x] = Math.min(a[x], sum - max1 - max2);
		}
		if (children == 0) {
			a[x] = 0;
		}
		a[x] = Math.min(a[x], sum);
		size[x] = sum + 1;
	}

}
