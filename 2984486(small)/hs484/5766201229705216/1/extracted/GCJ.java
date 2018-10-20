package gcj.Round1A2014.B;

import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;
import java.io.*;

public class GCJ {

	public static void tr(Object... o) {
		System.err.println(Arrays.deepToString(o));
	}

	public static void main(String[] args) throws Throwable {
		String pkg = new Object(){}.getClass().getEnclosingClass().getPackage().getName().replace('.', '/');
		String dir = "src/" + pkg;

		String filename = "";

//		if (true) { filename = "sample.in"; }
//		if (true) { filename = "B-small-attempt0.in"; }
		if (true) { filename = "B-large.in"; }

		Scanner sc = null;
		try {
			sc = new Scanner(new File(dir + "/" + filename));
		} catch (FileNotFoundException e) {
			tr(e.getMessage());
			return;
		}
		PrintWriter fout = new PrintWriter(new File(dir + "/" + filename + ".res"));

		GCJ obj = new GCJ();
		int TNO = sc.nextInt();
		for (int tno = 0; tno < TNO; tno++) {
			fout.write(String.format("Case #%d: ", (tno + 1)));
			obj.solve(sc, fout);
			fout.flush();
		}
		fout.flush();
		fout.close();
	}

	class V extends ArrayList<V> {
		int id;
	}

	int N;
	V[] vs;
	int[][] subt;
	int[][] dp;

	void solve(Scanner sc, PrintWriter fout) {
		N = sc.nextInt();
		vs = new V[N];
		for (int i = 0; i < N; i++) {
			vs[i] = new V();
			vs[i].id = i;
		}
		for (int i = 0; i < N - 1; i++) {
			int x = sc.nextInt() - 1;
			int y = sc.nextInt() - 1;
			vs[x].add(vs[y]);
			vs[y].add(vs[x]);
		}

		subt = new int[N+1][N];
		dp = new int[N+1][N];

		for (int i = 0; i < N+1; i++) {
			fill(subt[i], -1);
			fill(dp[i], -1);
		}

		int ans = N;
		for (int root = 0; root < N; root++) {
			int cur = dp(N, root);
			ans = min(ans, cur);
		}
//		tr("--");
		fout.println(ans);
	}

	int dp(int parent, int node) {
		if (dp[parent][node] != -1) return dp[parent][node];
		int res = N;
		int nch = vs[node].size();
		if (parent == N) {} else {nch--;}
//		tr(parent+1, node+1, nch, subt(parent, node));
		if (nch == 0) {
			res = 0;
		} else if (nch == 1) {
			res = 0;
			for (int i = 0; i < vs[node].size(); i++) {
				int ch = vs[node].get(i).id;
				if (parent == ch) continue;
				res += subt(node, ch);
			}
		} else {
			int allSubt = subt(parent, node) - 1;
			res = allSubt;
			for (int k1 = 0; k1 < vs[node].size(); k1++) {
				for (int k2 = 0; k2 < k1; k2++) {
					int ch1 = vs[node].get(k1).id;
					int ch2 = vs[node].get(k2).id;
					if (ch1 == parent || ch2 == parent) continue;
					int cur =
							dp(node, ch1) + dp(node, ch2)
							+ allSubt - subt(node, ch1) - subt(node, ch2);
					res = min(res, cur);
				}
			}
		}
		return dp[parent][node] = res;
	}

	int subt(int parent, int node) {
		if (subt[parent][node] != -1) return subt[parent][node];
		int res = 1;
		for (int i = 0; i < vs[node].size(); i++) {
			int ch = vs[node].get(i).id;
			if (parent == ch) continue;
			res += subt(node, ch);
		}
		return subt[parent][node] = res;
	}

}
