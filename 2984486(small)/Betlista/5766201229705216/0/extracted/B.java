import static java.lang.Integer.parseInt;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.StringTokenizer;

public class B {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = parseInt(br.readLine());
		StringTokenizer tok;
		for (int ii = 1; ii <= T; ii++) {
			int N = parseInt(br.readLine());
			int[] x = new int[N - 1];
			int[] y = new int[N - 1];
			for (int i = 0; i < N - 1; i++) {
				tok = new StringTokenizer(br.readLine());
				x[i] = parseInt(tok.nextToken());
				y[i] = parseInt(tok.nextToken());
			}
			// if (ii == 16) {
			// System.out.println(N);
			// for (int i = 0; i < x.length; i++) {
			// System.out.printf("%d %d\n", x[i], y[i]);
			// }
			// }
			int res = solve(N, x, y);
			System.out.printf("Case #%d: %d\n", ii, res);
		}
	}

	static int solve(int N, int[] x, int[] y) {
		LinkedList<Integer>[] g = new LinkedList[N + 1];
		for (int i = 0; i <= N; i++) {
			g[i] = new LinkedList<Integer>();
		}
		for (int i = 0; i < N - 1; i++) {
			g[x[i]].add(y[i]);
			g[y[i]].add(x[i]);
		}

		// for each root candidate
		int min = N - 1; // 1 vertex tree is full
		for (int i = 1; i <= N; i++) {
			int children = foundChildren(g, i, 0);
			if (children == 0) {
				return 0;
			}
			if (children == 1) {
				int tmp = count(g, i, 0) - 1;
				if (tmp < min) {
					min = tmp;
				}
				continue;
			}
			// if (g[i].size() < 3) {
			// at most 2 children
			for (int child1 = 0; child1 < g[i].size(); child1++) {
				for (int child2 = child1 + 1; child2 < g[i].size(); child2++) {
					int ch1 = g[i].get(child1);
					int ch2 = g[i].get(child2);
					// System.out.printf(
					// "trying root: %d, child1: %d, child2: %d\n", i,
					// ch1, ch2);
					int r1 = tryRoot(g, ch1, i);
					int r2 = tryRoot(g, ch2, i);
					int o = 0;
					for (int otherChild = 0; otherChild < g[i].size(); otherChild++) {
						if (otherChild == child1 || otherChild == child2) {
							continue;
						}
						o += count(g, g[i].get(otherChild), i);
					}
					if (r1 + r2 + o < min) {
						min = r1 + r2 + o;
					}
				}
			}
			// }
		}
		return min;
	}

	private static int tryRoot(LinkedList<Integer>[] g, int from, int prev) {
		int children = foundChildren(g, from, prev);
		if (children == 0) {
			return 0; // is leaf
		}
		if (children == 1) {
			// need to be removed
			return count(g, from, prev) - 1;
		}
		// if (children == 2) {
		assert (children >= 2);
		// TODO:
		int min = Integer.MAX_VALUE;
		for (int child1 = 0; child1 < g[from].size(); child1++) {
			int ch1 = g[from].get(child1);
			if (ch1 == prev)
				continue;
			for (int child2 = child1 + 1; child2 < g[from].size(); child2++) {
				int ch2 = g[from].get(child2);
				if (ch2 == prev)
					continue;
				int tmp = 0;
				// System.out.printf(
				// "   trying root: %d, child1: %d, child2: %d\n", from,
				// ch1, ch2);
				int r1 = tryRoot(g, ch1, from);
				tmp += r1;
				int r2 = tryRoot(g, ch2, from);
				tmp += r2;
				for (int other = 0; other < g[from].size(); ++other) {
					int och = g[from].get(other);
					if (och == prev || other == child1 || other == child2) {
						continue;
					}
					tmp += count(g, och, from);
				}
				if (tmp < min) {
					min = tmp;
				}
			}
		}
		return min;
		// }
	}

	private static int count(LinkedList<Integer>[] g, int from, int prev) {
		int children = foundChildren(g, from, prev);
		if (children == 0) {
			return 1;
		}
		int res = 1;
		for (int next : g[from]) {
			if (next != prev) {
				res += count(g, next, from);
			}
		}
		return res;
	}

	private static int foundChildren(LinkedList<Integer>[] g, int from, int prev) {
		int res = 0;
		for (int next : g[from]) {
			if (next != prev) {
				++res;
			}
		}
		return res;
	}
}
