package Round1A;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashSet;
import java.util.Locale;
import java.util.Scanner;

public class ProblemB {

	static BufferedWriter out;
	static int best;

	public static void solve(Scanner sc) throws IOException {
		int N = sc.nextInt();
		int[][] edges = new int[N - 1][2];
		Node[] nodes = new Node[N];
		for (int i = 0; i < nodes.length; i++) {
			nodes[i] = new Node(i);
		}
		for (int i = 0; i < edges.length; i++) {
			edges[i][0] = sc.nextInt() - 1;
			edges[i][1] = sc.nextInt() - 1;
			nodes[edges[i][0]].neighbors.add(nodes[edges[i][1]]);
			nodes[edges[i][1]].neighbors.add(nodes[edges[i][0]]);
		}
		best = N;
		for (int root = 0; root < N; root++) {
			fixTree(nodes, root);
			best = Math.min(best, nodes[root].toFix);
		}

		System.out.println(best);
		out.write(best + "\n");
	}

	static void fixTree(Node[] nodes, int root) {
		Node r = nodes[root];
		r.children = 0;
		for (Node n : r.neighbors) {
			computeFix(nodes, n, r);
			r.children += n.children + 1;
		}
		if (r.neighbors.size() == 0) {
			r.toFix = 0;
			return;
		}
		if (r.neighbors.size() == 1) {
			r.toFix = r.children;
			return;
		}

		int best = -1;
		// Node bestN = null;
		int second = -1;
		// Node secondN = null;

		for (Node n : r.neighbors) {
			int diff = n.children + 1 - n.toFix;
			if (diff > best) {
				second = best;
				// secondN = bestN;
				best = diff;
				// bestN = n;
			} else if (diff > second) {
				second = diff;
				// secondN = n;
			}
		}
		// // fix the best
		// r.toFix = bestN.toFix + secondN.toFix;
		// for (Node n : r.neighbors) {
		// if (n != bestN && n != secondN) {
		// // remove the rest
		// r.toFix += n.children + 1;
		// }
		// }
		r.toFix = r.children - best - second;
	}

	static void computeFix(Node[] nodes, Node node, Node parent) {
		node.children = 0;
		for (Node n : node.neighbors) {
			if (n != parent) {
				computeFix(nodes, n, node);
				node.children += n.children + 1;
			}
		}
		if (node.neighbors.size() == 1) {
			node.toFix = 0;
			return;
		}
		if (node.neighbors.size() == 2) {
			node.toFix = node.children;
			return;
		}

		int best = -1;
//		Node bestN = null;
		int second = -1;
//		Node secondN = null;

		for (Node n : node.neighbors) {
			if (n != parent) {
				int diff = n.children + 1 - n.toFix;
				if (diff > best) {
					second = best;
//					secondN = bestN;
					best = diff;
//					bestN = n;
				} else if (diff > second) {
					second = diff;
//					secondN = n;
				}
			}
		}
		// fix the best
//		node.toFix = bestN.toFix + secondN.toFix;
//		for (Node n : node.neighbors) {
//			if (n != parent) {
//				if (n != bestN && n != secondN) {
//					// remove the rest
//					node.toFix += n.children + 1;
//				}
//			}
//		}
//		if (node.toFix != node.children - best - second) 
//			System.out.println("here");
		node.toFix = node.children - best - second;
	}

	public static void main(String[] args) throws IOException {
//		 String name = "B-practice";
//		String name = "B-small-attempt1";
		 String name = "B-large";
		Scanner sc = new Scanner(new File(name + ".in"));
		sc.useLocale(Locale.US);

		FileWriter fstream = new FileWriter(name + ".out");
		out = new BufferedWriter(fstream);

		int cases = sc.nextInt();

		for (int i = 1; i <= cases; i++) {
			System.out.format(Locale.US, "Case #%d: ", i);
			out.write("Case #" + i + ": ");
			solve(sc);
		}
		sc.close();
		out.close();
	}

	static class Node {
		HashSet<Node> neighbors = new HashSet<Node>();
		int toFix = 0;
		int children = 0;
		int id = 0;

		public Node(int id) {
			this.id = id;
		}

		public Node() {
		}

		@Override
		public String toString() {
			return "Node " + id + ": " + toFix;
		}
	}
}
