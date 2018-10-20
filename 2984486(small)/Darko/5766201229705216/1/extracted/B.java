import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class B {

	class Node {
		int k, res, csz;
		List<Node> children;
		List<Integer> cszs;

		Node(int k) {
			this.k = k;
			res = csz = -1;
			children = new ArrayList<Node>();
		}

		public int getDescendants() {
			if (csz < 0) {
				csz = 0;
				cszs = new ArrayList<Integer>();
				for (Node child : children) {
					int d = 1 + child.getDescendants();
					cszs.add(d);
					csz += d;
				}
			}
			return csz;
		}

		public int getMin() {
			if (res < 0) {
				res = getDescendants();
				if (children.size() > 1) {
					for (int i = 0; i < children.size() - 1; i++) {
						for (int j = i + 1; j < children.size(); j++) {
							int t = csz - cszs.get(i) - cszs.get(j)
									+ children.get(i).getMin()
									+ children.get(j).getMin();
							if (t < res)
								res = t;
						}
					}
				}
			}
			return res;
		}
	}

	private void work() throws IOException {
		Scanner sc = new Scanner(new FileReader("B-large.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("B-large.out"));
		// Scanner sc = new Scanner(new FileReader("B-small-attempt0.in"));
		// PrintWriter pw = new PrintWriter(new
		// FileWriter("B-small-attempt0.out"));
		// Scanner sc = new Scanner(new FileReader("b.in"));
		// PrintWriter pw = new PrintWriter(new FileWriter("b.out"));

		Map<Integer, List<Integer>> g = new HashMap<Integer, List<Integer>>();
		for (int i = 0; i < 1024; i++) {
			g.put(i, new ArrayList<Integer>());
		}

		int nc = sc.nextInt();
		for (int tc = 1; tc <= nc; tc++) {
			int n = sc.nextInt();
			for (int i = 0; i < n; i++) {
				g.get(i).clear();
			}
			for (int i = 0; i < n - 1; i++) {
				int u = sc.nextInt() - 1;
				int v = sc.nextInt() - 1;
				g.get(u).add(v);
				g.get(v).add(u);
			}

			int best = n + 1;

			for (int i = 0; i < n; i++) {
				Node root = getTree(i, n, g);
				int t = root.getMin();
				if (t < best)
					best = t;
			}

			pw.printf("Case #%d: %d\n", tc, best);
		}
		pw.close();
	}

	Node[] q = new Node[1024];
	int qs, qe;

	private Node getTree(int root, int n, Map<Integer, List<Integer>> g) {
		boolean[] seen = new boolean[n];
		qs = qe = 0;
		q[qe++] = new Node(root);
		seen[root] = true;
		while (qs < qe) {
			Node cur = q[qs++];
			for (int v : g.get(cur.k)) {
				if (!seen[v]) {
					Node child = new Node(v);
					cur.children.add(child);
					q[qe++] = child;
					seen[v] = true;
				}
			}
		}
		return q[0];
	}

	public static void main(String[] args) throws IOException {
		new B().work();
	}

}
