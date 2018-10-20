import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class B {
	static int[] size;
	static ArrayList<Integer>[] T;

	public static void dfs1(int i, int p) {
		size[i] = 1;
		for (int j : T[i]) {
			if (j != p) {
				dfs1(j, i);
				size[i] += size[j];
			}
		}
	}

	public static int dfs2(int i, int p) {
		ArrayList<Integer> costs = new ArrayList<>();
		for (int j : T[i])
			if (j != p)
				costs.add(dfs2(j, i) - size[j]);
		Collections.sort(costs);
		if (costs.size() <= 1)
			return size[i] - 1;
		else
			return size[i] - 1 + costs.get(0) + costs.get(1);
	}

	public static void main(String[] args) throws Exception {
		String fileName = "B-large";
		Scanner in = new Scanner(new File(fileName + ".in"));
		PrintWriter out = new PrintWriter(fileName + ".out");
		int tc = in.nextInt();
		int cc = 1;
		while (tc-- > 0) {
			int n = in.nextInt();
			size = new int[n];
			T = new ArrayList[n];
			for (int i = 0; i < n; i++)
				T[i] = new ArrayList<>();
			for (int i = 0; i < n - 1; i++) {
				int a = in.nextInt() - 1;
				int b = in.nextInt() - 1;
				T[a].add(b);
				T[b].add(a);
			}
			int ret = n - 1;
			for (int i = 0; i < n; i++) {
				dfs1(i, -1);
				ret = Math.min(ret, dfs2(i, -1));
			}
			System.out.printf("Case #%d: %d\n", cc, ret);
			out.printf("Case #%d: %d\n", cc, ret);
			cc++;
		}
		out.close();
	}
}
