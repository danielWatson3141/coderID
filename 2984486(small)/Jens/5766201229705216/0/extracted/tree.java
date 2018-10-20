import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.InputStream;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * @author Jens Staahl
 */

public class tree {

	// some local config
	static boolean test = true;
	static String testDataFile = "B-small-attempt0 (1).in";

	// Just solves the acutal kattis-problem
	ZKattio io;

	private void solve() throws Throwable {
		io = new ZKattio(stream);
		long t0 = System.currentTimeMillis();
		BufferedWriter writer = new BufferedWriter(new FileWriter(this
				.getClass().getCanonicalName() + ".out"));
		int n = io.getInt();
		for (int i = 0; i < n; i++) {
			solveCase(i + 1, writer);
		}
		writer.flush();
		long time = System.currentTimeMillis() - t0;
		System.out.println("Time: " + (time));
	}

	private void solveCase(int caseNr, BufferedWriter writer) throws Throwable {
		int n = io.getInt();
		List[] edges = new List[n];
		for (int i = 0; i < n; i++) {
			edges[i] = new ArrayList<>();
			
		}
		for (int i = 0; i < n-1; i++) {
			int a = io.getInt()-1;
			int b = io.getInt()-1;
			edges[a].add(b);
			edges[b].add(a);
		}
		int ret = 0;
		for (int i = 0; i < n; i++) {
			boolean[] vis = new boolean[n];
			vis[i] = true;
			ret = Math.max(ret,  go(i, edges, vis));
		}
		String cc = (n-ret) + "";

		String ans = "Case #" + caseNr + ": " + cc + "\n";

		writer.write(ans);
		System.out.print(ans);
	}

	private int go(int i, List[] edges, boolean[] visited) {

		List<Integer> vals = new ArrayList<>();
		List<Integer> use = new ArrayList<>();
		List<Integer> list = edges[i];

		for (int j = 0; j < list.size(); j++) {
			if(!visited[list.get(j)]){
				use.add(list.get(j));
			}
			visited[(int) list.get(j)] = true;
		}
		for (int j = 0; j < use.size(); j++) {
			vals.add(go(use.get(j), edges, visited));
		}
		int ret = 1;
		if(vals.size()>= 2){
			Collections.sort(vals);
			ret += vals.get(vals.size()-1) + vals.get(vals.size()-2);
		}
		return ret;
	}

	public static void main(String[] args) throws Throwable {
		new tree().solve();
	}

	public tree() throws Throwable {
		if (test) {
			stream = new FileInputStream(testDataFile);
		}
	}

	InputStream stream = System.in;
	BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));// outStream
																				// =
																				// System.out;

}